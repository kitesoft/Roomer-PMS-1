// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomTree.pas' rev: 24.00 (Win64)

#ifndef DxcustomtreeHPP
#define DxcustomtreeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcustomtree
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxTreeCustomNodeClass;

enum TdxTreeNodeNotification : unsigned char { tnStructure, tnData };

typedef System::Set<TdxTreeNodeNotification, TdxTreeNodeNotification::tnStructure, TdxTreeNodeNotification::tnData>  TdxTreeNodeNotifications;

__interface IdxTreeOwner;
typedef System::DelphiInterface<IdxTreeOwner> _di_IdxTreeOwner;
class DELPHICLASS TdxTreeCustomNode;
__interface  INTERFACE_UUID("{E5BD359F-E1D0-4ABC-9D9D-45A6516F2F8B}") IdxTreeOwner  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanCollapse(TdxTreeCustomNode* ASender) = 0 ;
	virtual bool __fastcall CanExpand(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall Collapsed(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall Expanded(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall LoadChildren(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall BeforeDelete(TdxTreeCustomNode* ASender) = 0 ;
	virtual void __fastcall DeleteNode(TdxTreeCustomNode* ASender) = 0 ;
	virtual System::Classes::TPersistent* __fastcall GetOwner(void) = 0 ;
	virtual TdxTreeCustomNodeClass __fastcall GetNodeClass(TdxTreeCustomNode* ARelativeNode) = 0 ;
	virtual void __fastcall TreeNotification(TdxTreeCustomNode* ASender, TdxTreeNodeNotifications ANotification) = 0 ;
	virtual void __fastcall BeginUpdate(void) = 0 ;
	virtual void __fastcall EndUpdate(void) = 0 ;
};

enum TdxTreeNodeAttachMode : unsigned char { namAdd, namAddFirst, namAddChild, namAddChildFirst, namInsert };

enum TdxTreeNodeAddMode : unsigned char { amAdd, amAddFirst, amInsert };

enum TdxTreeNodeState : unsigned char { nsCollapsed, nsHasChildren, nsValidIndexes, nsDeleting, nsInternalDelete };

typedef System::Set<TdxTreeNodeState, TdxTreeNodeState::nsCollapsed, TdxTreeNodeState::nsInternalDelete>  TdxTreeNodeStates;

typedef int __fastcall (*TdxCustomTreeNodeCompareProc)(TdxTreeCustomNode* ANode1, TdxTreeCustomNode* ANode2);

class PASCALIMPLEMENTATION TdxTreeCustomNode : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxTreeCustomNode* operator[](int Index) { return Items[Index]; }
	
private:
	int FCount;
	void *FData;
	TdxTreeCustomNode* FFirst;
	int FImageIndex;
	int FIndex;
	TdxTreeCustomNode* FLast;
	TdxTreeCustomNode* FNext;
	TdxTreeCustomNode* FParent;
	TdxTreeCustomNode* FPrev;
	TdxTreeNodeStates FState;
	int FStructureID;
	bool __fastcall GetExpanded(void);
	bool __fastcall GetHasChildren(void);
	int __fastcall GetIndex(void);
	TdxTreeCustomNode* __fastcall GetItem(int AIndex);
	int __fastcall GetLevel(void);
	System::Classes::TPersistent* __fastcall GetOwner(void);
	TdxTreeCustomNode* __fastcall GetRoot(void);
	void __fastcall SetExpanded(bool AValue);
	void __fastcall SetHasChildren(bool AValue);
	void __fastcall SetImageIndex(int AValue);
	
protected:
	_di_IdxTreeOwner FOwner;
	void __fastcall AdjustIndexes(void);
	void __fastcall ExtractFromParent(void);
	virtual int __fastcall GetImageIndex(void);
	void __fastcall InternalInsert(TdxTreeCustomNode* AValue);
	void __fastcall Notify(TdxTreeNodeNotifications ANotification);
	void __fastcall PopulateItems(System::Classes::TList* AList);
	void __fastcall SetFirst(TdxTreeCustomNode* AValue);
	void __fastcall SetLast(TdxTreeCustomNode* AValue);
	void __fastcall SetNodeParent(TdxTreeCustomNode* ANewNode, TdxTreeCustomNode* ANewParent, TdxTreeNodeAddMode AMode);
	void __fastcall SetParentFor(TdxTreeCustomNode* AValue, bool AValidateIndexes = true);
	void __fastcall UpdateItems(System::Classes::TList* AList);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	__property TdxTreeNodeStates State = {read=FState, write=FState, nodefault};
	__property int StructureID = {read=FStructureID, write=FStructureID, nodefault};
	
public:
	__fastcall virtual TdxTreeCustomNode(_di_IdxTreeOwner AOwner);
	__fastcall virtual ~TdxTreeCustomNode(void);
	TdxTreeCustomNode* __fastcall AddChild(void);
	TdxTreeCustomNode* __fastcall AddChildFirst(void);
	TdxTreeCustomNode* __fastcall AddNode(TdxTreeCustomNode* ANode, TdxTreeCustomNode* ARelative, void * AData, TdxTreeNodeAttachMode AttachMode);
	void __fastcall CustomSort(TdxCustomTreeNodeCompareProc ACompareProc, bool ARecurse = false);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DeleteChildren(void);
	bool __fastcall HasAsParent(TdxTreeCustomNode* ANode);
	bool __fastcall IsRoot(void);
	virtual void __fastcall LoadChildren(void);
	virtual void __fastcall MoveTo(TdxTreeCustomNode* ADestNode, TdxTreeNodeAttachMode AMode);
	__property int Count = {read=FCount, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property TdxTreeCustomNode* First = {read=FFirst};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property bool HasChildren = {read=GetHasChildren, write=SetHasChildren, nodefault};
	__property int ImageIndex = {read=GetImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property TdxTreeCustomNode* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxTreeCustomNode* Last = {read=FLast};
	__property int Level = {read=GetLevel, nodefault};
	__property TdxTreeCustomNode* Next = {read=FNext};
	__property System::Classes::TPersistent* Owner = {read=GetOwner};
	__property TdxTreeCustomNode* Parent = {read=FParent};
	__property TdxTreeCustomNode* Prev = {read=FPrev};
	__property TdxTreeCustomNode* Root = {read=GetRoot};
};


typedef bool __fastcall (__closure *TdxTreeForEachNodeProc)(TdxTreeCustomNode* ANode, void * AData);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall dxTreeForEach(TdxTreeCustomNode* ARoot, TdxTreeForEachNodeProc AProc, void * AData);
}	/* namespace Dxcustomtree */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMTREE)
using namespace Dxcustomtree;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomtreeHPP
