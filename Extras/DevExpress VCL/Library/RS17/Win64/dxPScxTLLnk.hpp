// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxTLLnk.pas' rev: 24.00 (Win64)

#ifndef DxpscxtllnkHPP
#define DxpscxtllnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxDBTL.hpp>	// Pascal unit
#include <cxTLData.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxtllnk
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxTreeListNodeClass;

typedef System::TMetaClass* TcxTreeListAdapterClass;

typedef System::TMetaClass* TcxTreeListReportLinkFormatterClass;

typedef System::TMetaClass* TcxTreeListReportLinkBuilderClass;

typedef System::TMetaClass* TcxTreeListAttributeClass;

class DELPHICLASS TcxTreeListAttribute;
class PASCALIMPLEMENTATION TcxTreeListAttribute : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListAttribute(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListAttribute(void) { }
	
};


class DELPHICLASS TcxTreeListBandAttribute;
class PASCALIMPLEMENTATION TcxTreeListBandAttribute : public TcxTreeListAttribute
{
	typedef TcxTreeListAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListBandAttribute(void) : TcxTreeListAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListBandAttribute(void) { }
	
};


class DELPHICLASS TcxTreeListNodeAttribute;
class PASCALIMPLEMENTATION TcxTreeListNodeAttribute : public TcxTreeListAttribute
{
	typedef TcxTreeListAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListNodeAttribute(void) : TcxTreeListAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListNodeAttribute(void) { }
	
};


class DELPHICLASS TcxTreeListFooterAttribute;
class PASCALIMPLEMENTATION TcxTreeListFooterAttribute : public TcxTreeListAttribute
{
	typedef TcxTreeListAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListFooterAttribute(void) : TcxTreeListAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListFooterAttribute(void) { }
	
};


class DELPHICLASS TcxTreeListHeaderAttribute;
class PASCALIMPLEMENTATION TcxTreeListHeaderAttribute : public TcxTreeListAttribute
{
	typedef TcxTreeListAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListHeaderAttribute(void) : TcxTreeListAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListHeaderAttribute(void) { }
	
};


class DELPHICLASS TcxTreeListIndentsRowAttribute;
class PASCALIMPLEMENTATION TcxTreeListIndentsRowAttribute : public TcxTreeListAttribute
{
	typedef TcxTreeListAttribute inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxTreeListIndentsRowAttribute(void) : TcxTreeListAttribute() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListIndentsRowAttribute(void) { }
	
};


typedef int TcxTreeListAttributeID;

struct DECLSPEC_DRECORD TcxTreeListCellCustomDrawInfo
{
public:
	TcxTreeListAttributeID AttributeID;
	Cxtl::TcxTreeListBand* Band;
	Cxtl::TcxTreeListColumn* Column;
	Cxtl::TcxTreeListNode* Node;
	int Index;
};


typedef System::TMetaClass* TcxTreeListReportLinkRowProducerClass;

class DELPHICLASS TcxTreeListReportLinkRowProducer;
class DELPHICLASS TcxTreeListReportLinkBuilder;
class DELPHICLASS TcxTreeListAttributeHostInfo;
class DELPHICLASS TcxTreeListAdapter;
class DELPHICLASS TcxTreeListReportLinkFormatter;
class PASCALIMPLEMENTATION TcxTreeListReportLinkRowProducer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxTreeListReportLinkBuilder* FBuilder;
	Dxpscore::TdxReportCell* FHost;
	Dxpscore::TdxReportCell* FRow;
	int FRowHeight;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void);
	int __fastcall GetIndentWidth(void);
	int __fastcall GetRowWidth(void);
	
protected:
	virtual void __fastcall AfterCalculateRowHeight(void);
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateRowHost(TcxTreeListAttributeHostInfo* const AHostInfo);
	virtual bool __fastcall DoesItemParticipateInRowAutoHeightCalculation(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall FixupRowHeight(void);
	virtual void __fastcall FixupRowItselfHeight(void);
	virtual void __fastcall InitializeRow(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	
public:
	__fastcall virtual TcxTreeListReportLinkRowProducer(TcxTreeListReportLinkBuilder* ABuilder);
	virtual TcxTreeListAdapter* __fastcall Adapter(void)/* overload */;
	virtual TcxTreeListReportLinkBuilder* __fastcall Builder(void)/* overload */;
	virtual TcxTreeListReportLinkFormatter* __fastcall Formatter(void)/* overload */;
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TcxTreeListAttributeHostInfo* AHostInfo);
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property Dxpscore::TdxReportCell* Host = {read=FHost};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int LineHeight = {read=GetLineHeight, nodefault};
	__property Dxpscore::TdxReportCell* Row = {read=FRow};
	__property int RowHeight = {read=FRowHeight, write=FRowHeight, nodefault};
	__property int RowWidth = {read=GetRowWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkRowProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkNodeSeparatorProducerClass;

class DELPHICLASS TcxTreeListReportLinkNodeSeparatorProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkNodeSeparatorProducer : public TcxTreeListReportLinkRowProducer
{
	typedef TcxTreeListReportLinkRowProducer inherited;
	
private:
	Dxpscore::TAbstractdxReportCellData* FItem;
	
protected:
	virtual void __fastcall InitializeItem(void);
	virtual void __fastcall InitializeRow(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetItemClass(void);
	virtual int __fastcall GetLineHeight(void);
	
public:
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TcxTreeListAttributeHostInfo* AHostInfo);
public:
	/* TcxTreeListReportLinkRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkNodeSeparatorProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkRowProducer(ABuilder) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkNodeSeparatorProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkRowSubItemsProducerClass;

class DELPHICLASS TcxTreeListReportLinkRowSubItemsProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkRowSubItemsProducer : public TcxTreeListReportLinkRowProducer
{
	typedef TcxTreeListReportLinkRowProducer inherited;
	
private:
	Cxtl::TcxTreeListColumn* __fastcall GetColumn(int Index);
	
protected:
	virtual void __fastcall CreateDataItems(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AnIndex);
	virtual bool __fastcall GetHasSubItem(int Index);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index) = 0 ;
	virtual int __fastcall GetSubItemCount(void);
	
public:
	__property Cxtl::TcxTreeListColumn* Columns[int Index] = {read=GetColumn};
	__property bool HasSubItem[int Index] = {read=GetHasSubItem};
	__property System::Types::TRect SubItemBounds[int Index] = {read=GetSubItemBound};
	__property Dxpscore::TdxReportCellDataClass SubItemClasses[int Index] = {read=GetSubItemClass};
	__property int SubItemCount = {read=GetSubItemCount, nodefault};
public:
	/* TcxTreeListReportLinkRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkRowSubItemsProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkRowProducer(ABuilder) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkRowSubItemsProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkBandsProducerClass;

class DELPHICLASS TcxTreeListReportLinkBandsProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkBandsProducer : public TcxTreeListReportLinkRowSubItemsProducer
{
	typedef TcxTreeListReportLinkRowSubItemsProducer inherited;
	
protected:
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AnIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
	virtual int __fastcall GetSubItemCount(void);
public:
	/* TcxTreeListReportLinkRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkBandsProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkRowSubItemsProducer(ABuilder) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkBandsProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkFootersProducerClass;

class DELPHICLASS TcxTreeListReportLinkBandedRowProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkBandedRowProducer : public TcxTreeListReportLinkRowProducer
{
	typedef TcxTreeListReportLinkRowProducer inherited;
	
private:
	System::Classes::TList* FIndents;
	Dxpscore::TdxReportCellExpandButton* __fastcall GetIndent(int Index);
	
protected:
	virtual void __fastcall AfterCalculateRowHeight(void);
	virtual void __fastcall CreateBandedDataItems(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateBandedRows(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateIndents(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateIndentsRow(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	virtual System::Types::TRect __fastcall GetBandedDataItemBounds(Dxpscore::TAbstractdxReportCellData* AItem);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetBandedDataItemClass(Cxtl::TcxTreeListColumn* AColumn);
	virtual int __fastcall GetBandedRowIndent(void);
	virtual int __fastcall GetIndentArea(void);
	virtual System::Types::TRect __fastcall GetIndentBound(int AIndex);
	virtual int __fastcall GetIndentCount(void);
	virtual void __fastcall InitializeBandedDataItem(Dxpscore::TAbstractdxReportCellData* AItem);
	virtual void __fastcall InitializeBandedRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex);
	__property int IndentArea = {read=GetIndentArea, nodefault};
	__property System::Types::TRect IndentBounds[int Index] = {read=GetIndentBound};
	__property int IndentCount = {read=GetIndentCount, nodefault};
	__property Dxpscore::TdxReportCellExpandButton* Indents[int Index] = {read=GetIndent};
	
public:
	__fastcall virtual TcxTreeListReportLinkBandedRowProducer(TcxTreeListReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxTreeListReportLinkBandedRowProducer(void);
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TcxTreeListAttributeHostInfo* AHostInfo);
};


class DELPHICLASS TcxTreeListReportLinkFootersProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkFootersProducer : public TcxTreeListReportLinkBandedRowProducer
{
	typedef TcxTreeListReportLinkBandedRowProducer inherited;
	
private:
	Cxtl::TcxTreeListNode* FAttachedNode;
	Cxtl::TcxTreeListNode* FDataNode;
	
protected:
	virtual void __fastcall CreateBandedDataItems(Dxpscore::TdxReportCell* AParent);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetBandedRowIndent(void);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual void __fastcall InitializeBandedRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex);
	virtual void __fastcall InitializeRow(void);
	
public:
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TcxTreeListAttributeHostInfo* AHostInfo, Cxtl::TcxTreeListNode* AAttachedNode, Cxtl::TcxTreeListNode* ADataNode);
public:
	/* TcxTreeListReportLinkBandedRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkFootersProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkBandedRowProducer(ABuilder) { }
	/* TcxTreeListReportLinkBandedRowProducer.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkFootersProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkHeadersProducerClass;

class DELPHICLASS TcxTreeListReportLinkHeadersProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkHeadersProducer : public TcxTreeListReportLinkRowSubItemsProducer
{
	typedef TcxTreeListReportLinkRowSubItemsProducer inherited;
	
protected:
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSubItem(Dxpscore::TAbstractdxReportCellData* ASubItem, int AnIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual System::Types::TRect __fastcall GetSubItemBound(int Index);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetSubItemClass(int Index);
public:
	/* TcxTreeListReportLinkRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkHeadersProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkRowSubItemsProducer(ABuilder) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkHeadersProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkNodeProducerClass;

class DELPHICLASS TcxTreeListReportLinkNodeProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkNodeProducer : public TcxTreeListReportLinkBandedRowProducer
{
	typedef TcxTreeListReportLinkBandedRowProducer inherited;
	
private:
	Dxpscore::TdxCustomReportCellCheck* FCheck;
	Dxpscore::TdxReportCellGraphic* FImage;
	Cxtl::TcxTreeListNode* FNode;
	Dxpscore::TAbstractdxReportCellData* FPreviewItem;
	Dxpscore::TdxReportCellGraphic* FStateImage;
	int __fastcall GetCheckIndentIndex(void);
	int __fastcall GetImageIndentIndex(void);
	Cxtl::TcxTreeListColumn* __fastcall GetPreviewColumn(void);
	Cxtl::TcxTreeListPreviewPlace __fastcall GetPreviewPlace(void);
	int __fastcall GetStateImageIndentIndex(void);
	
protected:
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall CreateChecks(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateIcons(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateImages(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateIndents(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreatePreview(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateStateImages(Dxpscore::TdxReportCell* AParent);
	virtual bool __fastcall DoesItemParticipateInRowAutoHeightCalculation(Dxpscore::TdxReportVisualItem* AnItem);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall InitializeBandedDataItem(Dxpscore::TAbstractdxReportCellData* AItem);
	virtual void __fastcall InitializeBandedRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall InitializeCheck(void);
	virtual void __fastcall InitializeImage(int AnIndex);
	virtual void __fastcall InitializeIndent(Dxpscore::TdxReportCellExpandButton* AnIndent, int AnIndex);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeStateImage(int AnIndex);
	bool __fastcall IsItemIndent(Dxpscore::TdxReportVisualItem* AnItem);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Types::TRect __fastcall GetBandedDataItemBounds(Dxpscore::TAbstractdxReportCellData* AItem);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetBandedDataItemClass(Cxtl::TcxTreeListColumn* AColumn);
	virtual int __fastcall GetBandedRowIndent(void);
	virtual bool __fastcall GetCellAutoHeight(void);
	virtual System::Types::TRect __fastcall GetCheckRect(void);
	virtual bool __fastcall GetHasPreview(void);
	virtual System::Types::TRect __fastcall GetImageRect(void);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetLineHeight(void);
	virtual int __fastcall GetPreviewHeight(void);
	virtual int __fastcall GetPreviewIndent(void);
	virtual int __fastcall GetPreviewLineCount(void);
	virtual int __fastcall GetPreviewLineHeight(void);
	virtual System::Types::TRect __fastcall GetStateImageRect(void);
	
public:
	HIDESBASE virtual Dxpscore::TdxReportCell* __fastcall Produce(TcxTreeListAttributeHostInfo* AHostInfo, Cxtl::TcxTreeListNode* ANode);
	__property bool CellAutoHeight = {read=GetCellAutoHeight, nodefault};
	__property int CheckIndentIndex = {read=GetCheckIndentIndex, nodefault};
	__property System::Types::TRect CheckRect = {read=GetCheckRect};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property Dxpscore::TdxReportCellGraphic* Image = {read=FImage};
	__property int ImageIndentIndex = {read=GetImageIndentIndex, nodefault};
	__property System::Types::TRect ImageRect = {read=GetImageRect};
	__property Cxtl::TcxTreeListColumn* PreviewColumn = {read=GetPreviewColumn};
	__property int PreviewHeight = {read=GetPreviewHeight, nodefault};
	__property int PreviewIndent = {read=GetPreviewIndent, nodefault};
	__property Dxpscore::TAbstractdxReportCellData* PreviewItem = {read=FPreviewItem};
	__property int PreviewLineCount = {read=GetPreviewLineCount, nodefault};
	__property int PreviewLineHeight = {read=GetPreviewLineHeight, nodefault};
	__property Cxtl::TcxTreeListPreviewPlace PreviewPlace = {read=GetPreviewPlace, nodefault};
	__property Dxpscore::TdxReportCellGraphic* StateImage = {read=FStateImage};
	__property int StateImageIndentIndex = {read=GetStateImageIndentIndex, nodefault};
	__property System::Types::TRect StateImageRect = {read=GetStateImageRect};
public:
	/* TcxTreeListReportLinkBandedRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkNodeProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkBandedRowProducer(ABuilder) { }
	/* TcxTreeListReportLinkBandedRowProducer.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkNodeProducer(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkCategorizedNodeProducer;
class PASCALIMPLEMENTATION TcxTreeListReportLinkCategorizedNodeProducer : public TcxTreeListReportLinkNodeProducer
{
	typedef TcxTreeListReportLinkNodeProducer inherited;
	
protected:
	virtual void __fastcall CreateBandedRows(Dxpscore::TdxReportCell* AParent);
public:
	/* TcxTreeListReportLinkBandedRowProducer.Create */ inline __fastcall virtual TcxTreeListReportLinkCategorizedNodeProducer(TcxTreeListReportLinkBuilder* ABuilder) : TcxTreeListReportLinkNodeProducer(ABuilder) { }
	/* TcxTreeListReportLinkBandedRowProducer.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkCategorizedNodeProducer(void) { }
	
};


typedef System::TMetaClass* TcxTreeListNodeHelperClass;

class DELPHICLASS TcxTreeListNodeHelper;
class PASCALIMPLEMENTATION TcxTreeListNodeHelper : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	TcxTreeListAdapter* FAdapter;
	Cxtl::TcxTreeListNode* FNode;
	
protected:
	virtual TcxTreeListAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TcxTreeListNodeClass __fastcall NodeClass();
	virtual bool __fastcall GetHasSelectedChildren(void);
	virtual bool __fastcall GetHasSelectedParents(void);
	
public:
	__fastcall virtual TcxTreeListNodeHelper(TcxTreeListAdapter* AnAdapter);
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod virtual TcxTreeListReportLinkNodeProducerClass __fastcall ProducerClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__property bool HasSelectedChildren = {read=GetHasSelectedChildren, nodefault};
	__property bool HasSelectedParents = {read=GetHasSelectedParents, nodefault};
	__property Cxtl::TcxTreeListNode* Node = {read=FNode, write=FNode};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListNodeHelper(void) { }
	
};


class DELPHICLASS TcxTreeListNodeHelperCache;
class PASCALIMPLEMENTATION TcxTreeListNodeHelperCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
public:
	TcxTreeListNodeHelper* operator[](Cxtl::TcxTreeListNode* Node) { return Helpers[Node]; }
	
private:
	TcxTreeListAdapter* FAdapter;
	TcxTreeListNodeHelper* __fastcall GetHelper(Cxtl::TcxTreeListNode* Node);
	HIDESBASE TcxTreeListNodeHelper* __fastcall GetItem(int Index);
	
protected:
	int __fastcall IndexOf(Cxtl::TcxTreeListNode* Node);
	__property TcxTreeListNodeHelper* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TcxTreeListNodeHelperCache(TcxTreeListAdapter* AnAdapter);
	__property TcxTreeListAdapter* Adapter = {read=FAdapter};
	__property TcxTreeListNodeHelper* Helpers[Cxtl::TcxTreeListNode* Node] = {read=GetHelper/*, default*/};
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TcxTreeListNodeHelperCache(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkProducerCache;
class PASCALIMPLEMENTATION TcxTreeListReportLinkProducerCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
public:
	TcxTreeListReportLinkRowProducer* operator[](TcxTreeListReportLinkRowProducerClass ProducerClass) { return Producers[ProducerClass]; }
	
private:
	TcxTreeListReportLinkBuilder* FBuilder;
	HIDESBASE TcxTreeListReportLinkRowProducer* __fastcall GetItem(int Index);
	TcxTreeListReportLinkRowProducer* __fastcall GetProducer(TcxTreeListReportLinkRowProducerClass ProducerClass);
	
protected:
	int __fastcall IndexOf(TcxTreeListReportLinkRowProducerClass AProducerClass);
	__property TcxTreeListReportLinkRowProducer* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TcxTreeListReportLinkProducerCache(TcxTreeListReportLinkBuilder* ABuilder);
	__property TcxTreeListReportLinkBuilder* Builder = {read=FBuilder};
	__property TcxTreeListReportLinkRowProducer* Producers[TcxTreeListReportLinkRowProducerClass ProducerClass] = {read=GetProducer/*, default*/};
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkProducerCache(void) { }
	
};


class DELPHICLASS TcxTreeListCustomReportLink;
class PASCALIMPLEMENTATION TcxTreeListReportLinkBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxTreeListAdapter* FAdapter;
	TcxTreeListReportLinkFormatter* FFormatter;
	TcxTreeListReportLinkProducerCache* FProducerCache;
	TcxTreeListCustomReportLink* FReportLink;
	System::Classes::TList* FReportRows;
	Dxpscore::TdxReportCell* __fastcall GetHost(void);
	Dxpscore::TdxReportCells* __fastcall GetReportCells(void);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	int __fastcall GetReportRowCount(void);
	Cxtl::TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	void __fastcall AddReportRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall CreateBands(void);
	TcxTreeListReportLinkBandsProducer* __fastcall GetBandsProducer(void);
	virtual TcxTreeListReportLinkBandsProducerClass __fastcall GetBandsProducerClass(void);
	virtual void __fastcall CreateFooters(TcxTreeListAttributeHostInfo* AHostInfo, Cxtl::TcxTreeListNode* AAttachedNode, Cxtl::TcxTreeListNode* ADataNode);
	TcxTreeListReportLinkFootersProducer* __fastcall GetFootersProducer(void);
	virtual TcxTreeListReportLinkFootersProducerClass __fastcall GetFootersProducerClass(void);
	virtual void __fastcall CreateHeaders(void);
	TcxTreeListReportLinkHeadersProducer* __fastcall GetHeadersProducer(void);
	virtual TcxTreeListReportLinkHeadersProducerClass __fastcall GetHeadersProducerClass(void);
	virtual void __fastcall CreateNode(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall CreateNodes(void);
	TcxTreeListReportLinkNodeProducer* __fastcall GetNodeProducer(Cxtl::TcxTreeListNode* ANode);
	virtual TcxTreeListReportLinkNodeProducerClass __fastcall GetNodeProducerClass(Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall CreateNodeSeparator(Cxtl::TcxTreeListNode* ANode);
	TcxTreeListReportLinkNodeSeparatorProducer* __fastcall GetNodeSeparatorProducer(void);
	virtual TcxTreeListReportLinkNodeSeparatorProducerClass __fastcall GetNodeSeparatorProducerClass(void);
	virtual void __fastcall DoBuild(void);
	bool __fastcall IsAborted(void);
	__property TcxTreeListReportLinkProducerCache* ProducerCache = {read=FProducerCache};
	__property TcxTreeListCustomReportLink* ReportLink = {read=FReportLink};
	
public:
	__fastcall virtual TcxTreeListReportLinkBuilder(TcxTreeListCustomReportLink* AReportLink);
	__fastcall virtual ~TcxTreeListReportLinkBuilder(void);
	virtual void __fastcall Build(void);
	void __fastcall Progress(const double APercentDone);
	virtual TcxTreeListAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TcxTreeListAdapterClass __fastcall AdapterClass();
	virtual TcxTreeListReportLinkFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TcxTreeListReportLinkFormatterClass __fastcall FormatterClass();
	__property Dxpscore::TdxReportCell* Host = {read=GetHost};
	__property Dxpscore::TdxReportCells* ReportCells = {read=GetReportCells};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow};
	__property Cxtl::TcxCustomTreeList* TreeList = {read=GetTreeList};
};


class DELPHICLASS TcxTreeListReportLinkBuilderHandler;
class PASCALIMPLEMENTATION TcxTreeListReportLinkBuilderHandler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxTreeListReportLinkBuilder* FBuilder;
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
public:
	__fastcall virtual TcxTreeListReportLinkBuilderHandler(TcxTreeListReportLinkBuilder* ABuilder);
	virtual TcxTreeListReportLinkBuilder* __fastcall Builder(void)/* overload */;
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkBuilderHandler(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListAdapter : public TcxTreeListReportLinkBuilderHandler
{
	typedef TcxTreeListReportLinkBuilderHandler inherited;
	
private:
	int FDetailsLineCount;
	int FFooterLineCount;
	int FGroupFooterLineCount;
	TcxTreeListNodeHelperCache* FHelperCache;
	bool FMultiRows;
	bool __fastcall GetAutoWidth(void);
	Cxtl::TcxTreeListBand* __fastcall GetBand(int Index);
	int __fastcall GetBandCount(void);
	Cxtl::TcxTreeListBand* __fastcall GetBottomBand(int Index);
	int __fastcall GetBottomBandCount(void);
	bool __fastcall GetCanUseLookAndFeelColors(void);
	Cxtl::TcxTreeListColumn* __fastcall GetCategorizedColumn(void);
	bool __fastcall GetCellAutoHeight(void);
	bool __fastcall GetCellEndEllipsis(void);
	bool __fastcall GetCellMultiline(void);
	Cxtl::TcxTreeListColumn* __fastcall GetColumn(int Index);
	int __fastcall GetColumnCount(void);
	int __fastcall GetDefaultRowHeight(void);
	int __fastcall GetFooterLineCount(Cxtl::TcxTreeListNode* ANode);
	Cxtl::TcxTreeListGridLines __fastcall GetGridLines(void);
	System::Uitypes::TColor __fastcall GetGridLinesColor(void);
	bool __fastcall GetHasPreview(void);
	bool __fastcall GetHeaderAutoHeight(void);
	TcxTreeListNodeHelper* __fastcall GetHelper(Cxtl::TcxTreeListNode* Node);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	int __fastcall GetIndentWidth(void);
	bool __fastcall GetIsDefaultRowHeightAssigned(void);
	bool __fastcall GetIsNodeColorUsedForIndents(void);
	Cxlookandfeels::TcxLookAndFeelKind __fastcall GetLookAndFeelKind(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	bool __fastcall GetMultiSelection(void);
	Cxtl::TcxTreeListNode* __fastcall GetNode(int Index);
	int __fastcall GetNodeCount(void);
	Cxtl::TcxTreeListOptionsView* __fastcall GetOptionsView(void);
	Cxtl::TcxTreeListPaintStyle __fastcall GetPaintStyle(void);
	Cxtl::TcxTreeListColumn* __fastcall GetPreviewColumn(void);
	int __fastcall GetPreviewLeftIndent(void);
	Cxtl::TcxTreeListPreviewPlace __fastcall GetPreviewPlace(void);
	int __fastcall GetPreviewRightIndent(void);
	Cxtl::TcxTreeListBand* __fastcall GetRootBand(int Index);
	int __fastcall GetRootBandCount(void);
	bool __fastcall GetShowRoot(void);
	bool __fastcall GetShowHorzGridLines(void);
	bool __fastcall GetShowTreeLines(void);
	bool __fastcall GetShowVertGridLines(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	Cxtl::TcxTreeListStyles* __fastcall GetStyles(void);
	System::Uitypes::TColor __fastcall GetThemedBandHeaderItemColor(void);
	System::Uitypes::TColor __fastcall GetThemedBandHeaderItemTextColor(void);
	System::Uitypes::TColor __fastcall GetThemedFooterItemColor(void);
	System::Uitypes::TColor __fastcall GetThemedFooterItemTextColor(void);
	System::Uitypes::TColor __fastcall GetThemedHeaderItemColor(void);
	System::Uitypes::TColor __fastcall GetThemedHeaderItemTextColor(void);
	System::Uitypes::TColor __fastcall GetThemedHeaderRowColor(void);
	System::Uitypes::TColor __fastcall GetTreeLinesColor(void);
	Cxtl::TcxTreeListTreeLineStyle __fastcall GetTreeLinesStyle(void);
	Cxtl::TcxCustomTreeList* __fastcall GetTreeList(void);
	bool __fastcall GetUseStylesForIndents(void);
	
protected:
	virtual int __fastcall CalculateDetailsLineCount(void);
	void __fastcall Calculate(void);
	__classmethod Cxedit::TcxCustomEditProperties* __fastcall GetProperties(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	__classmethod Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	__classmethod Cxedit::TcxEditRepositoryItem* __fastcall GetRepositoryItem(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual Cxgraphics::TcxViewParams __fastcall GetBackgroundViewParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetBandBackgroundViewParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetBandHeaderViewParams(Cxtl::TcxTreeListBand* ABand);
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnFooterViewParams(Cxtl::TcxTreeListColumn* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnHeaderViewParams(Cxtl::TcxTreeListColumn* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentViewParams(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetIndentViewParams(Cxtl::TcxTreeListNode* ANode, int AnIndent);
	virtual Cxgraphics::TcxViewParams __fastcall GetPreviewViewParams(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetFooterRowViewParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetSelectionViewParams(void);
	bool __fastcall HasSelectionStyle(void);
	Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(int Index);
	bool __fastcall HasBackgroundBitmap(int Index);
	void __fastcall DoGetLevelImages(int ALevel, Vcl::Imglist::TCustomImageList* &AImages, Vcl::Imglist::TCustomImageList* &AStateImages);
	int __fastcall GetCheckWidth(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall HasCheck(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsGroupNode(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall HasNodeAttachedFooter(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListNode* ASummaryNode);
	bool __fastcall HasNodeSummary(Cxtl::TcxTreeListNode* ANode);
	__property TcxTreeListNodeHelper* Helpers[Cxtl::TcxTreeListNode* Node] = {read=GetHelper};
	__property Cxlookandfeels::TcxLookAndFeelKind LookAndFeelKind = {read=GetLookAndFeelKind, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property Cxtl::TcxTreeListOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxtl::TcxTreeListStyles* Styles = {read=GetStyles};
	__property Cxtl::TcxCustomTreeList* TreeList = {read=GetTreeList};
	
public:
	__fastcall virtual TcxTreeListAdapter(TcxTreeListReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxTreeListAdapter(void);
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property int BandCount = {read=GetBandCount, nodefault};
	__property Cxtl::TcxTreeListBand* Bands[int Index] = {read=GetBand};
	__property int BottomBandCount = {read=GetBottomBandCount, nodefault};
	__property Cxtl::TcxTreeListBand* BottomBands[int Index] = {read=GetBottomBand};
	__property bool CanUseLookAndFeelColors = {read=GetCanUseLookAndFeelColors, nodefault};
	__property Cxtl::TcxTreeListColumn* CategorizedColumn = {read=GetCategorizedColumn};
	__property bool CellAutoHeight = {read=GetCellAutoHeight, nodefault};
	__property bool CellEndEllipsis = {read=GetCellEndEllipsis, nodefault};
	__property bool CellMultiline = {read=GetCellMultiline, nodefault};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property Cxtl::TcxTreeListColumn* Columns[int Index] = {read=GetColumn};
	__property int DefaultRowHeight = {read=GetDefaultRowHeight, nodefault};
	__property int DetailsLineCount = {read=FDetailsLineCount, nodefault};
	__property int FooterLineCount[Cxtl::TcxTreeListNode* ANode] = {read=GetFooterLineCount};
	__property Cxtl::TcxTreeListGridLines GridLines = {read=GetGridLines, nodefault};
	__property System::Uitypes::TColor GridLinesColor = {read=GetGridLinesColor, nodefault};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property bool HeaderAutoHeight = {read=GetHeaderAutoHeight, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property bool IsDefaultRowHeightAssigned = {read=GetIsDefaultRowHeightAssigned, nodefault};
	__property bool IsNodeColorUsedForIndents = {read=GetIsNodeColorUsedForIndents, nodefault};
	__property bool MultiSelection = {read=GetMultiSelection, nodefault};
	__property Cxtl::TcxTreeListPaintStyle PaintStyle = {read=GetPaintStyle, nodefault};
	__property Cxtl::TcxTreeListColumn* PreviewColumn = {read=GetPreviewColumn};
	__property int PreviewLeftIndent = {read=GetPreviewLeftIndent, nodefault};
	__property Cxtl::TcxTreeListPreviewPlace PreviewPlace = {read=GetPreviewPlace, nodefault};
	__property int PreviewRightIndent = {read=GetPreviewRightIndent, nodefault};
	__property int NodeCount = {read=GetNodeCount, nodefault};
	__property Cxtl::TcxTreeListNode* Nodes[int Index] = {read=GetNode};
	__property int RootBandCount = {read=GetRootBandCount, nodefault};
	__property Cxtl::TcxTreeListBand* RootBands[int Index] = {read=GetRootBand};
	__property bool ShowRoot = {read=GetShowRoot, nodefault};
	__property bool ShowHorzGridLines = {read=GetShowHorzGridLines, nodefault};
	__property bool ShowTreeLines = {read=GetShowTreeLines, nodefault};
	__property bool ShowVertGridLines = {read=GetShowVertGridLines, nodefault};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages};
	__property System::Uitypes::TColor ThemedBandHeaderItemColor = {read=GetThemedBandHeaderItemColor, nodefault};
	__property System::Uitypes::TColor ThemedBandHeaderItemTextColor = {read=GetThemedBandHeaderItemTextColor, nodefault};
	__property System::Uitypes::TColor ThemedFooterItemColor = {read=GetThemedFooterItemColor, nodefault};
	__property System::Uitypes::TColor ThemedFooterItemTextColor = {read=GetThemedFooterItemTextColor, nodefault};
	__property System::Uitypes::TColor ThemedHeaderItemColor = {read=GetThemedHeaderItemColor, nodefault};
	__property System::Uitypes::TColor ThemedHeaderItemTextColor = {read=GetThemedHeaderItemTextColor, nodefault};
	__property System::Uitypes::TColor ThemedHeaderRowColor = {read=GetThemedHeaderRowColor, nodefault};
	__property System::Uitypes::TColor TreeLinesColor = {read=GetTreeLinesColor, nodefault};
	__property Cxtl::TcxTreeListTreeLineStyle TreeLinesStyle = {read=GetTreeLinesStyle, nodefault};
	__property bool UseStylesForIndents = {read=GetUseStylesForIndents, nodefault};
};


class DELPHICLASS TcxTreeListCustomItemPlaceController;
class DELPHICLASS TcxTreeListColumnPlace;
class PASCALIMPLEMENTATION TcxTreeListCustomItemPlaceController : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxTreeListColumnPlace* operator[](Cxtl::TcxTreeListColumn* Column) { return ItemsByColumn[Column]; }
	
private:
	TcxTreeListReportLinkFormatter* FFormatter;
	int FHeaderLineCount;
	int FWidth;
	TcxTreeListAdapter* __fastcall GetAdapter(void);
	int __fastcall GetHeaderLineCount(void);
	int __fastcall GetWidth(void);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall CalculateHeaderLineCount(void);
	virtual TcxTreeListColumnPlace* __fastcall GetItemByColumn(Cxtl::TcxTreeListColumn* Column);
	virtual void __fastcall WidthChanged(void);
	
public:
	__fastcall virtual TcxTreeListCustomItemPlaceController(TcxTreeListReportLinkFormatter* AFormatter);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Refresh(void);
	__property TcxTreeListAdapter* Adapter = {read=GetAdapter};
	__property TcxTreeListReportLinkFormatter* Formatter = {read=FFormatter};
	__property int HeaderLineCount = {read=GetHeaderLineCount, nodefault};
	__property TcxTreeListColumnPlace* ItemsByColumn[Cxtl::TcxTreeListColumn* Column] = {read=GetItemByColumn/*, default*/};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListCustomItemPlaceController(void) { }
	
};


class DELPHICLASS TcxTreeListCustomBandPlace;
class PASCALIMPLEMENTATION TcxTreeListColumnPlace : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxtl::TcxTreeListColumn* FColumn;
	TcxTreeListCustomBandPlace* FController;
	int FLeftBound;
	int FWidth;
	TcxTreeListAdapter* __fastcall GetAdapter(void);
	System::Types::TRect __fastcall GetCellBounds(Cxtl::TcxTreeListNode* ANode);
	int __fastcall GetCellHeight(Cxtl::TcxTreeListNode* ANode);
	System::Types::TRect __fastcall GetFooterCellBounds(int AIndex);
	int __fastcall GetFooterLineHeight(void);
	TcxTreeListReportLinkFormatter* __fastcall GetFormatter(void);
	System::Types::TRect __fastcall GetHeaderCellBounds(void);
	int __fastcall GetHeaderLineHeight(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFixed(void);
	int __fastcall GetLeftBound(void);
	int __fastcall GetMinWidth(void);
	int __fastcall GetOriginalWidth(void);
	int __fastcall GetWidth(void);
	
protected:
	virtual int __fastcall CalculateLeftBound(void);
	virtual int __fastcall GetLineCount(void);
	virtual int __fastcall GetRowIndex(void);
	virtual void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AnItem);
	__property TcxTreeListAdapter* Adapter = {read=GetAdapter};
	__property TcxTreeListReportLinkFormatter* Formatter = {read=GetFormatter};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int OriginalWidth = {read=GetOriginalWidth, nodefault};
	__property int RowIndex = {read=GetRowIndex, nodefault};
	
public:
	__fastcall virtual TcxTreeListColumnPlace(TcxTreeListCustomBandPlace* AController, Cxtl::TcxTreeListColumn* AColumn);
	virtual void __fastcall Calculate(int ALeftBound);
	__property System::Types::TRect CellBounds[Cxtl::TcxTreeListNode* ANode] = {read=GetCellBounds};
	__property int CellHeights[Cxtl::TcxTreeListNode* ANode] = {read=GetCellHeight};
	__property Cxtl::TcxTreeListColumn* Column = {read=FColumn};
	__property TcxTreeListCustomBandPlace* Controller = {read=FController};
	__property System::Types::TRect FooterCellBounds[int AIndex] = {read=GetFooterCellBounds};
	__property int FooterLineHeight = {read=GetFooterLineHeight, nodefault};
	__property System::Types::TRect HeaderCellBounds = {read=GetHeaderCellBounds};
	__property int HeaderLineHeight = {read=GetHeaderLineHeight, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int LeftBound = {read=GetLeftBound, write=FLeftBound, nodefault};
	__property int Width = {read=GetWidth, write=FWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListColumnPlace(void) { }
	
};


class DELPHICLASS TcxTreeListItemPlaceController;
class DELPHICLASS TcxTreeListBandPlace;
class PASCALIMPLEMENTATION TcxTreeListCustomBandPlace : public TcxTreeListCustomItemPlaceController
{
	typedef TcxTreeListCustomItemPlaceController inherited;
	
public:
	TcxTreeListColumnPlace* operator[](int Index) { return Items[Index]; }
	
private:
	Cxtl::TcxTreeListBand* FBand;
	System::Classes::TList* FColumnIndexes;
	TcxTreeListItemPlaceController* FController;
	int FHeight;
	System::Contnrs::TObjectList* FItems;
	int FLeftBound;
	int FMinWidth;
	TcxTreeListBandPlace* FParent;
	int FTopBound;
	int __fastcall GetColumnIndex(Cxtl::TcxTreeListColumn* AColumn);
	System::Types::TRect __fastcall GetBounds(void);
	bool __fastcall GetExpandable(void);
	int __fastcall GetHeight(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFixed(void);
	TcxTreeListColumnPlace* __fastcall GetItem(int AIndex);
	int __fastcall GetItemCount(void);
	int __fastcall GetLeftBound(void);
	int __fastcall GetLevelIndex(void);
	int __fastcall GetMinWidth(void);
	int __fastcall GetTopBound(void);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetViewParams(void);
	
protected:
	virtual int __fastcall CalculateHeaderLineCount(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxTreeListColumnPlace* __fastcall GetItemByColumn(Cxtl::TcxTreeListColumn* Column);
	virtual void __fastcall AddItems(void);
	void __fastcall AssignWidth(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateItemLeftBound(TcxTreeListColumnPlace* AnItem);
	virtual void __fastcall CalculateItemsWidth(void);
	virtual int __fastcall CalculateLeftBound(void);
	virtual int __fastcall CalculateLevelHeight(void);
	virtual int __fastcall CalculateLineHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateTopBound(void);
	virtual TcxTreeListColumnPlace* __fastcall CreateItem(Cxtl::TcxTreeListColumn* AColumn);
	virtual void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AnItem);
	virtual int __fastcall GetRowCount(void);
	virtual bool __fastcall GetItemsAutoWidth(void);
	virtual int __fastcall GetItemsAvailableWidth(void);
	virtual int __fastcall InternalCalculateMinWidth(void);
	virtual int __fastcall InternalCalculateWidth(void);
	__property Cxtl::TcxTreeListBand* Band = {read=FBand};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property bool ItemsAutoWidth = {read=GetItemsAutoWidth, nodefault};
	__property int ItemsAvailableWidth = {read=GetItemsAvailableWidth, nodefault};
	__property int LevelIndex = {read=GetLevelIndex, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property Dxpscxcommon::TdxReportItemViewParams ViewParams = {read=GetViewParams};
	
public:
	__fastcall virtual TcxTreeListCustomBandPlace(TcxTreeListItemPlaceController* AController, TcxTreeListBandPlace* AParent, Cxtl::TcxTreeListBand* ABand);
	__fastcall virtual ~TcxTreeListCustomBandPlace(void);
	virtual void __fastcall Calculate(void);
	int __fastcall IndexOf(TcxTreeListColumnPlace* AnItem)/* overload */;
	int __fastcall IndexOf(Cxtl::TcxTreeListColumn* AColumn)/* overload */;
	virtual void __fastcall Refresh(void);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property int ColumnIndexes[Cxtl::TcxTreeListColumn* Column] = {read=GetColumnIndex};
	__property TcxTreeListItemPlaceController* Controller = {read=FController};
	__property bool Expandable = {read=GetExpandable, nodefault};
	__property int Height = {read=GetHeight, write=FHeight, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxTreeListColumnPlace* Items[int Index] = {read=GetItem/*, default*/};
	__property int LeftBound = {read=GetLeftBound, write=FLeftBound, nodefault};
	__property TcxTreeListBandPlace* Parent = {read=FParent};
	__property int TopBound = {read=GetTopBound, write=FTopBound, nodefault};
};


typedef System::TMetaClass* TcxTreeListCustomBandPlaceClass;

class PASCALIMPLEMENTATION TcxTreeListBandPlace : public TcxTreeListCustomBandPlace
{
	typedef TcxTreeListCustomBandPlace inherited;
	
private:
	System::Classes::TList* FChildItems;
	TcxTreeListCustomBandPlace* __fastcall GetChildItem(int Index);
	int __fastcall GetChildItemCount(void);
	
protected:
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall InternalCalculateMinWidth(void);
	virtual int __fastcall InternalCalculateWidth(void);
	virtual void __fastcall WidthChanged(void);
	void __fastcall CalculateChildItemWidths(void);
	void __fastcall RefreshChildItems(void);
	
public:
	__fastcall virtual TcxTreeListBandPlace(TcxTreeListItemPlaceController* AnOwner, TcxTreeListBandPlace* AParent, Cxtl::TcxTreeListBand* ABand);
	__fastcall virtual ~TcxTreeListBandPlace(void);
	HIDESBASE int __fastcall IndexOf(TcxTreeListCustomBandPlace* AnItem);
	virtual void __fastcall Refresh(void);
	__property int ChildItemCount = {read=GetChildItemCount, nodefault};
	__property TcxTreeListCustomBandPlace* ChildItems[int Index] = {read=GetChildItem};
};


class DELPHICLASS TcxTreeListBottomBandPlace;
class PASCALIMPLEMENTATION TcxTreeListBottomBandPlace : public TcxTreeListCustomBandPlace
{
	typedef TcxTreeListCustomBandPlace inherited;
	
protected:
	virtual void __fastcall AddItems(void);
	virtual int __fastcall CalculateItemLeftBound(TcxTreeListColumnPlace* AnItem);
	virtual void __fastcall CalculateItemsWidth(void);
	virtual bool __fastcall GetItemsAutoWidth(void);
	virtual int __fastcall GetItemsAvailableWidth(void);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall InternalCalculateMinWidth(void);
	virtual int __fastcall InternalCalculateWidth(void);
	virtual void __fastcall WidthChanged(void);
public:
	/* TcxTreeListCustomBandPlace.Create */ inline __fastcall virtual TcxTreeListBottomBandPlace(TcxTreeListItemPlaceController* AController, TcxTreeListBandPlace* AParent, Cxtl::TcxTreeListBand* ABand) : TcxTreeListCustomBandPlace(AController, AParent, ABand) { }
	/* TcxTreeListCustomBandPlace.Destroy */ inline __fastcall virtual ~TcxTreeListBottomBandPlace(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListItemPlaceController : public TcxTreeListCustomItemPlaceController
{
	typedef TcxTreeListCustomItemPlaceController inherited;
	
public:
	TcxTreeListCustomBandPlace* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FBottomItems;
	int FHeight;
	System::Contnrs::TObjectList* FItems;
	int FLevelCount;
	System::Classes::TList* FLevelHeights;
	System::Classes::TList* FRootItems;
	bool __fastcall GetAutoWidth(void);
	int __fastcall GetAvailableWidth(void);
	TcxTreeListCustomBandPlace* __fastcall GetBottomItem(int AIndex);
	int __fastcall GetBottomItemCount(void);
	int __fastcall GetHeight(void);
	TcxTreeListCustomBandPlace* __fastcall GetItem(int AIndex);
	TcxTreeListCustomBandPlace* __fastcall GetItemByBand(Cxtl::TcxTreeListBand* ABand);
	int __fastcall GetItemCount(void);
	int __fastcall GetLevelCount(void);
	int __fastcall GetLevelHeight(int AIndex);
	TcxTreeListCustomBandPlace* __fastcall GetRootItem(int AIndex);
	int __fastcall GetRootItemCount(void);
	void __fastcall SetLevelHeight(int AIndex, int AValue);
	
protected:
	virtual int __fastcall CalculateHeaderLineCount(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxTreeListColumnPlace* __fastcall GetItemByColumn(Cxtl::TcxTreeListColumn* AColumn);
	virtual void __fastcall AddItems(void);
	virtual TcxTreeListCustomBandPlace* __fastcall CreateItem(Cxtl::TcxTreeListBand* ABand);
	virtual TcxTreeListCustomBandPlaceClass __fastcall GetItemClass(Cxtl::TcxTreeListBand* ABand);
	void __fastcall RefreshBottomItems(void);
	void __fastcall RefreshItems(void);
	void __fastcall RefreshRootItems(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateItemHeight(TcxTreeListCustomBandPlace* AnItem);
	virtual int __fastcall CalculateItemLeftBound(TcxTreeListCustomBandPlace* AnItem);
	virtual int __fastcall CalculateItemTopBound(TcxTreeListCustomBandPlace* AnItem);
	virtual int __fastcall CalculateLevelCount(void);
	void __fastcall CalculateItemWidths(void);
	void __fastcall CalculateLevelHeights(void);
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property int AvailableWidth = {read=GetAvailableWidth, nodefault};
	
public:
	__fastcall virtual TcxTreeListItemPlaceController(TcxTreeListReportLinkFormatter* AFormatter);
	__fastcall virtual ~TcxTreeListItemPlaceController(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Refresh(void);
	int __fastcall BottomIndexOf(TcxTreeListCustomBandPlace* AnItem);
	int __fastcall IndexOf(TcxTreeListCustomBandPlace* AnItem)/* overload */;
	int __fastcall IndexOf(Cxtl::TcxTreeListBand* ABand)/* overload */;
	int __fastcall RootIndexOf(TcxTreeListCustomBandPlace* AnItem)/* overload */;
	int __fastcall RootIndexOf(Cxtl::TcxTreeListBand* ABand)/* overload */;
	__property int BottomItemCount = {read=GetBottomItemCount, nodefault};
	__property TcxTreeListCustomBandPlace* BottomItems[int Index] = {read=GetBottomItem};
	__property int Height = {read=GetHeight, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxTreeListCustomBandPlace* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxTreeListCustomBandPlace* ItemsByBand[Cxtl::TcxTreeListBand* Band] = {read=GetItemByBand};
	__property int LevelCount = {read=GetLevelCount, nodefault};
	__property int LevelHeights[int Index] = {read=GetLevelHeight, write=SetLevelHeight};
	__property int RootItemCount = {read=GetRootItemCount, nodefault};
	__property TcxTreeListCustomBandPlace* RootItems[int Index] = {read=GetRootItem};
};


typedef System::DynamicArray<Cxtl::TcxTreeListSummaryItem*> Dxpscxtllnk__82;

typedef System::DynamicArray<System::DynamicArray<Cxtl::TcxTreeListSummaryItem*> > TcxTreeListReportLinkSummaryItems;

class DELPHICLASS TcxTreeListReportLinkLevelInfo;
class PASCALIMPLEMENTATION TcxTreeListReportLinkLevelInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TCustomImageList* FStateImages;
public:
	/* TObject.Create */ inline __fastcall TcxTreeListReportLinkLevelInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkLevelInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListReportLinkFormatter : public TcxTreeListReportLinkBuilderHandler
{
	typedef TcxTreeListReportLinkBuilderHandler inherited;
	
private:
	System::Classes::TList* FBands;
	int FBandLineHeight;
	System::Classes::TList* FColumns;
	int FDetailsLineHeight;
	TcxTreeListReportLinkSummaryItems FGroupFooterSummaryItems;
	TcxTreeListItemPlaceController* FItemPlaceController;
	Vcl::Graphics::TFont* FFont;
	int FFooterLineHeight;
	int FHeaderLineHeight;
	System::Contnrs::TObjectList* FLevelInfos;
	System::Classes::TList* FLookAndFeelItems;
	int FExpansionLevel;
	int FMaxNodeImageHeight;
	System::Classes::TList* FNodes;
	int FPreviewLineHeight;
	TcxTreeListReportLinkSummaryItems FFooterSummaryItems;
	System::Uitypes::TColor FTransparentColor;
	bool __fastcall GetAutoWidth(void);
	int __fastcall GetAvailableWidth(void);
	int __fastcall GetBandCount(void);
	Cxtl::TcxTreeListBand* __fastcall GetBands(int AIndex);
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetCanvas(void);
	int __fastcall GetColumnCount(void);
	Cxtl::TcxTreeListColumn* __fastcall GetColumns(int AIndex);
	System::Uitypes::TColor __fastcall GetExpandButtonColor(void);
	int __fastcall GetExpandButtonSize(void);
	System::Uitypes::TColor __fastcall GetGridLinesColor(void);
	bool __fastcall GetHasNodeSeparator(void);
	bool __fastcall GetHasPreview(void);
	int __fastcall GetIndentCount(Cxtl::TcxTreeListNode* Node);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(int ALevel);
	int __fastcall GetImagesWidth(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall GetIsNodeColorUsedForIndents(void);
	TcxTreeListReportLinkLevelInfo* __fastcall GetLevelInfos(int ALevel);
	Dxpscore::TdxReportVisualItem* __fastcall GetLookAndFeelItem(int Index);
	int __fastcall GetLookAndFeelItemCount(void);
	Cxtl::TcxTreeListNode* __fastcall GetNode(int Index);
	int __fastcall GetNodeCount(void);
	System::Uitypes::TColor __fastcall GetNodeSeparatorColor(void);
	int __fastcall GetNodeSeparatorThickness(void);
	bool __fastcall GetPreviewAutoHeight(void);
	Cxtl::TcxTreeListColumn* __fastcall GetPreviewColumn(void);
	int __fastcall GetPreviewMaxLineCount(void);
	Dxpscore::TdxPSReportRenderer* __fastcall GetRenderer(void);
	bool __fastcall GetShowBandHeaders(void);
	bool __fastcall GetShowFooters(void);
	bool __fastcall GetShowHeaders(void);
	bool __fastcall GetShowPreview(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(int ALevel);
	bool __fastcall GetUseLookAndFeelColors(void);
	int __fastcall GetViewWidth(void);
	System::Uitypes::TColor __fastcall GetTreeLinesColor(void);
	Cxtl::TcxTreeListTreeLineStyle __fastcall GetTreeLinesStyle(void);
	int __fastcall GetStateImagesWidth(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall HasImages(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall HasStateImages(Cxtl::TcxTreeListNode* ANode);
	void __fastcall FormatLookAndFeelItems(void);
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual bool __fastcall IdxPSCellParams_GetAutoHeight(void);
	virtual Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall IdxPSCellParams_GetCanvas(void);
	virtual bool __fastcall IdxPSCellParams_GetDisplayGraphicsAsText(void);
	virtual bool __fastcall IdxPSCellParams_GetEndEllipsis(void);
	virtual bool __fastcall IdxPSCellParams_GetFlatCheckMarks(void);
	virtual System::UnicodeString __fastcall IdxPSCellParams_GetGraphicsText(void);
	virtual bool __fastcall IdxPSCellParams_GetMultiline(void);
	virtual bool __fastcall IdxPSCellParams_GetTransparentGraphics(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginLeft(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginRight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxHeight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxLineCount(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall IdxPSCellParams2_GetRichEditGraphicClass(void);
	virtual bool __fastcall IdxPSCellParams2_GetRichEditTransparent(void);
	virtual void __fastcall AddDelimiters(void);
	virtual void __fastcall AddHorizontalDelimiters(void);
	virtual void __fastcall AddVerticalDelimiters(void);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall CalculateLineHeights(void);
	bool __fastcall CanProcessSelectionStyle(Cxtl::TcxTreeListNode* ANode);
	void __fastcall CreateLevelInfos(void);
	virtual void __fastcall CreateNodeList(void);
	virtual bool __fastcall IsSelectedNode(Cxtl::TcxTreeListNode* ANode);
	Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(int Index);
	int __fastcall GetBackgroundBitmapIndex(int Index);
	bool __fastcall HasBackgroundBitmap(int Index);
	int __fastcall MapStyleBackgroundBitmapIndex(int ATreeListBackgroundBitmapIndex);
	void __fastcall CalculateHeight(const Dxpscxcommon::TdxReportItemViewParams &AParams, int &AHeight);
	int __fastcall CalculatePatternHeight(const Dxpscxcommon::TdxReportItemViewParams &AParams);
	void __fastcall CreateBands(void);
	void __fastcall CreateColumns(void);
	void __fastcall CreateItems(void);
	void __fastcall CreateSummaryItems(void);
	int __fastcall GetFooterCellCount(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	int __fastcall GetNodeIndent(Cxtl::TcxTreeListNode* ANode);
	Cxtl::TcxTreeListNode* __fastcall GetNodeParent(Cxtl::TcxTreeListNode* ANode, int ALevel);
	Cxtl::TcxTreeListNode* __fastcall GetNextNode(Cxtl::TcxTreeListNode* ANode);
	Cxtl::TcxTreeListNode* __fastcall GetPrevNode(Cxtl::TcxTreeListNode* ANode);
	int __fastcall GetStyleFontIndex(const Dxpscxcommon::TdxReportItemViewParams &AParams);
	TcxTreeListReportLinkSummaryItems __fastcall GetSummaryItems(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall HasFooterCell(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	bool __fastcall HasParent(Cxtl::TcxTreeListNode* ANode);
	int __fastcall IndexOfNode(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsColorTransparent(System::Uitypes::TColor AColor);
	bool __fastcall IsFirstNode(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsLastNode(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsNodeExpanded(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsNodeFirstChild(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsNodeLastChild(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsOddNode(Cxtl::TcxTreeListNode* ANode);
	bool __fastcall IsNodeSelected(Cxtl::TcxTreeListNode* ANode);
	void __fastcall RegisterLookAndFeelItem(Dxpscore::TdxReportVisualItem* AnItem, Dxpscore::TdxCellEdgeStyle AEdgeStyle);
	void __fastcall SetViewParams(Dxpscore::TdxReportVisualItem* AnItem, const Dxpscxcommon::TdxReportItemViewParams &AParams);
	unsigned __fastcall MakeIndentIndex(int AnIndex);
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* Canvas = {read=GetCanvas};
	__property TcxTreeListItemPlaceController* ItemPlaceController = {read=FItemPlaceController};
	__property TcxTreeListReportLinkLevelInfo* LevelInfos[int ALevel] = {read=GetLevelInfos};
	__property int LookAndFeelItemCount = {read=GetLookAndFeelItemCount, nodefault};
	__property Dxpscore::TdxReportVisualItem* LookAndFeelItems[int Index] = {read=GetLookAndFeelItem};
	__property Dxpscore::TdxPSReportRenderer* Renderer = {read=GetRenderer};
	__property int ViewWidth = {read=GetViewWidth, nodefault};
	
public:
	__fastcall virtual TcxTreeListReportLinkFormatter(TcxTreeListReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxTreeListReportLinkFormatter(void);
	virtual TcxTreeListAdapter* __fastcall Adapter(void)/* overload */;
	virtual void __fastcall DoInitializeHost(Dxpscore::TdxReportCell* AHost);
	virtual void __fastcall DoInitializeBandItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeBandRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeBandItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetBandBackgroundViewParams(void);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetBandItemClass(int Index);
	System::Types::TRect __fastcall GetBandItemBounds(int Index);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetBandItemViewParams(Cxtl::TcxTreeListBand* ABand);
	virtual void __fastcall DoInitializeNodeCheck(Dxpscore::TdxCustomReportCellCheck* AnItem, Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetNodeCheckCellSides(Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual Dxpscore::TdxCustomReportCellCheckClass __fastcall GetNodeCheckClass(Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetNodeCheckViewParams(Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual void __fastcall DoInitializeFooterCell(Dxpscore::TAbstractdxReportCellData* AnItem, Cxtl::TcxTreeListColumn* AColumn, int ACellIndex, Cxtl::TcxTreeListNode* ANode);
	void __fastcall DoInitializeFooterIndent(Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex, int AnIndentCount, Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoInitializeFooterBandedRow(Dxpscore::TdxReportCell* ARow, int AIndentCount);
	virtual void __fastcall DoInitializeFooterRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeFooterCell(Dxpscore::TAbstractdxReportCellData* AnItem, int AColumnIndex, int ACellIndex);
	virtual System::Types::TRect __fastcall GetFooterCellBounds(Cxtl::TcxTreeListColumn* AColumn, int ACellIndex, int AIndent);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetFooterCellClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetFooterCellViewParams(Cxtl::TcxTreeListColumn* AColumn);
	Dxpscore::TdxPSTreeLineMode __fastcall GetNodeFooterIndentTreeLineMode(int AnIndex, int AnIndentCount, Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetFooterRowViewParams(void);
	virtual void __fastcall DoInitializeHeaderItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeHeaderRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoReportLinkInitializeHeaderItem(Dxpscore::TAbstractdxReportCellData* AnItem, int AIndex);
	virtual System::Types::TRect __fastcall GetHeaderItemBounds(int AnIndex);
	virtual Dxpscore::TdxReportCellTextClass __fastcall GetHeaderItemClass(int AnIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetHeaderItemViewParams(Cxtl::TcxTreeListColumn* AColumn);
	virtual void __fastcall DoInitializeNodeImage(Dxpscore::TdxReportCellGraphic* AnItem, Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual void __fastcall DoReportLinkInitializeNodeImage(Dxpscore::TAbstractdxReportCellData* AnItem, Cxtl::TcxTreeListNode* ANode, int AnIndex);
	Dxpscore::TdxCellSides __fastcall GetNodeImageCellSides(Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual Dxpscore::TdxReportCellGraphicClass __fastcall GetNodeImageClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetNodeImageViewParams(Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual void __fastcall DoInitializeNodeIndent(Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex, int AnIndentCount, Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoInitializeExpandButton(Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex, int AnIndentCount, Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoReportLinkInitializeNodeIndent(Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex, int AnIndentCount, Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscore::TdxCellSides __fastcall GetNodeIndentCellSides(Cxtl::TcxTreeListNode* ANode, int AnIndex, int AnIndentCount);
	virtual Dxpscore::TdxReportCellExpandButtonClass __fastcall GetNodeIndentClass(void);
	Dxpscore::TdxPSTreeLineMode __fastcall GetNodeIndentTreeLineMode(int AnIndex, int AnIndentCount, Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetNodeIndentViewParams(Cxtl::TcxTreeListNode* ANode, int AnIndex, int AnIndentCount);
	virtual void __fastcall DoInitializeNodeBandedRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall DoInitializeNodeRow(Dxpscore::TdxReportCell* ARow, Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoInitializeNodeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode, bool AnIsPreview = false);
	virtual void __fastcall DoReportLinkInitializeNodeItem(Dxpscore::TAbstractdxReportCellData* AnItem, Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual System::Variant __fastcall GetCellValue(Cxedit::TcxCustomEditProperties* AProperties, Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	int __fastcall GetNodeBackgroundBitmapStyleIndex(Cxtl::TcxTreeListNode* ANode);
	virtual System::Types::TRect __fastcall GetNodeItemBounds(Cxtl::TcxTreeListNode* ANode, int AIndex);
	Dxpscore::TdxCellSides __fastcall GetNodeItemCellSides(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetNodeItemClass(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode, bool AnIsPreview = false);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetNodeItemViewParams(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoInitializePreview(Dxpscore::TAbstractdxReportCellData* AnItem, Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscore::TdxCellSides __fastcall GetPreviewCellSides(Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetPreviewClass(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetPreviewViewParams(Cxtl::TcxTreeListColumn* AColumn, Cxtl::TcxTreeListNode* ANode);
	virtual void __fastcall DoInitializeNodeSeparator(Dxpscore::TAbstractdxReportCellData* AnItem);
	virtual void __fastcall DoInitializeNodeSeparatorRow(Dxpscore::TdxReportCell* ARow);
	virtual Dxpscore::TdxReportCellBoxClass __fastcall GetNodeSeparatorClass(void);
	virtual void __fastcall DoInitializeNodeStateImage(Dxpscore::TdxReportCellGraphic* AnItem, Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual void __fastcall DoReportLinkInitializeNodeStateImage(Dxpscore::TAbstractdxReportCellData* AnItem, Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetNodeStateImageCellSides(Cxtl::TcxTreeListNode* ANode, int AnIndex);
	virtual Dxpscore::TdxReportCellGraphicClass __fastcall GetNodeStateImageClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetNodeStateImageViewParams(Cxtl::TcxTreeListNode* ANode, int AnIndex);
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property int AvailableWidth = {read=GetAvailableWidth, nodefault};
	__property int BandLineHeight = {read=FBandLineHeight, write=FBandLineHeight, nodefault};
	__property int BandCount = {read=GetBandCount, nodefault};
	__property Cxtl::TcxTreeListBand* Bands[int Index] = {read=GetBands};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property Cxtl::TcxTreeListColumn* Columns[int Index] = {read=GetColumns};
	__property int DetailsLineHeight = {read=FDetailsLineHeight, write=FDetailsLineHeight, nodefault};
	__property System::Uitypes::TColor ExpandButtonColor = {read=GetExpandButtonColor, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSize, nodefault};
	__property int FooterLineHeight = {read=FFooterLineHeight, write=FFooterLineHeight, nodefault};
	__property System::Uitypes::TColor GridLinesColor = {read=GetGridLinesColor, nodefault};
	__property bool HasNodeSeparator = {read=GetHasNodeSeparator, nodefault};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property int HeaderLineHeight = {read=FHeaderLineHeight, write=FHeaderLineHeight, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images[int ALevel] = {read=GetImages};
	__property int IndentCounts[Cxtl::TcxTreeListNode* Node] = {read=GetIndentCount};
	__property bool IsNodeColorUsedForIndents = {read=GetIsNodeColorUsedForIndents, nodefault};
	__property int NodeCount = {read=GetNodeCount, nodefault};
	__property Cxtl::TcxTreeListNode* Nodes[int Index] = {read=GetNode};
	__property System::Uitypes::TColor NodeSeparatorColor = {read=GetNodeSeparatorColor, nodefault};
	__property int NodeSeparatorThickness = {read=GetNodeSeparatorThickness, nodefault};
	__property bool PreviewAutoHeight = {read=GetPreviewAutoHeight, nodefault};
	__property Cxtl::TcxTreeListColumn* PreviewColumn = {read=GetPreviewColumn};
	__property int PreviewLineHeight = {read=FPreviewLineHeight, write=FPreviewLineHeight, nodefault};
	__property int PreviewMaxLineCount = {read=GetPreviewMaxLineCount, nodefault};
	__property bool ShowBandHeaders = {read=GetShowBandHeaders, nodefault};
	__property bool ShowFooters = {read=GetShowFooters, nodefault};
	__property bool ShowHeaders = {read=GetShowHeaders, nodefault};
	__property bool ShowPreview = {read=GetShowPreview, nodefault};
	__property Vcl::Imglist::TCustomImageList* StateImages[int ALevel] = {read=GetStateImages};
	__property bool UseLookAndFeelColors = {read=GetUseLookAndFeelColors, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=FTransparentColor, write=FTransparentColor, default=-16777211};
	__property System::Uitypes::TColor TreeLinesColor = {read=GetTreeLinesColor, nodefault};
	__property Cxtl::TcxTreeListTreeLineStyle TreeLinesStyle = {read=GetTreeLinesStyle, nodefault};
private:
	void *__IdxPSCellParams2;	/* Dxpscxcommon::IdxPSCellParams2 */
	void *__IdxPSCellParams;	/* Dxpscxcommon::IdxPSCellParams */
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {09EAB051-1AC2-46FB-A7F4-D6BFA883D015}
	operator Dxpscxcommon::_di_IdxPSCellParams2()
	{
		Dxpscxcommon::_di_IdxPSCellParams2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscxcommon::IdxPSCellParams2*(void) { return (Dxpscxcommon::IdxPSCellParams2*)&__IdxPSCellParams2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F0A495A1-1F0F-4245-A437-16E21ACF9FED}
	operator Dxpscxcommon::_di_IdxPSCellParams()
	{
		Dxpscxcommon::_di_IdxPSCellParams intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscxcommon::IdxPSCellParams*(void) { return (Dxpscxcommon::IdxPSCellParams*)&__IdxPSCellParams; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsExpanding;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsExpanding : public Dxpscxcommon::TdxCustomReportLinkOptionsExpanding
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsExpanding inherited;
	
private:
	bool FAutoExpandNodes;
	bool FExplicitlyExpandNodes;
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	void __fastcall SetAutoExpandNodes(bool Value);
	void __fastcall SetExplicitlyExpandNodes(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool AutoExpandNodes = {read=FAutoExpandNodes, write=SetAutoExpandNodes, default=0};
	__property bool ExplicitlyExpandNodes = {read=FExplicitlyExpandNodes, write=SetExplicitlyExpandNodes, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsExpanding(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsExpanding(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsExpanding(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsFormatting;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsFormatting : public Dxpscxcommon::TdxCustomReportLinkOptionsFormatting
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsFormatting inherited;
	
private:
	bool FConsumeSelectionStyle;
	System::Uitypes::TColor FNodeSeparatorColor;
	int FNodeSeparatorThickness;
	System::Uitypes::TColor __fastcall GetActualNodeSeparatorColor(void);
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	void __fastcall SetConsumeSelectionStyle(bool Value);
	void __fastcall SetNodeSeparatorColor(System::Uitypes::TColor Value);
	void __fastcall SetNodeSeparatorThickness(int Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property System::Uitypes::TColor ActualNodeSeparatorColor = {read=GetActualNodeSeparatorColor, nodefault};
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool ConsumeSelectionStyle = {read=FConsumeSelectionStyle, write=SetConsumeSelectionStyle, default=0};
	__property System::Uitypes::TColor NodeSeparatorColor = {read=FNodeSeparatorColor, write=SetNodeSeparatorColor, default=536870912};
	__property int NodeSeparatorThickness = {read=FNodeSeparatorThickness, write=SetNodeSeparatorThickness, default=0};
	__property UseLookAndFeelColors = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsFormatting(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsFormatting(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsFormatting(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsOnEveryPage;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsOnEveryPage : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPage
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPage inherited;
	
private:
	HIDESBASE TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property BandHeaders = {default=1};
	__property Footers = {default=1};
	__property Headers = {default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsOnEveryPage(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPage(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsOnEveryPage(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsPagination;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsPagination : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPagination
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPagination inherited;
	
private:
	bool __fastcall GetNode(void);
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	void __fastcall SetNode(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Band = {default=0};
	__property Column = {default=1};
	__property Custom = {default=0};
	__property bool Node = {read=GetNode, write=SetNode, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsPagination(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPagination(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsPagination(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsPreview;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsPreview : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreview
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreview inherited;
	
private:
	HIDESBASE TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsPreview(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreview(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsPreview(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsRefinements;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsRefinements : public Dxpscxcommon::TdxCustomReportLinkOptionsRefinements
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsRefinements inherited;
	
private:
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsRefinements(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsRefinements(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsRefinements(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsSelection;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsSelection : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelection
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelection inherited;
	
private:
	HIDESBASE TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsSelection(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelection(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsSelection(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsSize;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsSize : public Dxpscxcommon::TdxCustomReportLinkOptionsSize
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsSize inherited;
	
private:
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property AutoWidth = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsSize(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsSize(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsSize(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkOptionsView;
class PASCALIMPLEMENTATION TcxTreeListReportLinkOptionsView : public Dxpscxcommon::TdxCustomTableControlReportLinkOptionsView
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLinkOptionsView inherited;
	
private:
	bool FBorders;
	bool FTreeLines;
	TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	void __fastcall SetBorders(bool Value);
	void __fastcall SetTreeLines(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property BandHeaders = {default=1};
	__property bool Borders = {read=FBorders, write=SetBorders, default=1};
	__property ExpandButtons = {default=1};
	__property Footers = {default=1};
	__property Headers = {default=1};
	__property bool TreeLines = {read=FTreeLines, write=SetTreeLines, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxTreeListReportLinkOptionsView(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomTableControlReportLinkOptionsView(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkOptionsView(void) { }
	
};


typedef System::TMetaClass* TcxTreeListReportLinkStylesClass;

class DELPHICLASS TcxTreeListReportLinkStyles;
class PASCALIMPLEMENTATION TcxTreeListReportLinkStyles : public Dxpscxcommon::TdxCustomReportLinkStyles
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyles inherited;
	
private:
	Cxtl::TcxTreeListGetNodeIndentStyleEvent FOnGetNodeIndentStyle;
	HIDESBASE TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual System::UnicodeString __fastcall GetStyleCaption(int AnIndex);
	virtual int __fastcall GetStyleIndexByCaption(const System::UnicodeString Caption);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetBandHeaderParams(Cxtl::TcxTreeListBand* ABand, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetColumnFooterParams(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetColumnHeaderParams(Cxtl::TcxTreeListColumn* AColumn, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetContentParams(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetFooterRowParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetImagesParams(Cxtl::TcxTreeListNode* ANode, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetIndentParams(Cxtl::TcxTreeListNode* ANode, int AnIndent, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetPreviewParams(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetSelectionParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Cxstyles::TcxStyle* BandBackground = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* BandHeader = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* ContentEven = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* ContentOdd = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* FooterRow = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* Preview = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* Selection = {read=GetValue, write=SetValue, index=9};
	__property StyleSheet;
	__property Cxtl::TcxTreeListGetNodeIndentStyleEvent OnGetNodeIndentStyle = {read=FOnGetNodeIndentStyle, write=FOnGetNodeIndentStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxTreeListReportLinkStyles(System::Classes::TPersistent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkStyles(void) { }
	
};


class DELPHICLASS TcxTreeListReportLinkStyleSheet;
class PASCALIMPLEMENTATION TcxTreeListReportLinkStyleSheet : public Dxpscxcommon::TdxCustomReportLinkStyleSheet
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyleSheet inherited;
	
private:
	TcxTreeListReportLinkStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxTreeListReportLinkStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxTreeListReportLinkStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxTreeListReportLinkStyleSheet(System::Classes::TComponent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxTreeListReportLinkStyleSheet(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListAttributeHostInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxpscore::TdxReportCell* FParent;
	
public:
	System::Types::TPoint Origin;
	void __fastcall Initialize(Dxpscore::TdxReportCell* AParent);
	__property Dxpscore::TdxReportCell* Parent = {read=FParent};
public:
	/* TObject.Create */ inline __fastcall TcxTreeListAttributeHostInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListAttributeHostInfo(void) { }
	
};


typedef System::TMetaClass* TcxTreeListAttributeHostInfoServicesClass;

class DELPHICLASS TcxTreeListAttributeHostInfoServices;
class PASCALIMPLEMENTATION TcxTreeListAttributeHostInfoServices : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxTreeListAttributeHostInfo* FPageDetailsHostInfo;
	TcxTreeListAttributeHostInfo* FPageFootersHostInfo;
	TcxTreeListAttributeHostInfo* FPageHeadersHostInfo;
	TcxTreeListCustomReportLink* FReportLink;
	bool __fastcall GetArePageFootersAssigned(void);
	bool __fastcall GetArePageHeadersAssigned(void);
	bool __fastcall GetCanUseBandHeadersOnEveyPage(void);
	bool __fastcall GetCanUseFootersOnEveryPage(void);
	bool __fastcall GetCanUseHeadersOnEveryPage(void);
	bool __fastcall GetIsInconsistentHeadersState(void);
	TcxTreeListReportLinkOptionsOnEveryPage* __fastcall GetOptionsOnEveryPage(void);
	TcxTreeListReportLinkOptionsView* __fastcall GetOptionsView(void);
	Dxpscore::TdxReportCell* __fastcall GetPageDetails(void);
	Dxpscore::TdxReportCell* __fastcall GetPageFooters(void);
	Dxpscore::TdxReportCell* __fastcall GetPageHeaders(void);
	
protected:
	void __fastcall CreateHostInfos(void);
	void __fastcall DestroyHostInfos(void);
	virtual TcxTreeListAttributeHostInfo* __fastcall GetBandHeadersHostInfo(void);
	virtual TcxTreeListAttributeHostInfo* __fastcall GetFootersHostInfo(void);
	virtual TcxTreeListAttributeHostInfo* __fastcall GetHeadersHostInfo(void);
	virtual System::UnicodeString __fastcall GetInconsistentStateText(void);
	virtual bool __fastcall GetIsInconsistentState(void);
	bool __fastcall HasCells(void);
	__property TcxTreeListReportLinkOptionsOnEveryPage* OptionsOnEveryPage = {read=GetOptionsOnEveryPage};
	__property TcxTreeListReportLinkOptionsView* OptionsView = {read=GetOptionsView};
	__property Dxpscore::TdxReportCell* PageDetails = {read=GetPageDetails};
	__property Dxpscore::TdxReportCell* PageFooters = {read=GetPageFooters};
	__property Dxpscore::TdxReportCell* PageHeaders = {read=GetPageHeaders};
	
public:
	__fastcall virtual TcxTreeListAttributeHostInfoServices(TcxTreeListCustomReportLink* AReportLink);
	__fastcall virtual ~TcxTreeListAttributeHostInfoServices(void);
	void __fastcall InitializeHostInfos(void);
	__property bool ArePageFootersAssigned = {read=GetArePageFootersAssigned, nodefault};
	__property bool ArePageHeadersAssigned = {read=GetArePageHeadersAssigned, nodefault};
	__property TcxTreeListAttributeHostInfo* BandHeadersHostInfo = {read=GetBandHeadersHostInfo};
	__property bool CanUseBandHeadersOnEveyPage = {read=GetCanUseBandHeadersOnEveyPage, nodefault};
	__property bool CanUseFootersOnEveryPage = {read=GetCanUseFootersOnEveryPage, nodefault};
	__property bool CanUseHeadersOnEveryPage = {read=GetCanUseHeadersOnEveryPage, nodefault};
	__property TcxTreeListAttributeHostInfo* FootersHostInfo = {read=GetFootersHostInfo};
	__property TcxTreeListAttributeHostInfo* HeadersHostInfo = {read=GetHeadersHostInfo};
	__property System::UnicodeString InconsistentStateText = {read=GetInconsistentStateText};
	__property bool IsInconsistentHeadersState = {read=GetIsInconsistentHeadersState, nodefault};
	__property bool IsInconsistentState = {read=GetIsInconsistentState, nodefault};
	__property TcxTreeListAttributeHostInfo* PageDetailsHostInfo = {read=FPageDetailsHostInfo};
	__property TcxTreeListAttributeHostInfo* PageFootersHostInfo = {read=FPageFootersHostInfo};
	__property TcxTreeListAttributeHostInfo* PageHeadersHostInfo = {read=FPageHeadersHostInfo};
	__property TcxTreeListCustomReportLink* ReportLink = {read=FReportLink};
};


typedef System::DynamicArray<Cxtl::TcxTreeListNode*> TcxTreeListNodeArray;

typedef System::DynamicArray<Cxtl::TcxTreeListColumn*> TcxTreeListColumnArray;

typedef void __fastcall (__closure *TcxTreeListReportLinkGetCustomPageBreaksEvent)(TcxTreeListCustomReportLink* Sender);

typedef void __fastcall (__closure *TcxTreeListReportLinkCustomDrawBandCellEvent)(TcxTreeListCustomReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListBand* ABand, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListReportLinkCustomDrawCellEvent)(TcxTreeListCustomReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListReportLinkCustomDrawFooterCellEvent)(TcxTreeListCustomReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListReportLinkCustomDrawHeaderCellEvent)(TcxTreeListCustomReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListReportLinkCustomDrawIndentCellEvent)(TcxTreeListCustomReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListNode* ANode, int AnIndex, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListReportLinkInitializeBandCellEvent)(TcxTreeListCustomReportLink* Sender, Cxtl::TcxTreeListBand* ABand, Dxpscore::TdxReportCellImage* AnItem);

typedef void __fastcall (__closure *TcxTreeListReportLinkInitializeCellEvent)(TcxTreeListCustomReportLink* Sender, Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem);

typedef void __fastcall (__closure *TcxTreeListReportLinkInitializeFooterCellEvent)(TcxTreeListCustomReportLink* Sender, int ASummaryCellIndex, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TcxTreeListReportLinkInitializeHeaderCellEvent)(TcxTreeListCustomReportLink* Sender, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellImage* AnItem);

typedef void __fastcall (__closure *TcxTreeListReportLinkInitializeIndentCellEvent)(TcxTreeListCustomReportLink* Sender, Cxtl::TcxTreeListNode* ANode, int AnIndex, Dxpscore::TAbstractdxReportCellData* AnItem);

class DELPHICLASS TdxfmTreeListReportLinkDesignWindow;
class PASCALIMPLEMENTATION TcxTreeListCustomReportLink : public Dxpscxcommon::TdxCustomTableControlReportLink
{
	typedef Dxpscxcommon::TdxCustomTableControlReportLink inherited;
	
private:
	TcxTreeListReportLinkBuilder* FBuilder;
	System::Classes::TList* FDelimitersHardHorz;
	System::Classes::TList* FDelimitersHardVert;
	TcxTreeListAttributeHostInfoServices* FHostInfoServices;
	System::Classes::TList* FReportRows;
	TcxTreeListReportLinkCustomDrawBandCellEvent FOnCustomDrawBandCell;
	TcxTreeListReportLinkCustomDrawCellEvent FOnCustomDrawCell;
	TcxTreeListReportLinkCustomDrawFooterCellEvent FOnCustomDrawFooterCell;
	TcxTreeListReportLinkCustomDrawHeaderCellEvent FOnCustomDrawHeaderCell;
	TcxTreeListReportLinkCustomDrawIndentCellEvent FOnCustomDrawIndentCell;
	TcxTreeListReportLinkGetCustomPageBreaksEvent FOnGetCustomPageBreaks;
	TcxTreeListReportLinkInitializeBandCellEvent FOnInitializeBandCell;
	TcxTreeListReportLinkInitializeCellEvent FOnInitializeCell;
	TcxTreeListReportLinkInitializeFooterCellEvent FOnInitializeFooterCell;
	TcxTreeListReportLinkInitializeHeaderCellEvent FOnInitializeHeaderCell;
	TcxTreeListReportLinkInitializeIndentCellEvent FOnInitializeIndentCell;
	HIDESBASE TcxTreeListReportLinkStyles* __fastcall GetActiveStyles(void);
	HIDESBASE TdxfmTreeListReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	TcxTreeListReportLinkOptionsExpanding* __fastcall GetOptionsExpanding(void);
	TcxTreeListReportLinkOptionsFormatting* __fastcall GetOptionsFormatting(void);
	TcxTreeListReportLinkOptionsOnEveryPage* __fastcall GetOptionsOnEveryPage(void);
	HIDESBASE TcxTreeListReportLinkOptionsPagination* __fastcall GetOptionsPagination(void);
	TcxTreeListReportLinkOptionsPreview* __fastcall GetOptionsPreview(void);
	TcxTreeListReportLinkOptionsRefinements* __fastcall GetOptionsRefinements(void);
	TcxTreeListReportLinkOptionsSelection* __fastcall GetOptionsSelection(void);
	TcxTreeListReportLinkOptionsSize* __fastcall GetOptionsSize(void);
	HIDESBASE TcxTreeListReportLinkOptionsView* __fastcall GetOptionsView(void);
	Dxpscore::TAbstractdxReportCellData* __fastcall GetReportCellDataByColumn(Cxtl::TcxTreeListColumn* AColumn);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	Dxpscore::TdxReportCell* __fastcall GetReportRowByNode(Cxtl::TcxTreeListNode* Node);
	int __fastcall GetReportRowCount(void);
	TcxTreeListReportLinkStyles* __fastcall GetStyles(void);
	Cxtl::TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetOnCustomDrawBandCell(TcxTreeListReportLinkCustomDrawBandCellEvent Value);
	void __fastcall SetOnCustomDrawCell(TcxTreeListReportLinkCustomDrawCellEvent Value);
	void __fastcall SetOnCustomDrawFooterCell(TcxTreeListReportLinkCustomDrawFooterCellEvent Value);
	void __fastcall SetOnCustomDrawHeaderCell(TcxTreeListReportLinkCustomDrawHeaderCellEvent Value);
	void __fastcall SetOnCustomDrawIndentCell(TcxTreeListReportLinkCustomDrawIndentCellEvent Value);
	HIDESBASE void __fastcall SetOptionsExpanding(TcxTreeListReportLinkOptionsExpanding* Value);
	HIDESBASE void __fastcall SetOptionsFormatting(TcxTreeListReportLinkOptionsFormatting* Value);
	HIDESBASE void __fastcall SetOptionsOnEveryPage(TcxTreeListReportLinkOptionsOnEveryPage* Value);
	HIDESBASE void __fastcall SetOptionsPagination(TcxTreeListReportLinkOptionsPagination* Value);
	HIDESBASE void __fastcall SetOptionsPreview(TcxTreeListReportLinkOptionsPreview* Value);
	HIDESBASE void __fastcall SetOptionsRefinements(TcxTreeListReportLinkOptionsRefinements* Value);
	HIDESBASE void __fastcall SetOptionsSelection(TcxTreeListReportLinkOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsSize(TcxTreeListReportLinkOptionsSize* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxTreeListReportLinkOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TcxTreeListReportLinkStyles* Value);
	
protected:
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual bool __fastcall GetBreakPagesByHardDelimiters(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual bool __fastcall GetUseHardVertDelimiters(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsDrawFootersOnEveryPage(void);
	virtual bool __fastcall IsDrawHeadersOnEveryPage(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeHardDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	virtual bool __fastcall GetAreNativeStylesAvailable(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStylesClass __fastcall GetStylesClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheetClass __fastcall GetStyleSheetClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheet* __fastcall GetStyleSheetPrototype(void);
	virtual void __fastcall PrepareConstruct(void);
	DYNAMIC void __fastcall DoCustomDrawBandCell(Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListBand* ABand, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawCell(Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawFooterCell(Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawHeaderCell(Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawIndentCell(Vcl::Graphics::TCanvas* ACanvas, Cxtl::TcxTreeListNode* ANode, int AnIndex, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoGetCustomPageBreaks(void);
	DYNAMIC void __fastcall DoInitializeBandCell(Cxtl::TcxTreeListBand* ABand, Dxpscore::TdxReportCellImage* AnItem);
	DYNAMIC void __fastcall DoInitializeCell(Cxtl::TcxTreeListNode* ANode, Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TAbstractdxReportCellData* AnItem);
	DYNAMIC void __fastcall DoInitializeFooterCell(Cxtl::TcxTreeListColumn* AColumn, int ASummaryCellIndex, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeHeaderCell(Cxtl::TcxTreeListColumn* AColumn, Dxpscore::TdxReportCellImage* AnItem);
	DYNAMIC void __fastcall DoInitializeIndentCell(Cxtl::TcxTreeListNode* ANode, int AnIndex, Dxpscore::TAbstractdxReportCellData* AnItem);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsExpandingClass __fastcall GetOptionsExpandingClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsFormattingClass __fastcall GetOptionsFormattingClass(void);
	virtual Dxpscxcommon::TdxCustomTableControlReportLinkOptionsOnEveryPageClass __fastcall GetOptionsOnEveryPageClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	virtual Dxpscxcommon::TdxCustomTableControlReportLinkOptionsPreviewClass __fastcall GetOptionsPreviewClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsRefinementsClass __fastcall GetOptionsRefinementsClass(void);
	virtual Dxpscxcommon::TdxCustomTableControlReportLinkOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsSizeClass __fastcall GetOptionsSizeClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	void __fastcall AddReportRow(Dxpscore::TdxReportCell* AReportRow);
	void __fastcall AddHorizontalHardDelimiter(int ADelimiter);
	void __fastcall AddVerticalHardDelimiter(Dxpscore::TdxReportCell* ADelimiter)/* overload */;
	void __fastcall AddVerticalHardDelimiter(int ADelimiter)/* overload */;
	virtual TcxTreeListReportLinkBuilder* __fastcall CreateBuilder(void);
	__classmethod virtual TcxTreeListReportLinkBuilderClass __fastcall GetBuilderClass();
	int __fastcall ExtractIndentIndex(int AData);
	virtual TcxTreeListAttributeID __fastcall GetItemCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TcxTreeListCellCustomDrawInfo &ADrawInfo);
	virtual bool __fastcall IsCustomDrawn(TcxTreeListAttributeID AnAttributeID);
	unsigned __fastcall MakeIndentIndex(int AnIndex);
	__property TcxTreeListReportLinkStyles* ActiveStyles = {read=GetActiveStyles};
	__property TcxTreeListReportLinkBuilder* Builder = {read=FBuilder};
	__property System::Classes::TList* DelimitersHardHorz = {read=FDelimitersHardHorz};
	__property System::Classes::TList* DelimitersHardVert = {read=FDelimitersHardVert};
	__property TcxTreeListAttributeHostInfoServices* HostInfoServices = {read=FHostInfoServices};
	__property Cxtl::TcxCustomTreeList* TreeList = {read=GetTreeList};
	
public:
	__fastcall virtual TcxTreeListCustomReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxTreeListCustomReportLink(void);
	void __fastcall AddHorizontalPageBreak(Cxtl::TcxTreeListColumn* AColumn)/* overload */;
	void __fastcall AddHorizontalPageBreak(Cxtl::TcxTreeListColumn* const *AColumns, const int AColumns_Size)/* overload */;
	void __fastcall AddHorizontalPageBreak(const TcxTreeListColumnArray AColumns)/* overload */;
	void __fastcall AddHorizontalPageBreak(System::Classes::TList* AColumns)/* overload */;
	void __fastcall AddPageBreak(Cxtl::TcxTreeListNode* ANode)/* overload */;
	void __fastcall AddPageBreak(Cxtl::TcxTreeListNode* const *ANodes, const int ANodes_Size)/* overload */;
	void __fastcall AddPageBreak(const TcxTreeListNodeArray ANodes)/* overload */;
	void __fastcall AddPageBreak(System::Classes::TList* ANodes)/* overload */;
	__property TdxfmTreeListReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property Dxpscore::TAbstractdxReportCellData* ReportCellDataByColumn[Cxtl::TcxTreeListColumn* AColumn] = {read=GetReportCellDataByColumn};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow};
	__property Dxpscore::TdxReportCell* ReportRowsByNode[Cxtl::TcxTreeListNode* Node] = {read=GetReportRowByNode};
	
__published:
	__property Color = {default=16777215};
	__property Font;
	__property TcxTreeListReportLinkOptionsExpanding* OptionsExpanding = {read=GetOptionsExpanding, write=SetOptionsExpanding};
	__property TcxTreeListReportLinkOptionsFormatting* OptionsFormatting = {read=GetOptionsFormatting, write=SetOptionsFormatting};
	__property TcxTreeListReportLinkOptionsOnEveryPage* OptionsOnEveryPage = {read=GetOptionsOnEveryPage, write=SetOptionsOnEveryPage};
	__property TcxTreeListReportLinkOptionsPagination* OptionsPagination = {read=GetOptionsPagination, write=SetOptionsPagination};
	__property TcxTreeListReportLinkOptionsPreview* OptionsPreview = {read=GetOptionsPreview, write=SetOptionsPreview};
	__property TcxTreeListReportLinkOptionsRefinements* OptionsRefinements = {read=GetOptionsRefinements, write=SetOptionsRefinements};
	__property TcxTreeListReportLinkOptionsSelection* OptionsSelection = {read=GetOptionsSelection, write=SetOptionsSelection};
	__property TcxTreeListReportLinkOptionsSize* OptionsSize = {read=GetOptionsSize, write=SetOptionsSize};
	__property TcxTreeListReportLinkOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property ScaleFonts = {default=1};
	__property StyleRepository;
	__property TcxTreeListReportLinkStyles* Styles = {read=GetStyles, write=SetStyles};
	__property SupportedCustomDraw = {default=0};
	__property TcxTreeListReportLinkCustomDrawBandCellEvent OnCustomDrawBandCell = {read=FOnCustomDrawBandCell, write=SetOnCustomDrawBandCell};
	__property TcxTreeListReportLinkCustomDrawCellEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=SetOnCustomDrawCell};
	__property TcxTreeListReportLinkCustomDrawFooterCellEvent OnCustomDrawFooterCell = {read=FOnCustomDrawFooterCell, write=SetOnCustomDrawFooterCell};
	__property TcxTreeListReportLinkCustomDrawHeaderCellEvent OnCustomDrawHeaderCell = {read=FOnCustomDrawHeaderCell, write=SetOnCustomDrawHeaderCell};
	__property TcxTreeListReportLinkCustomDrawIndentCellEvent OnCustomDrawIndentCell = {read=FOnCustomDrawIndentCell, write=SetOnCustomDrawIndentCell};
	__property TcxTreeListReportLinkGetCustomPageBreaksEvent OnGetCustomPageBreaks = {read=FOnGetCustomPageBreaks, write=FOnGetCustomPageBreaks};
	__property TcxTreeListReportLinkInitializeBandCellEvent OnInitializeBandCell = {read=FOnInitializeBandCell, write=FOnInitializeBandCell};
	__property TcxTreeListReportLinkInitializeCellEvent OnInitializeCell = {read=FOnInitializeCell, write=FOnInitializeCell};
	__property TcxTreeListReportLinkInitializeFooterCellEvent OnInitializeFooterCell = {read=FOnInitializeFooterCell, write=FOnInitializeFooterCell};
	__property TcxTreeListReportLinkInitializeHeaderCellEvent OnInitializeHeaderCell = {read=FOnInitializeHeaderCell, write=FOnInitializeHeaderCell};
	__property TcxTreeListReportLinkInitializeIndentCellEvent OnInitializeIndentCell = {read=FOnInitializeIndentCell, write=FOnInitializeIndentCell};
};


class DELPHICLASS TcxTreeListReportLink;
class PASCALIMPLEMENTATION TcxTreeListReportLink : public TcxTreeListCustomReportLink
{
	typedef TcxTreeListCustomReportLink inherited;
	
private:
	HIDESBASE Cxtl::TcxTreeList* __fastcall GetTreeList(void);
	
public:
	__property Cxtl::TcxTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxTreeListCustomReportLink.Create */ inline __fastcall virtual TcxTreeListReportLink(System::Classes::TComponent* AOwner) : TcxTreeListCustomReportLink(AOwner) { }
	/* TcxTreeListCustomReportLink.Destroy */ inline __fastcall virtual ~TcxTreeListReportLink(void) { }
	
};


class DELPHICLASS TcxDBTreeListReportLink;
class PASCALIMPLEMENTATION TcxDBTreeListReportLink : public TcxTreeListCustomReportLink
{
	typedef TcxTreeListCustomReportLink inherited;
	
private:
	Cxdbtl::TcxDBTreeList* __fastcall GetDBTreeList(void);
	
public:
	__property Cxdbtl::TcxDBTreeList* DBTreeList = {read=GetDBTreeList};
public:
	/* TcxTreeListCustomReportLink.Create */ inline __fastcall virtual TcxDBTreeListReportLink(System::Classes::TComponent* AOwner) : TcxTreeListCustomReportLink(AOwner) { }
	/* TcxTreeListCustomReportLink.Destroy */ inline __fastcall virtual ~TcxDBTreeListReportLink(void) { }
	
};


class DELPHICLASS TcxVirtualTreeListReportLink;
class PASCALIMPLEMENTATION TcxVirtualTreeListReportLink : public TcxTreeListCustomReportLink
{
	typedef TcxTreeListCustomReportLink inherited;
	
private:
	Cxtldata::TcxVirtualTreeList* __fastcall GetVirtualTreeList(void);
	
public:
	__property Cxtldata::TcxVirtualTreeList* VirtualTreeList = {read=GetVirtualTreeList};
public:
	/* TcxTreeListCustomReportLink.Create */ inline __fastcall virtual TcxVirtualTreeListReportLink(System::Classes::TComponent* AOwner) : TcxTreeListCustomReportLink(AOwner) { }
	/* TcxTreeListCustomReportLink.Destroy */ inline __fastcall virtual ~TcxVirtualTreeListReportLink(void) { }
	
};


class PASCALIMPLEMENTATION TdxfmTreeListReportLinkDesignWindow : public Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow
{
	typedef Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshView;
	Vcl::Extctrls::TImage* imgShow;
	Vcl::Extctrls::TImage* imgOnEveryPage;
	Vcl::Extctrls::TBevel* bvlWarningHost;
	Cxpc::TcxTabSheet* tshBehaviors;
	Cxpc::TcxTabSheet* tshFormatting;
	Vcl::Extctrls::TImage* imgLookAndFeel;
	Vcl::Extctrls::TImage* imgRefinements;
	Cxpc::TcxTabSheet* tshPreview;
	Vcl::Extctrls::TImage* imgPreview;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxstyles::TcxStyleRepository* cxStyleRepository1;
	Cxstyles::TcxStyle* styleBandHeaders;
	Cxstyles::TcxStyle* styleStandard;
	Cxstyles::TcxStyle* stylePreview;
	Cxstyles::TcxStyle* styleCardShadow;
	Cxpc::TcxTabSheet* tshStyles;
	Vcl::Menus::TPopupMenu* pmStyles;
	Vcl::Menus::TMenuItem* miStyleFont;
	Vcl::Menus::TMenuItem* miStyleColor;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmap;
	Vcl::Menus::TMenuItem* milLine;
	Vcl::Menus::TMenuItem* miStylesSaveAs;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmapClear;
	Vcl::Menus::TMenuItem* miStyleRestoreDefaults;
	Vcl::Extctrls::TBevel* bvlStylesHost;
	Cxgraphics::TcxImageList* ilStylesPopup;
	Cxtl::TcxTreeList* PreviewTreeList;
	Cxtl::TcxTreeListColumn* colManufacturerName;
	Cxtl::TcxTreeListColumn* colManufacturerLogo;
	Cxtl::TcxTreeListColumn* colManufacturerCountry;
	Cxtl::TcxTreeListColumn* colCarModel;
	Cxtl::TcxTreeListColumn* colCarIsSUV;
	Vcl::Menus::TMenuItem* miStylesSelectAll;
	Vcl::Menus::TMenuItem* miLine4;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblRefinements;
	Cxlabel::TcxLabel* lblStyleSheets;
	Cxlabel::TcxLabel* Label1;
	Cxlabel::TcxLabel* lblUseNativeStyles;
	Cxlabel::TcxLabel* lblPreviewOptions;
	Cxlabel::TcxLabel* lblPreviewMaxLineCount;
	Cxcheckbox::TcxCheckBox* chbxShowBands;
	Cxcheckbox::TcxCheckBox* chbxShowHeaders;
	Cxcheckbox::TcxCheckBox* chbxShowFooters;
	Cxcheckbox::TcxCheckBox* chbxShowExpandButtons;
	Cxcheckbox::TcxCheckBox* chbxBandsOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxHeadersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxFootersOnEveryPage;
	Cxcheckbox::TcxCheckBox* chbxShowTreeLines;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxFlatCheckMarks;
	Cxcheckbox::TcxCheckBox* chbxDisplayGraphicsAsText;
	Cxcheckbox::TcxCheckBox* chbxTransparentGraphics;
	Cxcheckbox::TcxCheckBox* chbxSuppressBackgroundBitmaps;
	Cxcheckbox::TcxCheckBox* chbxConsumeSelectionStyle;
	Cxcheckbox::TcxCheckBox* chbxUseNativeStyles;
	Cxcheckbox::TcxCheckBox* chbxPreviewVisible;
	Cxcheckbox::TcxCheckBox* chbxPreviewAutoHeight;
	Cxdropdownedit::TcxComboBox* cbxLookAndFeel;
	Cxbuttons::TcxButton* btnStyleColor;
	Cxbuttons::TcxButton* btnStyleFont;
	Cxbuttons::TcxButton* btnStyleBackgroundBitmap;
	Cxbuttons::TcxButton* btnStyleSheetNew;
	Cxbuttons::TcxButton* btnStyleSheetCopy;
	Cxbuttons::TcxButton* btnStyleSheetDelete;
	Cxbuttons::TcxButton* btnStylesSaveAs;
	Cxbuttons::TcxButton* btnStyleSheetRename;
	Cxbuttons::TcxButton* btnStyleBackgroundBitmapClear;
	Cxbuttons::TcxButton* btnStyleRestoreDefaults;
	Cxlabel::TcxLabel* Bevel2;
	Cxlabel::TcxLabel* lblPreviewWindow;
	Cxlabel::TcxLabel* bvlRefinementsSeparator;
	Cxdropdownedit::TcxComboBox* cbxStyleSheets;
	Cxspinedit::TcxSpinEdit* sePreviewMaxLineCount;
	Cxspinedit::TcxSpinEdit* seSeparatorThickness;
	Cxlabel::TcxLabel* lblSize;
	Cxlabel::TcxLabel* lblSeparatorsThickness;
	Cxlabel::TcxLabel* lblSeparatorsColor;
	Cxlabel::TcxLabel* lblSeparators;
	Cxlabel::TcxLabel* lblSelection;
	Cxlabel::TcxLabel* lblExpanding;
	Vcl::Extctrls::TImage* imgSeparators;
	Vcl::Extctrls::TImage* imgSelection;
	Vcl::Extctrls::TImage* imgGridSize;
	Vcl::Extctrls::TImage* imgExpanding;
	Cxcheckbox::TcxCheckBox* chbxProcessSelection;
	Cxcheckbox::TcxCheckBox* chbxProcessExactSelection;
	Cxcheckbox::TcxCheckBox* chbxExplicitlyExpandNodes;
	Cxcheckbox::TcxCheckBox* chbxExpandNodes;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxcolorcombobox::TcxColorComboBox* ccbxSeparatorColor;
	void __fastcall LookAndFeelChange(System::TObject* Sender);
	void __fastcall OptionsRefinementsClick(System::TObject* Sender);
	void __fastcall PreviewVisibleClick(System::TObject* Sender);
	void __fastcall PreviewAutoHeightClick(System::TObject* Sender);
	void __fastcall OptionsSelectionClick(System::TObject* Sender);
	void __fastcall OptionsExpandingClick(System::TObject* Sender);
	void __fastcall OptionsViewClick(System::TObject* Sender);
	void __fastcall OptionsOnEveryPageClick(System::TObject* Sender);
	void __fastcall OptionsSizeClick(System::TObject* Sender);
	void __fastcall OptionsFormattingClick(System::TObject* Sender);
	void __fastcall pmStylesPopup(System::TObject* Sender);
	void __fastcall StyleColorClick(System::TObject* Sender);
	void __fastcall StyleFontClick(System::TObject* Sender);
	void __fastcall StyleBackgroundBitmapClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsClick(System::TObject* Sender);
	void __fastcall btnStyleSheetNewClick(System::TObject* Sender);
	void __fastcall btnStyleSheetCopyClick(System::TObject* Sender);
	void __fastcall btnStyleSheetDeleteClick(System::TObject* Sender);
	void __fastcall btnStyleSheetRenameClick(System::TObject* Sender);
	void __fastcall StylesSaveAsClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lbxStylesClick(System::TObject* Sender);
	void __fastcall StyleBackgroundBitmapClearClick(System::TObject* Sender);
	void __fastcall StyleRestoreDefaultsClick(System::TObject* Sender);
	void __fastcall miStylesSelectAllClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall lblUseNativeStylesClick(System::TObject* Sender);
	void __fastcall PreviewTreeListCustomDrawBandHeaderCell(Cxtl::TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxtl::TcxTreeListHeaderCellViewInfo* AViewInfo, bool &ADone);
	void __fastcall PreviewTreeListCustomDrawDataCell(Cxtl::TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxtl::TcxTreeListEditCellViewInfo* AViewInfo, bool &ADone);
	void __fastcall PreviewTreeListCustomDrawFooterCell(Cxtl::TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxtl::TcxTreeListFooterCellViewInfo* AViewInfo, bool &ADone);
	void __fastcall PreviewTreeListCustomDrawHeaderCell(Cxtl::TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxtl::TcxTreeListHeaderCellViewInfo* AViewInfo, bool &ADone);
	void __fastcall cbxStyleSheetsPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall PreviewMaxLineCountChanged(System::TObject* Sender);
	void __fastcall SeparatorColorChanged(System::TObject* Sender);
	void __fastcall SeparatorThicknessChanged(System::TObject* Sender);
	
private:
	Dxpscxcommon::TdxStylesListBox* lbxStyles;
	Dxextctrls::TdxPSWarningPane* wpIncorrectOnEveryPageState;
	Cxstyles::TcxStyle* __fastcall GetActiveStyle(void);
	bool __fastcall GetHasSelectedStyles(void);
	bool __fastcall GetHasSelectedStylesWithAssignedBitmap(void);
	HIDESBASE TcxTreeListCustomReportLink* __fastcall GetReportLink(void);
	bool __fastcall CanSelectAllStyles(void);
	void __fastcall CreateControls(void);
	void __fastcall CustomDrawBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall CustomDrawCheckMark(Cxgraphics::TcxCanvas* ACanvas, Cxtl::TcxTreeListEditCellViewInfo* AViewInfo);
	void __fastcall CustomDrawFooter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxtl::TcxTreeListFooterCellViewInfo* AViewInfo);
	void __fastcall CustomDrawHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxtl::TcxTreeListHeaderCellViewInfo* AViewInfo);
	void __fastcall CustomDrawTextRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const System::UnicodeString AText, System::Classes::TAlignment AnAlignmentHorz, Cxclasses::TcxAlignmentVert AnAlignmentVert, Cxgraphics::TcxViewParams &AParams);
	System::Classes::TAlignment __fastcall ExtractAlignmentHorz(Cxtl::TcxTreeListEditCellViewInfo* AViewInfo);
	Cxclasses::TcxAlignmentVert __fastcall ExtractAlignmentVert(Cxtl::TcxTreeListEditCellViewInfo* AViewInfo);
	void __fastcall InitializePreviewTreeList(void);
	void __fastcall InitializePreviewTreeListStyles(void);
	void __fastcall LoadDataIntoPreviewTreeList(void);
	void __fastcall RecreateStylesListBox(void);
	void __fastcall RestoreSelectedStyles(System::Classes::TList* AList);
	void __fastcall SaveSelectedStyles(System::Classes::TList* AList);
	void __fastcall SetActivePage(void);
	void __fastcall UpdatePreviewTreeListStyles(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	void __fastcall WarningPaneUpdate(void);
	void __fastcall SetOptionsExpandingByIndex(int Index, bool Value);
	void __fastcall SetOptionsFormattingByIndex(int Index, bool Value);
	void __fastcall SetOptionsOnEveryPageByIndex(int Index, bool Value);
	void __fastcall SetOptionsRefinementsByIndex(int Index, bool Value);
	void __fastcall SetOptionsSelectionByIndex(int Index, bool Value);
	void __fastcall SetOptionsSizeByIndex(int Index, bool Value);
	void __fastcall SetOptionsViewByIndex(int Index, bool Value);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	virtual int __fastcall GetDesignerTabIndex(void);
	virtual void __fastcall SetDesignerTabIndex(int Value);
	DYNAMIC void __fastcall DoActiveStyleSheetChanged(void);
	DYNAMIC void __fastcall DoFormActivated(bool AnActive);
	DYNAMIC void __fastcall DoRefreshStylesList(void);
	DYNAMIC void __fastcall DoStyleChanged(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	DYNAMIC void __fastcall DoStylesChanged(System::Classes::TStrings* AStrings, bool ARecreate);
	virtual void __fastcall GetSelectedStyleNames(System::Classes::TStrings* AStrings);
	virtual void __fastcall GetStyleNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall GetStyleSheetNames(/* out */ System::Classes::TStrings* &AStrings);
	__property Cxstyles::TcxStyle* ActiveStyle = {read=GetActiveStyle};
	__property bool HasSelectedStyles = {read=GetHasSelectedStyles, nodefault};
	__property bool HasSelectedStylesWithAssignedBitmap = {read=GetHasSelectedStylesWithAssignedBitmap, nodefault};
	
public:
	__fastcall virtual TdxfmTreeListReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmTreeListReportLinkDesignWindow(void);
	__property TcxTreeListCustomReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmTreeListReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmTreeListReportLinkDesignWindow(HWND ParentWindow) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 vspsTreeListFirst = System::Int8(0x0);
static const System::Int8 vspsTreeListBandHeader = System::Int8(0x0);
static const System::Int8 vspsTreeListContent = System::Int8(0x1);
static const System::Int8 vspsTreeListContentEven = System::Int8(0x2);
static const System::Int8 vspsTreeListContentOdd = System::Int8(0x3);
static const System::Int8 vspsTreeListFooter = System::Int8(0x4);
static const System::Int8 vspsTreeListFooterRow = System::Int8(0x5);
static const System::Int8 vspsTreeListHeader = System::Int8(0x6);
static const System::Int8 vspsTreeListIndent = System::Int8(0x7);
static const System::Int8 vspsTreeListPreview = System::Int8(0x8);
static const System::Int8 vspsTreeListSelection = System::Int8(0x9);
static const System::Int8 vspsTreeListBandBackground = System::Int8(0xa);
static const System::Int8 vspsTreeListLast = System::Int8(0xa);
static const System::Int8 cxTreeListAttributeIDBase = System::Int8(0x0);
static const System::Int8 cxTreeListUndefinedID = System::Int8(0x0);
static const System::Int8 cxTreeListBandID = System::Int8(0x1);
static const System::Int8 cxTreeListFooterID = System::Int8(0x2);
static const System::Int8 cxTreeListHeaderID = System::Int8(0x3);
static const System::Int8 cxTreeListIndentID = System::Int8(0x4);
static const System::Int8 cxTreeListNodeID = System::Int8(0x5);
extern PACKAGE System::Uitypes::TColor dxPSDefaultTreeListNodeSeparatorColor;
}	/* namespace Dxpscxtllnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXTLLNK)
using namespace Dxpscxtllnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxtllnkHPP
