// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxSSLnk.pas' rev: 24.00 (Win64)

#ifndef DxpscxsslnkHPP
#define DxpscxsslnkHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSData.hpp>	// Pascal unit
#include <cxSSStyles.hpp>	// Pascal unit
#include <cxSSheet.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSBaseGridLnk.hpp>	// Pascal unit
#include <dxPSExcelEdgePatterns.hpp>	// Pascal unit
#include <dxPSExcelFillPatterns.hpp>	// Pascal unit
#include <dxPSEdgePatterns.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxsslnk
{
//-- type declarations -------------------------------------------------------
struct TdxPSCellBorder;
typedef TdxPSCellBorder *PdxPSCellBorder;

struct DECLSPEC_DRECORD TdxPSCellBorder
{
public:
	System::Uitypes::TColor Color;
	Dxpsedgepatterns::TdxPSEdgePatternClass Pattern;
};


typedef System::StaticArray<TdxPSCellBorder, 4> TdxPSCellBorders;

typedef TdxPSCellBorders *PdxPSCellBorders;

enum TdxPSCellBorderCorner : unsigned char { cbcTopLeft, cbcTopRight, cbcBottomRight, cbcBottomLeft };

typedef System::Set<TdxPSCellBorderCorner, TdxPSCellBorderCorner::cbcTopLeft, TdxPSCellBorderCorner::cbcBottomLeft>  TdxPSCellBorderCorners;

enum TdxPSCellBorderEnd : unsigned char { cbsTopLeft, cbsBottomRight };

typedef System::Set<TdxPSCellBorderEnd, TdxPSCellBorderEnd::cbsTopLeft, TdxPSCellBorderEnd::cbsBottomRight>  TdxPSCellBorderEnds;

typedef System::Int8 TdxPSCellBorderSub;

enum TdxPSCellCorner : unsigned char { ccTopLeft, ccTopRight, ccBottomRight, ccBottomLeft };

class DELPHICLASS TdxReportCellSSString;
class DELPHICLASS TdxPSGridCellsAdapter;
class PASCALIMPLEMENTATION TdxReportCellSSString : public Dxpscore::TdxReportCellString
{
	typedef Dxpscore::TdxReportCellString inherited;
	
private:
	TdxPSCellBorders FBorders;
	unsigned FBorderSlants;
	unsigned FBorderSubs;
	System::Uitypes::TColor FContentBkColor;
	Dxpsfillpatterns::TdxPSFillPatternClass FContentPattern;
	int FRealCol;
	int FRealRow;
	int FTextExtentLeft;
	int FTextExtentRight;
	TdxPSCellBorder __fastcall GetBorder(Dxpscore::TdxCellSide ASide);
	System::Uitypes::TColor __fastcall GetBordersBkColor(void);
	int __fastcall GetBorderSlant(Dxpscore::TdxCellSide ASide, TdxPSCellBorderCorner ACorner);
	Dxpsglbl::TDWORDBits __fastcall GetBorderSlantOffset(Dxpscore::TdxCellSide ASide, TdxPSCellBorderCorner ACorner);
	TdxPSCellBorderSub __fastcall GetBorderSub(Dxpscore::TdxCellSide ASide, TdxPSCellBorderEnd AEnd);
	unsigned __fastcall GetBorderSubMask(Dxpscore::TdxCellSide ASide, TdxPSCellBorderEnd AEnd);
	Dxpsglbl::TDWORDBits __fastcall GetBorderSubOffset(Dxpscore::TdxCellSide ASide, TdxPSCellBorderEnd AEnd);
	bool __fastcall GetClipContent(void);
	int __fastcall GetCol(void);
	bool __fastcall GetFill(void);
	bool __fastcall GetIsFixed(void);
	bool __fastcall GetIsMerged(void);
	bool __fastcall GetIsNearMostLeft(void);
	bool __fastcall GetIsNearMostTop(void);
	bool __fastcall GetIsNearMostTopOrLeft(void);
	bool __fastcall GetIsVirtual(void);
	int __fastcall GetRow(void);
	void __fastcall SetBorder(Dxpscore::TdxCellSide ASide, TdxPSCellBorder &Value);
	void __fastcall SetBorderSlant(Dxpscore::TdxCellSide ASide, TdxPSCellBorderCorner ACorner, int Value);
	void __fastcall SetBorderSub(Dxpscore::TdxCellSide ASide, TdxPSCellBorderEnd AEnd, TdxPSCellBorderSub Value);
	void __fastcall SetClipConent(bool Value);
	void __fastcall SetFill(bool Value);
	void __fastcall SetIsFixed(bool Value);
	void __fastcall SetIsMerged(bool Value);
	void __fastcall SetIsNearMostLeft(bool Value);
	void __fastcall SetIsNearMostTop(bool Value);
	void __fastcall SetIsVirtual(bool Value);
	
protected:
	void __fastcall CalcBorderSubs(TdxPSGridCellsAdapter* AnAdapter);
	void __fastcall CalcDoubleBorderSlants(TdxPSGridCellsAdapter* AnAdapter);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual System::Types::TRect __fastcall GetBackgroundBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetBorderEdgeBounds(Dxpscore::TdxCellSide ASide, const System::Types::TRect &AOuterRect);
	HIDESBASE Vcl::Graphics::TBrush* __fastcall GetBorderBrush(Dxpscore::TdxCellSide ASide);
	virtual Dxpscore::TdxPSCellBorderClass __fastcall GetBorderEdgeClass(Dxpscore::TdxCellSide ASide);
	virtual System::Types::TRect __fastcall GetEffectiveBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	virtual System::Types::TRect __fastcall GetTextBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall IsDrawn(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage, const System::Types::TRect &ARect);
	virtual Dxpscore::TdxPSCellBorderPainterClass __fastcall GetBorderPainterClass(void);
	virtual void __fastcall InitBorderPainter(Dxpscore::TdxPSCellBorderPainter* ABordersPainter);
	virtual System::Uitypes::TColor __fastcall GetContentBkColor(void);
	virtual Dxpsfillpatterns::TdxPSFillPatternClass __fastcall GetContentPattern(void);
	virtual void __fastcall SetContentBkColor(System::Uitypes::TColor Value);
	virtual void __fastcall SetContentPattern(Dxpsfillpatterns::TdxPSFillPatternClass Value);
	void __fastcall ReadBorders(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	void __fastcall WriteBorders(Dxpscore::TdxPSDataWriter* AWriter);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	System::Types::TRect __fastcall GetAbsoluteInnerBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	HRGN __fastcall GetDoubleBorderRgn(Dxpscore::TdxCellSide ASide, const System::Types::TRect &R);
	bool __fastcall IsDoubleLineBorderPattern(TdxPSCellBorder &ABorder)/* overload */;
	bool __fastcall IsDoubleLineBorderPattern(Dxpscore::TdxCellSide ASide)/* overload */;
	TdxPSCellBorder __fastcall NullBorder(void);
	
public:
	__fastcall virtual TdxReportCellSSString(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetBorders(System::Uitypes::TColor AColor, Dxpsedgepatterns::TdxPSEdgePatternClass APattern);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__property TdxPSCellBorder Borders[Dxpscore::TdxCellSide ASide] = {read=GetBorder, write=SetBorder};
	__property System::Uitypes::TColor BordersBkColor = {read=GetBordersBkColor, nodefault};
	__property int BorderSlants[Dxpscore::TdxCellSide ASide][TdxPSCellBorderCorner ACorner] = {read=GetBorderSlant, write=SetBorderSlant};
	__property TdxPSCellBorderSub BorderSubs[Dxpscore::TdxCellSide ASide][TdxPSCellBorderEnd AEnd] = {read=GetBorderSub, write=SetBorderSub};
	__property bool ClipContent = {read=GetClipContent, write=SetClipConent, nodefault};
	__property int Col = {read=GetCol, nodefault};
	__property bool Fill = {read=GetFill, write=SetFill, nodefault};
	__property bool IsFixed = {read=GetIsFixed, write=SetIsFixed, nodefault};
	__property bool IsMerged = {read=GetIsMerged, write=SetIsMerged, nodefault};
	__property bool IsNearMostLeft = {read=GetIsNearMostLeft, write=SetIsNearMostLeft, nodefault};
	__property bool IsNearMostTop = {read=GetIsNearMostTop, write=SetIsNearMostTop, nodefault};
	__property bool IsNearMostTopOrLeft = {read=GetIsNearMostTopOrLeft, nodefault};
	__property bool IsVirtual = {read=GetIsVirtual, write=SetIsVirtual, nodefault};
	__property int RealCol = {read=FRealCol, write=FRealCol, nodefault};
	__property int RealRow = {read=FRealRow, write=FRealRow, nodefault};
	__property int Row = {read=GetRow, nodefault};
	__property int TextExtentLeft = {read=FTextExtentLeft, write=FTextExtentLeft, nodefault};
	__property int TextExtentRight = {read=FTextExtentRight, write=FTextExtentRight, nodefault};
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TdxReportCellSSString(void) { }
	
};


class DELPHICLASS TdxPSCellPatternsBorderPainter;
class PASCALIMPLEMENTATION TdxPSCellPatternsBorderPainter : public Dxpscore::TdxPSCellBorderPainter
{
	typedef Dxpscore::TdxPSCellBorderPainter inherited;
	
private:
	TdxPSGridCellsAdapter* FGridAdapter;
	
protected:
	void __fastcall ClipItemBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &AOuterRect);
	void __fastcall DrawBorder(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, Dxpscore::TdxCellSide ASide);
	
public:
	HIDESBASE TdxReportCellSSString* __fastcall Item(void)/* overload */;
	virtual void __fastcall DrawBorders(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R);
	__property TdxPSGridCellsAdapter* GridAdapter = {read=FGridAdapter};
public:
	/* TdxPSCellBorderPainter.Create */ inline __fastcall virtual TdxPSCellPatternsBorderPainter(Dxpscore::TdxPSReportRenderer* ARenderer) : Dxpscore::TdxPSCellBorderPainter(ARenderer) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSCellPatternsBorderPainter(void) { }
	
};


class PASCALIMPLEMENTATION TdxPSGridCellsAdapter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxpscore::TdxReportCells* FReportCells;
	TdxReportCellSSString* __fastcall GetCell(int Col, int Row);
	int __fastcall GetColCount(void);
	int __fastcall GetColOffset(int Index);
	int __fastcall GetColWidth(int Index);
	Dxpscore::TdxReportCell* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowHeight(int Index);
	int __fastcall GetRowIndex(int Index);
	int __fastcall GetRowOffset(int Index);
	
public:
	__fastcall TdxPSGridCellsAdapter(Dxpscore::TdxReportCells* AReportCells);
	TdxReportCellSSString* __fastcall GetNeighborCell(TdxReportCellSSString* AItem, Dxpscore::TdxCellSide ASide);
	__property TdxReportCellSSString* Cells[int Col][int Row] = {read=GetCell/*, default*/};
	__property int ColCount = {read=GetColCount, nodefault};
	__property int ColOffsets[int Index] = {read=GetColOffset};
	__property int ColWidths[int Index] = {read=GetColWidth};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeights[int Index] = {read=GetRowHeight};
	__property int RowIndexes[int Index] = {read=GetRowIndex};
	__property int RowOffsets[int Index] = {read=GetRowOffset};
	__property Dxpscore::TdxReportCell* Rows[int Index] = {read=GetRow};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSGridCellsAdapter(void) { }
	
};


class DELPHICLASS TdxPSSSStringGridCellDataMap;
class PASCALIMPLEMENTATION TdxPSSSStringGridCellDataMap : public Dxpsbasegridlnk::TdxPSTextGridCellDataMap
{
	typedef Dxpsbasegridlnk::TdxPSTextGridCellDataMap inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeCellData(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem, Dxpsbasegridlnk::TAbstractdxGridReportLink* AReportLink);
	__classmethod virtual Dxpscore::TdxReportCellDataClass __fastcall DataClass();
public:
	/* TObject.Create */ inline __fastcall TdxPSSSStringGridCellDataMap(void) : Dxpsbasegridlnk::TdxPSTextGridCellDataMap() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSSSStringGridCellDataMap(void) { }
	
};


enum TdxPSSpreadSheetReportLinkOptionView : unsigned char { ssovRowAndColumnHeadings, ssovGridLines, ssovSuppressSourceFormats };

typedef System::Set<TdxPSSpreadSheetReportLinkOptionView, TdxPSSpreadSheetReportLinkOptionView::ssovRowAndColumnHeadings, TdxPSSpreadSheetReportLinkOptionView::ssovSuppressSourceFormats>  TdxPSSpreadSheetReportLinkOptionsView;

class DELPHICLASS TCustomdxSpreadSheetReportLink;
class PASCALIMPLEMENTATION TCustomdxSpreadSheetReportLink : public Dxpsbasegridlnk::TAbstractdxGridReportLink
{
	typedef Dxpsbasegridlnk::TAbstractdxGridReportLink inherited;
	
private:
	bool FAppendingExtraColumns;
	int FColCount;
	System::Classes::TList* FCellObjects;
	int FExtraColumnCount;
	TdxPSGridCellsAdapter* FGridAdapter;
	TdxPSSpreadSheetReportLinkOptionsView FOptionsView;
	System::Types::TRect FPrintArea;
	bool FProcessingMerges;
	int FRowCount;
	Vcl::Graphics::TFont* FTempFont;
	Cxssheet::TcxSSBookSheet* __fastcall GetBookSheet(void);
	Cxssheet::TcxCustomSpreadSheetBook* __fastcall GetCustomSpreadSheetBook(void);
	int __fastcall GetMeaningColCount(void);
	int __fastcall GetMeaningRowCount(void);
	Cxssdata::TcxSSMergedCellsStorage* __fastcall GetMergedCells(void);
	void __fastcall SetOptionsView(TdxPSSpreadSheetReportLinkOptionsView Value);
	void __fastcall SetPrintArea(System::Types::TRect &Value);
	Cxssheet::TcxSSCellObject* __fastcall GetSSCellObject(int ACol, int ARow);
	Cxssstyles::TcxSSCellStyle* __fastcall GetSSCellStyle(int ACol, int ARow);
	Cxexcelconst::PcxExcelPalette __fastcall GetSSColorPalette(void);
	Cxssdata::TcxSSDataStorage* __fastcall GetSSDataStorage(void);
	System::Uitypes::TColor __fastcall GetSSDefaultCellSideColor(Dxpscore::TdxCellSide ASide);
	Cxssstyles::TcxSSCellStyle* __fastcall GetSSDefaultStyle(void);
	int __fastcall GetFlatIndex(int ACol, int ARow);
	System::Uitypes::TColor __fastcall GetRealColor(int AColorIndex, System::Uitypes::TColor ADefaultColor);
	bool __fastcall IsSSDefaultStyle(Cxssstyles::TcxSSCellStyle* AStyle);
	
protected:
	int FSourceHeaderFontIndex;
	virtual System::UnicodeString __fastcall CannotActivateReportErrorString(void);
	DYNAMIC void __fastcall DoChangeComponent(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsScaleGridLines(void);
	virtual bool __fastcall NeedTwoPassRendering(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetDataItemClass(int ACol, int ARow = 0x0);
	virtual int __fastcall GetColCount(void);
	virtual int __fastcall GetFixedColCount(void);
	virtual int __fastcall GetFixedRowCount(void);
	virtual int __fastcall GetRowCount(void);
	virtual Dxpscore::TdxCellSides __fastcall GetCellSides(int ACol, int ARow);
	virtual System::UnicodeString __fastcall GetCellText(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetCellTextAlignY(int ACol, int ARow);
	virtual int __fastcall GetMinRowHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Vcl::Graphics::TFont* AFont);
	virtual System::Types::TRect __fastcall GetSelectionRect(void);
	virtual System::Uitypes::TColor __fastcall GetSourceCellColor(int ACol, int ARow);
	virtual System::Uitypes::TColor __fastcall GetSourceCellContentBkColor(int ACol, int ARow);
	virtual Dxpsfillpatterns::TdxPSFillPatternClass __fastcall GetSourceCellContentPattern(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellEdge3DSoft(int ACol, int ARow);
	virtual Dxpscore::TdxCellEdgeMode __fastcall GetSourceCellEdgeMode(int ACol, int ARow);
	virtual int __fastcall GetSourceCellFontIndex(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellMultiline(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetSourceCellTextAlignX(int ACol, int ARow);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetSourceCellTextAlignY(int ACol, int ARow);
	virtual bool __fastcall GetSourceCellTransparent(int ACol, int ARow);
	virtual int __fastcall GetSourceColWidth(int ACol);
	virtual int __fastcall GetSourceRowHeight(int ARow);
	virtual bool __fastcall HasSelection(void);
	virtual bool __fastcall IsDrawBorder(void);
	virtual bool __fastcall IsDrawHorzLines(void);
	virtual bool __fastcall IsDrawVertLines(void);
	virtual bool __fastcall IsEmptyRow(int ARow);
	virtual bool __fastcall IsProcessedCol(int ACol);
	virtual bool __fastcall IsProcessedRow(int ARow);
	virtual void __fastcall AfterConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall PrepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall UnprepareConstruct(Dxpscore::TdxReportCells* AReportCells);
	void __fastcall AddMerges(Dxpscore::TdxReportCells* AReportCells);
	void __fastcall AppendAdditionalColumns(TdxPSGridCellsAdapter* AnAdapter);
	void __fastcall CalcTextExtents(TdxPSGridCellsAdapter* AnAdapter);
	void __fastcall DeleteCellObjects(void);
	void __fastcall DeleteUnneededCellSides(TdxPSGridCellsAdapter* AnAdapter);
	void __fastcall FixupRowWidths(TdxPSGridCellsAdapter* AnAdapter);
	bool __fastcall HasMerges(void);
	bool __fastcall IsEmptyCell(const Cxsstypes::TcxSSCellRec &ACell);
	bool __fastcall OnlyEdgeIsAssigned(const Cxsstypes::TcxSSCellRec &ACell, Cxsstypes::TcxSSEdgeBorder AEdge);
	bool __fastcall OnlyLeftEdgeIsAssigned(Cxsstypes::TcxSSCellRec &ACell);
	bool __fastcall OnlyTopEdgeIsAssigned(Cxsstypes::TcxSSCellRec &ACell);
	void __fastcall PostProcessItems(TdxPSGridCellsAdapter* AnAdapter);
	virtual void __fastcall SetupCellBorders(int ACol, int ARow, Dxpscore::TAbstractdxReportCellData* ADataItem);
	void __fastcall CheckPrintAreaBounds(System::Types::TRect &R);
	int __fastcall GetColumnOffset(int ACol);
	int __fastcall GetRowOffset(int ARow);
	bool __fastcall IsMergedBorder(int ACol, int ARow, Dxpscore::TdxCellSide ASide);
	virtual bool __fastcall IsMergedCell(int ACol, int ARow);
	virtual bool __fastcall IsNearMostLeftCell(int ACol, int ARow);
	virtual bool __fastcall IsNearMostTopCell(int ACol, int ARow);
	bool __fastcall IsShowGridLines(void);
	bool __fastcall IsShowRowAndColumnHeadings(void);
	bool __fastcall IsSuppressSourceFormats(void);
	__property int ColCount = {read=GetColCount, nodefault};
	__property int ExtraColumnCount = {read=FExtraColumnCount, nodefault};
	__property int MeaningColCount = {read=GetMeaningColCount, nodefault};
	__property int MeaningRowCount = {read=GetMeaningRowCount, nodefault};
	__property Cxssdata::TcxSSMergedCellsStorage* MergedCells = {read=GetMergedCells};
	__property int RowCount = {read=GetRowCount, nodefault};
	
public:
	__fastcall virtual TCustomdxSpreadSheetReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxSpreadSheetReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ClearPrintArea(void);
	virtual bool __fastcall DataProviderPresent(void);
	virtual bool __fastcall DataToPrintExist(void);
	virtual bool __fastcall PrintAreaExists(void);
	__property Cxssheet::TcxSSBookSheet* BookSheet = {read=GetBookSheet};
	__property Cxssheet::TcxCustomSpreadSheetBook* CustomSpreadSheetBook = {read=GetCustomSpreadSheetBook};
	__property System::Types::TRect PrintArea = {read=FPrintArea, write=SetPrintArea};
	
__published:
	__property Color = {default=16777215};
	__property Effects3D = {default=0};
	__property FixedColor = {default=-16777201};
	__property FixedFont;
	__property FixedTransparent = {default=0};
	__property Font;
	__property GridLineColor = {default=0};
	__property HeadersOnEveryPage = {default=0};
	__property OnlySelected = {default=0};
	__property TdxPSSpreadSheetReportLinkOptionsView OptionsView = {read=FOptionsView, write=SetOptionsView, default=1};
	__property RowAutoHeight = {default=0};
	__property ScaleFonts = {default=1};
	__property Soft3D = {default=1};
	__property Transparent = {default=1};
	__property UseCustomPageBreaks = {default=0};
	__property UseHorzDelimiters = {default=1};
	__property UseVertDelimiters = {default=1};
	__property OnGetCustomPageBreaks;
	__property OnInitializeItem;
};


class DELPHICLASS TdxSpreadSheetBookReportLink;
class PASCALIMPLEMENTATION TdxSpreadSheetBookReportLink : public TCustomdxSpreadSheetReportLink
{
	typedef TCustomdxSpreadSheetReportLink inherited;
	
private:
	Cxssheet::TcxSpreadSheetBook* __fastcall GetSpreadSheetBook(void);
	
public:
	__property Cxssheet::TcxSpreadSheetBook* SpreadSheetBook = {read=GetSpreadSheetBook};
public:
	/* TCustomdxSpreadSheetReportLink.Create */ inline __fastcall virtual TdxSpreadSheetBookReportLink(System::Classes::TComponent* AOwner) : TCustomdxSpreadSheetReportLink(AOwner) { }
	/* TCustomdxSpreadSheetReportLink.Destroy */ inline __fastcall virtual ~TdxSpreadSheetBookReportLink(void) { }
	
};


class DELPHICLASS TdxSpreadSheetReportLink;
class PASCALIMPLEMENTATION TdxSpreadSheetReportLink : public TCustomdxSpreadSheetReportLink
{
	typedef TCustomdxSpreadSheetReportLink inherited;
	
private:
	Cxssheet::TcxSpreadSheet* __fastcall GetSpreadSheet(void);
	
public:
	__property Cxssheet::TcxSpreadSheet* SpreadSheet = {read=GetSpreadSheet};
public:
	/* TCustomdxSpreadSheetReportLink.Create */ inline __fastcall virtual TdxSpreadSheetReportLink(System::Classes::TComponent* AOwner) : TCustomdxSpreadSheetReportLink(AOwner) { }
	/* TCustomdxSpreadSheetReportLink.Destroy */ inline __fastcall virtual ~TdxSpreadSheetReportLink(void) { }
	
};


class DELPHICLASS TfmdxSpreadSheetDesignWindow;
class PASCALIMPLEMENTATION TfmdxSpreadSheetDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxpc::TcxPageControl* pgctrlMain;
	Cxpc::TcxTabSheet* tshOptions;
	Vcl::Extctrls::TImage* Image5;
	Vcl::Extctrls::TImage* imgGrid;
	Cxpc::TcxTabSheet* tshColor;
	Cxpc::TcxTabSheet* tshFont;
	Cxpc::TcxTabSheet* tshBehaviors;
	Vcl::Extctrls::TImage* Image3;
	Vcl::Extctrls::TImage* Image1;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* stFixedTransparent;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblMiscellaneous;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* lblOnEveryPage;
	Cxlabel::TcxLabel* lblSelection;
	Cxcheckbox::TcxCheckBox* chbxRowAutoHeight;
	Cxcheckbox::TcxCheckBox* chbxShowRowAndColumnHeadings;
	Cxcheckbox::TcxCheckBox* chbxShowGridlines;
	Cxcheckbox::TcxCheckBox* chbxSuppressSourceFormats;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxcheckbox::TcxCheckBox* chbxFixedTransparent;
	Cxcheckbox::TcxCheckBox* chbxOnlySelected;
	Cxcheckbox::TcxCheckBox* chbxFixedRowsOnEveryPage;
	Cxbuttons::TcxButton* btnFont;
	Cxbuttons::TcxButton* btnFixedFont;
	Cxtextedit::TcxTextEdit* edFont;
	Cxtextedit::TcxTextEdit* edFixedFont;
	Cxcolorcombobox::TcxColorComboBox* ccbxLineColor;
	Cxlabel::TcxLabel* lblColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxFixedColor;
	Cxlabel::TcxLabel* lblFixedColor;
	Cxlabel::TcxLabel* cxLabel1;
	void __fastcall chbxFixedRowsOnEveryPageClick(System::TObject* Sender);
	void __fastcall chbxOnlySelectedClick(System::TObject* Sender);
	void __fastcall btnFixedFontClick(System::TObject* Sender);
	void __fastcall chbxRowAutoHeightClick(System::TObject* Sender);
	void __fastcall chbxOptionsViewChanged(System::TObject* Sender);
	void __fastcall chbxFixedTransparentClick(System::TObject* Sender);
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall lblColorClick(System::TObject* Sender);
	void __fastcall pgctrlMainChange(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	void __fastcall stFixedTransparentClick(System::TObject* Sender);
	
private:
	Vcl::Controls::TCustomControl* FPreviewBox;
	TCustomdxSpreadSheetReportLink* __fastcall GetReportLink(void);
	void __fastcall CreateControls(void);
	void __fastcall SetReportLink(TCustomdxSpreadSheetReportLink* Value);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdateControlsState(void);
	virtual void __fastcall UpdatePreview(void);
	
public:
	__fastcall virtual TfmdxSpreadSheetDesignWindow(System::Classes::TComponent* AOwner);
	__property TCustomdxSpreadSheetReportLink* ReportLink = {read=GetReportLink, write=SetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TfmdxSpreadSheetDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmdxSpreadSheetDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmdxSpreadSheetDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Types::TRect dxPSEmptySSPrintArea;
extern PACKAGE System::StaticArray<Dxpscore::TdxCellSide, 4> dxPSCellSideMap;
extern PACKAGE System::StaticArray<Cxsstypes::TcxSSEdgeBorder, 4> cxSSEdgeBorderMap;
extern PACKAGE System::StaticArray<Dxpsedgepatterns::TdxPSCellEdgePatternOrientation, 4> dxCellEdgeSideOrientation;
extern PACKAGE System::StaticArray<Dxpsedgepatterns::TdxPSEdgePatternClass, 15> dxPSEdgePatternClassMap;
extern PACKAGE System::StaticArray<Dxpsfillpatterns::TdxPSFillPatternClass, 18> dxPSFillPatternClassMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignX, 5> dxPSTextAlignXMap;
extern PACKAGE System::StaticArray<Cxdrawtextutils::TcxTextAlignY, 4> dxPSTextAlignYMap;
}	/* namespace Dxpscxsslnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXSSLNK)
using namespace Dxpscxsslnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxsslnkHPP
