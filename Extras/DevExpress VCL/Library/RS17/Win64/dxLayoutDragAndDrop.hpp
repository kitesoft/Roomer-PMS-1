// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutDragAndDrop.pas' rev: 24.00 (Win64)

#ifndef DxlayoutdraganddropHPP
#define DxlayoutdraganddropHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxLayoutControl.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutdraganddrop
{
//-- type declarations -------------------------------------------------------
enum TdxLayoutDragSource : unsigned char { dsControl, dsCustomizeFormAvailableItems, dsCustomizeFormTreeViewItems };

class DELPHICLASS TdxLayoutCustomDragAndDropObject;
class PASCALIMPLEMENTATION TdxLayoutCustomDragAndDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	Dxlayoutcontainer::TdxLayoutContainer* FContainer;
	Dxlayoutcontainer::TdxCustomLayoutItem* FSourceItem;
	System::Types::TPoint FStartDragPoint;
	
protected:
	void __fastcall Modified(void);
	__property Dxlayoutcontainer::TdxLayoutContainer* Container = {read=FContainer};
	
public:
	__fastcall virtual TdxLayoutCustomDragAndDropObject(Cxcontrols::TcxControl* AControl);
	virtual void __fastcall Init(TdxLayoutDragSource ASource, Dxlayoutcontainer::TdxCustomLayoutItem* ASourceItem, const System::Types::TPoint P);
	__property Dxlayoutcontainer::TdxCustomLayoutItem* SourceItem = {read=FSourceItem, write=FSourceItem};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutCustomDragAndDropObject(void) { }
	
};


class DELPHICLASS TdxLayoutDragAndDropObject;
class DELPHICLASS TdxLayoutCustomDragAndDropController;
class PASCALIMPLEMENTATION TdxLayoutDragAndDropObject : public TdxLayoutCustomDragAndDropObject
{
	typedef TdxLayoutCustomDragAndDropObject inherited;
	
private:
	TdxLayoutCustomDragAndDropController* FController;
	TdxLayoutDragSource FSource;
	System::Types::TRect FSourceItemBounds;
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetDestinationItem(void);
	
protected:
	virtual TdxLayoutCustomDragAndDropController* __fastcall CreateController(void);
	virtual void __fastcall DirtyChanged(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	__property TdxLayoutCustomDragAndDropController* Controller = {read=FController};
	__property TdxLayoutDragSource Source = {read=FSource, write=FSource, nodefault};
	__property System::Types::TRect SourceItemBounds = {read=FSourceItemBounds};
	
public:
	__fastcall virtual TdxLayoutDragAndDropObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TdxLayoutDragAndDropObject(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual void __fastcall Init(TdxLayoutDragSource ASource, Dxlayoutcontainer::TdxCustomLayoutItem* ASourceItem, const System::Types::TPoint P);
	bool __fastcall CanDrop(void);
	__property Dxlayoutcontainer::TdxCustomLayoutItem* DestinationItem = {read=GetDestinationItem};
};


class DELPHICLASS TdxLayoutCustomSizingDragAndDropObject;
class PASCALIMPLEMENTATION TdxLayoutCustomSizingDragAndDropObject : public TdxLayoutCustomDragAndDropObject
{
	typedef TdxLayoutCustomDragAndDropObject inherited;
	
protected:
	virtual void __fastcall RestoreSize(void);
	
public:
	virtual void __fastcall EndDragAndDrop(bool Accepted);
public:
	/* TdxLayoutCustomDragAndDropObject.Create */ inline __fastcall virtual TdxLayoutCustomSizingDragAndDropObject(Cxcontrols::TcxControl* AControl) : TdxLayoutCustomDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutCustomSizingDragAndDropObject(void) { }
	
};


class DELPHICLASS TdxLayoutSizingDragAndDropObject;
class PASCALIMPLEMENTATION TdxLayoutSizingDragAndDropObject : public TdxLayoutCustomSizingDragAndDropObject
{
	typedef TdxLayoutCustomSizingDragAndDropObject inherited;
	
private:
	System::Types::TRect FOriginalBounds;
	System::Types::TSize FOriginalSize;
	int FMarkerIndex;
	
protected:
	virtual void __fastcall RestoreSize(void);
	__property int MarkerIndex = {read=FMarkerIndex, nodefault};
	
public:
	__fastcall virtual TdxLayoutSizingDragAndDropObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TdxLayoutSizingDragAndDropObject(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall Init(TdxLayoutDragSource ASource, Dxlayoutcontainer::TdxCustomLayoutItem* ASourceItem, const System::Types::TPoint P);
};


enum TdxLayoutSizingStrategy : unsigned char { lssLeft, lssRight, lssClient, lssNone };

class DELPHICLASS TdxLayoutSplitterDragAndDropObject;
class PASCALIMPLEMENTATION TdxLayoutSplitterDragAndDropObject : public TdxLayoutCustomSizingDragAndDropObject
{
	typedef TdxLayoutCustomSizingDragAndDropObject inherited;
	
private:
	typedef System::DynamicArray<System::Types::TPoint> _TdxLayoutSplitterDragAndDropObject__1;
	
	
private:
	Dxlayoutcontainer::TdxLayoutGroup* FParentItem;
	Dxlayoutcontainer::TdxCustomLayoutItem* FLeftItem;
	Dxlayoutcontainer::TdxCustomLayoutItem* FRightItem;
	_TdxLayoutSplitterDragAndDropObject__1 FOriginalSizes;
	TdxLayoutSizingStrategy FSizingStrategy;
	int FLeftItemSize;
	int FRightItemSize;
	System::Types::TPoint FPrevPoint;
	
protected:
	virtual void __fastcall RestoreSize(void);
	virtual Dxlayoutcontainer::TdxLayoutAlignHorz __fastcall GetWorkAlign(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemMinSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetSignificantValue(const System::Types::TPoint P) = 0 ;
	virtual void __fastcall SetItemSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo, int ASize) = 0 ;
	
public:
	virtual void __fastcall DragAndDrop(const System::Types::TPoint P, bool &Accepted);
	virtual void __fastcall Init(TdxLayoutDragSource ASource, Dxlayoutcontainer::TdxCustomLayoutItem* ASourceItem, const System::Types::TPoint P);
public:
	/* TdxLayoutCustomDragAndDropObject.Create */ inline __fastcall virtual TdxLayoutSplitterDragAndDropObject(Cxcontrols::TcxControl* AControl) : TdxLayoutCustomSizingDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutSplitterDragAndDropObject(void) { }
	
};


class DELPHICLASS TdxLayoutHSplitterDragAndDropObject;
class PASCALIMPLEMENTATION TdxLayoutHSplitterDragAndDropObject : public TdxLayoutSplitterDragAndDropObject
{
	typedef TdxLayoutSplitterDragAndDropObject inherited;
	
protected:
	virtual Dxlayoutcontainer::TdxLayoutAlignHorz __fastcall GetWorkAlign(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemMinSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetSignificantValue(const System::Types::TPoint P);
	virtual void __fastcall SetItemSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo, int ASize);
public:
	/* TdxLayoutCustomDragAndDropObject.Create */ inline __fastcall virtual TdxLayoutHSplitterDragAndDropObject(Cxcontrols::TcxControl* AControl) : TdxLayoutSplitterDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutHSplitterDragAndDropObject(void) { }
	
};


class DELPHICLASS TdxLayoutVSplitterDragAndDropObject;
class PASCALIMPLEMENTATION TdxLayoutVSplitterDragAndDropObject : public TdxLayoutSplitterDragAndDropObject
{
	typedef TdxLayoutSplitterDragAndDropObject inherited;
	
protected:
	virtual Dxlayoutcontainer::TdxLayoutAlignHorz __fastcall GetWorkAlign(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemMinSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetSignificantValue(const System::Types::TPoint P);
	virtual void __fastcall SetItemSize(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo, int ASize);
public:
	/* TdxLayoutCustomDragAndDropObject.Create */ inline __fastcall virtual TdxLayoutVSplitterDragAndDropObject(Cxcontrols::TcxControl* AControl) : TdxLayoutSplitterDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutVSplitterDragAndDropObject(void) { }
	
};


class DELPHICLASS TdxLayoutDragAndDropHelper;
class PASCALIMPLEMENTATION TdxLayoutDragAndDropHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxlayoutcontainer::TdxLayoutContainer* FContainer;
	Dxlayoutcontainer::TdxCustomLayoutItem* FDragItem;
	System::Types::TPoint FMouseDownPos;
	void __fastcall BeginDragAndDrop(TdxLayoutDragSource ASource);
	bool __fastcall CanBeginDragAndDrop(int X, int Y);
	Cxcontrols::TcxControl* __fastcall GetControl(void);
	TdxLayoutDragAndDropObject* __fastcall GetDragAndDropObject(void);
	
protected:
	__property Cxcontrols::TcxControl* Control = {read=GetControl};
	__property TdxLayoutDragAndDropObject* DragAndDropObject = {read=GetDragAndDropObject};
	
public:
	__fastcall virtual TdxLayoutDragAndDropHelper(Dxlayoutcontainer::TdxLayoutContainer* AContainer);
	void __fastcall InitializeDragItem(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, int X, int Y);
	void __fastcall Reset(void);
	void __fastcall TryBeginDragAndDrop(int X, int Y, TdxLayoutDragSource ASource);
	__property Dxlayoutcontainer::TdxLayoutContainer* Container = {read=FContainer};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* DragItem = {read=FDragItem};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutDragAndDropHelper(void) { }
	
};


enum TdxLayoutItemInsertionKind : unsigned char { ikNone, ikLeft, ikTop, ikRight, ikBottom, ikInside };

class DELPHICLASS TdxLayoutItemInsertionPoint;
class PASCALIMPLEMENTATION TdxLayoutItemInsertionPoint : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxlayoutcontainer::TdxCustomLayoutItem* FItem;
	bool FIsInternalInsertion;
	
public:
	__fastcall TdxLayoutItemInsertionPoint(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, bool AIsInternalInsertion);
	HIDESBASE bool __fastcall Equals(TdxLayoutItemInsertionPoint* AValue);
	__property Dxlayoutcontainer::TdxCustomLayoutItem* Item = {read=FItem};
	__property bool IsInternalInsertion = {read=FIsInternalInsertion, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemInsertionPoint(void) { }
	
};


class DELPHICLASS TdxLayoutItemInsertionPoints;
class PASCALIMPLEMENTATION TdxLayoutItemInsertionPoints : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxLayoutItemInsertionPoint* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxLayoutItemInsertionPoint* __fastcall GetItem(int Index);
	
public:
	TdxLayoutItemInsertionPoint* __fastcall Find(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	__property TdxLayoutItemInsertionPoint* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxLayoutItemInsertionPoints(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxLayoutItemInsertionPoints(void) { }
	
};


class DELPHICLASS TdxLayoutItemInsertionInfo;
class PASCALIMPLEMENTATION TdxLayoutItemInsertionInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxlayoutcontainer::TdxCustomLayoutItem* FDestinationItem;
	TdxLayoutItemInsertionKind FInsertionKind;
	TdxLayoutItemInsertionPoint* FInsertionPoint;
	
public:
	__fastcall TdxLayoutItemInsertionInfo(Dxlayoutcontainer::TdxCustomLayoutItem* ADestinationItem, TdxLayoutItemInsertionKind AInsertionKind, TdxLayoutItemInsertionPoint* AInsertionPoint)/* overload */;
	HIDESBASE bool __fastcall Equals(TdxLayoutItemInsertionInfo* AValue);
	__property Dxlayoutcontainer::TdxCustomLayoutItem* DestinationItem = {read=FDestinationItem, write=FDestinationItem};
	__property TdxLayoutItemInsertionKind InsertionKind = {read=FInsertionKind, write=FInsertionKind, nodefault};
	__property TdxLayoutItemInsertionPoint* InsertionPoint = {read=FInsertionPoint, write=FInsertionPoint};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemInsertionInfo(void) { }
	
};


class DELPHICLASS TdxLayoutItems;
class PASCALIMPLEMENTATION TdxLayoutItems : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	Dxlayoutcontainer::TdxCustomLayoutItem* operator[](int Index) { return Items[Index]; }
	
private:
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetItem(int Index);
	
public:
	__property Dxlayoutcontainer::TdxCustomLayoutItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxLayoutItems(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxLayoutItems(void) : System::Classes::TList() { }
	
};


enum TdxItemAlignment : unsigned char { iaStart, iaCenter, iaEnd, iaStretch };

class DELPHICLASS TdxLayoutItemInsertionCalculator;
class PASCALIMPLEMENTATION TdxLayoutItemInsertionCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxLayoutCustomDragAndDropController* FController;
	TdxItemAlignment __fastcall GetItemAlignment(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	bool __fastcall GetHorizontal(void);
	
protected:
	__property TdxLayoutCustomDragAndDropController* Controller = {read=FController};
	__property bool Horizontal = {read=GetHorizontal, nodefault};
	
public:
	__fastcall TdxLayoutItemInsertionCalculator(TdxLayoutCustomDragAndDropController* AController);
	void __fastcall ArrangeItems(TdxLayoutItems* AItems);
	void __fastcall CalculateInsertionInfoForEmptyArea(Dxlayoutcontainer::TdxLayoutGroup* AGroup, const System::Types::TRect &ABounds, const System::Types::TPoint P, TdxLayoutItems* AItems, /* out */ TdxLayoutItemInsertionKind &AInsertionKind, /* out */ Dxlayoutcontainer::TdxCustomLayoutItem* &AInsertionPlace);
	TdxLayoutItemInsertionInfo* __fastcall GetInsertionInfo(const System::Types::TPoint P);
	TdxLayoutItemInsertionInfo* __fastcall GetInsertionInfoForEmptyArea(Dxlayoutcontainer::TdxLayoutGroup* AGroup, const System::Types::TPoint P);
	TdxLayoutItemInsertionKind __fastcall GetInsertionKind(Dxlayoutcontainer::TdxLayoutGroup* AGroup, Dxlayoutcontainer::TdxCustomLayoutItem* ADestinationItem, const System::Types::TPoint P);
	TdxLayoutItemInsertionKind __fastcall GetInsertionKindForEmptyArea(const System::Types::TRect &ABounds, const System::Types::TPoint P);
	TdxLayoutItemInsertionPoint* __fastcall GetInsertionPoint(Dxlayoutcontainer::TdxLayoutGroup* AGroup, Dxlayoutcontainer::TdxCustomLayoutItem* ADestinationItem, TdxLayoutItemInsertionKind AInsertionKind, const System::Types::TPoint P);
	TdxLayoutItemInsertionPoint* __fastcall GetInsertionPoints(Dxlayoutcontainer::TdxLayoutGroup* AGroup, Dxlayoutcontainer::TdxCustomLayoutItem* ADestinationItem, TdxLayoutItemInsertionKind AInsertionKind, TdxLayoutItemInsertionPoints* AInsertionPoints);
	System::Types::TRect __fastcall GetInsertionZoneBounds(System::Types::TRect &ABounds, System::Types::TRect &AContentBounds, TdxLayoutItemInsertionKind AInsertionKind)/* overload */;
	System::Types::TRect __fastcall GetInsertionZoneBounds(Dxlayoutcontainer::TdxLayoutGroup* AGroup, Dxlayoutcontainer::TdxCustomLayoutItem* ADestinationItem, TdxLayoutItemInsertionKind AInsertionKind)/* overload */;
	bool __fastcall IsInsertionPoint(Dxlayoutcontrol::TdxLayoutControl* AControl, Dxlayoutcontainer::TdxCustomLayoutItem* AItem, Dxlayoutcontainer::TdxCustomLayoutItem* ADestinationItem, Dxlayoutcontainer::TdxCustomLayoutItem* AOriginalDestinationItem, TdxLayoutItemInsertionKind AInsertionKind);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemInsertionCalculator(void) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutCustomDragAndDropController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxlayoutcontainer::TdxLayoutAreaPart FAreaPart;
	Cxcontrols::TcxDragImage* FDragImage;
	System::Types::TPoint FDragImageOffset;
	System::Types::TPoint FDragImagePoint;
	Dxlayoutcontainer::TdxLayoutContainer* FDestinationContainer;
	Dxlayoutcontainer::TdxLayoutGroup* FDestinationGroup;
	Dxlayoutcontainer::TdxCustomLayoutItem* FDestinationItem;
	Dxlayoutcontainer::TdxCustomLayoutHitTest* FHitTest;
	bool FNeedUpdateDestinationImage;
	TdxLayoutDragAndDropObject* FOwner;
	TdxLayoutDragSource FSource;
	System::Types::TRect FSourceItemBounds;
	Dxlayoutcontainer::TdxLayoutContainer* __fastcall GetContainer(void);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetSourceItem(void);
	void __fastcall SetAreaPart(Dxlayoutcontainer::TdxLayoutAreaPart Value);
	void __fastcall SetDestinationContainer(Dxlayoutcontainer::TdxLayoutContainer* Value);
	void __fastcall SetDestinationGroup(Dxlayoutcontainer::TdxLayoutGroup* Value);
	void __fastcall SetDestinationItem(Dxlayoutcontainer::TdxCustomLayoutItem* Value);
	
protected:
	void __fastcall Changed(void);
	void __fastcall CreateDragImage(void);
	virtual void __fastcall CreateDestinationImage(void);
	virtual void __fastcall DestroyDestinationImage(void);
	virtual void __fastcall DoDrop(Dxlayoutcontainer::TdxLayoutActionType ALayoutAction);
	Dxlayoutcontainer::TdxLayoutContainer* __fastcall FindDestLayoutContainer(const System::Types::TPoint P);
	void __fastcall PaintDragImage(void);
	virtual void __fastcall UpdateDestinationImage(void);
	void __fastcall ResetDragAndDropObjects(void);
	void __fastcall ShowDragImage(void);
	virtual void __fastcall UpdateStates(void);
	__property Dxlayoutcontainer::TdxLayoutAreaPart AreaPart = {read=FAreaPart, write=SetAreaPart, nodefault};
	__property Dxlayoutcontainer::TdxLayoutContainer* Container = {read=GetContainer};
	__property Dxlayoutcontainer::TdxLayoutContainer* DestinationContainer = {read=FDestinationContainer, write=SetDestinationContainer};
	__property Dxlayoutcontainer::TdxLayoutGroup* DestinationGroup = {read=FDestinationGroup, write=SetDestinationGroup};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* DestinationItem = {read=FDestinationItem, write=SetDestinationItem};
	__property TdxLayoutDragAndDropObject* Owner = {read=FOwner};
	__property TdxLayoutDragSource Source = {read=FSource, write=FSource, nodefault};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* SourceItem = {read=GetSourceItem};
	__property System::Types::TRect SourceItemBounds = {read=FSourceItemBounds};
	
public:
	__fastcall virtual TdxLayoutCustomDragAndDropController(TdxLayoutDragAndDropObject* AOwner);
	void __fastcall Calculate(const System::Types::TPoint P, bool &Accepted);
	bool __fastcall CanDrop(void);
	bool __fastcall CanRemove(void);
	void __fastcall Drop(bool Accepted);
	System::Uitypes::TCursor __fastcall GetCursor(bool Accepted);
	void __fastcall Invalidate(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutCustomDragAndDropController(void) { }
	
};


class DELPHICLASS TdxLayoutDragAndDropController;
class PASCALIMPLEMENTATION TdxLayoutDragAndDropController : public TdxLayoutCustomDragAndDropController
{
	typedef TdxLayoutCustomDragAndDropController inherited;
	
private:
	Cxcontrols::TcxDragImage* FDestinationImage;
	int __fastcall GetDestinationPosition(void);
	
protected:
	virtual void __fastcall CreateDestinationImage(void);
	virtual void __fastcall DestroyDestinationImage(void);
	virtual void __fastcall DoDrop(Dxlayoutcontainer::TdxLayoutActionType ALayoutAction);
	virtual void __fastcall PaintDestinationImage(void);
	virtual void __fastcall UpdateDestinationImage(void);
public:
	/* TdxLayoutCustomDragAndDropController.Create */ inline __fastcall virtual TdxLayoutDragAndDropController(TdxLayoutDragAndDropObject* AOwner) : TdxLayoutCustomDragAndDropController(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutDragAndDropController(void) { }
	
};


class DELPHICLASS TdxLayoutItemDropPlaceWindow;
class PASCALIMPLEMENTATION TdxLayoutItemDropPlaceWindow : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FInControl;
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	void __fastcall SetInControl(const bool Value);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	__property bool InControl = {read=FInControl, write=SetInControl, nodefault};
public:
	/* TCustomControl.Create */ inline __fastcall virtual TdxLayoutItemDropPlaceWindow(System::Classes::TComponent* AOwner) : Vcl::Controls::TCustomControl(AOwner) { }
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TdxLayoutItemDropPlaceWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLayoutItemDropPlaceWindow(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TdxLayoutItemDropPlaceWindows;
class PASCALIMPLEMENTATION TdxLayoutItemDropPlaceWindows : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxLayoutItemDropPlaceWindow* operator[](int Index) { return Items[Index]; }
	
private:
	bool FVisible;
	HIDESBASE TdxLayoutItemDropPlaceWindow* __fastcall GetItem(int Index);
	void __fastcall SetVisible(const bool Value);
	
public:
	HIDESBASE void __fastcall Add(const System::Types::TRect &R);
	virtual void __fastcall Clear(void);
	__property TdxLayoutItemDropPlaceWindow* Items[int Index] = {read=GetItem/*, default*/};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxLayoutItemDropPlaceWindows(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxLayoutItemDropPlaceWindows(void) { }
	
};


class DELPHICLASS TdxLayoutDragAndDropControllerEx;
class PASCALIMPLEMENTATION TdxLayoutDragAndDropControllerEx : public TdxLayoutCustomDragAndDropController
{
	typedef TdxLayoutCustomDragAndDropController inherited;
	
private:
	TdxLayoutItemDropPlaceWindows* FDropPlaces;
	
protected:
	virtual void __fastcall CreateDestinationImage(void);
	virtual void __fastcall DestroyDestinationImage(void);
	virtual void __fastcall DoDrop(Dxlayoutcontainer::TdxLayoutActionType ALayoutAction);
	System::Types::TRect __fastcall GetRect(const System::Types::TRect &ABounds);
	System::Types::TRect __fastcall GetScreenRect(const System::Types::TRect &R);
	virtual void __fastcall UpdateDestinationImage(void);
	__property TdxLayoutItemDropPlaceWindows* DropPlaces = {read=FDropPlaces};
public:
	/* TdxLayoutCustomDragAndDropController.Create */ inline __fastcall virtual TdxLayoutDragAndDropControllerEx(TdxLayoutDragAndDropObject* AOwner) : TdxLayoutCustomDragAndDropController(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutDragAndDropControllerEx(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxLayoutDragAndDropObject* __fastcall dxLayoutDragAndDropObject(void);
extern PACKAGE TdxLayoutSizingDragAndDropObject* __fastcall dxLayoutSizingDragAndDropObject(void);
}	/* namespace Dxlayoutdraganddrop */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTDRAGANDDROP)
using namespace Dxlayoutdraganddrop;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutdraganddropHPP
