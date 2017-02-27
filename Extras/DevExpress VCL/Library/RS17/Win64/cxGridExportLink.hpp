// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridExportLink.pas' rev: 24.00 (Win64)

#ifndef CxgridexportlinkHPP
#define CxgridexportlinkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxExport.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxCalc.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridBandedTableView.hpp>	// Pascal unit
#include <cxGridCardView.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridRows.hpp>	// Pascal unit
#include <cxGridStrs.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridChartView.hpp>	// Pascal unit
#include <cxGridLayoutView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridexportlink
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxGridExport;
class PASCALIMPLEMENTATION EcxGridExport : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxGridExport(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxGridExport(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxGridExport(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxGridExport(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxGridExport(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxGridExport(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxGridExport(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxGridExport(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxGridExport(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxGridExport(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxGridExport(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxGridExport(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxGridExport(void) { }
	
};


class DELPHICLASS TcxGridCustomExport;
class PASCALIMPLEMENTATION TcxGridCustomExport : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxexport::TcxExportScale* FColumns;
	int FDefaultRowHeight;
	Cxexport::TcxCacheCellStyle FDefaultStyle;
	int FDefaultStyleIndex;
	bool FExpand;
	int FExportType;
	System::UnicodeString FFileName;
	Cxgrid::TcxCustomGrid* FGrid;
	Cxgridcustomview::TcxCustomGridView* FGridView;
	Cxexport::_di_IcxCellInternalCache FInternalProvider;
	bool FInternalProviderSupported;
	Cxexport::_di_IcxExportProvider FProvider;
	Cxexport::TcxExportScale* FRows;
	System::Classes::TList* FRecordsList;
	bool FSaveAll;
	bool FSaveGridModeFlag;
	bool FUseNativeFormat;
	Cxgridcustomview::TcxCustomGridViewInfo* FViewInfo;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetExpandButtonSize(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetRecord(int ARecordIndex);
	int __fastcall GetRecordCount(void);
	Cxgridcustomview::TcxCustomGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall BeforeCommit(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfo* __fastcall CalculateViewViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView, System::Types::TRect &ABounds);
	System::Variant __fastcall CheckNativeValue(Cxedit::TcxCustomEditProperties* AProperties, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, const System::Variant &AValue);
	virtual void __fastcall CreateExportCache(void);
	virtual void __fastcall CreateExportCells(void);
	virtual void __fastcall ExpandRecords(bool AFullExpand);
	virtual void __fastcall ExportCells(void);
	virtual void __fastcall ExtractRowsForExport(void);
	void __fastcall FillArea(const System::Types::TRect &ABounds, int AStyleIndex, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	void __fastcall FillRealArea(const System::Types::TRect &ABounds, int AStyleIndex, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall Finalize(void);
	Cxexport::TcxCacheCellStyle __fastcall GetContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000));
	System::Variant __fastcall GetViewItemValue(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual System::Variant __fastcall GetViewItemValueEx(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxedit::TcxCustomEditProperties* &AProperties);
	bool __fastcall HasSelectedChildren(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	bool __fastcall HasSelectedRecords(Cxgridcustomview::TcxCustomGridView* AView);
	virtual void __fastcall Initialize(void);
	bool __fastcall IsCurrencyItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	bool __fastcall IsCurrencyProperties(Cxedit::TcxCustomEditProperties* AProperties);
	bool __fastcall IsEmpty(void);
	virtual bool __fastcall IsNativeFormatProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	void __fastcall RealBoundsToLogicalBounds(const System::Types::TRect &ABounds, /* out */ System::Types::TRect &ALogicalBounds);
	void __fastcall RealBoundsToLogicalBoundsEx(const System::Types::TRect &ABounds, const System::Types::TRect &ASearchArea, /* out */ System::Types::TRect &ALogicalBounds);
	int __fastcall RegisterContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	int __fastcall RegisterSolidStyle(int AStyleIndex, System::TObject* AData = (System::TObject*)(0x0));
	int __fastcall RegisterSolidStyleEx(System::Uitypes::TColor AColor);
	virtual void __fastcall RegisterStyles(void);
	int __fastcall RegisterViewParams(const Cxgraphics::TcxViewParams &AViewParams, const System::Classes::TAlignment AAlignment = (System::Classes::TAlignment)(0x0));
	bool __fastcall SetCellAsGraphic(const System::Types::TRect &ABounds, int AColumn, int ARow, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	void __fastcall SetCellValueAndStyle(int AColumn, int ARow, const System::Variant &AValue, const Cxexport::TcxCacheCellStyle &AStyle);
	void __fastcall SetRealCellStyle(const System::Types::TRect &ARealBounds, const System::Types::TRect &ASearchArea, int AStyleIndex);
	void __fastcall SetRealCellStyleAndValue(const System::Types::TRect &ARealBounds, const System::Types::TRect &ASearchArea, int AStyleIndex, const System::Variant &AValue);
	void __fastcall SetRealCellStyleAndValueEx(const System::Types::TRect &ARealBounds, const System::Types::TRect &ASearchArea, int AStyleIndex, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	int __fastcall TextHeight(Vcl::Graphics::TFont* AFont);
	int __fastcall TextHeightEx(const Cxgraphics::TcxViewParams &AViewParams);
	int __fastcall TextWidth(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText);
	int __fastcall TextWidthEx(const Cxgraphics::TcxViewParams &AViewParams, const System::UnicodeString AText);
	void __fastcall ViewParamsToExportStyle(const Cxgraphics::TcxViewParams &AViewParams, Cxexport::TcxCacheCellStyle &AExportStyle, const System::Classes::TAlignment AAlignment = (System::Classes::TAlignment)(0x0), Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000));
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property int DefaultRowHeight = {read=FDefaultRowHeight, write=FDefaultRowHeight, nodefault};
	__property Cxexport::TcxCacheCellStyle DefaultStyle = {read=FDefaultStyle, write=FDefaultStyle};
	__property int DefaultStyleIndex = {read=FDefaultStyleIndex, write=FDefaultStyleIndex, nodefault};
	__property int ExportType = {read=FExportType, nodefault};
	__property System::Classes::TList* RecordsList = {read=FRecordsList};
	
public:
	__fastcall virtual TcxGridCustomExport(System::UnicodeString AFileName, int AExportType, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgrid::TcxCustomGrid* AGrid, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo);
	__fastcall virtual TcxGridCustomExport(TcxGridCustomExport* AMasterExport, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo);
	__fastcall virtual ~TcxGridCustomExport(void);
	void __fastcall AddSeparators(System::UnicodeString const *ASeparators, const int ASeparators_Size);
	virtual void __fastcall DoExport(void);
	__property Cxexport::TcxExportScale* Columns = {read=FColumns};
	__property bool Expand = {read=FExpand, write=FExpand, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSize, nodefault};
	__property System::UnicodeString FileName = {read=FFileName};
	__property Cxgrid::TcxCustomGrid* Grid = {read=FGrid};
	__property Cxgridcustomview::TcxCustomGridView* GridView = {read=FGridView};
	__property Cxexport::_di_IcxCellInternalCache InternalProvider = {read=FInternalProvider};
	__property bool InternalProviderSupported = {read=FInternalProviderSupported, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Cxexport::_di_IcxExportProvider Provider = {read=FProvider};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property Cxgridcustomtableview::TcxCustomGridRecord* Records[int ARecordIndex] = {read=GetRecord};
	__property Cxexport::TcxExportScale* Rows = {read=FRows};
	__property bool SaveAll = {read=FSaveAll, write=FSaveAll, nodefault};
	__property bool UseNativeFormat = {read=FUseNativeFormat, write=FUseNativeFormat, nodefault};
	__property Cxgridcustomview::TcxCustomGridViewInfo* ViewInfo = {read=GetViewInfo};
};


typedef System::TMetaClass* TcxGridCustomExportClass;

class DELPHICLASS TcxExportVisualItem;
class PASCALIMPLEMENTATION TcxExportVisualItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect Bounds;
	System::TObject* Data;
	System::TObject* Data2;
	System::UnicodeString DisplayText;
	bool Hidden;
	bool IsBackground;
	Cxgraphics::TcxBorders ItemBorders;
	System::Uitypes::TColor ItemBorderColor;
	int Style;
	bool Slave;
	System::Variant Value;
	System::Types::TRect __fastcall GetBoundsRelativeTo(int ATop, int ALeft);
	bool __fastcall IsColumn(void);
public:
	/* TObject.Create */ inline __fastcall TcxExportVisualItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxExportVisualItem(void) { }
	
};


class DELPHICLASS TcxExportGroupSummaryItem;
class PASCALIMPLEMENTATION TcxExportGroupSummaryItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Classes::TAlignment Alignment;
	System::Types::TRect Bounds;
	Cxgridcustomtableview::TcxCustomGridTableItem* Column;
	int Index;
	Cxgridtableview::TcxGridTableSummaryItem* SummaryItem;
	System::UnicodeString Text;
	System::Variant Value;
	Cxgraphics::TcxViewParams ViewParams;
	void __fastcall InitWidth(void);
public:
	/* TObject.Create */ inline __fastcall TcxExportGroupSummaryItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxExportGroupSummaryItem(void) { }
	
};


typedef System::TMetaClass* TcxExportVisualItemClass;

class DELPHICLASS TcxGridTableViewExport;
class PASCALIMPLEMENTATION TcxGridTableViewExport : public TcxGridCustomExport
{
	typedef TcxGridCustomExport inherited;
	
private:
	Cxclasses::TcxObjectList* FGroupSummaryItemsList;
	int FRecordHeight;
	int FRecordRowCount;
	int FRecordWidth;
	Cxclasses::TcxObjectList* FPatternsList;
	Cxclasses::TcxObjectList* FVisualItemsList;
	System::Uitypes::TColor __fastcall GetFooterCellBorderColor(void);
	System::Uitypes::TColor __fastcall GetGridLineColor(void);
	Cxgraphics::TcxBorders __fastcall GetGridLines(void);
	Cxgridtableview::TcxGridTableView* __fastcall GetGridView(void);
	int __fastcall GetGroupSummaryCount(void);
	TcxExportGroupSummaryItem* __fastcall GetGroupSummaryItem(int AIndex);
	bool __fastcall GetHasPreview(Cxgridcustomtableview::TcxCustomGridRecord* ARow);
	int __fastcall GetIndicatorWidth(void);
	int __fastcall GetLeftPos(void);
	Cxgridtableview::TcxGridTableOptionsView* __fastcall GetOptionsView(void);
	TcxExportVisualItem* __fastcall GetPattern(int AIndex);
	int __fastcall GetPatternCount(void);
	Cxgridtableview::TcxGridPreviewPlace __fastcall GetPreviewPlace(void);
	Cxgridtableview::TcxGridTableViewStyles* __fastcall GetStyles(void);
	HIDESBASE Cxgridtableview::TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	TcxExportVisualItem* __fastcall GetVisualItem(int AIndex);
	int __fastcall GetVisualItemCount(void);
	void __fastcall SetLeftPos(int AValue);
	
protected:
	virtual void __fastcall AddDataRow(int &ATop, int &ALeft, Cxgridtableview::TcxGridDataRow* ARow);
	virtual void __fastcall AddFooterCells(int &ATop, int &ALeft, Cxgridtableview::TcxCustomGridRow* ARow, int ALevel, int ADataLevel, Cxcustomdata::TcxDataSummaryItems* AItems, System::PVariant AValues, bool AIsFooter);
	virtual void __fastcall AddGroupRow(int &ATop, int &ALeft, Cxgridtableview::TcxGridGroupRow* ARow);
	virtual int __fastcall AddIndents(int ATop, int ARowHeight, Cxgridcustomtableview::TcxCustomGridRecord* ARow, bool AHasButton, int ALevel = 0xffffffff);
	virtual void __fastcall AddMasterDataRow(int &ATop, int &ALeft, Cxgridtableview::TcxGridMasterDataRow* ARow);
	virtual void __fastcall AddRowFooter(int &ATop, int &ALeft, int ADataLevel, int ALevel, Cxgridcustomtableview::TcxCustomGridRecord* ARow);
	virtual void __fastcall AddRowFooters(int &ATop, int &ALeft, Cxgridcustomtableview::TcxCustomGridRecord* ARow);
	virtual void __fastcall AddRowPreview(int &ATop, int &ALeft, Cxgridcustomtableview::TcxCustomGridRecord* ARow);
	TcxExportVisualItem* __fastcall AddVisualDataItem(const System::Types::TRect &AItemBounds, int AStyle, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AColumn);
	virtual TcxExportVisualItem* __fastcall AddVisualItem(TcxExportVisualItemClass AItemClass, const System::Types::TRect &ABounds);
	TcxExportVisualItem* __fastcall AddVisualItemEx(const System::Types::TRect &AItemBounds, const System::UnicodeString ADisplayText, const Cxgraphics::TcxViewParams &AViewParams, System::Classes::TAlignment AAlignment, Cxgraphics::TcxBorders ABorders, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), bool AIsBackground = false, bool AWordWrap = true)/* overload */;
	TcxExportVisualItem* __fastcall AddVisualItemEx(const System::Types::TRect &AItemBounds, const System::UnicodeString ADisplayText, int AStyle, bool AIsBackground = false)/* overload */;
	TcxExportVisualItem* __fastcall AddPattern(const System::Types::TRect &ABounds, System::TObject* AData, int AOffset = 0x0);
	bool __fastcall CanShowMultiSummaries(bool AIsFooter);
	virtual void __fastcall CreateContent(int &ATop, int &ALeft);
	virtual void __fastcall CreateFooter(int &ATop, int &ALeft);
	virtual void __fastcall CreateHeader(int &ATop, int &ALeft);
	virtual void __fastcall CreateExportCells(void);
	void __fastcall CreateRecordFromPattern(int &ATop, int &ALeft, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	bool __fastcall DoMergeCell(TcxExportVisualItem* AMasterItem, TcxExportVisualItem* ASlaveItem);
	virtual void __fastcall ExportCells(void);
	virtual void __fastcall ExportDetailCell(TcxExportVisualItem* ACell);
	virtual void __fastcall Finalize(void);
	virtual int __fastcall GetColumnOffset(Cxgridtableview::TcxGridColumn* AColumn);
	Cxexport::TcxCacheCellStyle __fastcall GetExpandButtonParams(Cxgraphics::TcxBorders ABorders);
	int __fastcall GetFooterCellCount(Cxcustomdata::TcxDataSummaryItems* AItems);
	System::Types::TRect __fastcall GetFooterItemBounds(int AIndex, int ALineIndex, const System::Types::TRect &AOrigin, bool AIsFooter);
	int __fastcall GetFooterLineCount(Cxcustomdata::TcxDataSummaryItems* AItems);
	System::Types::TRect __fastcall GetGroupRowColumnIntersection(const System::Types::TRect &ARowBounds, Cxgridcustomtableview::TcxCustomGridTableItem* AColumn);
	virtual bool __fastcall GetIsSummaryUnderColumns(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetPatternParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, TcxExportVisualItem* AItem);
	int __fastcall GetPreviewHeight(Cxgridcustomtableview::TcxCustomGridRecord* ARow);
	virtual bool __fastcall HasFooter(Cxgridcustomtableview::TcxCustomGridRecord* ARow, int &ALevel);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall MergeCells(void);
	void __fastcall ProcessGroupSummaryItem(Cxgridtableview::TcxGridGroupRow* ARow, System::PVariant AValues, int AIndex, const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &ARowViewParams);
	void __fastcall ProcessGroupSummaryItems(Cxgridtableview::TcxGridGroupRow* ARow, System::Types::TRect &ABounds);
	void __fastcall ProduceHeadersContainer(int &ATop, int &ALeft, Cxgridtableview::TcxGridColumnContainerViewInfo* AViewInfo);
	void __fastcall SetPatternsBounds(int ATop, int ABottom);
	void __fastcall SetPatternsHeight(int AHeight);
	void __fastcall ScalePatterns(int AHeight, int ARowHeight);
	__property int GroupSummaryItemCount = {read=GetGroupSummaryCount, nodefault};
	__property TcxExportGroupSummaryItem* GroupSummaryItems[int Index] = {read=GetGroupSummaryItem};
	__property Cxclasses::TcxObjectList* GroupSummaryItemsList = {read=FGroupSummaryItemsList};
	__property int LeftPos = {read=GetLeftPos, write=SetLeftPos, nodefault};
	__property int PatternCount = {read=GetPatternCount, nodefault};
	__property TcxExportVisualItem* Patterns[int Index] = {read=GetPattern};
	__property Cxclasses::TcxObjectList* PatternsList = {read=FPatternsList};
	
public:
	__property System::Uitypes::TColor FooterCellBorderColor = {read=GetFooterCellBorderColor, nodefault};
	__property System::Uitypes::TColor GridLineColor = {read=GetGridLineColor, nodefault};
	__property Cxgraphics::TcxBorders GridLines = {read=GetGridLines, nodefault};
	__property Cxgridtableview::TcxGridTableView* GridView = {read=GetGridView};
	__property bool HasPreview[Cxgridcustomtableview::TcxCustomGridRecord* ARow] = {read=GetHasPreview};
	__property int IndicatorWidth = {read=GetIndicatorWidth, nodefault};
	__property bool IsSummaryUnderColumns = {read=GetIsSummaryUnderColumns, nodefault};
	__property Cxgridtableview::TcxGridTableOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxgridtableview::TcxGridPreviewPlace PreviewPlace = {read=GetPreviewPlace, nodefault};
	__property int RecordHeight = {read=FRecordHeight, write=FRecordHeight, nodefault};
	__property int RecordRowCount = {read=FRecordRowCount, nodefault};
	__property int RecordWidth = {read=FRecordWidth, write=FRecordWidth, nodefault};
	__property Cxgridtableview::TcxGridTableViewStyles* Styles = {read=GetStyles};
	__property Cxgridtableview::TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisualItemCount = {read=GetVisualItemCount, nodefault};
	__property TcxExportVisualItem* VisualItems[int Index] = {read=GetVisualItem};
	__property Cxclasses::TcxObjectList* VisualItemsList = {read=FVisualItemsList};
public:
	/* TcxGridCustomExport.Create */ inline __fastcall virtual TcxGridTableViewExport(System::UnicodeString AFileName, int AExportType, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgrid::TcxCustomGrid* AGrid, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridCustomExport(AFileName, AExportType, AGridView, AGrid, AViewInfo) { }
	/* TcxGridCustomExport.CreateFrom */ inline __fastcall virtual TcxGridTableViewExport(TcxGridCustomExport* AMasterExport, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridCustomExport(AMasterExport, AGridView, AViewInfo) { }
	/* TcxGridCustomExport.Destroy */ inline __fastcall virtual ~TcxGridTableViewExport(void) { }
	
};


class DELPHICLASS TcxGridBandedTableViewExport;
class PASCALIMPLEMENTATION TcxGridBandedTableViewExport : public TcxGridTableViewExport
{
	typedef TcxGridTableViewExport inherited;
	
private:
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableView* __fastcall GetGridView(void);
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall CreateBandHeaders(int &ATop, bool AForRootBands);
	virtual void __fastcall CreateHeader(int &ATop, int &ALeft);
	virtual int __fastcall GetColumnOffset(Cxgridtableview::TcxGridColumn* AColumn);
	virtual System::Types::TPoint __fastcall GetContentOffset(void);
	virtual bool __fastcall GetIsSummaryUnderColumns(void);
	int __fastcall GetParentBandOffset(Cxgridbandedtableview::TcxGridBand* ABand);
	TcxExportVisualItem* __fastcall GetPatternByBand(Cxgridbandedtableview::TcxGridBand* ABand);
	virtual Cxgraphics::TcxViewParams __fastcall GetPatternParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, TcxExportVisualItem* AItem);
	int __fastcall ProduceColumnsContainer(Cxgridtableview::TcxGridColumnContainerViewInfo* AContainer, int ATop, int ALeft);
	
public:
	__property System::Types::TPoint ContentOffset = {read=GetContentOffset};
	__property Cxgridbandedtableview::TcxGridBandedTableView* GridView = {read=GetGridView};
	__property Cxgridbandedtableview::TcxGridBandedTableOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxgridbandedtableview::TcxGridBandedTableViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxGridCustomExport.Create */ inline __fastcall virtual TcxGridBandedTableViewExport(System::UnicodeString AFileName, int AExportType, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgrid::TcxCustomGrid* AGrid, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridTableViewExport(AFileName, AExportType, AGridView, AGrid, AViewInfo) { }
	/* TcxGridCustomExport.CreateFrom */ inline __fastcall virtual TcxGridBandedTableViewExport(TcxGridCustomExport* AMasterExport, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridTableViewExport(AMasterExport, AGridView, AViewInfo) { }
	/* TcxGridCustomExport.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewExport(void) { }
	
};


class DELPHICLASS TcxExportCardRow;
class DELPHICLASS TcxExportCard;
class PASCALIMPLEMENTATION TcxExportCardRow : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FHasSeparator;
	TcxExportCard* FOwner;
	System::Types::TRect __fastcall GetCaptionBounds(void);
	Cxgraphics::TcxViewParams __fastcall GetCaptionStyle(void);
	Cxgridcardview::TcxGridCard* __fastcall GetCard(void);
	int __fastcall GetCategoryIndent(void);
	System::Classes::TAlignment __fastcall GetDataAlignment(void);
	System::Types::TRect __fastcall GetDataBounds(void);
	Cxgraphics::TcxViewParams __fastcall GetDataStyle(void);
	System::Variant __fastcall GetDataValue(void);
	bool __fastcall GetHasIndent(void);
	bool __fastcall GetHasSeparator(void);
	int __fastcall GetHeight(void);
	System::Types::TRect __fastcall GetIndentBounds(void);
	Cxgraphics::TcxViewParams __fastcall GetIndentStyle(void);
	System::Types::TRect __fastcall GetSeparatorBounds(void);
	int __fastcall GetSeparatorWidth(void);
	bool __fastcall GetShowCaption(void);
	bool __fastcall GetShowData(void);
	System::UnicodeString __fastcall GetVisibleCaption(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	void __fastcall AddToScales(Cxexport::TcxExportScale* AColumnScale, Cxexport::TcxExportScale* ARowScale);
	
public:
	System::Types::TRect Bounds;
	int CaptionStyleIndex;
	int CaptionWidth;
	int DataStyleIndex;
	int IndentStyleIndex;
	Cxgridcardview::TcxGridCardViewRow* Row;
	__fastcall TcxExportCardRow(TcxExportCard* AOwner);
	__property System::Types::TRect CaptionBounds = {read=GetCaptionBounds};
	__property Cxgraphics::TcxViewParams CaptionStyle = {read=GetCaptionStyle};
	__property Cxgridcardview::TcxGridCard* Card = {read=GetCard};
	__property int CategoryIndent = {read=GetCategoryIndent, nodefault};
	__property System::Classes::TAlignment DataAlignment = {read=GetDataAlignment, nodefault};
	__property System::Types::TRect DataBounds = {read=GetDataBounds};
	__property Cxgraphics::TcxViewParams DataStyle = {read=GetDataStyle};
	__property System::Variant DataValue = {read=GetDataValue};
	__property bool HasIndent = {read=GetHasIndent, nodefault};
	__property bool HasSeparator = {read=GetHasSeparator, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property System::Types::TRect IndentBounds = {read=GetIndentBounds};
	__property Cxgraphics::TcxViewParams IndentStyle = {read=GetIndentStyle};
	__property TcxExportCard* Owner = {read=FOwner};
	__property System::Types::TRect SeparatorBounds = {read=GetSeparatorBounds};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
	__property bool ShowCaption = {read=GetShowCaption, nodefault};
	__property bool ShowData = {read=GetShowData, nodefault};
	__property System::UnicodeString VisibleCaption = {read=GetVisibleCaption};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxExportCardRow(void) { }
	
};


class DELPHICLASS TcxGridCardViewExport;
class PASCALIMPLEMENTATION TcxExportCard : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Types::TRect FBounds;
	Cxgridcardview::TcxGridCard* FCard;
	Cxclasses::TcxObjectList* FLayersList;
	TcxGridCardViewExport* FOwner;
	int __fastcall GetBorderWidth(void);
	bool __fastcall GetHasSeparators(void);
	System::Classes::TList* __fastcall GetLayer(int AIndex);
	int __fastcall GetLayerCount(void);
	System::Types::TRect __fastcall GetLayerSeparator(int AIndex);
	TcxExportCardRow* __fastcall GetRow(int ALayerIndex, int ARowIndex);
	int __fastcall GetRowCount(int ALayerIndex);
	int __fastcall GetSeparatorWidth(void);
	void __fastcall SetBounds(const System::Types::TRect &ABounds);
	System::Classes::TList* __fastcall AddLayer(void);
	TcxExportCardRow* __fastcall AddRow(int ALayerIndex, Cxgridcardview::TcxGridCardViewRow* ARow);
	void __fastcall AddLayerSeparators(void);
	void __fastcall AdjustLayersWidthToWidth(void);
	int __fastcall AdjustRowsHeightInLayer(int ALayer, int ATop);
	void __fastcall AdjustRowsWidthToWidth(int ALayer);
	void __fastcall CheckCategorySeparators(bool AHorizontalLayout);
	
public:
	__fastcall TcxExportCard(TcxGridCardViewExport* AOwner, Cxgridcardview::TcxGridCard* ACard);
	__fastcall virtual ~TcxExportCard(void);
	void __fastcall AddToScales(Cxexport::TcxExportScale* AColumnScale, Cxexport::TcxExportScale* ARowScale);
	void __fastcall CalculateLayersCaptionWidth(Cxexport::TcxExportIntList* AWidths, bool AFistRowInLayerOnly);
	int __fastcall GetRowCaptionWidth(int ALayerIndex, int ARowIndex, int AMaxWidth = 0x0);
	void __fastcall SetLayersCaptionWidth(Cxexport::TcxExportIntList* AWidths, bool AFistRowInLayerOnly);
	void __fastcall SetRowCaptionWidth(int ALayerIndex, int ARowIndex, int AWidth);
	__property int BorderWidth = {read=GetBorderWidth, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds, write=SetBounds};
	__property Cxgridcardview::TcxGridCard* Card = {read=FCard};
	__property bool HasSeparators = {read=GetHasSeparators, nodefault};
	__property int LayerCount = {read=GetLayerCount, nodefault};
	__property System::Classes::TList* Layers[int AIndex] = {read=GetLayer};
	__property System::Types::TRect LayerSeparators[int Index] = {read=GetLayerSeparator};
	__property Cxclasses::TcxObjectList* LayersList = {read=FLayersList};
	__property TcxGridCardViewExport* Owner = {read=FOwner};
	__property int RowCount[int ALayerIndex] = {read=GetRowCount};
	__property TcxExportCardRow* Rows[int ALayerIndex][int ARowIndex] = {read=GetRow};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
};


class DELPHICLASS TcxExportCardLayoutBuilder;
class PASCALIMPLEMENTATION TcxExportCardLayoutBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxExportCard* FExportCard;
	TcxGridCardViewExport* FOwner;
	System::Classes::TList* FRowsList;
	
protected:
	virtual int __fastcall GetLayerIndex(Cxgridcardview::TcxGridCardViewRow* ARow);
	virtual void __fastcall SplitRowsToLayers(void);
	
public:
	__fastcall TcxExportCardLayoutBuilder(TcxGridCardViewExport* AOwner);
	__fastcall virtual ~TcxExportCardLayoutBuilder(void);
	void __fastcall BuildLayout(Cxgridcardview::TcxGridCard* ACard, TcxExportCard* AExportCard);
	__property TcxExportCard* ExportCard = {read=FExportCard};
	__property TcxGridCardViewExport* Owner = {read=FOwner};
	__property System::Classes::TList* RowsList = {read=FRowsList};
};


class PASCALIMPLEMENTATION TcxGridCardViewExport : public TcxGridCustomExport
{
	typedef TcxGridCustomExport inherited;
	
private:
	int FCardBorderStyle;
	Cxexport::TcxExportScale* FCardSeparators;
	int FCardSeparatorStyleIndex;
	int FCategorySeparatorStyleIndex;
	int FColumnCardCount;
	bool FKeepRowsSameHeight;
	int FLayerSeparatorStyleIndex;
	TcxExportCardLayoutBuilder* FLayoutBuilder;
	int FRowCardCount;
	Cxclasses::TcxObjectList* FExportCardsList;
	Cxgridcardview::TcxGridCard* __fastcall GetCard(int AIndex);
	int __fastcall GetCardBorderWidth(void);
	int __fastcall GetCardCount(void);
	int __fastcall GetCardHeight(void);
	int __fastcall GetCardIndent(void);
	System::Types::TRect __fastcall GetCardSeparator(int AIndex);
	int __fastcall GetCardSeparatorCount(void);
	int __fastcall GetCardWidth(void);
	int __fastcall GetCategoryIndent(void);
	int __fastcall GetCategorySeparatorWidth(void);
	TcxExportCard* __fastcall GetExportCard(int AIndex);
	Cxgridcardview::TcxGridCardView* __fastcall GetGridView(void);
	int __fastcall GetInterCardHorzSpace(void);
	int __fastcall GetInterCardVertSpace(void);
	bool __fastcall GetIsHorizontalRows(void);
	bool __fastcall GetIsSimpleLayout(void);
	int __fastcall GetLayerSeparatorWidth(void);
	Cxgridcardview::TcxGridCardViewLayoutDirection __fastcall GetLayoutDirection(void);
	Cxgridcardview::TcxGridCardViewOptionsView* __fastcall GetOptionsView(void);
	
protected:
	void __fastcall AddCardSeparator(int APosition);
	TcxExportCard* __fastcall AddExportCard(int AColumnPosition, int ARowPosition, Cxgridcardview::TcxGridCard* ACard);
	void __fastcall AdjustRowCaptionWidth(void);
	void __fastcall CalculateVisibleInfo(void);
	TcxExportCardLayoutBuilder* __fastcall CreateCardLayoutBuilder(void);
	virtual void __fastcall CreateExportCells(void);
	void __fastcall ExportCardRow(TcxExportCard* ACard, TcxExportCardRow* ARow, const System::Types::TRect &ACardLogicalBounds);
	virtual void __fastcall ExportCells(void);
	virtual void __fastcall Finalize(void);
	virtual void __fastcall RegisterStyles(void);
	virtual void __fastcall SetRowSameHeight(void);
	__property Cxclasses::TcxObjectList* ExportCardsList = {read=FExportCardsList};
	
public:
	__property int CardBorderStyle = {read=FCardBorderStyle, nodefault};
	__property int CardBorderWidth = {read=GetCardBorderWidth, nodefault};
	__property int CardCount = {read=GetCardCount, nodefault};
	__property int CardHeight = {read=GetCardHeight, nodefault};
	__property int CardIndent = {read=GetCardIndent, nodefault};
	__property Cxgridcardview::TcxGridCard* Cards[int Index] = {read=GetCard};
	__property int CardSeparatorCount = {read=GetCardSeparatorCount, nodefault};
	__property System::Types::TRect CardSeparators[int Index] = {read=GetCardSeparator};
	__property int CardSeparatorStyleIndex = {read=FCardSeparatorStyleIndex, nodefault};
	__property int CardWidth = {read=GetCardWidth, nodefault};
	__property int CategoryIndent = {read=GetCategoryIndent, nodefault};
	__property int CategorySeparatorStyleIndex = {read=FCategorySeparatorStyleIndex, nodefault};
	__property int CategorySeparatorWidth = {read=GetCategorySeparatorWidth, nodefault};
	__property int ColumnCardCount = {read=FColumnCardCount, write=FColumnCardCount, nodefault};
	__property TcxExportCard* ExportCards[int Index] = {read=GetExportCard};
	__property Cxgridcardview::TcxGridCardView* GridView = {read=GetGridView};
	__property int InterCardHorzSpace = {read=GetInterCardHorzSpace, nodefault};
	__property int InterCardVertSpace = {read=GetInterCardVertSpace, nodefault};
	__property bool IsHorizontalRows = {read=GetIsHorizontalRows, nodefault};
	__property bool IsSimpleLayout = {read=GetIsSimpleLayout, nodefault};
	__property bool KeepRowsSameHeight = {read=FKeepRowsSameHeight, nodefault};
	__property int LayerSeparatorStyleIndex = {read=FLayerSeparatorStyleIndex, nodefault};
	__property int LayerSeparatorWidth = {read=GetLayerSeparatorWidth, nodefault};
	__property TcxExportCardLayoutBuilder* LayoutBuilder = {read=FLayoutBuilder};
	__property Cxgridcardview::TcxGridCardViewLayoutDirection LayoutDirection = {read=GetLayoutDirection, nodefault};
	__property Cxgridcardview::TcxGridCardViewOptionsView* OptionsView = {read=GetOptionsView};
	__property int RowCardCount = {read=FRowCardCount, write=FRowCardCount, nodefault};
public:
	/* TcxGridCustomExport.Create */ inline __fastcall virtual TcxGridCardViewExport(System::UnicodeString AFileName, int AExportType, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgrid::TcxCustomGrid* AGrid, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridCustomExport(AFileName, AExportType, AGridView, AGrid, AViewInfo) { }
	/* TcxGridCustomExport.CreateFrom */ inline __fastcall virtual TcxGridCardViewExport(TcxGridCustomExport* AMasterExport, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridCustomExport(AMasterExport, AGridView, AViewInfo) { }
	/* TcxGridCustomExport.Destroy */ inline __fastcall virtual ~TcxGridCardViewExport(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewExport;
class PASCALIMPLEMENTATION TcxGridLayoutViewExport : public TcxGridTableViewExport
{
	typedef TcxGridTableViewExport inherited;
	
private:
	Cxgraphics::TcxViewParams FBackground;
	Cxgridlayoutview::TcxGridLayoutViewRecord* FCard;
	System::Types::TRect FCardBounds;
	Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo* FCardViewInfo;
	int __fastcall GetCardCount(void);
	Cxgridlayoutview::TcxGridLayoutViewRecord* __fastcall GetCard(int AIndex);
	Cxgridlayoutview::TcxGridLayoutContainer* __fastcall GetContainer(void);
	HIDESBASE Cxgridlayoutview::TcxGridLayoutView* __fastcall GetGridView(void);
	int __fastcall GetRecordHeight(void);
	int __fastcall GetRecordWidth(void);
	
protected:
	void __fastcall AddRectangle(const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall CreateExportCache(void);
	virtual void __fastcall CreateExportCells(void);
	void __fastcall ExportCardCaption(Cxgridlayoutview::TcxGridLayoutViewRecordCaptionViewInfo* AInfo);
	void __fastcall ExportEditItem(const System::Types::TRect &ABounds, Cxgridlayoutview::TcxGridLayoutViewItemViewInfo* AInfo);
	void __fastcall ExportLayoutItem(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AInfo);
	void __fastcall GetItemBordersInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* const AItemInfo, Cxgraphics::TcxBorders &ABorders, System::Uitypes::TColor &ABorderColor);
	Cxgraphics::TcxViewParams __fastcall GetParams(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemInfo);
	System::Types::TRect __fastcall GetRelativeBounds(const System::Types::TRect &AItemBounds);
	bool __fastcall HasCaption(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AInfo);
	__property Cxgraphics::TcxViewParams Background = {read=FBackground};
	__property Cxgridlayoutview::TcxGridLayoutViewRecord* Card = {read=FCard};
	__property System::Types::TRect CardBounds = {read=FCardBounds};
	__property Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo* CardViewInfo = {read=FCardViewInfo};
	
public:
	__property Cxgridlayoutview::TcxGridLayoutView* GridView = {read=GetGridView};
	__property int CardCount = {read=GetCardCount, nodefault};
	__property Cxgridlayoutview::TcxGridLayoutViewRecord* Cards[int Index] = {read=GetCard};
	__property Cxgridlayoutview::TcxGridLayoutContainer* Container = {read=GetContainer};
	__property int RecordHeight = {read=GetRecordHeight, nodefault};
	__property int RecordWidth = {read=GetRecordWidth, nodefault};
public:
	/* TcxGridCustomExport.Create */ inline __fastcall virtual TcxGridLayoutViewExport(System::UnicodeString AFileName, int AExportType, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgrid::TcxCustomGrid* AGrid, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridTableViewExport(AFileName, AExportType, AGridView, AGrid, AViewInfo) { }
	/* TcxGridCustomExport.CreateFrom */ inline __fastcall virtual TcxGridLayoutViewExport(TcxGridCustomExport* AMasterExport, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridTableViewExport(AMasterExport, AGridView, AViewInfo) { }
	/* TcxGridCustomExport.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewExport(void) { }
	
};


class DELPHICLASS TcxGridChartViewExport;
class PASCALIMPLEMENTATION TcxGridChartViewExport : public TcxGridCustomExport
{
	typedef TcxGridCustomExport inherited;
	
private:
	Cxgridchartview::TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall CreateExportCache(void);
	virtual void __fastcall ExportAsGraphic(void);
	virtual void __fastcall ExportAsData(void);
	
public:
	__property Cxgridchartview::TcxGridChartView* GridView = {read=GetGridView};
public:
	/* TcxGridCustomExport.Create */ inline __fastcall virtual TcxGridChartViewExport(System::UnicodeString AFileName, int AExportType, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgrid::TcxCustomGrid* AGrid, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridCustomExport(AFileName, AExportType, AGridView, AGrid, AViewInfo) { }
	/* TcxGridCustomExport.CreateFrom */ inline __fastcall virtual TcxGridChartViewExport(TcxGridCustomExport* AMasterExport, Cxgridcustomview::TcxCustomGridView* AGridView, Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : TcxGridCustomExport(AMasterExport, AGridView, AViewInfo) { }
	/* TcxGridCustomExport.Destroy */ inline __fastcall virtual ~TcxGridChartViewExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int cxGridFooterCellIndent;
extern PACKAGE bool ExportImagesAsGraphic;
extern PACKAGE void __fastcall ExportGridToFile(System::UnicodeString AFileName, int AExportType, Cxgrid::TcxGrid* AGrid, bool AExpand, bool ASaveAll, bool AUseNativeFormat, const System::UnicodeString ASeparator, const System::UnicodeString ABeginString, const System::UnicodeString AEndString, const System::UnicodeString AFileExt);
extern PACKAGE void __fastcall ExportGridToHTML(const System::UnicodeString AFileName, Cxgrid::TcxGrid* AGrid, bool AExpand = true, bool ASaveAll = true, const System::UnicodeString AFileExt = L"html");
extern PACKAGE void __fastcall ExportGridToXML(const System::UnicodeString AFileName, Cxgrid::TcxGrid* AGrid, bool AExpand = true, bool ASaveAll = true, const System::UnicodeString AFileExt = L"xml");
extern PACKAGE void __fastcall ExportGridToExcel(const System::UnicodeString AFileName, Cxgrid::TcxGrid* AGrid, bool AExpand = true, bool ASaveAll = true, bool AUseNativeFormat = true, const System::UnicodeString AFileExt = L"xls");
extern PACKAGE void __fastcall ExportGridToText(const System::UnicodeString AFileName, Cxgrid::TcxGrid* AGrid, bool AExpand = true, bool ASaveAll = true, const System::UnicodeString ASeparator = System::UnicodeString(), const System::UnicodeString ABeginString = System::UnicodeString(), const System::UnicodeString AEndString = System::UnicodeString(), const System::UnicodeString AFileExt = L"txt");
extern PACKAGE void __fastcall ExportGridToXLSX(const System::UnicodeString AFileName, Cxgrid::TcxGrid* AGrid, bool AExpand = true, bool ASaveAll = true, bool AUseNativeFormat = true, const System::UnicodeString AFileExt = L"xlsx");
}	/* namespace Cxgridexportlink */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDEXPORTLINK)
using namespace Cxgridexportlink;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridexportlinkHPP
