// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCustomPivotGrid.pas' rev: 24.00 (Win32)

#ifndef CxcustompivotgridHPP
#define CxcustompivotgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <cxFilterControl.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxFilterControlDialog.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <dxCustomTree.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcustompivotgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxPivotGrid;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxPivotGrid : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxPivotGrid(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxPivotGrid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxPivotGrid(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxPivotGrid(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxPivotGrid(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxPivotGrid(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxPivotGrid(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxPivotGrid(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxPivotGrid(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxPivotGrid(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxPivotGrid(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxPivotGrid(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxPivotGrid(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPivotGridGroupItemClass;

typedef System::TMetaClass* TcxPivotGridCrossCellClass;

typedef System::TMetaClass* TcxPivotGridFieldClass;

enum TcxPivotGridChange : unsigned char { gcLayout, gcData, gcView, gcSelection };

typedef System::Set<TcxPivotGridChange, TcxPivotGridChange::gcLayout, TcxPivotGridChange::gcSelection>  TcxPivotGridChanges;

enum TcxPivotGridFieldArea : unsigned char { faColumn, faRow, faFilter, faData };

typedef System::Set<TcxPivotGridFieldArea, TcxPivotGridFieldArea::faColumn, TcxPivotGridFieldArea::faData>  TcxPivotGridFieldAreas;

enum TcxPivotGridDataFieldArea : unsigned char { dfaNone, dfaColumn, dfaRow };

typedef System::Set<TcxPivotGridDataFieldArea, TcxPivotGridDataFieldArea::dfaNone, TcxPivotGridDataFieldArea::dfaRow>  TcxPivotGridDataFieldAreas;

enum TcxPivotGridGroupInterval : unsigned char { giDefault, giDate, giDateDay, giDateDayOfWeek, giDateDayOfYear, giDateWeekOfMonth, giDateWeekOfYear, giDateMonth, giDateQuarter, giDateYear, giYearAge, giMonthAge, giWeekAge, giDayAge, giAlphabetical, giNumeric, giCustom };

enum TcxPivotGridTotalsLocation : unsigned char { tlFar, tlNear, tlCustom };

enum TcxPivotGridColumnTotalsLocation : unsigned char { ctlFar, ctlNear };

enum TcxPivotGridRowTotalsLocation : unsigned char { rtlFar, rtlNear, rtlTree };

enum TcxPivotGridSummaryType : unsigned char { stCount, stSum, stMin, stMax, stAverage, stStdDev, stStdDevP, stVariance, stVarianceP, stCustom };

enum TcxPivotGridTotalsVisibility : unsigned char { tvAutomatic, tvCustom, tvNone };

enum TcxPivotGridCalculationBaseType : unsigned char { cbRawData, cbVisibleData };

typedef System::StaticArray<NativeInt, 536870911> TIntArray;

typedef TIntArray *PIntArray;

__interface IcxPivotGridListener;
typedef System::DelphiInterface<IcxPivotGridListener> _di_IcxPivotGridListener;
class DELPHICLASS TcxCustomPivotGrid;
__interface  INTERFACE_UUID("{34D8F0E7-C4E2-4F82-A85E-6EE378E7E8FA}") IcxPivotGridListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall DataChanged(TcxCustomPivotGrid* Sender) = 0 ;
	virtual void __fastcall LayoutChanged(TcxCustomPivotGrid* Sender) = 0 ;
	virtual void __fastcall PivotRemoved(TcxCustomPivotGrid* Sender) = 0 ;
	virtual void __fastcall SelectionChanged(TcxCustomPivotGrid* Sender) = 0 ;
};

class DELPHICLASS TcxPivotList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	HIDESBASE void __fastcall Assign(System::Classes::TList* AListA, System::Classes::TListAssignOp AOperator = (System::Classes::TListAssignOp)(0x0), System::Classes::TList* AListB = (System::Classes::TList*)(0x0));
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxPivotList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridVariantValue;
class PASCALIMPLEMENTATION TcxPivotGridVariantValue : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	int FHash;
	System::Variant FUniqueName;
	bool FUnUsed;
	System::Variant FValue;
	void __fastcall CalculateHash(void);
	void __fastcall SetValue(const System::Variant &AValue);
	
public:
	__fastcall TcxPivotGridVariantValue(const System::Variant &AValue);
	bool __fastcall IsEqual(TcxPivotGridVariantValue* const AValue);
	int __fastcall Compare(const System::Variant &AValue);
	int __fastcall CompareWithHash(TcxPivotGridVariantValue* const AValue)/* overload */;
	__property int Hash = {read=FHash, nodefault};
	__property System::Variant UniqueName = {read=FUniqueName, write=FUniqueName};
	__property System::Variant Value = {read=FValue, write=SetValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridVariantValue(void) { }
	
};


class DELPHICLASS TcxPivotGridVariantList;
class PASCALIMPLEMENTATION TcxPivotGridVariantList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Variant operator[](int Index) { return Values[Index]; }
	
private:
	int FLockCount;
	bool FModified;
	bool FSortedByHash;
	System::Classes::TNotifyEvent FOnChange;
	int __fastcall GetCount(void);
	TcxPivotGridVariantValue* __fastcall GetItem(int AIndex);
	System::Variant __fastcall GetValue(int AIndex);
	void __fastcall SetSorted(bool AValue);
	void __fastcall SetSortedByHash(bool AValue);
	void __fastcall SetValue(int AIndex, const System::Variant &AValue);
	
protected:
	Cxclasses::TcxObjectList* FItems;
	bool FSorted;
	void __fastcall Changed(void);
	void __fastcall CheckCapacityOnAddItem(void);
	bool __fastcall HashedIndexOf(const System::Variant &AValue, /* out */ int &AIndex);
	int __fastcall InternalAddValue(const System::Variant &AValue, int AIndex);
	void __fastcall MakeSorted(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TcxPivotGridVariantList(void);
	__fastcall virtual ~TcxPivotGridVariantList(void);
	int __fastcall Add(const System::Variant &AValue);
	int __fastcall AddUnique(const System::Variant &AValue);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	int __fastcall IndexOf(const System::Variant &AValue);
	void __fastcall MakeUnique(void);
	int __fastcall Remove(const System::Variant &AValue);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(bool AForceUpdate = true);
	__property int Count = {read=GetCount, nodefault};
	__property TcxPivotGridVariantValue* Items[int Index] = {read=GetItem};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property bool SortedByHash = {read=FSortedByHash, write=SetSortedByHash, nodefault};
	__property System::Variant Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};


class DELPHICLASS TcxPivotGridRecords;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridRecords : public TcxPivotList
{
	typedef TcxPivotList inherited;
	
public:
	NativeInt operator[](int Index) { return Items[Index]; }
	
private:
	bool FSorted;
	NativeInt __fastcall GetItem(int AIndex);
	void __fastcall SetItem(int AIndex, NativeInt AValue);
	
protected:
	void __fastcall CreateIntersection(TcxPivotGridRecords* ARecords, PIntArray AList);
	__property bool Sorted = {read=FSorted, write=FSorted, nodefault};
	
public:
	HIDESBASE void __fastcall Add(int ARecordIndex);
	void __fastcall MakeSorted(void);
	void __fastcall MakeUnique(void);
	__property NativeInt Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotGridRecords(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxPivotGridRecords(void) : TcxPivotList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridFields;
class DELPHICLASS TcxPivotGridField;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFields : public TcxPivotList
{
	typedef TcxPivotList inherited;
	
public:
	TcxPivotGridField* operator[](int Index) { return Fields[Index]; }
	
private:
	TcxPivotGridField* __fastcall GetField(int Index);
	TcxPivotGridField* __fastcall GetFirstField(void);
	
public:
	void __fastcall ArrangeFields(void);
	__property TcxPivotGridField* Fields[int Index] = {read=GetField/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotGridFields(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxPivotGridFields(void) : TcxPivotList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridCustomCellViewInfo;
typedef void __fastcall (__closure *TcxPivotGridCustomDrawEvent)(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);

class DELPHICLASS TcxPivotGridCells;
class DELPHICLASS TcxPivotGridHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCells : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxPivotGridCustomCellViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxPivotGridCustomCellViewInfo* __fastcall GetItem(int AIndex);
	
protected:
	void __fastcall CorrectBoundsForPrinting(const System::Types::TRect &ABounds);
	
public:
	void __fastcall BeforePaint(void);
	bool __fastcall CalculateHitTest(TcxPivotGridHitTest* AHitTest);
	void __fastcall DeleteAll(void);
	void __fastcall ExcludeFromClipping(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomDrawEvent AHandler);
	__property TcxPivotGridCustomCellViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxPivotGridCells(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotGridCells(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridPrefilterPosition : unsigned char { pfpTop, pfpBottom };

class DELPHICLASS TcxPivotGridPrefilter;
class DELPHICLASS TcxPivotGridPrefilterViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilter : public TcxPivotGridCells
{
	typedef TcxPivotGridCells inherited;
	
private:
	TcxCustomPivotGrid* FPivotGrid;
	bool __fastcall GetCanMRUPopupShow(void);
	bool __fastcall GetCustomizeButtonVisible(void);
	Cxcustomdata::TcxDataFilterCriteria* __fastcall GetFilter(void);
	TcxPivotGridPrefilterPosition __fastcall GetPosition(void);
	TcxPivotGridPrefilterViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall GetVisible(void);
	
protected:
	void __fastcall Calculate(System::Types::TRect &AClientBounds);
	
public:
	__fastcall TcxPivotGridPrefilter(TcxCustomPivotGrid* APivotGrid);
	void __fastcall ShowPrefilterDialog(void);
	__property bool CanMRUPopupShow = {read=GetCanMRUPopupShow, nodefault};
	__property bool CustomizeButtonVisible = {read=GetCustomizeButtonVisible, nodefault};
	__property Cxcustomdata::TcxDataFilterCriteria* Filter = {read=GetFilter};
	__property TcxPivotGridPrefilterPosition Position = {read=GetPosition, nodefault};
	__property TcxPivotGridPrefilterViewInfo* ViewInfo = {read=GetViewInfo};
	__property bool Visible = {read=GetVisible, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridGroupItem;
class DELPHICLASS TcxPivotGridCrossCell;
class PASCALIMPLEMENTATION TcxPivotGridGroupItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxcustomdata::TcxCustomDataController* FDataController;
	System::UnicodeString FDisplayText;
	bool FExpanded;
	TcxPivotGridField* FField;
	bool FHasChildren;
	Cxclasses::TcxObjectList* FItems;
	int FIndex;
	int FMemberIndex;
	TcxPivotGridGroupItem* FParent;
	TcxCustomPivotGrid* FPivotGrid;
	int FRecordCount;
	int FRecordIndex;
	TcxPivotGridRecords* FRecords;
	System::UnicodeString FUniqueName;
	System::UnicodeString __fastcall GetDisplayText(void);
	System::Variant __fastcall GetDisplayValue(void);
	bool __fastcall GetExpanded(void);
	bool __fastcall GetHasChildren(void);
	bool __fastcall GetHasCustomTotals(void);
	TcxPivotGridGroupItem* __fastcall getNextSibling(void);
	bool __fastcall GetIsHierarchy(void);
	TcxPivotGridGroupItem* __fastcall GetItem(int AIndex);
	int __fastcall GetItemCount(void);
	int __fastcall GetLevel(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	TcxPivotGridGroupItem* __fastcall getPrevSibling(void);
	void __fastcall SetExpanded(bool AValue);
	void __fastcall SetHasChildren(bool AValue);
	
protected:
	int FHash;
	System::Variant FInternalValue;
	bool FIsValueAsssigned;
	bool FSortingValid;
	System::Variant FSummaryValue;
	virtual TcxPivotGridCrossCellClass __fastcall GetCrossCellClass(void);
	bool __fastcall GetIsCollapsed(void);
	virtual bool __fastcall GetIsRow(void);
	virtual bool __fastcall GetItemAlwaysExpanded(void);
	int __fastcall GetRecordCount(void);
	virtual int __fastcall GetSize(void);
	virtual int __fastcall GetSingleItemSize(void);
	virtual int __fastcall GetTotalsCount(void);
	System::UnicodeString __fastcall GetUniqueValue(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual TcxPivotGridGroupItemClass __fastcall ChildItemsClass(void);
	void __fastcall CollapseField(TcxPivotGridField* AField);
	void __fastcall ExpandField(TcxPivotGridField* AField);
	bool __fastcall FieldProcessTopValues(void);
	bool __fastcall FieldSortedBySummary(void);
	void __fastcall InitializeRecords(void);
	virtual void __fastcall InitSummaryValue(TcxPivotGridGroupItem* ACrossTotal);
	virtual void __fastcall PostProcessGroup(TcxPivotGridGroupItem* ACrossTotal);
	virtual void __fastcall ProcessSortBySummary(TcxPivotGridGroupItem* ACrossTotal);
	virtual void __fastcall ProcessTopValues(TcxPivotGridGroupItem* ACrossTotal);
	void __fastcall ReIndexChildren(bool AFullReindex = false);
	void __fastcall SetFieldExpanding(TcxPivotGridField* AField, bool AExpandState);
	virtual void __fastcall SetSummaryInfoDirty(TcxPivotGridGroupItem* ACrossTotal);
	__property System::Variant DisplayValue = {read=GetDisplayValue};
	__property bool IsRow = {read=GetIsRow, nodefault};
	__property Cxclasses::TcxObjectList* ItemList = {read=FItems};
	__property System::Variant SummaryValue = {read=FSummaryValue};
	
public:
	__fastcall virtual TcxPivotGridGroupItem(TcxPivotGridGroupItem* AParent, Cxcustomdata::TcxCustomDataController* ADataController, int ARecordIndex, TcxPivotGridField* AField);
	__fastcall virtual ~TcxPivotGridGroupItem(void);
	TcxPivotGridGroupItem* __fastcall AddChild(TcxPivotGridGroupItemClass AClass)/* overload */;
	TcxPivotGridGroupItem* __fastcall AddChild(int AIndex, int ARecordIndex, TcxPivotGridField* AField)/* overload */;
	void __fastcall CheckExpanding(void);
	bool __fastcall ChildrenNeeded(void);
	int __fastcall Compare(const System::Variant &AValue)/* overload */;
	virtual TcxPivotGridRecords* __fastcall CreateSummaryRecords(void);
	virtual void __fastcall DeleteChildren(void);
	virtual TcxPivotGridCrossCell* __fastcall GetCellByCrossItem(TcxPivotGridGroupItem* AItem);
	TcxPivotGridGroupItem* __fastcall GetPrev(void);
	void __fastcall InitializeValue(const System::UnicodeString ADisplayText, const System::WideString AnUniqueName);
	void __fastcall MarkDeleted(void);
	void __fastcall RemoveChildrenFrom(TcxPivotGridGroupItem* AItem);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=FDataController};
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property int Index = {read=FIndex, nodefault};
	__property TcxPivotGridField* Field = {read=FField};
	__property bool HasChildren = {read=GetHasChildren, write=SetHasChildren, nodefault};
	__property bool HasCustomTotals = {read=GetHasCustomTotals, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxPivotGridGroupItem* Items[int Index] = {read=GetItem};
	__property bool IsCollapsed = {read=GetIsCollapsed, nodefault};
	__property bool IsHierarchy = {read=GetIsHierarchy, nodefault};
	__property int Level = {read=GetLevel, nodefault};
	__property int MemberIndex = {read=FMemberIndex, write=FMemberIndex, nodefault};
	__property TcxPivotGridGroupItem* NextSibling = {read=getNextSibling};
	__property TcxPivotGridGroupItem* Parent = {read=FParent};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
	__property TcxPivotGridGroupItem* PrevSibling = {read=getPrevSibling};
	__property int RecordIndex = {read=FRecordIndex, nodefault};
	__property TcxPivotGridRecords* Records = {read=FRecords};
	__property int Size = {read=GetSize, nodefault};
	__property int TotalsCount = {read=GetTotalsCount, nodefault};
	__property System::UnicodeString UniqueName = {read=FUniqueName};
	__property System::Variant Value = {read=GetValue};
};


class DELPHICLASS TcxPivotGridRowItem;
class PASCALIMPLEMENTATION TcxPivotGridRowItem : public TcxPivotGridGroupItem
{
	typedef TcxPivotGridGroupItem inherited;
	
protected:
	TcxPivotGridCrossCell* FCachedCrossCell;
	Cxclasses::TcxObjectList* FCrossCells;
	void __fastcall ClearCache(void);
	virtual bool __fastcall GetIsRow(void);
	virtual bool __fastcall GetItemAlwaysExpanded(void);
	virtual int __fastcall GetSingleItemSize(void);
	virtual void __fastcall SetSummaryInfoDirty(TcxPivotGridGroupItem* ACrossTotal);
	
public:
	__fastcall virtual TcxPivotGridRowItem(TcxPivotGridGroupItem* AParent, Cxcustomdata::TcxCustomDataController* ADataController, int ARecordIndex, TcxPivotGridField* AField);
	__fastcall virtual ~TcxPivotGridRowItem(void);
	virtual void __fastcall DeleteChildren(void);
	virtual TcxPivotGridCrossCell* __fastcall GetCellByCrossItem(TcxPivotGridGroupItem* AItem);
};


class DELPHICLASS TcxPivotGridColumnItem;
class PASCALIMPLEMENTATION TcxPivotGridColumnItem : public TcxPivotGridGroupItem
{
	typedef TcxPivotGridGroupItem inherited;
	
protected:
	virtual bool __fastcall GetItemAlwaysExpanded(void);
	virtual int __fastcall GetSingleItemSize(void);
	virtual void __fastcall SetSummaryInfoDirty(TcxPivotGridGroupItem* ACrossTotal);
	
public:
	virtual TcxPivotGridCrossCell* __fastcall GetCellByCrossItem(TcxPivotGridGroupItem* AItem);
public:
	/* TcxPivotGridGroupItem.Create */ inline __fastcall virtual TcxPivotGridColumnItem(TcxPivotGridGroupItem* AParent, Cxcustomdata::TcxCustomDataController* ADataController, int ARecordIndex, TcxPivotGridField* AField) : TcxPivotGridGroupItem(AParent, ADataController, ARecordIndex, AField) { }
	/* TcxPivotGridGroupItem.Destroy */ inline __fastcall virtual ~TcxPivotGridColumnItem(void) { }
	
};


class DELPHICLASS TcxPivotGridDataItem;
class PASCALIMPLEMENTATION TcxPivotGridDataItem : public TcxPivotGridGroupItem
{
	typedef TcxPivotGridGroupItem inherited;
	
protected:
	virtual int __fastcall GetSingleItemSize(void);
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxPivotGridGroupItem.Create */ inline __fastcall virtual TcxPivotGridDataItem(TcxPivotGridGroupItem* AParent, Cxcustomdata::TcxCustomDataController* ADataController, int ARecordIndex, TcxPivotGridField* AField) : TcxPivotGridGroupItem(AParent, ADataController, ARecordIndex, AField) { }
	/* TcxPivotGridGroupItem.Destroy */ inline __fastcall virtual ~TcxPivotGridDataItem(void) { }
	
};


class DELPHICLASS TcxPivotGridCrossCellDataSource;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCrossCellDataSource : public Cxcustomdata::TcxCustomDataSource
{
	typedef Cxcustomdata::TcxCustomDataSource inherited;
	
protected:
	TcxCustomPivotGrid* PivotGrid;
	TcxPivotGridRecords* Records;
	bool __fastcall HasData(void);
	virtual int __fastcall GetFieldCount(void);
	virtual TcxPivotGridField* __fastcall GetPivotGridField(int AIndex);
	virtual int __fastcall GetRecordCount(void);
	virtual System::Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	
public:
	__fastcall virtual TcxPivotGridCrossCellDataSource(TcxPivotGridCrossCell* ACell);
	__fastcall virtual TcxPivotGridCrossCellDataSource(System::Classes::TList* ACrossCells);
	__fastcall virtual ~TcxPivotGridCrossCellDataSource(void);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxPivotGridField* PivotGridFields[int AIndex] = {read=GetPivotGridField};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property System::Variant Values[void * ARecordHandle][void * AItemHandle] = {read=GetValue};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridCrossCellSummary;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCrossCell : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPivotGridCrossCellSummary* operator[](int AIndex) { return SummaryCells[AIndex]; }
	
private:
	bool FCalculated;
	TcxPivotGridGroupItem* FColumn;
	TcxPivotGridCrossCell* FPrevCrossCell;
	TcxPivotGridRecords* FRecords;
	TcxPivotGridGroupItem* FRow;
	Cxclasses::TcxObjectList* FSummaryCells;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	TcxPivotGridCrossCellSummary* __fastcall GetSummaryCell(int AIndex);
	int __fastcall GetSummaryCellCount(void);
	bool __fastcall GetUseRawData(void);
	
protected:
	virtual TcxPivotGridCrossCellSummary* __fastcall AddSummaryCell(TcxPivotGridField* AField, TcxPivotGridRecords* ARecords);
	virtual void __fastcall CalculateVisibleSummary(void);
	TcxPivotGridRecords* __fastcall CreateCrossRecords(void);
	System::Classes::TList* __fastcall CreateCrossCellsList(void);
	virtual void __fastcall DoCalculateSummary(void);
	virtual bool __fastcall IsCalculationAvailable(void);
	virtual void __fastcall GetDataTypes(TcxPivotGridField* ADataField, int &ASourceType, int &AFloatType);
	virtual bool __fastcall GetIsEmpty(void);
	virtual TcxPivotGridCrossCell* __fastcall GetPrevCrossCellInRow(void);
	virtual TcxPivotGridCrossCell* __fastcall GetPrevCrossCellInColumn(void);
	__property bool Calculated = {read=FCalculated, write=FCalculated, nodefault};
	__property TcxPivotGridCrossCell* PrevCrossCell = {read=FPrevCrossCell, write=FPrevCrossCell};
	__property bool UseRawData = {read=GetUseRawData, nodefault};
	
public:
	__fastcall virtual TcxPivotGridCrossCell(TcxPivotGridGroupItem* ARow, TcxPivotGridGroupItem* AColumn);
	__fastcall virtual ~TcxPivotGridCrossCell(void);
	void __fastcall CalculateSummaries(void);
	virtual Cxcustomdata::TcxCustomDataSource* __fastcall CreateDrillDownDataSource(void);
	virtual System::Variant __fastcall GetSummaryByField(TcxPivotGridField* AField, TcxPivotGridSummaryType ASummaryType);
	virtual System::Variant __fastcall GetSummaryValue(TcxPivotGridCrossCellSummary* ASummary, TcxPivotGridSummaryType AType);
	__property TcxPivotGridGroupItem* Column = {read=FColumn};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property TcxPivotGridRecords* Records = {read=FRecords};
	__property TcxPivotGridGroupItem* Row = {read=FRow};
	__property int SummaryCellCount = {read=GetSummaryCellCount, nodefault};
	__property TcxPivotGridCrossCellSummary* SummaryCells[int AIndex] = {read=GetSummaryCell/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOLAPCrossCell;
class PASCALIMPLEMENTATION TcxPivotGridOLAPCrossCell : public TcxPivotGridCrossCell
{
	typedef TcxPivotGridCrossCell inherited;
	
private:
	bool FIsEmpty;
	System::Variant FNativeValues;
	
protected:
	virtual void __fastcall GetDataTypes(TcxPivotGridField* ADataField, int &ASourceType, int &AFloatType);
	virtual bool __fastcall GetIsEmpty(void);
	virtual bool __fastcall IsCalculationAvailable(void);
	
public:
	virtual System::Variant __fastcall GetSummaryByField(TcxPivotGridField* AField, TcxPivotGridSummaryType ASummaryType);
	virtual System::Variant __fastcall GetSummaryValue(TcxPivotGridCrossCellSummary* ASummary, TcxPivotGridSummaryType AType);
	__property System::Variant NativeValues = {read=FNativeValues, write=FNativeValues};
public:
	/* TcxPivotGridCrossCell.Create */ inline __fastcall virtual TcxPivotGridOLAPCrossCell(TcxPivotGridGroupItem* ARow, TcxPivotGridGroupItem* AColumn) : TcxPivotGridCrossCell(ARow, AColumn) { }
	/* TcxPivotGridCrossCell.Destroy */ inline __fastcall virtual ~TcxPivotGridOLAPCrossCell(void) { }
	
};


typedef System::Variant __fastcall (__closure *TcxPivotGridGetRecordValueProc)(const void * ARecord, bool AIsGroupValue);

class PASCALIMPLEMENTATION TcxPivotGridCrossCellSummary : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::StaticArray<System::Variant, 10> _TcxPivotGridCrossCellSummary__1;
	
	
private:
	TcxPivotGridField* FDataField;
	TcxPivotGridCrossCell* FOwner;
	_TcxPivotGridCrossCellSummary__1 FSummaries;
	System::Variant FSummaryVariation;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	System::Variant __fastcall GetSummaryByIndex(int AIndex);
	bool __fastcall GetSummaryNullIgnore(void);
	TcxPivotGridRecords* __fastcall GetRecords(void);
	bool __fastcall GetVariationNullIgnore(void);
	
protected:
	virtual void __fastcall CalculateCustomSummary(void);
	virtual void __fastcall CalculateSummaryVariation(void);
	virtual void __fastcall CheckValue(System::Variant &AValue);
	virtual void __fastcall DoCalculateSummary(System::Classes::TList* ARecords, TcxPivotGridGetRecordValueProc AGetValueProc = 0x0);
	System::Variant __fastcall GetIntermadiateValue(const void * ACell, bool AIsGroupValue);
	System::Variant __fastcall GetRecordValue(const void * ARecord, bool AIsGroupValue);
	void __fastcall SetSummaryByIndex(int AIndex, const System::Variant &AValue);
	void __fastcall SetSummaryByType(TcxPivotGridSummaryType AType, const System::Extended AValue, int AVarType);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property bool SummaryNullIgnore = {read=GetSummaryNullIgnore, nodefault};
	__property bool VariationNullIgnore = {read=GetVariationNullIgnore, nodefault};
	
public:
	__fastcall virtual TcxPivotGridCrossCellSummary(TcxPivotGridCrossCell* AOwner, TcxPivotGridField* ADataField);
	virtual void __fastcall Clear(void);
	TcxPivotGridCrossCellSummary* __fastcall GetPrevCell(TcxPivotGridCrossCellSummary* APrevCell);
	virtual System::Variant __fastcall GetValue(int ARecordIndex);
	System::Variant __fastcall GetSummaryByType(TcxPivotGridSummaryType AType);
	System::Variant __fastcall GetSummaryValue(TcxPivotGridSummaryType AType);
	__property System::Variant Average = {read=GetSummaryByIndex, index=4};
	__property System::Variant Count = {read=GetSummaryByIndex, index=0};
	__property System::Variant Custom = {read=GetSummaryByIndex, write=SetSummaryByIndex, index=9};
	__property TcxPivotGridField* DataField = {read=FDataField};
	__property System::Variant Max = {read=GetSummaryByIndex, index=3};
	__property System::Variant Min = {read=GetSummaryByIndex, index=2};
	__property TcxPivotGridCrossCell* Owner = {read=FOwner};
	__property TcxPivotGridRecords* Records = {read=GetRecords};
	__property System::Variant StdDev = {read=GetSummaryByIndex, index=5};
	__property System::Variant StdDevP = {read=GetSummaryByIndex, index=6};
	__property System::Variant Sum = {read=GetSummaryByIndex, index=1};
	__property System::Variant SummaryVariation = {read=FSummaryVariation, write=FSummaryVariation};
	__property System::Variant Variance = {read=GetSummaryByIndex, index=7};
	__property System::Variant VarianceP = {read=GetSummaryByIndex, index=8};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridCrossCellSummary(void) { }
	
};


typedef System::TMetaClass* TcxPivotGridCrossCellSummaryClass;

class DELPHICLASS TcxPivotGridDataBuilder;
class DELPHICLASS TcxPivotGridCustomOLAPDataSource;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridDataBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxPivotGridFields* FColumnFields;
	TcxPivotGridGroupItem* FColumns;
	TcxPivotGridGroupItem* FData;
	Cxcustomdata::TcxCustomDataController* FDataController;
	TcxPivotGridFields* FDataFields;
	System::Classes::TList* FExpandingItems;
	int FExpandingLockCount;
	TcxPivotGridFields* FFields;
	TcxPivotGridFields* FFilteredFields;
	TcxPivotGridRecords* FFilteredIndexes;
	TcxPivotGridFields* FFilterFields;
	TcxPivotGridGroupItem* FGroupCrossItem;
	int FGroupCrossRecordCount;
	TIntArray *FGroupCrossRecords;
	TIntArray *FGroupRecords;
	TcxPivotGridCustomOLAPDataSource* FOLAPDataSource;
	TcxCustomPivotGrid* FPivotGrid;
	TcxPivotGridFields* FRowFields;
	TcxPivotGridGroupItem* FRows;
	TcxPivotGridCrossCell* __fastcall GetCrossCell(TcxPivotGridGroupItem* ARow, TcxPivotGridGroupItem* AColumn);
	TcxPivotGridFields* __fastcall GetSummaryFields(void);
	
protected:
	void __fastcall AddSummaryField(TcxPivotGridField* AField);
	void __fastcall AfterDataChanged(void);
	virtual void __fastcall ApplyFilter(void);
	bool __fastcall CanGroupByColumns(void);
	bool __fastcall CanGroupByRows(void);
	virtual void __fastcall Clear(void);
	void __fastcall ClearGroupRecords(void);
	void __fastcall CreateDataCells(void);
	virtual void __fastcall GroupBy(TcxPivotGridFields* AFields, TcxPivotGridGroupItem* ARoot);
	virtual void __fastcall GroupByColumns(void);
	virtual void __fastcall GroupByRows(void);
	void __fastcall GroupExpandingChanged(TcxPivotGridGroupItem* AItem);
	PIntArray __fastcall InitializeRecordsList(void);
	void __fastcall LockExpanding(void);
	void __fastcall PopulateRecordsList(void);
	void __fastcall SplitFieldsByGroups(void);
	void __fastcall UnlockExpanding(void);
	
public:
	__fastcall TcxPivotGridDataBuilder(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridDataBuilder(void);
	bool __fastcall CanGroup(void);
	virtual void __fastcall DataChanged(void);
	TcxPivotGridFields* __fastcall GetFieldsListByArea(TcxPivotGridFieldArea Area);
	__property TcxPivotGridFields* ColumnFields = {read=FColumnFields};
	__property TcxPivotGridGroupItem* Columns = {read=FColumns};
	__property TcxPivotGridCrossCell* CrossCells[TcxPivotGridGroupItem* ARow][TcxPivotGridGroupItem* AColumn] = {read=GetCrossCell};
	__property TcxPivotGridGroupItem* Data = {read=FData};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=FDataController};
	__property TcxPivotGridFields* DataFields = {read=FDataFields};
	__property TcxPivotGridFields* Fields = {read=FFields};
	__property TcxPivotGridFields* FilteredFields = {read=FFilteredFields};
	__property TcxPivotGridRecords* FilteredIndexes = {read=FFilteredIndexes};
	__property TcxPivotGridFields* FilterFields = {read=FFilterFields};
	__property TcxPivotGridGroupItem* GroupCrossItem = {read=FGroupCrossItem, write=FGroupCrossItem};
	__property PIntArray GroupCrossRecords = {read=FGroupCrossRecords};
	__property int GroupCrossRecordCount = {read=FGroupCrossRecordCount, write=FGroupCrossRecordCount, nodefault};
	__property PIntArray GroupRecords = {read=FGroupRecords};
	__property TcxPivotGridCustomOLAPDataSource* OLAPDataSource = {read=FOLAPDataSource};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
	__property TcxPivotGridFields* RowFields = {read=FRowFields};
	__property TcxPivotGridGroupItem* Rows = {read=FRows};
	__property TcxPivotGridFields* SummaryFields = {read=GetSummaryFields};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridViewDataLimitValue;
class PASCALIMPLEMENTATION TcxPivotGridViewDataLimitValue : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TcxPivotGridField* Field;
	System::Variant MaxValue;
	System::Variant MinValue;
	
public:
	__fastcall TcxPivotGridViewDataLimitValue(TcxPivotGridField* AField);
	void __fastcall Calculate(const System::Variant &V);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridViewDataLimitValue(void) { }
	
};


class DELPHICLASS TcxPivotGridViewDataLimitValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridViewDataLimitValues : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxPivotGridViewDataLimitValue* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxPivotGridViewDataLimitValue* __fastcall GetItem(int Index);
	
public:
	HIDESBASE TcxPivotGridViewDataLimitValue* __fastcall Add(TcxPivotGridField* AField)/* overload */;
	void __fastcall Calculate(TcxPivotGridField* AField, const System::Variant &V);
	TcxPivotGridViewDataLimitValue* __fastcall FindByField(TcxPivotGridField* AField);
	System::Variant __fastcall GetMaximumValue(TcxPivotGridField* AField);
	System::Variant __fastcall GetMinimumValue(TcxPivotGridField* AField);
	__property TcxPivotGridViewDataLimitValue* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxPivotGridViewDataLimitValues(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotGridViewDataLimitValues(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridViewDataItem;
class DELPHICLASS TcxPivotGridCustomTotal;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridViewDataItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FIndex;
	bool FIsDataField;
	Cxclasses::TcxObjectList* FItems;
	TcxPivotGridGroupItem* FGroupItem;
	TcxPivotGridViewDataLimitValues* FLimitValues;
	TcxPivotGridViewDataItem* FParent;
	int FTag;
	int FVisibleIndex;
	bool __fastcall GetExpanded(void);
	TcxPivotGridViewDataItem* __fastcall GetFirst(void);
	bool __fastcall GetHasButton(void);
	bool __fastcall GetHasChildren(void);
	TcxPivotGridViewDataItem* __fastcall GetItem(int AIndex);
	int __fastcall GetItemCount(void);
	bool __fastcall GetIsGrandTotal(void);
	bool __fastcall GetIsTotalItem(void);
	TcxPivotGridViewDataItem* __fastcall GetLast(void);
	int __fastcall GetLevel(void);
	TcxPivotGridViewDataItem* __fastcall GetNextVisible(void);
	TcxPivotGridViewDataItem* __fastcall GetPrevVisible(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	TcxPivotGridViewDataItem* __fastcall GetRoot(void);
	System::Classes::TList* __fastcall GetViewDataList(void);
	bool __fastcall GetVisible(void);
	
protected:
	virtual int __fastcall GetChildLeftVisibleIndex(void);
	virtual int __fastcall GetChildRightVisibleIndex(void);
	virtual TcxPivotGridField* __fastcall GetField(void);
	virtual bool __fastcall GetIsTotal(void);
	virtual int __fastcall GetSize(void);
	int __fastcall GetSizeWithChildren(void);
	int __fastcall GetSizeWithDataFields(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	__property TcxPivotGridViewDataLimitValues* LimitValues = {read=FLimitValues};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property System::Classes::TList* ViewDataList = {read=GetViewDataList};
	
public:
	__fastcall virtual TcxPivotGridViewDataItem(TcxPivotGridViewDataItem* AParent, TcxPivotGridGroupItem* AGroupItem);
	__fastcall virtual ~TcxPivotGridViewDataItem(void);
	TcxPivotGridViewDataItem* __fastcall Add(TcxPivotGridGroupItem* AData);
	TcxPivotGridViewDataItem* __fastcall AddTotal(TcxPivotGridGroupItem* AData, int AIndex);
	void __fastcall ClearCache(void);
	void __fastcall DeleteChildren(void);
	System::UnicodeString __fastcall GetDisplayText(void);
	TcxPivotGridGroupItem* __fastcall GetGroupItem(TcxPivotGridField* &ADataField);
	TcxPivotGridGroupItem* __fastcall GetGroupItemByField(TcxPivotGridField* ADataField);
	virtual bool __fastcall GetSummaryType(TcxPivotGridSummaryType &ASummaryType, TcxPivotGridCustomTotal* &ATotal);
	int __fastcall MeasureWidth(System::Classes::TPersistent* AField, bool AIncludeTotals);
	__property bool Expanded = {read=GetExpanded, nodefault};
	__property TcxPivotGridField* Field = {read=GetField};
	__property TcxPivotGridViewDataItem* First = {read=GetFirst};
	__property TcxPivotGridGroupItem* GroupItem = {read=FGroupItem};
	__property bool HasButton = {read=GetHasButton, nodefault};
	__property bool HasChildren = {read=GetHasChildren, nodefault};
	__property int Index = {read=FIndex, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxPivotGridViewDataItem* Items[int Index] = {read=GetItem};
	__property bool IsDataField = {read=FIsDataField, nodefault};
	__property bool IsGrandTotal = {read=GetIsGrandTotal, nodefault};
	__property bool IsTotal = {read=GetIsTotal, nodefault};
	__property bool IsTotalItem = {read=GetIsTotalItem, nodefault};
	__property TcxPivotGridViewDataItem* Last = {read=GetLast};
	__property int Level = {read=GetLevel, nodefault};
	__property TcxPivotGridViewDataItem* NextVisible = {read=GetNextVisible};
	__property TcxPivotGridViewDataItem* Parent = {read=FParent};
	__property TcxPivotGridViewDataItem* PrevVisible = {read=GetPrevVisible};
	__property TcxPivotGridViewDataItem* Root = {read=GetRoot};
	__property int Size = {read=GetSize, nodefault};
	__property int SizeWithChildren = {read=GetSizeWithChildren, nodefault};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	__property System::UnicodeString Value = {read=GetValue};
	__property bool Visible = {read=GetVisible, nodefault};
	__property int VisibleIndex = {read=FVisibleIndex, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridViewDataTotalItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridViewDataTotalItem : public TcxPivotGridViewDataItem
{
	typedef TcxPivotGridViewDataItem inherited;
	
private:
	TcxPivotGridCustomTotal* FTotal;
	
protected:
	System::UnicodeString __fastcall GetDescription(void);
	virtual bool __fastcall GetIsTotal(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	void __fastcall SetTotal(int AIndex);
	
public:
	virtual bool __fastcall GetSummaryType(TcxPivotGridSummaryType &ASummaryType, TcxPivotGridCustomTotal* &ATotal);
	__property TcxPivotGridCustomTotal* Total = {read=FTotal};
public:
	/* TcxPivotGridViewDataItem.Create */ inline __fastcall virtual TcxPivotGridViewDataTotalItem(TcxPivotGridViewDataItem* AParent, TcxPivotGridGroupItem* AGroupItem) : TcxPivotGridViewDataItem(AParent, AGroupItem) { }
	/* TcxPivotGridViewDataItem.Destroy */ inline __fastcall virtual ~TcxPivotGridViewDataTotalItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridViewDataSelection;
class DELPHICLASS TcxPivotGridViewData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridViewDataSelection : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	typedef System::DynamicArray<System::Types::TRect> _TcxPivotGridViewDataSelection__1;
	
	
public:
	System::Types::TRect operator[](int AIndex) { return Regions[AIndex]; }
	
private:
	System::Types::TRect FAnchorCells;
	System::Types::TPoint FFocusedCell;
	bool FHasTemporarySelection;
	_TcxPivotGridViewDataSelection__1 FRegions;
	int FLockCount;
	TcxPivotGridViewData* FViewData;
	int __fastcall GetCount(void);
	System::Types::TRect __fastcall GetRegion(int AIndex);
	bool __fastcall GetMultiSelect(void);
	System::Types::TRect __fastcall GetTemporarySelection(void);
	bool __fastcall IsTemporarySelected(void);
	void __fastcall SetFocusedCell(const System::Types::TPoint &APoint);
	void __fastcall SetTemporarySelection(const System::Types::TRect &AValue);
	
protected:
	virtual void __fastcall ApplyTemporarySelection(bool AIsSet);
	virtual void __fastcall ChangeSelection(const System::Types::TRect &R, System::Classes::TShiftState AShift);
	virtual void __fastcall DoChanged(void);
	virtual void __fastcall InnerClear(void);
	virtual void __fastcall InnerSetFocusedCell(const System::Types::TPoint &APoint);
	bool __fastcall IsSelected(void);
	void __fastcall ValidateFocusedCell(void);
	void __fastcall ValidateSelections(void);
	__property System::Types::TRect AnchorCells = {read=FAnchorCells, write=FAnchorCells};
	__property int LockCount = {read=FLockCount, nodefault};
	__property bool MultiSelect = {read=GetMultiSelect, nodefault};
	__property System::Types::TRect TemporarySelection = {read=GetTemporarySelection, write=SetTemporarySelection};
	__property TcxPivotGridViewData* ViewData = {read=FViewData};
	
public:
	__fastcall virtual TcxPivotGridViewDataSelection(TcxPivotGridViewData* AViewData);
	__fastcall virtual ~TcxPivotGridViewDataSelection(void);
	virtual void __fastcall Add(const System::Types::TRect &ARegion);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	void __fastcall EndUpdate(bool ASendNotification = true);
	virtual System::Types::TRect __fastcall GetCombinedSelectionBounds(void);
	virtual bool __fastcall IsCellSelected(int AColumn, int ARow);
	virtual void __fastcall MakeNew(const System::Types::TRect &ARegion);
	__property int Count = {read=GetCount, nodefault};
	__property System::Types::TPoint FocusedCell = {read=FFocusedCell, write=SetFocusedCell};
	__property System::Types::TRect Regions[int AIndex] = {read=GetRegion/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOptionsSelection;
class DELPHICLASS TcxPivotGridOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridViewData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FBookMarkRow;
	bool FCalculatedLimitValues;
	int FColumnIndex;
	TcxPivotGridViewDataItem* FColumns;
	System::Classes::TList* FColumnsList;
	int FColumnsPerPage;
	bool FExpandColumns;
	bool FExpandRows;
	TcxPivotGridViewDataLimitValues* FLimitValues;
	int FMaxRowLevel;
	int FMaxColumnLevel;
	TcxCustomPivotGrid* FOwner;
	int FRowIndex;
	TcxPivotGridViewDataItem* FRows;
	System::Classes::TList* FRowsList;
	int FRowsPerPage;
	TcxPivotGridViewDataSelection* FSelection;
	System::Types::TRect __fastcall GetAnchorCells(void);
	TcxPivotGridCrossCellSummary* __fastcall GetCell(int ARow, int AColumn);
	System::UnicodeString __fastcall GetCellAsText(int ARow, int AColumn);
	TcxPivotGridViewDataItem* __fastcall GetColumn(int AIndex);
	int __fastcall GetColumnCount(void);
	TcxPivotGridDataBuilder* __fastcall GetDataBuilder(void);
	System::Types::TPoint __fastcall GetFocusedCell(void);
	TcxPivotGridOptionsSelection* __fastcall GetOptionsSelection(void);
	TcxPivotGridOptionsView* __fastcall GetOptionsView(void);
	TcxPivotGridViewDataItem* __fastcall GetRow(int AIndex);
	int __fastcall GetRowCount(void);
	bool __fastcall NeedCalculateLimitValues(void);
	void __fastcall SetAnchorCells(const System::Types::TRect &AValue);
	void __fastcall SetColumnIndex(int AIndex);
	void __fastcall SetFocusedCell(const System::Types::TPoint &APoint);
	void __fastcall SetRowIndex(int AIndex);
	
protected:
	void __fastcall AdjustCellIndexes(int &ARow, int &AColumn, bool AByMouse = false);
	System::Types::TPoint __fastcall AdjustCellIndexesPoint(const System::Types::TPoint &P, bool AByMouse = false);
	void __fastcall Calculate(void);
	int __fastcall CalculateDataWidth(TcxPivotGridField* AField);
	void __fastcall CalculateDataFieldInfo(int &AFieldIndex, TcxPivotGridGroupItem* &AFields, TcxPivotGridDataFieldArea AcceptedArea);
	void __fastcall CalculateLimitValues(void);
	void __fastcall Clear(void);
	virtual bool __fastcall CanCellSelect(int ARow, int AColumn);
	void __fastcall DoNextPage(bool AGoForward);
	virtual void __fastcall HeaderCellSelect(TcxPivotGridViewDataItem* ADataItem, System::Classes::TShiftState AShift);
	bool __fastcall IsGroupItemEquals(TcxPivotGridViewDataItem* AItem1, TcxPivotGridViewDataItem* AItem2);
	int __fastcall PopulateSelectedCells(System::Classes::TList* ACells);
	void __fastcall ProduceColumns(void);
	void __fastcall ProduceRows(void);
	virtual void __fastcall Scroll(System::Uitypes::TScrollCode AScrollCode, TcxPivotGridViewDataItem* AItem, int APage, int AMax, int ASize, int AScrollPos, int &APos);
	bool __fastcall ScrollColumns(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	bool __fastcall ScrollRows(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall ValidateIndexes(void);
	void __fastcall ValidateSelection(System::Types::TRect &ASelection);
	__property System::Types::TRect AnchorCells = {read=GetAnchorCells, write=SetAnchorCells};
	__property bool CalculatedLimitValues = {read=FCalculatedLimitValues, nodefault};
	__property bool ExpandColumns = {read=FExpandColumns, write=FExpandColumns, nodefault};
	__property bool ExpandRows = {read=FExpandRows, write=FExpandRows, nodefault};
	__property TcxPivotGridViewDataLimitValues* LimitValues = {read=FLimitValues};
	__property TcxPivotGridOptionsSelection* OptionsSelection = {read=GetOptionsSelection};
	
public:
	__fastcall virtual TcxPivotGridViewData(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridViewData(void);
	bool __fastcall IsCellSelected(int ARow, int AColumn);
	bool __fastcall MakeSelectionVisible(void);
	__property TcxPivotGridCrossCellSummary* Cells[int Row][int Column] = {read=GetCell};
	__property System::UnicodeString CellsAsText[int Row][int Column] = {read=GetCellAsText};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property int ColumnIndex = {read=FColumnIndex, write=SetColumnIndex, nodefault};
	__property TcxPivotGridViewDataItem* Columns[int AIndex] = {read=GetColumn};
	__property int ColumnsPerPage = {read=FColumnsPerPage, write=FColumnsPerPage, nodefault};
	__property System::Classes::TList* ColumnsList = {read=FColumnsList};
	__property TcxPivotGridDataBuilder* DataBuilder = {read=GetDataBuilder};
	__property System::Types::TPoint FocusedCell = {read=GetFocusedCell, write=SetFocusedCell};
	__property int MaxRowLevel = {read=FMaxRowLevel, nodefault};
	__property int MaxColumnLevel = {read=FMaxColumnLevel, nodefault};
	__property TcxPivotGridOptionsView* OptionsView = {read=GetOptionsView};
	__property TcxCustomPivotGrid* PivotGrid = {read=FOwner};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int RowIndex = {read=FRowIndex, write=SetRowIndex, nodefault};
	__property TcxPivotGridViewDataItem* Rows[int AIndex] = {read=GetRow};
	__property System::Classes::TList* RowsList = {read=FRowsList};
	__property int RowsPerPage = {read=FRowsPerPage, write=FRowsPerPage, nodefault};
	__property TcxPivotGridViewDataSelection* Selection = {read=FSelection};
};

#pragma pack(pop)

__interface IcxPivotGridSizableObject;
typedef System::DelphiInterface<IcxPivotGridSizableObject> _di_IcxPivotGridSizableObject;
__interface  INTERFACE_UUID("{CFCAC754-EC31-4A72-8BED-1D9D2715E062}") IcxPivotGridSizableObject  : public System::IInterface 
{
	
public:
	virtual void __fastcall ApplyBestFit(void) = 0 ;
	virtual bool __fastcall CanResize(void) = 0 ;
	virtual int __fastcall GetActualWidth(void) = 0 ;
	virtual int __fastcall GetMinWidth(void) = 0 ;
	virtual void __fastcall SetSizeDelta(int ADelta) = 0 ;
};

__interface IcxPivotGridField;
typedef System::DelphiInterface<IcxPivotGridField> _di_IcxPivotGridField;
class DELPHICLASS TcxPivotGridFieldHeaderCellViewInfo;
class DELPHICLASS TcxPivotGridDragDropAreaInfo;
__interface  INTERFACE_UUID("{61CC4884-4510-4C28-86DC-EC0B984E56DA}") IcxPivotGridField  : public IcxPivotGridSizableObject 
{
	
public:
	virtual void __fastcall AssignAreaIndex(TcxPivotGridFieldArea AArea, int AIndex) = 0 ;
	virtual bool __fastcall CanDrag(void) = 0 ;
	virtual bool __fastcall CanDrop(TcxPivotGridFieldArea AArea) = 0 ;
	virtual bool __fastcall CanRemove(void) = 0 ;
	virtual void __fastcall ChangeExpanding(void) = 0 ;
	virtual void __fastcall ChangeSorting(void) = 0 ;
	virtual void __fastcall DragDrop(TcxPivotGridFieldArea AArea, int AIndex) = 0 ;
	virtual bool __fastcall GetVisible(void) = 0 ;
	virtual TcxPivotGridFieldHeaderCellViewInfo* __fastcall GetViewInfo(void) = 0 ;
	virtual bool __fastcall IsCompatibleWidth(TcxPivotGridDragDropAreaInfo* AInfo) = 0 ;
	virtual void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AState) = 0 ;
	virtual void __fastcall SetVisible(bool AValue) = 0 ;
};

class DELPHICLASS TcxPivotGridCustomOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomPivotGrid* FPivotGrid;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Changed(void);
	void __fastcall SetBoolValue(bool &AFieldValue, bool AValue);
	
public:
	__fastcall virtual TcxPivotGridCustomOptions(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsBehavior : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FCellHints;
	bool FFieldHeaderHints;
	bool FFocusCellOnCycle;
	bool FFocusCellOnTab;
	bool FGroupHeaderHints;
	
public:
	__fastcall virtual TcxPivotGridOptionsBehavior(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CellHints = {read=FCellHints, write=FCellHints, default=0};
	__property bool FieldHeaderHints = {read=FFieldHeaderHints, write=FFieldHeaderHints, default=1};
	__property bool FocusCellOnCycle = {read=FFocusCellOnCycle, write=FFocusCellOnCycle, default=0};
	__property bool FocusCellOnTab = {read=FFocusCellOnTab, write=FFocusCellOnTab, default=0};
	__property bool GroupHeaderHints = {read=FGroupHeaderHints, write=FGroupHeaderHints, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOptionsBehavior(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsCustomize : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FFiltering;
	bool FFilterResizable;
	bool FHiding;
	bool FMoving;
	bool FQuickCustomization;
	bool FQuickPrefiltering;
	bool FSizing;
	bool FSorting;
	void __fastcall SetFiltering(bool AValue);
	void __fastcall SetValue(int AIndex, bool AValue);
	
public:
	__fastcall virtual TcxPivotGridOptionsCustomize(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Filtering = {read=FFiltering, write=SetValue, index=0, default=1};
	__property bool FilterResizable = {read=FFilterResizable, write=SetValue, index=6, default=1};
	__property bool Hiding = {read=FHiding, write=SetValue, index=1, default=1};
	__property bool Moving = {read=FMoving, write=SetValue, index=2, default=1};
	__property bool QuickCustomization = {read=FQuickCustomization, write=SetValue, index=3, default=1};
	__property bool QuickPrefiltering = {read=FQuickPrefiltering, write=SetValue, index=7, default=1};
	__property bool Sizing = {read=FSizing, write=SetValue, index=4, default=1};
	__property bool Sorting = {read=FSorting, write=SetValue, index=5, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOptionsCustomize(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridLines : unsigned char { pglNone, pglHorz, pglVert, pglBoth };

enum TcxPivotGridShowHeaderFilterButtons : unsigned char { pgsfbAlways, pgsfbWhenSelected };

enum TcxPivotGridFilterButtonShowMode : unsigned char { pgfbmButton, pgfbmSmartTag };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsView : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FColumnFields;
	bool FColumnGrandTotals;
	System::UnicodeString FColumnGrandTotalText;
	int FColumnGrandTotalWidth;
	bool FColumnTotals;
	TcxPivotGridColumnTotalsLocation FColumnTotalsLocation;
	bool FDataFields;
	System::Uitypes::TColor FDropArrowColor;
	int FFilterDropDownMaxItemCount;
	int FFilterDropDownWidth;
	bool FFilterFields;
	bool FFilterSeparator;
	bool FGrandTotalsForSingleValues;
	System::Uitypes::TColor FGridLineColor;
	TcxPivotGridLines FGridLines;
	bool FMarkNarrowCells;
	bool FRowFields;
	bool FRowGrandTotals;
	System::UnicodeString FRowGrandTotalText;
	int FRowGrandTotalWidth;
	bool FRowTotals;
	TcxPivotGridRowTotalsLocation FRowTotalsLocation;
	TcxPivotGridShowHeaderFilterButtons FShowHeaderFilterButtons;
	bool FTotalsForSingleValues;
	TcxPivotGridFilterButtonShowMode FHeaderFilterButtonShowMode;
	bool __fastcall GetIsCompactLayout(void);
	System::Uitypes::TScrollStyle __fastcall GetScrollBars(void);
	TcxPivotGridTotalsLocation __fastcall GetTotalsLocation(void);
	void __fastcall ReadGrandTotalWidth(System::Classes::TReader* AReader);
	void __fastcall SetColumnFields(bool AValue);
	void __fastcall SetColumnGrandTotals(bool AValue);
	void __fastcall SetColumnGrandTotalText(const System::UnicodeString AValue);
	void __fastcall SetColumnGrandTotalWidth(int AValue);
	void __fastcall SetColumnTotals(bool AValue);
	void __fastcall SetColumnTotalsLocation(TcxPivotGridColumnTotalsLocation AValue);
	void __fastcall SetDataFields(bool AValue);
	void __fastcall SetFilterDropDownMaxItemCount(int AValue);
	void __fastcall SetFilterDropDownWidth(int AValue);
	void __fastcall SetFilterFields(bool AValue);
	void __fastcall SetFilterSeparator(bool AValue);
	void __fastcall SetGrandTotalsForSingleValues(bool AValue);
	void __fastcall SetGridLineColor(System::Uitypes::TColor AValue);
	void __fastcall SetGridLines(TcxPivotGridLines AValue);
	void __fastcall SetHeaderFilterButtonShowMode(TcxPivotGridFilterButtonShowMode AValue);
	void __fastcall SetMarkNarrowCells(bool AValue);
	void __fastcall SetRowFields(bool AValue);
	void __fastcall SetRowGrandTotals(bool AValue);
	void __fastcall SetRowGrandTotalText(const System::UnicodeString AValue);
	void __fastcall SetRowGrandTotalWidth(int AValue);
	void __fastcall SetRowTotals(bool AValue);
	void __fastcall SetRowTotalsLocation(TcxPivotGridRowTotalsLocation AValue);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle AValue);
	void __fastcall SetShowHeaderFilterButtons(TcxPivotGridShowHeaderFilterButtons AValue);
	void __fastcall SetTotalsForSingleValues(bool AValue);
	void __fastcall SetTotalsLocation(const TcxPivotGridTotalsLocation AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	int __fastcall GetActualItemWidth(bool AColumnItem);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	void __fastcall ApplyBestFit(void);
	bool __fastcall CanResize(void);
	int __fastcall GetActualWidth(void);
	int __fastcall GetMinWidth(void);
	void __fastcall SetSizeDelta(int ADelta);
	__property bool IsCompactLayout = {read=GetIsCompactLayout, nodefault};
	
public:
	__fastcall virtual TcxPivotGridOptionsView(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool ColumnFields = {read=FColumnFields, write=SetColumnFields, default=1};
	__property bool ColumnGrandTotals = {read=FColumnGrandTotals, write=SetColumnGrandTotals, default=1};
	__property System::UnicodeString ColumnGrandTotalText = {read=FColumnGrandTotalText, write=SetColumnGrandTotalText};
	__property int ColumnGrandTotalWidth = {read=FColumnGrandTotalWidth, write=SetColumnGrandTotalWidth, default=0};
	__property bool ColumnTotals = {read=FColumnTotals, write=SetColumnTotals, default=1};
	__property TcxPivotGridColumnTotalsLocation ColumnTotalsLocation = {read=FColumnTotalsLocation, write=SetColumnTotalsLocation, default=0};
	__property bool DataFields = {read=FDataFields, write=SetDataFields, default=1};
	__property System::Uitypes::TColor DropArrowColor = {read=FDropArrowColor, write=FDropArrowColor, default=65280};
	__property int FilterDropDownMaxItemCount = {read=FFilterDropDownMaxItemCount, write=SetFilterDropDownMaxItemCount, default=15};
	__property int FilterDropDownWidth = {read=FFilterDropDownWidth, write=SetFilterDropDownWidth, default=0};
	__property bool FilterFields = {read=FFilterFields, write=SetFilterFields, default=1};
	__property bool FilterSeparator = {read=FFilterSeparator, write=SetFilterSeparator, default=1};
	__property bool GrandTotalsForSingleValues = {read=FGrandTotalsForSingleValues, write=SetGrandTotalsForSingleValues, default=0};
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=536870912};
	__property TcxPivotGridLines GridLines = {read=FGridLines, write=SetGridLines, default=3};
	__property TcxPivotGridFilterButtonShowMode HeaderFilterButtonShowMode = {read=FHeaderFilterButtonShowMode, write=SetHeaderFilterButtonShowMode, default=0};
	__property bool MarkNarrowCells = {read=FMarkNarrowCells, write=SetMarkNarrowCells, default=0};
	__property bool RowFields = {read=FRowFields, write=SetRowFields, default=1};
	__property bool RowGrandTotals = {read=FRowGrandTotals, write=SetRowGrandTotals, default=1};
	__property System::UnicodeString RowGrandTotalText = {read=FRowGrandTotalText, write=SetRowGrandTotalText};
	__property int RowGrandTotalWidth = {read=FRowGrandTotalWidth, write=SetRowGrandTotalWidth, default=0};
	__property bool RowTotals = {read=FRowTotals, write=SetRowTotals, default=1};
	__property TcxPivotGridRowTotalsLocation RowTotalsLocation = {read=FRowTotalsLocation, write=SetRowTotalsLocation, default=0};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=GetScrollBars, write=SetScrollBars, default=3};
	__property TcxPivotGridShowHeaderFilterButtons ShowHeaderFilterButtons = {read=FShowHeaderFilterButtons, write=SetShowHeaderFilterButtons, default=0};
	__property bool TotalsForSingleValues = {read=FTotalsForSingleValues, write=SetTotalsForSingleValues, default=0};
	__property TcxPivotGridTotalsLocation TotalsLocation = {read=GetTotalsLocation, write=SetTotalsLocation, stored=false, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOptionsView(void) { }
	
private:
	void *__IcxPivotGridSizableObject;	/* IcxPivotGridSizableObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {CFCAC754-EC31-4A72-8BED-1D9D2715E062}
	operator _di_IcxPivotGridSizableObject()
	{
		_di_IcxPivotGridSizableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridSizableObject*(void) { return (IcxPivotGridSizableObject*)&__IcxPivotGridSizableObject; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxPivotGridSizableObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOptionsData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsData : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FAnsiSort;
	TcxPivotGridCalculationBaseType FCalculationBase;
	bool FSaveExpanding;
	bool FSummaryNullIgnore;
	bool FVariationNullIgnore;
	void __fastcall SetAnsiSort(bool AValue);
	void __fastcall SetCalculationBase(TcxPivotGridCalculationBaseType AValue);
	void __fastcall SetSummaryNullIgnore(bool AValue);
	void __fastcall SetVariationNullIgnore(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	int __fastcall CompareAsString(const System::Variant &V1, const System::Variant &V2);
	
public:
	__fastcall virtual TcxPivotGridOptionsData(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AnsiSort = {read=FAnsiSort, write=SetAnsiSort, default=0};
	__property TcxPivotGridCalculationBaseType CalculationBase = {read=FCalculationBase, write=SetCalculationBase, default=0};
	__property bool SaveExpanding = {read=FSaveExpanding, write=FSaveExpanding, default=1};
	__property bool SummaryNullIgnore = {read=FSummaryNullIgnore, write=SetSummaryNullIgnore, default=0};
	__property bool VariationNullIgnore = {read=FVariationNullIgnore, write=SetVariationNullIgnore, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOptionsData(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridPrefilterVisible : unsigned char { pfvNever, pfvNonEmpty, pfvAlways };

class DELPHICLASS TcxPivotGridOptionsPrefilter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsPrefilter : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FCustomizeButton;
	bool FMRUItemsList;
	int FMRUItemsListCount;
	int FMRUItemsListDropDownCount;
	TcxPivotGridPrefilterPosition FPosition;
	TcxPivotGridPrefilterVisible FVisible;
	void __fastcall SetCustomizeButton(bool AValue);
	void __fastcall SetMRUItemsList(bool AValue);
	void __fastcall SetMRUItemsListCount(int AValue);
	void __fastcall SetMRUItemsListDropDownCount(int AValue);
	void __fastcall SetPosition(TcxPivotGridPrefilterPosition AValue);
	void __fastcall SetVisible(TcxPivotGridPrefilterVisible AValue);
	
public:
	__fastcall virtual TcxPivotGridOptionsPrefilter(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CustomizeButton = {read=FCustomizeButton, write=SetCustomizeButton, default=1};
	__property bool MRUItemsList = {read=FMRUItemsList, write=SetMRUItemsList, default=1};
	__property int MRUItemsListCount = {read=FMRUItemsListCount, write=SetMRUItemsListCount, default=10};
	__property int MRUItemsListDropDownCount = {read=FMRUItemsListDropDownCount, write=SetMRUItemsListDropDownCount, default=0};
	__property TcxPivotGridPrefilterPosition Position = {read=FPosition, write=SetPosition, default=1};
	__property TcxPivotGridPrefilterVisible Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOptionsPrefilter(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridOptionsSelectionInclude : unsigned char { osiCrossCells, osiGrandTotalCells, osiTotalCells };

typedef System::Set<TcxPivotGridOptionsSelectionInclude, TcxPivotGridOptionsSelectionInclude::osiCrossCells, TcxPivotGridOptionsSelectionInclude::osiTotalCells>  TcxPivotGridOptionsSelectionIncludes;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsSelection : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FHideFocusRect;
	bool FHideSelection;
	TcxPivotGridOptionsSelectionIncludes FIncludeCells;
	bool FMultiSelect;
	void __fastcall SetHideFocusRect(bool AValue);
	void __fastcall SetHideSelection(bool AValue);
	void __fastcall SetIncludeCells(const TcxPivotGridOptionsSelectionIncludes AValue);
	void __fastcall SetMultiSelect(bool AValue);
	
public:
	__fastcall virtual TcxPivotGridOptionsSelection(TcxCustomPivotGrid* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool HideFocusRect = {read=FHideFocusRect, write=SetHideFocusRect, default=0};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=0};
	__property TcxPivotGridOptionsSelectionIncludes IncludeCells = {read=FIncludeCells, write=SetIncludeCells, default=7};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOptionsSelection(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridCustomizationFormFieldListType : unsigned char { fltAvailable, fltColumn, fltRow, fltFilter, fltData };

class DELPHICLASS TcxPivotGridCustomCustomizationForm;
class PASCALIMPLEMENTATION TcxPivotGridCustomCustomizationForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	Cxclasses::TcxTimer* FHookTimer;
	bool FIsLayoutChanged;
	bool FIsUpdateSelection;
	TcxCustomPivotGrid* FPivotGrid;
	System::TObject* FSelectedObject;
	int __fastcall GetFieldItemHeight(void);
	bool __fastcall GetIsLocked(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	void __fastcall HookTimerHandler(System::TObject* Sender);
	void __fastcall SetPivotGrid(TcxCustomPivotGrid* Value);
	void __fastcall SetSelectedObject(System::TObject* Value);
	
protected:
	int FontHeight;
	void __fastcall CalculateFieldHitTest(TcxPivotGridHitTest* AHitTest, TcxPivotGridField* AField, const System::Types::TRect &ABounds);
	virtual bool __fastcall CanChangeFieldSortOrder(void);
	virtual bool __fastcall CanChangeFieldFilter(void);
	void __fastcall ChangeFieldSorting(TcxPivotGridField* AField);
	void __fastcall CreateControls(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoClose(System::Uitypes::TCloseAction &Action);
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall DoCustomDrawFieldHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall DoUpdateSelection(void);
	virtual System::Uitypes::TColor __fastcall GetCustomizationFormListBackgroundColor(void);
	TcxPivotGridDragDropAreaInfo* __fastcall GetDragDropInfo(void);
	bool __fastcall GetFieldListType(TcxPivotGridField* AField, /* out */ TcxPivotGridCustomizationFormFieldListType &AType);
	virtual System::TObject* __fastcall GetFieldListByType(TcxPivotGridCustomizationFormFieldListType AListType);
	virtual bool __fastcall GetImmediateUpdate(void);
	virtual void __fastcall Init(void);
	virtual void __fastcall LookAndFeelChanged(void);
	void __fastcall PopulateFieldList(System::Classes::TList* AList, TcxPivotGridCustomizationFormFieldListType AType);
	void __fastcall SetDragFieldToController(TcxPivotGridField* AField);
	virtual void __fastcall SetIsLayoutChanged(bool AValue);
	virtual void __fastcall Localize(void);
	virtual void __fastcall UpdateButtonState(void);
	void __fastcall UpdateSelection(void);
	__property bool IsLayoutChanged = {read=FIsLayoutChanged, write=SetIsLayoutChanged, nodefault};
	__property System::TObject* SelectedObject = {read=FSelectedObject, write=SetSelectedObject};
	
public:
	__fastcall virtual ~TcxPivotGridCustomCustomizationForm(void);
	virtual void __fastcall CalculateFormLayout(void);
	virtual void __fastcall RefreshList(void);
	bool __fastcall CalculateHitTest(TcxPivotGridHitTest* AHitTest);
	virtual bool __fastcall CanDrag(_di_IcxPivotGridField AField);
	void __fastcall FieldFilterPopup(TcxPivotGridField* AField, System::Classes::TNotifyEvent AInitPopupEvent = 0x0);
	void __fastcall UpdateHitTest(void);
	__property int FieldItemHeight = {read=GetFieldItemHeight, nodefault};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid, write=SetPivotGrid};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxPivotGridCustomCustomizationForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPivotGridCustomCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridCustomCustomizationForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxPivotGridCustomizationFormClass;

enum TcxPivotGridCustomizationFormStyle : unsigned char { cfsDefault, cfsAdvanced };

class DELPHICLASS TcxPivotGridCustomization;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomization : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	bool FAvailableFieldsSorted;
	TcxPivotGridCustomCustomizationForm* FForm;
	System::Types::TRect FFormBounds;
	TcxPivotGridCustomizationFormStyle FFormStyle;
	Vcl::Controls::TWinControl* FSite;
	TcxPivotGridCustomCustomizationForm* __fastcall Getform(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetAvailableFieldsSorted(bool AValue);
	void __fastcall SetFormStyle(TcxPivotGridCustomizationFormStyle AValue);
	void __fastcall SetSite(Vcl::Controls::TWinControl* AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	TcxPivotGridDragDropAreaInfo* DragDropInfo;
	System::Types::TRect __fastcall CalculateFormBounds(void);
	void __fastcall CalculateFormLayout(void);
	bool __fastcall CanAssignedSite(Vcl::Controls::TWinControl* ASite);
	void __fastcall CustomizationFormNeeded(void);
	virtual void __fastcall CustomizationVisibleChanged(void);
	virtual TcxPivotGridCustomizationFormClass __fastcall GetCustomizationFormClass(void);
	virtual void __fastcall LookAndFeelChanged(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall OnShowCustomization(System::TObject* Sender);
	void __fastcall OnHideCustomization(System::TObject* Sender);
	virtual void __fastcall Refresh(void);
	void __fastcall UpdateCustomization(void);
	
public:
	__fastcall virtual TcxPivotGridCustomization(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridCustomization(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CalculateHitTest(TcxPivotGridHitTest* AHitTest);
	__property TcxPivotGridCustomCustomizationForm* Form = {read=Getform};
	__property System::Types::TRect FormBounds = {read=FFormBounds, write=FFormBounds};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	
__published:
	__property bool AvailableFieldsSorted = {read=FAvailableFieldsSorted, write=SetAvailableFieldsSorted, default=0};
	__property TcxPivotGridCustomizationFormStyle FormStyle = {read=FFormStyle, write=SetFormStyle, default=0};
	__property Vcl::Controls::TWinControl* Site = {read=FSite, write=SetSite};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOptionsDataField;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOptionsDataField : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	TcxPivotGridDataFieldArea FArea;
	int FAreaIndex;
	System::UnicodeString FCaption;
	bool FIsCaptionAssigned;
	bool FMoving;
	TcxPivotGridFieldHeaderCellViewInfo* FViewInfo;
	int FMinWidth;
	int FWidth;
	int __fastcall GetActualWidth(void);
	System::UnicodeString __fastcall GetCaption(void);
	TcxPivotGridDataBuilder* __fastcall GetDataBuilder(void);
	int __fastcall GetHeaderWidth(void);
	void __fastcall SetArea(TcxPivotGridDataFieldArea AValue);
	void __fastcall SetAreaIndex(int AValue);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetWidth(int AValue);
	void __fastcall AssignAreaIndex(TcxPivotGridFieldArea AArea, int AIndex);
	void __fastcall ChangeExpanding(void);
	void __fastcall ChangeSorting(void);
	int __fastcall GetMinWidth(void);
	TcxPivotGridFieldHeaderCellViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetMinWidth(int AValue);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AState);
	void __fastcall SetVisible(bool AValue);
	
protected:
	virtual bool __fastcall CanDrag(void);
	virtual bool __fastcall CanDrop(TcxPivotGridFieldArea Area);
	virtual bool __fastcall CanRemove(void);
	bool __fastcall CanResize(void);
	int __fastcall CheckIndex(int AIndex, TcxPivotGridFields* AFields, TcxPivotGridFieldArea AArea);
	virtual void __fastcall DragDrop(TcxPivotGridFieldArea AArea, int AIndex);
	int __fastcall GetActualAreaIndex(bool AInHeaderArea = true);
	bool __fastcall IsCompatibleWidth(TcxPivotGridDragDropAreaInfo* AInfo);
	bool __fastcall IsSameArea(TcxPivotGridFieldArea AArea);
	void __fastcall SetSizeDelta(int ADelta);
	void __fastcall ValidateAreaIndex(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	__property int ActualWidth = {read=GetActualWidth, nodefault};
	__property TcxPivotGridDataBuilder* DataBuilder = {read=GetDataBuilder};
	__property int HeaderWidth = {read=GetHeaderWidth, nodefault};
	__property TcxPivotGridFieldHeaderCellViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxPivotGridOptionsDataField(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridOptionsDataField(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ApplyBestFit(void);
	
__published:
	__property TcxPivotGridDataFieldArea Area = {read=FArea, write=SetArea, default=0};
	__property int AreaIndex = {read=FAreaIndex, write=SetAreaIndex, default=-1};
	__property bool IsCaptionAssigned = {read=FIsCaptionAssigned, write=FIsCaptionAssigned, default=0};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=FIsCaptionAssigned};
	__property bool Moving = {read=FMoving, write=FMoving, default=1};
	__property int MinWidth = {read=GetMinWidth, write=SetMinWidth, default=20};
	__property int Width = {read=FWidth, write=SetWidth, default=105};
private:
	void *__IcxPivotGridField;	/* IcxPivotGridField */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {61CC4884-4510-4C28-86DC-EC0B984E56DA}
	operator _di_IcxPivotGridField()
	{
		_di_IcxPivotGridField intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridField*(void) { return (IcxPivotGridField*)&__IcxPivotGridField; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {CFCAC754-EC31-4A72-8BED-1D9D2715E062}
	operator _di_IcxPivotGridSizableObject()
	{
		_di_IcxPivotGridSizableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridSizableObject*(void) { return (IcxPivotGridSizableObject*)&__IcxPivotGridField; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxPivotGridField; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomCellViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	void __fastcall SetBitmap(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetTextColor(System::Uitypes::TColor AValue);
	
protected:
	Cxgraphics::TcxBorders FBorders;
	System::Types::TRect FBounds;
	Cxgraphics::TcxCanvas* FCanvas;
	System::Types::TRect FClipRect;
	System::UnicodeString FDisplayText;
	bool FHasClipping;
	bool FIsHotTrack;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	bool FTransparent;
	Cxgraphics::TcxViewParams FViewParams;
	bool FVisible;
	bool FVisibleInfoCalculated;
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall CalculateCellBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	virtual void __fastcall CalculateVisibleInfo(void);
	bool __fastcall CheckClipping(bool ANeedClip);
	virtual void __fastcall CorrectBoundsForPrinting(const System::Types::TRect &ABounds);
	virtual void __fastcall DoDraw(void);
	System::Types::TRect __fastcall ExcludeBorders(const System::Types::TRect &ABounds, Cxgraphics::TcxBorders ABorders);
	virtual bool __fastcall ExcludeFromPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &APoint);
	virtual bool __fastcall SetHotTrack(TcxPivotGridHitTest* AHitTest);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	bool __fastcall HasHintPoint(const System::Types::TPoint &P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	__property Cxgraphics::TcxBorders Borders = {read=FBorders, write=FBorders, nodefault};
	__property System::UnicodeString DisplayText = {read=GetDisplayText, write=FDisplayText};
	__property System::UnicodeString HintText = {read=GetHintText};
	
public:
	__fastcall virtual TcxPivotGridCustomCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
	void __fastcall CheckVisibleInfo(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property Vcl::Graphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property System::Types::TRect ClipRect = {read=FClipRect};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property bool HasClipping = {read=FHasClipping, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, write=SetTextColor, nodefault};
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams, write=FViewParams};
	__property bool Visible = {read=FVisible, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomCellViewInfo(void) { }
	
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}
	operator Dxcustomhint::_di_IcxHintableObject()
	{
		Dxcustomhint::_di_IcxHintableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomhint::IcxHintableObject*(void) { return (Dxcustomhint::IcxHintableObject*)&__IcxHintableObject; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxHintableObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridEditContainerViewInfo;
class PASCALIMPLEMENTATION TcxPivotGridEditContainerViewInfo : public TcxPivotGridCustomCellViewInfo
{
	typedef TcxPivotGridCustomCellViewInfo inherited;
	
private:
	bool FUseLocalViewData;
	bool FUseLocalEditStyle;
	
protected:
	System::Classes::TAlignment FAlignment;
	bool FCalculated;
	Cxedit::TcxCustomEditViewData* FEditViewData;
	Cxedit::TcxCustomEditViewInfo* FEditViewInfo;
	TcxPivotGridField* FDataField;
	Cxedit::TcxEditStyle* FEditStyle;
	bool FMultiLine;
	Cxedit::TcxCustomEditProperties* FProperties;
	bool FShowEndEllipsis;
	System::Types::TRect FTextBounds;
	System::Variant FValue;
	Cxclasses::TcxAlignmentVert FAlignVert;
	void __fastcall InitEditStyle(void);
	void __fastcall CalculateEditViewInfo(Cxedit::TcxCustomEditViewInfo* AEditViewInfo, const System::Types::TPoint &AMousePos);
	virtual void __fastcall CalculateVisibleInfo(void);
	Cxedit::TcxCustomEditViewInfo* __fastcall CreateEditViewInfo(void);
	void __fastcall CreateEditViewData(void);
	void __fastcall DestroyEditViewData(void);
	virtual void __fastcall DrawUsingEditProperties(void);
	void __fastcall InitializeProperties(void);
	virtual bool __fastcall OnGetDisplayTextSupported(void);
	void __fastcall ReleaseEditStyle(void);
	virtual bool __fastcall UseEditProperties(void);
	
public:
	__fastcall virtual TcxPivotGridEditContainerViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
	__fastcall virtual ~TcxPivotGridEditContainerViewInfo(void);
	__property Cxedit::TcxCustomEditProperties* Properties = {read=FProperties};
	__property System::Variant Value = {read=FValue};
};


class DELPHICLASS TcxPivotGridHeaderCellViewInfo;
class DELPHICLASS TcxPivotGridHeaderBackgroundCellViewInfo;
class PASCALIMPLEMENTATION TcxPivotGridHeaderCellViewInfo : public TcxPivotGridEditContainerViewInfo
{
	typedef TcxPivotGridEditContainerViewInfo inherited;
	
private:
	void __fastcall SetData(System::TObject* AValue);
	void __fastcall SetAlignVert(const Cxclasses::TcxAlignmentVert Value);
	
protected:
	TcxPivotGridHeaderBackgroundCellViewInfo* FBackground;
	System::Types::TRect FButtonRect;
	System::Types::TRect FButtonAreaRect;
	System::TObject* FData;
	bool FExpanded;
	System::Classes::TPersistent* FField;
	bool FHasButton;
	Vcl::Imglist::TCustomImageList* FImages;
	System::Classes::TAlignment FImageAlignHorz;
	Cxclasses::TcxAlignmentVert FImageAlignVert;
	int FImageIndex;
	System::Types::TRect FImageRect;
	Cxlookandfeelpainters::TcxNeighbors FNeighbors;
	System::Classes::TPersistent* FSizeField;
	System::Types::TRect FSortMarkBounds;
	Dxcore::TdxSortOrder FSortOrder;
	Cxlookandfeelpainters::TcxButtonState FState;
	virtual void __fastcall CalculateImageInfo(void);
	virtual void __fastcall CalculateSortingInfo(void);
	virtual void __fastcall CalculateVisibleInfo(void);
	virtual bool __fastcall CanDrawBackgroundFirst(void);
	virtual void __fastcall CheckSizingArea(TcxPivotGridHitTest* AHitTest);
	virtual bool __fastcall DrawBackgroundProc(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DoDraw(void);
	void __fastcall DrawHeaderText(void);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	virtual bool __fastcall GetIsLast(void);
	virtual bool __fastcall IsSingle(void);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &APoint);
	virtual void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState Value);
	virtual bool __fastcall UseEditProperties(void);
	__property System::TObject* Data = {read=FData, write=SetData};
	
public:
	__fastcall virtual TcxPivotGridHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams)/* overload */;
	__fastcall TcxPivotGridHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams, const System::UnicodeString ADisplayText)/* overload */;
	bool __fastcall GetHitTestBounds(TcxPivotGridHitTest* AHitTest, const System::Types::TRect &ABounds);
	bool __fastcall IsTotal(void);
	__property System::Classes::TAlignment AlignHorz = {read=FAlignment, write=FAlignment, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=FAlignVert, write=SetAlignVert, nodefault};
	__property TcxPivotGridHeaderBackgroundCellViewInfo* Background = {read=FBackground, write=FBackground};
	__property Borders;
	__property System::Types::TRect ButtonRect = {read=FButtonRect};
	__property DisplayText = {default=0};
	__property bool Expanded = {read=FExpanded, write=FExpanded, nodefault};
	__property System::Classes::TPersistent* Field = {read=FField};
	__property bool HasButton = {read=FHasButton, nodefault};
	__property System::Classes::TAlignment ImageAlignHorz = {read=FImageAlignHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert ImageAlignVert = {read=FImageAlignVert, nodefault};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property bool MultiLine = {read=FMultiLine, write=FMultiLine, nodefault};
	__property Cxlookandfeelpainters::TcxNeighbors Neighbors = {read=FNeighbors, write=FNeighbors, nodefault};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=FShowEndEllipsis, nodefault};
	__property System::Types::TRect SortMarkBounds = {read=FSortMarkBounds};
	__property Dxcore::TdxSortOrder SortOrder = {read=FSortOrder, write=FSortOrder, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
public:
	/* TcxPivotGridEditContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxPivotGridHeaderCellViewInfo(void) { }
	
};


class DELPHICLASS TcxPivotGridFieldGroup;
class PASCALIMPLEMENTATION TcxPivotGridFieldHeaderCellViewInfo : public TcxPivotGridHeaderCellViewInfo
{
	typedef TcxPivotGridHeaderCellViewInfo inherited;
	
private:
	bool __fastcall GetFocused(void);
	
protected:
	TcxPivotGridFieldArea FArea;
	int FAreaIndex;
	bool FFilterActive;
	System::Types::TRect FFilterBounds;
	Cxlookandfeelpainters::TcxButtonState FFilterState;
	bool FFocused;
	TcxPivotGridFieldGroup* FGroup;
	bool FIsFilterButtonAlwaysVisible;
	bool FIsSmartTag;
	void __fastcall CalculateFilterInfo(void);
	virtual void __fastcall CalculateSortingInfo(void);
	virtual bool __fastcall CanDrawBackgroundFirst(void);
	virtual void __fastcall DoDraw(void);
	virtual bool __fastcall ExcludeFromPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	virtual bool __fastcall GetIsLast(void);
	Cxlookandfeelpainters::TcxFilterSmartTagState __fastcall GetSmartTagState(void);
	bool __fastcall IsFilterButtonVisible(void);
	virtual bool __fastcall IsSingle(void);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &APoint);
	virtual void __fastcall SetFilterState(const Cxlookandfeelpainters::TcxButtonState Value);
	virtual bool __fastcall SetHotTrack(TcxPivotGridHitTest* AHitTest);
	virtual void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState Value);
	bool __fastcall SingleOrLeftMostInGroup(void);
	bool __fastcall SingleOrRightMostInGroup(void);
	virtual bool __fastcall UseEditProperties(void);
	
public:
	__fastcall virtual TcxPivotGridFieldHeaderCellViewInfo(System::Classes::TPersistent* AOwner);
	void __fastcall Initialize(Cxgraphics::TcxCanvas* ACanvas, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const Cxgraphics::TcxViewParams &AViewParams);
	int __fastcall MeasureHeight(void);
	int __fastcall MeasureWidth(void);
	void __fastcall SetBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AClipRect);
	void __fastcall PaintTo(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxButtonState AFilterState, Dxcore::TdxSortOrder ASortOrder, const bool AHasBackground = false, TcxPivotGridCustomDrawEvent AHandler = 0x0);
	__property TcxPivotGridFieldArea Area = {read=FArea, nodefault};
	__property int AreaIndex = {read=FAreaIndex, nodefault};
	__property bool FilterActive = {read=FFilterActive, nodefault};
	__property System::Types::TRect FilterBounds = {read=FFilterBounds};
	__property Cxlookandfeelpainters::TcxButtonState FilterState = {read=FFilterState, write=SetFilterState, nodefault};
	__property bool Focused = {read=FFocused, nodefault};
	__property TcxPivotGridFieldGroup* Group = {read=FGroup};
public:
	/* TcxPivotGridHeaderCellViewInfo.Create */ inline __fastcall virtual TcxPivotGridFieldHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams)/* overload */ : TcxPivotGridHeaderCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxPivotGridHeaderCellViewInfo.Create */ inline __fastcall TcxPivotGridFieldHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams, const System::UnicodeString ADisplayText)/* overload */ : TcxPivotGridHeaderCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams, ADisplayText) { }
	
public:
	/* TcxPivotGridEditContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxPivotGridFieldHeaderCellViewInfo(void) { }
	
};


enum TcxPivotGridFocusRectStyle : unsigned char { frsNone, frsDot, frsLine };

enum TcxPivotGridDataCellLimitValueType : unsigned char { lvtColumnMaximum, lvtColumnMinimum, lvtRowMaximum, lvtRowMinimum, lvtMaximum, lvtMinimum };

typedef System::Set<TcxPivotGridDataCellLimitValueType, TcxPivotGridDataCellLimitValueType::lvtColumnMaximum, TcxPivotGridDataCellLimitValueType::lvtMinimum>  TcxPivotGridDataCellLimitValueTypes;

class DELPHICLASS TcxPivotGridDataCellViewInfo;
class PASCALIMPLEMENTATION TcxPivotGridDataCellViewInfo : public TcxPivotGridEditContainerViewInfo
{
	typedef TcxPivotGridEditContainerViewInfo inherited;
	
private:
	int __fastcall GetColumnIndex(void);
	System::UnicodeString __fastcall GetDisplayFormat(void);
	bool __fastcall GetIsGrandTotal(void);
	bool __fastcall GetIsTotal(void);
	TcxPivotGridDataCellLimitValueTypes __fastcall GetLimitValueTypes(void);
	int __fastcall GetRowIndex(void);
	
protected:
	int FBorderColor;
	TcxPivotGridCrossCellSummary* FCellSummary;
	TcxPivotGridViewDataItem* FColumn;
	TcxPivotGridCrossCell* FCrossCell;
	TcxPivotGridFocusRectStyle FFocusRectStyle;
	bool FIsTotal;
	bool FIsTotalAssigned;
	bool FMarkNarrowCells;
	TcxPivotGridViewDataItem* FRow;
	bool FSelected;
	TcxPivotGridSummaryType FSummaryType;
	TcxPivotGridCustomTotal* FTotal;
	virtual void __fastcall CalculateVisibleInfo(void);
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall DrawText(void);
	virtual void __fastcall FormatDisplayValue(void);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &APoint);
	virtual bool __fastcall OnGetDisplayTextSupported(void);
	System::UnicodeString __fastcall ReplaceDigitsByPattern(const System::UnicodeString ADisplayText);
	__property System::UnicodeString DisplayFormat = {read=GetDisplayFormat};
	
public:
	virtual void __fastcall Initialize(TcxPivotGridViewDataItem* ARow, TcxPivotGridViewDataItem* AColumn, TcxPivotGridField* ADataField);
	int __fastcall MeasureWidth(void);
	__property System::Classes::TAlignment Align = {read=FAlignment, write=FAlignment, nodefault};
	__property int BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property Borders;
	__property TcxPivotGridCrossCellSummary* CellSummary = {read=FCellSummary};
	__property TcxPivotGridViewDataItem* Column = {read=FColumn};
	__property int ColumnIndex = {read=GetColumnIndex, nodefault};
	__property TcxPivotGridCrossCell* CrossCell = {read=FCrossCell};
	__property TcxPivotGridField* DataField = {read=FDataField};
	__property DisplayText = {default=0};
	__property TcxPivotGridFocusRectStyle FocusRectStyle = {read=FFocusRectStyle, write=FFocusRectStyle, nodefault};
	__property bool IsGrandTotal = {read=GetIsGrandTotal, nodefault};
	__property bool IsTotal = {read=GetIsTotal, nodefault};
	__property TcxPivotGridDataCellLimitValueTypes LimitValueTypes = {read=GetLimitValueTypes, nodefault};
	__property bool MarkNarrowCells = {read=FMarkNarrowCells, write=FMarkNarrowCells, nodefault};
	__property TcxPivotGridViewDataItem* Row = {read=FRow};
	__property int RowIndex = {read=GetRowIndex, nodefault};
	__property bool Selected = {read=FSelected, nodefault};
	__property TcxPivotGridSummaryType SummaryType = {read=FSummaryType, nodefault};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
	__property TcxPivotGridCustomTotal* Total = {read=FTotal};
public:
	/* TcxPivotGridEditContainerViewInfo.Create */ inline __fastcall virtual TcxPivotGridDataCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxPivotGridEditContainerViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxPivotGridEditContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxPivotGridDataCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxPivotGridDataCellViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridHeaderBackgroundCellViewInfo : public TcxPivotGridCustomCellViewInfo
{
	typedef TcxPivotGridCustomCellViewInfo inherited;
	
protected:
	TcxPivotGridFieldArea FArea;
	Cxgeometry::TcxRect* FFieldHeadersBounds;
	bool FHasFields;
	virtual void __fastcall CorrectBoundsForPrinting(const System::Types::TRect &ABounds);
	virtual void __fastcall DoDraw(void);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	
public:
	__property TcxPivotGridFieldArea Area = {read=FArea, nodefault};
	__property DisplayText = {default=0};
	__property Cxgeometry::TcxRect* FieldHeadersBounds = {read=FFieldHeadersBounds};
	__property bool HasFields = {read=FHasFields, nodefault};
public:
	/* TcxPivotGridCustomCellViewInfo.Create */ inline __fastcall virtual TcxPivotGridHeaderBackgroundCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxPivotGridCustomCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridHeaderBackgroundCellViewInfo(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridPrefilterButtonAlignment : unsigned char { pfbaLeft, pfbaRight };

class DELPHICLASS TcxPivotGridPrefilterPartViewInfo;
class DELPHICLASS TcxPivotGridPrefilterPartsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterPartViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	bool FDroppedDown;
	TcxPivotGridPrefilterPartsViewInfo* FPartsViewInfo;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	TcxPivotGridPrefilter* FPrefilter;
	Cxlookandfeelpainters::TcxButtonState FState;
	
protected:
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual void __fastcall Click(void);
	virtual int __fastcall DoCalculateHeight(void) = 0 ;
	virtual int __fastcall DoCalculateWidth(void) = 0 ;
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual TcxPivotGridPrefilterButtonAlignment __fastcall GetAlignment(void);
	virtual int __fastcall GetPartIndex(void) = 0 ;
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall SetDroppedDown(TcxPivotGridHitTest* AHitTest, bool ADroppedDown);
	virtual bool __fastcall SetHotTrack(TcxPivotGridHitTest* AHitTest);
	virtual bool __fastcall SetPressed(TcxPivotGridHitTest* AHitTest, bool AMouseDown);
	__property TcxPivotGridPrefilterButtonAlignment Alignment = {read=GetAlignment, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
	
public:
	__fastcall virtual TcxPivotGridPrefilterPartViewInfo(TcxPivotGridPrefilterPartsViewInfo* APartsViewInfo);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilterPartViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPivotGridPrefilterPartViewInfoClass;

class DELPHICLASS TcxPivotGridPrefilterCloseButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterCloseButtonViewInfo : public TcxPivotGridPrefilterPartViewInfo
{
	typedef TcxPivotGridPrefilterPartViewInfo inherited;
	
protected:
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual void __fastcall Click(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetPartIndex(void);
public:
	/* TcxPivotGridPrefilterPartViewInfo.Create */ inline __fastcall virtual TcxPivotGridPrefilterCloseButtonViewInfo(TcxPivotGridPrefilterPartsViewInfo* APartsViewInfo) : TcxPivotGridPrefilterPartViewInfo(APartsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilterCloseButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridPrefilterActivateButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterActivateButtonViewInfo : public TcxPivotGridPrefilterPartViewInfo
{
	typedef TcxPivotGridPrefilterPartViewInfo inherited;
	
protected:
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual void __fastcall Click(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetPartIndex(void);
	bool __fastcall GetChecked(void);
public:
	/* TcxPivotGridPrefilterPartViewInfo.Create */ inline __fastcall virtual TcxPivotGridPrefilterActivateButtonViewInfo(TcxPivotGridPrefilterPartsViewInfo* APartsViewInfo) : TcxPivotGridPrefilterPartViewInfo(APartsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilterActivateButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridPrefilterCustomizeButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterCustomizeButtonViewInfo : public TcxPivotGridPrefilterPartViewInfo
{
	typedef TcxPivotGridPrefilterPartViewInfo inherited;
	
private:
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::UnicodeString __fastcall GetText(void);
	int __fastcall GetTextOffset(void);
	
protected:
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual void __fastcall Click(void);
	virtual TcxPivotGridPrefilterButtonAlignment __fastcall GetAlignment(void);
	int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetPartIndex(void);
public:
	/* TcxPivotGridPrefilterPartViewInfo.Create */ inline __fastcall virtual TcxPivotGridPrefilterCustomizeButtonViewInfo(TcxPivotGridPrefilterPartsViewInfo* APartsViewInfo) : TcxPivotGridPrefilterPartViewInfo(APartsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilterCustomizeButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridPrefilterDropDownButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterDropDownButtonViewInfo : public TcxPivotGridPrefilterPartViewInfo
{
	typedef TcxPivotGridPrefilterPartViewInfo inherited;
	
protected:
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxPivotGridPrefilterButtonAlignment __fastcall GetAlignment(void);
	virtual int __fastcall GetPartIndex(void);
	virtual bool __fastcall GetVisible(void);
public:
	/* TcxPivotGridPrefilterPartViewInfo.Create */ inline __fastcall virtual TcxPivotGridPrefilterDropDownButtonViewInfo(TcxPivotGridPrefilterPartsViewInfo* APartsViewInfo) : TcxPivotGridPrefilterPartViewInfo(APartsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilterDropDownButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridPrefilterCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterCaptionViewInfo : public TcxPivotGridPrefilterPartViewInfo
{
	typedef TcxPivotGridPrefilterPartViewInfo inherited;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxPivotGridPrefilterButtonAlignment __fastcall GetAlignment(void);
	virtual int __fastcall GetPartIndex(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall SetDroppedDown(TcxPivotGridHitTest* AHitTest, bool ADroppedDown);
public:
	/* TcxPivotGridPrefilterPartViewInfo.Create */ inline __fastcall virtual TcxPivotGridPrefilterCaptionViewInfo(TcxPivotGridPrefilterPartsViewInfo* APartsViewInfo) : TcxPivotGridPrefilterPartViewInfo(APartsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPrefilterCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterPartsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPivotGridPrefilterPartViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxPivotGridPrefilterCaptionViewInfo* FCaptionViewInfo;
	TcxPivotGridPrefilterDropDownButtonViewInfo* FDropDownButtonViewInfo;
	TcxPivotGridPrefilterViewInfo* FPrefilterViewInfo;
	Cxclasses::TcxObjectList* FItems;
	int __fastcall GetCount(void);
	int __fastcall GetHeight(void);
	TcxPivotGridPrefilterPartViewInfo* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall AddItems(void);
	virtual void __fastcall DestroyItems(void);
	System::Types::TRect __fastcall GetDropDownPartBounds(void);
	void __fastcall SetDroppedDown(TcxPivotGridHitTest* AHitTest, bool ADroppedDown);
	bool __fastcall SetHotTrack(TcxPivotGridHitTest* AHitTest);
	bool __fastcall SetPressed(TcxPivotGridHitTest* AHitTest, bool AMouseDown);
	__property TcxPivotGridPrefilterViewInfo* PrefilterViewInfo = {read=FPrefilterViewInfo};
	
public:
	__fastcall virtual TcxPivotGridPrefilterPartsViewInfo(TcxPivotGridPrefilterViewInfo* APreFilterViewInfo);
	__fastcall virtual ~TcxPivotGridPrefilterPartsViewInfo(void);
	TcxPivotGridPrefilterPartViewInfo* __fastcall AddItem(TcxPivotGridPrefilterPartViewInfoClass AItemClass);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	void __fastcall DrawParts(void);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	__property int Count = {read=GetCount, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property TcxPivotGridPrefilterPartViewInfo* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPrefilterViewInfo : public TcxPivotGridCustomCellViewInfo
{
	typedef TcxPivotGridCustomCellViewInfo inherited;
	
private:
	TcxPivotGridPrefilterPartsViewInfo* FPartsViewInfo;
	TcxPivotGridPrefilter* FPrefilter;
	void __fastcall DrawBackground(void);
	
protected:
	virtual void __fastcall CalculateVisibleInfo(void);
	virtual void __fastcall CorrectBoundsForPrinting(const System::Types::TRect &ABounds);
	virtual void __fastcall DoDraw(void);
	int __fastcall GetHeight(void);
	virtual bool __fastcall GetHitTest(TcxPivotGridHitTest* AHitTest);
	int __fastcall GetTextWidth(void);
	System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	void __fastcall SetDroppedDown(TcxPivotGridHitTest* AHitTest, bool ADroppedDown);
	virtual bool __fastcall SetHotTrack(TcxPivotGridHitTest* AHitTest);
	bool __fastcall SetPressed(TcxPivotGridHitTest* AHitTest, bool AMouseDown);
	
public:
	__fastcall TcxPivotGridPrefilterViewInfo(TcxPivotGridPrefilter* APrefilter, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams)/* overload */;
	__fastcall virtual ~TcxPivotGridPrefilterViewInfo(void);
	__property DisplayText = {default=0};
	__property TcxPivotGridPrefilter* Prefilter = {read=FPrefilter};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridFilterSeparatorCellViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFilterSeparatorCellViewInfo : public TcxPivotGridCustomCellViewInfo
{
	typedef TcxPivotGridCustomCellViewInfo inherited;
	
private:
	int FIndentSize;
	
protected:
	virtual void __fastcall DoDraw(void);
	
public:
	__fastcall virtual TcxPivotGridFilterSeparatorCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
	__property int IndentSize = {read=FIndentSize, write=FIndentSize, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridFilterSeparatorCellViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridViewInfo;
class DELPHICLASS TcxPivotGridStyles;
__interface IcxPivotGridBaseStyles;
typedef System::DelphiInterface<IcxPivotGridBaseStyles> _di_IcxPivotGridBaseStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	Cxgraphics::TcxCanvas* FCanvas;
	TcxPivotGridCells* FColumnHeaders;
	TcxPivotGridCells* FCommonCells;
	TcxPivotGridCells* FDataCells;
	TcxPivotGridCells* FFieldHeaders;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	TcxCustomPivotGrid* FPivotGrid;
	TcxPivotGridPrefilter* FPrefilter;
	TcxPivotGridCells* FRowHeaders;
	int __fastcall GetColumnFieldsCount(void);
	TcxPivotGridDataBuilder* __fastcall GetDataBuilder(void);
	System::Types::TPoint __fastcall GetFocusedCell(void);
	System::Types::TSize __fastcall GetIconsSize(void);
	TcxPivotGridOptionsDataField* __fastcall GetOptionsDataField(void);
	TcxPivotGridOptionsView* __fastcall GetOptionsView(void);
	int __fastcall GetRowFieldsCount(void);
	TcxPivotGridStyles* __fastcall GetStyles(void);
	TcxPivotGridViewData* __fastcall GetViewData(void);
	
protected:
	_di_IcxPivotGridBaseStyles FBaseStyles;
	System::Types::TRect FCellsBounds;
	TcxPivotGridViewDataItem* FColStart;
	System::Types::TRect FColumnBounds;
	int FColumnHeadersHeight;
	TcxPivotList* FColumnItems;
	int FColumnRowCount;
	System::Types::TRect FDataCellsBounds;
	int FDataFieldsWidth;
	Cxclasses::TcxObjectList* FDragDropAreas;
	bool FDrawBorders;
	bool FDrawExpandButtons;
	int FFieldHeaderHeight;
	Cxgeometry::TcxRect* FFieldHeadersBounds;
	int FFilterHeight;
	int FHeaderHeight;
	bool FIsPrinting;
	bool FNeedCorrectHeaders;
	TcxPivotList* FRowColumnPos;
	int FRowHeadersHeight;
	int FRowHeadersWidth;
	TcxPivotList* FRowItems;
	System::Types::TRect FRowsBounds;
	Cxgraphics::TcxViewParams FViewParams;
	TcxPivotGridDragDropAreaInfo* __fastcall AddDragDropAreaInfo(int APos, const System::Types::TRect &ABounds, const System::Types::TRect &ADisplayBounds, TcxPivotGridFieldArea AArea, int AAreaIndex, System::Classes::TPersistent* AField);
	TcxPivotGridFieldHeaderCellViewInfo* __fastcall AddFieldHeader(const System::Types::TRect &ABounds, TcxPivotGridField* AField, TcxPivotGridFieldArea AArea, int AAreaIndex);
	TcxPivotGridHeaderBackgroundCellViewInfo* __fastcall AddFieldsBackground(const System::Types::TRect &ABounds, const System::UnicodeString ADescription, bool AHasDescription, TcxPivotGridFieldArea AArea);
	TcxPivotGridFilterSeparatorCellViewInfo* __fastcall AddFilterSeparator(const int ATop);
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	TcxPivotGridField* __fastcall GetDataFieldFromViewData(TcxPivotGridViewDataItem* AItem);
	Vcl::Graphics::TFont* __fastcall GetFont(int AStyleIndex);
	int __fastcall GetRowColumnPos(int ALevel, System::Classes::TPersistent* &ALevelField);
	TcxPivotGridField* __fastcall GetRowField(int AIndex);
	virtual int __fastcall GetStartColumnIndex(void);
	virtual int __fastcall GetStartRowIndex(void);
	bool __fastcall GroupHeaderOutOfBounds(TcxPivotGridField* AField, int ARight);
	void __fastcall CalculateCells(void);
	void __fastcall CalculateFieldsLayout(void);
	void __fastcall CalculateFilterLayout(void);
	virtual void __fastcall CheckCellSelection(TcxPivotGridDataCellViewInfo* ACell);
	void __fastcall CorrectBackground(void);
	virtual void __fastcall DoCalculate(void);
	virtual System::UnicodeString __fastcall GetHeaderDisplayText(TcxPivotGridHeaderCellViewInfo* ACell, TcxPivotGridViewDataItem* AItem);
	TcxPivotGridCustomCellViewInfo* __fastcall AddPartBackground(const System::Types::TRect &ABounds);
	TcxPivotGridHeaderCellViewInfo* __fastcall AddColumnItem(const System::Types::TRect &ABounds, TcxPivotGridViewDataItem* AItem);
	TcxPivotGridDataCellViewInfo* __fastcall AddDataCell(TcxPivotGridViewDataItem* ARow, TcxPivotGridViewDataItem* AColumn, int ALeft, int ATop);
	TcxPivotGridHeaderCellViewInfo* __fastcall AddRowItem(const System::Types::TRect &ABounds, TcxPivotGridViewDataItem* AItem, System::Classes::TPersistent* ASizeField);
	TcxPivotGridHeaderCellViewInfo* __fastcall AddRowGroupItem(const System::Types::TRect &ABounds, TcxPivotGridViewDataItem* AItem, System::Classes::TPersistent* ASizeField);
	void __fastcall InitCellViewParams(TcxPivotGridDataCellViewInfo* ACell);
	virtual void __fastcall InitializeFields(void);
	void __fastcall InitializeFieldsPosition(TcxPivotGridFields* AFields, TcxPivotGridFieldArea AArea);
	void __fastcall InitHeaderCell(TcxPivotGridHeaderCellViewInfo* ACell, TcxPivotGridViewDataItem* AItem);
	bool __fastcall IsDataFieldVisible(TcxPivotGridDataFieldAreas AArea = TcxPivotGridDataFieldAreas() );
	void __fastcall CalculateRows(void);
	virtual void __fastcall CreateRows(TcxPivotList* ARows);
	void __fastcall CreateColumns(TcxPivotList* AColumns);
	void __fastcall CalculateColumns(void);
	void __fastcall CalculateColumnsFields(void);
	void __fastcall CalculateDataItemsFields(void);
	void __fastcall CalculateRowsFields(void);
	virtual void __fastcall CreateDragDropAreaInfo(const System::Types::TRect &AAreaBounds, int AStartIndex, TcxPivotGridFieldArea AArea);
	bool __fastcall IsGroupItemExist(System::Classes::TList* AList, TcxPivotGridViewDataItem* AItem);
	int __fastcall PrepareViewDataItems(TcxPivotList* &AList, TcxPivotGridViewDataItem* AStartItem, int AAvailableSize, int &AStartIndex);
	int __fastcall SpaceBetween(TcxPivotGridViewDataItem* AItem1, TcxPivotGridViewDataItem* AItem2, System::Classes::TList* AList);
	
public:
	__fastcall virtual TcxPivotGridViewInfo(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateHitTest(TcxPivotGridHitTest* AHitTest);
	void __fastcall Clear(void);
	void __fastcall InvalidateRect(const System::Types::TRect &ARect);
	void __fastcall SelectionChanged(void);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property _di_IcxPivotGridBaseStyles BaseStyles = {read=FBaseStyles};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TcxPivotGridCells* CommonCells = {read=FCommonCells};
	__property int ColumnFieldsCount = {read=GetColumnFieldsCount, nodefault};
	__property System::Types::TRect ColumnsBounds = {read=FColumnBounds};
	__property TcxPivotGridCells* ColumnHeaders = {read=FColumnHeaders};
	__property int ColumnHeadersHeight = {read=FColumnHeadersHeight, nodefault};
	__property TcxPivotGridDataBuilder* DataBuilder = {read=GetDataBuilder};
	__property TcxPivotGridCells* DataCells = {read=FDataCells};
	__property System::Types::TRect DataCellsBounds = {read=FDataCellsBounds};
	__property bool DrawBorders = {read=FDrawBorders, write=FDrawBorders, nodefault};
	__property bool DrawExpandButtons = {read=FDrawExpandButtons, write=FDrawExpandButtons, nodefault};
	__property int FieldHeaderHeight = {read=FFieldHeaderHeight, nodefault};
	__property TcxPivotGridCells* FieldHeaders = {read=FFieldHeaders};
	__property int FilterHeight = {read=FFilterHeight, nodefault};
	__property System::Types::TPoint FocusedCell = {read=GetFocusedCell};
	__property int HeaderHeight = {read=FHeaderHeight, nodefault};
	__property bool IsPrinting = {read=FIsPrinting, nodefault};
	__property TcxPivotGridOptionsDataField* OptionsDataField = {read=GetOptionsDataField};
	__property TcxPivotGridOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
	__property TcxPivotGridPrefilter* Prefilter = {read=FPrefilter};
	__property int RowFieldsCount = {read=GetRowFieldsCount, nodefault};
	__property TcxPivotGridCells* RowHeaders = {read=FRowHeaders};
	__property int RowHeadersWidth = {read=FRowHeadersWidth, nodefault};
	__property System::Types::TRect RowsBounds = {read=FRowsBounds};
	__property int StartColumnIndex = {read=GetStartColumnIndex, nodefault};
	__property int StartRowIndex = {read=GetStartRowIndex, nodefault};
	__property TcxPivotGridStyles* Styles = {read=GetStyles};
	__property TcxPivotGridViewData* ViewData = {read=GetViewData};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxCustomPivotGrid* FPivotGrid;
	TcxPivotGridViewInfo* FViewInfo;
	
protected:
	virtual void __fastcall DoPaint(void);
	void __fastcall DoCustomDrawFieldHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	void __fastcall DoCustomDrawColumnHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	void __fastcall DoCustomDrawPart(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	void __fastcall DoCustomDrawRowHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	void __fastcall DoCustomDrawDataCell(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	
public:
	__fastcall virtual TcxPivotGridPainter(TcxCustomPivotGrid* AOwner);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
	__property TcxPivotGridViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridPainter(void) { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{60482E74-4425-4CF0-86A3-818C486E895F}") IcxPivotGridBaseStyles  : public System::IInterface 
{
	
public:
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnHeaderParams(TcxPivotGridViewDataItem* AColumn) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxPivotGridDataCellViewInfo* ACell) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetFieldHeaderParams(TcxPivotGridField* AField) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetHeaderBackgroundParams(TcxPivotGridFieldArea AArea) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetPrefilterParams(void) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetRowHeaderParams(TcxPivotGridViewDataItem* ARow) = 0 ;
};

typedef void __fastcall (__closure *TcxPivotGridGetContentStyleEvent)(TcxCustomPivotGrid* Sender, TcxPivotGridDataCellViewInfo* ACell, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxPivotGridGetHeaderItemStyleEvent)(TcxCustomPivotGrid* Sender, TcxPivotGridViewDataItem* AItem, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxPivotGridGetFieldHeaderStyleEvent)(TcxCustomPivotGrid* Sender, TcxPivotGridField* AField, Cxstyles::TcxStyle* &AStyle);

class DELPHICLASS TcxPivotGridCustomStyles;
class PASCALIMPLEMENTATION TcxPivotGridCustomStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	bool FSuppressContentColoration;
	bool FSuppressBackgroundBitmaps;
	TcxPivotGridGetHeaderItemStyleEvent FOnGetColumnHeaderStyle;
	TcxPivotGridGetContentStyleEvent FOnGetContentStyle;
	TcxPivotGridGetFieldHeaderStyleEvent FOnGetFieldHeaderStyle;
	TcxPivotGridGetHeaderItemStyleEvent FOnGetRowHeaderStyle;
	
protected:
	virtual void __fastcall Changed(int AIndex);
	void __fastcall CheckViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetContentStyleIndexByCell(TcxPivotGridDataCellViewInfo* ACell);
	virtual void __fastcall GetDefaultHeadersAreaViewParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	__property bool SuppressContentColoration = {read=FSuppressContentColoration, write=FSuppressContentColoration, nodefault};
	__property bool SuppressBackgroundBitmaps = {read=FSuppressBackgroundBitmaps, write=FSuppressBackgroundBitmaps, nodefault};
	__property Cxstyles::TcxStyle* Background = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* ColumnHeader = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* ColumnHeaderArea = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* ColumnMaximumValue = {read=GetValue, write=SetValue, index=15};
	__property Cxstyles::TcxStyle* ColumnMinimumValue = {read=GetValue, write=SetValue, index=16};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* DataHeaderArea = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* FieldHeader = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* FilterHeaderArea = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* FilterSeparator = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* HeaderBackground = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* Inactive = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* MaximumValue = {read=GetValue, write=SetValue, index=17};
	__property Cxstyles::TcxStyle* MinimumValue = {read=GetValue, write=SetValue, index=18};
	__property Cxstyles::TcxStyle* Prefilter = {read=GetValue, write=SetValue, index=14};
	__property Cxstyles::TcxStyle* RowHeader = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* RowHeaderArea = {read=GetValue, write=SetValue, index=11};
	__property Cxstyles::TcxStyle* RowMaximumValue = {read=GetValue, write=SetValue, index=19};
	__property Cxstyles::TcxStyle* RowMinimumValue = {read=GetValue, write=SetValue, index=20};
	__property Cxstyles::TcxStyle* Selected = {read=GetValue, write=SetValue, index=12};
	__property Cxstyles::TcxStyle* Total = {read=GetValue, write=SetValue, index=13};
	__property TcxPivotGridGetHeaderItemStyleEvent OnGetColumnHeaderStyle = {read=FOnGetColumnHeaderStyle, write=FOnGetColumnHeaderStyle};
	__property TcxPivotGridGetContentStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=FOnGetContentStyle};
	__property TcxPivotGridGetFieldHeaderStyleEvent OnGetFieldHeaderStyle = {read=FOnGetFieldHeaderStyle, write=FOnGetFieldHeaderStyle};
	__property TcxPivotGridGetHeaderItemStyleEvent OnGetRowHeaderStyle = {read=FOnGetRowHeaderStyle, write=FOnGetRowHeaderStyle};
	
public:
	__fastcall virtual TcxPivotGridCustomStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Cxgraphics::TcxViewParams __fastcall GetBackgroundParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnHeaderParams(TcxPivotGridViewDataItem* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnMaximumValueParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnMinimumValueParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxPivotGridDataCellViewInfo* ACell);
	virtual Cxgraphics::TcxViewParams __fastcall GetFieldHeaderParams(TcxPivotGridField* AField);
	virtual Cxgraphics::TcxViewParams __fastcall GetFilterSeparatorParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetHeaderBackgroundParams(TcxPivotGridFieldArea AArea);
	virtual Cxgraphics::TcxViewParams __fastcall GetMaximumValueParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetMinimumValueParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetPrefilterParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetRowHeaderParams(TcxPivotGridViewDataItem* ARow);
	virtual Cxgraphics::TcxViewParams __fastcall GetRowMaximumValueParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetRowMinimumValueParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetSelectionParams(void);
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomStyles(void) { }
	
private:
	void *__IcxPivotGridBaseStyles;	/* IcxPivotGridBaseStyles */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {60482E74-4425-4CF0-86A3-818C486E895F}
	operator _di_IcxPivotGridBaseStyles()
	{
		_di_IcxPivotGridBaseStyles intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridBaseStyles*(void) { return (IcxPivotGridBaseStyles*)&__IcxPivotGridBaseStyles; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxPivotGridStyles : public TcxPivotGridCustomStyles
{
	typedef TcxPivotGridCustomStyles inherited;
	
public:
	virtual Cxgraphics::TcxViewParams __fastcall GetColumnHeaderParams(TcxPivotGridViewDataItem* AColumn);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxPivotGridDataCellViewInfo* ACell);
	virtual Cxgraphics::TcxViewParams __fastcall GetRowHeaderParams(TcxPivotGridViewDataItem* ARow);
	
__published:
	__property Background;
	__property ColumnHeader;
	__property ColumnHeaderArea;
	__property ColumnMaximumValue;
	__property ColumnMinimumValue;
	__property Content;
	__property DataHeaderArea;
	__property FieldHeader;
	__property FilterHeaderArea;
	__property FilterSeparator;
	__property HeaderBackground;
	__property Inactive;
	__property MaximumValue;
	__property MinimumValue;
	__property Prefilter;
	__property RowHeader;
	__property RowHeaderArea;
	__property RowMaximumValue;
	__property RowMinimumValue;
	__property Selected;
	__property StyleSheet;
	__property Total;
	__property OnGetColumnHeaderStyle;
	__property OnGetContentStyle;
	__property OnGetFieldHeaderStyle;
	__property OnGetRowHeaderStyle;
public:
	/* TcxPivotGridCustomStyles.Create */ inline __fastcall virtual TcxPivotGridStyles(System::Classes::TPersistent* AOwner) : TcxPivotGridCustomStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxPivotGridStyles(void) { }
	
};


class DELPHICLASS TcxPivotGridFieldStyles;
class PASCALIMPLEMENTATION TcxPivotGridFieldStyles : public TcxPivotGridCustomStyles
{
	typedef TcxPivotGridCustomStyles inherited;
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	
__published:
	__property ColumnHeader;
	__property ColumnMaximumValue;
	__property ColumnMinimumValue;
	__property Content;
	__property MaximumValue;
	__property MinimumValue;
	__property RowHeader;
	__property RowMaximumValue;
	__property RowMinimumValue;
	__property Total;
	__property OnGetColumnHeaderStyle;
	__property OnGetContentStyle;
	__property OnGetRowHeaderStyle;
public:
	/* TcxPivotGridCustomStyles.Create */ inline __fastcall virtual TcxPivotGridFieldStyles(System::Classes::TPersistent* AOwner) : TcxPivotGridCustomStyles(AOwner) { }
	
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxPivotGridFieldStyles(void) { }
	
};


class DELPHICLASS TcxPivotGridStyleSheet;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxPivotGridStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxPivotGridStyles* AValue);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxPivotGridStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxPivotGridStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxPivotGridStyleSheet(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridDataController;
class PASCALIMPLEMENTATION TcxPivotGridDataController : public Cxcustomdata::TcxCustomDataController
{
	typedef Cxcustomdata::TcxCustomDataController inherited;
	
private:
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	
protected:
	virtual void __fastcall FilterChanged(void);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	
public:
	virtual System::UnicodeString __fastcall GetFilterItemFieldCaption(System::TObject* AItem);
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
public:
	/* TcxCustomDataController.Create */ inline __fastcall virtual TcxPivotGridDataController(System::Classes::TComponent* AOwner) : Cxcustomdata::TcxCustomDataController(AOwner) { }
	/* TcxCustomDataController.Destroy */ inline __fastcall virtual ~TcxPivotGridDataController(void) { }
	
};


enum TcxPivotGridOLAPFieldType : unsigned char { oftDimension, oftMeasure, oftKPI, oftSet };

enum TcxOLAPKPIType : unsigned char { oktValue, oktGoal, oktStatus, oktTrend, oktWeight };

enum TcxPivotGridOLAPKPIGraphicType : unsigned char { gtNone, gtServerDefined, gtShapes, gtTrafficLights, gtRoadSigns, gtGauge, gtReversedGauge, gtThermometer, gtReversedThermometer, gtCylinder, gtReversedCylinder, gtFaces, gtVarianceArrow, gtStandardArrow, gtStatusArrow, gtReversedStatusArrow };

typedef void __fastcall (__closure *TcxPivotGridInitializeFieldEvent)(TcxPivotGridCustomOLAPDataSource* Sender, TcxPivotGridField* AField);

enum TcxOLAPStructureNodeType : unsigned char { ntCube, ntMeasure, ntKPI, ntDimension, ntSet, ntFolder, ntGroup, ntField };

typedef System::Set<TcxOLAPStructureNodeType, TcxOLAPStructureNodeType::ntCube, TcxOLAPStructureNodeType::ntField>  TcxOLAPStructureNodeTypes;

class DELPHICLASS TcxPivotGridOLAPStructureNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOLAPStructureNode : public Dxcustomtree::TdxTreeCustomNode
{
	typedef Dxcustomtree::TdxTreeCustomNode inherited;
	
private:
	int FCardinality;
	bool FCurrency;
	int FDBType;
	System::UnicodeString FDimensionUniqueName;
	System::UnicodeString FDisplayText;
	System::UnicodeString FHierarchyUniqueName;
	TcxPivotGridOLAPKPIGraphicType FKPIGraphicType;
	System::UnicodeString FKPIName;
	TcxOLAPKPIType FKPIType;
	int FLevelNumber;
	System::UnicodeString FLevelUniqueName;
	System::Classes::TList* FLinkedFields;
	TcxOLAPStructureNodeType FNodeType;
	int FStructureType;
	System::UnicodeString FUniqueName;
	TcxOLAPStructureNodeTypes __fastcall GetAggregateType(void);
	bool __fastcall GetIsKPI(void);
	TcxPivotGridOLAPStructureNode* __fastcall GetParent(void);
	void __fastcall SetNodeType(TcxOLAPStructureNodeType AValue);
	
protected:
	virtual int __fastcall GetImageIndex(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TcxPivotGridOLAPStructureNode(Dxcustomtree::_di_IdxTreeOwner AOwner);
	__fastcall virtual ~TcxPivotGridOLAPStructureNode(void);
	void __fastcall AddFieldLink(TcxPivotGridField* AField);
	TcxPivotGridField* __fastcall GetLinkedField(TcxCustomPivotGrid* APivotGrid);
	TcxPivotGridOLAPStructureNode* __fastcall ItemByDisplayText(const System::UnicodeString ADisplayText);
	void __fastcall RemoveFieldLink(TcxPivotGridField* AField);
	__property TcxOLAPStructureNodeTypes AggregateType = {read=GetAggregateType, nodefault};
	__property int Cardinality = {read=FCardinality, write=FCardinality, nodefault};
	__property bool Currency = {read=FCurrency, write=FCurrency, nodefault};
	__property int DBType = {read=FDBType, write=FDBType, nodefault};
	__property System::UnicodeString DimensionUniqueName = {read=FDimensionUniqueName, write=FDimensionUniqueName};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=FDisplayText};
	__property System::UnicodeString HierarchyUniqueName = {read=FHierarchyUniqueName, write=FHierarchyUniqueName};
	__property bool IsKPI = {read=GetIsKPI, nodefault};
	__property TcxPivotGridOLAPKPIGraphicType KPIGraphicType = {read=FKPIGraphicType, write=FKPIGraphicType, nodefault};
	__property System::UnicodeString KPIName = {read=FKPIName, write=FKPIName};
	__property TcxOLAPKPIType KPIType = {read=FKPIType, write=FKPIType, nodefault};
	__property int LevelNumber = {read=FLevelNumber, write=FLevelNumber, nodefault};
	__property System::UnicodeString LevelUniqueName = {read=FLevelUniqueName, write=FLevelUniqueName};
	__property TcxOLAPStructureNodeType NodeType = {read=FNodeType, write=SetNodeType, nodefault};
	__property TcxPivotGridOLAPStructureNode* Parent = {read=GetParent};
	__property int StructureType = {read=FStructureType, write=FStructureType, nodefault};
	__property System::UnicodeString UniqueName = {read=FUniqueName, write=FUniqueName};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridOLAPField;
class DELPHICLASS TcxPivotGridFieldFilter;
class PASCALIMPLEMENTATION TcxPivotGridCustomOLAPDataSource : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	Cxclasses::TcxObjectList* FFields;
	Cxclasses::TcxObjectList* FGroups;
	System::Classes::TList* FListeners;
	TcxCustomPivotGrid* FPivotGrid;
	TcxPivotGridOLAPStructureNode* FStructure;
	bool FStructureWasChanged;
	TcxPivotGridInitializeFieldEvent FOnInitializeField;
	int __fastcall GetListenerCount(void);
	TcxCustomPivotGrid* __fastcall GetListener(int AIndex);
	void __fastcall SetActive(bool AValue);
	
protected:
	void __fastcall AddListener(TcxCustomPivotGrid* AListener);
	virtual void __fastcall Changed(void);
	TcxPivotGridOLAPField* __fastcall CreateNewField(TcxPivotGridOLAPStructureNode* AStructure);
	void __fastcall CreateFieldsFromStructure(void);
	virtual void __fastcall CreateStructure(void);
	void __fastcall CreateStructureRoot(void);
	virtual TcxPivotGridCrossCellDataSource* __fastcall CreateDrillDownDataSource(TcxPivotGridCrossCell* ACell, Cxclasses::TcxObjectList* FieldList, int ASummaryIndex)/* overload */;
	virtual TcxPivotGridCrossCellDataSource* __fastcall CreateDrillDownDataSource(System::Classes::TList* ACells, Cxclasses::TcxObjectList* FieldList, int ASummaryIndex)/* overload */;
	virtual void __fastcall CreateMembers(TcxPivotGridField* AField, TcxPivotGridGroupItem* AParent, bool AHasChildren, TcxPivotGridFields* ADataFields);
	System::Classes::TList* __fastcall CreateMembersFromGroup(TcxPivotGridGroupItem* AItem, bool AIncludeParent = true, bool ACheckExpanding = false);
	virtual void __fastcall CreateRootLayout(TcxCustomPivotGrid* APivotGrid, TcxPivotGridFields* ARowFields, TcxPivotGridFields* AColumnFields, TcxPivotGridFields* ADataFields, TcxPivotGridFields* AFilterFields);
	virtual void __fastcall DoInitializeField(TcxPivotGridField* AField);
	void __fastcall ExpandMember(TcxPivotGridField* AField, TcxPivotGridGroupItem* AMember, bool AExpandChildren);
	virtual TcxPivotGridFieldClass __fastcall GetFieldClass(void);
	TcxPivotGridOLAPField* __fastcall GetFieldForStructure(TcxPivotGridFieldGroup* AGroup, TcxPivotGridOLAPStructureNode* AStructure);
	TcxPivotGridFieldGroup* __fastcall GetGroupForStructure(TcxPivotGridOLAPStructureNode* AStructure);
	virtual bool __fastcall GetIsActive(void);
	virtual bool __fastcall GetIsTerminated(void);
	TcxPivotGridOLAPField* __fastcall GetLinkByUniqueName(const System::WideString AName);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeCrossCells(TcxPivotGridGroupItem* ARowsGroup, TcxPivotGridGroupItem* AColumnsGroup, TcxPivotGridFields* ADataFields, TcxPivotGridOLAPFieldType AOLAPType);
	void __fastcall InitializeCrossCellKPIValue(TcxPivotGridCrossCell* ACell, int ADataFieldIndex, const System::Variant &AFormattedValue, const System::Variant &ANativeValue);
	void __fastcall InitializeCrossCellValues(TcxPivotGridCrossCell* ACell, const System::Variant &AFormattedValues, const System::Variant &ANativeValues, bool IsInitialized);
	virtual void __fastcall InitializeExpanding(TcxPivotGridDataBuilder* ADataBuilder, TcxPivotGridField* AField, TcxPivotGridGroupItem* AnExpandingItem, TcxPivotGridGroupItem* ACrossGroup, TcxPivotGridFields* ADataFields);
	virtual void __fastcall InitializeLayoutKPI(TcxPivotGridFields* ARowFields, TcxPivotGridFields* AColumnFields, TcxPivotGridFields* ADataFields, TcxPivotGridFields* AFilterFields, TcxPivotGridGroupItem* ARowsGroup, TcxPivotGridGroupItem* AColumnsGroup);
	virtual void __fastcall CreateLayoutTotals(TcxPivotGridGroupItem* AColumns, TcxPivotGridGroupItem* ARows, TcxPivotGridFields* ASummaryFields, System::Classes::TList* AnExpandedMembers);
	virtual void __fastcall InitializeStructureMembers(TcxPivotGridOLAPField* AField, TcxPivotGridVariantList* AList);
	virtual void __fastcall InitializeTotal(TcxPivotGridFields* ADataFields, TcxPivotGridFields* AFilterFields, TcxPivotGridGroupItem* AColumns, TcxPivotGridGroupItem* ARows);
	void __fastcall NotifyListeners(void);
	virtual void __fastcall PopulateFilteredUniqueNames(TcxPivotGridOLAPField* AField, TcxPivotGridFieldFilter* AFilter, System::Classes::TStringList* &AUniqueValues);
	virtual void __fastcall PopulateFilteredValues(TcxPivotGridOLAPField* AField, TcxPivotGridFieldFilter* AFilter, System::Classes::TStrings* AValues, System::Classes::TStringList* AUniqueValues);
	void __fastcall ProcessMembersForExpanding(TcxPivotGridField* AField, TcxPivotGridGroupItem* AMember, bool AExpandChildren);
	void __fastcall RemoveListener(TcxCustomPivotGrid* AListener);
	virtual void __fastcall QueryLayout(TcxPivotGridFields* ARowFields, TcxPivotGridFields* AColumnFields, TcxPivotGridFields* ADataFields, TcxPivotGridFields* AFilterFields);
	virtual void __fastcall QueryLayoutTotals(TcxPivotGridFields* AColumnFields, TcxPivotGridFields* ARowFields, TcxPivotGridFields* ADataFields, TcxPivotGridFields* AFilterFields, System::Classes::TList* AnExpandedMembers);
	virtual void __fastcall QueryRootMembers(TcxPivotGridField* ARowField, System::Classes::TList* AParentMembers, TcxPivotGridFields* AFilters, TcxPivotGridFields* ADataFields);
	void __fastcall StoreFieldsInformation(void);
	void __fastcall BeginUpdate(void);
	virtual bool __fastcall CanCollapse(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual bool __fastcall CanExpand(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual void __fastcall Collapsed(Dxcustomtree::TdxTreeCustomNode* ASender);
	void __fastcall EndUpdate(void);
	virtual void __fastcall Expanded(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual void __fastcall LoadChildren(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual void __fastcall BeforeDelete(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual void __fastcall DeleteNode(Dxcustomtree::TdxTreeCustomNode* ASender);
	System::Classes::TPersistent* __fastcall OLAPStructureGetOwner(void);
	Dxcustomtree::TdxTreeCustomNodeClass __fastcall GetNodeClass(Dxcustomtree::TdxTreeCustomNode* ARelativeNode);
	virtual void __fastcall TreeNotification(Dxcustomtree::TdxTreeCustomNode* ASender, Dxcustomtree::TdxTreeNodeNotifications ANotification);
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool IsActive = {read=GetIsActive, nodefault};
	__property bool IsTerminated = {read=GetIsTerminated, nodefault};
	__property int ListenerCount = {read=GetListenerCount, nodefault};
	__property TcxCustomPivotGrid* Listeners[int Index] = {read=GetListener};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid, write=FPivotGrid};
	__property bool StructureWasChanged = {read=FStructureWasChanged, write=FStructureWasChanged, nodefault};
	__property TcxPivotGridInitializeFieldEvent OnInitializeField = {read=FOnInitializeField, write=FOnInitializeField};
	
public:
	__fastcall virtual TcxPivotGridCustomOLAPDataSource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridCustomOLAPDataSource(void);
	void __fastcall RetrieveFields(TcxCustomPivotGrid* APivotGrid);
	__property TcxPivotGridOLAPStructureNode* Structure = {read=FStructure};
private:
	void *__IdxTreeOwner;	/* Dxcustomtree::IdxTreeOwner */
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E5BD359F-E1D0-4ABC-9D9D-45A6516F2F8B}
	operator Dxcustomtree::_di_IdxTreeOwner()
	{
		Dxcustomtree::_di_IdxTreeOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcustomtree::IdxTreeOwner*(void) { return (Dxcustomtree::IdxTreeOwner*)&__IdxTreeOwner; }
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


class DELPHICLASS TcxPivotGridKPICellViewInfo;
class PASCALIMPLEMENTATION TcxPivotGridKPICellViewInfo : public TcxPivotGridDataCellViewInfo
{
	typedef TcxPivotGridDataCellViewInfo inherited;
	
private:
	TcxPivotGridOLAPKPIGraphicType FGraphicType;
	
protected:
	virtual void __fastcall DrawText(void);
	virtual void __fastcall FormatDisplayValue(void);
	virtual System::UnicodeString __fastcall GetHintText(void);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &APoint);
	
public:
	virtual void __fastcall Initialize(TcxPivotGridViewDataItem* ARow, TcxPivotGridViewDataItem* AColumn, TcxPivotGridField* ADataField);
	__property TcxPivotGridOLAPKPIGraphicType GraphicType = {read=FGraphicType, write=FGraphicType, nodefault};
public:
	/* TcxPivotGridEditContainerViewInfo.Create */ inline __fastcall virtual TcxPivotGridKPICellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxPivotGridDataCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxPivotGridEditContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxPivotGridKPICellViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxPivotGridHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TPersistent* FField;
	TcxPivotGridCustomizationFormFieldListType FFieldListType;
	TcxPivotGridCustomCellViewInfo* FHitObject;
	System::Types::TPoint FHitPoint;
	TcxCustomPivotGrid* FOwner;
	_di_IcxPivotGridSizableObject FResizeField;
	int FResizeFieldStartPos;
	bool FResizeRows;
	System::Classes::TShiftState FShiftState;
	bool __fastcall GetBitState(int AIndex);
	TcxPivotGridGroupItem* __fastcall GetGroupItem(void);
	int __fastcall GetPosValue(int AIndex);
	TcxPivotGridViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetBitState(int AIndex, bool AValue);
	void __fastcall SetPosValue(int AIndex, int AValue);
	void __fastcall SetHitPoint(const System::Types::TPoint &AValue);
	
protected:
	__int64 Flags;
	__property bool BitState[int AIndex] = {read=GetBitState, write=SetBitState};
	__property _di_IcxPivotGridSizableObject ResizeField = {read=FResizeField};
	__property int ResizeFieldStartPos = {read=FResizeFieldStartPos, nodefault};
	__property TcxPivotGridViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxPivotGridHitTest(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridHitTest(void);
	void __fastcall Clear(void);
	void __fastcall Recalculate(void);
	__property System::Classes::TPersistent* Field = {read=FField, write=FField};
	__property TcxPivotGridCustomizationFormFieldListType FieldListType = {read=FFieldListType, write=FFieldListType, nodefault};
	__property TcxPivotGridGroupItem* GroupItem = {read=GetGroupItem};
	__property bool HitAtButton = {read=GetBitState, index=1, nodefault};
	__property bool HitAtCustomizationForm = {read=GetBitState, index=16, nodefault};
	__property bool HitAtDataCell = {read=GetBitState, index=2, nodefault};
	__property bool HitAtDataField = {read=GetBitState, index=3, nodefault};
	__property bool HitAtField = {read=GetBitState, index=4, nodefault};
	__property bool HitAtFieldList = {read=GetBitState, index=17, nodefault};
	__property bool HitAtFieldTreeView = {read=GetBitState, index=18, nodefault};
	__property bool HitAtFilter = {read=GetBitState, index=6, nodefault};
	__property bool HitAtGroupHeader = {read=GetBitState, index=7, nodefault};
	__property bool HitAtHeaderArea = {read=GetBitState, index=5, nodefault};
	__property bool HitAtHorzSizingEdge = {read=GetBitState, index=8, nodefault};
	__property bool HitAtPrefilter = {read=GetBitState, index=10, nodefault};
	__property bool HitAtPrefilterCloseButton = {read=GetBitState, index=11, nodefault};
	__property bool HitAtPrefilterActivateButton = {read=GetBitState, index=12, nodefault};
	__property bool HitAtPrefilterCaption = {read=GetBitState, index=15, nodefault};
	__property bool HitAtPrefilterCustomizationButton = {read=GetBitState, index=13, nodefault};
	__property bool HitAtPrefilterDropDownButton = {read=GetBitState, index=14, nodefault};
	__property TcxPivotGridCustomCellViewInfo* HitObject = {read=FHitObject};
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=SetHitPoint};
	__property int HitX = {read=GetPosValue, write=SetPosValue, index=0, nodefault};
	__property int HitY = {read=GetPosValue, write=SetPosValue, index=1, nodefault};
	__property TcxCustomPivotGrid* PivotGrid = {read=FOwner};
	__property System::Classes::TShiftState ShiftState = {read=FShiftState, write=FShiftState, nodefault};
};


class DELPHICLASS TcxPivotGridHotTrackController;
class DELPHICLASS TcxPivotGridController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridHotTrackController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxPivotGridCustomCellViewInfo* FCell;
	TcxPivotGridController* FOwner;
	TcxPivotGridHitTest* __fastcall GetHitTest(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	
protected:
	void __fastcall UpdateState(TcxPivotGridCustomCellViewInfo* AObject);
	
public:
	__fastcall virtual TcxPivotGridHotTrackController(TcxPivotGridController* AOwner);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Update(TcxPivotGridCustomCellViewInfo* AObject);
	__property TcxPivotGridCustomCellViewInfo* Cell = {read=FCell};
	__property TcxPivotGridHitTest* HitTest = {read=GetHitTest};
	__property TcxPivotGridController* Owner = {read=FOwner};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridHotTrackController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridMRUPrefilterPopup;
class DELPHICLASS TcxPivotGridFilterMRUItem;
class PASCALIMPLEMENTATION TcxPivotGridMRUPrefilterPopup : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	TcxPivotGridPrefilter* __fastcall GetPrefilter(void);
	TcxPivotGridFilterMRUItem* __fastcall SelectedMRUItem(void);
	
protected:
	void __fastcall BeforePopup(void);
	virtual void __fastcall DoCloseUp(void);
	void __fastcall InitValues(void);
	virtual void __fastcall UpdateWindowRegion(void);
	
public:
	__fastcall virtual TcxPivotGridMRUPrefilterPopup(System::Classes::TComponent* AOwner)/* overload */;
	void __fastcall Popup(void);
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property TcxPivotGridPrefilter* Prefilter = {read=GetPrefilter};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxPivotGridMRUPrefilterPopup(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxPivotGridMRUPrefilterPopup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridMRUPrefilterPopup(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxPivotGridFilterPopup;
class PASCALIMPLEMENTATION TcxPivotGridFilterPopup : public Cxdropdownedit::TcxPopupEdit
{
	typedef Cxdropdownedit::TcxPopupEdit inherited;
	
private:
	TcxPivotGridField* FField;
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	TcxPivotGridFieldFilter* __fastcall GetFilter(void);
	void __fastcall SetField(TcxPivotGridField* AField);
	void __fastcall SetShowAllState(Cxlookandfeelpainters::TcxCheckBoxState AValue);
	Cxbuttons::TcxButton* __fastcall CreateButton(int ATag);
	void __fastcall UpdateButtonCaptions(void);
	
protected:
	Cxbuttons::TcxButton* FCancelButton;
	bool FFilterModified;
	bool FLocked;
	Cxlookandfeelpainters::TcxButtonState FPrevFilterState;
	Cxbuttons::TcxButton* FOkButton;
	Cxlookandfeelpainters::TcxCheckBoxState FShowAllState;
	Cxchecklistbox::TcxCheckListBox* FValues;
	Cxchecklistbox::TcxCheckListBoxItem* __fastcall AddValue(TcxPivotGridVariantValue* const AValue);
	virtual void __fastcall BeforePopup(void);
	virtual void __fastcall ButtonClickHandler(System::TObject* ASender);
	void __fastcall CheckButtonsEnabled(void);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall DoCloseUp(void);
	int __fastcall GetCheckedCount(void);
	System::Variant __fastcall GetFieldValueByValueIndex(int AIndex);
	HIDESBASE int __fastcall GetHeight(int AItemCount);
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetStateByCount(int ACount);
	virtual void __fastcall InitValues(void);
	void __fastcall SetPopupSize(const int AWidth, const int AHeight);
	virtual void __fastcall SetupPopupWindow(void);
	virtual void __fastcall UpdateWindowRegion(void);
	void __fastcall ValuesChanges(System::TObject* Sender);
	
public:
	__fastcall virtual TcxPivotGridFilterPopup(System::Classes::TComponent* AOwner)/* overload */;
	void __fastcall Popup(void);
	virtual void __fastcall SaveChanges(void);
	virtual void __fastcall TranslationChanged(void);
	__property Cxbuttons::TcxButton* CancelButton = {read=FCancelButton};
	__property TcxPivotGridField* Field = {read=FField, write=SetField};
	__property TcxPivotGridFieldFilter* Filter = {read=GetFilter};
	__property bool FilterModified = {read=FFilterModified, nodefault};
	__property Cxbuttons::TcxButton* OkButton = {read=FOkButton};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property Cxlookandfeelpainters::TcxCheckBoxState ShowAllState = {read=FShowAllState, write=SetShowAllState, nodefault};
	__property Cxchecklistbox::TcxCheckListBox* Values = {read=FValues};
public:
	/* TcxCustomPopupEdit.Destroy */ inline __fastcall virtual ~TcxPivotGridFilterPopup(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxPivotGridFilterPopup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridFilterPopup(HWND ParentWindow) : Cxdropdownedit::TcxPopupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxPivotGridCustomDragDropObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomDragDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	TcxPivotGridHitTest* __fastcall GetHitTest(void);
	TcxPivotGridOptionsView* __fastcall GetOptionsView(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	TcxPivotGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	
public:
	__property TcxPivotGridHitTest* HitTest = {read=GetHitTest};
	__property TcxPivotGridOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property TcxPivotGridViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxPivotGridCustomDragDropObject(Cxcontrols::TcxControl* AControl) : Cxcontrols::TcxDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomDragDropObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridResizingObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridResizingObject : public TcxPivotGridCustomDragDropObject
{
	typedef TcxPivotGridCustomDragDropObject inherited;
	
private:
	int FSizeCursorPos;
	int __fastcall GetSizeDelta(void);
	System::Types::TRect __fastcall GetSizeMarkBounds(void);
	void __fastcall SetSizeCursorPos(int AValue);
	
protected:
	int StartPos;
	int StartPosDelta;
	System::Types::TRect SizingBounds;
	_di_IcxPivotGridSizableObject SizableObject;
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DirtyChanged(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual bool __fastcall GetImmediateStart(void);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	void __fastcall SetSizeDelta(int ADelta);
	
public:
	__property int SizeCursorPos = {read=FSizeCursorPos, write=SetSizeCursorPos, nodefault};
	__property int SizeDelta = {read=GetSizeDelta, nodefault};
	__property System::Types::TRect SizeMarkBounds = {read=GetSizeMarkBounds};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxPivotGridResizingObject(Cxcontrols::TcxControl* AControl) : TcxPivotGridCustomDragDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridResizingObject(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridDragDropAreaInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxPivotGridFieldArea Area;
	int AreaIndex;
	System::Types::TRect Bounds;
	System::Types::TRect DisplayBounds;
	System::Classes::TPersistent* Field;
	bool Visible;
public:
	/* TObject.Create */ inline __fastcall TcxPivotGridDragDropAreaInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridDragDropAreaInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridDragAndDropObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridDragAndDropObject : public TcxPivotGridCustomDragDropObject
{
	typedef TcxPivotGridCustomDragDropObject inherited;
	
private:
	_di_IcxPivotGridField FDragField;
	void __fastcall FieldPaintTo(TcxPivotGridFieldHeaderCellViewInfo* AFieldViewInfo, const System::Types::TRect &ABounds);
	int __fastcall GetDragDropAreaCount(void);
	TcxPivotGridDragDropAreaInfo* __fastcall GetDragDropArea(int AIndex);
	System::Uitypes::TColor __fastcall GetDragDropArrowColor(void);
	TcxPivotGridFieldHeaderCellViewInfo* __fastcall GetFieldViewInfo(void);
	
protected:
	bool AAccepted;
	Cxinplacecontainer::TcxPlaceArrows* Arrows;
	Cxcontrols::TcxDragImage* DragImage;
	TcxPivotGridDragDropAreaInfo* DragDropInfo;
	System::Types::TPoint HotSpot;
	int IndentOffset;
	virtual void __fastcall BeginDragAndDrop(void);
	virtual bool __fastcall CanRemove(void);
	virtual bool __fastcall CheckArea(const System::Types::TPoint &P, TcxPivotGridDragDropAreaInfo* &AInfo);
	virtual void __fastcall CreateDragImage(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall DragDropField(TcxPivotGridFieldArea AArea, int AAreaIndex);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	bool __fastcall GetImmediateUpdate(void);
	System::TObject* __fastcall GetFieldListByType(TcxPivotGridCustomizationFormFieldListType AListType);
	virtual bool __fastcall IsSameDropPlace(void);
	void __fastcall PaintDragHeader(const System::Types::TRect &ABounds);
	void __fastcall ChangeArrowPos(bool AllowHide);
	void __fastcall ShowDragImage(const System::Types::TPoint &APos);
	
public:
	__fastcall virtual ~TcxPivotGridDragAndDropObject(void);
	__property _di_IcxPivotGridField DragField = {read=FDragField};
	__property int DragDropAreaCount = {read=GetDragDropAreaCount, nodefault};
	__property TcxPivotGridDragDropAreaInfo* DragDropAreas[int Index] = {read=GetDragDropArea};
	__property System::Uitypes::TColor DragDropArrowColor = {read=GetDragDropArrowColor, nodefault};
	__property TcxPivotGridFieldHeaderCellViewInfo* FieldViewInfo = {read=GetFieldViewInfo};
	__property bool ImmediateUpdate = {read=GetImmediateUpdate, nodefault};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxPivotGridDragAndDropObject(Cxcontrols::TcxControl* AControl) : TcxPivotGridCustomDragDropObject(AControl) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridHintHelper;
class DELPHICLASS TcxPivotGridHintController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridHintHelper : public Dxcustomhint::TcxControlHintHelper
{
	typedef Dxcustomhint::TcxControlHintHelper inherited;
	
private:
	TcxPivotGridHintController* FController;
	
protected:
	virtual int __fastcall GetHintHidePause(void);
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void);
	
public:
	__fastcall virtual TcxPivotGridHintHelper(TcxPivotGridHintController* AController);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxPivotGridHintHelper(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridHintController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::Types::TRect FHintAreaBounds;
	TcxPivotGridHintHelper* FHintHelper;
	System::TObject* FHintObject;
	System::UnicodeString FHintText;
	TcxPivotGridController* FOwner;
	TcxPivotGridHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetHintVisible(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	
protected:
	bool __fastcall CanShowHint(void);
	virtual bool __fastcall GetHintInfo(System::Types::TRect &ABounds, System::Types::TRect &ATextBounds);
	void __fastcall HintCheckerTimerHandler(System::TObject* Sender);
	__property System::TObject* HintObject = {read=FHintObject, write=FHintObject};
	
public:
	__fastcall virtual TcxPivotGridHintController(TcxPivotGridController* AOwner);
	__fastcall virtual ~TcxPivotGridHintController(void);
	virtual void __fastcall HideHint(void);
	virtual void __fastcall ShowHint(void);
	void __fastcall Update(void);
	__property System::Types::TRect HintAreaBounds = {read=FHintAreaBounds, write=FHintAreaBounds};
	__property TcxPivotGridHintHelper* HintHelper = {read=FHintHelper};
	__property System::UnicodeString HintText = {read=FHintText, write=FHintText};
	__property bool HintVisible = {read=GetHintVisible, nodefault};
	__property TcxPivotGridHitTest* HitTest = {read=GetHitTest};
	__property TcxPivotGridController* Owner = {read=FOwner};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIgnoreSelection;
	TcxPivotGridFilterPopup* FFilterPopup;
	TcxPivotGridHintController* FHintController;
	TcxPivotGridHotTrackController* FHotTrackController;
	TcxCustomPivotGrid* FOwner;
	TcxPivotGridMRUPrefilterPopup* FPrefilterPopup;
	Vcl::Extctrls::TTimer* FSelectionTimer;
	void __fastcall CalculateIgnoreSelection(void);
	bool __fastcall GetFocused(void);
	System::Types::TPoint __fastcall GetFocusedCell(void);
	TcxPivotGridHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetIsDesigning(void);
	TcxPivotGridOptionsCustomize* __fastcall GetOptionsCustomize(void);
	TcxPivotGridOptionsSelection* __fastcall GetOptionsSelection(void);
	TcxPivotGridOptionsView* __fastcall GetOptionsView(void);
	TcxPivotGridViewData* __fastcall GetViewData(void);
	TcxPivotGridViewInfo* __fastcall GetViewInfo(void);
	
protected:
	_di_IcxPivotGridField DownField;
	bool FilterOpenedBeforeClick;
	bool PrefilterOpenedBeforeClick;
	bool SuspendSelectionTimer;
	void __fastcall CalculateAnchor(System::Classes::TShiftState AShift);
	System::Types::TSize __fastcall CalculateFilterDropDownSize(TcxPivotGridFieldFilter* AFilter);
	void __fastcall CheckSelectionTimer(const int X, const int Y);
	virtual TcxPivotGridFilterPopup* __fastcall CreateFilterPopup(void);
	virtual TcxPivotGridHintController* __fastcall CreateHintController(void);
	virtual TcxPivotGridHotTrackController* __fastcall CreateHotTrackController(void);
	void __fastcall DoFieldHeaderClick(System::Classes::TPersistent* AField, System::Classes::TShiftState AShift);
	System::Uitypes::TCursor __fastcall GetCursor(const int X, const int Y);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual bool __fastcall IsButtonDown(void);
	bool __fastcall IsCellSelected(TcxPivotGridDataCellViewInfo* ACell);
	virtual void __fastcall MakeSelected(System::Classes::TShiftState AShift, bool AMouseMove = false);
	bool __fastcall ProcessNavigationByStep(bool AGoBackward, System::Classes::TShiftState AShiftState);
	void __fastcall ProcessTabKeyDown(bool AGoBackward);
	void __fastcall SelectionTimerHandler(System::TObject* Sender);
	void __fastcall SetSelection(int ACol, int ARow, System::Classes::TShiftState AShift);
	void __fastcall SetSelectionInc(const int DX, const int DY, System::Classes::TShiftState AShift, bool AByTimer = false);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	
public:
	__fastcall virtual TcxPivotGridController(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridController(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DblClick(void);
	virtual void __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall KeyPress(System::WideChar &AKey);
	void __fastcall MakeCellFocused(TcxPivotGridDataCellViewInfo* ACell, System::Classes::TShiftState AShift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall FieldFilterPopup(TcxPivotGridField* AField, System::Classes::TNotifyEvent AInitPopupEvent = 0x0);
	void __fastcall StartSelectionTimer(void);
	void __fastcall StopSelectionTimer(void);
	virtual void __fastcall Update(void);
	__property TcxPivotGridFilterPopup* FilterPopup = {read=FFilterPopup};
	__property bool Focused = {read=GetFocused, nodefault};
	__property System::Types::TPoint FocusedCell = {read=GetFocusedCell};
	__property TcxPivotGridHitTest* HitTest = {read=GetHitTest};
	__property TcxPivotGridHintController* HintController = {read=FHintController};
	__property TcxPivotGridHotTrackController* HotTrackController = {read=FHotTrackController};
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property TcxPivotGridOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize};
	__property TcxPivotGridOptionsSelection* OptionsSelection = {read=GetOptionsSelection};
	__property TcxPivotGridOptionsView* OptionsView = {read=GetOptionsView};
	__property TcxCustomPivotGrid* PivotGrid = {read=FOwner};
	__property TcxPivotGridMRUPrefilterPopup* PrefilterPopup = {read=FPrefilterPopup};
	__property Vcl::Extctrls::TTimer* SelectionTimer = {read=FSelectionTimer};
	__property TcxPivotGridViewData* ViewData = {read=GetViewData};
	__property TcxPivotGridViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

enum TcxPivotGridFilterType : unsigned char { ftExcluded, ftIncluded };

class PASCALIMPLEMENTATION TcxPivotGridFieldFilter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxPivotGridField* FField;
	TcxPivotGridFilterType FFilterType;
	int FLockCount;
	bool FModified;
	TcxPivotGridVariantList* FValues;
	System::Types::TSize FWindowSize;
	System::Classes::TNotifyEvent FOnChange;
	bool __fastcall GetHasFilter(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	void __fastcall SetFilterType(TcxPivotGridFilterType AFilterType);
	
protected:
	virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall ValuesChanged(System::TObject* ASender);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(bool AForceUpdate = true);
	void __fastcall ReadData(System::Classes::TStream* AStream);
	void __fastcall WriteData(System::Classes::TStream* AStream);
	__property System::Types::TSize WindowSize = {read=FWindowSize, write=FWindowSize};
	
public:
	__fastcall virtual TcxPivotGridFieldFilter(TcxPivotGridField* AOwner);
	__fastcall virtual ~TcxPivotGridFieldFilter(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	bool __fastcall Contains(const System::Variant &AValue);
	__property TcxPivotGridField* Field = {read=FField};
	__property TcxPivotGridFilterType FilterType = {read=FFilterType, write=SetFilterType, nodefault};
	__property bool HasFilter = {read=GetHasFilter, nodefault};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property TcxPivotGridVariantList* Values = {read=FValues};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TcxPivotGridFieldOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFieldOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxPivotGridField* FField;
	bool FFiltering;
	bool FMoving;
	bool FSizing;
	bool FSorting;
	void __fastcall SetFiltering(bool AValue);
	void __fastcall SetMoving(bool AValue);
	void __fastcall SetSizing(bool AValue);
	void __fastcall SetSorting(bool AValue);
	
protected:
	virtual bool __fastcall CanFiltering(void);
	virtual bool __fastcall CanSorting(void);
	virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall SetOption(bool &AOption, bool ANewValue);
	
public:
	__fastcall virtual TcxPivotGridFieldOptions(TcxPivotGridField* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxPivotGridField* Field = {read=FField};
	
__published:
	__property bool Filtering = {read=FFiltering, write=SetFiltering, default=1};
	__property bool Moving = {read=FMoving, write=SetMoving, default=1};
	__property bool Sizing = {read=FSizing, write=SetSizing, default=1};
	__property bool Sorting = {read=FSorting, write=SetSorting, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridFieldOptions(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomTotal : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FDisplayFormat;
	TcxPivotGridSummaryType FSummaryType;
	TcxPivotGridField* __fastcall GetField(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	void __fastcall SetDisplayFormat(const System::UnicodeString AValue);
	void __fastcall SetSummaryType(TcxPivotGridSummaryType AValue);
	
public:
	__fastcall virtual TcxPivotGridCustomTotal(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxPivotGridField* Field = {read=GetField};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	
__published:
	__property TcxPivotGridSummaryType SummaryType = {read=FSummaryType, write=SetSummaryType, default=1};
	__property System::UnicodeString DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomTotal(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridCustomTotalCollection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomTotalCollection : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxPivotGridCustomTotal* operator[](int Index) { return Items[Index]; }
	
private:
	TcxPivotGridField* FOwner;
	HIDESBASE TcxPivotGridCustomTotal* __fastcall GetItem(int AIndex);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxPivotGridCustomTotal* AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxPivotGridCustomTotalCollection(TcxPivotGridField* AOwner)/* overload */;
	HIDESBASE TcxPivotGridCustomTotal* __fastcall Add(TcxPivotGridSummaryType ASummaryType);
	__property TcxPivotGridField* Field = {read=FOwner};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property TcxPivotGridCustomTotal* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomTotalCollection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridSortBySummaryInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridSortBySummaryInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxPivotGridField* FField;
	TcxPivotGridField* FOwner;
	TcxPivotGridSummaryType FSummaryType;
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	void __fastcall SetField(TcxPivotGridField* AValue);
	void __fastcall SetSummaryType(TcxPivotGridSummaryType AValue);
	
protected:
	virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual bool __fastcall ValidateProperties(void);
	
public:
	__fastcall virtual TcxPivotGridSortBySummaryInfo(TcxPivotGridField* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxPivotGridField* Owner = {read=FOwner};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	
__published:
	__property TcxPivotGridField* Field = {read=FField, write=SetField};
	__property TcxPivotGridSummaryType SummaryType = {read=FSummaryType, write=SetSummaryType, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridSortBySummaryInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridDefaultValuesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridDefaultValuesProvider : public Cxedit::TcxCustomEditDefaultValuesProvider
{
	typedef Cxedit::TcxCustomEditDefaultValuesProvider inherited;
	
public:
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
public:
	/* TcxCustomEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxPivotGridDefaultValuesProvider(void) { }
	
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxPivotGridDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditDefaultValuesProvider(AOwner) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridFieldDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFieldDataBinding : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxPivotGridField* FField;
	bool FValueTypeAssigned;
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	System::UnicodeString __fastcall GetValueType(void);
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	void __fastcall SetValueType(System::UnicodeString AValue);
	void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass AValue);
	bool __fastcall IsValueTypeStored(void);
	
protected:
	Cxedit::TcxCustomEditDefaultValuesProvider* FDefaultValuesProvider;
	virtual Cxedit::_di_IcxEditDefaultValuesProvider __fastcall GetDefaultValuesProvider(void);
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual System::UnicodeString __fastcall GetFilterFieldName(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Init(void);
	
public:
	__fastcall virtual TcxPivotGridFieldDataBinding(TcxPivotGridField* AOwner);
	__fastcall virtual ~TcxPivotGridFieldDataBinding(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxPivotGridField* Field = {read=FField};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property bool ValueTypeAssigned = {read=FValueTypeAssigned, write=FValueTypeAssigned, nodefault};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
	
__published:
	__property System::UnicodeString ValueType = {read=GetValueType, write=SetValueType, stored=IsValueTypeStored};
};

#pragma pack(pop)

enum TcxPivotGridSummaryVariation : unsigned char { svNone, svAbsolute, svPercent, svPercentOfColumn, svPercentOfRow };

enum TcxPivotGridFieldDataVisibility : unsigned char { dvAllCells, dvCrossAndTotalCells, dvGrandTotalCells };

typedef void __fastcall (__closure *TcxPivotGridCalculateCustomSummaryEvent)(TcxPivotGridField* Sender, TcxPivotGridCrossCellSummary* ASummary);

typedef void __fastcall (__closure *TcxPivotGridGetDisplayTextEvent)(TcxPivotGridField* Sender, TcxPivotGridDataCellViewInfo* ACell, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxPivotGridGetGroupValueDisplayTextEvent)(TcxPivotGridField* Sender, const System::Variant &AGroupValue, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxPivotGridGetGroupValueEvent)(TcxPivotGridField* Sender, int ARecordIndex, System::Variant &AValue);

typedef void __fastcall (__closure *TcxPivotGridGetTotalDisplayTextEvent)(TcxPivotGridField* Sender, TcxPivotGridGroupItem* AGroupItem, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxPivotGridGetPropertiesEvent)(TcxPivotGridField* Sender, TcxPivotGridCustomCellViewInfo* ACell, Cxedit::TcxCustomEditProperties* &AProperties);

typedef void __fastcall (__closure *TcxPivotGridFieldGetGroupImageIndex)(TcxPivotGridField* Sender, TcxPivotGridViewDataItem* const AItem, int &AImageIndex, System::Classes::TAlignment &AImageAlignHorz, Cxclasses::TcxAlignmentVert &AImageAlignVert);

class PASCALIMPLEMENTATION TcxPivotGridField : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TcxPivotGridFieldAreas FAllowedAreas;
	TcxPivotGridFieldArea FArea;
	int FAreaIndex;
	System::UnicodeString FCaption;
	TcxPivotGridCustomTotalCollection* FCustomTotals;
	bool FCurrency;
	TcxPivotGridFieldDataBinding* FDataBinding;
	TcxPivotGridFieldDataVisibility FDataVisibility;
	System::UnicodeString FDisplayFormat;
	Cxedit::TcxEditStyle* FEditStyle;
	Cxedit::TcxCustomEditViewData* FEditViewData;
	TcxPivotGridVariantList* FExpandingInfo;
	TcxPivotGridFieldFilter* FFilter;
	bool FFloat;
	TcxPivotGridFieldGroup* FGroup;
	bool FGroupExpanded;
	TcxPivotGridVariantList* FGroupValueList;
	bool FGroupValuesValid;
	TcxPivotGridGroupInterval FGroupInterval;
	int FGroupIntervalRange;
	bool FHidden;
	System::Classes::TAlignment FImageAlign;
	System::Uitypes::TImageIndex FImageIndex;
	int FIndex;
	bool FIsCaptionAssigned;
	Cxedit::TcxEditRepositoryItem* FLastUsedDefaultRepositoryItem;
	int FMinWidth;
	TcxPivotGridFieldOptions* FOptions;
	TcxCustomPivotGrid* FPivotGrid;
	Cxedit::TcxCustomEditProperties* FProperties;
	Cxedit::TcxCustomEditPropertiesClass FPropertiesClass;
	Cxedit::TcxCustomEditProperties* FPropertiesValue;
	Cxedit::TcxEditRepositoryItem* FRepositoryItem;
	Dxcore::TdxSortOrder FSortOrder;
	TcxPivotGridSortBySummaryInfo* FSortBySummaryInfo;
	TcxPivotGridFieldStyles* FStyles;
	System::Classes::TNotifyEvent FSubClassEvents;
	int FSummaryIndex;
	TcxPivotGridSummaryType FSummaryType;
	TcxPivotGridSummaryVariation FSummaryVariation;
	TcxPivotGridTotalsVisibility FTotalsVisibility;
	int FTopValueCount;
	bool FTopValueShowOthers;
	System::UnicodeString FUniqueName;
	bool FVisible;
	int FVisibleIndex;
	TcxPivotGridFieldHeaderCellViewInfo* FViewInfo;
	int FWidth;
	TcxPivotGridCalculateCustomSummaryEvent FOnCalculateCustomSummary;
	TcxPivotGridGetDisplayTextEvent FOnGetDisplayText;
	TcxPivotGridFieldGetGroupImageIndex FOnGetGroupImageIndex;
	TcxPivotGridGetGroupValueEvent FOnGetGroupValue;
	TcxPivotGridGetGroupValueDisplayTextEvent FOnGetGroupValueDisplayText;
	TcxPivotGridGetPropertiesEvent FOnGetProperties;
	TcxPivotGridGetTotalDisplayTextEvent FOnGetTotalDisplayText;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	int __fastcall GetActualHeaderWidth(void);
	int __fastcall GetActualWidth(void);
	TcxPivotGridFieldArea __fastcall GetArea(void);
	TcxPivotGridController* __fastcall GetController(void);
	TcxPivotGridDataBuilder* __fastcall GetDataBuilder(void);
	bool __fastcall GetFieldInCompactLayout(void);
	bool __fastcall GetGroupExpanded(void);
	int __fastcall GetGroupIndex(void);
	TcxPivotGridVariantList* __fastcall GetGroupValueList(void);
	int __fastcall GetHeaderWidth(void);
	bool __fastcall GetHidden(void);
	bool __fastcall GetIsDestroying(void);
	bool __fastcall GetIsHierarchy(void);
	bool __fastcall GetIsLastVisibleInArea(void);
	int __fastcall GetMinWidth(void);
	System::UnicodeString __fastcall GetPropertiesClassName(void);
	int __fastcall GetRecordCount(void);
	bool __fastcall GetSortedBySummary(void);
	System::Variant __fastcall GetValueByRecordIndex(int ARecordIndex);
	bool __fastcall GetVisible(void);
	bool __fastcall GetVisibleInGroup(void);
	bool __fastcall IsFirstFieldInGroup(void);
	void __fastcall SetArea(TcxPivotGridFieldArea AValue);
	void __fastcall SetAreaIndex(int AValue);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetCustomTotals(TcxPivotGridCustomTotalCollection* AValue);
	void __fastcall SetDataBinding(TcxPivotGridFieldDataBinding* AValue);
	void __fastcall SetDataVisibility(TcxPivotGridFieldDataVisibility AValue);
	void __fastcall SetDisplayFormat(const System::UnicodeString AValue);
	void __fastcall SetGroup(TcxPivotGridFieldGroup* AValue);
	void __fastcall SetGroupExpanded(bool AValue);
	void __fastcall SetGroupIndex(int AValue);
	void __fastcall SetGroupInterval(TcxPivotGridGroupInterval AValue);
	void __fastcall SetGroupIntervalRange(int AValue);
	void __fastcall SetHidden(bool AValue);
	void __fastcall SetImageAlign(System::Classes::TAlignment AValue);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex AValue);
	void __fastcall SetIndex(int AValue);
	void __fastcall SetMinWidth(int Avalue);
	void __fastcall SetOnGetProperties(TcxPivotGridGetPropertiesEvent AValue);
	void __fastcall SetOptions(TcxPivotGridFieldOptions* AValue);
	void __fastcall SetProperties(Cxedit::TcxCustomEditProperties* Value);
	void __fastcall SetPropertiesClass(Cxedit::TcxCustomEditPropertiesClass Value);
	void __fastcall SetPropertiesClassName(const System::UnicodeString Value);
	void __fastcall SetRepositoryItem(Cxedit::TcxEditRepositoryItem* Value);
	void __fastcall SetSizeDelta(int ADelta);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder AValue);
	void __fastcall SetSortBySummaryInfo(TcxPivotGridSortBySummaryInfo* AValue);
	void __fastcall SetStyles(TcxPivotGridFieldStyles* AValue);
	void __fastcall SetSummaryType(TcxPivotGridSummaryType AValue);
	void __fastcall SetSummaryVariation(TcxPivotGridSummaryVariation AValue);
	void __fastcall SetTotalsVisibility(TcxPivotGridTotalsVisibility AValue);
	void __fastcall SetTopValueCount(int AValue);
	void __fastcall SetTopValueShowOthers(bool AValue);
	void __fastcall SetValueByRecordIndex(int ARecordIndex, const System::Variant &AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetWidth(int AValue);
	void __fastcall FilterChanged(System::TObject* Sender);
	void __fastcall InternalDoGetDisplayText(TcxPivotGridDataCellViewInfo* ACell, System::UnicodeString &AText);
	bool __fastcall IsCustomTotalStored(void);
	void __fastcall ChangeExpanding(void);
	void __fastcall ChangeSorting(void);
	TcxPivotGridFieldHeaderCellViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AState);
	void __fastcall CreateProperties(void);
	void __fastcall DestroyProperties(void);
	void __fastcall RecreateProperties(void);
	void __fastcall ReadUniqueName(System::Classes::TReader* AReader);
	void __fastcall WriteUniqueName(System::Classes::TWriter* AWriter);
	
protected:
	void __fastcall AssignAreaIndex(TcxPivotGridFieldArea AArea, int AIndex);
	virtual bool __fastcall CanDrag(void);
	virtual bool __fastcall CanDrop(TcxPivotGridFieldArea AArea);
	bool __fastcall CanModifyArea(void);
	virtual bool __fastcall CanRemove(void);
	bool __fastcall CanResize(void);
	virtual void __fastcall Changed(bool AIsViewChanged = false);
	Cxedit::TcxEditStyle* __fastcall CreateEditStyle(Cxedit::TcxCustomEditProperties* AProperties);
	void __fastcall CreateEditViewData(void);
	virtual void __fastcall DataChanged(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall DestroyEditViewData(void);
	void __fastcall DoChangeSorting(void);
	virtual void __fastcall DragDrop(TcxPivotGridFieldArea AArea, int AAreaIndex);
	virtual TcxPivotGridFieldAreas __fastcall GetAllowedAreas(void);
	virtual TcxPivotGridDataCellViewInfoClass __fastcall GetCellViewInfoClass(void);
	Cxedit::TcxCustomEditViewData* __fastcall GetEditViewData(void);
	virtual System::UnicodeString __fastcall GetUniqueName(void);
	virtual bool __fastcall IsAllowedAreasStored(void);
	bool __fastcall IsCompatibleWidth(TcxPivotGridDragDropAreaInfo* AInfo);
	virtual bool __fastcall IsEqual(TcxPivotGridOLAPStructureNode* const AStructure);
	void __fastcall InitGroupValues(void);
	void __fastcall InitProperties(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoCalculateCustomSummary(TcxPivotGridCrossCellSummary* ACell);
	virtual void __fastcall DoGetDisplayText(TcxPivotGridDataCellViewInfo* ACell);
	virtual int __fastcall DoGetGroupImageIndex(TcxPivotGridViewDataItem* AItem, System::Classes::TAlignment &AAlignHorz, Cxclasses::TcxAlignmentVert &AAlignVert);
	virtual System::Variant __fastcall DoGetGroupValue(const System::Variant &AValue, int ARecordIndex);
	virtual System::UnicodeString __fastcall DoGetGroupValueDisplayText(const System::Variant &AValue);
	virtual void __fastcall DoFilterChanged(void);
	Cxedit::TcxCustomEditProperties* __fastcall DoGetProperties(TcxPivotGridCustomCellViewInfo* ACell);
	virtual void __fastcall DoGetTotalDisplayText(TcxPivotGridGroupItem* AGroupItem, System::UnicodeString &AText);
	virtual bool __fastcall IsCurrency(Cxdatastorage::TcxValueTypeClass AType);
	bool __fastcall IsItemExpanded(TcxPivotGridGroupItem* AGroup);
	bool __fastcall HasSummaryVariation(void);
	virtual System::UnicodeString __fastcall GetActualDisplayFormat(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(void);
	Cxedit::TcxEditStyle* __fastcall GetEditStyle(Cxedit::TcxCustomEditProperties* AProperties, bool ALocal);
	Cxedit::TcxCustomEditProperties* __fastcall GetUserEditProperties(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetPropertiesValue(void);
	Cxedit::TcxEditRepositoryItem* __fastcall GetRepositoryItem(void);
	void __fastcall EditViewDataGetDisplayTextHandler(Cxedit::TcxCustomEditViewData* Sender, System::UnicodeString &AText);
	void __fastcall PropertiesChanged(void);
	void __fastcall PropertiesChangedHandler(System::TObject* Sender);
	void __fastcall PropertiesValueChanged(void);
	bool __fastcall UseEditProperties(void);
	virtual TcxPivotGridCustomTotalCollection* __fastcall CreateCustomTotals(void);
	virtual TcxPivotGridFieldDataBinding* __fastcall CreateDataBinding(void);
	virtual TcxPivotGridFieldFilter* __fastcall CreateFilter(void);
	virtual TcxPivotGridFieldOptions* __fastcall CreateOptions(void);
	virtual TcxPivotGridSortBySummaryInfo* __fastcall CreateSortBySummaryInfo(void);
	virtual TcxPivotGridFieldStyles* __fastcall CreateStyles(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	void __fastcall GroupCheckExpanding(TcxPivotGridGroupItem* AGroup);
	virtual void __fastcall GroupExpandingChanged(TcxPivotGridGroupItem* ASender);
	virtual System::UnicodeString __fastcall GetCaption(void);
	System::Word __fastcall GetDataType(void);
	bool __fastcall GetDisplayTextAssigned(void);
	bool __fastcall IsRecordVisible(int ARecordIndex);
	void __fastcall SetAreaIndexInternal(TcxPivotGridFieldArea AArea, int AAreaIndex);
	void __fastcall SetExpanding(bool AValue);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	void __fastcall SetPivotGrid(TcxCustomPivotGrid* AValue);
	void __fastcall ItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall RepositoryItemPropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties)/* overload */;
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property TcxPivotGridController* Controller = {read=GetController};
	__property bool Currency = {read=FCurrency, write=FCurrency, nodefault};
	__property TcxPivotGridDataBuilder* DataBuilder = {read=GetDataBuilder};
	__property TcxPivotGridVariantList* ExpandingInfo = {read=FExpandingInfo};
	__property bool Float = {read=FFloat, write=FFloat, nodefault};
	__property bool GroupValuesValid = {read=FGroupValuesValid, write=FGroupValuesValid, nodefault};
	__property int HeaderWidth = {read=GetHeaderWidth, nodefault};
	__property TcxPivotGridFieldHeaderCellViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxPivotGridField(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridField(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ApplyBestFit(void);
	void __fastcall CollapseAll(void);
	void __fastcall ExpandAll(void);
	System::Variant __fastcall GetGroupValue(int ARecordIndex);
	System::UnicodeString __fastcall GetGroupValueDisplayText(const System::Variant &AGroupValue);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual bool __fastcall IsFiltered(void);
	void __fastcall SetAreaPosition(TcxPivotGridFieldArea AArea, int AAreaIndex);
	__property int ActualWidth = {read=GetActualWidth, nodefault};
	__property bool FieldInCompactLayout = {read=GetFieldInCompactLayout, nodefault};
	__property TcxPivotGridFieldFilter* Filter = {read=FFilter};
	__property TcxPivotGridFieldGroup* Group = {read=FGroup, write=SetGroup};
	__property TcxPivotGridVariantList* GroupValueList = {read=GetGroupValueList};
	__property int Index = {read=FIndex, write=SetIndex, nodefault};
	__property bool IsHierarchy = {read=GetIsHierarchy, nodefault};
	__property bool IsLastVisibleInArea = {read=GetIsLastVisibleInArea, nodefault};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid, write=SetPivotGrid};
	__property Cxedit::TcxCustomEditPropertiesClass PropertiesClass = {read=FPropertiesClass, write=SetPropertiesClass};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property bool SortedBySummary = {read=GetSortedBySummary, nodefault};
	__property int SummaryIndex = {read=FSummaryIndex, nodefault};
	__property System::UnicodeString UniqueName = {read=GetUniqueName};
	__property System::Variant Values[int ARecordIndex] = {read=GetValueByRecordIndex, write=SetValueByRecordIndex};
	__property bool VisibleInGroup = {read=GetVisibleInGroup, nodefault};
	__property int VisibleIndex = {read=FVisibleIndex, nodefault};
	
__published:
	__property TcxPivotGridFieldArea Area = {read=GetArea, write=SetArea, default=2};
	__property int AreaIndex = {read=FAreaIndex, write=SetAreaIndex, default=-1};
	__property TcxPivotGridFieldAreas AllowedAreas = {read=GetAllowedAreas, write=FAllowedAreas, stored=IsAllowedAreasStored, nodefault};
	__property bool IsCaptionAssigned = {read=FIsCaptionAssigned, write=FIsCaptionAssigned, default=0};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=FIsCaptionAssigned};
	__property TcxPivotGridCustomTotalCollection* CustomTotals = {read=FCustomTotals, write=SetCustomTotals, stored=IsCustomTotalStored};
	__property TcxPivotGridFieldDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property TcxPivotGridFieldDataVisibility DataVisibility = {read=FDataVisibility, write=SetDataVisibility, default=0};
	__property System::UnicodeString DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat};
	__property TcxPivotGridFieldOptions* Options = {read=FOptions, write=SetOptions};
	__property System::UnicodeString PropertiesClassName = {read=GetPropertiesClassName, write=SetPropertiesClassName};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property Cxedit::TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
	__property System::Classes::TAlignment ImageAlign = {read=FImageAlign, write=SetImageAlign, default=0};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property int GroupIndex = {read=GetGroupIndex, write=SetGroupIndex, default=-1};
	__property bool GroupExpanded = {read=GetGroupExpanded, write=SetGroupExpanded, default=1};
	__property TcxPivotGridGroupInterval GroupInterval = {read=FGroupInterval, write=SetGroupInterval, default=0};
	__property int GroupIntervalRange = {read=FGroupIntervalRange, write=SetGroupIntervalRange, default=10};
	__property bool Hidden = {read=GetHidden, write=SetHidden, default=0};
	__property int MinWidth = {read=GetMinWidth, write=SetMinWidth, default=20};
	__property TcxPivotGridSummaryType SummaryType = {read=FSummaryType, write=SetSummaryType, default=1};
	__property TcxPivotGridSortBySummaryInfo* SortBySummaryInfo = {read=FSortBySummaryInfo, write=SetSortBySummaryInfo};
	__property Dxcore::TdxSortOrder SortOrder = {read=FSortOrder, write=SetSortOrder, default=0};
	__property TcxPivotGridFieldStyles* Styles = {read=FStyles, write=SetStyles};
	__property TcxPivotGridSummaryVariation SummaryVariation = {read=FSummaryVariation, write=SetSummaryVariation, default=0};
	__property TcxPivotGridTotalsVisibility TotalsVisibility = {read=FTotalsVisibility, write=SetTotalsVisibility, default=0};
	__property int TopValueCount = {read=FTopValueCount, write=SetTopValueCount, default=0};
	__property bool TopValueShowOthers = {read=FTopValueShowOthers, write=SetTopValueShowOthers, default=0};
	__property bool Visible = {read=GetVisible, write=SetVisible, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property TcxPivotGridCalculateCustomSummaryEvent OnCalculateCustomSummary = {read=FOnCalculateCustomSummary, write=FOnCalculateCustomSummary};
	__property TcxPivotGridGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
	__property TcxPivotGridFieldGetGroupImageIndex OnGetGroupImageIndex = {read=FOnGetGroupImageIndex, write=FOnGetGroupImageIndex};
	__property TcxPivotGridGetGroupValueEvent OnGetGroupValue = {read=FOnGetGroupValue, write=FOnGetGroupValue};
	__property TcxPivotGridGetGroupValueDisplayTextEvent OnGetGroupValueDisplayText = {read=FOnGetGroupValueDisplayText, write=FOnGetGroupValueDisplayText};
	__property TcxPivotGridGetPropertiesEvent OnGetProperties = {read=FOnGetProperties, write=SetOnGetProperties};
	__property TcxPivotGridGetTotalDisplayTextEvent OnGetTotalDisplayText = {read=FOnGetTotalDisplayText, write=FOnGetTotalDisplayText};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
private:
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxPivotGridField;	/* IcxPivotGridField */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {61CC4884-4510-4C28-86DC-EC0B984E56DA}
	operator _di_IcxPivotGridField()
	{
		_di_IcxPivotGridField intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridField*(void) { return (IcxPivotGridField*)&__IcxPivotGridField; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {CFCAC754-EC31-4A72-8BED-1D9D2715E062}
	operator _di_IcxPivotGridSizableObject()
	{
		_di_IcxPivotGridSizableObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridSizableObject*(void) { return (IcxPivotGridSizableObject*)&__IcxPivotGridField; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxStoredObject; }
	#endif
	
};


class DELPHICLASS TcxPivotGridOLAPFieldOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOLAPFieldOptions : public TcxPivotGridFieldOptions
{
	typedef TcxPivotGridFieldOptions inherited;
	
private:
	TcxPivotGridOLAPKPIGraphicType FKPIGraphicType;
	bool __fastcall IsKPIGraphicTypeStored(void);
	void __fastcall SetKPIGraphicType(TcxPivotGridOLAPKPIGraphicType AValue);
	
protected:
	virtual bool __fastcall CanFiltering(void);
	virtual bool __fastcall CanSorting(void);
	
public:
	__fastcall virtual TcxPivotGridOLAPFieldOptions(TcxPivotGridField* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxPivotGridOLAPKPIGraphicType KPIGraphicType = {read=FKPIGraphicType, write=SetKPIGraphicType, stored=IsKPIGraphicTypeStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPivotGridOLAPFieldOptions(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridOLAPFieldSortMode : unsigned char { osmValue, osmDisplayText, osmKey, osmID, osmNone };

class PASCALIMPLEMENTATION TcxPivotGridOLAPField : public TcxPivotGridField
{
	typedef TcxPivotGridField inherited;
	
private:
	TcxPivotGridOLAPFieldType FFieldType;
	TcxPivotGridOLAPFieldSortMode FSortMode;
	TcxPivotGridOLAPStructureNode* FStructure;
	System::UnicodeString __fastcall GetDimensionUniqueName(void);
	TcxPivotGridOLAPFieldType __fastcall GetFieldType(void);
	System::UnicodeString __fastcall GetHierarchyUniqueName(void);
	TcxOLAPKPIType __fastcall GetKPIType(void);
	int __fastcall GetLevelNumber(void);
	System::UnicodeString __fastcall GetLevelUniqueName(void);
	TcxPivotGridOLAPFieldOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetOptions(TcxPivotGridOLAPFieldOptions* AValue);
	void __fastcall SetSortMode(TcxPivotGridOLAPFieldSortMode AValue);
	void __fastcall SetStructure(TcxPivotGridOLAPStructureNode* AValue);
	
protected:
	void __fastcall AssignFromUnboundField(TcxPivotGridField* AField);
	virtual TcxPivotGridFieldOptions* __fastcall CreateOptions(void);
	virtual System::UnicodeString __fastcall GetActualDisplayFormat(void);
	virtual TcxPivotGridFieldAreas __fastcall GetAllowedAreas(void);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual TcxPivotGridDataCellViewInfoClass __fastcall GetCellViewInfoClass(void);
	bool __fastcall GetIsMeasure(void);
	virtual System::UnicodeString __fastcall GetUniqueName(void);
	virtual bool __fastcall IsAllowedAreasStored(void);
	virtual bool __fastcall IsEqual(TcxPivotGridOLAPStructureNode* const AStructure);
	
public:
	__fastcall virtual ~TcxPivotGridOLAPField(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	int __fastcall FilteredValueCount(TcxPivotGridField* AField, bool IsExpanding = false);
	virtual bool __fastcall IsFiltered(void);
	__classmethod System::Classes::TStrings* __fastcall PopulateFilteredValues(TcxPivotGridField* AField, bool IsExpanding = false);
	__property System::UnicodeString DimensionUniqueName = {read=GetDimensionUniqueName};
	__property System::UnicodeString HierarchyUniqueName = {read=GetHierarchyUniqueName};
	__property bool IsMeasure = {read=GetIsMeasure, nodefault};
	__property TcxOLAPKPIType KPIType = {read=GetKPIType, nodefault};
	__property int LevelNumber = {read=GetLevelNumber, nodefault};
	__property System::UnicodeString LevelUniqueName = {read=GetLevelUniqueName};
	__property TcxPivotGridOLAPStructureNode* Structure = {read=FStructure, write=SetStructure};
	
__published:
	__property TcxPivotGridOLAPFieldOptions* Options = {read=GetOptions, write=SetOptions};
	__property TcxPivotGridOLAPFieldType FieldType = {read=GetFieldType, write=FFieldType, nodefault};
	__property TcxPivotGridOLAPFieldSortMode SortMode = {read=FSortMode, write=SetSortMode, default=0};
public:
	/* TcxPivotGridField.Create */ inline __fastcall virtual TcxPivotGridOLAPField(System::Classes::TComponent* AOwner) : TcxPivotGridField(AOwner) { }
	
};


class DELPHICLASS TcxPivotGridFieldGroupCollection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFieldGroup : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
public:
	TcxPivotGridField* operator[](int AIndex) { return Fields[AIndex]; }
	
private:
	System::UnicodeString FCaption;
	System::UnicodeString FUniqueName;
	bool FIsCaptionAssigned;
	TcxPivotGridFieldArea __fastcall GetArea(void);
	int __fastcall GetAreaIndex(void);
	System::UnicodeString __fastcall GetCaption(void);
	TcxPivotGridField* __fastcall GetField(int AIndex);
	int __fastcall GetFieldCount(void);
	TcxPivotGridFieldGroupCollection* __fastcall GetGroups(void);
	bool __fastcall GetIsDestroying(void);
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	bool __fastcall GetVisible(void);
	int __fastcall GetVisibleCount(void);
	void __fastcall SetArea(TcxPivotGridFieldArea AValue);
	void __fastcall SetAreaIndex(int AValue);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall ReadUniqueName(System::Classes::TReader* AReader);
	void __fastcall WriteUniqueName(System::Classes::TWriter* AWriter);
	
protected:
	System::Classes::TList* FieldList;
	virtual bool __fastcall CanDropTo(TcxPivotGridFieldArea AArea, int AIndex);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	int __fastcall GetLatestIndex(void);
	TcxPivotGridField* __fastcall GetNextField(TcxPivotGridField* AField);
	virtual void __fastcall GroupChanged(void);
	void __fastcall InternalSetArea(TcxPivotGridFieldArea AArea);
	bool __fastcall IsEqual(TcxPivotGridOLAPStructureNode* const AStructure);
	bool __fastcall IsSameDropPlace(int AIndex);
	void __fastcall ResetIndexes(int &ANewIndex);
	void __fastcall SetExpanded(bool AExpanded);
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property System::UnicodeString UniqueName = {read=FUniqueName, write=FUniqueName};
	
public:
	__fastcall virtual TcxPivotGridFieldGroup(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxPivotGridFieldGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Add(TcxPivotGridField* AField);
	void __fastcall AddFields(TcxPivotGridField* *AFields, const int AFields_Size);
	void __fastcall Clear(void);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	int __fastcall IndexOf(TcxPivotGridField* AField);
	void __fastcall Insert(int AIndex, TcxPivotGridField* AField);
	bool __fastcall IsFieldVisible(TcxPivotGridField* AField);
	bool __fastcall IsLastVisibleField(TcxPivotGridField* AField);
	void __fastcall Remove(TcxPivotGridField* AField);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxPivotGridField* Fields[int AIndex] = {read=GetField/*, default*/};
	__property TcxPivotGridFieldGroupCollection* Groups = {read=GetGroups};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	
__published:
	__property TcxPivotGridFieldArea Area = {read=GetArea, write=SetArea, stored=false, nodefault};
	__property int AreaIndex = {read=GetAreaIndex, write=SetAreaIndex, stored=false, nodefault};
	__property bool IsCaptionAssigned = {read=FIsCaptionAssigned, write=FIsCaptionAssigned, nodefault};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=FIsCaptionAssigned};
	__property bool Visible = {read=GetVisible, write=SetVisible, stored=false, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFieldGroupCollection : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxPivotGridFieldGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomPivotGrid* FOwner;
	HIDESBASE TcxPivotGridFieldGroup* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxPivotGridFieldGroup* AValue);
	
protected:
	virtual bool __fastcall CanDropTo(TcxPivotGridFieldArea AArea, int AIndex);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxPivotGridFieldGroupCollection(TcxCustomPivotGrid* AOwner)/* overload */;
	HIDESBASE TcxPivotGridFieldGroup* __fastcall Add(void);
	__property TcxCustomPivotGrid* PivotGrid = {read=FOwner};
	__property TcxPivotGridFieldGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxPivotGridFieldGroupCollection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridCustomPopupMenu;
class DELPHICLASS TcxPivotGridPopupMenus;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomPopupMenu : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Menus::TPopupMenu* FBuiltInMenu;
	TcxPivotGridPopupMenus* FOwner;
	System::Classes::TComponent* FPopupMenu;
	bool FUseBuiltInMenu;
	TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	Vcl::Menus::TMenuItem* __fastcall GetRoot(void);
	void __fastcall SetPopupMenu(System::Classes::TComponent* AValue);
	
protected:
	virtual void __fastcall AssignValues(TcxPivotGridCustomPopupMenu* ASource);
	void __fastcall CreateInternalMenu(void);
	virtual void __fastcall CreateItems(void);
	Vcl::Menus::TMenuItem* __fastcall CreateSeparator(Vcl::Menus::TMenuItem* AOwner);
	Vcl::Menus::TMenuItem* __fastcall CreateSubItem(Vcl::Menus::TMenuItem* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true);
	virtual void __fastcall DoExecute(int ACommand);
	void __fastcall ExecuteItem(Vcl::Menus::TMenuItem* AItem);
	Vcl::Menus::TMenuItem* __fastcall GetItemByCommand(int ACommand);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall MenuItemClickHandler(System::TObject* Sender);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property Vcl::Menus::TMenuItem* Root = {read=GetRoot};
	
public:
	__fastcall virtual TcxPivotGridCustomPopupMenu(TcxPivotGridPopupMenus* AOwner);
	__fastcall virtual ~TcxPivotGridCustomPopupMenu(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ExecuteCommand(int ACommand);
	virtual bool __fastcall Popup(int X, int Y);
	__property Vcl::Menus::TPopupMenu* BuiltInMenu = {read=FBuiltInMenu};
	__property TcxPivotGridPopupMenus* Owner = {read=FOwner};
	__property TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	
__published:
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property bool UseBuiltInMenu = {read=FUseBuiltInMenu, write=FUseBuiltInMenu, default=1};
};

#pragma pack(pop)

enum TcxPivotGridFieldHeaderPopupMenuItem : unsigned char { fpmiHide, fpmiOrder, fpmiFieldList };

typedef System::Set<TcxPivotGridFieldHeaderPopupMenuItem, TcxPivotGridFieldHeaderPopupMenuItem::fpmiHide, TcxPivotGridFieldHeaderPopupMenuItem::fpmiFieldList>  TcxPivotGridFieldHeaderPopupMenuItems;

class DELPHICLASS TcxPivotGridFieldHeaderMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFieldHeaderMenu : public TcxPivotGridCustomPopupMenu
{
	typedef TcxPivotGridCustomPopupMenu inherited;
	
private:
	TcxPivotGridField* FField;
	TcxPivotGridFieldHeaderPopupMenuItems FItems;
	TcxPivotGridCells* __fastcall GetFieldHeaders(void);
	TcxPivotGridFieldHeaderCellViewInfo* __fastcall GetFieldViewInfo(void);
	TcxPivotGridOptionsDataField* __fastcall GetOptionsDataField(void);
	bool __fastcall IsItemsStored(void);
	
protected:
	virtual void __fastcall AssignValues(TcxPivotGridCustomPopupMenu* ASource);
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	void __fastcall GetIndexes(int &AStart, int &APrev, int &ANext, int &AFinish);
	__property TcxPivotGridCells* FieldHeaders = {read=GetFieldHeaders};
	__property TcxPivotGridFieldHeaderCellViewInfo* FieldViewInfo = {read=GetFieldViewInfo};
	
public:
	__fastcall virtual TcxPivotGridFieldHeaderMenu(TcxPivotGridPopupMenus* AOwner);
	__property TcxPivotGridField* Field = {read=FField};
	__property TcxPivotGridOptionsDataField* OptionsDataField = {read=GetOptionsDataField};
	
__published:
	__property TcxPivotGridFieldHeaderPopupMenuItems Items = {read=FItems, write=FItems, stored=IsItemsStored, nodefault};
public:
	/* TcxPivotGridCustomPopupMenu.Destroy */ inline __fastcall virtual ~TcxPivotGridFieldHeaderMenu(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridGroupValuePopupMenuItem : unsigned char { vpmiExpandCollapse, vpmiExpandAll, vpmiCollapseAll };

typedef System::Set<TcxPivotGridGroupValuePopupMenuItem, TcxPivotGridGroupValuePopupMenuItem::vpmiExpandCollapse, TcxPivotGridGroupValuePopupMenuItem::vpmiCollapseAll>  TcxPivotGridGroupValuePopupMenuItems;

class DELPHICLASS TcxPivotGridGroupValueMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridGroupValueMenu : public TcxPivotGridCustomPopupMenu
{
	typedef TcxPivotGridCustomPopupMenu inherited;
	
private:
	TcxPivotGridGroupItem* FGroupItem;
	TcxPivotGridGroupValuePopupMenuItems FItems;
	bool __fastcall IsItemsStored(void);
	
protected:
	virtual void __fastcall AssignValues(TcxPivotGridCustomPopupMenu* ASource);
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	
public:
	__fastcall virtual TcxPivotGridGroupValueMenu(TcxPivotGridPopupMenus* AOwner);
	__property TcxPivotGridGroupItem* GroupItem = {read=FGroupItem};
	
__published:
	__property TcxPivotGridGroupValuePopupMenuItems Items = {read=FItems, write=FItems, stored=IsItemsStored, nodefault};
public:
	/* TcxPivotGridCustomPopupMenu.Destroy */ inline __fastcall virtual ~TcxPivotGridGroupValueMenu(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridHeaderAreaMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridHeaderAreaMenu : public TcxPivotGridCustomPopupMenu
{
	typedef TcxPivotGridCustomPopupMenu inherited;
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
public:
	/* TcxPivotGridCustomPopupMenu.Create */ inline __fastcall virtual TcxPivotGridHeaderAreaMenu(TcxPivotGridPopupMenus* AOwner) : TcxPivotGridCustomPopupMenu(AOwner) { }
	/* TcxPivotGridCustomPopupMenu.Destroy */ inline __fastcall virtual ~TcxPivotGridHeaderAreaMenu(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxPivotGridPopupMenuClickEvent)(TcxCustomPivotGrid* Sender, Vcl::Menus::TMenuItem* AItem, bool &AHandled);

typedef void __fastcall (__closure *TcxPivotGridPopupMenuPopupEvent)(TcxCustomPivotGrid* Sender, TcxPivotGridCustomPopupMenu* ABuiltInMenu, bool &AHandled);

class PASCALIMPLEMENTATION TcxPivotGridPopupMenus : public TcxPivotGridCustomOptions
{
	typedef TcxPivotGridCustomOptions inherited;
	
private:
	TcxPivotGridFieldHeaderMenu* FFieldHeaderMenu;
	TcxPivotGridGroupValueMenu* FGroupValueMenu;
	TcxPivotGridHeaderAreaMenu* FHeaderAreaMenu;
	TcxPivotGridPopupMenuClickEvent FOnClick;
	TcxPivotGridPopupMenuPopupEvent FOnPopup;
	TcxPivotGridHitTest* __fastcall GetHitTest(void);
	void __fastcall SetFieldHeaderMenu(TcxPivotGridFieldHeaderMenu* AValue);
	void __fastcall SetGroupValueMenu(TcxPivotGridGroupValueMenu* AValue);
	void __fastcall SetHeaderAreaMenu(TcxPivotGridHeaderAreaMenu* AValue);
	
protected:
	virtual TcxPivotGridFieldHeaderMenu* __fastcall CreateFieldHeaderMenu(void);
	virtual TcxPivotGridGroupValueMenu* __fastcall CreateGroupValueMenu(void);
	virtual TcxPivotGridHeaderAreaMenu* __fastcall CreateHeaderAreaMenu(void);
	virtual void __fastcall CreateMenus(void);
	virtual void __fastcall DestroyMenus(void);
	virtual void __fastcall DoOnClick(Vcl::Menus::TMenuItem* AItem, bool &AHandled);
	virtual void __fastcall DoOnPopup(TcxPivotGridCustomPopupMenu* ASender, bool &AHandled);
	virtual bool __fastcall DoShowPopupMenu(const System::Types::TPoint &P);
	virtual void __fastcall MenuItemClickHandler(System::TObject* Sender);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property TcxPivotGridHitTest* HitTest = {read=GetHitTest};
	
public:
	__fastcall virtual TcxPivotGridPopupMenus(TcxCustomPivotGrid* AOwner);
	__fastcall virtual ~TcxPivotGridPopupMenus(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxPivotGridFieldHeaderMenu* FieldHeaderMenu = {read=FFieldHeaderMenu, write=SetFieldHeaderMenu};
	__property TcxPivotGridGroupValueMenu* GroupValueMenu = {read=FGroupValueMenu, write=SetGroupValueMenu};
	__property TcxPivotGridHeaderAreaMenu* HeaderAreaMenu = {read=FHeaderAreaMenu, write=SetHeaderAreaMenu};
	__property TcxPivotGridPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxPivotGridPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
};


__interface IcxPivotGridDesignerIntf;
typedef System::DelphiInterface<IcxPivotGridDesignerIntf> _di_IcxPivotGridDesignerIntf;
__interface  INTERFACE_UUID("{DA451370-2F02-43D0-9F31-C25D7632E004}") IcxPivotGridDesignerIntf  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanRetrieveFields(bool &AIsActive) = 0 ;
	virtual TcxPivotGridField* __fastcall CreateField(void) = 0 ;
	virtual void __fastcall DoCreateAllFields(void) = 0 ;
};

class DELPHICLASS TcxPivotGridExportController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridExportController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomPivotGrid* FPivotGrid;
	bool __fastcall GetExpandColumns(void);
	bool __fastcall GetExpandRows(void);
	TcxPivotGridOptionsView* __fastcall GetOptionsView(void);
	TcxPivotGridStyles* __fastcall GetStyles(void);
	TcxPivotGridViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetExpandColumns(bool AValue);
	void __fastcall SetExpandRows(bool AValue);
	
protected:
	bool FSavedBorders;
	bool FSavedExpandButtons;
	TcxPivotGridOptionsView* FSavedOptionsView;
	TcxPivotGridOptionsPrefilter* FSavedPrefilterOptions;
	TcxPivotGridStyles* FSavedStyles;
	virtual void __fastcall Finalize(void);
	virtual void __fastcall Initialize(void);
	
public:
	__fastcall virtual TcxPivotGridExportController(TcxCustomPivotGrid* APivotGrid);
	__fastcall virtual ~TcxPivotGridExportController(void);
	TcxPivotGridViewInfo* __fastcall CalculateViewInfo(void);
	void __fastcall ReplaceStyles(_di_IcxPivotGridBaseStyles AStyles);
	__property bool ExpandRows = {read=GetExpandRows, write=SetExpandRows, nodefault};
	__property bool ExpandColumns = {read=GetExpandColumns, write=SetExpandColumns, nodefault};
	__property TcxPivotGridOptionsView* OptionsView = {read=GetOptionsView};
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
	__property TcxPivotGridStyles* Styles = {read=GetStyles};
	__property TcxPivotGridViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFilterMRUItem : public Cxclasses::TcxMRUItem
{
	typedef Cxclasses::TcxMRUItem inherited;
	
private:
	System::UnicodeString __fastcall GetCaption(void);
	
protected:
	bool __fastcall StreamEquals(System::Classes::TMemoryStream* AStream);
	
public:
	Cxcustomdata::TcxDataFilterCriteria* Filter;
	__fastcall TcxPivotGridFilterMRUItem(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	__fastcall virtual ~TcxPivotGridFilterMRUItem(void);
	void __fastcall AssignTo(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	virtual bool __fastcall Equals(Cxclasses::TcxMRUItem* AItem);
	bool __fastcall FilterEquals(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	System::Classes::TMemoryStream* __fastcall GetStream(void);
	__property System::UnicodeString Caption = {read=GetCaption};
};

#pragma pack(pop)

class DELPHICLASS TcxPivotGridFilterMRUItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridFilterMRUItems : public Cxclasses::TcxMRUItems
{
	typedef Cxclasses::TcxMRUItems inherited;
	
public:
	TcxPivotGridFilterMRUItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomPivotGrid* FPivotGrid;
	System::Classes::TList* FVisibleItems;
	HIDESBASE TcxPivotGridFilterMRUItem* __fastcall GetItem(int Index);
	int __fastcall GetVisibleCount(void);
	TcxPivotGridFilterMRUItem* __fastcall GetVisibleItem(int Index);
	void __fastcall SetVisibleCount(int AValue);
	
protected:
	void __fastcall RefreshVisibleItemsList(void);
	
public:
	__fastcall virtual TcxPivotGridFilterMRUItems(TcxCustomPivotGrid* APivotGrid);
	__fastcall virtual ~TcxPivotGridFilterMRUItems(void);
	HIDESBASE void __fastcall Add(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	bool __fastcall IsEmpty(void);
	__property TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid};
	__property TcxPivotGridFilterMRUItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int VisibleCount = {read=GetVisibleCount, write=SetVisibleCount, nodefault};
	__property TcxPivotGridFilterMRUItem* VisibleItems[int Index] = {read=GetVisibleItem};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxPivotGridCompareEvent)(TcxCustomPivotGrid* Sender, TcxPivotGridField* AField, const System::Variant &AValue1, const System::Variant &AValue2, int &Compare);

typedef void __fastcall (__closure *TcxPivotGridCustomDrawFieldHeaderEvent)(TcxCustomPivotGrid* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridFieldHeaderCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridCustomDrawGroupHeaderEvent)(TcxCustomPivotGrid* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridHeaderCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridCustomDrawCellEvent)(TcxCustomPivotGrid* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridDataCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridCustomDrawPartEvent)(TcxCustomPivotGrid* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxPivotGridFieldChangedEvent)(TcxCustomPivotGrid* Sender, TcxPivotGridField* AField);

class PASCALIMPLEMENTATION TcxCustomPivotGrid : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxPivotGridChanges FChanges;
	TcxPivotGridController* FController;
	TcxPivotGridCustomization* FCustomization;
	bool FCustomSortAssigned;
	TcxPivotGridDataBuilder* FDataBuilder;
	Cxcustomdata::TcxCustomDataController* FDataController;
	Vcl::Imglist::TCustomImageList* FFieldHeaderImages;
	Cxclasses::TcxObjectList* FFields;
	TcxPivotGridFields* FFilterableFields;
	Vcl::Imglist::TCustomImageList* FGroupHeaderImages;
	TcxPivotGridFieldGroupCollection* FGroups;
	bool FHasSummaryVariation;
	TcxPivotGridHitTest* FHitTest;
	int FHourglassCursorRefCount;
	Vcl::Imglist::TChangeLink* FImagesListener;
	bool FIsRestoring;
	System::Classes::TInterfaceList* FListeners;
	int FLockCount;
	Cxnavigator::TcxNavigatorControlNotifier* FNavigatorNotifier;
	TcxPivotGridCustomOLAPDataSource* FOLAPDataSource;
	TcxPivotGridOptionsBehavior* FOptionsBehavior;
	TcxPivotGridOptionsCustomize* FOptionsCustomize;
	TcxPivotGridOptionsData* FOptionsData;
	TcxPivotGridOptionsDataField* FOptionsDataField;
	TcxPivotGridOptionsPrefilter* FOptionsPrefilter;
	TcxPivotGridOptionsSelection* FOptionsSelection;
	TcxPivotGridOptionsView* FOptionsView;
	TcxPivotGridPainter* FPainter;
	TcxPivotGridPopupMenus* FPopupMenus;
	TcxPivotGridFilterMRUItems* FPrefilterMRUItems;
	TcxPivotGridFields* FSummaryFields;
	TcxPivotGridStyles* FStyles;
	TcxPivotGridViewData* FViewData;
	TcxPivotGridViewInfo* FViewInfo;
	System::Classes::TNotifyEvent FPopupMenusEvents;
	System::Classes::TNotifyEvent FStylesEvents;
	TcxPivotGridCompareEvent FOnCompare;
	TcxPivotGridCustomDrawFieldHeaderEvent FOnCustomDrawFieldHeader;
	TcxPivotGridCustomDrawGroupHeaderEvent FOnCustomDrawColumnHeader;
	TcxPivotGridCustomDrawGroupHeaderEvent FOnCustomDrawRowHeader;
	TcxPivotGridCustomDrawCellEvent FOnCustomDrawCell;
	TcxPivotGridCustomDrawPartEvent FOnCustomDrawPart;
	System::Classes::TNotifyEvent FOnCustomization;
	TcxPivotGridFieldChangedEvent FOnFieldPosChanged;
	TcxPivotGridFieldChangedEvent FOnFieldSizeChanged;
	System::Classes::TNotifyEvent FOnFilterChanged;
	System::Classes::TNotifyEvent FOnPrefilterDialogShow;
	System::Classes::TNotifyEvent FOnLayoutChanged;
	System::Classes::TNotifyEvent FOnSelectionChanged;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxInitStoredObjectEvent FOnInitStoredObject;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	int __fastcall GetFieldCount(void);
	TcxPivotGridField* __fastcall GetField(int AIndex);
	bool __fastcall GetIsLocked(void);
	int __fastcall GetRecordCount(void);
	int __fastcall GetRowLevelIndentWidth(void);
	void __fastcall SetCustomization(TcxPivotGridCustomization* AValue);
	void __fastcall SetField(int AIndex, TcxPivotGridField* AValue);
	void __fastcall SetFieldHeaderImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetGroupHeaderImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetGroups(TcxPivotGridFieldGroupCollection* AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* &AField, Vcl::Imglist::TCustomImageList* ANewValue);
	void __fastcall SetOLAPDataSource(TcxPivotGridCustomOLAPDataSource* AValue);
	void __fastcall SetOptionsBehavior(TcxPivotGridOptionsBehavior* AValue);
	void __fastcall SetOptionsCustomize(TcxPivotGridOptionsCustomize* AValue);
	void __fastcall SetOptionsData(TcxPivotGridOptionsData* AValue);
	void __fastcall SetOptionsDataField(TcxPivotGridOptionsDataField* AValue);
	void __fastcall SetOptionsPrefilter(TcxPivotGridOptionsPrefilter* AValue);
	void __fastcall SetOptionsSelection(TcxPivotGridOptionsSelection* AValue);
	void __fastcall SetOptionsView(TcxPivotGridOptionsView* AValue);
	void __fastcall SetPopupMenus(TcxPivotGridPopupMenus* AValue);
	void __fastcall SetStyles(TcxPivotGridStyles* AValue);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMRefreshCustomization(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	void __fastcall RestoreFrom(Cxstorage::TcxStorageType AStorageType, const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool ACreateChildren, bool ADeleteChildren);
	void __fastcall StoreTo(Cxstorage::TcxStorageType AStorageType, const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool AReCreate = true);
	
protected:
	bool NeedUpdateScrollBarsPost;
	System::TDateTime RefreshDate;
	void __fastcall AddField(TcxPivotGridField* AField);
	void __fastcall RemoveField(TcxPivotGridField* AField);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall BoundsChanged(void);
	void __fastcall CheckChanges(void);
	void __fastcall CheckUpdateScrollBars(void);
	virtual void __fastcall ClearCacheInformation(void);
	virtual void __fastcall CreateSubClasses(void);
	void __fastcall DestroyEditViewDatas(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DataSourceChanged(void);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	void __fastcall FilterControlDialogApply(System::TObject* Sender);
	void __fastcall HideHourglassCursor(void);
	void __fastcall ImagesChangeHandler(System::TObject* Sender);
	HIDESBASE bool __fastcall IsDestroying(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	HIDESBASE bool __fastcall IsLoading(void);
	bool __fastcall IsOLAPActive(void);
	bool __fastcall IsPrefilterEnabled(void);
	bool __fastcall IsRestoring(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall RefreshFilterableFieldsList(void);
	void __fastcall ShowHourglassCursor(void);
	void __fastcall UpdateMRUItems(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual TcxPivotGridFieldClass __fastcall GetFieldClass(void);
	virtual void __fastcall Loaded(void);
	virtual TcxPivotGridController* __fastcall CreateController(void);
	virtual TcxPivotGridCustomization* __fastcall CreateCustomization(void);
	virtual TcxPivotGridDataBuilder* __fastcall CreateDataBuilder(void);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall CreateDataController(void);
	virtual TcxPivotGridFieldGroupCollection* __fastcall CreateGroups(void);
	virtual TcxPivotGridHitTest* __fastcall CreateHitTest(void);
	virtual TcxPivotGridOptionsBehavior* __fastcall CreateOptionsBehavior(void);
	virtual TcxPivotGridOptionsCustomize* __fastcall CreateOptionsCustomize(void);
	virtual TcxPivotGridOptionsData* __fastcall CreateOptionsData(void);
	virtual TcxPivotGridOptionsDataField* __fastcall CreateOptionsDataField(void);
	virtual TcxPivotGridOptionsPrefilter* __fastcall CreateOptionsPrefilter(void);
	virtual TcxPivotGridOptionsSelection* __fastcall CreateOptionsSelection(void);
	virtual TcxPivotGridOptionsView* __fastcall CreateOptionsView(void);
	virtual TcxPivotGridPainter* __fastcall CreatePainter(void);
	virtual TcxPivotGridPopupMenus* __fastcall CreatePopupMenus(void);
	virtual TcxPivotGridStyles* __fastcall CreateStyles(void);
	virtual TcxPivotGridViewData* __fastcall CreateViewData(void);
	virtual TcxPivotGridViewInfo* __fastcall CreateViewInfo(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DoCompare(TcxPivotGridField* AField, const System::Variant &AValue1, const System::Variant &AValue2, int &Compare);
	virtual void __fastcall DoCustomDrawFieldHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridFieldHeaderCellViewInfo* ACell, bool &ADone);
	virtual void __fastcall DoCustomDrawColumnHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridHeaderCellViewInfo* ACell, bool &ADone);
	virtual void __fastcall DoCustomDrawPart(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridCustomCellViewInfo* ACell, bool &ADone);
	virtual void __fastcall DoCustomDrawRowHeader(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridHeaderCellViewInfo* ACell, bool &ADone);
	virtual void __fastcall DoCustomDrawCell(Cxgraphics::TcxCanvas* ACanvas, TcxPivotGridDataCellViewInfo* ACell, bool &ADone);
	virtual void __fastcall DoCustomization(void);
	virtual void __fastcall DoFieldPosChanged(TcxPivotGridField* AField);
	virtual void __fastcall DoFieldSizeChanged(TcxPivotGridField* AField);
	void __fastcall DoFilterChanged(void);
	virtual void __fastcall DoLayoutChanged(void);
	void __fastcall DoPrefilterChanged(void);
	virtual void __fastcall DoSelectionChanged(void);
	virtual void __fastcall EraseBackground(HDC DC)/* overload */;
	DYNAMIC void __fastcall FocusChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall GetIsFocused(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual bool __fastcall HasBackground(void);
	bool __fastcall IsDesignerAvailable(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	void __fastcall RecreatePainter(void);
	void __fastcall RecreateViewInfo(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall SelectionChanged(void);
	virtual void __fastcall SendNotification(TcxPivotGridChanges AChanges);
	bool __fastcall SetFieldAreaIndex(System::Classes::TPersistent* AField, TcxPivotGridFieldArea AArea, int &AIndex);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	void __fastcall ViewChanged(void);
	System::TObject* __fastcall GetItem(int Index);
	int __fastcall GetItemID(System::TObject* AItem);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
	virtual bool __fastcall CanRetrieveFields(bool &AIsActive);
	virtual void __fastcall DoCreateAllFields(void);
	virtual System::UnicodeString __fastcall GetCaption(int Index);
	int __fastcall GetCount(void);
	Cxfilter::TcxFilterCriteria* __fastcall GetCriteria(void);
	System::TObject* __fastcall GetItemLink(int Index);
	int __fastcall GetItemLinkID(int Index);
	System::UnicodeString __fastcall GetItemLinkName(int Index);
	System::UnicodeString __fastcall GetFieldName(int Index);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(int Index)/* overload */;
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueType(int Index);
	bool __fastcall CanAppend(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanEdit(void);
	bool __fastcall CanInsert(void);
	bool __fastcall IsActive(void);
	bool __fastcall IsBof(void);
	bool __fastcall IsBookmarkAvailable(void);
	bool __fastcall IsEditing(void);
	bool __fastcall IsEof(void);
	void __fastcall ClearBookmark(void);
	void __fastcall DoAction(int AButtonIndex);
	Cxnavigator::TcxNavigatorControlNotifier* __fastcall GetNotifier(void);
	bool __fastcall IsActionSupported(int AButtonIndex);
	System::UnicodeString __fastcall StoredObject_GetObjectName(void);
	virtual bool __fastcall StoredObject_GetProperties(System::Classes::TStrings* AProperties)/* overload */;
	virtual void __fastcall StoredObject_GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall StoredObject_SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall StoredParent_CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredParent_DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall StoredParent_GetChildren(System::Classes::TStringList* AChildren);
	__property BorderStyle = {default=1};
	__property TcxPivotGridChanges Changes = {read=FChanges, write=FChanges, nodefault};
	__property TcxPivotGridController* Controller = {read=FController};
	__property bool CustomSortAssigned = {read=FCustomSortAssigned, nodefault};
	__property TcxPivotGridDataBuilder* DataBuilder = {read=FDataBuilder};
	__property Cxclasses::TcxObjectList* FieldList = {read=FFields};
	__property bool HasSummaryVariation = {read=FHasSummaryVariation, write=FHasSummaryVariation, nodefault};
	__property Vcl::Imglist::TChangeLink* ImagesListener = {read=FImagesListener};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property int LockCount = {read=FLockCount, write=FLockCount, nodefault};
	__property TcxPivotGridPainter* Painter = {read=FPainter};
	__property TcxPivotGridFilterMRUItems* PrefilterMRUItems = {read=FPrefilterMRUItems};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RowLevelIndentWidth = {read=GetRowLevelIndentWidth, nodefault};
	__property TcxPivotGridViewInfo* ViewInfo = {read=FViewInfo};
	__property TcxPivotGridCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property TcxPivotGridCustomDrawFieldHeaderEvent OnCustomDrawFieldHeader = {read=FOnCustomDrawFieldHeader, write=FOnCustomDrawFieldHeader};
	__property TcxPivotGridCustomDrawGroupHeaderEvent OnCustomDrawColumnHeader = {read=FOnCustomDrawColumnHeader, write=FOnCustomDrawColumnHeader};
	__property TcxPivotGridCustomDrawGroupHeaderEvent OnCustomDrawRowHeader = {read=FOnCustomDrawRowHeader, write=FOnCustomDrawRowHeader};
	__property TcxPivotGridCustomDrawCellEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=FOnCustomDrawCell};
	__property TcxPivotGridCustomDrawPartEvent OnCustomDrawPart = {read=FOnCustomDrawPart, write=FOnCustomDrawPart};
	__property System::Classes::TNotifyEvent OnCustomization = {read=FOnCustomization, write=FOnCustomization};
	__property TcxPivotGridFieldChangedEvent OnFieldPosChanged = {read=FOnFieldPosChanged, write=FOnFieldPosChanged};
	__property TcxPivotGridFieldChangedEvent OnFieldSizeChanged = {read=FOnFieldSizeChanged, write=FOnFieldSizeChanged};
	__property System::Classes::TNotifyEvent OnFilterChanged = {read=FOnFilterChanged, write=FOnFilterChanged};
	__property System::Classes::TNotifyEvent OnPrefilterDialogShow = {read=FOnPrefilterDialogShow, write=FOnPrefilterDialogShow};
	__property System::Classes::TNotifyEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	__property System::Classes::TNotifyEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
	
public:
	__fastcall virtual TcxCustomPivotGrid(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomPivotGrid(void);
	void __fastcall AddListener(_di_IcxPivotGridListener AListener);
	void __fastcall ApplyBestFit(void);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall CopyToClipboard(bool ACopyAll = false);
	virtual Cxcustomdata::TcxCustomDataSource* __fastcall CreateDrillDownDataSource(void);
	virtual TcxPivotGridField* __fastcall CreateField(void);
	void __fastcall DeleteAllFields(void);
	void __fastcall EndUpdate(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall ShowPrefilterDialog(void);
	void __fastcall FullRefresh(void);
	TcxPivotGridField* __fastcall GetFieldByName(const System::UnicodeString AName);
	void __fastcall LayoutChanged(void);
	void __fastcall RemoveListener(_di_IcxPivotGridListener AListener);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, bool ACreateChildren = false, bool ADeleteChildren = false);
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, bool ACreateChildren = false, bool ADeleteChildren = false);
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, bool ACreateChildren = false, bool ADeleteChildren = false);
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, bool AReCreate = true);
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, bool AReCreate = true);
	void __fastcall StoreToStream(System::Classes::TStream* AStream);
	virtual void __fastcall TranslationChanged(void);
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=FDataController};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property Vcl::Imglist::TCustomImageList* FieldHeaderImages = {read=FFieldHeaderImages, write=SetFieldHeaderImages};
	__property TcxPivotGridField* Fields[int Index] = {read=GetField, write=SetField};
	__property Font;
	__property Vcl::Imglist::TCustomImageList* GroupHeaderImages = {read=FGroupHeaderImages, write=SetGroupHeaderImages};
	__property TcxPivotGridFieldGroupCollection* Groups = {read=FGroups, write=SetGroups};
	__property TcxPivotGridHitTest* HitTest = {read=FHitTest};
	__property LookAndFeel;
	__property LookAndFeelPainter;
	__property TcxPivotGridCustomOLAPDataSource* OLAPDataSource = {read=FOLAPDataSource, write=SetOLAPDataSource};
	__property TcxPivotGridOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TcxPivotGridOptionsCustomize* OptionsCustomize = {read=FOptionsCustomize, write=SetOptionsCustomize};
	__property TcxPivotGridOptionsData* OptionsData = {read=FOptionsData, write=SetOptionsData};
	__property TcxPivotGridOptionsDataField* OptionsDataField = {read=FOptionsDataField, write=SetOptionsDataField};
	__property TcxPivotGridOptionsPrefilter* OptionsPrefilter = {read=FOptionsPrefilter, write=SetOptionsPrefilter};
	__property TcxPivotGridOptionsSelection* OptionsSelection = {read=FOptionsSelection, write=SetOptionsSelection};
	__property TcxPivotGridOptionsView* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property TcxPivotGridPopupMenus* PopupMenus = {read=FPopupMenus, write=SetPopupMenus};
	__property TcxPivotGridStyles* Styles = {read=FStyles, write=SetStyles};
	__property TcxPivotGridFields* SummaryFields = {read=FSummaryFields};
	__property TcxPivotGridViewData* ViewData = {read=FViewData};
	
__published:
	__property TcxPivotGridCustomization* Customization = {read=FCustomization, write=SetCustomization};
	__property System::Classes::TNotifyEvent PopupMenusEvents = {read=FPopupMenusEvents, write=FPopupMenusEvents};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FStylesEvents, write=FStylesEvents};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxInitStoredObjectEvent OnInitStoredObject = {read=FOnInitStoredObject, write=FOnInitStoredObject};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomPivotGrid(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect){ Cxcontrols::TcxControl::EraseBackground(ACanvas, ARect); }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxPivotGridDesignerIntf;	/* IcxPivotGridDesignerIntf */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxNavigator;	/* Cxnavigator::IcxNavigator */
	void *__IcxFilterControl;	/* Cxfiltercontrol::IcxFilterControl */
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DA451370-2F02-43D0-9F31-C25D7632E004}
	operator _di_IcxPivotGridDesignerIntf()
	{
		_di_IcxPivotGridDesignerIntf intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxPivotGridDesignerIntf*(void) { return (IcxPivotGridDesignerIntf*)&__IcxPivotGridDesignerIntf; }
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A15F80CA-DE56-47CB-B0EB-035D0BF90E9D}
	operator Cxnavigator::_di_IcxNavigator()
	{
		Cxnavigator::_di_IcxNavigator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigator*(void) { return (Cxnavigator::IcxNavigator*)&__IcxNavigator; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B9890E09-5400-428D-8F72-1FF8FD15937C}
	operator Cxfiltercontrol::_di_IcxFilterControl()
	{
		Cxfiltercontrol::_di_IcxFilterControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxfiltercontrol::IcxFilterControl*(void) { return (Cxfiltercontrol::IcxFilterControl*)&__IcxFilterControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6AF48CD0-3A0B-4BEC-AC88-5D323432A686}
	operator Cxstorage::_di_IcxStoredParent()
	{
		Cxstorage::_di_IcxStoredParent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredParent*(void) { return (Cxstorage::IcxStoredParent*)&__IcxStoredParent; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxSkinSupport; }
	#endif
	
};


__interface IcxPivotGridDesignerHelper;
typedef System::DelphiInterface<IcxPivotGridDesignerHelper> _di_IcxPivotGridDesignerHelper;
__interface  INTERFACE_UUID("{88DE8BF4-DCA9-4E8A-B5FA-B860CD01299C}") IcxPivotGridDesignerHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall AddListener(TcxCustomPivotGrid* APivotGrid) = 0 ;
	virtual void __fastcall RemoveListener(TcxCustomPivotGrid* APivotGrid) = 0 ;
	virtual void __fastcall Select(System::Classes::TPersistent* AObject, System::Classes::TShiftState AShift) = 0 ;
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject) = 0 ;
};

class DELPHICLASS TcxPivotGridCustomDesignHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomDesignHelper : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	void __fastcall RefreshListener(TcxCustomPivotGrid* APivotGrid);
public:
	/* TObject.Create */ inline __fastcall TcxPivotGridCustomDesignHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomDesignHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 gs_Background = System::Int8(0x0);
static const System::Int8 gs_ColumnHeader = System::Int8(0x1);
static const System::Int8 gs_ColumnHeaderArea = System::Int8(0x2);
static const System::Int8 gs_Content = System::Int8(0x3);
static const System::Int8 gs_DataHeaderArea = System::Int8(0x4);
static const System::Int8 gs_FieldHeader = System::Int8(0x5);
static const System::Int8 gs_FilterHeaderArea = System::Int8(0x6);
static const System::Int8 gs_FilterSeparator = System::Int8(0x7);
static const System::Int8 gs_HeaderBackground = System::Int8(0x8);
static const System::Int8 gs_Inactive = System::Int8(0x9);
static const System::Int8 gs_RowHeader = System::Int8(0xa);
static const System::Int8 gs_RowHeaderArea = System::Int8(0xb);
static const System::Int8 gs_Selected = System::Int8(0xc);
static const System::Int8 gs_Total = System::Int8(0xd);
static const System::Int8 gs_Prefilter = System::Int8(0xe);
static const System::Int8 gs_ColumnMaximumValue = System::Int8(0xf);
static const System::Int8 gs_ColumnMinimumValue = System::Int8(0x10);
static const System::Int8 gs_MaximumValue = System::Int8(0x11);
static const System::Int8 gs_MinimumValue = System::Int8(0x12);
static const System::Int8 gs_RowMaximumValue = System::Int8(0x13);
static const System::Int8 gs_RowMinimumValue = System::Int8(0x14);
static const System::Int8 gs_MaxStyleIndex = System::Int8(0x14);
static const System::Int8 htcButton = System::Int8(0x1);
static const System::Int8 htcDataCell = System::Int8(0x2);
static const System::Int8 htcDataHeader = System::Int8(0x3);
static const System::Int8 htcFieldHeader = System::Int8(0x4);
static const System::Int8 htcHeaderArea = System::Int8(0x5);
static const System::Int8 htcFilter = System::Int8(0x6);
static const System::Int8 htcGroupHeader = System::Int8(0x7);
static const System::Int8 htcHorzSizingEdge = System::Int8(0x8);
static const System::Int8 htcVertSizingEdge = System::Int8(0x9);
static const System::Int8 htcPrefilter = System::Int8(0xa);
static const System::Int8 htcPrefilterCloseButton = System::Int8(0xb);
static const System::Int8 htcPrefilterActivateButton = System::Int8(0xc);
static const System::Int8 htcPrefilterCustomizationButton = System::Int8(0xd);
static const System::Int8 htcPrefilterDropDownButton = System::Int8(0xe);
static const System::Int8 htcPrefilterCaption = System::Int8(0xf);
static const System::Int8 htcCustomizationForm = System::Int8(0x10);
static const System::Int8 htcFieldList = System::Int8(0x11);
static const System::Int8 htcFieldTreeView = System::Int8(0x12);
static const System::Int8 pgcmHide = System::Int8(0x0);
static const System::Int8 pgcmMoveToBeginning = System::Int8(0x1);
static const System::Int8 pgcmMoveToEnd = System::Int8(0x2);
static const System::Int8 pgcmMoveToLeft = System::Int8(0x3);
static const System::Int8 pgcmMoveToRight = System::Int8(0x4);
static const System::Int8 pgcmExpand = System::Int8(0x5);
static const System::Int8 pgcmCollapse = System::Int8(0x6);
static const System::Int8 pgcmExpandAll = System::Int8(0x7);
static const System::Int8 pgcmCollapseAll = System::Int8(0x8);
static const System::Int8 pgcmShowCustomization = System::Int8(0x9);
static const System::Int8 pgcmHideCustomization = System::Int8(0xa);
static const System::Int8 pgcmShowPrefilterDialog = System::Int8(0xb);
extern PACKAGE int cxPivotGridFilterSeparatorHeight;
static const System::Int8 cxPivotGridDefaultFieldWidth = System::Int8(0x69);
static const System::Byte cxPivotGridDefaultRowsTreeWidth = System::Byte(0xc8);
static const System::Int8 cxPivotGridDefaultFieldMinWidth = System::Int8(0x14);
static const System::Byte cxPivotGridFilterPopupMinWidth = System::Byte(0x96);
static const System::Int8 cxPivotGridFilterPopupMinHeight = System::Int8(0xf);
static const System::Byte cxPivotGridFilterPopupDefaultWidth = System::Byte(0x96);
static const System::Byte cxPivotGridFilterPopupDefaultHeight = System::Byte(0x96);
static const System::Int8 cxPivotGridFilterMinSysPanelHeight = System::Int8(0x1a);
static const System::Int8 cxPivotGridDropDownWidth = System::Int8(0x0);
static const System::Int8 cxPivotGridDropDownMaxItemCount = System::Int8(0xf);
static const System::Int8 cxPivotGridSpace = System::Int8(0x5);
static const System::Int8 cxPivotGridHorzSpace = System::Int8(0x3);
static const System::Int8 cxPivotGridHalfSpace = System::Int8(0x1);
static const System::Int8 cxPivotGridDoubleSpace = System::Int8(0x4);
static const System::Int8 cxPivotGridSizeAreaDelta = System::Int8(0x3);
static const System::Int8 cxPivotGridSizeMarkWidth = System::Int8(0x2);
static const System::Int8 cxPivotGridInvalidIndex = System::Int8(-1);
static const System::Int8 cxPivotGridOthersRecordIndex = System::Int8(-2);
static const System::Int8 cxPivotGridRecordVisible = System::Int8(-1);
static const System::Int8 cxPivotGridRecordInvisible = System::Int8(-2);
extern PACKAGE System::UnicodeString cxPivotGridDefaultFieldFloatFormat;
extern PACKAGE System::UnicodeString cxPivotGridDefaultFieldIntFormat;
extern PACKAGE System::UnicodeString cxPivotGridDefaultFieldPercentFormat;
static const System::Int8 cxPivotGridDefaultGroupIntervalRange = System::Int8(0xa);
extern PACKAGE System::WideChar cxPivotPatternChar;
static const System::Word cxPivotGridDropArrowColor = System::Word(0xff00);
extern PACKAGE int cxPivotGridAutoScrollInterval;
extern PACKAGE int cxPivotGridAutoScrollAreaWidth;
static const System::Int8 cxPivotGridControlsIndent = System::Int8(0x8);
static const System::Byte cxPivotGridCustomizationMinWidth = System::Byte(0xb4);
static const System::Byte cxPivotGridCustomizationMinHeight = System::Byte(0xb4);
static const System::Byte cxPivotGridCustomizationDefaultHeight = System::Byte(0xc8);
static const System::Byte cxPivotGridCustomizationDefaultWidth = System::Byte(0xc8);
extern PACKAGE _di_IcxPivotGridDesignerHelper DesignerHelper;
extern PACKAGE TcxPivotGridCustomizationFormClass cxPivotGridCustomizationFormClass;
extern PACKAGE TcxPivotGridCrossCellSummaryClass PivotGridCrossCellSummaryClass;
extern PACKAGE Vcl::Imglist::TCustomImageList* cxPivotGridPopupMenuImages;
extern PACKAGE System::UnicodeString __fastcall GetOLAPHierarchyLevelUniqueName(TcxPivotGridOLAPField* AField);
extern PACKAGE bool __fastcall IsOLAPHierarchy(TcxPivotGridGroupItem* AnItem);
extern PACKAGE bool __fastcall IsNotLastVisibleOLAPHierarchyItem(TcxPivotGridGroupItem* AnItem);
extern PACKAGE void __fastcall PivotGridError(bool ACondition, const System::UnicodeString AMessage);
extern PACKAGE Vcl::Controls::TImageList* __fastcall cxPivotGridHierarchyImages(void);
extern PACKAGE Cxgraphics::TcxImageList* __fastcall cxPivotGridKPIImageList(void);
}	/* namespace Cxcustompivotgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCUSTOMPIVOTGRID)
using namespace Cxcustompivotgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcustompivotgridHPP
