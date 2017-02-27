// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonBackstageViewGalleryControl.pas' rev: 24.00 (Win32)

#ifndef DxribbonbackstageviewgallerycontrolHPP
#define DxribbonbackstageviewgallerycontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxGallery.hpp>	// Pascal unit
#include <dxGalleryControl.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarStrs.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonbackstageviewgallerycontrol
{
//-- type declarations -------------------------------------------------------
enum TdxRibbonBackstageViewGalleryItemPinMode : unsigned char { bgipmNone, bgipmTag, bgipmButton };

class DELPHICLASS TdxRibbonBackstageViewGalleryItem;
class DELPHICLASS TdxRibbonBackstageViewGalleryItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryItem : public Dxgallerycontrol::TdxGalleryControlItem
{
	typedef Dxgallerycontrol::TdxGalleryControlItem inherited;
	
private:
	bool FAllowChangePinnedState;
	bool FPinned;
	TdxRibbonBackstageViewGalleryItemViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetAllowChangePinnedState(bool AValue);
	void __fastcall SetPinned(bool AValue);
	
protected:
	virtual Dxgallerycontrol::TdxGalleryItemViewInfo* __fastcall CreateViewInfo(void);
	__property TdxRibbonBackstageViewGalleryItemViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxRibbonBackstageViewGalleryItem(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AllowChangePinnedState = {read=FAllowChangePinnedState, write=SetAllowChangePinnedState, default=1};
	__property bool Pinned = {read=FPinned, write=SetPinned, default=0};
public:
	/* TdxGalleryControlItem.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBackstageViewGalleryControlController;
class DELPHICLASS TdxRibbonBackstageViewGalleryControlViewInfo;
class DELPHICLASS TdxRibbonBackstageViewGalleryControlPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryItemViewInfo : public Dxgallerycontrol::TdxGalleryItemViewInfo
{
	typedef Dxgallerycontrol::TdxGalleryItemViewInfo inherited;
	
private:
	typedef System::DynamicArray<System::Types::TRect> _TdxRibbonBackstageViewGalleryItemViewInfo__1;
	
	
private:
	TdxRibbonBackstageViewGalleryControlController* __fastcall GetController(void);
	TdxRibbonBackstageViewGalleryControlViewInfo* __fastcall GetControlViewInfo(void);
	TdxRibbonBackstageViewGalleryItem* __fastcall GetItem(void);
	HIDESBASE TdxRibbonBackstageViewGalleryControlPainter* __fastcall GetPainter(void);
	int __fastcall GetPartCount(void);
	System::Types::TRect __fastcall GetParts(int Index);
	System::Types::TSize __fastcall GetPinSize(void);
	
protected:
	_TdxRibbonBackstageViewGalleryItemViewInfo__1 FParts;
	virtual void __fastcall CalculateGlyphArea(const System::Types::TSize &AGlyphSize);
	virtual void __fastcall CalculateTextAreaContent(const System::Types::TRect &ABounds);
	virtual void __fastcall CheckTextAreaSize(void);
	Cxlookandfeelpainters::TdxGalleryItemViewState __fastcall GetPartState(int Index);
	virtual TdxRibbonBackstageViewGalleryItemPinMode __fastcall GetPinMode(void);
	virtual System::Types::TSize __fastcall GetTextAreaSize(void);
	
public:
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType, const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateTextAreaSizeLimitedByRowCount(Cxgraphics::TcxCanvas* ACanvas, int ARowCount);
	virtual void __fastcall CalculateTextAreaSizeLimitedByWidth(Cxgraphics::TcxCanvas* ACanvas, int AMaxWidth);
	int __fastcall GetPartAtPos(const System::Types::TPoint &P);
	virtual System::UnicodeString __fastcall GetPartHint(int APartIndex);
	__property TdxRibbonBackstageViewGalleryControlController* Controller = {read=GetController};
	__property TdxRibbonBackstageViewGalleryControlViewInfo* ControlViewInfo = {read=GetControlViewInfo};
	__property TdxRibbonBackstageViewGalleryItem* Item = {read=GetItem};
	__property TdxRibbonBackstageViewGalleryControlPainter* Painter = {read=GetPainter};
	__property int PartCount = {read=GetPartCount, nodefault};
	__property System::Types::TRect Parts[int Index] = {read=GetParts};
	__property Cxlookandfeelpainters::TdxGalleryItemViewState PartState[int Index] = {read=GetPartState};
	__property TdxRibbonBackstageViewGalleryItemPinMode PinMode = {read=GetPinMode, nodefault};
	__property System::Types::TSize PinSize = {read=GetPinSize};
public:
	/* TdxGalleryItemViewInfo.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryItemViewInfo(Dxgallerycontrol::TdxGalleryControlItem* AItem) : Dxgallerycontrol::TdxGalleryItemViewInfo(AItem) { }
	/* TdxGalleryItemViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBackstageViewGalleryItems;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryItems : public Dxgallerycontrol::TdxGalleryControlItems
{
	typedef Dxgallerycontrol::TdxGalleryControlItems inherited;
	
public:
	TdxRibbonBackstageViewGalleryItem* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	HIDESBASE TdxRibbonBackstageViewGalleryItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxRibbonBackstageViewGalleryItem* AValue);
	
protected:
	int __fastcall GetPinnedItemsCount(void);
	
public:
	HIDESBASE TdxRibbonBackstageViewGalleryItem* __fastcall Add(void);
	HIDESBASE TdxRibbonBackstageViewGalleryItem* __fastcall GetItemAtPos(const System::Types::TPoint &P);
	__property TdxRibbonBackstageViewGalleryItem* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Dxgallerycontrol::TdxGalleryControlItems(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryItems(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewGalleryGroup;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryGroup : public Dxgallerycontrol::TdxGalleryControlGroup
{
	typedef Dxgallerycontrol::TdxGalleryControlGroup inherited;
	
private:
	HIDESBASE TdxRibbonBackstageViewGalleryItems* __fastcall GetItems(void);
	
protected:
	virtual Dxgallerycontrol::TdxGalleryGroupViewInfo* __fastcall CreateViewInfo(void);
	virtual Dxgallery::TdxGalleryItemClass __fastcall GetGalleryItemClass(void);
	virtual Dxgallery::TdxGalleryItemsClass __fastcall GetGalleryItemsClass(void);
	
public:
	__property TdxRibbonBackstageViewGalleryItems* Items = {read=GetItems};
public:
	/* TdxGalleryControlGroup.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryGroup(System::Classes::TComponent* AOwner) : Dxgallerycontrol::TdxGalleryControlGroup(AOwner) { }
	/* TdxGalleryControlGroup.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryGroup(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBackstageViewGalleryGroupViewInfo;
class DELPHICLASS TdxRibbonBackstageViewGalleryControlOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryGroupViewInfo : public Dxgallerycontrol::TdxGalleryGroupViewInfo
{
	typedef Dxgallerycontrol::TdxGalleryGroupViewInfo inherited;
	
private:
	TdxRibbonBackstageViewGalleryGroup* __fastcall GetGroup(void);
	HIDESBASE TdxRibbonBackstageViewGalleryControlOptionsView* __fastcall GetOptionsView(void);
	HIDESBASE TdxRibbonBackstageViewGalleryControlPainter* __fastcall GetPainter(void);
	bool __fastcall GetSeparatePinnedItems(void);
	
protected:
	System::Types::TRect FSeparatorRect;
	virtual void __fastcall CalculateItems(Cxcontrols::TdxChangeType AType);
	virtual void __fastcall CalculatePinnableItemsPlace(const System::Types::TRect &AItemRect, Cxcontrols::TdxChangeType AType);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawSeparator(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual void __fastcall Calculate(Cxcontrols::TdxChangeType AType, const System::Types::TRect &ABounds);
	virtual int __fastcall GetMaxColumnCount(void);
	__property TdxRibbonBackstageViewGalleryGroup* Group = {read=GetGroup};
	__property TdxRibbonBackstageViewGalleryControlOptionsView* OptionsView = {read=GetOptionsView};
	__property TdxRibbonBackstageViewGalleryControlPainter* Painter = {read=GetPainter};
	__property bool SeparatePinnedItems = {read=GetSeparatePinnedItems, nodefault};
	__property System::Types::TRect SeparatorRect = {read=FSeparatorRect};
public:
	/* TdxGalleryGroupViewInfo.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryGroupViewInfo(Dxgallerycontrol::TdxGalleryControlGroup* AGroup) : Dxgallerycontrol::TdxGalleryGroupViewInfo(AGroup) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryGroupViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonbackstageViewGalleryGroups;
class PASCALIMPLEMENTATION TdxRibbonbackstageViewGalleryGroups : public Dxgallerycontrol::TdxGalleryControlGroups
{
	typedef Dxgallerycontrol::TdxGalleryControlGroups inherited;
	
public:
	TdxRibbonBackstageViewGalleryGroup* operator[](int AIndex) { return Groups[AIndex]; }
	
private:
	HIDESBASE TdxRibbonBackstageViewGalleryGroup* __fastcall GetGroup(int AIndex);
	HIDESBASE void __fastcall SetGroup(int AIndex, TdxRibbonBackstageViewGalleryGroup* AValue);
	
public:
	HIDESBASE TdxRibbonBackstageViewGalleryGroup* __fastcall Add(void);
	HIDESBASE bool __fastcall FindByCaption(const System::UnicodeString ACaption, /* out */ TdxRibbonBackstageViewGalleryGroup* &AGroup);
	HIDESBASE TdxRibbonBackstageViewGalleryItem* __fastcall GetItemAtPos(const System::Types::TPoint &P);
	__property TdxRibbonBackstageViewGalleryGroup* Groups[int AIndex] = {read=GetGroup, write=SetGroup/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxRibbonbackstageViewGalleryGroups(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Dxgallerycontrol::TdxGalleryControlGroups(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxRibbonbackstageViewGalleryGroups(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewGallery;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGallery : public Dxgallerycontrol::TdxGalleryControlStructure
{
	typedef Dxgallerycontrol::TdxGalleryControlStructure inherited;
	
private:
	HIDESBASE TdxRibbonbackstageViewGalleryGroups* __fastcall GetGroups(void);
	
protected:
	virtual Dxgallery::TdxGalleryGroupClass __fastcall GetGroupClass(void);
	virtual Dxgallery::TdxGalleryGroupsClass __fastcall GetGroupsClass(void);
	
public:
	__property TdxRibbonbackstageViewGalleryGroups* Groups = {read=GetGroups};
public:
	/* TdxCustomGallery.Create */ inline __fastcall virtual TdxRibbonBackstageViewGallery(System::Classes::TPersistent* AOwner) : Dxgallerycontrol::TdxGalleryControlStructure(AOwner) { }
	/* TdxCustomGallery.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGallery(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewGalleryControlOptionsViewItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlViewInfo : public Dxgallerycontrol::TdxGalleryControlViewInfo
{
	typedef Dxgallerycontrol::TdxGalleryControlViewInfo inherited;
	
private:
	TdxRibbonBackstageViewGalleryControlOptionsViewItem* __fastcall GetOptionsViewItem(void);
	HIDESBASE TdxRibbonBackstageViewGalleryControlPainter* __fastcall GetPainter(void);
	TdxRibbonBackstageViewGalleryItemPinMode __fastcall GetPinMode(void);
	
protected:
	virtual System::Types::TSize __fastcall DoCalculateItemSize(void);
	virtual int __fastcall GetTextAreaMaxWidth(const System::Types::TSize &AImageSize);
	
public:
	__property TdxRibbonBackstageViewGalleryControlOptionsViewItem* OptionsViewItem = {read=GetOptionsViewItem};
	__property TdxRibbonBackstageViewGalleryControlPainter* Painter = {read=GetPainter};
	__property TdxRibbonBackstageViewGalleryItemPinMode PinMode = {read=GetPinMode, nodefault};
public:
	/* TdxGalleryControlViewInfo.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlViewInfo(Dxgallerycontrol::TdxCustomGalleryControl* AGalleryControl) : Dxgallerycontrol::TdxGalleryControlViewInfo(AGalleryControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomRibbonBackstageViewGalleryControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlController : public Dxgallerycontrol::TdxGalleryControlController
{
	typedef Dxgallerycontrol::TdxGalleryControlController inherited;
	
private:
	int FKeyPressedCode;
	int FKeySelectedItemPartIndex;
	int FMouseHoveredItemPartIndex;
	void __fastcall CheckPartIndex(int &APartIndex, TdxRibbonBackstageViewGalleryItem* AItem);
	TdxRibbonBackstageViewGalleryItem* __fastcall GetKeySelectedItem(void);
	TdxRibbonBackstageViewGalleryItem* __fastcall GetMouseHoveredItem(void);
	HIDESBASE TdxCustomRibbonBackstageViewGalleryControl* __fastcall GetOwnerControl(void);
	TdxRibbonBackstageViewGalleryItemPinMode __fastcall GetPinMode(void);
	HIDESBASE void __fastcall SetKeySelectedItem(TdxRibbonBackstageViewGalleryItem* AValue);
	void __fastcall SetKeySelectedItemPartIndex(int AValue);
	HIDESBASE void __fastcall SetMouseHoveredItem(TdxRibbonBackstageViewGalleryItem* AValue);
	void __fastcall SetMouseHoveredItemPartIndex(int AValue);
	
protected:
	virtual void __fastcall ProcessItemClick(Dxgallerycontrol::TdxGalleryControlItem* AItem, int X, int Y);
	virtual void __fastcall ProcessItemPartClick(TdxRibbonBackstageViewGalleryItem* AItem, int APartIndex);
	virtual void __fastcall ProcessNavigationKey(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall UpdateMouseHoveredItem(const System::Types::TPoint &P);
	
public:
	virtual void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState AShift);
	__property int KeyPressedCode = {read=FKeyPressedCode, write=FKeyPressedCode, nodefault};
	__property TdxRibbonBackstageViewGalleryItem* KeySelectedItem = {read=GetKeySelectedItem, write=SetKeySelectedItem};
	__property int KeySelectedItemPartIndex = {read=FKeySelectedItemPartIndex, write=SetKeySelectedItemPartIndex, nodefault};
	__property TdxRibbonBackstageViewGalleryItem* MouseHoveredItem = {read=GetMouseHoveredItem, write=SetMouseHoveredItem};
	__property int MouseHoveredItemPartIndex = {read=FMouseHoveredItemPartIndex, write=SetMouseHoveredItemPartIndex, nodefault};
	__property TdxCustomRibbonBackstageViewGalleryControl* Owner = {read=GetOwnerControl};
	__property TdxRibbonBackstageViewGalleryItemPinMode PinMode = {read=GetPinMode, nodefault};
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlController(Dxgallerycontrol::TdxCustomGalleryControl* AOwner) : Dxgallerycontrol::TdxGalleryControlController(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlController(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlPainter : public Dxgallerycontrol::TdxGalleryControlPainter
{
	typedef Dxgallerycontrol::TdxGalleryControlPainter inherited;
	
private:
	int __fastcall GetPartState(const Cxlookandfeelpainters::TdxGalleryItemViewState &AState);
	Dxbar::_di_IdxSkin __fastcall GetSkin(void);
	
protected:
	virtual bool __fastcall DrawItemSelectionFirst(void);
	virtual System::Uitypes::TColor __fastcall GetGroupCaptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetItemCaptionTextColor(const Cxlookandfeelpainters::TdxGalleryItemViewState &AState);
	virtual System::Uitypes::TColor __fastcall GetItemDescriptionTextColor(const Cxlookandfeelpainters::TdxGalleryItemViewState &AState);
	
public:
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual int __fastcall GetBorderSize(void);
	virtual void __fastcall DrawGroupHeader(Cxgraphics::TcxCanvas* ACanvas, Dxgallerycontrol::TdxGalleryGroupViewInfo* const AViewInfo);
	virtual System::Types::TRect __fastcall GetGroupHeaderContentOffsets(void);
	virtual void __fastcall DrawItem(Cxgraphics::TcxCanvas* ACanvas, Dxgallerycontrol::TdxGalleryItemViewInfo* AViewInfo);
	virtual void __fastcall DrawItemPin(Cxgraphics::TcxCanvas* ACanvas, TdxRibbonBackstageViewGalleryItemViewInfo* AViewInfo);
	virtual void __fastcall DrawItemSelection(Cxgraphics::TcxCanvas* ACanvas, Dxgallerycontrol::TdxGalleryItemViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall GetPinButtonSize(void);
	virtual System::Types::TSize __fastcall GetPinTagSize(void);
	virtual void __fastcall DrawPinnedItemSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual int __fastcall GetPinnedItemSeparatorHeight(void);
	__property Dxbar::_di_IdxSkin Skin = {read=GetSkin};
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlPainter(Dxgallerycontrol::TdxCustomGalleryControl* AOwner) : Dxgallerycontrol::TdxGalleryControlPainter(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBackstageViewGalleryControlOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlOptionsBehavior : public Dxgallerycontrol::TdxGalleryControlOptionsBehavior
{
	typedef Dxgallerycontrol::TdxGalleryControlOptionsBehavior inherited;
	
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlOptionsBehavior(Dxgallerycontrol::TdxCustomGalleryControl* AOwner) : Dxgallerycontrol::TdxGalleryControlOptionsBehavior(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlOptionsBehavior(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlOptionsViewItem : public Dxgallerycontrol::TdxGalleryControlOptionsItem
{
	typedef Dxgallerycontrol::TdxGalleryControlOptionsItem inherited;
	
private:
	TdxRibbonBackstageViewGalleryItemPinMode FPinMode;
	void __fastcall SetPinMode(TdxRibbonBackstageViewGalleryItemPinMode AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxRibbonBackstageViewGalleryItemPinMode PinMode = {read=FPinMode, write=SetPinMode, default=0};
public:
	/* TdxGalleryControlOptionsItem.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlOptionsViewItem(Dxgallerycontrol::TdxCustomGalleryControl* AOwner) : Dxgallerycontrol::TdxGalleryControlOptionsItem(AOwner) { }
	/* TdxGalleryControlOptionsItem.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlOptionsViewItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBackstageViewGalleryControlOptionsViewGroup;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlOptionsViewGroup : public Dxgallerycontrol::TdxGalleryControlCustomOptions
{
	typedef Dxgallerycontrol::TdxGalleryControlCustomOptions inherited;
	
private:
	bool FPinnedItemSeparator;
	void __fastcall SetPinnedItemSeparator(bool AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxRibbonBackstageViewGalleryControlOptionsViewGroup(Dxgallerycontrol::TdxCustomGalleryControl* AOwner);
	
__published:
	__property bool PinnedItemSeparator = {read=FPinnedItemSeparator, write=SetPinnedItemSeparator, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlOptionsViewGroup(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlOptionsView : public Dxgallerycontrol::TdxGalleryControlOptionsView
{
	typedef Dxgallerycontrol::TdxGalleryControlOptionsView inherited;
	
private:
	TdxRibbonBackstageViewGalleryControlOptionsViewGroup* FGroup;
	TdxRibbonBackstageViewGalleryControlOptionsViewItem* __fastcall GetItem(void);
	void __fastcall SetGroup(TdxRibbonBackstageViewGalleryControlOptionsViewGroup* AValue);
	HIDESBASE void __fastcall SetItem(TdxRibbonBackstageViewGalleryControlOptionsViewItem* AValue);
	
protected:
	virtual TdxRibbonBackstageViewGalleryControlOptionsViewGroup* __fastcall CreateGroup(void);
	virtual Dxgallerycontrol::TdxGalleryControlOptionsItem* __fastcall CreateItem(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxRibbonBackstageViewGalleryControlOptionsView(Dxgallerycontrol::TdxCustomGalleryControl* AOwner);
	__fastcall virtual ~TdxRibbonBackstageViewGalleryControlOptionsView(void);
	
__published:
	__property TdxRibbonBackstageViewGalleryControlOptionsViewGroup* Group = {read=FGroup, write=SetGroup};
	__property TdxRibbonBackstageViewGalleryControlOptionsViewItem* Item = {read=GetItem, write=SetItem};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBackstageViewGalleryControlSizeGrip;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlSizeGrip : public Dxribbon::TdxRibbonSizeGrip
{
	typedef Dxribbon::TdxRibbonSizeGrip inherited;
	
protected:
	virtual Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
public:
	/* TcxSizeGrip.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlSizeGrip(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonSizeGrip(AOwner) { }
	/* TcxSizeGrip.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlSizeGrip(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewGalleryControlSizeGrip(HWND ParentWindow) : Dxribbon::TdxRibbonSizeGrip(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewGalleryControlScrollBar;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControlScrollBar : public Dxribbon::TdxRibbonScrollBar
{
	typedef Dxribbon::TdxRibbonScrollBar inherited;
	
protected:
	virtual Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
public:
	/* TcxControlScrollBar.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControlScrollBar(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonScrollBar(AOwner) { }
	/* TcxControlScrollBar.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControlScrollBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewGalleryControlScrollBar(HWND ParentWindow) : Dxribbon::TdxRibbonScrollBar(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TdxRibbonBackstageViewGalleryControlItemEvent)(System::TObject* Sender, TdxRibbonBackstageViewGalleryItem* AItem);

class PASCALIMPLEMENTATION TdxCustomRibbonBackstageViewGalleryControl : public Dxgallerycontrol::TdxCustomGalleryControl
{
	typedef Dxgallerycontrol::TdxCustomGalleryControl inherited;
	
private:
	Dxribbon::TdxCustomRibbon* FRibbon;
	TdxRibbonBackstageViewGalleryControlItemEvent FOnItemClick;
	void __fastcall ColorSchemeChangeHandler(System::TObject* Sender, const void *AEventArgs);
	TdxRibbonBackstageViewGalleryControlController* __fastcall GetController(void);
	HIDESBASE TdxRibbonBackstageViewGallery* __fastcall GetGallery(void);
	TdxRibbonBackstageViewGalleryControlOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TdxRibbonBackstageViewGalleryControlOptionsView* __fastcall GetOptionsView(void);
	TdxRibbonBackstageViewGalleryControlPainter* __fastcall GetPainter(void);
	TdxRibbonBackstageViewGalleryControlViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE void __fastcall SetGallery(TdxRibbonBackstageViewGallery* AValue);
	HIDESBASE void __fastcall SetOptionsBehavior(TdxRibbonBackstageViewGalleryControlOptionsBehavior* AValue);
	HIDESBASE void __fastcall SetOptionsView(TdxRibbonBackstageViewGalleryControlOptionsView* AValue);
	void __fastcall SetRibbon(Dxribbon::TdxCustomRibbon* AValue);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	
protected:
	virtual Dxgallerycontrol::TdxGalleryControlController* __fastcall CreateController(void);
	virtual Dxgallerycontrol::TdxGalleryControlStructure* __fastcall CreateGallery(void);
	virtual Dxgallerycontrol::TdxGalleryControlOptionsBehavior* __fastcall CreateOptionsBehavior(void);
	virtual Dxgallerycontrol::TdxGalleryControlOptionsView* __fastcall CreateOptionsView(void);
	virtual Dxgallerycontrol::TdxGalleryControlPainter* __fastcall CreatePainter(void);
	virtual Dxgallerycontrol::TdxGalleryControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DoClickItem(Dxgallery::TdxGalleryItem* AItem);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetBorderSize(void);
	virtual Cxcontrols::TcxControlScrollBarClass __fastcall GetScrollBarClass(Vcl::Forms::TScrollBarKind AKind);
	virtual Cxcontrols::TcxSizeGripClass __fastcall GetSizeGripClass(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	__property TdxRibbonBackstageViewGalleryControlController* Controller = {read=GetController};
	__property TdxRibbonBackstageViewGallery* Gallery = {read=GetGallery, write=SetGallery};
	__property TdxRibbonBackstageViewGalleryControlOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TdxRibbonBackstageViewGalleryControlOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TdxRibbonBackstageViewGalleryControlPainter* Painter = {read=GetPainter};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=FRibbon, write=SetRibbon};
	__property TdxRibbonBackstageViewGalleryControlViewInfo* ViewInfo = {read=GetViewInfo};
	__property TdxRibbonBackstageViewGalleryControlItemEvent OnItemClick = {read=FOnItemClick, write=FOnItemClick};
	
public:
	__fastcall virtual TdxCustomRibbonBackstageViewGalleryControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomRibbonBackstageViewGalleryControl(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomRibbonBackstageViewGalleryControl(HWND ParentWindow) : Dxgallerycontrol::TdxCustomGalleryControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewGalleryControl;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewGalleryControl : public TdxCustomRibbonBackstageViewGalleryControl
{
	typedef TdxCustomRibbonBackstageViewGalleryControl inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Enabled = {default=1};
	__property Font;
	__property PopupMenu;
	__property Visible = {default=1};
	__property AutoSizeMode = {default=0};
	__property BorderStyle = {default=1};
	__property Gallery;
	__property Images;
	__property OptionsBehavior;
	__property OptionsView;
	__property Ribbon;
	__property OnClick;
	__property OnDblClick;
	__property OnContextPopup;
	__property OnItemClick;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TdxCustomRibbonBackstageViewGalleryControl.Create */ inline __fastcall virtual TdxRibbonBackstageViewGalleryControl(System::Classes::TComponent* AOwner) : TdxCustomRibbonBackstageViewGalleryControl(AOwner) { }
	/* TdxCustomRibbonBackstageViewGalleryControl.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewGalleryControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewGalleryControl(HWND ParentWindow) : TdxCustomRibbonBackstageViewGalleryControl(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxribbonbackstageviewgallerycontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONBACKSTAGEVIEWGALLERYCONTROL)
using namespace Dxribbonbackstageviewgallerycontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonbackstageviewgallerycontrolHPP
