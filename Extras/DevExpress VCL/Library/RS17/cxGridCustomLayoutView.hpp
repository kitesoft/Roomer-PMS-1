// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridCustomLayoutView.pas' rev: 24.00 (Win32)

#ifndef CxgridcustomlayoutviewHPP
#define CxgridcustomlayoutviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridcustomlayoutview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridCustomLayoutViewControllerClass;

typedef System::TMetaClass* TcxGridCustomLayoutRecordViewInfoClass;

typedef System::TMetaClass* TcxGridCustomLayoutViewSeparatorsViewInfoClass;

class DELPHICLASS TcxGridCustomLayoutViewBand;
class DELPHICLASS TcxGridCustomLayoutRecordViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewBand : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridCustomLayoutRecordViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	int FIndex;
	System::Classes::TList* FItems;
	TcxGridCustomLayoutRecordViewInfo* __fastcall GetLastVisible(void);
	TcxGridCustomLayoutRecordViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetCount(void);
	TcxGridCustomLayoutRecordViewInfo* __fastcall GetFirstVisible(void);
	int __fastcall GetVisibleCount(void);
	void __fastcall SetItem(int Index, TcxGridCustomLayoutRecordViewInfo* Value);
	
public:
	__fastcall TcxGridCustomLayoutViewBand(int AIndex);
	__fastcall virtual ~TcxGridCustomLayoutViewBand(void);
	TcxGridCustomLayoutRecordViewInfo* __fastcall GetNearest(int APos);
	bool __fastcall IsItemVisible(int Index);
	__property int Index = {read=FIndex, nodefault};
	__property TcxGridCustomLayoutRecordViewInfo* LastVisible = {read=GetLastVisible};
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridCustomLayoutRecordViewInfo* FirstVisible = {read=GetFirstVisible};
	__property TcxGridCustomLayoutRecordViewInfo* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCustomLayoutViewBandClass;

class DELPHICLASS TcxGridCustomLayoutViewBands;
class DELPHICLASS TcxGridCustomLayoutRecordsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewBands : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxGridCustomLayoutViewBand* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridCustomLayoutRecordsViewInfo* FRecordsViewInfo;
	System::Contnrs::TObjectList* FItems;
	int __fastcall GetCount(void);
	TcxGridCustomLayoutViewBand* __fastcall GetItem(int Index);
	TcxGridCustomLayoutViewBand* __fastcall GetLastVisible(void);
	int __fastcall GetVisibleCount(void);
	
protected:
	virtual TcxGridCustomLayoutViewBandClass __fastcall GetBandClass(void);
	__property TcxGridCustomLayoutRecordsViewInfo* RecordsViewInfo = {read=FRecordsViewInfo};
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	
public:
	__fastcall TcxGridCustomLayoutViewBands(TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo);
	__fastcall virtual ~TcxGridCustomLayoutViewBands(void);
	void __fastcall Clear(void);
	bool __fastcall IsItemVisible(int AColumn, int ARow);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridCustomLayoutViewBand* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxGridCustomLayoutViewBand* LastVisible = {read=GetLastVisible};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCustomLayoutViewBandsClass;

class DELPHICLASS TcxGridCustomLayoutViewViewData;
class DELPHICLASS TcxGridCustomLayoutRecord;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewViewData : public Cxgridcustomtableview::TcxCustomGridTableViewData
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewData inherited;
	
private:
	HIDESBASE TcxGridCustomLayoutRecord* __fastcall GetRecord(int Index);
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
	
public:
	__property TcxGridCustomLayoutRecord* Records[int Index] = {read=GetRecord};
public:
	/* TcxCustomGridTableViewData.Create */ inline __fastcall virtual TcxGridCustomLayoutViewViewData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableViewData(AGridView) { }
	/* TcxCustomGridTableViewData.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewViewData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewControllerHelper;
class DELPHICLASS TcxGridCustomLayoutViewController;
class DELPHICLASS TcxGridCustomLayoutViewViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewControllerHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxGridCustomLayoutViewController* FController;
	Cxcontrols::TcxControl* __fastcall GetControl(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetScrollBarOffsetBegin(void);
	int __fastcall GetScrollBarOffsetEnd(void);
	TcxGridCustomLayoutViewViewData* __fastcall GetViewData(void);
	TcxGridCustomLayoutViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanScrollBarVisible(Vcl::Forms::TScrollBarKind AKind);
	virtual int __fastcall GetPageRecordCount(int AVisibleRecordCount);
	virtual void __fastcall DoInitScrollBarParameters(Vcl::Forms::TScrollBarKind AKind, bool ACanHide);
	void __fastcall InitScrollBarParameters(Vcl::Forms::TScrollBarKind AKind, bool ACanHide);
	virtual bool __fastcall IsDataScrollBar(Vcl::Forms::TScrollBarKind AKind);
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
	__property TcxGridCustomLayoutViewController* Controller = {read=FController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property int ScrollBarOffsetBegin = {read=GetScrollBarOffsetBegin, nodefault};
	__property int ScrollBarOffsetEnd = {read=GetScrollBarOffsetEnd, nodefault};
	__property TcxGridCustomLayoutViewViewData* ViewData = {read=GetViewData};
	__property TcxGridCustomLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxGridCustomLayoutViewControllerHelper(TcxGridCustomLayoutViewController* AController);
	virtual bool __fastcall GetIsRecordsScrollHorizontal(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void) = 0 ;
	virtual int __fastcall GetScrollDelta(void) = 0 ;
	void __fastcall InitScrollBarsParameters(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewControllerHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCustomLayoutViewControllerHelperClass;

class DELPHICLASS TcxGridCustomLayoutViewControllerHorizontalHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewControllerHorizontalHelper : public TcxGridCustomLayoutViewControllerHelper
{
	typedef TcxGridCustomLayoutViewControllerHelper inherited;
	
private:
	void __fastcall FocusRecordInNextColumn(Cxclasses::TcxDirection ADirection, bool AIsSelecting);
	
protected:
	virtual bool __fastcall IsDataScrollBar(Vcl::Forms::TScrollBarKind AKind);
	
public:
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual int __fastcall GetScrollDelta(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TcxGridCustomLayoutViewControllerHelper.Create */ inline __fastcall virtual TcxGridCustomLayoutViewControllerHorizontalHelper(TcxGridCustomLayoutViewController* AController) : TcxGridCustomLayoutViewControllerHelper(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewControllerHorizontalHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewControllerVerticalHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewControllerVerticalHelper : public TcxGridCustomLayoutViewControllerHelper
{
	typedef TcxGridCustomLayoutViewControllerHelper inherited;
	
private:
	void __fastcall FocusRecordInNextRow(Cxclasses::TcxDirection ADirection, bool AIsSelecting);
	
protected:
	virtual bool __fastcall IsDataScrollBar(Vcl::Forms::TScrollBarKind AKind);
	
public:
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual int __fastcall GetScrollDelta(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TcxGridCustomLayoutViewControllerHelper.Create */ inline __fastcall virtual TcxGridCustomLayoutViewControllerVerticalHelper(TcxGridCustomLayoutViewController* AController) : TcxGridCustomLayoutViewControllerHelper(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewControllerVerticalHelper(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridCustomLayoutViewController : public Cxgridcustomtableview::TcxCustomGridTableController
{
	typedef Cxgridcustomtableview::TcxCustomGridTableController inherited;
	
private:
	TcxGridCustomLayoutViewControllerHelper* FHelper;
	TcxGridCustomLayoutRecordViewInfo* FScrollRecordViewInfo;
	TcxGridCustomLayoutRecordViewInfo* __fastcall GetFocusedRecordViewInfo(void);
	HIDESBASE TcxGridCustomLayoutViewViewData* __fastcall GetViewData(void);
	HIDESBASE TcxGridCustomLayoutViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetScrollRecordViewInfo(TcxGridCustomLayoutRecordViewInfo* Value);
	
protected:
	virtual void __fastcall DoScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual int __fastcall GetDragScrollInterval(void);
	virtual bool __fastcall GetIsRecordsScrollHorizontal(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual int __fastcall GetScrollDelta(void);
	virtual int __fastcall GetPageRecordCount(void);
	virtual void __fastcall ScrollData(Cxclasses::TcxDirection ADirection);
	virtual void __fastcall CreateHelper(void);
	virtual void __fastcall DestroyHelper(void);
	virtual TcxGridCustomLayoutViewControllerHelperClass __fastcall GetHelperClass(void);
	virtual void __fastcall InternalKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall ProcessFocusedItemKeys(System::Word &AKey, System::Classes::TShiftState AShift, bool ARowGoOnCycle);
	__property TcxGridCustomLayoutRecordViewInfo* FocusedRecordViewInfo = {read=GetFocusedRecordViewInfo};
	__property TcxGridCustomLayoutViewControllerHelper* Helper = {read=FHelper};
	__property TcxGridCustomLayoutRecordViewInfo* ScrollRecordViewInfo = {read=FScrollRecordViewInfo, write=SetScrollRecordViewInfo};
	__property TcxGridCustomLayoutViewViewData* ViewData = {read=GetViewData};
	__property TcxGridCustomLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxGridCustomLayoutViewController(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridCustomLayoutViewController(void);
	virtual bool __fastcall IsDataFullyVisible(bool AIsCallFromMaster = false);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MakeItemVisible(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall FocusNextItemHorizontally(bool AGoForward, bool AGoOnCycle);
	virtual bool __fastcall FocusNextItemVertically(bool AGoForward, bool AGoOnCycle);
	virtual bool __fastcall CanScrollFocusedRecord(bool ADown);
	virtual bool __fastcall ScrollFocusedRecord(bool ADown);
	void __fastcall LayoutDirectionChanged(void);
};


class DELPHICLASS TcxGridCustomLayoutViewPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewPainter : public Cxgridcustomtableview::TcxCustomGridTablePainter
{
	typedef Cxgridcustomtableview::TcxCustomGridTablePainter inherited;
	
private:
	HIDESBASE TcxGridCustomLayoutViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawSeparators(void);
	virtual void __fastcall PaintContent(void);
	
public:
	__property TcxGridCustomLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxGridCustomLayoutViewPainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTablePainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewInfoCacheItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewInfoCacheItem : public Cxgridcustomtableview::TcxCustomGridTableViewInfoCacheItem
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewInfoCacheItem inherited;
	
public:
	/* TcxCustomGridViewInfoCacheItem.Create */ inline __fastcall virtual TcxGridCustomLayoutViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex) : Cxgridcustomtableview::TcxCustomGridTableViewInfoCacheItem(AOwner, AIndex) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewInfoCacheItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewItemFilterButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewItemFilterButtonViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	bool FFirstCalculate;
	bool __fastcall GetActive(void);
	Cxgridcustomtableview::TcxGridFilterPopup* __fastcall GetDropDownWindowValue(void);
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetItem(void) = 0 ;
	virtual void __fastcall AfterCalculateBounds(System::Types::TRect &ABounds);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall GetVisibleForHitTest(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall EmulateMouseMoveAfterCalculate(void);
	bool __fastcall HasInitialHitTest(void);
	virtual bool __fastcall NeedsContainerHotTrack(void);
	virtual bool __fastcall OccupiesSpace(void);
	virtual bool __fastcall CloseDropDownWindowOnDestruction(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	virtual bool __fastcall IsDropDownWindowOwner(void);
	__property Cxgridcustomtableview::TcxGridFilterPopup* DropDownWindow = {read=GetDropDownWindowValue};
	__property bool FirstCalculate = {read=FFirstCalculate, nodefault};
	
public:
	__fastcall virtual TcxGridCustomLayoutViewItemFilterButtonViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo);
	bool __fastcall NeedCalculate(void);
	__property bool Active = {read=GetActive, nodefault};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewItemFilterButtonViewInfo(void) { }
	
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

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutRecordViewInfo : public Cxgridcustomtableview::TcxCustomGridRecordViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordViewInfo inherited;
	
private:
	int FCol;
	int FRow;
	System::Types::TPoint FCalculationPosition;
	TcxGridCustomLayoutRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual bool __fastcall GetVisible(void);
	virtual int __fastcall GetPixelScrollSize(void);
	__property System::Types::TPoint CalculationPosition = {read=FCalculationPosition, write=FCalculationPosition};
	
public:
	__classmethod virtual int __fastcall GetExpandButtonSize(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* ALookAndFeelPainter);
	bool __fastcall IsFullyVisible(void);
	__property TcxGridCustomLayoutRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property int Col = {read=FCol, nodefault};
	__property int Row = {read=FRow, nodefault};
public:
	/* TcxCustomGridRecordViewInfo.Create */ inline __fastcall virtual TcxGridCustomLayoutRecordViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord) : Cxgridcustomtableview::TcxCustomGridRecordViewInfo(ARecordsViewInfo, ARecord) { }
	/* TcxCustomGridRecordViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutRecordViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewSeparatorsViewInfo;
class DELPHICLASS TcxGridCustomLayoutView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewSeparatorsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridCustomLayoutViewViewInfo* FGridViewInfo;
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxGridCustomLayoutView* __fastcall GetGridView(void);
	System::Types::TRect __fastcall GetItem(int Index);
	TcxGridCustomLayoutRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	void __fastcall SetItem(int Index, const System::Types::TRect &Value);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	
protected:
	void __fastcall Add(const System::Types::TRect &R);
	virtual void __fastcall DoCalculate(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual int __fastcall GetWidth(void);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property TcxGridCustomLayoutView* GridView = {read=GetGridView};
	__property TcxGridCustomLayoutViewViewInfo* GridViewInfo = {read=FGridViewInfo};
	__property TcxGridCustomLayoutRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	
public:
	__fastcall virtual TcxGridCustomLayoutViewSeparatorsViewInfo(TcxGridCustomLayoutViewViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridCustomLayoutViewSeparatorsViewInfo(void);
	void __fastcall Calculate(void);
	void __fastcall Clear(void);
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property System::Types::TRect Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int Width = {read=GetWidth, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutRecordsViewInfoBasedCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutRecordsViewInfoBasedCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxGridCustomLayoutRecordsViewInfo* FRecordsViewInfo;
	TcxGridCustomLayoutRecordViewInfo* __fastcall GetRecord(int Index);
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual void __fastcall AfterCalculate(void);
	virtual void __fastcall BeforeCalculate(void);
	void __fastcall Calculate(const System::Types::TRect &AContentBounds);
	virtual void __fastcall DoCalculate(const System::Types::TRect &AContentBounds);
	int __fastcall GetRecordIndent(void);
	virtual int __fastcall GetRecordSpaceHorz(void);
	virtual int __fastcall GetRecordSpaceVert(void);
	int __fastcall GetSeparatorWidth(void);
	int __fastcall GetMaxCount(void);
	virtual int __fastcall GetMaxColumnCount(void);
	virtual int __fastcall GetMaxRowCount(void);
	__property TcxGridCustomLayoutRecordViewInfo* Records[int Index] = {read=GetRecord};
	
public:
	__fastcall virtual TcxGridCustomLayoutRecordsViewInfoBasedCalculator(TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo);
	__property int RecordSpaceHorz = {read=GetRecordSpaceHorz, nodefault};
	__property int RecordSpaceVert = {read=GetRecordSpaceVert, nodefault};
	__property TcxGridCustomLayoutRecordsViewInfo* RecordsViewInfo = {read=FRecordsViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutRecordsViewInfoBasedCalculator(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCustomLayoutRecordsViewInfoBasedCalculatorClass;

class DELPHICLASS TcxGridCustomLayoutViewInfoHorizontalCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewInfoHorizontalCalculator : public TcxGridCustomLayoutRecordsViewInfoBasedCalculator
{
	typedef TcxGridCustomLayoutRecordsViewInfoBasedCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual void __fastcall DoCalculate(const System::Types::TRect &AContentBounds);
	virtual int __fastcall GetRecordSpaceHorz(void);
	virtual int __fastcall GetRecordSpaceVert(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridCustomLayoutViewInfoHorizontalCalculator(TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridCustomLayoutRecordsViewInfoBasedCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewInfoHorizontalCalculator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewInfoVerticalCalculator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewInfoVerticalCalculator : public TcxGridCustomLayoutRecordsViewInfoBasedCalculator
{
	typedef TcxGridCustomLayoutRecordsViewInfoBasedCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual void __fastcall DoCalculate(const System::Types::TRect &AContentBounds);
	virtual int __fastcall GetRecordSpaceHorz(void);
	virtual int __fastcall GetRecordSpaceVert(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridCustomLayoutViewInfoVerticalCalculator(TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridCustomLayoutRecordsViewInfoBasedCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewInfoVerticalCalculator(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutRecordsViewInfo : public Cxgridcustomtableview::TcxCustomGridRecordsViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordsViewInfo inherited;
	
public:
	TcxGridCustomLayoutRecordViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridCustomLayoutViewBands* FBands;
	TcxGridCustomLayoutRecordsViewInfoBasedCalculator* FCalculator;
	int FMaxRecordHeight;
	int FRecordHeight;
	int FRecordSpaceHorz;
	int FRecordSpaceVert;
	int FRecordWidth;
	bool __fastcall IsVertical(void);
	HIDESBASE TcxGridCustomLayoutRecordViewInfo* __fastcall GetItem(int Index);
	HIDESBASE TcxGridCustomLayoutView* __fastcall GetGridView(void);
	TcxGridCustomLayoutViewViewInfo* __fastcall GetGridViewInfo(void);
	
protected:
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual int __fastcall GetPixelScrollContentSize(void);
	virtual int __fastcall GetItemLeftBound(int AIndex);
	virtual int __fastcall GetItemsOffset(int AItemCountDelta);
	virtual int __fastcall GetItemTopBound(int AIndex);
	virtual void __fastcall OffsetItem(int AIndex, int AOffset);
	virtual int __fastcall CalculateHeight(bool &AFullyVisible);
	virtual int __fastcall CalculateMaxRecordHeight(void);
	virtual int __fastcall CalculateRecordHeight(void);
	virtual int __fastcall CalculateRecordWidth(void);
	virtual int __fastcall CalculateWidth(int AMaxWidth);
	virtual TcxGridCustomLayoutRecordsViewInfoBasedCalculatorClass __fastcall GetCalculatorClass(void);
	virtual TcxGridCustomLayoutViewBandsClass __fastcall GetBandsClass(void);
	virtual TcxGridCustomLayoutRecordViewInfoClass __fastcall GetItemViewInfoClass(void);
	virtual int __fastcall GetMaxRecordWidth(int AColumn);
	virtual int __fastcall GetMaxRecordHeight(int ARow);
	virtual int __fastcall GetRecordIndent(void);
	virtual int __fastcall GetSeparatorWidth(void);
	__property TcxGridCustomLayoutRecordsViewInfoBasedCalculator* Calculator = {read=FCalculator};
	__property int RecordIndent = {read=GetRecordIndent, nodefault};
	__property int RecordSpaceHorz = {read=FRecordSpaceHorz, nodefault};
	__property int RecordSpaceVert = {read=FRecordSpaceVert, nodefault};
	
public:
	__fastcall virtual TcxGridCustomLayoutRecordsViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridCustomLayoutRecordsViewInfo(void);
	virtual bool __fastcall CanOffset(int AItemCountDelta);
	HIDESBASE virtual TcxGridCustomLayoutRecordViewInfo* __fastcall GetRealItem(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__property TcxGridCustomLayoutViewBands* Bands = {read=FBands};
	__property TcxGridCustomLayoutView* GridView = {read=GetGridView};
	__property TcxGridCustomLayoutViewViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridCustomLayoutRecordViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int MaxRecordHeight = {read=FMaxRecordHeight, nodefault};
	__property int RecordHeight = {read=FRecordHeight, nodefault};
	__property int RecordWidth = {read=FRecordWidth, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewViewInfo : public Cxgridcustomtableview::TcxCustomGridTableViewInfo
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewInfo inherited;
	
private:
	int FPrevRecordHeight;
	TcxGridCustomLayoutViewSeparatorsViewInfo* FSeparatorsViewInfo;
	HIDESBASE TcxGridCustomLayoutViewController* __fastcall GetController(void);
	HIDESBASE TcxGridCustomLayoutView* __fastcall GetGridView(void);
	TcxGridCustomLayoutRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual void __fastcall AfterCalculating(void);
	virtual void __fastcall BeforeCalculating(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateHeight(const System::Types::TPoint &AMaxSize, int &AHeight, bool &AFullyVisible);
	virtual void __fastcall CalculateWidth(const System::Types::TPoint &AMaxSize, int &AWidth);
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(bool AIsRecreating);
	virtual TcxGridCustomLayoutViewSeparatorsViewInfoClass __fastcall GetSeparatorsViewInfoClass(void);
	
public:
	__property TcxGridCustomLayoutViewController* Controller = {read=GetController};
	__property TcxGridCustomLayoutView* GridView = {read=GetGridView};
	__property TcxGridCustomLayoutRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property TcxGridCustomLayoutViewSeparatorsViewInfo* SeparatorsViewInfo = {read=FSeparatorsViewInfo};
public:
	/* TcxCustomGridTableViewInfo.Create */ inline __fastcall virtual TcxGridCustomLayoutViewViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableViewInfo(AGridView) { }
	/* TcxCustomGridTableViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutRecord : public Cxgridcustomtableview::TcxCustomGridRecord
{
	typedef Cxgridcustomtableview::TcxCustomGridRecord inherited;
	
private:
	bool FExpanded;
	HIDESBASE TcxGridCustomLayoutView* __fastcall GetGridView(void);
	HIDESBASE void __fastcall SetExpanded(bool Value);
	
protected:
	virtual void __fastcall DoCollapse(bool ARecurse);
	virtual void __fastcall DoExpand(bool ARecurse);
	virtual bool __fastcall GetExpandable(void);
	virtual bool __fastcall GetExpanded(void);
	virtual bool __fastcall GetHasCells(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordViewInfoClass __fastcall GetViewInfoClass(void);
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	
public:
	__fastcall virtual TcxGridCustomLayoutRecord(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo);
	__property TcxGridCustomLayoutView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutRecord(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewOptionsCustomize : public Cxgridcustomtableview::TcxCustomGridTableOptionsCustomize
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsCustomize inherited;
	
private:
	bool FExpandable;
	TcxGridCustomLayoutView* __fastcall GetGridView(void);
	void __fastcall SetExpandable(bool Value);
	
protected:
	__property bool Expandable = {read=FExpandable, write=SetExpandable, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridCustomLayoutView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridTableOptionsCustomize.Create */ inline __fastcall virtual TcxGridCustomLayoutViewOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableOptionsCustomize(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewOptionsCustomize(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomLayoutViewOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomLayoutViewOptionsView : public Cxgridcustomtableview::TcxCustomGridTableOptionsView
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsView inherited;
	
private:
	System::WideChar FCaptionSeparator;
	int FIndent;
	System::Uitypes::TColor FSeparatorColor;
	int FSeparatorWidth;
	void __fastcall SetCaptionSeparator(System::WideChar Value);
	void __fastcall SetIndent(int Value);
	void __fastcall SetSeparatorColor(System::Uitypes::TColor Value);
	void __fastcall SetSeparatorWidth(int Value);
	
protected:
	__property System::WideChar CaptionSeparator = {read=FCaptionSeparator, write=SetCaptionSeparator, default=58};
	__property int Indent = {read=FIndent, write=SetIndent, default=7};
	__property System::Uitypes::TColor SeparatorColor = {read=FSeparatorColor, write=SetSeparatorColor, default=536870912};
	__property int SeparatorWidth = {read=FSeparatorWidth, write=SetSeparatorWidth, default=2};
	
public:
	__fastcall virtual TcxGridCustomLayoutViewOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Uitypes::TColor __fastcall GetSeparatorColor(void);
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutViewOptionsView(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridCustomLayoutView : public Cxgridcustomtableview::TcxCustomGridTableView
{
	typedef Cxgridcustomtableview::TcxCustomGridTableView inherited;
	
private:
	TcxGridCustomLayoutViewOptionsCustomize* __fastcall GetOptionsCustomize(void);
	HIDESBASE TcxGridCustomLayoutViewOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE TcxGridCustomLayoutViewViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE void __fastcall SetOptionsCustomize(TcxGridCustomLayoutViewOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxGridCustomLayoutViewOptionsView* Value);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall IsRecordPixelScrolling(void);
	void __fastcall Reposition(void);
	
public:
	__property TcxGridCustomLayoutViewOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize, write=SetOptionsCustomize};
	__property TcxGridCustomLayoutViewOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxGridCustomLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridCustomLayoutView(Cxcontrols::TcxControl* AControl) : Cxgridcustomtableview::TcxCustomGridTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxGridCustomLayoutView(System::Classes::TComponent* AOwner) : Cxgridcustomtableview::TcxCustomGridTableView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridCustomLayoutView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcustomtableview::TcxCustomGridTableView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxGridCustomLayoutViewRecordDefaultIndent = System::Int8(0x7);
static const int cxGridCustomLayoutViewSeparatorDefaultColor = int(536870912);
static const System::Int8 cxGridCustomLayoutViewSeparatorDefaultWidth = System::Int8(0x2);
static const System::WideChar cxGridCustomLayoutViewDefaultRecordCaptionSeparator = (System::WideChar)(0x3a);
}	/* namespace Cxgridcustomlayoutview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCUSTOMLAYOUTVIEW)
using namespace Cxgridcustomlayoutview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridcustomlayoutviewHPP
