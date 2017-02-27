// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomTileControl.pas' rev: 24.00 (Win32)

#ifndef DxcustomtilecontrolHPP
#define DxcustomtilecontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <cxLibraryConsts.hpp>	// Pascal unit
#include <dxHooks.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcustomtilecontrol
{
//-- type declarations -------------------------------------------------------
enum TdxTileControlAutoScrollSide : unsigned char { sLeft, sRight, sTop, sBottom };

typedef System::Set<TdxTileControlAutoScrollSide, TdxTileControlAutoScrollSide::sLeft, TdxTileControlAutoScrollSide::sBottom>  TdxTileControlAutoScrollSides;

enum TdxTileControlRectIntersectedBounds : unsigned char { rcNone, rcFull, rcFullLeft, rcFullTop, rcFullRight, rcFullBottom, rcLeft, rcRight };

enum TdxTileControlItemCheckMode : unsigned char { tcicmNone, tcicmMultiple };

enum TdxTileControlGroupLayout : unsigned char { glHorizontal, glVertical };

enum TdxTileControlScrollMode : unsigned char { smDefault, smScrollbars, smScrollButtons };

enum TdxTileControlVirtualGroupState : unsigned char { vgsNoVisible, vgsVisible };

enum TdxTileControlDesignTimeWhatSelected : unsigned char { tcdtwsNone, tcdtwsItem, tcdtwsItems, tcdtwsGroup, tcdtwsGroups, tcdtwsMixed };

class DELPHICLASS TdxLayoutItemPosition;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemPosition : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FRow;
	int FColumn;
	
protected:
	void __fastcall Assign(TdxLayoutItemPosition* ASource);
	bool __fastcall IsEqual(TdxLayoutItemPosition* APosition);
	
public:
	__property int Row = {read=FRow, write=FRow, nodefault};
	__property int Column = {read=FColumn, write=FColumn, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxLayoutItemPosition(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemPosition(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCells;
class DELPHICLASS TdxTileControlCustomCellViewInfo;
class DELPHICLASS TdxTileControlHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCells : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxTileControlCustomCellViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxTileControlCustomCellViewInfo* __fastcall GetItem(int AIndex);
	
protected:
	void __fastcall DrawWithoutClipping(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	bool __fastcall CalculateHitTest(TdxTileControlHitTest* AHitTest);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall RefreshState(void);
	__property TdxTileControlCustomCellViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxTileControlCells(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxTileControlCells(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCustomViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::Types::TRect FBounds;
	
protected:
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest) = 0 ;
	virtual bool __fastcall IsEqual(TdxTileControlCustomViewInfo* ACompare);
	
public:
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual void __fastcall RefreshState(void);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
public:
	/* TObject.Create */ inline __fastcall TdxTileControlCustomViewInfo(void) : Dxcoreclasses::TcxIUnknownObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlCustomViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomCellViewInfo : public TdxTileControlCustomViewInfo
{
	typedef TdxTileControlCustomViewInfo inherited;
	
private:
	bool FCalculated;
	System::Types::TRect FClipRect;
	System::Types::TRect FVisibleBounds;
	bool FVisible;
	void __fastcall SetCalculate(bool AValue);
	
protected:
	virtual void __fastcall CalculateClipping(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	virtual void __fastcall Offset(const int DX, const int DY);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	void __fastcall Calculate(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Recalculate(void);
	__property bool Calculated = {read=FCalculated, write=SetCalculate, nodefault};
	__property System::Types::TRect ClipRect = {read=FClipRect};
	__property bool Visible = {read=FVisible, nodefault};
	__property System::Types::TRect VisibleBounds = {read=FVisibleBounds, write=FVisibleBounds};
public:
	/* TObject.Create */ inline __fastcall TdxTileControlCustomCellViewInfo(void) : TdxTileControlCustomViewInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlCustomCellViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlAnimatedDragAndDropCustomCellViewInfo;
class DELPHICLASS TdxCustomTileControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlAnimatedDragAndDropCustomCellViewInfo : public TdxTileControlCustomCellViewInfo
{
	typedef TdxTileControlCustomCellViewInfo inherited;
	
protected:
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ADrawRect);
	virtual System::Types::TRect __fastcall GetBaseDrawBounds(void);
	System::Types::TRect __fastcall GetDrawBounds(bool AAbsolutePosition = false);
	virtual bool __fastcall GetIsAnimatedOnDragDrop(void);
	virtual TdxCustomTileControl* __fastcall GetTileControl(void);
	__property bool IsAnimatedOnDragDrop = {read=GetIsAnimatedOnDragDrop, nodefault};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
public:
	/* TObject.Create */ inline __fastcall TdxTileControlAnimatedDragAndDropCustomCellViewInfo(void) : TdxTileControlCustomCellViewInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlAnimatedDragAndDropCustomCellViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlItemViewInfo;
class DELPHICLASS TdxTileControlItem;
class DELPHICLASS TdxTileControlCustomItemViewData;
class DELPHICLASS TdxTileControlController;
class DELPHICLASS TdxTileControlGroup;
class DELPHICLASS TdxTileControlPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemViewInfo : public TdxTileControlAnimatedDragAndDropCustomCellViewInfo
{
	typedef TdxTileControlAnimatedDragAndDropCustomCellViewInfo inherited;
	
private:
	Dxanimation::TdxImageAnimationTransition* FAnimation;
	Cxgraphics::TcxBitmap* FCache;
	int FHottrackValue;
	int FInflateDelta;
	bool FIsDirty;
	TdxTileControlItem* FItem;
	TdxLayoutItemPosition* FPosition;
	TdxTileControlCustomItemViewData* FViewData;
	TdxTileControlController* __fastcall GetController(void);
	System::Types::TRect __fastcall GetDragItemPlaceBounds(void);
	bool __fastcall GetFocused(void);
	TdxTileControlGroup* __fastcall GetGroup(void);
	bool __fastcall GetHottracked(void);
	bool __fastcall GetNeedDrawDragItemPlace(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	bool __fastcall GetSelected(void);
	TdxTileControlCustomItemViewData* __fastcall GetViewData(void);
	void __fastcall SetHottrackValue(int AValue);
	void __fastcall SetInflateDelta(int AValue);
	void __fastcall SetIsDirty(bool AValue);
	void __fastcall SetViewData(TdxTileControlCustomItemViewData* AValue);
	
protected:
	virtual void __fastcall CalculateBounds(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DirtyChanged(void);
	virtual void __fastcall DrawChecked(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ADrawRect);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawHottrackRect(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawSelection(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetActualVisualBounds(void);
	virtual System::Types::TRect __fastcall GetBaseDrawBounds(void);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual TdxCustomTileControl* __fastcall GetTileControl(void);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	virtual void __fastcall ValidateCache(const System::Types::TRect &ADrawRect);
	virtual void __fastcall ValidateImage(void);
	__property Dxanimation::TdxImageAnimationTransition* Animation = {read=FAnimation};
	__property Cxgraphics::TcxBitmap* Cache = {read=FCache};
	__property TdxTileControlController* Controller = {read=GetController};
	__property System::Types::TRect DragItemPlaceBounds = {read=GetDragItemPlaceBounds};
	__property int HottrackValue = {read=FHottrackValue, write=SetHottrackValue, nodefault};
	__property int InflateDelta = {read=FInflateDelta, write=SetInflateDelta, nodefault};
	__property bool IsDirty = {read=FIsDirty, write=SetIsDirty, nodefault};
	__property bool NeedDrawDragItemPlace = {read=GetNeedDrawDragItemPlace, nodefault};
	
public:
	__fastcall virtual TdxTileControlItemViewInfo(TdxTileControlItem* AOwner);
	__fastcall virtual ~TdxTileControlItemViewInfo(void);
	__property bool Focused = {read=GetFocused, nodefault};
	__property TdxTileControlGroup* Group = {read=GetGroup};
	__property bool Hottracked = {read=GetHottracked, nodefault};
	__property TdxTileControlItem* Item = {read=FItem};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property TdxLayoutItemPosition* Position = {read=FPosition, write=FPosition};
	__property bool Selected = {read=GetSelected, nodefault};
	__property TdxTileControlCustomItemViewData* ViewData = {read=GetViewData, write=SetViewData};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCustomGroupViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomGroupViewInfo : public TdxTileControlCustomCellViewInfo
{
	typedef TdxTileControlCustomCellViewInfo inherited;
	
private:
	TdxTileControlGroup* FGroup;
	TdxCustomTileControl* __fastcall GetTileControl(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	
protected:
	virtual void __fastcall CalculateBounds(void);
	virtual void __fastcall CalculateSize(int &AWidth, int &AHeight);
	virtual int __fastcall GetLeftPos(void);
	virtual int __fastcall GetTopPos(void);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	virtual void __fastcall Offset(const int DX, const int DY);
	
public:
	__fastcall virtual TdxTileControlCustomGroupViewInfo(TdxTileControlGroup* AOwner);
	__property TdxTileControlGroup* Group = {read=FGroup};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlCustomGroupViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlVirtualGroupViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlVirtualGroupViewInfo : public TdxTileControlCustomGroupViewInfo
{
	typedef TdxTileControlCustomGroupViewInfo inherited;
	
private:
	System::Types::TRect FAreaBounds;
	int FBasisWidth;
	bool FSizeMustFromDragItem;
	TdxTileControlVirtualGroupState FState;
	void __fastcall SetState(const TdxTileControlVirtualGroupState AValue);
	void __fastcall CalculateSizeAtHorizontalGroupLayout(int &AWidth, int &AHeight);
	void __fastcall CalculateSizeAtVerticalGroupLayout(int &AWidth, int &AHeight);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	
protected:
	virtual void __fastcall CalculateAreaBounds(void);
	virtual void __fastcall CalculateSize(int &AWidth, int &AHeight);
	virtual void __fastcall DoCalculate(void);
	void __fastcall ExpandBounds(const int DW, const int DH);
	virtual int __fastcall GetLeftPos(void);
	virtual int __fastcall GetTopPos(void);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Invalidate(void);
	void __fastcall RecalculateAreaBounds(void);
	__property System::Types::TRect AreaBounds = {read=FAreaBounds, write=FAreaBounds};
	__property int BasisWidth = {read=FBasisWidth, nodefault};
	__property TdxTileControlVirtualGroupState State = {read=FState, write=SetState, nodefault};
	__property bool SizeMustFromDragItem = {read=FSizeMustFromDragItem, write=FSizeMustFromDragItem, nodefault};
public:
	/* TdxTileControlCustomGroupViewInfo.Create */ inline __fastcall virtual TdxTileControlVirtualGroupViewInfo(TdxTileControlGroup* AOwner) : TdxTileControlCustomGroupViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlVirtualGroupViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlGroupViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlGroupViewInfo : public TdxTileControlCustomGroupViewInfo
{
	typedef TdxTileControlCustomGroupViewInfo inherited;
	
private:
	int FColumnCount;
	System::Types::TRect FExpandedBounds;
	System::Types::TRect FMaximizedAreaBounds;
	System::Types::TRect FNewGroupAreaBounds;
	int FRowCount;
	bool __fastcall GetSelected(void);
	void __fastcall CalculateRowAndColumnLargeItem(TdxTileControlItem* AItem, TdxTileControlItem* AItemPrev, int &ARow, int &AColumn);
	void __fastcall CalculateRowAndColumnNoLargeItem(TdxTileControlItem* AItem, TdxTileControlItem* AItemPrev, int &ARow, int &AColumn);
	void __fastcall DoCorrectColumnAndRow(int &AColumn, int &ARow, const int AItemRowCount);
	void __fastcall DoCorrectColumnAndRowIfOccupiedForNoLargeItem(TdxTileControlItem* ACurrentItem, int &AColumn, int &ARow);
	void __fastcall DoCorrectRowIfOccupiedForLargeItem(TdxTileControlItem* ACurrentItem, const int AColumn, int &ARow);
	void __fastcall ExpandBoundsToBottomControl(System::Types::TRect &ABounds);
	void __fastcall ExpandBoundsToLeftControl(System::Types::TRect &ABounds);
	void __fastcall ExpandBoundsToRightControl(System::Types::TRect &ABounds);
	void __fastcall ExpandBoundsToTopControl(System::Types::TRect &ABounds);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	int __fastcall GetTilesMaximizedAreaHeght(void);
	int __fastcall GetTilesMaximizedAreaWidth(void);
	bool __fastcall IsItemOccupyPosition(TdxTileControlItem* AItem, TdxLayoutItemPosition* APosition, int &AOccupiedRow);
	bool __fastcall IsOccupiedByPriorItems(TdxLayoutItemPosition* APosition, TdxTileControlItem* ACurrentItem);
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	
protected:
	virtual void __fastcall CalculateExpandedBounds(void);
	virtual void __fastcall CalculateMaximizedAreaBounds(void);
	void __fastcall CalculateDimensionAndItemsPositions(void);
	void __fastcall CalculateItemPosition(TdxTileControlItem* AItem, TdxTileControlItem* AItemPrev);
	virtual void __fastcall CalculateSize(int &AWidth, int &AHeight);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual int __fastcall GetLeftPos(void);
	virtual int __fastcall GetTopPos(void);
	int __fastcall GetZIndex(TdxLayoutItemPosition* APosition);
	void __fastcall InitializeNextPosition(TdxLayoutItemPosition* APosition, TdxLayoutItemPosition* &FNextPosition, const int AItemRowCount);
	virtual void __fastcall Scroll(const int DX, const int DY);
	
public:
	System::Types::TRect __fastcall GetContentRect(void);
	__property int ColumnCount = {read=FColumnCount, nodefault};
	__property System::Types::TRect ExpandedBounds = {read=FExpandedBounds};
	__property System::Types::TRect MaximizedAreaBounds = {read=FMaximizedAreaBounds};
	__property int RowCount = {read=FRowCount, nodefault};
	__property bool Selected = {read=GetSelected, nodefault};
public:
	/* TdxTileControlCustomGroupViewInfo.Create */ inline __fastcall virtual TdxTileControlGroupViewInfo(TdxTileControlGroup* AOwner) : TdxTileControlCustomGroupViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlGroupViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlTitleViewInfo;
class DELPHICLASS TdxTileControlTitle;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlTitleViewInfo : public TdxTileControlCustomCellViewInfo
{
	typedef TdxTileControlCustomCellViewInfo inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	System::Types::TRect FGlyphBounds;
	System::Types::TRect FTextBounds;
	int FTextOffset;
	TdxTileControlTitle* FTitle;
	TdxTileControlPainter* __fastcall GetPainter(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	
protected:
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual int __fastcall GetLeftOffset(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual int __fastcall GetTextLeftOffset(void);
	int __fastcall GetTextOutFlags(void);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	System::Types::TRect __fastcall MeasureTextBounds(const System::Types::TRect &AVisibleBounds);
	virtual void __fastcall Scroll(const int DX, const int DY);
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	
public:
	__fastcall TdxTileControlTitleViewInfo(void);
	__fastcall virtual ~TdxTileControlTitleViewInfo(void);
	__property Vcl::Graphics::TFont* Font = {read=FFont};
	__property System::Types::TRect GlyphBounds = {read=FGlyphBounds};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, nodefault};
	__property int TextOffset = {read=FTextOffset, nodefault};
	__property TdxTileControlTitle* Title = {read=FTitle};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCustomDesignHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomDesignHelper : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	virtual TdxCustomTileControl* __fastcall GetControl(void);
	
public:
	__fastcall virtual TdxTileControlCustomDesignHelper(TdxCustomTileControl* AControl);
	virtual void __fastcall CreateItemClickHandler(TdxTileControlItem* AItem) = 0 ;
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall Select(System::Classes::TPersistent* AObject, System::Classes::TShiftState AShift) = 0 ;
	virtual void __fastcall SetSelection(System::Classes::TList* AList) = 0 ;
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject) = 0 ;
	__property TdxCustomTileControl* Control = {read=GetControl};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlCustomDesignHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxTileControlCustomDesignHelperClass;

class DELPHICLASS TdxTileControlHintController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlHintController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxTileControlController* FOwner;
	TdxCustomTileControl* __fastcall GetTileControl(void);
	
public:
	__fastcall virtual TdxTileControlHintController(TdxTileControlController* AOwner);
	__property TdxTileControlController* Owner = {read=FOwner};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlHintController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlInflateItemAnimation;
class PASCALIMPLEMENTATION TdxTileControlInflateItemAnimation : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	int FDelta;
	TdxTileControlItem* FItem;
	TdxCustomTileControl* FTileControl;
	
protected:
	virtual void __fastcall DoAnimate(void);
	void __fastcall InflateItem(TdxTileControlItem* AItem, const void * AData);
	
public:
	__fastcall TdxTileControlInflateItemAnimation(TdxCustomTileControl* ATileControl, TdxTileControlItem* AItem, const int ADelta, const int ACount);
	__fastcall virtual ~TdxTileControlInflateItemAnimation(void);
	__property TdxTileControlItem* Item = {read=FItem};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
};


class DELPHICLASS TdxTileControlFramesAnimation;
class PASCALIMPLEMENTATION TdxTileControlFramesAnimation : public Dxanimation::TdxImageAnimationTransition
{
	typedef Dxanimation::TdxImageAnimationTransition inherited;
	
private:
	TdxTileControlCustomItemViewData* FDestViewData;
	TdxTileControlItem* FItem;
	TdxTileControlCustomItemViewData* FSourceViewData;
	
protected:
	virtual void __fastcall InitializeViewData(void);
	__property TdxTileControlCustomItemViewData* DestViewData = {read=FDestViewData};
	__property TdxTileControlCustomItemViewData* SourceViewData = {read=FSourceViewData};
	
public:
	__fastcall virtual TdxTileControlFramesAnimation(TdxTileControlItem* AItem);
	__fastcall virtual ~TdxTileControlFramesAnimation(void);
	__property TdxTileControlItem* Item = {read=FItem};
};


class DELPHICLASS TdxTileControlDragAndDropAnimation;
class DELPHICLASS TdxTileControlDragAndDropChanges;
class PASCALIMPLEMENTATION TdxTileControlDragAndDropAnimation : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	TdxTileControlDragAndDropChanges* FChanges;
	System::Types::TPoint FDragImageOrigin;
	TdxCustomTileControl* __fastcall GetTileControl(void);
	
protected:
	int __fastcall AnimationLength(void);
	virtual void __fastcall DoAnimate(void);
	
public:
	__fastcall TdxTileControlDragAndDropAnimation(TdxTileControlDragAndDropChanges* AChanges);
	__property TdxTileControlDragAndDropChanges* Changes = {read=FChanges};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
public:
	/* TdxAnimationTransition.Destroy */ inline __fastcall virtual ~TdxTileControlDragAndDropAnimation(void) { }
	
};


class DELPHICLASS TdxTileControlHottrackItemAnimation;
class PASCALIMPLEMENTATION TdxTileControlHottrackItemAnimation : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	TdxTileControlItem* FItem;
	bool FShowFrame;
	
protected:
	virtual void __fastcall DoAnimate(void);
	virtual bool __fastcall IsCompatible(Dxanimation::TdxAnimationTransition* AAnimation);
	
public:
	__fastcall TdxTileControlHottrackItemAnimation(TdxTileControlItem* AItem, bool AShowFrame);
	__fastcall virtual ~TdxTileControlHottrackItemAnimation(void);
	__property TdxTileControlItem* Item = {read=FItem};
	__property bool ShowFrame = {read=FShowFrame, nodefault};
};


enum TdxTileControlActionBarsAnimationMode : unsigned char { tcabamShow, tcabamHide };

class DELPHICLASS TdxTileControlActionBarsAnimation;
class DELPHICLASS TdxTileControlCustomActionBar;
class PASCALIMPLEMENTATION TdxTileControlActionBarsAnimation : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	TdxCustomTileControl* FTileControl;
	TdxTileControlActionBarsAnimationMode FMode;
	int FPrevPosition;
	TdxTileControlCustomActionBar* __fastcall GetActionBarTop(void);
	TdxTileControlCustomActionBar* __fastcall GetActionBarBottom(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateActionBarBottomBounds(void);
	virtual System::Types::TRect __fastcall CalculateActionBarTopBounds(void);
	virtual void __fastcall DoAnimate(void);
	virtual bool __fastcall IsCompatible(Dxanimation::TdxAnimationTransition* Animation);
	
public:
	__fastcall virtual TdxTileControlActionBarsAnimation(TdxCustomTileControl* ATileControl, TdxTileControlActionBarsAnimationMode AMode);
	__property TdxTileControlCustomActionBar* ActionBarBottom = {read=GetActionBarBottom};
	__property TdxTileControlCustomActionBar* ActionBarTop = {read=GetActionBarTop};
	__property TdxTileControlActionBarsAnimationMode Mode = {read=FMode, nodefault};
	__property int PrevPosition = {read=FPrevPosition, nodefault};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
public:
	/* TdxAnimationTransition.Destroy */ inline __fastcall virtual ~TdxTileControlActionBarsAnimation(void) { }
	
};


class DELPHICLASS TdxTileControlContentAnimation;
class DELPHICLASS TdxTileControlViewInfo;
class PASCALIMPLEMENTATION TdxTileControlContentAnimation : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	int FLengthX;
	int FLengthY;
	int FPrevPositionX;
	int FPrevPositionY;
	TdxCustomTileControl* FTileControl;
	int __fastcall GetPositionX(void);
	int __fastcall GetPositionY(void);
	TdxTileControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoAnimate(void);
	virtual void __fastcall DoMoveContent(const int ADeltaX, const int ADeltaY);
	__property int LengthX = {read=FLengthX, nodefault};
	__property int LengthY = {read=FLengthY, nodefault};
	__property int PrevPositionX = {read=FPrevPositionX, write=FPrevPositionX, nodefault};
	__property int PrevPositionY = {read=FPrevPositionY, write=FPrevPositionY, nodefault};
	
public:
	__fastcall virtual TdxTileControlContentAnimation(TdxCustomTileControl* ATileControl, unsigned ATime, const int ALengthX, const int ALenghtY);
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
	__property TdxTileControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxAnimationTransition.Destroy */ inline __fastcall virtual ~TdxTileControlContentAnimation(void) { }
	
};


class DELPHICLASS TdxTileControlRubberAnimation;
class DELPHICLASS TdxTileControlHandScroll;
class PASCALIMPLEMENTATION TdxTileControlRubberAnimation : public TdxTileControlContentAnimation
{
	typedef TdxTileControlContentAnimation inherited;
	
private:
	TdxTileControlHandScroll* FHandScrollObject;
	TdxTileControlController* __fastcall GetController(void);
	
protected:
	virtual void __fastcall DoMoveContent(const int ADeltaX, const int ADeltaY);
	
public:
	__fastcall virtual TdxTileControlRubberAnimation(TdxCustomTileControl* ATileControl, TdxTileControlHandScroll* AHandScrollObject);
	__fastcall virtual ~TdxTileControlRubberAnimation(void);
	__property TdxTileControlHandScroll* HandScrollObject = {read=FHandScrollObject};
	__property TdxTileControlController* Controller = {read=GetController};
};


class DELPHICLASS TdxTileControlDragAndDropChangesCellInfo;
class DELPHICLASS TdxTileControlGroupCaption;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragAndDropChangesCellInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomTileControl* __fastcall GetTileControl(void);
	TdxTileControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	int AreaSize;
	bool BeforeUpdate;
	System::Types::TRect Bounds;
	TdxTileControlAnimatedDragAndDropCustomCellViewInfo* Cell;
	Cxgraphics::TcxRegion* ClipRgn;
	int ColumnIndex;
	int IndexInGroup;
	TdxTileControlGroupCaption* GroupCaption;
	System::Types::TPoint GroupOrigin;
	TdxTileControlItem* Item;
	bool IsItemMovedToNeighborPosition;
	void __fastcall CalculateComplexDrawingAreaBounds(System::Types::TRect &R, System::Types::TRect &R1, const int AOffset);
	void __fastcall CalculateSimpleDrawingAreaBounds(System::Types::TRect &R, const int AOffset);
	int __fastcall CompareTileControlGroupCaptions(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	int __fastcall CompareTileControlItems(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	bool __fastcall IsEqualGroupCaptions(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	bool __fastcall IsEqualItems(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	
public:
	__fastcall TdxTileControlDragAndDropChangesCellInfo(TdxTileControlAnimatedDragAndDropCustomCellViewInfo* ACell, bool ABeforeUpdate);
	__fastcall virtual ~TdxTileControlDragAndDropChangesCellInfo(void);
	int __fastcall Compare(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, const int AProgress);
	void __fastcall InvalidateAnimatedArea(void);
	bool __fastcall IsEqual(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	bool __fastcall Merge(TdxTileControlDragAndDropChangesCellInfo* AInfo);
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlDragDropCustomObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragAndDropChanges : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FDragFinished;
	TdxTileControlCustomCellViewInfo* FDragObject;
	System::Types::TRect FDragImageBounds;
	System::Types::TPoint FDragImagePosition;
	Cxclasses::TcxObjectList* FItemsInfo;
	int FLock;
	int FProgress;
	TdxTileControlViewInfo* FViewInfo;
	int __fastcall GetCount(void);
	TdxTileControlDragDropCustomObject* __fastcall GetDragAndDropObject(void);
	bool __fastcall GetDragObjectFinished(void);
	TdxTileControlDragAndDropChangesCellInfo* __fastcall GetItem(int AIndex);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	
protected:
	virtual void __fastcall AnimateDragFinished(const int AProgress);
	virtual void __fastcall DrawItems(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PopulateItemsInfo(bool ABeforeUpdate);
	void __fastcall SetAnimationProgress(const int AProgress);
	__property bool DragFinished = {read=FDragFinished, write=FDragFinished, nodefault};
	__property Cxclasses::TcxObjectList* ItemsInfo = {read=FItemsInfo};
	__property int Progress = {read=FProgress, nodefault};
	
public:
	__fastcall TdxTileControlDragAndDropChanges(TdxTileControlViewInfo* AViewInfo);
	__fastcall virtual ~TdxTileControlDragAndDropChanges(void);
	virtual void __fastcall AfterUpdate(void);
	virtual void __fastcall BeforeUpdate(void);
	int __fastcall IndexOf(TdxTileControlAnimatedDragAndDropCustomCellViewInfo* ACell);
	__property int Count = {read=GetCount, nodefault};
	__property TdxTileControlDragDropCustomObject* DragAndDropObject = {read=GetDragAndDropObject};
	__property TdxTileControlCustomCellViewInfo* DragObject = {read=FDragObject};
	__property bool DragObjectFinished = {read=GetDragObjectFinished, nodefault};
	__property TdxTileControlDragAndDropChangesCellInfo* Items[int Index] = {read=GetItem};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlViewInfo* ViewInfo = {read=FViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlAutoScrollingObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlAutoScrollingObject : public Cxinplacecontainer::TcxCustomAutoScrollingObject
{
	typedef Cxinplacecontainer::TcxCustomAutoScrollingObject inherited;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual bool __fastcall GetHasScrollBar(void);
	virtual void __fastcall GetScrollBarParams(int &AMin, int &AMax, int &APos);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AKind, System::Uitypes::TScrollCode ACode, int &APosition);
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
public:
	/* TcxCustomAutoScrollingObject.Create */ inline __fastcall virtual TdxTileControlAutoScrollingObject(System::TObject* AOwner) : Cxinplacecontainer::TcxCustomAutoScrollingObject(AOwner) { }
	/* TcxCustomAutoScrollingObject.Destroy */ inline __fastcall virtual ~TdxTileControlAutoScrollingObject(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlHandScroll : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	int FFinishAnimationPosX;
	int FFinishAnimationPosY;
	int FStartAnimationPosX;
	int FStartAnimationPosY;
	void __fastcall DoScrollHorizontally(void);
	void __fastcall DoScrollVertically(void);
	int __fastcall GetSlowdownScrollFactor(int APos, int AContentSize, int ADelta);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	TdxTileControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual bool __fastcall GetImmediateStart(void);
	__property int FinishAnimationPosX = {read=FFinishAnimationPosX, nodefault};
	__property int FinishAnimationPosY = {read=FFinishAnimationPosY, nodefault};
	__property int StartAnimationPosX = {read=FStartAnimationPosX, nodefault};
	__property int StartAnimationPosY = {read=FStartAnimationPosY, nodefault};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TdxTileControlHandScroll(Cxcontrols::TcxControl* AControl) : Cxcontrols::TcxDragAndDropObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlHandScroll(void) { }
	
};

#pragma pack(pop)

enum TdxTileControlDragDropState : unsigned char { tcddsPulling, tcddsMoving };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragDropCustomObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	TdxTileControlGroup* FBeginGroup;
	int FBeginIndex;
	TdxTileControlCustomCellViewInfo* FDragCell;
	bool FDragCellIsHided;
	System::Types::TPoint FHotSpot;
	bool FHotSpotCalculated;
	bool FIsTouching;
	bool FPrevAccepted;
	int FPullProgress;
	TdxTileControlDragDropState FState;
	void __fastcall CalculateHotSpot(void);
	TdxTileControlAutoScrollingObject* __fastcall CreateAutoScrollObject(Vcl::Forms::TScrollBarKind Kind, const System::Types::TRect &ARect, System::Uitypes::TScrollCode ACode);
	void __fastcall CreateAutoScrollObjects(void);
	void __fastcall DestroyAutoScrollObjects(void);
	TdxTileControlController* __fastcall GetController(void);
	System::Types::TRect __fastcall GetDragBounds(void);
	TdxTileControlGroup* __fastcall GetDragCellAsGroup(void);
	TdxTileControlItem* __fastcall GetDragCellAsItem(void);
	bool __fastcall GetDragCellIsItem(void);
	TdxTileControlDragAndDropChanges* __fastcall GetDragDropChanges(void);
	TdxTileControlHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetIsPullDownGesture(void);
	int __fastcall GetMaxPullSize(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	TdxTileControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetPullProgress(int AValue);
	void __fastcall HideOriginalDragCell(void);
	bool __fastcall IsRectInControl(const System::Types::TRect &ARect);
	System::Types::TPoint __fastcall MouseClientToScreen(const System::Types::TPoint &P);
	
protected:
	Cxinplacecontainer::TcxDragImage* DragImage;
	System::StaticArray<TdxTileControlAutoScrollingObject*, 4> ScrollControllers;
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall BeginDragAndDropGroup(void);
	virtual void __fastcall BeginDragAndDropItem(void);
	virtual void __fastcall BeginDragMoving(void);
	virtual bool __fastcall CheckAutoScrolling(void);
	void __fastcall DoAnimateContent(const System::Types::TPoint &AStart, const System::Types::TPoint &AFinish);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall DragAndDropGroup(bool &Accepted);
	virtual void __fastcall DragAndDropItem(bool &Accepted);
	virtual void __fastcall DragMoving(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual void __fastcall EndDragAndDropGroup(bool Accepted);
	virtual void __fastcall EndDragAndDropItem(bool Accepted, TdxTileControlGroup* &ANewGroup);
	virtual void __fastcall EndDragMoving(bool Accepted);
	virtual void __fastcall InitializeDragImage(void);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	virtual bool __fastcall GetImmediateStart(void);
	virtual void __fastcall PullDown(bool Accepted);
	virtual void __fastcall Pulling(const System::Types::TPoint &P);
	virtual void __fastcall ShowDragImage(const System::Types::TPoint &APos);
	void __fastcall StopAutoScrollingTimers(void);
	__property TdxTileControlController* Controller = {read=GetController};
	__property System::Types::TRect DragBounds = {read=GetDragBounds};
	__property TdxTileControlCustomCellViewInfo* DragCell = {read=FDragCell};
	__property TdxTileControlGroup* DragCellAsGroup = {read=GetDragCellAsGroup};
	__property TdxTileControlItem* DragCellAsItem = {read=GetDragCellAsItem};
	__property bool DragCellIsItem = {read=GetDragCellIsItem, nodefault};
	__property TdxTileControlDragAndDropChanges* DragDropChanges = {read=GetDragDropChanges};
	__property TdxTileControlHitTest* HitTest = {read=GetHitTest};
	__property bool IsPullDownGesture = {read=GetIsPullDownGesture, nodefault};
	__property bool IsTouching = {read=FIsTouching, nodefault};
	__property int MaxPullSize = {read=GetMaxPullSize, nodefault};
	__property int PullProgress = {read=FPullProgress, write=SetPullProgress, nodefault};
	__property TdxTileControlDragDropState State = {read=FState, nodefault};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxTileControlDragDropCustomObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TdxTileControlDragDropCustomObject(void);
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlDragDropGroup;
class DELPHICLASS TdxTileControlGroupCollection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragDropGroup : public TdxTileControlDragDropCustomObject
{
	typedef TdxTileControlDragDropCustomObject inherited;
	
private:
	TdxTileControlGroup* FDragGroup;
	int FPrevIndex;
	int __fastcall GetPotentialIndexForDraggedGroup(void);
	int __fastcall GetPotentialIndexForNewlyInsertedGroup(void);
	int __fastcall GetPotentialIndexForMovedGroup(void);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	TdxTileControlGroupCollection* __fastcall GetGroups(void);
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	__property TdxTileControlGroupCollection* Groups = {read=GetGroups};
	
protected:
	virtual void __fastcall BeginDragAndDropGroup(void);
	virtual void __fastcall DragAndDropGroup(bool &Accepted);
	virtual void __fastcall EndDragAndDropGroup(bool Accepted);
	
public:
	__property TdxTileControlGroup* DragGroup = {read=FDragGroup};
public:
	/* TdxTileControlDragDropCustomObject.Create */ inline __fastcall virtual TdxTileControlDragDropGroup(Cxcontrols::TcxControl* AControl) : TdxTileControlDragDropCustomObject(AControl) { }
	/* TdxTileControlDragDropCustomObject.Destroy */ inline __fastcall virtual ~TdxTileControlDragDropGroup(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlDragItemInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragItemInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxTileControlItem* FItem;
	TdxTileControlGroup* FGroup;
	TdxTileControlGroup* FSourceGroup;
	
protected:
	void __fastcall SetGroup(TdxTileControlGroup* AGroup);
	
public:
	__property TdxTileControlItem* Item = {read=FItem};
	__property TdxTileControlGroup* Group = {read=FGroup};
	__property TdxTileControlGroup* SourceGroup = {read=FSourceGroup};
public:
	/* TObject.Create */ inline __fastcall TdxTileControlDragItemInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlDragItemInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlDragItemPlace;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragItemPlace : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxTileControlGroupViewInfo* FGroup;
	TdxLayoutItemPosition* FPosition;
	TdxTileControlVirtualGroupViewInfo* FVirtualGroup;
	
public:
	__fastcall TdxTileControlDragItemPlace(void);
	__fastcall virtual ~TdxTileControlDragItemPlace(void);
	void __fastcall Assign(TdxTileControlDragItemPlace* ASource);
	TdxTileControlGroup* __fastcall GetGroup(void);
	bool __fastcall IsEqual(TdxTileControlDragItemPlace* APlace);
	__property TdxTileControlGroupViewInfo* Group = {read=FGroup, write=FGroup};
	__property TdxLayoutItemPosition* Position = {read=FPosition, write=FPosition};
	__property TdxTileControlVirtualGroupViewInfo* VirtualGroup = {read=FVirtualGroup, write=FVirtualGroup};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlDragDropItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDragDropItem : public TdxTileControlDragDropCustomObject
{
	typedef TdxTileControlDragDropCustomObject inherited;
	
private:
	bool FDragOverIsAccepted;
	TdxTileControlItem* FDragItem;
	bool FWasTryDecreaseBeginGroup;
	Cxclasses::TcxObjectList* FGroupItemsPositions;
	TdxLayoutItemPosition* FNextPosition;
	TdxTileControlDragItemPlace* FPrevPlace;
	TdxTileControlDragItemPlace* FPlace;
	TdxTileControlGroup* FTemporaryGroup;
	void __fastcall CalculateDragAndDropItemInGroup(void);
	void __fastcall CalculateDragAndDropItemInAnotherGroup(void);
	void __fastcall CalculateDragAndDropItemInPrevGroup(void);
	void __fastcall CalculateDragAndDropItemInVirtualGroup(bool &AAccepted);
	void __fastcall CheckGroupDragItem(void);
	void __fastcall CheckPlaceDragItem(bool &AAccepted);
	void __fastcall CheckPositionDragItem(void);
	void __fastcall CheckPositionDragPoint(const System::Types::TPoint &ADragPoint);
	TdxTileControlGroup* __fastcall CreateNewGroupAndMoveDragItemTo(TdxTileControlVirtualGroupViewInfo* AVirtualGroup);
	void __fastcall DoCollapseBeginGroupWhenItemIsLast(void);
	void __fastcall DoItemDragOver(bool &AAccepted);
	void __fastcall DoRestoreDragItemSourcePosition(void);
	void __fastcall FindGroupOccupiedCenterOfDragItem(void);
	void __fastcall FindVirtualGroupOccupiedCenterOfDragItem(void);
	void __fastcall FindSomethingOccupiedPartiallyOfDragItem(void);
	TdxTileControlDragItemInfo* __fastcall GetDragItemInfo(void);
	System::Types::TPoint __fastcall GetDragPoint(void);
	TdxTileControlGroup* __fastcall GetGroupCrossedOnTheRight(void);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	int __fastcall GetNewIndexOfDragItem(TdxTileControlGroup* AGroup);
	System::Types::TPoint __fastcall GetSecondaryDragPoint(const System::Types::TRect &ABounds);
	int __fastcall GetSpecialPointX(void);
	int __fastcall GetSpecialPointY(void);
	bool __fastcall GetStayInPlaceVirtualGroup(void);
	Cxclasses::TcxObjectList* __fastcall GetVirtualGroups(void);
	bool __fastcall HasValidGroup(void);
	void __fastcall InitializePrevPlace(void);
	bool __fastcall IsBoundsAreasItemsChanged(TdxTileControlGroup* AGroup);
	bool __fastcall IsDoDecreaseBeginGroup(void);
	bool __fastcall IsDragBoundsCrossesOnTheRight(TdxTileControlGroup* AGroup);
	bool __fastcall IsDragItemsGroupHasMaxExpanded(void);
	bool __fastcall IsDragItemsGroupStayMoreRight(void);
	bool __fastcall IsExitFromVirtualGroup(void);
	bool __fastcall IsPossibleIncreaseGroup(TdxTileControlGroup* AGroup, bool &AAccepted);
	void __fastcall MoveDragItemFromControl(void);
	void __fastcall MoveDragItemToGroup(TdxTileControlGroup* AGroup, int AIndexInGroup);
	void __fastcall RecalculateGroup(TdxTileControlGroup* AGroup);
	void __fastcall RestoreDragItemSourcePosition(void);
	void __fastcall RestoreGroupItemsPositions(TdxTileControlGroup* AGroup);
	void __fastcall SetNoVisibleAllVirtualGroups(void);
	void __fastcall SwitchOff(TdxTileControlVirtualGroupViewInfo* AVirtualGroup);
	void __fastcall StoreGroupItemsPositions(TdxTileControlGroup* AGroup);
	void __fastcall TryDecreaseBeginGroup(void);
	
protected:
	virtual void __fastcall BeginDragAndDropItem(void);
	virtual void __fastcall BeginDragMoving(void);
	virtual void __fastcall DragAndDropItem(bool &Accepted);
	virtual void __fastcall EndDragAndDropItem(bool Accepted, TdxTileControlGroup* &ANewGroup);
	virtual void __fastcall PullDown(bool Accepted);
	__property TdxTileControlDragItemInfo* DragItemInfo = {read=GetDragItemInfo};
	
public:
	__fastcall virtual TdxTileControlDragDropItem(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TdxTileControlDragDropItem(void);
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	__property TdxTileControlDragItemPlace* Place = {read=FPlace};
	__property Cxclasses::TcxObjectList* VirtualGroups = {read=GetVirtualGroups};
	__property TdxTileControlItem* DragItem = {read=FDragItem};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCheckedItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCheckedItems : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxTileControlItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxTileControlItem* __fastcall GetItem(int Index);
	
public:
	__property TdxTileControlItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxTileControlCheckedItems(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxTileControlCheckedItems(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

typedef bool __fastcall (__closure *TdxTileControlDesignTimeMenuItemCheckedCondition)(TdxTileControlItem* AItem);

class DELPHICLASS TdxTileControlItemNavigator;
class DELPHICLASS TdxTileControlScrollButtonViewInfo;
class DELPHICLASS TdxTileControlItemFrame;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::Classes::TList* FAnimationItems;
	System::Classes::TList* FAnimations;
	bool FCanItemDrawing;
	bool FContextMenuHandled;
	System::TObject* FDragCell;
	TdxTileControlCustomDesignHelper* FDesignHelper;
	Vcl::Menus::TPopupMenu* FDesignPopupMenu;
	Cxclasses::TcxComponentCollectionItem* FDesignPopupMenuCaller;
	TdxTileControlDesignTimeWhatSelected FDesignWhatObjectsSelected;
	TdxTileControlItem* FFocusedItem;
	int FFramesAnimationLockCount;
	bool FHasRubberAnimation;
	TdxTileControlHintController* FHintController;
	TdxTileControlItem* FHottrackedItem;
	TdxTileControlItem* FMouseDownItem;
	bool FMouseDownWasHandled;
	TdxTileControlItemNavigator* FNavigator;
	TdxTileControlScrollButtonViewInfo* FPressedScrollButton;
	System::Types::TPoint FStartDragPos;
	TdxCustomTileControl* FTileControl;
	bool __fastcall GetCanGroupMoving(void);
	bool __fastcall GetCanItemMoving(void);
	TdxTileControlCheckedItems* __fastcall GetCheckedItems(void);
	bool __fastcall GetHasAnimation_(void);
	TdxTileControlHitTest* __fastcall GetHitTest(void);
	TdxTileControlItemCheckMode __fastcall GetItemCheckMode(void);
	TdxTileControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall RestoreItemBounds(TdxTileControlItem* AItem, const void * AData);
	void __fastcall SetFocusedItem(TdxTileControlItem* AValue);
	void __fastcall SetHottrackedItem(TdxTileControlItem* AValue);
	void __fastcall SetPressedScrollButton(TdxTileControlScrollButtonViewInfo* AValue);
	Vcl::Menus::TMenuItem* __fastcall AddPopupMenuItem(System::UnicodeString ACaption, const int ATag, const System::Byte AGroupIndex, const bool AChecked, const bool ARadioItem, System::Classes::TNotifyEvent AOnClick);
	bool __fastcall CheckDesignPopupMenu(System::Classes::TShiftState AShift);
	void __fastcall CreateTileControlItem(System::TObject* Sender);
	void __fastcall DeleteSelectedObjects(System::TObject* Sender);
	void __fastcall DeleteTileControlGroups(void);
	void __fastcall DeleteTileControlItems(const bool ASelectNextObjectAfterDelete);
	void __fastcall DeleteTileControlSelectedItems(void);
	bool __fastcall GetIsExtraLargeItem(TdxTileControlItem* AItem);
	bool __fastcall GetIsLargeItem(TdxTileControlItem* AItem);
	bool __fastcall GetIsSmallItem(TdxTileControlItem* AItem);
	bool __fastcall GetDesignerMenuItemChecked(const int ATag, TdxTileControlItem* AItem)/* overload */;
	bool __fastcall GetDesignerMenuItemChecked(TdxTileControlItem* AItem, TdxTileControlDesignTimeMenuItemCheckedCondition AFunc)/* overload */;
	TdxTileControlDesignTimeWhatSelected __fastcall GetDesignTimeWhatSelected(void);
	System::Classes::TPersistent* __fastcall GetNextObject(int ADeletedGroupIndex)/* overload */;
	System::Classes::TPersistent* __fastcall GetNextObject(int ADeletedItemIndex, TdxTileControlGroup* ADeletedItemGroup)/* overload */;
	void __fastcall PopulateDesignPopupMenu(void);
	void __fastcall PopulateOneGroupDesignPopupMenu(void);
	void __fastcall PopulateOneItemDesignPopupMenu(void);
	void __fastcall ProcessDesignPopupMenu(Cxclasses::TcxComponentCollectionItem* ACaller, System::Classes::TShiftState AShift, const System::Types::TPoint &APopupPoint);
	void __fastcall SwitchItemsProperty(System::TObject* Sender);
	
protected:
	void __fastcall AddAnimation(Dxanimation::TdxAnimationTransition* Animation);
	void __fastcall AnimateItem(TdxTileControlItem* AItem);
	void __fastcall AfterAnimation(Dxanimation::TdxAnimationController* Sender);
	void __fastcall BeforeAnimation(Dxanimation::TdxAnimationController* Sender);
	void __fastcall DestroyAnimation(Dxanimation::TdxAnimationTransition* Animation);
	virtual bool __fastcall CanShowActionBarsOnRightClick(void);
	virtual bool __fastcall CanToggleItemCheckOnRightClick(void);
	void __fastcall ChangePressedScrollButtonState(void);
	void __fastcall CheckActionBarsState(TdxTileControlItem* ACheckingItem);
	void __fastcall FrameDestroyed(TdxTileControlItemFrame* AFrame);
	bool __fastcall HitAtGroup(void);
	bool __fastcall HitAtItem(void);
	bool __fastcall HitAtItemOrGroup(void);
	void __fastcall ImmediateAnimation(Dxanimation::TdxAnimationTransition* Animation);
	bool __fastcall IsEnableDrawDragItemPlace(void);
	bool __fastcall IsHandScrolling(Vcl::Forms::TScrollBarKind ACheckedKind);
	void __fastcall ItemChecked(TdxTileControlItem* AItem);
	void __fastcall ItemDestroyed(TdxTileControlItem* AItem);
	void __fastcall RefreshItems(void);
	void __fastcall RestoreItemsBounds(void);
	void __fastcall TerminateAnimations(bool ATerminateFrames);
	void __fastcall UncheckAllItems(void);
	bool __fastcall CanCreateSelectionHelper(void);
	void __fastcall CheckCreateDesignHelper(void);
	void __fastcall DestroyDesignHelper(void);
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject);
	virtual void __fastcall SelectObject(System::Classes::TPersistent* AObject, System::Classes::TShiftState AShift);
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	bool __fastcall PtInCaller(const System::Types::TPoint &P);
	void __fastcall HideActionBars(void);
	void __fastcall HideScrollButtons(void);
	void __fastcall ShowActionBars(void);
	void __fastcall ToggleActionBars(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	__property System::Classes::TList* AnimationItems = {read=FAnimationItems};
	__property System::Classes::TList* Animations = {read=FAnimations};
	__property bool CanGroupMoving = {read=GetCanGroupMoving, nodefault};
	__property bool CanItemMoving = {read=GetCanItemMoving, nodefault};
	__property bool CanItemDrawing = {read=FCanItemDrawing, write=FCanItemDrawing, nodefault};
	__property TdxTileControlCheckedItems* CheckedItems = {read=GetCheckedItems};
	__property bool ContextMenuHandled = {read=FContextMenuHandled, nodefault};
	__property TdxTileControlCustomDesignHelper* DesignHelper = {read=FDesignHelper};
	__property System::TObject* DragCell = {read=FDragCell, write=FDragCell};
	__property int FramesAnimationLockCount = {read=FFramesAnimationLockCount, write=FFramesAnimationLockCount, nodefault};
	__property bool HasAnimation_ = {read=GetHasAnimation_, nodefault};
	__property bool HasRubberAnimation = {read=FHasRubberAnimation, nodefault};
	__property TdxTileControlHintController* HintController = {read=FHintController};
	__property TdxTileControlHitTest* HitTest = {read=GetHitTest};
	__property TdxTileControlItemCheckMode ItemCheckMode = {read=GetItemCheckMode, nodefault};
	__property bool MouseDownWasHandled = {read=FMouseDownWasHandled, write=FMouseDownWasHandled, nodefault};
	__property TdxTileControlItemNavigator* Navigator = {read=FNavigator};
	__property System::Types::TPoint StartDragPos = {read=FStartDragPos, write=FStartDragPos};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
	__property TdxTileControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxTileControlController(TdxCustomTileControl* AOwner);
	__fastcall virtual ~TdxTileControlController(void);
	void __fastcall PrepareToDragAndDrop(void);
	virtual void __fastcall ProcessContextMenuMessage(Winapi::Messages::TWMContextMenu &Message);
	void __fastcall StartAnimations(void);
	void __fastcall StartFramesAnimation(void);
	void __fastcall StopAnimations(void);
	void __fastcall StopFramesAnimation(void);
	__property TdxTileControlItem* FocusedItem = {read=FFocusedItem, write=SetFocusedItem};
	__property TdxTileControlItem* HottrackedItem = {read=FHottrackedItem, write=SetHottrackedItem};
	__property TdxTileControlScrollButtonViewInfo* PressedScrollButton = {read=FPressedScrollButton, write=SetPressedScrollButton};
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	void *__IdxAnimationListener;	/* Dxanimation::IdxAnimationListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0CAAD87B-8A4B-464B-A738-1340BD80C3D8}
	operator Dxanimation::_di_IdxAnimationListener()
	{
		Dxanimation::_di_IdxAnimationListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxanimation::IdxAnimationListener*(void) { return (Dxanimation::IdxAnimationListener*)&__IdxAnimationListener; }
	#endif
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxTileControlHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::TObject* FHitObject;
	System::Types::TPoint FHitPoint;
	TdxCustomTileControl* FOwner;
	TdxTileControlController* __fastcall GetController(void);
	TdxTileControlGroup* __fastcall GetGroup(void);
	TdxTileControlItem* __fastcall GetItem(void);
	int __fastcall GetPosValue(const int AIndex);
	TdxTileControlScrollButtonViewInfo* __fastcall GetScrollButton(void);
	void __fastcall SetBitState(int AIndex, bool AValue);
	void __fastcall SetHitObject(System::TObject* AValue);
	void __fastcall SetHitPoint(const System::Types::TPoint &AValue);
	void __fastcall SetPosValue(const int AIndex, const int AValue);
	
protected:
	__int64 Flags;
	virtual TdxTileControlCustomViewInfo* __fastcall GetActiveViewInfo(void);
	bool __fastcall GetBitState(int AIndex);
	__property TdxTileControlCustomViewInfo* ActiveViewInfo = {read=GetActiveViewInfo};
	__property bool BitState[int AIndex] = {read=GetBitState, write=SetBitState};
	__property TdxTileControlController* Controller = {read=GetController};
	__property TdxTileControlScrollButtonViewInfo* ScrollButton = {read=GetScrollButton};
	
public:
	__fastcall TdxTileControlHitTest(TdxCustomTileControl* AOwner);
	void __fastcall Calculate(const int X, const int Y);
	void __fastcall Clear(void);
	virtual void __fastcall Recalculate(void);
	__property TdxTileControlGroup* Group = {read=GetGroup};
	__property bool HitAtActionBarBottom = {read=GetBitState, index=12, nodefault};
	__property bool HitAtActionBarTop = {read=GetBitState, index=11, nodefault};
	__property bool HitAtActionButton = {read=GetBitState, index=6, nodefault};
	__property bool HitAtBackButton = {read=GetBitState, index=4, nodefault};
	__property bool HitAtGroup = {read=GetBitState, index=1, nodefault};
	__property bool HitAtGroupCaption = {read=GetBitState, index=10, nodefault};
	__property bool HitAtItem = {read=GetBitState, index=2, nodefault};
	__property bool HitAtPageTab = {read=GetBitState, index=3, nodefault};
	__property bool HitAtScrollButton = {read=GetBitState, index=7, nodefault};
	__property bool HitAtScrollButtonArea = {read=GetBitState, index=8, nodefault};
	__property bool HitAtTitle = {read=GetBitState, index=9, nodefault};
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=SetHitPoint};
	__property System::TObject* HitObject = {read=FHitObject, write=SetHitObject};
	__property int HitX = {read=GetPosValue, write=SetPosValue, index=0, nodefault};
	__property int HitY = {read=GetPosValue, write=SetPosValue, index=1, nodefault};
	__property TdxTileControlItem* Item = {read=GetItem};
	__property TdxCustomTileControl* TileControl = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlHitTest(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemNavigator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxTileControlController* FController;
	int FCurrentNavigationItemOccupiedRow;
	bool FFocusItemOnCycle;
	TdxLayoutItemPosition* FPosition;
	TdxTileControlItem* __fastcall GetCurrentNavigationItem(void);
	int __fastcall GetCurrentNavigationItemColumn(void);
	int __fastcall GetCurrentNavigationItemRow(void);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	TdxTileControlGroupCollection* __fastcall GetGroups(void);
	TdxTileControlItem* __fastcall GetItemByBackSearchOnColumns(TdxTileControlGroup* AGroup, TdxLayoutItemPosition* AOriginalPosition, const int AEndColumn);
	TdxTileControlItem* __fastcall GetItemByBackSearchOnRows(TdxTileControlGroup* AGroup, TdxLayoutItemPosition* AOriginalPosition, const int AEndRow);
	TdxTileControlItem* __fastcall GetItemByForwardSearchOnColumns(TdxTileControlGroup* AGroup, TdxLayoutItemPosition* AOriginalPosition, const int AEndColumn);
	TdxTileControlItem* __fastcall GetItemByForwardSearchOnRows(TdxTileControlGroup* AGroup, TdxLayoutItemPosition* AOriginalPosition, const int AEndRow);
	TdxTileControlItem* __fastcall GetNextItemInColumnAboveTheCurrentWhenHorizontalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetNextItemInColumnAboveTheCurrentWhenVerticalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetNextItemInColumnBelowTheCurrent(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetNextItemInNextRowWhenHorizontalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetNextItemInNextRowWhenVerticalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetNextItemInRowToRightHand(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetOccupiedItem(TdxLayoutItemPosition* APosition, TdxTileControlGroup* AGroup);
	TdxTileControlItem* __fastcall GetPrevItemInColumnBelowTheCurrentWhenHorizontalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetPrevItemInColumnBelowTheCurrentWhenVerticalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetPrevItemInColumnAboveTheCurrent(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetPrevItemInPrevRowWhenHorizontalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetPrevItemInPrevRowWhenVerticalLayout(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	TdxTileControlItem* __fastcall GetPrevItemInRowToLeftHand(TdxLayoutItemPosition* APosition, int ACurrentGroupIndex);
	void __fastcall SetCurrentNavigationItem(TdxTileControlItem* AValue);
	
protected:
	virtual TdxTileControlItem* __fastcall GetFirstItem(void);
	virtual TdxTileControlItem* __fastcall GetFirstItemInRow(void);
	virtual TdxTileControlItem* __fastcall GetLastItem(void);
	virtual TdxTileControlItem* __fastcall GetLastItemInRow(void);
	virtual TdxTileControlItem* __fastcall GetNextItemInColumn(void);
	virtual TdxTileControlItem* __fastcall GetNextItemInRow(void);
	virtual TdxTileControlItem* __fastcall GetPrevItemInColumn(void);
	virtual TdxTileControlItem* __fastcall GetPrevItemInRow(void);
	__property TdxTileControlController* Controller = {read=FController};
	__property TdxTileControlItem* CurrentNavigationItem = {read=GetCurrentNavigationItem, write=SetCurrentNavigationItem};
	__property int CurrentNavigationItemColumn = {read=GetCurrentNavigationItemColumn, nodefault};
	__property int CurrentNavigationItemRow = {read=GetCurrentNavigationItemRow, nodefault};
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	__property TdxTileControlGroupCollection* Groups = {read=GetGroups};
	
public:
	__fastcall TdxTileControlItemNavigator(TdxTileControlController* AController);
	__fastcall virtual ~TdxTileControlItemNavigator(void);
	bool __fastcall IsAcceptedKey(System::Word Key);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall SaveCurrentNavigationItem(void);
};

#pragma pack(pop)

enum TdxTileItemInnerObjectAlignment : unsigned char { oaDefault, oaTopLeft, oaTopCenter, oaTopRight, oaMiddleLeft, oaMiddleCenter, oaMiddleRight, oaBottomLeft, oaBottomCenter, oaBottomRight };

enum TdxTileControlImageWithTextAlignment : unsigned char { itaNone, itaLeft, itaTop, itaRight, itaBottom };

class DELPHICLASS TdxTileControlItemPersistent;
class DELPHICLASS TdxTileControlCustomItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemPersistent : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TdxTileControlCustomItem* __fastcall GetOwnerItem(void);
	
protected:
	virtual void __fastcall Changed(void);
	virtual bool __fastcall IsChanged(void);
	__property TdxTileControlCustomItem* Owner = {read=GetOwnerItem};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TdxTileControlItemPersistent(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlItemPersistent(void) { }
	
};

#pragma pack(pop)

enum TdxTileItemTextAssignedValue : unsigned char { avColor, avTextColor, avFont };

typedef System::Set<TdxTileItemTextAssignedValue, TdxTileItemTextAssignedValue::avColor, TdxTileItemTextAssignedValue::avFont>  TdxTileItemTextAssignedValues;

class DELPHICLASS TdxTileControlItemText;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemText : public TdxTileControlItemPersistent
{
	typedef TdxTileControlItemPersistent inherited;
	
private:
	TdxTileItemInnerObjectAlignment FAlign;
	System::Classes::TAlignment FAlignment;
	TdxTileItemTextAssignedValues FAssignedValues;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	int FIndentHorz;
	int FIndentVert;
	System::Uitypes::TColor FTextColor;
	bool FTransparent;
	System::UnicodeString FValue;
	bool FWordWrap;
	bool __fastcall IsFontStored(void);
	void __fastcall SetAlign(TdxTileItemInnerObjectAlignment AValue);
	void __fastcall SetAlignment(System::Classes::TAlignment AValue);
	void __fastcall SetAssignedValues(TdxTileItemTextAssignedValues AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetIndentHorz(int AValue);
	void __fastcall SetIndentVert(int AValue);
	void __fastcall SetTextColor(System::Uitypes::TColor AValue);
	void __fastcall SetTransparent(bool AValue);
	void __fastcall SetValue(const System::UnicodeString AValue);
	void __fastcall SetWordWrap(bool AValue);
	
protected:
	TdxTileItemInnerObjectAlignment FDefaultAlign;
	void __fastcall CalculateBounds(System::Types::TRect &ABounds);
	void __fastcall FontChanged(System::TObject* Sender);
	TdxTileItemInnerObjectAlignment __fastcall GetActualAlign(void);
	System::Uitypes::TColor __fastcall GetActualColor(void);
	Vcl::Graphics::TFont* __fastcall GetActualFont(void);
	System::Uitypes::TColor __fastcall GetActualFontColor(void);
	System::UnicodeString __fastcall GetActualValue(void);
	int __fastcall GetTextOutFlags(void);
	bool __fastcall HasValue(void);
	
public:
	__fastcall virtual TdxTileControlItemText(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTileControlItemText(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property TdxTileItemInnerObjectAlignment Align = {read=FAlign, write=SetAlign, default=0};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TdxTileItemTextAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property int IndentHorz = {read=FIndentHorz, write=SetIndentHorz, default=6};
	__property int IndentVert = {read=FIndentVert, write=SetIndentVert, default=6};
	__property System::UnicodeString Value = {read=FValue, write=SetValue};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=SetTextColor, default=536870912};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=1};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlItemGlyph;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemGlyph : public TdxTileControlItemPersistent
{
	typedef TdxTileControlItemPersistent inherited;
	
private:
	TdxTileItemInnerObjectAlignment FAlign;
	TdxTileControlImageWithTextAlignment FAlignWithText;
	Dxgdiplusclasses::TdxSmartImage* FImage;
	int FIndentHorz;
	int FIndentVert;
	Cxgraphics::TcxImageFitMode FMode;
	void __fastcall ImageChanged(System::TObject* Sender);
	void __fastcall SetAlign(TdxTileItemInnerObjectAlignment AValue);
	void __fastcall SetAlignWithText(TdxTileControlImageWithTextAlignment AValue);
	void __fastcall SetImage(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetIndentHorz(int AValue);
	void __fastcall SetIndentVert(int AValue);
	void __fastcall SetMode(Cxgraphics::TcxImageFitMode AValue);
	
protected:
	TdxTileItemInnerObjectAlignment __fastcall GetActualAlign(void);
	System::Types::TRect __fastcall GetClientRect(const System::Types::TRect &ABounds);
	virtual bool __fastcall IsChanged(void);
	
public:
	__fastcall virtual TdxTileControlItemGlyph(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTileControlItemGlyph(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property TdxTileItemInnerObjectAlignment Align = {read=FAlign, write=SetAlign, default=0};
	__property TdxTileControlImageWithTextAlignment AlignWithText = {read=FAlignWithText, write=SetAlignWithText, default=0};
	__property Dxgdiplusclasses::TdxSmartImage* Image = {read=FImage, write=SetImage};
	__property int IndentHorz = {read=FIndentHorz, write=SetIndentHorz, default=6};
	__property int IndentVert = {read=FIndentVert, write=SetIndentVert, default=6};
	__property Cxgraphics::TcxImageFitMode Mode = {read=FMode, write=SetMode, default=0};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCustomStyle;
class PASCALIMPLEMENTATION TdxTileControlCustomStyle : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	Vcl::Graphics::TFont* FFont;
	bool FFontChanged;
	Dxskinscore::TdxSkinGradientMode FGradient;
	System::Uitypes::TColor FGradientBeginColor;
	System::Uitypes::TColor FGradientEndColor;
	Dxskinscore::TdxSkinStretchMode FStretch;
	Dxgdiplusclasses::TdxSmartImage* FTexture;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall ImageChanged(System::TObject* Sender);
	bool __fastcall IsFontStored(void);
	void __fastcall SetBorderColor(System::Uitypes::TColor AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetGradientBeginColor(System::Uitypes::TColor AValue);
	void __fastcall SetGradientEndColor(System::Uitypes::TColor AValue);
	void __fastcall SetGradientMode(Dxskinscore::TdxSkinGradientMode AValue);
	void __fastcall SetStretch(Dxskinscore::TdxSkinStretchMode AValue);
	void __fastcall SetTexture(Dxgdiplusclasses::TdxSmartImage* AValue);
	
protected:
	virtual void __fastcall Changed(void);
	void __fastcall FontChanged(System::TObject* Sender);
	virtual bool __fastcall IsChanged(void);
	virtual bool __fastcall IsEmpty(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxTileControlCustomStyle(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTileControlCustomStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=SetBorderColor, default=536870912};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property Dxskinscore::TdxSkinGradientMode Gradient = {read=FGradient, write=SetGradientMode, default=0};
	__property System::Uitypes::TColor GradientBeginColor = {read=FGradientBeginColor, write=SetGradientBeginColor, default=536870912};
	__property System::Uitypes::TColor GradientEndColor = {read=FGradientEndColor, write=SetGradientEndColor, default=536870912};
	__property Dxskinscore::TdxSkinStretchMode Stretch = {read=FStretch, write=SetStretch, default=0};
	__property Dxgdiplusclasses::TdxSmartImage* Texture = {read=FTexture, write=SetTexture};
};


enum TdxTileControlItemOptionsAnimateAssignedValue : unsigned char { ioaavAnimateText };

typedef System::Set<TdxTileControlItemOptionsAnimateAssignedValue, TdxTileControlItemOptionsAnimateAssignedValue::ioaavAnimateText, TdxTileControlItemOptionsAnimateAssignedValue::ioaavAnimateText>  TdxTileControlItemOptionsAnimateAssignedValues;

class DELPHICLASS TdxTileControlCustomItemOptionsAnimate;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomItemOptionsAnimate : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FAnimateText;
	TdxTileControlItemOptionsAnimateAssignedValues FAssignedValues;
	bool __fastcall GetAnimateText(void);
	bool __fastcall IsAnimateTextStored(void);
	void __fastcall SetAnimateText(bool AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual TdxTileControlCustomItemOptionsAnimate* __fastcall GetParentOptionsAnimate(void);
	__property TdxTileControlItemOptionsAnimateAssignedValues AssignedValues = {read=FAssignedValues, write=FAssignedValues, stored=false, nodefault};
	__property TdxTileControlCustomItemOptionsAnimate* ParentOptionsAnimate = {read=GetParentOptionsAnimate};
	
public:
	__fastcall virtual TdxTileControlCustomItemOptionsAnimate(System::Classes::TPersistent* AOwner);
	
__published:
	__property bool AnimateText = {read=GetAnimateText, write=SetAnimateText, stored=IsAnimateTextStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlCustomItemOptionsAnimate(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomItemViewData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FClientRect;
	Dxgdiplusclasses::TdxGPImage* FImage;
	System::Types::TRect FImageBounds;
	bool FIsDirty;
	TdxTileControlCustomItem* FItem;
	bool FNeedDrawTextOnImage;
	System::StaticArray<System::Types::TRect, 4> FTextBounds;
	System::Types::TRect __fastcall GetBounds(void);
	Dxgdiplusclasses::TdxGPImage* __fastcall GetImage(void);
	bool __fastcall GetIsActive(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	System::Types::TRect __fastcall GetTextBounds(int AIndex);
	TdxTileControlItem* __fastcall GetTileItem(void);
	void __fastcall SetIsDirty(bool AValue);
	void __fastcall SetNeedDrawTextOnImage(bool AValue);
	
protected:
	void __fastcall AdjustObjectBounds(const System::Types::TRect &ABounds, System::Types::TRect &AObjectBounds, TdxTileItemInnerObjectAlignment AAlign, int AIndentHorz, int AIndentVert);
	void __fastcall AdjustImageBoundsWithText(const System::Types::TRect &ABounds, TdxTileControlItemText* AText, System::Types::TRect &AImageBounds, System::Types::TRect &ATextBounds);
	void __fastcall CalculateImageAndTextLayout(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawItemBackground(Cxgraphics::TcxCanvas* const ACanvas);
	virtual void __fastcall DrawItemGlyph(Cxgraphics::TcxCanvas* const ACanvas);
	virtual void __fastcall DrawItemText(Cxgraphics::TcxCanvas* const ACanvas, const int AIndex);
	virtual void __fastcall DrawItemTexts(Cxgraphics::TcxCanvas* const ACanvas);
	virtual void __fastcall PrepareViewData(void);
	
public:
	__fastcall virtual TdxTileControlCustomItemViewData(TdxTileControlCustomItem* AItem);
	__fastcall virtual ~TdxTileControlCustomItemViewData(void);
	void __fastcall ValidateViewData(void);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property System::Types::TRect ClientRect = {read=FClientRect};
	__property Dxgdiplusclasses::TdxGPImage* Image = {read=GetImage};
	__property System::Types::TRect ImageBounds = {read=FImageBounds};
	__property bool IsActive = {read=GetIsActive, nodefault};
	__property bool IsDirty = {read=FIsDirty, write=SetIsDirty, nodefault};
	__property TdxTileControlCustomItem* Item = {read=FItem};
	__property bool NeedDrawTextOnImage = {read=FNeedDrawTextOnImage, write=SetNeedDrawTextOnImage, nodefault};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property System::Types::TRect TextBounds[int Index] = {read=GetTextBounds};
	__property TdxTileControlItem* TileItem = {read=GetTileItem};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlItemOptionsAnimate;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemOptionsAnimate : public TdxTileControlCustomItemOptionsAnimate
{
	typedef TdxTileControlCustomItemOptionsAnimate inherited;
	
protected:
	virtual TdxTileControlCustomItemOptionsAnimate* __fastcall GetParentOptionsAnimate(void);
	
__published:
	__property AssignedValues;
public:
	/* TdxTileControlCustomItemOptionsAnimate.Create */ inline __fastcall virtual TdxTileControlItemOptionsAnimate(System::Classes::TPersistent* AOwner) : TdxTileControlCustomItemOptionsAnimate(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlItemOptionsAnimate(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxTileControlItemGlyph* FGlyph;
	Cxgeometry::TcxMargin* FMargins;
	TdxTileControlItemOptionsAnimate* FOptionsAnimate;
	bool FParentStyle;
	TdxTileControlCustomStyle* FStyle;
	System::StaticArray<TdxTileControlItemText*, 4> FTexts;
	TdxTileControlCustomItemViewData* FViewData;
	bool FVisible;
	TdxTileControlItemText* __fastcall GetText(int Index);
	bool __fastcall IsGlyphStored(void);
	bool __fastcall IsMarginsStored(void);
	bool __fastcall IsStyleStored(void);
	void __fastcall MarginsChangeHandler(System::TObject* Sender);
	void __fastcall SetGlyph(TdxTileControlItemGlyph* AValue);
	void __fastcall SetMargins(Cxgeometry::TcxMargin* AValue);
	void __fastcall SetOptionsAnimate(TdxTileControlItemOptionsAnimate* AValue);
	void __fastcall SetParentStyle(bool AValue);
	void __fastcall SetStyle(TdxTileControlCustomStyle* AValue);
	void __fastcall SetText(int AIndex, TdxTileControlItemText* AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	HIDESBASE virtual void __fastcall Changed(void);
	virtual TdxTileControlItemOptionsAnimate* __fastcall CreateOptionsAnimate(void) = 0 ;
	virtual TdxTileControlItemText* __fastcall CreateText(const TdxTileItemInnerObjectAlignment AAlign);
	virtual TdxTileControlCustomItemViewData* __fastcall CreateViewData(void);
	virtual TdxTileControlItem* __fastcall GetTileItem(void);
	void __fastcall StyleChanged(System::TObject* Sender);
	__property TdxTileControlItemOptionsAnimate* OptionsAnimate = {read=FOptionsAnimate, write=SetOptionsAnimate};
	__property bool ParentStyle = {read=FParentStyle, write=SetParentStyle, default=1};
	__property TdxTileControlCustomItemViewData* ViewData = {read=FViewData};
	
public:
	__fastcall virtual TdxTileControlCustomItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTileControlCustomItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	__property TdxTileControlItemGlyph* Glyph = {read=FGlyph, write=SetGlyph, stored=IsGlyphStored};
	__property Cxgeometry::TcxMargin* Margins = {read=FMargins, write=SetMargins, stored=IsMarginsStored};
	__property TdxTileControlCustomStyle* Style = {read=FStyle, write=SetStyle, stored=IsStyleStored};
	__property TdxTileControlItemText* Text1 = {read=GetText, write=SetText, index=0};
	__property TdxTileControlItemText* Text2 = {read=GetText, write=SetText, index=1};
	__property TdxTileControlItemText* Text3 = {read=GetText, write=SetText, index=2};
	__property TdxTileControlItemText* Text4 = {read=GetText, write=SetText, index=3};
	__property TdxTileControlItem* TileItem = {read=GetTileItem};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlItemFrameOptionsAnimate;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemFrameOptionsAnimate : public TdxTileControlItemOptionsAnimate
{
	typedef TdxTileControlItemOptionsAnimate inherited;
	
protected:
	virtual TdxTileControlCustomItemOptionsAnimate* __fastcall GetParentOptionsAnimate(void);
public:
	/* TdxTileControlCustomItemOptionsAnimate.Create */ inline __fastcall virtual TdxTileControlItemFrameOptionsAnimate(System::Classes::TPersistent* AOwner) : TdxTileControlItemOptionsAnimate(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlItemFrameOptionsAnimate(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemFrame : public TdxTileControlCustomItem
{
	typedef TdxTileControlCustomItem inherited;
	
private:
	void *FData;
	
protected:
	virtual void __fastcall Changed(void);
	virtual TdxTileControlItemOptionsAnimate* __fastcall CreateOptionsAnimate(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual TdxTileControlItem* __fastcall GetTileItem(void);
	
public:
	__fastcall virtual ~TdxTileControlItemFrame(void);
	__property void * Data = {read=FData, write=FData};
	
__published:
	__property ParentStyle = {default=1};
	__property Style;
	__property Glyph;
	__property Margins;
	__property OptionsAnimate;
	__property Text1;
	__property Text2;
	__property Text3;
	__property Text4;
	__property Visible = {default=1};
public:
	/* TdxTileControlCustomItem.Create */ inline __fastcall virtual TdxTileControlItemFrame(System::Classes::TComponent* AOwner) : TdxTileControlCustomItem(AOwner) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxTileControlForEachItemFrameProc)(TdxTileControlItemFrame* AItem, const void * AData);

class DELPHICLASS TdxTileControlItemFrames;
class PASCALIMPLEMENTATION TdxTileControlItemFrames : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxTileControlItemFrame* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxTileControlItemFrame* __fastcall GetItem(int AIndex);
	TdxTileControlItem* __fastcall GetOwnerItem(void);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxTileControlItemFrame* const AValue);
	
protected:
	void __fastcall ForEach(TdxTileControlForEachItemFrameProc AProc, const void * AData);
	
public:
	HIDESBASE TdxTileControlItemFrame* __fastcall Add(void);
	__property TdxTileControlItem* Owner = {read=GetOwnerItem};
	__property TdxTileControlItemFrame* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxTileControlItemFrames(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxTileControlItemFrames(void) { }
	
};


class DELPHICLASS TdxTileControlItemDetailOptions;
class DELPHICLASS TdxTileControlDetailSite;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlItemDetailOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::UnicodeString FCaption;
	Vcl::Controls::TWinControl* FDetailControl;
	TdxTileControlDetailSite* FDetailSite;
	bool FShowTab;
	bool __fastcall GetHasDetail(void);
	TdxTileControlDetailSite* __fastcall GetDetailSite(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	TdxTileControlItem* __fastcall GetTileItem(void);
	void __fastcall SetCaption(System::UnicodeString AValue);
	void __fastcall SetDetailControl(Vcl::Controls::TWinControl* AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual bool __fastcall IsChanged(void);
	
public:
	__fastcall virtual ~TdxTileControlItemDetailOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	__property bool HasDetail = {read=GetHasDetail, nodefault};
	__property TdxTileControlDetailSite* DetailSite = {read=GetDetailSite};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlItem* TileItem = {read=GetTileItem};
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property Vcl::Controls::TWinControl* DetailControl = {read=FDetailControl, write=SetDetailControl};
	__property bool ShowTab = {read=FShowTab, write=FShowTab, default=0};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TdxTileControlItemDetailOptions(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxOwnedPersistent(AOwner) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxTileControlItemFrameEvent)(TdxTileControlItemFrame* Sender);

typedef void __fastcall (__closure *TdxTileControlItemEvent)(TdxTileControlItem* Sender);

class PASCALIMPLEMENTATION TdxTileControlItem : public TdxTileControlCustomItem
{
	typedef TdxTileControlCustomItem inherited;
	
private:
	int FActiveFrameIndex;
	Cxclasses::TcxObjectList* FActiveTransitions;
	int FAnimationInterval;
	Dxanimation::TdxDrawAnimationMode FAnimationMode;
	Cxclasses::TcxTimer* FAnimationTimer;
	bool FChecked;
	TdxTileControlItemDetailOptions* FDetailOptions;
	TdxTileControlItemFrames* FFrames;
	TdxTileControlGroup* FGroup;
	int FIndexInGroupAtLoaded;
	bool FIsActive;
	bool FIsLarge;
	int FRowCount;
	TdxTileControlItemViewInfo* FViewInfo;
	TdxTileControlItemEvent FOnActivateDetail;
	TdxTileControlItemEvent FOnActiveFrameChanged;
	TdxTileControlItemEvent FOnDeactivateDetail;
	TdxTileControlItemEvent FOnClick;
	TdxTileControlItemFrameEvent FOnFrameDestroy;
	TdxTileControlItemFrameEvent FOnFrameInitialize;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	TdxTileControlItemFrame* __fastcall GetActiveFrame(void);
	bool __fastcall GetActuallyVisible(void);
	TdxTileControlController* __fastcall GetController(void);
	int __fastcall GetGroupIndex(void);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	int __fastcall GetIndexInGroup(void);
	bool __fastcall GetIsAnimationActive(void);
	bool __fastcall GetIsMostLeft(void);
	bool __fastcall GetIsMostRight(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	int __fastcall GetVisibleFramesCount(void);
	bool __fastcall IsDetailOptionsStored(void);
	void __fastcall RefreshFrame(TdxTileControlItemFrame* AItem, const void * AData);
	void __fastcall SetActiveFrame(TdxTileControlItemFrame* AValue);
	void __fastcall SetActiveFrameIndex(int AValue);
	void __fastcall SetAnimationInterval(int AValue);
	void __fastcall SetChecked(bool AValue);
	void __fastcall SetDetailOptions(TdxTileControlItemDetailOptions* AValue);
	void __fastcall SetFrames(TdxTileControlItemFrames* AValue);
	void __fastcall SetGroup(TdxTileControlGroup* AValue);
	void __fastcall SetGroupIndex(int AValue);
	void __fastcall SetIndexInGroup(int AValue);
	void __fastcall SetIsLarge(bool AValue);
	void __fastcall SetRowCount(int AValue);
	void __fastcall SetOnActivateDetail(TdxTileControlItemEvent AValue);
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	
protected:
	virtual void __fastcall ActiveFrameChanged(void);
	void __fastcall AddTransition(Dxanimation::TdxAnimationTransition* ATransition);
	void __fastcall AnimationTimerHandler(System::TObject* Sender);
	virtual void __fastcall Changed(void);
	void __fastcall CheckTimerEnabled(void);
	TdxTileControlCustomItemViewData* __fastcall CheckViewDataInitialized(TdxTileControlCustomItemViewData* AViewData);
	virtual TdxTileControlItemDetailOptions* __fastcall CreateDetailOptions(void);
	virtual TdxTileControlDetailSite* __fastcall CreateDetailSite(void);
	virtual TdxTileControlItemFrames* __fastcall CreateFrames(void);
	virtual TdxTileControlItemOptionsAnimate* __fastcall CreateOptionsAnimate(void);
	virtual TdxTileControlItemViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DoActivateDetail(void);
	virtual void __fastcall DoActiveFrameChanged(void);
	virtual void __fastcall DoClick(void);
	virtual void __fastcall DoDeactivateDetail(void);
	virtual void __fastcall DoFrameDestroy(TdxTileControlItemFrame* AFrame);
	virtual void __fastcall DoFrameInitialize(TdxTileControlItemFrame* AFrame);
	virtual void __fastcall FrameChanged(TdxTileControlCustomItem* AFrame);
	TdxTileControlCustomItemViewData* __fastcall GetActualViewData(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual TdxTileControlItem* __fastcall GetTileItem(void);
	void __fastcall Invalidate(void);
	bool __fastcall IsDragged(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall Refresh(void);
	void __fastcall RemoveTransition(Dxanimation::TdxAnimationTransition* ATransition);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	void __fastcall StopTransitions(void);
	void __fastcall ToggleChecked(void);
	System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	int __fastcall GetPropertyIndex(const System::UnicodeString AName);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property Cxclasses::TcxObjectList* ActiveTransitions = {read=FActiveTransitions};
	__property Cxclasses::TcxTimer* AnimationTimer = {read=FAnimationTimer};
	__property TdxTileControlController* Controller = {read=GetController};
	__property bool IsAnimationActive = {read=GetIsAnimationActive, nodefault};
	__property bool IsActive = {read=FIsActive, write=FIsActive, nodefault};
	__property int VisibleFramesCount = {read=GetVisibleFramesCount, nodefault};
	
public:
	__fastcall virtual TdxTileControlItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTileControlItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	void __fastcall ActivateDetail(void);
	void __fastcall Click(void);
	void __fastcall DeactivateDetail(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall MakeVisible(void);
	void __fastcall Move(TdxTileControlGroup* AGroupDest, int AIndexDest);
	void __fastcall RemoveFromGroup(void);
	__property TdxTileControlItemFrame* ActiveFrame = {read=GetActiveFrame, write=SetActiveFrame};
	__property int ActiveFrameIndex = {read=FActiveFrameIndex, write=SetActiveFrameIndex, nodefault};
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property bool Checked = {read=FChecked, write=SetChecked, default=0};
	__property TdxTileControlGroup* Group = {read=FGroup, write=SetGroup};
	__property bool IsMostLeft = {read=GetIsMostLeft, nodefault};
	__property bool IsMostRight = {read=GetIsMostRight, nodefault};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlItemViewInfo* ViewInfo = {read=FViewInfo};
	
__published:
	__property int AnimationInterval = {read=FAnimationInterval, write=SetAnimationInterval, default=3000};
	__property Dxanimation::TdxDrawAnimationMode AnimationMode = {read=FAnimationMode, write=FAnimationMode, default=1};
	__property TdxTileControlItemDetailOptions* DetailOptions = {read=FDetailOptions, write=SetDetailOptions, stored=IsDetailOptionsStored};
	__property int GroupIndex = {read=GetGroupIndex, write=SetGroupIndex, nodefault};
	__property int IndexInGroup = {read=GetIndexInGroup, write=SetIndexInGroup, nodefault};
	__property bool IsLarge = {read=FIsLarge, write=SetIsLarge, default=0};
	__property TdxTileControlItemFrames* Frames = {read=FFrames, write=SetFrames};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=1};
	__property Style;
	__property Glyph;
	__property Margins;
	__property OptionsAnimate;
	__property Text1;
	__property Text2;
	__property Text3;
	__property Text4;
	__property Visible = {default=1};
	__property TdxTileControlItemEvent OnActivateDetail = {read=FOnActivateDetail, write=SetOnActivateDetail};
	__property TdxTileControlItemEvent OnActiveFrameChanged = {read=FOnActiveFrameChanged, write=FOnActiveFrameChanged};
	__property TdxTileControlItemEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TdxTileControlItemEvent OnDeactivateDetail = {read=FOnDeactivateDetail, write=FOnDeactivateDetail};
	__property TdxTileControlItemFrameEvent OnFrameDestroy = {read=FOnFrameDestroy, write=FOnFrameDestroy};
	__property TdxTileControlItemFrameEvent OnFrameInitialize = {read=FOnFrameInitialize, write=FOnFrameInitialize};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
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


class DELPHICLASS TdxTileControlCustomStoredCollection;
class PASCALIMPLEMENTATION TdxTileControlCustomStoredCollection : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
private:
	TdxCustomTileControl* __fastcall GetTileControl(void);
	
protected:
	virtual System::UnicodeString __fastcall GetItemPrefixName(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall StoredCreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredDeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall StoredChildren(System::Classes::TStringList* AChildren);
	
public:
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxTileControlCustomStoredCollection(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxTileControlCustomStoredCollection(void) { }
	
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


typedef void __fastcall (__closure *TdxTileControlItemChangeEvent)(Cxclasses::TcxComponentCollectionItem* AItem);

typedef void __fastcall (__closure *TdxTileControlForEachItemProc)(TdxTileControlItem* AItem, const void * AData);

class DELPHICLASS TdxTileControlItemCollection;
class PASCALIMPLEMENTATION TdxTileControlItemCollection : public TdxTileControlCustomStoredCollection
{
	typedef TdxTileControlCustomStoredCollection inherited;
	
public:
	TdxTileControlItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxTileControlItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxTileControlItem* const AValue);
	
protected:
	void __fastcall ForEach(TdxTileControlForEachItemProc AProc, const void * AData, bool AVisibleOnly = true);
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual System::TObject* __fastcall StoredCreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredChildren(System::Classes::TStringList* AChildren);
	
public:
	HIDESBASE TdxTileControlItem* __fastcall Add(void);
	__property TdxTileControlItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxTileControlItemCollection(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : TdxTileControlCustomStoredCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxTileControlItemCollection(void) { }
	
};


typedef System::TMetaClass* TdxTileControlItemCollectionClass;

class PASCALIMPLEMENTATION TdxTileControlGroup : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxTileControlGroupCaption* FCaption;
	Cxclasses::TcxObjectList* FItems;
	TdxTileControlGroupViewInfo* FViewInfo;
	TdxTileControlVirtualGroupViewInfo* FVirtualGroupBefore;
	TdxTileControlVirtualGroupViewInfo* FVirtualGroupAfter;
	bool FVisible;
	TdxCustomTileControl* FTileControl;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	void __fastcall AssignFrom(TdxTileControlGroup* AGroup, TdxTileControlItem* AExcludeItem = (TdxTileControlItem*)(0x0));
	System::Types::TRect __fastcall GetBounds(void);
	System::Types::TRect __fastcall GetExpandedBounds(void);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	TdxTileControlGroupCollection* __fastcall GetGroups(void);
	TdxTileControlItem* __fastcall GetItem(int AIndex);
	int __fastcall GetItemCount(void);
	bool __fastcall GetIsMostLeft(void);
	bool __fastcall GetIsMostRight(void);
	System::Types::TRect __fastcall GetMaximizedAreaBounds(void);
	int __fastcall GetRealColumnCount(void);
	int __fastcall GetRealRowCount(void);
	bool __fastcall IsCaptionStored(void);
	void __fastcall SetCaption(TdxTileControlGroupCaption* AValue);
	void __fastcall SetVisible(bool AValue);
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	
protected:
	virtual void __fastcall GroupChanged(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	void __fastcall Invalidate(void);
	bool __fastcall IsDragged(void);
	virtual void __fastcall SetCollection(Cxclasses::TcxComponentCollection* AValue);
	virtual void __fastcall SetIndex(int AValue);
	void __fastcall SetIndexForHorzLayout(int AValue);
	void __fastcall SetIndexForVertLayout(int AValue);
	void __fastcall UpdateTileControlLink(void);
	System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall StoredCreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredDeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall StoredChildren(System::Classes::TStringList* AChildren);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property System::Types::TRect ExpandedBounds = {read=GetExpandedBounds};
	__property System::Types::TRect MaximizedAreaBounds = {read=GetMaximizedAreaBounds};
	__property Cxclasses::TcxObjectList* ItemsList = {read=FItems};
	__property bool IsMostLeft = {read=GetIsMostLeft, nodefault};
	__property bool IsMostRight = {read=GetIsMostRight, nodefault};
	__property int RealColumnCount = {read=GetRealColumnCount, nodefault};
	__property int RealRowCount = {read=GetRealRowCount, nodefault};
	__property TdxTileControlGroupViewInfo* ViewInfo = {read=FViewInfo};
	__property TdxTileControlVirtualGroupViewInfo* VirtualGroupBefore = {read=FVirtualGroupBefore};
	__property TdxTileControlVirtualGroupViewInfo* VirtualGroupAfter = {read=FVirtualGroupAfter};
	
public:
	__fastcall virtual TdxTileControlGroup(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTileControlGroup(void);
	void __fastcall Add(TdxTileControlItem* AItem);
	void __fastcall DeleteItem(TdxTileControlItem* AItem);
	void __fastcall DeleteItems(void);
	int __fastcall IndexOfItem(TdxTileControlItem* AItem);
	void __fastcall MakeVisible(void);
	void __fastcall MoveItem(TdxTileControlItem* AItem, int AIndexDest);
	void __fastcall RemoveItem(TdxTileControlItem* AItem);
	void __fastcall RemoveItems(void);
	__property TdxTileControlGroupCollection* Groups = {read=GetGroups};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxTileControlItem* Items[int Index] = {read=GetItem};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
	
__published:
	__property TdxTileControlGroupCaption* Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property Index;
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
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


class DELPHICLASS TdxTileControlGroupCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlGroupCaptionViewInfo : public TdxTileControlAnimatedDragAndDropCustomCellViewInfo
{
	typedef TdxTileControlAnimatedDragAndDropCustomCellViewInfo inherited;
	
private:
	TdxTileControlGroupCaption* FCaption;
	Vcl::Graphics::TFont* FFont;
	int FHeight;
	int FIndent;
	System::Types::TRect FTextBounds;
	TdxTileControlGroup* __fastcall GetGroup(void);
	int __fastcall GetHeight(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	void __fastcall SetHeight(int AValue);
	
protected:
	virtual void __fastcall CalculateBounds(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ADrawRect);
	virtual System::Types::TRect __fastcall GetBaseDrawBounds(void);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	System::Types::TRect __fastcall GetTextBounds(const System::Types::TRect &ABounds);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	int __fastcall GetTextOutFlags(void);
	virtual TdxCustomTileControl* __fastcall GetTileControl(void);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	virtual void __fastcall MeasureHeight(void);
	virtual void __fastcall Offset(const int DX, const int DY);
	virtual void __fastcall Scroll(const int DX, const int DY);
	__property TdxTileControlGroupCaption* Caption = {read=FCaption};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TdxTileControlGroupCaptionViewInfo(TdxTileControlGroupCaption* AOwner);
	__fastcall virtual ~TdxTileControlGroupCaptionViewInfo(void);
	__property Vcl::Graphics::TFont* Font = {read=FFont};
	__property TdxTileControlGroup* Group = {read=GetGroup};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlGroupCaption : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	bool FFontChanged;
	TdxTileControlGroup* FGroup;
	System::UnicodeString FText;
	TdxTileControlGroupCaptionViewInfo* FViewInfo;
	System::Types::TRect __fastcall GetBounds(void);
	int __fastcall GetHeight(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	bool __fastcall IsFontStored(void);
	void __fastcall MeasureHeight(void);
	void __fastcall SetAlignment(System::Classes::TAlignment AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetHeight(int AHeight);
	void __fastcall SetText(System::UnicodeString AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall FontChanged(System::TObject* Sender);
	virtual bool __fastcall IsChanged(void);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property TdxTileControlGroup* Group = {read=FGroup};
	__property int Height = {read=GetHeight, nodefault};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlGroupCaptionViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxTileControlGroupCaption(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTileControlGroupCaption(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property System::UnicodeString Text = {read=FText, write=SetText};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxTileControlGroupCollection : public TdxTileControlCustomStoredCollection
{
	typedef TdxTileControlCustomStoredCollection inherited;
	
public:
	TdxTileControlGroup* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxTileControlGroup* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxTileControlGroup* const AValue);
	
protected:
	TdxTileControlGroup* __fastcall GetNextVisibleGroup(TdxTileControlGroup* AGroup);
	TdxTileControlGroup* __fastcall GetPrevVisibleGroup(TdxTileControlGroup* AGroup);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Update(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual System::TObject* __fastcall StoredCreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredDeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	
public:
	HIDESBASE TdxTileControlGroup* __fastcall Add(void);
	HIDESBASE TdxTileControlGroup* __fastcall Insert(int AIndex);
	__property TdxTileControlGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxTileControlGroupCollection(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : TdxTileControlCustomStoredCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxTileControlGroupCollection(void) { }
	
};


typedef System::TMetaClass* TdxTileControlGroupCollectionClass;

class DELPHICLASS TdxTileControlStyle;
class PASCALIMPLEMENTATION TdxTileControlStyle : public TdxTileControlCustomStyle
{
	typedef TdxTileControlCustomStyle inherited;
	
private:
	System::Uitypes::TColor FCheckedItemCheckMarkColor;
	System::Uitypes::TColor FCheckedItemFrameColor;
	System::Uitypes::TColor FFocusedColor;
	void __fastcall SetCheckedItemCheckMarkColor(System::Uitypes::TColor AValue);
	void __fastcall SetCheckedItemFrameColor(System::Uitypes::TColor AValue);
	void __fastcall SetFocusedColor(System::Uitypes::TColor AValue);
	
public:
	__fastcall virtual TdxTileControlStyle(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property System::Uitypes::TColor CheckedItemCheckMarkColor = {read=FCheckedItemCheckMarkColor, write=SetCheckedItemCheckMarkColor, default=536870912};
	__property System::Uitypes::TColor CheckedItemFrameColor = {read=FCheckedItemFrameColor, write=SetCheckedItemFrameColor, default=536870912};
	__property System::Uitypes::TColor FocusedColor = {read=FFocusedColor, write=SetFocusedColor, default=536870912};
public:
	/* TdxTileControlCustomStyle.Destroy */ inline __fastcall virtual ~TdxTileControlStyle(void) { }
	
};


class DELPHICLASS TdxTileControlOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlOptionsBehavior : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Byte FBackgroundScrollSync;
	bool FFocusItemOnCycle;
	bool FGroupMoving;
	bool FHideFocusOnItemHotTrack;
	TdxTileControlItemCheckMode FItemCheckMode;
	bool FItemHotTrack;
	bool FItemMoving;
	TdxTileControlScrollMode FScrollMode;
	TdxCustomTileControl* __fastcall GetTileControl(void);
	void __fastcall SetBackgroundScrollSync(System::Byte AValue);
	void __fastcall SetItemCheckMode(TdxTileControlItemCheckMode AValue);
	void __fastcall SetScrollMode(TdxTileControlScrollMode AValue);
	
protected:
	virtual void __fastcall Changed(void);
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	
public:
	__fastcall virtual TdxTileControlOptionsBehavior(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property System::Byte BackgroundScrollSync = {read=FBackgroundScrollSync, write=SetBackgroundScrollSync, default=15};
	__property bool FocusItemOnCycle = {read=FFocusItemOnCycle, write=FFocusItemOnCycle, default=1};
	__property bool GroupMoving = {read=FGroupMoving, write=FGroupMoving, default=0};
	__property bool HideFocusOnItemHotTrack = {read=FHideFocusOnItemHotTrack, write=FHideFocusOnItemHotTrack, default=0};
	__property TdxTileControlItemCheckMode ItemCheckMode = {read=FItemCheckMode, write=SetItemCheckMode, default=1};
	__property bool ItemHotTrack = {read=FItemHotTrack, write=FItemHotTrack, default=1};
	__property bool ItemMoving = {read=FItemMoving, write=FItemMoving, default=1};
	__property TdxTileControlScrollMode ScrollMode = {read=FScrollMode, write=SetScrollMode, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlOptionsBehavior(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlOptionsView : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FCenterContentHorz;
	bool FCenterContentVert;
	int FGroupIndent;
	int FIndentHorz;
	int FIndentVert;
	int FItemIndent;
	int FItemSize;
	TdxTileControlGroupLayout FGroupLayout;
	int FGroupMaxRowCount;
	int FVirtualGroupWidth;
	int __fastcall GetMaxItemRowCount(void);
	int __fastcall GetVirtualGroupWidth(const int AGroupIndent, const int AItemIndent);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	void __fastcall SetCenterContentHorz(bool AValue);
	void __fastcall SetCenterContentVert(bool AValue);
	void __fastcall SetGroupIndent(int AValue);
	void __fastcall SetIndentHorz(int AValue);
	void __fastcall SetIndentVert(int AValue);
	void __fastcall SetItemIndent(int AValue);
	void __fastcall SetItemSize(int AValue);
	void __fastcall SetGroupLayout(TdxTileControlGroupLayout AValue);
	void __fastcall SetGroupMaxRowCount(int AValue);
	
protected:
	virtual void __fastcall Changed(void);
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property int VirtualGroupWidth = {read=FVirtualGroupWidth, nodefault};
	
public:
	__fastcall virtual TdxTileControlOptionsView(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property bool CenterContentHorz = {read=FCenterContentHorz, write=SetCenterContentHorz, default=0};
	__property bool CenterContentVert = {read=FCenterContentVert, write=SetCenterContentVert, default=0};
	__property int GroupIndent = {read=FGroupIndent, write=SetGroupIndent, default=56};
	__property int IndentHorz = {read=FIndentHorz, write=SetIndentHorz, default=74};
	__property int IndentVert = {read=FIndentVert, write=SetIndentVert, default=40};
	__property int ItemIndent = {read=FItemIndent, write=SetItemIndent, default=8};
	__property int ItemSize = {read=FItemSize, write=SetItemSize, default=120};
	__property TdxTileControlGroupLayout GroupLayout = {read=FGroupLayout, write=SetGroupLayout, default=0};
	__property int GroupMaxRowCount = {read=FGroupMaxRowCount, write=SetGroupMaxRowCount, default=4};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxTileControlOptionsView(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlViewInfo : public TdxTileControlCustomViewInfo
{
	typedef TdxTileControlCustomViewInfo inherited;
	
private:
	TdxTileControlCells* FCells;
	System::Types::TRect FClientBounds;
	int FContentBottom;
	int FContentHeight;
	int FContentRight;
	int FContentWidth;
	bool FFixedGroupsOrigin;
	int FItemHalfIndent;
	int FItemLargeWidth;
	int FRealContentWidth;
	System::Types::TRect FTilesArea;
	int FRowCount;
	int FLeftScrollPos;
	System::StaticArray<TdxTileControlScrollButtonViewInfo*, 4> FScrollButtonViewInfo;
	TdxCustomTileControl* FTileControl;
	int FTopScrollPos;
	System::Types::TPoint FVisibleGroupsOrigin;
	void __fastcall CalculateDerivedItemSizes(void);
	int __fastcall GetGroupCount(void);
	TdxTileControlGroupLayout __fastcall GetGroupLayout(void);
	TdxTileControlGroupCollection* __fastcall GetGroups(void);
	TdxTileControlItemCollection* __fastcall GetItems(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	int __fastcall GetHorzScrollPage(void);
	int __fastcall GetSubColumnSize(void);
	TdxTileControlTitle* __fastcall GetTitle(void);
	void __fastcall CalculateClientBounds(void);
	void __fastcall CalculateTilesArea(void);
	void __fastcall CreateScrollButtonsViewInfo(void);
	void __fastcall DestroyScrollButtonsViewInfo(void);
	void __fastcall DoCenterContent(void);
	void __fastcall DoCenterContentHorz(void);
	void __fastcall DoCenterContentHorzAtHorizontalGroupLayout(const int AShift, const int AAreaRight);
	void __fastcall DoCenterContentHorzAtVerticalGroupLayout(const int AShift);
	void __fastcall DoCenterContentVert(void);
	void __fastcall DoCenterContentVertAtHorizontalGroupLayout(const int AShift);
	void __fastcall DoCenterContentVertAtVerticalGroupLayout(const int AShift, const int AAreaBottom);
	System::Types::TRect __fastcall GetContentBounds(void);
	int __fastcall GetGroupsCaptionsMaxHeight(void);
	int __fastcall GetTitleHeight(void);
	int __fastcall GetVertScrollPage(void);
	System::Types::TRect __fastcall GetVisibleGroupsBounds(void);
	bool __fastcall IsFixedContentLeftSide(void);
	bool __fastcall IsFixedContentTopSide(void);
	bool __fastcall IsScrollBarsParametersWasChanged(void);
	void __fastcall MakeVisibleOnHorz(const System::Types::TRect &ABounds, bool AIsLeftMost, bool AIsRightMost);
	void __fastcall MakeVisibleOnVert(const System::Types::TRect &ABounds, bool AIsLeftMost, bool AIsRightMost);
	void __fastcall MeasureGroupsCaptionsHeights(void);
	void __fastcall SetLeftScrollPos(int AValue);
	void __fastcall SetTopScrollPos(int AValue);
	
protected:
	TdxTileControlDragAndDropChanges* DragDropChanges;
	Cxclasses::TcxObjectList* FVirtualGroups;
	void __fastcall AddGroup(TdxTileControlGroup* AGroup);
	virtual void __fastcall AddGroups(void);
	void __fastcall AddItem(TdxTileControlItem* AItem);
	virtual void __fastcall AddItems(void);
	void __fastcall AddScrollButtons(void);
	void __fastcall AddVirtualGroupAfter(TdxTileControlGroup* AGroup);
	void __fastcall AddVirtualGroupBefore(TdxTileControlGroup* AGroup);
	void __fastcall CalculateRowCount(void);
	void __fastcall CalculateTitle(void);
	void __fastcall ClearGroupsOrigin(void);
	virtual void __fastcall DoCalculate(void);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	void __fastcall HideScrollButtons(void);
	bool __fastcall IsContentCentredHorz(void);
	bool __fastcall IsContentCentredVert(void);
	bool __fastcall IsContentNotCentredHorz(void);
	bool __fastcall IsContentNotCentredVert(void);
	bool __fastcall IsScrollAvailable(void)/* overload */;
	bool __fastcall IsScrollAvailable(Cxlookandfeelpainters::TcxArrowDirection ADirection)/* overload */;
	void __fastcall MakeVisible(const System::Types::TRect &ABounds, bool AIsLeftMost, bool AIsRightMost);
	virtual void __fastcall Scroll(const int DX, const int DY);
	void __fastcall StoreGroupsOrigin(void);
	
public:
	__fastcall virtual TdxTileControlViewInfo(TdxCustomTileControl* AOwner);
	__fastcall virtual ~TdxTileControlViewInfo(void);
	void __fastcall Calculate(void);
	void __fastcall Clear(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	int __fastcall GetItemWidth(bool AIsLarge = false);
	virtual void __fastcall RefreshState(void);
	__property TdxTileControlCells* Cells = {read=FCells, write=FCells};
	__property System::Types::TRect ClientBounds = {read=FClientBounds};
	__property int ContentHeight = {read=FContentHeight, write=FContentHeight, nodefault};
	__property int ContentWidth = {read=FContentWidth, write=FContentWidth, nodefault};
	__property TdxTileControlGroupCollection* Groups = {read=GetGroups};
	__property TdxTileControlGroupLayout GroupLayout = {read=GetGroupLayout, nodefault};
	__property int GroupsCount = {read=GetGroupCount, nodefault};
	__property int ItemHalfIndent = {read=FItemHalfIndent, nodefault};
	__property int ItemLargeWidth = {read=FItemLargeWidth, nodefault};
	__property TdxTileControlItemCollection* Items = {read=GetItems};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property int RowCount = {read=FRowCount, nodefault};
	__property int HorzScrollPage = {read=GetHorzScrollPage, nodefault};
	__property int LeftScrollPos = {read=FLeftScrollPos, write=SetLeftScrollPos, nodefault};
	__property int SubColumnSize = {read=GetSubColumnSize, nodefault};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
	__property System::Types::TRect TilesArea = {read=FTilesArea};
	__property TdxTileControlTitle* Title = {read=GetTitle};
	__property int TitleHeight = {read=GetTitleHeight, nodefault};
	__property int TopScrollPos = {read=FTopScrollPos, write=SetTopScrollPos, nodefault};
	__property int VertScrollPage = {read=GetVertScrollPage, nodefault};
	__property Cxclasses::TcxObjectList* VirtualGroups = {read=FVirtualGroups};
	__property System::Types::TPoint VisibleGroupsOrigin = {read=FVisibleGroupsOrigin};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlAssets;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlAssets : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxskinscore::TdxSkinImage* FBackButton;
	Dxskinscore::TdxSkinImage* FCustomButton;
	
public:
	__fastcall virtual TdxTileControlAssets(void);
	__fastcall virtual ~TdxTileControlAssets(void);
	__property Dxskinscore::TdxSkinImage* BackButton = {read=FBackButton};
	__property Dxskinscore::TdxSkinImage* CustomButton = {read=FCustomButton};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlPainter : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Dxskininfo::TdxSkinInfo* FSkinInfo;
	TdxCustomTileControl* FTileControl;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	bool __fastcall GetUserSkins(void);
	
protected:
	virtual void __fastcall DrawDefaultItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawDefaultItemCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R)/* overload */;
	virtual void __fastcall DrawDefaultItemCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor ACheckMarkColor, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	virtual void __fastcall DrawItemCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawStyleRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxTileControlCustomStyle* AStyle, const int ATextureOffsetX, const int ATextureOffsetY, Cxgraphics::TcxBorders ABorders);
	virtual System::Uitypes::TColor __fastcall GetActionBarDefaultBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetActionBarDefaultTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetCheckedItemCheckMarkColor(void);
	virtual System::Uitypes::TColor __fastcall GetCheckedItemFrameColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultItemTextBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultItemTextColor(void);
	virtual int __fastcall GetGroupCaptionDefaultFontSize(void);
	virtual System::Uitypes::TColor __fastcall GetGroupCaptionDefaultTextColor(void);
	virtual System::Types::TRect __fastcall GetPageTabContentOffset(void);
	virtual int __fastcall GetPageTabDefaultFontSize(void);
	virtual System::Uitypes::TColor __fastcall GetPageTabTextColor(Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall GetSelectionFocusedColor(void);
	virtual System::Uitypes::TColor __fastcall GetSelectionHottrackedColor(void);
	virtual System::Uitypes::TColor __fastcall GetSelectionSelectedColor(void);
	virtual int __fastcall GetTitleDefaultFontSize(void);
	virtual System::Uitypes::TColor __fastcall GetTitleDefaultTextColor(void);
	
public:
	__fastcall virtual TdxTileControlPainter(TdxCustomTileControl* ATileControl);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawColoredGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, Dxskinscore::TdxSkinImage* AGlyph, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawItemBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxTileControlCustomStyle* AStyle);
	virtual void __fastcall DrawItemPlace(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawPageTab(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawVirtualGroup(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall ValidatePainterData(void);
	__property System::Uitypes::TColor ActionBarDefaultBackgroundColor = {read=GetActionBarDefaultBackgroundColor, nodefault};
	__property System::Uitypes::TColor ActionBarDefaultTextColor = {read=GetActionBarDefaultTextColor, nodefault};
	__property System::Uitypes::TColor CheckedItemCheckMarkColor = {read=GetCheckedItemCheckMarkColor, nodefault};
	__property System::Uitypes::TColor CheckedItemFrameColor = {read=GetCheckedItemFrameColor, nodefault};
	__property System::Uitypes::TColor DefaultItemTextBackgroundColor = {read=GetDefaultItemTextBackgroundColor, nodefault};
	__property System::Uitypes::TColor DefaultItemTextColor = {read=GetDefaultItemTextColor, nodefault};
	__property int GroupCaptionDefaultFontSize = {read=GetGroupCaptionDefaultFontSize, nodefault};
	__property System::Uitypes::TColor GroupCaptionDefaultTextColor = {read=GetGroupCaptionDefaultTextColor, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property System::Types::TRect PageTabContentOffset = {read=GetPageTabContentOffset};
	__property int PageTabDefaultFontSize = {read=GetPageTabDefaultFontSize, nodefault};
	__property System::Uitypes::TColor PageTabTextColor[Cxlookandfeelpainters::TcxButtonState AState] = {read=GetPageTabTextColor};
	__property System::Uitypes::TColor SelectionFocusedColor = {read=GetSelectionFocusedColor, nodefault};
	__property System::Uitypes::TColor SelectionHottrackedColor = {read=GetSelectionHottrackedColor, nodefault};
	__property System::Uitypes::TColor SelectionSelectedColor = {read=GetSelectionSelectedColor, nodefault};
	__property Dxskininfo::TdxSkinInfo* SkinInfo = {read=FSkinInfo};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
	__property int TitleDefaultFontSize = {read=GetTitleDefaultFontSize, nodefault};
	__property System::Uitypes::TColor TitleDefaultTextColor = {read=GetTitleDefaultTextColor, nodefault};
	__property bool UseSkins = {read=GetUserSkins, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlPainter(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlTitle : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	bool FFontChanged;
	Dxgdiplusclasses::TdxSmartImage* FGlyph;
	System::Classes::TAlignment FGlyphAlignHorz;
	Cxclasses::TcxAlignmentVert FGlyphAlignVert;
	int FIndentHorz;
	int FIndentVert;
	System::Uitypes::TColor FTabsActiveTextColor;
	int FTabsFontSize;
	System::Uitypes::TColor FTabsHotTextColor;
	System::Uitypes::TColor FTabsTextColor;
	System::UnicodeString FText;
	System::Classes::TAlignment FTextAlignHorz;
	Cxclasses::TcxAlignmentVert FTextAlignVert;
	TdxTileControlTitleViewInfo* FViewInfo;
	bool FWordWrap;
	TdxCustomTileControl* __fastcall GetTileControl(void);
	bool __fastcall IsFontStored(void);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetGlyphAlignHorz(System::Classes::TAlignment AValue);
	void __fastcall SetGlyphAlignVert(Cxclasses::TcxAlignmentVert AValue);
	void __fastcall SetIndentHorz(int AValue);
	void __fastcall SetIndentVert(int AValue);
	void __fastcall SetTabsFontSize(int AValue);
	void __fastcall SetTabsActiveTextColor(System::Uitypes::TColor AValue);
	void __fastcall SetTabsHotTextColor(System::Uitypes::TColor AValue);
	void __fastcall SetTabsTextColor(System::Uitypes::TColor AValue);
	void __fastcall SetText(System::UnicodeString AValue);
	void __fastcall SetTextAlignHorz(System::Classes::TAlignment AValue);
	void __fastcall SetTextAlignVert(Cxclasses::TcxAlignmentVert AValue);
	void __fastcall SetWordWrap(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual TdxTileControlTitleViewInfo* __fastcall CreateViewInfo(void);
	void __fastcall FontChanged(System::TObject* Sender);
	virtual bool __fastcall IsChanged(void);
	__property System::Classes::TAlignment GlyphAlignHorz = {read=FGlyphAlignHorz, write=SetGlyphAlignHorz, default=1};
	__property Cxclasses::TcxAlignmentVert GlyphAlignVert = {read=FGlyphAlignVert, write=SetGlyphAlignVert, default=1};
	__property System::Classes::TAlignment TextAlignHorz = {read=FTextAlignHorz, write=SetTextAlignHorz, default=0};
	__property Cxclasses::TcxAlignmentVert TextAlignVert = {read=FTextAlignVert, write=SetTextAlignVert, default=1};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlTitleViewInfo* ViewInfo = {read=FViewInfo};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
	
public:
	__fastcall virtual TdxTileControlTitle(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTileControlTitle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=FGlyph, write=SetGlyph};
	__property int IndentHorz = {read=FIndentHorz, write=SetIndentHorz, default=6};
	__property int IndentVert = {read=FIndentVert, write=SetIndentVert, default=6};
	__property System::Uitypes::TColor TabsActiveTextColor = {read=FTabsActiveTextColor, write=SetTabsActiveTextColor, default=536870912};
	__property int TabsFontSize = {read=FTabsFontSize, write=SetTabsFontSize, default=12};
	__property System::Uitypes::TColor TabsHotTextColor = {read=FTabsHotTextColor, write=SetTabsHotTextColor, default=536870912};
	__property System::Uitypes::TColor TabsTextColor = {read=FTabsTextColor, write=SetTabsTextColor, default=536870912};
	__property System::UnicodeString Text = {read=FText, write=SetText};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlPageTabCellViewInfo;
class DELPHICLASS TdxTileControlDetailSiteTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlPageTabCellViewInfo : public TdxTileControlCustomCellViewInfo
{
	typedef TdxTileControlCustomCellViewInfo inherited;
	
private:
	TdxTileControlItem* FItem;
	TdxTileControlDetailSiteTitleViewInfo* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	bool __fastcall GetActive(void);
	System::UnicodeString __fastcall GetCaption(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AValue);
	
protected:
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	void __fastcall SetBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	
public:
	__fastcall TdxTileControlPageTabCellViewInfo(TdxTileControlDetailSiteTitleViewInfo* AOwner, TdxTileControlItem* AItem);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	virtual void __fastcall RefreshState(void);
	__property bool Active = {read=GetActive, nodefault};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property TdxTileControlItem* Item = {read=FItem};
	__property TdxTileControlDetailSiteTitleViewInfo* Owner = {read=FOwner};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlPageTabCellViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlCustomButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomButtonViewInfo : public TdxTileControlCustomCellViewInfo
{
	typedef TdxTileControlCustomCellViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxButtonState FState;
	void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState Value);
	
protected:
	virtual Dxskinscore::TdxSkinImage* __fastcall GetTexture(void) = 0 ;
	
public:
	virtual void __fastcall Invalidate(void) = 0 ;
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	void __fastcall SetBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	__property Dxskinscore::TdxSkinImage* Texture = {read=GetTexture};
public:
	/* TObject.Create */ inline __fastcall TdxTileControlCustomButtonViewInfo(void) : TdxTileControlCustomCellViewInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlCustomButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlDetailSiteBackButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDetailSiteBackButtonViewInfo : public TdxTileControlCustomButtonViewInfo
{
	typedef TdxTileControlCustomButtonViewInfo inherited;
	
private:
	TdxTileControlDetailSite* FOwner;
	
protected:
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual Dxskinscore::TdxSkinImage* __fastcall GetTexture(void);
	
public:
	__fastcall virtual TdxTileControlDetailSiteBackButtonViewInfo(TdxTileControlDetailSite* AOwner);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall RefreshState(void);
	__property TdxTileControlDetailSite* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlDetailSiteBackButtonViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlScrollButtonViewInfo : public TdxTileControlCustomCellViewInfo
{
	typedef TdxTileControlCustomCellViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxArrowDirection FDirection;
	TdxCustomTileControl* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	Cxclasses::TcxTimer* FTimer;
	TdxTileControlController* __fastcall GetController(void);
	TdxTileControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState AValue);
	void __fastcall TimerHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoScrollContent(void);
	virtual System::Types::TRect __fastcall GetArea(void);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	virtual void __fastcall Scroll(const int DX, const int DY);
	virtual void __fastcall MouseLeave(void);
	bool __fastcall PtInCaller(const System::Types::TPoint &P);
	__property Cxclasses::TcxTimer* Timer = {read=FTimer};
	
public:
	__fastcall virtual TdxTileControlScrollButtonViewInfo(TdxCustomTileControl* AOwner, Cxlookandfeelpainters::TcxArrowDirection ADirection);
	__fastcall virtual ~TdxTileControlScrollButtonViewInfo(void);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall RefreshState(void);
	__property System::Types::TRect Area = {read=GetArea};
	__property TdxTileControlController* Controller = {read=GetController};
	__property Cxlookandfeelpainters::TcxArrowDirection Direction = {read=FDirection, nodefault};
	__property TdxCustomTileControl* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	__property TdxTileControlViewInfo* ViewInfo = {read=GetViewInfo};
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlDetailSiteTitleViewInfo : public TdxTileControlTitleViewInfo
{
	typedef TdxTileControlTitleViewInfo inherited;
	
private:
	TdxTileControlDetailSiteBackButtonViewInfo* FBackButtonViewInfo;
	TdxTileControlDetailSite* FOwner;
	TdxTileControlCells* FTabs;
	Vcl::Graphics::TFont* FTabsFont;
	TdxTileControlItem* __fastcall GetItem(void);
	HIDESBASE TdxCustomTileControl* __fastcall GetTileControl(void);
	
protected:
	virtual void __fastcall CalculateBackButton(void);
	virtual void __fastcall CalculateTabs(void);
	virtual TdxTileControlDetailSiteBackButtonViewInfo* __fastcall CreateBackButtonViewInfo(void);
	virtual TdxTileControlPageTabCellViewInfo* __fastcall CreateTabCellViewInfo(TdxTileControlItem* AItem);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual int __fastcall GetTextLeftOffset(void);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	
public:
	__fastcall virtual TdxTileControlDetailSiteTitleViewInfo(TdxTileControlDetailSite* AOwner);
	__fastcall virtual ~TdxTileControlDetailSiteTitleViewInfo(void);
	virtual void __fastcall RefreshState(void);
	__property TdxTileControlDetailSiteBackButtonViewInfo* BackButtonViewInfo = {read=FBackButtonViewInfo};
	__property TdxTileControlItem* Item = {read=GetItem};
	__property TdxTileControlDetailSite* Owner = {read=FOwner};
	__property TdxTileControlCells* Tabs = {read=FTabs};
	__property Vcl::Graphics::TFont* TabsFont = {read=FTabsFont};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxTileControlDetailSite : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxTileControlCustomCellViewInfo* FPressedCell;
	TdxTileControlDetailSiteTitleViewInfo* FTitleViewInfo;
	Vcl::Controls::TWinControl* __fastcall GetActiveControl(void);
	TdxTileControlHitTest* __fastcall GetHitTest(void);
	int __fastcall GetIndex(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	TdxTileControlItem* __fastcall GetTileItem(void);
	void __fastcall SetPressedCell(TdxTileControlCustomCellViewInfo* AValue);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall DoPaint(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	bool __fastcall PtInCaller(const System::Types::TPoint &P);
	virtual void __fastcall ReallyMouseLeave(void);
	virtual TdxTileControlDetailSiteTitleViewInfo* __fastcall CreateTitleViewInfo(void);
	virtual void __fastcall DoActivateDetail(void);
	virtual void __fastcall DoDeactivateDetail(void);
	void __fastcall InitializeSite(int ALeft);
	__property TdxTileControlCustomCellViewInfo* PressedCell = {read=FPressedCell, write=SetPressedCell};
	__property TdxTileControlDetailSiteTitleViewInfo* TitleViewInfo = {read=FTitleViewInfo};
	
public:
	__fastcall virtual TdxTileControlDetailSite(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTileControlDetailSite(void);
	__property Vcl::Controls::TWinControl* ActiveControl = {read=GetActiveControl};
	__property TdxTileControlHitTest* HitTest = {read=GetHitTest};
	__property int Index = {read=GetIndex, nodefault};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	__property TdxTileControlItem* TileItem = {read=GetTileItem};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTileControlDetailSite(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	
};


enum TdxTileControlActionBarItemAlignment : unsigned char { abiaLeft, abiaRight };

enum TdxTileControlActionBarItemPosition : unsigned char { abipTopBar, abipBottomBar };

class DELPHICLASS TdxTileControlActionBarItem;
typedef void __fastcall (__closure *TdxTileControlActionBarItemEvent)(TdxTileControlActionBarItem* Sender);

class PASCALIMPLEMENTATION TdxTileControlActionBarItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxTileControlActionBarItemAlignment FAlign;
	System::UnicodeString FCaption;
	Dxskinscore::TdxSkinImage* FImage;
	TdxTileControlActionBarItemPosition FPosition;
	bool FVisible;
	TdxTileControlActionBarItemEvent FOnClick;
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetGlyph(void);
	int __fastcall GetGlyphFrameCount(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall SetAlign(TdxTileControlActionBarItemAlignment AValue);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetGlyphFrameCount(int AValue);
	void __fastcall SetPosition(TdxTileControlActionBarItemPosition AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	__property Dxskinscore::TdxSkinImage* Image = {read=FImage};
	
public:
	__fastcall virtual TdxTileControlActionBarItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTileControlActionBarItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Click(void);
	
__published:
	__property TdxTileControlActionBarItemAlignment Align = {read=FAlign, write=SetAlign, default=0};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphFrameCount = {read=GetGlyphFrameCount, write=SetGlyphFrameCount, default=1};
	__property TdxTileControlActionBarItemPosition Position = {read=FPosition, write=SetPosition, default=1};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property TdxTileControlActionBarItemEvent OnClick = {read=FOnClick, write=FOnClick};
};


class DELPHICLASS TdxTileControlActionBarItems;
class PASCALIMPLEMENTATION TdxTileControlActionBarItems : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxTileControlActionBarItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxTileControlActionBarItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxTileControlActionBarItem* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetItemPrefixName(void);
	
public:
	HIDESBASE TdxTileControlActionBarItem* __fastcall Add(void);
	__property TdxTileControlActionBarItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxTileControlActionBarItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxTileControlActionBarItems(void) { }
	
};


class DELPHICLASS TdxTileControlActionBarCustomItemViewInfo;
class DELPHICLASS TdxTileControlCustomActionBarViewInfo;
class DELPHICLASS TdxTileControlActionBarController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlActionBarCustomItemViewInfo : public TdxTileControlCustomButtonViewInfo
{
	typedef TdxTileControlCustomButtonViewInfo inherited;
	
private:
	TdxTileControlCustomActionBarViewInfo* FOwner;
	TdxTileControlActionBarController* __fastcall GetController(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	
protected:
	System::Types::TRect FGlyphBounds;
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextBounds(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual void __fastcall DoCalculate(void);
	
public:
	__fastcall TdxTileControlActionBarCustomItemViewInfo(TdxTileControlCustomActionBarViewInfo* AOwner);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall RefreshState(void);
	__property TdxTileControlActionBarController* Controller = {read=GetController};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property TdxTileControlCustomActionBarViewInfo* Owner = {read=FOwner};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
	__property System::UnicodeString Text = {read=GetText};
	__property System::Types::TRect TextBounds = {read=GetTextBounds};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlActionBarCustomItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlActionBars;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlCustomActionBarViewInfo : public TdxTileControlCustomViewInfo
{
	typedef TdxTileControlCustomViewInfo inherited;
	
private:
	TdxTileControlCells* FCells;
	TdxTileControlCustomActionBar* FOwner;
	TdxTileControlActionBars* __fastcall GetActionBars(void);
	TdxTileControlActionBarItems* __fastcall GetItems(void);
	TdxTileControlPainter* __fastcall GetPainter(void);
	
protected:
	virtual void __fastcall CalculateItems(const System::Types::TRect &ABounds);
	virtual TdxTileControlActionBarCustomItemViewInfo* __fastcall CreateItemViewInfo(TdxTileControlActionBarItem* AItem);
	virtual bool __fastcall GetCanDisplayItem(TdxTileControlActionBarItem* AItem);
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	
public:
	__fastcall virtual TdxTileControlCustomActionBarViewInfo(TdxTileControlCustomActionBar* AOwner);
	__fastcall virtual ~TdxTileControlCustomActionBarViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall MeasureHeight(void);
	virtual void __fastcall RefreshState(void);
	__property TdxTileControlActionBars* ActionBars = {read=GetActionBars};
	__property TdxTileControlCells* Cells = {read=FCells};
	__property TdxTileControlActionBarItems* Items = {read=GetItems};
	__property TdxTileControlCustomActionBar* Owner = {read=FOwner};
	__property TdxTileControlPainter* Painter = {read=GetPainter};
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlActionBarItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlActionBarItemViewInfo : public TdxTileControlActionBarCustomItemViewInfo
{
	typedef TdxTileControlActionBarCustomItemViewInfo inherited;
	
private:
	TdxTileControlActionBarItem* FItem;
	
protected:
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual Dxskinscore::TdxSkinImage* __fastcall GetTexture(void);
	
public:
	__fastcall TdxTileControlActionBarItemViewInfo(TdxTileControlCustomActionBarViewInfo* AOwner, TdxTileControlActionBarItem* AItem);
	__property TdxTileControlActionBarItem* Item = {read=FItem};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlActionBarItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlActionBarHitTest;
class PASCALIMPLEMENTATION TdxTileControlActionBarHitTest : public TdxTileControlHitTest
{
	typedef TdxTileControlHitTest inherited;
	
private:
	TdxTileControlCustomActionBar* FOwner;
	
protected:
	virtual TdxTileControlCustomViewInfo* __fastcall GetActiveViewInfo(void);
	
public:
	__fastcall TdxTileControlActionBarHitTest(TdxTileControlCustomActionBar* AOwner);
	__property TdxTileControlCustomActionBar* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlActionBarHitTest(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlActionBarController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::TObject* FHotCell;
	TdxTileControlCustomActionBar* FOwner;
	System::TObject* FPressedCell;
	TdxTileControlActionBarHitTest* __fastcall GetHitTest(void);
	TdxCustomTileControl* __fastcall GetTileControl(void);
	void __fastcall SetHotCell(System::TObject* AValue);
	void __fastcall SetPressedCell(System::TObject* AValue);
	
protected:
	virtual void __fastcall ProcessMouseLeftButtonClick(void);
	void __fastcall UncheckAllItems(void);
	
public:
	__fastcall virtual TdxTileControlActionBarController(TdxTileControlCustomActionBar* AOwner);
	__fastcall virtual ~TdxTileControlActionBarController(void);
	void __fastcall HideActionBars(void);
	void __fastcall RefreshStates(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	bool __fastcall PtInCaller(const System::Types::TPoint &P);
	__property TdxTileControlActionBarHitTest* HitTest = {read=GetHitTest};
	__property System::TObject* HotCell = {read=FHotCell, write=SetHotCell};
	__property TdxTileControlCustomActionBar* Owner = {read=FOwner};
	__property System::TObject* PressedCell = {read=FPressedCell, write=SetPressedCell};
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxTileControlCustomActionBar : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxTileControlActionBarController* FController;
	TdxTileControlActionBarHitTest* FHitTest;
	TdxCustomTileControl* FTileControl;
	TdxTileControlCustomActionBarViewInfo* FViewInfo;
	
protected:
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual TdxTileControlActionBarController* __fastcall CreateController(void);
	virtual TdxTileControlActionBarHitTest* __fastcall CreateHitTest(void);
	virtual TdxTileControlCustomActionBarViewInfo* __fastcall CreateViewInfo(void) = 0 ;
	virtual void __fastcall DoPaint(void);
	void __fastcall Recalculate(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual TdxTileControlCustomActionBar(TdxCustomTileControl* ATileControl);
	__fastcall virtual ~TdxTileControlCustomActionBar(void);
	__property TdxTileControlActionBarController* Controller = {read=FController};
	__property TdxTileControlActionBarHitTest* HitTest = {read=FHitTest};
	__property TdxCustomTileControl* TileControl = {read=FTileControl};
	__property TdxTileControlCustomActionBarViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTileControlCustomActionBar(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxTileControlBottomActionBar;
class PASCALIMPLEMENTATION TdxTileControlBottomActionBar : public TdxTileControlCustomActionBar
{
	typedef TdxTileControlCustomActionBar inherited;
	
protected:
	virtual TdxTileControlCustomActionBarViewInfo* __fastcall CreateViewInfo(void);
public:
	/* TdxTileControlCustomActionBar.Create */ inline __fastcall virtual TdxTileControlBottomActionBar(TdxCustomTileControl* ATileControl) : TdxTileControlCustomActionBar(ATileControl) { }
	/* TdxTileControlCustomActionBar.Destroy */ inline __fastcall virtual ~TdxTileControlBottomActionBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTileControlBottomActionBar(HWND ParentWindow) : TdxTileControlCustomActionBar(ParentWindow) { }
	
};


class DELPHICLASS TdxTileControlBottomActionBarViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlBottomActionBarViewInfo : public TdxTileControlCustomActionBarViewInfo
{
	typedef TdxTileControlCustomActionBarViewInfo inherited;
	
protected:
	virtual bool __fastcall GetCanDisplayItem(TdxTileControlActionBarItem* AItem);
public:
	/* TdxTileControlCustomActionBarViewInfo.Create */ inline __fastcall virtual TdxTileControlBottomActionBarViewInfo(TdxTileControlCustomActionBar* AOwner) : TdxTileControlCustomActionBarViewInfo(AOwner) { }
	/* TdxTileControlCustomActionBarViewInfo.Destroy */ inline __fastcall virtual ~TdxTileControlBottomActionBarViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlTopActionBar;
class PASCALIMPLEMENTATION TdxTileControlTopActionBar : public TdxTileControlCustomActionBar
{
	typedef TdxTileControlCustomActionBar inherited;
	
protected:
	virtual TdxTileControlCustomActionBarViewInfo* __fastcall CreateViewInfo(void);
public:
	/* TdxTileControlCustomActionBar.Create */ inline __fastcall virtual TdxTileControlTopActionBar(TdxCustomTileControl* ATileControl) : TdxTileControlCustomActionBar(ATileControl) { }
	/* TdxTileControlCustomActionBar.Destroy */ inline __fastcall virtual ~TdxTileControlTopActionBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTileControlTopActionBar(HWND ParentWindow) : TdxTileControlCustomActionBar(ParentWindow) { }
	
};


class DELPHICLASS TdxTileControlTopActionBarViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlTopActionBarViewInfo : public TdxTileControlCustomActionBarViewInfo
{
	typedef TdxTileControlCustomActionBarViewInfo inherited;
	
protected:
	virtual TdxTileControlActionBarCustomItemViewInfo* __fastcall CreateBackButtonViewInfo(void);
	virtual bool __fastcall GetCanDisplayItem(TdxTileControlActionBarItem* AItem);
	virtual void __fastcall CalculateItems(const System::Types::TRect &ABounds);
public:
	/* TdxTileControlCustomActionBarViewInfo.Create */ inline __fastcall virtual TdxTileControlTopActionBarViewInfo(TdxTileControlCustomActionBar* AOwner) : TdxTileControlCustomActionBarViewInfo(AOwner) { }
	/* TdxTileControlCustomActionBarViewInfo.Destroy */ inline __fastcall virtual ~TdxTileControlTopActionBarViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxTileControlTopActionBarBackButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlTopActionBarBackButtonViewInfo : public TdxTileControlActionBarCustomItemViewInfo
{
	typedef TdxTileControlActionBarCustomItemViewInfo inherited;
	
protected:
	virtual bool __fastcall GetHitTest(TdxTileControlHitTest* AHitTest);
	virtual Dxskinscore::TdxSkinImage* __fastcall GetTexture(void);
public:
	/* TdxTileControlActionBarCustomItemViewInfo.Create */ inline __fastcall TdxTileControlTopActionBarBackButtonViewInfo(TdxTileControlCustomActionBarViewInfo* AOwner) : TdxTileControlActionBarCustomItemViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxTileControlTopActionBarBackButtonViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTileControlActionBars : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	bool FFontChanged;
	int FIndentHorz;
	int FIndentVert;
	int FItemIndent;
	TdxTileControlActionBarItems* FItems;
	TdxCustomTileControl* __fastcall GetTileControl(void);
	bool __fastcall IsFontStored(void);
	void __fastcall FontChanged(System::TObject* Sender);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetIndentHorz(int AValue);
	void __fastcall SetIndentVert(int AValue);
	void __fastcall SetItemIndent(int AValue);
	void __fastcall SetItems(TdxTileControlActionBarItems* AValue);
	
protected:
	virtual TdxTileControlActionBarItems* __fastcall CreateItems(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall ItemsChangeHandler(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	__property TdxCustomTileControl* TileControl = {read=GetTileControl};
	
public:
	__fastcall virtual TdxTileControlActionBars(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxTileControlActionBars(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property int IndentHorz = {read=FIndentHorz, write=SetIndentHorz, default=24};
	__property int IndentVert = {read=FIndentVert, write=SetIndentVert, default=14};
	__property int ItemIndent = {read=FItemIndent, write=SetItemIndent, default=30};
	__property TdxTileControlActionBarItems* Items = {read=FItems, write=SetItems};
};

#pragma pack(pop)

enum TdxTileControlChange : unsigned char { tccLayout, tccSelection, tccItems };

typedef System::Set<TdxTileControlChange, TdxTileControlChange::tccLayout, TdxTileControlChange::tccItems>  TdxTileControlChanges;

typedef void __fastcall (__closure *TdxTileControlItemBeforeCheckEvent)(TdxCustomTileControl* Sender, TdxTileControlItem* AItem, bool &AAllow);

typedef void __fastcall (__closure *TdxTileControlItemCheckEvent)(TdxCustomTileControl* Sender, TdxTileControlItem* AItem);

typedef void __fastcall (__closure *TdxTileControlItemDragBeginEvent)(TdxCustomTileControl* Sender, TdxTileControlDragItemInfo* AInfo, bool &AAllow);

typedef void __fastcall (__closure *TdxTileControlItemDragEndEvent)(TdxCustomTileControl* Sender, TdxTileControlDragItemInfo* AInfo);

typedef void __fastcall (__closure *TdxTileControlItemDragOverEvent)(TdxCustomTileControl* Sender, TdxTileControlDragItemInfo* AInfo, bool &AAccept);

class PASCALIMPLEMENTATION TdxCustomTileControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxTileControlCustomActionBar* FActionBarBottom;
	TdxTileControlActionBars* FActionBars;
	TdxTileControlCustomActionBar* FActionBarTop;
	TdxTileControlDetailSite* FActiveDetail;
	Dxanimation::TdxImageAnimationTransition* FAnimation;
	TdxTileControlAssets* FAssets;
	TdxTileControlChanges FChanges;
	TdxTileControlController* FController;
	bool FDetailsAnimationInProcess;
	bool FDragDropInProcess;
	TdxTileControlDragItemInfo* FDragItemInfo;
	bool FForceCalculate;
	TdxTileControlGroupCollection* FGroups;
	TdxTileControlHitTest* FHitTest;
	bool FIsRestoring;
	TdxTileControlItemCollection* FItems;
	int FLockCount;
	TdxTileControlOptionsBehavior* FOptionsBehavior;
	TdxTileControlCustomItemOptionsAnimate* FOptionsItemAnimate;
	TdxTileControlOptionsView* FOptionsView;
	TdxTileControlPainter* FPainter;
	bool FRightButtonPressed;
	int FStoredVersion;
	System::UnicodeString FStoringName;
	TdxTileControlStyle* FStyle;
	TdxTileControlTitle* FTitle;
	TdxTileControlViewInfo* FViewInfo;
	TdxTileControlItemBeforeCheckEvent FOnItemBeforeCheck;
	TdxTileControlItemCheckEvent FOnItemCheck;
	TdxTileControlItemDragBeginEvent FOnItemDragBegin;
	TdxTileControlItemDragEndEvent FOnItemDragEnd;
	TdxTileControlItemDragOverEvent FOnItemDragOver;
	Cxstorage::TcxGetStoredPropertiesEvent FOnGetStoredProperties;
	Cxstorage::TcxGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	Cxstorage::TcxInitStoredObjectEvent FOnInitStoredObject;
	Cxstorage::TcxSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	void __fastcall AfterActiveDetailChangingAnimation(TdxTileControlDetailSite* AActiveDetail, TdxTileControlDetailSite* ANewDetail);
	void __fastcall AnimationHandler(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	void __fastcall BeforeActiveDetailChangingAnimation(TdxTileControlDetailSite* AActiveDetail, TdxTileControlDetailSite* ANewDetail);
	TdxTileControlHitTest* __fastcall GetActiveHitTest(void);
	TdxTileControlItem* __fastcall GetCheckedItem(int Index);
	int __fastcall GetCheckedItemCount(void);
	TdxTileControlGroup* __fastcall GetDraggedGroup(void);
	TdxTileControlItem* __fastcall GetDraggedItem(void);
	bool __fastcall GetIsLocked(void);
	void __fastcall InitializeDragItemInfo(void);
	bool __fastcall IsGroupDragged(void);
	bool __fastcall IsItemDragged(void);
	bool __fastcall IsStyleStored(void);
	bool __fastcall IsTitleStored(void);
	void __fastcall RefreshItem(TdxTileControlItem* AItem, const void * AData);
	void __fastcall SetActionBars(TdxTileControlActionBars* AValue);
	void __fastcall SetActiveDetail(TdxTileControlDetailSite* AValue);
	void __fastcall SetOptionsBehavior(TdxTileControlOptionsBehavior* AValue);
	void __fastcall SetOptionsItemAnimate(TdxTileControlCustomItemOptionsAnimate* AValue);
	void __fastcall SetOptionsView(TdxTileControlOptionsView* AValue);
	void __fastcall SetStyle(TdxTileControlStyle* AValue);
	void __fastcall SetTitle(TdxTileControlTitle* AValue);
	void __fastcall ScrollHorz(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall ScrollVert(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	
protected:
	TdxTileControlCheckedItems* FCheckedItems;
	void __fastcall AddChanges(TdxTileControlChanges AChanges);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall BringInternalControlsToFront(void);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	void __fastcall CheckChanges(void);
	virtual TdxTileControlCustomActionBar* __fastcall CreateActionBarBottom(void);
	virtual TdxTileControlActionBars* __fastcall CreateActionBars(void);
	virtual TdxTileControlCustomActionBar* __fastcall CreateActionBarTop(void);
	virtual TdxTileControlAssets* __fastcall CreateAssets(void);
	virtual TdxTileControlController* __fastcall CreateController(void);
	virtual TdxTileControlGroupCollection* __fastcall CreateGroupsCollection(void);
	virtual TdxTileControlHitTest* __fastcall CreateHitTest(void);
	virtual TdxTileControlItemCollection* __fastcall CreateItemsCollection(void);
	virtual TdxTileControlPainter* __fastcall CreatePainter(void);
	virtual TdxTileControlStyle* __fastcall CreateStyle(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual TdxTileControlTitle* __fastcall CreateTitle(void);
	virtual TdxTileControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroySubClasses(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DoActivateDetail(TdxTileControlDetailSite* ADetail);
	DYNAMIC void __fastcall DoCancelMode(void);
	virtual void __fastcall DoDeactivateDetail(TdxTileControlDetailSite* ADetail);
	virtual void __fastcall DoInitStoredObject(System::TObject* AObject);
	DYNAMIC bool __fastcall DoItemBeforeCheck(TdxTileControlItem* AItem);
	DYNAMIC void __fastcall DoItemCheck(TdxTileControlItem* AItem);
	DYNAMIC void __fastcall DoItemDragBegin(bool &AAllow);
	DYNAMIC void __fastcall DoItemDragEnd(void);
	DYNAMIC void __fastcall DoItemDragOver(bool &AAccept);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall DrawScrollBars(Cxgraphics::TcxCanvas* ACanvas);
	TdxTileControlGroup* __fastcall FindGroup(const System::UnicodeString AName);
	DYNAMIC void __fastcall FocusChanged(void);
	void __fastcall ForceUpdate(bool AUpdateAll = false);
	virtual System::Types::TRect __fastcall GetActionBarBottomBounds(void);
	virtual System::Types::TRect __fastcall GetActionBarTopBounds(void);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	virtual bool __fastcall IsActionBarTopVisible(void);
	virtual bool __fastcall IsActionBarBottomVisible(void);
	HIDESBASE bool __fastcall IsDestroying(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	HIDESBASE bool __fastcall IsLoading(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	TdxTileControlGroup* __fastcall InsertGroup(int AIndex);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	void __fastcall LockTimers(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ReCreateViewInfo(void);
	void __fastcall RefreshActionBars(void);
	void __fastcall RefreshItems(void);
	void __fastcall RemoveGroupIfEmpty(TdxTileControlGroup* AGroup);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetAutoSize(bool Value);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	void __fastcall StyleChanged(System::TObject* Sender);
	void __fastcall UnlockTimers(void);
	void __fastcall ValidateChanges(void);
	TdxTileControlGroupCollectionClass __fastcall GetGroupsClass(void);
	TdxTileControlItemCollectionClass __fastcall GetItemsClass(void);
	void __fastcall RestoreFrom(Cxstorage::TcxStorageType AStorageType, const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool ACreateChildren, bool ADeleteChildren, const System::UnicodeString ARestoreName);
	void __fastcall StoreTo(Cxstorage::TcxStorageType AStorageType, const System::UnicodeString AStorageName, System::Classes::TStream* AStorageStream, bool AReCreate, const System::UnicodeString ASaveName);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredObjectProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall StoredCreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall StoredDeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	__property TdxTileControlCustomActionBar* ActionBarBottom = {read=FActionBarBottom};
	__property TdxTileControlCustomActionBar* ActionBarTop = {read=FActionBarTop};
	__property Dxanimation::TdxImageAnimationTransition* Animation = {read=FAnimation};
	__property TdxTileControlAssets* Assets = {read=FAssets};
	__property TdxTileControlChanges Changes = {read=FChanges, write=FChanges, nodefault};
	__property bool DetailsAnimationInProcess = {read=FDetailsAnimationInProcess, nodefault};
	__property bool DragDropInProcess = {read=FDragDropInProcess, write=FDragDropInProcess, nodefault};
	__property TdxTileControlGroup* DraggedGroup = {read=GetDraggedGroup};
	__property TdxTileControlItem* DraggedItem = {read=GetDraggedItem};
	__property bool ForceCalculate = {read=FForceCalculate, nodefault};
	__property TdxTileControlHitTest* HitTest = {read=FHitTest};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property bool IsRestoring = {read=FIsRestoring, write=FIsRestoring, nodefault};
	__property int LockCount = {read=FLockCount, write=FLockCount, nodefault};
	__property TdxTileControlPainter* Painter = {read=FPainter};
	__property System::UnicodeString StoringName = {read=FStoringName, write=FStoringName};
	__property TdxTileControlViewInfo* ViewInfo = {read=FViewInfo};
	__property Cxstorage::TcxGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property Cxstorage::TcxGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property Cxstorage::TcxInitStoredObjectEvent OnInitStoredObject = {read=FOnInitStoredObject, write=FOnInitStoredObject};
	__property Cxstorage::TcxSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
	__property TdxTileControlItemBeforeCheckEvent OnItemBeforeCheck = {read=FOnItemBeforeCheck, write=FOnItemBeforeCheck};
	__property TdxTileControlItemCheckEvent OnItemCheck = {read=FOnItemCheck, write=FOnItemCheck};
	__property TdxTileControlItemDragBeginEvent OnItemDragBegin = {read=FOnItemDragBegin, write=FOnItemDragBegin};
	__property TdxTileControlItemDragEndEvent OnItemDragEnd = {read=FOnItemDragEnd, write=FOnItemDragEnd};
	__property TdxTileControlItemDragOverEvent OnItemDragOver = {read=FOnItemDragOver, write=FOnItemDragOver};
	__property int StoredVersion = {read=FStoredVersion, nodefault};
	
public:
	__fastcall virtual TdxCustomTileControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomTileControl(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	TdxTileControlGroup* __fastcall CreateGroup(void);
	TdxTileControlItem* __fastcall CreateItem(bool AIsLarge = false, TdxTileControlGroup* AGroup = (TdxTileControlGroup*)(0x0));
	void __fastcall DeleteItem(TdxTileControlItem* AItem);
	void __fastcall EndUpdate(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual bool __fastcall IsMouseInPressedArea(int X, int Y);
	virtual void __fastcall LayoutChanged(void);
	void __fastcall RemoveGroup(TdxTileControlGroup* AGroup);
	virtual bool __fastcall IsAnyActionBarVisible(void);
	virtual void __fastcall HideActionBars(void);
	virtual void __fastcall ShowActionBars(void);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, bool AChildrenCreating = false, bool AChildrenDeleting = false, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, bool AChildrenCreating = false, bool AChildrenDeleting = false, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, bool AChildrenCreating = false, bool AChildrenDeleting = false, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall StoreToIniFile(System::UnicodeString AStorageName, bool AReCreate = true, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToRegistry(System::UnicodeString AStorageName, bool AReCreate = true, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToStream(System::Classes::TStream* AStream, const System::UnicodeString ASaveName = System::UnicodeString());
	__property TdxTileControlActionBars* ActionBars = {read=FActionBars, write=SetActionBars};
	__property TdxTileControlDetailSite* ActiveDetail = {read=FActiveDetail, write=SetActiveDetail};
	__property TdxTileControlHitTest* ActiveHitTest = {read=GetActiveHitTest};
	__property TdxTileControlItem* CheckedItems[int Index] = {read=GetCheckedItem};
	__property int CheckedItemCount = {read=GetCheckedItemCount, nodefault};
	__property TdxTileControlController* Controller = {read=FController};
	__property TdxTileControlGroupCollection* Groups = {read=FGroups};
	__property TdxTileControlItemCollection* Items = {read=FItems};
	__property TdxTileControlOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TdxTileControlCustomItemOptionsAnimate* OptionsItemAnimate = {read=FOptionsItemAnimate, write=SetOptionsItemAnimate};
	__property TdxTileControlOptionsView* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property TdxTileControlStyle* Style = {read=FStyle, write=SetStyle, stored=IsStyleStored};
	__property TdxTileControlTitle* Title = {read=FTitle, write=SetTitle, stored=IsTitleStored};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomTileControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
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
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxTileControlDefaultActionBarsIndentHorz = System::Int8(0x18);
static const System::Int8 dxTileControlDefaultActionBarsIndentVert = System::Int8(0xe);
static const System::Int8 dxTileControlDefaultActionBarsItemIndent = System::Int8(0x1e);
static const bool dxTileControlDefaultAnimateText = true;
static const System::Int8 dxTileControlDefaultIndentHorz = System::Int8(0x4a);
static const System::Int8 dxTileControlDefaultIndentVert = System::Int8(0x28);
static const System::Int8 dxTileControlDefaultItemIndent = System::Int8(0x8);
static const System::Int8 dxTileControlDefaultItemSize = System::Int8(0x78);
static const System::Int8 dxTileControlDefaultGroupIndent = System::Int8(0x38);
static const System::Int8 dxTileControlDefaultRowCount = System::Int8(0x4);
static const System::Int8 dxTileControlDefaultItemRowCount = System::Int8(0x1);
static const System::Int8 dxTileControlItemMaxRowCount = System::Int8(0xa);
static const System::Int8 dxTileContolSizeGroupBorder = System::Int8(0x1);
static const System::Int8 dxTileFocusItemFrameSize = System::Int8(0x3);
static const System::Int8 dxTileItemObjectDefaultIndent = System::Int8(0x6);
static const System::Word dxTileControlInvisiblePosition = System::Word(0x3a98);
static const System::Int8 dxTileControlDefaultTabFontSize = System::Int8(0xc);
static const System::Int8 dxTileControlDefaultTitleFontSize = System::Int8(0x20);
static const System::Int8 dxTileControlDefaultGroupCaptionFontSize = System::Int8(0x10);
static const int dxTileDefaultActionBarColor = int(0xd2d2d2);
static const int dxTileDefaultActionBarTextColor = int(0);
static const System::Word dxTileControlDropArrowColor = System::Word(0xff00);
static const int dxTileItemLightColor = int(0x30a965);
static const int dxTileItemShadowColor = int(0x17934b);
static const int dxTileVirtualGroupBackgroundColor = int(0x444444);
static const int dxTileItemPlaceColor = int(0x444444);
static const System::Int8 dxTileCheckedItemCheckMarkAreaSize = System::Int8(0x2d);
static const System::Int8 dxTileCheckedItemCheckMarkPenSize = System::Int8(0x3);
static const System::Int8 dxTileCheckedItemFrameBorderSize = System::Int8(0x4);
static const System::Int8 dxTileControlAutoScrollWidth = System::Int8(0x14);
static const System::Int8 dxTileControlResizeDelta = System::Int8(0x14);
static const System::Int8 dxTileControlScrollStep = System::Int8(0x14);
static const System::Int8 dxTileControlDefaultScrollSync = System::Int8(0xf);
static const System::Int8 dxTileControlInflateAnimationStepsCount = System::Int8(0x7);
static const System::Word dxTileControlDefaultAnimationInterval = System::Word(0xbb8);
static const Dxanimation::TdxDrawAnimationMode dxTileControlDefaultAnimationMode = (Dxanimation::TdxDrawAnimationMode)(1);
static const System::Word dxTileDropAnimationStepCount = System::Word(0x2710);
static const System::Byte dxTileControlActionBarsAnimationTime = System::Byte(0xc8);
static const System::Word dxTileControlActivateDetailAnimationTime = System::Word(0x1f4);
static const System::Word dxTileControlHotTrackItemAnimationTime = System::Word(0x1f4);
static const System::Byte dxTileControlInflateAnimationTime = System::Byte(0x96);
static const System::Byte dxTileControlCenterContentAnimationTime = System::Byte(0x96);
static const System::Word dxTileControlFramesAnimationTime = System::Word(0x3e8);
static const System::Word dxTileControlRubberAnimationTime = System::Word(0x190);
static const System::Int8 tchtGroup = System::Int8(0x1);
static const System::Int8 tchtItem = System::Int8(0x2);
static const System::Int8 tchtPageTab = System::Int8(0x3);
static const System::Int8 tchtBackButton = System::Int8(0x4);
static const System::Int8 tchtActionBar = System::Int8(0x5);
static const System::Int8 tchtActionButton = System::Int8(0x6);
static const System::Int8 tchtScrollButton = System::Int8(0x7);
static const System::Int8 tchtScrollButtonArea = System::Int8(0x8);
static const System::Int8 tchtTitle = System::Int8(0x9);
static const System::Int8 tchtGroupCaption = System::Int8(0xa);
static const System::Int8 tchtActionBarTop = System::Int8(0xb);
static const System::Int8 tchtActionBarBottom = System::Int8(0xc);
static const System::Int8 dxTileControlStoringVersion = System::Int8(0x2);
extern PACKAGE TdxTileControlCustomDesignHelperClass dxDesignHelperClass;
}	/* namespace Dxcustomtilecontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMTILECONTROL)
using namespace Dxcustomtilecontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomtilecontrolHPP
