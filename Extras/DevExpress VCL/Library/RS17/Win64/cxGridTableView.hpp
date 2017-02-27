// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridTableView.pas' rev: 24.00 (Win64)

#ifndef CxgridtableviewHPP
#define CxgridtableviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridDetailsSite.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridtableview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridColumnHeaderAreaPainterClass;

typedef System::TMetaClass* TcxGridColumnHeaderAreaViewInfoClass;

typedef System::TMetaClass* TcxGridColumnHeaderViewInfoClass;

typedef int TcxGridColumnContainerKind;

class DELPHICLASS TcxCustomGridColumnHitTest;
class DELPHICLASS TcxGridColumn;
class PASCALIMPLEMENTATION TcxCustomGridColumnHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	
public:
	TcxGridColumn* Column;
	int ColumnContainerKind;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxCustomGridColumnHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridColumnHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};


class DELPHICLASS TcxGridGroupByBoxHitTest;
class PASCALIMPLEMENTATION TcxGridGroupByBoxHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridGroupByBoxHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridGroupByBoxHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};


class DELPHICLASS TcxGridColumnHeaderHitTest;
class PASCALIMPLEMENTATION TcxGridColumnHeaderHitTest : public TcxCustomGridColumnHitTest
{
	typedef TcxCustomGridColumnHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridColumnHeaderHitTest(void) : TcxCustomGridColumnHitTest() { }
	
};


class DELPHICLASS TcxGridColumnHeaderHorzSizingEdgeHitTest;
class PASCALIMPLEMENTATION TcxGridColumnHeaderHorzSizingEdgeHitTest : public TcxCustomGridColumnHitTest
{
	typedef TcxCustomGridColumnHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderHorzSizingEdgeHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridColumnHeaderHorzSizingEdgeHitTest(void) : TcxCustomGridColumnHitTest() { }
	
};


class DELPHICLASS TcxGridColumnHeaderFilterButtonHitTest;
class PASCALIMPLEMENTATION TcxGridColumnHeaderFilterButtonHitTest : public TcxCustomGridColumnHitTest
{
	typedef TcxCustomGridColumnHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderFilterButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridColumnHeaderFilterButtonHitTest(void) : TcxCustomGridColumnHitTest() { }
	
};


class DELPHICLASS TcxGridHeaderHitTest;
class PASCALIMPLEMENTATION TcxGridHeaderHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridHeaderHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridHeaderHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};


class DELPHICLASS TcxGridFooterHitTest;
class PASCALIMPLEMENTATION TcxGridFooterHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFooterHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFooterHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};


class DELPHICLASS TcxGridFooterCellHitTest;
class PASCALIMPLEMENTATION TcxGridFooterCellHitTest : public TcxCustomGridColumnHitTest
{
	typedef TcxCustomGridColumnHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	Cxcustomdata::TcxDataSummaryItem* SummaryItem;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFooterCellHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFooterCellHitTest(void) : TcxCustomGridColumnHitTest() { }
	
};


class DELPHICLASS TcxGridGroupFooterHitTest;
class PASCALIMPLEMENTATION TcxGridGroupFooterHitTest : public TcxGridFooterHitTest
{
	typedef TcxGridFooterHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridGroupFooterHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridGroupFooterHitTest(void) : TcxGridFooterHitTest() { }
	
};


class DELPHICLASS TcxGridGroupFooterCellHitTest;
class PASCALIMPLEMENTATION TcxGridGroupFooterCellHitTest : public TcxGridFooterCellHitTest
{
	typedef TcxGridFooterCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridGroupFooterCellHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridGroupFooterCellHitTest(void) : TcxGridFooterCellHitTest() { }
	
};


class DELPHICLASS TcxGridRowIndicatorHitTest;
class PASCALIMPLEMENTATION TcxGridRowIndicatorHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	bool MultiSelect;
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridRowIndicatorHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridRowIndicatorHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};


class DELPHICLASS TcxGridRowSizingEdgeHitTest;
class PASCALIMPLEMENTATION TcxGridRowSizingEdgeHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	virtual System::Uitypes::TCursor __fastcall Cursor(void);
	virtual Cxgridcustomview::TcxCustomGridDragAndDropObjectClass __fastcall DragAndDropObjectClass(void);
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridRowSizingEdgeHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridRowSizingEdgeHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};


class DELPHICLASS TcxGridIndicatorHitTest;
class PASCALIMPLEMENTATION TcxGridIndicatorHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridIndicatorHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridIndicatorHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};


class DELPHICLASS TcxGridIndicatorHeaderHitTest;
class PASCALIMPLEMENTATION TcxGridIndicatorHeaderHitTest : public TcxGridIndicatorHitTest
{
	typedef TcxGridIndicatorHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridIndicatorHeaderHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridIndicatorHeaderHitTest(void) : TcxGridIndicatorHitTest() { }
	
};


class DELPHICLASS TcxGridRowLevelIndentHitTest;
class PASCALIMPLEMENTATION TcxGridRowLevelIndentHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridRowLevelIndentHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridRowLevelIndentHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};


class DELPHICLASS TcxGridGroupSummaryHitTest;
class PASCALIMPLEMENTATION TcxGridGroupSummaryHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
private:
	TcxGridColumn* __fastcall GetColumn(void);
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	Cxcustomdata::TcxDataSummaryItem* SummaryItem;
	__property TcxGridColumn* Column = {read=GetColumn};
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridGroupSummaryHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridGroupSummaryHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};


typedef System::TMetaClass* TcxCustomGridRowClass;

class DELPHICLASS TcxCustomGridRow;
class DELPHICLASS TcxGridGroupRow;
class DELPHICLASS TcxGridMasterDataRow;
class DELPHICLASS TcxGridTableView;
class DELPHICLASS TcxGridViewData;
class PASCALIMPLEMENTATION TcxCustomGridRow : public Cxgridcustomtableview::TcxCustomGridRecord
{
	typedef Cxgridcustomtableview::TcxCustomGridRecord inherited;
	
private:
	TcxGridGroupRow* __fastcall GetAsGroupRow(void);
	TcxGridMasterDataRow* __fastcall GetAsMasterDataRow(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetGridViewLevel(void);
	bool __fastcall GetIsFilterRow(void);
	bool __fastcall GetIsNewItemRow(void);
	TcxGridViewData* __fastcall GetViewData(void);
	
protected:
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	
public:
	virtual bool __fastcall ExpandOnDblClick(void);
	virtual bool __fastcall SupportsCellMultiSelect(void);
	__property TcxGridGroupRow* AsGroupRow = {read=GetAsGroupRow};
	__property TcxGridMasterDataRow* AsMasterDataRow = {read=GetAsMasterDataRow};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property Cxgridlevel::TcxGridLevel* GridViewLevel = {read=GetGridViewLevel};
	__property bool IsFilterRow = {read=GetIsFilterRow, nodefault};
	__property bool IsNewItemRow = {read=GetIsNewItemRow, nodefault};
	__property TcxGridViewData* ViewData = {read=GetViewData};
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxCustomGridRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : Cxgridcustomtableview::TcxCustomGridRecord(AViewData, AIndex, ARecordInfo) { }
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxCustomGridRow(void) { }
	
};


class DELPHICLASS TcxGridDataRow;
class PASCALIMPLEMENTATION TcxGridDataRow : public TcxCustomGridRow
{
	typedef TcxCustomGridRow inherited;
	
protected:
	virtual bool __fastcall GetHasCells(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordViewInfoClass __fastcall GetViewInfoClass(void);
	
public:
	virtual bool __fastcall SupportsCellMultiSelect(void);
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxGridDataRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : TcxCustomGridRow(AViewData, AIndex, ARecordInfo) { }
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridDataRow(void) { }
	
};


typedef System::TMetaClass* TcxGridNewItemRowClass;

class DELPHICLASS TcxGridNewItemRow;
class PASCALIMPLEMENTATION TcxGridNewItemRow : public TcxGridDataRow
{
	typedef TcxGridDataRow inherited;
	
public:
	virtual bool __fastcall SupportsCellMultiSelect(void);
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxGridNewItemRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : TcxGridDataRow(AViewData, AIndex, ARecordInfo) { }
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridNewItemRow(void) { }
	
};


typedef System::TMetaClass* TcxGridFilterRowClass;

class DELPHICLASS TcxGridFilterRow;
class PASCALIMPLEMENTATION TcxGridFilterRow : public TcxGridNewItemRow
{
	typedef TcxGridNewItemRow inherited;
	
private:
	bool FSelected;
	void __fastcall ActualizeProperties(Cxedit::TcxCustomEditProperties* AProperties);
	Cxfilter::TcxFilterCriteriaItem* __fastcall GetFilterCriteriaItem(int Index);
	
protected:
	virtual void __fastcall RefreshRecordInfo(void);
	virtual bool __fastcall GetSelected(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall SetSelected(bool Value);
	virtual System::UnicodeString __fastcall GetDisplayText(int Index);
	virtual System::Variant __fastcall GetValue(int Index);
	virtual void __fastcall SetDisplayText(int Index, const System::UnicodeString Value);
	virtual void __fastcall SetValue(int Index, const System::Variant &Value);
	virtual System::UnicodeString __fastcall GetDisplayTextForValue(int AIndex, const System::Variant &AValue);
	virtual Cxfilter::TcxFilterOperatorKind __fastcall GetFilterOperatorKind(const System::Variant &AValue, bool ACheckMask);
	virtual bool __fastcall IsFilterOperatorSupported(Cxfilter::TcxFilterOperatorKind AKind, const System::Variant &AValue);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	__property Cxfilter::TcxFilterCriteriaItem* FilterCriteriaItems[int Index] = {read=GetFilterCriteriaItem};
	__property bool InternalSelected = {read=FSelected, write=FSelected, nodefault};
	
public:
	__fastcall virtual ~TcxGridFilterRow(void);
	virtual bool __fastcall CanFocusCells(void);
	bool __fastcall IsEmpty(void);
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxGridFilterRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : TcxGridNewItemRow(AViewData, AIndex, ARecordInfo) { }
	
};


class PASCALIMPLEMENTATION TcxGridMasterDataRow : public TcxGridDataRow
{
	typedef TcxGridDataRow inherited;
	
private:
	Cxgridcustomview::TcxCustomGridView* __fastcall GetActiveDetailGridView(void);
	bool __fastcall GetActiveDetailGridViewExists(void);
	int __fastcall GetActiveDetailIndex(void);
	Cxgridlevel::TcxGridLevel* __fastcall GetActiveDetailLevel(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetDetailGridView(int Index);
	int __fastcall GetDetailGridViewCount(void);
	bool __fastcall GetDetailGridViewExists(int Index);
	bool __fastcall GetDetailGridViewHasData(int Index);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetInternalActiveDetailGridView(void);
	bool __fastcall GetInternalActiveDetailGridViewExists(void);
	int __fastcall GetInternalActiveDetailIndex(void);
	void __fastcall SetActiveDetailIndex(int Value);
	void __fastcall SetActiveDetailLevel(Cxgridlevel::TcxGridLevel* Value);
	
protected:
	virtual void __fastcall DoCollapse(bool ARecurse);
	virtual void __fastcall DoExpand(bool ARecurse);
	virtual bool __fastcall GetExpandable(void);
	virtual bool __fastcall GetExpanded(void);
	virtual bool __fastcall GetHasChildren(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall ToggleExpanded(void);
	__property Cxgridcustomview::TcxCustomGridView* InternalActiveDetailGridView = {read=GetInternalActiveDetailGridView};
	__property bool InternalActiveDetailGridViewExists = {read=GetInternalActiveDetailGridViewExists, nodefault};
	__property int InternalActiveDetailIndex = {read=GetInternalActiveDetailIndex, nodefault};
	
public:
	virtual bool __fastcall ExpandOnDblClick(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetFirstFocusableChild(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetLastFocusableChild(bool ARecursive);
	__property Cxgridcustomview::TcxCustomGridView* ActiveDetailGridView = {read=GetActiveDetailGridView};
	__property bool ActiveDetailGridViewExists = {read=GetActiveDetailGridViewExists, nodefault};
	__property int ActiveDetailIndex = {read=GetActiveDetailIndex, write=SetActiveDetailIndex, nodefault};
	__property Cxgridlevel::TcxGridLevel* ActiveDetailLevel = {read=GetActiveDetailLevel, write=SetActiveDetailLevel};
	__property int DetailGridViewCount = {read=GetDetailGridViewCount, nodefault};
	__property bool DetailGridViewExists[int Index] = {read=GetDetailGridViewExists};
	__property bool DetailGridViewHasData[int Index] = {read=GetDetailGridViewHasData};
	__property Cxgridcustomview::TcxCustomGridView* DetailGridViews[int Index] = {read=GetDetailGridView};
	__property bool HasChildren = {read=GetHasChildren, nodefault};
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxGridMasterDataRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : TcxGridDataRow(AViewData, AIndex, ARecordInfo) { }
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridMasterDataRow(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridGroupRow : public TcxCustomGridRow
{
	typedef TcxCustomGridRow inherited;
	
private:
	TcxGridColumn* __fastcall GetGroupedColumn(void);
	Cxcustomdata::TcxDataGroupSummaryItems* __fastcall GetGroupSummaryItems(void);
	
protected:
	virtual void __fastcall DoCollapse(bool ARecurse);
	virtual void __fastcall DoExpand(bool ARecurse);
	virtual bool __fastcall GetExpandable(void);
	virtual bool __fastcall GetExpanded(void);
	virtual System::UnicodeString __fastcall GetDisplayCaption(void);
	virtual System::UnicodeString __fastcall GetDisplayText(int Index);
	virtual System::UnicodeString __fastcall GetDisplayTextValue(void);
	virtual bool __fastcall GetIsData(void);
	virtual bool __fastcall GetIsParent(void);
	HIDESBASE virtual System::Variant __fastcall GetValue(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall SetDisplayText(int Index, const System::UnicodeString Value);
	virtual void __fastcall SetValue(int Index, const System::Variant &Value);
	
public:
	bool __fastcall GetGroupSummaryInfo(Cxcustomdata::TcxDataSummaryItems* &ASummaryItems, System::PVariant &ASummaryValues);
	__property System::UnicodeString DisplayCaption = {read=GetDisplayCaption};
	__property System::UnicodeString DisplayText = {read=GetDisplayTextValue};
	__property TcxGridColumn* GroupedColumn = {read=GetGroupedColumn};
	__property Cxcustomdata::TcxDataGroupSummaryItems* GroupSummaryItems = {read=GetGroupSummaryItems};
	__property System::Variant Value = {read=GetValue};
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxGridGroupRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : TcxCustomGridRow(AViewData, AIndex, ARecordInfo) { }
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridGroupRow(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridViewData : public Cxgridcustomtableview::TcxCustomGridTableViewData
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewData inherited;
	
private:
	TcxGridFilterRow* FFilterRow;
	TcxGridNewItemRow* __fastcall GetNewItemRow(void);
	TcxCustomGridRow* __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	
protected:
	virtual TcxGridMasterDataRow* __fastcall GetFirstVisibleExpandedMasterRow(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetNewItemRecordClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetRecordByKind(int AKind, int AIndex);
	virtual int __fastcall GetRecordKind(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetDataRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetGroupRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetMasterRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
	void __fastcall CreateFilterRow(void);
	void __fastcall DestroyFilterRow(void);
	void __fastcall CheckFilterRow(void);
	virtual TcxGridFilterRowClass __fastcall GetFilterRowClass(void);
	
public:
	__fastcall virtual ~TcxGridViewData(void);
	virtual void __fastcall Collapse(bool ARecurse);
	virtual void __fastcall Expand(bool ARecurse);
	virtual bool __fastcall HasFilterRow(void);
	virtual bool __fastcall HasNewItemRecord(void);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall MakeDetailVisible(System::Classes::TComponent* ADetailLevel);
	__property TcxGridFilterRow* FilterRow = {read=FFilterRow};
	__property TcxGridNewItemRow* NewItemRow = {read=GetNewItemRow};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxCustomGridRow* Rows[int Index] = {read=GetRow};
public:
	/* TcxCustomGridTableViewData.Create */ inline __fastcall virtual TcxGridViewData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableViewData(AGridView) { }
	
};


typedef System::TMetaClass* TcxGridColumnHeaderMovingObjectClass;

class DELPHICLASS TcxGridColumnHeaderMovingObject;
class DELPHICLASS TcxGridTableViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnHeaderMovingObject : public Cxgridcustomtableview::TcxCustomGridTableItemMovingObject
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemMovingObject inherited;
	
private:
	int FOriginalDestColumnContainerKind;
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	TcxGridColumn* __fastcall GetSourceItem(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetSourceItem(TcxGridColumn* Value);
	
protected:
	virtual void __fastcall CalculateDestParams(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, /* out */ int &AContainerKind, /* out */ Cxgridcustomtableview::TcxGridItemContainerZone* &AZone);
	virtual bool __fastcall CanRemove(void);
	virtual void __fastcall CheckDestItemContainerKind(int &AValue);
	virtual void __fastcall DoColumnMoving(void);
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(Cxcontrols::TcxArrowPlace APlace);
	virtual System::Types::TRect __fastcall GetArrowAreaBoundsForHeader(Cxcontrols::TcxArrowPlace APlace);
	virtual System::Types::TRect __fastcall GetArrowsClientRect(void);
	virtual Cxgridcustomview::TcxCustomGridCellViewInfo* __fastcall GetSourceItemViewInfo(void);
	virtual bool __fastcall IsValidDestination(void);
	virtual bool __fastcall IsValidDestinationForVisibleSource(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property int OriginalDestColumnContainerKind = {read=FOriginalDestColumnContainerKind, write=FOriginalDestColumnContainerKind, nodefault};
	__property TcxGridColumn* SourceItem = {read=GetSourceItem, write=SetSourceItem};
	__property TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Init(const System::Types::TPoint P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxCustomGridTableItemMovingObject.Create */ inline __fastcall virtual TcxGridColumnHeaderMovingObject(Cxcontrols::TcxControl* AControl) : Cxgridcustomtableview::TcxCustomGridTableItemMovingObject(AControl) { }
	/* TcxCustomGridTableItemMovingObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderMovingObject(void) { }
	
};


class DELPHICLASS TcxCustomGridSizingObject;
class DELPHICLASS TcxGridTableController;
class PASCALIMPLEMENTATION TcxCustomGridSizingObject : public Cxgridcustomview::TcxCustomGridDragAndDropObject
{
	typedef Cxgridcustomview::TcxCustomGridDragAndDropObject inherited;
	
private:
	int FDestPointX;
	int FDestPointY;
	int FOriginalSize;
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetDestPointX(int Value);
	void __fastcall SetDestPointY(int Value);
	
protected:
	virtual void __fastcall DirtyChanged(void);
	virtual int __fastcall GetCurrentSize(void);
	virtual int __fastcall GetDeltaSize(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual System::Types::TRect __fastcall GetHorzSizingMarkBounds(void);
	virtual bool __fastcall GetImmediateStart(void);
	virtual bool __fastcall GetIsHorizontalSizing(void);
	virtual System::Types::TRect __fastcall GetSizingItemBounds(void) = 0 ;
	virtual System::Types::TRect __fastcall GetSizingMarkBounds(void);
	virtual int __fastcall GetSizingMarkWidth(void) = 0 ;
	virtual System::Types::TRect __fastcall GetVertSizingMarkBounds(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	__property TcxGridTableController* Controller = {read=GetController};
	__property int CurrentSize = {read=GetCurrentSize, nodefault};
	__property int DeltaSize = {read=GetDeltaSize, nodefault};
	__property int DestPointX = {read=FDestPointX, write=SetDestPointX, nodefault};
	__property int DestPointY = {read=FDestPointY, write=SetDestPointY, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property bool IsHorizontalSizing = {read=GetIsHorizontalSizing, nodefault};
	__property int OriginalSize = {read=FOriginalSize, write=FOriginalSize, nodefault};
	__property System::Types::TRect SizingItemBounds = {read=GetSizingItemBounds};
	__property System::Types::TRect SizingMarkBounds = {read=GetSizingMarkBounds};
	__property int SizingMarkWidth = {read=GetSizingMarkWidth, nodefault};
	__property TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall BeforeScrolling(void);
	virtual void __fastcall Init(const System::Types::TPoint P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxCustomGridSizingObject(Cxcontrols::TcxControl* AControl) : Cxgridcustomview::TcxCustomGridDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridSizingObject(void) { }
	
};


class DELPHICLASS TcxCustomGridColumnSizingObject;
class DELPHICLASS TcxGridColumnHeaderViewInfo;
class PASCALIMPLEMENTATION TcxCustomGridColumnSizingObject : public TcxCustomGridSizingObject
{
	typedef TcxCustomGridSizingObject inherited;
	
private:
	TcxGridColumn* FColumn;
	TcxGridColumnHeaderViewInfo* __fastcall GetColumnHeaderViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall GetSizingItemBounds(void);
	virtual int __fastcall GetSizingMarkWidth(void);
	__property TcxGridColumn* Column = {read=FColumn, write=FColumn};
	__property TcxGridColumnHeaderViewInfo* ColumnHeaderViewInfo = {read=GetColumnHeaderViewInfo};
	
public:
	virtual void __fastcall Init(const System::Types::TPoint P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxCustomGridColumnSizingObject(Cxcontrols::TcxControl* AControl) : TcxCustomGridSizingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridColumnSizingObject(void) { }
	
};


class DELPHICLASS TcxGridColumnHorzSizingObject;
class PASCALIMPLEMENTATION TcxGridColumnHorzSizingObject : public TcxCustomGridColumnSizingObject
{
	typedef TcxCustomGridColumnSizingObject inherited;
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual int __fastcall GetCurrentSize(void);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxGridColumnHorzSizingObject(Cxcontrols::TcxControl* AControl) : TcxCustomGridColumnSizingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHorzSizingObject(void) { }
	
};


class DELPHICLASS TcxGridRowSizingObject;
class DELPHICLASS TcxCustomGridRowViewInfo;
class PASCALIMPLEMENTATION TcxGridRowSizingObject : public TcxCustomGridSizingObject
{
	typedef TcxCustomGridSizingObject inherited;
	
private:
	TcxCustomGridRow* FRow;
	TcxCustomGridRowViewInfo* __fastcall GetRowViewInfo(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual int __fastcall GetCurrentSize(void);
	virtual bool __fastcall GetIsHorizontalSizing(void);
	virtual System::Types::TRect __fastcall GetSizingItemBounds(void);
	virtual int __fastcall GetSizingMarkWidth(void);
	__property TcxCustomGridRow* Row = {read=FRow};
	__property TcxCustomGridRowViewInfo* RowViewInfo = {read=GetRowViewInfo};
	
public:
	virtual void __fastcall Init(const System::Types::TPoint P, Cxgridcustomview::TcxCustomGridHitTest* AParams);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxGridRowSizingObject(Cxcontrols::TcxControl* AControl) : TcxCustomGridSizingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridRowSizingObject(void) { }
	
};


class DELPHICLASS TcxGridTableItemsListBox;
class PASCALIMPLEMENTATION TcxGridTableItemsListBox : public Cxgridcustomtableview::TcxCustomGridTableItemsListBox
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemsListBox inherited;
	
private:
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	
protected:
	virtual int __fastcall CalculateItemHeight(void);
	virtual bool __fastcall DrawItemDrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds) = 0 ;
	virtual bool __fastcall GetItemEndEllipsis(void) = 0 ;
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall UpdateBackgroundColor(void);
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, nodefault};
	
public:
	__fastcall virtual TcxGridTableItemsListBox(System::Classes::TComponent* AOwner);
	virtual void __fastcall PaintItem(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, int AIndex, bool AFocused);
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxGridTableItemsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridTableItemsListBox(HWND ParentWindow) : Cxgridcustomtableview::TcxCustomGridTableItemsListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxGridTableColumnsListBox;
class PASCALIMPLEMENTATION TcxGridTableColumnsListBox : public TcxGridTableItemsListBox
{
	typedef TcxGridTableItemsListBox inherited;
	
protected:
	virtual void __fastcall DoRefreshItems(void);
	virtual bool __fastcall DrawItemDrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetDragAndDropParams(void);
	virtual bool __fastcall GetItemEndEllipsis(void);
public:
	/* TcxGridTableItemsListBox.Create */ inline __fastcall virtual TcxGridTableColumnsListBox(System::Classes::TComponent* AOwner) : TcxGridTableItemsListBox(AOwner) { }
	
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxGridTableColumnsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridTableColumnsListBox(HWND ParentWindow) : TcxGridTableItemsListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxGridTableCustomizationForm;
class PASCALIMPLEMENTATION TcxGridTableCustomizationForm : public Cxgridcustomtableview::TcxCustomGridTableCustomizationForm
{
	typedef Cxgridcustomtableview::TcxCustomGridTableCustomizationForm inherited;
	
private:
	TcxGridTableColumnsListBox* __fastcall GetColumnsListBox(void);
	Cxpc::TcxTabSheet* __fastcall GetColumnsPage(void);
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridTableItemsListBoxClass __fastcall GetItemsListBoxClass(void);
	virtual System::UnicodeString __fastcall GetItemsPageCaption(void);
	__property TcxGridTableColumnsListBox* ColumnsListBox = {read=GetColumnsListBox};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__property TcxGridTableController* Controller = {read=GetController};
	__property Cxpc::TcxTabSheet* ColumnsPage = {read=GetColumnsPage};
public:
	/* TcxCustomGridCustomizationForm.Create */ inline __fastcall virtual TcxGridTableCustomizationForm(Cxgridcustomview::TcxCustomGridController* AController) : Cxgridcustomtableview::TcxCustomGridTableCustomizationForm(AController) { }
	/* TcxCustomGridCustomizationForm.Destroy */ inline __fastcall virtual ~TcxGridTableCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridTableCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomtableview::TcxCustomGridTableCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridTableCustomizationForm(HWND ParentWindow) : Cxgridcustomtableview::TcxCustomGridTableCustomizationForm(ParentWindow) { }
	
};


class DELPHICLASS TcxGridDragOpenInfoMasterDataRowTab;
class PASCALIMPLEMENTATION TcxGridDragOpenInfoMasterDataRowTab : public Cxgrid::TcxGridDragOpenInfoTab
{
	typedef Cxgrid::TcxGridDragOpenInfoTab inherited;
	
public:
	TcxGridMasterDataRow* GridRow;
	__fastcall virtual TcxGridDragOpenInfoMasterDataRowTab(Cxgridlevel::TcxGridLevel* ALevel, TcxGridMasterDataRow* AGridRow);
	virtual bool __fastcall Equals(Cxgridcommon::TcxCustomGridDragOpenInfo* AInfo);
	virtual void __fastcall Run(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDragOpenInfoMasterDataRowTab(void) { }
	
};


class DELPHICLASS TcxGridColumnsCustomizationPopup;
class PASCALIMPLEMENTATION TcxGridColumnsCustomizationPopup : public Cxgridcustomtableview::TcxCustomGridItemsCustomizationPopup
{
	typedef Cxgridcustomtableview::TcxCustomGridItemsCustomizationPopup inherited;
	
private:
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked);
	virtual void __fastcall SetItemIndex(System::TObject* AItem, int AIndex);
	
public:
	__property TcxGridTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridCustomizationPopup.Create */ inline __fastcall virtual TcxGridColumnsCustomizationPopup(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridItemsCustomizationPopup(AGridView) { }
	
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxGridColumnsCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridColumnsCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomtableview::TcxCustomGridItemsCustomizationPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridColumnsCustomizationPopup(HWND ParentWindow) : Cxgridcustomtableview::TcxCustomGridItemsCustomizationPopup(ParentWindow) { }
	
};


class DELPHICLASS TcxGridTableEditingController;
class PASCALIMPLEMENTATION TcxGridTableEditingController : public Cxgridcustomtableview::TcxGridEditingController
{
	typedef Cxgridcustomtableview::TcxGridEditingController inherited;
	
private:
	Cxclasses::TcxTimer* FDelayedFilteringTimer;
	bool FApplyingImmediateFiltering;
	TcxGridTableController* __fastcall GetController(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	
protected:
	void __fastcall ApplyFilterRowFiltering(void);
	virtual bool __fastcall CanInitEditing(void);
	virtual bool __fastcall CanUpdateEditValue(void);
	virtual void __fastcall DoEditChanged(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall GetHideEditOnFocusedRecordChange(void);
	virtual void __fastcall InitEdit(void);
	virtual bool __fastcall IsNeedInvokeEditChangedEventsBeforePost(void);
	virtual void __fastcall PostEditingData(void);
	void __fastcall StartDelayingFiltering(void);
	void __fastcall OnDelayingFilteringTimer(System::TObject* Sender);
	__property bool ApplyingImmediateFiltering = {read=FApplyingImmediateFiltering, write=FApplyingImmediateFiltering, nodefault};
	
public:
	__fastcall virtual ~TcxGridTableEditingController(void);
	virtual void __fastcall HideEdit(bool Accept);
	__property TcxGridTableController* Controller = {read=GetController};
	__property TcxGridTableView* GridView = {read=GetGridView};
public:
	/* TcxGridEditingController.Create */ inline __fastcall virtual TcxGridTableEditingController(Cxgridcustomtableview::TcxCustomGridTableController* AController) : Cxgridcustomtableview::TcxGridEditingController(AController) { }
	
};


class PASCALIMPLEMENTATION TcxGridTableController : public Cxgridcustomtableview::TcxCustomGridTableController
{
	typedef Cxgridcustomtableview::TcxCustomGridTableController inherited;
	
private:
	TcxGridColumn* FCellSelectionAnchor;
	TcxGridColumn* FHorzSizingColumn;
	bool FIsFilterPopupOpenedFromHeader;
	bool FKeepFilterRowFocusing;
	int FLeftPos;
	TcxGridColumn* FPressedColumn;
	System::Classes::TList* FSelectedColumns;
	TcxGridColumnsCustomizationPopup* __fastcall GetColumnsCustomizationPopup(void);
	TcxGridTableCustomizationForm* __fastcall GetCustomizationForm(void);
	TcxGridTableEditingController* __fastcall GetEditingController(void);
	TcxGridColumn* __fastcall GetFocusedColumn(void);
	int __fastcall GetFocusedColumnIndex(void);
	TcxCustomGridRow* __fastcall GetFocusedRow(void);
	int __fastcall GetFocusedRowIndex(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	bool __fastcall GetIsColumnHorzSizing(void);
	TcxGridColumn* __fastcall GetSelectedColumn(int Index);
	int __fastcall GetSelectedColumnCount(void);
	TcxCustomGridRow* __fastcall GetSelectedRow(int Index);
	int __fastcall GetSelectedRowCount(void);
	int __fastcall GetTopRowIndex(void);
	HIDESBASE TcxGridViewData* __fastcall GetViewData(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetFocusedColumn(TcxGridColumn* Value);
	void __fastcall SetFocusedColumnIndex(int Value);
	void __fastcall SetFocusedRow(TcxCustomGridRow* Value);
	void __fastcall SetFocusedRowIndex(int Value);
	void __fastcall SetLeftPos(int Value);
	void __fastcall SetPressedColumn(TcxGridColumn* Value);
	void __fastcall SetTopRowIndex(int Value);
	void __fastcall AddSelectedColumn(TcxGridColumn* AColumn);
	void __fastcall RemoveSelectedColumn(TcxGridColumn* AColumn);
	
protected:
	virtual bool __fastcall CanAppend(bool ACheckOptions);
	virtual bool __fastcall CanDelete(bool ACheckOptions);
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanInsert(bool ACheckOptions);
	virtual bool __fastcall CanUseAutoHeightEditing(void);
	virtual void __fastcall CheckCoordinates(void);
	void __fastcall CheckLeftPos(int &Value);
	virtual void __fastcall FocusedItemChanged(Cxgridcustomtableview::TcxCustomGridTableItem* APrevFocusedItem);
	virtual void __fastcall FocusedRecordChanged(int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedDataRecordIndex, int AFocusedDataRecordIndex, bool ANewItemRecordFocusingChanged);
	virtual bool __fastcall GetDesignHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual Cxgridcustomtableview::TcxCustomGridRecord* __fastcall GetFocusedRecord(void);
	virtual bool __fastcall GetIsRecordsScrollHorizontal(void);
	virtual Cxgridcustomtableview::TcxCustomGridItemsCustomizationPopupClass __fastcall GetItemsCustomizationPopupClass(void);
	virtual int __fastcall GetMaxTopRecordIndexValue(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual int __fastcall GetScrollBarRecordCount(void);
	virtual bool __fastcall IsColumnFixedDuringHorzSizing(TcxGridColumn* AColumn);
	virtual bool __fastcall IsKeyForMultiSelect(System::Word AKey, System::Classes::TShiftState AShift, bool AFocusedRecordChanged);
	virtual bool __fastcall IsPixelScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall LeftPosChanged(void);
	virtual bool __fastcall NeedsAdditionalRowsScrolling(bool AIsCallFromMaster = false);
	virtual void __fastcall RemoveFocus(void);
	virtual void __fastcall ScrollData(Cxclasses::TcxDirection ADirection);
	virtual void __fastcall SetFocusedRecord(Cxgridcustomtableview::TcxCustomGridRecord* Value);
	virtual void __fastcall ShowNextPage(void);
	virtual void __fastcall ShowPrevPage(void);
	virtual void __fastcall CreateGridViewItem(System::TObject* Sender);
	virtual void __fastcall DeleteGridViewItem(System::Classes::TPersistent* AItem);
	virtual void __fastcall DeleteGridViewItems(System::TObject* Sender);
	virtual void __fastcall PopulateColumnHeaderDesignPopupMenu(Vcl::Menus::TPopupMenu* AMenu);
	virtual void __fastcall DoScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall CanScrollData(Cxclasses::TcxDirection ADirection);
	virtual bool __fastcall CanPostponeRecordSelection(System::Classes::TShiftState AShift);
	virtual bool __fastcall CanProcessMultiSelect(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift)/* overload */;
	virtual void __fastcall DoMouseNormalSelection(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall DoMouseRangeSelection(bool AClearSelection = true, System::TObject* AData = (System::TObject*)(0x0));
	virtual void __fastcall DoNormalSelection(void);
	virtual void __fastcall MultiSelectKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall SupportsAdditiveSelection(void);
	virtual bool __fastcall SupportsRecordSelectionToggling(void);
	virtual bool __fastcall DefocusSpecialRow(void);
	virtual bool __fastcall FocusSpecialRow(void);
	virtual void __fastcall FilterRowFocusChanged(void);
	virtual void __fastcall FilterRowFocusChanging(bool AValue);
	virtual void __fastcall DoPullFocusingScrolling(Cxclasses::TcxDirection ADirection);
	virtual bool __fastcall GetPullFocusingScrollingDirection(int X, int Y, /* out */ Cxclasses::TcxDirection &ADirection);
	virtual bool __fastcall SupportsPullFocusing(void);
	virtual Cxgridcommon::TcxCustomGridDragOpenInfo* __fastcall GetDragOpenInfo(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual Cxclasses::TcxDirection __fastcall GetDragScrollDirection(int X, int Y);
	virtual void __fastcall CheckCustomizationFormBounds(System::Types::TRect &R);
	virtual TcxGridColumnHeaderMovingObjectClass __fastcall GetColumnHeaderDragAndDropObjectClass(void);
	virtual Cxgridcustomview::TcxCustomGridCustomizationFormClass __fastcall GetCustomizationFormClass(void);
	virtual bool __fastcall CanProcessCellMultiSelect(TcxGridColumn* APrevFocusedColumn);
	virtual void __fastcall CellMultiSelectKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall DoNormalCellSelection(void);
	void __fastcall DoRangeCellSelection(void);
	virtual bool __fastcall GetCellMultiSelect(void);
	__property bool CellMultiSelect = {read=GetCellMultiSelect, nodefault};
	void __fastcall AddBeginsWithMask(System::Variant &AValue);
	void __fastcall RemoveBeginsWithMask(System::Variant &AValue);
	int __fastcall GetBeginsWithMaskPos(const System::UnicodeString AValue);
	virtual Cxgridcustomtableview::TcxGridEditingControllerClass __fastcall GetEditingControllerClass(void);
	__property bool IsFilterPopupOpenedFromHeader = {read=FIsFilterPopupOpenedFromHeader, write=FIsFilterPopupOpenedFromHeader, nodefault};
	__property bool KeepFilterRowFocusing = {read=FKeepFilterRowFocusing, write=FKeepFilterRowFocusing, nodefault};
	__property TcxGridViewData* ViewData = {read=GetViewData};
	__property TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxGridTableController(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridTableController(void);
	virtual void __fastcall CheckScrolling(const System::Types::TPoint P);
	void __fastcall ClearGrouping(void);
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall DoCancelMode(void);
	bool __fastcall IsFilterRowFocused(void);
	bool __fastcall IsNewItemRowFocused(void);
	virtual bool __fastcall IsSpecialRowFocused(void);
	virtual void __fastcall MakeItemVisible(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall SelectAll(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsDataFullyVisible(bool AIsCallFromMaster = false);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual void __fastcall DoKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ClearCellSelection(void);
	void __fastcall SelectAllColumns(void);
	void __fastcall SelectCells(TcxGridColumn* AFromColumn, TcxGridColumn* AToColumn, int AFromRowIndex, int AToRowIndex);
	void __fastcall SelectColumns(TcxGridColumn* AFromColumn, TcxGridColumn* AToColumn);
	__property TcxGridColumn* CellSelectionAnchor = {read=FCellSelectionAnchor, write=FCellSelectionAnchor};
	__property TcxGridColumnsCustomizationPopup* ColumnsCustomizationPopup = {read=GetColumnsCustomizationPopup};
	__property TcxGridTableCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
	__property TcxGridTableEditingController* EditingController = {read=GetEditingController};
	__property TcxGridColumn* FocusedColumn = {read=GetFocusedColumn, write=SetFocusedColumn};
	__property int FocusedColumnIndex = {read=GetFocusedColumnIndex, write=SetFocusedColumnIndex, nodefault};
	__property TcxCustomGridRow* FocusedRow = {read=GetFocusedRow, write=SetFocusedRow};
	__property int FocusedRowIndex = {read=GetFocusedRowIndex, write=SetFocusedRowIndex, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridColumn* HorzSizingColumn = {read=FHorzSizingColumn};
	__property bool IsColumnHorzSizing = {read=GetIsColumnHorzSizing, nodefault};
	__property int LeftPos = {read=FLeftPos, write=SetLeftPos, nodefault};
	__property TcxGridColumn* PressedColumn = {read=FPressedColumn, write=SetPressedColumn};
	__property int SelectedColumnCount = {read=GetSelectedColumnCount, nodefault};
	__property TcxGridColumn* SelectedColumns[int Index] = {read=GetSelectedColumn};
	__property int SelectedRowCount = {read=GetSelectedRowCount, nodefault};
	__property TcxCustomGridRow* SelectedRows[int Index] = {read=GetSelectedRow};
	__property int TopRowIndex = {read=GetTopRowIndex, write=SetTopRowIndex, nodefault};
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanProcessMultiSelect(bool AIsKeyboard){ return Cxgridcustomtableview::TcxCustomGridTableController::CanProcessMultiSelect(AIsKeyboard); }
	inline bool __fastcall  CanProcessMultiSelect(System::Word AKey, System::Classes::TShiftState AShift, bool AFocusedRecordChanged){ return Cxgridcustomtableview::TcxCustomGridTableController::CanProcessMultiSelect(AKey, AShift, AFocusedRecordChanged); }
	
};


class DELPHICLASS TcxGridColumnContainerPainter;
class DELPHICLASS TcxGridColumnContainerViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnContainerPainter : public Cxgridcustomtableview::TcxCustomGridPartPainter
{
	typedef Cxgridcustomtableview::TcxCustomGridPartPainter inherited;
	
private:
	TcxGridColumnContainerViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawItems(void);
	virtual bool __fastcall DrawItemsFirst(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridColumnContainerViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridColumnContainerPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomtableview::TcxCustomGridPartPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnContainerPainter(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderAreaPainter;
class DELPHICLASS TcxGridColumnHeaderAreaViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnHeaderAreaPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridColumnHeaderAreaViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridColumnHeaderAreaViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridColumnHeaderAreaPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderAreaPainter(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderSortingMarkPainter;
class PASCALIMPLEMENTATION TcxGridColumnHeaderSortingMarkPainter : public TcxGridColumnHeaderAreaPainter
{
	typedef TcxGridColumnHeaderAreaPainter inherited;
	
protected:
	virtual void __fastcall Paint(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridColumnHeaderSortingMarkPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnHeaderAreaPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderSortingMarkPainter(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderFilterButtonPainter;
class DELPHICLASS TcxGridColumnHeaderFilterButtonViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnHeaderFilterButtonPainter : public TcxGridColumnHeaderAreaPainter
{
	typedef TcxGridColumnHeaderAreaPainter inherited;
	
private:
	Cxlookandfeelpainters::TcxFilterSmartTagState __fastcall GetSmartTagState(void);
	HIDESBASE TcxGridColumnHeaderFilterButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property Cxlookandfeelpainters::TcxFilterSmartTagState SmartTagState = {read=GetSmartTagState, nodefault};
	__property TcxGridColumnHeaderFilterButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridColumnHeaderFilterButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnHeaderAreaPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderFilterButtonPainter(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderGlyphPainter;
class DELPHICLASS TcxGridColumnHeaderGlyphViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnHeaderGlyphPainter : public TcxGridColumnHeaderAreaPainter
{
	typedef TcxGridColumnHeaderAreaPainter inherited;
	
private:
	HIDESBASE TcxGridColumnHeaderGlyphViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridColumnHeaderGlyphViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridColumnHeaderGlyphPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnHeaderAreaPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderGlyphPainter(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderPainter;
class PASCALIMPLEMENTATION TcxGridColumnHeaderPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridColumnHeaderViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall BeforePaint(void);
	virtual void __fastcall DrawAreas(void);
	virtual void __fastcall DrawBorders(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawPressed(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	virtual void __fastcall Paint(void);
	__property TcxGridColumnHeaderViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridColumnHeaderPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderPainter(void) { }
	
};


class DELPHICLASS TcxGridHeaderPainter;
class PASCALIMPLEMENTATION TcxGridHeaderPainter : public TcxGridColumnContainerPainter
{
	typedef TcxGridColumnContainerPainter inherited;
	
protected:
	virtual bool __fastcall DrawItemsFirst(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridHeaderPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnContainerPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridHeaderPainter(void) { }
	
};


class DELPHICLASS TcxGridGroupByBoxPainter;
class DELPHICLASS TcxGridGroupByBoxViewInfo;
class PASCALIMPLEMENTATION TcxGridGroupByBoxPainter : public TcxGridColumnContainerPainter
{
	typedef TcxGridColumnContainerPainter inherited;
	
private:
	HIDESBASE TcxGridGroupByBoxViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(const System::Types::TRect &R)/* overload */;
	void __fastcall DrawConnectors(void);
	virtual void __fastcall DrawContent(void);
	virtual bool __fastcall DrawItemsFirst(void);
	__property TcxGridGroupByBoxViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridGroupByBoxPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnContainerPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupByBoxPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(void){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(); }
	
};


class DELPHICLASS TcxGridFooterCellPainter;
class PASCALIMPLEMENTATION TcxGridFooterCellPainter : public TcxGridColumnHeaderPainter
{
	typedef TcxGridColumnHeaderPainter inherited;
	
protected:
	virtual void __fastcall DrawBorders(void);
	virtual void __fastcall DrawContent(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFooterCellPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnHeaderPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFooterCellPainter(void) { }
	
};


typedef System::TMetaClass* TcxGridFooterPainterClass;

class DELPHICLASS TcxGridFooterPainter;
class DELPHICLASS TcxGridFooterViewInfo;
class PASCALIMPLEMENTATION TcxGridFooterPainter : public TcxGridColumnContainerPainter
{
	typedef TcxGridColumnContainerPainter inherited;
	
private:
	HIDESBASE TcxGridFooterViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(const System::Types::TRect &R)/* overload */;
	virtual void __fastcall DrawBorders(void);
	virtual bool __fastcall DrawItemsFirst(void);
	virtual void __fastcall DrawSeparator(void);
	__property TcxGridFooterViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFooterPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxGridColumnContainerPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFooterPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(void){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(); }
	
};


class DELPHICLASS TcxCustomGridIndicatorItemPainter;
class DELPHICLASS TcxCustomGridIndicatorItemViewInfo;
class PASCALIMPLEMENTATION TcxCustomGridIndicatorItemPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxCustomGridIndicatorItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxCustomGridIndicatorItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxCustomGridIndicatorItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridIndicatorItemPainter(void) { }
	
};


class DELPHICLASS TcxGridIndicatorHeaderItemPainter;
class DELPHICLASS TcxGridIndicatorHeaderItemViewInfo;
class PASCALIMPLEMENTATION TcxGridIndicatorHeaderItemPainter : public TcxCustomGridIndicatorItemPainter
{
	typedef TcxCustomGridIndicatorItemPainter inherited;
	
private:
	HIDESBASE TcxGridIndicatorHeaderItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall DrawBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawQuickCustomizationMark(void);
	__property TcxGridIndicatorHeaderItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridIndicatorHeaderItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridIndicatorItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridIndicatorHeaderItemPainter(void) { }
	
};


class DELPHICLASS TcxGridIndicatorRowItemPainter;
class DELPHICLASS TcxGridIndicatorRowItemViewInfo;
class PASCALIMPLEMENTATION TcxGridIndicatorRowItemPainter : public TcxCustomGridIndicatorItemPainter
{
	typedef TcxCustomGridIndicatorItemPainter inherited;
	
private:
	HIDESBASE TcxGridIndicatorRowItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	__property TcxGridIndicatorRowItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridIndicatorRowItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridIndicatorItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridIndicatorRowItemPainter(void) { }
	
};


class DELPHICLASS TcxGridIndicatorFooterItemPainter;
class DELPHICLASS TcxGridIndicatorFooterItemViewInfo;
class PASCALIMPLEMENTATION TcxGridIndicatorFooterItemPainter : public TcxCustomGridIndicatorItemPainter
{
	typedef TcxCustomGridIndicatorItemPainter inherited;
	
private:
	HIDESBASE TcxGridIndicatorFooterItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawBorders(void);
	__property TcxGridIndicatorFooterItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridIndicatorFooterItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridIndicatorItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridIndicatorFooterItemPainter(void) { }
	
};


class DELPHICLASS TcxGridIndicatorPainter;
class DELPHICLASS TcxGridIndicatorViewInfo;
class PASCALIMPLEMENTATION TcxGridIndicatorPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridIndicatorViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawItems(void);
	virtual bool __fastcall DrawItemsFirst(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxGridIndicatorViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridIndicatorPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridIndicatorPainter(void) { }
	
};


class DELPHICLASS TcxCustomGridRowPainter;
class PASCALIMPLEMENTATION TcxCustomGridRowPainter : public Cxgridcustomtableview::TcxCustomGridRecordPainter
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordPainter inherited;
	
private:
	HIDESBASE TcxCustomGridRowViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawFooters(void);
	virtual void __fastcall DrawIndent(void);
	virtual void __fastcall DrawIndentPart(int ALevel, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawLastHorzGridLine(void);
	virtual void __fastcall DrawSeparator(void);
	virtual void __fastcall Paint(void);
	__property TcxCustomGridRowViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxCustomGridRowPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomtableview::TcxCustomGridRecordPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridRowPainter(void) { }
	
};


typedef System::TMetaClass* TcxGridRowsPainterClass;

class DELPHICLASS TcxGridRowsPainter;
class DELPHICLASS TcxGridRowsViewInfo;
class PASCALIMPLEMENTATION TcxGridRowsPainter : public Cxgridcustomtableview::TcxCustomGridRecordsPainter
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordsPainter inherited;
	
private:
	TcxGridRowsViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridRowsViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__classmethod virtual void __fastcall DrawDataRowCells(TcxCustomGridRowViewInfo* ARowViewInfo);
public:
	/* TcxCustomGridRecordsPainter.Create */ inline __fastcall virtual TcxGridRowsPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* AViewInfo) : Cxgridcustomtableview::TcxCustomGridRecordsPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridRowsPainter(void) { }
	
};


class DELPHICLASS TcxGridTablePainter;
class PASCALIMPLEMENTATION TcxGridTablePainter : public Cxgridcustomtableview::TcxCustomGridTablePainter
{
	typedef Cxgridcustomtableview::TcxCustomGridTablePainter inherited;
	
private:
	System::Classes::TList* FGridLines;
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanOffset(int AItemsOffset, int DX, int DY);
	virtual void __fastcall DrawFooter(void);
	virtual void __fastcall DrawGroupByBox(void);
	virtual void __fastcall DrawHeader(void);
	virtual void __fastcall DrawIndicator(void);
	virtual void __fastcall DrawRecords(void);
	virtual void __fastcall Offset(int AItemsOffset)/* overload */;
	virtual void __fastcall Offset(int DX, int DY)/* overload */;
	virtual void __fastcall PaintContent(void);
	
public:
	void __fastcall AddGridLine(const System::Types::TRect &R);
	__property TcxGridTableController* Controller = {read=GetController};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxGridTablePainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTablePainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridTablePainter(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridColumnContainerViewInfo : public Cxgridcustomtableview::TcxCustomGridPartViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridPartViewInfo inherited;
	
public:
	TcxGridColumnHeaderViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	int FItemHeight;
	System::Classes::TList* FItems;
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	int __fastcall GetCount(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridColumnHeaderViewInfo* __fastcall GetInternalItem(int Index);
	TcxGridColumnHeaderViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetItemHeight(void);
	
protected:
	virtual TcxGridColumnHeaderViewInfo* __fastcall CreateItem(int AIndex);
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DestroyItems(void);
	virtual TcxGridColumn* __fastcall GetColumn(int Index) = 0 ;
	virtual int __fastcall GetColumnCount(void) = 0 ;
	virtual TcxGridColumnHeaderViewInfoClass __fastcall GetItemClass(void);
	virtual int __fastcall CalculateItemHeight(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetColumnAdditionalWidth(TcxGridColumn* AColumn);
	virtual int __fastcall GetColumnMinWidth(TcxGridColumn* AColumn);
	virtual Cxlookandfeelpainters::TcxNeighbors __fastcall GetColumnNeighbors(TcxGridColumn* AColumn);
	virtual int __fastcall GetColumnWidth(TcxGridColumn* AColumn);
	virtual System::Types::TRect __fastcall GetItemAreaBounds(TcxGridColumnHeaderViewInfo* AItem);
	virtual bool __fastcall GetItemMultiLinePainting(TcxGridColumnHeaderViewInfo* AItem);
	virtual System::Types::TRect __fastcall GetItemsAreaBounds(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetItemsHitTest(const System::Types::TPoint P);
	virtual int __fastcall GetKind(void) = 0 ;
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetZonesAreaBounds(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall Offset(int DX, int DY);
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TcxGridColumn* Columns[int Index] = {read=GetColumn};
	__property TcxGridTableController* Controller = {read=GetController};
	__property System::Types::TRect ZonesAreaBounds = {read=GetZonesAreaBounds};
	
public:
	__fastcall virtual TcxGridColumnContainerViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridColumnContainerViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual Cxgridcustomtableview::TcxGridItemContainerZone* __fastcall GetZone(const System::Types::TPoint P);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridColumnHeaderViewInfo* InternalItems[int Index] = {read=GetInternalItem};
	__property int ItemHeight = {read=GetItemHeight, nodefault};
	__property TcxGridColumnHeaderViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property System::Types::TRect ItemsAreaBounds = {read=GetItemsAreaBounds};
	__property int Kind = {read=GetKind, nodefault};
};


class PASCALIMPLEMENTATION TcxGridColumnHeaderAreaViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridColumnHeaderViewInfo* FColumnHeaderViewInfo;
	TcxGridColumn* __fastcall GetColumn(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	
protected:
	virtual bool __fastcall CanShowContainerHint(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall HasMouse(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall NeedsContainerHotTrack(void);
	virtual bool __fastcall OccupiesSpace(void);
	virtual bool __fastcall ResidesInContent(void);
	__property TcxGridColumn* Column = {read=GetColumn};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	
public:
	__fastcall virtual TcxGridColumnHeaderAreaViewInfo(TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo);
	HIDESBASE virtual void __fastcall Calculate(const System::Types::TRect &ABounds, System::Types::TRect &ATextAreaBounds);
	__property System::Classes::TAlignment AlignmentHorz = {read=GetAlignmentHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignmentVert = {read=GetAlignmentVert, nodefault};
	__property TcxGridColumnHeaderViewInfo* ColumnHeaderViewInfo = {read=FColumnHeaderViewInfo};
	__property int Height = {read=GetHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderAreaViewInfo(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderSortingMarkViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnHeaderSortingMarkViewInfo : public TcxGridColumnHeaderAreaViewInfo
{
	typedef TcxGridColumnHeaderAreaViewInfo inherited;
	
private:
	Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanShowContainerHint(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	__property Dxcore::TdxSortOrder SortOrder = {read=GetSortOrder, nodefault};
public:
	/* TcxGridColumnHeaderAreaViewInfo.Create */ inline __fastcall virtual TcxGridColumnHeaderSortingMarkViewInfo(TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo) : TcxGridColumnHeaderAreaViewInfo(AColumnHeaderViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderSortingMarkViewInfo(void) { }
	
};


class DELPHICLASS TcxGridColumnHeaderHorzSizingEdgeViewInfo;
class PASCALIMPLEMENTATION TcxGridColumnHeaderHorzSizingEdgeViewInfo : public TcxGridColumnHeaderAreaViewInfo
{
	typedef TcxGridColumnHeaderAreaViewInfo inherited;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall OccupiesSpace(void);
	virtual bool __fastcall ResidesInContent(void);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds, System::Types::TRect &ATextAreaBounds);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
public:
	/* TcxGridColumnHeaderAreaViewInfo.Create */ inline __fastcall virtual TcxGridColumnHeaderHorzSizingEdgeViewInfo(TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo) : TcxGridColumnHeaderAreaViewInfo(AColumnHeaderViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderHorzSizingEdgeViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridColumnHeaderFilterButtonViewInfo : public TcxGridColumnHeaderAreaViewInfo
{
	typedef TcxGridColumnHeaderAreaViewInfo inherited;
	
private:
	bool __fastcall GetActive(void);
	Cxgridcustomtableview::TcxGridFilterPopup* __fastcall GetDropDownWindowValue(void);
	
protected:
	Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetItem(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual void __fastcall DropDown(void);
	virtual bool __fastcall EmulateMouseMoveAfterCalculate(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual bool __fastcall GetAlwaysVisible(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall NeedsContainerHotTrack(void);
	virtual bool __fastcall OccupiesSpace(void);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	virtual bool __fastcall CloseDropDownWindowOnDestruction(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	virtual bool __fastcall IsDropDownWindowOwner(void);
	bool __fastcall IsSmartTag(void);
	__property Cxgridcustomtableview::TcxGridFilterPopup* DropDownWindow = {read=GetDropDownWindowValue};
	__property bool AlwaysVisible = {read=GetAlwaysVisible, nodefault};
	
public:
	virtual bool __fastcall MouseMove(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	__property bool Active = {read=GetActive, nodefault};
public:
	/* TcxGridColumnHeaderAreaViewInfo.Create */ inline __fastcall virtual TcxGridColumnHeaderFilterButtonViewInfo(TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo) : TcxGridColumnHeaderAreaViewInfo(AColumnHeaderViewInfo) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderFilterButtonViewInfo(void) { }
	
private:
	void *__IcxGridFilterPopupOwner;	/* Cxgridcustomtableview::IcxGridFilterPopupOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1FC070B2-36E5-4388-B22D-1FF5D240E95F}
	operator Cxgridcustomtableview::_di_IcxGridFilterPopupOwner()
	{
		Cxgridcustomtableview::_di_IcxGridFilterPopupOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustomtableview::IcxGridFilterPopupOwner*(void) { return (Cxgridcustomtableview::IcxGridFilterPopupOwner*)&__IcxGridFilterPopupOwner; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxGridColumnHeaderGlyphViewInfo : public TcxGridColumnHeaderAreaViewInfo
{
	typedef TcxGridColumnHeaderAreaViewInfo inherited;
	
private:
	bool FUseImages;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	System::Uitypes::TImageIndex __fastcall GetImageIndex(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanShowContainerHint(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	
public:
	__fastcall virtual TcxGridColumnHeaderGlyphViewInfo(TcxGridColumnHeaderViewInfo* AColumnHeaderViewInfo);
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph};
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetImageIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridColumnHeaderGlyphViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridColumnHeaderViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	int FAdditionalHeightAtTop;
	int FAdditionalWidthAtLeft;
	System::Classes::TList* FAreaViewInfos;
	System::Types::TRect FCellBoundsForHint;
	TcxGridColumn* FColumn;
	TcxGridColumnContainerViewInfo* FContainer;
	bool FDrawPressed;
	bool FIsFilterActive;
	Cxlookandfeelpainters::TcxNeighbors FNeighbors;
	int FRealWidth;
	bool FSortByGroupSummary;
	System::Types::TRect FTextAreaBounds;
	int FWidth;
	int __fastcall GetAreaViewInfoCount(void);
	TcxGridColumnHeaderAreaViewInfo* __fastcall GetAreaViewInfo(int Index);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	bool __fastcall GetHasTextOffsetLeft(void);
	bool __fastcall GetHasTextOffsetRight(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFixed(void);
	int __fastcall GetRealWidth(void);
	void __fastcall EnumAreaViewInfoClasses(System::TClass AClass);
	void __fastcall CreateAreaViewInfos(void);
	void __fastcall DestroyAreaViewInfos(void);
	
protected:
	bool __fastcall AreasNeedHotTrack(void);
	virtual void __fastcall CalculateCellBoundsForHint(void);
	virtual bool __fastcall CalculateHasTextOffset(System::Classes::TAlignment ASide);
	virtual int __fastcall CalculateHeight(void);
	int __fastcall CalculateRealWidth(int Value);
	virtual void __fastcall CalculateTextAreaBounds(void);
	virtual void __fastcall CalculateVisible(int ALeftBound, int AWidth);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanFilter(void);
	virtual bool __fastcall CanHorzSize(void);
	virtual bool __fastcall CanPress(void);
	virtual bool __fastcall CanShowHint(void);
	virtual bool __fastcall CanSort(void);
	virtual void __fastcall CheckWidth(int &Value);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoCalculateParams(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual System::Types::TRect __fastcall GetAreaBounds(void);
	virtual void __fastcall GetAreaViewInfoClasses(Cxgridcommon::TcxGridClassEnumeratorProc AProc);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual System::UnicodeString __fastcall GetCaption(void);
	__classmethod virtual int __fastcall GetCellBorderWidth(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	__classmethod virtual int __fastcall GetCellHeight(int ATextHeight, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual int __fastcall GetDataOffset(void);
	virtual int __fastcall GetHeight(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual bool __fastcall GetIsPressed(void);
	virtual int __fastcall GetMaxWidth(void);
	virtual int __fastcall GetMinWidth(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual bool __fastcall GetMultiLinePainting(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetRealBounds(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall HasCustomDraw(void);
	virtual bool __fastcall HasFixedContentSpace(void);
	virtual bool __fastcall HasGlyph(void);
	bool __fastcall HasHeaderAsContainer(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall DesignMouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall HasDesignPopupMenu(void);
	virtual void __fastcall PopulateDesignPopupMenu(Vcl::Menus::TPopupMenu* AMenu);
	virtual System::Types::TRect __fastcall GetCellBoundsForHint(void);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual System::Types::TRect __fastcall GetHintTextRect(const System::Types::TPoint AMousePos);
	bool __fastcall HasCustomHint(void);
	virtual bool __fastcall IsHintForText(void);
	virtual bool __fastcall IsHintMultiLine(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	__property System::UnicodeString Caption = {read=GetCaption};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property bool HasTextOffsetLeft = {read=GetHasTextOffsetLeft, nodefault};
	__property bool HasTextOffsetRight = {read=GetHasTextOffsetRight, nodefault};
	__property bool SortByGroupSummary = {read=FSortByGroupSummary, nodefault};
	
public:
	__fastcall virtual TcxGridColumnHeaderViewInfo(TcxGridColumnContainerViewInfo* AContainer, TcxGridColumn* AColumn);
	__fastcall virtual ~TcxGridColumnHeaderViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual int __fastcall GetBestFitWidth(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AAutoWidthItem);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property int AreaViewInfoCount = {read=GetAreaViewInfoCount, nodefault};
	__property TcxGridColumnHeaderAreaViewInfo* AreaViewInfos[int Index] = {read=GetAreaViewInfo};
	__property TcxGridColumn* Column = {read=FColumn};
	__property TcxGridColumnContainerViewInfo* Container = {read=FContainer};
	__property int DataOffset = {read=GetDataOffset, nodefault};
	__property bool DrawPressed = {read=FDrawPressed, write=FDrawPressed, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsFilterActive = {read=FIsFilterActive, nodefault};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property bool IsPressed = {read=GetIsPressed, nodefault};
	__property int MaxWidth = {read=GetMaxWidth, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property Cxlookandfeelpainters::TcxNeighbors Neighbors = {read=FNeighbors, write=FNeighbors, nodefault};
	__property int RealWidth = {read=GetRealWidth, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


typedef System::TMetaClass* TcxGridHeaderViewInfoSpecificClass;

class DELPHICLASS TcxGridHeaderViewInfoSpecific;
class DELPHICLASS TcxGridHeaderViewInfo;
class PASCALIMPLEMENTATION TcxGridHeaderViewInfoSpecific : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxGridHeaderViewInfo* FContainerViewInfo;
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetItemHeight(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall GetHeight(void);
	
public:
	__fastcall virtual TcxGridHeaderViewInfoSpecific(TcxGridHeaderViewInfo* AContainerViewInfo);
	__property TcxGridHeaderViewInfo* ContainerViewInfo = {read=FContainerViewInfo};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int Height = {read=GetHeight, nodefault};
	__property int ItemHeight = {read=GetItemHeight, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridHeaderViewInfoSpecific(void) { }
	
};


typedef System::TMetaClass* TcxGridHeaderViewInfoClass;

class PASCALIMPLEMENTATION TcxGridHeaderViewInfo : public TcxGridColumnContainerViewInfo
{
	typedef TcxGridColumnContainerViewInfo inherited;
	
private:
	TcxGridHeaderViewInfoSpecific* FSpecific;
	
protected:
	virtual TcxGridColumn* __fastcall GetColumn(int Index);
	virtual int __fastcall GetColumnCount(void);
	virtual void __fastcall AddIndicatorItems(TcxGridIndicatorViewInfo* AIndicatorViewInfo, int ATopBound);
	virtual void __fastcall CalculateColumnAutoWidths(void);
	virtual void __fastcall CalculateColumnWidths(void);
	virtual int __fastcall CalculateHeight(void);
	virtual void __fastcall CalculateInvisible(void);
	virtual int __fastcall CalculateItemHeight(void);
	virtual void __fastcall CalculateItems(void);
	virtual void __fastcall CalculateVisible(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanCalculateAutoWidths(void);
	virtual bool __fastcall DrawColumnBackgroundHandler(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual Cxgridcustomtableview::TcxGridPartAlignment __fastcall GetAlignment(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetColumnBackgroundBitmap(void);
	virtual Cxlookandfeelpainters::TcxNeighbors __fastcall GetColumnNeighbors(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsAutoWidth(void);
	virtual bool __fastcall GetIsScrollable(void);
	virtual bool __fastcall GetItemMultiLinePainting(TcxGridColumnHeaderViewInfo* AItem);
	virtual int __fastcall GetKind(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetWidth(void);
	virtual System::Types::TRect __fastcall GetZonesAreaBounds(void);
	virtual bool __fastcall IsAlwaysVisibleForCalculation(void);
	virtual bool __fastcall IsHeightAssigned(void);
	virtual void __fastcall Offset(int DX, int DY);
	void __fastcall RecalculateItemVisibles(void);
	__property Vcl::Graphics::TBitmap* ColumnBackgroundBitmap = {read=GetColumnBackgroundBitmap};
	
public:
	__fastcall virtual TcxGridHeaderViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridHeaderViewInfo(void);
	void __fastcall AssignColumnWidths(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	__property TcxGridHeaderViewInfoSpecific* Specific = {read=FSpecific};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


class DELPHICLASS TcxGridGroupByBoxColumnHeaderViewInfo;
class PASCALIMPLEMENTATION TcxGridGroupByBoxColumnHeaderViewInfo : public TcxGridColumnHeaderViewInfo
{
	typedef TcxGridColumnHeaderViewInfo inherited;
	
private:
	TcxGridGroupByBoxViewInfo* __fastcall GetContainer(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual bool __fastcall HasFixedContentSpace(void);
	int __fastcall InheritedCalculateHeight(void);
	
public:
	__property TcxGridGroupByBoxViewInfo* Container = {read=GetContainer};
public:
	/* TcxGridColumnHeaderViewInfo.Create */ inline __fastcall virtual TcxGridGroupByBoxColumnHeaderViewInfo(TcxGridColumnContainerViewInfo* AContainer, TcxGridColumn* AColumn) : TcxGridColumnHeaderViewInfo(AContainer, AColumn) { }
	/* TcxGridColumnHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridGroupByBoxColumnHeaderViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridGroupByBoxViewInfoClass;

class PASCALIMPLEMENTATION TcxGridGroupByBoxViewInfo : public TcxGridColumnContainerViewInfo
{
	typedef TcxGridColumnContainerViewInfo inherited;
	
private:
	bool FCalculatingColumnWidth;
	int __fastcall GetGroupByBoxVerOffset(void);
	System::Types::TRect __fastcall GetLinkLineBounds(int Index, bool Horizontal);
	
protected:
	virtual TcxGridColumn* __fastcall GetColumn(int Index);
	virtual int __fastcall GetColumnCount(void);
	virtual TcxGridColumnHeaderViewInfoClass __fastcall GetItemClass(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateItemHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgridcustomtableview::TcxGridPartAlignment __fastcall GetAlignment(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual int __fastcall GetColumnWidth(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsAutoWidth(void);
	virtual bool __fastcall GetIsScrollable(void);
	virtual System::Types::TRect __fastcall GetItemAreaBounds(TcxGridColumnHeaderViewInfo* AItem);
	virtual int __fastcall GetKind(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall IsSingleLine(void);
	__property bool CalculatingColumnWidth = {read=FCalculatingColumnWidth, nodefault};
	__property int GroupByBoxVerOffset = {read=GetGroupByBoxVerOffset, nodefault};
	
public:
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	__property System::Types::TRect LinkLineBounds[int Index][bool Horizontal] = {read=GetLinkLineBounds};
public:
	/* TcxGridColumnContainerViewInfo.Create */ inline __fastcall virtual TcxGridGroupByBoxViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : TcxGridColumnContainerViewInfo(AGridViewInfo) { }
	/* TcxGridColumnContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxGridGroupByBoxViewInfo(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


typedef System::TMetaClass* TcxGridFooterCellViewInfoClass;

class DELPHICLASS TcxGridFooterCellViewInfo;
class PASCALIMPLEMENTATION TcxGridFooterCellViewInfo : public TcxGridColumnHeaderViewInfo
{
	typedef TcxGridColumnHeaderViewInfo inherited;
	
private:
	Cxcustomdata::TcxDataSummaryItem* FSummaryItem;
	TcxGridFooterViewInfo* __fastcall GetContainer(void);
	Cxcustomdata::TcxDataSummary* __fastcall GetSummary(void);
	
protected:
	virtual void __fastcall AfterCalculateBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanPress(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual void __fastcall GetAreaViewInfoClasses(Cxgridcommon::TcxGridClassEnumeratorProc AProc);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	__classmethod virtual int __fastcall GetCellBorderWidth(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual bool __fastcall GetIsPressed(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasCustomDraw(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall PopulateDesignPopupMenu(Vcl::Menus::TPopupMenu* AMenu);
	__property Cxcustomdata::TcxDataSummary* Summary = {read=GetSummary};
	
public:
	__fastcall virtual TcxGridFooterCellViewInfo(TcxGridColumnContainerViewInfo* AContainer, Cxcustomdata::TcxDataSummaryItem* ASummaryItem);
	virtual int __fastcall GetBestFitWidth(void);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridFooterViewInfo* Container = {read=GetContainer};
	__property Cxcustomdata::TcxDataSummaryItem* SummaryItem = {read=FSummaryItem};
public:
	/* TcxGridColumnHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFooterCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridFooterViewInfoClass;

class PASCALIMPLEMENTATION TcxGridFooterViewInfo : public TcxGridHeaderViewInfo
{
	typedef TcxGridHeaderViewInfo inherited;
	
private:
	int FRowCount;
	System::Classes::TList* FSummaryItems;
	bool __fastcall GetMultipleSummaries(void);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowHeight(void);
	
protected:
	virtual TcxGridColumnHeaderViewInfo* __fastcall CreateItem(int AIndex);
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DestroyItems(void);
	virtual TcxGridColumn* __fastcall GetColumn(int Index);
	virtual int __fastcall GetColumnCount(void);
	virtual TcxGridColumnHeaderViewInfoClass __fastcall GetItemClass(void);
	virtual void __fastcall PrepareSummaryItems(System::Classes::TList* ASummaryItems);
	virtual System::Types::TRect __fastcall CalculateBounds(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateItemHeight(void);
	virtual void __fastcall CalculateItem(int AIndex);
	virtual void __fastcall CalculateItems(void);
	virtual int __fastcall CalculateRowCount(void);
	virtual bool __fastcall CanCalculateAutoWidths(void);
	virtual Cxgridcustomtableview::TcxGridPartAlignment __fastcall GetAlignment(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Types::TRect __fastcall GetBordersBounds(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual int __fastcall GetColumnWidth(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsAutoWidth(void);
	virtual bool __fastcall GetIsScrollable(void);
	virtual System::Types::TRect __fastcall GetItemAreaBounds(TcxGridColumnHeaderViewInfo* AItem);
	HIDESBASE virtual int __fastcall GetItemHeight(TcxGridColumn* AColumn)/* overload */;
	HIDESBASE int __fastcall GetItemHeight(int AIndex)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetItemHitTestClass(void);
	virtual int __fastcall GetItemLeftBound(TcxGridColumn* AColumn)/* overload */;
	int __fastcall GetItemLeftBound(int AIndex)/* overload */;
	virtual int __fastcall GetItemRowIndex(int AIndex);
	virtual System::Types::TRect __fastcall GetItemsAreaBounds(void);
	virtual int __fastcall GetItemTopBound(TcxGridColumn* AColumn)/* overload */;
	virtual int __fastcall GetItemTopBound(int AIndex)/* overload */;
	virtual int __fastcall GetKind(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(void);
	virtual int __fastcall GetSeparatorWidth(void);
	virtual Cxcustomdata::TcxDataSummaryItems* __fastcall GetSummaryItems(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasSeparator(void);
	virtual bool __fastcall IsAlwaysVisibleForCalculation(void);
	virtual bool __fastcall IsColumnOnFirstLayer(int AColumnIndex);
	virtual bool __fastcall IsHeightAssigned(void);
	virtual bool __fastcall IsItemVisible(int AIndex);
	virtual bool __fastcall IsMultilayerLayout(void);
	virtual void __fastcall Offset(int DX, int DY);
	__property System::Classes::TList* SummaryItemsList = {read=FSummaryItems};
	
public:
	virtual bool __fastcall CanShowMultipleSummaries(void);
	virtual int __fastcall GetCellBestFitWidth(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	__property System::Types::TRect BordersBounds = {read=GetBordersBounds};
	__property bool MultipleSummaries = {read=GetMultipleSummaries, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowHeight = {read=GetRowHeight, nodefault};
	__property System::Types::TRect SeparatorBounds = {read=GetSeparatorBounds};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
	__property Cxcustomdata::TcxDataSummaryItems* SummaryItems = {read=GetSummaryItems};
public:
	/* TcxGridHeaderViewInfo.Create */ inline __fastcall virtual TcxGridFooterViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : TcxGridHeaderViewInfo(AGridViewInfo) { }
	/* TcxGridHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFooterViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxCustomGridIndicatorItemViewInfoClass;

class PASCALIMPLEMENTATION TcxCustomGridIndicatorItemViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridIndicatorViewInfo* FContainer;
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	
protected:
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasCustomDraw(void);
	
public:
	__fastcall virtual TcxCustomGridIndicatorItemViewInfo(TcxGridIndicatorViewInfo* AContainer);
	__fastcall virtual ~TcxCustomGridIndicatorItemViewInfo(void);
	__property TcxGridIndicatorViewInfo* Container = {read=FContainer};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
};


class PASCALIMPLEMENTATION TcxGridIndicatorHeaderItemViewInfo : public TcxCustomGridIndicatorItemViewInfo
{
	typedef TcxCustomGridIndicatorItemViewInfo inherited;
	
private:
	Cxgridcustomtableview::TcxCustomGridCustomizationPopup* __fastcall GetDropDownWindowValue(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual bool __fastcall CanShowHint(void);
	virtual System::Types::TRect __fastcall GetCellBoundsForHint(void);
	virtual System::Types::TRect __fastcall GetHintTextRect(const System::Types::TPoint AMousePos);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall IsHintForText(void);
	virtual bool __fastcall IsHintMultiLine(void);
	virtual bool __fastcall SupportsQuickCustomization(void);
	virtual bool __fastcall CloseDropDownWindowOnDestruction(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	__property Cxgridcustomtableview::TcxCustomGridCustomizationPopup* DropDownWindow = {read=GetDropDownWindowValue};
public:
	/* TcxCustomGridIndicatorItemViewInfo.Create */ inline __fastcall virtual TcxGridIndicatorHeaderItemViewInfo(TcxGridIndicatorViewInfo* AContainer) : TcxCustomGridIndicatorItemViewInfo(AContainer) { }
	/* TcxCustomGridIndicatorItemViewInfo.Destroy */ inline __fastcall virtual ~TcxGridIndicatorHeaderItemViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridIndicatorRowItemViewInfoClass;

class PASCALIMPLEMENTATION TcxGridIndicatorRowItemViewInfo : public TcxCustomGridIndicatorItemViewInfo
{
	typedef TcxCustomGridIndicatorItemViewInfo inherited;
	
private:
	TcxCustomGridRowViewInfo* FRowViewInfo;
	TcxCustomGridRow* __fastcall GetGridRecord(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxlookandfeelpainters::TcxIndicatorKind __fastcall GetIndicatorKind(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetRowSizingEdgeBounds(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property System::Types::TRect RowSizingEdgeBounds = {read=GetRowSizingEdgeBounds};
	
public:
	__fastcall virtual ~TcxGridIndicatorRowItemViewInfo(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxCustomGridRow* GridRecord = {read=GetGridRecord};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property Cxlookandfeelpainters::TcxIndicatorKind IndicatorKind = {read=GetIndicatorKind, nodefault};
	__property TcxCustomGridRowViewInfo* RowViewInfo = {read=FRowViewInfo, write=FRowViewInfo};
public:
	/* TcxCustomGridIndicatorItemViewInfo.Create */ inline __fastcall virtual TcxGridIndicatorRowItemViewInfo(TcxGridIndicatorViewInfo* AContainer) : TcxCustomGridIndicatorItemViewInfo(AContainer) { }
	
};


class PASCALIMPLEMENTATION TcxGridIndicatorFooterItemViewInfo : public TcxCustomGridIndicatorItemViewInfo
{
	typedef TcxCustomGridIndicatorItemViewInfo inherited;
	
private:
	int __fastcall GetSeparatorWidth(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual System::Types::TRect __fastcall GetBordersBounds(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(void);
	bool __fastcall HasSeparator(void);
	
public:
	__property System::Types::TRect BordersBounds = {read=GetBordersBounds};
	__property System::Types::TRect SeparatorBounds = {read=GetSeparatorBounds};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
public:
	/* TcxCustomGridIndicatorItemViewInfo.Create */ inline __fastcall virtual TcxGridIndicatorFooterItemViewInfo(TcxGridIndicatorViewInfo* AContainer) : TcxCustomGridIndicatorItemViewInfo(AContainer) { }
	/* TcxCustomGridIndicatorItemViewInfo.Destroy */ inline __fastcall virtual ~TcxGridIndicatorFooterItemViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridIndicatorViewInfoClass;

class PASCALIMPLEMENTATION TcxGridIndicatorViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	TcxCustomGridIndicatorItemViewInfo* __fastcall GetItem(int Index);
	void __fastcall DestroyItems(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall GetAlwaysVisible(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridIndicatorRowItemViewInfoClass __fastcall GetRowItemClass(TcxCustomGridRowViewInfo* ARowViewInfo);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetWidth(void);
	
public:
	__fastcall virtual TcxGridIndicatorViewInfo(TcxGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridIndicatorViewInfo(void);
	TcxCustomGridIndicatorItemViewInfo* __fastcall AddItem(TcxCustomGridIndicatorItemViewInfoClass AItemClass)/* overload */;
	TcxCustomGridIndicatorItemViewInfo* __fastcall AddItem(int ATopBound, int AHeight, TcxCustomGridIndicatorItemViewInfoClass AItemClass)/* overload */;
	TcxCustomGridIndicatorItemViewInfo* __fastcall AddRowItem(TcxCustomGridRowViewInfo* ARowViewInfo);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	void __fastcall CalculateRowItem(TcxCustomGridRowViewInfo* ARowViewInfo, TcxCustomGridIndicatorItemViewInfo* AItem);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	System::Types::TRect __fastcall GetRowItemBounds(TcxCustomGridRow* AGridRecord);
	__property bool AlwaysVisible = {read=GetAlwaysVisible, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxCustomGridIndicatorItemViewInfo* Items[int Index] = {read=GetItem};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


class DELPHICLASS TcxGridRowFooterCellViewInfo;
class DELPHICLASS TcxGridRowFooterViewInfo;
class PASCALIMPLEMENTATION TcxGridRowFooterCellViewInfo : public TcxGridFooterCellViewInfo
{
	typedef TcxGridFooterCellViewInfo inherited;
	
private:
	HIDESBASE TcxGridRowFooterViewInfo* __fastcall GetContainer(void);
	TcxCustomGridRow* __fastcall GetGridRecord(void);
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	
public:
	__property TcxGridRowFooterViewInfo* Container = {read=GetContainer};
	__property TcxCustomGridRow* GridRecord = {read=GetGridRecord};
public:
	/* TcxGridFooterCellViewInfo.Create */ inline __fastcall virtual TcxGridRowFooterCellViewInfo(TcxGridColumnContainerViewInfo* AContainer, Cxcustomdata::TcxDataSummaryItem* ASummaryItem) : TcxGridFooterCellViewInfo(AContainer, ASummaryItem) { }
	
public:
	/* TcxGridColumnHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridRowFooterCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridRowFooterViewInfoClass;

class DELPHICLASS TcxGridRowFootersViewInfo;
class PASCALIMPLEMENTATION TcxGridRowFooterViewInfo : public TcxGridFooterViewInfo
{
	typedef TcxGridFooterViewInfo inherited;
	
private:
	TcxGridRowFootersViewInfo* FContainer;
	int FLevel;
	int __fastcall GetIndent(void);
	TcxCustomGridRow* __fastcall GetGridRecord(void);
	int __fastcall GetGroupLevel(void);
	TcxCustomGridRowViewInfo* __fastcall GetRowViewInfo(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetColumnWidth(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetIsPart(void);
	virtual System::Types::TRect __fastcall GetItemAreaBounds(TcxGridColumnHeaderViewInfo* AItem);
	virtual TcxGridColumnHeaderViewInfoClass __fastcall GetItemClass(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetItemHitTestClass(void);
	virtual bool __fastcall GetItemMultiLinePainting(TcxGridColumnHeaderViewInfo* AItem);
	virtual Cxcustomdata::TcxDataSummaryItems* __fastcall GetSummaryItems(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetVisualLevel(void);
	virtual bool __fastcall HasSeparator(void);
	virtual void __fastcall PrepareSummaryItems(System::Classes::TList* ASummaryItems);
	__property int Indent = {read=GetIndent, nodefault};
	
public:
	__fastcall virtual TcxGridRowFooterViewInfo(TcxGridRowFootersViewInfo* AContainer, int ALevel);
	virtual bool __fastcall CanShowMultipleSummaries(void);
	__property TcxGridRowFootersViewInfo* Container = {read=FContainer};
	__property TcxCustomGridRow* GridRecord = {read=GetGridRecord};
	__property int GroupLevel = {read=GetGroupLevel, nodefault};
	__property int Level = {read=FLevel, nodefault};
	__property TcxCustomGridRowViewInfo* RowViewInfo = {read=GetRowViewInfo};
	__property int VisualLevel = {read=GetVisualLevel, nodefault};
public:
	/* TcxGridHeaderViewInfo.Destroy */ inline __fastcall virtual ~TcxGridRowFooterViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridRowFootersViewInfoClass;

class PASCALIMPLEMENTATION TcxGridRowFootersViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridRowFooterViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	int FHeight;
	System::Classes::TList* FItems;
	TcxCustomGridRowViewInfo* FRowViewInfo;
	int __fastcall GetCount(void);
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetHeight(void);
	TcxGridRowFooterViewInfo* __fastcall GetItem(int Index);
	TcxGridRowFooterViewInfo* __fastcall GetVisibleItem(int ALevel);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	
protected:
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound);
	virtual int __fastcall CalculateHeight(void);
	virtual TcxGridRowFooterViewInfoClass __fastcall GetItemClass(void);
	
public:
	__fastcall virtual TcxGridRowFootersViewInfo(TcxCustomGridRowViewInfo* ARowViewInfo);
	__fastcall virtual ~TcxGridRowFootersViewInfo(void);
	int __fastcall GetCellBestFitWidth(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	bool __fastcall GetTopBound(int ALevel, int &ATopBound);
	virtual void __fastcall Offset(int DX, int DY);
	void __fastcall Paint(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridRowFooterViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int Height = {read=GetHeight, nodefault};
	__property TcxCustomGridRowViewInfo* RowViewInfo = {read=FRowViewInfo};
	__property TcxGridRowFooterViewInfo* VisibleItems[int ALevel] = {read=GetVisibleItem};
};


typedef System::TMetaClass* TcxCustomGridRowViewInfoClass;

class DELPHICLASS TcxGridTableViewInfoCacheItem;
class PASCALIMPLEMENTATION TcxCustomGridRowViewInfo : public Cxgridcustomtableview::TcxCustomGridRecordViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordViewInfo inherited;
	
private:
	TcxGridRowFootersViewInfo* FFootersViewInfo;
	TcxCustomGridIndicatorItemViewInfo* FIndicatorItem;
	HIDESBASE TcxGridTableViewInfoCacheItem* __fastcall GetCacheItem(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	Cxgraphics::TcxGridLines __fastcall GetGridLines(void);
	TcxCustomGridRow* __fastcall GetGridRecord(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetLevel(void);
	int __fastcall GetLevelIndent(void);
	System::Types::TRect __fastcall GetLevelIndentBounds(int Index);
	System::Types::TRect __fastcall GetLevelIndentHorzLineBounds(int Index);
	System::Types::TRect __fastcall GetLevelIndentSpaceBounds(int Index);
	System::Types::TRect __fastcall GetLevelIndentVertLineBounds(int Index);
	TcxGridRowsViewInfo* __fastcall GetRecordsViewInfo(void);
	int __fastcall GetVisualLevel(void);
	void __fastcall CreateFootersViewInfo(void);
	void __fastcall DestroyFootersViewInfo(void);
	void __fastcall RecreateFootersViewInfo(void);
	
protected:
	virtual void __fastcall AfterRowsViewInfoCalculate(void);
	virtual void __fastcall AfterRowsViewInfoOffset(void);
	virtual void __fastcall CalculateExpandButtonBounds(System::Types::TRect &ABounds);
	virtual int __fastcall CalculateHeight(void);
	System::Types::TRect __fastcall CalculateLevelIndentHorzLineBounds(int ALevel, const System::Types::TRect &ABounds);
	System::Types::TRect __fastcall CalculateLevelIndentSpaceBounds(int ALevel, const System::Types::TRect &ABounds);
	System::Types::TRect __fastcall CalculateLevelIndentVertLineBounds(int ALevel, const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CanSize(void);
	virtual void __fastcall CheckRowHeight(int &AValue);
	virtual bool __fastcall GetAutoHeight(void);
	virtual int __fastcall GetBaseHeight(void);
	virtual int __fastcall GetBottomPartHeight(void);
	virtual bool __fastcall GetCellTransparent(Cxgridcustomtableview::TcxGridTableCellViewInfo* ACell);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual int __fastcall GetContentIndent(void);
	virtual int __fastcall GetContentWidth(void);
	virtual int __fastcall GetDataHeight(void);
	virtual int __fastcall GetDataIndent(void);
	virtual int __fastcall GetDataWidth(void);
	virtual System::Types::TRect __fastcall GetFocusRectBounds(void);
	virtual TcxGridRowFootersViewInfoClass __fastcall GetFootersViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetLastHorzGridLineBounds(void);
	virtual int __fastcall GetMaxHeight(void);
	virtual int __fastcall GetNonBaseHeight(void);
	virtual int __fastcall GetRowHeight(void);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(void);
	virtual System::Uitypes::TColor __fastcall GetSeparatorColor(void);
	virtual int __fastcall GetSeparatorWidth(void);
	virtual bool __fastcall GetShowSeparator(void);
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetWidth(void);
	bool __fastcall HasAnyFooter(int ALevel);
	virtual bool __fastcall HasFooter(int ALevel);
	virtual bool __fastcall HasFooters(void);
	virtual bool __fastcall HasLastHorzGridLine(void);
	virtual bool __fastcall IsFullyVisible(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall SetRowHeight(int Value) = 0 ;
	__property int BaseHeight = {read=GetBaseHeight, nodefault};
	__property int BottomPartHeight = {read=GetBottomPartHeight, nodefault};
	__property TcxGridTableViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property TcxCustomGridIndicatorItemViewInfo* IndicatorItem = {read=FIndicatorItem};
	__property System::Types::TRect LastHorzGridLineBounds = {read=GetLastHorzGridLineBounds};
	__property int Level = {read=GetLevel, nodefault};
	__property int LevelIndent = {read=GetLevelIndent, nodefault};
	__property int NonBaseHeight = {read=GetNonBaseHeight, nodefault};
	__property int RowHeight = {read=GetRowHeight, write=SetRowHeight, nodefault};
	__property bool ShowSeparator = {read=GetShowSeparator, nodefault};
	
public:
	__fastcall virtual TcxCustomGridRowViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxCustomGridRowViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall Click(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual System::Types::TRect __fastcall GetBoundsForInvalidate(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	bool __fastcall HasSeparator(void);
	__property int ContentIndent = {read=GetContentIndent, nodefault};
	__property int DataHeight = {read=GetDataHeight, nodefault};
	__property int DataIndent = {read=GetDataIndent, nodefault};
	__property int DataWidth = {read=GetDataWidth, nodefault};
	__property TcxGridRowFootersViewInfo* FootersViewInfo = {read=FFootersViewInfo};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property Cxgraphics::TcxGridLines GridLines = {read=GetGridLines, nodefault};
	__property TcxCustomGridRow* GridRecord = {read=GetGridRecord};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property System::Types::TRect LevelIndentBounds[int Index] = {read=GetLevelIndentBounds};
	__property System::Types::TRect LevelIndentHorzLineBounds[int Index] = {read=GetLevelIndentHorzLineBounds};
	__property System::Types::TRect LevelIndentSpaceBounds[int Index] = {read=GetLevelIndentSpaceBounds};
	__property System::Types::TRect LevelIndentVertLineBounds[int Index] = {read=GetLevelIndentVertLineBounds};
	__property int MaxHeight = {read=GetMaxHeight, nodefault};
	__property TcxGridRowsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property System::Types::TRect SeparatorBounds = {read=GetSeparatorBounds};
	__property System::Uitypes::TColor SeparatorColor = {read=GetSeparatorColor, nodefault};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
	__property int VisualLevel = {read=GetVisualLevel, nodefault};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


typedef System::TMetaClass* TcxGridRowsViewInfoClass;

class PASCALIMPLEMENTATION TcxGridRowsViewInfo : public Cxgridcustomtableview::TcxCustomGridRecordsViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordsViewInfo inherited;
	
public:
	TcxCustomGridRowViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	int FCommonPreviewHeight;
	int FDataRowHeight;
	TcxCustomGridRowViewInfo* FFilterRowViewInfo;
	int FGroupRowHeight;
	TcxCustomGridRowViewInfo* FNewItemRowViewInfo;
	int FRestHeight;
	int FRowHeight;
	TcxCustomGridRowViewInfo* __fastcall GetFilterRowViewInfo(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	Cxgraphics::TcxGridLines __fastcall GetGridLines(void);
	TcxGridTableViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridHeaderViewInfo* __fastcall GetHeaderViewInfo(void);
	HIDESBASE TcxCustomGridRowViewInfo* __fastcall GetItem(int Index);
	TcxCustomGridRowViewInfo* __fastcall GetNewItemRowViewInfo(void);
	TcxGridRowsPainterClass __fastcall GetPainterClassValue(void);
	HIDESBASE TcxGridViewData* __fastcall GetViewData(void);
	
protected:
	bool FIsFirstRowFullyVisible;
	virtual void __fastcall AfterCalculate(void);
	virtual void __fastcall AfterOffset(void);
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateBounds(void);
	virtual void __fastcall CalculateConsts(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual int __fastcall CalculateDataRowHeight(void);
	virtual int __fastcall CalculateGroupRowDefaultHeight(bool AMinHeight);
	virtual int __fastcall CalculateGroupRowHeight(void);
	virtual int __fastcall CalculatePreviewDefaultHeight(void);
	virtual int __fastcall CalculateRestHeight(int ATopBound);
	virtual int __fastcall CalculateRowDefaultHeight(void);
	virtual int __fastcall CalculateRowHeight(void);
	virtual void __fastcall CalculateVisibleCount(void);
	virtual bool __fastcall GetAutoDataCellHeight(void);
	virtual int __fastcall GetCommonDataRowHeight(void);
	virtual TcxCustomGridRowViewInfoClass __fastcall GetFilterRowViewInfoClass(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetGroupBackgroundBitmap(void);
	virtual int __fastcall GetGroupRowSeparatorWidth(void);
	virtual int __fastcall GetItemLeftBound(int AIndex);
	virtual int __fastcall GetItemsOffset(int AItemCountDelta);
	virtual int __fastcall GetItemTopBound(int AIndex);
	virtual bool __fastcall GetIsScrollable(void);
	virtual TcxCustomGridRowViewInfoClass __fastcall GetNewItemRowViewInfoClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall GetRowWidth(void);
	virtual int __fastcall GetSeparatorWidth(void);
	bool __fastcall HasFilterRow(void);
	virtual bool __fastcall HasLastHorzGridLine(TcxCustomGridRowViewInfo* ARowViewInfo);
	bool __fastcall HasNewItemRow(void);
	virtual bool __fastcall IsFilterRowVisible(void);
	virtual bool __fastcall IsNewItemRowVisible(void);
	void __fastcall NotifyItemsCalculationFinished(void);
	virtual void __fastcall OffsetItem(int AIndex, int AOffset);
	__property int CommonPreviewHeight = {read=FCommonPreviewHeight, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridHeaderViewInfo* HeaderViewInfo = {read=GetHeaderViewInfo};
	__property bool IsScrollable = {read=GetIsScrollable, nodefault};
	__property TcxGridViewData* ViewData = {read=GetViewData};
	
public:
	__fastcall virtual ~TcxGridRowsViewInfo(void);
	virtual void __fastcall AfterConstruction(void);
	virtual int __fastcall CalculateCustomGroupRowHeight(bool AMinHeight, Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall CanDataRowSize(void);
	virtual int __fastcall GetCellHeight(int ACellContentHeight);
	virtual System::TClass __fastcall GetDataRowCellsAreaViewInfoClass(void);
	int __fastcall GetFooterCellBestFitWidth(TcxGridColumn* AColumn);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual Cxgridcustomtableview::TcxCustomGridRecordViewInfo* __fastcall GetRealItem(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual int __fastcall GetRestHeight(int ATopBound);
	virtual bool __fastcall IsCellMultiLine(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual bool __fastcall IsDataRowHeightAssigned(void);
	virtual void __fastcall Offset(int DX, int DY);
	__property int CommonDataRowHeight = {read=GetCommonDataRowHeight, nodefault};
	__property int DataRowHeight = {read=FDataRowHeight, nodefault};
	__property TcxCustomGridRowViewInfo* FilterRowViewInfo = {read=GetFilterRowViewInfo};
	__property Cxgraphics::TcxGridLines GridLines = {read=GetGridLines, nodefault};
	__property Vcl::Graphics::TBitmap* GroupBackgroundBitmap = {read=GetGroupBackgroundBitmap};
	__property int GroupRowHeight = {read=FGroupRowHeight, write=FGroupRowHeight, nodefault};
	__property int GroupRowSeparatorWidth = {read=GetGroupRowSeparatorWidth, nodefault};
	__property bool IsFirstRowFullyVisible = {read=FIsFirstRowFullyVisible, nodefault};
	__property TcxCustomGridRowViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxCustomGridRowViewInfo* NewItemRowViewInfo = {read=GetNewItemRowViewInfo};
	__property TcxGridRowsPainterClass PainterClass = {read=GetPainterClassValue};
	__property int RowHeight = {read=FRowHeight, write=FRowHeight, nodefault};
	__property int RowWidth = {read=GetRowWidth, nodefault};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
public:
	/* TcxCustomGridRecordsViewInfo.Create */ inline __fastcall virtual TcxGridRowsViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : Cxgridcustomtableview::TcxCustomGridRecordsViewInfo(AGridViewInfo) { }
	
};


class PASCALIMPLEMENTATION TcxGridTableViewInfo : public Cxgridcustomtableview::TcxCustomGridTableViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewInfo inherited;
	
private:
	int FBorderOverlapSize;
	int FDataWidth;
	int FExpandButtonIndent;
	TcxGridFooterViewInfo* FFooterViewInfo;
	TcxGridGroupByBoxViewInfo* FGroupByBoxViewInfo;
	TcxGridHeaderViewInfo* FHeaderViewInfo;
	TcxGridIndicatorViewInfo* FIndicatorViewInfo;
	int FLevelIndent;
	int FPrevDataRowHeight;
	int __fastcall GetPopupRowHeight(void);
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	int __fastcall GetDataWidth(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	System::Uitypes::TColor __fastcall GetGridLineColor(void);
	Cxgraphics::TcxGridLines __fastcall GetGridLines(void);
	int __fastcall GetLeftPos(void);
	Vcl::Graphics::TBitmap* __fastcall GetLevelIndentBackgroundBitmap(void);
	System::Uitypes::TColor __fastcall GetLevelIndentColor(int Index);
	TcxGridRowsViewInfo* __fastcall GetRecordsViewInfo(void);
	HIDESBASE TcxGridViewData* __fastcall GetViewData(void);
	
protected:
	virtual void __fastcall AfterCalculating(void);
	virtual void __fastcall BeforeCalculating(void);
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(bool AIsRecreating);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculateBorderOverlapSize(void);
	virtual System::Types::TRect __fastcall CalculateClientBounds(void);
	virtual int __fastcall CalculateDataWidth(void);
	virtual int __fastcall GetEqualHeightRecordScrollSize(void);
	virtual void __fastcall CalculateExpandButtonParams(void);
	virtual void __fastcall CalculateHeight(const System::Types::TPoint AMaxSize, int &AHeight, bool &AFullyVisible);
	virtual System::Types::TRect __fastcall CalculatePartBounds(Cxgridcustomtableview::TcxCustomGridPartViewInfo* APart);
	virtual void __fastcall CalculateParts(void);
	virtual int __fastcall CalculateVisibleEqualHeightRecordCount(void);
	virtual void __fastcall CalculateWidth(const System::Types::TPoint AMaxSize, int &AWidth);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall DoGetHitTest(const System::Types::TPoint P);
	virtual int __fastcall GetColumnFooterWidth(TcxGridFooterViewInfo* AFooterViewInfo, TcxGridColumn* AColumn);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	virtual int __fastcall GetFirstItemAdditionalWidth(void);
	virtual int __fastcall GetGridLineWidth(void);
	virtual System::Uitypes::TColor __fastcall GetLevelSeparatorColor(void);
	virtual System::Types::TRect __fastcall GetMultilineEditorBounds(const System::Types::TRect &ACellEditBounds, int ACalculatedHeight, Cxedit::TcxInplaceEditAutoHeight AAutoHeight);
	virtual int __fastcall GetNonRecordsAreaHeight(bool ACheckScrollBar);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsHorz(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsVert(void);
	virtual int __fastcall GetVisualLevelCount(void);
	bool __fastcall HasFirstBorderOverlap(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall RecreateViewInfos(void);
	virtual bool __fastcall SupportsAutoHeight(void);
	virtual bool __fastcall SupportsGroupSummariesAlignedWithColumns(void);
	virtual bool __fastcall SupportsMultipleFooterSummaries(void);
	virtual TcxGridFooterPainterClass __fastcall GetFooterPainterClass(void);
	virtual TcxGridFooterViewInfoClass __fastcall GetFooterViewInfoClass(void);
	virtual TcxGridGroupByBoxViewInfoClass __fastcall GetGroupByBoxViewInfoClass(void);
	virtual TcxGridHeaderViewInfoClass __fastcall GetHeaderViewInfoClass(void);
	virtual TcxGridIndicatorViewInfoClass __fastcall GetIndicatorViewInfoClass(void);
	virtual TcxGridHeaderViewInfoSpecificClass __fastcall GetHeaderViewInfoSpecificClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsViewInfoClass __fastcall GetRecordsViewInfoClass(void);
	__property int BorderOverlapSize = {read=FBorderOverlapSize, nodefault};
	__property TcxGridTableController* Controller = {read=GetController};
	__property TcxGridViewData* ViewData = {read=GetViewData};
	
public:
	virtual Cxgraphics::TcxBorders __fastcall GetCellBorders(bool AIsRight, bool AIsBottom);
	virtual int __fastcall GetCellHeight(int AIndex, int ACellHeight);
	virtual int __fastcall GetCellTopOffset(int AIndex, int ACellHeight);
	virtual System::Types::TRect __fastcall GetOffsetBounds(int AItemsOffset, /* out */ System::Types::TRect &AUpdateBounds)/* overload */;
	virtual System::Types::TRect __fastcall GetOffsetBounds(int DX, int DY, /* out */ System::Types::TRect &AUpdateBounds)/* overload */;
	virtual int __fastcall GetVisualLevel(int ALevel);
	virtual int __fastcall GetNearestPopupHeight(int AHeight, bool AAdditionalRecord = false);
	virtual int __fastcall GetPopupHeight(int ADropDownRowCount);
	__property int DataWidth = {read=GetDataWidth, nodefault};
	__property int ExpandButtonIndent = {read=FExpandButtonIndent, write=FExpandButtonIndent, nodefault};
	__property int FirstItemAdditionalWidth = {read=GetFirstItemAdditionalWidth, nodefault};
	__property TcxGridFooterViewInfo* FooterViewInfo = {read=FFooterViewInfo};
	__property System::Uitypes::TColor GridLineColor = {read=GetGridLineColor, nodefault};
	__property Cxgraphics::TcxGridLines GridLines = {read=GetGridLines, nodefault};
	__property int GridLineWidth = {read=GetGridLineWidth, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property TcxGridGroupByBoxViewInfo* GroupByBoxViewInfo = {read=FGroupByBoxViewInfo};
	__property TcxGridHeaderViewInfo* HeaderViewInfo = {read=FHeaderViewInfo};
	__property TcxGridIndicatorViewInfo* IndicatorViewInfo = {read=FIndicatorViewInfo};
	__property int LeftPos = {read=GetLeftPos, nodefault};
	__property int LevelIndent = {read=FLevelIndent, write=FLevelIndent, nodefault};
	__property Vcl::Graphics::TBitmap* LevelIndentBackgroundBitmap = {read=GetLevelIndentBackgroundBitmap};
	__property System::Uitypes::TColor LevelIndentColors[int Index] = {read=GetLevelIndentColor};
	__property System::Uitypes::TColor LevelSeparatorColor = {read=GetLevelSeparatorColor, nodefault};
	__property TcxGridRowsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property int VisualLevelCount = {read=GetVisualLevelCount, nodefault};
public:
	/* TcxCustomGridTableViewInfo.Create */ inline __fastcall virtual TcxGridTableViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableViewInfo(AGridView) { }
	/* TcxCustomGridTableViewInfo.Destroy */ inline __fastcall virtual ~TcxGridTableViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridTableViewInfoCacheItem : public Cxgridcustomtableview::TcxCustomGridTableViewInfoCacheItem
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewInfoCacheItem inherited;
	
private:
	bool FIsPreviewHeightAssigned;
	int FPreviewHeight;
	void __fastcall SetPreviewHeight(int Value);
	
public:
	virtual void __fastcall UnassignValues(bool AKeepMaster);
	__property bool IsPreviewHeightAssigned = {read=FIsPreviewHeightAssigned, write=FIsPreviewHeightAssigned, nodefault};
	__property int PreviewHeight = {read=FPreviewHeight, write=SetPreviewHeight, nodefault};
public:
	/* TcxCustomGridViewInfoCacheItem.Create */ inline __fastcall virtual TcxGridTableViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex) : Cxgridcustomtableview::TcxCustomGridTableViewInfoCacheItem(AOwner, AIndex) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridTableViewInfoCacheItem(void) { }
	
};


class DELPHICLASS TcxGridMasterTableViewInfoCacheItem;
class PASCALIMPLEMENTATION TcxGridMasterTableViewInfoCacheItem : public TcxGridTableViewInfoCacheItem
{
	typedef TcxGridTableViewInfoCacheItem inherited;
	
private:
	bool FIsDetailsSiteFullyVisibleAssigned;
	bool FIsDetailsSiteHeightAssigned;
	bool FIsDetailsSiteNormalHeightAssigned;
	bool FIsDetailsSiteWidthAssigned;
	bool FDetailsSiteFullyVisible;
	int FDetailsSiteHeight;
	int FDetailsSiteNormalHeight;
	int FDetailsSiteWidth;
	bool FUnassigningValues;
	HIDESBASE TcxGridMasterDataRow* __fastcall GetGridRecord(void);
	bool __fastcall GetIsDetailsSiteCachedInfoAssigned(void);
	void __fastcall SetDetailsSiteFullyVisible(bool Value);
	void __fastcall SetDetailsSiteHeight(int Value);
	void __fastcall SetDetailsSiteNormalHeight(int Value);
	void __fastcall SetDetailsSiteWidth(int Value);
	
protected:
	__property TcxGridMasterDataRow* GridRecord = {read=GetGridRecord};
	
public:
	Cxgriddetailssite::TcxCustomGridDetailsSiteViewInfoCachedInfo* DetailsSiteCachedInfo;
	__fastcall virtual ~TcxGridMasterTableViewInfoCacheItem(void);
	virtual void __fastcall UnassignValues(bool AKeepMaster);
	__property bool IsDetailsSiteCachedInfoAssigned = {read=GetIsDetailsSiteCachedInfoAssigned, nodefault};
	__property bool IsDetailsSiteFullyVisibleAssigned = {read=FIsDetailsSiteFullyVisibleAssigned, write=FIsDetailsSiteFullyVisibleAssigned, nodefault};
	__property bool IsDetailsSiteHeightAssigned = {read=FIsDetailsSiteHeightAssigned, write=FIsDetailsSiteHeightAssigned, nodefault};
	__property bool IsDetailsSiteNormalHeightAssigned = {read=FIsDetailsSiteNormalHeightAssigned, write=FIsDetailsSiteNormalHeightAssigned, nodefault};
	__property bool IsDetailsSiteWidthAssigned = {read=FIsDetailsSiteWidthAssigned, write=FIsDetailsSiteWidthAssigned, nodefault};
	__property bool DetailsSiteFullyVisible = {read=FDetailsSiteFullyVisible, write=SetDetailsSiteFullyVisible, nodefault};
	__property int DetailsSiteHeight = {read=FDetailsSiteHeight, write=SetDetailsSiteHeight, nodefault};
	__property int DetailsSiteNormalHeight = {read=FDetailsSiteNormalHeight, write=SetDetailsSiteNormalHeight, nodefault};
	__property int DetailsSiteWidth = {read=FDetailsSiteWidth, write=SetDetailsSiteWidth, nodefault};
public:
	/* TcxCustomGridViewInfoCacheItem.Create */ inline __fastcall virtual TcxGridMasterTableViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex) : TcxGridTableViewInfoCacheItem(AOwner, AIndex) { }
	
};


class DELPHICLASS TcxGridColumnOptions;
class PASCALIMPLEMENTATION TcxGridColumnOptions : public Cxgridcustomtableview::TcxCustomGridTableItemOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemOptions inherited;
	
private:
	bool FCellMerging;
	bool FGroupFooters;
	bool FHorzSizing;
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	void __fastcall SetCellMerging(bool Value);
	void __fastcall SetGroupFooters(bool Value);
	void __fastcall SetHorzSizing(bool Value);
	
protected:
	__property TcxGridTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridColumnOptions(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CellMerging = {read=FCellMerging, write=SetCellMerging, default=0};
	__property EditAutoHeight = {default=0};
	__property bool GroupFooters = {read=FGroupFooters, write=SetGroupFooters, default=1};
	__property Grouping = {default=1};
	__property bool HorzSizing = {read=FHorzSizing, write=SetHorzSizing, default=1};
	__property Moving = {default=1};
	__property ShowCaption = {default=1};
	__property SortByDisplayText = {default=0};
	__property Sorting = {default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridColumnOptions(void) { }
	
};


typedef void __fastcall (__closure *TcxGridGetFooterStyleExEvent)(TcxGridTableView* Sender, TcxCustomGridRow* ARow, TcxGridColumn* AColumn, int AFooterGroupLevel, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxGridGetFooterSummaryStyleEvent)(TcxGridTableView* AView, TcxCustomGridRow* ARow, TcxGridColumn* AColumn, int AFooterGroupLevel, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxGridGetGroupSummaryStyleEvent)(TcxGridTableView* Sender, TcxGridGroupRow* ARow, TcxGridColumn* AColumn, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxGridGetHeaderStyleEvent)(TcxGridTableView* Sender, TcxGridColumn* AColumn, Cxstyles::TcxStyle* &AStyle);

class DELPHICLASS TcxGridColumnStyles;
class PASCALIMPLEMENTATION TcxGridColumnStyles : public Cxgridcustomtableview::TcxCustomGridTableItemStyles
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemStyles inherited;
	
private:
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetFooterStyle;
	TcxGridGetFooterStyleExEvent FOnGetFooterStyleEx;
	TcxGridGetFooterSummaryStyleEvent FOnGetFooterSummaryStyle;
	TcxGridGetGroupSummaryStyleEvent FOnGetGroupSummaryStyle;
	TcxGridGetHeaderStyleEvent FOnGetHeaderStyle;
	HIDESBASE TcxGridTableView* __fastcall GetGridViewValue(void);
	HIDESBASE TcxGridColumn* __fastcall GetItem(void);
	void __fastcall SetOnGetFooterStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetFooterStyleEx(TcxGridGetFooterStyleExEvent Value);
	void __fastcall SetOnGetFooterSummaryStyle(TcxGridGetFooterSummaryStyleEvent Value);
	void __fastcall SetOnGetGroupSummaryStyle(TcxGridGetGroupSummaryStyleEvent Value);
	void __fastcall SetOnGetHeaderStyle(TcxGridGetHeaderStyleEvent Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetFooterParams(TcxCustomGridRow* ARow, int AFooterGroupLevel, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetGroupSummaryParams(TcxGridGroupRow* ARow, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetHeaderParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridTableView* GridView = {read=GetGridViewValue};
	__property TcxGridColumn* Item = {read=GetItem};
	
__published:
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* GroupSummary = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=3};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetFooterStyle = {read=FOnGetFooterStyle, write=SetOnGetFooterStyle};
	__property TcxGridGetFooterStyleExEvent OnGetFooterStyleEx = {read=FOnGetFooterStyleEx, write=SetOnGetFooterStyleEx};
	__property TcxGridGetFooterSummaryStyleEvent OnGetFooterSummaryStyle = {read=FOnGetFooterSummaryStyle, write=SetOnGetFooterSummaryStyle};
	__property TcxGridGetGroupSummaryStyleEvent OnGetGroupSummaryStyle = {read=FOnGetGroupSummaryStyle, write=SetOnGetGroupSummaryStyle};
	__property TcxGridGetHeaderStyleEvent OnGetHeaderStyle = {read=FOnGetHeaderStyle, write=SetOnGetHeaderStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxGridColumnStyles(System::Classes::TPersistent* AOwner) : Cxgridcustomtableview::TcxCustomGridTableItemStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridColumnStyles(void) { }
	
};


enum TcxGridSummariesIndex : unsigned char { siFooter, siGroupFooter, siGroup };

typedef System::TMetaClass* TcxGridColumnSummaryClass;

class DELPHICLASS TcxGridColumnSummary;
class PASCALIMPLEMENTATION TcxGridColumnSummary : public Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions inherited;
	
private:
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	System::UnicodeString __fastcall GetFormat(int Index);
	Cxcustomdata::TcxSummaryKind __fastcall GetKind(int Index);
	bool __fastcall GetSortByGroupFooterSummary(void);
	bool __fastcall GetSortByGroupSummary(void);
	void __fastcall SetFormat(int Index, const System::UnicodeString Value);
	void __fastcall SetKind(int Index, Cxcustomdata::TcxSummaryKind Value);
	void __fastcall SetSortByGroupFooterSummary(bool Value);
	void __fastcall SetSortByGroupSummary(bool Value);
	
protected:
	Cxcustomdata::TcxDataSummaryItems* __fastcall GetSummaryItems(TcxGridSummariesIndex AIndex);
	Cxcustomdata::TcxSummaryPosition __fastcall GetSummaryItemsPosition(TcxGridSummariesIndex AIndex);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Cxcustomdata::TcxSummaryKind FooterKind = {read=GetKind, write=SetKind, stored=false, index=0, nodefault};
	__property System::UnicodeString FooterFormat = {read=GetFormat, write=SetFormat, stored=false, index=0};
	__property Cxcustomdata::TcxSummaryKind GroupFooterKind = {read=GetKind, write=SetKind, stored=false, index=1, nodefault};
	__property System::UnicodeString GroupFooterFormat = {read=GetFormat, write=SetFormat, stored=false, index=1};
	__property Cxcustomdata::TcxSummaryKind GroupKind = {read=GetKind, write=SetKind, stored=false, index=2, nodefault};
	__property System::UnicodeString GroupFormat = {read=GetFormat, write=SetFormat, stored=false, index=2};
	__property bool SortByGroupFooterSummary = {read=GetSortByGroupFooterSummary, write=SetSortByGroupFooterSummary, stored=false, nodefault};
	__property bool SortByGroupSummary = {read=GetSortByGroupSummary, write=SetSortByGroupSummary, stored=false, nodefault};
public:
	/* TcxCustomGridTableItemCustomOptions.Create */ inline __fastcall virtual TcxGridColumnSummary(Cxgridcustomtableview::TcxCustomGridTableItem* AItem) : Cxgridcustomtableview::TcxCustomGridTableItemCustomOptions(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridColumnSummary(void) { }
	
};


typedef void __fastcall (__closure *TcxGridColumnCompareRowValuesEvent)(TcxGridColumn* Sender, TcxGridDataRow* ARow1, Cxedit::TcxCustomEditProperties* AProperties1, const System::Variant &AValue1, TcxGridDataRow* ARow2, Cxedit::TcxCustomEditProperties* AProperties2, const System::Variant &AValue2, bool &AAreEqual);

typedef void __fastcall (__closure *TcxGridColumnCompareValuesEvent)(TcxGridColumn* Sender, Cxedit::TcxCustomEditProperties* AProperties1, const System::Variant &AValue1, Cxedit::TcxCustomEditProperties* AProperties2, const System::Variant &AValue2, bool &AAreEqual);

typedef void __fastcall (__closure *TcxGridColumnCustomDrawHeaderEvent)(TcxGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridGroupSummaryCellCustomDrawEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridGroupRow* ARow, TcxGridColumn* AColumn, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, Cxgridcustomview::TcxCustomGridViewCellViewInfo* AViewInfo, bool &ADone);

class PASCALIMPLEMENTATION TcxGridColumn : public Cxgridcustomtableview::TcxCustomGridTableItem
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItem inherited;
	
private:
	System::Classes::TAlignment FFooterAlignmentHorz;
	System::Classes::TAlignment FGroupSummaryAlignment;
	Vcl::Graphics::TBitmap* FHeaderGlyph;
	System::Classes::TAlignment FHeaderGlyphAlignmentHorz;
	Cxclasses::TcxAlignmentVert FHeaderGlyphAlignmentVert;
	System::Uitypes::TImageIndex FHeaderImageIndex;
	bool FIsFooterAlignmentHorzAssigned;
	bool FIsGroupSummaryAlignmentAssigned;
	bool FSelected;
	TcxGridColumnSummary* FSummary;
	TcxGridColumnCompareRowValuesEvent FOnCompareRowValuesForCellMerging;
	TcxGridColumnCompareValuesEvent FOnCompareValuesForCellMerging;
	TcxGridColumnCustomDrawHeaderEvent FOnCustomDrawFooterCell;
	TcxGridGroupSummaryCellCustomDrawEvent FOnCustomDrawGroupSummaryCell;
	TcxGridColumnCustomDrawHeaderEvent FOnCustomDrawHeader;
	System::Classes::TNotifyEvent FOnHeaderClick;
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	System::Classes::TAlignment __fastcall GetFooterAlignmentHorz(void);
	TcxGridTableView* __fastcall GetGridView(void);
	System::Classes::TAlignment __fastcall GetGroupSummaryAlignment(void);
	bool __fastcall GetIsPreview(void);
	TcxGridColumnOptions* __fastcall GetOptions(void);
	TcxGridColumnStyles* __fastcall GetStyles(void);
	HIDESBASE TcxGridViewData* __fastcall GetViewData(void);
	void __fastcall SetFooterAlignmentHorz(System::Classes::TAlignment Value);
	void __fastcall SetGroupSummaryAlignment(System::Classes::TAlignment Value);
	void __fastcall SetHeaderGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetHeaderGlyphAlignmentHorz(System::Classes::TAlignment Value);
	void __fastcall SetHeaderGlyphAlignmentVert(Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetHeaderImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetIsPreview(bool Value);
	void __fastcall SetOnCompareRowValuesForCellMerging(TcxGridColumnCompareRowValuesEvent Value);
	void __fastcall SetOnCompareValuesForCellMerging(TcxGridColumnCompareValuesEvent Value);
	void __fastcall SetOnCustomDrawFooterCell(TcxGridColumnCustomDrawHeaderEvent Value);
	void __fastcall SetOnCustomDrawGroupSummaryCell(TcxGridGroupSummaryCellCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawHeader(TcxGridColumnCustomDrawHeaderEvent Value);
	void __fastcall SetOnHeaderClick(System::Classes::TNotifyEvent Value);
	HIDESBASE void __fastcall SetOptions(TcxGridColumnOptions* Value);
	void __fastcall SetSelected(bool Value);
	HIDESBASE void __fastcall SetStyles(TcxGridColumnStyles* Value);
	void __fastcall SetSummary(TcxGridColumnSummary* Value);
	bool __fastcall IsFooterAlignmentHorzStored(void);
	bool __fastcall IsGroupSummaryAlignmentStored(void);
	void __fastcall HeaderGlyphChanged(System::TObject* Sender);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemOptionsClass __fastcall GetOptionsClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemStylesClass __fastcall GetStylesClass(void);
	virtual TcxGridColumnSummaryClass __fastcall GetSummaryClass(void);
	virtual void __fastcall AssignColumnWidths(void);
	virtual void __fastcall BestFitApplied(bool AFireEvents);
	virtual int __fastcall CalculateBestFitWidth(void);
	virtual bool __fastcall CanCellMerging(void);
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanFocus(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual bool __fastcall CanHorzSize(void);
	virtual bool __fastcall CanShowGroupFooters(void);
	virtual void __fastcall ForceWidth(int Value);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual void __fastcall SetEditValue(const System::Variant &Value);
	virtual bool __fastcall GetFixed(void);
	virtual bool __fastcall GetIsBottom(void);
	virtual bool __fastcall GetIsLeft(void);
	virtual bool __fastcall GetIsMostBottom(void);
	virtual bool __fastcall GetIsMostLeft(void);
	virtual bool __fastcall GetIsMostRight(void);
	virtual bool __fastcall GetIsRight(void);
	virtual bool __fastcall GetIsTop(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall GetVisibleForCustomization(void);
	virtual bool __fastcall HasFixedWidth(void);
	virtual bool __fastcall HideOnGrouping(void);
	bool __fastcall IsFilterRowIncrementalFiltering(void);
	virtual bool __fastcall IsVisibleStored(void);
	virtual bool __fastcall IsVisibleForCustomizationStored(void);
	bool __fastcall SupportsBeginsWithFilterOperator(TcxCustomGridRow* ARow);
	TcxGridColumnHeaderViewInfoClass __fastcall GetHeaderViewInfoClass(void);
	virtual void __fastcall DoCustomDrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupSummaryCell(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridViewCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawHeader(Cxgraphics::TcxCanvas* ACanvas, TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoHeaderClick(void);
	bool __fastcall HasCustomDrawFooterCell(void);
	bool __fastcall HasCustomDrawGroupSummaryCell(void);
	bool __fastcall HasCustomDrawHeader(void);
	bool __fastcall HasGlyph(void);
	__property TcxGridTableController* Controller = {read=GetController};
	__property TcxGridViewData* ViewData = {read=GetViewData};
	
public:
	__fastcall virtual TcxGridColumn(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridColumn(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall DoCompareValuesForCellMerging(TcxGridDataRow* ARow1, Cxedit::TcxCustomEditProperties* AProperties1, const System::Variant &AValue1, TcxGridDataRow* ARow2, Cxedit::TcxCustomEditProperties* AProperties2, const System::Variant &AValue2);
	virtual void __fastcall FocusWithSelection(void);
	bool __fastcall GroupBy(int AGroupIndex, bool ACanShow = true);
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property GroupingDateRanges;
	__property Hidden;
	__property bool IsBottom = {read=GetIsBottom, nodefault};
	__property bool IsLeft = {read=GetIsLeft, nodefault};
	__property bool IsMostBottom = {read=GetIsMostBottom, nodefault};
	__property bool IsMostLeft = {read=GetIsMostLeft, nodefault};
	__property bool IsMostRight = {read=GetIsMostRight, nodefault};
	__property bool IsPreview = {read=GetIsPreview, write=SetIsPreview, nodefault};
	__property bool IsRight = {read=GetIsRight, nodefault};
	__property bool IsTop = {read=GetIsTop, nodefault};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	
__published:
	__property BestFitMaxWidth = {default=0};
	__property DateTimeGrouping = {default=0};
	__property System::Classes::TAlignment FooterAlignmentHorz = {read=GetFooterAlignmentHorz, write=SetFooterAlignmentHorz, stored=IsFooterAlignmentHorzStored, nodefault};
	__property GroupIndex = {default=-1};
	__property System::Classes::TAlignment GroupSummaryAlignment = {read=GetGroupSummaryAlignment, write=SetGroupSummaryAlignment, stored=IsGroupSummaryAlignmentStored, nodefault};
	__property HeaderAlignmentHorz;
	__property HeaderAlignmentVert;
	__property Vcl::Graphics::TBitmap* HeaderGlyph = {read=FHeaderGlyph, write=SetHeaderGlyph};
	__property System::Classes::TAlignment HeaderGlyphAlignmentHorz = {read=FHeaderGlyphAlignmentHorz, write=SetHeaderGlyphAlignmentHorz, default=0};
	__property Cxclasses::TcxAlignmentVert HeaderGlyphAlignmentVert = {read=FHeaderGlyphAlignmentVert, write=SetHeaderGlyphAlignmentVert, default=2};
	__property HeaderHint = {default=0};
	__property System::Uitypes::TImageIndex HeaderImageIndex = {read=FHeaderImageIndex, write=SetHeaderImageIndex, default=-1};
	__property MinWidth = {default=20};
	__property TcxGridColumnOptions* Options = {read=GetOptions, write=SetOptions};
	__property SortIndex = {default=-1};
	__property SortOrder;
	__property TcxGridColumnStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridColumnSummary* Summary = {read=FSummary, write=SetSummary};
	__property VisibleForCustomization;
	__property Width;
	__property TcxGridColumnCompareRowValuesEvent OnCompareRowValuesForCellMerging = {read=FOnCompareRowValuesForCellMerging, write=SetOnCompareRowValuesForCellMerging};
	__property TcxGridColumnCompareValuesEvent OnCompareValuesForCellMerging = {read=FOnCompareValuesForCellMerging, write=SetOnCompareValuesForCellMerging};
	__property TcxGridColumnCustomDrawHeaderEvent OnCustomDrawFooterCell = {read=FOnCustomDrawFooterCell, write=SetOnCustomDrawFooterCell};
	__property TcxGridGroupSummaryCellCustomDrawEvent OnCustomDrawGroupSummaryCell = {read=FOnCustomDrawGroupSummaryCell, write=SetOnCustomDrawGroupSummaryCell};
	__property TcxGridColumnCustomDrawHeaderEvent OnCustomDrawHeader = {read=FOnCustomDrawHeader, write=SetOnCustomDrawHeader};
	__property System::Classes::TNotifyEvent OnHeaderClick = {read=FOnHeaderClick, write=SetOnHeaderClick};
	__property OnInitGroupingDateRanges;
};


class DELPHICLASS TcxGridTableBackgroundBitmaps;
class PASCALIMPLEMENTATION TcxGridTableBackgroundBitmaps : public Cxgridcustomtableview::TcxCustomGridTableBackgroundBitmaps
{
	typedef Cxgridcustomtableview::TcxCustomGridTableBackgroundBitmaps inherited;
	
protected:
	virtual int __fastcall GetBitmapStyleIndex(int Index);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Graphics::TBitmap* Footer = {read=GetValue, write=SetValue, index=3};
	__property Vcl::Graphics::TBitmap* Header = {read=GetValue, write=SetValue, index=4};
	__property Vcl::Graphics::TBitmap* Group = {read=GetValue, write=SetValue, index=5};
	__property Vcl::Graphics::TBitmap* GroupByBox = {read=GetValue, write=SetValue, index=6};
	__property Vcl::Graphics::TBitmap* Indicator = {read=GetValue, write=SetValue, index=7};
	__property Vcl::Graphics::TBitmap* Preview = {read=GetValue, write=SetValue, index=8};
public:
	/* TcxCustomGridBackgroundBitmaps.Create */ inline __fastcall virtual TcxGridTableBackgroundBitmaps(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableBackgroundBitmaps(AGridView) { }
	/* TcxCustomGridBackgroundBitmaps.Destroy */ inline __fastcall virtual ~TcxGridTableBackgroundBitmaps(void) { }
	
};


class DELPHICLASS TcxGridTableDateTimeHandling;
class PASCALIMPLEMENTATION TcxGridTableDateTimeHandling : public Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling
{
	typedef Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling inherited;
	
__published:
	__property DateFormat = {default=0};
	__property Grouping = {default=1};
	__property HourFormat = {default=0};
	__property UseLongDateFormat = {default=1};
	__property UseShortTimeFormat = {default=1};
public:
	/* TcxCustomGridTableDateTimeHandling.Create */ inline __fastcall virtual TcxGridTableDateTimeHandling(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridTableDateTimeHandling(void) { }
	
};


class DELPHICLASS TcxGridTableShowLockedStateImageOptions;
class PASCALIMPLEMENTATION TcxGridTableShowLockedStateImageOptions : public Cxgridcustomtableview::TcxCustomGridTableShowLockedStateImageOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableShowLockedStateImageOptions inherited;
	
__published:
	__property BestFit = {default=1};
	__property Filtering = {default=1};
	__property Grouping = {default=1};
	__property Sorting = {default=1};
public:
	/* TcxCustomGridTableShowLockedStateImageOptions.Create */ inline __fastcall virtual TcxGridTableShowLockedStateImageOptions(void) : Cxgridcustomtableview::TcxCustomGridTableShowLockedStateImageOptions() { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridTableShowLockedStateImageOptions(void) { }
	
};


class DELPHICLASS TcxGridTableOptionsBehavior;
class PASCALIMPLEMENTATION TcxGridTableOptionsBehavior : public Cxgridcustomtableview::TcxCustomGridTableOptionsBehavior
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsBehavior inherited;
	
private:
	bool FColumnHeaderHints;
	bool FCopyPreviewToClipboard;
	bool FExpandMasterRowOnDblClick;
	HIDESBASE TcxGridTableShowLockedStateImageOptions* __fastcall GetShowLockedStateImageOptions(void);
	void __fastcall SetColumnHeaderHints(bool Value);
	void __fastcall SetCopyPreviewToClipboard(bool Value);
	void __fastcall SetExpandMasterRowOnDblClick(bool Value);
	HIDESBASE void __fastcall SetShowLockedStateImageOptions(TcxGridTableShowLockedStateImageOptions* Value);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridShowLockedStateImageOptionsClass __fastcall GetShowLockedStateImageOptionsClass(void);
	
public:
	__fastcall virtual TcxGridTableOptionsBehavior(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property RepaintVisibleRecordsOnScroll = {default=0};
	
__published:
	__property BestFitMaxRecordCount = {default=0};
	__property bool ColumnHeaderHints = {read=FColumnHeaderHints, write=SetColumnHeaderHints, default=1};
	__property bool CopyPreviewToClipboard = {read=FCopyPreviewToClipboard, write=SetCopyPreviewToClipboard, default=1};
	__property EditAutoHeight = {default=0};
	__property bool ExpandMasterRowOnDblClick = {read=FExpandMasterRowOnDblClick, write=SetExpandMasterRowOnDblClick, default=1};
	__property FocusCellOnCycle = {default=0};
	__property RecordScrollMode = {default=0};
	__property TcxGridTableShowLockedStateImageOptions* ShowLockedStateImageOptions = {read=GetShowLockedStateImageOptions, write=SetShowLockedStateImageOptions};
	__property PullFocusing = {default=0};
public:
	/* TcxCustomGridOptionsBehavior.Destroy */ inline __fastcall virtual ~TcxGridTableOptionsBehavior(void) { }
	
};


class DELPHICLASS TcxGridTableFiltering;
class PASCALIMPLEMENTATION TcxGridTableFiltering : public Cxgridcustomtableview::TcxCustomGridTableFiltering
{
	typedef Cxgridcustomtableview::TcxCustomGridTableFiltering inherited;
	
private:
	bool __fastcall GetColumnAddValueItems(void);
	bool __fastcall GetColumnFilteredItemsList(void);
	bool __fastcall GetColumnMRUItemsList(void);
	int __fastcall GetColumnMRUItemsListCount(void);
	Cxgridcustomtableview::TcxGridItemFilterPopupOptions* __fastcall GetColumnPopup(void);
	void __fastcall SetColumnAddValueItems(bool Value);
	void __fastcall SetColumnFilteredItemsList(bool Value);
	void __fastcall SetColumnMRUItemsList(bool Value);
	void __fastcall SetColumnMRUItemsListCount(int Value);
	void __fastcall SetColumnPopup(Cxgridcustomtableview::TcxGridItemFilterPopupOptions* Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	__property int ColumnPopupDropDownWidth = {read=GetItemPopupDropDownWidth, write=SetItemPopupDropDownWidth, nodefault};
	__property DropDownWidth;
	__property int ColumnPopupMaxDropDownItemCount = {read=GetItemPopupMaxDropDownItemCount, write=SetItemPopupMaxDropDownItemCount, nodefault};
	__property MaxDropDownCount;
	
__published:
	__property bool ColumnAddValueItems = {read=GetColumnAddValueItems, write=SetColumnAddValueItems, default=1};
	__property bool ColumnFilteredItemsList = {read=GetColumnFilteredItemsList, write=SetColumnFilteredItemsList, default=0};
	__property bool ColumnMRUItemsList = {read=GetColumnMRUItemsList, write=SetColumnMRUItemsList, default=1};
	__property int ColumnMRUItemsListCount = {read=GetColumnMRUItemsListCount, write=SetColumnMRUItemsListCount, default=5};
	__property Cxgridcustomtableview::TcxGridItemFilterPopupOptions* ColumnPopup = {read=GetColumnPopup, write=SetColumnPopup};
public:
	/* TcxCustomGridTableFiltering.Create */ inline __fastcall virtual TcxGridTableFiltering(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableFiltering(AGridView) { }
	/* TcxCustomGridTableFiltering.Destroy */ inline __fastcall virtual ~TcxGridTableFiltering(void) { }
	
};


class DELPHICLASS TcxGridTableOptionsCustomize;
class PASCALIMPLEMENTATION TcxGridTableOptionsCustomize : public Cxgridcustomtableview::TcxCustomGridTableOptionsCustomize
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsCustomize inherited;
	
private:
	bool FColumnHidingOnGrouping;
	bool FColumnHorzSizing;
	bool FDataRowSizing;
	bool FGroupBySorting;
	bool FGroupRowSizing;
	bool __fastcall GetColumnFiltering(void);
	bool __fastcall GetColumnGrouping(void);
	bool __fastcall GetColumnHiding(void);
	bool __fastcall GetColumnMoving(void);
	bool __fastcall GetColumnSorting(void);
	bool __fastcall GetColumnsQuickCustomization(void);
	int __fastcall GetColumnsQuickCustomizationMaxDropDownCount(void);
	Cxgridcustomtableview::TcxGridQuickCustomizationReordering __fastcall GetColumnsQuickCustomizationReordering(void);
	TcxGridTableView* __fastcall GetGridView(void);
	void __fastcall SetColumnFiltering(bool Value);
	void __fastcall SetColumnGrouping(bool Value);
	void __fastcall SetColumnHiding(bool Value);
	void __fastcall SetColumnHidingOnGrouping(bool Value);
	void __fastcall SetColumnHorzSizing(bool Value);
	void __fastcall SetColumnMoving(bool Value);
	void __fastcall SetColumnSorting(bool Value);
	void __fastcall SetColumnsQuickCustomization(bool Value);
	void __fastcall SetColumnsQuickCustomizationMaxDropDownCount(int Value);
	void __fastcall SetColumnsQuickCustomizationReordering(Cxgridcustomtableview::TcxGridQuickCustomizationReordering Value);
	void __fastcall SetDataRowSizing(bool Value);
	void __fastcall SetGroupBySorting(bool Value);
	void __fastcall SetGroupRowSizing(bool Value);
	
public:
	__fastcall virtual TcxGridTableOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridTableView* GridView = {read=GetGridView};
	
__published:
	__property bool ColumnFiltering = {read=GetColumnFiltering, write=SetColumnFiltering, default=1};
	__property bool ColumnGrouping = {read=GetColumnGrouping, write=SetColumnGrouping, default=1};
	__property bool ColumnHiding = {read=GetColumnHiding, write=SetColumnHiding, default=0};
	__property bool ColumnHidingOnGrouping = {read=FColumnHidingOnGrouping, write=SetColumnHidingOnGrouping, default=1};
	__property bool ColumnHorzSizing = {read=FColumnHorzSizing, write=SetColumnHorzSizing, default=1};
	__property bool ColumnMoving = {read=GetColumnMoving, write=SetColumnMoving, default=1};
	__property bool ColumnSorting = {read=GetColumnSorting, write=SetColumnSorting, default=1};
	__property bool ColumnsQuickCustomization = {read=GetColumnsQuickCustomization, write=SetColumnsQuickCustomization, default=0};
	__property int ColumnsQuickCustomizationMaxDropDownCount = {read=GetColumnsQuickCustomizationMaxDropDownCount, write=SetColumnsQuickCustomizationMaxDropDownCount, default=0};
	__property Cxgridcustomtableview::TcxGridQuickCustomizationReordering ColumnsQuickCustomizationReordering = {read=GetColumnsQuickCustomizationReordering, write=SetColumnsQuickCustomizationReordering, default=0};
	__property bool DataRowSizing = {read=FDataRowSizing, write=SetDataRowSizing, default=0};
	__property bool GroupBySorting = {read=FGroupBySorting, write=SetGroupBySorting, default=0};
	__property bool GroupRowSizing = {read=FGroupRowSizing, write=SetGroupRowSizing, default=0};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridTableOptionsCustomize(void) { }
	
};


class DELPHICLASS TcxGridTableOptionsData;
class PASCALIMPLEMENTATION TcxGridTableOptionsData : public Cxgridcustomtableview::TcxCustomGridTableOptionsData
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsData inherited;
	
public:
	/* TcxCustomGridTableOptionsData.Create */ inline __fastcall virtual TcxGridTableOptionsData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableOptionsData(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridTableOptionsData(void) { }
	
};


class DELPHICLASS TcxGridTableOptionsSelection;
class PASCALIMPLEMENTATION TcxGridTableOptionsSelection : public Cxgridcustomtableview::TcxCustomGridTableOptionsSelection
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsSelection inherited;
	
private:
	bool FCellMultiSelect;
	void __fastcall SetCellMultiSelect(bool Value);
	
protected:
	virtual void __fastcall SetCellSelect(bool Value);
	virtual void __fastcall SetInvertSelect(bool Value);
	virtual void __fastcall SetMultiSelect(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CellMultiSelect = {read=FCellMultiSelect, write=SetCellMultiSelect, default=0};
public:
	/* TcxCustomGridTableOptionsSelection.Create */ inline __fastcall virtual TcxGridTableOptionsSelection(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableOptionsSelection(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridTableOptionsSelection(void) { }
	
};


class DELPHICLASS TcxGridSpecialRowOptions;
class PASCALIMPLEMENTATION TcxGridSpecialRowOptions : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	System::UnicodeString FInfoText;
	bool FIsInfoTextAssigned;
	System::Uitypes::TColor FSeparatorColor;
	int FSeparatorWidth;
	bool FVisible;
	TcxGridTableView* __fastcall GetGridView(void);
	System::UnicodeString __fastcall GetInfoText(void);
	void __fastcall SetInfoText(const System::UnicodeString Value);
	void __fastcall SetSeparatorColor(System::Uitypes::TColor Value);
	void __fastcall SetSeparatorWidth(int Value);
	void __fastcall SetVisible(bool Value);
	bool __fastcall IsInfoTextStored(void);
	
protected:
	virtual System::UnicodeString __fastcall DefaultInfoText(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall DefaultSeparatorColor(void);
	virtual void __fastcall VisibleChanged(void) = 0 ;
	
public:
	__fastcall virtual TcxGridSpecialRowOptions(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Uitypes::TColor __fastcall GetSeparatorColor(void);
	__property TcxGridTableView* GridView = {read=GetGridView};
	
__published:
	__property System::UnicodeString InfoText = {read=GetInfoText, write=SetInfoText, stored=IsInfoTextStored};
	__property System::Uitypes::TColor SeparatorColor = {read=FSeparatorColor, write=SetSeparatorColor, default=536870912};
	__property int SeparatorWidth = {read=FSeparatorWidth, write=SetSeparatorWidth, default=6};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridSpecialRowOptions(void) { }
	
};


enum TcxGridFilterRowApplyChangesMode : unsigned char { fracOnCellExit, fracImmediately, fracDelayed };

typedef System::TMetaClass* TcxGridFilterRowOptionsClass;

class DELPHICLASS TcxGridFilterRowOptions;
class PASCALIMPLEMENTATION TcxGridFilterRowOptions : public TcxGridSpecialRowOptions
{
	typedef TcxGridSpecialRowOptions inherited;
	
private:
	TcxGridFilterRowApplyChangesMode FApplyChanges;
	unsigned FApplyInputDelay;
	void __fastcall SetApplyChanges(TcxGridFilterRowApplyChangesMode Value);
	void __fastcall SetApplyInputDelay(unsigned Value);
	
protected:
	virtual System::UnicodeString __fastcall DefaultInfoText(void);
	virtual void __fastcall VisibleChanged(void);
	
public:
	__fastcall virtual TcxGridFilterRowOptions(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxGridFilterRowApplyChangesMode ApplyChanges = {read=FApplyChanges, write=SetApplyChanges, default=0};
	__property unsigned ApplyInputDelay = {read=FApplyInputDelay, write=SetApplyInputDelay, default=1000};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridFilterRowOptions(void) { }
	
};


typedef System::TMetaClass* TcxGridNewItemRowOptionsClass;

class DELPHICLASS TcxGridNewItemRowOptions;
class PASCALIMPLEMENTATION TcxGridNewItemRowOptions : public TcxGridSpecialRowOptions
{
	typedef TcxGridSpecialRowOptions inherited;
	
protected:
	virtual System::UnicodeString __fastcall DefaultInfoText(void);
	virtual void __fastcall VisibleChanged(void);
public:
	/* TcxGridSpecialRowOptions.Create */ inline __fastcall virtual TcxGridNewItemRowOptions(Cxgridcustomview::TcxCustomGridView* AGridView) : TcxGridSpecialRowOptions(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridNewItemRowOptions(void) { }
	
};


enum TcxGridGroupByHeaderLayout : unsigned char { ghlVerticallyShifted, ghlHorizontal };

enum TcxGridGroupFootersMode : unsigned char { gfInvisible, gfVisibleWhenExpanded, gfAlwaysVisible };

enum TcxGridGroupRowStyle : unsigned char { grsStandard, grsOffice11 };

enum TcxGridGroupSummaryLayout : unsigned char { gslStandard, gslAlignWithColumns, gslAlignWithColumnsAndDistribute };

class DELPHICLASS TcxGridTableOptionsView;
class PASCALIMPLEMENTATION TcxGridTableOptionsView : public Cxgridcustomtableview::TcxCustomGridTableOptionsView
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsView inherited;
	
private:
	bool FColumnAutoWidth;
	int FDataRowHeight;
	bool FExpandButtonsForEmptyDetails;
	bool FFooter;
	bool FFooterAutoHeight;
	bool FFooterMultiSummaries;
	System::Uitypes::TColor FGridLineColor;
	Cxgraphics::TcxGridLines FGridLines;
	bool FGroupByBox;
	TcxGridGroupByHeaderLayout FGroupByHeaderLayout;
	bool FGroupFooterMultiSummaries;
	TcxGridGroupFootersMode FGroupFooters;
	int FGroupRowHeight;
	TcxGridGroupRowStyle FGroupRowStyle;
	TcxGridGroupSummaryLayout FGroupSummaryLayout;
	bool FHeader;
	int FHeaderHeight;
	bool FIndicator;
	int FIndicatorWidth;
	TcxGridGroupFootersMode FPrevGroupFooters;
	System::Uitypes::TColor FRowSeparatorColor;
	int FRowSeparatorWidth;
	bool __fastcall GetExpandButtonsForEmptyDetails(void);
	HIDESBASE TcxGridTableView* __fastcall GetGridView(void);
	bool __fastcall GetHeaderAutoHeight(void);
	bool __fastcall GetHeaderEndEllipsis(void);
	Cxgridcustomtableview::TcxGridItemFilterButtonShowMode __fastcall GetHeaderFilterButtonShowMode(void);
	bool __fastcall GetNewItemRow(void);
	System::UnicodeString __fastcall GetNewItemRowInfoText(void);
	System::Uitypes::TColor __fastcall GetNewItemRowSeparatorColor(void);
	int __fastcall GetNewItemRowSeparatorWidth(void);
	Cxgridcustomtableview::TcxGridShowItemFilterButtons __fastcall GetShowColumnFilterButtons(void);
	void __fastcall SetColumnAutoWidth(bool Value);
	void __fastcall SetDataRowHeight(int Value);
	void __fastcall SetExpandButtonsForEmptyDetails(bool Value);
	void __fastcall SetHeaderFilterButtonShowMode(Cxgridcustomtableview::TcxGridItemFilterButtonShowMode Value);
	void __fastcall SetFooter(bool Value);
	void __fastcall SetFooterAutoHeight(bool Value);
	void __fastcall SetFooterMultiSummaries(bool Value);
	void __fastcall SetGridLineColor(System::Uitypes::TColor Value);
	void __fastcall SetGridLines(Cxgraphics::TcxGridLines Value);
	void __fastcall SetGroupByBox(bool Value);
	void __fastcall SetGroupByHeaderLayout(TcxGridGroupByHeaderLayout Value);
	void __fastcall SetGroupFooterMultiSummaries(bool Value);
	void __fastcall SetGroupFooters(TcxGridGroupFootersMode Value);
	void __fastcall SetGroupRowHeight(int Value);
	void __fastcall SetGroupRowStyle(TcxGridGroupRowStyle Value);
	void __fastcall SetGroupSummaryLayout(TcxGridGroupSummaryLayout Value);
	void __fastcall SetHeader(bool Value);
	void __fastcall SetHeaderAutoHeight(bool Value);
	void __fastcall SetHeaderEndEllipsis(bool Value);
	void __fastcall SetHeaderHeight(int Value);
	void __fastcall SetIndicator(bool Value);
	void __fastcall SetIndicatorWidth(int Value);
	void __fastcall SetNewItemRow(bool Value);
	void __fastcall SetNewItemRowInfoText(const System::UnicodeString Value);
	void __fastcall SetNewItemRowSeparatorColor(System::Uitypes::TColor Value);
	void __fastcall SetNewItemRowSeparatorWidth(int Value);
	void __fastcall SetRowSeparatorColor(System::Uitypes::TColor Value);
	void __fastcall SetRowSeparatorWidth(int Value);
	void __fastcall SetShowColumnFilterButtons(Cxgridcustomtableview::TcxGridShowItemFilterButtons Value);
	void __fastcall ReadNewItemRow(System::Classes::TReader* Reader);
	void __fastcall ReadNewItemRowInfoText(System::Classes::TReader* Reader);
	void __fastcall ReadNewItemRowSeparatorColor(System::Classes::TReader* Reader);
	void __fastcall ReadNewItemRowSeparatorWidth(System::Classes::TReader* Reader);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall ItemCaptionAutoHeightChanged(void);
	
public:
	__fastcall virtual TcxGridTableOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall CanShowFooterMultiSummaries(void);
	bool __fastcall CanShowGroupFooterMultiSummaries(void);
	virtual void __fastcall CheckDataRowHeight(int &AValue);
	virtual void __fastcall CheckGroupRowHeight(int &AValue);
	virtual System::Uitypes::TColor __fastcall GetGridLineColor(void);
	TcxGridGroupSummaryLayout __fastcall GetGroupSummaryLayout(void);
	System::Uitypes::TColor __fastcall GetRowSeparatorColor(void);
	__property TcxGridTableView* GridView = {read=GetGridView};
	__property bool NewItemRow = {read=GetNewItemRow, write=SetNewItemRow, nodefault};
	__property System::UnicodeString NewItemRowInfoText = {read=GetNewItemRowInfoText, write=SetNewItemRowInfoText};
	__property System::Uitypes::TColor NewItemRowSeparatorColor = {read=GetNewItemRowSeparatorColor, write=SetNewItemRowSeparatorColor, nodefault};
	__property int NewItemRowSeparatorWidth = {read=GetNewItemRowSeparatorWidth, write=SetNewItemRowSeparatorWidth, nodefault};
	__property TcxGridGroupFootersMode PrevGroupFooters = {read=FPrevGroupFooters, nodefault};
	
__published:
	__property CellAutoHeight = {default=0};
	__property CellTextMaxLineCount = {default=0};
	__property bool ColumnAutoWidth = {read=FColumnAutoWidth, write=SetColumnAutoWidth, default=0};
	__property int DataRowHeight = {read=FDataRowHeight, write=SetDataRowHeight, default=0};
	__property EditAutoHeightBorderColor = {default=536870912};
	__property bool ExpandButtonsForEmptyDetails = {read=GetExpandButtonsForEmptyDetails, write=SetExpandButtonsForEmptyDetails, default=1};
	__property bool Footer = {read=FFooter, write=SetFooter, default=0};
	__property bool FooterAutoHeight = {read=FFooterAutoHeight, write=SetFooterAutoHeight, default=0};
	__property bool FooterMultiSummaries = {read=FFooterMultiSummaries, write=SetFooterMultiSummaries, default=0};
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=536870912};
	__property Cxgraphics::TcxGridLines GridLines = {read=FGridLines, write=SetGridLines, default=0};
	__property bool GroupByBox = {read=FGroupByBox, write=SetGroupByBox, default=1};
	__property TcxGridGroupByHeaderLayout GroupByHeaderLayout = {read=FGroupByHeaderLayout, write=SetGroupByHeaderLayout, default=0};
	__property bool GroupFooterMultiSummaries = {read=FGroupFooterMultiSummaries, write=SetGroupFooterMultiSummaries, default=0};
	__property TcxGridGroupFootersMode GroupFooters = {read=FGroupFooters, write=SetGroupFooters, default=0};
	__property int GroupRowHeight = {read=FGroupRowHeight, write=SetGroupRowHeight, default=0};
	__property TcxGridGroupRowStyle GroupRowStyle = {read=FGroupRowStyle, write=SetGroupRowStyle, default=0};
	__property TcxGridGroupSummaryLayout GroupSummaryLayout = {read=FGroupSummaryLayout, write=SetGroupSummaryLayout, default=0};
	__property bool Header = {read=FHeader, write=SetHeader, default=1};
	__property bool HeaderAutoHeight = {read=GetHeaderAutoHeight, write=SetHeaderAutoHeight, default=0};
	__property bool HeaderEndEllipsis = {read=GetHeaderEndEllipsis, write=SetHeaderEndEllipsis, default=0};
	__property Cxgridcustomtableview::TcxGridItemFilterButtonShowMode HeaderFilterButtonShowMode = {read=GetHeaderFilterButtonShowMode, write=SetHeaderFilterButtonShowMode, default=1};
	__property int HeaderHeight = {read=FHeaderHeight, write=SetHeaderHeight, default=0};
	__property bool Indicator = {read=FIndicator, write=SetIndicator, default=0};
	__property int IndicatorWidth = {read=FIndicatorWidth, write=SetIndicatorWidth, default=12};
	__property System::Uitypes::TColor RowSeparatorColor = {read=FRowSeparatorColor, write=SetRowSeparatorColor, default=536870912};
	__property int RowSeparatorWidth = {read=FRowSeparatorWidth, write=SetRowSeparatorWidth, default=0};
	__property Cxgridcustomtableview::TcxGridShowItemFilterButtons ShowColumnFilterButtons = {read=GetShowColumnFilterButtons, write=SetShowColumnFilterButtons, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridTableOptionsView(void) { }
	
};


enum TcxGridPreviewPlace : unsigned char { ppBottom, ppTop };

typedef System::TMetaClass* TcxGridPreviewClass;

class DELPHICLASS TcxGridPreview;
class PASCALIMPLEMENTATION TcxGridPreview : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	bool FAutoHeight;
	TcxGridColumn* FColumn;
	int FLeftIndent;
	int FMaxLineCount;
	TcxGridPreviewPlace FPlace;
	int FRightIndent;
	bool FVisible;
	bool __fastcall GetActive(void);
	TcxGridTableView* __fastcall GetGridView(void);
	void __fastcall SetAutoHeight(bool Value);
	void __fastcall SetColumn(TcxGridColumn* Value);
	void __fastcall SetLeftIndent(int Value);
	void __fastcall SetMaxLineCount(int Value);
	void __fastcall SetPlace(TcxGridPreviewPlace Value);
	void __fastcall SetRightIndent(int Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	int __fastcall GetFixedHeight(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	void __fastcall PropertyChanged(void);
	
public:
	__fastcall virtual TcxGridPreview(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool Active = {read=GetActive, nodefault};
	__property TcxGridTableView* GridView = {read=GetGridView};
	
__published:
	__property bool AutoHeight = {read=FAutoHeight, write=SetAutoHeight, default=1};
	__property TcxGridColumn* Column = {read=FColumn, write=SetColumn};
	__property int LeftIndent = {read=FLeftIndent, write=SetLeftIndent, default=20};
	__property int MaxLineCount = {read=FMaxLineCount, write=SetMaxLineCount, default=3};
	__property TcxGridPreviewPlace Place = {read=FPlace, write=SetPlace, default=0};
	__property int RightIndent = {read=FRightIndent, write=SetRightIndent, default=5};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridPreview(void) { }
	
};


typedef void __fastcall (__closure *TcxGridGetGroupStyleEvent)(TcxGridTableView* Sender, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int ALevel, Cxstyles::TcxStyle* &AStyle);

class DELPHICLASS TcxGridTableViewStyles;
class PASCALIMPLEMENTATION TcxGridTableViewStyles : public Cxgridcustomtableview::TcxCustomGridTableViewStyles
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewStyles inherited;
	
private:
	bool FProcessingGroupSortedSummary;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetFooterStyle;
	TcxGridGetFooterStyleExEvent FOnGetFooterStyleEx;
	TcxGridGetFooterSummaryStyleEvent FOnGetFooterSummaryStyle;
	TcxGridGetGroupStyleEvent FOnGetGroupStyle;
	TcxGridGetGroupSummaryStyleEvent FOnGetGroupSummaryStyle;
	TcxGridGetHeaderStyleEvent FOnGetHeaderStyle;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetPreviewStyle;
	HIDESBASE TcxGridTableView* __fastcall GetGridViewValue(void);
	void __fastcall SetOnGetFooterStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetFooterStyleEx(TcxGridGetFooterStyleExEvent Value);
	void __fastcall SetOnGetFooterSummaryStyle(TcxGridGetFooterSummaryStyleEvent Value);
	void __fastcall SetOnGetGroupStyle(TcxGridGetGroupStyleEvent Value);
	void __fastcall SetOnGetGroupSummaryStyle(TcxGridGetGroupSummaryStyleEvent Value);
	void __fastcall SetOnGetHeaderStyle(TcxGridGetHeaderStyleEvent Value);
	void __fastcall SetOnGetPreviewStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetCellContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, System::TObject* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetFooterCellParams(TcxCustomGridRow* ARow, TcxGridColumn* AColumn, int AFooterGroupLevel, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetFooterParams(TcxCustomGridRow* ARow, TcxGridColumn* AColumn, int AFooterGroupLevel, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetGroupParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, int ALevel, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetGroupSummaryCellContentParams(TcxGridGroupRow* ARow, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetGroupSummaryCellParams(TcxGridGroupRow* ARow, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetGroupSummaryParams(TcxGridGroupRow* ARow, Cxcustomdata::TcxDataSummaryItem* ASummaryItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetHeaderParams(TcxGridColumn* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetPreviewParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetRecordContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridTableView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* FilterRowInfoText = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=11};
	__property Cxstyles::TcxStyle* Group = {read=GetValue, write=SetValue, index=12};
	__property Cxstyles::TcxStyle* GroupByBox = {read=GetValue, write=SetValue, index=13};
	__property Cxstyles::TcxStyle* GroupFooterSortedSummary = {read=GetValue, write=SetValue, index=14};
	__property Cxstyles::TcxStyle* GroupSortedSummary = {read=GetValue, write=SetValue, index=15};
	__property Cxstyles::TcxStyle* GroupSummary = {read=GetValue, write=SetValue, index=16};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=17};
	__property Cxstyles::TcxStyle* Indicator = {read=GetValue, write=SetValue, index=19};
	__property Cxstyles::TcxStyle* NewItemRowInfoText = {read=GetValue, write=SetValue, index=18};
	__property Cxstyles::TcxStyle* Preview = {read=GetValue, write=SetValue, index=20};
	__property StyleSheet;
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetFooterStyle = {read=FOnGetFooterStyle, write=SetOnGetFooterStyle};
	__property TcxGridGetFooterStyleExEvent OnGetFooterStyleEx = {read=FOnGetFooterStyleEx, write=SetOnGetFooterStyleEx};
	__property TcxGridGetFooterSummaryStyleEvent OnGetFooterSummaryStyle = {read=FOnGetFooterSummaryStyle, write=SetOnGetFooterSummaryStyle};
	__property TcxGridGetGroupStyleEvent OnGetGroupStyle = {read=FOnGetGroupStyle, write=SetOnGetGroupStyle};
	__property TcxGridGetGroupSummaryStyleEvent OnGetGroupSummaryStyle = {read=FOnGetGroupSummaryStyle, write=SetOnGetGroupSummaryStyle};
	__property TcxGridGetHeaderStyleEvent OnGetHeaderStyle = {read=FOnGetHeaderStyle, write=SetOnGetHeaderStyle};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetPreviewStyle = {read=FOnGetPreviewStyle, write=SetOnGetPreviewStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxGridTableViewStyles(System::Classes::TPersistent* AOwner) : Cxgridcustomtableview::TcxCustomGridTableViewStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridTableViewStyles(void) { }
	
};


class DELPHICLASS TcxGridTableViewStyleSheet;
class PASCALIMPLEMENTATION TcxGridTableViewStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxGridTableViewStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxGridTableViewStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxGridTableViewStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxGridTableViewStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxGridTableViewStyleSheet(void) { }
	
};


class DELPHICLASS TcxGridTableSummaryGroupItemLink;
class PASCALIMPLEMENTATION TcxGridTableSummaryGroupItemLink : public Cxcustomdata::TcxDataSummaryGroupItemLink
{
	typedef Cxcustomdata::TcxDataSummaryGroupItemLink inherited;
	
private:
	TcxGridColumn* __fastcall GetColumn(void);
	void __fastcall SetColumn(TcxGridColumn* Value);
	TcxGridTableView* __fastcall GetGridView(void);
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property TcxGridTableView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridColumn* Column = {read=GetColumn, write=SetColumn};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxGridTableSummaryGroupItemLink(System::Classes::TCollection* Collection) : Cxcustomdata::TcxDataSummaryGroupItemLink(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxGridTableSummaryGroupItemLink(void) { }
	
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


__interface IcxGridSummaryItem;
typedef System::DelphiInterface<IcxGridSummaryItem> _di_IcxGridSummaryItem;
__interface  INTERFACE_UUID("{6F9A0C3E-E33F-4E77-9357-82F1D19CDB67}") IcxGridSummaryItem  : public System::IInterface 
{
	
public:
	virtual System::UnicodeString __fastcall GetDisplayText(void) = 0 ;
	virtual bool __fastcall GetVisibleForCustomization(void) = 0 ;
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property bool VisibleForCustomization = {read=GetVisibleForCustomization};
};

class DELPHICLASS TcxGridTableSummaryItem;
class PASCALIMPLEMENTATION TcxGridTableSummaryItem : public Cxcustomdata::TcxDataSummaryItem
{
	typedef Cxcustomdata::TcxDataSummaryItem inherited;
	
private:
	System::UnicodeString FDisplayText;
	bool FVisibleForCustomization;
	TcxGridColumn* __fastcall GetColumn(void);
	TcxGridTableView* __fastcall GetGridView(void);
	void __fastcall SetColumn(TcxGridColumn* Value);
	void __fastcall SetDisplayText(const System::UnicodeString Value);
	void __fastcall SetVisibleForCustomization(bool Value);
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	System::UnicodeString __fastcall GetDisplayText(void);
	bool __fastcall GetVisibleForCustomization(void);
	__property TcxGridTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridTableSummaryItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxGridColumn* Column = {read=GetColumn, write=SetColumn};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property Sorted = {default=0};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=SetVisibleForCustomization, default=1};
public:
	/* TcxDataSummaryItem.Destroy */ inline __fastcall virtual ~TcxGridTableSummaryItem(void) { }
	
private:
	void *__IcxGridSummaryItem;	/* IcxGridSummaryItem */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6F9A0C3E-E33F-4E77-9357-82F1D19CDB67}
	operator _di_IcxGridSummaryItem()
	{
		_di_IcxGridSummaryItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridSummaryItem*(void) { return (IcxGridSummaryItem*)&__IcxGridSummaryItem; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


typedef void __fastcall (__closure *TcxGridColumnEvent)(TcxGridTableView* Sender, TcxGridColumn* AColumn);

typedef void __fastcall (__closure *TcxGridIndicatorCellCustomDrawEvent)(TcxGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridIndicatorItemViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridGroupRowChangingEvent)(TcxGridTableView* Sender, TcxGridGroupRow* AGroup, bool &AAllow);

typedef void __fastcall (__closure *TcxGridGroupRowEvent)(TcxGridTableView* Sender, TcxGridGroupRow* AGroup);

class PASCALIMPLEMENTATION TcxGridTableView : public Cxgridcustomtableview::TcxCustomGridTableView
{
	typedef Cxgridcustomtableview::TcxCustomGridTableView inherited;
	
private:
	bool FAllowCellMerging;
	TcxGridFilterRowOptions* FFilterRow;
	TcxGridNewItemRowOptions* FNewItemRow;
	TcxGridPreview* FPreview;
	TcxGridColumnEvent FOnColumnHeaderClick;
	TcxGridColumnEvent FOnColumnPosChanged;
	TcxGridColumnEvent FOnColumnSizeChanged;
	TcxGridColumnCustomDrawHeaderEvent FOnCustomDrawColumnHeader;
	TcxGridColumnCustomDrawHeaderEvent FOnCustomDrawFooterCell;
	Cxgridcustomtableview::TcxGridTableCellCustomDrawEvent FOnCustomDrawGroupCell;
	TcxGridGroupSummaryCellCustomDrawEvent FOnCustomDrawGroupSummaryCell;
	TcxGridIndicatorCellCustomDrawEvent FOnCustomDrawIndicatorCell;
	TcxGridGroupRowEvent FOnGroupRowCollapsed;
	TcxGridGroupRowChangingEvent FOnGroupRowCollapsing;
	TcxGridGroupRowEvent FOnGroupRowExpanded;
	TcxGridGroupRowChangingEvent FOnGroupRowExpanding;
	System::Classes::TNotifyEvent FOnLeftPosChanged;
	HIDESBASE TcxGridTableBackgroundBitmaps* __fastcall GetBackgroundBitmaps(void);
	TcxGridColumn* __fastcall GetColumn(int Index);
	int __fastcall GetColumnCount(void);
	HIDESBASE TcxGridTableController* __fastcall GetController(void);
	Cxgridcustomtableview::TcxGridDataController* __fastcall GetDataController(void);
	TcxGridTableDateTimeHandling* __fastcall GetDateTimeHandling(void);
	TcxGridTableFiltering* __fastcall GetFiltering(void);
	TcxGridColumn* __fastcall GetGroupedColumn(int Index);
	int __fastcall GetGroupedColumnCount(void);
	HIDESBASE TcxGridTableOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TcxGridTableOptionsCustomize* __fastcall GetOptionsCustomize(void);
	HIDESBASE TcxGridTableOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE TcxGridTableOptionsSelection* __fastcall GetOptionsSelection(void);
	HIDESBASE TcxGridTableOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE TcxGridTablePainter* __fastcall GetPainter(void);
	HIDESBASE TcxGridTableViewStyles* __fastcall GetStyles(void);
	HIDESBASE TcxGridViewData* __fastcall GetViewData(void);
	HIDESBASE TcxGridTableViewInfo* __fastcall GetViewInfo(void);
	TcxGridColumn* __fastcall GetVisibleColumn(int Index);
	int __fastcall GetVisibleColumnCount(void);
	HIDESBASE void __fastcall SetBackgroundBitmaps(TcxGridTableBackgroundBitmaps* Value);
	void __fastcall SetColumn(int Index, TcxGridColumn* Value);
	void __fastcall SetDataController(Cxgridcustomtableview::TcxGridDataController* Value);
	HIDESBASE void __fastcall SetDateTimeHandling(TcxGridTableDateTimeHandling* Value);
	HIDESBASE void __fastcall SetFiltering(TcxGridTableFiltering* Value);
	void __fastcall SetFilterRow(TcxGridFilterRowOptions* Value);
	void __fastcall SetNewItemRow(TcxGridNewItemRowOptions* Value);
	void __fastcall SetOnColumnHeaderClick(TcxGridColumnEvent Value);
	void __fastcall SetOnColumnPosChanged(TcxGridColumnEvent Value);
	void __fastcall SetOnColumnSizeChanged(TcxGridColumnEvent Value);
	void __fastcall SetOnCustomDrawColumnHeader(TcxGridColumnCustomDrawHeaderEvent Value);
	void __fastcall SetOnCustomDrawFooterCell(TcxGridColumnCustomDrawHeaderEvent Value);
	void __fastcall SetOnCustomDrawGroupCell(Cxgridcustomtableview::TcxGridTableCellCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawGroupSummaryCell(TcxGridGroupSummaryCellCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawIndicatorCell(TcxGridIndicatorCellCustomDrawEvent Value);
	void __fastcall SetOnLeftPosChanged(System::Classes::TNotifyEvent Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxGridTableOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsCustomize(TcxGridTableOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsData(TcxGridTableOptionsData* Value);
	HIDESBASE void __fastcall SetOptionsSelection(TcxGridTableOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxGridTableOptionsView* Value);
	void __fastcall SetPreview(TcxGridPreview* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridTableViewStyles* Value);
	
protected:
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall AssignLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual void __fastcall BeforeEditLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual System::UnicodeString __fastcall GetLayoutCustomizationFormButtonCaption(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual void __fastcall AfterAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual bool __fastcall CanCellMerging(void);
	virtual bool __fastcall CanOffset(int ARecordCountDelta);
	virtual bool __fastcall CanOffsetHorz(void);
	virtual void __fastcall DetailDataChanged(Cxgridcustomview::TcxCustomGridView* ADetail);
	virtual void __fastcall DoAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual void __fastcall GetItemsListForClipboard(System::Classes::TList* AItems, bool ACopyAll);
	virtual bool __fastcall GetResizeOnBoundsChange(void);
	bool __fastcall HasCellMerging(void);
	virtual bool __fastcall IsEqualHeightRecords(void);
	bool __fastcall IsPreviewHeightFixed(void);
	virtual bool __fastcall IsRecordHeightDependsOnData(void);
	virtual bool __fastcall UpdateOnDetailDataChange(Cxgridcustomview::TcxCustomGridView* ADetail);
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridBackgroundBitmapsClass __fastcall GetBackgroundBitmapsClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableDateTimeHandlingClass __fastcall GetDateTimeHandlingClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableFilteringClass __fastcall GetFilteringClass(void);
	virtual TcxGridFilterRowOptionsClass __fastcall GetFilterRowOptionsClass(void);
	virtual TcxGridNewItemRowOptionsClass __fastcall GetNewItemRowOptionsClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual TcxGridPreviewClass __fastcall GetPreviewClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual Cxcustomdata::TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual void __fastcall ItemVisibilityChanged(Cxgridcustomtableview::TcxCustomGridTableItem* AItem, bool Value);
	virtual bool __fastcall CalculateDataCellSelected(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, bool AUseViewInfo, Cxgridcustomtableview::TcxGridTableCellViewInfo* ACellViewInfo);
	virtual void __fastcall DoColumnHeaderClick(TcxGridColumn* AColumn);
	virtual void __fastcall DoColumnPosChanged(TcxGridColumn* AColumn);
	virtual void __fastcall DoColumnSizeChanged(TcxGridColumn* AColumn);
	virtual void __fastcall DoCustomDrawColumnHeader(Cxgraphics::TcxCanvas* ACanvas, TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, TcxGridColumnHeaderViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupCell(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxGridTableCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupSummaryCell(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridViewCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawIndicatorCell(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridIndicatorItemViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoLeftPosChanged(void);
	bool __fastcall HasCustomDrawColumnHeader(void);
	bool __fastcall HasCustomDrawFooterCell(void);
	bool __fastcall HasCustomDrawGroupCell(void);
	bool __fastcall HasCustomDrawGroupSummaryCell(void);
	bool __fastcall HasCustomDrawIndicatorCell(void);
	virtual void __fastcall DoGroupRowCollapsed(TcxGridGroupRow* AGroup);
	virtual bool __fastcall DoGroupRowCollapsing(TcxGridGroupRow* AGroup);
	virtual void __fastcall DoGroupRowExpanded(TcxGridGroupRow* AGroup);
	virtual bool __fastcall DoGroupRowExpanding(TcxGridGroupRow* AGroup);
	__property bool AllowCellMerging = {read=FAllowCellMerging, write=FAllowCellMerging, nodefault};
	
public:
	__fastcall virtual TcxGridTableView(System::Classes::TComponent* AOwner);
	TcxGridColumn* __fastcall CreateColumn(void);
	bool __fastcall UseRestHeightForDetails(void);
	__classmethod virtual bool __fastcall CanBeLookupList();
	virtual bool __fastcall CanPopupAutoHeight(void);
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TcxGridColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	__property TcxGridTableController* Controller = {read=GetController};
	__property int GroupedColumnCount = {read=GetGroupedColumnCount, nodefault};
	__property TcxGridColumn* GroupedColumns[int Index] = {read=GetGroupedColumn};
	__property TcxGridTablePainter* Painter = {read=GetPainter};
	__property TcxGridViewData* ViewData = {read=GetViewData};
	__property TcxGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisibleColumnCount = {read=GetVisibleColumnCount, nodefault};
	__property TcxGridColumn* VisibleColumns[int Index] = {read=GetVisibleColumn};
	
__published:
	__property TcxGridTableBackgroundBitmaps* BackgroundBitmaps = {read=GetBackgroundBitmaps, write=SetBackgroundBitmaps};
	__property Cxgridcustomtableview::TcxGridDataController* DataController = {read=GetDataController, write=SetDataController};
	__property TcxGridTableDateTimeHandling* DateTimeHandling = {read=GetDateTimeHandling, write=SetDateTimeHandling};
	__property TcxGridTableFiltering* Filtering = {read=GetFiltering, write=SetFiltering};
	__property TcxGridFilterRowOptions* FilterRow = {read=FFilterRow, write=SetFilterRow};
	__property Images;
	__property TcxGridNewItemRowOptions* NewItemRow = {read=FNewItemRow, write=SetNewItemRow};
	__property TcxGridTableOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxGridTableOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize, write=SetOptionsCustomize};
	__property TcxGridTableOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property TcxGridTableOptionsSelection* OptionsSelection = {read=GetOptionsSelection, write=SetOptionsSelection};
	__property TcxGridTableOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxGridPreview* Preview = {read=FPreview, write=SetPreview};
	__property TcxGridTableViewStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxGridColumnEvent OnColumnHeaderClick = {read=FOnColumnHeaderClick, write=SetOnColumnHeaderClick};
	__property TcxGridColumnEvent OnColumnPosChanged = {read=FOnColumnPosChanged, write=SetOnColumnPosChanged};
	__property TcxGridColumnEvent OnColumnSizeChanged = {read=FOnColumnSizeChanged, write=SetOnColumnSizeChanged};
	__property TcxGridColumnCustomDrawHeaderEvent OnCustomDrawColumnHeader = {read=FOnCustomDrawColumnHeader, write=SetOnCustomDrawColumnHeader};
	__property TcxGridColumnCustomDrawHeaderEvent OnCustomDrawFooterCell = {read=FOnCustomDrawFooterCell, write=SetOnCustomDrawFooterCell};
	__property Cxgridcustomtableview::TcxGridTableCellCustomDrawEvent OnCustomDrawGroupCell = {read=FOnCustomDrawGroupCell, write=SetOnCustomDrawGroupCell};
	__property TcxGridGroupSummaryCellCustomDrawEvent OnCustomDrawGroupSummaryCell = {read=FOnCustomDrawGroupSummaryCell, write=SetOnCustomDrawGroupSummaryCell};
	__property TcxGridIndicatorCellCustomDrawEvent OnCustomDrawIndicatorCell = {read=FOnCustomDrawIndicatorCell, write=SetOnCustomDrawIndicatorCell};
	__property OnCustomization;
	__property TcxGridGroupRowEvent OnGroupRowCollapsed = {read=FOnGroupRowCollapsed, write=FOnGroupRowCollapsed};
	__property TcxGridGroupRowChangingEvent OnGroupRowCollapsing = {read=FOnGroupRowCollapsing, write=FOnGroupRowCollapsing};
	__property TcxGridGroupRowEvent OnGroupRowExpanded = {read=FOnGroupRowExpanded, write=FOnGroupRowExpanded};
	__property TcxGridGroupRowChangingEvent OnGroupRowExpanding = {read=FOnGroupRowExpanding, write=FOnGroupRowExpanding};
	__property OnInitGroupingDateRanges;
	__property System::Classes::TNotifyEvent OnLeftPosChanged = {read=FOnLeftPosChanged, write=SetOnLeftPosChanged};
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridTableView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridTableView(Cxcontrols::TcxControl* AControl) : Cxgridcustomtableview::TcxCustomGridTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcustomtableview::TcxCustomGridTableView(AControl, AAssignOwner) { }
	
};


class DELPHICLASS TcxGridColumnAccess;
class PASCALIMPLEMENTATION TcxGridColumnAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall CanCellMerging(TcxGridColumn* AInstance);
	__classmethod bool __fastcall CanShowGroupFooters(TcxGridColumn* AInstance);
	__classmethod virtual void __fastcall DoCustomDrawGroupSummaryCell(TcxGridColumn* AInstance, Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridViewCellViewInfo* AViewInfo, bool &ADone);
	__classmethod bool __fastcall HasCustomDrawGroupSummaryCell(TcxGridColumn* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxGridColumnAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridColumnAccess(void) { }
	
};


class DELPHICLASS TcxGridTableViewAccess;
class PASCALIMPLEMENTATION TcxGridTableViewAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall DoColumnPosChanged(TcxGridTableView* AInstance, TcxGridColumn* AColumn);
	__classmethod void __fastcall DoCustomDrawGroupCell(TcxGridTableView* AInstance, Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxGridTableCellViewInfo* AViewInfo, bool &ADone);
	__classmethod virtual void __fastcall DoCustomDrawGroupSummaryCell(TcxGridTableView* AInstance, Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridViewCellViewInfo* AViewInfo, bool &ADone);
	__classmethod bool __fastcall HasCustomDrawGroupCell(TcxGridTableView* AInstance);
	__classmethod bool __fastcall HasCustomDrawGroupSummaryCell(TcxGridTableView* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxGridTableViewAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridTableViewAccess(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Byte htGridBase = System::Byte(0xc8);
static const System::Byte htGroupByBox = System::Byte(0xc9);
static const System::Byte htColumnHeader = System::Byte(0xca);
static const System::Byte htColumnHeaderHorzSizingEdge = System::Byte(0xcb);
static const System::Byte htColumnHeaderFilterButton = System::Byte(0xcc);
static const System::Byte htFooter = System::Byte(0xcd);
static const System::Byte htFooterCell = System::Byte(0xce);
static const System::Byte htGroupFooter = System::Byte(0xcf);
static const System::Byte htGroupFooterCell = System::Byte(0xd0);
static const System::Byte htRowIndicator = System::Byte(0xd1);
static const System::Byte htRowSizingEdge = System::Byte(0xd2);
static const System::Byte htIndicator = System::Byte(0xd3);
static const System::Byte htIndicatorHeader = System::Byte(0xd4);
static const System::Byte htRowLevelIndent = System::Byte(0xd5);
static const System::Byte htHeader = System::Byte(0xd6);
static const System::Byte htGroupSummary = System::Byte(0xd7);
static const System::Int8 ckHeader = System::Int8(0x2);
static const System::Int8 ckGroupByBox = System::Int8(0x3);
static const System::Int8 ckFooter = System::Int8(0x4);
static const System::Int8 cxGridDefaultIndicatorWidth = System::Int8(0xc);
static const System::Int8 cxGridCustomRowSeparatorDefaultWidth = System::Int8(0x6);
static const System::Int8 cxGridCustomRowSeparatorMinWidth = System::Int8(0x2);
static const System::Int8 cxGridPreviewDefaultLeftIndent = System::Int8(0x14);
static const System::Int8 cxGridPreviewDefaultMaxLineCount = System::Int8(0x3);
static const System::Int8 cxGridPreviewDefaultRightIndent = System::Int8(0x5);
static const System::Int8 cxGridHeaderSizingEdgeSize = System::Int8(0x8);
static const System::Int8 cxGridRowSizingEdgeSize = System::Int8(0x8);
extern PACKAGE int cxGridOffice11GroupRowSeparatorWidth;
static const System::Int8 rkFiltering = System::Int8(0x2);
static const System::Int8 isColumnFirst = System::Int8(0x1);
static const System::Int8 isFooter = System::Int8(0x1);
static const System::Int8 isGroupSummary = System::Int8(0x2);
static const System::Int8 isHeader = System::Int8(0x3);
static const System::Int8 isColumnLast = System::Int8(0x3);
static const System::Int8 bbTableFirst = System::Int8(0x3);
static const System::Int8 bbFooter = System::Int8(0x3);
static const System::Int8 bbHeader = System::Int8(0x4);
static const System::Int8 bbGroup = System::Int8(0x5);
static const System::Int8 bbGroupByBox = System::Int8(0x6);
static const System::Int8 bbIndicator = System::Int8(0x7);
static const System::Int8 bbPreview = System::Int8(0x8);
static const System::Int8 bbTableLast = System::Int8(0x8);
static const System::Int8 vsTableFirst = System::Int8(0xa);
static const System::Int8 vsFilterRowInfoText = System::Int8(0xa);
static const System::Int8 vsFooter = System::Int8(0xb);
static const System::Int8 vsGroup = System::Int8(0xc);
static const System::Int8 vsGroupByBox = System::Int8(0xd);
static const System::Int8 vsGroupFooterSortedSummary = System::Int8(0xe);
static const System::Int8 vsGroupSortedSummary = System::Int8(0xf);
static const System::Int8 vsGroupSummary = System::Int8(0x10);
static const System::Int8 vsHeader = System::Int8(0x11);
static const System::Int8 vsNewItemRowInfoText = System::Int8(0x12);
static const System::Int8 vsIndicator = System::Int8(0x13);
static const System::Int8 vsPreview = System::Int8(0x14);
static const System::Int8 vsTableLast = System::Int8(0x14);
static const System::Word cxGridFilterRowDelayDefault = System::Word(0x3e8);
}	/* namespace Cxgridtableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDTABLEVIEW)
using namespace Cxgridtableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridtableviewHPP
