// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonGallery.pas' rev: 24.00 (Win32)

#ifndef DxribbongalleryHPP
#define DxribbongalleryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <dxBarAccessibility.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxRibbonForm.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Actions.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbongallery
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxRibbonGalleryGroupItemActionLinkClass;

typedef System::TMetaClass* TdxRibbonGalleryGroupItemClass;

enum TdxRibbonDropDownGalleryNavigationDirection : unsigned char { dgndNone, dgndUp, dgndDown };

enum TdxRibbonGalleryVisibilityState : unsigned char { gbsIndefinite, gbsFalse, gbsTrue };

enum TdxRibbonGalleryGroupItemTextKind : unsigned char { itkNone, itkCaption, itkCaptionAndDescription };

enum TdxRibbonGalleryImagePosition : unsigned char { gipLeft, gipRight, gipTop, gipBottom };

enum TdxRibbonGalleryItemSelectionMode : unsigned char { gsmNone, gsmSingle, gsmMultiple, gsmSingleInGroup };

enum TdxRibbonGallerySubmenuResizing : unsigned char { gsrNone, gsrHeight, gsrWidthAndHeight };

typedef TdxRibbonGallerySubmenuResizing TdxRibbonGalleryDropDownResizing;

typedef void __fastcall (__closure *TdxSelectionChangedEvent)(System::TObject* Sender, bool DeselectAll);

class DELPHICLASS TcxItemSize;
class PASCALIMPLEMENTATION TcxItemSize : public Cxgeometry::TcxSize
{
	typedef Cxgeometry::TcxSize inherited;
	
private:
	bool FAssigned;
	TcxItemSize* FParent;
	void __fastcall SetAssigned(bool AValue);
	
protected:
	virtual void __fastcall DoChange(void);
	virtual int __fastcall GetValue(int Index);
	virtual bool __fastcall IsSizeStored(int Index);
	virtual void __fastcall SetSize(const System::Types::TSize &Value);
	__property bool Assigned = {read=FAssigned, write=SetAssigned, nodefault};
	__property TcxItemSize* Parent = {read=FParent, write=FParent};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxItemSize(System::Classes::TPersistent* AOwner) : Cxgeometry::TcxSize(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxItemSize(void) { }
	
};


enum TdxRibbonGalleryItemPullHighlightingDirection : unsigned char { gphdStartToFinish, gphdFinishToStart };

enum TdxRibbonGalleryItemPullHighlightingMode : unsigned char { iphmNone, iphmStartToFinish, iphmFinishToStart };

class DELPHICLASS TdxRibbonGalleryItemPullHighlighting;
class PASCALIMPLEMENTATION TdxRibbonGalleryItemPullHighlighting : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FActive;
	bool FIsAssigned;
	TdxRibbonGalleryItemPullHighlightingDirection FDirection;
	TdxRibbonGalleryItemPullHighlighting* FParent;
	System::Classes::TNotifyEvent FOnChange;
	bool __fastcall GetActive(void);
	TdxRibbonGalleryItemPullHighlightingDirection __fastcall GetDirection(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetIsAssigned(bool Value);
	void __fastcall SetDirection(TdxRibbonGalleryItemPullHighlightingDirection Value);
	
protected:
	void __fastcall DoChange(void);
	virtual bool __fastcall IsActiveStored(void);
	virtual bool __fastcall IsDirectionStored(void);
	__property bool IsAssigned = {read=FIsAssigned, write=SetIsAssigned, nodefault};
	__property TdxRibbonGalleryItemPullHighlighting* Parent = {read=FParent, write=FParent};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, stored=IsActiveStored, nodefault};
	__property TdxRibbonGalleryItemPullHighlightingDirection Direction = {read=GetDirection, write=SetDirection, stored=IsDirectionStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryItemPullHighlighting(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxRibbonGalleryItemPullHighlighting(void) : System::Classes::TPersistent() { }
	
};


class DELPHICLASS TdxRibbonGalleryBaseOptions;
class DELPHICLASS TdxCustomRibbonGalleryItem;
class DELPHICLASS TdxInRibbonGalleryOptions;
class DELPHICLASS TdxInMenuGalleryOptions;
class PASCALIMPLEMENTATION TdxRibbonGalleryBaseOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	TdxCustomRibbonGalleryItem* FGalleryItem;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	TdxRibbonGalleryImagePosition FItemImagePosition;
	TcxItemSize* FItemImageSize;
	TdxRibbonGalleryItemPullHighlighting* FItemPullHighlighting;
	int FSpaceAfterGroupHeader;
	int FSpaceBetweenItemCaptionAndDescription;
	int FSpaceBetweenItemImageAndText;
	int FSpaceBetweenItemsHorizontally;
	int FSpaceBetweenItemsVertically;
	System::Classes::TNotifyEvent FOnChanged;
	TdxInRibbonGalleryOptions* __fastcall GetInRibbonOptions(void);
	TdxInMenuGalleryOptions* __fastcall GetInMenuOptions(void);
	void __fastcall FreeNotificationHandler(System::Classes::TComponent* ASender);
	void __fastcall ImageLinkChangeHandler(System::TObject* Sender);
	void __fastcall ReadSpaceBetweenItemsProperty(System::Classes::TReader* Reader);
	void __fastcall SetItemImageSize(TcxItemSize* Value);
	void __fastcall SetItemPullHighlighting(TdxRibbonGalleryItemPullHighlighting* Value);
	void __fastcall WriteSpaceBetweenItemsProperty(System::Classes::TWriter* Writer);
	
protected:
	TdxRibbonGalleryItemPullHighlightingMode __fastcall ObtainItemPullHighlightingMode(void);
	virtual void __fastcall Changed(void);
	void __fastcall CheckIntRange(int &Value);
	void __fastcall CheckItemsSpaceRange(int &Value);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoImageListContentChanged(void) = 0 ;
	virtual TdxRibbonGalleryImagePosition __fastcall GetItemImagePosition(void);
	virtual TcxItemSize* __fastcall GetItemSize(void);
	virtual TdxRibbonGalleryGroupItemTextKind __fastcall GetItemTextKind(void);
	virtual bool __fastcall GetRemoveHorizontalItemPadding(void);
	virtual bool __fastcall GetRemoveVerticalItemPadding(void);
	virtual int __fastcall GetSpaceAfterGroupHeader(void);
	virtual int __fastcall GetSpaceBetweenItemCaptionAndDescription(void);
	virtual int __fastcall GetSpaceBetweenItemImageAndText(void);
	virtual int __fastcall GetSpaceBetweenItems(void);
	virtual int __fastcall GetSpaceBetweenItemsHorizontally(void);
	virtual int __fastcall GetSpaceBetweenItemsVertically(void);
	virtual bool __fastcall IsItemImagePositionStored(void);
	virtual bool __fastcall IsItemImageSizeStored(void);
	virtual bool __fastcall IsSpaceAfterGroupHeaderStored(void);
	virtual bool __fastcall IsSpaceBetweenItemCaptionAndDescriptionStored(void);
	virtual bool __fastcall IsSpaceBetweenItemImageAndTextStored(void);
	virtual bool __fastcall IsSpaceBetweenItemsHorizontallyStored(void);
	virtual bool __fastcall IsSpaceBetweenItemsVerticallyStored(void);
	virtual void __fastcall ItemImageSizeChange(System::TObject* Sender);
	virtual void __fastcall ItemPullHighlightingChange(System::TObject* Sender);
	virtual void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	virtual void __fastcall SetItemImagePosition(TdxRibbonGalleryImagePosition Value);
	virtual void __fastcall SetItemSize(TcxItemSize* Value);
	virtual void __fastcall SetItemTextKind(TdxRibbonGalleryGroupItemTextKind Value);
	virtual void __fastcall SetSpaceAfterGroupHeader(int Value);
	virtual void __fastcall SetSpaceBetweenItemCaptionAndDescription(int Value);
	virtual void __fastcall SetSpaceBetweenItemImageAndText(int Value);
	virtual void __fastcall SetSpaceBetweenItems(int Value);
	virtual void __fastcall SetSpaceBetweenItemsHorizontally(int Value);
	virtual void __fastcall SetSpaceBetweenItemsVertically(int Value);
	__property Vcl::Imglist::TChangeLink* ImageChangeLink = {read=FImageChangeLink};
	__property bool RemoveHorizontalItemPadding = {read=GetRemoveHorizontalItemPadding, nodefault};
	__property bool RemoveVerticalItemPadding = {read=GetRemoveVerticalItemPadding, nodefault};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property TdxInRibbonGalleryOptions* InRibbonOptions = {read=GetInRibbonOptions};
	__property TdxInMenuGalleryOptions* InMenuOptions = {read=GetInMenuOptions};
	
public:
	__fastcall virtual TdxRibbonGalleryBaseOptions(TdxCustomRibbonGalleryItem* AOwner)/* overload */;
	__fastcall virtual ~TdxRibbonGalleryBaseOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TdxRibbonGalleryImagePosition ItemImagePosition = {read=GetItemImagePosition, write=SetItemImagePosition, stored=IsItemImagePositionStored, nodefault};
	__property TcxItemSize* ItemImageSize = {read=FItemImageSize, write=SetItemImageSize, stored=IsItemImageSizeStored};
	__property TdxRibbonGalleryGroupItemTextKind ItemTextKind = {read=GetItemTextKind, write=SetItemTextKind, stored=false, nodefault};
	__property TcxItemSize* ItemSize = {read=GetItemSize, write=SetItemSize, stored=false};
	__property TdxRibbonGalleryItemPullHighlighting* ItemPullHighlighting = {read=FItemPullHighlighting, write=SetItemPullHighlighting, stored=false};
	__property int SpaceAfterGroupHeader = {read=GetSpaceAfterGroupHeader, write=SetSpaceAfterGroupHeader, stored=IsSpaceAfterGroupHeaderStored, nodefault};
	__property int SpaceBetweenItemCaptionAndDescription = {read=GetSpaceBetweenItemCaptionAndDescription, write=SetSpaceBetweenItemCaptionAndDescription, stored=IsSpaceBetweenItemCaptionAndDescriptionStored, nodefault};
	__property int SpaceBetweenItemImageAndText = {read=GetSpaceBetweenItemImageAndText, write=SetSpaceBetweenItemImageAndText, stored=IsSpaceBetweenItemImageAndTextStored, nodefault};
	__property int SpaceBetweenItems = {read=GetSpaceBetweenItems, write=SetSpaceBetweenItems, nodefault};
	__property int SpaceBetweenItemsHorizontally = {read=GetSpaceBetweenItemsHorizontally, write=SetSpaceBetweenItemsHorizontally, stored=IsSpaceBetweenItemsHorizontallyStored, nodefault};
	__property int SpaceBetweenItemsVertically = {read=GetSpaceBetweenItemsVertically, write=SetSpaceBetweenItemsVertically, stored=IsSpaceBetweenItemsVerticallyStored, nodefault};
};


enum TdxRibbonGalleryGroupOptionsAssignedValue : unsigned char { avItemImagePosition, avItemImageSize, avItemPullHighlighting, avItemPullHighlightingMode, avItemSize, avItemTextKind, avSpaceAfterGroupHeader, avSpaceBetweenItemCaptionAndDescription, avSpaceBetweenItemImageAndText, avSpaceBetweenItems, avSpaceBetweenItemsHorizontally, avSpaceBetweenItemsVertically };

typedef System::Set<TdxRibbonGalleryGroupOptionsAssignedValue, TdxRibbonGalleryGroupOptionsAssignedValue::avItemImagePosition, TdxRibbonGalleryGroupOptionsAssignedValue::avSpaceBetweenItemsVertically>  TdxRibbonGalleryGroupOptionsAssignedValues;

class DELPHICLASS TdxRibbonGalleryGroupOptions;
class DELPHICLASS TdxRibbonGalleryGroup;
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupOptions : public TdxRibbonGalleryBaseOptions
{
	typedef TdxRibbonGalleryBaseOptions inherited;
	
private:
	TdxRibbonGalleryGroupOptionsAssignedValues FAssignedValues;
	TdxRibbonGalleryGroup* FGroup;
	TdxRibbonGalleryItemPullHighlightingMode FItemPullHighlightingMode;
	TcxItemSize* FItemSize;
	TdxRibbonGalleryGroupItemTextKind FItemTextKind;
	TdxRibbonGalleryBaseOptions* FParentOptions;
	TdxRibbonGalleryItemPullHighlightingMode __fastcall GetItemPullHighlightingMode(void);
	bool __fastcall IsItemPullHighlightingModeStored(void);
	bool __fastcall IsItemSizeStored(void);
	bool __fastcall IsItemTextKindStored(void);
	void __fastcall ItemSizeChange(System::TObject* Sender);
	void __fastcall SetAssignedValues(const TdxRibbonGalleryGroupOptionsAssignedValues Value);
	void __fastcall SetItemPullHighlightingMode(TdxRibbonGalleryItemPullHighlightingMode Value);
	
protected:
	virtual void __fastcall DoImageListContentChanged(void);
	virtual TdxRibbonGalleryImagePosition __fastcall GetItemImagePosition(void);
	virtual TcxItemSize* __fastcall GetItemSize(void);
	virtual TdxRibbonGalleryGroupItemTextKind __fastcall GetItemTextKind(void);
	virtual int __fastcall GetSpaceAfterGroupHeader(void);
	virtual int __fastcall GetSpaceBetweenItemCaptionAndDescription(void);
	virtual int __fastcall GetSpaceBetweenItemImageAndText(void);
	virtual int __fastcall GetSpaceBetweenItemsHorizontally(void);
	virtual int __fastcall GetSpaceBetweenItemsVertically(void);
	virtual bool __fastcall IsSpaceAfterGroupHeaderStored(void);
	virtual bool __fastcall IsSpaceBetweenItemCaptionAndDescriptionStored(void);
	virtual bool __fastcall IsSpaceBetweenItemImageAndTextStored(void);
	virtual bool __fastcall IsSpaceBetweenItemsHorizontallyStored(void);
	virtual bool __fastcall IsSpaceBetweenItemsVerticallyStored(void);
	virtual bool __fastcall IsItemImagePositionStored(void);
	virtual bool __fastcall IsItemImageSizeStored(void);
	virtual void __fastcall ItemImageSizeChange(System::TObject* Sender);
	virtual void __fastcall ItemPullHighlightingChange(System::TObject* Sender);
	virtual void __fastcall SetItemImagePosition(TdxRibbonGalleryImagePosition Value);
	virtual void __fastcall SetItemSize(TcxItemSize* Value);
	virtual void __fastcall SetItemTextKind(TdxRibbonGalleryGroupItemTextKind Value);
	virtual void __fastcall SetSpaceAfterGroupHeader(int Value);
	virtual void __fastcall SetSpaceBetweenItemCaptionAndDescription(int Value);
	virtual void __fastcall SetSpaceBetweenItemImageAndText(int Value);
	virtual void __fastcall SetSpaceBetweenItemsHorizontally(int Value);
	virtual void __fastcall SetSpaceBetweenItemsVertically(int Value);
	__property TdxRibbonGalleryGroup* Group = {read=FGroup};
	__property TdxRibbonGalleryBaseOptions* ParentOptions = {read=FParentOptions};
	
public:
	__fastcall virtual TdxRibbonGalleryGroupOptions(TdxRibbonGalleryBaseOptions* AParentOptions, TdxRibbonGalleryGroup* AGroup)/* overload */;
	__fastcall virtual ~TdxRibbonGalleryGroupOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxRibbonGalleryGroupOptionsAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property Images;
	__property ItemImagePosition;
	__property ItemImageSize;
	__property ItemTextKind = {stored=IsItemTextKindStored};
	__property ItemSize = {stored=IsItemSizeStored};
	__property ItemPullHighlighting;
	__property TdxRibbonGalleryItemPullHighlightingMode ItemPullHighlightingMode = {read=GetItemPullHighlightingMode, write=SetItemPullHighlightingMode, stored=IsItemPullHighlightingModeStored, nodefault};
	__property SpaceAfterGroupHeader;
	__property SpaceBetweenItemCaptionAndDescription;
	__property SpaceBetweenItemImageAndText;
	__property SpaceBetweenItemsHorizontally;
	__property SpaceBetweenItemsVertically;
public:
	/* TdxRibbonGalleryBaseOptions.Create */ inline __fastcall virtual TdxRibbonGalleryGroupOptions(TdxCustomRibbonGalleryItem* AOwner)/* overload */ : TdxRibbonGalleryBaseOptions(AOwner) { }
	
};


class DELPHICLASS TdxCustomRibbonGalleryOptions;
class PASCALIMPLEMENTATION TdxCustomRibbonGalleryOptions : public TdxRibbonGalleryBaseOptions
{
	typedef TdxRibbonGalleryBaseOptions inherited;
	
private:
	bool FItemAllowDeselect;
	TdxRibbonGalleryItemSelectionMode FItemSelectionMode;
	bool FShowItemHint;
	bool FShowScrollbar;
	int FSpaceBetweenGroups;
	int FSpaceBetweenItemsAndBorder;
	TdxSelectionChangedEvent FOnSelectionChanged;
	int FColumnCount;
	System::Classes::TNotifyEvent FOnColumnCountChanged;
	void __fastcall DoSelectionChanged(bool DeselectAll);
	bool __fastcall GetCanCollapse(void);
	bool __fastcall GetCollapsed(void);
	bool __fastcall GetEqualItemSizeInAllGroups(void);
	TcxItemSize* __fastcall GetItemSizeInRibbon(void);
	int __fastcall GetMinColumnCount(void);
	int __fastcall GetRowCount(void);
	TdxRibbonGallerySubmenuResizing __fastcall GetSubmenuResizing(void);
	void __fastcall SetCanCollapse(bool Value);
	void __fastcall SetCollapsed(bool Value);
	void __fastcall SetColumnCount(int Value);
	void __fastcall SetSpaceBetweenGroups(int Value);
	void __fastcall SetEqualItemSizeInAllGroups(bool Value);
	void __fastcall SetItemSelectionMode(TdxRibbonGalleryItemSelectionMode Value);
	void __fastcall SetItemSizeInRibbon(TcxItemSize* Value);
	void __fastcall SetMinColumnCount(int Value);
	void __fastcall SetRowCount(int Value);
	void __fastcall SetShowItemHint(bool Value);
	void __fastcall SetSpaceBetweenItemsAndBorder(int Value);
	void __fastcall SetSubmenuResizing(TdxRibbonGallerySubmenuResizing Value);
	void __fastcall ColumnCountChanged(void);
	
protected:
	virtual void __fastcall DoImageListContentChanged(void);
	__property bool ShowScrollbar = {read=FShowScrollbar, write=FShowScrollbar, nodefault};
	__property bool CanCollapse = {read=GetCanCollapse, write=SetCanCollapse, stored=false, nodefault};
	__property bool Collapsed = {read=GetCollapsed, write=SetCollapsed, stored=false, nodefault};
	__property bool EqualItemSizeInAllGroups = {read=GetEqualItemSizeInAllGroups, write=SetEqualItemSizeInAllGroups, stored=false, nodefault};
	__property bool ItemAllowDeselect = {read=FItemAllowDeselect, write=FItemAllowDeselect, default=0};
	__property TdxRibbonGalleryItemSelectionMode ItemSelectionMode = {read=FItemSelectionMode, write=SetItemSelectionMode, default=1};
	__property TcxItemSize* ItemSizeInRibbon = {read=GetItemSizeInRibbon, write=SetItemSizeInRibbon, stored=false};
	__property int SpaceBetweenGroups = {read=FSpaceBetweenGroups, write=SetSpaceBetweenGroups, default=0};
	__property int SpaceBetweenItemsAndBorder = {read=FSpaceBetweenItemsAndBorder, write=SetSpaceBetweenItemsAndBorder, default=1};
	__property bool ShowItemHint = {read=FShowItemHint, write=SetShowItemHint, default=1};
	__property TdxRibbonGallerySubmenuResizing SubmenuResizing = {read=GetSubmenuResizing, write=SetSubmenuResizing, stored=false, nodefault};
	__property int ColumnCount = {read=FColumnCount, write=SetColumnCount, default=5};
	__property int MinColumnCount = {read=GetMinColumnCount, write=SetMinColumnCount, stored=false, nodefault};
	__property int RowCount = {read=GetRowCount, write=SetRowCount, stored=false, nodefault};
	__property TdxSelectionChangedEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
	__property System::Classes::TNotifyEvent OnColumnCountChanged = {read=FOnColumnCountChanged, write=FOnColumnCountChanged};
	
public:
	__fastcall virtual TdxCustomRibbonGalleryOptions(TdxCustomRibbonGalleryItem* AOwner)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TdxRibbonGalleryBaseOptions.Destroy */ inline __fastcall virtual ~TdxCustomRibbonGalleryOptions(void) { }
	
};


class DELPHICLASS TdxRibbonGalleryOptions;
class PASCALIMPLEMENTATION TdxRibbonGalleryOptions : public TdxCustomRibbonGalleryOptions
{
	typedef TdxCustomRibbonGalleryOptions inherited;
	
__published:
	__property CanCollapse;
	__property Collapsed;
	__property ColumnCount = {default=5};
	__property EqualItemSizeInAllGroups;
	__property Images;
	__property ItemAllowDeselect = {default=0};
	__property ItemImagePosition;
	__property ItemImageSize;
	__property ItemPullHighlighting;
	__property ItemSelectionMode = {default=1};
	__property ItemSize;
	__property ItemSizeInRibbon;
	__property ItemTextKind;
	__property MinColumnCount;
	__property RowCount;
	__property ShowItemHint = {default=1};
	__property ShowScrollbar = {stored=false};
	__property SpaceAfterGroupHeader;
	__property SpaceBetweenGroups = {default=0};
	__property SpaceBetweenItemCaptionAndDescription;
	__property SpaceBetweenItemImageAndText;
	__property SpaceBetweenItemsAndBorder = {default=1};
	__property SpaceBetweenItemsHorizontally;
	__property SpaceBetweenItemsVertically;
	__property SubmenuResizing;
public:
	/* TdxCustomRibbonGalleryOptions.Create */ inline __fastcall virtual TdxRibbonGalleryOptions(TdxCustomRibbonGalleryItem* AOwner)/* overload */ : TdxCustomRibbonGalleryOptions(AOwner) { }
	
public:
	/* TdxRibbonGalleryBaseOptions.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryOptions(void) { }
	
};


class PASCALIMPLEMENTATION TdxInRibbonGalleryOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FAlwaysShowItemCaption;
	bool FCanCollapse;
	bool FCollapsed;
	TcxItemSize* FItemSize;
	int FMinColumnCount;
	System::Classes::TNotifyEvent FOnChanged;
	System::Classes::TNotifyEvent FOnMinColumnCountChanged;
	void __fastcall Changed(void);
	void __fastcall MinColumnCountChanged(void);
	void __fastcall ItemSizeChange(System::TObject* Sender);
	void __fastcall SetAlwaysShowItemCaption(bool Value);
	void __fastcall SetCanCollapse(bool Value);
	void __fastcall SetCollapsed(bool Value);
	void __fastcall SetItemSize(TcxItemSize* Value);
	void __fastcall SetMinColumnCount(int Value);
	
protected:
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property System::Classes::TNotifyEvent OnMinColumnCountChanged = {read=FOnMinColumnCountChanged, write=FOnMinColumnCountChanged};
	
public:
	__fastcall TdxInRibbonGalleryOptions(void);
	__fastcall virtual ~TdxInRibbonGalleryOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AlwaysShowItemCaption = {read=FAlwaysShowItemCaption, write=SetAlwaysShowItemCaption, default=0};
	__property bool CanCollapse = {read=FCanCollapse, write=SetCanCollapse, default=1};
	__property bool Collapsed = {read=FCollapsed, write=SetCollapsed, default=0};
	__property TcxItemSize* ItemSize = {read=FItemSize, write=SetItemSize};
	__property int MinColumnCount = {read=FMinColumnCount, write=SetMinColumnCount, default=2};
};


class PASCALIMPLEMENTATION TdxInMenuGalleryOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FCollapsedInSubmenu;
	bool FEqualItemSizeInAllGroups;
	TdxRibbonGalleryItemPullHighlightingMode FItemPullHighlightingMode;
	TcxItemSize* FItemSize;
	TdxRibbonGalleryGroupItemTextKind FItemTextKind;
	TdxRibbonGallerySubmenuResizing FDropDownGalleryResizing;
	int FRowCount;
	System::Classes::TNotifyEvent FOnChanged;
	void __fastcall Changed(void);
	bool __fastcall IsItemSizeStored(void);
	void __fastcall ItemSizeChange(System::TObject* Sender);
	void __fastcall SetCollapsedInSubmenu(bool Value);
	void __fastcall SetEqualItemSizeInAllGroups(bool Value);
	void __fastcall SetItemPullHighlightingMode(TdxRibbonGalleryItemPullHighlightingMode Value);
	void __fastcall SetItemSize(TcxItemSize* Value);
	void __fastcall SetItemTextKind(TdxRibbonGalleryGroupItemTextKind Value);
	void __fastcall SetRowCount(int Value);
	
protected:
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall TdxInMenuGalleryOptions(void);
	__fastcall virtual ~TdxInMenuGalleryOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CollapsedInSubmenu = {read=FCollapsedInSubmenu, write=SetCollapsedInSubmenu, default=1};
	__property TdxRibbonGallerySubmenuResizing DropDownGalleryResizing = {read=FDropDownGalleryResizing, write=FDropDownGalleryResizing, default=2};
	__property bool EqualItemSizeInAllGroups = {read=FEqualItemSizeInAllGroups, write=SetEqualItemSizeInAllGroups, default=1};
	__property TdxRibbonGalleryItemPullHighlightingMode ItemPullHighlightingMode = {read=FItemPullHighlightingMode, write=SetItemPullHighlightingMode, default=0};
	__property TcxItemSize* ItemSize = {read=FItemSize, write=SetItemSize, stored=IsItemSizeStored};
	__property TdxRibbonGalleryGroupItemTextKind ItemTextKind = {read=FItemTextKind, write=SetItemTextKind, default=1};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=0};
};


class DELPHICLASS TdxRibbonGalleryGroupHeader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupHeader : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	System::UnicodeString FCaption;
	TdxRibbonGalleryGroup* FOwner;
	bool FVisible;
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall TdxRibbonGalleryGroupHeader(TdxRibbonGalleryGroup* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryGroupHeader(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryGroupItem;
class DELPHICLASS TdxRibbonGalleryGroupItemActionLink;
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxRibbonGalleryGroupItemActionLink* FActionLink;
	System::UnicodeString FCaption;
	System::UnicodeString FDescription;
	bool FEnabled;
	Vcl::Graphics::TBitmap* FGlyph;
	Vcl::Graphics::TBitmap* FGlyphInDropDown;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	bool FSelected;
	System::Classes::TNotifyEvent FOnClick;
	Vcl::Controls::TMouseEvent FOnMouseDown;
	Vcl::Controls::TMouseMoveEvent FOnMouseMove;
	Vcl::Controls::TMouseEvent FOnMouseUp;
	void __fastcall DoActionChange(System::TObject* Sender);
	System::Classes::TBasicAction* __fastcall GetAction(void);
	TdxCustomRibbonGalleryItem* __fastcall GetGalleryItem(void);
	TdxRibbonGalleryGroup* __fastcall GetGroup(void);
	bool __fastcall GetSelected(void);
	TdxRibbonGalleryItemSelectionMode __fastcall GetSelectionMode(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsOnClickStored(void);
	bool __fastcall IsSelectedStored(void);
	void __fastcall SetAction(System::Classes::TBasicAction* Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphInDropDown(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetSelected(bool Value);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	DYNAMIC void __fastcall DoClick(void);
	DYNAMIC TdxRibbonGalleryGroupItemActionLinkClass __fastcall GetActionLinkClass(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	bool __fastcall GetEnabled(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall UpdateActionLink(void);
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=GetGalleryItem};
	__property Vcl::Graphics::TBitmap* GlyphInDropDown = {read=FGlyphInDropDown, write=SetGlyphInDropDown};
	__property bool LoadedSelected = {read=FSelected, write=FSelected, nodefault};
	__property TdxRibbonGalleryItemSelectionMode SelectionMode = {read=GetSelectionMode, nodefault};
	
public:
	__fastcall virtual TdxRibbonGalleryGroupItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonGalleryGroupItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxRibbonGalleryGroup* Group = {read=GetGroup};
	
__published:
	__property System::Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property System::UnicodeString Description = {read=FDescription, write=SetDescription};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property System::UnicodeString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property bool Selected = {read=GetSelected, write=SetSelected, stored=IsSelectedStored, default=0};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
	__property Vcl::Controls::TMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property Vcl::Controls::TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property Vcl::Controls::TMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
};


class DELPHICLASS TdxRibbonGalleryGroupItems;
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupItems : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxRibbonGalleryGroupItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxRibbonGalleryGroup* __fastcall GetGroup(void);
	HIDESBASE TdxRibbonGalleryGroupItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonGalleryGroupItem* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem);
	__property TdxRibbonGalleryGroup* Group = {read=GetGroup};
	
public:
	HIDESBASE TdxRibbonGalleryGroupItem* __fastcall Add(void);
	HIDESBASE TdxRibbonGalleryGroupItem* __fastcall Insert(int Index);
	__property TdxRibbonGalleryGroupItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxRibbonGalleryGroupItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryGroupItems(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryGroup : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxRibbonGalleryGroupHeader* FHeader;
	TdxRibbonGalleryGroupItems* FItems;
	TdxRibbonGalleryGroupOptions* FOptions;
	bool FVisible;
	TdxCustomRibbonGalleryItem* __fastcall GetGalleryItem(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	void __fastcall ItemsChange(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall CreateItems(void);
	void __fastcall ReadItems(System::Classes::TReader* AReader);
	void __fastcall SetHeader(TdxRibbonGalleryGroupHeader* Value);
	void __fastcall SetItems(TdxRibbonGalleryGroupItems* Value);
	void __fastcall SetOptions(TdxRibbonGalleryGroupOptions* Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	
public:
	__fastcall virtual TdxRibbonGalleryGroup(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonGalleryGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=GetGalleryItem};
	__property TdxRibbonGalleryGroupItems* Items = {read=FItems, write=SetItems};
	
__published:
	__property TdxRibbonGalleryGroupHeader* Header = {read=FHeader, write=SetHeader};
	__property TdxRibbonGalleryGroupOptions* Options = {read=FOptions, write=SetOptions};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryGroups;
class PASCALIMPLEMENTATION TdxRibbonGalleryGroups : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxRibbonGalleryGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomRibbonGalleryItem* __fastcall GetGalleryItem(void);
	HIDESBASE TdxRibbonGalleryGroup* __fastcall GetItem(int Index);
	void __fastcall RemoveFromFilter(Cxclasses::TcxComponentCollectionItem* AItem);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonGalleryGroup* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Notify(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem);
	virtual void __fastcall Update(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=GetGalleryItem};
	
public:
	HIDESBASE TdxRibbonGalleryGroup* __fastcall Add(void);
	HIDESBASE TdxRibbonGalleryGroup* __fastcall Insert(int Index);
	__property TdxRibbonGalleryGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxRibbonGalleryGroups(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryGroups(void) { }
	
};


class DELPHICLASS TdxRibbonGalleryFilterCategoryGroups;
class DELPHICLASS TdxRibbonGalleryFilterCategory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryFilterCategoryGroups : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxRibbonGalleryGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TdxRibbonGalleryFilterCategory* FFilterCategory;
	bool __fastcall CanAddGroup(TdxRibbonGalleryGroup* AGroup);
	TdxRibbonGalleryGroup* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	
public:
	__fastcall TdxRibbonGalleryFilterCategoryGroups(TdxRibbonGalleryFilterCategory* AFilterCategory);
	HIDESBASE void __fastcall Assign(TdxRibbonGalleryFilterCategoryGroups* ASource);
	HIDESBASE int __fastcall Add(TdxRibbonGalleryGroup* AGroup);
	HIDESBASE void __fastcall Insert(int AIndex, TdxRibbonGalleryGroup* AGroup);
	__property TdxRibbonGalleryFilterCategory* FilterCategory = {read=FFilterCategory};
	__property TdxRibbonGalleryGroup* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryFilterCategoryGroups(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryFilterCategory : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FCaption;
	System::Classes::TList* FGroupIndexes;
	TdxRibbonGalleryFilterCategoryGroups* FGroups;
	void __fastcall AddGroupByGroupIndex(int AIndex);
	TdxCustomRibbonGalleryItem* __fastcall GetGalleryItem(void);
	void __fastcall ReadCategoryGroups(System::Classes::TReader* AReader);
	void __fastcall WriteCategoryGroups(System::Classes::TWriter* AWriter);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall RestoreGroupIndexes(void);
	
public:
	__fastcall virtual TdxRibbonGalleryFilterCategory(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxRibbonGalleryFilterCategory(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=GetGalleryItem};
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property TdxRibbonGalleryFilterCategoryGroups* Groups = {read=FGroups, stored=false};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryFilterCategories;
class DELPHICLASS TdxRibbonGalleryFilter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryFilterCategories : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxRibbonGalleryFilterCategory* operator[](int Index) { return Items[Index]; }
	
private:
	TdxRibbonGalleryFilter* FGalleryFilter;
	HIDESBASE TdxRibbonGalleryFilterCategory* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonGalleryFilterCategory* Value);
	
protected:
	void __fastcall DeleteGroup(TdxRibbonGalleryGroup* AGroup);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property TdxRibbonGalleryFilter* GalleryFilter = {read=FGalleryFilter};
	
public:
	__fastcall TdxRibbonGalleryFilterCategories(TdxRibbonGalleryFilter* AGalleryFilter);
	HIDESBASE TdxRibbonGalleryFilterCategory* __fastcall Add(void);
	__property TdxRibbonGalleryFilterCategory* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryFilterCategories(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryFilter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FActiveCategoryIndex;
	System::UnicodeString FCaption;
	TdxRibbonGalleryFilterCategories* FCategories;
	TdxCustomRibbonGalleryItem* FGalleryItem;
	int FLoadedActiveCategoryIndex;
	bool FVisible;
	void __fastcall SetActiveCategoryIndex(int Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetCategories(TdxRibbonGalleryFilterCategories* Value);
	
protected:
	void __fastcall CategoriesChanged(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall Loaded(void);
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=FGalleryItem};
	
public:
	__fastcall TdxRibbonGalleryFilter(TdxCustomRibbonGalleryItem* AGalleryItem);
	__fastcall virtual ~TdxRibbonGalleryFilter(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsGroupFiltered(TdxRibbonGalleryGroup* AGroup);
	
__published:
	__property int ActiveCategoryIndex = {read=FActiveCategoryIndex, write=SetActiveCategoryIndex, default=-1};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property TdxRibbonGalleryFilterCategories* Categories = {read=FCategories, write=SetCategories};
	__property bool Visible = {read=FVisible, write=FVisible, default=0};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxRibbonGalleryHotTrackedItemChangedEvent)(TdxRibbonGalleryGroupItem* APrevHotTrackedGroupItem, TdxRibbonGalleryGroupItem* ANewHotTrackedGroupItem);

typedef System::TMetaClass* TCustomdxRibbonGalleryOptionsClass;

class DELPHICLASS TdxRibbonDropDownGallery;
class PASCALIMPLEMENTATION TdxCustomRibbonGalleryItem : public Dxbar::TCustomdxBarSubItem
{
	typedef Dxbar::TCustomdxBarSubItem inherited;
	
private:
	TdxRibbonDropDownGallery* FDropDownGallery;
	TdxRibbonGalleryFilter* FGalleryFilter;
	TdxRibbonGalleryGroups* FGalleryGroups;
	TdxCustomRibbonGalleryOptions* FGalleryOptions;
	TdxInRibbonGalleryOptions* FGalleryInRibbonOptions;
	TdxInMenuGalleryOptions* FGalleryInMenuOptions;
	int FFilterChangedLockCount;
	int FLockGroupItemClickEventsCount;
	bool FIsClone;
	bool FRecalculatingOnFilterChanged;
	TdxRibbonGalleryHotTrackedItemChangedEvent FOnHotTrackedItemChanged;
	void __fastcall ReadGalleryGroups(System::Classes::TReader* AReader);
	void __fastcall SetDropDownGallery(TdxRibbonDropDownGallery* Value);
	void __fastcall SetGalleryFilter(TdxRibbonGalleryFilter* Value);
	void __fastcall SetGalleryGroups(TdxRibbonGalleryGroups* Value);
	void __fastcall SetGalleryInRibbonOptions(TdxInRibbonGalleryOptions* Value);
	void __fastcall SetGalleryInMenuOptions(TdxInMenuGalleryOptions* Value);
	void __fastcall SetGalleryOptions(TdxCustomRibbonGalleryOptions* Value);
	void __fastcall SetSelectedGroupItem(TdxRibbonGalleryGroupItem* Value);
	
protected:
	TdxRibbonGalleryGroupItem* FClickedGroupItem;
	TdxRibbonGalleryGroupItem* FFirstVisibleGroupItem;
	TdxRibbonGalleryGroupItem* FSelectedGroupItem;
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall CanBePlacedOn(Dxbar::TdxBarItemControlParentKind AParentKind, Dxbar::TdxBar* AToolbar, /* out */ System::UnicodeString &AErrorText);
	DYNAMIC void __fastcall DoCloseUp(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	__classmethod virtual System::UnicodeString __fastcall GetNewCaption();
	virtual bool __fastcall InternalCanMergeWith(Dxbar::TdxBarItem* AItem);
	virtual void __fastcall UpdateEx(Dxbar::TdxBarKinds AParentKinds = (Dxbar::TdxBarKinds() << Dxbar::TdxBarKind::bkBarControl << Dxbar::TdxBarKind::bkBarQuickControl << Dxbar::TdxBarKind::bkSubMenu ));
	bool __fastcall AreGroupItemClickEventsLocked(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoGroupItemClick(TdxRibbonGalleryGroupItem* AItem);
	virtual void __fastcall DoInitFilterMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	DYNAMIC void __fastcall DoPopup(void);
	virtual TdxRibbonGalleryGroupItemClass __fastcall GetGroupItemClass(void);
	virtual TCustomdxRibbonGalleryOptionsClass __fastcall GetGalleryOptionsClass(void);
	virtual System::UnicodeString __fastcall GetErrorCanPlaceText(void);
	void __fastcall ColumnCountChanged(System::TObject* Sender);
	virtual void __fastcall DoHotTrackedItemChanged(TdxRibbonGalleryGroupItem* APrevHotTrackedGroupItem, TdxRibbonGalleryGroupItem* ANewHotTrackedGroupItem);
	virtual void __fastcall DoFilterChanged(void);
	void __fastcall FilterCaptionChanged(void);
	void __fastcall FilterChanged(void);
	void __fastcall GalleryChanged(void);
	void __fastcall ItemSelectionModeChanged(System::TObject* Sender, bool DeselectAll);
	void __fastcall MinColumnCountChanged(System::TObject* Sender);
	void __fastcall OptionsChanged(System::TObject* Sender);
	System::UnicodeString __fastcall GetFilterCaption(void);
	HIDESBASE Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	void __fastcall GroupVisibleChanged(void);
	bool __fastcall IsFilterVisible(void);
	void __fastcall LockFilterChanged(bool ALock);
	void __fastcall RemoveGroupItem(TdxRibbonGalleryGroupItem* AItem);
	__property bool IsClone = {read=FIsClone, nodefault};
	__property bool RecalculatingOnFilterChanged = {read=FRecalculatingOnFilterChanged, nodefault};
	__property TdxRibbonDropDownGallery* DropDownGallery = {read=FDropDownGallery, write=SetDropDownGallery};
	__property TdxRibbonGalleryGroups* GalleryCategories = {read=FGalleryGroups, write=SetGalleryGroups};
	__property TdxRibbonGalleryFilter* GalleryFilter = {read=FGalleryFilter, write=SetGalleryFilter};
	__property TdxInRibbonGalleryOptions* GalleryInRibbonOptions = {read=FGalleryInRibbonOptions, write=SetGalleryInRibbonOptions};
	__property TdxInMenuGalleryOptions* GalleryInMenuOptions = {read=FGalleryInMenuOptions, write=SetGalleryInMenuOptions};
	__property TdxCustomRibbonGalleryOptions* GalleryOptions = {read=FGalleryOptions, write=SetGalleryOptions};
	__property TdxRibbonGalleryHotTrackedItemChangedEvent OnHotTrackedItemChanged = {read=FOnHotTrackedItemChanged, write=FOnHotTrackedItemChanged};
	
public:
	__fastcall virtual TdxCustomRibbonGalleryItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomRibbonGalleryItem(void);
	TdxRibbonGalleryGroupItem* __fastcall CopyGroupItem(TdxRibbonGalleryGroupItem* AGroupItem, TdxRibbonGalleryGroup* ATargetGroup, int AIndex);
	DYNAMIC void __fastcall DoClick(void);
	virtual System::UnicodeString __fastcall GetAddMessageName(void);
	bool __fastcall IsGroupVisible(int AGroupIndex, bool AIgnoreVisibleProperty = false);
	void __fastcall LockGroupItemClickEvents(bool ALock);
	TdxRibbonGalleryGroupItem* __fastcall MoveGroupItem(TdxRibbonGalleryGroupItem* AGroupItem, TdxRibbonGalleryGroup* ATargetGroup, int AIndex);
	void __fastcall ShowGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	__property TdxRibbonGalleryGroups* GalleryGroups = {read=FGalleryGroups, write=SetGalleryGroups};
	__property TdxRibbonGalleryGroupItem* SelectedGroupItem = {read=FSelectedGroupItem, write=SetSelectedGroupItem};
};


class DELPHICLASS TdxRibbonGalleryItem;
typedef void __fastcall (__closure *TdxRibbonGalleryFilterChangedEvent)(TdxRibbonGalleryItem* Sender);

typedef void __fastcall (__closure *TdxRibbonGalleryGroupItemClickEvent)(TdxRibbonGalleryItem* Sender, TdxRibbonGalleryGroupItem* AItem);

typedef void __fastcall (__closure *TdxRibbonGalleryInitFilterMenuEvent)(TdxRibbonGalleryItem* Sender, Dxbar::TdxBarItemLinks* AItemLinks);

class PASCALIMPLEMENTATION TdxRibbonGalleryItem : public TdxCustomRibbonGalleryItem
{
	typedef TdxCustomRibbonGalleryItem inherited;
	
private:
	TdxRibbonGalleryFilterChangedEvent FOnFilterChanged;
	TdxRibbonGalleryGroupItemClickEvent FOnGroupItemClick;
	TdxRibbonGalleryInitFilterMenuEvent FOnInitFilterMenu;
	TdxRibbonGalleryOptions* __fastcall GetGalleryOptions(void);
	HIDESBASE void __fastcall SetGalleryOptions(TdxRibbonGalleryOptions* Value);
	
protected:
	virtual void __fastcall DoFilterChanged(void);
	virtual void __fastcall DoGroupItemClick(TdxRibbonGalleryGroupItem* AItem);
	virtual void __fastcall DoInitFilterMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	virtual TCustomdxRibbonGalleryOptionsClass __fastcall GetGalleryOptionsClass(void);
	virtual void __fastcall UpdateActionLink(void);
	
__published:
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property LargeGlyph;
	__property LargeImageIndex = {default=-1};
	__property ShowCaption = {default=1};
	__property OnClick;
	__property TdxRibbonGalleryOptions* GalleryOptions = {read=GetGalleryOptions, write=SetGalleryOptions};
	__property GalleryCategories;
	__property GalleryFilter;
	__property GalleryInRibbonOptions;
	__property GalleryInMenuOptions;
	__property ItemLinks;
	__property ItemOptions;
	__property OnCloseUp;
	__property TdxRibbonGalleryFilterChangedEvent OnFilterChanged = {read=FOnFilterChanged, write=FOnFilterChanged};
	__property TdxRibbonGalleryGroupItemClickEvent OnGroupItemClick = {read=FOnGroupItemClick, write=FOnGroupItemClick};
	__property OnHotTrackedItemChanged;
	__property TdxRibbonGalleryInitFilterMenuEvent OnInitFilterMenu = {read=FOnInitFilterMenu, write=FOnInitFilterMenu};
	__property OnPopup;
public:
	/* TdxCustomRibbonGalleryItem.Create */ inline __fastcall virtual TdxRibbonGalleryItem(System::Classes::TComponent* AOwner) : TdxCustomRibbonGalleryItem(AOwner) { }
	/* TdxCustomRibbonGalleryItem.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryItem(void) { }
	
};


class DELPHICLASS TdxRibbonGalleryController;
class DELPHICLASS TdxRibbonGalleryControl;
class DELPHICLASS TdxRibbonGalleryControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FGroupItemHotTrackEnabled;
	TdxRibbonGalleryGroupItem* FHintItem;
	TdxRibbonGalleryGroupItem* FKeyboardHotGroupItem;
	bool FLastCommandFromKeyboard;
	TdxRibbonGalleryGroupItem* FMouseDownGroupItem;
	TdxRibbonGalleryControl* FOwner;
	bool __fastcall GetEnabled(void);
	TdxRibbonGalleryGroupItem* __fastcall GetFirstGroupItem(void);
	TdxCustomRibbonGalleryItem* __fastcall GetGalleryItem(void);
	int __fastcall GetGroupCount(void);
	TdxRibbonGalleryGroupItem* __fastcall GetKeyboardHotGroupItem(void);
	TdxRibbonGalleryControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall GroupItemMouseMove(TdxRibbonGalleryGroupItem* AGroupItem, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ProcessHotTrack(TdxRibbonGalleryGroupItem* AGroupItem);
	void __fastcall SetHotGroupItem(TdxRibbonGalleryGroupItem* const Value);
	void __fastcall UnsetDownedFromGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	
protected:
	void __fastcall CancelHint(void);
	TdxRibbonGalleryGroupItem* __fastcall CheckEnabled(TdxRibbonGalleryGroupItem* AGroupItem);
	TdxRibbonGalleryGroupItem* __fastcall GetGroupItem(int AGroupIndex, int AIndex);
	void __fastcall HotTrackItem(TdxRibbonGalleryGroupItem* AItem);
	void __fastcall SetHintItem(TdxRibbonGalleryGroupItem* AItem);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=GetGalleryItem};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property bool GroupItemHotTrackEnabled = {read=FGroupItemHotTrackEnabled, write=FGroupItemHotTrackEnabled, nodefault};
	
public:
	__fastcall virtual TdxRibbonGalleryController(TdxRibbonGalleryControl* AOwner);
	__property TdxRibbonGalleryGroupItem* KeyboardHotGroupItem = {read=GetKeyboardHotGroupItem, write=FKeyboardHotGroupItem};
	__property TdxRibbonGalleryControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonOnSubmenuGalleryController;
class DELPHICLASS TdxRibbonGalleryFilterMenuControl;
class DELPHICLASS TdxRibbonOnMenuGalleryControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonOnSubmenuGalleryController : public TdxRibbonGalleryController
{
	typedef TdxRibbonGalleryController inherited;
	
private:
	TdxRibbonGalleryFilterMenuControl* FFilterMenuControl;
	void __fastcall CheckFilterMenuHotTrack(void);
	void __fastcall FilterMenuButtonClick(System::TObject* Sender);
	void __fastcall FilterMenuCategoryButtonClick(System::TObject* Sender);
	void __fastcall FilterMenuGroupButtonClick(System::TObject* Sender);
	HIDESBASE TdxRibbonGalleryGroupItem* __fastcall GetFirstGroupItem(void);
	int __fastcall GetGalleryWidth(void);
	TdxRibbonGalleryGroupItem* __fastcall GetLastGroupItem(void);
	HIDESBASE TdxRibbonOnMenuGalleryControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall HideFilterMenu(void);
	void __fastcall InitFilterMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	bool __fastcall IsFilterMenuInternalButton(Dxbar::TdxBarItem* AItem);
	void __fastcall ShowFilterMenu(void);
	
protected:
	void __fastcall FilterMenuControlDestroyed(void);
	void __fastcall HotTrackFirstGroupItem(void);
	void __fastcall HotTrackLastGroupItem(void);
	bool __fastcall IsFilterMenuShowed(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall Navigation(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection);
	void __fastcall PageDown(void);
	void __fastcall PageUp(void);
	void __fastcall Tabulation(void);
	
public:
	__property TdxRibbonOnMenuGalleryControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxRibbonGalleryController.Create */ inline __fastcall virtual TdxRibbonOnSubmenuGalleryController(TdxRibbonGalleryControl* AOwner) : TdxRibbonGalleryController(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonOnSubmenuGalleryController(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxRibbonGalleryFilterMenuControl : public Dxbar::TdxBarInternalSubMenuControl
{
	typedef Dxbar::TdxBarInternalSubMenuControl inherited;
	
private:
	TdxRibbonGalleryControl* FGalleryControl;
	Cxclasses::TcxObjectLink* FGalleryControlLink;
	
protected:
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual void __fastcall ProcessMouseDownMessageForMeaningParent(HWND AWnd, unsigned AMsg, const System::Types::TPoint &AMousePos);
	__property TdxRibbonGalleryControl* GalleryControl = {read=FGalleryControl};
	
public:
	__fastcall TdxRibbonGalleryFilterMenuControl(TdxRibbonGalleryControl* AGalleryControl);
	__fastcall virtual ~TdxRibbonGalleryFilterMenuControl(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonGalleryFilterMenuControl(HWND ParentWindow) : Dxbar::TdxBarInternalSubMenuControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonGalleryScrollBar;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryControl : public Dxbar::TdxBarSubItemControl
{
	typedef Dxbar::TdxBarSubItemControl inherited;
	
private:
	bool FCollapsed;
	TdxRibbonGalleryController* FController;
	System::Types::TRect FHintBounds;
	TdxRibbonGalleryGroupItem* FHintItem;
	bool FIsClickOnItemsArea;
	bool FIsClosingUpSubmenuControl;
	bool FIsCollapsedAssigned;
	bool FIsCreatingSubmenuControl;
	bool FIsDroppingDown;
	bool FIsNeedScrollBarLock;
	TdxRibbonGalleryScrollBar* FScrollBar;
	bool FSizeChanged;
	void __fastcall DoScrollBarDropDown(System::TObject* Sender);
	void __fastcall DrawInvalid(const System::Types::TRect &ABounds);
	bool __fastcall GetCollapsed(void);
	HIDESBASE TdxCustomRibbonGalleryItem* __fastcall GetItem(void);
	TdxRibbonGalleryControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall ObtainTextColors(void);
	void __fastcall SetCollapsed(bool Value);
	
protected:
	virtual bool __fastcall DoHint(bool &ANeedDeactivate, /* out */ System::UnicodeString &AHintText, /* out */ System::UnicodeString &AShortCut);
	System::UnicodeString __fastcall GetHintText(TdxRibbonGalleryGroupItem* AGroupItem);
	virtual System::Types::TPoint __fastcall GetHintPosition(const System::Types::TPoint &ACursorPos, int AHeight);
	void __fastcall UpdateHint(TdxRibbonGalleryGroupItem* AHintItem, const System::Types::TRect &ABounds);
	virtual int __fastcall CalcDefaultWidth(void);
	virtual int __fastcall CalcMinHeight(void);
	virtual void __fastcall CalcParts(void);
	virtual bool __fastcall CanClicked(void);
	virtual bool __fastcall CanCustomize(void);
	virtual void __fastcall ControlUnclick(bool ByMouse);
	virtual TdxRibbonGalleryController* __fastcall CreateController(void);
	virtual Dxbar::TdxBarCustomHintViewInfo* __fastcall CreateHintViewInfo(const System::UnicodeString AHintText, const System::UnicodeString AShortCut);
	DYNAMIC void __fastcall DoCloseUp(bool AHadSubMenuControl);
	DYNAMIC void __fastcall DoDropDown(bool AByMouse);
	virtual void __fastcall DropDown(bool AByMouse);
	virtual void __fastcall EnabledChanged(void);
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	virtual int __fastcall GetDefaultHeightInSubMenu(void);
	virtual int __fastcall GetDefaultWidthInSubMenu(void);
	virtual void __fastcall GetDefaultTextColors(bool AEnabled, bool ASelected, bool AFlat, System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
	int __fastcall GetMouseWheelStep(void);
	virtual void __fastcall GetSubMenuControlPositionParams(/* out */ System::Types::TPoint &P, /* out */ int &AOwnerWidth, /* out */ int &AOwnerHeight);
	virtual int __fastcall InternalGetDefaultWidth(void);
	void __fastcall Changed(void);
	virtual bool __fastcall WantsKey(System::Word Key);
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual void __fastcall ControlActivate(bool AImmediately, bool AByMouse);
	virtual void __fastcall ControlClick(bool AByMouse, System::WideChar AKey = (System::WideChar)(0x0));
	virtual void __fastcall CreateSubMenuControl(void);
	virtual void __fastcall DoCreateSubMenuControl(void);
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	void __fastcall FilterCaptionChanged(void);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	TdxRibbonGalleryGroups* __fastcall GetGroups(void);
	virtual Dxbar::TdxBarSubMenuControl* __fastcall GetSubMenuControl(void);
	virtual Dxbar::TdxBarItemControlViewInfoClass __fastcall GetViewInfoClass(void);
	int __fastcall GetVisibleGroupCount(void);
	virtual bool __fastcall HasSubMenu(void);
	virtual bool __fastcall CanDestroyOnClick(void);
	bool __fastcall IsEnabledScrollBar(void);
	virtual bool __fastcall IsHiddenForCustomization(void);
	virtual bool __fastcall IsNeedScrollBar(void);
	bool __fastcall IsValidPainter(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(void);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoScrollBarScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall DoScrollBarMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	int __fastcall GetScrollBarMaxPos(void);
	void __fastcall ScrollBarSetup(void);
	virtual void __fastcall SetScrollBarPosition(int APosition);
	virtual bool __fastcall NeedBufferedRepaint(void);
	__property bool Collapsed = {read=GetCollapsed, write=SetCollapsed, nodefault};
	__property TdxRibbonGalleryController* Controller = {read=FController};
	__property TdxRibbonGalleryScrollBar* ScrollBar = {read=FScrollBar};
	__property bool SizeChanged = {read=FSizeChanged, write=FSizeChanged, nodefault};
	
public:
	__fastcall virtual TdxRibbonGalleryControl(Dxbar::TdxBarItemLink* AItemLink);
	__fastcall virtual ~TdxRibbonGalleryControl(void);
	virtual void __fastcall Update(const System::Types::TRect &R)/* overload */;
	void __fastcall ShowGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property TdxCustomRibbonGalleryItem* Item = {read=GetItem};
	__property TdxRibbonGalleryControlViewInfo* ViewInfo = {read=GetViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Update(void){ Dxbar::TdxBarItemControl::Update(); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryGroupElementViewInfo;
class DELPHICLASS TdxRibbonGalleryGroupViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupElementViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxRibbonGalleryGroupViewInfo* FOwner;
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	TdxRibbonGalleryControl* __fastcall GetGalleryItemControl(void);
	unsigned __fastcall GetTextFlags(System::Classes::TAlignment AnAlignment);
	
public:
	__fastcall TdxRibbonGalleryGroupElementViewInfo(TdxRibbonGalleryGroupViewInfo* AOwner);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property TdxRibbonGalleryGroupViewInfo* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryGroupElementViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryGroupHeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupHeaderViewInfo : public TdxRibbonGalleryGroupElementViewInfo
{
	typedef TdxRibbonGalleryGroupElementViewInfo inherited;
	
private:
	System::Types::TRect FTextBounds;
	bool __fastcall IsVisible(void);
	
protected:
	virtual System::UnicodeString __fastcall GetCaption(void);
	int __fastcall GetHeight(int AWidth, bool AWithSpaceAfterHeader);
	virtual System::Types::TRect __fastcall GetTextBounds(void);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect TextBounds = {read=FTextBounds};
public:
	/* TdxRibbonGalleryGroupElementViewInfo.Create */ inline __fastcall TdxRibbonGalleryGroupHeaderViewInfo(TdxRibbonGalleryGroupViewInfo* AOwner) : TdxRibbonGalleryGroupElementViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryGroupHeaderViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryGroupItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupItemViewInfo : public TdxRibbonGalleryGroupElementViewInfo
{
	typedef TdxRibbonGalleryGroupElementViewInfo inherited;
	
private:
	System::Types::TRect FCaptionBounds;
	TdxRibbonGalleryVisibilityState FCaptionVisibilityState;
	int FCaptionWidth;
	bool FChanged;
	System::Types::TRect FDescriptionBounds;
	System::Classes::TStrings* FDescriptionLines;
	int FDescriptionRowCount;
	System::Types::TSize FDescriptionSize;
	TdxRibbonGalleryVisibilityState FDescriptionVisibilityState;
	TdxRibbonGalleryGroupItem* FGroupItem;
	System::Types::TRect FImageBounds;
	System::Types::TSize FPredefinedItemSize;
	void __fastcall CheckCaptionFontStyle(Vcl::Graphics::TFont* AFont);
	int __fastcall GetDescriptionLenght(void);
	System::Types::TRect __fastcall GetDescriptionRect(int AMaxWidth);
	bool __fastcall GetDowned(void);
	TdxRibbonGalleryGroupItem* __fastcall GetHotGroupItem(void);
	int __fastcall GetHorizontalImageIndent(void);
	System::Types::TSize __fastcall GetImagePlaceSize(void);
	bool __fastcall GetIsItemPullHighlighting(void);
	TdxRibbonGalleryGroupOptions* __fastcall GetOptions(void);
	Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	System::Types::TRect __fastcall GetRectConsiderBounds(const System::Types::TRect &ARect);
	bool __fastcall GetSelected(void);
	int __fastcall GetVerticalImageIndent(void);
	bool __fastcall IsCaptionVisible(void);
	bool __fastcall IsDescriptionVisible(void);
	bool __fastcall IsImageVisible(void);
	bool __fastcall IsInplaceGallery(void);
	bool __fastcall IsMergeItemsImages(void);
	bool __fastcall IsThisGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	int __fastcall ItemHeightWithoutImage(System::Types::TRect &ADescriptionRect);
	int __fastcall ItemWidthWithoutImage(System::Types::TRect &ADescriptionRect, int AMaxWidth);
	void __fastcall ValidateDescriptionStrings(Cxgraphics::TcxCanvas* ACanvas);
	
protected:
	virtual System::Types::TSize __fastcall CalculateImageSize(void);
	void __fastcall DrawImage(HDC DC, const System::Types::TRect &ARect);
	virtual void __fastcall DrawItemText(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual int __fastcall GetCaptionHeight(void);
	virtual int __fastcall GetCaptionWidth(void);
	Vcl::Graphics::TBitmap* __fastcall GetCurrentGlyph(void);
	virtual System::UnicodeString __fastcall GetDescription(void);
	virtual int __fastcall GetDescriptionHeight(System::Types::TRect &ADescriptionRect);
	virtual int __fastcall GetDescriptionWidth(System::Types::TRect &ADescriptionRect, int AMaxWidth);
	bool __fastcall GetHotTracked(void);
	System::Types::TSize __fastcall GetImageSize(void);
	System::Types::TSize __fastcall GetItemSize(int AMaxWidth = 0x0);
	Dxbar::_di_IdxSkin __fastcall GetRibbonSkin(void);
	virtual int __fastcall GetSpaceBetweenItemCaptionAndDescription(void);
	virtual int __fastcall GetSpaceBetweenItemImageAndText(void);
	virtual System::Types::TSize __fastcall GetUnsizedImageSize(void);
	bool __fastcall IsImageAssigned(void);
	virtual System::Types::TRect __fastcall GetCaptionBounds(void);
	virtual System::Types::TRect __fastcall GetDescriptionBounds(void);
	virtual System::Types::TRect __fastcall GetImageBounds(void);
	virtual int __fastcall GetTextLeft(void);
	virtual int __fastcall GetTextRight(void);
	virtual int __fastcall GetTextTop(void);
	virtual bool __fastcall IsBoldCaption(void);
	void __fastcall ResetCachedValues(void);
	void __fastcall SetPredefinedItemSize(const System::Types::TSize &AValue);
	__property System::Classes::TStrings* DescriptionLines = {read=FDescriptionLines};
	__property int HorizontalImageIndent = {read=GetHorizontalImageIndent, nodefault};
	__property TdxRibbonGalleryGroupItem* HotGroupItem = {read=GetHotGroupItem};
	__property bool IsItemPullHighlighting = {read=GetIsItemPullHighlighting, nodefault};
	__property TdxRibbonGalleryGroupOptions* Options = {read=GetOptions};
	__property Dxbar::TdxBarPainter* Painter = {read=GetPainter};
	__property int VerticalImageIndent = {read=GetVerticalImageIndent, nodefault};
	
public:
	__fastcall TdxRibbonGalleryGroupItemViewInfo(TdxRibbonGalleryGroupViewInfo* AOwner, TdxRibbonGalleryGroupItem* AGroupItem);
	__fastcall virtual ~TdxRibbonGalleryGroupItemViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property System::UnicodeString Description = {read=GetDescription};
	__property TdxRibbonGalleryGroupItem* GroupItem = {read=FGroupItem};
};

#pragma pack(pop)

enum TdxRibbonGalleryGroupRepaintPart : unsigned char { ggrpAll, ggrpBefore, ggrpAfter, ggrpBetween };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryGroupViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxRibbonGalleryGroup* FGroup;
	TdxRibbonGalleryGroupHeaderViewInfo* FHeader;
	Cxclasses::TcxObjectList* FItems;
	System::Types::TSize FItemSize;
	TdxRibbonGalleryControlViewInfo* FOwner;
	int __fastcall GetFirstItemInGroupRow(int ARowIndex, int AColumnCount);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	TdxRibbonGalleryGroupItemViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	System::Types::TSize __fastcall GetItemSize(int AMaxItemWidth = 0x0);
	TdxRibbonGalleryGroupOptions* __fastcall GetOptions(void);
	Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	
protected:
	System::Types::TSize __fastcall CalculateItemSize(const System::Types::TSize &APredefinedItemSize, int AMaxItemWidth = 0x0);
	void __fastcall ClearItems(void);
	void __fastcall CorrectItemWidth(const System::Types::TRect &ABounds);
	void __fastcall CreateGroupItem(int AItemIndex, const System::Types::TRect &ABounds);
	virtual int __fastcall GetColumnCount(int AWidth);
	virtual int __fastcall GetColumnCountInRow(int ARow, int AGroupWidth);
	virtual int __fastcall GetColumnLeft(int AColumnIndex, int AGroupLeft);
	int __fastcall GetColumnWidth(void);
	int __fastcall GetGroupWidth(void);
	System::Types::TRect __fastcall GetHeaderBounds(const System::Types::TRect &AGroupBounds);
	int __fastcall GetItemColumn(int AIndex, int AGroupWidth);
	int __fastcall GetItemIndex(int ARow, int AColumn, int AGroupWidth);
	int __fastcall GetItemRow(int AGroupItemIndex, int AGroupWidth);
	int __fastcall GetLastItemInGroupRow(int ARowIndex, int AColumnCount);
	int __fastcall GetRowCount(int AGroupWidth);
	int __fastcall GetRowHeight(void);
	virtual int __fastcall GetRowTop(int ARowIndex, int AGroupTop, int AGroupWidth);
	int __fastcall GetSpaceBetweenItems(bool IsAflat);
	void __fastcall RepaintChainOfItems(int AnItemIndex, bool IsHotTrack, Cxgraphics::TcxCanvas* ACanvas, TdxRibbonGalleryGroupRepaintPart APart = (TdxRibbonGalleryGroupRepaintPart)(0x0), int AnItemIndex2 = 0x0);
	void __fastcall SetBounds(const System::Types::TRect &ABounds);
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property TdxRibbonGalleryGroupOptions* Options = {read=GetOptions};
	__property Dxbar::TdxBarPainter* Painter = {read=GetPainter};
	
public:
	__fastcall TdxRibbonGalleryGroupViewInfo(TdxRibbonGalleryControlViewInfo* AOwner, TdxRibbonGalleryGroup* AGroup);
	__fastcall virtual ~TdxRibbonGalleryGroupViewInfo(void);
	void __fastcall Calculate(int AGroupTop, int AGroupBottom, const System::Types::TRect &AControlClientRect);
	int __fastcall GetHeight(int AWidth);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxRibbonGalleryGroup* Group = {read=FGroup};
	__property TdxRibbonGalleryGroupHeaderViewInfo* Header = {read=FHeader};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxRibbonGalleryGroupItemViewInfo* Items[int Index] = {read=GetItem};
	__property System::Types::TSize ItemSize = {read=FItemSize};
	__property TdxRibbonGalleryControlViewInfo* Owner = {read=FOwner};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryControlViewInfo : public Dxbar::TdxBarItemControlViewInfo
{
	typedef Dxbar::TdxBarItemControlViewInfo inherited;
	
private:
	typedef System::DynamicArray<System::Types::TSize> _TdxRibbonGalleryControlViewInfo__1;
	
	
private:
	int FDontDisplayHotTrackedGroupItem;
	int FDontDisplayGroupHeaderWhenHotTrackingGroupItem;
	TdxRibbonGalleryGroupItem* FDownedGroupItem;
	System::Types::TSize FGlobalItemSize;
	_TdxRibbonGalleryControlViewInfo__1 FGroupItemStoredSizes;
	TdxRibbonGalleryGroupItem* FHotGroupItem;
	int FLayoutOffset;
	System::Uitypes::TColor FDisabledTextColor;
	System::Uitypes::TColor FHotTextColor;
	System::Uitypes::TColor FSelectedTextColor;
	System::Uitypes::TColor FTextColor;
	int __fastcall GetGroupCount(void);
	TdxRibbonGalleryGroupViewInfo* __fastcall GetGroup(int Index);
	System::Types::TSize __fastcall GetGroupItemSize(int AGroupIndex);
	void __fastcall CalculateGlobalItemSize(void);
	TdxRibbonGalleryControl* __fastcall GetControl(void);
	System::Types::TRect __fastcall GetGalleryBounds(void);
	TdxCustomRibbonGalleryItem* __fastcall GetGalleryItem(void);
	TdxCustomRibbonGalleryOptions* __fastcall GetGalleryOptions(void);
	TdxInMenuGalleryOptions* __fastcall GetGalleryInMenuOptions(void);
	System::Types::TSize __fastcall GetGallerySize(void);
	Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	System::Types::TRect __fastcall GetScrollBarBounds(void);
	int __fastcall GetScrollBarWidth(void);
	void __fastcall DrawGroupItem(TdxRibbonGalleryGroupItem* const AGroupItem);
	void __fastcall RepaintChainOfGroups(TdxRibbonGalleryGroupItem* ANewItem, TdxRibbonGalleryGroupItem* AOldItem);
	
protected:
	Cxclasses::TcxObjectList* FGroups;
	virtual void __fastcall DisplayGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R) = 0 ;
	void __fastcall DrawSelectedGroupItem(TdxRibbonGalleryGroupItem* ASelectedGroupItem, TdxRibbonGalleryGroupItem* AOldSelectedGroupItem);
	void __fastcall GalleryChanged(void);
	int __fastcall GetAbsoluteGroupTop(int AGroupIndex, int AWidth);
	virtual System::Types::TRect __fastcall GetControlBounds(void);
	virtual int __fastcall GetGalleryHeight(int AWidth);
	virtual System::Types::TRect __fastcall GetGalleryMargins(void) = 0 ;
	int __fastcall GetGroupItemCount(int ALastGroupIndex);
	virtual int __fastcall GetHeight(int AWidth);
	virtual int __fastcall GetLayoutWidth(int AColumnCount, /* out */ bool &AGroupItemWidthIsNull) = 0 ;
	virtual System::Types::TSize __fastcall GetMaxGroupItemSize(void);
	TdxRibbonGalleryGroupItem* __fastcall GetGroupItem(int X, int Y);
	System::Types::TSize __fastcall GetGroupItemStoredSize(int AGroupIndex);
	TdxRibbonGalleryGroupItemViewInfo* __fastcall GetGroupItemViewInfo(TdxRibbonGalleryGroupItem* AGroupItem);
	virtual int __fastcall GetInRibbonGalleryState(void);
	virtual int __fastcall GetLeftLayoutIndent(void);
	virtual System::Types::TSize __fastcall GetMinSize(void) = 0 ;
	bool __fastcall GetNextButtonEnabled(void);
	bool __fastcall GetPreviousButtonEnabled(void);
	virtual Dxbar::_di_IdxSkin __fastcall GetRibbonSkin(void);
	virtual int __fastcall GetRightLayoutIndent(void);
	int __fastcall GetVisibleGroupIndex(int AStartGroupIndex, bool AIncreaseIndex);
	int __fastcall GetVisibleNotEmptyGroupIndex(int AStartGroupIndex, bool AIncreaseIndex);
	virtual int __fastcall InternalGetScrollBarWidth(void) = 0 ;
	virtual bool __fastcall IsGroupHeaderVisible(void);
	bool __fastcall IsGroupItemAtThisPlace(int X, int Y);
	virtual bool __fastcall IsInRibbon(void);
	void __fastcall RemoveGroupItem(TdxRibbonGalleryGroupItem* AItem);
	virtual void __fastcall Changed(void);
	void __fastcall SetDownedGroupItem(TdxRibbonGalleryGroupItem* const Value);
	void __fastcall SetGroupItemStoredSize(const System::Types::TSize &Value, int AGroupIndex);
	void __fastcall SetHotGroupItem(TdxRibbonGalleryGroupItem* Value);
	virtual void __fastcall ShowGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	__property System::Uitypes::TColor DisabledTextColor = {read=FDisabledTextColor, nodefault};
	__property System::Uitypes::TColor HotTextColor = {read=FHotTextColor, nodefault};
	__property System::Uitypes::TColor SelectedTextColor = {read=FSelectedTextColor, nodefault};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, nodefault};
	__property int DontDisplayGroupHeaderWhenHotTrackingGroupItem = {read=FDontDisplayGroupHeaderWhenHotTrackingGroupItem, write=FDontDisplayGroupHeaderWhenHotTrackingGroupItem, nodefault};
	__property int DontDisplayHotTrackedGroupItem = {read=FDontDisplayHotTrackedGroupItem, write=FDontDisplayHotTrackedGroupItem, nodefault};
	__property TdxRibbonGalleryGroupItem* DownedGroupItem = {read=FDownedGroupItem};
	__property System::Types::TRect GalleryBounds = {read=GetGalleryBounds};
	__property TdxInMenuGalleryOptions* GalleryInMenuOptions = {read=GetGalleryInMenuOptions};
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=GetGalleryItem};
	__property TdxCustomRibbonGalleryOptions* GalleryOptions = {read=GetGalleryOptions};
	__property System::Types::TSize GallerySize = {read=GetGallerySize};
	__property System::Types::TSize GlobalItemSize = {read=FGlobalItemSize};
	__property TdxRibbonGalleryGroupItem* HotGroupItem = {read=FHotGroupItem, write=SetHotGroupItem};
	__property int LayoutOffset = {read=FLayoutOffset, nodefault};
	__property Dxbar::TdxBarPainter* Painter = {read=GetPainter};
	__property int ScrollBarWidth = {read=GetScrollBarWidth, nodefault};
	
public:
	__fastcall virtual TdxRibbonGalleryControlViewInfo(Dxbar::TdxBarItemControl* AControl);
	__fastcall virtual ~TdxRibbonGalleryControlViewInfo(void);
	virtual void __fastcall Calculate(int ALayoutOffset, System::Uitypes::TScrollCode AScrollCode);
	virtual bool __fastcall IsCollapsed(void) = 0 ;
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxRibbonGalleryControl* Control = {read=GetControl};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property TdxRibbonGalleryGroupViewInfo* Groups[int Index] = {read=GetGroup};
	__property System::Types::TRect ScrollBarBounds = {read=GetScrollBarBounds};
};

#pragma pack(pop)

class DELPHICLASS TdxInRibbonGalleryControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxInRibbonGalleryControlViewInfo : public TdxRibbonGalleryControlViewInfo
{
	typedef TdxRibbonGalleryControlViewInfo inherited;
	
private:
	typedef System::DynamicArray<Dxbar::TdxBarItemCachedWidthInfo> _TdxInRibbonGalleryControlViewInfo__1;
	
	
private:
	Dxanimation::TdxImageAnimationTransition* FAnimation;
	int FAnimationBitmapHeight;
	bool FCollapsed;
	int FColumnCount;
	int FControlHeight;
	bool FDrawWithoutBackground;
	int FRowCount;
	TdxRibbonGalleryGroupItem* FShowGroupItem;
	int FTopVisibleRow;
	_TdxInRibbonGalleryControlViewInfo__1 FWidthForColumnCountInfos;
	void __fastcall DoCalculate(void);
	int __fastcall GetControlHeight(void);
	int __fastcall GetGroupColumnCount(void);
	int __fastcall GetRowIndex(int AGroupItemIndex, int AColumnCount);
	int __fastcall GetSpaceBetweenItems(bool IsAflat);
	bool __fastcall IsScrollingPossible(int ARowDelta);
	void __fastcall PopulateGroupItemList(int AFirstVisibleRow, int ALastVisibleRow, int AColumnCount, System::Contnrs::TObjectList* AList);
	bool __fastcall CanCollapse(void);
	bool __fastcall GetCollapsed(void);
	int __fastcall GetColumnCount(void);
	int __fastcall GetMaxColumnCount(void);
	int __fastcall GetMinColumnCount(void);
	int __fastcall GetTopIndent(void);
	int __fastcall GetTotalRows(void);
	int __fastcall GetWidthForColumnCount(int AColumnCount);
	void __fastcall SetCollapsed(bool Value);
	void __fastcall SetColumnCount(int Value);
	
protected:
	void __fastcall AnimationHandler(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	virtual void __fastcall BoundsCalculated(void);
	void __fastcall CalculateLayout(int ALayoutOffset, int AColumnCount, System::Contnrs::TObjectList* AGroupItemsList);
	int __fastcall CorrectGroupItemWidth(const System::Types::TSize &AGroupItemSize);
	void __fastcall DoDrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DoScrolling(int ARowDelta);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetControlMargins(void);
	virtual System::Types::TRect __fastcall GetGalleryMargins(void);
	virtual int __fastcall GetLayoutWidth(int AColumnCount, /* out */ bool &AGroupItemWidthIsNull);
	virtual System::Types::TSize __fastcall GetMaxGroupItemSize(void);
	int __fastcall GetBottomLayoutIndent(void);
	virtual int __fastcall GetLeftLayoutIndent(void);
	virtual int __fastcall GetRightLayoutIndent(void);
	int __fastcall GetTopLayoutIndent(void);
	virtual int __fastcall InternalGetScrollBarWidth(void);
	virtual bool __fastcall IsInRibbon(void);
	virtual void __fastcall ShowGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	__property Dxanimation::TdxImageAnimationTransition* Animation = {read=FAnimation};
	__property int ControlHeight = {read=GetControlHeight, nodefault};
	__property bool DrawWithoutBackground = {read=FDrawWithoutBackground, nodefault};
	__property int RowCount = {read=FRowCount, nodefault};
	__property int TotalRows = {read=GetTotalRows, nodefault};
	
public:
	__fastcall virtual TdxInRibbonGalleryControlViewInfo(Dxbar::TdxBarItemControl* AControl);
	virtual void __fastcall Calculate(int ALayoutOffset, System::Uitypes::TScrollCode AScrollCode);
	virtual bool __fastcall IsCollapsed(void);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall ResetCachedValues(void);
	__property int ColumnCount = {read=FColumnCount, nodefault};
	__property int TopVisibleRow = {read=FTopVisibleRow, nodefault};
public:
	/* TdxRibbonGalleryControlViewInfo.Destroy */ inline __fastcall virtual ~TdxInRibbonGalleryControlViewInfo(void) { }
	
private:
	void *__IdxBarMultiColumnItemControlViewInfo;	/* Dxbar::IdxBarMultiColumnItemControlViewInfo */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B92D58D1-3251-4816-A43F-D4D4AF2F02EE}
	operator Dxbar::_di_IdxBarMultiColumnItemControlViewInfo()
	{
		Dxbar::_di_IdxBarMultiColumnItemControlViewInfo intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarMultiColumnItemControlViewInfo*(void) { return (Dxbar::IdxBarMultiColumnItemControlViewInfo*)&__IdxBarMultiColumnItemControlViewInfo; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonOnMenuGalleryControlViewInfo : public TdxRibbonGalleryControlViewInfo
{
	typedef TdxRibbonGalleryControlViewInfo inherited;
	
private:
	System::Types::TRect FFilterBandContentRect;
	bool FFilterBandHotTrack;
	System::Types::TRect FFilterBandRect;
	System::Contnrs::TObjectList* FGroupItemDescriptionRectCache;
	void __fastcall CalculateFilterBand(void);
	void __fastcall DrawFilterBand(void);
	void __fastcall DrawFilterCaption(void);
	int __fastcall GetBottomSeparatorHeight(void);
	int __fastcall GetFilterBandHeight(void);
	int __fastcall GetHeightByRowCount(int AWidth);
	int __fastcall GetSpaceBetweenItems(int AGroupIndex, bool IsAflat);
	void __fastcall InitializeGroupItemDescriptionRectCache(void);
	bool __fastcall NeedsDrawBottomSeparator(void);
	
protected:
	virtual void __fastcall DisplayGroupItem(TdxRibbonGalleryGroupItem* AGroupItem);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetControlBounds(void);
	virtual int __fastcall GetGalleryHeight(int AWidth);
	virtual System::Types::TRect __fastcall GetGalleryMargins(void);
	System::Types::TRect __fastcall GetGroupItemDescriptionRect(int AGroupIndex, int AnItemIndex);
	virtual int __fastcall GetHeight(int AWidth);
	virtual int __fastcall GetLayoutWidth(int AColumnCount, /* out */ bool &AGroupItemWidthIsNull);
	void __fastcall GroupItemYRange(TdxRibbonGalleryGroupItem* const AGroupItem, int &ATop, int &ABottom);
	virtual System::Types::TSize __fastcall GetMinSize(void);
	virtual int __fastcall InternalGetScrollBarWidth(void);
	virtual void __fastcall Changed(void);
	void __fastcall SetGroupItemDescriptionRect(int AGroupIndex, int AnItemIndex, const System::Types::TRect &ARect);
	
public:
	__fastcall virtual ~TdxRibbonOnMenuGalleryControlViewInfo(void);
	virtual void __fastcall Calculate(int ALayoutOffset, System::Uitypes::TScrollCode AScrollCode);
	void __fastcall GetFilterMenuShowingParams(/* out */ System::Types::TPoint &APosition, /* out */ int &AOwnerHeight);
	virtual bool __fastcall IsCollapsed(void);
	bool __fastcall IsPtInFilterBandHotTrackArea(const System::Types::TPoint &P);
	void __fastcall RepaintFilterBand(void);
	void __fastcall SetFilterBandHotTrack(bool AValue);
public:
	/* TdxRibbonGalleryControlViewInfo.Create */ inline __fastcall virtual TdxRibbonOnMenuGalleryControlViewInfo(Dxbar::TdxBarItemControl* AControl) : TdxRibbonGalleryControlViewInfo(AControl) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryControlAccessibilityHelper : public Dxbaraccessibility::TdxBarSubItemControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxBarSubItemControlAccessibilityHelper inherited;
	
private:
	TdxRibbonGalleryControl* __fastcall GetControl(void);
	TdxRibbonOnSubmenuGalleryController* __fastcall GetOnSubmenuController(void);
	
protected:
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual void __fastcall GetKeyTipData(System::Classes::TList* AKeyTipsData);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	void __fastcall OnSubmenuHotTrack(TdxRibbonDropDownGalleryNavigationDirection ANavigationDirection);
	virtual bool __fastcall ShowDropDownWindow(void);
	__property TdxRibbonGalleryControl* Control = {read=GetControl};
	__property TdxRibbonOnSubmenuGalleryController* OnSubmenuController = {read=GetOnSubmenuController};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonGalleryControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxBarSubItemControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryControlAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonDropDownGalleryControlAccessibilityHelper;
class DELPHICLASS TdxRibbonDropDownGalleryControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonDropDownGalleryControlAccessibilityHelper : public Dxbaraccessibility::TdxBarSubMenuControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxBarSubMenuControlAccessibilityHelper inherited;
	
private:
	HIDESBASE TdxRibbonDropDownGalleryControl* __fastcall GetBarControl(void);
	TdxRibbonGalleryControlAccessibilityHelper* __fastcall GetInternalGalleryItemControlAccessibilityHelper(void);
	
protected:
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual void __fastcall HandleVertNavigationKey(bool AUpKey, bool AFocusItemControl);
	__property TdxRibbonDropDownGalleryControl* BarControl = {read=GetBarControl};
	__property TdxRibbonGalleryControlAccessibilityHelper* InternalGalleryItemControlAccessibilityHelper = {read=GetInternalGalleryItemControlAccessibilityHelper};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonDropDownGalleryControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxBarSubMenuControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonDropDownGalleryControlAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryScrollBarViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryScrollBarViewInfo : public Cxscrollbar::TcxScrollBarViewInfo
{
	typedef Cxscrollbar::TcxScrollBarViewInfo inherited;
	
private:
	System::Types::TRect FDropDownButtonRect;
	
public:
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateDropDownStyle(void);
	__property System::Types::TRect DropDownButtonRect = {read=FDropDownButtonRect};
public:
	/* TcxScrollBarViewInfo.Create */ inline __fastcall virtual TdxRibbonGalleryScrollBarViewInfo(Cxscrollbar::TcxScrollBarHelper* AScrollBar) : Cxscrollbar::TcxScrollBarViewInfo(AScrollBar) { }
	/* TcxScrollBarViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryScrollBarViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGalleryScrollBarPainter;
class DELPHICLASS TdxRibbonGalleryScrollBarHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGalleryScrollBarPainter : public Cxscrollbar::TcxScrollBarPainter
{
	typedef Cxscrollbar::TcxScrollBarPainter inherited;
	
private:
	TdxRibbonGalleryControl* __fastcall GetGalleryControl(void);
	TdxRibbonGalleryScrollBarHelper* __fastcall GetScrollBar(void);
	HIDESBASE TdxRibbonGalleryScrollBarViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawScrollBarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DoDrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	__property TdxRibbonGalleryScrollBarHelper* ScrollBar = {read=GetScrollBar};
	__property TdxRibbonGalleryScrollBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TcxScrollBarPainter.Create */ inline __fastcall virtual TdxRibbonGalleryScrollBarPainter(Cxscrollbar::TcxScrollBarHelper* AScrollBar) : Cxscrollbar::TcxScrollBarPainter(AScrollBar) { }
	/* TcxScrollBarPainter.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryScrollBarPainter(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxRibbonGalleryScrollBarHelper : public Cxscrollbar::TcxScrollBarHelper
{
	typedef Cxscrollbar::TcxScrollBarHelper inherited;
	
private:
	bool FIsDropDownButtonPressed;
	TdxRibbonGalleryScrollBar* FRibbonScrollBar;
	TdxRibbonGalleryControl* __fastcall GetGalleryControl(void);
	
protected:
	virtual Cxscrollbar::TcxScrollBarPainterClass __fastcall GetPainterClass(void);
	virtual Cxscrollbar::TcxScrollBarViewInfoClass __fastcall GetViewInfoClass(void);
	Dxbar::TdxBarPainter* __fastcall GetBarPainter(void);
	int __fastcall GetButtonSkinState(Cxlookandfeelpainters::TcxButtonState AState);
	Dxbar::_di_IdxSkin __fastcall GetRibbonSkin(void);
	bool __fastcall IsButtonEnabled(Dxribbonskins::TdxInRibbonGalleryScrollBarButtonKind AButtonKind);
	bool __fastcall IsDropDownButtonUnderMouse(void);
	bool __fastcall IsDropDownStyle(void);
	__property TdxRibbonGalleryControl* GalleryControl = {read=GetGalleryControl};
	__property bool IsDropDownButtonPressed = {read=FIsDropDownButtonPressed, write=FIsDropDownButtonPressed, nodefault};
	
public:
	__fastcall virtual TdxRibbonGalleryScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
public:
	/* TcxScrollBarHelper.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryScrollBarHelper(void) { }
	
};


class PASCALIMPLEMENTATION TdxRibbonGalleryScrollBar : public Cxscrollbar::TcxScrollBar
{
	typedef Cxscrollbar::TcxScrollBar inherited;
	
private:
	TdxRibbonGalleryControl* FGalleryControl;
	System::Classes::TNotifyEvent FOnDropDown;
	void __fastcall DoDropDown(void);
	TdxRibbonGalleryScrollBarHelper* __fastcall GetHelper(void);
	bool __fastcall GetIsDropDownButtonPressed(void);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNoParams &Message);
	
protected:
	virtual Cxscrollbar::TcxScrollBarHelperClass __fastcall GetHelperClass(void);
	__property TdxRibbonGalleryControl* GalleryControl = {read=FGalleryControl};
	__property TdxRibbonGalleryScrollBarHelper* Helper = {read=GetHelper};
	
public:
	__fastcall TdxRibbonGalleryScrollBar(TdxRibbonGalleryControl* AGalleryControl);
	bool __fastcall IsDropDownStyle(void);
	__property bool IsDropDownButtonPressed = {read=GetIsDropDownButtonPressed, nodefault};
	__property System::Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
public:
	/* TcxScrollBar.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryScrollBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonGalleryScrollBar(HWND ParentWindow) : Cxscrollbar::TcxScrollBar(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxRibbonDropDownGallery : public Dxribbon::TdxRibbonCustomPopupMenu
{
	typedef Dxribbon::TdxRibbonCustomPopupMenu inherited;
	
private:
	TdxCustomRibbonGalleryItem* FGalleryItem;
	void __fastcall SetGalleryItem(TdxCustomRibbonGalleryItem* Value);
	
protected:
	virtual Dxbar::TCustomdxBarControl* __fastcall CreateBarControl(void);
	virtual Dxbar::TCustomdxBarControlClass __fastcall GetControlClass(void);
	bool __fastcall HasValidGalleryItem(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
__published:
	__property BarManager;
	__property Font;
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=FGalleryItem, write=SetGalleryItem};
	__property ItemLinks;
	__property ItemOptions;
	__property PopupAlignment = {default=0};
	__property Ribbon;
	__property UseOwnFont;
	__property OnCloseUp;
	__property OnPaintBar;
	__property OnPopup;
public:
	/* TdxRibbonCustomPopupMenu.Create */ inline __fastcall virtual TdxRibbonDropDownGallery(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonCustomPopupMenu(AOwner) { }
	/* TdxRibbonCustomPopupMenu.Destroy */ inline __fastcall virtual ~TdxRibbonDropDownGallery(void) { }
	
};


class DELPHICLASS TdxRibbonDropDownGalleryGalleryItemItemLinks;
class PASCALIMPLEMENTATION TdxRibbonDropDownGalleryGalleryItemItemLinks : public Dxbar::TdxBarSubMenuControlItemLinks
{
	typedef Dxbar::TdxBarSubMenuControlItemLinks inherited;
	
public:
	virtual bool __fastcall CanContainItem(Dxbar::TdxBarItem* AItem, /* out */ System::UnicodeString &AErrorText)/* overload */;
public:
	/* TdxBarItemLinks.Create */ inline __fastcall TdxRibbonDropDownGalleryGalleryItemItemLinks(Dxbar::TdxBarManager* ABarManager, Dxbar::_di_IdxBarLinksOwner ALinksOwner) : Dxbar::TdxBarSubMenuControlItemLinks(ABarManager, ALinksOwner) { }
	/* TdxBarItemLinks.Destroy */ inline __fastcall virtual ~TdxRibbonDropDownGalleryGalleryItemItemLinks(void) { }
	
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  CanContainItem(Dxbar::TdxBarItem* AItem){ return Dxbar::TdxBarItemLinks::CanContainItem(AItem); }
	
};


class DELPHICLASS TdxRibbonDropDownGalleryControlPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonDropDownGalleryControlPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxbar::TdxBarPainter* FPainter;
	
protected:
	bool __fastcall HasSizingBand(TdxRibbonDropDownGalleryControl* AGalleryControl);
	
public:
	__fastcall virtual TdxRibbonDropDownGalleryControlPainter(Dxbar::TdxBarPainter* APainter);
	virtual int __fastcall GetSizingBandHeight(TdxRibbonDropDownGalleryControl* AGalleryControl);
	virtual bool __fastcall PtInSizingArea(TdxRibbonDropDownGalleryControl* AGalleryControl, const System::Types::TPoint &P);
	void __fastcall SubMenuControlDrawBorder(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC DC, const System::Types::TRect &R);
	__property Dxbar::TdxBarPainter* Painter = {read=FPainter};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonDropDownGalleryControlPainter(void) { }
	
};

#pragma pack(pop)

enum TdxDropDownGalleryResizingState : unsigned char { grsNone, grsTop, grsTopRight, grsBottom, grsBottomRight };

class PASCALIMPLEMENTATION TdxRibbonDropDownGalleryControl : public Dxribbon::TdxRibbonPopupMenuControl
{
	typedef Dxribbon::TdxRibbonPopupMenuControl inherited;
	
private:
	TdxCustomRibbonGalleryItem* FGalleryItem;
	TdxRibbonDropDownGalleryGalleryItemItemLinks* FGalleryItemItemLinks;
	Dxtouch::TdxGestureHelper* FGestureHelper;
	int FHeight;
	int FHitTest;
	TdxRibbonDropDownGalleryControlPainter* FInternalPainter;
	bool FIsResizingAssigned;
	System::Types::TPoint FMouseResizingDelta;
	int FMouseWheelStep;
	TdxDropDownGalleryResizingState FResizingState;
	TdxRibbonGallerySubmenuResizing FResizing;
	bool FUseInternalSizeValue;
	void __fastcall DoResizing(void);
	TdxRibbonGalleryControl* __fastcall GetInternalGalleryItemControl(void);
	Dxbar::TdxBarItemLink* __fastcall GetInternalGalleryItemLink(void);
	TdxRibbonDropDownGalleryControlPainter* __fastcall GetInternalPainter(void);
	int __fastcall GetMouseWheelStep(void);
	TdxRibbonGallerySubmenuResizing __fastcall GetResizing(void);
	TdxDropDownGalleryResizingState __fastcall HitTestToResizingState(void);
	bool __fastcall IsHitTestResizing(void);
	void __fastcall SetResizing(TdxRibbonGallerySubmenuResizing Value);
	void __fastcall StartResizing(void);
	void __fastcall StopResizing(void);
	MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	
protected:
	bool __fastcall AllowGesture(int AGestureId);
	bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	void __fastcall EndGestureScroll(void);
	void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	int __fastcall GetPanOptions(void);
	bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint);
	NativeUInt __fastcall GetGestureClientHandle(void);
	bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual void __fastcall DoGesture(const Vcl::Controls::TGestureEventInfo &EventInfo, bool &Handled);
	virtual void __fastcall DoGetGestureOptions(Vcl::Controls::TInteractiveGestures &Gestures, Vcl::Controls::TInteractiveGestureOptions &Options);
	virtual Vcl::Controls::TInteractiveGestures __fastcall GetDefaultInteractiveGestures(void);
	virtual Vcl::Controls::TInteractiveGestureOptions __fastcall GetDefaultInteractiveGestureOptions(void);
	DYNAMIC bool __fastcall IsTouchPropertyStored(Vcl::Controls::TTouchProperty AProperty);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	virtual int __fastcall GetDefaultPanOptions(void);
	virtual void __fastcall CalcColumnItemRects(int ATopIndex, /* out */ int &ALastItemBottom);
	virtual bool __fastcall ChangeSizeByChildItemControl(/* out */ System::Types::TSize &ASize);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	virtual void __fastcall DoNCPaint(HDC DC, const System::Types::TRect &ARect);
	virtual Dxbar::TdxBarItemLink* __fastcall DoFindLinkWithAccel(System::Word AKey, System::Classes::TShiftState AShift, Dxbar::TdxBarItemLink* ACurrentLink);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual System::Types::TRect __fastcall GetClientOffset(bool AIncludeDetachCaption = true);
	virtual System::Types::TSize __fastcall GetItemsPaneSize(void);
	virtual System::Types::TSize __fastcall GetMinSize(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall IsControlExists(Dxbar::TdxBarItemControl* ABarItemControl);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual bool __fastcall IsResizing(void);
	bool __fastcall IsSizingBandAtBottom(void);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall MustFitInWorkAreaWidth(void);
	virtual bool __fastcall NeedsMouseWheel(void);
	virtual bool __fastcall NeedsSelectFirstItemOnDropDownByKey(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall UpdateItem(Dxbar::TdxBarItemControl* AControl);
	virtual int __fastcall GetBorderSize(void);
	virtual System::Types::TRect __fastcall GetItemsRectOffset(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TdxCustomRibbonGalleryItem* GalleryItem = {read=FGalleryItem, write=FGalleryItem};
	__property TdxRibbonGalleryControl* InternalGalleryItemControl = {read=GetInternalGalleryItemControl};
	__property Dxbar::TdxBarItemLink* InternalGalleryItemLink = {read=GetInternalGalleryItemLink};
	__property TdxRibbonDropDownGalleryControlPainter* InternalPainter = {read=GetInternalPainter};
	__property TdxRibbonGallerySubmenuResizing Resizing = {read=GetResizing, write=SetResizing, nodefault};
	
public:
	__fastcall virtual TdxRibbonDropDownGalleryControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonDropDownGalleryControl(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonDropDownGalleryControl(HWND ParentWindow) : Dxribbon::TdxRibbonPopupMenuControl(ParentWindow) { }
	
private:
	void *__IdxGestureOwner;	/* Dxtouch::IdxGestureOwner */
	void *__IdxGestureClient;	/* Dxtouch::IdxGestureClient */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4DF001DA-BE2C-4817-B75C-55171270D158}
	operator Dxtouch::_di_IdxGestureOwner()
	{
		Dxtouch::_di_IdxGestureOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureOwner*(void) { return (Dxtouch::IdxGestureOwner*)&__IdxGestureOwner; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {652B8A09-DAC8-4332-9206-C8905AEE7791}
	operator Dxtouch::_di_IdxGestureClient()
	{
		Dxtouch::_di_IdxGestureClient intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient*(void) { return (Dxtouch::IdxGestureClient*)&__IdxGestureClient; }
	#endif
	
};


class DELPHICLASS TdxRibbonDropDownGalleryControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonDropDownGalleryControlViewInfo : public Dxbar::TdxBarSubMenuControlViewInfo
{
	typedef Dxbar::TdxBarSubMenuControlViewInfo inherited;
	
private:
	HIDESBASE TdxRibbonDropDownGalleryControl* __fastcall GetBarControl(void);
	
public:
	virtual void __fastcall Calculate(void);
	__property TdxRibbonDropDownGalleryControl* BarControl = {read=GetBarControl};
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxRibbonDropDownGalleryControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxbar::TdxBarSubMenuControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonDropDownGalleryControlViewInfo(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxRibbonGalleryGroupItemActionLink : public Vcl::Actnlist::TActionLink
{
	typedef Vcl::Actnlist::TActionLink inherited;
	
protected:
	TdxRibbonGalleryGroupItem* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHint(const System::UnicodeString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetOnExecute(System::Classes::TNotifyEvent Value);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TdxRibbonGalleryGroupItemActionLink(System::TObject* AClient) : Vcl::Actnlist::TActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TdxRibbonGalleryGroupItemActionLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxRibbonGalleryDefaultColumnCount = System::Int8(0x5);
static const System::Int8 dxRibbonGalleryGroupItemInRibbonImageIndent = System::Int8(0x1);
static const System::Int8 dxRibbonGalleryGroupItemIndent = System::Int8(0x3);
static const System::Int8 dxRibbonGalleryMinColumnCount = System::Int8(0x2);
}	/* namespace Dxribbongallery */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONGALLERY)
using namespace Dxribbongallery;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbongalleryHPP
