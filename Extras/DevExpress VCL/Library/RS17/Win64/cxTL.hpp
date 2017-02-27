// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTL.pas' rev: 24.00 (Win64)

#ifndef CxtlHPP
#define CxtlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxTLStrs.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLibraryConsts.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLookupEdit.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxTreeList;
class PASCALIMPLEMENTATION EcxTreeList : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxTreeList(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxTreeList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : System::Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxTreeList(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxTreeList(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxTreeList(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxTreeList(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxTreeList(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxTreeList(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxTreeList(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxTreeList(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxTreeList(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxTreeList(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxTreeList(void) { }
	
};


typedef System::TMetaClass* TcxCustomTreeListClass;

typedef System::TMetaClass* TcxTreeListOptionsCustomizingClass;

typedef System::TMetaClass* TcxTreeListCustomCellViewInfoClass;

typedef System::TMetaClass* TcxTreeListNodeClass;

typedef System::TMetaClass* TcxTreeListPreviewClass;

typedef System::StaticArray<int, 536870911> TIntArray;

typedef TIntArray *PIntArray;

enum TcxTreeListBandFixedKind : unsigned char { tlbfNone, tlbfLeft, tlbfRight };

enum TcxTreeListBandExpandable : unsigned char { tlbeDefault, tlbeExpandable, tlbeNotExpandable };

enum TcxTreeListGridLines : unsigned char { tlglNone, tlglHorz, tlglVert, tlglBoth };

enum TcxTreeListImageIndexType : unsigned char { tlitImageIndex, tlitSelectedIndex, tlitStateIndex, tlitOverlayIndex, tlitOverlayStateIndex };

typedef System::Set<TcxTreeListImageIndexType, TcxTreeListImageIndexType::tlitImageIndex, TcxTreeListImageIndexType::tlitOverlayStateIndex>  TcxTreeListImageIndexes;

enum TcxTreeListNodeAttachMode : unsigned char { tlamAdd, tlamAddFirst, tlamAddChild, tlamAddChildFirst, tlamInsert };

enum TcxTreeListNodeAddMode : unsigned char { tlnaAdd, tlnaAddFirst, tlnaInsert };

typedef System::StaticArray<System::Uitypes::TImageIndex, 5> TcxTreeListNodeImageIndexes;

class DELPHICLASS TcxTreeListNode;
typedef int __fastcall (*TcxTreeListCompareFunc)(TcxTreeListNode* AItem1, TcxTreeListNode* AItem2);

typedef System::StaticArray<Cxgraphics::TcxViewParams, 2> TcxCachedContentParams;

typedef bool __fastcall (*TcxTreeListFindFunc)(TcxTreeListNode* ANode, void * AData);

__interface IcxTreeListDesigner;
typedef System::DelphiInterface<IcxTreeListDesigner> _di_IcxTreeListDesigner;
__interface  INTERFACE_UUID("{1F4D4387-57E1-4756-9093-1124077A0F54}") IcxTreeListDesigner  : public System::IInterface 
{
	
public:
	virtual void __fastcall ComponentModified(void) = 0 ;
	virtual void __fastcall ComponentRemoved(System::TObject* Sender) = 0 ;
};

__interface IcxTreeListDesignTimeOperations;
typedef System::DelphiInterface<IcxTreeListDesignTimeOperations> _di_IcxTreeListDesignTimeOperations;
__interface  INTERFACE_UUID("{781A0614-EA26-4214-85D2-10C7DA2AF22B}") IcxTreeListDesignTimeOperations  : public System::IInterface 
{
	
public:
	virtual bool __fastcall SupportBandColumnEditor(void) = 0 ;
	virtual bool __fastcall SupportItemsEditor(void) = 0 ;
	virtual bool __fastcall SupportCreateAllItems(void) = 0 ;
	virtual void __fastcall CreateAllItems(void) = 0 ;
};

struct TcxTreeListNodeData;
typedef TcxTreeListNodeData *PcxTreeListNodeData;

struct DECLSPEC_DRECORD TcxTreeListNodeData
{
public:
	TcxTreeListNode* Node;
	void *NodeData;
};


enum TcxTreeListChange : unsigned char { tcStructure, tcData, tcLayout, tcImages, tcColumns, tcSortOrder, tcLoading, tcSelection, tcFocusedNode, tcSummary };

typedef System::Set<TcxTreeListChange, TcxTreeListChange::tcStructure, TcxTreeListChange::tcSummary>  TcxTreeListChanges;

struct DECLSPEC_DRECORD TcxTreeListSummaryInfo
{
public:
	System::Variant Value;
	System::Variant TempValue;
	int Count;
};


typedef System::DynamicArray<TcxTreeListSummaryInfo> TcxTreeListSummaryInfos;

enum TcxTreeListNodeState : unsigned char { nsDeleting, nsHasChildren, nsValuesAssigned, nsCollapsed, nsValidIndexes, nsInternalDelete, nsHidden, nsHeightAssigned, nsInserting, nsEditing, nsCheck, nsCheckStateInvalid, nsDisabled, nsSaveExpanded, nsReserved1 };

typedef System::Set<TcxTreeListNodeState, TcxTreeListNodeState::nsDeleting, TcxTreeListNodeState::nsReserved1>  TcxTreeListNodeStates;

enum TcxTreeListNodeCheckInfo : unsigned char { nciChecked, nciGrayed, nciAllowGrayed, nciCheckGroup, nciRadioGroup, nciCheckValid, nciChangeCheck };

typedef System::Set<TcxTreeListNodeCheckInfo, TcxTreeListNodeCheckInfo::nciChecked, TcxTreeListNodeCheckInfo::nciChangeCheck>  TcxTreeListNodeCheckInfos;

enum TcxTreeListNodeCheckGroupType : unsigned char { ncgNone, ncgCheckGroup, ncgRadioGroup };

class DELPHICLASS TcxCustomTreeList;
class DELPHICLASS TcxTreeListNodeViewData;
class DELPHICLASS TcxTreeListSummary;
class PASCALIMPLEMENTATION TcxTreeListNode : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TcxTreeListNode* operator[](int Index) { return Items[Index]; }
	
private:
	int FAbsoluteIndex;
	int FCount;
	void *FData;
	TcxTreeListNode* FFirst;
	void *FHandle;
	int FHeight;
	int FIndex;
	TcxTreeListNode* FLast;
	TcxTreeListNode* FNext;
	int FOriginalIndex;
	TcxCustomTreeList* FTreeList;
	TcxTreeListNode* FParent;
	TcxTreeListNode* FPrev;
	TcxTreeListNodeViewData* FViewData;
	int __fastcall GetAbsoluteIndex(void);
	bool __fastcall GetAllowGrayed(void);
	bool __fastcall GetChecked(void);
	int __fastcall GetCheckedCount(void);
	int __fastcall GetChildVisibleCount(void);
	TcxTreeListNodeCheckGroupType __fastcall GetCheckGroupType(void);
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetCheckState(void);
	bool __fastcall GetEnabled(void);
	bool __fastcall GetExpanded(void);
	bool __fastcall GetFocused(void);
	int __fastcall GetGrayedCount(void);
	bool __fastcall GetHasCheckbox(void);
	bool __fastcall GetHasChildren(void);
	bool __fastcall GetHasVisibleChildren(void);
	bool __fastcall GetHotTrack(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsDeleting(void);
	bool __fastcall GetIsEditing(void);
	bool __fastcall GetIsFirst(void);
	bool __fastcall GetIsGroupNode(void);
	bool __fastcall GetIsHidden(void);
	bool __fastcall GetIsLast(void);
	bool __fastcall GetIsPrinted(void);
	bool __fastcall GetIsRadioGroup(void);
	bool __fastcall GetIsVisible(void);
	TcxTreeListNode* __fastcall GetItem(int AIndex);
	int __fastcall GetLevel(void);
	TcxTreeListNode* __fastcall GetRoot(void);
	bool __fastcall GetSelected(void);
	TcxTreeListSummary* __fastcall GetSummary(void);
	System::Uitypes::TImageIndex __fastcall GetNodeImageIndex(int AIndex);
	System::UnicodeString __fastcall GetText(int AIndex);
	System::Variant __fastcall GetValue(int AIndex);
	int __fastcall GetValueCount(void);
	bool __fastcall GetVisible(void);
	int __fastcall GetVisibleIndex(void);
	void __fastcall AdjustIndexes(void);
	void __fastcall InternalInsert(TcxTreeListNode* AValue);
	void __fastcall SetAllowGrayed(bool AValue);
	void __fastcall SetChecked(bool AValue);
	void __fastcall SetCheckGroupType(TcxTreeListNodeCheckGroupType AValue);
	void __fastcall SetCheckState(Cxlookandfeelpainters::TcxCheckBoxState AValue);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetExpanded(bool AValue);
	void __fastcall SetFirst(TcxTreeListNode* AValue);
	void __fastcall SetFocused(bool AValue);
	void __fastcall SetFooterSummaryValue(int AIndex, System::Variant &AValue);
	void __fastcall SetHasChildren(bool AValue);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetItem(int AIndex, TcxTreeListNode* AValue);
	void __fastcall SetLast(TcxTreeListNode* AValue);
	void __fastcall SetNodeImageIndex(int AIndex, System::Uitypes::TImageIndex AValue);
	void __fastcall SetParentFor(TcxTreeListNode* AValue, bool AValidateIndexes = true);
	void __fastcall SetText(int AIndex, const System::UnicodeString AValue);
	void __fastcall SetSelected(bool AValue);
	void __fastcall SetValue(int AIndex, const System::Variant &AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	TcxTreeListNodeImageIndexes FImageIndexes;
	TcxTreeListSummaryInfos FSummaryInfo;
	int FVisibleIndex;
	TcxTreeListNodeCheckInfos CheckInfo;
	TcxTreeListNodeStates State;
	virtual void __fastcall AssignData(TcxTreeListNode* ASource);
	void __fastcall ExtractFromParent(void);
	virtual int __fastcall GetFooterSummaryCount(void);
	virtual System::UnicodeString __fastcall GetFooterSummaryText(int AIndex);
	virtual System::Variant __fastcall GetFooterSummaryValue(int AIndex);
	virtual bool __fastcall GetInserting(void);
	virtual bool __fastcall GetIsFirstVisible(void);
	virtual bool __fastcall GetIsLastVisible(void);
	virtual bool __fastcall GetIsRoot(void);
	TcxTreeListNode* __fastcall GetNextVisibleEx(bool IsPrev);
	TcxTreeListNode* __fastcall GetNextSiblingEx(TcxTreeListNode* ANode, bool AForward);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	TcxTreeListNode* __fastcall GetRootParent(void);
	void __fastcall InternalFree(void);
	virtual void __fastcall InitializeHandle(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream, int AVersion);
	virtual void __fastcall RestoreStateAfterRefresh(void);
	virtual void __fastcall SaveStateBeforeRefresh(void);
	void __fastcall SetChildrenCheckState(Cxlookandfeelpainters::TcxCheckBoxState AValue, TcxTreeListNode* AExclude);
	void __fastcall UpdateCheckStates(void);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	bool __fastcall CanSizing(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	System::Types::TRect __fastcall GetSizingBoundsRect(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	int __fastcall GetSizingIncrement(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	bool __fastcall IsDynamicUpdate(void);
	void __fastcall PopulateItems(Dxcoreclasses::TdxFastList* AList);
	void __fastcall SetSizeDelta(Cxinplacecontainer::TcxDragSizingDirection ADirection, int ADelta);
	void __fastcall UpdateItems(Dxcoreclasses::TdxFastList* AList);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	__property int CheckedCount = {read=GetCheckedCount, nodefault};
	__property int GrayedCount = {read=GetGrayedCount, nodefault};
	__property void * Handle = {read=FHandle, write=FHandle};
	__property int OriginalIndex = {read=FOriginalIndex, write=FOriginalIndex, nodefault};
	__property bool IsPrinted = {read=GetIsPrinted, nodefault};
	__property bool IsRadioGroup = {read=GetIsRadioGroup, nodefault};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property TcxTreeListSummary* Summary = {read=GetSummary};
	__property TcxTreeListNodeViewData* ViewData = {read=FViewData, write=FViewData};
	
public:
	__fastcall virtual TcxTreeListNode(TcxCustomTreeList* AOwner);
	__fastcall virtual ~TcxTreeListNode(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AssignValues(System::Variant const *AValues, const int AValues_Size);
	virtual TcxTreeListNode* __fastcall AddChild(void);
	virtual TcxTreeListNode* __fastcall AddChildFirst(void);
	void __fastcall AlphaSort(bool ARecurse = false);
	bool __fastcall CanCollapse(void);
	bool __fastcall CanExpand(void);
	bool __fastcall CanMove(TcxTreeListNode* ADest, TcxTreeListNodeAttachMode AMode);
	void __fastcall CheckClick(void);
	void __fastcall Collapse(bool Recurse);
	void __fastcall CustomSort(TcxTreeListCompareFunc ASortProc, bool ARecurse = false);
	void __fastcall Delete(void);
	void __fastcall DeleteChildren(void);
	System::Types::TRect __fastcall DisplayRect(bool AEntryOnly);
	void __fastcall EndEdit(bool Cancel);
	void __fastcall Expand(bool Recurse);
	TcxTreeListNode* __fastcall GetNext(void);
	TcxTreeListNode* __fastcall GetNextChild(TcxTreeListNode* ANode);
	TcxTreeListNode* __fastcall getNextSibling(void);
	TcxTreeListNode* __fastcall GetNextSiblingVisible(void);
	TcxTreeListNode* __fastcall GetNextVisible(void);
	TcxTreeListNode* __fastcall GetPrev(void);
	TcxTreeListNode* __fastcall GetPrevChild(TcxTreeListNode* ANode);
	TcxTreeListNode* __fastcall getPrevSibling(void);
	TcxTreeListNode* __fastcall GetPrevSiblingVisible(void);
	TcxTreeListNode* __fastcall GetPrevVisible(void);
	TcxTreeListNode* __fastcall getFirstChild(void);
	TcxTreeListNode* __fastcall GetFirstChildVisible(void);
	TcxTreeListNode* __fastcall GetLastChild(void);
	TcxTreeListNode* __fastcall GetLastChildVisible(void);
	bool __fastcall HasAsParent(TcxTreeListNode* ANode);
	int __fastcall IndexOf(TcxTreeListNode* ANode);
	virtual TcxTreeListNode* __fastcall InsertChild(TcxTreeListNode* ABeforeNode);
	void __fastcall Invalidate(void);
	bool __fastcall IsMultiThreadedSorting(void);
	bool __fastcall IsSibling(TcxTreeListNode* ANode);
	void __fastcall LoadChildren(void);
	void __fastcall MakeVisible(void);
	virtual void __fastcall MoveTo(TcxTreeListNode* ADestNode, TcxTreeListNodeAttachMode AMode);
	virtual void __fastcall Repaint(bool ARecalculate);
	__property int AbsoluteIndex = {read=GetAbsoluteIndex, nodefault};
	__property bool AllowGrayed = {read=GetAllowGrayed, write=SetAllowGrayed, nodefault};
	__property bool Checked = {read=GetChecked, write=SetChecked, nodefault};
	__property TcxTreeListNodeCheckGroupType CheckGroupType = {read=GetCheckGroupType, write=SetCheckGroupType, nodefault};
	__property Cxlookandfeelpainters::TcxCheckBoxState CheckState = {read=GetCheckState, write=SetCheckState, nodefault};
	__property int ChildVisibleCount = {read=GetChildVisibleCount, nodefault};
	__property int Count = {read=FCount, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property bool Deleting = {read=GetIsDeleting, nodefault};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property int FooterSummaryCount = {read=GetFooterSummaryCount, nodefault};
	__property System::UnicodeString FooterSummaryTexts[int Index] = {read=GetFooterSummaryText};
	__property System::Variant FooterSummaryValues[int Index] = {read=GetFooterSummaryValue, write=SetFooterSummaryValue};
	__property bool HasCheckbox = {read=GetHasCheckbox, nodefault};
	__property bool HasChildren = {read=GetHasChildren, write=SetHasChildren, nodefault};
	__property bool HasVisibleChildren = {read=GetHasVisibleChildren, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property bool HotTrack = {read=GetHotTrack, nodefault};
	__property System::Uitypes::TImageIndex ImageIndex = {read=GetNodeImageIndex, write=SetNodeImageIndex, index=0, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property bool Inserting = {read=GetInserting, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsFirst = {read=GetIsFirst, nodefault};
	__property bool IsFirstVisible = {read=GetIsFirstVisible, nodefault};
	__property bool IsGroupNode = {read=GetIsGroupNode, nodefault};
	__property bool IsHidden = {read=GetIsHidden, nodefault};
	__property bool IsLast = {read=GetIsLast, nodefault};
	__property bool IsLastVisible = {read=GetIsLastVisible, nodefault};
	__property bool IsVisible = {read=GetIsVisible, nodefault};
	__property TcxTreeListNode* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int Level = {read=GetLevel, nodefault};
	__property System::Uitypes::TImageIndex OverlayIndex = {read=GetNodeImageIndex, write=SetNodeImageIndex, index=3, nodefault};
	__property System::Uitypes::TImageIndex OverlayStateIndex = {read=GetNodeImageIndex, write=SetNodeImageIndex, index=4, nodefault};
	__property TcxTreeListNode* Parent = {read=FParent};
	__property TcxTreeListNode* Root = {read=GetRoot};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property System::Uitypes::TImageIndex SelectedIndex = {read=GetNodeImageIndex, write=SetNodeImageIndex, index=1, nodefault};
	__property System::Uitypes::TImageIndex StateIndex = {read=GetNodeImageIndex, write=SetNodeImageIndex, index=2, nodefault};
	__property System::UnicodeString Texts[int Index] = {read=GetText, write=SetText};
	__property TcxCustomTreeList* TreeList = {read=FTreeList};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property System::Variant Values[int Index] = {read=GetValue, write=SetValue};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
private:
	void *__IcxDragSizing;	/* Cxinplacecontainer::IcxDragSizing */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5EA02F4E-E367-4E4D-A26D-000B5E5CD434}
	operator Cxinplacecontainer::_di_IcxDragSizing()
	{
		Cxinplacecontainer::_di_IcxDragSizing intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxDragSizing*(void) { return (Cxinplacecontainer::IcxDragSizing*)&__IcxDragSizing; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxDragSizing; }
	#endif
	
};


class DELPHICLASS TcxTreeListRootNode;
class PASCALIMPLEMENTATION TcxTreeListRootNode : public TcxTreeListNode
{
	typedef TcxTreeListNode inherited;
	
protected:
	virtual int __fastcall GetFooterSummaryCount(void);
	virtual System::UnicodeString __fastcall GetFooterSummaryText(int AIndex);
	virtual bool __fastcall GetIsRoot(void);
	virtual void __fastcall InitializeHandle(void);
public:
	/* TcxTreeListNode.Create */ inline __fastcall virtual TcxTreeListRootNode(TcxCustomTreeList* AOwner) : TcxTreeListNode(AOwner) { }
	/* TcxTreeListNode.Destroy */ inline __fastcall virtual ~TcxTreeListRootNode(void) { }
	
};


class DELPHICLASS TcxUnboundTreeListNode;
class PASCALIMPLEMENTATION TcxUnboundTreeListNode : public TcxTreeListNode
{
	typedef TcxTreeListNode inherited;
	
protected:
	virtual void __fastcall ReadData(System::Classes::TStream* AStream, int AVersion);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TcxUnboundTreeListNode(TcxCustomTreeList* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TcxTreeListNode.Destroy */ inline __fastcall virtual ~TcxUnboundTreeListNode(void) { }
	
};


class DELPHICLASS TcxTreeListColumnStyles;
class DELPHICLASS TcxTreeListBand;
class DELPHICLASS TcxTreeListColumn;
class PASCALIMPLEMENTATION TcxTreeListColumnStyles : public Cxinplacecontainer::TcxEditContainerStyles
{
	typedef Cxinplacecontainer::TcxEditContainerStyles inherited;
	
private:
	TcxTreeListBand* __fastcall GetBand(void);
	TcxTreeListColumn* __fastcall GetColumn(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxTreeListColumnStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxTreeListNode* ANode);
	__property TcxTreeListBand* Band = {read=GetBand};
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=2};
	__property Content;
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxTreeListColumnStyles(void) { }
	
};


class DELPHICLASS TcxTreeListColumnPosition;
class DELPHICLASS TcxTreeListBandRow;
class PASCALIMPLEMENTATION TcxTreeListColumnPosition : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TcxTreeListBand* FBand;
	int FBandIndex;
	int FColIndex;
	int FLineCount;
	TcxTreeListBandRow* FRow;
	int FRowIndex;
	int FVisibleColIndex;
	int __fastcall GetBandIndex(void);
	int __fastcall GetColIndex(void);
	TcxTreeListColumn* __fastcall GetColumn(void);
	bool __fastcall GetIsUpdating(void);
	int __fastcall GetRowIndex(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	int __fastcall GetVisibleBandIndex(void);
	int __fastcall GetVisibleRowIndex(void);
	void __fastcall SetBandIndex(int AValue);
	void __fastcall SetColIndex(int AValue);
	void __fastcall SetLineCount(int AValue);
	void __fastcall SetRow(TcxTreeListBandRow* AValue);
	void __fastcall SetRowIndex(int AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual bool __fastcall IsPositionChanged(void);
	virtual void __fastcall Restore(bool ABandsIndexOnly);
	virtual void __fastcall Store(bool ABandIndexOnly);
	__property bool IsUpdating = {read=GetIsUpdating, nodefault};
	
public:
	__fastcall virtual TcxTreeListColumnPosition(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SetPosition(int AColIndex, int ARowIndex, bool IsInsertRow = false);
	void __fastcall SetPositionEx(int ABandIndex, int AColIndex, int ARowIndex, bool IsInsertRow = false);
	__property TcxTreeListBand* Band = {read=FBand};
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property TcxTreeListBandRow* Row = {read=FRow, write=SetRow};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property int VisibleBandIndex = {read=GetVisibleBandIndex, nodefault};
	__property int VisibleColIndex = {read=FVisibleColIndex, nodefault};
	__property int VisibleRowIndex = {read=GetVisibleRowIndex, nodefault};
	
__published:
	__property int ColIndex = {read=GetColIndex, write=SetColIndex, nodefault};
	__property int LineCount = {read=FLineCount, write=SetLineCount, default=1};
	__property int RowIndex = {read=GetRowIndex, write=SetRowIndex, nodefault};
	__property int BandIndex = {read=GetBandIndex, write=SetBandIndex, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListColumnPosition(void) { }
	
};


typedef System::TMetaClass* TcxTreeListColumnPositionClass;

class DELPHICLASS TcxTreeListCaption;
class PASCALIMPLEMENTATION TcxTreeListCaption : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TAlignment FAlignHorz;
	Cxclasses::TcxAlignmentVert FAlignVert;
	Vcl::Graphics::TBitmap* FGlyph;
	System::Classes::TAlignment FGlyphAlignHorz;
	Cxclasses::TcxAlignmentVert FGlyphAlignVert;
	bool FMultiLine;
	bool FShowEndEllipsis;
	System::UnicodeString FText;
	System::Classes::TNotifyEvent FOnChange;
	bool __fastcall IsAlignVertStored(void);
	bool __fastcall IsGlyphAlignVertStored(void);
	void __fastcall SetAlignHorz(System::Classes::TAlignment AValue);
	void __fastcall SetAlignVert(Cxclasses::TcxAlignmentVert AValue);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetGlyphAlignHorz(System::Classes::TAlignment AValue);
	void __fastcall SetGlyphAlignVert(Cxclasses::TcxAlignmentVert AValue);
	void __fastcall SetMultiLine(bool AValue);
	void __fastcall SetShowEndEllipsis(bool AValue);
	void __fastcall SetText(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual bool __fastcall IsTextStored(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TcxTreeListCaption(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxTreeListCaption(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Classes::TAlignment AlignHorz = {read=FAlignHorz, write=SetAlignHorz, default=0};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=FAlignVert, write=SetAlignVert, stored=IsAlignVertStored, nodefault};
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property System::Classes::TAlignment GlyphAlignHorz = {read=FGlyphAlignHorz, write=SetGlyphAlignHorz, default=0};
	__property Cxclasses::TcxAlignmentVert GlyphAlignVert = {read=FGlyphAlignVert, write=SetGlyphAlignVert, stored=IsGlyphAlignVertStored, nodefault};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiLine, default=0};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=1};
	__property System::UnicodeString Text = {read=GetText, write=SetText, stored=IsTextStored};
};


class DELPHICLASS TcxTreeListColumnOptions;
class PASCALIMPLEMENTATION TcxTreeListColumnOptions : public Cxinplacecontainer::TcxCustomEditContainerItemOptions
{
	typedef Cxinplacecontainer::TcxCustomEditContainerItemOptions inherited;
	
private:
	bool FCellEndEllipsis;
	Cxedit::TcxItemInplaceEditAutoHeight FEditAutoHeight;
	bool FFooter;
	bool FGroupFooter;
	bool FHidden;
	bool FSizing;
	bool FVertSizing;
	TcxTreeListColumn* __fastcall GetColumn(void);
	void __fastcall SetCellEndEllipsis(bool AValue);
	void __fastcall SetEditAutoHeight(Cxedit::TcxItemInplaceEditAutoHeight AValue);
	void __fastcall SetFooter(bool AValue);
	void __fastcall SetGroupFooter(bool AValue);
	void __fastcall SetSizing(bool AValue);
	void __fastcall SetVertSizing(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxTreeListColumnOptions(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxTreeListColumn* Column = {read=GetColumn};
	
__published:
	__property bool CellEndEllipsis = {read=FCellEndEllipsis, write=SetCellEndEllipsis, default=1};
	__property Cxedit::TcxItemInplaceEditAutoHeight EditAutoHeight = {read=FEditAutoHeight, write=SetEditAutoHeight, default=0};
	__property bool Footer = {read=FFooter, write=SetFooter, default=1};
	__property bool GroupFooter = {read=FGroupFooter, write=SetGroupFooter, default=1};
	__property bool Hidden = {read=FHidden, write=FHidden, default=0};
	__property bool Sizing = {read=FSizing, write=SetSizing, default=1};
	__property bool VertSizing = {read=FVertSizing, write=SetVertSizing, default=1};
	__property Customizing = {default=1};
	__property Editing = {default=1};
	__property Focusing = {default=1};
	__property IncSearch = {default=1};
	__property Moving = {default=1};
	__property ShowEditButtons = {default=0};
	__property Sorting = {default=1};
	__property TabStop = {default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListColumnOptions(void) { }
	
};


class DELPHICLASS TcxTreeListSummaryItem;
typedef void __fastcall (__closure *TcxTreeListSummaryItemGetTextEvent)(TcxTreeListSummaryItem* Sender, const System::Variant &AValue, System::UnicodeString &AText);

class PASCALIMPLEMENTATION TcxTreeListSummaryItem : public Cxcustomdata::TcxCustomDataSummaryItem
{
	typedef Cxcustomdata::TcxCustomDataSummaryItem inherited;
	
private:
	int FAbsoluteIndex;
	System::Classes::TAlignment FAlignHorz;
	bool FAlignHorzAssigned;
	Cxclasses::TcxAlignmentVert FAlignVert;
	bool FAlignVertAssigned;
	bool FAllNodes;
	TcxTreeListColumn* FCalculatedColumn;
	bool FMultiLine;
	bool FVisible;
	int FVisibleIndexInColumn;
	TcxTreeListSummaryItemGetTextEvent FOnGetText;
	System::Classes::TAlignment __fastcall GetAlignHorz(void);
	Cxclasses::TcxAlignmentVert __fastcall GetAlignVert(void);
	TcxTreeListColumn* __fastcall GetCalculatedColumn(void);
	TcxTreeListColumn* __fastcall GetColumn(void);
	bool __fastcall IsAlignHorzStored(void);
	bool __fastcall IsAlignVertStored(void);
	bool __fastcall IsCalculatedColumnStored(void);
	void __fastcall SetAlignHorz(System::Classes::TAlignment AValue);
	void __fastcall SetAlignVert(Cxclasses::TcxAlignmentVert AValue);
	void __fastcall SetAllNodes(bool AValue);
	void __fastcall SetCalculatedColumn(TcxTreeListColumn* AValue);
	void __fastcall SetMultiLine(bool AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall ReadAlignHorz(System::Classes::TReader* Reader);
	void __fastcall ReadAlignVert(System::Classes::TReader* Reader);
	void __fastcall WriteAlignHorz(System::Classes::TWriter* Writer);
	void __fastcall WriteAlignVert(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall AssignValues(Cxcustomdata::TcxCustomDataSummaryItem* Source);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	virtual System::UnicodeString __fastcall GetValueFormat(Cxcustomdata::TcxSummaryValueType AValueType, const System::Variant &AValue, bool AIsFooter);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TcxTreeListSummaryItem(System::Classes::TCollection* Collection);
	virtual System::UnicodeString __fastcall FormatValue(const System::Variant &AValue, bool AIsFooter);
	__property int AbsoluteIndex = {read=FAbsoluteIndex, write=FAbsoluteIndex, nodefault};
	__property bool AlignHorzAssigned = {read=FAlignHorzAssigned, write=FAlignHorzAssigned, nodefault};
	__property bool AlignVertAssigned = {read=FAlignVertAssigned, write=FAlignVertAssigned, nodefault};
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property int VisibleIndexInColumn = {read=FVisibleIndexInColumn, nodefault};
	
__published:
	__property System::Classes::TAlignment AlignHorz = {read=GetAlignHorz, write=SetAlignHorz, stored=IsAlignHorzStored, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=GetAlignVert, write=SetAlignVert, stored=IsAlignVertStored, nodefault};
	__property bool AllNodes = {read=FAllNodes, write=SetAllNodes, default=1};
	__property TcxTreeListColumn* CalculatedColumn = {read=GetCalculatedColumn, write=SetCalculatedColumn, stored=IsCalculatedColumnStored};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiLine, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property Format = {default=0};
	__property Kind = {default=0};
	__property TcxTreeListSummaryItemGetTextEvent OnGetText = {read=FOnGetText, write=FOnGetText};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxTreeListSummaryItem(void) { }
	
};


typedef System::TMetaClass* TcxTreeListSummaryItemClass;

class DELPHICLASS TcxTreeListColumnSummary;
class DELPHICLASS TcxTreeListSummaryItems;
class PASCALIMPLEMENTATION TcxTreeListColumnSummary : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TcxTreeListSummaryItems* FFooterSummaryItems;
	TcxTreeListSummaryItems* FGroupFooterSummaryItems;
	TcxTreeListColumn* __fastcall GetColumn(void);
	int __fastcall GetFooterVisibleCount(void);
	int __fastcall GetGroupFooterVisibleCount(void);
	void __fastcall SetFooterSummaryItems(TcxTreeListSummaryItems* AValue);
	void __fastcall SetGroupFooterSummaryItems(TcxTreeListSummaryItems* AValue);
	
protected:
	void __fastcall Changed(bool ARedrawOnly);
	
public:
	__fastcall virtual TcxTreeListColumnSummary(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxTreeListColumnSummary(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property int FooterVisibleCount = {read=GetFooterVisibleCount, nodefault};
	__property int GroupFooterVisibleCount = {read=GetGroupFooterVisibleCount, nodefault};
	
__published:
	__property TcxTreeListSummaryItems* FooterSummaryItems = {read=FFooterSummaryItems, write=SetFooterSummaryItems};
	__property TcxTreeListSummaryItems* GroupFooterSummaryItems = {read=FGroupFooterSummaryItems, write=SetGroupFooterSummaryItems};
};


class PASCALIMPLEMENTATION TcxTreeListSummaryItems : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxTreeListSummaryItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxTreeListColumnSummary* FSummary;
	int FVisibleCount;
	TcxTreeListColumn* __fastcall GetColumn(void);
	HIDESBASE TcxTreeListSummaryItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxTreeListSummaryItem* AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxTreeListSummaryItems(TcxTreeListColumnSummary* ASummary, TcxTreeListSummaryItemClass AItemClass);
	HIDESBASE TcxTreeListSummaryItem* __fastcall Add(void);
	TcxTreeListSummaryItem* __fastcall GetItemByKind(Cxcustomdata::TcxSummaryKind AKind);
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property TcxTreeListSummaryItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxTreeListColumnSummary* Summary = {read=FSummary};
	__property int VisibleCount = {read=FVisibleCount, nodefault};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxTreeListSummaryItems(void) { }
	
};


typedef System::TMetaClass* TcxTreeListColumnSummaryClass;

typedef void __fastcall (__closure *TcxTreeListOnGetDisplayTextEvent)(TcxTreeListColumn* Sender, TcxTreeListNode* ANode, System::UnicodeString &Value);

typedef void __fastcall (__closure *TcxTreeListGetEditPropertiesEvent)(TcxTreeListColumn* Sender, TcxTreeListNode* ANode, Cxedit::TcxCustomEditProperties* &EditProperties);

typedef void __fastcall (__closure *TcxTreeListValidateDrawValueEvent)(TcxTreeListColumn* Sender, TcxTreeListNode* ANode, const System::Variant &AValue, Cxedit::TcxEditValidateInfo* AData);

class DELPHICLASS TcxTreeListColumnHeaderCellViewInfo;
class DELPHICLASS TcxTreeListDataController;
class PASCALIMPLEMENTATION TcxTreeListColumn : public Cxinplacecontainer::TcxCustomInplaceEditContainer
{
	typedef Cxinplacecontainer::TcxCustomInplaceEditContainer inherited;
	
private:
	int FBestFitMaxWidth;
	TcxTreeListCaption* FCaption;
	int FCalculatedWidth;
	int FData;
	TcxTreeListColumnHeaderCellViewInfo* FHeaderCell;
	System::UnicodeString FStatusHint;
	bool FIsCurrency;
	bool FIsTextStored;
	int FMinWidth;
	System::Classes::TNotifyEvent FOnChangeName;
	TcxTreeListColumnPosition* FPosition;
	int FSortIndex;
	Dxcore::TdxSortOrder FSortOrder;
	int FStoreID;
	TcxTreeListColumnSummary* FSummary;
	System::Classes::TPersistent* FSummaryFooter;
	bool FVisible;
	int FWidth;
	TcxTreeListOnGetDisplayTextEvent FOnGetDisplayText;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	TcxTreeListValidateDrawValueEvent FOnValidateDrawValue;
	bool __fastcall GetActuallyVisible(void);
	HIDESBASE TcxTreeListDataController* __fastcall GetDataController(void);
	Cxinplacecontainer::TcxItemDataBinding* __fastcall GetDataBinding(void);
	System::UnicodeString __fastcall GetDisplayText(TcxTreeListNode* ANode);
	int __fastcall GetDisplayWidth(void);
	TcxTreeListGetEditPropertiesEvent __fastcall GetEditingProperties(void);
	TcxTreeListGetEditPropertiesEvent __fastcall GetEditProperties(void);
	bool __fastcall GetHasIndent(void);
	int __fastcall GetID(void);
	int __fastcall GetIndentWidth(void);
	bool __fastcall GetIsFixed(void);
	bool __fastcall GetIsHidden(void);
	bool __fastcall GetIsLeft(void);
	bool __fastcall GetIsPreview(void);
	bool __fastcall GetIsRight(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsReading(void);
	bool __fastcall GetIsUpdating(void);
	bool __fastcall GetIsWidthStored(void);
	int __fastcall GetItemIndex(void);
	TcxTreeListColumnOptions* __fastcall GetOptions(void);
	int __fastcall GetSortIndex(void);
	TcxTreeListColumnStyles* __fastcall GetStyles(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	System::Variant __fastcall GetValueByNode(TcxTreeListNode* ANode);
	Cxdatastorage::TcxValueDef* __fastcall GetValueDef(void);
	int __fastcall GetVisibleIndex(void);
	int __fastcall GetWidth(void);
	void __fastcall SetBestFitMaxWidth(int AValue);
	void __fastcall SetCaption(TcxTreeListCaption* AValue);
	HIDESBASE void __fastcall SetDataBinding(Cxinplacecontainer::TcxItemDataBinding* AValue);
	void __fastcall SetDisplayWidth(int AValue);
	void __fastcall SetEditingProperties(TcxTreeListGetEditPropertiesEvent AValue);
	void __fastcall SetEditProperties(TcxTreeListGetEditPropertiesEvent AValue);
	void __fastcall SetIsPreview(bool AValue);
	void __fastcall SetItemIndex(int AValue);
	void __fastcall SetMinWidth(int AValue);
	HIDESBASE void __fastcall SetOptions(TcxTreeListColumnOptions* AValue);
	void __fastcall SetPosition(TcxTreeListColumnPosition* AValue);
	void __fastcall SetSortIndex(int AValue);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder AValue);
	HIDESBASE void __fastcall SetStyles(TcxTreeListColumnStyles* AValue);
	void __fastcall SetSummary(TcxTreeListColumnSummary* AValue);
	void __fastcall SetSummaryFooter(System::Classes::TPersistent* AValue);
	void __fastcall SetValueByNode(TcxTreeListNode* ANode, const System::Variant &AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanEditAutoHeight(void);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual bool __fastcall CanInitEditing(void);
	void __fastcall AssignWidth(void);
	void __fastcall CancelSorting(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanMoving(void);
	virtual bool __fastcall CanSort(void);
	virtual void __fastcall ChangeCaption(System::TObject* Sender);
	virtual void __fastcall Changed(void);
	void __fastcall ForceWidth(int AWidth);
	Cxedit::TcxInplaceEditAutoHeight __fastcall GetEditAutoHeight(void);
	virtual int __fastcall GetHeaderFooterBestfitSize(void);
	virtual Cxinplacecontainer::TcxCustomEditContainerItemOptionsClass __fastcall GetOptionsClass(void);
	virtual Dxcore::TdxSortOrder __fastcall GetRealSortOrder(void);
	virtual Cxinplacecontainer::TcxEditContainerStylesClass __fastcall GetStylesClass(void);
	int __fastcall GetSummaryBestFitSize(TcxTreeListNode* ANode, TcxTreeListSummaryItems* AItems);
	virtual TcxTreeListColumnSummaryClass __fastcall GetSummaryClass(void);
	virtual void __fastcall SetEditingControl(Cxinplacecontainer::TcxEditingControl* Value);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	virtual bool __fastcall CanSizing(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual int __fastcall GetAvailableMaxWidth(void);
	int __fastcall GetRealMinSize(void);
	virtual System::Types::TRect __fastcall GetSizingBoundsRect(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual int __fastcall GetSizingIncrement(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual bool __fastcall IsDynamicUpdate(void);
	virtual void __fastcall SetSizeDelta(Cxinplacecontainer::TcxDragSizingDirection ADirection, int ADelta);
	System::UnicodeString __fastcall GetObjectName(void);
	HIDESBASE virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	int __fastcall GetPropertyIndex(const System::UnicodeString AName);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	void __fastcall ChangeSortOrder(Dxcore::TdxSortOrder ASortOrder, System::Classes::TShiftState AShift);
	void __fastcall ConvertOldFooterSummaries(void);
	virtual void __fastcall DoGetDisplayText(NativeInt ARecordIndex, System::UnicodeString &AText);
	virtual System::Variant __fastcall DoGetNodeDisplayText(TcxTreeListNode* ANode, const System::Variant &AValue);
	virtual System::Variant __fastcall DoOnGetDisplayText(TcxTreeListNode* ANode, bool AsText = false, bool AValueOnly = false);
	virtual void __fastcall DoValidateDrawValue(TcxTreeListNode* ANode, const System::Variant &AValue, Cxedit::TcxEditValidateInfo* AData);
	int __fastcall GetCellHeight(TcxTreeListNode* ANode, int AWidth, int ALines, Vcl::Graphics::TFont* AFont, const System::Variant &AValue);
	virtual System::Variant __fastcall GetCurrentValue(void);
	virtual TcxTreeListColumnPositionClass __fastcall GetPositionClass(void);
	virtual bool __fastcall GetIsCurrency(void);
	virtual bool __fastcall GetIsTextStored(void);
	virtual bool __fastcall HasDataTextHandler(void);
	virtual void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AItem);
	void __fastcall InitializeValueDef(void);
	bool __fastcall IsVisibleInQuickCustomizationPopup(void);
	virtual void __fastcall SetCurrentValue(const System::Variant &Value);
	virtual void __fastcall ValidateDrawValue(const System::Variant &AValue, Cxinplacecontainer::TcxEditCellViewInfo* AEditViewInfo);
	__property int Data = {read=FData, write=FData, nodefault};
	__property TcxTreeListDataController* DataController = {read=GetDataController};
	__property bool HasIndent = {read=GetHasIndent, nodefault};
	__property TcxTreeListColumnHeaderCellViewInfo* HeaderCell = {read=FHeaderCell};
	__property int ID = {read=GetID, nodefault};
	__property bool IsCurrency = {read=GetIsCurrency, nodefault};
	__property bool IsTextStored = {read=FIsTextStored, nodefault};
	__property bool IsFixed = {read=GetIsFixed, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsReading = {read=GetIsReading, nodefault};
	__property bool IsUpdating = {read=GetIsUpdating, nodefault};
	__property int StoreID = {read=FStoreID, write=FStoreID, nodefault};
	__property Cxdatastorage::TcxValueDef* ValueDef = {read=GetValueDef};
	__property Controller;
	__property EditingControl;
	__property EditViewData;
	__property System::Classes::TNotifyEvent OnChangeName = {read=FOnChangeName, write=FOnChangeName};
	
public:
	__fastcall virtual TcxTreeListColumn(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxTreeListColumn(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ApplyBestFit(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall MakeVisible(void);
	virtual void __fastcall RestoreDefaults(void);
	virtual void __fastcall RestoreWidths(void);
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property System::UnicodeString DisplayTexts[TcxTreeListNode* ANode] = {read=GetDisplayText};
	__property int DisplayWidth = {read=GetDisplayWidth, write=SetDisplayWidth, nodefault};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property bool IsHidden = {read=GetIsHidden, nodefault};
	__property bool IsLeft = {read=GetIsLeft, nodefault};
	__property bool IsPreview = {read=GetIsPreview, write=SetIsPreview, nodefault};
	__property bool IsRight = {read=GetIsRight, nodefault};
	__property PropertiesValue;
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property Editing;
	__property EditValue = {default=0};
	__property Focused;
	__property ItemIndex = {read=GetItemIndex, write=SetItemIndex};
	__property Value = {default=0};
	__property ValueCount;
	__property System::Variant Values[TcxTreeListNode* ANode] = {read=GetValueByNode, write=SetValueByNode};
	
__published:
	__property System::Classes::TPersistent* SummaryFooter = {read=FSummaryFooter, write=SetSummaryFooter, stored=false};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int BestFitMaxWidth = {read=FBestFitMaxWidth, write=SetBestFitMaxWidth, default=0};
	__property TcxTreeListCaption* Caption = {read=FCaption, write=SetCaption};
	__property Cxinplacecontainer::TcxItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=20};
	__property TcxTreeListColumnOptions* Options = {read=GetOptions, write=SetOptions};
	__property int Width = {read=GetWidth, write=SetWidth, stored=GetIsWidthStored, nodefault};
	__property TcxTreeListColumnPosition* Position = {read=FPosition, write=SetPosition};
	__property Dxcore::TdxSortOrder SortOrder = {read=FSortOrder, write=SetSortOrder, default=0};
	__property int SortIndex = {read=GetSortIndex, write=SetSortIndex, default=-1};
	__property System::UnicodeString StatusHint = {read=FStatusHint, write=FStatusHint};
	__property TcxTreeListColumnStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxTreeListColumnSummary* Summary = {read=FSummary, write=SetSummary};
	__property TcxTreeListOnGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
	__property TcxTreeListGetEditPropertiesEvent OnGetEditingProperties = {read=GetEditingProperties, write=SetEditingProperties};
	__property TcxTreeListGetEditPropertiesEvent OnGetEditProperties = {read=GetEditProperties, write=SetEditProperties};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
	__property TcxTreeListValidateDrawValueEvent OnValidateDrawValue = {read=FOnValidateDrawValue, write=FOnValidateDrawValue};
	__property PropertiesClassName = {default=0};
	__property Properties;
	__property PropertiesEvents;
	__property RepositoryItem;
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxDragSizing;	/* Cxinplacecontainer::IcxDragSizing */
	
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5EA02F4E-E367-4E4D-A26D-000B5E5CD434}
	operator Cxinplacecontainer::_di_IcxDragSizing()
	{
		Cxinplacecontainer::_di_IcxDragSizing intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxDragSizing*(void) { return (Cxinplacecontainer::IcxDragSizing*)&__IcxDragSizing; }
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


typedef System::TMetaClass* TcxTreeListColumnClass;

class DELPHICLASS TcxTreeListSizingDragAndDropObject;
class PASCALIMPLEMENTATION TcxTreeListSizingDragAndDropObject : public Cxinplacecontainer::TcxSizingDragAndDropObject
{
	typedef Cxinplacecontainer::TcxSizingDragAndDropObject inherited;
	
private:
	System::Types::TPoint FOffset;
	System::TObject* FDragItem;
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual System::Types::TRect __fastcall GetSizingMarkBounds(void);
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxTreeListSizingDragAndDropObject(Cxcontrols::TcxControl* AControl) : Cxinplacecontainer::TcxSizingDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListSizingDragAndDropObject(void) { }
	
};


class DELPHICLASS TcxTreeListDropInfo;
class PASCALIMPLEMENTATION TcxTreeListDropInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	bool Accepted;
	TcxTreeListBand* Band;
	int ColIndex;
	bool Customizing;
	System::Types::TPoint DropPos;
	Cxclasses::TcxPosition Position;
public:
	/* TObject.Create */ inline __fastcall TcxTreeListDropInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListDropInfo(void) { }
	
};


class DELPHICLASS TcxTreeListDragAndDropObject;
class DELPHICLASS TcxTreeListBands;
class DELPHICLASS TcxTreeListHeaderCellViewInfo;
class DELPHICLASS TcxTreeListHitTest;
class DELPHICLASS TcxTreeListOptionsCustomizing;
class DELPHICLASS TcxTreeListPainter;
class DELPHICLASS TcxTreeListViewInfo;
class PASCALIMPLEMENTATION TcxTreeListDragAndDropObject : public Cxinplacecontainer::TcxCustomControlDragAndDropObject
{
	typedef Cxinplacecontainer::TcxCustomControlDragAndDropObject inherited;
	
private:
	Cxinplacecontainer::TcxPlaceArrows* FArrows;
	TcxTreeListDropInfo* FDropInfo;
	bool __fastcall DrawArrowsNeeded(void);
	TcxTreeListBands* __fastcall GetBands(void);
	bool __fastcall GetCustomizing(void);
	TcxTreeListBand* __fastcall GetDestBand(void);
	TcxTreeListHeaderCellViewInfo* __fastcall GetDragHeader(void);
	Cxclasses::TcxPosition __fastcall GetDropPosition(void);
	TcxTreeListHitTest* __fastcall GetHitTest(void);
	TcxTreeListOptionsCustomizing* __fastcall GetOptionsCustomize(void);
	TcxTreeListPainter* __fastcall GetPainter(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	TcxTreeListViewInfo* __fastcall GetViewInfo(void);
	
protected:
	System::Types::TPoint FOrigin;
	virtual void __fastcall BeginDragAndDrop(void);
	void __fastcall ChangeArrowsPosition(void);
	virtual bool __fastcall CanCustomize(void) = 0 ;
	HIDESBASE virtual bool __fastcall CanDrop(void) = 0 ;
	virtual bool __fastcall CanRemove(void) = 0 ;
	bool __fastcall CheckInCustomizing(const System::Types::TPoint APoint);
	virtual void __fastcall CheckDragPosition(void) = 0 ;
	virtual TcxTreeListDropInfo* __fastcall CreateDropInfo(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual bool __fastcall Drop(void) = 0 ;
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(void);
	virtual System::Types::TRect __fastcall GetDisplayRect(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual void __fastcall InitDropInfo(const System::Types::TPoint P);
	virtual void __fastcall InitializeScrollArea(const System::Types::TRect &Area);
	virtual void __fastcall MakeCustomizingPageVisible(void) = 0 ;
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TcxTreeListDragAndDropObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TcxTreeListDragAndDropObject(void);
	__property Cxinplacecontainer::TcxPlaceArrows* Arrows = {read=FArrows};
	__property TcxTreeListBands* Bands = {read=GetBands};
	__property bool Customizing = {read=GetCustomizing, nodefault};
	__property TcxTreeListBand* DestBand = {read=GetDestBand};
	__property TcxTreeListHeaderCellViewInfo* DragHeader = {read=GetDragHeader};
	__property TcxTreeListDropInfo* DropInfo = {read=FDropInfo};
	__property Cxclasses::TcxPosition DropPosition = {read=GetDropPosition, nodefault};
	__property TcxTreeListHitTest* HitTest = {read=GetHitTest};
	__property TcxTreeListOptionsCustomizing* OptionsCustomizing = {read=GetOptionsCustomize};
	__property TcxTreeListPainter* Painter = {read=GetPainter};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property TcxTreeListViewInfo* ViewInfo = {read=GetViewInfo};
};


class DELPHICLASS TcxTreeListDragAndDropBandObject;
class PASCALIMPLEMENTATION TcxTreeListDragAndDropBandObject : public TcxTreeListDragAndDropObject
{
	typedef TcxTreeListDragAndDropObject inherited;
	
private:
	void __fastcall AfterDropPositionChange(void);
	void __fastcall BeforeDropPositionChange(void);
	TcxTreeListBand* __fastcall GetBand(void);
	int __fastcall GetDropColIndex(void);
	int __fastcall GetDropParentBandIndex(void);
	
protected:
	virtual bool __fastcall CanCustomize(void);
	virtual bool __fastcall CanDrop(void);
	virtual bool __fastcall CanRemove(void);
	bool __fastcall CheckBandInsertAt(TcxTreeListBand* ABand);
	virtual void __fastcall CheckDragPosition(void);
	virtual bool __fastcall Drop(void);
	System::Types::TRect __fastcall GetBoundsForInsert(TcxTreeListBand* ABand);
	virtual void __fastcall MakeCustomizingPageVisible(void);
	
public:
	__property TcxTreeListBand* Band = {read=GetBand};
public:
	/* TcxTreeListDragAndDropObject.Create */ inline __fastcall virtual TcxTreeListDragAndDropBandObject(Cxcontrols::TcxControl* AControl) : TcxTreeListDragAndDropObject(AControl) { }
	/* TcxTreeListDragAndDropObject.Destroy */ inline __fastcall virtual ~TcxTreeListDragAndDropBandObject(void) { }
	
};


class DELPHICLASS TcxTreeListColumnDropInfo;
class PASCALIMPLEMENTATION TcxTreeListColumnDropInfo : public TcxTreeListDropInfo
{
	typedef TcxTreeListDropInfo inherited;
	
public:
	System::Types::TRect Area;
	TcxTreeListColumn* Column;
	int RowIndex;
	bool InsertRow;
public:
	/* TObject.Create */ inline __fastcall TcxTreeListColumnDropInfo(void) : TcxTreeListDropInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListColumnDropInfo(void) { }
	
};


class DELPHICLASS TcxTreeListDragAndDropColumnObject;
class PASCALIMPLEMENTATION TcxTreeListDragAndDropColumnObject : public TcxTreeListDragAndDropObject
{
	typedef TcxTreeListDragAndDropObject inherited;
	
private:
	TcxTreeListColumn* __fastcall GetColumn(void);
	TcxTreeListColumnDropInfo* __fastcall GetDropInfo(void);
	
protected:
	virtual bool __fastcall CanCustomize(void);
	virtual bool __fastcall CanDrop(void);
	void __fastcall CheckDropColumnIndex(TcxTreeListBandRow* ARow, int &AColIndex);
	virtual bool __fastcall CanRemove(void);
	bool __fastcall ChangeColumnOnly(void);
	bool __fastcall CheckBandDropArea(TcxTreeListBand* ABand);
	virtual void __fastcall CheckDragPosition(void);
	bool __fastcall CheckOnlyOwnColumns(void);
	virtual TcxTreeListDropInfo* __fastcall CreateDropInfo(void);
	virtual bool __fastcall Drop(void);
	virtual System::Types::TRect __fastcall GetArrowAreaBounds(void);
	void __fastcall InitDropInfoFromColumn(TcxTreeListColumn* AColumn);
	virtual void __fastcall MakeCustomizingPageVisible(void);
	
public:
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property TcxTreeListColumnDropInfo* DropInfo = {read=GetDropInfo};
public:
	/* TcxTreeListDragAndDropObject.Create */ inline __fastcall virtual TcxTreeListDragAndDropColumnObject(Cxcontrols::TcxControl* AControl) : TcxTreeListDragAndDropObject(AControl) { }
	/* TcxTreeListDragAndDropObject.Destroy */ inline __fastcall virtual ~TcxTreeListDragAndDropColumnObject(void) { }
	
};


class DELPHICLASS TcxTreeListCellNavigator;
class DELPHICLASS TcxTreeListController;
class PASCALIMPLEMENTATION TcxTreeListCellNavigator : public Cxinplacecontainer::TcxCustomCellNavigator
{
	typedef Cxinplacecontainer::TcxCustomCellNavigator inherited;
	
private:
	bool FColumnChanged;
	TcxTreeListColumn* FCurrentNavigationColumn;
	int __fastcall GetCellIndex(TcxTreeListColumn* AColumn, TcxTreeListBandRow* ARow);
	TcxTreeListController* __fastcall GetController(void);
	TcxTreeListNode* __fastcall GetFocusedNode(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	bool __fastcall GoToNextCellInBand(bool AForward, TcxTreeListColumn* AColumn, int &ACellIndex);
	bool __fastcall GoToNextNodeCell(bool AForward, TcxTreeListNode* ANode, TcxTreeListColumn* AColumn, int &ACellIndex);
	
protected:
	void __fastcall AppendRecord(int &ARowIndex, int &ACellIndex);
	virtual void __fastcall CalcNextRow(bool AForward, int &ARowIndex, int &ACellIndex);
	virtual int __fastcall GetCount(int ARecordIndex);
	virtual Cxinplacecontainer::TcxCustomInplaceEditContainer* __fastcall GetCellContainer(int ARowIndex, int ACellIndex);
	TcxTreeListNode* __fastcall GetNode(int ARowIndex);
	virtual void __fastcall Init(int &ARowIndex, int &ACellIndex, int &ARowCount);
	bool __fastcall IsGroupRow(int ARowIndex);
	void __fastcall SaveCurrentNavigationColumn(void);
	virtual void __fastcall SetFocusCell(int ARowIndex, int ACellIndex, System::Classes::TShiftState AShift);
	
public:
	virtual bool __fastcall FocusNextCell(bool AForward, bool ANextRow, System::Classes::TShiftState AShift = System::Classes::TShiftState() );
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Refresh(void);
	__property TcxTreeListController* Controller = {read=GetController};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property TcxTreeListNode* FocusedNode = {read=GetFocusedNode};
public:
	/* TcxCustomCellNavigator.Create */ inline __fastcall virtual TcxTreeListCellNavigator(Cxinplacecontainer::TcxCustomControlController* AController) : Cxinplacecontainer::TcxCustomCellNavigator(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListCellNavigator(void) { }
	
};


class DELPHICLASS TcxTreeListPopup;
class DELPHICLASS TcxTreeListIndicatorCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListPopup : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	TcxTreeListIndicatorCellViewInfo* FOwner;
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateOwnerBounds(void);
	virtual void __fastcall CreateListBox(void) = 0 ;
	virtual int __fastcall GetClientMinWidth(void);
	virtual void __fastcall InitPopup(void);
	virtual bool __fastcall NeedIgnoreMouseMessageAfterCloseUp(NativeUInt AWnd, unsigned AMsg, System::Classes::TShiftState AShift, const System::Types::TPoint APos);
	DYNAMIC void __fastcall Paint(void);
	DYNAMIC void __fastcall VisibleChanged(void);
	
public:
	__fastcall virtual TcxTreeListPopup(Vcl::Controls::TWinControl* AOwnerControl);
	HIDESBASE virtual void __fastcall Popup(void);
	__property BorderWidths;
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property int ClientMinWidth = {read=GetClientMinWidth, nodefault};
	__property TcxTreeListIndicatorCellViewInfo* Owner = {read=FOwner, write=FOwner};
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxTreeListPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListPopup(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListCustomizationPopup;
class PASCALIMPLEMENTATION TcxTreeListCustomizationPopup : public TcxTreeListPopup
{
	typedef TcxTreeListPopup inherited;
	
private:
	Cxchecklistbox::TcxCheckListBox* FCheckListBox;
	void __fastcall CheckListBoxClick(System::TObject* Sender);
	void __fastcall CheckListBoxCheckClick(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);
	void __fastcall CheckListBoxKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall CheckListBoxMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
protected:
	virtual void __fastcall AddCheckListBoxItems(void) = 0 ;
	virtual void __fastcall AdjustCheckListBoxSize(bool AFixedHeight = false);
	virtual void __fastcall CheckClicked(int AIndex, bool AChecked);
	virtual void __fastcall CreateListBox(void);
	virtual int __fastcall GetCheckListBoxColumnWidth(void);
	void __fastcall GetCheckListBoxSelectedItems(System::Classes::TList* AItems);
	virtual int __fastcall GetDropDownCount(void) = 0 ;
	virtual void __fastcall InitPopup(void);
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked) = 0 ;
	void __fastcall SetCheckListBoxSelectedItems(System::Classes::TList* AItems);
	__property int CheckListBoxColumnWidth = {read=GetCheckListBoxColumnWidth, nodefault};
	
public:
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall CorrectBoundsWithDesktopWorkArea(System::Types::TPoint &APosition);
	__property Cxchecklistbox::TcxCheckListBox* CheckListBox = {read=FCheckListBox};
public:
	/* TcxTreeListPopup.Create */ inline __fastcall virtual TcxTreeListCustomizationPopup(Vcl::Controls::TWinControl* AOwnerControl) : TcxTreeListPopup(AOwnerControl) { }
	
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxTreeListCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : TcxTreeListPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListCustomizationPopup(HWND ParentWindow) : TcxTreeListPopup(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListColumnsCustomizationPopup;
class PASCALIMPLEMENTATION TcxTreeListColumnsCustomizationPopup : public TcxTreeListCustomizationPopup
{
	typedef TcxTreeListCustomizationPopup inherited;
	
protected:
	virtual void __fastcall AddCheckListBoxItems(void);
	virtual int __fastcall GetDropDownCount(void);
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked);
public:
	/* TcxTreeListPopup.Create */ inline __fastcall virtual TcxTreeListColumnsCustomizationPopup(Vcl::Controls::TWinControl* AOwnerControl) : TcxTreeListCustomizationPopup(AOwnerControl) { }
	
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxTreeListColumnsCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListColumnsCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : TcxTreeListCustomizationPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListColumnsCustomizationPopup(HWND ParentWindow) : TcxTreeListCustomizationPopup(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListBandsCustomizationPopup;
class PASCALIMPLEMENTATION TcxTreeListBandsCustomizationPopup : public TcxTreeListCustomizationPopup
{
	typedef TcxTreeListCustomizationPopup inherited;
	
protected:
	virtual void __fastcall AddCheckListBoxItems(void);
	virtual int __fastcall GetDropDownCount(void);
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked);
public:
	/* TcxTreeListPopup.Create */ inline __fastcall virtual TcxTreeListBandsCustomizationPopup(Vcl::Controls::TWinControl* AOwnerControl) : TcxTreeListCustomizationPopup(AOwnerControl) { }
	
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxTreeListBandsCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListBandsCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : TcxTreeListCustomizationPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListBandsCustomizationPopup(HWND ParentWindow) : TcxTreeListCustomizationPopup(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListEditingController;
class PASCALIMPLEMENTATION TcxTreeListEditingController : public Cxinplacecontainer::TcxEditingController
{
	typedef Cxinplacecontainer::TcxEditingController inherited;
	
private:
	bool FIsEditAutoHeight;
	Cxmemo::TcxAutoHeightInplaceEdit* FMultilineEdit;
	Cxedit::TcxInplaceEditAutoHeight __fastcall GetAutoHeight(void);
	TcxTreeListColumn* __fastcall GetColumn(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	void __fastcall AfterAssignMultilineEditProperties(void);
	void __fastcall BeforeAssignMultilineEditProperties(void);
	bool __fastcall CanUseAutoHeightEditor(void);
	virtual bool __fastcall CanUpdateEditValue(void);
	bool __fastcall CanUpdateMultilineEditHeight(void);
	void __fastcall CheckMultilineEditBounds(System::Types::TRect &ABounds);
	void __fastcall CheckUsingMultilineEdit(void);
	virtual Cxmemo::TcxAutoHeightInplaceEdit* __fastcall CreateMultilineEdit(void);
	System::Types::TRect __fastcall GetAdjustedMultilineEditBounds(const System::Types::TRect &ABounds);
	virtual System::Types::TRect __fastcall GetFocusRectBounds(void);
	virtual void __fastcall InitEdit(void);
	virtual void __fastcall MultilineEditTextChanged(void);
	virtual void __fastcall StartEditAutoHeight(bool AHeightChanged);
	__property Cxedit::TcxInplaceEditAutoHeight AutoHeight = {read=GetAutoHeight, nodefault};
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property bool IsEditAutoHeight = {read=FIsEditAutoHeight, write=FIsEditAutoHeight, nodefault};
	__property Cxmemo::TcxAutoHeightInplaceEdit* MultilineEdit = {read=FMultilineEdit};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
public:
	__fastcall virtual TcxTreeListEditingController(Cxinplacecontainer::TcxCustomControlController* AController);
	__fastcall virtual ~TcxTreeListEditingController(void);
};


enum TcxNodeDragInfoState : unsigned char { ndiNone, ndiInsertBefore, ndiInsertAfter, ndiAddChild };

class DELPHICLASS TcxTreeListNodeDragInfoImage;
class PASCALIMPLEMENTATION TcxTreeListNodeDragInfoImage : public Cxinplacecontainer::TcxDragImage
{
	typedef Cxinplacecontainer::TcxDragImage inherited;
	
private:
	int FImageIndex;
	Cxgraphics::TcxImageList* FImages;
	System::Types::TPoint FPrevPosition;
	int FPrevImageIndex;
	HRGN FWindowRegion;
	void __fastcall DeleteImageRegion(void);
	TcxNodeDragInfoState __fastcall GetState(void);
	bool __fastcall IsImageIndexValid(void);
	void __fastcall LoadResourceImages(void);
	void __fastcall SetImageIndex(int AValue);
	void __fastcall SetState(const TcxNodeDragInfoState Value);
	void __fastcall UpdateImage(void);
	void __fastcall UpdateImageRegion(void);
	void __fastcall UpdateWindowRegion(void);
	
protected:
	HRGN __fastcall CreateImageRegion(void);
	HIDESBASE bool __fastcall MoveTo(System::Types::TPoint APosition);
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	
public:
	__fastcall virtual TcxTreeListNodeDragInfoImage(void);
	__fastcall virtual ~TcxTreeListNodeDragInfoImage(void);
	__property TcxNodeDragInfoState State = {read=GetState, write=SetState, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListNodeDragInfoImage(System::Classes::TComponent* AOwner, int Dummy) : Cxinplacecontainer::TcxDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListNodeDragInfoImage(HWND ParentWindow) : Cxinplacecontainer::TcxDragImage(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListCustomHeaderCellViewInfo;
class DELPHICLASS TcxTreeListOptionsBehavior;
class DELPHICLASS TcxTreeListOptionsSelection;
class PASCALIMPLEMENTATION TcxTreeListController : public Cxinplacecontainer::TcxCustomControlController
{
	typedef Cxinplacecontainer::TcxCustomControlController inherited;
	
private:
	TcxTreeListBandsCustomizationPopup* FBandsCustomizationPopup;
	System::TObject* FClickedObject;
	TcxTreeListColumnsCustomizationPopup* FColumnsCustomizationPopup;
	bool FDragCursorWasChanged;
	bool FDragDropInProcess;
	TcxTreeListNodeDragInfoImage* FDragNodeInfoImage;
	TcxTreeListNode* FFocusedNode;
	int FFocusedNodeIndex;
	TcxTreeListNode* FForceSelectionNode;
	TcxTreeListBand* FForcingWidthBand;
	TcxTreeListColumn* FForcingWidthColumn;
	TcxTreeListColumn* FHotTrackColumn;
	TcxTreeListNode* FHotTrackNode;
	System::Classes::TShiftState FHotTrackShift;
	TcxTreeListNode* FIncSearchNode;
	System::UnicodeString FIncSearchText;
	bool FIsDblClick;
	TcxTreeListCustomHeaderCellViewInfo* FPressedHeader;
	System::Uitypes::TCursor FPrevDragCursor;
	TcxTreeListNode* FPrevFocusedNode;
	Cxinplacecontainer::TcxDragSizingDirection FResizeDirection;
	bool FSearchNotification;
	TcxTreeListNode* FSelectionAnchor;
	int FSelectionLockCount;
	TcxTreeListBandsCustomizationPopup* __fastcall GetBandsCustomizationPopup(void);
	TcxTreeListColumnsCustomizationPopup* __fastcall GetColumnsCustomizationPopup(void);
	HIDESBASE TcxTreeListDataController* __fastcall GetDataController(void);
	TcxNodeDragInfoState __fastcall GetDropMode(int X, int Y);
	TcxTreeListEditingController* __fastcall GetEditingController(void);
	int __fastcall GetFocusedNodeIndex(void);
	TcxTreeListHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetIsDragCopy(void);
	int __fastcall GetLeftPos(void);
	TcxTreeListOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TcxTreeListOptionsSelection* __fastcall GetOptionsSelection(void);
	System::Classes::TList* __fastcall GetSelection(void);
	TcxTreeListNode* __fastcall GetSelectionAnchor(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetForcingWidthColumn(TcxTreeListColumn* AColumn);
	void __fastcall SetIncSearchNode(TcxTreeListNode* ANode);
	void __fastcall SetLeftPos(int AValue);
	void __fastcall SetPressedHeader(TcxTreeListCustomHeaderCellViewInfo* AHeader);
	
protected:
	bool CanClearSelection;
	System::Classes::TList* DragNodesList;
	System::Uitypes::TCursor PrevCursor;
	TcxTreeListNode* ExpandingNode;
	Vcl::Extctrls::TTimer* ExpandTimer;
	System::StaticArray<Cxinplacecontainer::TcxAutoScrollingEditingControlObject*, 4> ScrollControllers;
	void __fastcall AddNodeToSelection(TcxTreeListNode* ANode);
	virtual void __fastcall BeforeShowEdit(void);
	virtual bool __fastcall CanHandleDeleteRecordKeys(void);
	virtual bool __fastcall CheckAutoScrolling(const System::Types::TPoint APoint);
	void __fastcall UpdateStatusHint(void);
	void __fastcall CheckFocusedNodeItem(void);
	virtual void __fastcall ChangeFocusedNode(TcxTreeListNode* ANode);
	virtual NativeInt __fastcall GetFocusedRecordIndex(void);
	virtual void __fastcall SetFocusedNode(TcxTreeListNode* ANode);
	virtual void __fastcall SetFocusedNodeItem(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	virtual void __fastcall SetFocusedRecordIndex(NativeInt Value);
	virtual void __fastcall BeforeStartDrag(void);
	bool __fastcall CanDrop(void);
	Cxinplacecontainer::TcxAutoScrollingEditingControlObject* __fastcall CreateAutoScrollObject(Vcl::Forms::TScrollBarKind Kind, const System::Types::TRect &ARect, System::Uitypes::TScrollCode ACode);
	virtual void __fastcall CheckButtonTimer(void);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall DragEnter(void);
	virtual void __fastcall DragLeave(void);
	virtual void __fastcall DragMove(System::TObject* Source, const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DropTo(TcxTreeListNode* ANode, TcxTreeListNodeAttachMode AMode);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall OnExpandTimer(System::TObject* Sender);
	void __fastcall ResetButtonTimer(void);
	void __fastcall DoNextNode(bool AForward);
	virtual void __fastcall DoNextPage(bool AForward, System::Classes::TShiftState Shift);
	virtual void __fastcall DoShowNextPageEx(bool AGoForward, bool ASetCursor, System::Classes::TShiftState AShift);
	virtual void __fastcall FocusedRecordChanged(int APrevFocusedRecordIndex, int AFocusedRecordIndex);
	virtual void __fastcall FocusedItemChanged(Cxinplacecontainer::TcxCustomInplaceEditContainer* APrevFocusedItem);
	virtual bool __fastcall IsKeyForController(System::Word AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall IsNodeKeyHandle(TcxTreeListNode* ANode, System::Word &AKey, System::Classes::TShiftState Shift);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual Cxinplacecontainer::TcxEditCellViewInfo* __fastcall GetFocusedCellViewInfo(Cxinplacecontainer::TcxCustomInplaceEditContainer* AEditContainer);
	virtual bool __fastcall GetImmediateEditor(void);
	virtual Cxinplacecontainer::TcxCustomCellNavigatorClass __fastcall GetNavigatorClass(void);
	TcxTreeListNode* __fastcall GetNode(int ARecordIndex);
	virtual Cxinplacecontainer::TcxDragSizingDirection __fastcall GetResizeDirection(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall CancelIncSearching(void);
	virtual bool __fastcall DoSearch(TcxTreeListNode* AFromNode, int AItemIndex, const System::UnicodeString AText, bool AGoForward);
	virtual Cxinplacecontainer::TcxCustomInplaceEditContainer* __fastcall GetIncSearchingItem(void);
	virtual System::UnicodeString __fastcall GetIncSearchingText(void);
	virtual bool __fastcall GetIsIncSearching(void);
	TcxTreeListNode* __fastcall GetNextNodeForIncSearch(TcxTreeListNode* ANode, bool AGoForward);
	void __fastcall CheckLocate(bool AFound);
	virtual void __fastcall SearchLocate(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem, const System::UnicodeString AValue);
	virtual void __fastcall SearchLocateNext(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem, bool AForward);
	bool __fastcall CanCreateSelectionHelper(void);
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject);
	virtual void __fastcall SelectObject(System::Classes::TPersistent* AObject, System::Classes::TShiftState AShift);
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject);
	void __fastcall CancelSelection(bool KeepPrimary = true);
	void __fastcall SelectRange(TcxTreeListNode* const AStartNode, TcxTreeListNode* const AFinishNode);
	virtual void __fastcall ViewInfoChanged(void);
	__property TcxTreeListDataController* DataController = {read=GetDataController};
	__property bool DragCursorWasChanged = {read=FDragCursorWasChanged, write=FDragCursorWasChanged, nodefault};
	__property TcxTreeListEditingController* EditingController = {read=GetEditingController};
	__property bool SearchNotification = {read=FSearchNotification, write=FSearchNotification, nodefault};
	__property int SelectionLockCount = {read=FSelectionLockCount, write=FSelectionLockCount, nodefault};
	
public:
	__fastcall virtual ~TcxTreeListController(void);
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeginDragAndDrop(void);
	void __fastcall BeginUpdateSelection(void);
	virtual bool __fastcall CanDrag(int X, int Y);
	bool __fastcall CanDeleteSelection(void);
	bool __fastcall CanInsertNode(void);
	bool __fastcall CanSelectNode(TcxTreeListNode* ANode);
	bool __fastcall CheckCustomizationPopup(void);
	virtual void __fastcall CheckDeletedNode(TcxTreeListNode* ANode);
	void __fastcall CheckFocusedNode(void);
	void __fastcall CheckHeaderClick(System::Classes::TShiftState AShift);
	void __fastcall CheckNodeContentClick(System::Classes::TShiftState Shift);
	virtual void __fastcall DblClick(void);
	bool __fastcall DeleteConfirmation(void);
	virtual bool __fastcall DoHeaderMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall DoNodeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	void __fastcall EndUpdateSelection(void);
	TcxTreeListNode* __fastcall FindNearestFocusableNode(int AVisibleIndex);
	TcxTreeListColumn* __fastcall FindNearestFocusableColumn(int AVisibleIndex);
	bool __fastcall HitAtNodeContent(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MakeFocusedItemVisible(void);
	virtual void __fastcall MakeFocusedRecordVisible(void);
	HIDESBASE virtual void __fastcall Reset(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall Select(TcxTreeListNode* ANode, System::Classes::TShiftState AShift);
	void __fastcall SetSelection(System::Classes::TList* AList);
	virtual void __fastcall SetFocusedRecordItem(NativeInt ARecordIndex, Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	void __fastcall SetHotTrackCursor(System::Uitypes::TCursor ACursor);
	void __fastcall SetHotTrackNode(TcxTreeListNode* ANode, System::Classes::TShiftState AShift);
	void __fastcall ShowEdit(System::Classes::TShiftState AShift, int X, int Y);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	virtual void __fastcall FocusChanged(void);
	void __fastcall UpdateHotTrackNode(System::Classes::TShiftState AShift)/* overload */;
	void __fastcall UpdateHotTrackNode(int X, int Y, System::Classes::TShiftState AShift)/* overload */;
	__property TcxTreeListBandsCustomizationPopup* BandsCustomizationPopup = {read=GetBandsCustomizationPopup};
	__property System::TObject* ClickedObject = {read=FClickedObject, write=FClickedObject};
	__property TcxTreeListColumnsCustomizationPopup* ColumnsCustomizationPopup = {read=GetColumnsCustomizationPopup};
	__property bool DragDropInProcess = {read=FDragDropInProcess, write=FDragDropInProcess, nodefault};
	__property TcxTreeListNode* FocusedNode = {read=FFocusedNode, write=SetFocusedNode};
	__property int FocusedNodeIndex = {read=GetFocusedNodeIndex, write=FFocusedNodeIndex, nodefault};
	__property TcxTreeListNode* ForceSelectionNode = {read=FForceSelectionNode, write=FForceSelectionNode};
	__property TcxTreeListBand* ForcingWidthBand = {read=FForcingWidthBand, write=FForcingWidthBand};
	__property TcxTreeListColumn* ForcingWidthColumn = {read=FForcingWidthColumn, write=SetForcingWidthColumn};
	__property TcxTreeListHitTest* HitTest = {read=GetHitTest};
	__property TcxTreeListColumn* HotTrackColumn = {read=FHotTrackColumn, write=FHotTrackColumn};
	__property TcxTreeListNode* HotTrackNode = {read=FHotTrackNode, write=FHotTrackNode};
	__property System::Classes::TShiftState HotTrackShift = {read=FHotTrackShift, write=FHotTrackShift, nodefault};
	__property TcxTreeListNode* IncSearchNode = {read=FIncSearchNode, write=SetIncSearchNode};
	__property System::UnicodeString IncSearchText = {read=FIncSearchText, write=FIncSearchText};
	__property bool IsDblClick = {read=FIsDblClick, write=FIsDblClick, nodefault};
	__property bool IsDragCopy = {read=GetIsDragCopy, nodefault};
	__property int LeftPos = {read=GetLeftPos, write=SetLeftPos, nodefault};
	__property TcxTreeListOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property TcxTreeListOptionsSelection* OptionsSelection = {read=GetOptionsSelection};
	__property TcxTreeListCustomHeaderCellViewInfo* PressedHeader = {read=FPressedHeader, write=SetPressedHeader};
	__property TcxTreeListNode* PrevFocusedNode = {read=FPrevFocusedNode};
	__property System::Classes::TList* Selection = {read=GetSelection};
	__property TcxTreeListNode* SelectionAnchor = {read=GetSelectionAnchor, write=FSelectionAnchor};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxCustomControlController.Create */ inline __fastcall virtual TcxTreeListController(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxinplacecontainer::TcxCustomControlController(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListHitTest : public Cxinplacecontainer::TcxCustomHitTestController
{
	typedef Cxinplacecontainer::TcxCustomHitTestController inherited;
	
private:
	System::TObject* FDragItem;
	TcxTreeListBand* FHitBand;
	TcxTreeListColumn* FHitColumn;
	TcxTreeListNode* FHitNode;
	int FLockCount;
	bool __fastcall GetHitAtImages(void);
	bool __fastcall GetHitAtFooterArea(void);
	bool __fastcall GetHitAtHeader(void);
	Cxinplacecontainer::TcxCustomViewInfoItem* __fastcall GetHitCell(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	HIDESBASE TcxTreeListViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall AllowDesignMouseEvents(int X, int Y, System::Classes::TShiftState AShift);
	virtual bool __fastcall CanShowHint(System::TObject* AItem);
	bool __fastcall CanStartDrag(void);
	void __fastcall CheckFooterColumn(void);
	virtual void __fastcall CheckSelection(System::Classes::TShiftState AShift);
	virtual void __fastcall DoCalculate(void);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(void);
	virtual bool __fastcall GetHitAtNavigator(void);
	bool __fastcall GetState(int Index);
	void __fastcall SetHitState(int Index, bool Value);
	__property System::TObject* DragItem = {read=FDragItem, write=FDragItem};
	__property bool HitAtFooterArea = {read=GetHitAtFooterArea, nodefault};
	__property bool HitAtHeader = {read=GetHitAtHeader, nodefault};
	__property int LockCount = {read=FLockCount, write=FLockCount, nodefault};
	__property TcxTreeListViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual bool __fastcall CanMoving(void);
	virtual bool __fastcall CanSizing(void);
	__property System::Uitypes::TCursor Cursor = {read=GetCurrentCursor, nodefault};
	__property bool HitAtBackground = {read=GetState, index=4, nodefault};
	__property bool HitAtBand = {read=GetState, index=5, nodefault};
	__property bool HitAtBandContainer = {read=GetState, index=6, nodefault};
	__property bool HitAtBandCustomizing = {read=GetState, index=7, nodefault};
	__property bool HitAtBandHeader = {read=GetState, index=8, nodefault};
	__property bool HitAtButton = {read=GetState, index=9, nodefault};
	__property bool HitAtCheckButton = {read=GetState, index=10, nodefault};
	__property bool HitAtColumn = {read=GetState, index=11, nodefault};
	__property bool HitAtColumnCustomizing = {read=GetState, index=12, nodefault};
	__property bool HitAtColumnHeader = {read=GetState, index=13, nodefault};
	__property bool HitAtFooter = {read=GetState, index=14, nodefault};
	__property bool HitAtFooterItem = {read=GetState, index=15, nodefault};
	__property bool HitAtGroupFooter = {read=GetState, index=16, nodefault};
	__property bool HitAtGroupFooterItem = {read=GetState, index=17, nodefault};
	__property bool HitAtImage = {read=GetState, index=18, nodefault};
	__property bool HitAtImages = {read=GetHitAtImages, nodefault};
	__property bool HitAtIndent = {read=GetState, index=19, nodefault};
	__property bool HitAtIndicator = {read=GetState, index=20, nodefault};
	__property bool HitAtNode = {read=GetState, index=21, nodefault};
	__property bool HitAtNodePreview = {read=GetState, index=22, nodefault};
	__property bool HitAtSeparator = {read=GetState, index=23, nodefault};
	__property bool HitAtSizingHorz = {read=GetState, index=24, nodefault};
	__property bool HitAtSizingVert = {read=GetState, index=25, nodefault};
	__property bool HitAtStateImage = {read=GetState, index=26, nodefault};
	__property TcxTreeListBand* HitBand = {read=FHitBand};
	__property Cxinplacecontainer::TcxCustomViewInfoItem* HitCell = {read=GetHitCell};
	__property TcxTreeListColumn* HitColumn = {read=FHitColumn};
	__property TcxTreeListNode* HitNode = {read=FHitNode};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxCustomHitTestController.Create */ inline __fastcall virtual TcxTreeListHitTest(Cxinplacecontainer::TcxCustomControlController* AOwner) : Cxinplacecontainer::TcxCustomHitTestController(AOwner) { }
	/* TcxCustomHitTestController.Destroy */ inline __fastcall virtual ~TcxTreeListHitTest(void) { }
	
};


class DELPHICLASS TcxTreeListHitTestArea;
class DELPHICLASS TcxTreeListCustomCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListHitTestArea : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FArea;
	TcxTreeListCustomCellViewInfo* FLink;
	
protected:
	virtual void __fastcall Calculate(void) = 0 ;
	virtual bool __fastcall GetHitTest(TcxTreeListHitTest* AHitTest);
	virtual void __fastcall InitHitTest(TcxTreeListHitTest* AHitTest) = 0 ;
	
public:
	__fastcall virtual TcxTreeListHitTestArea(TcxTreeListCustomCellViewInfo* ALink);
	__property System::Types::TRect Area = {read=FArea, write=FArea};
	__property TcxTreeListCustomCellViewInfo* Link = {read=FLink};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListHitTestArea(void) { }
	
};


class DELPHICLASS TcxTreeListHeaderSizingArea;
class PASCALIMPLEMENTATION TcxTreeListHeaderSizingArea : public TcxTreeListHitTestArea
{
	typedef TcxTreeListHitTestArea inherited;
	
private:
	Cxinplacecontainer::TcxDragSizingDirection FDirection;
	
protected:
	virtual void __fastcall Calculate(void);
	virtual void __fastcall InitHitTest(TcxTreeListHitTest* AHitTest);
	
public:
	__fastcall TcxTreeListHeaderSizingArea(TcxTreeListCustomCellViewInfo* ALink, Cxinplacecontainer::TcxDragSizingDirection ADirection);
	__property Cxinplacecontainer::TcxDragSizingDirection Direction = {read=FDirection, nodefault};
public:
	/* TcxTreeListHitTestArea.Create */ inline __fastcall virtual TcxTreeListHeaderSizingArea(TcxTreeListCustomCellViewInfo* ALink) : TcxTreeListHitTestArea(ALink) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListHeaderSizingArea(void) { }
	
};


class DELPHICLASS TcxTreeListNodeSizingArea;
class PASCALIMPLEMENTATION TcxTreeListNodeSizingArea : public TcxTreeListHitTestArea
{
	typedef TcxTreeListHitTestArea inherited;
	
protected:
	virtual void __fastcall Calculate(void);
	virtual bool __fastcall GetHitTest(TcxTreeListHitTest* AHitTest);
	virtual void __fastcall InitHitTest(TcxTreeListHitTest* AHitTest);
	
public:
	__fastcall virtual TcxTreeListNodeSizingArea(TcxTreeListCustomCellViewInfo* ALink);
	__fastcall virtual ~TcxTreeListNodeSizingArea(void);
};


typedef System::StaticArray<System::Types::TRect, 2> TcxTreeListSeparators;

class DELPHICLASS TcxTreeListOptionsView;
class DELPHICLASS TcxTreeListStyles;
class PASCALIMPLEMENTATION TcxTreeListCustomCellViewInfo : public Cxinplacecontainer::TcxCustomViewInfoItem
{
	typedef Cxinplacecontainer::TcxCustomViewInfoItem inherited;
	
private:
	bool __fastcall GetExtPaintStyle(void);
	TcxTreeListHitTest* __fastcall GetHitTestController(void);
	TcxTreeListOptionsView* __fastcall GetOptionsView(void);
	TcxTreeListStyles* __fastcall GetStyles(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	System::Types::TRect __fastcall GetVisibleRect(void);
	
protected:
	TcxTreeListNode* FAttachNode;
	System::Uitypes::TColor FBorderColor;
	Cxgraphics::TcxBorders FBorders;
	TcxTreeListNode* FNode;
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall CellHasOrigin(void);
	virtual System::Types::TPoint __fastcall GetCellOrigin(void);
	System::Types::TRect __fastcall GetClipRect(void);
	virtual Cxinplacecontainer::TcxEditingControl* __fastcall GetControl(void);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	void __fastcall SetBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	void __fastcall SetHitTestCodes(int const *ACodes, const int ACodes_Size);
	virtual bool __fastcall GetSelected(void);
	__property TcxTreeListNode* AttachNode = {read=FAttachNode};
	__property TcxTreeListHitTest* HitTest = {read=GetHitTestController};
	__property TcxTreeListOptionsView* OptionsView = {read=GetOptionsView};
	__property bool Selected = {read=GetSelected, nodefault};
	__property TcxTreeListStyles* Styles = {read=GetStyles};
	
public:
	__fastcall virtual TcxTreeListCustomCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	__fastcall virtual ~TcxTreeListCustomCellViewInfo(void);
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property Cxgraphics::TcxBorders Borders = {read=FBorders, nodefault};
	__property bool ExtPaintStyle = {read=GetExtPaintStyle, nodefault};
	__property TcxTreeListNode* Node = {read=FNode};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property System::Types::TRect VisibleRect = {read=GetVisibleRect};
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListCustomCellViewInfo(System::TObject* AOwner) : Cxinplacecontainer::TcxCustomViewInfoItem(AOwner) { }
	
};


class DELPHICLASS TcxTreeListBackgroundCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListBackgroundCellViewInfo : public TcxTreeListCustomCellViewInfo
{
	typedef TcxTreeListCustomCellViewInfo inherited;
	
protected:
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	__classmethod virtual int __fastcall CustomDrawID();
public:
	/* TcxTreeListCustomCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListBackgroundCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListCustomCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListBackgroundCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListBackgroundCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomCellViewInfo(AOwner) { }
	
};


class DELPHICLASS TcxTreeListFooterCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListFooterCellViewInfo : public TcxTreeListCustomCellViewInfo
{
	typedef TcxTreeListCustomCellViewInfo inherited;
	
private:
	TcxTreeListColumn* FColumn;
	bool FHidden;
	System::UnicodeString FText;
	bool __fastcall GetShowEndEllipsis(void);
	
protected:
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignVert(void);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	virtual TcxTreeListSummaryItem* __fastcall GetItem(void);
	virtual bool __fastcall GetMultiline(void);
	virtual void __fastcall Initialize(TcxTreeListNode* ANode, TcxTreeListNode* AttachNode, TcxTreeListColumn* AColumn);
	virtual void __fastcall Scroll(const int DX, const int DY);
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint);
	bool __fastcall HasHintPoint(const System::Types::TPoint P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	
public:
	__fastcall virtual TcxTreeListFooterCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	__classmethod virtual int __fastcall CustomDrawID();
	__property System::Classes::TAlignment AlignHorz = {read=GetAlignHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=GetAlignVert, nodefault};
	__property AttachNode;
	__property TcxTreeListColumn* Column = {read=FColumn};
	__property bool Hidden = {read=FHidden, nodefault};
	__property bool MultiLine = {read=GetMultiline, nodefault};
	__property bool ShowEndEllipsis = {read=GetShowEndEllipsis, nodefault};
	__property System::UnicodeString Text = {read=FText};
	__property TreeList;
public:
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListFooterCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListFooterCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomCellViewInfo(AOwner) { }
	
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	void *__IcxHotTrackElement;	/* Cxinplacecontainer::IcxHotTrackElement */
	
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
	// {E7171E58-276E-499B-9DDF-298D850883C9}
	operator Cxinplacecontainer::_di_IcxHotTrackElement()
	{
		Cxinplacecontainer::_di_IcxHotTrackElement intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxHotTrackElement*(void) { return (Cxinplacecontainer::IcxHotTrackElement*)&__IcxHotTrackElement; }
	#endif
	
};


class DELPHICLASS TcxTreeListFooterSingleCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListFooterSingleCellViewInfo : public TcxTreeListFooterCellViewInfo
{
	typedef TcxTreeListFooterCellViewInfo inherited;
	
private:
	TcxTreeListSummaryItem* FSummaryItem;
	
protected:
	virtual TcxTreeListSummaryItem* __fastcall GetItem(void);
	virtual bool __fastcall GetSelected(void);
	HIDESBASE void __fastcall Initialize(TcxTreeListNode* ANode, TcxTreeListNode* AttachNode, TcxTreeListColumn* AColumn, TcxTreeListSummaryItem* ASummaryItem)/* overload */;
	
public:
	__property TcxTreeListSummaryItem* SummaryItem = {read=FSummaryItem};
public:
	/* TcxTreeListFooterCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListFooterSingleCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListFooterCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	
public:
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListFooterSingleCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListFooterSingleCellViewInfo(System::TObject* AOwner) : TcxTreeListFooterCellViewInfo(AOwner) { }
	
};


class DELPHICLASS TcxTreeListFooterMultiItemsCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListFooterMultiItemsCellViewInfo : public TcxTreeListFooterCellViewInfo
{
	typedef TcxTreeListFooterCellViewInfo inherited;
	
private:
	bool FNeedShowHint;
	TcxTreeListSummaryItems* FSummaryItems;
	System::Types::TRect FHintRect;
	int FVisibleCount;
	System::UnicodeString __fastcall GetSeparator(void);
	
protected:
	bool __fastcall CanDifferentStyles(void);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignVert(void);
	virtual TcxTreeListSummaryItem* __fastcall GetItem(void);
	virtual bool __fastcall GetSelected(void);
	HIDESBASE void __fastcall Initialize(TcxTreeListNode* ADataNode, TcxTreeListNode* AttachNode, TcxTreeListColumn* AColumn, TcxTreeListSummaryItems* ASummaryItems)/* overload */;
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	
public:
	__property System::UnicodeString Separator = {read=GetSeparator};
	__property TcxTreeListSummaryItems* SummaryItems = {read=FSummaryItems};
	__property int VisibleCount = {read=FVisibleCount, nodefault};
public:
	/* TcxTreeListFooterCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListFooterMultiItemsCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListFooterCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	
public:
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListFooterMultiItemsCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListFooterMultiItemsCellViewInfo(System::TObject* AOwner) : TcxTreeListFooterCellViewInfo(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListCustomHeaderCellViewInfo : public TcxTreeListCustomCellViewInfo
{
	typedef TcxTreeListCustomCellViewInfo inherited;
	
private:
	bool FIsLast;
	Cxlookandfeelpainters::TcxNeighbors FNeighbors;
	Cxlookandfeelpainters::TcxButtonState FState;
	System::Types::TRect FTextBounds;
	bool __fastcall GetHotTrack(void);
	bool __fastcall GetPressed(void);
	void __fastcall SetHotTrack(bool AValue);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AValue);
	
protected:
	System::Types::TRect BordersMargins;
	virtual bool __fastcall CanNeighborFor(TcxTreeListHeaderCellViewInfo* ACandidate);
	virtual void __fastcall CheckClipping(const System::Types::TRect &ADisplayRect, const System::Types::TRect &AAvailableRect)/* overload */;
	virtual bool __fastcall CheckNeighbors(TcxTreeListHeaderCellViewInfo* ACandidate, int AShift);
	virtual void __fastcall Click(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignVert(void);
	virtual bool __fastcall GetIsVisible(void);
	virtual bool __fastcall GetMultiline(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall SetPressed(bool AValue);
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint);
	bool __fastcall HasHintPoint(const System::Types::TPoint P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	
public:
	__fastcall virtual TcxTreeListCustomHeaderCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	__property bool HotTrack = {read=GetHotTrack, write=SetHotTrack, nodefault};
	__property bool IsLast = {read=FIsLast, nodefault};
	__property bool MultiLine = {read=GetMultiline, nodefault};
	__property Cxlookandfeelpainters::TcxNeighbors Neighbors = {read=FNeighbors, nodefault};
	__property bool Pressed = {read=GetPressed, write=SetPressed, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
public:
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListCustomHeaderCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListCustomHeaderCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomCellViewInfo(AOwner) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CheckClipping(const System::Types::TRect &ADisplayRect){ Cxinplacecontainer::TcxCustomViewInfoItem::CheckClipping(ADisplayRect); }
	
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	void *__IcxHotTrackElement;	/* Cxinplacecontainer::IcxHotTrackElement */
	
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
	// {E7171E58-276E-499B-9DDF-298D850883C9}
	operator Cxinplacecontainer::_di_IcxHotTrackElement()
	{
		Cxinplacecontainer::_di_IcxHotTrackElement intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxHotTrackElement*(void) { return (Cxinplacecontainer::IcxHotTrackElement*)&__IcxHotTrackElement; }
	#endif
	
};


enum TcxTreeListIndicatorPosition : unsigned char { tlipBands, tlipColumns, tlipContent, tlipFooter };

class PASCALIMPLEMENTATION TcxTreeListIndicatorCellViewInfo : public TcxTreeListCustomHeaderCellViewInfo
{
	typedef TcxTreeListCustomHeaderCellViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxIndicatorKind FKind;
	TcxTreeListIndicatorPosition FPosition;
	TcxTreeListNodeSizingArea* FSizingArea;
	void __fastcall SetKind(Cxlookandfeelpainters::TcxIndicatorKind AValue);
	
protected:
	Cxlookandfeelpainters::TcxIndicatorKind __fastcall ActualIndicatorKind(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	TcxTreeListCustomizationPopup* __fastcall GetPopup(void);
	virtual void __fastcall Initialize(TcxTreeListNode* ANode, TcxTreeListIndicatorPosition APosition);
	bool __fastcall IsQuickCustomizationEnabled(void);
	virtual void __fastcall Scroll(const int DX, const int DY);
	virtual void __fastcall SetPressed(bool AValue);
	void __fastcall ShowPopup(void);
	System::Types::TRect __fastcall GetOwnerBounds(void);
	void __fastcall PopupClosed(void);
	__property TcxTreeListNodeSizingArea* SizingArea = {read=FSizingArea, write=FSizingArea};
	
public:
	__fastcall virtual ~TcxTreeListIndicatorCellViewInfo(void);
	__classmethod virtual int __fastcall CustomDrawID();
	__property Cxlookandfeelpainters::TcxIndicatorKind Kind = {read=FKind, write=SetKind, nodefault};
	__property TcxTreeListIndicatorPosition Position = {read=FPosition, nodefault};
public:
	/* TcxTreeListCustomHeaderCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListIndicatorCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListCustomHeaderCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListIndicatorCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomHeaderCellViewInfo(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListHeaderCellViewInfo : public TcxTreeListCustomHeaderCellViewInfo
{
	typedef TcxTreeListCustomHeaderCellViewInfo inherited;
	
private:
	TcxTreeListCaption* FCaption;
	System::Types::TPoint FGlyphPosition;
	System::Classes::TPersistent* FItem;
	System::Types::TRect FSortMarkBounds;
	Cxinplacecontainer::_di_IcxDragSizing __fastcall GetDragSizing(void);
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	System::Classes::TAlignment __fastcall GetGlyphAlignHorz(void);
	Cxclasses::TcxAlignmentVert __fastcall GetGlyphAlignVert(void);
	
protected:
	bool FHintCalculated;
	bool GlyphClipping;
	virtual void __fastcall DoCalculate(void);
	void __fastcall DoCalculateGlyphPosition(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignVert(void);
	virtual bool __fastcall GetFixed(void);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	virtual bool __fastcall GetMultiline(void);
	virtual bool __fastcall GetSelected(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	virtual System::UnicodeString __fastcall GetText(void);
	void __fastcall Initialize(TcxTreeListCaption* ACaption);
	virtual void __fastcall LinkItem(void);
	void __fastcall ReleaseReference(System::TObject* &AReference);
	virtual void __fastcall Scroll(const int DX, const int DY);
	virtual void __fastcall SetHitItem(void);
	__property Cxinplacecontainer::_di_IcxDragSizing DragSizing = {read=GetDragSizing};
	__property System::Classes::TPersistent* Item = {read=FItem};
	
public:
	__property System::Classes::TAlignment AlignHorz = {read=GetAlignHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=GetAlignVert, nodefault};
	__property bool Fixed = {read=GetFixed, nodefault};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph};
	__property System::Classes::TAlignment GlyphAlignHorz = {read=GetGlyphAlignHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert GlyphAlignVert = {read=GetGlyphAlignVert, nodefault};
	__property System::Types::TPoint GlyphPosition = {read=FGlyphPosition};
	__property bool ShowEndEllipsis = {read=GetShowEndEllipsis, nodefault};
	__property System::Types::TRect SortMarkBounds = {read=FSortMarkBounds};
	__property Dxcore::TdxSortOrder SortOrder = {read=GetSortOrder, nodefault};
	__property System::UnicodeString Text = {read=GetText};
	__property TextBounds;
	__property TreeList;
public:
	/* TcxTreeListCustomHeaderCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListHeaderCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListCustomHeaderCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	
public:
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListHeaderCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListHeaderCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomHeaderCellViewInfo(AOwner) { }
	
private:
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5EA02F4E-E367-4E4D-A26D-000B5E5CD434}
	operator Cxinplacecontainer::_di_IcxDragSizing() { return DragSizing; }
	#else
	operator Cxinplacecontainer::IcxDragSizing*(void) { return (Cxinplacecontainer::IcxDragSizing*)DragSizing; }
	#endif
	
};


class DELPHICLASS TcxTreeListBandHeaderCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListBandHeaderCellViewInfo : public TcxTreeListHeaderCellViewInfo
{
	typedef TcxTreeListHeaderCellViewInfo inherited;
	
private:
	TcxTreeListBand* __fastcall GetBand(void);
	
protected:
	virtual void __fastcall Click(void);
	virtual void __fastcall DoCalculate(void);
	virtual bool __fastcall GetFixed(void);
	virtual bool __fastcall GetIsVisible(void);
	virtual void __fastcall LinkItem(void);
	virtual void __fastcall SetHitItem(void);
	
public:
	__fastcall virtual ~TcxTreeListBandHeaderCellViewInfo(void);
	__classmethod virtual int __fastcall CustomDrawID();
	__property TcxTreeListBand* Band = {read=GetBand};
public:
	/* TcxTreeListCustomHeaderCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListBandHeaderCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListHeaderCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListBandHeaderCellViewInfo(System::TObject* AOwner) : TcxTreeListHeaderCellViewInfo(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListColumnHeaderCellViewInfo : public TcxTreeListHeaderCellViewInfo
{
	typedef TcxTreeListHeaderCellViewInfo inherited;
	
private:
	TcxTreeListBand* __fastcall GetBand(void);
	TcxTreeListColumn* __fastcall GetColumn(void);
	
protected:
	virtual void __fastcall Click(void);
	virtual void __fastcall DoCalculate(void);
	virtual bool __fastcall GetFixed(void);
	virtual bool __fastcall GetIsVisible(void);
	virtual Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	virtual void __fastcall LinkItem(void);
	virtual void __fastcall SetHitItem(void);
	
public:
	__fastcall virtual ~TcxTreeListColumnHeaderCellViewInfo(void);
	__classmethod virtual int __fastcall CustomDrawID();
	__property TcxTreeListBand* Band = {read=GetBand};
	__property TcxTreeListColumn* Column = {read=GetColumn};
public:
	/* TcxTreeListCustomHeaderCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListColumnHeaderCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListHeaderCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListColumnHeaderCellViewInfo(System::TObject* AOwner) : TcxTreeListHeaderCellViewInfo(AOwner) { }
	
};


enum TcxTreeListBandPart : unsigned char { tlbpHeader, tlbpContent, tlbpGroupFooter, tlbpFooter, tlbpSeparator };

class DELPHICLASS TcxTreeListBandCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListBandCellViewInfo : public TcxTreeListCustomCellViewInfo
{
	typedef TcxTreeListCustomCellViewInfo inherited;
	
private:
	TcxTreeListBand* FBand;
	TcxTreeListBandPart FPart;
	
protected:
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	void __fastcall Initialize(TcxTreeListBand* ABand, TcxTreeListNode* ANode, TcxTreeListNode* AAttachNode, TcxTreeListBandPart APart);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	__classmethod virtual int __fastcall CustomDrawID();
	__property TcxTreeListBand* Band = {read=FBand};
	__property TcxTreeListBandPart Part = {read=FPart, nodefault};
	__property AttachNode;
public:
	/* TcxTreeListCustomCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListBandCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListCustomCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListBandCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListBandCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomCellViewInfo(AOwner) { }
	
};


class DELPHICLASS TcxTreeListEditCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListEditCellViewInfo : public Cxinplacecontainer::TcxEditCellViewInfo
{
	typedef Cxinplacecontainer::TcxEditCellViewInfo inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	TcxTreeListNodeViewData* FNodeViewData;
	TcxTreeListBand* __fastcall GetBand(void);
	bool __fastcall GetEditing(void);
	TcxTreeListNode* __fastcall GetNode(void);
	TcxTreeListOptionsView* __fastcall GetOptionsView(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Clear(void);
	virtual System::Types::TRect __fastcall ContentOffset(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxedit::TcxEditButtonTransparency __fastcall GetButtonTransparency(void);
	virtual System::Types::TPoint __fastcall GetCellOrg(void);
	virtual TcxTreeListColumn* __fastcall GetColumn(void);
	virtual System::Variant __fastcall GetDisplayValue(void);
	virtual System::Types::TRect __fastcall GetEditRect(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetEditViewParams(void);
	virtual bool __fastcall GetFocused(void);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	virtual bool __fastcall GetHotTrack(void);
	Cxgraphics::TcxViewParams __fastcall GetIncSearchParams(void);
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	virtual NativeInt __fastcall GetRecordIndex(void);
	virtual bool __fastcall GetSelected(void);
	virtual int __fastcall GetSelectedTextColor(void);
	virtual int __fastcall GetSelectedBKColor(void);
	virtual void * __fastcall GetViewInfoData(void);
	virtual bool __fastcall IsAutoHeight(void);
	virtual bool __fastcall IsEditHotTrack(const System::Types::TPoint APoint);
	virtual bool __fastcall IsEndEllipsis(void);
	virtual bool __fastcall IsFixed(void);
	virtual bool __fastcall IsTransparent(void);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	__classmethod virtual int __fastcall CustomDrawID();
	virtual void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground = false)/* overload */;
	__property TcxTreeListBand* Band = {read=GetBand};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property TcxTreeListColumn* Column = {read=GetColumn};
	__property bool Editing = {read=GetEditing, nodefault};
	__property System::Types::TRect EditRect = {read=GetEditRect};
	__property bool Focused = {read=GetFocused, nodefault};
	__property bool HotTrack = {read=GetHotTrack, nodefault};
	__property TcxTreeListNode* Node = {read=GetNode};
	__property TcxTreeListNodeViewData* NodeViewData = {read=FNodeViewData};
	__property TcxTreeListOptionsView* OptionsView = {read=GetOptionsView};
	__property bool Selected = {read=GetSelected, nodefault};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxEditCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListEditCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListEditCellViewInfo(System::TObject* AOwner) : Cxinplacecontainer::TcxEditCellViewInfo(AOwner) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Invalidate(bool ARecalculate = false){ Cxinplacecontainer::TcxCustomViewInfoItem::Invalidate(ARecalculate); }
	
};


class DELPHICLASS TcxTreeListGroupNodeEditViewInfo;
class PASCALIMPLEMENTATION TcxTreeListGroupNodeEditViewInfo : public TcxTreeListEditCellViewInfo
{
	typedef TcxTreeListEditCellViewInfo inherited;
	
protected:
	virtual TcxTreeListColumn* __fastcall GetColumn(void);
	virtual bool __fastcall GetFocused(void);
	virtual bool __fastcall IsFixed(void);
	virtual void __fastcall Scroll(const int DX, const int DY);
public:
	/* TcxEditCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListGroupNodeEditViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListGroupNodeEditViewInfo(System::TObject* AOwner) : TcxTreeListEditCellViewInfo(AOwner) { }
	
};


class DELPHICLASS TcxTreeListPreviewCellViewInfo;
class DELPHICLASS TcxTreeListPreview;
class PASCALIMPLEMENTATION TcxTreeListPreviewCellViewInfo : public TcxTreeListEditCellViewInfo
{
	typedef TcxTreeListEditCellViewInfo inherited;
	
private:
	TcxTreeListPreview* FPreview;
	
protected:
	virtual System::Types::TRect __fastcall ContentOffset(void);
	virtual void __fastcall DoCalculate(void);
	virtual Cxedit::TcxEditButtonTransparency __fastcall GetButtonTransparency(void);
	virtual TcxTreeListColumn* __fastcall GetColumn(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetEditViewParams(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual int __fastcall GetMaxLineCount(void);
	virtual bool __fastcall IsAutoHeight(void);
	virtual bool __fastcall IsEditHotTrack(const System::Types::TPoint APoint);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	__fastcall virtual TcxTreeListPreviewCellViewInfo(System::TObject* AOwner);
	__classmethod virtual int __fastcall CustomDrawID();
	__property TcxTreeListPreview* Preview = {read=FPreview};
public:
	/* TcxEditCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListPreviewCellViewInfo(void) { }
	
};


enum TcxTreeListIndentLine : unsigned char { ilVertUp, ilVertDown, ilHorz };

typedef System::Set<TcxTreeListIndentLine, TcxTreeListIndentLine::ilVertUp, TcxTreeListIndentLine::ilHorz>  TcxTreeListIndentLines;

enum TcxTreeListNodeIndentKind : unsigned char { nikLevel, nikImage, nikState, nikCheck, nikFooter };

class DELPHICLASS TcxTreeListIndentCellViewInfo;
class PASCALIMPLEMENTATION TcxTreeListIndentCellViewInfo : public TcxTreeListCustomCellViewInfo
{
	typedef TcxTreeListCustomCellViewInfo inherited;
	
private:
	bool FButton;
	System::Types::TRect FGlyphRect;
	System::Types::TRect FHorzTreeLine;
	bool FHotTrack;
	int FImageIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	int FIndex;
	TcxTreeListNodeIndentKind FKind;
	TcxTreeListNode* FLevelNode;
	TcxTreeListIndentLines FLines;
	int FOverlayIndex;
	System::Types::TRect FVertTreeLine;
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetCheckState(void);
	bool __fastcall GetFixed(void);
	bool __fastcall GetHasImage(void);
	bool __fastcall GetIsExpanded(void);
	void __fastcall SetGlyphRect(const System::Types::TRect &AValue);
	
protected:
	void __fastcall CalculateTreeLines(System::Types::TPoint ACenter);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawCheck(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawImage(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawLines(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawTreeLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	Cxedit::TcxCustomEditViewInfo* __fastcall GetCheckBoxViewInfo(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
	virtual void __fastcall InitializeLevelIndent(TcxTreeListNode* ANode, TcxTreeListNode* AAttachNode, int AIndex);
	virtual void __fastcall InitializeImageIndent(Vcl::Imglist::TCustomImageList* AImages);
	virtual void __fastcall Scroll(const int DX, const int DY);
	void __fastcall SetSize(int ATop, int AHeight);
	virtual System::Types::TRect __fastcall GetHintBounds(void);
	virtual bool __fastcall IsNeedHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, bool &IsNeedOffsetHint);
	void __fastcall UpdateHotTrackState(const System::Types::TPoint APoint);
	bool __fastcall HasHintPoint(const System::Types::TPoint P);
	bool __fastcall IsHintAtMousePos(void);
	bool __fastcall UseHintHidePause(void);
	
public:
	__classmethod virtual int __fastcall CustomDrawID();
	__property bool Button = {read=FButton, nodefault};
	__property Cxlookandfeelpainters::TcxCheckBoxState CheckState = {read=GetCheckState, nodefault};
	__property bool Fixed = {read=GetFixed, nodefault};
	__property System::Types::TRect GlyphRect = {read=FGlyphRect, write=SetGlyphRect};
	__property bool HasImage = {read=GetHasImage, nodefault};
	__property System::Types::TRect HorzTreeLine = {read=FHorzTreeLine};
	__property bool HotTrack = {read=FHotTrack, nodefault};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property int Index = {read=FIndex, nodefault};
	__property bool IsExpanded = {read=GetIsExpanded, nodefault};
	__property TcxTreeListNodeIndentKind Kind = {read=FKind, nodefault};
	__property TcxTreeListNode* LevelNode = {read=FLevelNode};
	__property TcxTreeListIndentLines Lines = {read=FLines, nodefault};
	__property int OverlayIndex = {read=FOverlayIndex, nodefault};
	__property System::Types::TRect VertTreeLine = {read=FVertTreeLine};
	__property ViewParams;
	__property TreeList;
public:
	/* TcxTreeListCustomCellViewInfo.CreateEx */ inline __fastcall virtual TcxTreeListIndentCellViewInfo(TcxCustomTreeList* ATreeList, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect) : TcxTreeListCustomCellViewInfo(ATreeList, ABounds, AVisibleRect) { }
	/* TcxTreeListCustomCellViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListIndentCellViewInfo(void) { }
	
public:
	/* TcxCustomViewInfoItem.Create */ inline __fastcall virtual TcxTreeListIndentCellViewInfo(System::TObject* AOwner) : TcxTreeListCustomCellViewInfo(AOwner) { }
	
private:
	void *__IcxHintableObject;	/* Dxcustomhint::IcxHintableObject */
	void *__IcxHotTrackElement;	/* Cxinplacecontainer::IcxHotTrackElement */
	
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
	// {E7171E58-276E-499B-9DDF-298D850883C9}
	operator Cxinplacecontainer::_di_IcxHotTrackElement()
	{
		Cxinplacecontainer::_di_IcxHotTrackElement intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxHotTrackElement*(void) { return (Cxinplacecontainer::IcxHotTrackElement*)&__IcxHotTrackElement; }
	#endif
	
};


class DELPHICLASS TcxTreeListNavigatorSiteViewInfo;
class PASCALIMPLEMENTATION TcxTreeListNavigatorSiteViewInfo : public Cxinplacecontainer::TcxCustomNavigatorSiteViewInfo
{
	typedef Cxinplacecontainer::TcxCustomNavigatorSiteViewInfo inherited;
	
protected:
	virtual bool __fastcall GetHitTest(Cxinplacecontainer::TcxCustomHitTestController* AHitTest);
public:
	/* TcxCustomNavigatorSiteViewInfo.Create */ inline __fastcall virtual TcxTreeListNavigatorSiteViewInfo(System::TObject* AOwner) : Cxinplacecontainer::TcxCustomNavigatorSiteViewInfo(AOwner) { }
	/* TcxCustomNavigatorSiteViewInfo.Destroy */ inline __fastcall virtual ~TcxTreeListNavigatorSiteViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListNodeViewData : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Types::TRect Bounds;
	Cxinplacecontainer::TcxCustomControlCells* Cells;
	bool CheckFooterRgn;
	System::Types::TRect ContentBounds;
	bool DrawFocusRect;
	bool Focused;
	System::Types::TRect FocusRectBounds;
	int GroupFooterCount;
	int Height;
	TcxTreeListIndentCellViewInfo* ImageIndent;
	int IndentWidth;
	TcxTreeListNode* Node;
	System::Types::TPoint Origin;
	int PreviewHeight;
	int RowsHeight;
	int RowsOffset;
	bool Selected;
	TcxTreeListIndentCellViewInfo* StateImageIndent;
	TcxTreeListViewInfo* ViewInfo;
	__fastcall virtual TcxTreeListNodeViewData(TcxTreeListViewInfo* AViewInfo, TcxTreeListNode* ANode, int ACapacity);
	__fastcall virtual ~TcxTreeListNodeViewData(void);
	System::Types::TRect __fastcall GetRealBounds(void);
	System::Types::TRect __fastcall GetRealContentBounds(void);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas, Cxinplacecontainer::TcxCustomDrawCellEvent AHandler);
	virtual void __fastcall Scroll(int DX, int DY, bool ALeftFixed, bool ARightFixed);
	bool __fastcall Update(bool AForceUpdate);
};


class DELPHICLASS TcxTreeListLevelInfo;
class PASCALIMPLEMENTATION TcxTreeListViewInfo : public Cxinplacecontainer::TcxExtEditingControlViewInfo
{
	typedef Cxinplacecontainer::TcxExtEditingControlViewInfo inherited;
	
private:
	int FBandLineHeight;
	System::Types::TRect FBounds;
	bool FCanOffsetContent;
	Cxinplacecontainer::TcxCustomControlCells* FCells;
	System::StaticArray<System::Types::TRect, 3> FContentParts;
	int FContentHeight;
	int FContentWidth;
	Cxedit::TcxCustomEditProperties* FCheckBoxProperties;
	Cxedit::TcxCustomEditViewData* FCheckBoxViewData;
	Cxedit::TcxCustomEditViewInfo* FCheckBoxViewInfo;
	int FDefaultCellHeight;
	System::TObject* FDragItem;
	TcxTreeListEditCellViewInfo* FFakeCell;
	int FFooterLineHeight;
	System::Uitypes::TColor FGridLineColor;
	Cxgraphics::TcxBorders FGridLines;
	System::Classes::TList* FHeaderCells;
	int FHeadersHeight;
	Cxclasses::TcxObjectList* FHitTestCells;
	TcxTreeListBackgroundCellViewInfo* FHorzBackgroundCell;
	System::Types::TRect FHScrollArea;
	int FHScrollInc;
	int FHScrollPage;
	int FHScrollPos;
	int FHScrollSize;
	int FLockCount;
	bool FMultiRows;
	int FNodesHeight;
	Cxclasses::TcxObjectList* FNodesViewData;
	int FNodesVisibleCount;
	Vcl::Graphics::TFont* FPrevFont;
	int FPrevFontHeight;
	int FPreviewLineHeight;
	TIntArray *FRows;
	System::Uitypes::TColor FTreeLineColor;
	TcxTreeListBands* __fastcall GetBands(void);
	int __fastcall GetBandsHeight(void);
	int __fastcall GetBorderSize(void);
	bool __fastcall GetCalculateInProcess(void);
	System::Types::TSize __fastcall GetCheckBoxSize(void);
	TcxTreeListColumn* __fastcall GetColumn(int AIndex);
	int __fastcall GetColumnCount(void);
	int __fastcall GetColumnDefaultEditHeight(TcxTreeListColumn* AColumn);
	int __fastcall GetColumnsRowCount(void);
	System::Types::TRect __fastcall GetContentPart(TcxTreeListBandFixedKind AKind);
	int __fastcall GetCount(void);
	int __fastcall GetDefaultRowHeight(void);
	int __fastcall GetFixedSeparatorWidth(void);
	int __fastcall GetFooterHeight(void);
	int __fastcall GetFooterLineCount(void);
	int __fastcall GetGroupFooterHeight(void);
	int __fastcall GetGroupFooterLineCount(void);
	int __fastcall GetHeadersHeight(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	TcxTreeListBand* __fastcall GetIndentBand(void);
	bool __fastcall GetIndentLeftMost(void);
	int __fastcall GetIndicatorWidth(void);
	TcxTreeListNode* __fastcall GetLastNode(void);
	TcxTreeListLevelInfo* __fastcall GetLevelInfo(int ALevel);
	TcxTreeListNodeViewData* __fastcall GetNodeViewData(int AIndex);
	TcxTreeListOptionsView* __fastcall GetOptionsView(void);
	TcxTreeListViewInfo* __fastcall GetOriginalViewInfo(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	TcxTreeListPreview* __fastcall GetPreview(void);
	TcxTreeListNode* __fastcall GetRoot(void);
	int __fastcall GetRowOffset(int AIndex);
	TcxTreeListSummary* __fastcall GetSummary(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	TcxTreeListStyles* __fastcall GetStyles(void);
	TcxTreeListNode* __fastcall GetTopNode(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	int __fastcall GetVScrollPage(void);
	int __fastcall GetVScrollPos(void);
	int __fastcall GetVScrollSize(void);
	void __fastcall SetCalculateInProcess(bool AValue);
	void __fastcall SetHScrollPos(int APosition);
	void __fastcall SetLastNode(TcxTreeListNode* ANode);
	void __fastcall SetRowOffset(int AIndex, const int AValue);
	
protected:
	int FBandHeaderLineHeight;
	int FHeaderLineHeight;
	TcxTreeListBackgroundCellViewInfo* __fastcall AddBackgroundPart(const System::Types::TRect &ABounds);
	TcxTreeListBandHeaderCellViewInfo* __fastcall AddBandHeader(TcxTreeListBand* ABand, System::Types::TRect &ABounds, const System::Types::TRect &AClipRect);
	TcxTreeListBandCellViewInfo* __fastcall AddBandPart(TcxTreeListBandPart APart, TcxTreeListBand* ABand, TcxTreeListNode* ANode, TcxTreeListNode* AAttachNode, System::Types::TRect &ABounds, System::Types::TRect &AClipRect);
	TcxTreeListBandCellViewInfo* __fastcall AddBandSeparator(TcxTreeListNode* ANode, System::Types::TRect &ABounds, const System::Types::TRect &AClipBounds);
	void __fastcall AddBandsHeaders(TcxTreeListBandFixedKind AKind, const System::Types::TRect &ABounds, const System::Types::TRect &AClipBounds);
	void __fastcall AddCell(TcxTreeListCustomCellViewInfoClass ACellClass, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, void *AInstance);
	TcxTreeListColumnHeaderCellViewInfo* __fastcall AddColumnHeader(TcxTreeListColumn* AColumn, System::Types::TRect &ABounds, const System::Types::TRect &AClipBounds);
	TcxTreeListEditCellViewInfo* __fastcall AddEditCell(TcxTreeListNodeViewData* AViewData, TcxTreeListColumn* AColumn, System::Types::TRect &ABounds, System::Types::TRect &AClipRect, Cxinplacecontainer::TcxEditCellViewInfoClass AClass);
	void __fastcall AddColumnFooterItems(TcxTreeListNode* ADataNode, TcxTreeListNode* AttachNode, TcxTreeListColumn* AColumn, const System::Types::TRect &ABounds, const System::Types::TRect &AClipRect);
	void __fastcall AddFixedSeparators(System::Types::TRect &ABounds, TcxTreeListNode* AAttachNode);
	void __fastcall AddFooter(TcxTreeListNode* AAttachNode, int AIndex, int AIndent, const System::Types::TRect &ABounds);
	void __fastcall AddHeaderHitTestAreas(TcxTreeListHeaderCellViewInfo* ACell, bool AHorz, bool AVert);
	TcxTreeListIndentCellViewInfo* __fastcall AddImageIndent(TcxTreeListNode* ANode, Vcl::Imglist::TCustomImageList* AImages, System::Types::TRect &ABounds, const System::Types::TRect &AClipRect);
	TcxTreeListIndentCellViewInfo* __fastcall AddIndent(TcxTreeListNode* ANode, TcxTreeListNode* AAttachNode, int ALevel, TcxTreeListNodeIndentKind AKind, System::Types::TRect &ABounds, const System::Types::TRect &AClipRect);
	TcxTreeListIndentCellViewInfo* __fastcall AddIndentCheck(TcxTreeListNode* ANode, System::Types::TRect &ABounds, const System::Types::TRect &AClipRect);
	TcxTreeListIndicatorCellViewInfo* __fastcall AddIndicator(TcxTreeListNode* ANode, TcxTreeListIndicatorPosition APosition, System::Types::TRect &ABounds);
	void __fastcall AddNodeBands(TcxTreeListNodeViewData* AViewData);
	void __fastcall AddNodeCategorized(TcxTreeListNodeViewData* AViewData);
	void __fastcall AddNodeColumns(TcxTreeListNodeViewData* AViewData);
	void __fastcall AddNodeFooters(TcxTreeListNodeViewData* AViewData);
	void __fastcall AddNodeIndents(TcxTreeListNodeViewData* AViewData);
	TcxTreeListEditCellViewInfo* __fastcall AddNodePreview(TcxTreeListNodeViewData* AViewData);
	void __fastcall AddNodeStandardContent(TcxTreeListNodeViewData* AViewData);
	TcxTreeListNodeViewData* __fastcall AddNodeViewData(TcxTreeListNode* ANode, bool AInsert);
	void __fastcall AdjustNodeIndents(TcxTreeListNodeViewData* AViewData);
	virtual void __fastcall AfterCalculate(void);
	virtual void __fastcall BeforeCalculate(void);
	virtual void __fastcall CalculateBackgroundParts(void);
	virtual void __fastcall CalculateBandsLayout(void);
	virtual void __fastcall CalculateColumnsLayout(void);
	virtual int __fastcall CalculateDefaultEditHeight(void);
	virtual void __fastcall CalculateDefaultHeights(void);
	virtual void __fastcall CalculateFooterLayout(void);
	void __fastcall CalculateHeaderRowsLayout(void);
	void __fastcall CalculateHeadersNeighbors(void);
	virtual void __fastcall CalculateHitTest(TcxTreeListHitTest* AHitTest);
	virtual void __fastcall CalculateHorzScrollInfo(int AAvailableWidth, int AContentWidth);
	int __fastcall CalculateNodeAutoHeight(TcxTreeListNodeViewData* AViewData);
	virtual void __fastcall CalculateNodesOrigin(void);
	virtual void __fastcall CalculateNodesViewData(void);
	virtual void __fastcall CalculateNodesViewDataBackward(TcxTreeListNode* ANode, bool ACheckHeight, int &AvailableHeight);
	virtual void __fastcall CalculateNodesViewDataForward(TcxTreeListNode* ANode, int &AvailableHeight);
	void __fastcall CellsChanged(void);
	virtual bool __fastcall CheckScrollPosition(System::Uitypes::TScrollCode AScrollCode, int APos, int APage, int AInc, int AMax, int &AScrollPos);
	virtual void __fastcall CorrectBorders(void);
	void __fastcall Clear(void);
	void __fastcall DeleteNodeViewData(int AIndex);
	virtual void __fastcall DoCalculate(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	int __fastcall GetFontHeight(Vcl::Graphics::TFont* const AFont);
	virtual bool __fastcall GetIsIndicatorVisible(void);
	virtual bool __fastcall GetIsPrinting(void);
	int __fastcall GetLevelContentOffset(int ALevel);
	System::Types::TRect __fastcall GetMultilineEditorBounds(const System::Types::TRect &ACellEditBounds, int ACalculatedHeight, Cxedit::TcxInplaceEditAutoHeight AAutoHeight);
	virtual Cxinplacecontainer::TcxCustomNavigatorSiteViewInfoClass __fastcall GetNavigatorSiteViewInfoClass(void);
	int __fastcall GetNodeContentOffset(TcxTreeListNode* ANode);
	virtual bool __fastcall HasFooter(TcxTreeListNode* ANode);
	bool __fastcall HasStateIndent(TcxTreeListNode* ANode);
	void __fastcall InflateBoundsForGridLines(System::Types::TRect &ABounds, System::Types::TRect &AClipRect);
	void __fastcall InitializeHeaderRows(void);
	void __fastcall InitializeRows(const int ANewHeight, TcxTreeListNodeViewData* &AViewData);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall InvalidateRect(const System::Types::TRect &ARect);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	void __fastcall MakeVisible(TcxTreeListNode* ANode);
	int __fastcall MeasureColumnHeaderHeight(TcxTreeListColumn* AColumn);
	void __fastcall RecalculateHitTestCells(void);
	void __fastcall RecreateCheckBoxViewData(void);
	void __fastcall ScrollHorz(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall ScrollVert(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall UpdateScrollBars(void);
	virtual void __fastcall UpdateSelection(void);
	void __fastcall ValidateScrollPos(int &APosition, const int APage, const int AMax);
	__property bool CalculateInProcess = {read=GetCalculateInProcess, write=SetCalculateInProcess, nodefault};
	__property bool CanOffsetContent = {read=FCanOffsetContent, write=FCanOffsetContent, nodefault};
	__property TcxTreeListEditCellViewInfo* FakeCell = {read=FFakeCell};
	__property Cxclasses::TcxObjectList* HitTestCells = {read=FHitTestCells};
	__property bool IsPrinting = {read=GetIsPrinting, nodefault};
	__property int LockCount = {read=FLockCount, write=FLockCount, nodefault};
	__property int RowOffset[int Index] = {read=GetRowOffset, write=SetRowOffset};
	
public:
	__fastcall virtual TcxTreeListViewInfo(Cxinplacecontainer::TcxEditingControl* AOwner);
	__fastcall virtual ~TcxTreeListViewInfo(void);
	TcxTreeListEditCellViewInfo* __fastcall GetEditCell(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	void __fastcall SetDirty(void);
	bool __fastcall Validate(void);
	__property int BandHeaderLineHeight = {read=FBandHeaderLineHeight, nodefault};
	__property int BandLineHeight = {read=FBandLineHeight, nodefault};
	__property TcxTreeListBands* Bands = {read=GetBands};
	__property int BandsHeight = {read=GetBandsHeight, nodefault};
	__property int BorderSize = {read=GetBorderSize, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property Cxinplacecontainer::TcxCustomControlCells* Cells = {read=FCells, write=FCells};
	__property System::Types::TSize CheckboxSize = {read=GetCheckBoxSize};
	__property Cxedit::TcxCustomEditViewInfo* CheckBoxViewInfo = {read=FCheckBoxViewInfo};
	__property Cxedit::TcxCustomEditViewData* CheckBoxViewData = {read=FCheckBoxViewData};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TcxTreeListColumn* Columns[int Index] = {read=GetColumn};
	__property int ColumnsRowCount = {read=GetColumnsRowCount, nodefault};
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property int ContentHeight = {read=FContentHeight, write=FContentHeight, nodefault};
	__property System::Types::TRect ContentParts[TcxTreeListBandFixedKind AKind] = {read=GetContentPart};
	__property int ContentWidth = {read=FContentWidth, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property int DefaultCellHeight = {read=FDefaultCellHeight, nodefault};
	__property int DefaultRowHeight = {read=GetDefaultRowHeight, nodefault};
	__property int FixedSeparatorWidth = {read=GetFixedSeparatorWidth, nodefault};
	__property int FooterHeight = {read=GetFooterHeight, nodefault};
	__property int FooterLineCount = {read=GetFooterLineCount, nodefault};
	__property int FooterLineHeight = {read=FFooterLineHeight, nodefault};
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, nodefault};
	__property Cxgraphics::TcxBorders GridLines = {read=FGridLines, write=FGridLines, nodefault};
	__property int GroupFooterHeight = {read=GetGroupFooterHeight, nodefault};
	__property int GroupFooterLineCount = {read=GetGroupFooterLineCount, nodefault};
	__property int HeaderLineHeight = {read=FHeaderLineHeight, nodefault};
	__property int HeadersHeight = {read=GetHeadersHeight, nodefault};
	__property TcxTreeListBackgroundCellViewInfo* HorzBackgroundCell = {read=FHorzBackgroundCell};
	__property System::Types::TRect HScrollArea = {read=FHScrollArea};
	__property int HScrollInc = {read=FHScrollInc, nodefault};
	__property int HScrollPage = {read=FHScrollPage, nodefault};
	__property int HScrollPos = {read=FHScrollPos, write=SetHScrollPos, nodefault};
	__property int HScrollSize = {read=FHScrollSize, nodefault};
	__property TcxTreeListBand* IndentBand = {read=GetIndentBand};
	__property bool IndentLeftMost = {read=GetIndentLeftMost, nodefault};
	__property bool IsIndicatorVisible = {read=GetIsIndicatorVisible, nodefault};
	__property TcxTreeListLevelInfo* LevelInfo[int ALevel] = {read=GetLevelInfo};
	__property int VScrollPage = {read=GetVScrollPage, nodefault};
	__property int VScrollPos = {read=GetVScrollPos, nodefault};
	__property int VScrollSize = {read=GetVScrollSize, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property int IndicatorWidth = {read=GetIndicatorWidth, nodefault};
	__property TcxTreeListNode* LastNode = {read=GetLastNode, write=SetLastNode};
	__property bool MultiRows = {read=FMultiRows, nodefault};
	__property int NodesHeight = {read=FNodesHeight, nodefault};
	__property Cxclasses::TcxObjectList* NodesViewData = {read=FNodesViewData};
	__property int NodesVisibleCount = {read=FNodesVisibleCount, nodefault};
	__property TcxTreeListNodeViewData* NodeViewData[int Index] = {read=GetNodeViewData};
	__property TcxTreeListOptionsView* OptionsView = {read=GetOptionsView};
	__property TcxTreeListViewInfo* OriginalViewInfo = {read=GetOriginalViewInfo};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxTreeListPreview* Preview = {read=GetPreview};
	__property int PreviewLineHeight = {read=FPreviewLineHeight, nodefault};
	__property TcxTreeListNode* Root = {read=GetRoot};
	__property TcxTreeListSummary* Summary = {read=GetSummary};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages};
	__property TcxTreeListStyles* Styles = {read=GetStyles};
	__property TcxTreeListNode* TopNode = {read=GetTopNode};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property System::Uitypes::TColor TreeLineColor = {read=FTreeLineColor, nodefault};
};


class PASCALIMPLEMENTATION TcxTreeListPainter : public Cxinplacecontainer::TcxExtEditingControlPainter
{
	typedef Cxinplacecontainer::TcxExtEditingControlPainter inherited;
	
private:
	bool FCustomDrawSupported;
	Cxinplacecontainer::TcxCustomControlCells* __fastcall GetCells(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	HIDESBASE TcxTreeListViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall CheckCustomDrawSupport(void);
	virtual void __fastcall CustomDrawCell(Cxgraphics::TcxCanvas* ACanvas, Cxinplacecontainer::TcxCustomViewInfoItem* ACell, bool &ADone);
	
public:
	__property Cxinplacecontainer::TcxCustomControlCells* Cells = {read=GetCells};
	__property bool CustomDrawSupported = {read=FCustomDrawSupported, write=FCustomDrawSupported, nodefault};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property TcxTreeListViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomControlPainter.Create */ inline __fastcall virtual TcxTreeListPainter(Cxinplacecontainer::TcxEditingControl* AOwner) : Cxinplacecontainer::TcxExtEditingControlPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListPainter(void) { }
	
};


class DELPHICLASS TcxTreeListBandOptions;
class PASCALIMPLEMENTATION TcxTreeListBandOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FCustomizing;
	bool FHidden;
	bool FMoving;
	bool FOnlyOwnColumns;
	bool FSizing;
	bool FVertSizing;
	void __fastcall SetSizing(bool AValue);
	void __fastcall SetVertSizing(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxTreeListBandOptions(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool Customizing = {read=FCustomizing, write=FCustomizing, default=1};
	__property bool Hidden = {read=FHidden, write=FHidden, default=0};
	__property bool Moving = {read=FMoving, write=FMoving, default=1};
	__property bool OnlyOwnColumns = {read=FOnlyOwnColumns, write=FOnlyOwnColumns, default=0};
	__property bool Sizing = {read=FSizing, write=SetSizing, default=1};
	__property bool VertSizing = {read=FVertSizing, write=SetVertSizing, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListBandOptions(void) { }
	
};


typedef System::TMetaClass* TcxTreeListBandOptionsClass;

class DELPHICLASS TcxTreeListBandStyles;
class PASCALIMPLEMENTATION TcxTreeListBandStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxTreeListBand* __fastcall GetBand(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall DoGetContentParams(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxTreeListBandStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	__property TcxTreeListBand* Band = {read=GetBand};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* HeaderBackground = {read=GetValue, write=SetValue, index=3};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxTreeListBandStyles(void) { }
	
};


typedef System::TMetaClass* TcxTreeListBandStylesClass;

class DELPHICLASS TcxTreeListBandPosition;
class PASCALIMPLEMENTATION TcxTreeListBandPosition : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	int FBandIndex;
	int FColIndex;
	TcxTreeListBand* FParentBand;
	TcxTreeListBand* __fastcall GetBand(void);
	int __fastcall GetBandIndex(void);
	int __fastcall GetColIndex(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	int __fastcall GetVisibleColIndex(void);
	void __fastcall SetBandIndex(int AValue);
	void __fastcall SetColIndex(int AValue);
	bool __fastcall IsColIndexStored(void);
	bool __fastcall IsLocked(void);
	
protected:
	virtual void __fastcall Changed(void);
	bool __fastcall CheckBandIndex(int &AIndex);
	bool __fastcall IsPositionChanged(void);
	void __fastcall Restore(void);
	void __fastcall Store(void);
	
public:
	__fastcall virtual TcxTreeListBandPosition(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxTreeListBand* Band = {read=GetBand};
	__property TcxTreeListBand* ParentBand = {read=FParentBand};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property int VisibleColIndex = {read=GetVisibleColIndex, nodefault};
	
__published:
	__property int BandIndex = {read=GetBandIndex, write=SetBandIndex, default=-1};
	__property int ColIndex = {read=GetColIndex, write=SetColIndex, stored=IsColIndexStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListBandPosition(void) { }
	
};


class DELPHICLASS TcxTreeListBandRows;
class PASCALIMPLEMENTATION TcxTreeListBand : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	TcxTreeListBandRows* FBandRows;
	int FCalculatedWidth;
	TcxTreeListCaption* FCaption;
	System::Classes::TList* FChildBands;
	System::Classes::TList* FChildVisibleBands;
	System::Classes::TList* FColumns;
	TcxTreeListBandExpandable FExpandable;
	TcxTreeListBandFixedKind FFixedKind;
	bool FHasEmptyArea;
	TcxTreeListBandHeaderCellViewInfo* FHeaderCell;
	bool FIsDestroying;
	int FIndex;
	int FLineCount;
	int FMinWidth;
	TcxTreeListBandOptions* FOptions;
	TcxTreeListBandPosition* FPosition;
	TcxTreeListBandStyles* FStyles;
	bool FVisible;
	System::Classes::TList* FVisibleColumns;
	int FWidth;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	bool __fastcall GetActuallyExpandable(void);
	bool __fastcall GetActuallyVisible(void);
	TcxTreeListBands* __fastcall GetBands(void);
	int __fastcall GetCalculatedWidth(void);
	TcxTreeListColumn* __fastcall GetColumn(int AIndex);
	int __fastcall GetColumnCount(void);
	TcxTreeListBand* __fastcall GetChildBand(int AIndex);
	int __fastcall GetChildBandCount(void);
	int __fastcall GetDisplayWidth(void);
	TcxTreeListBand* __fastcall GetFirstChildBottomBand(void);
	bool __fastcall GetHasEmptyArea(void);
	int __fastcall GetIndentWidth(void);
	bool __fastcall GetIsBottom(void);
	bool __fastcall GetIsFirstInGroup(void);
	bool __fastcall GetIsLastAsChild(void);
	bool __fastcall GetIsLastInGroup(void);
	bool __fastcall GetIsLeftMost(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsRightMost(void);
	bool __fastcall GetIsRoot(void);
	bool __fastcall GetIsWidthFixed(void);
	int __fastcall GetLevel(void);
	TcxTreeListBand* __fastcall GetParentBand(void);
	TcxTreeListBand* __fastcall GetParentBandWidthAssigned(void);
	int __fastcall GetRootIndex(void);
	TcxTreeListBand* __fastcall GetRootParentBand(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	int __fastcall GetVisibleIndex(void);
	TcxTreeListColumn* __fastcall GetVisibleColumn(int AIndex);
	int __fastcall GetVisibleColumnCount(void);
	int __fastcall GetVisibleRootIndex(void);
	void __fastcall SetCaption(TcxTreeListCaption* AValue);
	void __fastcall SetCalculatedWidth(int AValue);
	void __fastcall SetColumn(int AIndex, TcxTreeListColumn* AValue);
	void __fastcall SetDisplayWidth(int AValue);
	void __fastcall SetExpandable(TcxTreeListBandExpandable AValue);
	void __fastcall SetFixedKind(TcxTreeListBandFixedKind AValue);
	void __fastcall SetMinWidth(int AValue);
	void __fastcall SetOptions(TcxTreeListBandOptions* AValue);
	void __fastcall SetPosition(TcxTreeListBandPosition* AValue);
	void __fastcall SetRootIndex(int AValue);
	void __fastcall SetStyles(TcxTreeListBandStyles* AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetVisibleColumn(int AIndex, TcxTreeListColumn* AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	int __fastcall ActualMinWidth(void);
	void __fastcall AdjustSubItems(void);
	void __fastcall AssignChildBandWidths(void);
	void __fastcall AssignColumnsWidth(void);
	void __fastcall AssignWidth(void);
	void __fastcall InitAutoWidthItem(Cxclasses::TcxAutoWidthItem* AItem);
	bool __fastcall IsBandFixedDuringSizing(void);
	bool __fastcall IsOnlyOwnColumns(void);
	bool __fastcall IsVisibleInQuickCustomizationPopup(void);
	void __fastcall CalculateLineCount(int ACurrentLine);
	virtual bool __fastcall CanDropColumnAt(const System::Types::TPoint APoint, /* out */ int &ARowIndex, /* out */ int &AColIndex);
	void __fastcall CheckExpandable(TcxTreeListBand* &ABand);
	void __fastcall ForceWidth(int AValue);
	int __fastcall GetMaxDeltaWidth(void);
	virtual bool __fastcall CanMoving(void);
	virtual void __fastcall ChangeCaption(System::TObject* Sender);
	virtual TcxTreeListBandOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxTreeListBandStylesClass __fastcall GetStyleClass(void);
	void __fastcall AddBand(TcxTreeListBand* ABand);
	void __fastcall AddColumn(TcxTreeListColumn* AColumn);
	void __fastcall ColumnSizeChanged(TcxTreeListColumn* AColumn);
	void __fastcall DeleteColumn(TcxTreeListColumn* AColumn);
	void __fastcall LayoutChanged(void);
	void __fastcall MoveBandsToRoot(void);
	void __fastcall MoveColumnsTo(TcxTreeListBand* ABand);
	void __fastcall Refresh(void);
	void __fastcall RemoveBand(TcxTreeListBand* ABand);
	void __fastcall RemoveChildBands(void);
	void __fastcall RemoveColumns(void);
	virtual void __fastcall SetIndex(int Value);
	bool __fastcall CanSizing(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual System::Types::TRect __fastcall GetSizingBoundsRect(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual int __fastcall GetSizingIncrement(Cxinplacecontainer::TcxDragSizingDirection ADirection);
	virtual bool __fastcall IsDynamicUpdate(void);
	virtual void __fastcall SetSizeDelta(Cxinplacecontainer::TcxDragSizingDirection ADirection, int ADelta);
	System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	int __fastcall GetPropertyIndex(const System::UnicodeString AName);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property int CalculatedWidth = {read=GetCalculatedWidth, write=SetCalculatedWidth, nodefault};
	__property System::Classes::TList* ChildVisibleBands = {read=FChildVisibleBands};
	__property TcxTreeListBand* FirstChildBottomBand = {read=GetFirstChildBottomBand};
	__property bool HasEmptyArea = {read=GetHasEmptyArea, write=FHasEmptyArea, nodefault};
	__property TcxTreeListBandHeaderCellViewInfo* HeaderCell = {read=FHeaderCell, write=FHeaderCell};
	__property bool IsFirstInGroup = {read=GetIsFirstInGroup, nodefault};
	__property bool IsLastInGroup = {read=GetIsLastInGroup, nodefault};
	__property bool IsWidthFixed = {read=GetIsWidthFixed, nodefault};
	__property TcxTreeListBand* ParentBandWidthAssigned = {read=GetParentBandWidthAssigned};
	
public:
	__fastcall virtual TcxTreeListBand(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxTreeListBand(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall ApplyBestFit(void);
	virtual void __fastcall BeforeDestruction(void);
	int __fastcall IndexOf(TcxTreeListBand* AChildBand);
	bool __fastcall HasAsParent(TcxTreeListBand* ABand);
	void __fastcall MoveBand(TcxTreeListBand* ABand, int AColIndex);
	virtual void __fastcall RestoreDefaults(void);
	void __fastcall RestoreWidths(void);
	__property bool ActuallyExpandable = {read=GetActuallyExpandable, nodefault};
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property TcxTreeListBandRows* BandRows = {read=FBandRows};
	__property TcxTreeListBands* Bands = {read=GetBands};
	__property int ChildBandCount = {read=GetChildBandCount, nodefault};
	__property TcxTreeListBand* ChildBands[int Index] = {read=GetChildBand};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TcxTreeListColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	__property int DisplayWidth = {read=GetDisplayWidth, write=SetDisplayWidth, nodefault};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property bool IsBottom = {read=GetIsBottom, nodefault};
	__property bool IsLastAsChild = {read=GetIsLastAsChild, nodefault};
	__property bool IsLeftMost = {read=GetIsLeftMost, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsRightMost = {read=GetIsRightMost, nodefault};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property int Level = {read=GetLevel, nodefault};
	__property int LineCount = {read=FLineCount, nodefault};
	__property TcxTreeListBand* ParentBand = {read=GetParentBand};
	__property int RootIndex = {read=GetRootIndex, write=SetRootIndex, nodefault};
	__property TcxTreeListBand* RootParentBand = {read=GetRootParentBand};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property int VisibleColumnCount = {read=GetVisibleColumnCount, nodefault};
	__property TcxTreeListColumn* VisibleColumns[int Index] = {read=GetVisibleColumn, write=SetVisibleColumn};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property int VisibleRootIndex = {read=GetVisibleRootIndex, nodefault};
	__property Index;
	
__published:
	__property TcxTreeListCaption* Caption = {read=FCaption, write=SetCaption};
	__property TcxTreeListBandExpandable Expandable = {read=FExpandable, write=SetExpandable, default=0};
	__property TcxTreeListBandFixedKind FixedKind = {read=FFixedKind, write=SetFixedKind, default=0};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=20};
	__property TcxTreeListBandOptions* Options = {read=FOptions, write=SetOptions};
	__property TcxTreeListBandPosition* Position = {read=FPosition, write=SetPosition};
	__property TcxTreeListBandStyles* Styles = {read=FStyles, write=SetStyles};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxDragSizing;	/* Cxinplacecontainer::IcxDragSizing */
	
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5EA02F4E-E367-4E4D-A26D-000B5E5CD434}
	operator Cxinplacecontainer::_di_IcxDragSizing()
	{
		Cxinplacecontainer::_di_IcxDragSizing intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxinplacecontainer::IcxDragSizing*(void) { return (Cxinplacecontainer::IcxDragSizing*)&__IcxDragSizing; }
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


typedef System::TMetaClass* TcxTreeListBandClass;

class PASCALIMPLEMENTATION TcxTreeListBands : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxTreeListBand* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	System::Classes::TList* FBottomItems;
	int FColumnsLineCount;
	TcxTreeListBand* FExpandableBand;
	int FLineCount;
	int FLockUpdate;
	System::Classes::TList* FRootItems;
	TcxCustomTreeList* FTreeList;
	System::Classes::TList* FVisibleItems;
	int FVisibleLeftFixedCount;
	int FVisibleRightFixedCount;
	System::Classes::TList* FVisibleRootItems;
	int FVisibleRootLeftFixedCount;
	int FVisibleRootRightFixedCount;
	TcxTreeListBand* __fastcall GetBottomItem(int AIndex);
	int __fastcall GetBottomItemCount(void);
	TcxTreeListBand* __fastcall GetFirstVisibleBand(void);
	HIDESBASE TcxTreeListBand* __fastcall GetItem(int AIndex);
	TcxTreeListBand* __fastcall GetLastVisibleBand(void);
	int __fastcall GetRootItemCount(void);
	TcxTreeListBand* __fastcall GetRootItem(int AIndex);
	TcxTreeListBand* __fastcall GetVisibleItem(int AIndex);
	int __fastcall GetVisibleItemCount(void);
	TcxTreeListBand* __fastcall GetVisibleRootItem(int AIndex);
	int __fastcall GetVisibleRootItemCount(void);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxTreeListBand* AValue);
	
protected:
	virtual void __fastcall Adjust(System::Classes::TList* ABands = (System::Classes::TList*)(0x0), int AWidth = 0x0);
	void __fastcall AssignColumnsWidth(void);
	void __fastcall AssignRootItemWidths(void);
	void __fastcall AssignRowColumnsWidth(TcxTreeListBandRow* ARow);
	virtual bool __fastcall CanExpandableLeftMostOnly(void);
	void __fastcall ClearCalculatedWidths(void);
	int __fastcall GetFirstVisibleIndex(TcxTreeListBandFixedKind AFixedKind);
	int __fastcall GetFirstVisibleRootIndex(TcxTreeListBandFixedKind AFixedKind);
	int __fastcall GetLastVisibleIndex(TcxTreeListBandFixedKind AFixedKind);
	int __fastcall GetLastVisibleRootIndex(TcxTreeListBandFixedKind AFixedKind);
	int __fastcall GetVisibleCountByKind(TcxTreeListBandFixedKind AFixedKind);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Notify(System::Classes::TCollectionItem* Item, System::Classes::TCollectionNotification Action);
	int __fastcall PopulateVisibleChildren(TcxTreeListBand* ABand);
	void __fastcall RefreshInformation(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	bool __fastcall IsUpdateLocked(void);
	void __fastcall LockUpdate(void);
	void __fastcall UnlockUpdate(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetChildren(System::Classes::TStringList* AChildren);
	
public:
	__fastcall virtual TcxTreeListBands(TcxCustomTreeList* AOwner);
	__fastcall virtual ~TcxTreeListBands(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	HIDESBASE TcxTreeListBand* __fastcall Add(void);
	virtual void __fastcall RestoreDefaults(void);
	virtual void __fastcall RestoreWidths(void);
	int __fastcall VisibleIndexOf(TcxTreeListBand* ABand);
	__property int BottomItemCount = {read=GetBottomItemCount, nodefault};
	__property TcxTreeListBand* BottomItems[int Index] = {read=GetBottomItem};
	__property int ColumnsLineCount = {read=FColumnsLineCount, nodefault};
	__property TcxTreeListBand* ExpandableBand = {read=FExpandableBand};
	__property TcxTreeListBand* FirstVisible = {read=GetFirstVisibleBand};
	__property TcxTreeListBand* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxTreeListBand* LastVisible = {read=GetLastVisibleBand};
	__property int LineCount = {read=FLineCount, nodefault};
	__property int RootItemCount = {read=GetRootItemCount, nodefault};
	__property TcxTreeListBand* RootItems[int Index] = {read=GetRootItem};
	__property TcxCustomTreeList* TreeList = {read=FTreeList};
	__property int VisibleItemCount = {read=GetVisibleItemCount, nodefault};
	__property TcxTreeListBand* VisibleItems[int Index] = {read=GetVisibleItem};
	__property int VisibleLeftFixedCount = {read=FVisibleLeftFixedCount, nodefault};
	__property int VisibleRightFixedCount = {read=FVisibleRightFixedCount, nodefault};
	__property int VisibleRootItemCount = {read=GetVisibleRootItemCount, nodefault};
	__property TcxTreeListBand* VisibleRootItems[int Index] = {read=GetVisibleRootItem};
	__property int VisibleRootLeftFixedCount = {read=FVisibleRootLeftFixedCount, nodefault};
	__property int VisibleRootRightFixedCount = {read=FVisibleRootRightFixedCount, nodefault};
private:
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
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


class PASCALIMPLEMENTATION TcxTreeListBandRow : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxTreeListColumn* operator[](int Index) { return Items[Index]; }
	
private:
	TcxTreeListBandRows* FBandRows;
	System::Classes::TList* FItems;
	int FLineCount;
	int FLineOffset;
	int FMinWidth;
	System::Classes::TList* FVisibleItems;
	int FWidth;
	bool FWidthAssigned;
	TcxTreeListBand* __fastcall GetBand(void);
	int __fastcall GetCount(void);
	TcxTreeListColumn* __fastcall GetFirst(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetIsFirst(void);
	bool __fastcall GetIsLast(void);
	TcxTreeListColumn* __fastcall GetItem(int AIndex);
	int __fastcall GetVisibleIndex(void);
	TcxTreeListColumn* __fastcall GetVisibleItem(int AIndex);
	int __fastcall GetVisibleItemCount(void);
	TcxTreeListColumn* __fastcall GetLast(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	void __fastcall AdjustColumns(void);
	void __fastcall AssignColumnsWidth(void);
	void __fastcall CheckEmpty(void);
	virtual void __fastcall Refresh(void);
	__property bool WidthAssigned = {read=FWidthAssigned, nodefault};
	
public:
	__fastcall virtual TcxTreeListBandRow(TcxTreeListBandRows* AOwner);
	__fastcall virtual ~TcxTreeListBandRow(void);
	int __fastcall IndexOf(TcxTreeListColumn* AColumn);
	__property TcxTreeListBand* Band = {read=GetBand};
	__property TcxTreeListBandRows* BandRows = {read=FBandRows};
	__property int Count = {read=GetCount, nodefault};
	__property TcxTreeListColumn* First = {read=GetFirst};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsFirst = {read=GetIsLast, nodefault};
	__property bool IsLast = {read=GetIsFirst, nodefault};
	__property TcxTreeListColumn* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxTreeListColumn* Last = {read=GetLast};
	__property int LineCount = {read=FLineCount, nodefault};
	__property int LineOffset = {read=FLineOffset, nodefault};
	__property int MinWidth = {read=FMinWidth, nodefault};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
	__property int VisibleItemCount = {read=GetVisibleItemCount, nodefault};
	__property TcxTreeListColumn* VisibleItems[int Index] = {read=GetVisibleItem};
	__property int Width = {read=FWidth, nodefault};
};


class PASCALIMPLEMENTATION TcxTreeListBandRows : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxTreeListBandRow* operator[](int Index) { return Items[Index]; }
	
private:
	TcxTreeListBand* FBand;
	Cxclasses::TcxObjectList* FItems;
	int FLineCount;
	int FRowMaxWidth;
	int FRowMinWidth;
	System::Classes::TList* FVisibleItems;
	int __fastcall GetCount(void);
	TcxTreeListBandRow* __fastcall GetFirst(void);
	TcxTreeListBandRow* __fastcall GetItem(int Index);
	TcxTreeListBandRow* __fastcall GetItemEx(int Index);
	TcxTreeListBandRow* __fastcall GetLast(void);
	int __fastcall GetVisibleItemCount(void);
	TcxTreeListBandRow* __fastcall GetVisibleItem(int AIndex);
	
protected:
	TcxTreeListBandRow* __fastcall Add(void);
	TcxTreeListBandRow* __fastcall CheckRowIndex(int ARowIndex);
	void __fastcall CheckRowEmpty(int ARowIndex);
	TcxTreeListBandRow* __fastcall Insert(int AIndex);
	virtual void __fastcall Refresh(void);
	
public:
	__fastcall virtual TcxTreeListBandRows(TcxTreeListBand* AOwner);
	__fastcall virtual ~TcxTreeListBandRows(void);
	__property TcxTreeListBand* Band = {read=FBand};
	__property int Count = {read=GetCount, nodefault};
	__property TcxTreeListBandRow* First = {read=GetFirst};
	__property TcxTreeListBandRow* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxTreeListBandRow* Last = {read=GetLast};
	__property int LineCount = {read=FLineCount, nodefault};
	__property int RowMaxWidth = {read=FRowMaxWidth, nodefault};
	__property int RowMinWidth = {read=FRowMinWidth, nodefault};
	__property int VisibleItemCount = {read=GetVisibleItemCount, nodefault};
	__property TcxTreeListBandRow* VisibleItems[int Index] = {read=GetVisibleItem};
};


enum TcxTreeListGroupFootersMode : unsigned char { tlgfInvisible, tlgfVisibleWhenExpanded, tlgfAlwaysVisible };

enum TcxTreeListTreeLineStyle : unsigned char { tllsNone, tllsDot, tllsSolid };

enum TcxTreeListPaintStyle : unsigned char { tlpsStandard, tlpsCategorized };

class PASCALIMPLEMENTATION TcxTreeListOptionsView : public Cxinplacecontainer::TcxControlOptionsView
{
	typedef Cxinplacecontainer::TcxControlOptionsView inherited;
	
private:
	int FBandLineHeight;
	bool FBands;
	bool FButtons;
	TcxTreeListColumn* FCategorizedColumn;
	bool FCheckGroups;
	bool FColumnAutoWidth;
	System::Uitypes::TColor FDropArrowColor;
	bool FDropNodeIndicator;
	bool FDynamicIndent;
	bool FDynamicFocusedStateImages;
	System::Uitypes::TColor FEditAutoHeightBorderColor;
	bool FExtPaintStyle;
	System::Uitypes::TColor FFixedSeparatorColor;
	int FFixedSeparatorWidth;
	bool FFocusRect;
	bool FFooter;
	System::Uitypes::TColor FGridLineColor;
	TcxTreeListGridLines FGridLines;
	TcxTreeListGroupFootersMode FGroupFooters;
	bool FHeaderAutoHeight;
	bool FHeaders;
	bool FIndicator;
	int FIndicatorWidth;
	TcxTreeListPaintStyle FPaintStyle;
	bool FShowRoot;
	bool FSimpleCustomizeBox;
	System::Uitypes::TColor FTreeLineColor;
	TcxTreeListTreeLineStyle FTreeLineStyle;
	bool FUseImageIndexForSelected;
	bool FUseNodeColorForIndent;
	bool __fastcall GetIsIndicatorVisible(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetBandLineHeight(int AValue);
	void __fastcall SetBands(bool AValue);
	void __fastcall SetButtons(bool AValue);
	void __fastcall SetCategorizedColumn(TcxTreeListColumn* AValue);
	void __fastcall SetCheckGroups(bool AValue);
	void __fastcall SetColumnAutoWidth(bool AValue);
	void __fastcall SetDynamicIndent(bool AValue);
	void __fastcall SetDynamicFocusedStateImages(bool AValue);
	void __fastcall SetEditAutoHeightBorderColor(System::Uitypes::TColor AValue);
	void __fastcall SetExtPaintStyle(bool AValue);
	void __fastcall SetFixedSeparatorColor(System::Uitypes::TColor AValue);
	void __fastcall SetFixedSeparatorWidth(int AValue);
	void __fastcall SetFocusRect(bool AValue);
	void __fastcall SetFooter(bool AValue);
	void __fastcall SetGridLineColor(System::Uitypes::TColor AValue);
	void __fastcall SetGridLines(TcxTreeListGridLines AValue);
	void __fastcall SetGroupFooters(TcxTreeListGroupFootersMode AValue);
	void __fastcall SetHeaderAutoHeight(bool AValue);
	void __fastcall SetHeaders(bool AValue);
	void __fastcall SetIndicator(bool AValue);
	void __fastcall SetIndicatorWidth(int AValue);
	void __fastcall SetPaintStyle(TcxTreeListPaintStyle AValue);
	void __fastcall SetShowRoot(bool AValue);
	void __fastcall SetSimpleCustomizeBox(bool AValue);
	void __fastcall SetTreeLineColor(System::Uitypes::TColor AValue);
	void __fastcall SetTreeLineStyle(TcxTreeListTreeLineStyle AValue);
	void __fastcall SetUseImageIndexForSelected(bool AValue);
	void __fastcall SetUseNodeColorForIndent(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	System::TObject* __fastcall GetControl(void);
	int __fastcall HorzIncrement(void);
	bool __fastcall IsCategorizedPaint(void);
	bool __fastcall IsExtPaintStyle(void);
	int __fastcall VertIncrement(void);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
public:
	__fastcall virtual TcxTreeListOptionsView(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxTreeListColumn* __fastcall GetCategorizedColumn(void);
	virtual void __fastcall RestoreDefaults(void);
	__property bool IsIndicatorVisible = {read=GetIsIndicatorVisible, nodefault};
	
__published:
	__property int BandLineHeight = {read=FBandLineHeight, write=SetBandLineHeight, default=0};
	__property bool Bands = {read=FBands, write=SetBands, default=0};
	__property bool Buttons = {read=FButtons, write=SetButtons, default=1};
	__property TcxTreeListColumn* CategorizedColumn = {read=FCategorizedColumn, write=SetCategorizedColumn};
	__property bool ColumnAutoWidth = {read=FColumnAutoWidth, write=SetColumnAutoWidth, default=0};
	__property bool CheckGroups = {read=FCheckGroups, write=SetCheckGroups, default=0};
	__property System::Uitypes::TColor DropArrowColor = {read=FDropArrowColor, write=FDropArrowColor, default=65280};
	__property bool DropNodeIndicator = {read=FDropNodeIndicator, write=FDropNodeIndicator, default=0};
	__property bool DynamicIndent = {read=FDynamicIndent, write=SetDynamicIndent, default=0};
	__property bool DynamicFocusedStateImages = {read=FDynamicFocusedStateImages, write=SetDynamicFocusedStateImages, default=0};
	__property System::Uitypes::TColor EditAutoHeightBorderColor = {read=FEditAutoHeightBorderColor, write=SetEditAutoHeightBorderColor, default=536870912};
	__property bool ExtPaintStyle = {read=FExtPaintStyle, write=SetExtPaintStyle, default=0};
	__property System::Uitypes::TColor FixedSeparatorColor = {read=FFixedSeparatorColor, write=SetFixedSeparatorColor, default=536870912};
	__property int FixedSeparatorWidth = {read=FFixedSeparatorWidth, write=SetFixedSeparatorWidth, default=2};
	__property bool FocusRect = {read=FFocusRect, write=SetFocusRect, default=1};
	__property bool Footer = {read=FFooter, write=SetFooter, default=0};
	__property System::Uitypes::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, default=536870912};
	__property TcxTreeListGridLines GridLines = {read=FGridLines, write=SetGridLines, default=0};
	__property TcxTreeListGroupFootersMode GroupFooters = {read=FGroupFooters, write=SetGroupFooters, default=0};
	__property bool HeaderAutoHeight = {read=FHeaderAutoHeight, write=SetHeaderAutoHeight, default=0};
	__property bool Headers = {read=FHeaders, write=SetHeaders, default=1};
	__property bool Indicator = {read=FIndicator, write=SetIndicator, default=0};
	__property int IndicatorWidth = {read=FIndicatorWidth, write=SetIndicatorWidth, default=12};
	__property NavigatorOffset = {default=50};
	__property TcxTreeListPaintStyle PaintStyle = {read=FPaintStyle, write=SetPaintStyle, default=0};
	__property bool ShowRoot = {read=FShowRoot, write=SetShowRoot, default=1};
	__property bool SimpleCustomizeBox = {read=FSimpleCustomizeBox, write=SetSimpleCustomizeBox, default=0};
	__property System::Uitypes::TColor TreeLineColor = {read=FTreeLineColor, write=SetTreeLineColor, default=536870912};
	__property TcxTreeListTreeLineStyle TreeLineStyle = {read=FTreeLineStyle, write=SetTreeLineStyle, default=1};
	__property bool UseImageIndexForSelected = {read=FUseImageIndexForSelected, write=SetUseImageIndexForSelected, default=1};
	__property bool UseNodeColorForIndent = {read=FUseNodeColorForIndent, write=SetUseNodeColorForIndent, default=1};
	__property CellAutoHeight = {default=0};
	__property CellEndEllipsis = {default=0};
	__property CellTextMaxLineCount = {default=0};
	__property ScrollBars = {default=3};
	__property ShowEditButtons;
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListOptionsView(void) { }
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
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


class PASCALIMPLEMENTATION TcxTreeListOptionsCustomizing : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FBandCustomizing;
	bool FBandHiding;
	bool FBandHorzSizing;
	bool FBandMoving;
	bool FBandsQuickCustomization;
	int FBandsQuickCustomizationMaxDropDownCount;
	bool FBandVertSizing;
	bool FColumnCustomizing;
	bool FColumnHiding;
	bool FColumnHorzSizing;
	bool FColumnMoving;
	bool FColumnsQuickCustomization;
	int FColumnsQuickCustomizationMaxDropDownCount;
	bool FColumnVertSizing;
	bool FDynamicSizing;
	bool FNestedBands;
	bool FNodeSizing;
	bool FRowSizing;
	bool FStackedColumns;
	TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetBandCustomizing(bool AValue);
	void __fastcall SetBandHiding(bool AValue);
	void __fastcall SetBandHorzSizing(bool AValue);
	void __fastcall SetBandMoving(bool AValue);
	void __fastcall SetBandsQuickCustomization(bool AValue);
	void __fastcall SetBandVertSizing(bool AValue);
	void __fastcall SetColumnCustomizing(bool AValue);
	void __fastcall SetColumnHiding(bool AValue);
	void __fastcall SetColumnHorzSizing(bool AValue);
	void __fastcall SetColumnMoving(bool AValue);
	void __fastcall SetColumnsQuickCustomization(bool AValue);
	void __fastcall SetColumnVertSizing(bool AValue);
	void __fastcall SetDynamicSizing(bool AValue);
	void __fastcall SetNestedBands(bool AValue);
	void __fastcall SetNodeSizing(bool AValue);
	void __fastcall SetRowSizing(bool AValue);
	void __fastcall SetStackedColumns(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxTreeListOptionsCustomizing(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property bool BandCustomizing = {read=FBandCustomizing, write=SetBandCustomizing, default=1};
	__property bool BandHorzSizing = {read=FBandHorzSizing, write=SetBandHorzSizing, default=1};
	__property bool BandHiding = {read=FBandHiding, write=SetBandHiding, default=0};
	__property bool BandMoving = {read=FBandMoving, write=SetBandMoving, default=1};
	__property bool BandsQuickCustomization = {read=FBandsQuickCustomization, write=SetBandsQuickCustomization, default=0};
	__property int BandsQuickCustomizationMaxDropDownCount = {read=FBandsQuickCustomizationMaxDropDownCount, write=FBandsQuickCustomizationMaxDropDownCount, default=0};
	__property bool BandVertSizing = {read=FBandVertSizing, write=SetBandVertSizing, default=1};
	__property bool ColumnCustomizing = {read=FColumnCustomizing, write=SetColumnCustomizing, default=1};
	__property bool ColumnHiding = {read=FColumnHiding, write=SetColumnHiding, default=0};
	__property bool ColumnHorzSizing = {read=FColumnHorzSizing, write=SetColumnHorzSizing, default=1};
	__property bool ColumnMoving = {read=FColumnMoving, write=SetColumnMoving, default=1};
	__property bool ColumnsQuickCustomization = {read=FColumnsQuickCustomization, write=SetColumnsQuickCustomization, default=0};
	__property int ColumnsQuickCustomizationMaxDropDownCount = {read=FColumnsQuickCustomizationMaxDropDownCount, write=FColumnsQuickCustomizationMaxDropDownCount, default=0};
	__property bool ColumnVertSizing = {read=FColumnVertSizing, write=SetColumnVertSizing, default=1};
	__property bool DynamicSizing = {read=FDynamicSizing, write=SetDynamicSizing, default=0};
	__property bool NestedBands = {read=FNestedBands, write=SetNestedBands, default=1};
	__property bool NodeSizing = {read=FNodeSizing, write=SetNodeSizing, default=0};
	__property bool RowSizing = {read=FRowSizing, write=SetRowSizing, default=0};
	__property bool StackedColumns = {read=FStackedColumns, write=SetStackedColumns, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListOptionsCustomizing(void) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListOptionsSelection : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FCellSelect;
	bool FHideFocusRect;
	bool FHideSelection;
	bool FInvertSelect;
	bool FMultiSelect;
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
public:
	__fastcall virtual TcxTreeListOptionsSelection(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property bool CellSelect = {read=FCellSelect, write=FCellSelect, default=1};
	__property bool HideFocusRect = {read=FHideFocusRect, write=FHideFocusRect, default=1};
	__property bool HideSelection = {read=FHideSelection, write=FHideSelection, default=0};
	__property bool InvertSelect = {read=FInvertSelect, write=FInvertSelect, default=1};
	__property bool MultiSelect = {read=FMultiSelect, write=FMultiSelect, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListOptionsSelection(void) { }
	
};


typedef System::TMetaClass* TcxTreeListOptionsSelectionClass;

class PASCALIMPLEMENTATION TcxTreeListOptionsBehavior : public Cxinplacecontainer::TcxControlOptionsBehavior
{
	typedef Cxinplacecontainer::TcxControlOptionsBehavior inherited;
	
private:
	bool FAutoDragCopy;
	int FBestFitMaxRecordCount;
	bool FConfirmDelete;
	bool FDragCollapse;
	bool FDragExpand;
	bool FDragFocusing;
	Cxedit::TcxInplaceEditAutoHeight FEditAutoHeight;
	bool FExpandOnDblClick;
	bool FExpandOnIncSearch;
	bool FFooterHints;
	bool FHeaderHints;
	bool FHotTrack;
	bool FMultiSort;
	bool FShowHourGlass;
	bool FSorting;
	int FWaitExpandingTime;
	int __fastcall GetChangeDelay(void);
	TcxTreeListColumn* __fastcall GetIncSearchItem(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall ReadBoolean(System::Classes::TReader* AReader);
	void __fastcall SetChangeDelay(int AValue);
	void __fastcall SetEditAutoHeight(Cxedit::TcxInplaceEditAutoHeight AValue);
	void __fastcall SetFooterHints(bool AValue);
	void __fastcall SetHeaderHints(bool AValue);
	HIDESBASE void __fastcall SetIncSearchItem(TcxTreeListColumn* AValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	__fastcall virtual TcxTreeListOptionsBehavior(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property bool AutoDragCopy = {read=FAutoDragCopy, write=FAutoDragCopy, default=0};
	__property int BestFitMaxRecordCount = {read=FBestFitMaxRecordCount, write=FBestFitMaxRecordCount, default=-1};
	__property int ChangeDelay = {read=GetChangeDelay, write=SetChangeDelay, default=0};
	__property bool ConfirmDelete = {read=FConfirmDelete, write=FConfirmDelete, default=1};
	__property bool DragCollapse = {read=FDragCollapse, write=FDragCollapse, default=1};
	__property DragDropText = {default=0};
	__property bool DragExpand = {read=FDragExpand, write=FDragExpand, default=1};
	__property bool DragFocusing = {read=FDragFocusing, write=FDragFocusing, default=0};
	__property Cxedit::TcxInplaceEditAutoHeight EditAutoHeight = {read=FEditAutoHeight, write=SetEditAutoHeight, default=0};
	__property bool ExpandOnDblClick = {read=FExpandOnDblClick, write=FExpandOnDblClick, default=1};
	__property bool ExpandOnIncSearch = {read=FExpandOnIncSearch, write=FExpandOnIncSearch, default=0};
	__property FocusCellOnCycle = {default=0};
	__property bool FooterHints = {read=FFooterHints, write=SetFooterHints, default=0};
	__property bool HeaderHints = {read=FHeaderHints, write=SetHeaderHints, default=0};
	__property bool HotTrack = {read=FHotTrack, write=FHotTrack, default=0};
	__property IncSearch = {default=0};
	__property TcxTreeListColumn* IncSearchItem = {read=GetIncSearchItem, write=SetIncSearchItem, default=0};
	__property bool MultiSort = {read=FMultiSort, write=FMultiSort, default=1};
	__property NavigatorHints = {default=0};
	__property bool ShowHourGlass = {read=FShowHourGlass, write=FShowHourGlass, default=1};
	__property bool Sorting = {read=FSorting, write=FSorting, default=1};
	__property int WaitForExpandNodeTime = {read=FWaitExpandingTime, write=FWaitExpandingTime, default=500};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListOptionsBehavior(void) { }
	
};


class DELPHICLASS TcxTreeListOptionsData;
class PASCALIMPLEMENTATION TcxTreeListOptionsData : public Cxinplacecontainer::TcxControlOptionsData
{
	typedef Cxinplacecontainer::TcxControlOptionsData inherited;
	
private:
	bool FDeleting;
	bool FInserting;
	Dxcore::TdxDefaultBoolean FMultiThreadedSorting;
	bool FSummaryNullIgnore;
	bool __fastcall GetAnsiSort(void);
	bool __fastcall GetCaseInsensitive(void);
	void __fastcall SetAnsiSort(bool Value);
	void __fastcall SetCaseInsensitive(bool Value);
	void __fastcall SetDeleting(const bool Value);
	void __fastcall SetInserting(const bool Value);
	void __fastcall SetSummaryNullIgnore(bool Value);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TcxTreeListOptionsData(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AnsiSort = {read=GetAnsiSort, write=SetAnsiSort, default=0};
	__property bool CaseInsensitive = {read=GetCaseInsensitive, write=SetCaseInsensitive, default=0};
	__property bool Deleting = {read=FDeleting, write=SetDeleting, default=1};
	__property bool Inserting = {read=FInserting, write=SetInserting, default=0};
	__property Dxcore::TdxDefaultBoolean MultiThreadedSorting = {read=FMultiThreadedSorting, write=FMultiThreadedSorting, default=2};
	__property bool SummaryNullIgnore = {read=FSummaryNullIgnore, write=SetSummaryNullIgnore, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListOptionsData(void) { }
	
};


enum TcxTreeListPreviewPlace : unsigned char { tlppBottom, tlppTop };

class PASCALIMPLEMENTATION TcxTreeListPreview : public Dxcoreclasses::TcxOwnedInterfacedPersistent
{
	typedef Dxcoreclasses::TcxOwnedInterfacedPersistent inherited;
	
private:
	bool FAutoHeight;
	TcxTreeListColumn* FColumn;
	int FLeftIndent;
	int FMaxLineCount;
	TcxTreeListPreviewPlace FPlace;
	int FRightIndent;
	bool FVisible;
	bool __fastcall GetActive(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetAutoHeight(bool AValue);
	void __fastcall SetColumn(TcxTreeListColumn* AValue);
	void __fastcall SetLeftIndent(int AValue);
	void __fastcall SetMaxLineCount(int AValue);
	void __fastcall SetPlace(TcxTreeListPreviewPlace AValue);
	void __fastcall SetRightIndent(int AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	System::TObject* __fastcall GetControl(void);
	
public:
	__fastcall virtual TcxTreeListPreview(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool Active = {read=GetActive, nodefault};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property bool AutoHeight = {read=FAutoHeight, write=SetAutoHeight, default=1};
	__property TcxTreeListColumn* Column = {read=FColumn, write=SetColumn};
	__property int LeftIndent = {read=FLeftIndent, write=SetLeftIndent, default=5};
	__property int MaxLineCount = {read=FMaxLineCount, write=SetMaxLineCount, default=3};
	__property TcxTreeListPreviewPlace Place = {read=FPlace, write=SetPlace, default=0};
	__property int RightIndent = {read=FRightIndent, write=SetRightIndent, default=5};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListPreview(void) { }
	
};


class DELPHICLASS TcxTreeListStyleSheet;
class PASCALIMPLEMENTATION TcxTreeListStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxTreeListStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxTreeListStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxTreeListStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxTreeListStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxTreeListStyleSheet(void) { }
	
};


typedef void __fastcall (__closure *TcxTreeListGetBandContentStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListBand* ABand, TcxTreeListNode* ANode, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxTreeListGetBandStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListBand* ABand, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxTreeListGetColumnFooterStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListColumn* AColumn, TcxTreeListNode* ANode, TcxTreeListSummaryItem* AFooterItem, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxTreeListGetColumnStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListColumn* AColumn, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxTreeListGetContentStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListColumn* AColumn, TcxTreeListNode* ANode, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxTreeListGetNodeIndentStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, int ALevel, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxTreeListGetPreviewStyleEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, Cxstyles::TcxStyle* &AStyle);

class PASCALIMPLEMENTATION TcxTreeListStyles : public Cxinplacecontainer::TcxCustomControlStyles
{
	typedef Cxinplacecontainer::TcxCustomControlStyles inherited;
	
private:
	bool FCanOffsetContent;
	TcxTreeListGetBandStyleEvent FOnGetBandBackgroundStyle;
	TcxTreeListGetBandContentStyleEvent FOnGetBandContentStyle;
	TcxTreeListGetBandStyleEvent FOnGetBandHeaderStyle;
	TcxTreeListGetBandContentStyleEvent FOnGetBandFooterStyle;
	TcxTreeListGetColumnFooterStyleEvent FOnGetColumnFooterStyle;
	TcxTreeListGetColumnStyleEvent FOnGetColumnHeaderStyle;
	TcxTreeListGetContentStyleEvent FOnGetContentStyle;
	TcxTreeListGetContentStyleEvent FOnGetHotTrackStyle;
	TcxTreeListGetNodeIndentStyleEvent FOnGetNodeIndentStyle;
	TcxTreeListGetPreviewStyleEvent FOnGetPreviewStyle;
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLoolAndFeel(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall DoGetBandBackgroundParams(TcxTreeListBand* ABand, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetBandContentParams(TcxTreeListBand* ABand, TcxTreeListNode* ANode, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetBandFooterParams(TcxTreeListBand* ABand, TcxTreeListNode* ANode, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetBandHeaderParams(TcxTreeListBand* ABand, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetColumnFooterParams(TcxTreeListColumn* AColumn, TcxTreeListNode* ANode, TcxTreeListSummaryItem* ASummaryItem, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetColumnHeaderParams(TcxTreeListColumn* AColumn, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetContentParams(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetNodeContentParams(TcxTreeListNode* ANode, Cxstyles::TcxStyle* AStyle, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall DoGetPreviewParams(TcxTreeListNode* ANode, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	bool __fastcall SelectionFontAssigned(void);
	
public:
	__fastcall virtual TcxTreeListStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetBandBackgroundParams(TcxTreeListBand* ABand);
	Cxgraphics::TcxViewParams __fastcall GetBandContentParams(TcxTreeListBand* ABand, TcxTreeListNode* ANode);
	Cxgraphics::TcxViewParams __fastcall GetBandFooterParams(TcxTreeListBand* ABand, TcxTreeListNode* ANode);
	Cxgraphics::TcxViewParams __fastcall GetBandHeaderParams(TcxTreeListBand* ABand);
	Cxgraphics::TcxViewParams __fastcall GetColumnFooterParams(TcxTreeListColumn* AColumn, TcxTreeListNode* ANode, TcxTreeListSummaryItem* ASummaryItem = (TcxTreeListSummaryItem*)(0x0));
	Cxgraphics::TcxViewParams __fastcall GetColumnHeaderParams(TcxTreeListColumn* AColumn);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	Cxgraphics::TcxViewParams __fastcall GetFooterParams(void);
	Cxgraphics::TcxViewParams __fastcall GetIncSearchParams(void);
	Cxgraphics::TcxViewParams __fastcall GetIndentParams(TcxTreeListNode* ANode, int AIndent);
	Cxgraphics::TcxViewParams __fastcall GetIndicatorParams(void);
	Cxgraphics::TcxViewParams __fastcall GetPreviewParams(TcxTreeListNode* ANode);
	__property bool CanOffsetContent = {read=FCanOffsetContent, write=FCanOffsetContent, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLoolAndFeel};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property Cxstyles::TcxStyle* BandBackground = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* BandContent = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* BandHeader = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* ColumnFooter = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* ColumnHeader = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* ContentEven = {read=GetValue, write=SetValue, index=11};
	__property Cxstyles::TcxStyle* ContentOdd = {read=GetValue, write=SetValue, index=12};
	__property Cxstyles::TcxStyle* Footer = {read=GetValue, write=SetValue, index=13};
	__property Cxstyles::TcxStyle* HotTrack = {read=GetValue, write=SetValue, index=17};
	__property Cxstyles::TcxStyle* IncSearch = {read=GetValue, write=SetValue, index=14};
	__property Cxstyles::TcxStyle* Indicator = {read=GetValue, write=SetValue, index=15};
	__property Navigator;
	__property NavigatorInfoPanel;
	__property Cxstyles::TcxStyle* Preview = {read=GetValue, write=SetValue, index=16};
	__property TcxTreeListGetBandStyleEvent OnGetBandBackgroundStyle = {read=FOnGetBandBackgroundStyle, write=FOnGetBandBackgroundStyle};
	__property TcxTreeListGetBandContentStyleEvent OnGetBandContentStyle = {read=FOnGetBandContentStyle, write=FOnGetBandContentStyle};
	__property TcxTreeListGetBandContentStyleEvent OnGetBandFooterStyle = {read=FOnGetBandFooterStyle, write=FOnGetBandFooterStyle};
	__property TcxTreeListGetBandStyleEvent OnGetBandHeaderStyle = {read=FOnGetBandHeaderStyle, write=FOnGetBandHeaderStyle};
	__property TcxTreeListGetColumnFooterStyleEvent OnGetColumnFooterStyle = {read=FOnGetColumnFooterStyle, write=FOnGetColumnFooterStyle};
	__property TcxTreeListGetColumnStyleEvent OnGetColumnHeaderStyle = {read=FOnGetColumnHeaderStyle, write=FOnGetColumnHeaderStyle};
	__property TcxTreeListGetContentStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=FOnGetContentStyle};
	__property TcxTreeListGetContentStyleEvent OnGetHotTrackStyle = {read=FOnGetHotTrackStyle, write=FOnGetHotTrackStyle};
	__property TcxTreeListGetNodeIndentStyleEvent OnGetNodeIndentStyle = {read=FOnGetNodeIndentStyle, write=FOnGetNodeIndentStyle};
	__property TcxTreeListGetPreviewStyleEvent OnGetPreviewStyle = {read=FOnGetPreviewStyle, write=FOnGetPreviewStyle};
	__property Background;
	__property Content;
	__property Inactive;
	__property Selection;
	__property StyleSheet;
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxTreeListStyles(void) { }
	
};


class DELPHICLASS TcxTreeListItemsCustomizeListBox;
class PASCALIMPLEMENTATION TcxTreeListItemsCustomizeListBox : public Cxlistbox::TcxListBox
{
	typedef Cxlistbox::TcxListBox inherited;
	
private:
	Cxclasses::TcxObjectList* FHeaders;
	TcxCustomTreeList* FTreeList;
	TcxTreeListHeaderCellViewInfo* __fastcall GetHeader(int AIndex);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	HIDESBASE void __fastcall AddItem(TcxTreeListCaption* ACaption);
	virtual TcxTreeListHeaderCellViewInfo* __fastcall CreateCell(void) = 0 ;
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DoDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall DoDrawItemEx(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	HIDESBASE virtual int __fastcall GetItemHeight(int AItem);
	System::Types::TPoint __fastcall GetOrigin(TcxTreeListHeaderCellViewInfo* AHeader);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall MakeItemVisible(TcxTreeListHeaderCellViewInfo* AHeader) = 0 ;
	virtual void __fastcall MeasureItem(Cxlistbox::TcxListBox* AControl, int Index, int &Height);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PopulateItems(void) = 0 ;
	void __fastcall RefreshList(void);
	DYNAMIC void __fastcall Resize(void);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint P);
	void __fastcall UpdateBackgroundColor(void);
	void __fastcall UpdateHeaderInfo(int AIndex);
	void __fastcall UpdateHeaders(void);
	__property TcxTreeListHeaderCellViewInfo* Headers[int Index] = {read=GetHeader};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	
public:
	__fastcall TcxTreeListItemsCustomizeListBox(System::Classes::TComponent* AOwner, TcxCustomTreeList* ATreeList, Vcl::Controls::TWinControl* AParent);
	__fastcall virtual ~TcxTreeListItemsCustomizeListBox(void);
	__property TcxCustomTreeList* TreeList = {read=FTreeList};
public:
	/* TcxListBox.Create */ inline __fastcall virtual TcxTreeListItemsCustomizeListBox(System::Classes::TComponent* AOwner) : Cxlistbox::TcxListBox(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListItemsCustomizeListBox(HWND ParentWindow) : Cxlistbox::TcxListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListColumnsCustomizeListBox;
class PASCALIMPLEMENTATION TcxTreeListColumnsCustomizeListBox : public TcxTreeListItemsCustomizeListBox
{
	typedef TcxTreeListItemsCustomizeListBox inherited;
	
protected:
	virtual TcxTreeListHeaderCellViewInfo* __fastcall CreateCell(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual void __fastcall MakeItemVisible(TcxTreeListHeaderCellViewInfo* AHeader);
	virtual void __fastcall PopulateItems(void);
public:
	/* TcxTreeListItemsCustomizeListBox.CreateEx */ inline __fastcall TcxTreeListColumnsCustomizeListBox(System::Classes::TComponent* AOwner, TcxCustomTreeList* ATreeList, Vcl::Controls::TWinControl* AParent) : TcxTreeListItemsCustomizeListBox(AOwner, ATreeList, AParent) { }
	/* TcxTreeListItemsCustomizeListBox.Destroy */ inline __fastcall virtual ~TcxTreeListColumnsCustomizeListBox(void) { }
	
public:
	/* TcxListBox.Create */ inline __fastcall virtual TcxTreeListColumnsCustomizeListBox(System::Classes::TComponent* AOwner) : TcxTreeListItemsCustomizeListBox(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListColumnsCustomizeListBox(HWND ParentWindow) : TcxTreeListItemsCustomizeListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListBandsCustomizeListBox;
class PASCALIMPLEMENTATION TcxTreeListBandsCustomizeListBox : public TcxTreeListItemsCustomizeListBox
{
	typedef TcxTreeListItemsCustomizeListBox inherited;
	
protected:
	virtual TcxTreeListHeaderCellViewInfo* __fastcall CreateCell(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual void __fastcall MakeItemVisible(TcxTreeListHeaderCellViewInfo* AHeader);
	virtual void __fastcall PopulateItems(void);
public:
	/* TcxTreeListItemsCustomizeListBox.CreateEx */ inline __fastcall TcxTreeListBandsCustomizeListBox(System::Classes::TComponent* AOwner, TcxCustomTreeList* ATreeList, Vcl::Controls::TWinControl* AParent) : TcxTreeListItemsCustomizeListBox(AOwner, ATreeList, AParent) { }
	/* TcxTreeListItemsCustomizeListBox.Destroy */ inline __fastcall virtual ~TcxTreeListBandsCustomizeListBox(void) { }
	
public:
	/* TcxListBox.Create */ inline __fastcall virtual TcxTreeListBandsCustomizeListBox(System::Classes::TComponent* AOwner) : TcxTreeListItemsCustomizeListBox(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListBandsCustomizeListBox(HWND ParentWindow) : TcxTreeListItemsCustomizeListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeListCustomizationForm;
class DELPHICLASS TcxTreeListCustomizing;
class PASCALIMPLEMENTATION TcxTreeListCustomizationForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TcxTreeListItemsCustomizeListBox* FDragDropListBox;
	Cxclasses::TcxTimer* FHookTimer;
	TcxTreeListCustomizing* FOwner;
	TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	void __fastcall FinishDragDrop(TcxTreeListItemsCustomizeListBox* Sender);
	void __fastcall StartDragDrop(TcxTreeListItemsCustomizeListBox* Sender);
	void __fastcall TimerHandler(System::TObject* Sender);
	
public:
	__fastcall TcxTreeListCustomizationForm(TcxTreeListCustomizing* AOwner);
	__fastcall virtual ~TcxTreeListCustomizationForm(void);
	__property Cxclasses::TcxTimer* HookTimer = {read=FHookTimer};
	__property TcxTreeListCustomizing* Customizing = {read=FOwner};
	__property TcxTreeListItemsCustomizeListBox* DragDropListBox = {read=FDragDropListBox};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxTreeListCustomizationForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListCustomizationForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxTreeListCustomizing : public Dxcoreclasses::TcxOwnedInterfacedPersistent
{
	typedef Dxcoreclasses::TcxOwnedInterfacedPersistent inherited;
	
private:
	TcxTreeListItemsCustomizeListBox* FBandListBox;
	System::Types::TRect FBounds;
	TcxTreeListCustomizationForm* FForm;
	TcxTreeListItemsCustomizeListBox* FHeaderListBox;
	bool FIsPositionAssigned;
	Cxpc::TcxPageControl* FPageControl;
	int FRowCount;
	Cxpc::TcxTabSheet* FTabSheetBands;
	Cxpc::TcxTabSheet* FTabSheetHeaders;
	Vcl::Forms::TForm* __fastcall GetForm(void);
	bool __fastcall GetIsSimpleMode(void);
	System::Types::TPoint __fastcall GetPosition(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetPosition(const System::Types::TPoint AValue);
	void __fastcall SetRowCount(int AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	void __fastcall CalculateSize(int &AWidth, int &AHeight);
	virtual void __fastcall Close(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall CreateCustomizingForm(void);
	virtual void __fastcall FinishCustomizing(const System::Types::TRect &ABounds);
	void __fastcall HideCustomizingForm(void);
	void __fastcall RefreshInformation(void);
	void __fastcall SetControlParent(Vcl::Controls::TWinControl* AControl, Vcl::Controls::TWinControl* AParent);
	void __fastcall ShowCustomizingForm(void);
	virtual void __fastcall Update(void);
	virtual void __fastcall ComponentModified(void);
	virtual void __fastcall ComponentRemoved(System::TObject* Sender);
	__property TcxTreeListItemsCustomizeListBox* BandListBox = {read=FBandListBox};
	__property TcxTreeListItemsCustomizeListBox* HeaderListBox = {read=FHeaderListBox};
	__property bool SimpleMode = {read=GetIsSimpleMode, nodefault};
	
public:
	__fastcall virtual TcxTreeListCustomizing(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxTreeListCustomizing(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall MakeBandPageVisible(void);
	void __fastcall MakeColumnPageVisible(void);
	bool __fastcall PtInCustomizingBox(const System::Types::TPoint APoint);
	__property Vcl::Forms::TForm* Form = {read=GetForm};
	__property bool IsPositionAssigned = {read=FIsPositionAssigned, write=FIsPositionAssigned, nodefault};
	__property System::Types::TPoint Position = {read=GetPosition, write=SetPosition};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=10};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
private:
	void *__IcxTreeListDesigner;	/* IcxTreeListDesigner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1F4D4387-57E1-4756-9093-1124077A0F54}
	operator _di_IcxTreeListDesigner()
	{
		_di_IcxTreeListDesigner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxTreeListDesigner*(void) { return (IcxTreeListDesigner*)&__IcxTreeListDesigner; }
	#endif
	
};


typedef System::TMetaClass* TcxTreeListCustomizingClass;

typedef void __fastcall (__closure *TcxTreeListForEachNodeProc)(TcxTreeListNode* ANode, void * Data);

class PASCALIMPLEMENTATION TcxTreeListDataController : public Cxinplacecontainer::TcxControlDataController
{
	typedef Cxinplacecontainer::TcxControlDataController inherited;
	
private:
	int FAllocatedRecords;
	TcxTreeListNode* FBookmarkNode;
	bool FDataChangedBusy;
	TcxTreeListNode* FEditingNode;
	bool FIsValueChanged;
	int FNodesCount;
	bool __fastcall GetHasEditData(void);
	TcxTreeListNode* __fastcall GetRoot(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	Cxdatastorage::TcxValueDef* __fastcall GetValueDef(int AIndex);
	void __fastcall FreeRecordProc(TcxTreeListNode* ANode, void * AData);
	void __fastcall InsertValueDef(TcxTreeListColumn* AColumn);
	void __fastcall InsertValueDefProc(TcxTreeListNode* ANode, void * AData);
	void __fastcall SetEditingNode(TcxTreeListNode* AValue);
	void __fastcall SetIsValueChanged(bool AValue);
	void __fastcall RemoveValueDef(TcxTreeListColumn* AColumn);
	void __fastcall RemoveValueDefProc(TcxTreeListNode* ANode, void * AData);
	
protected:
	void __fastcall CancelEditing(void);
	int __fastcall Compare(Cxdatastorage::TcxValueDef* AValueDef, void * AHandle1, void * AHandle2);
	void * __fastcall CopyData(TcxTreeListNode* ASource);
	virtual void __fastcall DeleteNode(TcxTreeListNode* ANode);
	void __fastcall DestroyHandles(void);
	void __fastcall ForEachNode(TcxTreeListForEachNodeProc AProc, void * AData);
	void __fastcall ForEachRecord(TcxTreeListForEachNodeProc AProc, void * AData);
	virtual Cxcustomdata::TcxDataControllerEditState __fastcall GetEditState(void);
	virtual bool __fastcall InternalCheckBookmark(int ADeletedRecordIndex);
	virtual void __fastcall InternalClearBookmark(void);
	virtual void __fastcall InternalGotoBookmark(void);
	virtual bool __fastcall InternalSaveBookmark(void);
	virtual bool __fastcall IsDataMode(void);
	virtual bool __fastcall IsLoading(void);
	virtual void __fastcall PostRecord(void);
	virtual void __fastcall PostValues(void);
	void __fastcall SetNodeData(void * ASource, TcxTreeListNode* ADest);
	virtual int __fastcall StringCompare(const System::Variant &V1, const System::Variant &V2);
	virtual void __fastcall SyncFocused(TcxTreeListNode* ANode);
	__property bool DataChangedBusy = {read=FDataChangedBusy, write=FDataChangedBusy, nodefault};
	__property TcxTreeListNode* EditingNode = {read=FEditingNode, write=SetEditingNode};
	__property bool IsValueChanged = {read=FIsValueChanged, write=SetIsValueChanged, nodefault};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	__property Cxdatastorage::TcxValueDef* ValueDefs[int AIndex] = {read=GetValueDef};
	
public:
	__fastcall virtual TcxTreeListDataController(System::Classes::TComponent* AOwner);
	virtual Cxcustomdata::TcxCustomDataField* __fastcall AddItem(System::TObject* AItem);
	void * __fastcall AllocateRecord(void);
	virtual void __fastcall ChangeValueTypeClass(int AItemIndex, Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	virtual int __fastcall CompareNodesByColumns(TcxTreeListNode* ANode1, TcxTreeListNode* ANode2, System::Classes::TList* AColumns);
	void __fastcall FreeNodeRecord(TcxTreeListNode* ANode);
	void __fastcall FreeRecord(void * &ARecord);
	virtual System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, int AItemIndex);
	virtual System::Variant __fastcall GetNodeDisplayText(TcxTreeListNode* ANode, int AIndex);
	virtual System::Variant __fastcall GetNodeValue(TcxTreeListNode* ANode, int AIndex);
	virtual System::Variant __fastcall GetValue(int ARecordIndex, int AItemIndex);
	System::Variant __fastcall GetValueForCompare(TcxTreeListNode* ANode, Cxcustomdata::TcxCustomDataField* AField);
	void __fastcall InitializeNodeFromRecordIndex(TcxTreeListNode* ANode);
	void __fastcall InitializeRecordIndexFromNode(TcxTreeListNode* ANode);
	virtual bool __fastcall IsBookmarkAvailable(void);
	virtual void __fastcall Cancel(void);
	virtual void __fastcall Edit(void);
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData(void);
	virtual void __fastcall RemoveItem(System::TObject* AItem);
	virtual bool __fastcall SetEditValue(int AItemIndex, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall SetNodeValue(TcxTreeListNode* ANode, int AIndex, const System::Variant &AValue);
	virtual void __fastcall SetValue(int ARecordIndex, int AItemIndex, const System::Variant &Value);
	virtual void __fastcall UpdateItemIndexes(void);
	__property int AllocatedRecords = {read=FAllocatedRecords, nodefault};
	__property bool HasEditData = {read=GetHasEditData, nodefault};
	__property int NodesCount = {read=FNodesCount, nodefault};
	__property TcxTreeListNode* Root = {read=GetRoot};
public:
	/* TcxDataController.Destroy */ inline __fastcall virtual ~TcxTreeListDataController(void) { }
	
};


class DELPHICLASS TcxTreeListCustomPopupMenu;
class PASCALIMPLEMENTATION TcxTreeListCustomPopupMenu : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TComponent* FPopupMenu;
	
protected:
	virtual System::Classes::TComponent* __fastcall GetPopupMenu(void);
	virtual System::Classes::TComponent* __fastcall GetRoot(void) = 0 ;
	virtual TcxCustomTreeList* __fastcall GetTreeList(void) = 0 ;
	virtual bool __fastcall Popup(int X, int Y);
	virtual void __fastcall SetPopupMenu(System::Classes::TComponent* AValue);
	__property System::Classes::TComponent* PopupMenu = {read=GetPopupMenu, write=SetPopupMenu};
	
public:
	__property System::Classes::TComponent* Root = {read=GetRoot};
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxTreeListCustomPopupMenu(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListCustomPopupMenu(void) { }
	
};


enum TcxTreeListBuiltInMenuItemType : unsigned char { tlmitDefault, tlmitChecked, tlmitSubItem };

class DELPHICLASS TcxTreeListCustomBuiltInMenu;
class PASCALIMPLEMENTATION TcxTreeListCustomBuiltInMenu : public TcxTreeListCustomPopupMenu
{
	typedef TcxTreeListCustomPopupMenu inherited;
	
protected:
	virtual System::Classes::TComponent* __fastcall CreateMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true, TcxTreeListBuiltInMenuItemType AItemType = (TcxTreeListBuiltInMenuItemType)(0x0), bool AChecked = false, int AImageIndex = 0xffffffff, bool AWithSeparator = false, bool AInternal = true) = 0 ;
	virtual void __fastcall CreatePopupMenu(void);
	virtual void __fastcall DestroyPopupMenu(void);
	void __fastcall GetBitmapFromImageList(Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, Vcl::Graphics::TBitmap* ABitmap);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(bool AInternal);
	virtual System::Classes::TComponentClass __fastcall GetPopupClass(void) = 0 ;
	virtual System::Classes::TComponent* __fastcall GetRoot(void);
	virtual TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall Initialize(void);
	virtual void __fastcall MenuItemClickHandler(System::TObject* Sender);
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxTreeListCustomBuiltInMenu(System::Classes::TPersistent* AOwner) : TcxTreeListCustomPopupMenu(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListCustomBuiltInMenu(void) { }
	
};


typedef System::TMetaClass* TcxTreeListCustomBuiltInMenuClass;

class DELPHICLASS TcxTreeListBuiltInMenu;
class PASCALIMPLEMENTATION TcxTreeListBuiltInMenu : public TcxTreeListCustomBuiltInMenu
{
	typedef TcxTreeListCustomBuiltInMenu inherited;
	
private:
	Vcl::Menus::TPopupMenu* __fastcall GetInternalPopupMenu(void);
	
protected:
	virtual System::Classes::TComponent* __fastcall CreateMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true, TcxTreeListBuiltInMenuItemType AItemType = (TcxTreeListBuiltInMenuItemType)(0x0), bool AChecked = false, int AImageIndex = 0xffffffff, bool AWithSeparator = false, bool AInternal = true);
	virtual System::Classes::TComponentClass __fastcall GetPopupClass(void);
	virtual System::Classes::TComponent* __fastcall GetRoot(void);
	virtual void __fastcall CreatePopupMenu(void);
	
public:
	__fastcall virtual ~TcxTreeListBuiltInMenu(void);
	__property Vcl::Menus::TPopupMenu* PopupMenu = {read=GetInternalPopupMenu};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxTreeListBuiltInMenu(System::Classes::TPersistent* AOwner) : TcxTreeListCustomBuiltInMenu(AOwner) { }
	
};


typedef void __fastcall (__closure *TcxTreeListPopupMenuClickEvent)(TcxCustomTreeList* Sender, System::TObject* AItem, bool &AHandled);

class DELPHICLASS TcxTreeListPopupMenu;
typedef void __fastcall (__closure *TcxTreeListPopupMenuPopupEvent)(TcxCustomTreeList* Sender, TcxTreeListPopupMenu* AContextMenu, bool &AHandled);

class PASCALIMPLEMENTATION TcxTreeListPopupMenu : public TcxTreeListCustomPopupMenu
{
	typedef TcxTreeListCustomPopupMenu inherited;
	
private:
	TcxTreeListCustomBuiltInMenu* FBuiltInMenu;
	bool FUseBuiltInMenu;
	Vcl::Imglist::TCustomImageList* FUserImages;
	TcxTreeListPopupMenuClickEvent FOnClick;
	TcxTreeListPopupMenuPopupEvent FOnPopup;
	TcxTreeListCustomBuiltInMenu* __fastcall GetBuiltInMenu(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	void __fastcall SetUseBuiltInMenu(bool AValue);
	void __fastcall SetUserImages(Vcl::Imglist::TCustomImageList* AValue);
	
protected:
	System::Classes::TComponent* __fastcall CreateInternalMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true, TcxTreeListBuiltInMenuItemType AItemType = (TcxTreeListBuiltInMenuItemType)(0x0), bool AChecked = false, int AImageIndex = 0xffffffff, bool AWithSeparator = false);
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	void __fastcall DoMenuItemClick(System::TObject* Sender);
	virtual void __fastcall DoClick(System::TObject* AItem, bool &AHandled);
	virtual bool __fastcall DoPopup(void);
	virtual bool __fastcall DoShowPopupMenu(const System::Types::TPoint P);
	virtual System::UnicodeString __fastcall GetResourceImagesName(void);
	virtual System::Classes::TComponent* __fastcall GetRoot(void);
	virtual TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall InitializeInternalMenu(void);
	virtual bool __fastcall IsPopupSuitable(TcxTreeListHitTest* AHitTest);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall Popup(int X, int Y);
	virtual void __fastcall SetPopupMenu(System::Classes::TComponent* AValue);
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	
public:
	__fastcall virtual TcxTreeListPopupMenu(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxTreeListPopupMenu(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Classes::TComponent* __fastcall CreateMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true, TcxTreeListBuiltInMenuItemType AItemType = (TcxTreeListBuiltInMenuItemType)(0x0), bool AChecked = false, int AImageIndex = 0xffffffff, bool AWithSeparator = false);
	__property TcxTreeListCustomBuiltInMenu* BuiltInMenu = {read=GetBuiltInMenu};
	__property Vcl::Imglist::TCustomImageList* UserImages = {read=FUserImages, write=SetUserImages};
	
__published:
	__property PopupMenu;
	__property bool UseBuiltInMenu = {read=FUseBuiltInMenu, write=SetUseBuiltInMenu, default=0};
	__property TcxTreeListPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxTreeListPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
};


typedef System::TMetaClass* TcxTreeListPopupMenuClass;

enum TcxTreeListFooterPopupMenuItem : unsigned char { tlfmiSum, tlfmiMin, tlfmiMax, tlfmiAverage, tlfmiCount, tlfmiNone, tlfmiAllNodes };

typedef System::Set<TcxTreeListFooterPopupMenuItem, TcxTreeListFooterPopupMenuItem::tlfmiSum, TcxTreeListFooterPopupMenuItem::tlfmiAllNodes>  TcxTreeListFooterPopupMenuItems;

class DELPHICLASS TcxTreeListFooterPopupMenu;
class PASCALIMPLEMENTATION TcxTreeListFooterPopupMenu : public TcxTreeListPopupMenu
{
	typedef TcxTreeListPopupMenu inherited;
	
private:
	TcxTreeListFooterPopupMenuItems FItems;
	TcxTreeListSummaryItems* FSummaryItems;
	Cxcustomdata::TcxSummaryKinds __fastcall GetVisibleItemKinds(void);
	bool __fastcall IsAllNodes(void);
	bool __fastcall IsItemEnabled(Cxcustomdata::TcxSummaryKind AKind);
	bool __fastcall IsItemsStored(void);
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	virtual System::UnicodeString __fastcall GetResourceImagesName(void);
	virtual bool __fastcall IsPopupSuitable(TcxTreeListHitTest* AHitTest);
	__property TcxTreeListSummaryItems* SummaryItems = {read=FSummaryItems};
	
public:
	__fastcall virtual TcxTreeListFooterPopupMenu(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxTreeListFooterPopupMenuItems Items = {read=FItems, write=FItems, stored=IsItemsStored, nodefault};
public:
	/* TcxTreeListPopupMenu.Destroy */ inline __fastcall virtual ~TcxTreeListFooterPopupMenu(void) { }
	
};


class DELPHICLASS TcxTreeListGroupFooterPopupMenu;
class PASCALIMPLEMENTATION TcxTreeListGroupFooterPopupMenu : public TcxTreeListFooterPopupMenu
{
	typedef TcxTreeListFooterPopupMenu inherited;
	
protected:
	virtual bool __fastcall IsPopupSuitable(TcxTreeListHitTest* AHitTest);
public:
	/* TcxTreeListFooterPopupMenu.Create */ inline __fastcall virtual TcxTreeListGroupFooterPopupMenu(System::Classes::TPersistent* AOwner) : TcxTreeListFooterPopupMenu(AOwner) { }
	
public:
	/* TcxTreeListPopupMenu.Destroy */ inline __fastcall virtual ~TcxTreeListGroupFooterPopupMenu(void) { }
	
};


enum TcxTreeListColumnHeaderPopupMenuItem : unsigned char { tlchmiSortAscending, tlchmiSortDescending, tlchmiClearSorting, tlchmiFooter, tlchmiGroupFooters, tlchmiRemoveThisColumn, tlchmiFieldChooser, tlchmiHorzAlignment, tlchmiVertAlignment, tlchmiBestFit, tlchmiBestFitAllColumns };

typedef System::Set<TcxTreeListColumnHeaderPopupMenuItem, TcxTreeListColumnHeaderPopupMenuItem::tlchmiSortAscending, TcxTreeListColumnHeaderPopupMenuItem::tlchmiBestFitAllColumns>  TcxTreeListColumnHeaderPopupMenuItems;

class DELPHICLASS TcxTreeListColumnHeaderPopupMenu;
class PASCALIMPLEMENTATION TcxTreeListColumnHeaderPopupMenu : public TcxTreeListPopupMenu
{
	typedef TcxTreeListPopupMenu inherited;
	
private:
	TcxTreeListColumn* FColumn;
	TcxTreeListColumnHeaderPopupMenuItems FItems;
	bool FSeparatorNeeded;
	void __fastcall CreateAlignmentSubMenus(void);
	bool __fastcall IsItemsStored(void);
	bool __fastcall IsSeparatorNeeded(void);
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	virtual System::UnicodeString __fastcall GetResourceImagesName(void);
	virtual bool __fastcall IsPopupSuitable(TcxTreeListHitTest* AHitTest);
	__property TcxTreeListColumn* Column = {read=FColumn, write=FColumn};
	
public:
	__fastcall virtual TcxTreeListColumnHeaderPopupMenu(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxTreeListColumnHeaderPopupMenuItems Items = {read=FItems, write=FItems, stored=IsItemsStored, nodefault};
public:
	/* TcxTreeListPopupMenu.Destroy */ inline __fastcall virtual ~TcxTreeListColumnHeaderPopupMenu(void) { }
	
};


class DELPHICLASS TcxTreeListPopupMenus;
class PASCALIMPLEMENTATION TcxTreeListPopupMenus : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Contnrs::TObjectList* FMenus;
	TcxTreeListColumnHeaderPopupMenu* FColumnHeaderMenu;
	TcxTreeListFooterPopupMenu* FFooterMenu;
	TcxTreeListGroupFooterPopupMenu* FGroupFooterMenu;
	TcxTreeListHitTest* __fastcall GetHitTest(void);
	TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetColumnHeaderMenu(TcxTreeListColumnHeaderPopupMenu* AValue);
	void __fastcall SetFooterMenu(TcxTreeListFooterPopupMenu* AValue);
	void __fastcall SetGroupFooterMenu(TcxTreeListGroupFooterPopupMenu* AValue);
	
protected:
	void __fastcall CreateMenus(void);
	bool __fastcall DoShowPopupMenu(const System::Types::TPoint P);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property TcxTreeListHitTest* HitTest = {read=GetHitTest};
	
public:
	__fastcall virtual TcxTreeListPopupMenus(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxTreeListPopupMenus(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomTreeList* TreeList = {read=GetTreeList};
	
__published:
	__property TcxTreeListColumnHeaderPopupMenu* ColumnHeaderMenu = {read=FColumnHeaderMenu, write=SetColumnHeaderMenu};
	__property TcxTreeListFooterPopupMenu* FooterMenu = {read=FFooterMenu, write=SetFooterMenu};
	__property TcxTreeListGroupFooterPopupMenu* GroupFooterMenu = {read=FGroupFooterMenu, write=SetGroupFooterMenu};
};


class PASCALIMPLEMENTATION TcxTreeListSummary : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FAbsoluteFooterSummaryItems;
	System::Classes::TList* FAbsoluteGroupFooterSummaryItems;
	int FFooterSummaryRowCount;
	int FFooterSummaryVisibleCount;
	int FGroupFooterSummaryRowCount;
	int FGroupFooterSummaryVisibleCount;
	bool FIsDirty;
	TcxCustomTreeList* FTreeList;
	int __fastcall GetFooterSummaryCount(void);
	TcxTreeListSummaryItem* __fastcall GetFooterSummaryItem(int AIndex);
	System::UnicodeString __fastcall GetFooterSummaryText(TcxTreeListSummaryItem* ASummaryItem);
	System::Variant __fastcall GetFooterSummaryValue(TcxTreeListSummaryItem* ASummaryItem);
	int __fastcall GetGroupFooterSummaryCount(void);
	TcxTreeListSummaryItem* __fastcall GetGroupFooterSummaryItem(int AIndex);
	System::UnicodeString __fastcall GetGroupFooterSummaryText(TcxTreeListSummaryItem* ASummaryItem, TcxTreeListNode* ANode);
	System::Variant __fastcall GetGroupFooterSummaryValue(TcxTreeListSummaryItem* ASummaryItem, TcxTreeListNode* ANode);
	TcxTreeListNode* __fastcall GetRoot(void);
	void __fastcall SetFooterSummaryValue(TcxTreeListSummaryItem* ASummaryItem, const System::Variant &Value);
	void __fastcall SetGroupFooterSummaryValue(TcxTreeListSummaryItem* ASummaryItem, TcxTreeListNode* ANode, const System::Variant &Value);
	
protected:
	void __fastcall AddSummaryItems(System::Classes::TList* AAbsoluteSummaryItems, TcxTreeListSummaryItems* ASummaryItems, bool AIsVisible, int &AVisibleCount, int &AVisibleRowCount);
	void __fastcall Calculate(void);
	void __fastcall CalculateNode(TcxTreeListNode* ADestNode, TcxTreeListNode* AValueNode, System::Classes::TList* AItems);
	virtual void __fastcall CheckChanges(void);
	bool __fastcall DoProcessSummaryValue(TcxTreeListNode* ANode, TcxTreeListSummaryItem* ASummaryItem, System::Variant &ASummaryValue, int &ASummaryCount, System::Variant &AValue, int &ACount);
	void __fastcall FinalizeValues(TcxTreeListNode* ANode, System::Classes::TList* AItems);
	void __fastcall InitializeValues(TcxTreeListNode* ANode, System::Classes::TList* AItems);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ProcessNode(TcxTreeListNode* AParent);
	void __fastcall ProcessSummaryValue(TcxTreeListNode* ANode, TcxTreeListSummaryItem* ASummaryItem, System::Variant &ASummaryValue, int &ASummaryCount);
	void __fastcall ProcessSummaryValues(TcxTreeListNode* ADestNode, TcxTreeListNode* AValueNode, System::Classes::TList* AItems);
	__property bool IsDirty = {read=FIsDirty, write=FIsDirty, nodefault};
	__property TcxTreeListNode* Root = {read=GetRoot};
	
public:
	__fastcall virtual TcxTreeListSummary(TcxCustomTreeList* ATreeList);
	__fastcall virtual ~TcxTreeListSummary(void);
	void __fastcall Recalculate(void);
	__property int FooterSummaryCount = {read=GetFooterSummaryCount, nodefault};
	__property int FooterSummaryRowCount = {read=FFooterSummaryRowCount, nodefault};
	__property int FooterSummaryVisibleCount = {read=FFooterSummaryVisibleCount, nodefault};
	__property TcxTreeListSummaryItem* FooterSummaryItems[int Index] = {read=GetFooterSummaryItem};
	__property System::UnicodeString FooterSummaryTexts[TcxTreeListSummaryItem* ASummaryItem] = {read=GetFooterSummaryText};
	__property System::Variant FooterSummaryValues[TcxTreeListSummaryItem* ASummaryItem] = {read=GetFooterSummaryValue, write=SetFooterSummaryValue};
	__property int GroupFooterSummaryCount = {read=GetGroupFooterSummaryCount, nodefault};
	__property int GroupFooterSummaryRowCount = {read=FGroupFooterSummaryRowCount, nodefault};
	__property int GroupFooterSummaryVisibleCount = {read=FGroupFooterSummaryVisibleCount, nodefault};
	__property TcxTreeListSummaryItem* GroupFooterSummaryItems[int Index] = {read=GetGroupFooterSummaryItem};
	__property System::UnicodeString GroupFooterSummaryTexts[TcxTreeListSummaryItem* ASummaryItem][TcxTreeListNode* ANode] = {read=GetGroupFooterSummaryText};
	__property System::Variant GroupFooterSummaryValues[TcxTreeListSummaryItem* ASummaryItem][TcxTreeListNode* ANode] = {read=GetGroupFooterSummaryValue, write=SetGroupFooterSummaryValue};
	__property TcxCustomTreeList* TreeList = {read=FTreeList};
};


typedef System::TMetaClass* TcxTreeListSummaryClass;

class PASCALIMPLEMENTATION TcxTreeListLevelInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	int FOffset;
	System::Types::TSize FSize;
	Vcl::Imglist::TCustomImageList* FStateImages;
	Vcl::Imglist::TChangeLink* FStateImagesChangeLink;
	TcxCustomTreeList* FTreeList;
	int FWidth;
	int __fastcall GetTotalWidth(void);
	bool __fastcall GetDynamicIndent(void);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetStateImages(Vcl::Imglist::TCustomImageList* AValue);
	
protected:
	void __fastcall Changed(System::TObject* Sender);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	int __fastcall Update(const int AOffset);
	
public:
	__fastcall TcxTreeListLevelInfo(TcxCustomTreeList* ATreeList);
	__fastcall virtual ~TcxTreeListLevelInfo(void);
	__property bool DynamicIndent = {read=GetDynamicIndent, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property int Offset = {read=FOffset, write=FOffset, nodefault};
	__property System::Types::TSize Size = {read=FSize};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=FStateImages, write=SetStateImages};
	__property int TotalWidth = {read=GetTotalWidth, nodefault};
	__property TcxCustomTreeList* TreeList = {read=FTreeList};
	__property int Width = {read=FWidth, nodefault};
};


class DELPHICLASS TcxTreeListLikeParams;
class PASCALIMPLEMENTATION TcxTreeListLikeParams : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::WideChar FPercent;
	System::WideChar FUnderline;
	
public:
	__fastcall TcxTreeListLikeParams(System::WideChar APercent, System::WideChar AUnderline);
	__property System::WideChar Percent = {read=FPercent, write=FPercent, nodefault};
	__property System::WideChar UnderLine = {read=FUnderline, write=FUnderline, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTreeListLikeParams(void) { }
	
};


typedef void __fastcall (__closure *TcxTreeListNodeChangedEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode);

typedef void __fastcall (__closure *TcxTreeListNodeCheckChangedEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, Cxlookandfeelpainters::TcxCheckBoxState AState);

typedef void __fastcall (__closure *TcxTreeListNodeChangingEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, bool &Allow);

typedef void __fastcall (__closure *TcxTreeListColumnChangedEvent)(TcxCustomTreeList* Sender, TcxTreeListColumn* AColumn);

typedef void __fastcall (__closure *TcxTreeListBandChangedEvent)(TcxCustomTreeList* Sender, TcxTreeListBand* ABand);

typedef void __fastcall (__closure *TcxTreeListMoveToEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* AttachNode, TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* Nodes, bool &IsCopy, bool &Done);

typedef void __fastcall (__closure *TcxTreeListNodeCompareEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode1, TcxTreeListNode* ANode2, int &ACompare);

typedef void __fastcall (__closure *TcxTreeListFocusedNodeChangedEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* APrevFocusedNode, TcxTreeListNode* AFocusedNode);

typedef void __fastcall (__closure *TcxTreeListGetCellHintEvent)(TcxCustomTreeList* Sender, System::TObject* ACell, System::UnicodeString &AText, bool &ANeedShow);

typedef void __fastcall (__closure *TcxTreeListGetDragDropTextEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxTreeListGetLevelImagesEvent)(TcxCustomTreeList* Sender, int ALevel, Vcl::Imglist::TCustomImageList* &AImages, Vcl::Imglist::TCustomImageList* &AStateImages);

typedef void __fastcall (__closure *TcxTreeListGetNodeImageIndexEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, TcxTreeListImageIndexType AIndexType, System::Uitypes::TImageIndex &AIndex);

typedef void __fastcall (__closure *TcxTreeListGetNodeHeightEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, int &AHeight);

typedef void __fastcall (__closure *TcxTreeListGetPreviewTextEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxTreeListGetNodePreviewHeightEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, const System::Variant &ADisplayValue, int &AHeight);

typedef void __fastcall (__closure *TcxTreeListIsGroupNodeEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, bool &IsGroup);

typedef void __fastcall (__closure *TcxTreeListEditingEvent)(TcxCustomTreeList* Sender, TcxTreeListColumn* AColumn, bool &Allow);

typedef void __fastcall (__closure *TcxTreeListFocusedColumnChanged)(TcxCustomTreeList* Sender, TcxTreeListColumn* APrevFocusedColumn, TcxTreeListColumn* AFocusedColumn);

typedef void __fastcall (__closure *TcxTreeListHotTrackNodeEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, System::Classes::TShiftState AShift, System::Uitypes::TCursor &ACursor);

typedef void __fastcall (__closure *TcxTreeListNodeDataChangedEvent)(TcxCustomTreeList* Sender, TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);

typedef void __fastcall (__closure *TcxTreeListCustomDrawBandCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListBandCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListCustomDrawBackgroundCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListCustomCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListCustomDrawHeaderCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListHeaderCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListCustomDrawEditCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListEditCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListCustomDrawIndentCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListIndentCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListCustomDrawIndicatorCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListIndicatorCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxTreeListCustomDrawFooterCellEvent)(TcxCustomTreeList* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxTreeListFooterCellViewInfo* AViewInfo, bool &ADone);

enum TcxTreeListFindMode : unsigned char { tlfmNormal, tlfmLike, tlfmExact };

struct DECLSPEC_DRECORD TcxTreeListSummaryEventArguments
{
public:
	TcxTreeListNode* Node;
	TcxTreeListSummaryItem* SummaryItem;
};


struct DECLSPEC_DRECORD TcxTreeListSummaryEventOutArguments
{
public:
	System::Variant Value;
	System::Variant SummaryValue;
	int CountValue;
	bool Done;
};


typedef void __fastcall (__closure *TcxTreeListSummaryEvent)(TcxCustomTreeList* ASender, const TcxTreeListSummaryEventArguments &Arguments, TcxTreeListSummaryEventOutArguments &OutArguments);

class PASCALIMPLEMENTATION TcxCustomTreeList : public Cxinplacecontainer::TcxExtEditingControl
{
	typedef Cxinplacecontainer::TcxExtEditingControl inherited;
	
private:
	System::Classes::TList* FAbsoluteItems;
	System::Classes::TList* FAbsoluteVisibleItems;
	TcxTreeListBands* FBands;
	TcxTreeListLevelInfo* FDefaultLevelInfo;
	TcxTreeListChanges FChanges;
	bool FChangesLocked;
	TcxTreeListCustomizing* FCustomizing;
	System::Types::TSize FDefaultIndentSize;
	bool FDefaultLayout;
	int FDefaultRowHeight;
	Vcl::Extctrls::TTimer* FDelayTimer;
	System::Classes::TList* FDesigners;
	TcxTreeListNode* FDragNode;
	int FExpansionLevel;
	bool FIgnoreLoadingStatus;
	bool FIsCancelOperation;
	bool FIsRefreshFields;
	bool FIsRestoring;
	Cxclasses::TcxObjectList* FLevelsInfo;
	bool FLockChanges;
	Cxnavigator::TcxNavigatorControlNotifier* FNavigatorNotifier;
	int FNextStoreID;
	TcxTreeListOptionsCustomizing* FOptionsCustomizing;
	TcxTreeListOptionsSelection* FOptionsSelection;
	TcxTreeListPopupMenus* FPopupMenus;
	System::Classes::TNotifyEvent FPopupMenusEvents;
	bool FPostChanged;
	TcxTreeListPreview* FPreview;
	TcxTreeListNode* FRoot;
	System::UnicodeString FOriginalHint;
	System::Classes::TList* FSortedColumns;
	System::Classes::TList* FSelectionList;
	System::Uitypes::TCursor FStoredCursor;
	System::UnicodeString FStoringName;
	System::Classes::TNotifyEvent FStylesEvents;
	TcxTreeListSummary* FSummary;
	TcxTreeListNode* FTopVisibleNode;
	System::Classes::TList* FVisibleColumns;
	TcxTreeListBandChangedEvent FOnBandHeaderClick;
	TcxTreeListBandChangedEvent FOnBandPosChanged;
	TcxTreeListBandChangedEvent FOnBandSizeChanged;
	TcxTreeListNodeChangingEvent FOnCanFocusNode;
	TcxTreeListNodeChangingEvent FOnCanSelectNode;
	System::Classes::TNotifyEvent FOnChange;
	TcxTreeListColumnChangedEvent FOnColumnHeaderClick;
	TcxTreeListColumnChangedEvent FOnColumnPosChanged;
	TcxTreeListColumnChangedEvent FOnColumnSizeChanged;
	TcxTreeListNodeCompareEvent FOnCompare;
	int FGlassCursorRefCount;
	TcxTreeListNodeChangingEvent FOnBeginDragNode;
	TcxTreeListNodeChangedEvent FOnCollapsed;
	TcxTreeListNodeChangingEvent FOnCollapsing;
	TcxTreeListCustomDrawBackgroundCellEvent FOnCustomDrawBackgroundCell;
	TcxTreeListCustomDrawBandCellEvent FOnCustomDrawBandCell;
	TcxTreeListCustomDrawHeaderCellEvent FOnCustomDrawBandHeaderCell;
	TcxTreeListCustomDrawEditCellEvent FOnCustomDrawDataCell;
	TcxTreeListCustomDrawFooterCellEvent FOnCustomDrawFooterCell;
	TcxTreeListCustomDrawHeaderCellEvent FOnCustomDrawHeaderCell;
	TcxTreeListCustomDrawIndentCellEvent FOnCustomDrawIndentCell;
	TcxTreeListCustomDrawIndicatorCellEvent FOnCustomDrawIndicatorCell;
	TcxTreeListCustomDrawEditCellEvent FOnCustomDrawPreviewCell;
	System::Classes::TNotifyEvent FOnCustomizationVisibleChanged;
	TcxTreeListNodeChangedEvent FOnDeletion;
	TcxTreeListNodeChangedEvent FOnExpanded;
	TcxTreeListNodeChangingEvent FOnExpanding;
	TcxTreeListGetLevelImagesEvent FOnGetLevelImages;
	TcxTreeListGetNodeHeightEvent FOnGetNodeHeight;
	TcxTreeListGetNodeImageIndexEvent FOnGetNodeImageIndex;
	TcxTreeListGetNodePreviewHeightEvent FOnGetNodePreviewHeight;
	System::Classes::TNotifyEvent FOnAfterSummary;
	System::Classes::TNotifyEvent FOnDataChanged;
	TcxTreeListFocusedColumnChanged FOnFocusedColumnChanged;
	TcxTreeListFocusedNodeChangedEvent FOnFocusedNodeChanged;
	TcxTreeListGetCellHintEvent FOnGetCellHint;
	TcxTreeListGetDragDropTextEvent FOnGetDragDropText;
	System::Classes::TNotifyEvent FOnLeftPosChanged;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxInitStoredObjectEvent FOnInitStoredObject;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	TcxTreeListHotTrackNodeEvent FOnHotTrackNode;
	TcxTreeListIsGroupNodeEvent FOnIsGroupNode;
	System::Classes::TNotifyEvent FOnLayoutChanged;
	TcxTreeListMoveToEvent FOnMoveTo;
	TcxTreeListNodeDataChangedEvent FOnNodeChanged;
	TcxTreeListNodeCheckChangedEvent FOnNodeCheckChanged;
	System::Classes::TNotifyEvent FOnSelectionChanged;
	System::Classes::TNotifyEvent FOnSorted;
	System::Classes::TNotifyEvent FOnSorting;
	TcxTreeListSummaryEvent FOnSummary;
	System::Classes::TNotifyEvent FOnTopRecordIndexChanged;
	int __fastcall GetAvailableContentWidth(void);
	int __fastcall GetAbsoluteCount(void);
	TcxTreeListNode* __fastcall GetAbsoluteItem(int AIndex);
	System::Classes::TList* __fastcall GetAbsoluteItemsList(void);
	int __fastcall GetAbsoluteVisibleCount(void);
	TcxTreeListNode* __fastcall GetAbsoluteVisibleItem(int AIndex);
	System::Classes::TList* __fastcall GetAbsoluteVisibleItemsList(void);
	TcxTreeListBands* __fastcall GetBands(void);
	TcxTreeListColumn* __fastcall GetColumn(int AIndex);
	int __fastcall GetColumnCount(void);
	System::Classes::TList* __fastcall GetColumnsList(void);
	TcxTreeListController* __fastcall GetController(void);
	int __fastcall GetCount(void);
	TcxTreeListDataController* __fastcall GetDataController(void);
	int __fastcall GetDefaultRowHeight(void);
	TcxTreeListColumn* __fastcall GetFocusedColumn(void);
	TcxTreeListNode* __fastcall GetFocusedNode(void);
	System::UnicodeString __fastcall GetHint(void);
	TcxTreeListHitTest* __fastcall GetHitTest(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	int __fastcall GetIndentWidth(void);
	Cxedit::TcxCustomEdit* __fastcall GetInplaceEditor(void);
	bool __fastcall GetIsCancelOperation(void);
	bool __fastcall GetIsEditing(void);
	bool __fastcall GetIsInserting(void);
	TcxTreeListNode* __fastcall GetItem(int Index);
	TcxTreeListNode* __fastcall GetLastNode(void);
	TcxTreeListNode* __fastcall GetLastVisibleNode(void);
	TcxTreeListLevelInfo* __fastcall GetLevelInfo(int ALevel);
	bool __fastcall GetNavigatorIsActive(void);
	TcxTreeListColumnChangedEvent __fastcall GetOnEdited(void);
	TcxTreeListEditingEvent __fastcall GetOnEditing(void);
	TcxTreeListColumnChangedEvent __fastcall GetOnEditValueChanged(void);
	HIDESBASE TcxTreeListOptionsBehavior* __fastcall GetOptionsBehavior(void);
	HIDESBASE TcxTreeListOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE TcxTreeListOptionsView* __fastcall GetOptionsView(void);
	bool __fastcall GetSearching(void);
	System::UnicodeString __fastcall GetSearchingText(void);
	TcxTreeListNode* __fastcall GetSelection(int AIndex);
	int __fastcall GetSelectionCount(void);
	bool __fastcall GetSorted(void);
	int __fastcall GetSortedColumnCount(void);
	TcxTreeListColumn* __fastcall GetSortedColumn(int Index);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	System::UnicodeString __fastcall GetStatusHint(void);
	TcxTreeListStyles* __fastcall GetStyles(void);
	TcxTreeListNode* __fastcall GetTopNode(void);
	TcxTreeListNode* __fastcall GetTopVisibleNode(void);
	int __fastcall GetVisibleCount(void);
	HIDESBASE TcxTreeListViewInfo* __fastcall GetViewInfo(void);
	TcxTreeListColumn* __fastcall GetVisibleColumn(int AIndex);
	int __fastcall GetVisibleColumnCount(void);
	void __fastcall SetAbsoluteItem(int AIndex, TcxTreeListNode* AValue);
	void __fastcall SetAbsoluteVisibleItem(int AIndex, TcxTreeListNode* AValue);
	void __fastcall SetBands(TcxTreeListBands* Value);
	void __fastcall SetColumn(int AIndex, TcxTreeListColumn* Value);
	void __fastcall SetDefaultRowHeight(int AValue);
	void __fastcall SetDefaultLayout(bool AValue);
	void __fastcall SetFocusedColumn(TcxTreeListColumn* AValue);
	void __fastcall SetFocusedNodeProp(TcxTreeListNode* Value);
	void __fastcall SetHint(const System::UnicodeString Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetIsRestoring(bool AValue);
	void __fastcall SetLastVisibleNode(TcxTreeListNode* AValue);
	void __fastcall SetOnEdited(TcxTreeListColumnChangedEvent Value);
	void __fastcall SetOnEditing(TcxTreeListEditingEvent Value);
	void __fastcall SetOnEditValueChanged(TcxTreeListColumnChangedEvent Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxTreeListOptionsBehavior* Value);
	void __fastcall SetOptionsCustomizing(TcxTreeListOptionsCustomizing* Value);
	HIDESBASE void __fastcall SetOptionsData(TcxTreeListOptionsData* Value);
	void __fastcall SetOptionsSelection(TcxTreeListOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxTreeListOptionsView* Value);
	void __fastcall SetPopupMenus(TcxTreeListPopupMenus* Value);
	void __fastcall SetPreview(TcxTreeListPreview* Value);
	void __fastcall SetSearchingText(const System::UnicodeString Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetStateImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetStatusHint(System::UnicodeString AValue);
	HIDESBASE void __fastcall SetStyles(TcxTreeListStyles* Value);
	void __fastcall SetTopVisibleNode(TcxTreeListNode* ANode);
	void __fastcall SetVisibleColumn(int Index, TcxTreeListColumn* AValue);
	void __fastcall DoChangedTimer(System::TObject* Sender);
	void __fastcall RestoreFrom(Cxstorage::TcxStorageType AStorageType, const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool ACreateChildren, bool ADeleteChildren, const System::UnicodeString ARestoreTreeListName);
	void __fastcall StoreTo(Cxstorage::TcxStorageType AStorageType, const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool AReCreate, const System::UnicodeString ASaveTreeListName);
	void __fastcall UpdateDesignerForms(void);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	HIDESBASE MESSAGE void __fastcall CMDrag(Vcl::Controls::TCMDrag &Message);
	
protected:
	void __fastcall AddChanges(TcxTreeListChanges AChanges);
	virtual TcxTreeListNode* __fastcall AddNode(TcxTreeListNode* ANode, TcxTreeListNode* ARelative, void * AData, TcxTreeListNodeAttachMode AttachMode);
	virtual TcxTreeListNode* __fastcall AddNodeInternal(TcxTreeListNode* ANode, TcxTreeListNode* ARelative, TcxTreeListNodeAttachMode AddMethod);
	virtual void __fastcall AfterMouseDown(System::Uitypes::TMouseButton AButton, int X, int Y);
	virtual void __fastcall AssignData(TcxCustomTreeList* ASource);
	virtual void __fastcall AssignOptions(TcxCustomTreeList* ASource);
	virtual void __fastcall BeforeUpdate(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	void __fastcall CalculateForceIndentWidth(void);
	virtual bool __fastcall CanCompare(void);
	virtual void __fastcall CheckChanges(void);
	void __fastcall CheckEvents(void);
	void __fastcall CheckImageListReferences(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall CheckLevelsInfo(void);
	void __fastcall CheckSelectionAndFocused(void);
	void __fastcall CheckSortOrderList(void);
	virtual void __fastcall CheckStructure(void);
	void __fastcall ClearCalculatedWidths(void);
	void __fastcall ColumnSortOrderChanged(TcxTreeListColumn* AColumn, System::Classes::TShiftState AShift);
	virtual TcxTreeListNode* __fastcall CreateNode(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoAfterSummary(void);
	virtual void __fastcall DoBandHeaderClick(TcxTreeListBand* ABand);
	virtual void __fastcall DoBandPosChanged(TcxTreeListBand* ABand);
	bool __fastcall DoBeginDragNode(TcxTreeListNode* ANode);
	virtual bool __fastcall DoCanFocusNode(TcxTreeListNode* ANode);
	virtual bool __fastcall DoCanNodeCollapse(TcxTreeListNode* ANode);
	virtual bool __fastcall DoCanNodeExpand(TcxTreeListNode* ANode);
	virtual bool __fastcall DoCanSelectNode(TcxTreeListNode* ANode);
	virtual void __fastcall DoChanged(bool BlockChangedEvent = true);
	virtual void __fastcall DoColumnHeaderClick(TcxTreeListColumn* AColumn);
	virtual void __fastcall DoColumnPosChanged(TcxTreeListColumn* AColumn);
	virtual void __fastcall DoCompare(TcxTreeListNode* ANode1, TcxTreeListNode* ANode2, int &ACompare);
	virtual void __fastcall DoCustomizationVisibleChanged(void);
	virtual void __fastcall DoDataChangedEvent(System::TObject* Sender);
	virtual void __fastcall DoDeletion(TcxTreeListNode* ANode);
	virtual void __fastcall DoEditValueChanged(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoExpand(TcxTreeListNode* ANode);
	virtual void __fastcall DoFocusedItemChanged(Cxinplacecontainer::TcxCustomInplaceEditContainer* APrevFocusedItem, Cxinplacecontainer::TcxCustomInplaceEditContainer* AFocusedItem);
	virtual void __fastcall DoFocusedNodeChanged(TcxTreeListNode* APrevNode, TcxTreeListNode* AFocusedNode);
	virtual void __fastcall DoGetCellHint(System::TObject* ACell, System::UnicodeString &AText, bool &ANeedShow);
	virtual void __fastcall DoGetLevelImages(TcxTreeListLevelInfo* AInfo, int ALevel);
	virtual void __fastcall DoGetNodeHeight(TcxTreeListNode* ANode, int &AHeight);
	virtual System::Uitypes::TImageIndex __fastcall DoGetNodeImageIndex(TcxTreeListNode* ANode, TcxTreeListImageIndexType AIndex);
	virtual void __fastcall DoGetPreviewHeight(TcxTreeListNode* ANode, int &AHeight);
	virtual void __fastcall DoHotTrackNode(TcxTreeListNode* ANode, System::Classes::TShiftState AShift, System::Uitypes::TCursor &ACursor);
	virtual void __fastcall DoInplaceEditContainerItemAdded(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual void __fastcall DoInplaceEditContainerItemRemoved(Cxinplacecontainer::TcxCustomInplaceEditContainer* AItem);
	virtual bool __fastcall DoIsGroupNode(TcxTreeListNode* ANode);
	virtual void __fastcall DoLayoutChangedEvent(void);
	virtual void __fastcall DoLeftPosChanged(void);
	virtual bool __fastcall DoMoveToEvent(TcxTreeListNode* AttachNode, TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* Nodes, bool &IsCopy);
	virtual void __fastcall DoNodeChanged(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	virtual void __fastcall DoNodeCheckChanged(TcxTreeListNode* ANode, Cxlookandfeelpainters::TcxCheckBoxState AState);
	virtual void __fastcall DoNodeCollapsed(TcxTreeListNode* ANode);
	virtual void __fastcall DoNodeExpanded(TcxTreeListNode* ANode);
	virtual void __fastcall DoSelectAll(void);
	virtual void __fastcall DoSelectionChanged(void);
	virtual void __fastcall DoSetNodeFocused(TcxTreeListNode* ANode, bool AValue, System::Classes::TShiftState Shift = System::Classes::TShiftState() );
	virtual void __fastcall DoSorted(void);
	virtual void __fastcall DoSorting(void);
	virtual void __fastcall DoSortNodes(void);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual void __fastcall DoTopRecordIndexChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual void __fastcall ForceLayoutChanged(void);
	virtual Cxnavigator::_di_IcxNavigator __fastcall GetNavigatorButtonsControl(void);
	virtual TcxTreeListBandClass __fastcall GetBandItemClass(void);
	virtual Cxinplacecontainer::TcxCustomControlControllerClass __fastcall GetControllerClass(void);
	virtual Cxinplacecontainer::TcxCustomControlStylesClass __fastcall GetControlStylesClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxinplacecontainer::TcxEditingControllerClass __fastcall GetEditingControllerClass(void);
	virtual Cxinplacecontainer::TcxHitTestControllerClass __fastcall GetHitTestControllerClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual TcxTreeListOptionsCustomizingClass __fastcall GetOptionsCustomizingClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual TcxTreeListOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Cxinplacecontainer::TcxControlOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxinplacecontainer::TcxCustomControlPainterClass __fastcall GetPainterClass(void);
	virtual TcxTreeListPreviewClass __fastcall GetPreviewClass(void);
	virtual TcxTreeListNodeClass __fastcall GetRootClass(void);
	virtual TcxTreeListSummaryClass __fastcall GetSummaryClass(void);
	virtual TcxTreeListColumnClass __fastcall GetTreeListColumnClass(void);
	virtual TcxTreeListCustomizingClass __fastcall GetTreeListCustomizingClass(void);
	virtual Cxinplacecontainer::TcxCustomControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual int __fastcall GetCountNodeForBestFit(void);
	TcxTreeListBand* __fastcall GetDefaultColumnContainer(void);
	virtual Cxedit::TcxInplaceEditAutoHeight __fastcall GetEditAutoHeight(void);
	TcxTreeListColumn* __fastcall GetSameColumn(TcxTreeListColumn* AColumn);
	virtual TcxTreeListNode* __fastcall GetStartNodeForBestFit(void);
	virtual bool __fastcall IsLocked(void);
	virtual bool __fastcall IsTreeListLocked(void);
	virtual void __fastcall ImagesChanged(System::TObject* Sender);
	virtual void __fastcall InitializeFields(void);
	void __fastcall InternalClearAll(void);
	virtual void __fastcall InternalCopy(TcxTreeListNode* ANode, TcxTreeListNode* ADestNode);
	void __fastcall InternalDelete(System::Classes::TList* ANodes);
	virtual void __fastcall InternalMove(TcxTreeListNode* ANode, TcxTreeListNode* ADestNode, TcxTreeListNodeAttachMode AMode);
	bool __fastcall IsNodeEdited(TcxTreeListNode* ANode);
	virtual bool __fastcall IsNodeInserting(TcxTreeListNode* ANode);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall RefreshFields(void);
	HIDESBASE virtual void __fastcall ScrollWindow(const int DX, const int DY);
	virtual void __fastcall StructureChanged(void);
	void __fastcall SetImageList(Vcl::Imglist::TCustomImageList* const AValue, Vcl::Imglist::TCustomImageList* &AFieldValue, Vcl::Imglist::TChangeLink* const AChangeLink);
	void __fastcall SetNodeParent(TcxTreeListNode* ANewNode, TcxTreeListNode* ANewParent, TcxTreeListNodeAddMode AMode);
	void __fastcall SetFocusedVisibleNode(TcxTreeListNode* ANode);
	virtual void __fastcall UpdateFocusedNode(TcxTreeListColumn* AColumn);
	void __fastcall ValidateStates(void);
	void __fastcall BeforeShowingEdit(void);
	virtual bool __fastcall CanMultiSelect(void);
	virtual void __fastcall DoBandSizeChanged(TcxTreeListBand* ABand);
	virtual void __fastcall DoClear(void);
	virtual void __fastcall DoColumnSizeChanged(TcxTreeListColumn* AColumn);
	TcxTreeListColumn* __fastcall DoCreateColumn(void);
	virtual void __fastcall DoDeleteSelection(void);
	virtual void __fastcall DoDeleteNode(TcxTreeListNode* ANode);
	void __fastcall DoInternalMoveTo(TcxTreeListNode* AttachNode, TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* ANodes, bool IsCopy);
	virtual void __fastcall DoMoveTo(TcxTreeListNode* AttachNode, TcxTreeListNodeAttachMode AttachMode, System::Classes::TList* ANodes, bool IsCopy);
	virtual void __fastcall DoOnBandSizeChanged(TcxTreeListBand* ABand);
	virtual void __fastcall DoOnColumnSizeChanged(TcxTreeListColumn* AColumn);
	virtual System::UnicodeString __fastcall DoWriteHeaderToText(void);
	virtual System::UnicodeString __fastcall DoWriteNodeToText(TcxTreeListNode* ANode);
	virtual void __fastcall DoWriteToClipboard(bool AOnlySelected);
	bool __fastcall DoWriteToText(bool AOnlySelected, /* out */ System::UnicodeString &AText);
	virtual void __fastcall DeleteNodes(System::Classes::TList* AList);
	virtual bool __fastcall GetIsActive(void);
	virtual int __fastcall GetFixedContentSize(void);
	int __fastcall GetMaxBandWidth(TcxTreeListBand* ABand);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual void __fastcall InitInsertingNode(TcxTreeListNode* ANode);
	virtual bool __fastcall InsertNode(TcxTreeListNode* ARelative, bool IsAppend);
	virtual void __fastcall MakeNodeVisible(TcxTreeListNode* ANode);
	void __fastcall RestoreCursor(void);
	void __fastcall SetGlassCursor(void);
	void __fastcall SortingStateChanged(TcxTreeListColumn* AColumn, System::Classes::TShiftState AShift);
	virtual bool __fastcall SupportBandColumnEditor(void);
	virtual bool __fastcall SupportItemsEditor(void);
	virtual bool __fastcall SupportCreateAllItems(void);
	virtual void __fastcall CreateAllItems(void);
	virtual int __fastcall NavigatorGetRecordCount(void);
	virtual int __fastcall NavigatorGetRecordIndex(void);
	bool __fastcall NavigatorIsEditing(void);
	void __fastcall RefreshNavigatorButtons(void);
	void __fastcall DoAction(int AButtonIndex);
	Cxnavigator::TcxNavigatorControlNotifier* __fastcall GetNotifier(void);
	virtual bool __fastcall IsActionSupported(int AButtonIndex);
	bool __fastcall CanAppend(void);
	bool __fastcall CanEdit(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanInsert(void);
	void __fastcall ClearBookmark(void);
	void __fastcall GotoBookmark(void);
	virtual bool __fastcall HasData(void);
	bool __fastcall IsBookmarkAvailable(void);
	void __fastcall SaveBookmark(void);
	System::Classes::TList* __fastcall GetSelectionsEx(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual void __fastcall CheckCreateDesignSelectionHelper(void);
	virtual void __fastcall ControlUpdateData(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DataLayoutChanged(void);
	virtual void __fastcall DoLayoutChanged(void);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	virtual System::Types::TRect __fastcall DragDropImageDisplayRect(void);
	virtual void __fastcall DrawDragDropImage(Vcl::Graphics::TBitmap* ADragBitmap, Cxgraphics::TcxCanvas* ACanvas);
	System::Types::TPoint __fastcall GetDragInfoImagePosition(System::Types::TPoint APoint);
	virtual System::UnicodeString __fastcall GetDragDropText(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetDragDropViewParams(void);
	DYNAMIC Cxcontrols::TDragControlObjectClass __fastcall GetDragObjectClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall InternalCollapseNode(TcxTreeListNode* ANode, bool ARecursive);
	virtual bool __fastcall InternalExpandNode(TcxTreeListNode* ANode, bool ARecursive);
	void __fastcall AssignItemsPosition(bool ABandIndexOnly);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	void __fastcall SaveItemsPosition(bool ABandIndexOnly);
	DYNAMIC void __fastcall Updated(void);
	DYNAMIC void __fastcall Updating(void);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredObjectProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall StoredCreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredDeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	bool __fastcall IsUpdating(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Modified(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	__property System::Classes::TList* AbsoluteItemsList = {read=GetAbsoluteItemsList};
	__property System::Classes::TList* AbsoluteVisibleItemsList = {read=GetAbsoluteVisibleItemsList};
	__property int AvailableContentWidth = {read=GetAvailableContentWidth, nodefault};
	__property Vcl::Extctrls::TTimer* ChangeDelayTimer = {read=FDelayTimer};
	__property TcxTreeListChanges Changes = {read=FChanges, write=FChanges, nodefault};
	__property bool ChangesLocked = {read=FChangesLocked, write=FChangesLocked, nodefault};
	__property System::Classes::TList* ColumnsList = {read=GetColumnsList};
	__property TcxTreeListController* Controller = {read=GetController};
	__property TcxTreeListDataController* DataController = {read=GetDataController};
	__property bool IgnoreLoadingStatus = {read=FIgnoreLoadingStatus, write=FIgnoreLoadingStatus, nodefault};
	__property bool IsCancelOperation = {read=GetIsCancelOperation, write=FIsCancelOperation, nodefault};
	__property int IndentWidth = {read=GetIndentWidth, nodefault};
	__property bool IsRefreshFields = {read=FIsRefreshFields, write=FIsRefreshFields, nodefault};
	__property bool IsRestoring = {read=FIsRestoring, write=SetIsRestoring, nodefault};
	__property bool LockChanges = {read=FLockChanges, write=FLockChanges, nodefault};
	__property TcxTreeListLevelInfo* LevelsInfo[int ALevel] = {read=GetLevelInfo};
	__property System::Classes::TList* SortedColumnsList = {read=FSortedColumns};
	__property System::UnicodeString StatusHint = {read=GetStatusHint, write=SetStatusHint};
	__property System::Uitypes::TCursor StoredCursor = {read=FStoredCursor, nodefault};
	__property System::UnicodeString StoringName = {read=FStoringName, write=FStoringName};
	__property TcxTreeListViewInfo* ViewInfo = {read=GetViewInfo};
	__property System::Classes::TNotifyEvent OnAfterSummary = {read=FOnAfterSummary, write=FOnAfterSummary};
	__property TcxTreeListBandChangedEvent OnBandHeaderClick = {read=FOnBandHeaderClick, write=FOnBandHeaderClick};
	__property TcxTreeListBandChangedEvent OnBandPosChanged = {read=FOnBandPosChanged, write=FOnBandPosChanged};
	__property TcxTreeListBandChangedEvent OnBandSizeChanged = {read=FOnBandSizeChanged, write=FOnBandSizeChanged};
	__property TcxTreeListNodeChangingEvent OnBeginDragNode = {read=FOnBeginDragNode, write=FOnBeginDragNode};
	__property TcxTreeListNodeChangingEvent OnCanFocusNode = {read=FOnCanFocusNode, write=FOnCanFocusNode};
	__property TcxTreeListNodeChangingEvent OnCanSelectNode = {read=FOnCanSelectNode, write=FOnCanSelectNode};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TcxTreeListNodeChangedEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property TcxTreeListNodeChangingEvent OnCollapsing = {read=FOnCollapsing, write=FOnCollapsing};
	__property TcxTreeListColumnChangedEvent OnColumnHeaderClick = {read=FOnColumnHeaderClick, write=FOnColumnHeaderClick};
	__property TcxTreeListColumnChangedEvent OnColumnPosChanged = {read=FOnColumnPosChanged, write=FOnColumnPosChanged};
	__property TcxTreeListColumnChangedEvent OnColumnSizeChanged = {read=FOnColumnSizeChanged, write=FOnColumnSizeChanged};
	__property TcxTreeListNodeCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property TcxTreeListCustomDrawBackgroundCellEvent OnCustomDrawBackgroundCell = {read=FOnCustomDrawBackgroundCell, write=FOnCustomDrawBackgroundCell};
	__property TcxTreeListCustomDrawBandCellEvent OnCustomDrawBandCell = {read=FOnCustomDrawBandCell, write=FOnCustomDrawBandCell};
	__property TcxTreeListCustomDrawHeaderCellEvent OnCustomDrawBandHeaderCell = {read=FOnCustomDrawBandHeaderCell, write=FOnCustomDrawBandHeaderCell};
	__property TcxTreeListCustomDrawEditCellEvent OnCustomDrawDataCell = {read=FOnCustomDrawDataCell, write=FOnCustomDrawDataCell};
	__property TcxTreeListCustomDrawFooterCellEvent OnCustomDrawFooterCell = {read=FOnCustomDrawFooterCell, write=FOnCustomDrawFooterCell};
	__property TcxTreeListCustomDrawHeaderCellEvent OnCustomDrawHeaderCell = {read=FOnCustomDrawHeaderCell, write=FOnCustomDrawHeaderCell};
	__property TcxTreeListCustomDrawIndentCellEvent OnCustomDrawIndentCell = {read=FOnCustomDrawIndentCell, write=FOnCustomDrawIndentCell};
	__property TcxTreeListCustomDrawIndicatorCellEvent OnCustomDrawIndicatorCell = {read=FOnCustomDrawIndicatorCell, write=FOnCustomDrawIndicatorCell};
	__property TcxTreeListCustomDrawEditCellEvent OnCustomDrawPreviewCell = {read=FOnCustomDrawPreviewCell, write=FOnCustomDrawPreviewCell};
	__property System::Classes::TNotifyEvent OnCustomizationFormVisibleChanged = {read=FOnCustomizationVisibleChanged, write=FOnCustomizationVisibleChanged};
	__property TcxTreeListNodeChangedEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TcxTreeListNodeChangedEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property TcxTreeListNodeChangingEvent OnExpanding = {read=FOnExpanding, write=FOnExpanding};
	__property TcxTreeListGetCellHintEvent OnGetCellHint = {read=FOnGetCellHint, write=FOnGetCellHint};
	__property TcxTreeListGetDragDropTextEvent OnGetDragDropText = {read=FOnGetDragDropText, write=FOnGetDragDropText};
	__property TcxTreeListGetLevelImagesEvent OnGetLevelImages = {read=FOnGetLevelImages, write=FOnGetLevelImages};
	__property TcxTreeListGetNodeHeightEvent OnGetNodeHeight = {read=FOnGetNodeHeight, write=FOnGetNodeHeight};
	__property TcxTreeListGetNodeImageIndexEvent OnGetNodeImageIndex = {read=FOnGetNodeImageIndex, write=FOnGetNodeImageIndex};
	__property TcxTreeListGetNodePreviewHeightEvent OnGetNodePreviewHeight = {read=FOnGetNodePreviewHeight, write=FOnGetNodePreviewHeight};
	__property TcxTreeListHotTrackNodeEvent OnHotTrackNode = {read=FOnHotTrackNode, write=FOnHotTrackNode};
	__property TcxTreeListIsGroupNodeEvent OnIsGroupNode = {read=FOnIsGroupNode, write=FOnIsGroupNode};
	__property System::Classes::TNotifyEvent OnLeftPosChanged = {read=FOnLeftPosChanged, write=FOnLeftPosChanged};
	__property TcxTreeListMoveToEvent OnMoveTo = {read=FOnMoveTo, write=FOnMoveTo};
	__property TcxTreeListNodeDataChangedEvent OnNodeChanged = {read=FOnNodeChanged, write=FOnNodeChanged};
	__property TcxTreeListNodeCheckChangedEvent OnNodeCheckChanged = {read=FOnNodeCheckChanged, write=FOnNodeCheckChanged};
	__property System::Classes::TNotifyEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
	__property System::Classes::TNotifyEvent OnSorted = {read=FOnSorted, write=FOnSorted};
	__property System::Classes::TNotifyEvent OnSorting = {read=FOnSorting, write=FOnSorting};
	__property TcxTreeListSummaryEvent OnSummary = {read=FOnSummary, write=FOnSummary};
	__property System::Classes::TNotifyEvent OnTopRecordIndexChanged = {read=FOnTopRecordIndexChanged, write=FOnTopRecordIndexChanged};
	__property NavigatorEvents;
	__property System::Classes::TNotifyEvent PopupMenusEvents = {read=FPopupMenusEvents, write=FPopupMenusEvents};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FStylesEvents, write=FStylesEvents};
	__property System::Classes::TNotifyEvent OnDataChanged = {read=FOnDataChanged, write=FOnDataChanged};
	__property TcxTreeListColumnChangedEvent OnEdited = {read=GetOnEdited, write=SetOnEdited};
	__property TcxTreeListEditingEvent OnEditing = {read=GetOnEditing, write=SetOnEditing};
	__property TcxTreeListColumnChangedEvent OnEditValueChanged = {read=GetOnEditValueChanged, write=SetOnEditValueChanged};
	__property TcxTreeListFocusedColumnChanged OnFocusedColumnChanged = {read=FOnFocusedColumnChanged, write=FOnFocusedColumnChanged};
	__property TcxTreeListFocusedNodeChangedEvent OnFocusedNodeChanged = {read=FOnFocusedNodeChanged, write=FOnFocusedNodeChanged};
	__property System::Classes::TNotifyEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxInitStoredObjectEvent OnInitStoredObject = {read=FOnInitStoredObject, write=FOnInitStoredObject};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
	
public:
	__fastcall virtual TcxCustomTreeList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomTreeList(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AdjustColumnsWidth(void);
	void __fastcall ApplyBestFit(void);
	void __fastcall Cancel(void);
	void __fastcall Clear(void);
	virtual TcxTreeListColumn* __fastcall CreateColumn(TcxTreeListBand* ABand = (TcxTreeListBand*)(0x0));
	virtual void __fastcall DeleteAllColumns(void);
	void __fastcall DeleteSelection(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	void __fastcall Edit(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual void __fastcall MakeDefaultLayout(void);
	void __fastcall Post(void);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	virtual void __fastcall FullRefresh(void);
	virtual TcxTreeListNode* __fastcall Find(void * AData, TcxTreeListNode* AStart, bool AExpandedOnly, bool AForward, TcxTreeListFindFunc AFilter, bool AIgnoreStartNode = false);
	TcxTreeListNode* __fastcall FindNodeByText(const System::UnicodeString AText, TcxTreeListColumn* AColumn, TcxTreeListNode* AStartNode = (TcxTreeListNode*)(0x0), bool AExpandedOnly = false, bool AForward = true, bool ACaseSensitive = true, TcxTreeListFindMode AMode = (TcxTreeListFindMode)(0x0), TcxTreeListLikeParams* ALikeParams = (TcxTreeListLikeParams*)(0x0), bool AIgnoreStartNode = false);
	void __fastcall SelectAll(void);
	virtual void __fastcall Select(TcxTreeListNode* Node, System::Classes::TShiftState ShiftState = System::Classes::TShiftState() )/* overload */;
	virtual void __fastcall Select(TcxTreeListNode* const *ANodes, const int ANodes_Size)/* overload */;
	virtual void __fastcall Select(System::Classes::TList* ANodesList)/* overload */;
	void __fastcall SetFocusedNode(TcxTreeListNode* ANode, System::Classes::TShiftState AShift);
	DYNAMIC bool __fastcall StartDrag(Vcl::Controls::TDragObject* DragObject);
	virtual void __fastcall Subselect(TcxTreeListNode* Node);
	virtual void __fastcall Deselect(TcxTreeListNode* Node);
	virtual void __fastcall ClearSelection(bool KeepPrimary = false);
	void __fastcall ClearSorting(void);
	TcxTreeListColumn* __fastcall ColumnByName(const System::UnicodeString AName);
	TcxTreeListNode* __fastcall GetSelections(System::Classes::TList* AList);
	void __fastcall GotoBOF(void);
	void __fastcall GotoEOF(void);
	void __fastcall GotoNext(void);
	void __fastcall GotoNextPage(void);
	void __fastcall GotoPrev(void);
	void __fastcall GotoPrevPage(void);
	bool __fastcall IsBOF(void);
	bool __fastcall IsEOF(void);
	void __fastcall CancelEdit(void);
	void __fastcall HideEdit(void);
	void __fastcall ShowEdit(void);
	void __fastcall ShowEditByKey(System::WideChar AKey);
	void __fastcall ShowEditByMouse(int X, int Y, System::Classes::TShiftState AShift);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, bool AChildrenCreating = false, bool AChildrenDeleting = false, const System::UnicodeString ARestoreTreeListName = System::UnicodeString());
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, bool AChildrenCreating = false, bool AChildrenDeleting = false, const System::UnicodeString ARestoreTreeListName = System::UnicodeString());
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, bool AChildrenCreating = false, bool AChildrenDeleting = false, const System::UnicodeString ARestoreTreeListName = System::UnicodeString());
	void __fastcall StoreToIniFile(System::UnicodeString AStorageName, bool AReCreate = true, const System::UnicodeString ASaveTreeListName = System::UnicodeString());
	void __fastcall StoreToRegistry(System::UnicodeString AStorageName, bool AReCreate = true, const System::UnicodeString ASaveTreeListName = System::UnicodeString());
	void __fastcall StoreToStream(System::Classes::TStream* AStream, const System::UnicodeString ASaveTreeListName = System::UnicodeString());
	bool __fastcall FindNext(bool AForward);
	void __fastcall CancelSearching(void);
	System::Types::TRect __fastcall CellRect(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	System::Types::TRect __fastcall GetEditRect(TcxTreeListNode* ANode, TcxTreeListColumn* AColumn);
	TcxTreeListNode* __fastcall GetNodeAt(int X, int Y);
	void __fastcall CopyAllToClipboard(void);
	void __fastcall CopySelectedToClipboard(void);
	void __fastcall RestoreColumnsDefaults(void);
	void __fastcall RestoreColumnsWidths(void);
	__property int AbsoluteCount = {read=GetAbsoluteCount, nodefault};
	__property TcxTreeListNode* AbsoluteItems[int Index] = {read=GetAbsoluteItem, write=SetAbsoluteItem};
	__property int AbsoluteVisibleCount = {read=GetAbsoluteVisibleCount, nodefault};
	__property TcxTreeListNode* AbsoluteVisibleItems[int Index] = {read=GetAbsoluteVisibleItem, write=SetAbsoluteVisibleItem};
	__property TcxTreeListBands* Bands = {read=GetBands, write=SetBands};
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TcxTreeListColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	__property int Count = {read=GetCount, nodefault};
	__property TcxTreeListCustomizing* Customizing = {read=FCustomizing, write=FCustomizing};
	__property System::Types::TSize DefaultIndentSize = {read=FDefaultIndentSize};
	__property bool DefaultLayout = {read=FDefaultLayout, write=SetDefaultLayout, default=0};
	__property int DefaultRowHeight = {read=GetDefaultRowHeight, write=SetDefaultRowHeight, default=0};
	__property System::Classes::TList* Designers = {read=FDesigners};
	__property TcxTreeListNode* DragNode = {read=FDragNode};
	__property int ExpansionLevel = {read=FExpansionLevel, nodefault};
	__property TcxTreeListColumn* FocusedColumn = {read=GetFocusedColumn, write=SetFocusedColumn};
	__property TcxTreeListNode* FocusedNode = {read=GetFocusedNode, write=SetFocusedNodeProp};
	__property TcxTreeListHitTest* HitTest = {read=GetHitTest};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property Cxedit::TcxCustomEdit* InplaceEditor = {read=GetInplaceEditor};
	__property bool IsActive = {read=GetIsActive, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsInserting = {read=GetIsInserting, nodefault};
	__property TcxTreeListNode* Items[int Index] = {read=GetItem};
	__property TcxTreeListNode* LastNode = {read=GetLastNode};
	__property TcxTreeListNode* LastVisibleNode = {read=GetLastVisibleNode, write=SetLastVisibleNode};
	__property Navigator;
	__property TcxTreeListOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxTreeListOptionsCustomizing* OptionsCustomizing = {read=FOptionsCustomizing, write=SetOptionsCustomizing};
	__property TcxTreeListOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property TcxTreeListOptionsSelection* OptionsSelection = {read=FOptionsSelection, write=SetOptionsSelection};
	__property TcxTreeListOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxTreeListPopupMenus* PopupMenus = {read=FPopupMenus, write=SetPopupMenus};
	__property TcxTreeListPreview* Preview = {read=FPreview, write=SetPreview};
	__property TcxTreeListNode* Root = {read=FRoot};
	__property bool Searching = {read=GetSearching, nodefault};
	__property System::UnicodeString SearchingText = {read=GetSearchingText, write=SetSearchingText};
	__property int SelectionCount = {read=GetSelectionCount, nodefault};
	__property System::Classes::TList* SelectionList = {read=FSelectionList};
	__property TcxTreeListNode* Selections[int Index] = {read=GetSelection};
	__property bool Sorted = {read=GetSorted, write=SetSorted, nodefault};
	__property int SortedColumnCount = {read=GetSortedColumnCount, nodefault};
	__property TcxTreeListColumn* SortedColumns[int Index] = {read=GetSortedColumn};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages, write=SetStateImages};
	__property TcxTreeListStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxTreeListSummary* Summary = {read=FSummary};
	__property TcxTreeListNode* TopNode = {read=GetTopNode};
	__property TcxTreeListNode* TopVisibleNode = {read=GetTopVisibleNode, write=SetTopVisibleNode};
	__property int VisibleColumnCount = {read=GetVisibleColumnCount, nodefault};
	__property TcxTreeListColumn* VisibleColumns[int Index] = {read=GetVisibleColumn, write=SetVisibleColumn};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property BorderSize;
	__property LookAndFeel;
	__property Color = {default=-16777211};
	
__published:
	__property BufferedPaint = {stored=false};
	__property System::UnicodeString Hint = {read=GetHint, write=SetHint};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTreeList(HWND ParentWindow) : Cxinplacecontainer::TcxExtEditingControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxTreeListDesignTimeOperations;	/* IcxTreeListDesignTimeOperations */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxNavigator;	/* Cxnavigator::IcxNavigator */
	
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
	// {781A0614-EA26-4214-85D2-10C7DA2AF22B}
	operator _di_IcxTreeListDesignTimeOperations()
	{
		_di_IcxTreeListDesignTimeOperations intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxTreeListDesignTimeOperations*(void) { return (IcxTreeListDesignTimeOperations*)&__IcxTreeListDesignTimeOperations; }
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
	
};


class DELPHICLASS TcxTreeList;
class PASCALIMPLEMENTATION TcxTreeList : public TcxCustomTreeList
{
	typedef TcxCustomTreeList inherited;
	
private:
	System::Classes::TMemoryStream* FDataStream;
	TcxTreeListNode* __fastcall InternalCreateNode(TcxTreeListNode* AParent, TcxTreeListNode* APrev, int &AIndex);
	
protected:
	virtual void __fastcall AssignData(TcxCustomTreeList* ASource);
	void __fastcall CorrectHandles(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual bool __fastcall SupportItemsEditor(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	void __fastcall ReadStructure(System::Classes::TStream* AStream, int AVersion);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	void __fastcall WriteStructure(System::Classes::TStream* AStream);
	
public:
	TcxTreeListNode* __fastcall Add(void)/* overload */;
	TcxTreeListNode* __fastcall Add(TcxTreeListNode* ASibling, void * AData = (void *)(0x0))/* overload */;
	TcxTreeListNode* __fastcall AddChild(TcxTreeListNode* AParent, void * AData = (void *)(0x0));
	TcxTreeListNode* __fastcall AddChildFirst(TcxTreeListNode* AParent, void * AData = (void *)(0x0));
	TcxTreeListNode* __fastcall AddFirst(void)/* overload */;
	TcxTreeListNode* __fastcall AddFirst(TcxTreeListNode* ASibling, void * AData = (void *)(0x0))/* overload */;
	virtual TcxTreeListNode* __fastcall AddNode(TcxTreeListNode* ANode, TcxTreeListNode* ARelative, void * AData, TcxTreeListNodeAttachMode AttachMode);
	HIDESBASE TcxTreeListNode* __fastcall Insert(TcxTreeListNode* ASibling, void * AData = (void *)(0x0));
	TcxTreeListNode* __fastcall InsertEx(TcxTreeListNode* ANode, TcxTreeListNode* ASibling, void * AData = (void *)(0x0));
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property ColumnCount;
	__property Columns;
	__property Customizing;
	__property FocusedColumn;
	__property FocusedNode;
	__property HitTest;
	__property IsEditing;
	__property Root;
	__property SelectionCount;
	__property Selections;
	__property Sorted;
	__property SortedColumnCount;
	__property SortedColumns;
	__property TopVisibleNode;
	__property VisibleColumnCount;
	__property VisibleColumns;
	__property VisibleCount;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Bands;
	__property BorderStyle = {default=1};
	__property Constraints;
	__property Cursor = {default=0};
	__property DefaultLayout = {default=0};
	__property DefaultRowHeight = {default=0};
	__property DragCursor = {default=0};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property HelpType = {default=1};
	__property Images;
	__property LookAndFeel;
	__property Navigator;
	__property OptionsBehavior;
	__property OptionsCustomizing;
	__property OptionsData;
	__property OptionsSelection;
	__property OptionsView;
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property PopupMenus;
	__property Preview;
	__property StateImages;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property NavigatorEvents;
	__property OnAfterSummary;
	__property OnBandHeaderClick;
	__property OnBandPosChanged;
	__property OnBandSizeChanged;
	__property OnBeginDragNode;
	__property OnCanFocusNode;
	__property OnCanResize;
	__property OnCanSelectNode;
	__property OnChange;
	__property OnClick;
	__property OnCollapsed;
	__property OnCollapsing;
	__property OnColumnHeaderClick;
	__property OnColumnPosChanged;
	__property OnColumnSizeChanged;
	__property OnCompare;
	__property OnConstrainedResize;
	__property OnContextPopup;
	__property OnCustomDrawBackgroundCell;
	__property OnCustomDrawBandCell;
	__property OnCustomDrawBandHeaderCell;
	__property OnCustomDrawDataCell;
	__property OnCustomDrawFooterCell;
	__property OnCustomDrawHeaderCell;
	__property OnCustomDrawIndentCell;
	__property OnCustomDrawIndicatorCell;
	__property OnCustomDrawPreviewCell;
	__property OnCustomizationFormVisibleChanged;
	__property OnDataChanged;
	__property OnDblClick;
	__property OnDeletion;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEdited;
	__property OnEditing;
	__property OnEditValueChanged;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnExpanded;
	__property OnExpanding;
	__property OnFocusedColumnChanged;
	__property OnFocusedNodeChanged;
	__property OnGetCellHint;
	__property OnGetDragDropText;
	__property OnGetLevelImages;
	__property OnGetNodeHeight;
	__property OnGetNodeImageIndex;
	__property OnGetNodePreviewHeight;
	__property OnGetSiteInfo;
	__property OnGetStoredProperties;
	__property OnGetStoredPropertyValue;
	__property OnHotTrackNode;
	__property OnInitEdit;
	__property OnInitEditValue;
	__property OnInitStoredObject;
	__property OnIsGroupNode;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnLeftPosChanged;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnMoveTo;
	__property OnNodeChanged;
	__property OnNodeCheckChanged;
	__property OnResize;
	__property OnSelectionChanged;
	__property OnSetStoredPropertyValue;
	__property OnSorted;
	__property OnSorting;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnSummary;
	__property OnTopRecordIndexChanged;
	__property OnUnDock;
	__property PopupMenusEvents;
	__property StylesEvents;
public:
	/* TcxCustomTreeList.Create */ inline __fastcall virtual TcxTreeList(System::Classes::TComponent* AOwner) : TcxCustomTreeList(AOwner) { }
	/* TcxCustomTreeList.Destroy */ inline __fastcall virtual ~TcxTreeList(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeList(HWND ParentWindow) : TcxCustomTreeList(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxTreeListDefWidth = System::Int8(0x64);
static const System::Int8 cxTreeListDefMinWidth = System::Int8(0x14);
static const System::Int8 cxTreeListHeaderMovingZoneSize = System::Int8(0x14);
static const System::Int8 cxTreeListDefIndicatorWidth = System::Int8(0xc);
static const System::Int8 cxTreeListDefSeparatorWidth = System::Int8(0x2);
static const System::Word cxTreeListDefDropArrowColor = System::Word(0xff00);
static const System::Int8 CustomizationPopupColumnOffset = System::Int8(0xa);
static const System::Int8 tlcs_Header = System::Int8(0x1);
static const System::Int8 tlcs_Footer = System::Int8(0x2);
static const System::Int8 tlbs_Content = System::Int8(0x0);
static const System::Int8 tlbs_Footer = System::Int8(0x1);
static const System::Int8 tlbs_Header = System::Int8(0x2);
static const System::Int8 tlbs_HeaderBackground = System::Int8(0x3);
static const System::Int8 tlsv_Content = System::Int8(0x0);
static const System::Int8 tlsv_BandBackground = System::Int8(0x6);
static const System::Int8 tlsv_BandContent = System::Int8(0x7);
static const System::Int8 tlsv_BandHeader = System::Int8(0x8);
static const System::Int8 tlsv_ColumnFooter = System::Int8(0x9);
static const System::Int8 tlsv_ColumnHeader = System::Int8(0xa);
static const System::Int8 tlsv_ContentEven = System::Int8(0xb);
static const System::Int8 tlsv_ContentOdd = System::Int8(0xc);
static const System::Int8 tlsv_Footer = System::Int8(0xd);
static const System::Int8 tlsv_HotTrack = System::Int8(0x11);
static const System::Int8 tlsv_IncSearch = System::Int8(0xe);
static const System::Int8 tlsv_Indicator = System::Int8(0xf);
static const System::Int8 tlsv_Preview = System::Int8(0x10);
static const System::Int8 cxtlMaxControlStyleIndex = System::Int8(0x10);
static const System::Int8 cxtlMaxColumnStyleIndex = System::Int8(0x2);
static const System::Int8 cxtlMaxBandStyleIndex = System::Int8(0x3);
static const System::Int8 tlhc_HitAtBackground = System::Int8(0x4);
static const System::Int8 tlhc_HitAtBand = System::Int8(0x5);
static const System::Int8 tlhc_HitAtBandContainer = System::Int8(0x6);
static const System::Int8 tlhc_HitAtBandCustomizing = System::Int8(0x7);
static const System::Int8 tlhc_HitAtBandHeader = System::Int8(0x8);
static const System::Int8 tlhc_HitAtButton = System::Int8(0x9);
static const System::Int8 tlhc_HitAtCheckButton = System::Int8(0xa);
static const System::Int8 tlhc_HitAtColumn = System::Int8(0xb);
static const System::Int8 tlhc_HitAtColumnCustomizing = System::Int8(0xc);
static const System::Int8 tlhc_HitAtColumnHeader = System::Int8(0xd);
static const System::Int8 tlhc_HitAtFooter = System::Int8(0xe);
static const System::Int8 tlhc_HitAtFooterItem = System::Int8(0xf);
static const System::Int8 tlhc_HitAtGroupFooter = System::Int8(0x10);
static const System::Int8 tlhc_HitAtGroupFooterItem = System::Int8(0x11);
static const System::Int8 tlhc_HitAtImage = System::Int8(0x12);
static const System::Int8 tlhc_HitAtIndent = System::Int8(0x13);
static const System::Int8 tlhc_HitAtIndicator = System::Int8(0x14);
static const System::Int8 tlhc_HitAtNode = System::Int8(0x15);
static const System::Int8 tlhc_HitAtNodePreview = System::Int8(0x16);
static const System::Int8 tlhc_HitAtSeparator = System::Int8(0x17);
static const System::Int8 tlhc_HitAtSizingHorz = System::Int8(0x18);
static const System::Int8 tlhc_HitAtSizingVert = System::Int8(0x19);
static const System::Int8 tlhc_HitAtStateImage = System::Int8(0x1a);
static const System::Int8 tlhc_HitAtNavigator = System::Int8(0x1b);
static const System::Int8 tlesNone = System::Int8(0x0);
static const System::Int8 tlesChanged = System::Int8(0x1);
static const System::Int8 tlesSelection = System::Int8(0x2);
static const System::Int8 cxtlHitDelta = System::Int8(0x3);
static const System::Int8 cxtlScrollDelta = System::Int8(0xa);
static const System::Int8 cxtlSizingMarkWidth = System::Int8(0x1);
static const System::Int8 cxtlEditCell = System::Int8(0x1);
static const System::Int8 cxtlPreviewCell = System::Int8(0x2);
static const System::Int8 cxtlBandPartCell = System::Int8(0x3);
static const System::Int8 cxtlColumnHeaderCell = System::Int8(0x4);
static const System::Int8 cxtlBandHeaderCell = System::Int8(0x5);
static const System::Int8 cxtlIndentCell = System::Int8(0x6);
static const System::Int8 cxtlIndicatorCell = System::Int8(0x7);
static const System::Int8 cxtlBackgroundCell = System::Int8(0x8);
static const System::Int8 cxtlFooterCell = System::Int8(0x9);
static const System::Int8 tlcmNone = System::Int8(0x0);
static const System::Int8 tlcmSum = System::Int8(0x1);
static const System::Int8 tlcmMin = System::Int8(0x2);
static const System::Int8 tlcmMax = System::Int8(0x3);
static const System::Int8 tlcmCount = System::Int8(0x4);
static const System::Int8 tlcmAverage = System::Int8(0x5);
static const System::Int8 tlcmAllNodes = System::Int8(0x6);
static const System::Int8 tlcmSortAscending = System::Int8(0x14);
static const System::Int8 tlcmSortDescending = System::Int8(0x15);
static const System::Int8 tlcmClearSorting = System::Int8(0x16);
static const System::Int8 tlcmFooter = System::Int8(0x17);
static const System::Int8 tlcmGroupFootersInvisible = System::Int8(0x18);
static const System::Int8 tlcmGroupFootersVisibleWhenExpanded = System::Int8(0x19);
static const System::Int8 tlcmGroupFootersAlwaysVisible = System::Int8(0x1a);
static const System::Int8 tlcmRemoveThisColumn = System::Int8(0x1b);
static const System::Int8 tlcmFieldChooser = System::Int8(0x1c);
static const System::Int8 tlcmHorzAlignmentLeft = System::Int8(0x1d);
static const System::Int8 tlcmHorzAlignmentRight = System::Int8(0x1e);
static const System::Int8 tlcmHorzAlignmentCenter = System::Int8(0x1f);
static const System::Int8 tlcmVertAlignmentTop = System::Int8(0x20);
static const System::Int8 tlcmVertAlignmentBottom = System::Int8(0x21);
static const System::Int8 tlcmVertAlignmentCenter = System::Int8(0x22);
static const System::Int8 tlcmBestFit = System::Int8(0x23);
static const System::Int8 tlcmBestFitAllColumns = System::Int8(0x24);
static const System::Word tlcmUser = System::Word(0x40c);
static const System::Int8 cvis_ViewInfoCalculate = System::Int8(0x4);
static const System::WideChar cxColumnTextSeparator = (System::WideChar)(0x9);
static const System::Int8 cxTreeListScrollWidthDragInterval = System::Int8(0x32);
static const System::Int8 cxTreeListIndentOffsetSize = System::Int8(0x6);
static const System::Int8 cxTreeListEditCellHeightOffset = System::Int8(0x2);
extern PACKAGE System::Types::TPoint cxTreeListDragDropTextAreaOffset;
extern PACKAGE TcxTreeListCustomBuiltInMenuClass cxTreeListBuiltInMenuClass;
extern PACKAGE void __fastcall (__closure *DesignerNavigatorProc)(System::TObject* AListener, bool AddListener);
extern PACKAGE int __fastcall cxCompareNodesByLevel(TcxTreeListNode* ANode1, TcxTreeListNode* ANode2);
extern PACKAGE void __fastcall cxTreeListError(const System::UnicodeString Description);
}	/* namespace Cxtl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTL)
using namespace Cxtl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtlHPP
