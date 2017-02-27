// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxVGridLnk.pas' rev: 24.00 (Win32)

#ifndef DxpscxvgridlnkHPP
#define DxpscxvgridlnkHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxDBVGrid.hpp>	// Pascal unit
#include <cxOI.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxvgridlnk
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomVerticalGridAdapterClass;

typedef System::TMetaClass* TcxCustomVerticalGridReportLinkBuilderClass;

typedef System::TMetaClass* TcxCustomVerticalGridReportLinkFormatterClass;

typedef System::TMetaClass* TcxVerticalGridCustomRowHelperClass;

typedef int TcxVerticalGridAttributeID;

struct DECLSPEC_DRECORD TcxVerticalGridCellCustomDrawInfo
{
public:
	TcxVerticalGridAttributeID AttributeID;
	Cxvgrid::TcxCustomRow* Row;
	int CellIndex;
	int RecordIndex;
};


class DELPHICLASS TcxVerticalGridRowElementPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridRowElementPlace : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int Offset;
	int Width;
	void __fastcall Clear(void);
public:
	/* TObject.Create */ inline __fastcall TcxVerticalGridRowElementPlace(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridRowElementPlace(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxVerticalGridCustomRowPlaceClass;

class DELPHICLASS TcxVerticalGridCustomRowPlace;
class DELPHICLASS TcxCustomVerticalGridReportLinkFormatter;
class DELPHICLASS TcxCustomVerticalGridReportLink;
class DELPHICLASS TcxVerticalGridCustomRowHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCustomRowPlace : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomVerticalGridReportLinkFormatter* FFormatter;
	Cxvgrid::TcxCustomRow* FRow;
	int FWrapIndex;
	bool __fastcall GetHasHeader(void);
	int __fastcall GetIndentArea(void);
	int __fastcall GetInterRecordsSpace(void);
	int __fastcall GetItemCount(void);
	int __fastcall GetRecordCount(void);
	int __fastcall GetRecordWidth(int RecordIndex);
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetScreenCanvas(void);
	int __fastcall GetStartRecordIndex(void);
	int __fastcall GetStopRecordIndex(void);
	
protected:
	virtual void __fastcall AddDelimiters(TcxCustomVerticalGridReportLink* AReportLink);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculatedHeaderWidth(void);
	virtual int __fastcall CalculatedMinHeight(void);
	virtual int __fastcall CalculatedMinWidth(void);
	virtual int __fastcall CalculatedRecordWidth(int ARecordIndex);
	int __fastcall CalculatedTextPatternHeight(Vcl::Graphics::TFont* AFont);
	int __fastcall CalculatedTextWidth(const System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
	virtual void __fastcall Clear(void);
	virtual int __fastcall GetHeaderAvailableWidth(void);
	virtual int __fastcall GetValueAvailableWidth(int RecordIndex);
	virtual Cxvgrid::TcxCustomRow* __fastcall Row(void)/* overload */;
	virtual TcxVerticalGridCustomRowHelper* __fastcall RowHelper(void)/* overload */;
	__property TcxCustomVerticalGridReportLinkFormatter* Formatter = {read=FFormatter};
	__property bool HasHeader = {read=GetHasHeader, nodefault};
	__property int HeaderAvailableWidth = {read=GetHeaderAvailableWidth, nodefault};
	__property int InterRecordsSpace = {read=GetInterRecordsSpace, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RecordWidths[int RecordIndex] = {read=GetRecordWidth};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=GetScreenCanvas};
	__property int StartRecordIndex = {read=GetStartRecordIndex, nodefault};
	__property int StopRecordIndex = {read=GetStopRecordIndex, nodefault};
	__property int ValueAvailableWidths[int RecordIndex] = {read=GetValueAvailableWidth};
	
public:
	__fastcall virtual TcxVerticalGridCustomRowPlace(TcxCustomVerticalGridReportLinkFormatter* AFormatter, Cxvgrid::TcxCustomRow* ARow, int AWrapIndex);
	__property int IndentArea = {read=GetIndentArea, nodefault};
	__property int WrapIndex = {read=FWrapIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridCustomRowPlace(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridCategoryRowPlace;
class DELPHICLASS TcxVerticalGridCategoryRowHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCategoryRowPlace : public TcxVerticalGridCustomRowPlace
{
	typedef TcxVerticalGridCustomRowPlace inherited;
	
private:
	TcxVerticalGridRowElementPlace* FPlace;
	System::UnicodeString __fastcall GetCaption(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	int __fastcall GetOffset(void);
	int __fastcall GetWidth(void);
	
protected:
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculatedHeaderWidth(void);
	virtual int __fastcall CalculatedMinHeight(void);
	virtual int __fastcall CalculatedMinWidth(void);
	HIDESBASE Cxvgrid::TcxCategoryRow* __fastcall Row(void)/* overload */;
	HIDESBASE TcxVerticalGridCategoryRowHelper* __fastcall RowHelper(void)/* overload */;
	__property System::UnicodeString Caption = {read=GetCaption};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	
public:
	__fastcall virtual TcxVerticalGridCategoryRowPlace(TcxCustomVerticalGridReportLinkFormatter* AFormatter, Cxvgrid::TcxCustomRow* ARow, int AWrapIndex);
	__fastcall virtual ~TcxVerticalGridCategoryRowPlace(void);
	__property int Offset = {read=GetOffset, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridCustomEditorRowPlace;
class DELPHICLASS TcxVerticalGridCustomEditorRowHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCustomEditorRowPlace : public TcxVerticalGridCustomRowPlace
{
	typedef TcxVerticalGridCustomRowPlace inherited;
	
private:
	TcxVerticalGridRowElementPlace* FHeaderPlace;
	System::Classes::TList* FValuePlaces;
	Vcl::Graphics::TFont* __fastcall GetHeaderFont(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperty(int RecordIndex);
	Vcl::Graphics::TFont* __fastcall GetValueFont(int RecordIndex);
	TcxVerticalGridRowElementPlace* __fastcall GetValuePlace(int RecordIndex);
	int __fastcall GetValuePlaceCount(void);
	System::Variant __fastcall GetValue(int RecordIndex);
	int __fastcall GetValuesOffset(void);
	
protected:
	virtual void __fastcall AddDelimiters(TcxCustomVerticalGridReportLink* AReportLink);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculatedHeaderWidth(void);
	virtual int __fastcall CalculatedMinHeight(void);
	virtual int __fastcall CalculatedRecordWidth(int ARecordIndex);
	virtual void __fastcall CalculateHeaderPlace(void);
	virtual void __fastcall CalculateValuePlaces(void);
	virtual void __fastcall Clear(void);
	void __fastcall ClearValuePlaces(void);
	void __fastcall CreateValuePlaces(void);
	void __fastcall FreeAndNilValuePlaces(void);
	bool __fastcall DoesItemParticipateInBestFitCalculation(int ARecordIndex);
	int __fastcall MeasureWidth(int ARecordIndex);
	HIDESBASE Cxvgrid::TcxCustomEditorRow* __fastcall Row(void)/* overload */;
	HIDESBASE TcxVerticalGridCustomEditorRowHelper* __fastcall RowHelper(void)/* overload */;
	__property Vcl::Graphics::TFont* HeaderFont = {read=GetHeaderFont};
	__property Cxedit::TcxCustomEditProperties* Properties[int RecordIndex] = {read=GetProperty};
	__property Vcl::Graphics::TFont* ValueFonts[int RecordIndex] = {read=GetValueFont};
	__property System::Variant Values[int RecordIndex] = {read=GetValue};
	__property int ValuesOffset = {read=GetValuesOffset, nodefault};
	
public:
	__fastcall virtual TcxVerticalGridCustomEditorRowPlace(TcxCustomVerticalGridReportLinkFormatter* AFormatter, Cxvgrid::TcxCustomRow* ARow, int AWrapIndex);
	__fastcall virtual ~TcxVerticalGridCustomEditorRowPlace(void);
	__property TcxVerticalGridRowElementPlace* HeaderPlace = {read=FHeaderPlace};
	__property int ValuePlaceCount = {read=GetValuePlaceCount, nodefault};
	__property TcxVerticalGridRowElementPlace* ValuePlaces[int RecordIndex] = {read=GetValuePlace};
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridCustomMultiEditorRowPlace;
class DELPHICLASS TcxVerticalGridCustomMultiEditorRowHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCustomMultiEditorRowPlace : public TcxVerticalGridCustomRowPlace
{
	typedef TcxVerticalGridCustomRowPlace inherited;
	
private:
	System::Classes::TList* FHeaderPlaces;
	System::Classes::TList* FHeaderSeparatorPlaces;
	System::Classes::TList* FValuePlaces;
	System::Classes::TList* FValueSeparatorPlaces;
	bool __fastcall GetHasHeaderSeparators(void);
	bool __fastcall GetHasValueSeparators(void);
	Vcl::Graphics::TFont* __fastcall GetHeaderFont(int CellIndex);
	TcxVerticalGridRowElementPlace* __fastcall GetHeaderPlace(int CellIndex);
	int __fastcall GetHeaderPlaceCount(void);
	int __fastcall GetHeaderSeparatorCount(void);
	TcxVerticalGridRowElementPlace* __fastcall GetHeaderSeparatorPlace(int CellIndex);
	int __fastcall GetHeaderSeparatorPlaceCount(void);
	int __fastcall GetHeaderSeparatorsArea(void);
	Vcl::Graphics::TFont* __fastcall GetHeaderSeparatorsFont(int CellIndex);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperty(int CellIndex, int RecordIndex);
	System::Variant __fastcall GetValue(int CellIndex, int RecordIndex);
	int __fastcall GetValueFlatIndex(int CellIndex, int RecordIndex);
	Vcl::Graphics::TFont* __fastcall GetValueFont(int CellIndex, int RecordIndex);
	TcxVerticalGridRowElementPlace* __fastcall GetValuePlace(int CellIndex, int RecordIndex);
	int __fastcall GetValuePlaceCount(void);
	int __fastcall GetValueSeparatorCount(void);
	int __fastcall GetValueSeparatorFlatIndex(int CellIndex, int RecordIndex);
	TcxVerticalGridRowElementPlace* __fastcall GetValueSeparatorPlace(int CellIndex, int RecordIndex);
	int __fastcall GetValueSeparatorPlaceCount(void);
	int __fastcall GetValueSeparatorsArea(int RecordIndex);
	Vcl::Graphics::TFont* __fastcall GetValueSeparatorsFont(int CellIndex, int RecordIndex);
	int __fastcall GetValuesOffset(void);
	
protected:
	virtual void __fastcall AddDelimiters(TcxCustomVerticalGridReportLink* AReportLink);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculatedHeaderWidth(void);
	virtual int __fastcall CalculatedMinHeight(void);
	virtual int __fastcall CalculatedRecordWidth(int ARecordIndex);
	void __fastcall CalculateHeaderPartWidths(void);
	virtual void __fastcall CalculateHeaderPlaces(void);
	virtual void __fastcall CalculateHeaderSeparatorPlaces(void);
	virtual void __fastcall CalculateHeaderSeparatorWidths(void);
	void __fastcall CalculatePartWidths(Cxclasses::TcxAutoWidthObject* AnAutoWidthObject, int AnAvailableWidth);
	void __fastcall CalculateValuePartWidths(void);
	virtual void __fastcall CalculateValuePlaces(void);
	virtual void __fastcall CalculateValueSeparatorPlaces(void);
	virtual void __fastcall CalculateValueSeparatorWidths(void);
	virtual void __fastcall Clear(void);
	virtual int __fastcall GetHeaderAvailableWidth(void);
	virtual int __fastcall GetValueAvailableWidth(int RecordIndex);
	void __fastcall ClearPlaces(void);
	void __fastcall CreatePlaces(void);
	void __fastcall FreeAndNilPlaces(void);
	bool __fastcall DoesItemParticipateInBestFitCalculation(int ACellIndex, int ARecordIndex);
	int __fastcall MeasureWidth(int ACellIndex, int ARecordIndex);
	HIDESBASE Cxvgrid::TcxCustomMultiEditorRow* __fastcall Row(void)/* overload */;
	HIDESBASE TcxVerticalGridCustomMultiEditorRowHelper* __fastcall RowHelper(void)/* overload */;
	__property bool HasHeaderSeparators = {read=GetHasHeaderSeparators, nodefault};
	__property bool HasValueSeparators = {read=GetHasValueSeparators, nodefault};
	__property Vcl::Graphics::TFont* HeaderFonts[int CellIndex] = {read=GetHeaderFont};
	__property int HeaderSeparatorCount = {read=GetHeaderSeparatorCount, nodefault};
	__property int HeaderSeparatorsArea = {read=GetHeaderSeparatorsArea, nodefault};
	__property Vcl::Graphics::TFont* HeaderSeparatorsFonts[int Index] = {read=GetHeaderSeparatorsFont};
	__property Cxedit::TcxCustomEditProperties* Properties[int CellIndex][int RecordIndex] = {read=GetProperty};
	__property int ValueFlatIndexes[int CellIndex][int RecordIndex] = {read=GetValueFlatIndex};
	__property Vcl::Graphics::TFont* ValueFonts[int CellIndex][int RecordIndex] = {read=GetValueFont};
	__property System::Variant Values[int CellIndex][int RecordIndex] = {read=GetValue};
	__property int ValueSeparatorCount = {read=GetValueSeparatorCount, nodefault};
	__property int ValueSeparatorFlatIndexes[int CellIndex][int RecordIndex] = {read=GetValueSeparatorFlatIndex};
	__property int ValueSeparatorsAreas[int RecordIndex] = {read=GetValueSeparatorsArea};
	__property Vcl::Graphics::TFont* ValueSeparatorsFonts[int CellIndex][int RecordIndex] = {read=GetValueSeparatorsFont};
	__property int ValuesOffset = {read=GetValuesOffset, nodefault};
	
public:
	__fastcall virtual TcxVerticalGridCustomMultiEditorRowPlace(TcxCustomVerticalGridReportLinkFormatter* AFormatter, Cxvgrid::TcxCustomRow* ARow, int AWrapIndex);
	__fastcall virtual ~TcxVerticalGridCustomMultiEditorRowPlace(void);
	__property int HeaderPlaceCount = {read=GetHeaderPlaceCount, nodefault};
	__property TcxVerticalGridRowElementPlace* HeaderPlaces[int CellIndex] = {read=GetHeaderPlace};
	__property int HeaderSeparatorPlaceCount = {read=GetHeaderSeparatorPlaceCount, nodefault};
	__property TcxVerticalGridRowElementPlace* HeaderSeparatorPlaces[int CellIndex] = {read=GetHeaderSeparatorPlace};
	__property int ValuePlaceCount = {read=GetValuePlaceCount, nodefault};
	__property TcxVerticalGridRowElementPlace* ValuePlaces[int CellIndex][int RecordIndex] = {read=GetValuePlace};
	__property int ValueSeparatorPlaceCount = {read=GetValueSeparatorPlaceCount, nodefault};
	__property TcxVerticalGridRowElementPlace* ValueSeparatorPlaces[int CellIndex][int RecordIndex] = {read=GetValueSeparatorPlace};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxVerticalGridReportLinkCustomElementProducerClass;

class DELPHICLASS TcxVerticalGridReportLinkCustomElementProducer;
class DELPHICLASS TcxCustomVerticalGridReportLinkBuilder;
class DELPHICLASS TcxVerticalGridHostInfo;
class DELPHICLASS TcxCustomVerticalGridAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkCustomElementProducer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomVerticalGridReportLinkBuilder* FBuilder;
	Dxpscore::TdxReportCell* FHost;
	Dxpscore::TdxReportCell* FRow;
	int FRowHeight;
	int FWrapIndex;
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetScreenCanvas(void);
	int __fastcall GetRowWidth(void);
	
protected:
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateRowHost(TcxVerticalGridHostInfo* AHostInfo);
	virtual void __fastcall InitializeRow(void);
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=GetScreenCanvas};
	__property int WrapIndex = {read=FWrapIndex, nodefault};
	
public:
	__fastcall virtual TcxVerticalGridReportLinkCustomElementProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	virtual TcxCustomVerticalGridAdapter* __fastcall Adapter(void)/* overload */;
	virtual TcxCustomVerticalGridReportLinkBuilder* __fastcall Builder(void)/* overload */;
	virtual TcxCustomVerticalGridReportLinkFormatter* __fastcall Formatter(void)/* overload */;
	virtual Dxpscore::TdxReportCell* __fastcall Produce(TcxVerticalGridHostInfo* AHostInfo, int AWrapIndex);
	__property Dxpscore::TdxReportCell* Host = {read=FHost};
	__property Dxpscore::TdxReportCell* Row = {read=FRow};
	__property int RowHeight = {read=FRowHeight, write=FRowHeight, nodefault};
	__property int RowWidth = {read=GetRowWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkCustomElementProducer(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxVerticalGridReportLinkWrapSeparatorProducerClass;

class DELPHICLASS TcxVerticalGridReportLinkWrapSeparatorProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkWrapSeparatorProducer : public TcxVerticalGridReportLinkCustomElementProducer
{
	typedef TcxVerticalGridReportLinkCustomElementProducer inherited;
	
private:
	Dxpscore::TdxReportCellString* FSeparator;
	System::Types::TRect __fastcall GetSeparatorBounds(void);
	
protected:
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateSeparator(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeSeparator(void);
	
public:
	__property Dxpscore::TdxReportCellString* Separator = {read=FSeparator};
	__property System::Types::TRect SeparatorBounds = {read=GetSeparatorBounds};
public:
	/* TcxVerticalGridReportLinkCustomElementProducer.Create */ inline __fastcall virtual TcxVerticalGridReportLinkWrapSeparatorProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxVerticalGridReportLinkCustomElementProducer(ABuilder) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkWrapSeparatorProducer(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxVerticalGridReportLinkCustomRowProducerClass;

class DELPHICLASS TcxVerticalGridReportLinkCustomRowProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkCustomRowProducer : public TcxVerticalGridReportLinkCustomElementProducer
{
	typedef TcxVerticalGridReportLinkCustomElementProducer inherited;
	
private:
	Cxvgrid::TcxCustomRow* FGridRow;
	System::Classes::TList* FIndents;
	Dxpscore::TdxReportCellExpandButton* __fastcall GetIndent(int Index);
	System::Types::TRect __fastcall GetIndentBounds(int Index);
	int __fastcall GetIndentCount(void);
	int __fastcall GetIndentWidth(void);
	int __fastcall GetItemCount(void);
	int __fastcall GetRecordCount(void);
	int __fastcall GetStartRecordIndex(void);
	int __fastcall GetStopRecordIndex(void);
	
protected:
	virtual void __fastcall CalculateRowAutoHeight(void);
	virtual void __fastcall CalculateRowHeight(void);
	virtual void __fastcall ClearItems(void);
	virtual void __fastcall CreateRow(void);
	Dxpscore::TdxReportCellExpandButton* __fastcall CreateRowIndent(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRowIndents(Dxpscore::TdxReportCell* AParent);
	virtual bool __fastcall DoesItemParticipateInRowAutoHeightCalculation(Dxpscore::TAbstractdxReportCellData* AnItem);
	virtual void __fastcall FixupRowDataHeight(void);
	virtual void __fastcall FixupRowHeight(void);
	virtual void __fastcall FixupRowItselfHeight(void);
	virtual void __fastcall InitializeRow(void);
	virtual void __fastcall InitializeRowIndent(Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex);
	virtual bool __fastcall GetAutoHeight(void);
	virtual bool __fastcall GetHasIndents(void);
	virtual int __fastcall GetLineHeight(void);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	
public:
	__fastcall virtual TcxVerticalGridReportLinkCustomRowProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxVerticalGridReportLinkCustomRowProducer(void);
	virtual Cxvgrid::TcxCustomRow* __fastcall GridRow(void)/* overload */;
	virtual TcxVerticalGridCustomRowHelper* __fastcall GridRowHelper(void)/* overload */;
	virtual TcxVerticalGridCustomRowPlace* __fastcall GridRowPlace(void)/* overload */;
	HIDESBASE Dxpscore::TdxReportCell* __fastcall Produce(TcxVerticalGridHostInfo* AHostInfo, Cxvgrid::TcxCustomRow* AGridRow, int AWrapIndex)/* overload */;
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property bool HasIndents = {read=GetHasIndents, nodefault};
	__property System::Types::TRect IndentBounds[int Index] = {read=GetIndentBounds};
	__property int IndentCount = {read=GetIndentCount, nodefault};
	__property Dxpscore::TdxReportCellExpandButton* Indents[int Index] = {read=GetIndent};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property int LineHeight = {read=GetLineHeight, nodefault};
	__property int StartRecordIndex = {read=GetStartRecordIndex, nodefault};
	__property int StopRecordIndex = {read=GetStopRecordIndex, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkCategoryRowProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkCategoryRowProducer : public TcxVerticalGridReportLinkCustomRowProducer
{
	typedef TcxVerticalGridReportLinkCustomRowProducer inherited;
	
private:
	System::Types::TRect __fastcall GetCategoryBounds(void);
	
protected:
	virtual void __fastcall CreateCategoryRow(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	
public:
	HIDESBASE Cxvgrid::TcxCategoryRow* __fastcall GridRow(void)/* overload */;
	HIDESBASE TcxVerticalGridCategoryRowHelper* __fastcall GridRowHelper(void)/* overload */;
	HIDESBASE TcxVerticalGridCategoryRowPlace* __fastcall GridRowPlace(void)/* overload */;
	__property System::Types::TRect CategoryBounds = {read=GetCategoryBounds};
public:
	/* TcxVerticalGridReportLinkCustomRowProducer.Create */ inline __fastcall virtual TcxVerticalGridReportLinkCategoryRowProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxVerticalGridReportLinkCustomRowProducer(ABuilder) { }
	/* TcxVerticalGridReportLinkCustomRowProducer.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkCategoryRowProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkCustomEditableRowProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkCustomEditableRowProducer : public TcxVerticalGridReportLinkCustomRowProducer
{
	typedef TcxVerticalGridReportLinkCustomRowProducer inherited;
	
private:
	System::Classes::TList* FHeaders;
	System::Classes::TList* FValues;
	Dxpscore::TdxReportCellImage* __fastcall GetHeader(int Index);
	int __fastcall GetHeaderCount(void);
	Dxpscore::TAbstractdxReportCellData* __fastcall GetValue(int Index);
	int __fastcall GetValueCount(void);
	
protected:
	virtual void __fastcall ClearItems(void);
	Dxpscore::TdxReportCellImage* __fastcall CreateHeaderItem(Dxpscore::TdxReportCell* AParent, int ACellIndex);
	Dxpscore::TAbstractdxReportCellData* __fastcall CreateValueItem(Dxpscore::TdxReportCell* AParent, int ACellIndex, int ARecordIndex);
	virtual void __fastcall DoInitializeHeader(Dxpscore::TdxReportCellImage* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeValue(Dxpscore::TAbstractdxReportCellData* AnItem, int ACellIndex, int ARecordIndex);
	virtual bool __fastcall DoesItemParticipateInRowAutoHeightCalculation(Dxpscore::TAbstractdxReportCellData* AnItem);
	__property int HeaderCount = {read=GetHeaderCount, nodefault};
	__property Dxpscore::TdxReportCellImage* Headers[int Index] = {read=GetHeader};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property Dxpscore::TAbstractdxReportCellData* Values[int Index] = {read=GetValue};
	
public:
	__fastcall virtual TcxVerticalGridReportLinkCustomEditableRowProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxVerticalGridReportLinkCustomEditableRowProducer(void);
	__property RecordCount;
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkCustomEditorRowProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkCustomEditorRowProducer : public TcxVerticalGridReportLinkCustomEditableRowProducer
{
	typedef TcxVerticalGridReportLinkCustomEditableRowProducer inherited;
	
private:
	bool __fastcall GetHasHeader(void);
	HIDESBASE Dxpscore::TdxReportCellImage* __fastcall GetHeader(void);
	System::Types::TRect __fastcall GetHeaderBounds(void);
	System::Types::TRect __fastcall GetValueBounds(int Index);
	
protected:
	virtual void __fastcall CreateHeader(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateValues(Dxpscore::TdxReportCell* AParent);
	__property bool HasHeader = {read=GetHasHeader, nodefault};
	__property System::Types::TRect HeaderBounds = {read=GetHeaderBounds};
	__property System::Types::TRect ValueBounds[int Index] = {read=GetValueBounds};
	
public:
	HIDESBASE Cxvgrid::TcxCustomEditorRow* __fastcall GridRow(void)/* overload */;
	HIDESBASE TcxVerticalGridCustomEditorRowHelper* __fastcall GridRowHelper(void)/* overload */;
	HIDESBASE TcxVerticalGridCustomEditorRowPlace* __fastcall GridRowPlace(void)/* overload */;
	__property Dxpscore::TdxReportCellImage* Header = {read=GetHeader};
	__property ValueCount;
	__property Values;
public:
	/* TcxVerticalGridReportLinkCustomEditableRowProducer.Create */ inline __fastcall virtual TcxVerticalGridReportLinkCustomEditorRowProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxVerticalGridReportLinkCustomEditableRowProducer(ABuilder) { }
	/* TcxVerticalGridReportLinkCustomEditableRowProducer.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkCustomEditorRowProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkCustomMultiEditorRowProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkCustomMultiEditorRowProducer : public TcxVerticalGridReportLinkCustomEditableRowProducer
{
	typedef TcxVerticalGridReportLinkCustomEditableRowProducer inherited;
	
private:
	System::Classes::TList* FHeaderSeparators;
	System::Classes::TList* FValueSeparators;
	bool __fastcall GetHasHeaderSeparators(void);
	bool __fastcall GetHasValueSeparators(void);
	System::Types::TRect __fastcall GetHeaderBounds(int Index);
	Dxpscore::TdxReportCellString* __fastcall GetHeaderSeparator(int Index);
	System::Types::TRect __fastcall GetHeaderSeparatorBounds(int Index);
	int __fastcall GetHeaderSeparatorCount(void);
	System::UnicodeString __fastcall GetHeaderSeparatorText(int Index);
	HIDESBASE Dxpscore::TAbstractdxReportCellData* __fastcall GetValue(int CellIndex, int RecordIndex);
	System::Types::TRect __fastcall GetValueBounds(int CellIndex, int RecordIndex);
	Dxpscore::TdxReportCellString* __fastcall GetValueSeparator(int Index);
	System::Types::TRect __fastcall GetValueSeparatorBounds(int Index, int RecordIndex);
	int __fastcall GetValueSeparatorCount(void);
	System::UnicodeString __fastcall GetValueSeparatorText(int Index);
	
protected:
	virtual void __fastcall ClearItems(void);
	virtual void __fastcall CreateRow(void);
	virtual void __fastcall CreateHeaders(Dxpscore::TdxReportCell* AParent);
	Dxpscore::TdxReportCellString* __fastcall CreateHeaderSeparator(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateHeaderSeparators(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateValues(Dxpscore::TdxReportCell* AParent);
	Dxpscore::TdxReportCellString* __fastcall CreateValueSeparator(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall CreateValueSeparators(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall DoInitializeHeaderSeparator(Dxpscore::TdxReportCellString* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeValueSeparator(Dxpscore::TdxReportCellString* AnItem, int AnIndex, int ARecordIndex);
	__property bool HasHeaderSeparators = {read=GetHasHeaderSeparators, nodefault};
	__property bool HasValueSeparators = {read=GetHasValueSeparators, nodefault};
	__property System::Types::TRect HeaderBounds[int Index] = {read=GetHeaderBounds};
	__property System::Types::TRect HeaderSeparatorBounds[int Index] = {read=GetHeaderSeparatorBounds};
	__property System::UnicodeString HeaderSeparatorTexts[int Index] = {read=GetHeaderSeparatorText};
	__property System::Types::TRect ValueSeparatorBounds[int Index][int RecordIndex] = {read=GetValueSeparatorBounds};
	__property System::Types::TRect ValueBounds[int CellIndex][int RecordIndex] = {read=GetValueBounds};
	__property System::UnicodeString ValueSeparatorTexts[int Index] = {read=GetValueSeparatorText};
	
public:
	__fastcall virtual TcxVerticalGridReportLinkCustomMultiEditorRowProducer(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxVerticalGridReportLinkCustomMultiEditorRowProducer(void);
	HIDESBASE Cxvgrid::TcxCustomMultiEditorRow* __fastcall GridRow(void)/* overload */;
	HIDESBASE TcxVerticalGridCustomMultiEditorRowHelper* __fastcall GridRowHelper(void)/* overload */;
	HIDESBASE TcxVerticalGridCustomMultiEditorRowPlace* __fastcall GridRowPlace(void)/* overload */;
	__property HeaderCount;
	__property Headers;
	__property int HeaderSeparatorCount = {read=GetHeaderSeparatorCount, nodefault};
	__property Dxpscore::TdxReportCellString* HeaderSeparators[int Index] = {read=GetHeaderSeparator};
	__property ValueCount;
	__property Dxpscore::TAbstractdxReportCellData* Values[int CellIndex][int RecordIndex] = {read=GetValue};
	__property int ValueSeparatorCount = {read=GetValueSeparatorCount, nodefault};
	__property Dxpscore::TdxReportCellString* ValueSeparators[int Index] = {read=GetValueSeparator};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCustomRowHelper : public Dxbase::TdxCustomClassMapItem
{
	typedef Dxbase::TdxCustomClassMapItem inherited;
	
private:
	TcxCustomVerticalGridAdapter* FAdapter;
	Cxvgrid::TcxCustomRow* FRow;
	
protected:
	virtual TcxCustomVerticalGridAdapter* __fastcall Adapter(void)/* overload */;
	virtual System::UnicodeString __fastcall GetDisplayText(int Index, int RecordIndex);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(int Index, int RecordIndex);
	virtual bool __fastcall GetHasHeaderImage(int Index);
	virtual bool __fastcall GetHasHeaderSeparators(void);
	virtual bool __fastcall GetHasValueSeparators(void);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetHeaderAlignmentHorz(int Index);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetHeaderAlignmentVert(int Index);
	virtual System::UnicodeString __fastcall GetHeaderCaption(int Index);
	virtual int __fastcall GetImageIndex(int Index);
	virtual int __fastcall GetIndentCount(void);
	virtual int __fastcall GetItemCount(void);
	virtual int __fastcall GetRecordMinWidth(void);
	virtual Cxvgrid::TcxCustomRowProperties* __fastcall GetRowProperties(int Index);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetSeparatorsAlignmentVert(void);
	virtual System::Variant __fastcall GetValue(int Index, int RecordIndex);
	__property bool HasHeaderSeparators = {read=GetHasHeaderSeparators, nodefault};
	__property bool HasValueSeparators = {read=GetHasValueSeparators, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int RecordMinWidth = {read=GetRecordMinWidth, nodefault};
	__property Cxclasses::TcxAlignmentVert SeparatorsAlignmentVert = {read=GetSeparatorsAlignmentVert, nodefault};
	
public:
	__fastcall virtual TcxVerticalGridCustomRowHelper(TcxCustomVerticalGridAdapter* AnAdapter);
	virtual void __fastcall Initialize(Cxvgrid::TcxCustomRow* ARow);
	__classmethod virtual System::TClass __fastcall PairClass();
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__classmethod virtual TcxVerticalGridReportLinkCustomRowProducerClass __fastcall ProducerClass();
	virtual Cxvgrid::TcxCustomRowProperties* __fastcall Properties(int Index)/* overload */;
	virtual Cxvgrid::TcxCustomRow* __fastcall Row(void)/* overload */;
	__classmethod virtual Cxvgrid::TcxCustomRowClass __fastcall RowClass();
	__classmethod virtual TcxVerticalGridCustomRowPlaceClass __fastcall RowPlaceClass();
	__property System::UnicodeString DisplayTexts[int Index][int RecordIndex] = {read=GetDisplayText};
	__property Cxedit::TcxCustomEditProperties* EditProperties[int Index][int RecordIndex] = {read=GetEditProperties};
	__property bool HasHeaderImages[int Index] = {read=GetHasHeaderImage};
	__property Cxdrawtextutils::TcxTextAlignX HeaderAlignmentHorzs[int Index] = {read=GetHeaderAlignmentHorz};
	__property Cxdrawtextutils::TcxTextAlignY HeaderAlignmentVerts[int Index] = {read=GetHeaderAlignmentVert};
	__property System::UnicodeString HeaderCaptions[int Index] = {read=GetHeaderCaption};
	__property int ImageIndexes[int Index] = {read=GetImageIndex};
	__property int IndentCount = {read=GetIndentCount, nodefault};
	__property System::Variant Values[int Index][int RecordIndex] = {read=GetValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridCustomRowHelper(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCategoryRowHelper : public TcxVerticalGridCustomRowHelper
{
	typedef TcxVerticalGridCustomRowHelper inherited;
	
protected:
	System::UnicodeString __fastcall GetCaption(void);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetHeaderAlignmentHorz(int Index);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetHeaderAlignmentVert(int Index);
	virtual System::UnicodeString __fastcall GetHeaderCaption(int Index);
	virtual int __fastcall GetImageIndex(int Index);
	
public:
	__classmethod virtual TcxVerticalGridReportLinkCustomRowProducerClass __fastcall ProducerClass();
	HIDESBASE Cxvgrid::TcxCaptionRowProperties* __fastcall Properties(int Index)/* overload */;
	HIDESBASE Cxvgrid::TcxCategoryRow* __fastcall Row(void)/* overload */;
	__classmethod virtual Cxvgrid::TcxCustomRowClass __fastcall RowClass();
	__classmethod virtual TcxVerticalGridCustomRowPlaceClass __fastcall RowPlaceClass();
	__property System::UnicodeString Caption = {read=GetCaption};
public:
	/* TcxVerticalGridCustomRowHelper.Create */ inline __fastcall virtual TcxVerticalGridCategoryRowHelper(TcxCustomVerticalGridAdapter* AnAdapter) : TcxVerticalGridCustomRowHelper(AnAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridCategoryRowHelper(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCustomEditorRowHelper : public TcxVerticalGridCustomRowHelper
{
	typedef TcxVerticalGridCustomRowHelper inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(int Index, int RecordIndex);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(int Index, int RecordIndex);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetHeaderAlignmentHorz(int Index);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetHeaderAlignmentVert(int Index);
	virtual System::UnicodeString __fastcall GetHeaderCaption(int Index);
	virtual int __fastcall GetImageIndex(int Index);
	virtual int __fastcall GetRecordMinWidth(void);
	virtual System::Variant __fastcall GetValue(int Index, int RecordIndex);
	
public:
	__classmethod virtual TcxVerticalGridReportLinkCustomRowProducerClass __fastcall ProducerClass();
	HIDESBASE Cxvgrid::TcxCustomEditorRowProperties* __fastcall Properties(int Index)/* overload */;
	HIDESBASE Cxvgrid::TcxCustomEditorRow* __fastcall Row(void)/* overload */;
	__classmethod virtual Cxvgrid::TcxCustomRowClass __fastcall RowClass();
	__classmethod virtual TcxVerticalGridCustomRowPlaceClass __fastcall RowPlaceClass();
	__property RecordMinWidth;
public:
	/* TcxVerticalGridCustomRowHelper.Create */ inline __fastcall virtual TcxVerticalGridCustomEditorRowHelper(TcxCustomVerticalGridAdapter* AnAdapter) : TcxVerticalGridCustomRowHelper(AnAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridCustomEditorRowHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridEditorRowHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridEditorRowHelper : public TcxVerticalGridCustomEditorRowHelper
{
	typedef TcxVerticalGridCustomEditorRowHelper inherited;
	
public:
	HIDESBASE Cxvgrid::TcxEditorRowProperties* __fastcall Properties(int Index)/* overload */;
	HIDESBASE Cxvgrid::TcxEditorRow* __fastcall Row(void)/* overload */;
	__classmethod virtual Cxvgrid::TcxCustomRowClass __fastcall RowClass();
public:
	/* TcxVerticalGridCustomRowHelper.Create */ inline __fastcall virtual TcxVerticalGridEditorRowHelper(TcxCustomVerticalGridAdapter* AnAdapter) : TcxVerticalGridCustomEditorRowHelper(AnAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridEditorRowHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridDBEditorRowHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridDBEditorRowHelper : public TcxVerticalGridCustomEditorRowHelper
{
	typedef TcxVerticalGridCustomEditorRowHelper inherited;
	
public:
	HIDESBASE Cxdbvgrid::TcxDBEditorRowProperties* __fastcall Properties(int Index)/* overload */;
	HIDESBASE Cxdbvgrid::TcxDBEditorRow* __fastcall Row(void)/* overload */;
	__classmethod virtual Cxvgrid::TcxCustomRowClass __fastcall RowClass();
public:
	/* TcxVerticalGridCustomRowHelper.Create */ inline __fastcall virtual TcxVerticalGridDBEditorRowHelper(TcxCustomVerticalGridAdapter* AnAdapter) : TcxVerticalGridCustomEditorRowHelper(AnAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridDBEditorRowHelper(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridCustomMultiEditorRowHelper : public TcxVerticalGridCustomRowHelper
{
	typedef TcxVerticalGridCustomRowHelper inherited;
	
private:
	int __fastcall GetHeaderSeparatorCount(void);
	System::UnicodeString __fastcall GetHeaderSeparatorText(int Index);
	int __fastcall GetValueSeparatorCount(void);
	System::UnicodeString __fastcall GetValueSeparatorText(int Index);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(int Index, int RecordIndex);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(int Index, int RecordIndex);
	virtual bool __fastcall GetHasHeaderSeparators(void);
	virtual bool __fastcall GetHasValueSeparators(void);
	virtual Cxdrawtextutils::TcxTextAlignX __fastcall GetHeaderAlignmentHorz(int Index);
	virtual Cxdrawtextutils::TcxTextAlignY __fastcall GetHeaderAlignmentVert(int Index);
	virtual System::UnicodeString __fastcall GetHeaderCaption(int Index);
	virtual int __fastcall GetImageIndex(int Index);
	virtual int __fastcall GetItemCount(void);
	virtual int __fastcall GetRecordMinWidth(void);
	virtual Cxvgrid::TcxCustomRowProperties* __fastcall GetRowProperties(int Index);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetSeparatorsAlignmentVert(void);
	virtual System::Variant __fastcall GetValue(int Index, int RecordIndex);
	
public:
	__classmethod virtual TcxVerticalGridReportLinkCustomRowProducerClass __fastcall ProducerClass();
	HIDESBASE Cxvgrid::TcxEditorRowItemProperties* __fastcall Properties(int Index)/* overload */;
	virtual Cxvgrid::TcxMultiEditorRowProperties* __fastcall RootProperties(void)/* overload */;
	HIDESBASE Cxvgrid::TcxCustomMultiEditorRow* __fastcall Row(void)/* overload */;
	__classmethod virtual Cxvgrid::TcxCustomRowClass __fastcall RowClass();
	__classmethod virtual TcxVerticalGridCustomRowPlaceClass __fastcall RowPlaceClass();
	__property HasHeaderSeparators;
	__property HasValueSeparators;
	__property int HeaderSeparatorCount = {read=GetHeaderSeparatorCount, nodefault};
	__property System::UnicodeString HeaderSeparatorTexts[int Index] = {read=GetHeaderSeparatorText};
	__property ItemCount;
	__property RecordMinWidth;
	__property SeparatorsAlignmentVert;
	__property int ValueSeparatorCount = {read=GetValueSeparatorCount, nodefault};
	__property System::UnicodeString ValueSeparatorTexts[int Index] = {read=GetValueSeparatorText};
public:
	/* TcxVerticalGridCustomRowHelper.Create */ inline __fastcall virtual TcxVerticalGridCustomMultiEditorRowHelper(TcxCustomVerticalGridAdapter* AnAdapter) : TcxVerticalGridCustomRowHelper(AnAdapter) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridCustomMultiEditorRowHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridRowHelperCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridRowHelperCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
public:
	TcxVerticalGridCustomRowHelper* operator[](Cxvgrid::TcxCustomRow* Row) { return Helpers[Row]; }
	
private:
	TcxCustomVerticalGridAdapter* FAdapter;
	TcxVerticalGridCustomRowHelper* __fastcall GetHelper(Cxvgrid::TcxCustomRow* Row);
	HIDESBASE TcxVerticalGridCustomRowHelper* __fastcall GetItem(int Index);
	
protected:
	int __fastcall IndexOf(Cxvgrid::TcxCustomRow* Row);
	__property TcxVerticalGridCustomRowHelper* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TcxVerticalGridRowHelperCache(TcxCustomVerticalGridAdapter* AnAdapter);
	__property TcxCustomVerticalGridAdapter* Adapter = {read=FAdapter};
	__property TcxVerticalGridCustomRowHelper* Helpers[Cxvgrid::TcxCustomRow* Row] = {read=GetHelper/*, default*/};
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TcxVerticalGridRowHelperCache(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkProducerCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkProducerCache : public Dxbase::TdxCustomCache
{
	typedef Dxbase::TdxCustomCache inherited;
	
public:
	TcxVerticalGridReportLinkCustomRowProducer* operator[](TcxVerticalGridReportLinkCustomRowProducerClass ProducerClass) { return Producers[ProducerClass]; }
	
private:
	TcxCustomVerticalGridReportLinkBuilder* FBuilder;
	HIDESBASE TcxVerticalGridReportLinkCustomRowProducer* __fastcall GetItem(int Index);
	TcxVerticalGridReportLinkCustomRowProducer* __fastcall GetProducer(TcxVerticalGridReportLinkCustomRowProducerClass ProducerClass);
	
protected:
	int __fastcall IndexOf(TcxVerticalGridReportLinkCustomRowProducerClass AProducerClass);
	__property TcxVerticalGridReportLinkCustomRowProducer* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TcxVerticalGridReportLinkProducerCache(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	__property TcxCustomVerticalGridReportLinkBuilder* Builder = {read=FBuilder};
	__property TcxVerticalGridReportLinkCustomRowProducer* Producers[TcxVerticalGridReportLinkCustomRowProducerClass ProducerClass] = {read=GetProducer/*, default*/};
public:
	/* TdxCustomCache.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkProducerCache(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomVerticalGridReportLinkBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomVerticalGridAdapter* FAdapter;
	TcxCustomVerticalGridReportLinkFormatter* FFormatter;
	TcxVerticalGridReportLinkProducerCache* FProducerCache;
	TcxCustomVerticalGridReportLink* FReportLink;
	System::Classes::TList* FReportRows;
	TcxVerticalGridReportLinkWrapSeparatorProducer* FWrapSeparatorProducer;
	int __fastcall GetAvailableSiteWidth(void);
	int __fastcall GetAvailableWidth(void);
	Dxpscore::TdxReportCell* __fastcall GetHost(void);
	Dxpscore::TdxReportCells* __fastcall GetReportCells(void);
	Dxpscore::TdxReportCell* __fastcall GetReportRow(int Index);
	int __fastcall GetReportRowCount(void);
	Cxvgrid::TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	void __fastcall AddReportRow(Dxpscore::TdxReportCell* ARow);
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual void __fastcall CreateRow(Cxvgrid::TcxCustomRow* ARow, int AWrapIndex);
	virtual void __fastcall CreateRows(void);
	virtual void __fastcall CreateWrapSeparator(int AWrapIndex);
	TcxVerticalGridReportLinkCustomRowProducer* __fastcall GetRowProducer(Cxvgrid::TcxCustomRow* ARow);
	virtual TcxVerticalGridReportLinkCustomRowProducerClass __fastcall GetRowProducerClass(Cxvgrid::TcxCustomRow* ARow);
	TcxVerticalGridReportLinkWrapSeparatorProducer* __fastcall GetWrapSeparatorProducer(int AWrapIndex);
	virtual TcxVerticalGridReportLinkWrapSeparatorProducerClass __fastcall GetWrapSeparatorProducerClass(void);
	bool __fastcall AreWrapSeparatorsNeeded(void);
	virtual void __fastcall DoBuild(void);
	bool __fastcall IsAborted(void);
	__property TcxVerticalGridReportLinkProducerCache* ProducerCache = {read=FProducerCache};
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=FReportLink};
	
public:
	__fastcall virtual TcxCustomVerticalGridReportLinkBuilder(TcxCustomVerticalGridReportLink* AReportLink);
	__fastcall virtual ~TcxCustomVerticalGridReportLinkBuilder(void);
	virtual void __fastcall Build(void);
	void __fastcall Progress(const double APercentDone);
	virtual TcxCustomVerticalGridAdapter* __fastcall Adapter(void)/* overload */;
	__classmethod virtual TcxCustomVerticalGridAdapterClass __fastcall AdapterClass();
	virtual TcxCustomVerticalGridReportLinkFormatter* __fastcall Formatter(void)/* overload */;
	__classmethod virtual TcxCustomVerticalGridReportLinkFormatterClass __fastcall FormatterClass();
	__property int AvailableSiteWidth = {read=GetAvailableSiteWidth, nodefault};
	__property int AvailableWidth = {read=GetAvailableWidth, nodefault};
	__property Dxpscore::TdxReportCell* Host = {read=GetHost};
	__property Dxpscore::TdxReportCells* ReportCells = {read=GetReportCells};
	__property int ReportRowCount = {read=GetReportRowCount, nodefault};
	__property Dxpscore::TdxReportCell* ReportRows[int Index] = {read=GetReportRow};
	__property Cxvgrid::TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkBuilderHandler;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkBuilderHandler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomVerticalGridReportLinkBuilder* FBuilder;
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	
public:
	__fastcall virtual TcxVerticalGridReportLinkBuilderHandler(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	virtual TcxCustomVerticalGridReportLinkBuilder* __fastcall Builder(void)/* overload */;
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkBuilderHandler(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomVerticalGridAdapter : public TcxVerticalGridReportLinkBuilderHandler
{
	typedef TcxVerticalGridReportLinkBuilderHandler inherited;
	
private:
	TcxVerticalGridRowHelperCache* FHelperCache;
	bool __fastcall GetCellAutoHeight(void);
	bool __fastcall GetCellEndEllipsis(void);
	bool __fastcall GetCellMultiline(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetDefaultRowHeight(void);
	int __fastcall GetFirstRecordIndex(void);
	System::Uitypes::TColor __fastcall GetGridLinesColor(void);
	int __fastcall GetHeaderAvailableWidth(Cxvgrid::TcxCustomRow* Row);
	int __fastcall GetHeaderMinWidth(void);
	int __fastcall GetHeaderWidth(void);
	TcxVerticalGridCustomRowHelper* __fastcall GetHelper(Cxvgrid::TcxCustomRow* Row);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	int __fastcall GetIndentArea(Cxvgrid::TcxCustomRow* Row);
	int __fastcall GetIndentCount(Cxvgrid::TcxCustomRow* Row);
	int __fastcall GetIndentWidth(void);
	bool __fastcall GetMakeSpaceForEmptyImage(void);
	Cxvgrid::TcxvgOptionsView* __fastcall GetOptionsView(void);
	Cxvgrid::TcxvgPaintStyle __fastcall GetPaintStyle(void);
	int __fastcall GetRecordCount(void);
	int __fastcall GetRecordMinWidth(int RecordIndex);
	int __fastcall GetRecordWidth(int RecordCount);
	Cxvgrid::TcxCustomRow* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowHeight(Cxvgrid::TcxCustomRow* Row);
	bool __fastcall GetShowHeaders(void);
	bool __fastcall GetShowHorzGridLines(void);
	bool __fastcall GetShowVertGridLines(void);
	Cxvgrid::TcxVerticalGridStyles* __fastcall GetStyles(void);
	int __fastcall GetValueMinWidth(void);
	Cxvgrid::TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual void __fastcall AfterBuilding(void);
	virtual void __fastcall BeforeBuilding(void);
	virtual int __fastcall GetInterRecordsSpace(void);
	virtual Cxvgrid::TcxvgLayoutStyle __fastcall GetLayoutStyle(void) = 0 ;
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	virtual Cxgraphics::TcxViewParams __fastcall GetCategoryViewParams(Cxvgrid::TcxCustomRow* ARow);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentViewParams(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	virtual Cxgraphics::TcxViewParams __fastcall GetHeaderViewParams(Cxvgrid::TcxCustomRow* ARow);
	virtual Cxgraphics::TcxViewParams __fastcall GetImageViewParams(Cxvgrid::TcxCustomRow* ARow);
	virtual Cxgraphics::TcxViewParams __fastcall GetIndentViewParams(Cxvgrid::TcxCustomRow* ARow);
	Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(int Index);
	int __fastcall GetRowIndentBackgroundBitmapIndex(Cxvgrid::TcxCustomRow* ARow, int Alevel);
	bool __fastcall HasBackgroundBitmap(int Index);
	void __fastcall FullExpand(void);
	int __fastcall GetImageHeight(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	int __fastcall GetImageWidth(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	Cxvgrid::TcxCustomRow* __fastcall GetRowParentAtLevel(Cxvgrid::TcxCustomRow* ARow, int ALevel);
	bool __fastcall HasCategoryRowAsParentAtLevel(Cxvgrid::TcxCustomRow* ARow, int ALevel, bool ACheckFollow);
	bool __fastcall HasRowImage(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	bool __fastcall IsRowLastChildAtLevel(Cxvgrid::TcxCustomRow* ARow, int ALevel);
	bool __fastcall IsRowVisible(Cxvgrid::TcxCustomRow* ARow);
	__property TcxVerticalGridCustomRowHelper* Helpers[Cxvgrid::TcxCustomRow* Row] = {read=GetHelper};
	__property Cxvgrid::TcxvgOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxvgrid::TcxVerticalGridStyles* Styles = {read=GetStyles};
	__property Cxvgrid::TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxCustomVerticalGridAdapter(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxCustomVerticalGridAdapter(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property bool CellAutoHeight = {read=GetCellAutoHeight, nodefault};
	__property bool CellEndEllipsis = {read=GetCellEndEllipsis, nodefault};
	__property bool CellMultiline = {read=GetCellMultiline, nodefault};
	__property int DefaultRowHeight = {read=GetDefaultRowHeight, nodefault};
	__property int FirstRecordIndex = {read=GetFirstRecordIndex, nodefault};
	__property System::Uitypes::TColor GridLinesColor = {read=GetGridLinesColor, nodefault};
	__property int HeaderAvailableWidths[Cxvgrid::TcxCustomRow* Row] = {read=GetHeaderAvailableWidth};
	__property int HeaderMinWidth = {read=GetHeaderMinWidth, nodefault};
	__property int HeaderWidth = {read=GetHeaderWidth, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property int IndentAreas[Cxvgrid::TcxCustomRow* Row] = {read=GetIndentArea};
	__property int IndentCounts[Cxvgrid::TcxCustomRow* Row] = {read=GetIndentCount};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property int InterRecordsSpace = {read=GetInterRecordsSpace, nodefault};
	__property Cxvgrid::TcxvgLayoutStyle LayoutStyle = {read=GetLayoutStyle, nodefault};
	__property bool MakeSpaceForEmptyImage = {read=GetMakeSpaceForEmptyImage, nodefault};
	__property Cxvgrid::TcxvgPaintStyle PaintStyle = {read=GetPaintStyle, nodefault};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RecordMinWidths[int RecordIndex] = {read=GetRecordMinWidth};
	__property int RecordWidth[int RecordCount] = {read=GetRecordWidth};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeights[Cxvgrid::TcxCustomRow* Row] = {read=GetRowHeight};
	__property Cxvgrid::TcxCustomRow* Rows[int Index] = {read=GetRow};
	__property bool ShowHeaders = {read=GetShowHeaders, nodefault};
	__property bool ShowHorzGridLines = {read=GetShowHorzGridLines, nodefault};
	__property bool ShowVertGridLines = {read=GetShowVertGridLines, nodefault};
	__property int ValueMinWidth = {read=GetValueMinWidth, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomVerticalGridReportLinkFormatter : public TcxVerticalGridReportLinkBuilderHandler
{
	typedef TcxVerticalGridReportLinkBuilderHandler inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	int FHeaderWidth;
	int FInterRecordsSpace;
	bool FIsPrevGridMode;
	System::Classes::TList* FLookAndFeelItems;
	System::Classes::TList* FRecordWidths;
	System::Classes::TList* FRowHeights;
	System::Classes::TList* FRowPlaces;
	System::Classes::TList* FRows;
	System::Uitypes::TColor FTransparentColor;
	System::Classes::TList* FViewWidths;
	System::Classes::TList* FWrappedRecordStartIndexes;
	bool __fastcall GetAutoWidth(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	System::Uitypes::TColor __fastcall GetExpandButtonColor(Cxvgrid::TcxCustomRow* Row);
	int __fastcall GetExpandButtonSize(void);
	System::Uitypes::TColor __fastcall GetGridLinesColor(void);
	int __fastcall GetHeaderAvailableWidth(Cxvgrid::TcxCustomRow* Row);
	int __fastcall GetHeaderMinWidth(void);
	int __fastcall GetHeaderWidth(void);
	int __fastcall GetIndentArea(Cxvgrid::TcxCustomRow* Row);
	int __fastcall GetInternalIndexByRecordIndex(int RecordIndex);
	int __fastcall GetInternalRecordWidth(void);
	int __fastcall GetInterRecordsSpace(void);
	Dxpscore::TdxReportVisualItem* __fastcall GetLookAndFeelItem(int Index);
	int __fastcall GetLookAndFeelItemCount(void);
	TcxVerticalGridReportLinkOptionsView* __fastcall GetOptionsView(void);
	int __fastcall GetRecordCount(int Index);
	int __fastcall GetRecordMinWidth(int RecordIndex);
	int __fastcall GetRecordWidth(int RecordIndex);
	Dxpscore::TdxPSReportRenderer* __fastcall GetRenderer(void);
	Cxvgrid::TcxCustomRow* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowHeight(Cxvgrid::TcxCustomRow* Row);
	TcxVerticalGridCustomRowHelper* __fastcall GetRowHelper(Cxvgrid::TcxCustomRow* Row);
	TcxVerticalGridCustomRowPlace* __fastcall GetRowPlace(int WrapIndex, int Index);
	TcxVerticalGridCustomRowPlace* __fastcall GetRowPlaceByRow(Cxvgrid::TcxCustomRow* Row, int WrapIndex);
	int __fastcall GetRowPlaceCount(void);
	int __fastcall GetRowPlaceFlatIndex(int WrapIndex, int Index);
	Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall GetScreenCanvas(void);
	bool __fastcall GetShowBorders(void);
	bool __fastcall GetShowHeaders(void);
	bool __fastcall GetShowHorzGridLines(void);
	bool __fastcall GetShowVertGridLines(void);
	int __fastcall GetViewMaxWidth(void);
	int __fastcall GetViewWidth(int WrapIndex);
	int __fastcall GetWrapCount(void);
	int __fastcall GetWrappedRecordStartIndex(int Index);
	int __fastcall GetWrappedRecordStopIndex(int Index);
	int __fastcall GetWrapSeparatorHeight(void);
	void __fastcall SetInterRecordsSpace(int Value);
	void __fastcall SetRecordWidth(int RecordIndex, int Value);
	void __fastcall SetRowHeight(Cxvgrid::TcxCustomRow* Row, int Value);
	void __fastcall SetViewWidth(int WrapIndex, int Value);
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
	virtual bool __fastcall GetAreRecordsNeededLoading(void);
	virtual bool __fastcall GetAreRecordsNeededUnloading(void);
	virtual int __fastcall GetFirstInternalRecordIndex(void);
	virtual int __fastcall GetInternalRecordCount(void);
	virtual void __fastcall LoadRecords(void);
	virtual void __fastcall UnloadRecords(void);
	void __fastcall AddWrappedRecordStartIndex(int Value);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateBestFit(void);
	void __fastcall CalculateHeight(const Dxpscxcommon::TdxReportItemViewParams &AParams, int &AHeight);
	virtual int __fastcall CalculatedMinWidth(void);
	void __fastcall CalculateRecordAutoWidths(void);
	void __fastcall CalculateRecordCounts(void);
	void __fastcall CalculateRowHeights(void);
	void __fastcall CalculateRowPlaces(void);
	void __fastcall CalculateViewWidths(void);
	virtual void __fastcall CreateRowList(void);
	void __fastcall CreateRowPlaces(void);
	virtual TcxVerticalGridCustomRowPlace* __fastcall CreateRowPlace(Cxvgrid::TcxCustomRow* ARow, int AWrapIndex);
	virtual void __fastcall InitializeRecordWidths(void);
	virtual void __fastcall InitializeRowHeights(void);
	virtual void __fastcall InitializeWrappedRecordIndexes(void);
	Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(int Index);
	int __fastcall GetBackgroundBitmapIndex(int Index);
	bool __fastcall HasBackgroundBitmap(int Index);
	int __fastcall MapStyleBackgroundBitmapIndex(int AVerticalGridBackgroundBitmapIndex);
	Vcl::Graphics::TFont* __fastcall GetCategoryRowFont(Cxvgrid::TcxCustomRow* ARow);
	Vcl::Graphics::TFont* __fastcall GetRowHeaderFont(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	Vcl::Graphics::TFont* __fastcall GetRowHeaderSeparatorsFont(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	Vcl::Graphics::TFont* __fastcall GetRowValueFont(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	Vcl::Graphics::TFont* __fastcall GetRowValueSeparatorsFont(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	void __fastcall ClearRowPlaces(void);
	Dxpscore::TdxCellSides __fastcall FixupHorzCellSides(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxCellSides ACellSides);
	void __fastcall FreeAndNilRowPlaces(void);
	int __fastcall GetImageHeight(Cxvgrid::TcxCustomRow* ARow, int ACellIndex);
	int __fastcall GetImageWidth(Cxvgrid::TcxCustomRow* ARow, int ACellIndex);
	Cxvgrid::TcxCustomRow* __fastcall GetNextRow(Cxvgrid::TcxCustomRow* ARow);
	Cxvgrid::TcxCustomRow* __fastcall GetPrevRow(Cxvgrid::TcxCustomRow* ARow);
	Cxvgrid::TcxCustomRow* __fastcall GetRowByReportRow(Dxpscore::TdxReportCell* ARow);
	int __fastcall GetStyleFontIndex(const Dxpscxcommon::TdxReportItemViewParams &AParams);
	int __fastcall IndexOfRow(Cxvgrid::TcxCustomRow* ARow);
	bool __fastcall IsColorTransparent(System::Uitypes::TColor AColor);
	bool __fastcall IsFirstRow(Cxvgrid::TcxCustomRow* ARow);
	bool __fastcall IsLastRow(Cxvgrid::TcxCustomRow* ARow);
	int __fastcall MakeCustomDrawCodeData(TcxVerticalGridAttributeID AnAttribute, int ACellIndex, int ARecordIndex);
	void __fastcall RegisterLookAndFeelItem(Dxpscore::TdxReportVisualItem* AnItem, Dxpscore::TdxCellEdgeStyle AEdgeStyle);
	void __fastcall SetViewParams(Dxpscore::TdxReportVisualItem* AnItem, const Dxpscxcommon::TdxReportItemViewParams &AParams);
	__property bool AreRecordsNeededLoading = {read=GetAreRecordsNeededLoading, nodefault};
	__property bool AreRecordsNeededUnloading = {read=GetAreRecordsNeededUnloading, nodefault};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ScreenCanvas = {read=GetScreenCanvas};
	__property int FirstInternalRecordIndex = {read=GetFirstInternalRecordIndex, nodefault};
	__property int HeaderAvailableWidths[Cxvgrid::TcxCustomRow* Row] = {read=GetHeaderAvailableWidth};
	__property int IndentAreas[Cxvgrid::TcxCustomRow* Row] = {read=GetIndentArea};
	__property int InternalIndexesByRecordIndex[int RecordIndex] = {read=GetInternalIndexByRecordIndex};
	__property int InternalRecordCount = {read=GetInternalRecordCount, nodefault};
	__property int InternalRecordWidth = {read=GetInternalRecordWidth, nodefault};
	__property bool IsPrevGridMode = {read=FIsPrevGridMode, nodefault};
	__property int LookAndFeelItemCount = {read=GetLookAndFeelItemCount, nodefault};
	__property Dxpscore::TdxReportVisualItem* LookAndFeelItems[int Index] = {read=GetLookAndFeelItem};
	__property Dxpscore::TdxPSReportRenderer* Renderer = {read=GetRenderer};
	__property TcxVerticalGridCustomRowHelper* RowHelpers[Cxvgrid::TcxCustomRow* Row] = {read=GetRowHelper};
	__property int RowPlaceCount = {read=GetRowPlaceCount, nodefault};
	__property int RowPlaceFlatIndexes[int WrapIndex][int Index] = {read=GetRowPlaceFlatIndex};
	__property TcxVerticalGridCustomRowPlace* RowPlaces[int WrapIndex][int Index] = {read=GetRowPlace};
	__property TcxVerticalGridCustomRowPlace* RowPlacesByRow[Cxvgrid::TcxCustomRow* Row][int WrapIndex] = {read=GetRowPlaceByRow};
	__property int ViewWidths[int WrapIndex] = {read=GetViewWidth, write=SetViewWidth};
	__property int WrappedRecordStartIndexes[int Index] = {read=GetWrappedRecordStartIndex};
	__property int WrappedRecordStopIndexes[int Index] = {read=GetWrappedRecordStopIndex};
	
public:
	__fastcall virtual TcxCustomVerticalGridReportLinkFormatter(TcxCustomVerticalGridReportLinkBuilder* ABuilder);
	__fastcall virtual ~TcxCustomVerticalGridReportLinkFormatter(void);
	virtual TcxCustomVerticalGridAdapter* __fastcall Adapter(void)/* overload */;
	virtual void __fastcall DoInitializeHost(Dxpscore::TdxReportCell* AHost);
	virtual void __fastcall DoInitializeRowImage(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCellGraphic* AnItem, int AnIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetRowImageCellSides(Cxvgrid::TcxCustomRow* ARow);
	virtual Dxpscore::TdxReportCellGraphicClass __fastcall GetRowImageClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetRowImageViewParams(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	virtual void __fastcall DoInitializeRowIndent(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex, int AnIndentCount);
	virtual void __fastcall DoInitializeExpandButton(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex, int AnIndentCount);
	virtual void __fastcall DoReportLinkInitializeRowIndent(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCellExpandButton* AnItem, int AnIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetRowIndentCellSides(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int AnIndentCount);
	virtual Dxpscore::TdxReportCellExpandButtonClass __fastcall GetRowIndentClass(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetRowIndentViewParams(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int AnIndentCount);
	virtual void __fastcall DoInitializeCategoryRow(Cxvgrid::TcxCategoryRow* ARow, Dxpscore::TdxReportCellImage* AnItem);
	virtual void __fastcall DoInitializeRowReportRow(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCell* AReportRow);
	virtual void __fastcall DoInitializeRowHeader(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCellImage* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeRowValue(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex, int ARecordIndex);
	virtual void __fastcall DoReportLinkInitializeRowHeader(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TdxReportCellImage* AnItem, int AnIndex);
	virtual void __fastcall DoReportLinkInitializeRowValue(Cxvgrid::TcxCustomRow* ARow, Dxpscore::TAbstractdxReportCellData* AnItem, int AnIndex, int ARecordIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetCategoryRowCellSides(Cxvgrid::TcxCustomRow* ARow);
	virtual Dxpscore::TdxReportCellImageClass __fastcall GetCategoryRowClass(Cxvgrid::TcxCustomRow* ARow);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetCategoryRowViewParams(Cxvgrid::TcxCustomRow* ARow);
	virtual System::Variant __fastcall GetCellValue(Cxvgrid::TcxCustomRow* ARow, Cxedit::TcxCustomEditProperties* AProperties, int AnIndex, int ARecordIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetRowHeaderCellSides(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	virtual Dxpscore::TdxReportCellImageClass __fastcall GetRowHeaderClass(Cxvgrid::TcxCustomRow* ARow);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetRowHeaderViewParams(Cxvgrid::TcxCustomRow* ARow, int AnIndex);
	virtual Dxpscore::TdxCellSides __fastcall GetRowValueCellSides(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetRowValueClass(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetRowValueViewParams(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex);
	virtual void __fastcall DoInitializeRowHeaderSeparator(Cxvgrid::TcxCustomMultiEditorRow* ARow, Dxpscore::TdxReportCellString* AnItem, int AnIndex);
	virtual void __fastcall DoInitializeRowValueSeparator(Cxvgrid::TcxCustomMultiEditorRow* ARow, Dxpscore::TdxReportCellString* AnItem, int AnIndex, int ARecordIndex);
	virtual void __fastcall DoReportLinkInitializeRowHeaderSeparator(Cxvgrid::TcxCustomMultiEditorRow* ARow, Dxpscore::TdxReportCellString* AnItem, int AnIndex);
	virtual void __fastcall DoReportLinkInitializeRowValueSeparator(Cxvgrid::TcxCustomMultiEditorRow* ARow, Dxpscore::TdxReportCellString* AnItem, int AnIndex, int ARecordIndex);
	Dxpscore::TdxCellSides __fastcall GetRowHeaderSeparatorCellSides(Cxvgrid::TcxCustomMultiEditorRow* ARow);
	virtual Dxpscore::TdxReportCellStringClass __fastcall GetRowHeaderSeparatorClass(Cxvgrid::TcxCustomMultiEditorRow* ARow);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetRowHeaderSeparatorViewParams(Cxvgrid::TcxCustomMultiEditorRow* ARow, int AnIndex);
	Dxpscore::TdxCellSides __fastcall GetRowValueSeparatorCellSides(Cxvgrid::TcxCustomMultiEditorRow* ARow);
	virtual Dxpscore::TdxReportCellStringClass __fastcall GetRowValueSeparatorClass(Cxvgrid::TcxCustomMultiEditorRow* ARow);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetRowValueSeparatorViewParams(Cxvgrid::TcxCustomMultiEditorRow* ARow, int AnIndex, int ARecordIndex);
	virtual void __fastcall DoInitializeWrapSeparatorItem(Dxpscore::TdxReportCellString* AnItem, int AWrapIndex);
	virtual void __fastcall DoInitializeWrapSeparatorRow(Dxpscore::TdxReportCell* ARow);
	virtual Dxpscore::TdxReportCellStringClass __fastcall GetWrapSeparatorClass(void);
	__property bool AutoWidth = {read=GetAutoWidth, nodefault};
	__property System::Uitypes::TColor ExpandButtonColors[Cxvgrid::TcxCustomRow* Row] = {read=GetExpandButtonColor};
	__property int ExpandButtonSize = {read=GetExpandButtonSize, nodefault};
	__property System::Uitypes::TColor GridLinesColor = {read=GetGridLinesColor, nodefault};
	__property int HeaderMinWidth = {read=GetHeaderMinWidth, nodefault};
	__property int HeaderWidth = {read=GetHeaderWidth, write=FHeaderWidth, nodefault};
	__property int InterRecordsSpace = {read=GetInterRecordsSpace, write=SetInterRecordsSpace, nodefault};
	__property TcxVerticalGridReportLinkOptionsView* OptionsView = {read=GetOptionsView};
	__property int RecordCounts[int Index] = {read=GetRecordCount};
	__property int RecordMinWidths[int RecordIndex] = {read=GetRecordMinWidth};
	__property int RecordWidths[int RecordIndex] = {read=GetRecordWidth, write=SetRecordWidth};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeights[Cxvgrid::TcxCustomRow* Row] = {read=GetRowHeight, write=SetRowHeight};
	__property Cxvgrid::TcxCustomRow* Rows[int Index] = {read=GetRow};
	__property bool ShowBorders = {read=GetShowBorders, nodefault};
	__property bool ShowHeaders = {read=GetShowHeaders, nodefault};
	__property bool ShowHorzGridLines = {read=GetShowHorzGridLines, nodefault};
	__property bool ShowVertGridLines = {read=GetShowVertGridLines, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=FTransparentColor, write=FTransparentColor, default=-16777211};
	__property int ViewMaxWidth = {read=GetViewMaxWidth, nodefault};
	__property int WrapCount = {read=GetWrapCount, nodefault};
	__property int WrapSeparatorHeight = {read=GetWrapSeparatorHeight, nodefault};
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

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkOptionsExpanding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkOptionsExpanding : public Dxpscxcommon::TdxCustomReportLinkOptionsExpanding
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsExpanding inherited;
	
private:
	bool FAutoExpandRows;
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetAutoExpandRows(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool AutoExpandRows = {read=FAutoExpandRows, write=SetAutoExpandRows, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVerticalGridReportLinkOptionsExpanding(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsExpanding(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkOptionsExpanding(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkOptionsFormatting;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkOptionsFormatting : public Dxpscxcommon::TdxCustomReportLinkOptionsFormatting
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsFormatting inherited;
	
private:
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVerticalGridReportLinkOptionsFormatting(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsFormatting(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkOptionsFormatting(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkOptionsPagination;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkOptionsPagination : public Dxpscxcommon::TdxCustomReportLinkOptionsPagination
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsPagination inherited;
	
private:
	bool FByRows;
	bool FByWrapping;
	bool FOneWrappingPerPage;
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetByRows(bool Value);
	void __fastcall SetByWrapping(bool Value);
	void __fastcall SetOneWrappingPerPage(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool ByRows = {read=FByRows, write=SetByRows, default=1};
	__property bool ByWrapping = {read=FByWrapping, write=SetByWrapping, default=1};
	__property bool OneWrappingPerPage = {read=FOneWrappingPerPage, write=SetOneWrappingPerPage, default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVerticalGridReportLinkOptionsPagination(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsPagination(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkOptionsPagination(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkOptionsRefinements;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkOptionsRefinements : public Dxpscxcommon::TdxCustomReportLinkOptionsRefinements
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsRefinements inherited;
	
private:
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	bool __fastcall GetSuppressBackgroundBitmaps(void);
	void __fastcall SetSuppressBackgroundBitmaps(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool SuppressBackgroundBitmaps = {read=GetSuppressBackgroundBitmaps, write=SetSuppressBackgroundBitmaps, stored=false, nodefault};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVerticalGridReportLinkOptionsRefinements(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsRefinements(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkOptionsRefinements(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkOptionsSize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkOptionsSize : public Dxpscxcommon::TdxCustomReportLinkOptionsSize
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsSize inherited;
	
private:
	bool FBestFit;
	bool FKeepSameRecordWidths;
	bool FWrapRecords;
	int FWrapSeparatorHeight;
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetBestFit(bool Value);
	void __fastcall SetKeepSameRecordWidths(bool Value);
	void __fastcall SetWrapRecords(bool Value);
	void __fastcall SetWrapSeparatorHeight(int Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property AutoWidth = {default=0};
	__property bool BestFit = {read=FBestFit, write=SetBestFit, default=0};
	__property bool KeepSameRecordWidths = {read=FKeepSameRecordWidths, write=SetKeepSameRecordWidths, default=1};
	__property bool WrapRecords = {read=FWrapRecords, write=SetWrapRecords, default=1};
	__property int WrapSeparatorHeight = {read=FWrapSeparatorHeight, write=SetWrapSeparatorHeight, default=20};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVerticalGridReportLinkOptionsSize(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsSize(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkOptionsSize(void) { }
	
};

#pragma pack(pop)

enum TcxVerticalGridReportLinkPrintMode : unsigned char { vpmLoadedRecords, vpmAllRecords };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkOptionsView : public Dxpscxcommon::TdxCustomReportLinkOptionsView
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsView inherited;
	
private:
	bool FBorders;
	bool FExpandButtons;
	bool FHeaders;
	TcxVerticalGridReportLinkPrintMode FMode;
	TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	void __fastcall SetBorders(bool Value);
	void __fastcall SetExpandButtons(bool Value);
	void __fastcall SetHeaders(bool Value);
	void __fastcall SetMode(TcxVerticalGridReportLinkPrintMode Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	virtual TcxVerticalGridReportLinkPrintMode __fastcall GetActualMode(void);
	__property TcxVerticalGridReportLinkPrintMode Mode = {read=FMode, write=SetMode, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxVerticalGridReportLinkPrintMode ActualMode = {read=GetActualMode, nodefault};
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool Borders = {read=FBorders, write=SetBorders, default=1};
	__property bool ExpandButtons = {read=FExpandButtons, write=SetExpandButtons, default=1};
	__property bool Headers = {read=FHeaders, write=SetHeaders, default=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVerticalGridReportLinkOptionsView(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsView(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkOptionsView(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxVerticalGridReportLinkStylesClass;

class DELPHICLASS TcxVerticalGridReportLinkStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkStyles : public Dxpscxcommon::TdxCustomReportLinkStyles
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyles inherited;
	
private:
	HIDESBASE TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual System::UnicodeString __fastcall GetStyleCaption(int AnIndex);
	virtual int __fastcall GetStyleIndexByCaption(const System::UnicodeString Caption);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetCategoryParams(Cxvgrid::TcxCustomRow* ARow, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetContentParams(Cxvgrid::TcxCustomRow* ARow, int AnIndex, int ARecordIndex, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetHeaderParams(Cxvgrid::TcxCustomRow* ARow, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetIndentParams(Cxvgrid::TcxCustomRow* ARow, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Cxstyles::TcxStyle* Category = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=1};
	__property StyleSheet;
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxVerticalGridReportLinkStyles(System::Classes::TPersistent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkStyles(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVerticalGridReportLinkStyleSheet;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridReportLinkStyleSheet : public Dxpscxcommon::TdxCustomReportLinkStyleSheet
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyleSheet inherited;
	
private:
	TcxVerticalGridReportLinkStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxVerticalGridReportLinkStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxVerticalGridReportLinkStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxVerticalGridReportLinkStyleSheet(System::Classes::TComponent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLinkStyleSheet(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVerticalGridHostInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxpscore::TdxReportCell* FParent;
	
public:
	System::Types::TPoint Origin;
	void __fastcall Initialize(Dxpscore::TdxReportCell* AParent);
	__property Dxpscore::TdxReportCell* Parent = {read=FParent};
public:
	/* TObject.Create */ inline __fastcall TcxVerticalGridHostInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxVerticalGridHostInfo(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxVerticalGridReportLinkCustomDrawRowHeaderCellEvent)(TcxCustomVerticalGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkCustomDrawRowHeaderSeparatorCellEvent)(TcxCustomVerticalGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkCustomDrawRowIndentCellEvent)(TcxCustomVerticalGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellExpandButton* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkCustomDrawRowValueCellEvent)(TcxCustomVerticalGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkCustomDrawRowValueSeparatorCellEvent)(TcxCustomVerticalGridReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TdxReportCellString* AnItem, bool &ADone);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkInitializeRowHeaderCellEvent)(TcxCustomVerticalGridReportLink* Sender, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, Dxpscore::TdxReportCellImage* AnItem);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkInitializeRowHeaderSeparatorCellEvent)(TcxCustomVerticalGridReportLink* Sender, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellString* AnItem);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkInitializeRowIndentCellEvent)(TcxCustomVerticalGridReportLink* Sender, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellExpandButton* AnItem);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkInitializeRowValueCellEvent)(TcxCustomVerticalGridReportLink* Sender, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TAbstractdxReportCellData* AnItem);

typedef void __fastcall (__closure *TcxVerticalGridReportLinkInitializeRowValueSeparatorCellEvent)(TcxCustomVerticalGridReportLink* Sender, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TdxReportCellString* AnItem);

class DELPHICLASS TcxfmVerticalGridReportLinkDesignWindow;
class PASCALIMPLEMENTATION TcxCustomVerticalGridReportLink : public Dxpscxcommon::TdxCustomcxControlReportLink
{
	typedef Dxpscxcommon::TdxCustomcxControlReportLink inherited;
	
private:
	TcxCustomVerticalGridReportLinkBuilder* FBuilder;
	Vcl::Graphics::TFont* FCategoryFont;
	System::Classes::TList* FDelimitersHardHorz;
	System::Classes::TList* FDelimitersHardVert;
	TcxVerticalGridHostInfo* FHostInfo;
	TcxVerticalGridReportLinkCustomDrawRowHeaderCellEvent FOnCustomDrawRowHeaderCell;
	TcxVerticalGridReportLinkCustomDrawRowHeaderSeparatorCellEvent FOnCustomDrawRowHeaderSeparatorCell;
	TcxVerticalGridReportLinkCustomDrawRowIndentCellEvent FOnCustomDrawRowIndentCell;
	TcxVerticalGridReportLinkCustomDrawRowValueCellEvent FOnCustomDrawRowValueCell;
	TcxVerticalGridReportLinkCustomDrawRowValueSeparatorCellEvent FOnCustomDrawRowValueSeparatorCell;
	TcxVerticalGridReportLinkInitializeRowHeaderCellEvent FOnInitializeRowHeaderCell;
	TcxVerticalGridReportLinkInitializeRowHeaderSeparatorCellEvent FOnInitializeRowHeaderSeparatorCell;
	TcxVerticalGridReportLinkInitializeRowIndentCellEvent FOnInitializeRowIndentCell;
	TcxVerticalGridReportLinkInitializeRowValueCellEvent FOnInitializeRowValueCell;
	TcxVerticalGridReportLinkInitializeRowValueSeparatorCellEvent FOnInitializeRowValueSeparatorCell;
	HIDESBASE TcxVerticalGridReportLinkStyles* __fastcall GetActiveStyles(void);
	HIDESBASE TcxfmVerticalGridReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	TcxVerticalGridReportLinkOptionsExpanding* __fastcall GetOptionsExpanding(void);
	TcxVerticalGridReportLinkOptionsFormatting* __fastcall GetOptionsFormatting(void);
	TcxVerticalGridReportLinkOptionsPagination* __fastcall GetOptionsPagination(void);
	TcxVerticalGridReportLinkOptionsRefinements* __fastcall GetOptionsRefinements(void);
	TcxVerticalGridReportLinkOptionsSize* __fastcall GetOptionsSize(void);
	TcxVerticalGridReportLinkOptionsView* __fastcall GetOptionsView(void);
	TcxVerticalGridReportLinkStyles* __fastcall GetStyles(void);
	Cxvgrid::TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	void __fastcall SetCategoryFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetOnCustomDrawRowHeaderCell(TcxVerticalGridReportLinkCustomDrawRowHeaderCellEvent Value);
	void __fastcall SetOnCustomDrawRowHeaderSeparatorCell(TcxVerticalGridReportLinkCustomDrawRowHeaderSeparatorCellEvent Value);
	void __fastcall SetOnCustomDrawRowIndentCell(TcxVerticalGridReportLinkCustomDrawRowIndentCellEvent Value);
	void __fastcall SetOnCustomDrawRowValueCell(TcxVerticalGridReportLinkCustomDrawRowValueCellEvent Value);
	void __fastcall SetOnCustomDrawRowValueSeparatorCell(TcxVerticalGridReportLinkCustomDrawRowValueSeparatorCellEvent Value);
	HIDESBASE void __fastcall SetOptionsExpanding(TcxVerticalGridReportLinkOptionsExpanding* Value);
	HIDESBASE void __fastcall SetOptionsFormatting(TcxVerticalGridReportLinkOptionsFormatting* Value);
	HIDESBASE void __fastcall SetOptionsPagination(TcxVerticalGridReportLinkOptionsPagination* Value);
	HIDESBASE void __fastcall SetOptionsRefinements(TcxVerticalGridReportLinkOptionsRefinements* Value);
	HIDESBASE void __fastcall SetOptionsSize(TcxVerticalGridReportLinkOptionsSize* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxVerticalGridReportLinkOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TcxVerticalGridReportLinkStyles* Value);
	
protected:
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall ConvertCoords(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABoundsRect, const System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall FontChanged(System::TObject* Sender);
	virtual bool __fastcall GetBreakPagesByHardDelimiters(void);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual bool __fastcall GetUseHardVertDelimiters(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual bool __fastcall IsSupportedCustomDraw(Dxpscore::TAbstractdxReportCellData* Item);
	virtual void __fastcall MakeHardDelimiters(Dxpscore::TdxReportCells* AReportCells, System::Classes::TList* AHorzDelimiters, System::Classes::TList* AVertDelimiters);
	DYNAMIC void __fastcall DoCustomDrawRowHeaderCell(Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellImage* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawRowHeaderSeparatorCell(Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawRowIndentCell(Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellExpandButton* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawRowValueCell(Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TAbstractdxReportCellData* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoCustomDrawRowValueSeparatorCell(Vcl::Graphics::TCanvas* ACanvas, Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TdxReportCellString* AnItem, bool &ADone);
	DYNAMIC void __fastcall DoInitializeRowHeaderCell(Cxvgrid::TcxCustomRow* ARow, int ACellIndex, Dxpscore::TdxReportCellImage* AnItem);
	DYNAMIC void __fastcall DoInitializeRowHeaderSeparatorCell(Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellString* AnItem);
	DYNAMIC void __fastcall DoInitializeRowIndentCell(Cxvgrid::TcxCustomRow* ARow, int AnIndex, Dxpscore::TdxReportCellExpandButton* AnItem);
	DYNAMIC void __fastcall DoInitializeRowValueCell(Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TAbstractdxReportCellData* AnItem);
	DYNAMIC void __fastcall DoInitializeRowValueSeparatorCell(Cxvgrid::TcxCustomRow* ARow, int ACellIndex, int ARecordIndex, Dxpscore::TdxReportCellString* AnItem);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsExpandingClass __fastcall GetOptionsExpandingClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsFormattingClass __fastcall GetOptionsFormattingClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsPaginationClass __fastcall GetOptionsPaginationClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsRefinementsClass __fastcall GetOptionsRefinementsClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsSizeClass __fastcall GetOptionsSizeClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual bool __fastcall GetAreNativeStylesAvailable(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStylesClass __fastcall GetStylesClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheetClass __fastcall GetStyleSheetClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheet* __fastcall GetStyleSheetPrototype(void);
	virtual void __fastcall PrepareConstruct(void);
	virtual void __fastcall UnprepareConstruct(void);
	void __fastcall AddHorizontalHardDelimiter(int ADelimiter);
	void __fastcall AddVerticalHardDelimiter(int ADelimiter)/* overload */;
	void __fastcall AddVerticalHardDelimiter(Dxpscore::TdxReportCell* ADelimiter)/* overload */;
	virtual TcxCustomVerticalGridReportLinkBuilder* __fastcall CreateBuilder(void);
	__classmethod virtual TcxCustomVerticalGridReportLinkBuilderClass __fastcall GetBuilderClass();
	void __fastcall ExtractCustomDrawCodeDataValues(int ACode, TcxVerticalGridAttributeID &AnAttribute, int &ACellIndex, int &ARecordIndex);
	virtual TcxVerticalGridAttributeID __fastcall GetItemCustomDrawInfo(Dxpscore::TdxReportVisualItem* AnItem, /* out */ TcxVerticalGridCellCustomDrawInfo &ADrawInfo);
	virtual bool __fastcall IsCustomDrawn(TcxVerticalGridAttributeID AnAttributeID);
	int __fastcall MakeCustomDrawCodeData(TcxVerticalGridAttributeID AnAttribute, int ACellIndex, int ARecordIndex);
	virtual void __fastcall InitializePrintModeControl(Cxdropdownedit::TcxComboBox* AControl);
	virtual void __fastcall UpdateStatePrintModeControl(Cxdropdownedit::TcxComboBox* AControl);
	__property TcxVerticalGridReportLinkStyles* ActiveStyles = {read=GetActiveStyles};
	__property TcxCustomVerticalGridReportLinkBuilder* Builder = {read=FBuilder};
	__property Vcl::Graphics::TFont* CategoryFont = {read=FCategoryFont, write=SetCategoryFont};
	__property System::Classes::TList* DelimitersHardHorz = {read=FDelimitersHardHorz};
	__property System::Classes::TList* DelimitersHardVert = {read=FDelimitersHardVert};
	__property TcxVerticalGridHostInfo* HostInfo = {read=FHostInfo};
	__property Cxvgrid::TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
	
public:
	__fastcall virtual TcxCustomVerticalGridReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomVerticalGridReportLink(void);
	__property TcxfmVerticalGridReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	
__published:
	__property Color = {default=16777215};
	__property Font;
	__property TcxVerticalGridReportLinkOptionsExpanding* OptionsExpanding = {read=GetOptionsExpanding, write=SetOptionsExpanding};
	__property TcxVerticalGridReportLinkOptionsFormatting* OptionsFormatting = {read=GetOptionsFormatting, write=SetOptionsFormatting};
	__property TcxVerticalGridReportLinkOptionsPagination* OptionsPagination = {read=GetOptionsPagination, write=SetOptionsPagination};
	__property TcxVerticalGridReportLinkOptionsRefinements* OptionsRefinements = {read=GetOptionsRefinements, write=SetOptionsRefinements};
	__property TcxVerticalGridReportLinkOptionsSize* OptionsSize = {read=GetOptionsSize, write=SetOptionsSize};
	__property TcxVerticalGridReportLinkOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property ScaleFonts = {default=1};
	__property StyleRepository;
	__property TcxVerticalGridReportLinkStyles* Styles = {read=GetStyles, write=SetStyles};
	__property SupportedCustomDraw = {default=0};
	__property TcxVerticalGridReportLinkCustomDrawRowHeaderCellEvent OnCustomDrawRowHeaderCell = {read=FOnCustomDrawRowHeaderCell, write=SetOnCustomDrawRowHeaderCell};
	__property TcxVerticalGridReportLinkCustomDrawRowHeaderSeparatorCellEvent OnCustomDrawRowHeaderSeparatorCell = {read=FOnCustomDrawRowHeaderSeparatorCell, write=SetOnCustomDrawRowHeaderSeparatorCell};
	__property TcxVerticalGridReportLinkCustomDrawRowIndentCellEvent OnCustomDrawRowIndentCell = {read=FOnCustomDrawRowIndentCell, write=SetOnCustomDrawRowIndentCell};
	__property TcxVerticalGridReportLinkCustomDrawRowValueCellEvent OnCustomDrawRowValueCell = {read=FOnCustomDrawRowValueCell, write=SetOnCustomDrawRowValueCell};
	__property TcxVerticalGridReportLinkCustomDrawRowValueSeparatorCellEvent OnCustomDrawRowValueSeparatorCell = {read=FOnCustomDrawRowValueSeparatorCell, write=SetOnCustomDrawRowValueSeparatorCell};
	__property TcxVerticalGridReportLinkInitializeRowHeaderCellEvent OnInitializeRowHeaderCell = {read=FOnInitializeRowHeaderCell, write=FOnInitializeRowHeaderCell};
	__property TcxVerticalGridReportLinkInitializeRowHeaderSeparatorCellEvent OnInitializeRowHeaderSeparatorCell = {read=FOnInitializeRowHeaderSeparatorCell, write=FOnInitializeRowHeaderSeparatorCell};
	__property TcxVerticalGridReportLinkInitializeRowIndentCellEvent OnInitializeRowIndentCell = {read=FOnInitializeRowIndentCell, write=FOnInitializeRowIndentCell};
	__property TcxVerticalGridReportLinkInitializeRowValueCellEvent OnInitializeRowValueCell = {read=FOnInitializeRowValueCell, write=FOnInitializeRowValueCell};
	__property TcxVerticalGridReportLinkInitializeRowValueSeparatorCellEvent OnInitializeRowValueSeparatorCell = {read=FOnInitializeRowValueSeparatorCell, write=FOnInitializeRowValueSeparatorCell};
};


class DELPHICLASS TcxUnboundVerticalGridReportLinkBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUnboundVerticalGridReportLinkBuilder : public TcxCustomVerticalGridReportLinkBuilder
{
	typedef TcxCustomVerticalGridReportLinkBuilder inherited;
	
public:
	__classmethod virtual TcxCustomVerticalGridAdapterClass __fastcall AdapterClass();
public:
	/* TcxCustomVerticalGridReportLinkBuilder.Create */ inline __fastcall virtual TcxUnboundVerticalGridReportLinkBuilder(TcxCustomVerticalGridReportLink* AReportLink) : TcxCustomVerticalGridReportLinkBuilder(AReportLink) { }
	/* TcxCustomVerticalGridReportLinkBuilder.Destroy */ inline __fastcall virtual ~TcxUnboundVerticalGridReportLinkBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxUnboundVerticalGridAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUnboundVerticalGridAdapter : public TcxCustomVerticalGridAdapter
{
	typedef TcxCustomVerticalGridAdapter inherited;
	
private:
	HIDESBASE Cxvgrid::TcxUnboundVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual Cxvgrid::TcxvgLayoutStyle __fastcall GetLayoutStyle(void);
	__property Cxvgrid::TcxUnboundVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
public:
	/* TcxCustomVerticalGridAdapter.Create */ inline __fastcall virtual TcxUnboundVerticalGridAdapter(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxCustomVerticalGridAdapter(ABuilder) { }
	/* TcxCustomVerticalGridAdapter.Destroy */ inline __fastcall virtual ~TcxUnboundVerticalGridAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxUnboundVerticalGridReportLink;
class PASCALIMPLEMENTATION TcxUnboundVerticalGridReportLink : public TcxCustomVerticalGridReportLink
{
	typedef TcxCustomVerticalGridReportLink inherited;
	
protected:
	__classmethod virtual TcxCustomVerticalGridReportLinkBuilderClass __fastcall GetBuilderClass();
public:
	/* TcxCustomVerticalGridReportLink.Create */ inline __fastcall virtual TcxUnboundVerticalGridReportLink(System::Classes::TComponent* AOwner) : TcxCustomVerticalGridReportLink(AOwner) { }
	/* TcxCustomVerticalGridReportLink.Destroy */ inline __fastcall virtual ~TcxUnboundVerticalGridReportLink(void) { }
	
};


class DELPHICLASS TcxVerticalGridReportLink;
class PASCALIMPLEMENTATION TcxVerticalGridReportLink : public TcxUnboundVerticalGridReportLink
{
	typedef TcxUnboundVerticalGridReportLink inherited;
	
private:
	HIDESBASE Cxvgrid::TcxVerticalGrid* __fastcall GetVerticalGrid(void);
	
public:
	__property Cxvgrid::TcxVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
public:
	/* TcxCustomVerticalGridReportLink.Create */ inline __fastcall virtual TcxVerticalGridReportLink(System::Classes::TComponent* AOwner) : TcxUnboundVerticalGridReportLink(AOwner) { }
	/* TcxCustomVerticalGridReportLink.Destroy */ inline __fastcall virtual ~TcxVerticalGridReportLink(void) { }
	
};


class DELPHICLASS TcxRTTIInspectorReportLink;
class PASCALIMPLEMENTATION TcxRTTIInspectorReportLink : public TcxUnboundVerticalGridReportLink
{
	typedef TcxUnboundVerticalGridReportLink inherited;
	
private:
	Cxoi::TcxRTTIInspector* __fastcall GetRTTIInspector(void);
	
public:
	__property Cxoi::TcxRTTIInspector* RTTIInspector = {read=GetRTTIInspector};
public:
	/* TcxCustomVerticalGridReportLink.Create */ inline __fastcall virtual TcxRTTIInspectorReportLink(System::Classes::TComponent* AOwner) : TcxUnboundVerticalGridReportLink(AOwner) { }
	/* TcxCustomVerticalGridReportLink.Destroy */ inline __fastcall virtual ~TcxRTTIInspectorReportLink(void) { }
	
};


class DELPHICLASS TcxVirtualVerticalGridReportLinkBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVirtualVerticalGridReportLinkBuilder : public TcxCustomVerticalGridReportLinkBuilder
{
	typedef TcxCustomVerticalGridReportLinkBuilder inherited;
	
public:
	__classmethod virtual TcxCustomVerticalGridAdapterClass __fastcall AdapterClass();
	__classmethod virtual TcxCustomVerticalGridReportLinkFormatterClass __fastcall FormatterClass();
public:
	/* TcxCustomVerticalGridReportLinkBuilder.Create */ inline __fastcall virtual TcxVirtualVerticalGridReportLinkBuilder(TcxCustomVerticalGridReportLink* AReportLink) : TcxCustomVerticalGridReportLinkBuilder(AReportLink) { }
	/* TcxCustomVerticalGridReportLinkBuilder.Destroy */ inline __fastcall virtual ~TcxVirtualVerticalGridReportLinkBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVirtualVerticalGridAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVirtualVerticalGridAdapter : public TcxCustomVerticalGridAdapter
{
	typedef TcxCustomVerticalGridAdapter inherited;
	
private:
	HIDESBASE Cxvgrid::TcxvgMultiRecordsOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE Cxvgrid::TcxVirtualVerticalGrid* __fastcall GetVerticalGrid(void);
	
protected:
	virtual int __fastcall GetInterRecordsSpace(void);
	virtual Cxvgrid::TcxvgLayoutStyle __fastcall GetLayoutStyle(void);
	
public:
	__property Cxvgrid::TcxvgMultiRecordsOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxvgrid::TcxVirtualVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
public:
	/* TcxCustomVerticalGridAdapter.Create */ inline __fastcall virtual TcxVirtualVerticalGridAdapter(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxCustomVerticalGridAdapter(ABuilder) { }
	/* TcxCustomVerticalGridAdapter.Destroy */ inline __fastcall virtual ~TcxVirtualVerticalGridAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVirtualVerticalGridReportLinkFormatter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVirtualVerticalGridReportLinkFormatter : public TcxCustomVerticalGridReportLinkFormatter
{
	typedef TcxCustomVerticalGridReportLinkFormatter inherited;
	
protected:
	virtual int __fastcall GetFirstInternalRecordIndex(void);
	virtual int __fastcall GetInternalRecordCount(void);
public:
	/* TcxCustomVerticalGridReportLinkFormatter.Create */ inline __fastcall virtual TcxVirtualVerticalGridReportLinkFormatter(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxCustomVerticalGridReportLinkFormatter(ABuilder) { }
	/* TcxCustomVerticalGridReportLinkFormatter.Destroy */ inline __fastcall virtual ~TcxVirtualVerticalGridReportLinkFormatter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxVirtualVerticalGridReportLinkOptionsView;
class DELPHICLASS TcxVirtualVerticalGridReportLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxVirtualVerticalGridReportLinkOptionsView : public TcxVerticalGridReportLinkOptionsView
{
	typedef TcxVerticalGridReportLinkOptionsView inherited;
	
private:
	HIDESBASE TcxVirtualVerticalGridReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual TcxVerticalGridReportLinkPrintMode __fastcall GetActualMode(void);
	
public:
	__property TcxVirtualVerticalGridReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Mode = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxVirtualVerticalGridReportLinkOptionsView(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TcxVerticalGridReportLinkOptionsView(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxVirtualVerticalGridReportLinkOptionsView(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxVirtualVerticalGridReportLink : public TcxCustomVerticalGridReportLink
{
	typedef TcxCustomVerticalGridReportLink inherited;
	
private:
	HIDESBASE TcxVirtualVerticalGridReportLinkOptionsView* __fastcall GetOptionsView(void);
	Cxvgrid::TcxVirtualVerticalGrid* __fastcall GetVirtualVerticalGrid(void);
	HIDESBASE void __fastcall SetOptionsView(TcxVirtualVerticalGridReportLinkOptionsView* Value);
	
protected:
	virtual void __fastcall InternalRestoreFromOriginal(void);
	__classmethod virtual TcxCustomVerticalGridReportLinkBuilderClass __fastcall GetBuilderClass();
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual void __fastcall InitializePrintModeControl(Cxdropdownedit::TcxComboBox* AControl);
	virtual void __fastcall UpdateStatePrintModeControl(Cxdropdownedit::TcxComboBox* AControl);
	
public:
	__property Cxvgrid::TcxVirtualVerticalGrid* VirtualVerticalGrid = {read=GetVirtualVerticalGrid};
	
__published:
	__property TcxVirtualVerticalGridReportLinkOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
public:
	/* TcxCustomVerticalGridReportLink.Create */ inline __fastcall virtual TcxVirtualVerticalGridReportLink(System::Classes::TComponent* AOwner) : TcxCustomVerticalGridReportLink(AOwner) { }
	/* TcxCustomVerticalGridReportLink.Destroy */ inline __fastcall virtual ~TcxVirtualVerticalGridReportLink(void) { }
	
};


class DELPHICLASS TcxDBVerticalGridReportLinkBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBVerticalGridReportLinkBuilder : public TcxVirtualVerticalGridReportLinkBuilder
{
	typedef TcxVirtualVerticalGridReportLinkBuilder inherited;
	
public:
	__classmethod virtual TcxCustomVerticalGridReportLinkFormatterClass __fastcall FormatterClass();
public:
	/* TcxCustomVerticalGridReportLinkBuilder.Create */ inline __fastcall virtual TcxDBVerticalGridReportLinkBuilder(TcxCustomVerticalGridReportLink* AReportLink) : TcxVirtualVerticalGridReportLinkBuilder(AReportLink) { }
	/* TcxCustomVerticalGridReportLinkBuilder.Destroy */ inline __fastcall virtual ~TcxDBVerticalGridReportLinkBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBVerticalGridReportLinkFormatter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBVerticalGridReportLinkFormatter : public TcxVirtualVerticalGridReportLinkFormatter
{
	typedef TcxVirtualVerticalGridReportLinkFormatter inherited;
	
private:
	HIDESBASE Cxdbvgrid::TcxDBVerticalGridDataController* __fastcall GetDataController(void);
	
protected:
	virtual bool __fastcall GetAreRecordsNeededLoading(void);
	virtual bool __fastcall GetAreRecordsNeededUnloading(void);
	virtual void __fastcall LoadRecords(void);
	virtual void __fastcall UnloadRecords(void);
	
public:
	__property Cxdbvgrid::TcxDBVerticalGridDataController* DataController = {read=GetDataController};
public:
	/* TcxCustomVerticalGridReportLinkFormatter.Create */ inline __fastcall virtual TcxDBVerticalGridReportLinkFormatter(TcxCustomVerticalGridReportLinkBuilder* ABuilder) : TcxVirtualVerticalGridReportLinkFormatter(ABuilder) { }
	/* TcxCustomVerticalGridReportLinkFormatter.Destroy */ inline __fastcall virtual ~TcxDBVerticalGridReportLinkFormatter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBVerticalGridReportLink;
class PASCALIMPLEMENTATION TcxDBVerticalGridReportLink : public TcxVirtualVerticalGridReportLink
{
	typedef TcxVirtualVerticalGridReportLink inherited;
	
private:
	Cxdbvgrid::TcxDBVerticalGrid* __fastcall GetDBVerticalGrid(void);
	
protected:
	__classmethod virtual TcxCustomVerticalGridReportLinkBuilderClass __fastcall GetBuilderClass();
	
public:
	__property Cxdbvgrid::TcxDBVerticalGrid* DBVerticalGrid = {read=GetDBVerticalGrid};
public:
	/* TcxCustomVerticalGridReportLink.Create */ inline __fastcall virtual TcxDBVerticalGridReportLink(System::Classes::TComponent* AOwner) : TcxVirtualVerticalGridReportLink(AOwner) { }
	/* TcxCustomVerticalGridReportLink.Destroy */ inline __fastcall virtual ~TcxDBVerticalGridReportLink(void) { }
	
};


class PASCALIMPLEMENTATION TcxfmVerticalGridReportLinkDesignWindow : public Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow
{
	typedef Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshView;
	Vcl::Extctrls::TImage* imgShow;
	Cxpc::TcxTabSheet* tshBehaviors;
	Vcl::Extctrls::TImage* imgExpanding;
	Vcl::Extctrls::TImage* imgGridSize;
	Cxpc::TcxTabSheet* tshFormatting;
	Vcl::Extctrls::TImage* imgLookAndFeel;
	Vcl::Extctrls::TImage* imgRefinements;
	Cxpc::TcxTabSheet* tshStyles;
	Vcl::Extctrls::TBevel* bvlStylesHost;
	Cxstyles::TcxStyleRepository* cxStyleRepository1;
	Cxstyles::TcxStyle* styleCategory;
	Vcl::Menus::TPopupMenu* pmStyles;
	Vcl::Menus::TMenuItem* miStyleFont;
	Vcl::Menus::TMenuItem* miStyleColor;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmap;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmapClear;
	Vcl::Menus::TMenuItem* milLine;
	Vcl::Menus::TMenuItem* miStylesSelectAll;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miStyleRestoreDefaults;
	Vcl::Menus::TMenuItem* miLine4;
	Vcl::Menus::TMenuItem* miStylesSaveAs;
	Vcl::Extctrls::TPanel* pnlPreview;
	Cxvgrid::TcxVerticalGrid* PreviewVGrid;
	Vcl::Extctrls::TImage* imgPagination;
	Cxvgrid::TcxCategoryRow* rowLuxurySedan;
	Cxvgrid::TcxEditorRow* rowManufacturer;
	Cxvgrid::TcxEditorRow* rowModel;
	Cxvgrid::TcxEditorRow* rowPicture;
	Cxvgrid::TcxEditorRow* rowEngine;
	Cxvgrid::TcxEditorRow* rowTransmission;
	Cxvgrid::TcxEditorRow* rowTires;
	Cxstyles::TcxStyle* styleHeader;
	Cxstyles::TcxStyle* styleContent;
	Cxcheckbox::TcxCheckBox* chbxShowHeaders;
	Cxcheckbox::TcxCheckBox* chbxShowExpandButtons;
	Cxcheckbox::TcxCheckBox* chbxShowBorders;
	Cxcheckbox::TcxCheckBox* chbxExpandRows;
	Cxcheckbox::TcxCheckBox* chbxAutoWidth;
	Cxcheckbox::TcxCheckBox* chbxBestFit;
	Cxcheckbox::TcxCheckBox* chbxWrapRecords;
	Cxcheckbox::TcxCheckBox* chbxKeepSameRecordWidths;
	Cxcheckbox::TcxCheckBox* chbxFlatCheckMarks;
	Cxcheckbox::TcxCheckBox* chbxDisplayGraphicsAsText;
	Cxcheckbox::TcxCheckBox* chbxTransparentGraphics;
	Cxcheckbox::TcxCheckBox* chbxSuppressBackgroundBitmaps;
	Cxcheckbox::TcxCheckBox* chbxPaginateByRows;
	Cxcheckbox::TcxCheckBox* chbxPaginateByWrapping;
	Cxcheckbox::TcxCheckBox* chbxOneWrappingPerPage;
	Cxcheckbox::TcxCheckBox* chbxUseNativeStyles;
	Cxlabel::TcxLabel* lblShow;
	Cxlabel::TcxLabel* lblPrintMode;
	Cxlabel::TcxLabel* lblExpanding;
	Cxlabel::TcxLabel* lblSize;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblRefinements;
	Cxlabel::TcxLabel* lblPagination;
	Cxlabel::TcxLabel* lblStyleSheets;
	Cxlabel::TcxLabel* Label1;
	Cxlabel::TcxLabel* lblUseNativeStyles;
	Cxlabel::TcxLabel* lblPreviewWindow;
	Cxlabel::TcxLabel* bvlMultipleRecords;
	Cxdropdownedit::TcxComboBox* cbxPrintMode;
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
	Cxdropdownedit::TcxComboBox* cbxStyleSheets;
	Cxgraphics::TcxImageList* ilStylesPopup;
	void __fastcall LookAndFeelChange(System::TObject* Sender);
	void __fastcall OptionsExpandingClick(System::TObject* Sender);
	void __fastcall OptionsFormattingClick(System::TObject* Sender);
	void __fastcall OptionsPaginationClick(System::TObject* Sender);
	void __fastcall OptionsRefinementsClick(System::TObject* Sender);
	void __fastcall OptionsSizeClick(System::TObject* Sender);
	void __fastcall OptionsViewClick(System::TObject* Sender);
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
	void __fastcall PreviewVGridDrawValue(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxvgrid::TcxvgPainter* APainter, Cxvgrid::TcxRowValueInfo* AValueInfo, bool &Done);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall cbxPrintModeChange(System::TObject* Sender);
	void __fastcall lblUseNativeStylesClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	
private:
	Dxpscxcommon::TdxStylesListBox* lbxStyles;
	Cxstyles::TcxStyle* __fastcall GetActiveStyle(void);
	HIDESBASE Cxvgrid::TcxCustomVerticalGrid* __fastcall GetComponent(void);
	bool __fastcall GetHasSelectedStyles(void);
	bool __fastcall GetHasSelectedStylesWithAssignedBitmap(void);
	HIDESBASE TcxCustomVerticalGridReportLink* __fastcall GetReportLink(void);
	bool __fastcall CanSelectAllStyles(void);
	void __fastcall CreateControls(void);
	void __fastcall CustomDrawTextRect(Cxgraphics::TcxCanvas* ACanvas, Cxvgrid::TcxRowValueInfo* AViewInfo, const System::UnicodeString AText);
	void __fastcall InitializePreviewVerticalGridStyles(void);
	void __fastcall LoadDataIntoPreviewVerticalGrid(void);
	void __fastcall RecreateStylesListBox(void);
	void __fastcall RestoreSelectedStyles(System::Classes::TList* AList);
	void __fastcall SaveSelectedStyles(System::Classes::TList* AList);
	void __fastcall SetActivePage(void);
	void __fastcall UpdatePreviewVerticalGridStyles(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	void __fastcall SetOptionsExpandingByIndex(int Index, bool Value);
	void __fastcall SetOptionsFormattingByIndex(int Index, bool Value);
	void __fastcall SetOptionsPaginationByIndex(int Index, bool Value);
	void __fastcall SetOptionsRefinementsByIndex(int Index, bool Value);
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
	virtual void __fastcall GetStyleSheetNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall GetStyleNames(/* out */ System::Classes::TStrings* &AStrings);
	__property Cxstyles::TcxStyle* ActiveStyle = {read=GetActiveStyle};
	__property Cxvgrid::TcxCustomVerticalGrid* Component = {read=GetComponent};
	__property bool HasSelectedStyles = {read=GetHasSelectedStyles, nodefault};
	__property bool HasSelectedStylesWithAssignedBitmap = {read=GetHasSelectedStylesWithAssignedBitmap, nodefault};
	
public:
	__fastcall virtual TcxfmVerticalGridReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxfmVerticalGridReportLinkDesignWindow(void);
	__property TcxCustomVerticalGridReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmVerticalGridReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmVerticalGridReportLinkDesignWindow(HWND ParentWindow) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 vspsVGridFirst = System::Int8(0x0);
static const System::Int8 vspsVGridContent = System::Int8(0x0);
static const System::Int8 vspsVGridHeader = System::Int8(0x1);
static const System::Int8 vspsVGridCategory = System::Int8(0x2);
static const System::Int8 vspsVGridLast = System::Int8(0x2);
static const System::Int8 cxVerticalGridBaseAttributeID = System::Int8(0x0);
static const System::Int8 cxVerticalGridUndefinedID = System::Int8(0x0);
static const System::Int8 cxVerticalGridCategoryRowID = System::Int8(0x1);
static const System::Int8 cxVerticalGridRowHeaderID = System::Int8(0x2);
static const System::Int8 cxVerticalGridRowHeaderSeparatorID = System::Int8(0x3);
static const System::Int8 cxVerticalGridRowValueID = System::Int8(0x4);
static const System::Int8 cxVerticalGridRowValueSeparatorID = System::Int8(0x5);
static const System::Int8 cxVerticalGridRowIndentID = System::Int8(0x6);
extern PACKAGE Vcl::Graphics::TPicture* __fastcall PreviewImage(void);
extern PACKAGE System::AnsiString __fastcall PreviewImageAsString(void);
}	/* namespace Dxpscxvgridlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXVGRIDLNK)
using namespace Dxpscxvgridlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxvgridlnkHPP
