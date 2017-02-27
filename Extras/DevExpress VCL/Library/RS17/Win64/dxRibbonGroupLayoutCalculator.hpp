// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonGroupLayoutCalculator.pas' rev: 24.00 (Win64)

#ifndef DxribbongrouplayoutcalculatorHPP
#define DxribbongrouplayoutcalculatorHPP

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
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbongrouplayoutcalculator
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TRLCItemControlInfo;
class PASCALIMPLEMENTATION TRLCItemControlInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Dxbar::_di_IdxBarItemControlViewInfo ViewInfo;
	int OneRowItemsBefore;
	int OneRowItemsAfter;
public:
	/* TObject.Create */ inline __fastcall TRLCItemControlInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TRLCItemControlInfo(void) { }
	
};


class DELPHICLASS TSequenceForWholeGroupHeightReducing;
class PASCALIMPLEMENTATION TSequenceForWholeGroupHeightReducing : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
public:
	TRLCItemControlInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TRLCItemControlInfo* __fastcall GetItem(int Index);
	
public:
	__property TRLCItemControlInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TObjectList.Create */ inline __fastcall TSequenceForWholeGroupHeightReducing(void)/* overload */ : System::Contnrs::TObjectList() { }
	/* TObjectList.Create */ inline __fastcall TSequenceForWholeGroupHeightReducing(bool AOwnsObjects)/* overload */ : System::Contnrs::TObjectList(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TSequenceForWholeGroupHeightReducing(void) { }
	
};


class DELPHICLASS TdxRibbonGroupLayoutCalculator;
class PASCALIMPLEMENTATION TdxRibbonGroupLayoutCalculator : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	typedef System::DynamicArray<int> _TdxRibbonGroupLayoutCalculator__1;
	
	typedef System::DynamicArray<int> _TdxRibbonGroupLayoutCalculator__2;
	
	
private:
	int FColumnCount;
	int FGroupRowCount;
	int FGroupRowHeight;
	_TdxRibbonGroupLayoutCalculator__1 FItemControlColumns;
	int FItemControlIndexForOneRowHeightReducing;
	_TdxRibbonGroupLayoutCalculator__2 FItemControlSeparators;
	System::Contnrs::TObjectList* FReducingSequences;
	int X;
	void __fastcall AlignOneRowHeightItemControl(Dxbar::_di_IdxBarItemControlViewInfo AItemControlViewInfo, int AColumnWidth);
	void __fastcall AlignOneRowHeightItemControls(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int AFirstIndex, int AColumnWidth);
	void __fastcall CheckDistanceBetweenTwoLastColumns(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int ALastItemControlIndex);
	void __fastcall DistributeOneRowHeightItemControlsOnGroupHeight(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int AFirstIndex, int ALastIndex);
	int __fastcall GetGroupHeight(void);
	void __fastcall IncrementColumnCount(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int ALastItemControlIndex);
	void __fastcall OffsetContent(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int AFirstItemControlIndex, int ALastItemControlIndex, int AOffset);
	void __fastcall PlaceOneRowHeightItemControls(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int AFirstIndex, int ALastIndex, bool ADistributeOnGroupHeight);
	void __fastcall PlaceSeparator(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int AItemControlIndex);
	void __fastcall PlaceWholeGroupHeightItemControl(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, int AIndex);
	bool __fastcall ReduceOneRowHeightItemControlsWithText(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, Dxbar::TdxBarItemRealViewLevel AUpToViewLevel);
	bool __fastcall TryReduceToSmallIconWithText(TSequenceForWholeGroupHeightReducing* ASequence);
	bool __fastcall ReduceToSmallIconWithText(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
	bool __fastcall ReduceToLargeControlOnly(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
	
protected:
	__property int GroupRowCount = {read=FGroupRowCount, nodefault};
	__property int GroupRowHeight = {read=FGroupRowHeight, nodefault};
	
public:
	__fastcall TdxRibbonGroupLayoutCalculator(int AGroupRowHeight, int AGroupRowCount);
	__fastcall virtual ~TdxRibbonGroupLayoutCalculator(void);
	void __fastcall CalcInit(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
	void __fastcall CalcLayout(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
	bool __fastcall CollapseMultiColumnItemControls(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
	bool __fastcall DecreaseMultiColumnItemControlsColumnCount(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
	bool __fastcall Reduce(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo, Dxbar::TdxBarItemRealViewLevel AUpToViewLevel);
	void __fastcall ReduceInit(Dxribbon::_di_IdxRibbonGroupViewInfo AGroupViewInfo);
private:
	void *__IdxRibbonGroupLayoutCalculator;	/* Dxribbon::IdxRibbonGroupLayoutCalculator */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {894AC146-F69A-4ED2-9293-AA54AAAE1189}
	operator Dxribbon::_di_IdxRibbonGroupLayoutCalculator()
	{
		Dxribbon::_di_IdxRibbonGroupLayoutCalculator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbon::IdxRibbonGroupLayoutCalculator*(void) { return (Dxribbon::IdxRibbonGroupLayoutCalculator*)&__IdxRibbonGroupLayoutCalculator; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall CalcItemControlsRealPositionInButtonGroup(System::Classes::TList* AItemControlViewInfos);
}	/* namespace Dxribbongrouplayoutcalculator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONGROUPLAYOUTCALCULATOR)
using namespace Dxribbongrouplayoutcalculator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbongrouplayoutcalculatorHPP
