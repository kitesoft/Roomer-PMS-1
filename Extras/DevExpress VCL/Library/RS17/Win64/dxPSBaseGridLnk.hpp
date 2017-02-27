// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSBaseGridLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsbasegridlnkHPP
#define DxpsbasegridlnkHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsbasegridlnk
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxPSCustomGridCellDataMapClass;

class DELPHICLASS TdxPSGridCellDataMaps;
class DELPHICLASS TAbstractdxGridReportLink;
class PASCALIMPLEMENTATION TdxPSGridCellDataMaps : public Dxbase::TdxCustomClassMaps
{
	typedef Dxbase::TdxCustomClassMaps inherited;
	
public:
	TdxPSCustomGridCellDataMapClass operator[](Dxpscore::TAbstractdxReportCellData* ADataItem) { return MapClasses[ADataItem]; }
	
private:
	TdxPSCustomGridCellDataMapClass __fastcall GetMapClass(Dxpscore::TAbstractdxReportCellData* ADataItem);
	
public:
	__classmethod TdxPSGridCellDataMaps* __fastcall Instance()/* overload */;
	void __fastcall InitializeCellData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem, TAbstractdxGridReportLink* AReportLink);
	__property TdxPSCustomGridCellDataMapClass MapClasses[Dxpscore::TAbstractdxReportCellData* ADataItem] = {read=GetMapClass/*, default*/};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSGridCellDataMaps(int Dummy) : Dxbase::TdxCustomClassMaps(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSGridCellDataMaps(void) : Dxbase::TdxCustomClassMaps() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSGridCellDataMaps(void) { }
	
};


class DELPHICLASS TdxPSCustomGridCellDataMap;
class PASCALIMPLEMENTATION TdxPSCustomGridCellDataMap : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeCellData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem, TAbstractdxGridReportLink* AReportLink);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall DataClass();
	
public:
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
public:
	/* TObject.Create */ inline __fastcall TdxPSCustomGridCellDataMap(void) : Dxbase::TdxCustomClassMapItem() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCustomGridCellDataMap(void) { }
	
};


class DELPHICLASS TdxPSTextGridCellDataMap;
class PASCALIMPLEMENTATION TdxPSTextGridCellDataMap : public TdxPSCustomGridCellDataMap
{
	typedef TdxPSCustomGridCellDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeCellData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem, TAbstractdxGridReportLink* AReportLink);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall DataClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSTextGridCellDataMap(void) : TdxPSCustomGridCellDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSTextGridCellDataMap(void) { }
	
};


class DELPHICLASS TdxPSImageGridCellDataMap;
class PASCALIMPLEMENTATION TdxPSImageGridCellDataMap : public TdxPSTextGridCellDataMap
{
	typedef TdxPSTextGridCellDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeCellData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem, TAbstractdxGridReportLink* AReportLink);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall DataClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSImageGridCellDataMap(void) : TdxPSTextGridCellDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSImageGridCellDataMap(void) { }
	
};


enum TdxGridDrawMode : unsigned char { gdmStrict, gdmOddEven, gdmChess, gdmBorrowSource };

typedef System::Set<TdxGridDrawMode, TdxGridDrawMode::gdmStrict, TdxGridDrawMode::gdmBorrowSource>  TdxGridDrawModes;

typedef void __fastcall (__closure *TdxCustomGridReportLinkEvent)(TAbstractdxGridReportLink* Sender);

typedef void __fastcall (__closure *TdxCustomGridReportLinkInitializeItemEvent)(TAbstractdxGridReportLink* Sender, int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);

class PASCALIMPLEMENTATION TAbstractdxGridReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	typedef System::DynamicArray<int> _TAbstractdxGridReportLink__1;
	
	typedef System::DynamicArray<int> _TAbstractdxGridReportLink__2;
	
	
private:
	bool FAutoWidth;
	System::Classes::TList* FDelimitersHardHorz;
	System::Classes::TList* FDelimitersHardVert;
	Vcl::Graphics::TFont* FDefaultFixedFont;
	TdxGridDrawMode FDrawMode;
	bool FEffects3D;
	bool FEndEllipsis;
	System::Uitypes::TColor FEvenColor;
	Vcl::Graphics::TFont* FEvenFont;
	System::Uitypes::TColor FFixedColor;
	Vcl::Graphics::TFont* FFixedFont;
	bool FFixedTransparent;
	System::Uitypes::TColor FGridLineColor;
	bool FIncludeFixed;
	bool FMultiline;
	bool FOnlySelected;
	System::Classes::TList* FReportRows;
	bool FRowAutoHeight;
	int FRowWidth;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* FScreenCanvas;
	bool FSoft3D;
	bool FSupportedCustomDraw;
	bool FUseCustomPageBreaks;
	TdxCustomGridReportLinkEvent FOnGetCustomPageBreaks;
	TdxCustomGridReportLinkInitializeItemEvent FOnInitializeItem;
	int __fastcall GetActualFirstCol(void);
	int __fastcall GetActualFirstRow(void);
	int __fastcall GetActualLastCol(void);
	int __fastcall GetActualLastRow(void);
	int __fastcall GetAvailableSiteHeight(void);
	int __fastcall GetAvailableSiteWidth(void);
	int __fastcall GetColumnWidth(int Index);
	System::Uitypes::TColor __fastcall GetOddColor(void);
	Vcl::Graphics::TFont* __fastcall GetOddFont(void);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	Dxpscore::TdxReportCell* __fastcall GetReportRowByRow(int Row);
	int __fastcall GetReportRowCount(void);
	int __fastcall GetRowHeight(int ARow);
	int __fastcall GetRowWidth(void);
	void __fastcall SetAutoWidth(bool Value);
	void __fastcall SetColumnWidth(int Index, int Value);
	void __fastcall SetEffects3D(bool Value);
	void __fastcall SetEndEllipsis(bool Value);
	void __fastcall SetEvenColor(System::Uitypes::TColor Value);
	void __fastcall SetEvenFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetFixedColor(System::Uitypes::TColor Value);
	void __fastcall SetFixedFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetFixedTransparent(bool Value);
	void __fastcall SetGridLineColor(System::Uitypes::TColor Value);
	void __fastcall SetIncludeFixed(bool Value);
	void __fastcall SetMultiline(bool Value);
	void __fastcall SetOddColor(System::Uitypes::TColor Value);
	void __fastcall SetOddFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetOnlySelected(bool Value);
	void __fastcall SetRowAutoHeight(bool Value);
	void __fastcall SetRowHeight(int Index, int Value);
	void __fastcall SetSoft3D(bool Value);
	void __fastcall SetSupportedCustomDraw(bool Value);
	void __fastcall SetUseCustomPageBreaks(bool Value);
	
protected:
	_TAbstractdxGridReportLink__1 FColumnWidths;
	int FCurrentCol;
	int FCurrentRow;
	int FEvenFontIndex;
	int FFixedFontIndex;
	_TAbstractdxGridReportLink__2 FRowHeights;
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual bool __fastcall GetBreakPagesByHardDelimiters(void);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual bool __fastcall GetUseHardHorzDelimiters(void);
	virtual bool __fastcall GetUseHardVertDelimiters(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* AItem);
	virtual void __fastcall MakeDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	virtual void __fastcall MakeHardDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	DYNAMIC void __fastcall DoGetCustomPageBreaks(void);
	DYNAMIC void __fastcall DoInitializeItem(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual void __fastcall AssignData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	virtual Dxpscore::TAbstractdxReportCellData* __fastcall CreateDataItem(Dxpscore::TdxReportCell* AParent, int ACol, int ARow, const System::Types::TRect &ABounds);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual void __fastcall CalculateColumnAutoWidths(void);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual void __fastcall CalculateRowHeights(Dxpscore::TdxReportCells* AReportCells);
	virtual int __fastcall CalculateRowWidth(void);
	virtual bool __fastcall CanCalculateColumnAutoWidths(void);
	virtual bool __fastcall CanCalculateRowAutoHeight(int ARow);
	virtual Dxpscore::TdxReportCellClass __fastcall GetRowClass(int ARow);
	virtual Dxpscore::TdxReportCell* __fastcall GetRowParent(Dxpscore::TdxReportCells* AReportCells, int ARow);
	virtual void __fastcall InitializeRow(Dxpscore::TdxReportCell* AReportRow, int ARow);
	virtual int __fastcall GetColCount(void);
	virtual int __fastcall GetFixedColCount(void);
	virtual int __fastcall GetFixedRowCount(void);
	virtual int __fastcall GetRowCount(void);
	virtual int __fastcall GetActualColCount(void);
	virtual int __fastcall GetActualColIndex(int Col);
	virtual int __fastcall GetActualRowCount(void);
	virtual System::Uitypes::TColor __fastcall GetCellColor(int ACol, int ARow);
	void __fastcall GetCellColRow(Dxpscore::TdxReportVisualItem* AItem, int &ACol, int &ARow);
	virtual System::Uitypes::TColor __fastcall GetCellContentBkColor(int ACol, int ARow);
	virtual Dxpsfillpatterns::TdxPSFillPatternClass __fastcall GetCellContentPattern(int ACol, int ARow);
	virtual bool __fastcall GetCellEdge3DSoft(Dxpscore::TAbstractdxReportCellData* AItem, int ACol, int ARow);
	virtual Dxpscore::TdxCellEdgeStyle __fastcall GetCellEdge3DStyle(Dxpscore::TAbstractdxReportCellData* AItem, int ACol, int ARow);
	virtual Dxpscore::TdxCellEdgeMode __fastcall GetCellEdgeMode(Dxpscore::TAbstractdxReportCellData* AItem, int ACol, int ARow);
	virtual Vcl::Graphics::TFont* __fastcall GetCellFont(int ACol, int ARow);
	virtual int __fastcall GetCellFontIndex(int ACol, int ARow);
	virtual bool __fastcall GetCellHasImage(int ACol, int ARow);
	virtual Vcl::Graphics::TGraphic* __fastcall GetCellImage(int ACol, int ARow);
	virtual int __fastcall GetCellImageIndex(int ACol, int ARow);
	virtual Dxpscore::TdxImageLayout __fastcall GetCellImageLayout(int ACol, int ARow);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetCellImageList(int ACol, int ARow);
	virtual bool __fastcall GetCellImageMakeSpaceForEmpty(int ACol, int ARow);
	virtual bool __fastcall GetCellImageTransparent(int ACol, int ARow);
	virtual bool __fastcall GetCellMultiline(int ACol, int ARow);
	virtual Dxpscore::TdxCellSides __fastcall GetCellSides(int ACol, int ARow);
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow) = 0 ;
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetCellTextAlignX(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetCellTextAlignY(int ACol, int ARow);
	virtual bool __fastcall GetCellTransparent(int ACol, int ARow);
	virtual Dxpscore::TdxCellSortOrder __fastcall GetColSortOrder(int ACol);
	virtual bool __fastcall GetEndEllipsis(void);
	int __fastcall GetInternalRowHeight(int Index);
	virtual int __fastcall GetMinRowHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall GetMultiline(void);
	virtual void __fastcall GetSelectedRange(System::PInteger ABeginCol, System::PInteger AEndCol, System::PInteger ABeginRow, System::PInteger AEndRow)/* overload */;
	virtual void __fastcall GetSelectedRange(/* out */ int &ABeginCol, /* out */ int &AEndCol, /* out */ int &ABeginRow, /* out */ int &AEndRow)/* overload */;
	virtual int __fastcall GetSelectedColCount(void);
	virtual int __fastcall GetSelectedRowCount(void);
	virtual System::Types::TRect __fastcall GetSelectionRect(void);
	virtual System::Uitypes::TColor __fastcall GetSourceCellColor(int ACol, int ARow);
	virtual System::Uitypes::TColor __fastcall GetSourceCellContentBkColor(int ACol, int ARow);
	virtual Dxpsfillpatterns::TdxPSFillPatternClass __fastcall GetSourceCellContentPattern(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellEdge3DSoft(int ACol, int ARow);
	virtual Dxpscore::TdxCellEdgeStyle __fastcall GetSourceCellEdge3DStyle(int ACol, int ARow);
	virtual Dxpscore::TdxCellEdgeMode __fastcall GetSourceCellEdgeMode(int ACol, int ARow);
	virtual Vcl::Graphics::TFont* __fastcall GetSourceCellFont(int ACol, int ARow);
	virtual int __fastcall GetSourceCellFontIndex(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellMultiline(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetSourceCellTextAlignX(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetSourceCellTextAlignY(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellTransparent(int ACol, int ARow);
	virtual int __fastcall GetSourceColWidth(int ACol);
	virtual int __fastcall GetSourceRowHeight(int ARow);
	virtual bool __fastcall HasColumnHeaderImage(int ACol);
	virtual bool __fastcall HasSelection(void);
	virtual bool __fastcall HasSelectionInCol(int ACol);
	virtual bool __fastcall HasSelectionInRow(int ARow);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawFixedHorzLines(void);
	virtual bool __fastcall IsDrawFixedVertLines(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual bool __fastcall IsDrawVertLines(void);
	virtual bool __fastcall IsEmptyRow(int ARow);
	virtual bool __fastcall IsFixedCell(int ACol, int ARow);
	virtual bool __fastcall IsFixedCol(int ACol);
	virtual bool __fastcall IsFixedRow(int ARow);
	virtual bool __fastcall IsFooterRow(int ARow);
	virtual bool __fastcall IsHeaderRow(int ARow);
	virtual bool __fastcall IsProcessedCell(int ACol, int ARow);
	virtual bool __fastcall IsProcessedCol(int ACol);
	virtual bool __fastcall IsProcessedRow(int ARow);
	virtual bool __fastcall IsSelectedCell(int ACol, int ARow);
	virtual bool __fastcall IsSelectedRow(int ARow);
	virtual void __fastcall NextCol(void);
	virtual void __fastcall NextRow(void);
	virtual void __fastcall SetDrawMode(TdxGridDrawMode Value);
	void __fastcall SetupBoundsRect(Dxpscore::TdxReportCell* ACell);
	void __fastcall AddReportRow(Dxpscore::TdxReportCell* ARow);
	void __fastcall AddHorizontalHardDelimiter(int ADelimiter);
	void __fastcall AddVerticalHardDelimiter(int ADelimiter)/* overload */;
	void __fastcall AddVerticalHardDelimiter(Dxpscore::TdxReportCell* ADelimiter)/* overload */;
	virtual void __fastcall AfterConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall BeforeConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall PrepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall UnprepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall InitializeDefaultFixedFont(Vcl::Graphics::TFont* AFont);
	bool __fastcall IsFixedFontStored(void);
	__property int ActualColIndexes[int Col] = {read=GetActualColIndex};
	__property int ActualColCount = {read=GetActualColCount, nodefault};
	__property int ActualFirstCol = {read=GetActualFirstCol, nodefault};
	__property int ActualFirstRow = {read=GetActualFirstRow, nodefault};
	__property int ActualLastCol = {read=GetActualLastCol, nodefault};
	__property int ActualLastRow = {read=GetActualLastRow, nodefault};
	__property int ActualRowCount = {read=GetActualRowCount, nodefault};
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=0};
	__property int AvailableSiteHeight = {read=GetAvailableSiteHeight, nodefault};
	__property int AvailableSiteWidth = {read=GetAvailableSiteWidth, nodefault};
	__property int ColCount = {read=GetColCount, nodefault};
	__property int ColumnWidths[int Index] = {read=GetColumnWidth, write=SetColumnWidth};
	__property System::Classes::TList* DelimitersHardHorz = {read=FDelimitersHardHorz};
	__property System::Classes::TList* DelimitersHardVert = {read=FDelimitersHardVert};
	__property TdxGridDrawMode DrawMode = {read=FDrawMode, write=SetDrawMode, default=0};
	__property bool Effects3D = {read=FEffects3D, write=SetEffects3D, default=0};
	__property bool EndEllipsis = {read=GetEndEllipsis, write=SetEndEllipsis, default=0};
	__property System::Uitypes::TColor EvenColor = {read=FEvenColor, write=SetEvenColor, default=16777215};
	__property Vcl::Graphics::TFont* EvenFont = {read=FEvenFont, write=SetEvenFont, stored=IsFontStored};
	__property int FixedColCount = {read=GetFixedColCount, nodefault};
	__property System::Uitypes::TColor FixedColor = {read=FFixedColor, write=SetFixedColor, default=-16777201};
	__property Vcl::Graphics::TFont* FixedFont = {read=FFixedFont, write=SetFixedFont, stored=IsFixedFontStored};
	__property int FixedRowCount = {read=GetFixedRowCount, nodefault};
	__property bool FixedTransparent = {read=FFixedTransparent, write=SetFixedTransparent, default=0};
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=0};
	__property bool IncludeFixed = {read=FIncludeFixed, write=SetIncludeFixed, default=1};
	__property int InternalRowHeights[int Index] = {read=GetInternalRowHeight};
	__property bool Multiline = {read=FMultiline, write=SetMultiline, default=0};
	__property System::Uitypes::TColor OddColor = {read=GetOddColor, write=SetOddColor, stored=IsFontStored, default=16777215};
	__property Vcl::Graphics::TFont* OddFont = {read=GetOddFont, write=SetOddFont, stored=IsFontStored};
	__property bool OnlySelected = {read=FOnlySelected, write=SetOnlySelected, default=0};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow};
	__property Dxpscore::TdxReportCell* ReportRowsByRow[int ARow] = {read=GetReportRowByRow};
	__property bool RowAutoHeight = {read=FRowAutoHeight, write=SetRowAutoHeight, default=0};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeights[int Index] = {read=GetRowHeight, write=SetRowHeight};
	__property int RowWidth = {read=GetRowWidth, nodefault};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=FScreenCanvas};
	__property int SelectedColCount = {read=GetSelectedColCount, nodefault};
	__property int SelectedRowCount = {read=GetSelectedRowCount, nodefault};
	__property System::Types::TRect SelectionRect = {read=GetSelectionRect};
	__property bool Soft3D = {read=FSoft3D, write=SetSoft3D, default=1};
	__property bool SupportedCustomDraw = {read=FSupportedCustomDraw, write=SetSupportedCustomDraw, default=0};
	
public:
	__fastcall virtual TAbstractdxGridReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TAbstractdxGridReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddPageBreak(int ARow)/* overload */;
	void __fastcall AddPageBreak(System::PIntegerArray ARows, int ACount)/* overload */;
	void __fastcall AddPageBreak(System::PIntegerArray ARows, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddPageBreak(System::Classes::TList* ARows)/* overload */;
	void __fastcall AddPageBreak(System::Classes::TList* ARows, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddPageBreak(int const *ARows, const int ARows_Size)/* overload */;
	void __fastcall AddPageBreak(int const *ARows, const int ARows_Size, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddPageBreak(const System::TBoundArray ARows)/* overload */;
	void __fastcall AddPageBreak(const System::TBoundArray ARows, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddHorizontalPageBreak(int AColumn)/* overload */;
	void __fastcall AddHorizontalPageBreak(System::PIntegerArray AColumns, int ACount)/* overload */;
	void __fastcall AddHorizontalPageBreak(System::PIntegerArray AColumns, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddHorizontalPageBreak(System::Classes::TList* AColumns)/* overload */;
	void __fastcall AddHorizontalPageBreak(System::Classes::TList* AColumns, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddHorizontalPageBreak(int const *AColumns, const int AColumns_Size)/* overload */;
	void __fastcall AddHorizontalPageBreak(int const *AColumns, const int AColumns_Size, int AStartIndex, int ACount)/* overload */;
	void __fastcall AddHorizontalPageBreak(const System::TBoundArray AColumns)/* overload */;
	void __fastcall AddHorizontalPageBreak(const System::TBoundArray AColumns, int AStartIndex, int ACount)/* overload */;
	virtual Vcl::Graphics::TFont* __fastcall DefaultFixedFont(void);
	__property Color = {default=16777215};
	__property Font;
	__property ScaleFonts = {default=1};
	__property Transparent = {default=1};
	__property bool UseCustomPageBreaks = {read=FUseCustomPageBreaks, write=SetUseCustomPageBreaks, default=0};
	__property TdxCustomGridReportLinkEvent OnGetCustomPageBreaks = {read=FOnGetCustomPageBreaks, write=FOnGetCustomPageBreaks};
	__property TdxCustomGridReportLinkInitializeItemEvent OnInitializeItem = {read=FOnInitializeItem, write=FOnInitializeItem};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxPSInitalizeDrawModeCombo(Cximagecombobox::TcxImageComboBox* AComboBox, const TdxGridDrawModes AModes);
extern PACKAGE TdxGridDrawMode __fastcall dxPSGetSelectedDrawMode(Cximagecombobox::TcxImageComboBox* AComboBox);
extern PACKAGE void __fastcall dxPSSyncDrawModeComboItemIndex(Cximagecombobox::TcxImageComboBox* AComboBox, TdxGridDrawMode AMode);
extern PACKAGE void __fastcall dxPSDrawGridPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, TAbstractdxGridReportLink* AReportLink, bool AShowFixedColumn = true, bool AShowFixedRow = true);
}	/* namespace Dxpsbasegridlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSBASEGRIDLNK)
using namespace Dxpsbasegridlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsbasegridlnkHPP
