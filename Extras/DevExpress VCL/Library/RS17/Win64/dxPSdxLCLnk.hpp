// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSdxLCLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsdxlclnkHPP
#define DxpsdxlclnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <dxLayoutControl.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdxlclnk
{
//-- type declarations -------------------------------------------------------
enum TdxLCCacheItemKind : unsigned char { ikLayoutItem, ikLayoutGroup, ikLayoutItemCaption, ikControl };

class DELPHICLASS TdxLCBoundsCacheItem;
class PASCALIMPLEMENTATION TdxLCBoundsCacheItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Classes::TComponent* Component;
	System::Types::TRect Bounds;
	bool EmbeddedLink;
public:
	/* TObject.Create */ inline __fastcall TdxLCBoundsCacheItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLCBoundsCacheItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutControlHost;
class PASCALIMPLEMENTATION TdxReportLayoutControlHost : public Dxpscontainerlnk::TdxReportWinControlHost
{
	typedef Dxpscontainerlnk::TdxReportWinControlHost inherited;
	
protected:
	virtual Dxpscore::TdxReportVisualItem* __fastcall GetControlItem(void);
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutControlHost(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportLayoutControlHost(Dxpscore::TdxReportCell* AParent) : Dxpscontainerlnk::TdxReportWinControlHost(AParent) { }
	
};


class DELPHICLASS TdxReportLayoutCaptionTextCell;
class PASCALIMPLEMENTATION TdxReportLayoutCaptionTextCell : public Dxpscore::TdxReportCellString
{
	typedef Dxpscore::TdxReportCellString inherited;
	
protected:
	virtual unsigned __fastcall GetDTFormat(void);
public:
	/* TdxReportCellText.Create */ inline __fastcall virtual TdxReportLayoutCaptionTextCell(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellString(AParent) { }
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportLayoutCaptionTextCell(void) { }
	
};


typedef System::TMetaClass* TdxReportLayoutCaptionTextCellClass;

class DELPHICLASS TdxReportLayoutCaptionImageCell;
class PASCALIMPLEMENTATION TdxReportLayoutCaptionImageCell : public Dxpscore::TdxReportCellImage
{
	typedef Dxpscore::TdxReportCellImage inherited;
	
public:
	/* TdxReportCellImage.Create */ inline __fastcall virtual TdxReportLayoutCaptionImageCell(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellImage(AParent) { }
	
public:
	/* TCustomdxReportCellImageContainer.Destroy */ inline __fastcall virtual ~TdxReportLayoutCaptionImageCell(void) { }
	
};


typedef System::TMetaClass* TdxReportLayoutCaptionImageCellClass;

class DELPHICLASS TdxReportCustomLayoutCaptionCell;
class PASCALIMPLEMENTATION TdxReportCustomLayoutCaptionCell : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetItem(void);
	System::Types::TRect __fastcall GetCaptionBounds(void);
	Dxlayoutcontainer::TdxCustomLayoutItemCaptionOptions* __fastcall GetCaptionOptions(void);
	bool __fastcall GetHasImageItem(void);
	bool __fastcall GetHasTextItem(void);
	System::Types::TRect __fastcall GetImageBounds(void);
	TdxReportLayoutCaptionImageCell* __fastcall GetImageItem(void);
	Dxlayoutcontainer::TdxCustomLayoutItemImageOptions* __fastcall GetImageOptions(void);
	System::Types::TRect __fastcall GetTextBounds(void);
	TdxReportLayoutCaptionTextCell* __fastcall GetTextItem(void);
	Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AdjustBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual TdxReportLayoutCaptionImageCell* __fastcall CreateImageCell(Dxpscore::TBasedxReportLink* AReportLink);
	virtual TdxReportLayoutCaptionTextCell* __fastcall CreateTextCell(Dxpscore::TBasedxReportLink* AReportLink);
	virtual TdxReportLayoutCaptionImageCellClass __fastcall GetReportLayoutCaptionImageCellClass(void);
	virtual TdxReportLayoutCaptionTextCellClass __fastcall GetReportLayoutCaptionTextCellClass(void);
	virtual bool __fastcall IsImageVisible(void);
	virtual bool __fastcall IsTextVisible(void);
	__property System::Types::TRect CaptionBounds = {read=GetCaptionBounds};
	__property System::Types::TRect ImageBounds = {read=GetImageBounds};
	__property System::Types::TRect TextBounds = {read=GetTextBounds};
	__property Dxlayoutcontainer::TdxCustomLayoutItemCaptionOptions* CaptionOptions = {read=GetCaptionOptions};
	__property Dxlayoutcontainer::TdxCustomLayoutItemImageOptions* ImageOptions = {read=GetImageOptions};
	
public:
	virtual void __fastcall Initialize(Dxpscore::TBasedxReportLink* AReportLink);
	__property TdxReportLayoutCaptionImageCell* ImageItem = {read=GetImageItem};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* Item = {read=GetItem};
	__property bool HasImageItem = {read=GetHasImageItem, nodefault};
	__property bool HasTextItem = {read=GetHasTextItem, nodefault};
	__property TdxReportLayoutCaptionTextCell* TextItem = {read=GetTextItem};
	__property Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportCustomLayoutCaptionCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportCustomLayoutCaptionCell(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


typedef System::TMetaClass* TdxReportCustomLayoutCaptionCellClass;

typedef System::TMetaClass* TdxCustomReportLayoutItemClass;

typedef void __fastcall (__closure *TdxLCGetLayoutItemViewInfoEvent)(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* &AViewInfo);

class DELPHICLASS TdxCustomReportLayoutItem;
class PASCALIMPLEMENTATION TdxCustomReportLayoutItem : public Dxpscore::TdxReportGroup
{
	typedef Dxpscore::TdxReportGroup inherited;
	
private:
	TdxLCGetLayoutItemViewInfoEvent FOnGetLayoutItemViewInfo;
	TdxReportCustomLayoutCaptionCell* __fastcall GetCaptionItem(void);
	bool __fastcall GetHasCaptionItem(void);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetItem(void);
	System::Types::TRect __fastcall GetItemBounds(void);
	Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AdjustBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall Initialize(Dxpscore::TBasedxReportLink* AReportLink);
	virtual TdxReportCustomLayoutCaptionCellClass __fastcall GetCaptionCellClass(void);
	virtual TdxReportCustomLayoutCaptionCell* __fastcall CreateCaptionCell(Dxpscore::TBasedxReportLink* AReportLink);
	bool __fastcall IsCaptionVisible(void);
	virtual bool __fastcall NeedCreateCaptionCell(void);
	int __fastcall GetFontIndex(void);
	__property System::Types::TRect ItemBounds = {read=GetItemBounds};
	__property Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__property Dxlayoutcontainer::TdxCustomLayoutItem* Item = {read=GetItem};
	__property TdxReportCustomLayoutCaptionCell* CaptionItem = {read=GetCaptionItem};
	__property bool HasCaptionItem = {read=GetHasCaptionItem, nodefault};
	__property TdxLCGetLayoutItemViewInfoEvent OnGetLayoutItemViewInfo = {read=FOnGetLayoutItemViewInfo, write=FOnGetLayoutItemViewInfo};
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxCustomReportLayoutItem(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportGroup(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxCustomReportLayoutItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutGroupCaptionTextCell;
class PASCALIMPLEMENTATION TdxReportLayoutGroupCaptionTextCell : public TdxReportLayoutCaptionTextCell
{
	typedef TdxReportLayoutCaptionTextCell inherited;
	
private:
	Dxlayoutcontainer::TdxCaptionLayout FLayout;
	bool __fastcall HasLayoutProperty(const Dxpsglbl::TdxPSVersion &AVersion);
	
protected:
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__property Dxlayoutcontainer::TdxCaptionLayout Layout = {read=FLayout, nodefault};
public:
	/* TdxReportCellText.Create */ inline __fastcall virtual TdxReportLayoutGroupCaptionTextCell(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutCaptionTextCell(AParent) { }
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportLayoutGroupCaptionTextCell(void) { }
	
};


class DELPHICLASS TdxReportLayoutGroupCaptionImageCell;
class PASCALIMPLEMENTATION TdxReportLayoutGroupCaptionImageCell : public TdxReportLayoutCaptionImageCell
{
	typedef TdxReportLayoutCaptionImageCell inherited;
	
public:
	/* TdxReportCellImage.Create */ inline __fastcall virtual TdxReportLayoutGroupCaptionImageCell(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutCaptionImageCell(AParent) { }
	
public:
	/* TCustomdxReportCellImageContainer.Destroy */ inline __fastcall virtual ~TdxReportLayoutGroupCaptionImageCell(void) { }
	
};


class DELPHICLASS TdxReportLayoutGroupCaptionCell;
class PASCALIMPLEMENTATION TdxReportLayoutGroupCaptionCell : public TdxReportCustomLayoutCaptionCell
{
	typedef TdxReportCustomLayoutCaptionCell inherited;
	
private:
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall GetGroup(void);
	HIDESBASE TdxReportLayoutGroupCaptionTextCell* __fastcall GetTextItem(void);
	
protected:
	virtual TdxReportLayoutCaptionTextCell* __fastcall CreateTextCell(Dxpscore::TBasedxReportLink* AReportLink);
	virtual TdxReportLayoutCaptionImageCell* __fastcall CreateImageCell(Dxpscore::TBasedxReportLink* AReportLink);
	virtual TdxReportLayoutCaptionImageCellClass __fastcall GetReportLayoutCaptionImageCellClass(void);
	virtual TdxReportLayoutCaptionTextCellClass __fastcall GetReportLayoutCaptionTextCellClass(void);
	
public:
	__property Dxlayoutcontainer::TdxLayoutGroup* Group = {read=GetGroup};
	__property TdxReportLayoutGroupCaptionTextCell* TextItem = {read=GetTextItem};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutGroupCaptionCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportLayoutGroupCaptionCell(Dxpscore::TdxReportCell* AParent) : TdxReportCustomLayoutCaptionCell(AParent) { }
	
};


class DELPHICLASS TdxPSReportLayoutGroupStandardLookAndFeelPainter;
class DELPHICLASS TdxPSReportLayoutGroupStandardLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportLayoutGroupStandardLookAndFeelPainter : public Dxpscore::TdxPSReportGroupStandardLookAndFeelPainter
{
	typedef Dxpscore::TdxPSReportGroupStandardLookAndFeelPainter inherited;
	
protected:
	virtual void __fastcall DrawCaptionText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	
public:
	HIDESBASE virtual TdxPSReportLayoutGroupStandardLookAndFeel* __fastcall LookAndFeel(void)/* overload */;
public:
	/* TdxPSReportGroupLookAndFeelPainter.Create */ inline __fastcall virtual TdxPSReportLayoutGroupStandardLookAndFeelPainter(Dxpscore::TdxPSReportRenderer* ARenderer) : Dxpscore::TdxPSReportGroupStandardLookAndFeelPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSReportLayoutGroupStandardLookAndFeelPainter(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSReportLayoutGroupStandardLookAndFeel : public Dxpscore::TdxPSReportGroupStandardLookAndFeel
{
	typedef Dxpscore::TdxPSReportGroupStandardLookAndFeel inherited;
	
protected:
	virtual int __fastcall GetBorderEdgeThickness(Dxpscore::TdxReportGroup* AGroup, Dxpscore::TdxCellSide ASide);
	virtual int __fastcall GetCaptionHeight(Dxpscore::TdxReportGroup* AGroup);
	virtual System::Types::TRect __fastcall GetCaptionTextBounds(Dxpscore::TdxReportGroup* AGroup);
	__classmethod virtual Dxpscore::TdxPSReportGroupLookAndFeelPainterClass __fastcall GetPainterClass();
public:
	/* TdxPSReportGroupLookAndFeel.Create */ inline __fastcall virtual TdxPSReportLayoutGroupStandardLookAndFeel(Dxpscore::TdxReportCells* AReportCells) : Dxpscore::TdxPSReportGroupStandardLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportLayoutGroupStandardLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportLayoutGroupWebLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportLayoutGroupWebLookAndFeel : public Dxpscore::TdxPSReportGroupWebLookAndFeel
{
	typedef Dxpscore::TdxPSReportGroupWebLookAndFeel inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetCaptionBounds(Dxpscore::TdxReportGroup* AGroup);
public:
	/* TdxPSReportGroupWebLookAndFeel.Create */ inline __fastcall virtual TdxPSReportLayoutGroupWebLookAndFeel(Dxpscore::TdxReportCells* AReportCells) : Dxpscore::TdxPSReportGroupWebLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportLayoutGroupWebLookAndFeel(void) { }
	
};


class DELPHICLASS TdxPSReportLayoutGroupOfficeLookAndFeel;
class PASCALIMPLEMENTATION TdxPSReportLayoutGroupOfficeLookAndFeel : public TdxPSReportLayoutGroupStandardLookAndFeel
{
	typedef TdxPSReportLayoutGroupStandardLookAndFeel inherited;
	
protected:
	virtual Dxpscore::TdxCellSides __fastcall GetBorderSides(Dxpscore::TdxReportGroup* AGroup);
	virtual int __fastcall GetCaptionIndent(void);
	
public:
	__classmethod virtual Dxpscore::TdxCellSides __fastcall DefaultBorderSides();
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TdxPSReportGroupLookAndFeel.Create */ inline __fastcall virtual TdxPSReportLayoutGroupOfficeLookAndFeel(Dxpscore::TdxReportCells* AReportCells) : TdxPSReportLayoutGroupStandardLookAndFeel(AReportCells) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSReportLayoutGroupOfficeLookAndFeel(void) { }
	
};


class DELPHICLASS TdxReportLayoutGroup;
class PASCALIMPLEMENTATION TdxReportLayoutGroup : public TdxCustomReportLayoutItem
{
	typedef TdxCustomReportLayoutItem inherited;
	
private:
	Dxpscore::TdxCellSide FSide;
	HIDESBASE TdxReportLayoutGroupCaptionCell* __fastcall GetCaptionItem(void);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall GetGroup(void);
	bool __fastcall HasSideProperty(const Dxpsglbl::TdxPSVersion &AVersion);
	
protected:
	virtual void __fastcall AdjustBorderOuterBounds(System::Types::TRect &R);
	virtual TdxReportCustomLayoutCaptionCellClass __fastcall GetCaptionCellClass(void);
	virtual void __fastcall Initialize(Dxpscore::TBasedxReportLink* AReportLink);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxReportLayoutGroupCaptionCell* CaptionItem = {read=GetCaptionItem};
	__property Dxlayoutcontainer::TdxLayoutGroup* Group = {read=GetGroup};
	__property Dxpscore::TdxCellSide Side = {read=FSide, nodefault};
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutGroup(Dxpscore::TdxReportCell* AParent) : TdxCustomReportLayoutItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutGroup(void) { }
	
};


class DELPHICLASS TdxReportLayoutBasicItem;
class PASCALIMPLEMENTATION TdxReportLayoutBasicItem : public TdxCustomReportLayoutItem
{
	typedef TdxCustomReportLayoutItem inherited;
	
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutBasicItem(Dxpscore::TdxReportCell* AParent) : TdxCustomReportLayoutItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutBasicItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutNonLabeledItem;
class PASCALIMPLEMENTATION TdxReportLayoutNonLabeledItem : public TdxCustomReportLayoutItem
{
	typedef TdxCustomReportLayoutItem inherited;
	
protected:
	virtual bool __fastcall NeedCreateCaptionCell(void);
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutNonLabeledItem(Dxpscore::TdxReportCell* AParent) : TdxCustomReportLayoutItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutNonLabeledItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutEmptySpaceItem;
class PASCALIMPLEMENTATION TdxReportLayoutEmptySpaceItem : public TdxReportLayoutNonLabeledItem
{
	typedef TdxReportLayoutNonLabeledItem inherited;
	
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutEmptySpaceItem(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutNonLabeledItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutEmptySpaceItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutDirectionalItem;
class PASCALIMPLEMENTATION TdxReportLayoutDirectionalItem : public TdxReportLayoutNonLabeledItem
{
	typedef TdxReportLayoutNonLabeledItem inherited;
	
private:
	Dxpscore::TdxReportCell* FSeparatorItem;
	bool __fastcall GetHasSeparatorItem(void);
	Dxlayoutcontainer::TdxLayoutDirectionalItem* __fastcall GetLayoutItem(void);
	System::Types::TRect __fastcall GetSeparatorBounds(void);
	
protected:
	virtual void __fastcall AdjustBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall Initialize(Dxpscore::TBasedxReportLink* AReportLink);
	virtual bool __fastcall NeedCreateCaptionCell(void);
	virtual Dxpscore::TdxReportCell* __fastcall CreateSeparatorCell(Dxpscore::TBasedxReportLink* AReportLink);
	__property System::Types::TRect SeparatorBounds = {read=GetSeparatorBounds};
	
public:
	__property Dxlayoutcontainer::TdxLayoutDirectionalItem* LayoutItem = {read=GetLayoutItem};
	__property Dxpscore::TdxReportCell* SeparatorItem = {read=FSeparatorItem};
	__property bool HasSeparatorItem = {read=GetHasSeparatorItem, nodefault};
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutDirectionalItem(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutNonLabeledItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutDirectionalItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutSeparatorItem;
class PASCALIMPLEMENTATION TdxReportLayoutSeparatorItem : public TdxReportLayoutDirectionalItem
{
	typedef TdxReportLayoutDirectionalItem inherited;
	
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutSeparatorItem(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutDirectionalItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutSeparatorItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutSplitterItem;
class PASCALIMPLEMENTATION TdxReportLayoutSplitterItem : public TdxReportLayoutDirectionalItem
{
	typedef TdxReportLayoutDirectionalItem inherited;
	
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutSplitterItem(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutDirectionalItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutSplitterItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutLabeledItemCaptionCell;
class PASCALIMPLEMENTATION TdxReportLayoutLabeledItemCaptionCell : public TdxReportCustomLayoutCaptionCell
{
	typedef TdxReportCustomLayoutCaptionCell inherited;
	
private:
	HIDESBASE Dxlayoutcontainer::TdxLayoutLabeledItemCustomCaptionOptions* __fastcall GetCaptionOptions(void);
	
protected:
	virtual TdxReportLayoutCaptionTextCell* __fastcall CreateTextCell(Dxpscore::TBasedxReportLink* AReportLink);
	__property Dxlayoutcontainer::TdxLayoutLabeledItemCustomCaptionOptions* CaptionOptions = {read=GetCaptionOptions};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutLabeledItemCaptionCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TdxReportLayoutLabeledItemCaptionCell(Dxpscore::TdxReportCell* AParent) : TdxReportCustomLayoutCaptionCell(AParent) { }
	
};


class DELPHICLASS TdxReportLayoutLabeledItem;
class PASCALIMPLEMENTATION TdxReportLayoutLabeledItem : public TdxReportLayoutBasicItem
{
	typedef TdxReportLayoutBasicItem inherited;
	
private:
	Dxlayoutcontainer::TdxLayoutCustomLabeledItem* __fastcall GetLayoutItem(void);
	
protected:
	virtual TdxReportCustomLayoutCaptionCellClass __fastcall GetCaptionCellClass(void);
	
public:
	__property Dxlayoutcontainer::TdxLayoutCustomLabeledItem* LayoutItem = {read=GetLayoutItem};
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutLabeledItem(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutBasicItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutLabeledItem(void) { }
	
};


class DELPHICLASS TdxReportLayoutItem;
class DELPHICLASS TdxLayoutControlReportLink;
class PASCALIMPLEMENTATION TdxReportLayoutItem : public TdxReportLayoutLabeledItem
{
	typedef TdxReportLayoutLabeledItem inherited;
	
private:
	Dxpscore::TdxReportVisualItem* FControlItem;
	Dxlayoutcontainer::TdxCustomLayoutControlAdapter* __fastcall GetAdapter(void);
	Vcl::Controls::TControl* __fastcall GetControl(void);
	System::Types::TRect __fastcall GetControlBounds(void);
	bool __fastcall GetHasControlItem(void);
	bool __fastcall GetIsControlAccessible(void);
	HIDESBASE Dxlayoutcontainer::TdxLayoutItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AdjustBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall Initialize(Dxpscore::TBasedxReportLink* AReportLink);
	virtual Dxpscore::TdxReportVisualItem* __fastcall CreateControlCell(TdxLayoutControlReportLink* AReportLink);
	virtual bool __fastcall NeedCreateControlCell(void);
	__property Dxlayoutcontainer::TdxCustomLayoutControlAdapter* Adapter = {read=GetAdapter};
	__property System::Types::TRect ControlBounds = {read=GetControlBounds};
	__property bool IsControlAccessible = {read=GetIsControlAccessible, nodefault};
	
public:
	HIDESBASE Dxlayoutcontainer::TdxLayoutItem* __fastcall LayoutItem(void);
	__property Vcl::Controls::TControl* Control = {read=GetControl};
	__property Dxpscore::TdxReportVisualItem* ControlItem = {read=FControlItem};
	__property bool HasControlItem = {read=GetHasControlItem, nodefault};
	__property Dxlayoutcontainer::TdxLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportLayoutItem(Dxpscore::TdxReportCell* AParent) : TdxReportLayoutLabeledItem(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TdxReportLayoutItem(void) { }
	
};


class DELPHICLASS TdxPSCustomLayoutItemDefinition;
class DELPHICLASS TdxLayoutControlReportLinkOptionsPagination;
class PASCALIMPLEMENTATION TdxPSCustomLayoutItemDefinition : public Dxpscontainerlnk::TdxPSCustomContainerItemDefinition
{
	typedef Dxpscontainerlnk::TdxPSCustomContainerItemDefinition inherited;
	
private:
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetLayoutItem(void);
	TdxCustomReportLayoutItem* __fastcall GetReportItem(void);
	void __fastcall SetLayoutItem(Dxlayoutcontainer::TdxCustomLayoutItem* Value);
	
protected:
	virtual void __fastcall AdjustBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall SaveOriginalItemSize(void);
	virtual void __fastcall SetupOriginalControlSize(void);
	
public:
	HIDESBASE TdxLayoutControlReportLinkOptionsPagination* __fastcall OptionsPagination(void)/* overload */;
	__property Dxlayoutcontainer::TdxCustomLayoutItem* LayoutItem = {read=GetLayoutItem, write=SetLayoutItem};
	__property TdxCustomReportLayoutItem* ReportItem = {read=GetReportItem};
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSCustomLayoutItemDefinition(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : Dxpscontainerlnk::TdxPSCustomContainerItemDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSCustomLayoutItemDefinition(void) { }
	
};


class DELPHICLASS TdxPSLayoutGroupDefinition;
class PASCALIMPLEMENTATION TdxPSLayoutGroupDefinition : public TdxPSCustomLayoutItemDefinition
{
	typedef TdxPSCustomLayoutItemDefinition inherited;
	
private:
	HIDESBASE Dxlayoutcontainer::TdxLayoutGroup* __fastcall GetLayoutItem(void);
	
protected:
	virtual void __fastcall AddDelimitersHorz(System::Classes::TList* AList);
	virtual void __fastcall AddDelimitersVert(System::Classes::TList* AList);
	
public:
	__property Dxlayoutcontainer::TdxLayoutGroup* LayoutItem = {read=GetLayoutItem};
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSLayoutGroupDefinition(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : TdxPSCustomLayoutItemDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSLayoutGroupDefinition(void) { }
	
};


class DELPHICLASS TdxPSLayoutBasicItemDefinition;
class PASCALIMPLEMENTATION TdxPSLayoutBasicItemDefinition : public TdxPSCustomLayoutItemDefinition
{
	typedef TdxPSCustomLayoutItemDefinition inherited;
	
protected:
	virtual void __fastcall AddDelimitersHorz(System::Classes::TList* AList);
	virtual void __fastcall AddDelimitersVert(System::Classes::TList* AList);
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSLayoutBasicItemDefinition(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : TdxPSCustomLayoutItemDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSLayoutBasicItemDefinition(void) { }
	
};


class DELPHICLASS TdxPSLayoutLabeledItemDefinition;
class PASCALIMPLEMENTATION TdxPSLayoutLabeledItemDefinition : public TdxPSLayoutBasicItemDefinition
{
	typedef TdxPSLayoutBasicItemDefinition inherited;
	
public:
	/* TdxPSCustomContainerItemDefinition.Create */ inline __fastcall virtual TdxPSLayoutLabeledItemDefinition(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem) : TdxPSLayoutBasicItemDefinition(AReportLink, AComponent, AReportItem) { }
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSLayoutLabeledItemDefinition(void) { }
	
};


class DELPHICLASS TdxPSLayoutItemDefinition;
class PASCALIMPLEMENTATION TdxPSLayoutItemDefinition : public TdxPSLayoutLabeledItemDefinition
{
	typedef TdxPSLayoutLabeledItemDefinition inherited;
	
private:
	HIDESBASE Dxlayoutcontainer::TdxLayoutItem* __fastcall GetLayoutItem(void);
	HIDESBASE TdxReportLayoutItem* __fastcall GetReportItem(void);
	
protected:
	virtual void __fastcall SaveOriginalItemSize(void);
	virtual void __fastcall SetupOriginalControlSize(void);
	
public:
	__fastcall virtual TdxPSLayoutItemDefinition(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AComponent, Dxpscore::TdxReportVisualItem* AReportItem);
	__property Dxlayoutcontainer::TdxLayoutItem* LayoutItem = {read=GetLayoutItem};
	__property TdxReportLayoutItem* ReportItem = {read=GetReportItem};
public:
	/* TdxPSCustomContainerItemDefinition.Destroy */ inline __fastcall virtual ~TdxPSLayoutItemDefinition(void) { }
	
};


class DELPHICLASS TdxPSLayoutControlObjectProducer;
class PASCALIMPLEMENTATION TdxPSLayoutControlObjectProducer : public Dxpscontainerlnk::TdxPSCustomProducer
{
	typedef Dxpscontainerlnk::TdxPSCustomProducer inherited;
	
public:
	HIDESBASE TdxLayoutControlReportLink* __fastcall ReportLink(void)/* overload */;
	HIDESBASE Dxlayoutcontrol::TdxLayoutControl* __fastcall RootContainer(void)/* overload */;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutControlObjectProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSCustomProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutControlObjectProducer(void) { }
	
};


typedef System::TMetaClass* TdxPSLayoutLookAndFeelProducerClass;

class DELPHICLASS TdxPSLayoutLookAndFeelProducer;
class PASCALIMPLEMENTATION TdxPSLayoutLookAndFeelProducer : public TdxPSLayoutControlObjectProducer
{
	typedef TdxPSLayoutControlObjectProducer inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	virtual System::Uitypes::TColor __fastcall GetGroupCaptionColor(void);
	virtual bool __fastcall GetIsContentTransparent(void);
	virtual bool __fastcall GetIsGroupCaptionTransparent(void);
	virtual System::Uitypes::TColor __fastcall GetTransparentColor(void);
	virtual void __fastcall InitializeReportLookAndFeel(Dxpscore::TdxPSReportGroupLookAndFeel* ALookAndFeel);
	__classmethod virtual Dxpscore::TdxPSReportGroupLookAndFeelClass __fastcall ReportLookAndFeelClass();
	__property System::Uitypes::TColor GroupCaptionColor = {read=GetGroupCaptionColor, nodefault};
	__property bool IsGroupCaptionTransparent = {read=GetIsGroupCaptionTransparent, nodefault};
	
public:
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall LayoutLookAndFeel(void)/* overload */;
	__classmethod virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelClass __fastcall LayoutLookAndFeelClass();
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	__property System::Uitypes::TColor ContentColor = {read=GetContentColor, nodefault};
	__property bool IsContentTransparent = {read=GetIsContentTransparent, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=GetTransparentColor, nodefault};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutLookAndFeelProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutControlObjectProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutLookAndFeelProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutStandardLookAndFeelProducer;
class PASCALIMPLEMENTATION TdxPSLayoutStandardLookAndFeelProducer : public TdxPSLayoutLookAndFeelProducer
{
	typedef TdxPSLayoutLookAndFeelProducer inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetTransparentColor(void);
	__classmethod virtual Dxpscore::TdxPSReportGroupLookAndFeelClass __fastcall ReportLookAndFeelClass();
	
public:
	HIDESBASE Dxlayoutlookandfeels::TdxLayoutStandardLookAndFeel* __fastcall LayoutLookAndFeel(void)/* overload */;
	__classmethod virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelClass __fastcall LayoutLookAndFeelClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutStandardLookAndFeelProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutLookAndFeelProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutStandardLookAndFeelProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutOfficeLookAndFeelProducer;
class PASCALIMPLEMENTATION TdxPSLayoutOfficeLookAndFeelProducer : public TdxPSLayoutStandardLookAndFeelProducer
{
	typedef TdxPSLayoutStandardLookAndFeelProducer inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxPSReportGroupLookAndFeelClass __fastcall ReportLookAndFeelClass();
	
public:
	HIDESBASE Dxlayoutlookandfeels::TdxLayoutOfficeLookAndFeel* __fastcall LayoutLookAndFeel(void)/* overload */;
	__classmethod virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelClass __fastcall LayoutLookAndFeelClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutOfficeLookAndFeelProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutStandardLookAndFeelProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutOfficeLookAndFeelProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutWebLookAndFeelProducer;
class PASCALIMPLEMENTATION TdxPSLayoutWebLookAndFeelProducer : public TdxPSLayoutLookAndFeelProducer
{
	typedef TdxPSLayoutLookAndFeelProducer inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetGroupCaptionColor(void);
	virtual System::Uitypes::TColor __fastcall GetTransparentColor(void);
	virtual void __fastcall InitializeReportLookAndFeel(Dxpscore::TdxPSReportGroupLookAndFeel* ALookAndFeel);
	__classmethod virtual Dxpscore::TdxPSReportGroupLookAndFeelClass __fastcall ReportLookAndFeelClass();
	
public:
	HIDESBASE Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* __fastcall LayoutLookAndFeel(void)/* overload */;
	__classmethod virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelClass __fastcall LayoutLookAndFeelClass();
	__property GroupCaptionColor;
	__property IsGroupCaptionTransparent;
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutWebLookAndFeelProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutLookAndFeelProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutWebLookAndFeelProducer(void) { }
	
};


typedef System::TMetaClass* TdxPSCustomLayoutItemProducerClass;

class DELPHICLASS TdxPSCustomLayoutItemProducer;
class DELPHICLASS TdxLayoutControlReportLinkOptionsTransparent;
class PASCALIMPLEMENTATION TdxPSCustomLayoutItemProducer : public TdxPSLayoutControlObjectProducer
{
	typedef TdxPSLayoutControlObjectProducer inherited;
	
private:
	System::Types::TRect __fastcall GetLayoutItemBounds(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	virtual bool __fastcall GetIsContentTransparent(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	TdxPSLayoutLookAndFeelProducer* __fastcall GetLayoutLookAndFeelProducer(void);
	virtual void __fastcall InitializeReportItem(Dxpscore::TdxReportCell* AnItem);
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	HIDESBASE TdxLayoutControlReportLinkOptionsTransparent* __fastcall OptionsTransparent(void)/* overload */;
	virtual void __fastcall AdjustBounds(void);
	void __fastcall SaveOriginalItemSize(void);
	
public:
	HIDESBASE TdxPSCustomLayoutItemDefinition* __fastcall Definition(void)/* overload */;
	__classmethod virtual Dxpscontainerlnk::TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall LayoutItem(void);
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
	__classmethod virtual System::TClass __fastcall PairClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
	virtual void __fastcall Reposition(void);
	__classmethod virtual void __fastcall Register();
	__classmethod virtual void __fastcall Unregister();
	__property System::Uitypes::TColor ContentColor = {read=GetContentColor, nodefault};
	__property bool IsContentTransparent = {read=GetIsContentTransparent, nodefault};
	__property System::Types::TRect LayoutItemBounds = {read=GetLayoutItemBounds};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	__property TdxPSLayoutLookAndFeelProducer* LayoutLookAndFeelProducer = {read=GetLayoutLookAndFeelProducer};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSCustomLayoutItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutControlObjectProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomLayoutItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutGroupProducer;
class PASCALIMPLEMENTATION TdxPSLayoutGroupProducer : public TdxPSCustomLayoutItemProducer
{
	typedef TdxPSCustomLayoutItemProducer inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetGroupCaptionContentColor(void);
	virtual bool __fastcall GetIsGroupCaptionTransparent(void);
	virtual void __fastcall InitializeReportItem(Dxpscore::TdxReportCell* AnItem);
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	HIDESBASE TdxPSLayoutGroupDefinition* __fastcall Definition(void)/* overload */;
	__classmethod virtual Dxpscontainerlnk::TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	HIDESBASE Dxlayoutcontainer::TdxLayoutGroup* __fastcall LayoutItem(void);
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
	virtual void __fastcall Reposition(void);
	__property System::Uitypes::TColor GroupCaptionContentColor = {read=GetGroupCaptionContentColor, nodefault};
	__property bool IsGroupCaptionTransparent = {read=GetIsGroupCaptionTransparent, nodefault};
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutGroupProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomLayoutItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutGroupProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutBasicItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutBasicItemProducer : public TdxPSCustomLayoutItemProducer
{
	typedef TdxPSCustomLayoutItemProducer inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetContentColor(void);
	virtual void __fastcall InitializeReportItem(Dxpscore::TdxReportCell* AnItem);
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	__classmethod virtual Dxpscontainerlnk::TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutBasicItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSCustomLayoutItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutBasicItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutEmptySpaceItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutEmptySpaceItemProducer : public TdxPSLayoutBasicItemProducer
{
	typedef TdxPSLayoutBasicItemProducer inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutEmptySpaceItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutBasicItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutEmptySpaceItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutDirectionalItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutDirectionalItemProducer : public TdxPSLayoutBasicItemProducer
{
	typedef TdxPSLayoutBasicItemProducer inherited;
	
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutDirectionalItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutBasicItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutDirectionalItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutSeparatorItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutSeparatorItemProducer : public TdxPSLayoutDirectionalItemProducer
{
	typedef TdxPSLayoutDirectionalItemProducer inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutSeparatorItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutDirectionalItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutSeparatorItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutSplitterItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutSplitterItemProducer : public TdxPSLayoutDirectionalItemProducer
{
	typedef TdxPSLayoutDirectionalItemProducer inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutSplitterItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutDirectionalItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutSplitterItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutCustomLabeledItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutCustomLabeledItemProducer : public TdxPSLayoutBasicItemProducer
{
	typedef TdxPSLayoutBasicItemProducer inherited;
	
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutCustomLabeledItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutBasicItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutCustomLabeledItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutLabeledItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutLabeledItemProducer : public TdxPSLayoutCustomLabeledItemProducer
{
	typedef TdxPSLayoutCustomLabeledItemProducer inherited;
	
protected:
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	__classmethod virtual Dxpscontainerlnk::TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	HIDESBASE Dxlayoutcontainer::TdxLayoutLabeledItem* __fastcall LayoutItem(void);
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutLabeledItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : TdxPSLayoutCustomLabeledItemProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutLabeledItemProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutItemProducer;
class PASCALIMPLEMENTATION TdxPSLayoutItemProducer : public TdxPSLayoutCustomLabeledItemProducer
{
	typedef TdxPSLayoutCustomLabeledItemProducer inherited;
	
private:
	Vcl::Controls::TControl* __fastcall GetControl(void);
	bool __fastcall GetHasControl(void);
	
protected:
	__classmethod virtual Dxpscore::TdxReportCellClass __fastcall ReportItemClass();
	
public:
	__fastcall virtual TdxPSLayoutItemProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject);
	HIDESBASE TdxPSLayoutItemDefinition* __fastcall Definition(void)/* overload */;
	__classmethod virtual Dxpscontainerlnk::TdxPSCustomContainerItemDefinitionClass __fastcall DefinitionClass();
	HIDESBASE Dxlayoutcontainer::TdxLayoutItem* __fastcall LayoutItem(void);
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemClass __fastcall LayoutItemClass();
	virtual System::UnicodeString __fastcall ProducingObjectFriendlyName(void);
	virtual void __fastcall Reposition(void);
	__property Vcl::Controls::TControl* Control = {read=GetControl};
	__property bool HasControl = {read=GetHasControl, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutItemProducer(void) { }
	
};


class DELPHICLASS TdxPSCustomLayoutObjectProducerCache;
class PASCALIMPLEMENTATION TdxPSCustomLayoutObjectProducerCache : public Dxpscontainerlnk::TdxPSContainerReportLinkCustomCache
{
	typedef Dxpscontainerlnk::TdxPSContainerReportLinkCustomCache inherited;
	
public:
	HIDESBASE TdxLayoutControlReportLink* __fastcall ReportLink(void)/* overload */;
public:
	/* TdxPSContainerReportLinkCustomCache.Create */ inline __fastcall virtual TdxPSCustomLayoutObjectProducerCache(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : Dxpscontainerlnk::TdxPSContainerReportLinkCustomCache(AReportLink) { }
	
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxPSCustomLayoutObjectProducerCache(void) { }
	
};


class DELPHICLASS TdxPSLayoutItemProducerCache;
class PASCALIMPLEMENTATION TdxPSLayoutItemProducerCache : public TdxPSCustomLayoutObjectProducerCache
{
	typedef TdxPSCustomLayoutObjectProducerCache inherited;
	
private:
	HIDESBASE TdxPSCustomLayoutItemProducer* __fastcall GetItem(int Index);
	TdxPSCustomLayoutItemProducer* __fastcall GetProducer(TdxPSCustomLayoutItemProducerClass AProducerClass, Dxlayoutcontainer::TdxCustomLayoutItem* ALayoutItem);
	
protected:
	__property TdxPSCustomLayoutItemProducer* Items[int Index] = {read=GetItem};
	
public:
	__property TdxPSCustomLayoutItemProducer* Producers[TdxPSCustomLayoutItemProducerClass AProducerClass][Dxlayoutcontainer::TdxCustomLayoutItem* ALayoutItem] = {read=GetProducer/*, default*/};
public:
	/* TdxPSContainerReportLinkCustomCache.Create */ inline __fastcall virtual TdxPSLayoutItemProducerCache(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : TdxPSCustomLayoutObjectProducerCache(AReportLink) { }
	
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxPSLayoutItemProducerCache(void) { }
	
};


class DELPHICLASS TdxPSLayoutLookAndFeelProducerCache;
class PASCALIMPLEMENTATION TdxPSLayoutLookAndFeelProducerCache : public TdxPSCustomLayoutObjectProducerCache
{
	typedef TdxPSCustomLayoutObjectProducerCache inherited;
	
private:
	HIDESBASE TdxPSLayoutLookAndFeelProducer* __fastcall GetItem(int Index);
	TdxPSLayoutLookAndFeelProducer* __fastcall GetProducer(TdxPSLayoutLookAndFeelProducerClass AProducerClass, Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* ALayoutLookAndFeel);
	
protected:
	__property TdxPSLayoutLookAndFeelProducer* Items[int Index] = {read=GetItem};
	
public:
	__property TdxPSLayoutLookAndFeelProducer* Producers[TdxPSLayoutLookAndFeelProducerClass AProducerClass][Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* ALayoutLookAndFeel] = {read=GetProducer/*, default*/};
public:
	/* TdxPSContainerReportLinkCustomCache.Create */ inline __fastcall virtual TdxPSLayoutLookAndFeelProducerCache(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : TdxPSCustomLayoutObjectProducerCache(AReportLink) { }
	
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TdxPSLayoutLookAndFeelProducerCache(void) { }
	
};


class DELPHICLASS TdxPSNativeLayoutControlProducer;
class PASCALIMPLEMENTATION TdxPSNativeLayoutControlProducer : public Dxpscontainerlnk::TdxPSNativePrintableControlProducer
{
	typedef Dxpscontainerlnk::TdxPSNativePrintableControlProducer inherited;
	
public:
	HIDESBASE Dxlayoutcontrol::TdxCustomLayoutControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSNativeLayoutControlProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSNativePrintableControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSNativeLayoutControlProducer(void) { }
	
};


class DELPHICLASS TdxPSLayoutControlProducer;
class PASCALIMPLEMENTATION TdxPSLayoutControlProducer : public Dxpscontainerlnk::TdxPSRootContainerProducer
{
	typedef Dxpscontainerlnk::TdxPSRootContainerProducer inherited;
	
private:
	System::Types::TRect __fastcall GetAvailableBounds(void);
	HIDESBASE TdxPSCustomLayoutItemProducer* __fastcall GetProducer(Dxlayoutcontainer::TdxCustomLayoutItem* LayoutItem);
	
protected:
	virtual void __fastcall CreateLayoutItems(Dxpscore::TdxReportVisualItem* AnItem);
	void __fastcall GetLayoutItemList(System::Classes::TList* AnItems);
	virtual Dxpscore::TdxReportCellClass __fastcall HostClass(void);
	virtual void __fastcall InitializeHost(Dxpscore::TdxReportCell* ACell);
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	virtual Dxpscore::TdxReportVisualItemClass __fastcall ItemClass(void);
	void __fastcall ReportLinkInitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	__property System::Types::TRect AvailableBounds = {read=GetAvailableBounds};
	__property TdxPSCustomLayoutItemProducer* Producers[Dxlayoutcontainer::TdxCustomLayoutItem* LayoutItem] = {read=GetProducer};
	
public:
	__classmethod virtual bool __fastcall CanHasAvailableChildren();
	__classmethod virtual bool __fastcall Reenterable();
	HIDESBASE Dxlayoutcontrol::TdxLayoutControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
	__classmethod virtual bool __fastcall HasNativeSupportForBorders();
	virtual bool __fastcall ObjectExpandHeight(void);
	virtual bool __fastcall ObjectExpandWidth(void);
	HIDESBASE TdxLayoutControlReportLink* __fastcall ReportLink(void)/* overload */;
	virtual void __fastcall Reposition(void);
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSLayoutControlProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSLayoutControlProducer(void) { }
	
};


struct TdxPSLayoutCacheFontItem;
typedef TdxPSLayoutCacheFontItem *PdxPSLayoutCacheFontItem;

struct DECLSPEC_DRECORD TdxPSLayoutCacheFontItem
{
public:
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelCaptionOptions* CaptionOptions;
	int FontIndex;
};


typedef System::TMetaClass* TdxLayoutControlReportLinkOptionsBehaviorClass;

class DELPHICLASS TdxLayoutControlReportLinkOptionsBehavior;
class PASCALIMPLEMENTATION TdxLayoutControlReportLinkOptionsBehavior : public Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPagination
{
	typedef Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPagination inherited;
	
private:
	bool FActiveTabToTop;
	bool FExpandGroups;
	bool FSkipEmptyGroups;
	bool FUnwrapTabs;
	void __fastcall SetActiveTabToTop(bool Value);
	void __fastcall SetExpandGroups(bool Value);
	void __fastcall SetSkipEmptyGroups(bool Value);
	void __fastcall SetUnwrapTabs(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool ActiveTabToTop = {read=FActiveTabToTop, write=SetActiveTabToTop, default=1};
	__property bool ExpandGroups = {read=FExpandGroups, write=SetExpandGroups, default=1};
	__property bool SkipEmptyGroups = {read=FSkipEmptyGroups, write=SetSkipEmptyGroups, default=1};
	__property bool UnwrapTabs = {read=FUnwrapTabs, write=SetUnwrapTabs, default=0};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxLayoutControlReportLinkOptionsBehavior(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPagination(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutControlReportLinkOptionsBehavior(void) { }
	
};


typedef System::TMetaClass* TdxLayoutControlReportLinkOptionsPaginationClass;

class PASCALIMPLEMENTATION TdxLayoutControlReportLinkOptionsPagination : public Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPagination
{
	typedef Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPagination inherited;
	
private:
	bool FGroups;
	bool FItems;
	void __fastcall SetGroups(bool Value);
	void __fastcall SetItems(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool Groups = {read=FGroups, write=SetGroups, default=1};
	__property bool Items = {read=FItems, write=SetItems, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxLayoutControlReportLinkOptionsPagination(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPagination(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutControlReportLinkOptionsPagination(void) { }
	
};


typedef System::TMetaClass* TdxLayoutControlReportLinkOptionsSizeClass;

class DELPHICLASS TdxLayoutControlReportLinkOptionsSize;
class PASCALIMPLEMENTATION TdxLayoutControlReportLinkOptionsSize : public Dxpscontainerlnk::TdxCustomContainerReportLinkOptions
{
	typedef Dxpscontainerlnk::TdxCustomContainerReportLinkOptions inherited;
	
private:
	bool FAutoWidth;
	void __fastcall SetAutoWidth(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxLayoutControlReportLinkOptionsSize(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : Dxpscontainerlnk::TdxCustomContainerReportLinkOptions(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutControlReportLinkOptionsSize(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutControlReportLinkOptionsTransparent : public Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsTransparent
{
	typedef Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsTransparent inherited;
	
private:
	bool FGroups;
	bool FItems;
	void __fastcall SetGroups(bool Value);
	void __fastcall SetItems(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool Groups = {read=FGroups, write=SetGroups, default=1};
	__property bool Items = {read=FItems, write=SetItems, default=1};
public:
	/* TdxCustomContainerReportLinkOptions.Create */ inline __fastcall virtual TdxLayoutControlReportLinkOptionsTransparent(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink) : Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsTransparent(AReportLink) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutControlReportLinkOptionsTransparent(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutControlReportLink : public Dxpscontainerlnk::TdxCustomContainerReportLink
{
	typedef Dxpscontainerlnk::TdxCustomContainerReportLink inherited;
	
private:
	System::Classes::TList* FCachedBounds;
	System::Classes::TList* FCachedFonts;
	Dxlayoutcontainer::TdxCustomLayoutItem* FCurrentLayoutItem;
	TdxPSLayoutItemProducerCache* FLayoutItemProducerCache;
	TdxPSLayoutLookAndFeelProducerCache* FLayoutLookAndFeelProducerCache;
	TdxLayoutControlReportLinkOptionsBehavior* FOptionsBehavior;
	TdxLayoutControlReportLinkOptionsSize* FOptionsSize;
	System::Types::TRect __fastcall GetAvailableBounds(void);
	int __fastcall GetCachedBoundsCount(void);
	TdxLCBoundsCacheItem* __fastcall GetCachedBoundsItem(int Index);
	PdxPSLayoutCacheFontItem __fastcall GetCachedFontItem(int Index);
	int __fastcall GetCachedFontItemCount(void);
	Dxpscore::TdxReportCell* __fastcall GetCurrentHost(void);
	Dxlayoutcontrol::TdxLayoutControl* __fastcall GetLayoutControl(void);
	TdxPSCustomLayoutItemProducer* __fastcall GetLayoutItemProducer(Dxlayoutcontainer::TdxCustomLayoutItem* LayoutItem);
	TdxPSLayoutLookAndFeelProducer* __fastcall GetLayoutLookAndFeelProducer(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel);
	TdxLayoutControlReportLinkOptionsPagination* __fastcall GetOptionsPagination(void);
	TdxLayoutControlReportLinkOptionsTransparent* __fastcall GetOptionsTransparent(void);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall GetRootLayoutGroup(void);
	HIDESBASE void __fastcall SetOptionsBehavior(TdxLayoutControlReportLinkOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsPagination(TdxLayoutControlReportLinkOptionsPagination* Value);
	void __fastcall SetOptionsSize(TdxLayoutControlReportLinkOptionsSize* Value);
	HIDESBASE void __fastcall SetOptionsTransparent(TdxLayoutControlReportLinkOptionsTransparent* Value);
	
protected:
	DYNAMIC bool __fastcall DoIsComponentProcessed(System::Classes::TComponent* AComponent);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual void __fastcall InternalRestoreDefaults(void);
	void __fastcall CacheControlsBounds(void);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	void __fastcall PostCheckEmbeddedControls(void);
	virtual void __fastcall PrepareConstruct(void);
	void __fastcall PrepareLookAndFeels(void);
	virtual void __fastcall RepositionControls(void);
	void __fastcall AddHiddenItem(Vcl::Comctrls::TTreeView* ATreeView, Vcl::Comctrls::TTreeNode* AParent, Dxlayoutcontainer::TdxCustomLayoutItem* AnItem);
	void __fastcall AddItem(Vcl::Comctrls::TTreeView* ATreeView, Vcl::Comctrls::TTreeNode* AParent, Dxlayoutcontainer::TdxCustomLayoutItem* AnItem);
	virtual bool __fastcall IsComponentEditable(System::Classes::TComponent* AComponent);
	virtual void __fastcall LoadControlsTree(Vcl::Comctrls::TTreeView* ATreeView);
	virtual void __fastcall LoadHiddenControlsTree(Vcl::Comctrls::TTreeView* ATreeView);
	int __fastcall AddBoundsToCache(System::Classes::TComponent* AComponent, const System::Types::TRect &ABounds);
	int __fastcall AddCaptionOptionsFontToCache(Dxlayoutlookandfeels::TdxLayoutLookAndFeelCaptionOptions* ACaptionOptions);
	void __fastcall ClearCachedBounds(void);
	void __fastcall ClearCachedFonts(void);
	bool __fastcall FindBoundsByComponent(System::Classes::TComponent* AComponent, System::Types::TRect &ABounds, bool ASetEmbedded);
	int __fastcall FindFontIndexByCaptionOptions(Dxlayoutlookandfeels::TdxLayoutLookAndFeelCaptionOptions* ACaptionOptions);
	void __fastcall FreeAndNilCachedBounds(void);
	void __fastcall FreeAndNilCachedFonts(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	DYNAMIC Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	virtual TdxLayoutControlReportLinkOptionsSizeClass __fastcall GetOptionsSizeClass(void);
	DYNAMIC Dxpscontainerlnk::TdxCustomContainerReportLinkOptionsTransparentClass __fastcall GetOptionsTransparentClass(void);
	Dxpscore::TdxPSReportGroupLookAndFeel* __fastcall FindReportGroupLookAndFeel(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* ALayoutLookAndFeel);
	Dxpscore::TdxReportCell* __fastcall FindReportItemByLayoutItem(Dxlayoutcontainer::TdxCustomLayoutItem* ALayoutItem);
	void __fastcall GetLayoutItemList(Dxlayoutcontrol::TdxLayoutControl* AControl, System::Classes::TList* AnItems);
	virtual System::Types::TRect __fastcall GetControlSiteBounds(Vcl::Controls::TControl* AControl);
	void __fastcall AdjustLayoutBounds(const System::Types::TRect &R);
	__property System::Types::TRect AvailableBounds = {read=GetAvailableBounds};
	__property int CachedBoundsCount = {read=GetCachedBoundsCount, nodefault};
	__property TdxLCBoundsCacheItem* CachedBoundsItem[int Index] = {read=GetCachedBoundsItem};
	__property System::Classes::TList* CachedBounds = {read=FCachedBounds};
	__property int CachedFontItemCount = {read=GetCachedFontItemCount, nodefault};
	__property PdxPSLayoutCacheFontItem CachedFontItems[int Index] = {read=GetCachedFontItem};
	__property System::Classes::TList* CachedFonts = {read=FCachedFonts};
	__property Dxpscore::TdxReportCell* CurrentHost = {read=GetCurrentHost};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* CurrentLayoutItem = {read=FCurrentLayoutItem, write=FCurrentLayoutItem};
	__property TdxPSLayoutItemProducerCache* LayoutItemProducerCache = {read=FLayoutItemProducerCache};
	__property TdxPSCustomLayoutItemProducer* LayoutItemProducers[Dxlayoutcontainer::TdxCustomLayoutItem* LayoutItem] = {read=GetLayoutItemProducer};
	__property TdxPSLayoutLookAndFeelProducerCache* LayoutLookAndFeelProducerCache = {read=FLayoutLookAndFeelProducerCache};
	__property TdxPSLayoutLookAndFeelProducer* LayoutLookAndFeelProducers[Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel] = {read=GetLayoutLookAndFeelProducer};
	__property Dxlayoutcontainer::TdxLayoutGroup* RootLayoutGroup = {read=GetRootLayoutGroup};
	
public:
	__fastcall virtual TdxLayoutControlReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutControlReportLink(void);
	__classmethod virtual bool __fastcall Aggregable();
	__property Dxlayoutcontrol::TdxLayoutControl* LayoutControl = {read=GetLayoutControl};
	
__published:
	__property TdxLayoutControlReportLinkOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TdxLayoutControlReportLinkOptionsPagination* OptionsPagination = {read=GetOptionsPagination, write=SetOptionsPagination};
	__property TdxLayoutControlReportLinkOptionsSize* OptionsSize = {read=FOptionsSize, write=SetOptionsSize};
	__property TdxLayoutControlReportLinkOptionsTransparent* OptionsTransparent = {read=GetOptionsTransparent, write=SetOptionsTransparent};
private:
	void *__IdxReportLinkController;	/* Dxpscore::IdxReportLinkController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {120F53E4-1B09-46EF-B42D-04AB8BBCC374}
	operator Dxpscore::_di_IdxReportLinkController()
	{
		Dxpscore::_di_IdxReportLinkController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscore::IdxReportLinkController*(void) { return (Dxpscore::IdxReportLinkController*)&__IdxReportLinkController; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxReportLinkController; }
	#endif
	
};


class DELPHICLASS TdxPSLayoutControlDesignWindow;
class PASCALIMPLEMENTATION TdxPSLayoutControlDesignWindow : public Dxpscontainerlnk::TdxfmCustomContainerDesignWindow
{
	typedef Dxpscontainerlnk::TdxfmCustomContainerDesignWindow inherited;
	
private:
	TdxLayoutControlReportLink* __fastcall GetLayoutReportLink(void);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual void __fastcall SetOptionsGroupsByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsPaginationByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsSizeByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsTabsByIndex(int AnIndex, bool AValue);
	virtual void __fastcall SetOptionsTransparentByIndex(int AnIndex, bool AValue);
	virtual void __fastcall InitializeControlsTree(void);
	virtual void __fastcall InitializeHiddenControlsTree(void);
	virtual bool __fastcall IsBoldNode(Vcl::Comctrls::TTreeNode* ANode);
	
public:
	__property TdxLayoutControlReportLink* LayoutReportLink = {read=GetLayoutReportLink};
public:
	/* TdxfmCustomContainerDesignWindow.Create */ inline __fastcall virtual TdxPSLayoutControlDesignWindow(System::Classes::TComponent* AOwner) : Dxpscontainerlnk::TdxfmCustomContainerDesignWindow(AOwner) { }
	/* TdxfmCustomContainerDesignWindow.Destroy */ inline __fastcall virtual ~TdxPSLayoutControlDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxPSLayoutControlDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscontainerlnk::TdxfmCustomContainerDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSLayoutControlDesignWindow(HWND ParentWindow) : Dxpscontainerlnk::TdxfmCustomContainerDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsdxlclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDXLCLNK)
using namespace Dxpsdxlclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdxlclnkHPP
