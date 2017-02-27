// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxGridLayoutViewLnk.pas' rev: 24.00 (Win64)

#ifndef DxpscxgridlayoutviewlnkHPP
#define DxpscxgridlayoutviewlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomLayoutView.hpp>	// Pascal unit
#include <cxGridLayoutView.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxGridDBLayoutView.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPScxGridLnk.hpp>	// Pascal unit
#include <dxPSdxLCLnk.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxgridlayoutviewlnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxReportLayoutRecord;
class PASCALIMPLEMENTATION TdxReportLayoutRecord : public Dxpscxgridlnk::TdxReportCustomLayoutRecord
{
	typedef Dxpscxgridlnk::TdxReportCustomLayoutRecord inherited;
	
private:
	Dxpsdxlclnk::TdxPSReportLayoutGroupStandardLookAndFeel* FGroupLookAndFeel;
	Dxlayoutcontainer::TdxLayoutContainer* __fastcall GetContainer(void);
	Cxgridlayoutview::TcxGridLayoutViewRecord* __fastcall GetLayoutRecord(void);
	
protected:
	__property Dxlayoutcontainer::TdxLayoutContainer* Container = {read=GetContainer};
	__property Cxgridlayoutview::TcxGridLayoutViewRecord* LayoutRecord = {read=GetLayoutRecord};
	
public:
	__fastcall virtual TdxReportLayoutRecord(Dxpscore::TdxReportCell* AParent);
	__fastcall virtual ~TdxReportLayoutRecord(void);
public:
	/* TdxReportCustomLayoutRecord.CreateEx */ inline __fastcall virtual TdxReportLayoutRecord(Dxpscore::TdxReportCell* AParent, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord) : Dxpscxgridlnk::TdxReportCustomLayoutRecord(AParent, AGridRecord) { }
	
};


class DELPHICLASS TdxReportGridLayoutItem;
class PASCALIMPLEMENTATION TdxReportGridLayoutItem : public Dxpsdxlclnk::TdxReportLayoutLabeledItem
{
	typedef Dxpsdxlclnk::TdxReportLayoutLabeledItem inherited;
	
private:
	Dxpscore::TAbstractdxReportCellData* FDataCell;
	Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetGridRecord(void);
	Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetGridTableItem(void);
	HIDESBASE Cxgridlayoutview::TcxGridLayoutItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Initialize(Dxpscore::TBasedxReportLink* AReportLink);
	Dxpscore::TAbstractdxReportCellData* __fastcall CreateDataCell(void);
	
public:
	__fastcall virtual ~TdxReportGridLayoutItem(void);
	__property Dxpscore::TAbstractdxReportCellData* DataCell = {read=FDataCell};
	__property Cxgridcustomtableview::TcxCustomGridRecord* GridRecord = {read=GetGridRecord};
	__property Cxgridcustomtableview::TcxCustomGridTableItem* GridTableItem = {read=GetGridTableItem};
	__property Cxgridlayoutview::TcxGridLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxReportGroup.Create */ inline __fastcall virtual TdxReportGridLayoutItem(Dxpscore::TdxReportCell* AParent) : Dxpsdxlclnk::TdxReportLayoutLabeledItem(AParent) { }
	
};


class DELPHICLASS TdxGridLayoutViewFormatter;
class DELPHICLASS TdxGridLayoutViewAdapter;
class DELPHICLASS TdxGridLayoutViewBuilder;
class PASCALIMPLEMENTATION TdxGridLayoutViewFormatter : public Dxpscxgridlnk::TdxGridCustomLayoutViewFormatter
{
	typedef Dxpscxgridlnk::TdxGridCustomLayoutViewFormatter inherited;
	
private:
	Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo* FCalculatingRecordViewInfo;
	System::Types::TRect __fastcall GetItemBounds(Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo* ARecordViewInfo, Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	Cxgridlayoutview::TcxGridLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	void __fastcall GetViewInfoHandler(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* &AViewInfo);
	
protected:
	virtual int __fastcall GetFirstRecordOffset(void);
	virtual int __fastcall GetInterRecordsSpaceHorz(void);
	virtual int __fastcall GetInterRecordsSpaceVert(void);
	void __fastcall CreateCaptionCell(TdxReportLayoutRecord* ARecord);
	void __fastcall DoCreateCaptionCell(TdxReportLayoutRecord* ARecord);
	void __fastcall InitializeRecordCells(TdxReportLayoutRecord* ARecord);
	Dxpsdxlclnk::TdxCustomReportLayoutItemClass __fastcall GetReportItemClass(Dxlayoutcontainer::TdxCustomLayoutItem* ALayoutItem);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetGroupViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetItemCaptionViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetRecordCaptionViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	Dxpscxcommon::TdxReportItemViewParams __fastcall GetRecordViewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	void __fastcall GetContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall GetGroupParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall GetItemParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall GetRecordCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property Cxgridlayoutview::TcxGridLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	
public:
	HIDESBASE TdxGridLayoutViewAdapter* __fastcall Adapter(void)/* overload */;
	HIDESBASE TdxGridLayoutViewBuilder* __fastcall Builder(void)/* overload */;
	virtual void __fastcall DoInitializeRecord(Dxpscxgridlnk::TdxReportCustomLayoutRecord* ARecord, Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetItemViewParams(Cxgridcustomtableview::TcxCustomGridTableItem* ATableItem, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, bool AnIsPreview = false, bool AIsDataCell = false);
	virtual Dxpscxgridlnk::TdxReportCustomLayoutRecordClass __fastcall GetRecordClass(Cxgridcustomlayoutview::TcxGridCustomLayoutRecord* AGridRecord);
public:
	/* TdxCustomGridTableViewFormatter.Create */ inline __fastcall virtual TdxGridLayoutViewFormatter(Dxpscxgridlnk::TdxCustomGridViewBuilder* ABuilder) : Dxpscxgridlnk::TdxGridCustomLayoutViewFormatter(ABuilder) { }
	/* TdxCustomGridTableViewFormatter.Destroy */ inline __fastcall virtual ~TdxGridLayoutViewFormatter(void) { }
	
private:
	void *__IcxGridLayoutViewStylesHelper;	/* Cxgridlayoutview::IcxGridLayoutViewStylesHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79CDADCA-DDC3-439F-9881-3406B13399EA}
	operator Cxgridlayoutview::_di_IcxGridLayoutViewStylesHelper()
	{
		Cxgridlayoutview::_di_IcxGridLayoutViewStylesHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridlayoutview::IcxGridLayoutViewStylesHelper*(void) { return (Cxgridlayoutview::IcxGridLayoutViewStylesHelper*)&__IcxGridLayoutViewStylesHelper; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxGridLayoutViewAdapter : public Dxpscxgridlnk::TdxGridCustomLayoutViewAdapter
{
	typedef Dxpscxgridlnk::TdxGridCustomLayoutViewAdapter inherited;
	
protected:
	HIDESBASE Cxgridlayoutview::TcxGridLayoutViewStyles* __fastcall Styles(void)/* overload */;
public:
	/* TdxCustomGridTableViewAdapter.Create */ inline __fastcall virtual TdxGridLayoutViewAdapter(Dxpscxgridlnk::TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : Dxpscxgridlnk::TdxGridCustomLayoutViewAdapter(AMasterAdapter, AGridView) { }
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridLayoutViewAdapter(void) { }
	
};


class PASCALIMPLEMENTATION TdxGridLayoutViewBuilder : public Dxpscxgridlnk::TdxGridCustomLayoutViewBuilder
{
	typedef Dxpscxgridlnk::TdxGridCustomLayoutViewBuilder inherited;
	
private:
	HIDESBASE TdxReportLayoutRecord* __fastcall GetRecord(int Index);
	
protected:
	HIDESBASE Cxgridlayoutview::TcxGridLayoutView* __fastcall GridView(void)/* overload */;
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	virtual void __fastcall DoBuildViewBody(void);
	virtual void __fastcall DoResizeRecords(void);
	__property TdxReportLayoutRecord* Records[int Index] = {read=GetRecord};
	
public:
	__fastcall virtual TdxGridLayoutViewBuilder(Dxpscxgridlnk::TdxGridReportLink* AReportLink, Dxpscxgridlnk::TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TdxGridLayoutViewBuilder(void);
	__classmethod virtual Dxpscxgridlnk::TdxGridViewAdapterClass __fastcall AdapterClass();
	HIDESBASE TdxGridLayoutViewFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual Dxpscxgridlnk::TdxGridViewFormatterClass __fastcall FormatterClass();
};


class DELPHICLASS TdxGridDBLayoutViewAdapter;
class PASCALIMPLEMENTATION TdxGridDBLayoutViewAdapter : public TdxGridLayoutViewAdapter
{
	typedef TdxGridLayoutViewAdapter inherited;
	
protected:
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall DataController(void)/* overload */;
	virtual Cxdbdata::TcxDBDataModeController* __fastcall DBDataModeController(void);
public:
	/* TdxCustomGridTableViewAdapter.Create */ inline __fastcall virtual TdxGridDBLayoutViewAdapter(Dxpscxgridlnk::TdxCustomGridViewAdapter* AMasterAdapter, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridLayoutViewAdapter(AMasterAdapter, AGridView) { }
	/* TdxCustomGridTableViewAdapter.Destroy */ inline __fastcall virtual ~TdxGridDBLayoutViewAdapter(void) { }
	
};


class DELPHICLASS TdxGridDBLayoutViewBuilder;
class PASCALIMPLEMENTATION TdxGridDBLayoutViewBuilder : public TdxGridLayoutViewBuilder
{
	typedef TdxGridLayoutViewBuilder inherited;
	
protected:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GridViewClass();
	
public:
	__classmethod virtual Dxpscxgridlnk::TdxGridViewAdapterClass __fastcall AdapterClass();
public:
	/* TdxGridLayoutViewBuilder.Create */ inline __fastcall virtual TdxGridDBLayoutViewBuilder(Dxpscxgridlnk::TdxGridReportLink* AReportLink, Dxpscxgridlnk::TdxCustomGridViewBuilder* AMasterBuilder, Cxgridcustomview::TcxCustomGridView* AGridView) : TdxGridLayoutViewBuilder(AReportLink, AMasterBuilder, AGridView) { }
	/* TdxGridLayoutViewBuilder.Destroy */ inline __fastcall virtual ~TdxGridDBLayoutViewBuilder(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxgridlayoutviewlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXGRIDLAYOUTVIEWLNK)
using namespace Dxpscxgridlayoutviewlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxgridlayoutviewlnkHPP
