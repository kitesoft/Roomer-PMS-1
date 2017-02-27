// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridRows.pas' rev: 24.00 (Win64)

#ifndef CxgridrowsHPP
#define CxgridrowsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridDetailsSite.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridrows
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridDataCellViewInfoClass;

class DELPHICLASS TcxGridPreviewHitTest;
class PASCALIMPLEMENTATION TcxGridPreviewHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridPreviewHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridPreviewHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};


class DELPHICLASS TcxGridDataCellPainter;
class DELPHICLASS TcxGridDataCellViewInfo;
class PASCALIMPLEMENTATION TcxGridDataCellPainter : public Cxgridcustomtableview::TcxGridTableDataCellPainter
{
	typedef Cxgridcustomtableview::TcxGridTableDataCellPainter inherited;
	
private:
	HIDESBASE TcxGridDataCellViewInfo* __fastcall GetViewInfo(void);
	
protected:
	bool __fastcall CanDelayedDrawBorder(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxBorder ABorder);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridDataCellViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridDataCellPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomtableview::TcxGridTableDataCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDataCellPainter(void) { }
	
};


class DELPHICLASS TcxGridDataRowPainter;
class DELPHICLASS TcxGridDataRowViewInfo;
class PASCALIMPLEMENTATION TcxGridDataRowPainter : public Cxgridtableview::TcxCustomGridRowPainter
{
	typedef Cxgridtableview::TcxCustomGridRowPainter inherited;
	
private:
	HIDESBASE TcxGridDataRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawCells(void);
	virtual bool __fastcall GetShowCells(void);
	virtual void __fastcall Paint(void);
	__property bool ShowCells = {read=GetShowCells, nodefault};
	__property TcxGridDataRowViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridDataRowPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridtableview::TcxCustomGridRowPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDataRowPainter(void) { }
	
};


class DELPHICLASS TcxGridNewItemRowPainter;
class DELPHICLASS TcxGridNewItemRowViewInfo;
class PASCALIMPLEMENTATION TcxGridNewItemRowPainter : public TcxGridDataRowPainter
{
	typedef TcxGridDataRowPainter inherited;
	
private:
	HIDESBASE TcxGridNewItemRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawSeparator(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	virtual bool __fastcall GetShowCells(void);
	virtual void __fastcall Paint(void);
	__property TcxGridNewItemRowViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridNewItemRowPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridDataRowPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridNewItemRowPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};


class DELPHICLASS TcxGridMasterDataRowDetailsSiteTabsPainter;
class DELPHICLASS TcxGridMasterDataRowDetailsSiteLeftTabsViewInfo;
class PASCALIMPLEMENTATION TcxGridMasterDataRowDetailsSiteTabsPainter : public Cxgriddetailssite::TcxGridDetailsSiteTabsPainter
{
	typedef Cxgriddetailssite::TcxGridDetailsSiteTabsPainter inherited;
	
private:
	HIDESBASE TcxGridMasterDataRowDetailsSiteLeftTabsViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBottomGridLine(void);
	virtual void __fastcall Paint(void);
	__property TcxGridMasterDataRowDetailsSiteLeftTabsViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridMasterDataRowDetailsSiteTabsPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgriddetailssite::TcxGridDetailsSiteTabsPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridMasterDataRowDetailsSiteTabsPainter(void) { }
	
};


class DELPHICLASS TcxGridExpandButtonCellPainter;
class DELPHICLASS TcxGridExpandButtonCellViewInfo;
class PASCALIMPLEMENTATION TcxGridExpandButtonCellPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridExpandButtonCellViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBorder(Cxgraphics::TcxBorder ABorder);
	__property TcxGridExpandButtonCellViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridExpandButtonCellPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridExpandButtonCellPainter(void) { }
	
};


class DELPHICLASS TcxGridMasterDataRowPainter;
class DELPHICLASS TcxGridMasterDataRowViewInfo;
class PASCALIMPLEMENTATION TcxGridMasterDataRowPainter : public TcxGridDataRowPainter
{
	typedef TcxGridDataRowPainter inherited;
	
private:
	HIDESBASE TcxGridMasterDataRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawCells(void);
	virtual void __fastcall DrawDetailsSite(void);
	virtual void __fastcall DrawExpandButtonCell(void);
	virtual bool __fastcall NeedsPainting(void);
	virtual void __fastcall Paint(void);
	__property TcxGridMasterDataRowViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridMasterDataRowPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridDataRowPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridMasterDataRowPainter(void) { }
	
};


class DELPHICLASS TcxGridGroupCellPainter;
class DELPHICLASS TcxGridGroupCellViewInfo;
class PASCALIMPLEMENTATION TcxGridGroupCellPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridGroupCellViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBorder(Cxgraphics::TcxBorder ABorder);
	__property TcxGridGroupCellViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridGroupCellPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupCellPainter(void) { }
	
};


class DELPHICLASS TcxGridGroupSummaryCellPainter;
class DELPHICLASS TcxGridGroupSummaryCellViewInfo;
class PASCALIMPLEMENTATION TcxGridGroupSummaryCellPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridGroupSummaryCellViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridGroupSummaryCellViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridGroupSummaryCellPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupSummaryCellPainter(void) { }
	
};


class DELPHICLASS TcxGridGroupRowPainter;
class DELPHICLASS TcxGridGroupRowViewInfo;
class PASCALIMPLEMENTATION TcxGridGroupRowPainter : public Cxgridtableview::TcxCustomGridRowPainter
{
	typedef Cxgridtableview::TcxCustomGridRowPainter inherited;
	
private:
	HIDESBASE TcxGridGroupRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawSeparator(void);
	virtual void __fastcall DrawSummaryCells(void);
	virtual void __fastcall Paint(void);
	__property TcxGridGroupRowViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridGroupRowPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridtableview::TcxCustomGridRowPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupRowPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};


class DELPHICLASS TcxGridCellViewInfo;
class PASCALIMPLEMENTATION TcxGridCellViewInfo : public Cxgridcustomtableview::TcxGridTableCellViewInfo
{
	typedef Cxgridcustomtableview::TcxGridTableCellViewInfo inherited;
	
private:
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GetGridView(void);
	Cxgraphics::TcxGridLines __fastcall GetGridLines(void);
	HIDESBASE Cxgridtableview::TcxCustomGridRow* __fastcall GetGridRecord(void);
	HIDESBASE Cxgridtableview::TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	Cxgridtableview::TcxCustomGridRowViewInfo* __fastcall GetRecordViewInfo(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	__property Cxgraphics::TcxGridLines GridLines = {read=GetGridLines, nodefault};
	
public:
	__property Cxgridtableview::TcxCustomGridRow* GridRecord = {read=GetGridRecord};
	__property Cxgridtableview::TcxGridTableView* GridView = {read=GetGridView};
	__property Cxgridtableview::TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property Cxgridtableview::TcxCustomGridRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TcxGridTableCellViewInfo.Create */ inline __fastcall virtual TcxGridCellViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo) : Cxgridcustomtableview::TcxGridTableCellViewInfo(ARecordViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCellViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridDataCellViewInfo : public Cxgridcustomtableview::TcxGridTableDataCellViewInfo
{
	typedef Cxgridcustomtableview::TcxGridTableDataCellViewInfo inherited;
	
private:
	bool FIsMerged;
	bool FIsMerging;
	System::Classes::TList* FMergedCells;
	TcxGridDataCellViewInfo* FMergingCell;
	int FOriginalHeight;
	HIDESBASE Cxgridtableview::TcxGridTableViewInfoCacheItem* __fastcall GetCacheItem(void);
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GetGridView(void);
	HIDESBASE Cxgridtableview::TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	Cxgridtableview::TcxGridColumn* __fastcall GetItem(void);
	TcxGridDataCellViewInfo* __fastcall GetMergedCell(int Index);
	int __fastcall GetMergedCellCount(void);
	TcxGridDataCellViewInfo* __fastcall GetMergedCellOfFocusedRow(void);
	TcxGridDataRowViewInfo* __fastcall GetRecordViewInfo(void);
	
protected:
	System::Types::TRect OriginalBounds;
	virtual void __fastcall AfterRowsViewInfoCalculate(void);
	virtual void __fastcall AfterRowsViewInfoOffset(void);
	virtual bool __fastcall CalculateSelected(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanBeMergingCell(void);
	virtual bool __fastcall CanCellMerging(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual bool __fastcall GetFocused(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall GetVisibleForHitTest(void);
	virtual bool __fastcall HasHitTestPoint(const System::Types::TPoint P);
	virtual void __fastcall Offset(int DX, int DY);
	void __fastcall RemoveMergedCell(TcxGridDataCellViewInfo* ACellViewInfo);
	__property Cxgridtableview::TcxGridTableViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property TcxGridDataCellViewInfo* MergedCellOfFocusedRow = {read=GetMergedCellOfFocusedRow};
	__property Cxgridtableview::TcxGridTableView* GridView = {read=GetGridView};
	__property Cxgridtableview::TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int OriginalHeight = {read=FOriginalHeight, nodefault};
	
public:
	__fastcall virtual ~TcxGridDataCellViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall MouseMove(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0));
	__property bool IsMerged = {read=FIsMerged, nodefault};
	__property bool IsMerging = {read=FIsMerging, nodefault};
	__property Cxgridtableview::TcxGridColumn* Item = {read=GetItem};
	__property int MergedCellCount = {read=GetMergedCellCount, nodefault};
	__property TcxGridDataCellViewInfo* MergedCells[int Index] = {read=GetMergedCell};
	__property TcxGridDataCellViewInfo* MergingCell = {read=FMergingCell};
	__property TcxGridDataRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TcxGridTableDataCellViewInfo.Create */ inline __fastcall virtual TcxGridDataCellViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo, Cxgridcustomtableview::TcxCustomGridTableItem* AItem) : Cxgridcustomtableview::TcxGridTableDataCellViewInfo(ARecordViewInfo, AItem) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


typedef System::TMetaClass* TcxGridDataRowCellsAreaViewInfoClass;

class DELPHICLASS TcxGridDataRowCellsAreaViewInfo;
class PASCALIMPLEMENTATION TcxGridDataRowCellsAreaViewInfo : public TcxGridCellViewInfo
{
	typedef TcxGridCellViewInfo inherited;
	
private:
	HIDESBASE TcxGridDataRowViewInfo* __fastcall GetRecordViewInfo(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual bool __fastcall CalculateVisible(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual bool __fastcall GetIsBottom(void);
	
public:
	__fastcall virtual TcxGridDataRowCellsAreaViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo);
	virtual bool __fastcall CanDrawSelected(void);
	virtual bool __fastcall DrawMergedCells(void);
	__property bool IsBottom = {read=GetIsBottom, nodefault};
	__property TcxGridDataRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridDataRowCellsAreaViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridPreviewCellViewInfoClass;

class DELPHICLASS TcxGridPreviewCellViewInfo;
class PASCALIMPLEMENTATION TcxGridPreviewCellViewInfo : public TcxGridDataCellViewInfo
{
	typedef TcxGridDataCellViewInfo inherited;
	
private:
	Cxgridtableview::TcxGridPreview* __fastcall GetPreview(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual void __fastcall GetEditViewDataContentOffsets(System::Types::TRect &R);
	virtual int __fastcall GetHeight(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual int __fastcall GetMaxLineCount(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual bool __fastcall SupportsZeroHeight(void);
	__property Cxgridtableview::TcxGridPreview* Preview = {read=GetPreview};
public:
	/* TcxGridDataCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridPreviewCellViewInfo(void) { }
	
public:
	/* TcxGridTableDataCellViewInfo.Create */ inline __fastcall virtual TcxGridPreviewCellViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo, Cxgridcustomtableview::TcxCustomGridTableItem* AItem) : TcxGridDataCellViewInfo(ARecordViewInfo, AItem) { }
	
};


class PASCALIMPLEMENTATION TcxGridDataRowViewInfo : public Cxgridtableview::TcxCustomGridRowViewInfo
{
	typedef Cxgridtableview::TcxCustomGridRowViewInfo inherited;
	
private:
	int FCellHeight;
	System::Types::TRect FCellsAreaBounds;
	TcxGridDataRowCellsAreaViewInfo* FCellsAreaViewInfo;
	System::Classes::TList* FCellViewInfos;
	TcxGridPreviewCellViewInfo* FPreviewViewInfo;
	TcxGridDataCellViewInfo* __fastcall GetCellViewInfo(int Index);
	int __fastcall GetCellViewInfoCount(void);
	HIDESBASE Cxgridtableview::TcxGridDataRow* __fastcall GetGridRecord(void);
	bool __fastcall GetHasPreview(void);
	TcxGridDataCellViewInfo* __fastcall GetInternalCellViewInfo(int Index);
	void __fastcall CreateViewInfos(void);
	void __fastcall DestroyViewInfos(void);
	
protected:
	virtual bool __fastcall AdjustToIntegralBottomBound(int &ABound);
	virtual void __fastcall AfterRowsViewInfoCalculate(void);
	virtual void __fastcall AfterRowsViewInfoOffset(void);
	void __fastcall ApplyMergedCellsBounds(System::Types::TRect &R, Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	void __fastcall ApplyMergingCellsBounds(System::Types::TRect &R);
	virtual void __fastcall CalculateCellViewInfo(int AIndex);
	int __fastcall CalculateDataAutoHeight(bool ACheckEditingCell = true);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateMultilineEditMinHeight(void);
	virtual bool __fastcall CanDelayedDrawDataCellBorders(void);
	virtual bool __fastcall CanSize(void);
	virtual void __fastcall CheckRowHeight(int &AValue);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Types::TRect __fastcall GetBackgroundBitmapBounds(void);
	virtual int __fastcall GetBaseHeight(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall SetRowHeight(int Value);
	HIDESBASE virtual int __fastcall GetCellHeight(int AIndex);
	virtual int __fastcall GetCellHeightValue(void);
	virtual int __fastcall GetCellLeftBound(int AIndex);
	virtual int __fastcall GetCellTopBound(int AIndex);
	virtual System::Types::TRect __fastcall GetCellsAreaBounds(void);
	virtual TcxGridDataRowCellsAreaViewInfoClass __fastcall GetCellsAreaViewInfoClass(void);
	virtual TcxGridDataCellViewInfoClass __fastcall GetCellViewInfoClass(int AIndex);
	virtual int __fastcall GetCellWidth(int AIndex);
	virtual TcxGridPreviewCellViewInfoClass __fastcall GetPreviewViewInfoClass(void);
	virtual bool __fastcall GetShowPreview(void);
	virtual bool __fastcall IsCellVisible(int AIndex);
	__property int CellHeight = {read=GetCellHeightValue, nodefault};
	__property bool ShowPreview = {read=GetShowPreview, nodefault};
	
public:
	__fastcall virtual TcxGridDataRowViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxGridDataRowViewInfo(void);
	virtual void __fastcall BeforeCellRecalculation(Cxgridcustomtableview::TcxGridTableCellViewInfo* ACell);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual System::Types::TRect __fastcall GetAreaBoundsForPainting(void);
	virtual System::Types::TRect __fastcall GetBoundsForInvalidate(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual System::Types::TRect __fastcall GetBoundsForItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual Cxgraphics::TcxBorders __fastcall GetCellBorders(bool AIsRight, bool AIsBottom);
	virtual Cxgridcustomtableview::TcxGridTableDataCellViewInfo* __fastcall GetCellViewInfoByItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	__property System::Types::TRect CellsAreaBounds = {read=GetCellsAreaBounds};
	__property TcxGridDataRowCellsAreaViewInfo* CellsAreaViewInfo = {read=FCellsAreaViewInfo};
	__property int CellViewInfoCount = {read=GetCellViewInfoCount, nodefault};
	__property TcxGridDataCellViewInfo* CellViewInfos[int Index] = {read=GetCellViewInfo};
	__property Cxgridtableview::TcxGridDataRow* GridRecord = {read=GetGridRecord};
	__property bool HasPreview = {read=GetHasPreview, nodefault};
	__property TcxGridDataCellViewInfo* InternalCellViewInfos[int Index] = {read=GetInternalCellViewInfo};
	__property TcxGridPreviewCellViewInfo* PreviewViewInfo = {read=FPreviewViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


class PASCALIMPLEMENTATION TcxGridNewItemRowViewInfo : public TcxGridDataRowViewInfo
{
	typedef TcxGridDataRowViewInfo inherited;
	
private:
	int FHeight;
	
protected:
	virtual bool __fastcall CalculateSelected(void);
	virtual bool __fastcall CanDelayedDrawDataCellBorders(void);
	virtual bool __fastcall CanShowDataCellHint(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetCellLeftBound(int AIndex);
	virtual int __fastcall GetCellWidth(int AIndex);
	virtual int __fastcall GetHeight(void);
	virtual System::UnicodeString __fastcall GetInfoText(void);
	virtual Cxgridtableview::TcxGridSpecialRowOptions* __fastcall GetOptions(void);
	virtual System::Uitypes::TColor __fastcall GetSeparatorColor(void);
	virtual int __fastcall GetSeparatorWidth(void);
	virtual bool __fastcall GetShowInfoText(void);
	virtual bool __fastcall GetShowPreview(void);
	virtual int __fastcall GetStyleIndex(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasFooters(void);
	virtual bool __fastcall HasLastHorzGridLine(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__property System::UnicodeString InfoText = {read=GetInfoText};
	__property Cxgridtableview::TcxGridSpecialRowOptions* Options = {read=GetOptions};
	__property bool ShowInfoText = {read=GetShowInfoText, nodefault};
public:
	/* TcxGridDataRowViewInfo.Create */ inline __fastcall virtual TcxGridNewItemRowViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord) : TcxGridDataRowViewInfo(ARecordsViewInfo, ARecord) { }
	/* TcxGridDataRowViewInfo.Destroy */ inline __fastcall virtual ~TcxGridNewItemRowViewInfo(void) { }
	
};


class DELPHICLASS TcxGridFilterRowViewInfo;
class PASCALIMPLEMENTATION TcxGridFilterRowViewInfo : public TcxGridNewItemRowViewInfo
{
	typedef TcxGridNewItemRowViewInfo inherited;
	
private:
	HIDESBASE Cxgridtableview::TcxGridFilterRow* __fastcall GetGridRecord(void);
	
protected:
	virtual Cxgridtableview::TcxGridSpecialRowOptions* __fastcall GetOptions(void);
	virtual bool __fastcall GetShowInfoText(void);
	virtual int __fastcall GetStyleIndex(void);
	
public:
	__property Cxgridtableview::TcxGridFilterRow* GridRecord = {read=GetGridRecord};
public:
	/* TcxGridDataRowViewInfo.Create */ inline __fastcall virtual TcxGridFilterRowViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord) : TcxGridNewItemRowViewInfo(ARecordsViewInfo, ARecord) { }
	/* TcxGridDataRowViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFilterRowViewInfo(void) { }
	
};


class DELPHICLASS TcxGridDetailsSiteViewInfo;
class PASCALIMPLEMENTATION TcxGridMasterDataRowDetailsSiteLeftTabsViewInfo : public Cxgriddetailssite::TcxGridDetailsSiteLeftTabsViewInfo
{
	typedef Cxgriddetailssite::TcxGridDetailsSiteLeftTabsViewInfo inherited;
	
private:
	System::Uitypes::TColor __fastcall GetBottomGridLineColor(void);
	int __fastcall GetBottomGridLineWidth(void);
	TcxGridDetailsSiteViewInfo* __fastcall GetSiteViewInfo(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual System::Types::TRect __fastcall GetBoundsRect(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetBottomGridLineBounds(void);
	__property int BottomGridLineWidth = {read=GetBottomGridLineWidth, nodefault};
	
public:
	virtual bool __fastcall HasBottomGridLine(void);
	__property System::Types::TRect BottomGridLineBounds = {read=GetBottomGridLineBounds};
	__property System::Uitypes::TColor BottomGridLineColor = {read=GetBottomGridLineColor, nodefault};
	__property TcxGridDetailsSiteViewInfo* SiteViewInfo = {read=GetSiteViewInfo};
public:
	/* TcxCustomGridDetailsSiteTabsViewInfo.Create */ inline __fastcall virtual TcxGridMasterDataRowDetailsSiteLeftTabsViewInfo(Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfo* ASiteViewInfo) : Cxgriddetailssite::TcxGridDetailsSiteLeftTabsViewInfo(ASiteViewInfo) { }
	/* TcxCustomGridDetailsSiteTabsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridMasterDataRowDetailsSiteLeftTabsViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridDetailsSiteViewInfoClass;

class PASCALIMPLEMENTATION TcxGridDetailsSiteViewInfo : public Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfo
{
	typedef Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfo inherited;
	
private:
	TcxGridMasterDataRowViewInfo* FMasterDataRowViewInfo;
	Cxgridtableview::TcxGridMasterTableViewInfoCacheItem* __fastcall GetCacheItem(void);
	Cxgridtableview::TcxGridTableView* __fastcall GetMasterGridView(void);
	Cxgridtableview::TcxGridTableViewInfo* __fastcall GetMasterGridViewInfo(void);
	
protected:
	virtual void __fastcall ControlFocusChanged(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveGridView(void);
	virtual bool __fastcall GetActiveGridViewExists(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveGridViewValue(void);
	virtual Cxgridlevel::TcxGridLevel* __fastcall GetActiveLevel(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual Cxcontrols::TcxControl* __fastcall GetContainer(void);
	virtual Cxgridcustomview::TcxCustomGridDesignController* __fastcall GetDesignController(void);
	virtual bool __fastcall GetFullyVisible(void);
	virtual int __fastcall GetHeight(void);
	virtual System::TObject* __fastcall GetMasterRecord(void);
	virtual int __fastcall GetMaxHeight(void);
	virtual int __fastcall GetMaxNormalHeight(void);
	virtual int __fastcall GetMaxWidth(void);
	virtual int __fastcall GetNormalHeight(void);
	virtual Cxgriddetailssite::TcxCustomGridDetailsSiteTabsViewInfoClass __fastcall GetTabsViewInfoClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall InitTabHitTest(Cxgriddetailssite::TcxGridDetailsSiteTabHitTest* AHitTest);
	__property Cxgridtableview::TcxGridMasterTableViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property Cxgridtableview::TcxGridTableView* MasterGridView = {read=GetMasterGridView};
	__property Cxgridtableview::TcxGridTableViewInfo* MasterGridViewInfo = {read=GetMasterGridViewInfo};
	__property TcxGridMasterDataRowViewInfo* MasterDataRowViewInfo = {read=FMasterDataRowViewInfo};
	
public:
	__fastcall virtual TcxGridDetailsSiteViewInfo(TcxGridMasterDataRowViewInfo* AMasterDataRowViewInfo);
	__fastcall virtual ~TcxGridDetailsSiteViewInfo(void);
	virtual void __fastcall ChangeActiveTab(Cxgridlevel::TcxGridLevel* ALevel, bool AFocusView = false);
	virtual bool __fastcall DetailHasData(Cxgridlevel::TcxGridLevel* ALevel);
	bool __fastcall HasMaxHeight(void);
	virtual bool __fastcall SupportsTabAccelerators(void);
};


typedef System::TMetaClass* TcxGridExpandButtonCellViewInfoClass;

class PASCALIMPLEMENTATION TcxGridExpandButtonCellViewInfo : public TcxGridCellViewInfo
{
	typedef TcxGridCellViewInfo inherited;
	
private:
	HIDESBASE TcxGridMasterDataRowViewInfo* __fastcall GetRecordViewInfo(void);
	System::Types::TRect __fastcall GetRightBorderRestSpaceBounds(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual int __fastcall GetBaseWidth(void);
	virtual System::Types::TRect __fastcall GetBorderBounds(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__property int BaseWidth = {read=GetBaseWidth, nodefault};
	__property System::Types::TRect RightBorderRestSpaceBounds = {read=GetRightBorderRestSpaceBounds};
	
public:
	__property TcxGridMasterDataRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TcxGridTableCellViewInfo.Create */ inline __fastcall virtual TcxGridExpandButtonCellViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo) : TcxGridCellViewInfo(ARecordViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridExpandButtonCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridDetailsAreaViewInfoClass;

class DELPHICLASS TcxGridDetailsAreaViewInfo;
class PASCALIMPLEMENTATION TcxGridDetailsAreaViewInfo : public TcxGridCellViewInfo
{
	typedef TcxGridCellViewInfo inherited;
	
private:
	HIDESBASE TcxGridMasterDataRowViewInfo* __fastcall GetRecordViewInfo(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	
public:
	__property TcxGridMasterDataRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TcxGridTableCellViewInfo.Create */ inline __fastcall virtual TcxGridDetailsAreaViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo) : TcxGridCellViewInfo(ARecordViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridDetailsAreaViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridMasterDataRowViewInfo : public TcxGridDataRowViewInfo
{
	typedef TcxGridDataRowViewInfo inherited;
	
private:
	TcxGridDetailsAreaViewInfo* FDetailsAreaViewInfo;
	TcxGridDetailsSiteViewInfo* FDetailsSiteViewInfo;
	TcxGridExpandButtonCellViewInfo* FExpandButtonCellViewInfo;
	int FRestHeight;
	HIDESBASE Cxgridtableview::TcxGridMasterTableViewInfoCacheItem* __fastcall GetCacheItem(void);
	System::Types::TRect __fastcall GetDetailsSiteIndentBounds(void);
	HIDESBASE Cxgridtableview::TcxGridMasterDataRow* __fastcall GetGridRecord(void);
	
protected:
	virtual void __fastcall CalculateExpandButtonBounds(System::Types::TRect &ABounds);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateRestHeight(int ARowHeight);
	virtual void __fastcall ControlFocusChanged(void);
	virtual int __fastcall GetDataHeight(void);
	virtual int __fastcall GetDataIndent(void);
	virtual int __fastcall GetDataWidth(void);
	virtual bool __fastcall GetDetailsSiteVisible(void);
	virtual System::Types::TRect __fastcall GetExpandButtonAreaBounds(void);
	virtual int __fastcall GetMaxHeight(void);
	virtual int __fastcall GetPixelScrollSize(void);
	virtual bool __fastcall IsDetailVisible(Cxgridcustomview::TcxCustomGridView* ADetail);
	virtual bool __fastcall IsFullyVisible(void);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridDetailsAreaViewInfoClass __fastcall GetDetailsAreaViewInfoClass(void);
	virtual TcxGridDetailsSiteViewInfoClass __fastcall GetDetailsSiteViewInfoClass(void);
	virtual TcxGridExpandButtonCellViewInfoClass __fastcall GetExpandButtonCellViewInfoClass(void);
	__property Cxgridtableview::TcxGridMasterTableViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property TcxGridDetailsAreaViewInfo* DetailsAreaViewInfo = {read=FDetailsAreaViewInfo};
	__property System::Types::TRect DetailsSiteIndentBounds = {read=GetDetailsSiteIndentBounds};
	__property TcxGridExpandButtonCellViewInfo* ExpandButtonCellViewInfo = {read=FExpandButtonCellViewInfo};
	__property int RestHeight = {read=FRestHeight, write=FRestHeight, nodefault};
	
public:
	__fastcall virtual TcxGridMasterDataRowViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxGridMasterDataRowViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall SupportsTabAccelerators(void);
	__property TcxGridDetailsSiteViewInfo* DetailsSiteViewInfo = {read=FDetailsSiteViewInfo};
	__property bool DetailsSiteVisible = {read=GetDetailsSiteVisible, nodefault};
	__property Cxgridtableview::TcxGridMasterDataRow* GridRecord = {read=GetGridRecord};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


class PASCALIMPLEMENTATION TcxGridGroupCellViewInfo : public TcxGridCellViewInfo
{
	typedef TcxGridCellViewInfo inherited;
	
private:
	System::Types::TRect __fastcall GetExpandedAreaBounds(void);
	HIDESBASE Cxgridtableview::TcxGridGroupRow* __fastcall GetGridRecord(void);
	HIDESBASE TcxGridGroupRowViewInfo* __fastcall GetRecordViewInfo(void);
	Cxgridtableview::TcxGridGroupRowStyle __fastcall GetRowStyle(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual bool __fastcall GetAlwaysSelected(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Types::TRect __fastcall GetBorderBounds(Cxgraphics::TcxBorder AIndex);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasCustomDraw(void);
	__property System::Types::TRect ExpandedAreaBounds = {read=GetExpandedAreaBounds};
	__property Cxgridtableview::TcxGridGroupRowStyle RowStyle = {read=GetRowStyle, nodefault};
	
public:
	virtual bool __fastcall CanDrawSelected(void);
	__property Cxgridtableview::TcxGridGroupRow* GridRecord = {read=GetGridRecord};
	__property TcxGridGroupRowViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TcxGridTableCellViewInfo.Create */ inline __fastcall virtual TcxGridGroupCellViewInfo(Cxgridcustomtableview::TcxCustomGridRecordViewInfo* ARecordViewInfo) : TcxGridCellViewInfo(ARecordViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridGroupCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridGroupRowSpacerViewInfoClass;

class DELPHICLASS TcxGridGroupRowSpacerViewInfo;
class PASCALIMPLEMENTATION TcxGridGroupRowSpacerViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridGroupRowViewInfo* FRowViewInfo;
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GetGridView(void);
	
protected:
	virtual int __fastcall CalculateWidth(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall HasBackground(void);
	
public:
	__fastcall virtual TcxGridGroupRowSpacerViewInfo(TcxGridGroupRowViewInfo* ARowViewInfo, const System::UnicodeString AText);
	__property Cxgridtableview::TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridGroupRowViewInfo* RowViewInfo = {read=FRowViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridGroupRowSpacerViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridGroupSummaryCellViewInfoClass;

class PASCALIMPLEMENTATION TcxGridGroupSummaryCellViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	bool FIsLast;
	TcxGridGroupRowViewInfo* FRowViewInfo;
	TcxGridGroupRowSpacerViewInfo* FSeparatorViewInfo;
	Cxcustomdata::TcxDataSummaryItem* FSummaryItem;
	int FTextWidth;
	System::Variant FValue;
	Cxgridtableview::TcxGridColumn* __fastcall GetColumn(void);
	HIDESBASE Cxgridtableview::TcxGridTableView* __fastcall GetGridView(void);
	void __fastcall SetIsLast(bool Value);
	
protected:
	virtual int __fastcall CalculateWidth(void);
	bool __fastcall CanAlignWithColumn(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(void);
	virtual System::UnicodeString __fastcall GetSeparatorText(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall Offset(int DX, int DY);
	
public:
	__fastcall virtual TcxGridGroupSummaryCellViewInfo(TcxGridGroupRowViewInfo* ARowViewInfo, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, const System::Variant &AValue);
	__fastcall virtual ~TcxGridGroupSummaryCellViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property Cxgridtableview::TcxGridColumn* Column = {read=GetColumn};
	__property Cxgridtableview::TcxGridTableView* GridView = {read=GetGridView};
	__property bool IsLast = {read=FIsLast, write=SetIsLast, nodefault};
	__property TcxGridGroupRowViewInfo* RowViewInfo = {read=FRowViewInfo};
	__property TcxGridGroupRowSpacerViewInfo* SeparatorViewInfo = {read=FSeparatorViewInfo};
	__property Cxcustomdata::TcxDataSummaryItem* SummaryItem = {read=FSummaryItem};
	__property System::Variant Value = {read=FValue};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


class PASCALIMPLEMENTATION TcxGridGroupRowViewInfo : public Cxgridtableview::TcxCustomGridRowViewInfo
{
	typedef Cxgridtableview::TcxCustomGridRowViewInfo inherited;
	
private:
	TcxGridGroupCellViewInfo* FCellViewInfo;
	TcxGridGroupRowSpacerViewInfo* FSummaryBeginningSpacerViewInfo;
	System::Classes::TList* FSummaryCellsWithoutColumns;
	System::Classes::TList* FSummaryCellViewInfos;
	TcxGridGroupRowSpacerViewInfo* FSummaryEndingSpacerViewInfo;
	HIDESBASE Cxgridtableview::TcxGridGroupRow* __fastcall GetGridRecord(void);
	Cxgridtableview::TcxGridGroupRowStyle __fastcall GetRowStyle(void);
	Cxgridtableview::TcxGridGroupSummaryLayout __fastcall GetSummaryCellLayout(void);
	TcxGridGroupSummaryCellViewInfo* __fastcall GetSummaryCellViewInfo(int Index);
	int __fastcall GetSummaryCellViewInfoCount(void);
	
protected:
	virtual void __fastcall CalculateExpandButtonBounds(System::Types::TRect &ABounds);
	virtual int __fastcall CalculateHeight(void);
	virtual bool __fastcall CanSize(void);
	virtual void __fastcall CheckRowHeight(int &AValue);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Types::TRect __fastcall GetExpandButtonAreaBounds(void);
	virtual System::Types::TRect __fastcall GetFocusRectBounds(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(void);
	virtual System::Types::TRect __fastcall GetSeparatorIndentBounds(void);
	virtual bool __fastcall GetShowSeparator(void);
	virtual bool __fastcall HasFocusRect(void);
	virtual bool __fastcall HasFooter(int ALevel);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall SetRowHeight(int Value);
	TcxGridGroupRowSpacerViewInfo* __fastcall CreateSpacerViewInfo(const System::UnicodeString AText);
	virtual void __fastcall CreateSpacerViewInfos(void);
	virtual void __fastcall DestroySpacerViewInfos(void);
	virtual TcxGridGroupRowSpacerViewInfoClass __fastcall GetSpacerViewInfoClass(void);
	TcxGridGroupSummaryCellViewInfo* __fastcall AddSummaryCellViewInfo(Cxcustomdata::TcxDataSummaryItem* ASummaryItem, const System::Variant &AValue);
	virtual void __fastcall CreateSummaryCellViewInfos(void);
	virtual void __fastcall DestroySummaryCellViewInfos(void);
	virtual TcxGridGroupSummaryCellViewInfoClass __fastcall GetSummaryCellViewInfoClass(void);
	virtual void __fastcall CalculateSummaryCells(void)/* overload */;
	virtual void __fastcall CalculateSummaryCells(System::Classes::TList* ACellViewInfos, const System::Types::TRect &AAreaBounds, System::Classes::TAlignment AAlignment, bool AAutoWidth)/* overload */;
	virtual Cxclasses::TcxAutoWidthObject* __fastcall CalculateSummaryCellWidths(System::Classes::TList* ACellViewInfos, int AAvailableWidth, bool AAutoWidth);
	virtual System::Types::TRect __fastcall GetColumnSummaryCellsAreaBounds(Cxgridtableview::TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo);
	void __fastcall GetColumnSummaryCellViewInfos(Cxgridtableview::TcxGridColumn* AColumn, System::Classes::TList* AList);
	virtual System::Types::TRect __fastcall GetSummaryBeginningSpacerBounds(void);
	virtual System::Types::TRect __fastcall GetSummaryEndingSpacerBounds(void);
	virtual System::UnicodeString __fastcall GetSummaryBeginningSpacerText(void);
	virtual System::UnicodeString __fastcall GetSummaryEndingSpacerText(void);
	virtual bool __fastcall GetSummaryCellAutoWidth(void);
	virtual System::Types::TRect __fastcall GetSummaryCellsAreaBounds(bool AForAlignableCells);
	virtual System::Types::TRect __fastcall GetSummaryCellsBounds(const System::Types::TRect &AAreaBounds, Cxclasses::TcxAutoWidthObject* AWidths, System::Classes::TAlignment AAlignment, bool AAutoWidth);
	virtual System::Classes::TList* __fastcall GetUnalignableSummaryCells(void);
	virtual bool __fastcall HasUnalignableSummaryCells(void);
	__property TcxGridGroupRowSpacerViewInfo* SummaryBeginningSpacerViewInfo = {read=FSummaryBeginningSpacerViewInfo};
	__property TcxGridGroupRowSpacerViewInfo* SummaryEndingSpacerViewInfo = {read=FSummaryEndingSpacerViewInfo};
	__property bool SummaryCellAutoWidth = {read=GetSummaryCellAutoWidth, nodefault};
	__property Cxgridtableview::TcxGridGroupSummaryLayout SummaryCellLayout = {read=GetSummaryCellLayout, nodefault};
	__property System::Classes::TList* SummaryCells = {read=FSummaryCellViewInfos};
	__property System::Classes::TList* SummaryCellsWithoutColumns = {read=FSummaryCellsWithoutColumns};
	__property System::Classes::TList* UnalignableSummaryCells = {read=GetUnalignableSummaryCells};
	__property Cxgridtableview::TcxGridGroupRowStyle RowStyle = {read=GetRowStyle, nodefault};
	
public:
	__fastcall virtual TcxGridGroupRowViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxGridGroupRowViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	__property TcxGridGroupCellViewInfo* CellViewInfo = {read=FCellViewInfo};
	__property Cxgridtableview::TcxGridGroupRow* GridRecord = {read=GetGridRecord};
	__property System::Types::TRect SeparatorIndentBounds = {read=GetSeparatorIndentBounds};
	__property int SummaryCellViewInfoCount = {read=GetSummaryCellViewInfoCount, nodefault};
	__property TcxGridGroupSummaryCellViewInfo* SummaryCellViewInfos[int Index] = {read=GetSummaryCellViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Byte htPreview = System::Byte(0xe7);
}	/* namespace Cxgridrows */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDROWS)
using namespace Cxgridrows;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridrowsHPP
