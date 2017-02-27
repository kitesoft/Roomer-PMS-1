// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutContainer.pas' rev: 24.00 (Win32)

#ifndef DxlayoutcontainerHPP
#define DxlayoutcontainerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLibraryConsts.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit
#include <dxLayoutSelection.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutcontainer
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxCustomLayoutItemClass;

typedef System::TMetaClass* TdxLayoutGroupClass;

typedef System::TMetaClass* TdxLayoutEmptySpaceItemClass;

typedef System::TMetaClass* TdxLayoutLabeledItemClass;

typedef System::TMetaClass* TdxLayoutSeparatorItemClass;

typedef System::TMetaClass* TdxLayoutGroupHelperClass;

typedef System::TMetaClass* TdxLayoutContainerPainterClass;

typedef System::TMetaClass* TdxCustomLayoutItemPainterClass;

typedef System::TMetaClass* TdxLayoutBasicItemPainterClass;

typedef System::TMetaClass* TdxLayoutItemPainterClass;

typedef System::TMetaClass* TdxLayoutGroupPainterClass;

typedef System::TMetaClass* TdxLayoutControlItemControlPainterClass;

typedef System::TMetaClass* TdxLayoutItemControlPainterClass;

typedef System::TMetaClass* TdxCustomLayoutItemCaptionPainterClass;

typedef System::TMetaClass* TdxLayoutGroupButtonPainterClass;

typedef System::TMetaClass* TdxLayoutEmptySpaceItemPainterClass;

typedef System::TMetaClass* TdxLayoutDirectionalItemPainterClass;

typedef System::TMetaClass* TdxLayoutSeparatorItemPainterClass;

typedef System::TMetaClass* TdxLayoutSplitterItemPainterClass;

typedef System::TMetaClass* TdxLayoutContainerViewInfoClass;

typedef System::TMetaClass* TdxCustomLayoutItemViewInfoClass;

typedef System::TMetaClass* TdxLayoutItemControlViewInfoClass;

typedef System::TMetaClass* TdxLayoutItemViewInfoClass;

typedef System::TMetaClass* TdxLayoutGroupViewInfoClass;

typedef System::TMetaClass* TdxLayoutGroupButtonViewInfoClass;

typedef System::TMetaClass* TdxLayoutEmptySpaceItemViewInfoClass;

typedef System::TMetaClass* TdxLayoutSeparatorItemViewInfoClass;

typedef System::TMetaClass* TdxLayoutSplitterItemViewInfoClass;

typedef System::TMetaClass* TdxLayoutGroupViewInfoSpecificClass;

enum TdxLayoutAlignHorz : unsigned char { ahLeft, ahCenter, ahRight, ahClient, ahParentManaged };

enum TdxLayoutAlignVert : unsigned char { avTop, avCenter, avBottom, avClient, avParentManaged };

typedef TdxLayoutAlignHorz TdxLayoutItemControlAlignHorz;

typedef TdxLayoutAlignVert TdxLayoutItemControlAlignVert;

enum TdxLayoutAutoAlign : unsigned char { aaHorizontal, aaVertical };

typedef System::Set<TdxLayoutAutoAlign, TdxLayoutAutoAlign::aaHorizontal, TdxLayoutAutoAlign::aaVertical>  TdxLayoutAutoAligns;

enum TdxLayoutDirection : unsigned char { ldHorizontal, ldVertical, ldTabbed };

enum TdxLayoutAreaPart : unsigned char { apNone, apLeft, apTop, apRight, apBottom, apCenter, apBefore, apAfter, apBeforeContent, apAfterContent, apFirstChild, apLastChild };

enum TdxLayoutActionType : unsigned char { atNone, atInsert, atCreateGroup, atContentInsert };

enum TdxLayoutCustomizeFormUpdateType : unsigned char { cfutCaption, cfutAvailableItems, cfutVisibleItems, cfutSelection, cfutView, cfutDragAndDropState };

typedef System::Set<TdxLayoutCustomizeFormUpdateType, TdxLayoutCustomizeFormUpdateType::cfutCaption, TdxLayoutCustomizeFormUpdateType::cfutDragAndDropState>  TdxLayoutCustomizeFormUpdateTypes;

enum TdxLayoutCustomizeFormMenuItem : unsigned char { cfmiAlignHorz, cfmiAlignVert, cfmiDirection, cfmiCaptionLayout, cfmiCaptionAlignHorz, cfmiCaptionAlignVert, cfmiCaption, cfmiBorder, cfmiExpandButton, cfmiGrouping };

typedef System::Set<TdxLayoutCustomizeFormMenuItem, TdxLayoutCustomizeFormMenuItem::cfmiAlignHorz, TdxLayoutCustomizeFormMenuItem::cfmiGrouping>  TdxLayoutCustomizeFormMenuItems;

enum TdxLayoutAvailableItemsViewKind : unsigned char { aivkList, aivkTree };

class DELPHICLASS TdxCustomLayoutItem;
typedef void __fastcall (__closure *TdxLayoutItemChangedEvent)(TdxCustomLayoutItem* AItem);

__interface IdxLayoutContainer;
typedef System::DelphiInterface<IdxLayoutContainer> _di_IdxLayoutContainer;
class DELPHICLASS TdxLayoutContainer;
__interface  INTERFACE_UUID("{85310BD8-3D7A-454F-A54B-9898C0AA55A2}") IdxLayoutContainer  : public System::IInterface 
{
	
public:
	virtual TdxLayoutContainer* __fastcall GetContainer(void) = 0 ;
};

class DELPHICLASS TdxUndoRedoManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxUndoRedoManager : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxLayoutContainer* FContainer;
	System::Classes::TMemoryStream* FCurrentLayout;
	int FIndex;
	int FLockCount;
	System::Contnrs::TObjectList* FUndoList;
	void __fastcall AddUndo(System::Classes::TMemoryStream* ALayout);
	int __fastcall GetRedoCount(void);
	int __fastcall GetUndoCount(void);
	
protected:
	void __fastcall CancelLastUndo(void);
	bool __fastcall IsLocked(void);
	void __fastcall RestoreLayout(System::Classes::TStream* AStream);
	__property int RedoCount = {read=GetRedoCount, nodefault};
	__property int UndoCount = {read=GetUndoCount, nodefault};
	
public:
	__fastcall virtual TdxUndoRedoManager(TdxLayoutContainer* AContainer);
	__fastcall virtual ~TdxUndoRedoManager(void);
	bool __fastcall CanRedo(void);
	bool __fastcall CanUndo(void);
	void __fastcall Clear(void);
	void __fastcall Redo(void);
	void __fastcall SaveLayout(void);
	void __fastcall Undo(void);
	__property TdxLayoutContainer* Container = {read=FContainer};
};

#pragma pack(pop)

class DELPHICLASS TdxCustomLayoutItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomLayoutItem* FItem;
	bool __fastcall GetIsRestoring(void);
	
protected:
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall Changed(void);
	__property TdxCustomLayoutItem* Item = {read=FItem};
	__property bool IsRestoring = {read=GetIsRestoring, nodefault};
	
public:
	__fastcall virtual TdxCustomLayoutItemOptions(TdxCustomLayoutItem* AItem);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlCustomCustomizeForm;
class DELPHICLASS TdxCustomLayoutHitTest;
class PASCALIMPLEMENTATION TdxLayoutControlCustomCustomizeForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TdxLayoutContainer* FContainer;
	void __fastcall SetContainer(TdxLayoutContainer* AValue);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall CanAddItem(void);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall CanShowItem(TdxCustomLayoutItem* AItem);
	TdxLayoutCustomizeFormMenuItems __fastcall DoGetMenuItems(System::Classes::TList* AList);
	virtual void __fastcall DoInitializeControl(void);
	virtual NativeUInt __fastcall GetWndParent(void);
	virtual void __fastcall ItemChanged(TdxCustomLayoutItem* AItem);
	virtual Vcl::Menus::TPopupMenu* __fastcall GetLayoutPopupMenu(void);
	virtual void __fastcall InitializeControl(void);
	
public:
	__fastcall virtual ~TdxLayoutControlCustomCustomizeForm(void);
	virtual TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual void __fastcall ToggleHotTrackState(TdxCustomLayoutItem* AItem);
	virtual void __fastcall UpdateAvailableItems(void);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall UpdateContent(void);
	virtual void __fastcall UpdateDragAndDropState(void);
	virtual void __fastcall UpdateSelection(void);
	virtual void __fastcall UpdateView(void);
	virtual void __fastcall UpdateVisibleItems(void);
	__property TdxLayoutContainer* Container = {read=FContainer, write=SetContainer};
	__property Vcl::Menus::TPopupMenu* LayoutPopupMenu = {read=GetLayoutPopupMenu};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxLayoutControlCustomCustomizeForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxLayoutControlCustomCustomizeForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLayoutControlCustomCustomizeForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxLayoutControlCustomCustomizeFormClass;

class DELPHICLASS TdxCustomLayoutItemImageOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemImageOptions : public TdxCustomLayoutItemOptions
{
	typedef TdxCustomLayoutItemOptions inherited;
	
private:
	Vcl::Graphics::TBitmap* FGlyph;
	int FImageIndex;
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetImageIndex(int AValue);
	void __fastcall GlyphChanged(System::TObject* Sender);
	
protected:
	bool __fastcall GetCurrentImage(/* out */ Vcl::Graphics::TBitmap* &AGlyph, /* out */ Vcl::Imglist::TCustomImageList* &AImages, /* out */ int &AImageIndex);
	Vcl::Imglist::TCustomImageList* __fastcall GetImageList(bool AEnabled);
	System::Types::TSize __fastcall GetImageSize(void);
	bool __fastcall IsImageAssigned(void);
	
public:
	__fastcall virtual TdxCustomLayoutItemImageOptions(TdxCustomLayoutItem* AItem);
	__fastcall virtual ~TdxCustomLayoutItemImageOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
};

#pragma pack(pop)

enum TdxAlignmentVert : unsigned char { tavTop, tavCenter, tavBottom };

enum TdxCaptionLayout : unsigned char { clLeft, clTop, clRight, clBottom };

enum TdxLayoutItemCaptionVisibleElement : unsigned char { cveImage, cveText };

typedef System::Set<TdxLayoutItemCaptionVisibleElement, TdxLayoutItemCaptionVisibleElement::cveImage, TdxLayoutItemCaptionVisibleElement::cveText>  TdxLayoutItemCaptionVisibleElements;

class DELPHICLASS TdxCustomLayoutItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemCaptionOptions : public TdxCustomLayoutItemOptions
{
	typedef TdxCustomLayoutItemOptions inherited;
	
private:
	System::Classes::TAlignment FAlignHorz;
	TdxAlignmentVert FAlignVert;
	TdxCustomLayoutItemImageOptions* FImageOptions;
	TdxCaptionLayout FLayout;
	bool FShowAccelChar;
	System::UnicodeString FText;
	TdxLayoutItemCaptionVisibleElements FVisibleElements;
	bool FVisible;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	int __fastcall GetImageIndex(void);
	void __fastcall SetAlignHorz(System::Classes::TAlignment Value);
	void __fastcall SetAlignVert(TdxAlignmentVert Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetImageIndex(int AValue);
	void __fastcall SetImageOptions(TdxCustomLayoutItemImageOptions* Value);
	void __fastcall SetLayout(TdxCaptionLayout Value);
	void __fastcall SetShowAccelChar(bool Value);
	void __fastcall SetVisibleElements(TdxLayoutItemCaptionVisibleElements Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual bool __fastcall IsTextStored(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall SetText(const System::UnicodeString Value);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int ImageIndex = {read=GetImageIndex, write=SetImageIndex, default=-1};
	__property TdxCustomLayoutItemImageOptions* ImageOptions = {read=FImageOptions, write=SetImageOptions};
	__property TdxCaptionLayout Layout = {read=FLayout, write=SetLayout, nodefault};
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	__property TdxLayoutItemCaptionVisibleElements VisibleElements = {read=FVisibleElements, write=SetVisibleElements, default=3};
	
public:
	__fastcall virtual TdxCustomLayoutItemCaptionOptions(TdxCustomLayoutItem* AItem);
	__fastcall virtual ~TdxCustomLayoutItemCaptionOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::Classes::TAlignment AlignHorz = {read=FAlignHorz, write=SetAlignHorz, default=0};
	__property TdxAlignmentVert AlignVert = {read=FAlignVert, write=SetAlignVert, nodefault};
	__property System::UnicodeString Text = {read=GetText, write=SetText, stored=IsTextStored};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomLayoutItemCaptionOptionsClass;

enum TdxLayoutSizeOptionsValue : unsigned char { sovSizableHorz, sovSizableVert };

typedef System::Set<TdxLayoutSizeOptionsValue, TdxLayoutSizeOptionsValue::sovSizableHorz, TdxLayoutSizeOptionsValue::sovSizableVert>  TdxLayoutSizeOptionsValues;

class DELPHICLASS TdxLayoutSizeOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSizeOptions : public TdxCustomLayoutItemOptions
{
	typedef TdxCustomLayoutItemOptions inherited;
	
private:
	TdxLayoutSizeOptionsValues FAssignedValues;
	bool FSizableHorz;
	bool FSizableVert;
	int FWidth;
	int FHeight;
	bool __fastcall GetSizableHorz(void);
	bool __fastcall GetSizableVert(void);
	void __fastcall SetAssignedValues(TdxLayoutSizeOptionsValues Value);
	void __fastcall SetSizableHorz(bool Value);
	void __fastcall SetSizableVert(bool Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetWidth(int Value);
	bool __fastcall IsSizableHorzStored(void);
	bool __fastcall IsSizableVertStored(void);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxLayoutSizeOptionsValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property bool SizableHorz = {read=GetSizableHorz, write=SetSizableHorz, stored=IsSizableHorzStored, nodefault};
	__property bool SizableVert = {read=GetSizableVert, write=SetSizableVert, stored=IsSizableVertStored, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
public:
	/* TdxCustomLayoutItemOptions.Create */ inline __fastcall virtual TdxLayoutSizeOptions(TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemOptions(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutSizeOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutOffsets;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutOffsets : public TdxCustomLayoutItemOptions
{
	typedef TdxCustomLayoutItemOptions inherited;
	
private:
	int FBottom;
	int FLeft;
	int FRight;
	int FTop;
	
protected:
	virtual int __fastcall GetValue(int Index);
	virtual void __fastcall SetValue(int Index, int Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int Bottom = {read=GetValue, write=SetValue, index=1, default=0};
	__property int Left = {read=GetValue, write=SetValue, index=2, default=0};
	__property int Right = {read=GetValue, write=SetValue, index=3, default=0};
	__property int Top = {read=GetValue, write=SetValue, index=4, default=0};
public:
	/* TdxCustomLayoutItemOptions.Create */ inline __fastcall virtual TdxLayoutOffsets(TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemOptions(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutOffsets(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutPadding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutPadding : public TdxLayoutOffsets
{
	typedef TdxLayoutOffsets inherited;
	
private:
	Dxlayoutlookandfeels::TdxLayoutPaddingAssignedValues FAssignedValues;
	bool __fastcall IsValueStored(int Index);
	void __fastcall SetAssignedValues(Dxlayoutlookandfeels::TdxLayoutPaddingAssignedValues Value);
	
protected:
	virtual int __fastcall GetValue(int Index);
	virtual void __fastcall SetValue(int Index, int Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::Types::TRect __fastcall GetValues(void);
	
__published:
	__property Dxlayoutlookandfeels::TdxLayoutPaddingAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property Bottom = {stored=IsValueStored, index=1, default=0};
	__property Left = {stored=IsValueStored, index=2, default=0};
	__property Right = {stored=IsValueStored, index=3, default=0};
	__property Top = {stored=IsValueStored, index=4, default=0};
public:
	/* TdxCustomLayoutItemOptions.Create */ inline __fastcall virtual TdxLayoutPadding(TdxCustomLayoutItem* AItem) : TdxLayoutOffsets(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutPadding(void) { }
	
};

#pragma pack(pop)

enum TdxLayoutItemChangeType : unsigned char { ictHard, ictMedium, ictLight, ictComplex };

enum TdxCustomLayoutItemAssignedValue : unsigned char { liavEnabled };

typedef System::Set<TdxCustomLayoutItemAssignedValue, TdxCustomLayoutItemAssignedValue::liavEnabled, TdxCustomLayoutItemAssignedValue::liavEnabled>  TdxCustomLayoutItemAssignedValues;

class DELPHICLASS TdxLayoutAlignmentConstraint;
class DELPHICLASS TdxLayoutGroup;
class DELPHICLASS TdxCustomLayoutItemViewInfo;
class DELPHICLASS TdxLayoutItem;
class PASCALIMPLEMENTATION TdxCustomLayoutItem : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TdxLayoutAlignHorz FAlignHorz;
	TdxLayoutAlignmentConstraint* FAlignmentConstraint;
	TdxLayoutAlignVert FAlignVert;
	bool FAllowRemove;
	TdxCustomLayoutItemAssignedValues FAssignedValues;
	int FCachedTextHeight;
	TdxLayoutContainer* FContainer;
	bool FCustomization;
	void *FData;
	bool FEnabled;
	bool FIsUserDefined;
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* FLayoutLookAndFeel;
	int FLoadedIndex;
	System::UnicodeString FLoadedParentName;
	bool FSuperfluous;
	TdxLayoutOffsets* FOffsets;
	TdxLayoutPadding* FPadding;
	TdxLayoutGroup* FParent;
	bool FVisible;
	TdxCustomLayoutItemViewInfo* FViewInfo;
	TdxCustomLayoutItemCaptionOptions* FCaptionOptions;
	TdxLayoutSizeOptions* FSizeOptions;
	System::Classes::TNotifyEvent FOnCaptionClick;
	void __fastcall ApplyLoadedPosition(void);
	TdxLayoutAlignHorz __fastcall GetRealAlignHorz(void);
	TdxLayoutAlignVert __fastcall GetRealAlignVert(void);
	bool __fastcall GetActuallyVisible(void);
	TdxLayoutAutoAligns __fastcall GetAutoAligns(void);
	TdxLayoutAlignHorz __fastcall GetAlignHorz(void);
	TdxLayoutAlignVert __fastcall GetAlignVert(void);
	System::UnicodeString __fastcall GetCaption(void);
	System::UnicodeString __fastcall GetCaptionForCustomizeForm(void);
	bool __fastcall GetEnabled(void);
	int __fastcall GetIndex(void);
	TdxCustomLayoutItemViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleIndex(void);
	void __fastcall SetAlignHorz(TdxLayoutAlignHorz Value);
	void __fastcall SetAlignmentConstraint(TdxLayoutAlignmentConstraint* Value);
	void __fastcall SetAlignVert(TdxLayoutAlignVert Value);
	void __fastcall SetAutoAligns(TdxLayoutAutoAligns Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetCaptionOptions(TdxCustomLayoutItemCaptionOptions* const Value);
	void __fastcall SetContainer(TdxLayoutContainer* Value);
	void __fastcall SetCustomization(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetLayoutLookAndFeel(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetOffsets(TdxLayoutOffsets* const Value);
	void __fastcall SetPadding(TdxLayoutPadding* const Value);
	void __fastcall SetParent(TdxLayoutGroup* Value);
	void __fastcall SetShowCaption(bool Value);
	void __fastcall SetViewInfo(TdxCustomLayoutItemViewInfo* Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetVisibleIndex(int Value);
	void __fastcall SetSizeOptions(TdxLayoutSizeOptions* Value);
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int Value);
	void __fastcall SetWidth(int Value);
	void __fastcall ReadIndex(System::Classes::TReader* Reader);
	void __fastcall WriteIndex(System::Classes::TWriter* Writer);
	bool __fastcall IsAlignHorzStored(void);
	bool __fastcall IsAlignVertStored(void);
	bool __fastcall IsEnabledStored(void);
	
protected:
	void __stdcall BeginLayoutLookAndFeelUserDestroying(void);
	void __stdcall EndLayoutLookAndFeelUserDestroying(void);
	void __stdcall LayoutLookAndFeelUserChanged(void);
	void __stdcall LayoutLookAndFeelUserDestroyed(void);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall IsOwner(System::Classes::TComponent* AOwner);
	virtual void __fastcall SelectComponent(System::Classes::TShiftState AShift = System::Classes::TShiftState() );
	virtual void __fastcall SelectParent(void);
	virtual void __fastcall SelectionChanged(void);
	virtual bool __fastcall IsSelectableItemVisible(void);
	virtual void __fastcall SelectableItemMakeVisible(void);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	virtual void __fastcall LayoutLookAndFeelChanged(void);
	virtual void __fastcall SetInitialSettings(void);
	virtual bool __fastcall CanBeAlone(void);
	virtual bool __fastcall CanDragAndDrop(const System::Types::TPoint &P);
	virtual bool __fastcall CanProcessAccel(/* out */ TdxCustomLayoutItem* &AItem);
	virtual bool __fastcall CanRemove(void);
	virtual bool __fastcall CanResizeHorz(void);
	virtual bool __fastcall CanResizeVert(void);
	virtual bool __fastcall HasControl(void);
	virtual bool __fastcall HasCaption(void);
	bool __fastcall IsHorzLocalPositionStable(void);
	bool __fastcall IsHorzPositionStable(void);
	bool __fastcall IsVertLocalPositionStable(void);
	bool __fastcall IsVertPositionStable(void);
	virtual void __fastcall DoGetTabOrderList(System::Classes::TList* List);
	void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual System::UnicodeString __fastcall GetInplaceRenameCaption(void);
	virtual void __fastcall SetInplaceRenameCaption(const System::UnicodeString ACaption);
	DYNAMIC void __fastcall DoCaptionDown(void);
	DYNAMIC void __fastcall DoCaptionClick(void);
	virtual void __fastcall DoPack(void);
	DYNAMIC bool __fastcall DoProcessAccel(void);
	virtual TdxLayoutAlignHorz __fastcall GetParentManagedAlignHorz(void);
	virtual TdxLayoutAlignVert __fastcall GetParentManagedAlignVert(void);
	virtual System::UnicodeString __fastcall GetBaseName(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual bool __fastcall GetIsRoot(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	virtual bool __fastcall GetShowCaption(void);
	virtual bool __fastcall GetVisible(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetOptions(void) = 0 ;
	virtual void __fastcall BeforeCalculateViewInfo(void);
	virtual void __fastcall AfterCalculateViewInfo(void);
	virtual void __fastcall ApplyCalculatedChanges(void);
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall CheckIndex(void);
	virtual bool __fastcall IsNeedDeleteAfterLoading(void);
	virtual void __fastcall PopulateItems(System::Classes::TList* AList);
	void __fastcall SetLoadedInfo(const System::UnicodeString AParentName, int AIndex);
	virtual bool __fastcall IsExpanded(void);
	virtual bool __fastcall IsGroup(void);
	bool __fastcall IsParentGroup(TdxLayoutGroup* AParentGroup);
	bool __fastcall IsChildItem(TdxCustomLayoutItem* AChildItem);
	virtual bool __fastcall CanInit(void);
	virtual void __fastcall DoInit(void);
	void __fastcall Init(void);
	bool __fastcall IsAvailable(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsDragged(void);
	bool __fastcall IsImageVisible(void);
	bool __fastcall IsLoading(void);
	virtual bool __fastcall IsLocked(void);
	virtual bool __fastcall IsParentLocked(void);
	bool __fastcall IsSelected(void);
	bool __fastcall IsTextVisible(void);
	virtual bool __fastcall IsVisibleForCustomization(void);
	bool __fastcall IsViewInfoValid(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall ProcessAccel(void);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall ProcessDialogKey(System::Word ACharCode, int AKeyData, TdxLayoutItem* AFocusedItem);
	virtual void __fastcall RestoreItemControlSize(void);
	void __fastcall ResetCachedTextHeight(void);
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	__classmethod virtual int __fastcall GetItemClassKind();
	TdxLayoutGroupHelperClass __fastcall GetParentHelperClass(void);
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void) = 0 ;
	virtual void __fastcall LoadFromIni(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection, int AVersion);
	virtual void __fastcall SaveToIni(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	virtual bool __fastcall Focused(void);
	virtual bool __fastcall FocusFirst(bool ACheckTabStop);
	void __fastcall DoItemChanged(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(bool ANeedPack = true);
	void __fastcall Changed(TdxLayoutItemChangeType AType = (TdxLayoutItemChangeType)(0x0));
	virtual void __fastcall DoChanged(TdxLayoutItemChangeType AType);
	void __fastcall ParentChanged(TdxLayoutItemChangeType AType);
	virtual void __fastcall ContainerChanged(void);
	virtual void __fastcall CustomizationChanged(void);
	virtual void __fastcall EnabledChanged(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall IsFocused(void);
	__property int CachedTextHeight = {read=FCachedTextHeight, write=FCachedTextHeight, nodefault};
	__property bool Customization = {read=FCustomization, write=SetCustomization, nodefault};
	__property bool IsUserDefined = {read=FIsUserDefined, write=FIsUserDefined, nodefault};
	__property int LoadedIndex = {read=FLoadedIndex, nodefault};
	__property bool Superfluous = {read=FSuperfluous, write=FSuperfluous, nodefault};
	__property TdxLayoutPadding* Padding = {read=FPadding, write=SetPadding};
	__property System::Classes::TNotifyEvent OnCaptionClick = {read=FOnCaptionClick, write=FOnCaptionClick};
	
public:
	__fastcall virtual TdxCustomLayoutItem(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction(void);
	__fastcall virtual ~TdxCustomLayoutItem(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual bool __fastcall CanMoveTo(TdxCustomLayoutItem* AParent);
	void __fastcall MakeVisible(void);
	bool __fastcall Move(TdxLayoutGroup* AParent, int AIndex, bool APack = false);
	bool __fastcall MoveTo(TdxLayoutGroup* AParent, int AVisibleIndex, bool APack = false);
	void __fastcall Pack(void);
	TdxLayoutGroup* __fastcall PutIntoHiddenGroup(TdxLayoutDirection ALayoutDirection);
	void __fastcall ToggleHotTrackState(void);
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property bool AllowRemove = {read=FAllowRemove, write=FAllowRemove, default=1};
	__property System::UnicodeString CaptionForCustomizeForm = {read=GetCaptionForCustomizeForm};
	__property TdxLayoutContainer* Container = {read=FContainer, write=SetContainer};
	__property void * Data = {read=FData, write=FData};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, stored=IsEnabledStored, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property TdxCustomLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisibleIndex = {read=GetVisibleIndex, write=SetVisibleIndex, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	
__published:
	__property TdxLayoutAutoAligns AutoAligns = {read=GetAutoAligns, write=SetAutoAligns, stored=false, nodefault};
	__property TdxLayoutAlignHorz AlignHorz = {read=GetAlignHorz, write=SetAlignHorz, stored=IsAlignHorzStored, nodefault};
	__property TdxLayoutAlignVert AlignVert = {read=GetAlignVert, write=SetAlignVert, stored=IsAlignVertStored, nodefault};
	__property TdxLayoutAlignmentConstraint* AlignmentConstraint = {read=FAlignmentConstraint, write=SetAlignmentConstraint};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=false};
	__property TdxCustomLayoutItemCaptionOptions* CaptionOptions = {read=FCaptionOptions, write=SetCaptionOptions};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LookAndFeel = {read=FLayoutLookAndFeel, write=SetLayoutLookAndFeel, stored=false};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=FLayoutLookAndFeel, write=SetLayoutLookAndFeel};
	__property TdxLayoutOffsets* Offsets = {read=FOffsets, write=SetOffsets};
	__property TdxLayoutGroup* Parent = {read=FParent, write=SetParent};
	__property bool ShowCaption = {read=GetShowCaption, write=SetShowCaption, stored=false, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property TdxLayoutSizeOptions* SizeOptions = {read=FSizeOptions, write=SetSizeOptions};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IdxLayoutSelectableItem;	/* Dxlayoutselection::IdxLayoutSelectableItem */
	void *__IdxLayoutLookAndFeelUser;	/* Dxlayoutlookandfeels::IdxLayoutLookAndFeelUser */
	
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
	// {2887168D-78EB-44A0-A440-E284B01BE407}
	operator Dxlayoutselection::_di_IdxLayoutSelectableItem()
	{
		Dxlayoutselection::_di_IdxLayoutSelectableItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutselection::IdxLayoutSelectableItem*(void) { return (Dxlayoutselection::IdxLayoutSelectableItem*)&__IdxLayoutSelectableItem; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {651F19FE-CBCB-4C16-8615-BBD57ED7255A}
	operator Dxlayoutlookandfeels::_di_IdxLayoutLookAndFeelUser()
	{
		Dxlayoutlookandfeels::_di_IdxLayoutLookAndFeelUser intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutlookandfeels::IdxLayoutLookAndFeelUser*(void) { return (Dxlayoutlookandfeels::IdxLayoutLookAndFeelUser*)&__IdxLayoutLookAndFeelUser; }
	#endif
	
};


class DELPHICLASS TdxLayoutBasicItem;
class PASCALIMPLEMENTATION TdxLayoutBasicItem : public TdxCustomLayoutItem
{
	typedef TdxCustomLayoutItem inherited;
	
protected:
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutBasicItem(System::Classes::TComponent* AOwner) : TdxCustomLayoutItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutBasicItem(void) { }
	
};


class DELPHICLASS TdxLayoutNonLabeledItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutNonLabeledItemCaptionOptions : public TdxCustomLayoutItemCaptionOptions
{
	typedef TdxCustomLayoutItemCaptionOptions inherited;
	
__published:
	__property Text = {default=0};
public:
	/* TdxCustomLayoutItemCaptionOptions.Create */ inline __fastcall virtual TdxLayoutNonLabeledItemCaptionOptions(TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemCaptionOptions(AItem) { }
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutNonLabeledItemCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutNonLabeledItem;
class PASCALIMPLEMENTATION TdxLayoutNonLabeledItem : public TdxLayoutBasicItem
{
	typedef TdxLayoutBasicItem inherited;
	
private:
	TdxLayoutNonLabeledItemCaptionOptions* __fastcall GetCaptionOptions(void);
	HIDESBASE void __fastcall SetCaptionOptions(TdxLayoutNonLabeledItemCaptionOptions* Value);
	
protected:
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	
__published:
	__property Enabled;
	__property TdxLayoutNonLabeledItemCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutNonLabeledItem(System::Classes::TComponent* AOwner) : TdxLayoutBasicItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutNonLabeledItem(void) { }
	
};


class DELPHICLASS TdxLayoutEmptySpaceItem;
class PASCALIMPLEMENTATION TdxLayoutEmptySpaceItem : public TdxLayoutNonLabeledItem
{
	typedef TdxLayoutNonLabeledItem inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetBaseName(void);
	__classmethod virtual int __fastcall GetItemClassKind();
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall CanBeAlone(void);
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutEmptySpaceItem(System::Classes::TComponent* AOwner) : TdxLayoutNonLabeledItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutEmptySpaceItem(void) { }
	
};


class DELPHICLASS TdxLayoutDirectionalItem;
class PASCALIMPLEMENTATION TdxLayoutDirectionalItem : public TdxLayoutNonLabeledItem
{
	typedef TdxLayoutNonLabeledItem inherited;
	
private:
	bool __fastcall GetIsVertical(void);
	
protected:
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall CanBeAlone(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetOptions(void);
	
public:
	__fastcall virtual TdxLayoutDirectionalItem(System::Classes::TComponent* AOwner);
	__property bool IsVertical = {read=GetIsVertical, nodefault};
public:
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutDirectionalItem(void) { }
	
};


class DELPHICLASS TdxLayoutSeparatorItem;
class PASCALIMPLEMENTATION TdxLayoutSeparatorItem : public TdxLayoutDirectionalItem
{
	typedef TdxLayoutDirectionalItem inherited;
	
protected:
	__classmethod virtual int __fastcall GetItemClassKind();
	virtual System::UnicodeString __fastcall GetBaseName(void);
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
public:
	/* TdxLayoutDirectionalItem.Create */ inline __fastcall virtual TdxLayoutSeparatorItem(System::Classes::TComponent* AOwner) : TdxLayoutDirectionalItem(AOwner) { }
	
public:
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutSeparatorItem(void) { }
	
};


class DELPHICLASS TdxLayoutSplitterItem;
class PASCALIMPLEMENTATION TdxLayoutSplitterItem : public TdxLayoutDirectionalItem
{
	typedef TdxLayoutDirectionalItem inherited;
	
protected:
	__classmethod virtual int __fastcall GetItemClassKind();
	virtual System::UnicodeString __fastcall GetBaseName(void);
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
public:
	/* TdxLayoutDirectionalItem.Create */ inline __fastcall virtual TdxLayoutSplitterItem(System::Classes::TComponent* AOwner) : TdxLayoutDirectionalItem(AOwner) { }
	
public:
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutSplitterItem(void) { }
	
};


class DELPHICLASS TdxCustomLayoutItemStorableCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemStorableCaptionOptions : public TdxCustomLayoutItemCaptionOptions
{
	typedef TdxCustomLayoutItemCaptionOptions inherited;
	
protected:
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
public:
	/* TdxCustomLayoutItemCaptionOptions.Create */ inline __fastcall virtual TdxCustomLayoutItemStorableCaptionOptions(TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemCaptionOptions(AItem) { }
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemStorableCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutLabeledItemCustomCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLabeledItemCustomCaptionOptions : public TdxCustomLayoutItemStorableCaptionOptions
{
	typedef TdxCustomLayoutItemStorableCaptionOptions inherited;
	
private:
	System::Uitypes::TCursor FCursor;
	int FWidth;
	void __fastcall SetWidth(int Value);
	
protected:
	__property System::Uitypes::TCursor Cursor = {read=FCursor, write=FCursor, default=0};
	
public:
	__fastcall virtual TdxLayoutLabeledItemCustomCaptionOptions(TdxCustomLayoutItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property AlignHorz = {default=0};
	__property AlignVert = {default=1};
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property VisibleElements = {default=3};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
public:
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutLabeledItemCustomCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCustomLabeledItem;
class PASCALIMPLEMENTATION TdxLayoutCustomLabeledItem : public TdxLayoutBasicItem
{
	typedef TdxLayoutBasicItem inherited;
	
private:
	TdxLayoutLabeledItemCustomCaptionOptions* __fastcall GetCaptionOptions(void);
	HIDESBASE void __fastcall SetCaptionOptions(TdxLayoutLabeledItemCustomCaptionOptions* Value);
	
protected:
	virtual TdxLayoutAlignVert __fastcall GetParentManagedAlignVert(void);
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetOptions(void);
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	__property TdxLayoutLabeledItemCustomCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
	
__published:
	__property Padding;
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutCustomLabeledItem(System::Classes::TComponent* AOwner) : TdxLayoutBasicItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutCustomLabeledItem(void) { }
	
};


class DELPHICLASS TdxLayoutLabeledItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLabeledItemCaptionOptions : public TdxLayoutLabeledItemCustomCaptionOptions
{
	typedef TdxLayoutLabeledItemCustomCaptionOptions inherited;
	
__published:
	__property AlignHorz = {default=0};
	__property AlignVert = {default=1};
	__property Cursor = {default=0};
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property ShowAccelChar = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property VisibleElements = {default=3};
	__property Width = {default=0};
public:
	/* TdxLayoutLabeledItemCustomCaptionOptions.Create */ inline __fastcall virtual TdxLayoutLabeledItemCaptionOptions(TdxCustomLayoutItem* AItem) : TdxLayoutLabeledItemCustomCaptionOptions(AItem) { }
	
public:
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutLabeledItemCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutLabeledItem;
class PASCALIMPLEMENTATION TdxLayoutLabeledItem : public TdxLayoutCustomLabeledItem
{
	typedef TdxLayoutCustomLabeledItem inherited;
	
private:
	HIDESBASE TdxLayoutLabeledItemCaptionOptions* __fastcall GetCaptionOptions(void);
	HIDESBASE void __fastcall SetCaptionOptions(TdxLayoutLabeledItemCaptionOptions* Value);
	
protected:
	virtual System::UnicodeString __fastcall GetBaseName(void);
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	__classmethod virtual int __fastcall GetItemClassKind();
	
__published:
	__property AllowRemove = {default=1};
	__property TdxLayoutLabeledItemCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
	__property Enabled;
	__property OnCaptionClick;
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutLabeledItem(System::Classes::TComponent* AOwner) : TdxLayoutCustomLabeledItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutLabeledItem(void) { }
	
};


class DELPHICLASS TdxCustomLayoutControlAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutControlAdapter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxLayoutItem* FItem;
	Vcl::Controls::TControl* __fastcall GetControl(void);
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	
protected:
	virtual bool __fastcall AllowCheckSize(void);
	virtual void __fastcall HideControlBorder(void);
	virtual void __fastcall Init(void);
	virtual void __fastcall AfterCalculateViewInfo(void);
	virtual void __fastcall InternalSetInitialSettings(void);
	virtual bool __fastcall NeedBorder(void);
	bool __fastcall HasBorderProperty(void);
	virtual bool __fastcall ShowItemCaption(void);
	virtual bool __fastcall UseItemColor(void);
	virtual void __fastcall BeginCustomization(void);
	virtual void __fastcall EndCustomization(void);
	__property Vcl::Controls::TControl* Control = {read=GetControl};
	__property TdxLayoutItem* Item = {read=FItem};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	
public:
	__fastcall virtual TdxCustomLayoutControlAdapter(TdxLayoutItem* AItem);
	virtual void __fastcall SetInitialSettings(void);
	__classmethod void __fastcall Register(Vcl::Controls::TControlClass AControlClass);
	__classmethod void __fastcall Unregister(Vcl::Controls::TControlClass AControlClass);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomLayoutControlAdapter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomLayoutControlAdapterClass;

class DELPHICLASS TdxLayoutItemCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemCaptionOptions : public TdxLayoutLabeledItemCaptionOptions
{
	typedef TdxLayoutLabeledItemCaptionOptions inherited;
	
__published:
	__property Layout = {default=0};
public:
	/* TdxLayoutLabeledItemCustomCaptionOptions.Create */ inline __fastcall virtual TdxLayoutItemCaptionOptions(TdxCustomLayoutItem* AItem) : TdxLayoutLabeledItemCaptionOptions(AItem) { }
	
public:
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutItemCaptionOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemControlOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemControlOptions : public TdxCustomLayoutItemOptions
{
	typedef TdxCustomLayoutItemOptions inherited;
	
private:
	TdxLayoutAlignHorz FAlignHorz;
	TdxLayoutAlignVert FAlignVert;
	bool FAutoControlAreaAlignment;
	bool FAutoColor;
	int FMinHeight;
	int FMinWidth;
	bool FOpaque;
	bool FShowBorder;
	bool __fastcall GetFixedSize(void);
	TdxLayoutItem* __fastcall GetItem(void);
	void __fastcall SetAlignHorz(TdxLayoutItemControlAlignHorz Value);
	void __fastcall SetAlignVert(TdxLayoutItemControlAlignVert Value);
	void __fastcall SetAutoControlAreaAlignment(bool Value);
	void __fastcall SetAutoColor(bool Value);
	void __fastcall SetFixedSize(bool Value);
	void __fastcall SetMinHeight(int Value);
	void __fastcall SetMinWidth(int Value);
	void __fastcall SetOpaque(bool Value);
	void __fastcall SetShowBorder(bool Value);
	
protected:
	__property TdxLayoutItem* Item = {read=GetItem};
	
public:
	__fastcall virtual TdxLayoutItemControlOptions(TdxCustomLayoutItem* AItem);
	bool __fastcall IsHeightFixed(void);
	bool __fastcall IsWidthFixed(void);
	
__published:
	__property TdxLayoutItemControlAlignHorz AlignHorz = {read=FAlignHorz, write=SetAlignHorz, default=3};
	__property TdxLayoutItemControlAlignVert AlignVert = {read=FAlignVert, write=SetAlignVert, default=3};
	__property bool AutoAlignment = {read=FAutoControlAreaAlignment, write=SetAutoControlAreaAlignment, stored=false, nodefault};
	__property bool AutoControlAreaAlignment = {read=FAutoControlAreaAlignment, write=SetAutoControlAreaAlignment, default=1};
	__property bool AutoColor = {read=FAutoColor, write=SetAutoColor, default=0};
	__property bool FixedSize = {read=GetFixedSize, write=SetFixedSize, stored=false, nodefault};
	__property int MinHeight = {read=FMinHeight, write=SetMinHeight, default=20};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=20};
	__property bool Opaque = {read=FOpaque, write=SetOpaque, default=0};
	__property bool ShowBorder = {read=FShowBorder, write=SetShowBorder, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutItemControlOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutItemControlOptionsClass;

class DELPHICLASS TdxLayoutControlItem;
class DELPHICLASS TdxLayoutControlItemViewInfo;
class PASCALIMPLEMENTATION TdxLayoutControlItem : public TdxLayoutCustomLabeledItem
{
	typedef TdxLayoutCustomLabeledItem inherited;
	
private:
	TdxLayoutItemControlOptions* FControlOptions;
	System::Types::TPoint FOriginalControlSize;
	HIDESBASE TdxLayoutControlItemViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetControlOptions(TdxLayoutItemControlOptions* Value);
	
protected:
	virtual void __fastcall DoInit(void);
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual bool __fastcall CanFocusControl(bool ACheckTabStop = false);
	virtual TdxLayoutItemControlOptionsClass __fastcall GetControlOptionsClass(void);
	__property TdxLayoutItemControlOptions* ControlOptions = {read=FControlOptions, write=SetControlOptions};
	
public:
	__property System::Types::TPoint OriginalControlSize = {read=FOriginalControlSize, write=FOriginalControlSize};
	__property TdxLayoutControlItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutControlItem(System::Classes::TComponent* AOwner) : TdxLayoutCustomLabeledItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TdxLayoutControlItem(void) { }
	
};


class DELPHICLASS TdxLayoutItemViewInfo;
class PASCALIMPLEMENTATION TdxLayoutItem : public TdxLayoutControlItem
{
	typedef TdxLayoutControlItem inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	bool FControlLocked;
	TdxCustomLayoutControlAdapter* FControlAdapter;
	System::Types::TPoint FControlSizeBeforeDestruction;
	bool FIsInternalHandleCreating;
	bool FIsNewControlSizeAssigned;
	System::Types::TPoint FNewControlSize;
	bool FControlSizeChanged;
	Dxlayoutselection::TdxControlsDesignSelectorHelper* FCustomizeControlHelper;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	HIDESBASE TdxLayoutItemCaptionOptions* __fastcall GetCaptionOptions(void);
	System::Types::TRect __fastcall GetDesignSelectorRect(void);
	HIDESBASE TdxLayoutItemViewInfo* __fastcall GetViewInfo(void);
	Vcl::Controls::TWinControl* __fastcall GetWinControl(void);
	HIDESBASE void __fastcall SetCaptionOptions(TdxLayoutItemCaptionOptions* Value);
	void __fastcall SetControl(Vcl::Controls::TControl* Value);
	bool __fastcall CanFocusControlOnCaptionClick(void);
	void __fastcall CreateControlAdapter(void);
	
protected:
	__classmethod virtual int __fastcall GetItemClassKind();
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanProcessAccel(/* out */ TdxCustomLayoutItem* &AItem);
	virtual void __fastcall ContainerChanged(void);
	virtual void __fastcall CustomizationChanged(void);
	DYNAMIC void __fastcall DoCaptionDown(void);
	virtual void __fastcall DoGetTabOrderList(System::Classes::TList* List);
	virtual bool __fastcall FocusFirst(bool ACheckTabStop);
	virtual System::UnicodeString __fastcall GetBaseName(void);
	DYNAMIC void __fastcall ProcessAccel(void);
	virtual void __fastcall RestoreItemControlSize(void);
	virtual void __fastcall AfterCalculateViewInfo(void);
	virtual void __fastcall BeforeCalculateViewInfo(void);
	virtual void __fastcall ApplyCalculatedChanges(void);
	virtual void __fastcall SetInitialSettings(void);
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall CanDragAndDrop(const System::Types::TPoint &P);
	virtual bool __fastcall CanFocusControl(bool ACheckTabStop = false);
	virtual void __fastcall ControlWndProc(Winapi::Messages::TMessage &Message);
	bool __fastcall IsDesignSelectorVisible(void);
	virtual bool __fastcall HasControl(void);
	bool __fastcall HasWinControl(void);
	void __fastcall SaveControlSizeBeforeDestruction(void);
	void __fastcall SaveOriginalControlSize(void);
	void __fastcall SetControlEnablement(void);
	void __fastcall SetControlFocus(void);
	void __fastcall SetControlVisibility(void);
	void __fastcall UpdateDesignSelectors(void);
	__property TdxCustomLayoutControlAdapter* ControlAdapter = {read=FControlAdapter};
	__property bool ControlLocked = {read=FControlLocked, nodefault};
	__property System::Types::TPoint ControlSizeBeforeDestruction = {read=FControlSizeBeforeDestruction};
	__property System::Types::TRect DesignSelectorRect = {read=GetDesignSelectorRect};
	__property Vcl::Controls::TWinControl* WinControl = {read=GetWinControl};
	
public:
	__fastcall virtual ~TdxLayoutItem(void);
	__property TdxLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
	
__published:
	__property AllowRemove = {default=1};
	__property TdxLayoutItemCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
	__property Vcl::Controls::TControl* Control = {read=FControl, write=SetControl};
	__property ControlOptions;
	__property Enabled;
	__property OnCaptionClick;
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TdxLayoutItem(System::Classes::TComponent* AOwner) : TdxLayoutControlItem(AOwner) { }
	
};


typedef System::TMetaClass* TdxLayoutItemClass;

class DELPHICLASS TdxLayoutGroupHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual TdxLayoutAlignHorz __fastcall GetChildItemsAlignHorz();
	__classmethod virtual TdxLayoutAlignVert __fastcall GetChildItemsAlignVert();
	__classmethod virtual TdxLayoutDirection __fastcall GetOrthogonalDirection();
	__classmethod virtual TdxLayoutGroupViewInfoSpecificClass __fastcall GetSpecificClass();
public:
	/* TObject.Create */ inline __fastcall TdxLayoutGroupHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutHorizontalGroupHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutHorizontalGroupHelper : public TdxLayoutGroupHelper
{
	typedef TdxLayoutGroupHelper inherited;
	
public:
	__classmethod virtual TdxLayoutAlignHorz __fastcall GetChildItemsAlignHorz();
	__classmethod virtual TdxLayoutAlignVert __fastcall GetChildItemsAlignVert();
	__classmethod virtual TdxLayoutDirection __fastcall GetOrthogonalDirection();
	__classmethod virtual TdxLayoutGroupViewInfoSpecificClass __fastcall GetSpecificClass();
public:
	/* TObject.Create */ inline __fastcall TdxLayoutHorizontalGroupHelper(void) : TdxLayoutGroupHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutHorizontalGroupHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutVerticalGroupHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutVerticalGroupHelper : public TdxLayoutGroupHelper
{
	typedef TdxLayoutGroupHelper inherited;
	
public:
	__classmethod virtual TdxLayoutAlignHorz __fastcall GetChildItemsAlignHorz();
	__classmethod virtual TdxLayoutAlignVert __fastcall GetChildItemsAlignVert();
	__classmethod virtual TdxLayoutDirection __fastcall GetOrthogonalDirection();
	__classmethod virtual TdxLayoutGroupViewInfoSpecificClass __fastcall GetSpecificClass();
public:
	/* TObject.Create */ inline __fastcall TdxLayoutVerticalGroupHelper(void) : TdxLayoutGroupHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutVerticalGroupHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutTabbedGroupHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutTabbedGroupHelper : public TdxLayoutHorizontalGroupHelper
{
	typedef TdxLayoutHorizontalGroupHelper inherited;
	
public:
	__classmethod virtual TdxLayoutAlignHorz __fastcall GetChildItemsAlignHorz();
	__classmethod virtual TdxLayoutAlignVert __fastcall GetChildItemsAlignVert();
	__classmethod virtual TdxLayoutDirection __fastcall GetOrthogonalDirection();
	__classmethod virtual TdxLayoutGroupViewInfoSpecificClass __fastcall GetSpecificClass();
public:
	/* TObject.Create */ inline __fastcall TdxLayoutTabbedGroupHelper(void) : TdxLayoutHorizontalGroupHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutTabbedGroupHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutTabbedOptions;
class PASCALIMPLEMENTATION TdxLayoutTabbedOptions : public Cxpc::TcxCustomTabControlProperties
{
	typedef Cxpc::TcxCustomTabControlProperties inherited;
	
private:
	Cxgraphics::TcxImageList* FInternalImages;
	TdxLayoutGroup* __fastcall GetGroup(void);
	Cxgraphics::TcxImageList* __fastcall GetInternalImages(void);
	System::UnicodeString __fastcall GetItemCaption(TdxCustomLayoutItem* AItem);
	
protected:
	virtual bool __fastcall DoCanChange(int NewTabIndex);
	void __fastcall CheckTabs(void);
	void __fastcall DeleteTab(TdxCustomLayoutItem* AItem);
	virtual void __fastcall DoSetTabIndex(int Value);
	TdxCustomLayoutItem* __fastcall GetItem(int AIndex);
	virtual int __fastcall GetTabIndex(void);
	void __fastcall InsertTab(TdxCustomLayoutItem* AItem);
	void __fastcall RefreshImages(void);
	void __fastcall RefreshTabsCaption(void);
	void __fastcall RefreshTabsEnabled(void);
	void __fastcall RefreshTabsVisible(void);
	__property TdxLayoutGroup* Group = {read=GetGroup};
	__property Cxgraphics::TcxImageList* InternalImages = {read=GetInternalImages};
	
public:
	__fastcall virtual TdxLayoutTabbedOptions(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxLayoutTabbedOptions(void);
	
__published:
	__property CloseButtonMode = {default=0};
	__property CloseTabWithMiddleClick = {default=0};
	__property HideTabs = {default=0};
	__property HotTrack = {default=0};
	__property ImageBorder = {default=0};
	__property MultiLine = {default=0};
	__property NavigatorPosition = {default=2};
	__property Options = {default=177};
	__property RaggedRight = {default=0};
	__property Rotate = {default=0};
	__property RotatedTabsMaxWidth = {default=0};
	__property ScrollOpposite = {default=0};
	__property ShowFrame = {default=0};
	__property TabCaptionAlignment = {default=2};
	__property TabHeight = {default=0};
	__property TabPosition = {default=0};
	__property TabWidth = {default=0};
};


class DELPHICLASS TdxLayoutGroupButton;
class DELPHICLASS TdxLayoutGroupButtons;
class PASCALIMPLEMENTATION TdxLayoutGroupButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FEnabled;
	Vcl::Graphics::TBitmap* FGlyph;
	unsigned FHeight;
	System::UnicodeString FHint;
	int FTag;
	bool FVisible;
	unsigned FWidth;
	System::Classes::TNotifyEvent FOnClick;
	System::Classes::TNotifyEvent FOnExpandButtonClick;
	TdxLayoutGroupButtons* __fastcall GetButtons(void);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetHeight(unsigned AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetWidth(unsigned AValue);
	
protected:
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall DoClick(void);
	bool __fastcall IsExpandButton(void);
	__property TdxLayoutGroupButtons* Buttons = {read=GetButtons};
	__property System::Classes::TNotifyEvent OnExpandButtonClick = {read=FOnExpandButtonClick, write=FOnExpandButtonClick};
	
public:
	__fastcall virtual TdxLayoutGroupButton(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxLayoutGroupButton(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::UnicodeString __fastcall GetNamePath(void);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property unsigned Height = {read=FHeight, write=SetHeight, default=0};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property int Tag = {read=FTag, write=FTag, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property unsigned Width = {read=FWidth, write=SetWidth, default=0};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
};


class DELPHICLASS TdxLayoutGroupButtonOptions;
class PASCALIMPLEMENTATION TdxLayoutGroupButtons : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxLayoutGroupButton* operator[](int Index) { return Items[Index]; }
	
private:
	TdxLayoutGroupButtonOptions* FOptions;
	System::Classes::TNotifyEvent FOnChange;
	HIDESBASE TdxLayoutGroupButton* __fastcall GetItem(int Index);
	TdxLayoutGroupButtonOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetItem(int Index, TdxLayoutGroupButton* const AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property TdxLayoutGroupButtonOptions* Options = {read=GetOptions};
	
public:
	__fastcall TdxLayoutGroupButtons(TdxLayoutGroupButtonOptions* AOptions);
	__property TdxLayoutGroupButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxLayoutGroupButtons(void) { }
	
};


enum TdxLayoutGroupButtonsAlignment : unsigned char { gbaLeft, gbaRight };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupButtonOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxLayoutGroupButtonsAlignment FAlignment;
	TdxLayoutGroupButtons* FButtons;
	unsigned FDefaultHeight;
	unsigned FDefaultWidth;
	TdxLayoutGroupButton* FExpandButton;
	TdxLayoutGroup* FGroup;
	TdxLayoutGroupButtons* FInternalButtons;
	bool FVisible;
	void __fastcall ChangeCollectionHandler(System::TObject* Sender);
	void __fastcall ExpandButtonClickHandler(System::TObject* Sender);
	bool __fastcall GetShowExpandButton(void);
	int __fastcall GetVisibleCount(void);
	void __fastcall SetAlignment(TdxLayoutGroupButtonsAlignment AValue);
	void __fastcall SetButtons(TdxLayoutGroupButtons* AValue);
	void __fastcall SetDefaultHeight(unsigned AValue);
	void __fastcall SetDefaultWidth(unsigned AValue);
	void __fastcall SetShowExpandButton(bool AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall Changed(void);
	bool __fastcall IsAnyButtonVisible(void);
	
public:
	__fastcall TdxLayoutGroupButtonOptions(TdxLayoutGroup* AGroup);
	__fastcall virtual ~TdxLayoutGroupButtonOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxLayoutGroupButton* ExpandButton = {read=FExpandButton};
	__property TdxLayoutGroup* Group = {read=FGroup};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	
__published:
	__property TdxLayoutGroupButtonsAlignment Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property TdxLayoutGroupButtons* Buttons = {read=FButtons, write=SetButtons};
	__property unsigned DefaultHeight = {read=FDefaultHeight, write=SetDefaultHeight, default=16};
	__property unsigned DefaultWidth = {read=FDefaultWidth, write=SetDefaultWidth, default=16};
	__property bool ShowExpandButton = {read=GetShowExpandButton, write=SetShowExpandButton, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupCaptionOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionOptions : public TdxCustomLayoutItemStorableCaptionOptions
{
	typedef TdxCustomLayoutItemStorableCaptionOptions inherited;
	
public:
	__fastcall virtual TdxLayoutGroupCaptionOptions(TdxCustomLayoutItem* AItem);
	
__published:
	__property AlignHorz = {default=0};
	__property AlignVert = {default=0};
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property Layout = {default=1};
	__property ShowAccelChar = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property VisibleElements = {default=3};
public:
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionOptions(void) { }
	
};

#pragma pack(pop)

enum TdxLayoutItemControlAreaAlignment : unsigned char { catDefault, catNone, catAuto, catOwn };

typedef void __fastcall (__closure *TdxLayoutGroupExpandingEvent)(System::TObject* Sender, bool &Allow);

typedef void __fastcall (__closure *TdxLayoutGroupTabChangingEvent)(System::TObject* Sender, int ANewTabIndex, bool &Allow);

class DELPHICLASS TdxLayoutGroupViewInfo;
class PASCALIMPLEMENTATION TdxLayoutGroup : public TdxCustomLayoutItem
{
	typedef TdxCustomLayoutItem inherited;
	
public:
	TdxCustomLayoutItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxLayoutGroupButtonOptions* FButtonOptions;
	bool FExpanded;
	bool FHidden;
	Cxclasses::TcxComponentList* FItems;
	int FItemIndex;
	Cxclasses::TcxComponentList* FVisibleItems;
	TdxLayoutDirection FLayoutDirection;
	TdxLayoutItemControlAreaAlignment FItemControlAreaAlignment;
	bool FLocked;
	bool FLayoutLookAndFeelException;
	bool FShowBorder;
	int FLockTabbedChangesCount;
	TdxLayoutTabbedOptions* FTabbedOptions;
	bool FUseIndent;
	System::Classes::TNotifyEvent FOnCollapsed;
	TdxLayoutGroupExpandingEvent FOnCollapsing;
	System::Classes::TNotifyEvent FOnExpanded;
	TdxLayoutGroupExpandingEvent FOnExpanding;
	System::Classes::TNotifyEvent FOnTabChanged;
	TdxLayoutGroupTabChangingEvent FOnTabChanging;
	void __fastcall TabbedOptionsChangedHandler(System::TObject* Sender, Cxpc::TcxCustomTabControlPropertiesChangedType AType);
	void __fastcall TabbedOptionsChangeHandler(System::TObject* Sender);
	void __fastcall TabCanCloseHandler(System::TObject* Sender, int ATabIndex, bool &ACanClose);
	void __fastcall TabClickHandler(System::TObject* Sender, int ATabVisibleIndex, System::Classes::TShiftState AShift);
	void __fastcall TabCloseHandler(System::TObject* Sender, int ATabIndex);
	TdxLayoutGroupCaptionOptions* __fastcall GetCaptionOptions(void);
	int __fastcall GetCount(void);
	TdxCustomLayoutItem* __fastcall GetItem(int Index);
	bool __fastcall GetShowBorder(void);
	HIDESBASE TdxLayoutGroupViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleCount(void);
	TdxCustomLayoutItem* __fastcall GetVisibleItem(int Index);
	void __fastcall SetButtonOptions(TdxLayoutGroupButtonOptions* Value);
	HIDESBASE void __fastcall SetCaptionOptions(TdxLayoutGroupCaptionOptions* Value);
	void __fastcall SetExpanded(bool Value);
	void __fastcall SetHidden(bool Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetItemControlAreaAlignment(TdxLayoutItemControlAreaAlignment Value);
	void __fastcall SetLayoutDirection(TdxLayoutDirection Value);
	void __fastcall SetLocked(bool Value);
	void __fastcall SetLayoutLookAndFeelException(bool Value);
	void __fastcall SetShowBorder(bool Value);
	void __fastcall SetTabbedOptions(TdxLayoutTabbedOptions* Value);
	void __fastcall SetUseIndent(bool Value);
	void __fastcall AddItem(TdxCustomLayoutItem* AItem);
	void __fastcall ExtractItem(TdxCustomLayoutItem* AItem);
	void __fastcall ItemListChanged(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall ReadSpecial(System::Classes::TReader* Reader);
	void __fastcall WriteSpecial(System::Classes::TWriter* Writer);
	bool __fastcall IsItemIndexStored(void);
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetChildLayoutLookAndFeel(void);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	__classmethod virtual int __fastcall GetItemClassKind();
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall CheckIndex(void);
	virtual bool __fastcall IsNeedDeleteAfterLoading(void);
	virtual void __fastcall PopulateItems(System::Classes::TList* AList);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanProcessAccel(/* out */ TdxCustomLayoutItem* &AItem);
	virtual bool __fastcall CanRemove(void);
	virtual void __fastcall ContainerChanged(void);
	virtual void __fastcall DoGetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall DoPack(void);
	__classmethod virtual TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	virtual System::UnicodeString __fastcall GetBaseName(void);
	virtual bool __fastcall GetIsRoot(void);
	virtual bool __fastcall GetShowCaption(void);
	virtual bool __fastcall GetVisible(void);
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall LoadFromIni(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection, int AVersion);
	virtual void __fastcall SaveToIni(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall ProcessDialogKey(System::Word ACharCode, int AKeyData, TdxLayoutItem* AFocusedItem);
	virtual void __fastcall RestoreItemControlSize(void);
	virtual void __fastcall LayoutLookAndFeelChanged(void);
	virtual void __fastcall SetInitialSettings(void);
	virtual void __fastcall BeforeCalculateViewInfo(void);
	virtual void __fastcall AfterCalculateViewInfo(void);
	virtual void __fastcall ApplyCalculatedChanges(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetOptions(void);
	virtual bool __fastcall IsExpanded(void);
	virtual bool __fastcall IsGroup(void);
	virtual bool __fastcall IsLocked(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual void __fastcall DoCollapsed(void);
	virtual bool __fastcall DoCollapsing(void);
	virtual void __fastcall DoExpanded(void);
	virtual bool __fastcall DoExpanding(void);
	virtual void __fastcall DoTabChanged(void);
	virtual bool __fastcall DoTabChanging(int ANewTabIndex);
	void __fastcall BuildVisibleItemsList(void);
	System::Types::TSize __fastcall GetMaxChildImageSize(void);
	TdxLayoutGroupHelperClass __fastcall GetHelperClass(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall FocusFirst(bool ACheckTabStop);
	virtual bool __fastcall AllowShowChild(TdxCustomLayoutItem* AChild);
	bool __fastcall IsAnyButtonVisible(void);
	void __fastcall LockTabbedChanges(void);
	void __fastcall UnlockTabbedChanges(void);
	void __fastcall ChangeItemIndex(TdxCustomLayoutItem* AItem, int Value);
	void __fastcall ChangeItemVisibleIndex(TdxCustomLayoutItem* AItem, int Value);
	int __fastcall GetItemIndex(int AItemVisibleIndex);
	int __fastcall IndexOf(TdxCustomLayoutItem* AItem);
	bool __fastcall IsSuperfluous(void);
	int __fastcall VisibleIndexOf(TdxCustomLayoutItem* AItem);
	
public:
	__fastcall virtual TdxLayoutGroup(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TdxLayoutGroup* __fastcall CreateGroup(TdxLayoutGroupClass AGroupClass = 0x0);
	TdxCustomLayoutItem* __fastcall CreateItem(TdxCustomLayoutItemClass AItemClass = 0x0);
	TdxLayoutItem* __fastcall CreateItemForControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall CanMoveTo(TdxCustomLayoutItem* AParent);
	void __fastcall MoveChildrenToParent(void);
	TdxLayoutGroup* __fastcall PutChildrenIntoHiddenGroup(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxCustomLayoutItem* Items[int Index] = {read=GetItem/*, default*/};
	__property IsUserDefined;
	__property TdxLayoutGroupViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property TdxCustomLayoutItem* VisibleItems[int Index] = {read=GetVisibleItem};
	
__published:
	__property AllowRemove = {default=1};
	__property TdxLayoutGroupButtonOptions* ButtonOptions = {read=FButtonOptions, write=SetButtonOptions};
	__property TdxLayoutGroupCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
	__property Enabled;
	__property bool Expanded = {read=FExpanded, write=SetExpanded, default=1};
	__property bool Hidden = {read=FHidden, write=SetHidden, default=0};
	__property TdxLayoutItemControlAreaAlignment ItemControlAreaAlignment = {read=FItemControlAreaAlignment, write=SetItemControlAreaAlignment, default=0};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, stored=IsItemIndexStored, nodefault};
	__property TdxLayoutDirection LayoutDirection = {read=FLayoutDirection, write=SetLayoutDirection, default=1};
	__property bool Locked = {read=FLocked, write=SetLocked, default=0};
	__property bool LookAndFeelException = {read=FLayoutLookAndFeelException, write=SetLayoutLookAndFeelException, stored=false, nodefault};
	__property bool LayoutLookAndFeelException = {read=FLayoutLookAndFeelException, write=SetLayoutLookAndFeelException, default=0};
	__property Padding;
	__property bool ShowBorder = {read=GetShowBorder, write=SetShowBorder, default=1};
	__property TdxLayoutTabbedOptions* TabbedOptions = {read=FTabbedOptions, write=SetTabbedOptions};
	__property bool UseIndent = {read=FUseIndent, write=SetUseIndent, default=1};
	__property OnCaptionClick;
	__property System::Classes::TNotifyEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property TdxLayoutGroupExpandingEvent OnCollapsing = {read=FOnCollapsing, write=FOnCollapsing};
	__property System::Classes::TNotifyEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property TdxLayoutGroupExpandingEvent OnExpanding = {read=FOnExpanding, write=FOnExpanding};
	__property System::Classes::TNotifyEvent OnTabChanged = {read=FOnTabChanged, write=FOnTabChanged};
	__property TdxLayoutGroupTabChangingEvent OnTabChanging = {read=FOnTabChanging, write=FOnTabChanging};
private:
	void *__IcxControlComponentState;	/* Cxcontrols::IcxControlComponentState */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E29BF582-E8C0-4868-A799-DB4C41AC3BC8}
	operator Cxcontrols::_di_IcxControlComponentState()
	{
		Cxcontrols::_di_IcxControlComponentState intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxControlComponentState; }
	#endif
	
};


enum TdxLayoutAlignmentConstraintKind : unsigned char { ackLeft, ackTop, ackRight, ackBottom };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutAlignmentConstraint : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TdxLayoutContainer* FContainer;
	System::Classes::TList* FItems;
	TdxLayoutAlignmentConstraintKind FKind;
	int __fastcall GetCount(void);
	TdxCustomLayoutItem* __fastcall GetItem(int Index);
	void __fastcall SetKind(TdxLayoutAlignmentConstraintKind Value);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	void __fastcall InternalAddItem(TdxCustomLayoutItem* AItem);
	void __fastcall InternalRemoveItem(TdxCustomLayoutItem* AItem);
	bool __fastcall AreItemViewInfosAligned(int ACount);
	void __fastcall AlignItemViewInfos(int ACount);
	void __fastcall ChangeOffset(int AIndex, int ADelta);
	void __fastcall ResetOffsets(void);
	
protected:
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	void __fastcall BeginUpdate(void);
	virtual bool __fastcall CanAddItem(TdxCustomLayoutItem* AItem);
	virtual void __fastcall Changed(void);
	void __fastcall EndUpdate(void);
	int __fastcall GetBorderValue(int AIndex);
	int __fastcall GetMostBorderValue(int ACount = 0x0);
	Dxlayoutcommon::TdxLayoutSide __fastcall GetOffsetSide(void);
	__property TdxLayoutContainer* Container = {read=FContainer};
	
public:
	__fastcall virtual TdxLayoutAlignmentConstraint(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutAlignmentConstraint(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall AddItem(TdxCustomLayoutItem* AItem);
	void __fastcall RemoveItem(TdxCustomLayoutItem* AItem);
	__property int Count = {read=GetCount, nodefault};
	__property TdxCustomLayoutItem* Items[int Index] = {read=GetItem};
	
__published:
	__property TdxLayoutAlignmentConstraintKind Kind = {read=FKind, write=SetKind, default=0};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutAlignmentConstraintClass;

class DELPHICLASS TdxLayoutContainerPersistent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutContainerPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxLayoutContainer* FContainer;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TdxLayoutContainerPersistent(TdxLayoutContainer* AContainer);
	__property TdxLayoutContainer* Container = {read=FContainer};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutContainerPersistent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutContainerFocusController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutContainerFocusController : public TdxLayoutContainerPersistent
{
	typedef TdxLayoutContainerPersistent inherited;
	
private:
	int FCurrentTabOrderIndex;
	void __fastcall SetCurrentTabOrderIndex(int Value);
	
protected:
	TdxCustomLayoutItem* __fastcall GetFocusedItem(void);
	int __fastcall GetMaxTabOrderIndex(void);
	Vcl::Controls::TWinControl* __fastcall FindNextFocusControl(Vcl::Controls::TWinControl* ACurrentControl, bool AGoForward, /* out */ int &AIndex);
	virtual bool __fastcall IsFocused(TdxCustomLayoutItem* AItem);
	int __fastcall LayoutIndexOf(System::Classes::TList* AList, int ACurrentIndex);
	void __fastcall SetFocus(void);
	void __fastcall KillFocus(void);
	void __fastcall SetItemFocus(TdxCustomLayoutItem* AItem);
	__property int CurrentTabOrderIndex = {read=FCurrentTabOrderIndex, write=SetCurrentTabOrderIndex, nodefault};
	
public:
	__fastcall virtual TdxLayoutContainerFocusController(TdxLayoutContainer* AContainer);
	bool __fastcall SetNextFocusControl(Vcl::Controls::TWinControl* AFocusedControl);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutContainerFocusController(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutContainerFocusControllerClass;

class DELPHICLASS TdxLayoutImageOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutImageOptions : public TdxLayoutContainerPersistent
{
	typedef TdxLayoutContainerPersistent inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FDisabledImages;
	Vcl::Imglist::TChangeLink* FDisabledImagesChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	Dxcoreclasses::TcxFreeNotificator* FNotifyComponent;
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	void __fastcall ImagesChange(System::TObject* Sender);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetDisabledImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetImageList(Vcl::Imglist::TCustomImageList* &ANewValue, Vcl::Imglist::TCustomImageList* &AOldValue, Vcl::Imglist::TChangeLink* const AChangeLink);
	
protected:
	void __fastcall Changed(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	
public:
	__fastcall virtual TdxLayoutImageOptions(TdxLayoutContainer* AContainer);
	__fastcall virtual ~TdxLayoutImageOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Imglist::TCustomImageList* DisabledImages = {read=FDisabledImages, write=SetDisabledImages};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
};

#pragma pack(pop)

enum TdxLayoutContainerAssignLayoutMode : unsigned char { almNone, almToParent, almFromParent };

class DELPHICLASS TdxLayoutContainerPainter;
class DELPHICLASS TdxLayoutContainerViewInfo;
class PASCALIMPLEMENTATION TdxLayoutContainer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Contnrs::TComponentList* FAlignmentConstraints;
	TdxLayoutContainerAssignLayoutMode FAssignLayoutMode;
	TdxLayoutContainerFocusController* FFocusController;
	TdxLayoutImageOptions* FImageOptions;
	bool FIsPlaceControlsNeeded;
	bool FIsPlacingControls;
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* FLayoutLookAndFeel;
	TdxLayoutCustomizeFormMenuItems FMenuItems;
	TdxLayoutContainerPainter* FPainter;
	TdxLayoutContainer* FPattern;
	int FPlaceControlsLockCount;
	Dxlayoutselection::_di_IdxLayoutDesignerHelper FSelectionHelper;
	int FUpdateLockCount;
	TdxLayoutContainerViewInfo* FViewInfo;
	Cxclasses::TcxComponentList* FAbsoluteItems;
	Cxclasses::TcxComponentList* FAvailableItems;
	TdxLayoutGroup* FRoot;
	Cxclasses::TcxComponentList* FSpecialItems;
	bool FDeleteUnloadedItems;
	bool FIsRestoring;
	int FStoredVersion;
	System::UnicodeString FStoringName;
	TdxUndoRedoManager* FUndoRedoManager;
	bool FCustomization;
	TdxLayoutAvailableItemsViewKind FCustomizeAvailableItemsViewKind;
	TdxLayoutControlCustomCustomizeForm* FCustomizeForm;
	System::Types::TRect FCustomizeFormBounds;
	TdxLayoutControlCustomCustomizeFormClass FCustomizeFormClass;
	bool FCustomizeFormTabbedView;
	TdxLayoutCustomizeFormUpdateTypes FCustomizeFormUpdateTypes;
	TdxCustomLayoutItem* FRenamingItem;
	bool FHighlightRoot;
	bool FShowDesignSelectors;
	System::Classes::TNotifyEvent FOnChanged;
	TdxLayoutItemChangedEvent FOnItemChanged;
	System::Classes::TNotifyEvent FOnSelectionChanged;
	void __fastcall AbsoluteItemListChanged(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall AvailableItemListChanged(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall DeleteSuperfluousItems(void);
	TdxLayoutAlignmentConstraint* __fastcall GetAlignmentConstraint(int Index);
	int __fastcall GetAlignmentConstraintCount(void);
	bool __fastcall GetIsDesignSelectorsVisible(void);
	bool __fastcall GetIsStoringNameMode(void);
	TdxCustomLayoutItem* __fastcall GetAbsoluteItem(int Index);
	int __fastcall GetAbsoluteItemCount(void);
	TdxCustomLayoutItem* __fastcall GetAvailableItem(int Index);
	int __fastcall GetAvailableItemCount(void);
	void __fastcall SetCustomization(bool AValue);
	void __fastcall SetCustomizeAvailableItemsViewKind(TdxLayoutAvailableItemsViewKind Value);
	void __fastcall SetCustomizeFormTabbedView(bool AValue);
	void __fastcall SetHighlightRoot(bool AValue);
	void __fastcall SetImageOptions(TdxLayoutImageOptions* AValue);
	void __fastcall SetIsRestoring(bool AValue);
	void __fastcall SetLayoutLookAndFeel(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* Value);
	void __fastcall SetRenamingItem(TdxCustomLayoutItem* AValue);
	void __fastcall SetShowDesignSelectors(bool Value);
	
protected:
	void __stdcall BeginLayoutLookAndFeelUserDestroying(void);
	void __stdcall EndLayoutLookAndFeelUserDestroying(void);
	virtual void __stdcall LayoutLookAndFeelUserChanged(void);
	void __stdcall LayoutLookAndFeelUserDestroyed(void);
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	void __fastcall AddAvailableItem(TdxCustomLayoutItem* AItem);
	void __fastcall AddSpecialGroup(TdxLayoutGroup* AGroup);
	TdxLayoutGroup* __fastcall GetNewHiddenGroup(void);
	void __fastcall CheckDestroySuperfluousGroup(TdxLayoutGroup* AGroup);
	void __fastcall CreateRootGroup(void);
	void __fastcall DestroyRootGroup(void);
	void __fastcall ExtractAvailableItem(TdxCustomLayoutItem* AItem);
	TdxLayoutGroup* __fastcall GetRoot(void);
	virtual void __fastcall SetItemViewInfo(TdxCustomLayoutItem* AItem, TdxCustomLayoutItemViewInfo* AViewInfo);
	void __fastcall SetRootGroup(TdxLayoutGroup* Value);
	void __fastcall SelectionChanged(System::Classes::TList* ASelection, Dxlayoutselection::TdxSelectionAction AAction);
	void __fastcall AddSelectionChangedListener(System::Classes::TPersistent* AListener);
	bool __fastcall IsActive(void);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	bool __fastcall CanModify(void);
	virtual bool __fastcall CanProcessKeyboard(void);
	void __fastcall ClearSelection(void);
	void __fastcall DeleteSelection(void);
	void __fastcall GetSelection(System::Classes::TList* AList);
	bool __fastcall IsComponentSelected(System::Classes::TPersistent* AComponent);
	void __fastcall RemoveSelectionChangedListener(System::Classes::TPersistent* AListener);
	void __fastcall SelectComponent(System::Classes::TPersistent* AComponent, System::Classes::TShiftState AShift = System::Classes::TShiftState() );
	void __fastcall SetSelection(System::Classes::TList* AList);
	System::UnicodeString __fastcall UniqueName(const System::UnicodeString BaseName);
	TdxLayoutContainer* __fastcall GetContainer(void);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall GetItemStoredCustomProperties(TdxCustomLayoutItem* AItem, System::Classes::TStrings* AProperties);
	virtual void __fastcall GetItemStoredCustomPropertyValue(TdxCustomLayoutItem* AItem, const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetItemStoredCustomPropertyValue(TdxCustomLayoutItem* AItem, const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall RestoreFrom(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, Cxstorage::TcxCustomReaderClass AReaderClass, const System::UnicodeString ARestoreName);
	void __fastcall StoreTo(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, Cxstorage::TcxCustomWriterClass AWriterClass, bool AReCreate, const System::UnicodeString ASaveName);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall ToggleHotTrackState(TdxCustomLayoutItem* AItem);
	bool __fastcall ShowHint(Vcl::Controls::THintInfo &AHintInfo, int X, int Y);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall IsChildKey(System::Word ACharCode);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual System::Types::TRect __fastcall CalculateCustomizeFormBounds(const System::Types::TRect &AFormBounds);
	virtual void __fastcall CreateCustomizeForm(void);
	virtual TdxLayoutControlCustomCustomizeForm* __fastcall GetCustomizeForm(void);
	virtual void __fastcall DestroyCustomizeForm(void);
	virtual void __fastcall ShowCustomizeForm(void);
	virtual TdxLayoutAlignmentConstraintClass __fastcall GetAlignmentConstraintClass(void);
	virtual TdxLayoutGroupClass __fastcall GetDefaultGroupClass(void);
	virtual TdxLayoutItemClass __fastcall GetDefaultItemClass(void);
	virtual TdxLayoutGroupClass __fastcall GetDefaultRootGroupClass(void);
	virtual TdxLayoutContainerFocusControllerClass __fastcall GetFocusControllerClass(void);
	virtual TdxLayoutContainerPainterClass __fastcall GetPainterClass(void);
	virtual Dxlayoutselection::TdxLayoutRunTimeSelectionHelperClass __fastcall GetSelectionHelperClass(void);
	virtual TdxLayoutContainerViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall CreateHandlers(void);
	virtual void __fastcall DestroyHandlers(void);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	virtual bool __fastcall CanGetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall CanUpdate(void);
	virtual void __fastcall DoCalculateRoot(bool ANeedPack);
	virtual void __fastcall DoChanged(void);
	virtual void __fastcall DoSelectionChanged(void);
	virtual void __fastcall InitializeSubControlsCxLookAndFeel(void);
	void __fastcall InvalidateWithChildren(void);
	virtual void __fastcall LayoutChanged(bool ANeedPack = true);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetDisabledImages(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	void __fastcall BuildSelectionLayer(void);
	virtual void __fastcall CustomizationChanged(void);
	virtual void __fastcall CustomizeFormPostUpdate(TdxLayoutCustomizeFormUpdateTypes AUpdateTypes);
	void __fastcall CustomizeFormUpdateList(TdxCustomLayoutItem* AItem);
	virtual TdxLayoutCustomizeFormMenuItems __fastcall DoGetCustomizationMenuItems(System::Classes::TList* const ASelectedItems);
	void __fastcall InvalidateSelectionLayer(const System::Types::TRect &R);
	virtual bool __fastcall IsCustomization(void);
	virtual void __fastcall PostBuildSelectionLayer(void);
	virtual void __fastcall PostInvalidateSelectionLayer(const System::Types::TRect &R);
	void __fastcall SelectItemParent(void);
	virtual void __fastcall BeginRename(TdxCustomLayoutItem* AItem, const System::Types::TRect &ABounds, Vcl::Graphics::TFont* const AFont);
	virtual void __fastcall CancelRename(void);
	virtual void __fastcall EndRename(const System::UnicodeString AText);
	void __fastcall UpdateItemsCustomization(void);
	void __fastcall BeginPlaceControls(void);
	void __fastcall CancelPlaceControls(void);
	void __fastcall EndPlaceControls(void);
	bool __fastcall IsPlacingControls(void);
	void __fastcall PlaceControls(TdxCustomLayoutItemViewInfo* AItemViewInfo = (TdxCustomLayoutItemViewInfo*)(0x0));
	virtual void __fastcall PostPlaceControls(void);
	void __fastcall PrepareControl(Vcl::Controls::TControl* AControl);
	void __fastcall UnprepareControl(Vcl::Controls::TControl* AControl);
	void __fastcall BeginPlacingControls(void);
	void __fastcall EndPlacingControls(void);
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall BeforeRestoring(void);
	void __fastcall CheckIndexes(void);
	System::UnicodeString __fastcall GetRootSectionName(System::Inifiles::TCustomIniFile* AIniFile);
	virtual bool __fastcall LoadPreviousVersions(System::Inifiles::TCustomIniFile* AIniFile);
	void __fastcall StoreChildren(System::Classes::TGetChildProc Proc);
	virtual bool __fastcall CanRestore(void);
	virtual bool __fastcall StoringSupports(void);
	virtual void __fastcall Restore(void);
	virtual void __fastcall Store(void);
	void __fastcall AddAlignmentConstraint(TdxLayoutAlignmentConstraint* AConstraint);
	void __fastcall CreateConstraints(void);
	void __fastcall DestroyConstraints(void);
	void __fastcall RemoveAlignmentConstraint(TdxLayoutAlignmentConstraint* AConstraint);
	void __fastcall AddAbsoluteItem(TdxCustomLayoutItem* AItem);
	virtual bool __fastcall CanSetItemName(TdxCustomLayoutItem* AItem);
	virtual void __fastcall DoItemChanged(TdxCustomLayoutItem* AItem);
	void __fastcall ExtractAbsoluteItem(TdxCustomLayoutItem* AItem);
	bool __fastcall IsRoot(TdxCustomLayoutItem* AItem);
	virtual bool __fastcall IsSizableHorz(void);
	virtual bool __fastcall IsSizableVert(void);
	virtual void __fastcall DoInitialize(void);
	virtual bool __fastcall IsAutoControlAlignment(void);
	virtual bool __fastcall IsAutoControlTabOrders(void);
	virtual bool __fastcall IsFocusControlOnItemCaptionClick(void);
	void __fastcall Initialize(void);
	void __fastcall SetFocus(void);
	int __fastcall GetMaxTabOrderIndex(void);
	void __fastcall KillFocus(void);
	TdxLayoutItem* __fastcall FindFocusedItem(void);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall ProcessDialogKey(System::Word ACharCode, int AKeyData);
	virtual Dxlayoutselection::TdxControlsDesignSelectorHelper* __fastcall CreateCustomizationControlHelper(TdxLayoutItem* AItem);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual System::Classes::TComponent* __fastcall GetItemsOwner(void);
	virtual Cxcontrols::TcxControl* __fastcall GetItemsParent(void);
	virtual System::Classes::TComponent* __fastcall GetItemsParentComponent(void);
	virtual System::Types::TPoint __fastcall GetScrollOffset(void);
	virtual bool __fastcall HasBackground(void);
	virtual void __fastcall SizeAdjustment(void);
	virtual void __fastcall DoEnter(void);
	virtual void __fastcall DoExit(void);
	bool __fastcall IsEditorMode(void);
	virtual bool __fastcall IsShowLockedGroupChildren(void);
	bool __fastcall IsViewInfoValid(void);
	virtual void __fastcall MakeVisible(TdxCustomLayoutItem* AItem);
	virtual void __fastcall AssignStructureFromPattern(void);
	virtual void __fastcall AssignStructureToPattern(void);
	void __fastcall CopyStructure(TdxLayoutContainer* ASource);
	virtual Vcl::Graphics::TFont* __fastcall GetBoldFont(void);
	virtual Vcl::Graphics::TFont* __fastcall GetDefaultFont(void) = 0 ;
	__property TdxLayoutContainerFocusController* FocusController = {read=FFocusController};
	__property bool IsDesignSelectorsVisible = {read=GetIsDesignSelectorsVisible, nodefault};
	__property bool IsRestoring = {read=FIsRestoring, write=SetIsRestoring, nodefault};
	__property bool IsStoringNameMode = {read=GetIsStoringNameMode, nodefault};
	__property TdxLayoutCustomizeFormMenuItems MenuItems = {read=FMenuItems, write=FMenuItems, nodefault};
	__property TdxLayoutContainerPainter* Painter = {read=FPainter};
	__property TdxLayoutContainer* Pattern = {read=FPattern};
	__property TdxCustomLayoutItem* RenamingItem = {read=FRenamingItem, write=SetRenamingItem};
	__property Dxlayoutselection::_di_IdxLayoutDesignerHelper SelectionHelper = {read=FSelectionHelper};
	__property int StoredVersion = {read=FStoredVersion, nodefault};
	__property TdxLayoutItemChangedEvent OnItemChanged = {read=FOnItemChanged, write=FOnItemChanged};
	
public:
	__fastcall virtual TdxLayoutContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutContainer(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(bool ANeedPack = true);
	TdxCustomLayoutHitTest* __fastcall GetHitTest(void)/* overload */;
	TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P)/* overload */;
	TdxCustomLayoutHitTest* __fastcall GetHitTest(int X, int Y)/* overload */;
	virtual void __fastcall BeginDragAndDrop(void);
	virtual bool __fastcall CanDragAndDrop(void);
	virtual void __fastcall FinishDragAndDrop(bool Accepted);
	TdxLayoutItem* __fastcall FindItem(Vcl::Controls::TControl* AControl)/* overload */;
	TdxLayoutItem* __fastcall FindItem(NativeUInt AControlHandle)/* overload */;
	TdxCustomLayoutItem* __fastcall FindItem(const System::UnicodeString AName)/* overload */;
	System::Types::TPoint __fastcall ClientToScreen(const System::Types::TPoint &Point);
	System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint &Point);
	void __fastcall GetTabOrderList(System::Classes::TList* List);
	void __fastcall CancelLastUndo(void);
	void __fastcall SaveToUndo(void);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool EraseBackground);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	bool __fastcall IsUpdateLocked(void);
	virtual void __fastcall Modified(void);
	void __fastcall Update(void);
	void __fastcall Clear(void);
	TdxCustomLayoutItem* __fastcall CloneItem(TdxCustomLayoutItem* AItem, TdxLayoutGroup* AParent = (TdxLayoutGroup*)(0x0));
	TdxLayoutAlignmentConstraint* __fastcall CreateAlignmentConstraint(void);
	TdxLayoutGroup* __fastcall CreateGroup(TdxLayoutGroupClass AGroupClass = 0x0, TdxLayoutGroup* AParent = (TdxLayoutGroup*)(0x0));
	TdxCustomLayoutItem* __fastcall CreateItem(TdxCustomLayoutItemClass AItemClass = 0x0, TdxLayoutGroup* AParent = (TdxLayoutGroup*)(0x0));
	TdxLayoutItem* __fastcall CreateItemForControl(Vcl::Controls::TControl* AControl, TdxLayoutGroup* AParent = (TdxLayoutGroup*)(0x0));
	void __fastcall CustomizeFormUpdate(TdxLayoutCustomizeFormUpdateTypes AUpdateTypes);
	virtual void __fastcall CheckItemNames(const System::UnicodeString AOldName, const System::UnicodeString ANewName);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, const System::UnicodeString ARestoreName = System::UnicodeString(), bool ADeleteUnloaded = false);
	void __fastcall RestoreFromStorage(const System::UnicodeString AStorageName, Cxstorage::TcxCustomReaderClass AReaderClass, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, bool AReCreate = true, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, bool AReCreate = true, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToStream(System::Classes::TStream* AStream, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToStorage(const System::UnicodeString AStorageName, Cxstorage::TcxCustomWriterClass AWriterClass, bool AReCreate = true, const System::UnicodeString ASaveName = System::UnicodeString());
	__property bool Customization = {read=FCustomization, write=SetCustomization, nodefault};
	__property TdxLayoutAvailableItemsViewKind CustomizeAvailableItemsViewKind = {read=FCustomizeAvailableItemsViewKind, write=SetCustomizeAvailableItemsViewKind, nodefault};
	__property TdxLayoutControlCustomCustomizeForm* CustomizeForm = {read=GetCustomizeForm};
	__property System::Types::TRect CustomizeFormBounds = {read=FCustomizeFormBounds, write=FCustomizeFormBounds};
	__property TdxLayoutControlCustomCustomizeFormClass CustomizeFormClass = {read=FCustomizeFormClass, write=FCustomizeFormClass};
	__property bool CustomizeFormTabbedView = {read=FCustomizeFormTabbedView, write=SetCustomizeFormTabbedView, nodefault};
	__property bool HighlightRoot = {read=FHighlightRoot, write=SetHighlightRoot, nodefault};
	__property TdxLayoutImageOptions* ImageOptions = {read=FImageOptions, write=SetImageOptions};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=FLayoutLookAndFeel, write=SetLayoutLookAndFeel};
	__property bool ShowDesignSelectors = {read=FShowDesignSelectors, write=SetShowDesignSelectors, nodefault};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property Cxcontrols::TcxControl* ItemsParent = {read=GetItemsParent};
	__property TdxUndoRedoManager* UndoRedoManager = {read=FUndoRedoManager};
	__property TdxLayoutContainerViewInfo* ViewInfo = {read=FViewInfo};
	__property int AlignmentConstraintCount = {read=GetAlignmentConstraintCount, nodefault};
	__property TdxLayoutAlignmentConstraint* AlignmentConstraints[int Index] = {read=GetAlignmentConstraint};
	__property int AbsoluteItemCount = {read=GetAbsoluteItemCount, nodefault};
	__property TdxCustomLayoutItem* AbsoluteItems[int Index] = {read=GetAbsoluteItem};
	__property TdxLayoutContainerAssignLayoutMode AssignLayoutMode = {read=FAssignLayoutMode, nodefault};
	__property int AvailableItemCount = {read=GetAvailableItemCount, nodefault};
	__property TdxCustomLayoutItem* AvailableItems[int Index] = {read=GetAvailableItem};
	__property TdxLayoutGroup* Root = {read=FRoot};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property System::Classes::TNotifyEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
private:
	void *__IdxSelectionChanged;	/* Dxlayoutselection::IdxSelectionChanged */
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IdxLayoutLookAndFeelUser;	/* Dxlayoutlookandfeels::IdxLayoutLookAndFeelUser */
	void *__IdxLayoutDesignerHelper;	/* Dxlayoutselection::IdxLayoutDesignerHelper */
	void *__IdxLayoutContainer;	/* IdxLayoutContainer */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {ECB1A3AE-1C91-4E5F-8ADC-34120676B1CA}
	operator Dxlayoutselection::_di_IdxSelectionChanged()
	{
		Dxlayoutselection::_di_IdxSelectionChanged intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutselection::IdxSelectionChanged*(void) { return (Dxlayoutselection::IdxSelectionChanged*)&__IdxSelectionChanged; }
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
	// {651F19FE-CBCB-4C16-8615-BBD57ED7255A}
	operator Dxlayoutlookandfeels::_di_IdxLayoutLookAndFeelUser()
	{
		Dxlayoutlookandfeels::_di_IdxLayoutLookAndFeelUser intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutlookandfeels::IdxLayoutLookAndFeelUser*(void) { return (Dxlayoutlookandfeels::IdxLayoutLookAndFeelUser*)&__IdxLayoutLookAndFeelUser; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0FF95B61-5074-49E4-99C6-1A8BB34F1547}
	operator Dxlayoutselection::_di_IdxLayoutDesignerHelper()
	{
		Dxlayoutselection::_di_IdxLayoutDesignerHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutselection::IdxLayoutDesignerHelper*(void) { return (Dxlayoutselection::IdxLayoutDesignerHelper*)&__IdxLayoutDesignerHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {85310BD8-3D7A-454F-A54B-9898C0AA55A2}
	operator _di_IdxLayoutContainer()
	{
		_di_IdxLayoutContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxLayoutContainer*(void) { return (IdxLayoutContainer*)&__IdxLayoutContainer; }
	#endif
	
};


typedef System::TMetaClass* TdxLayoutContainerClass;

typedef System::TMetaClass* TdxCustomLayoutHitTestClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomLayoutItem* FItem;
	TdxCustomLayoutItemViewInfo* FViewInfo;
	System::Types::TPoint FPos;
	
public:
	virtual bool __fastcall CanDragAndDrop(void);
	DYNAMIC System::Uitypes::TCursor __fastcall GetCursor(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual int __fastcall HitTestCode(void);
	__classmethod TdxCustomLayoutHitTest* __fastcall Instance();
	virtual bool __fastcall IsDeterminedAreaPart(void);
	virtual TdxLayoutAreaPart __fastcall GetAreaPart(void);
	virtual TdxLayoutGroup* __fastcall GetGroupForInsert(void);
	virtual TdxCustomLayoutItem* __fastcall GetDestinationItem(void);
	virtual TdxCustomLayoutItem* __fastcall GetSourceItem(void);
	__property TdxCustomLayoutItem* Item = {read=FItem, write=FItem};
	__property TdxCustomLayoutItemViewInfo* ViewInfo = {read=FViewInfo, write=FViewInfo};
	__property System::Types::TPoint Pos = {read=FPos, write=FPos};
public:
	/* TObject.Create */ inline __fastcall TdxCustomLayoutHitTest(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomLayoutItemHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemHitTest : public TdxCustomLayoutHitTest
{
	typedef TdxCustomLayoutHitTest inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxCustomLayoutItemHitTest(void) : TdxCustomLayoutHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutNoneHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutNoneHitTest : public TdxCustomLayoutHitTest
{
	typedef TdxCustomLayoutHitTest inherited;
	
public:
	virtual int __fastcall HitTestCode(void);
public:
	/* TObject.Create */ inline __fastcall TdxLayoutNoneHitTest(void) : TdxCustomLayoutHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutNoneHitTest(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomLayoutItemHitTestClass;

class DELPHICLASS TdxLayoutBasicItemHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutBasicItemHitTest : public TdxCustomLayoutItemHitTest
{
	typedef TdxCustomLayoutItemHitTest inherited;
	
private:
	TdxLayoutBasicItem* __fastcall GetItem(void);
	
public:
	virtual int __fastcall HitTestCode(void);
	virtual TdxLayoutGroup* __fastcall GetGroupForInsert(void);
	__property TdxLayoutBasicItem* Item = {read=GetItem};
public:
	/* TObject.Create */ inline __fastcall TdxLayoutBasicItemHitTest(void) : TdxCustomLayoutItemHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutBasicItemHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemHitTest : public TdxLayoutBasicItemHitTest
{
	typedef TdxLayoutBasicItemHitTest inherited;
	
private:
	HIDESBASE TdxLayoutItem* __fastcall GetItem(void);
	
public:
	virtual int __fastcall HitTestCode(void);
	__property TdxLayoutItem* Item = {read=GetItem};
public:
	/* TObject.Create */ inline __fastcall TdxLayoutItemHitTest(void) : TdxLayoutBasicItemHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupHitTest : public TdxCustomLayoutItemHitTest
{
	typedef TdxCustomLayoutItemHitTest inherited;
	
private:
	TdxLayoutGroup* __fastcall GetItem(void);
	TdxLayoutGroupViewInfo* __fastcall GetViewInfo(void);
	
public:
	virtual int __fastcall HitTestCode(void);
	virtual TdxLayoutGroup* __fastcall GetGroupForInsert(void);
	__property TdxLayoutGroup* Item = {read=GetItem};
	__property TdxLayoutGroupViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TObject.Create */ inline __fastcall TdxLayoutGroupHitTest(void) : TdxCustomLayoutItemHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutTabbedGroupHitTest;
class DELPHICLASS TdxLayoutGroupViewInfoTabbedSpecific;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutTabbedGroupHitTest : public TdxLayoutGroupHitTest
{
	typedef TdxLayoutGroupHitTest inherited;
	
private:
	TdxLayoutGroupViewInfoTabbedSpecific* __fastcall GetSpecific(void);
	
protected:
	__property TdxLayoutGroupViewInfoTabbedSpecific* Specific = {read=GetSpecific};
	
public:
	virtual TdxCustomLayoutItem* __fastcall GetDestinationItem(void);
	virtual TdxCustomLayoutItem* __fastcall GetSourceItem(void);
public:
	/* TObject.Create */ inline __fastcall TdxLayoutTabbedGroupHitTest(void) : TdxLayoutGroupHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutTabbedGroupHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutClientAreaHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutClientAreaHitTest : public TdxCustomLayoutHitTest
{
	typedef TdxCustomLayoutHitTest inherited;
	
private:
	TdxLayoutContainer* FContainer;
	
public:
	virtual int __fastcall HitTestCode(void);
	virtual TdxLayoutGroup* __fastcall GetGroupForInsert(void);
	virtual TdxCustomLayoutItem* __fastcall GetDestinationItem(void);
	__property TdxLayoutContainer* Container = {read=FContainer, write=FContainer};
public:
	/* TObject.Create */ inline __fastcall TdxLayoutClientAreaHitTest(void) : TdxCustomLayoutHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutClientAreaHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutSizeHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSizeHitTest : public TdxCustomLayoutItemHitTest
{
	typedef TdxCustomLayoutItemHitTest inherited;
	
private:
	System::Uitypes::TCursor FCursor;
	
protected:
	__property System::Uitypes::TCursor Cursor = {read=FCursor, write=FCursor, nodefault};
	
public:
	virtual int __fastcall HitTestCode(void);
	DYNAMIC System::Uitypes::TCursor __fastcall GetCursor(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
public:
	/* TObject.Create */ inline __fastcall TdxLayoutSizeHitTest(void) : TdxCustomLayoutItemHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutSizeHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutSplitterHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSplitterHitTest : public TdxCustomLayoutItemHitTest
{
	typedef TdxCustomLayoutItemHitTest inherited;
	
public:
	virtual bool __fastcall CanDragAndDrop(void);
	virtual int __fastcall HitTestCode(void);
	DYNAMIC System::Uitypes::TCursor __fastcall GetCursor(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
public:
	/* TObject.Create */ inline __fastcall TdxLayoutSplitterHitTest(void) : TdxCustomLayoutItemHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutSplitterHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCustomizeFormHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCustomizeFormHitTest : public TdxCustomLayoutHitTest
{
	typedef TdxCustomLayoutHitTest inherited;
	
private:
	TdxLayoutAreaPart FAreaPart;
	TdxLayoutContainer* FContainer;
	
public:
	virtual int __fastcall HitTestCode(void);
	virtual bool __fastcall IsDeterminedAreaPart(void);
	virtual TdxLayoutAreaPart __fastcall GetAreaPart(void);
	virtual TdxCustomLayoutItem* __fastcall GetDestinationItem(void);
	__property TdxLayoutAreaPart AreaPart = {read=FAreaPart, write=FAreaPart, nodefault};
	__property TdxLayoutContainer* Container = {read=FContainer, write=FContainer};
public:
	/* TObject.Create */ inline __fastcall TdxLayoutCustomizeFormHitTest(void) : TdxCustomLayoutHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutCustomizeFormHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCustomizeFormAvailableItemsHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCustomizeFormAvailableItemsHitTest : public TdxLayoutCustomizeFormHitTest
{
	typedef TdxLayoutCustomizeFormHitTest inherited;
	
public:
	virtual int __fastcall HitTestCode(void);
public:
	/* TObject.Create */ inline __fastcall TdxLayoutCustomizeFormAvailableItemsHitTest(void) : TdxLayoutCustomizeFormHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutCustomizeFormAvailableItemsHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutCustomizeFormTreeViewItemsHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutCustomizeFormTreeViewItemsHitTest : public TdxLayoutCustomizeFormHitTest
{
	typedef TdxLayoutCustomizeFormHitTest inherited;
	
public:
	virtual int __fastcall HitTestCode(void);
public:
	/* TObject.Create */ inline __fastcall TdxLayoutCustomizeFormTreeViewItemsHitTest(void) : TdxLayoutCustomizeFormHitTest() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutCustomizeFormTreeViewItemsHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomLayoutElementPainter;
class DELPHICLASS TdxCustomLayoutElementViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutElementPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TdxCustomLayoutElementViewInfo* FViewInfo;
	
protected:
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TdxCustomLayoutElementViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxCustomLayoutElementPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo);
	virtual void __fastcall Paint(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutElementPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomLayoutItemElementPainter;
class DELPHICLASS TdxCustomLayoutItemElementViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemElementPainter : public TdxCustomLayoutElementPainter
{
	typedef TdxCustomLayoutElementPainter inherited;
	
private:
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	TdxCustomLayoutItemElementViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	__property TdxCustomLayoutItemElementViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxCustomLayoutItemElementPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutElementPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemElementPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomLayoutItemCaptionPainter;
class DELPHICLASS TdxCustomLayoutItemCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemCaptionPainter : public TdxCustomLayoutItemElementPainter
{
	typedef TdxCustomLayoutItemElementPainter inherited;
	
private:
	HIDESBASE TdxCustomLayoutItemCaptionViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall DrawEnabled(void);
	System::Types::TRect __fastcall GetTextRect(void);
	virtual void __fastcall DoDrawText(void);
	virtual void __fastcall DoDrawGlyph(void);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall DrawBackground(void);
	void __fastcall DrawGlyph(void);
	void __fastcall DrawText(void);
	__property TdxCustomLayoutItemCaptionViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Paint(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxCustomLayoutItemCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemElementPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemCaptionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupCaptionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionPainter : public TdxCustomLayoutItemCaptionPainter
{
	typedef TdxCustomLayoutItemCaptionPainter inherited;
	
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemCaptionPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlItemCaptionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlItemCaptionPainter : public TdxCustomLayoutItemCaptionPainter
{
	typedef TdxCustomLayoutItemCaptionPainter inherited;
	
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutControlItemCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemCaptionPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutControlItemCaptionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemCaptionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemCaptionPainter : public TdxLayoutControlItemCaptionPainter
{
	typedef TdxLayoutControlItemCaptionPainter inherited;
	
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutItemCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutControlItemCaptionPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemCaptionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomLayoutItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemPainter : public TdxCustomLayoutElementPainter
{
	typedef TdxCustomLayoutElementPainter inherited;
	
private:
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	TdxCustomLayoutItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void) = 0 ;
	virtual void __fastcall DoDrawBackground(void);
	virtual void __fastcall DoDrawCaption(void);
	virtual void __fastcall DoDrawSpecificPart(void);
	virtual void __fastcall DoDrawSelectionFrame(void);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawCaption(void);
	virtual void __fastcall DrawContent(void);
	void __fastcall DrawItem(void);
	virtual void __fastcall DrawSpecificPart(void);
	virtual void __fastcall DrawDesignFeatures(void);
	virtual bool __fastcall CanDrawBackground(void);
	virtual bool __fastcall CanDrawCaption(void);
	virtual bool __fastcall CanDrawSpecificPart(void);
	virtual bool __fastcall CanPaint(void);
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	__property TdxCustomLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Paint(void);
	void __fastcall PaintDragImage(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxCustomLayoutItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutElementPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlItemControlPainter;
class DELPHICLASS TdxLayoutControlItemControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlItemControlPainter : public TdxCustomLayoutItemElementPainter
{
	typedef TdxCustomLayoutItemElementPainter inherited;
	
private:
	HIDESBASE TdxLayoutControlItemControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBorders(void);
	__property TdxLayoutControlItemControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Paint(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutControlItemControlPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemElementPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutControlItemControlPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemControlPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemControlPainter : public TdxLayoutControlItemControlPainter
{
	typedef TdxLayoutControlItemControlPainter inherited;
	
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutItemControlPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutControlItemControlPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemControlPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutBasicItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutBasicItemPainter : public TdxCustomLayoutItemPainter
{
	typedef TdxCustomLayoutItemPainter inherited;
	
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutBasicItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutBasicItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutEmptySpaceItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutEmptySpaceItemPainter : public TdxLayoutBasicItemPainter
{
	typedef TdxLayoutBasicItemPainter inherited;
	
protected:
	virtual void __fastcall DrawContent(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutEmptySpaceItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutBasicItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutEmptySpaceItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutDirectionalItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutDirectionalItemPainter : public TdxLayoutBasicItemPainter
{
	typedef TdxLayoutBasicItemPainter inherited;
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DoDrawContent(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutDirectionalItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutBasicItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutDirectionalItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutSeparatorItemPainter;
class DELPHICLASS TdxLayoutSeparatorItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSeparatorItemPainter : public TdxLayoutDirectionalItemPainter
{
	typedef TdxLayoutDirectionalItemPainter inherited;
	
private:
	HIDESBASE TdxLayoutSeparatorItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoDrawContent(void);
	__property TdxLayoutSeparatorItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutSeparatorItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutDirectionalItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutSeparatorItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutSplitterItemPainter;
class DELPHICLASS TdxLayoutSplitterItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSplitterItemPainter : public TdxLayoutDirectionalItemPainter
{
	typedef TdxLayoutDirectionalItemPainter inherited;
	
private:
	HIDESBASE TdxLayoutSplitterItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoDrawContent(void);
	__property TdxLayoutSplitterItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutSplitterItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutDirectionalItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutSplitterItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutLabeledItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLabeledItemPainter : public TdxLayoutBasicItemPainter
{
	typedef TdxLayoutBasicItemPainter inherited;
	
protected:
	virtual bool __fastcall CanDrawCaption(void);
	virtual TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutLabeledItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutBasicItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutLabeledItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlItemPainter : public TdxLayoutLabeledItemPainter
{
	typedef TdxLayoutLabeledItemPainter inherited;
	
private:
	HIDESBASE TdxLayoutControlItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanDrawSpecificPart(void);
	virtual TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual TdxLayoutControlItemControlPainterClass __fastcall GetControlPainterClass(void);
	virtual void __fastcall DoDrawControlBorder(void);
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawControlBorder(void);
	__property TdxLayoutControlItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutControlItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutLabeledItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutControlItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemPainter : public TdxLayoutControlItemPainter
{
	typedef TdxLayoutControlItemPainter inherited;
	
private:
	HIDESBASE TdxLayoutItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual TdxLayoutControlItemControlPainterClass __fastcall GetControlPainterClass(void);
	virtual void __fastcall DoDrawSpecificPart(void);
	__property TdxLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutItemPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxLayoutControlItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutItemPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupButtonPainter;
class DELPHICLASS TdxLayoutGroupButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupButtonPainter : public TdxCustomLayoutItemElementPainter
{
	typedef TdxCustomLayoutItemElementPainter inherited;
	
private:
	HIDESBASE TdxLayoutGroupButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property TdxLayoutGroupButtonViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Paint(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupButtonPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemElementPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupPainter : public TdxCustomLayoutItemPainter
{
	typedef TdxCustomLayoutItemPainter inherited;
	
private:
	HIDESBASE TdxLayoutGroupViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual void __fastcall DrawContent(void);
	virtual bool __fastcall CanDrawBorders(void);
	virtual bool __fastcall CanDrawSpecificControls(void);
	virtual bool __fastcall HasCaptionBackground(void);
	virtual void __fastcall DoDrawBorders(void);
	virtual void __fastcall DoDrawButtons(void);
	virtual void __fastcall DoDrawSpecificControls(void);
	virtual void __fastcall DrawBorders(void);
	virtual void __fastcall DrawButtons(void);
	virtual void __fastcall DrawItems(void);
	virtual void __fastcall DrawItemsArea(void);
	void __fastcall DrawSpecificControls(void);
	virtual void __fastcall DrawSpecificPart(void);
	virtual void __fastcall DrawDesignFeatures(void);
	__property TdxLayoutGroupViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TdxLayoutGroupPainter(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutElementViewInfo* AViewInfo) : TdxCustomLayoutItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutGroupPainter(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutContainerPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxLayoutContainerViewInfo* FViewInfo;
	int FPlaceControlsCounter;
	TdxLayoutContainer* __fastcall GetContainer(void);
	
protected:
	virtual void __fastcall DrawDesignFeatures(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawItems(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PlaceControls(TdxCustomLayoutItemViewInfo* AItemViewInfo);
	__property TdxLayoutContainer* Container = {read=GetContainer};
	
public:
	__fastcall virtual TdxLayoutContainerPainter(TdxLayoutContainerViewInfo* AViewInfo);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxLayoutContainerViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutContainerPainter(void) { }
	
};

#pragma pack(pop)

enum TdxLayoutElementViewInfoState : unsigned char { levsHot, levsPressed };

typedef System::Set<TdxLayoutElementViewInfoState, TdxLayoutElementViewInfoState::levsHot, TdxLayoutElementViewInfoState::levsPressed>  TdxLayoutElementViewInfoStates;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutElementViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TPoint FOffset;
	System::Types::TRect FBounds;
	System::Types::TRect FOriginalBounds;
	System::Types::TRect FPadding;
	bool FIsPaddingCalculated;
	TdxLayoutElementViewInfoStates FState;
	System::Types::TRect __fastcall GetPadding(void);
	void __fastcall SetOffset(const System::Types::TPoint &Value);
	void __fastcall SetState(TdxLayoutElementViewInfoStates AValue);
	
protected:
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void) = 0 ;
	virtual System::Types::TRect __fastcall CalculatePadding(void);
	virtual bool __fastcall GetEnabled(void);
	virtual bool __fastcall GetIsCustomization(void);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall MouseEnter(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall AssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual bool __fastcall CanAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	virtual void __fastcall StateChanged(void);
	virtual bool __fastcall IsHotTrackable(void);
	__property bool IsCustomization = {read=GetIsCustomization, nodefault};
	__property System::Types::TRect OriginalBounds = {read=FOriginalBounds};
	__property System::Types::TPoint Offset = {read=FOffset, write=SetOffset};
	__property System::Types::TRect Padding = {read=GetPadding};
	__property TdxLayoutElementViewInfoStates State = {read=FState, write=SetState, nodefault};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
public:
	/* TObject.Create */ inline __fastcall TdxCustomLayoutElementViewInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutElementViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemElementViewInfo : public TdxCustomLayoutElementViewInfo
{
	typedef TdxCustomLayoutElementViewInfo inherited;
	
private:
	TdxCustomLayoutItemViewInfo* FItemViewInfo;
	int FHeight;
	int FWidth;
	TdxCustomLayoutItem* __fastcall GetItem(void);
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(int Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	virtual bool __fastcall GetEnabled(void);
	virtual bool __fastcall GetIsCustomization(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall Invalidate(const System::Types::TRect &ABounds);
	bool __fastcall WantsMouse(int X, int Y);
	virtual bool __fastcall ShowHint(Vcl::Controls::THintInfo &AHintInfo);
	__property TdxCustomLayoutItem* Item = {read=GetItem};
	__property TdxCustomLayoutItemViewInfo* ItemViewInfo = {read=FItemViewInfo};
	__property bool Visible = {read=GetVisible, nodefault};
	
public:
	__fastcall virtual TdxCustomLayoutItemElementViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo);
	__fastcall virtual ~TdxCustomLayoutItemElementViewInfo(void);
	virtual int __fastcall CalculateMinHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemCaptionViewInfo : public TdxCustomLayoutItemElementViewInfo
{
	typedef TdxCustomLayoutItemElementViewInfo inherited;
	
private:
	bool FHotTracked;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	void __fastcall SetHotTracked(bool Value);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall StateChanged(void);
	virtual bool __fastcall IsHotTrackable(void);
	virtual int __fastcall CalculateTextFlags(void);
	virtual void __fastcall PrepareCanvas(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetImageAreaBounds(void);
	virtual System::Types::TRect __fastcall GetImageBounds(void);
	virtual int __fastcall GetImageHeight(void);
	virtual int __fastcall GetImageWidth(void);
	void __fastcall AdjustTextAreaBounds(System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual System::Types::TRect __fastcall GetHotTrackBounds(void);
	virtual Dxlayoutlookandfeels::TdxLayoutHotTrackStyles __fastcall GetHotTrackStyles(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetTextDisabledColor(void);
	virtual System::Uitypes::TColor __fastcall GetTextHotColor(void);
	virtual System::Uitypes::TColor __fastcall GetTextNormalColor(void);
	virtual int __fastcall GetTextHeight(void);
	virtual int __fastcall GetTextWidth(void);
	virtual System::UnicodeString __fastcall GetVisibleText(void);
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual TdxAlignmentVert __fastcall GetAlignVert(void);
	virtual Dxlayoutlookandfeels::TdxLayoutLookAndFeelCaptionOptions* __fastcall GetOptions(void);
	virtual Cxgraphics::TcxRotationAngle __fastcall GetRotationAngle(void);
	virtual int __fastcall GetSpaceBetweenImageText(void);
	virtual int __fastcall GetAvailableHeight(void);
	virtual int __fastcall GetAvailableWidth(void);
	virtual int __fastcall GetAvailableTextHeight(void);
	virtual int __fastcall GetAvailableTextWidth(void);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual bool __fastcall CanDoCaptionClick(int X, int Y);
	virtual bool __fastcall IsDefaultColor(void);
	virtual bool __fastcall IsMultiLine(void);
	bool __fastcall IsNeedSpaceBetweenImageText(void);
	virtual bool __fastcall IsPointInHotTrackBounds(const System::Types::TPoint &P);
	virtual bool __fastcall IsTextUnderlined(void);
	virtual bool __fastcall IsTransparent(void);
	virtual bool __fastcall IsVerticalCaption(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Types::TRect HotTrackBounds = {read=GetHotTrackBounds};
	__property Dxlayoutlookandfeels::TdxLayoutHotTrackStyles HotTrackStyles = {read=GetHotTrackStyles, nodefault};
	__property System::Types::TRect ImageBounds = {read=GetImageBounds};
	
public:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	bool __fastcall IsImageVisible(void);
	bool __fastcall IsTextVisible(void);
	__property System::Classes::TAlignment AlignHorz = {read=GetAlignHorz, nodefault};
	__property TdxAlignmentVert AlignVert = {read=GetAlignVert, nodefault};
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property bool HotTracked = {read=FHotTracked, write=SetHotTracked, nodefault};
	__property System::Types::TRect ImageAreaBounds = {read=GetImageAreaBounds};
	__property int ImageHeight = {read=GetImageHeight, nodefault};
	__property int ImageWidth = {read=GetImageWidth, nodefault};
	__property Dxlayoutlookandfeels::TdxLayoutLookAndFeelCaptionOptions* Options = {read=GetOptions};
	__property System::UnicodeString Text = {read=GetText};
	__property System::Types::TRect TextAreaBounds = {read=GetTextAreaBounds};
	__property int TextHeight = {read=GetTextHeight, nodefault};
	__property int TextWidth = {read=GetTextWidth, nodefault};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, nodefault};
	__property System::UnicodeString VisibleText = {read=GetVisibleText};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxCustomLayoutItemCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxCustomLayoutItemElementViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxCustomLayoutItemCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomLayoutItemCaptionViewInfoClass;

class DELPHICLASS TdxCustomLayoutItemViewInfoCloneData;
class DELPHICLASS TdxLayoutCloneDataList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemViewInfoCloneData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomLayoutItem* FItem;
	Dxcoreclasses::TcxFreeNotificator* FNotifyComponent;
	TdxLayoutCloneDataList* FOwner;
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	
protected:
	void __fastcall Changed(void);
	virtual int __fastcall GetSize(void);
	bool __fastcall ReadBoolean(System::Classes::TStream* AStream);
	void __fastcall WriteBoolean(System::Classes::TStream* AStream, bool AValue);
	
public:
	__fastcall virtual TdxCustomLayoutItemViewInfoCloneData(TdxLayoutCloneDataList* AOwner, TdxCustomLayoutItem* AItem);
	__fastcall virtual ~TdxCustomLayoutItemViewInfoCloneData(void);
	virtual void __fastcall Assign(TdxCustomLayoutItemViewInfoCloneData* Source);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Load(System::Classes::TStream* AStream);
	virtual void __fastcall Save(System::Classes::TStream* AStream);
	__property TdxCustomLayoutItem* Item = {read=FItem};
	__property TdxLayoutCloneDataList* Owner = {read=FOwner};
	__property int Size = {read=GetSize, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomLayoutItemViewInfoCloneDataClass;

class PASCALIMPLEMENTATION TdxLayoutCloneDataList : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
public:
	TdxCustomLayoutItemViewInfoCloneData* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TNotifyEvent FOnChanged;
	HIDESBASE TdxCustomLayoutItemViewInfoCloneData* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxCustomLayoutItemViewInfoCloneData* Value);
	
protected:
	void __fastcall Changed(void);
	
public:
	__property TdxCustomLayoutItemViewInfoCloneData* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
public:
	/* TObjectList.Create */ inline __fastcall TdxLayoutCloneDataList(void)/* overload */ : System::Contnrs::TObjectList() { }
	/* TObjectList.Create */ inline __fastcall TdxLayoutCloneDataList(bool AOwnsObjects)/* overload */ : System::Contnrs::TObjectList(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxLayoutCloneDataList(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutItemViewInfo : public TdxCustomLayoutElementViewInfo
{
	typedef TdxCustomLayoutElementViewInfo inherited;
	
private:
	System::StaticArray<int, 4> FOffsets;
	TdxCustomLayoutItemCaptionViewInfo* FCaptionViewInfo;
	TdxCustomLayoutItemViewInfoCloneData* FCloneData;
	TdxLayoutContainerViewInfo* FContainerViewInfo;
	TdxLayoutGroupViewInfo* FParentViewInfo;
	System::Contnrs::TObjectList* FElements;
	TdxCustomLayoutItemElementViewInfo* FElementWithMouse;
	TdxCustomLayoutItem* FItem;
	Dxcoreclasses::TcxFreeNotificator* FNotifyComponent;
	int FTabOrderIndex;
	int __fastcall GetMinHeight(void);
	int __fastcall GetMinWidth(void);
	int __fastcall GetUsualHeight(void);
	int __fastcall GetUsualWidth(void);
	TdxLayoutAlignHorz __fastcall GetAlignHorz(void);
	TdxLayoutAlignVert __fastcall GetAlignVert(void);
	System::Types::TRect __fastcall GetBackgroundBounds(void);
	bool __fastcall GetCanPaint(void);
	bool __fastcall GetHasMouse(void);
	int __fastcall GetOffset(Dxlayoutcommon::TdxLayoutSide ASide);
	int __fastcall GetOffsetsHeight(void);
	int __fastcall GetOffsetsWidth(void);
	bool __fastcall GetSelected(void);
	System::Types::TRect __fastcall GetSelectionArea(void);
	System::Types::TRect __fastcall GetSelectionBorderRect(void);
	Dxcore::TRects __fastcall GetSelectableMarkers(void);
	void __fastcall SetElementWithMouse(TdxCustomLayoutItemElementViewInfo* Value);
	void __fastcall SetHasMouse(bool Value);
	void __fastcall SetItem(TdxCustomLayoutItem* Value);
	HIDESBASE void __fastcall SetOffset(Dxlayoutcommon::TdxLayoutSide ASide, int Value);
	TdxCustomLayoutItemHitTest* __fastcall CreateHitTest(TdxCustomLayoutItemHitTestClass AHitTestClass, const System::Types::TPoint &P);
	
protected:
	virtual bool __fastcall GetIsCustomization(void);
	virtual void __fastcall AutoAlignControls(void);
	virtual void __fastcall DoCreateViewInfos(void);
	void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	virtual void __fastcall ItemChanged(TdxLayoutItemChangeType AType);
	virtual void __fastcall PopulateAutoAlignControlList(System::Classes::TList* AList);
	virtual void __fastcall PopulateControlViewInfoList(System::Classes::TList* AControls, System::Classes::TList* AWinControls);
	virtual bool __fastcall CanDrawBackground(void);
	virtual bool __fastcall CanDrawSpecificBackground(void);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void) = 0 ;
	virtual TdxCustomLayoutItemViewInfoCloneDataClass __fastcall GetCloneDataClass(void);
	virtual TdxCustomLayoutItemHitTestClass __fastcall GetHitTestClass(void) = 0 ;
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void) = 0 ;
	int __fastcall CalculateMinHeight(void);
	int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall DoCalculateHeight(bool AIsMinHeight);
	virtual int __fastcall DoCalculateWidth(bool AIsMinWidth);
	virtual int __fastcall CalculateOffset(Dxlayoutcommon::TdxLayoutSide ASide);
	virtual TdxLayoutAreaPart __fastcall GetAreaPart(const System::Types::TPoint &P);
	virtual bool __fastcall GetActuallyVisible(void);
	virtual System::Uitypes::TColor __fastcall GetColor(void) = 0 ;
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	TdxCustomLayoutItemElementViewInfo* __fastcall GetElement(int AIndex);
	int __fastcall GetElementCount(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::Types::TRect __fastcall GetHitTestBounds(void);
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetOptions(void);
	int __fastcall GetMarkerIndex(Dxcore::TRects AMarkers, const System::Types::TPoint &P)/* overload */;
	int __fastcall GetMarkerIndex(const System::Types::TPoint &P)/* overload */;
	virtual int __fastcall GetSelectionBoundsOffset(void);
	void __fastcall GetSelectionMarkers(/* out */ Dxcore::TRects &ASelectable, /* out */ Dxcore::TRects &ANonSelectable);
	bool __fastcall HasBackground(void);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasBorder(void);
	virtual void __fastcall CustomizationMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	virtual bool __fastcall CanAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	virtual void __fastcall Invalidate(const System::Types::TRect &ABounds);
	virtual void __fastcall PaintSelectionLayer(Cxgraphics::TcxAlphaBitmap* ABitmap);
	bool __fastcall ShowHint(Vcl::Controls::THintInfo &AHintInfo);
	virtual int __fastcall GetMaxTabOrderIndex(void);
	virtual bool __fastcall CanInplaceRename(void);
	virtual void __fastcall DoInplaceRename(void);
	void __fastcall InplaceRename(void);
	virtual System::Types::TRect __fastcall GetInplaceRenameBounds(void);
	bool __fastcall IsAvailable(void);
	virtual bool __fastcall IsExpanded(void);
	bool __fastcall IsParentExpanded(void);
	bool __fastcall IsParentLocked(void);
	bool __fastcall IsParentSelected(void);
	virtual bool __fastcall IsDefaultColor(void) = 0 ;
	virtual bool __fastcall IsTransparent(void);
	bool __fastcall IsDragged(void);
	bool __fastcall IsDraggedWithParent(void);
	bool __fastcall IsDragImagePainting(void);
	bool __fastcall IsValid(void);
	virtual int __fastcall GetCloneDataSize(void);
	bool __fastcall IsClone(void);
	virtual void __fastcall LoadCloneData(System::Classes::TStream* AStream);
	virtual void __fastcall SaveCloneData(System::Classes::TStream* AStream);
	void __fastcall PrepareCloneData(void);
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property System::Types::TRect BackgroundBounds = {read=GetBackgroundBounds};
	__property bool CanPaint = {read=GetCanPaint, nodefault};
	__property TdxCustomLayoutItemViewInfoCloneData* CloneData = {read=FCloneData};
	__property bool HasMouse = {read=GetHasMouse, write=SetHasMouse, nodefault};
	__property int ElementCount = {read=GetElementCount, nodefault};
	__property TdxCustomLayoutItemElementViewInfo* Elements[int Index] = {read=GetElement};
	__property TdxCustomLayoutItemElementViewInfo* ElementWithMouse = {read=FElementWithMouse, write=SetElementWithMouse};
	__property TdxCustomLayoutItem* Item = {read=FItem, write=SetItem};
	__property int OffsetsHeight = {read=GetOffsetsHeight, nodefault};
	__property int OffsetsWidth = {read=GetOffsetsWidth, nodefault};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* Options = {read=GetOptions};
	__property int TabOrderIndex = {read=FTabOrderIndex, write=FTabOrderIndex, nodefault};
	
public:
	__fastcall virtual TdxCustomLayoutItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem);
	__fastcall virtual ~TdxCustomLayoutItemViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateInternalTabOrders(int &AAvailTabOrder);
	virtual void __fastcall CalculateTabOrders(int &AAvailTabOrder);
	virtual TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual TdxCustomLayoutItem* __fastcall GetItemWithMouse(const System::Types::TPoint &P);
	void __fastcall ResetOffset(Dxlayoutcommon::TdxLayoutSide ASide);
	__property TdxLayoutAlignHorz AlignHorz = {read=GetAlignHorz, nodefault};
	__property TdxLayoutAlignVert AlignVert = {read=GetAlignVert, nodefault};
	__property TdxCustomLayoutItemCaptionViewInfo* CaptionViewInfo = {read=FCaptionViewInfo};
	__property System::Uitypes::TColor Color = {read=GetColor, nodefault};
	__property TdxLayoutContainerViewInfo* ContainerViewInfo = {read=FContainerViewInfo};
	__property TdxLayoutGroupViewInfo* ParentViewInfo = {read=FParentViewInfo};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property int MinHeight = {read=GetMinHeight, nodefault};
	__property int UsualWidth = {read=GetUsualWidth, nodefault};
	__property int UsualHeight = {read=GetUsualHeight, nodefault};
	__property int Offsets[Dxlayoutcommon::TdxLayoutSide ASide] = {read=GetOffset, write=SetOffset};
	__property bool Selected = {read=GetSelected, nodefault};
	__property System::Types::TRect SelectionBorderRect = {read=GetSelectionBorderRect};
	__property System::Types::TRect SelectionArea = {read=GetSelectionArea};
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutBasicItemCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutBasicItemCaptionViewInfo : public TdxCustomLayoutItemCaptionViewInfo
{
	typedef TdxCustomLayoutItemCaptionViewInfo inherited;
	
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutBasicItemCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxCustomLayoutItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutBasicItemCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutEmptySpaceItemCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutEmptySpaceItemCaptionViewInfo : public TdxLayoutBasicItemCaptionViewInfo
{
	typedef TdxLayoutBasicItemCaptionViewInfo inherited;
	
protected:
	virtual bool __fastcall CanDoCaptionClick(int X, int Y);
	virtual void __fastcall PrepareCanvas(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall IsHotTrackable(void);
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutEmptySpaceItemCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxLayoutBasicItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutEmptySpaceItemCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutLabeledItemCaptionViewInfo;
class DELPHICLASS TdxLayoutLabeledItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLabeledItemCaptionViewInfo : public TdxLayoutBasicItemCaptionViewInfo
{
	typedef TdxLayoutBasicItemCaptionViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutCustomLabeledItem* __fastcall GetItem(void);
	TdxLayoutLabeledItemViewInfo* __fastcall GetItemViewInfo(void);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual bool __fastcall GetIsFixedWidth(void);
	virtual int __fastcall GetSpaceBetweenImageText(void);
	virtual System::Types::TRect __fastcall GetImageAreaBounds(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual int __fastcall GetTextWidth(void);
	virtual bool __fastcall IsMultiLine(void);
	__property bool IsFixedWidth = {read=GetIsFixedWidth, nodefault};
	__property TdxLayoutCustomLabeledItem* Item = {read=GetItem};
	__property TdxLayoutLabeledItemViewInfo* ItemViewInfo = {read=GetItemViewInfo};
	
public:
	virtual int __fastcall CalculateMinWidth(void);
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutLabeledItemCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxLayoutBasicItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutLabeledItemCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlItemCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlItemCaptionViewInfo : public TdxLayoutLabeledItemCaptionViewInfo
{
	typedef TdxLayoutLabeledItemCaptionViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutControlItem* __fastcall GetItem(void);
	HIDESBASE TdxLayoutControlItemViewInfo* __fastcall GetItemViewInfo(void);
	
protected:
	__property TdxLayoutControlItem* Item = {read=GetItem};
	__property TdxLayoutControlItemViewInfo* ItemViewInfo = {read=GetItemViewInfo};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutControlItemCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxLayoutLabeledItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutControlItemCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemCaptionViewInfo : public TdxLayoutControlItemCaptionViewInfo
{
	typedef TdxLayoutControlItemCaptionViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutItem* __fastcall GetItem(void);
	HIDESBASE TdxLayoutItemViewInfo* __fastcall GetItemViewInfo(void);
	
protected:
	__property TdxLayoutItem* Item = {read=GetItem};
	__property TdxLayoutItemViewInfo* ItemViewInfo = {read=GetItemViewInfo};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutItemCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxLayoutControlItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutItemCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlItemControlViewInfo : public TdxCustomLayoutItemElementViewInfo
{
	typedef TdxCustomLayoutItemElementViewInfo inherited;
	
private:
	System::Types::TSize FPrevControlSize;
	System::Types::TRect FControlBounds;
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	Dxlayoutlookandfeels::TdxLayoutBorderStyle __fastcall GetBorderStyle(void);
	HIDESBASE TdxLayoutControlItem* __fastcall GetItem(void);
	TdxLayoutControlItemViewInfo* __fastcall GetItemViewInfo(void);
	bool __fastcall GetOpaqueControl(void);
	
protected:
	virtual bool __fastcall GetVisible(void);
	virtual System::Types::TRect __fastcall CalculateControlBounds(void);
	virtual int __fastcall GetBorderWidth(Dxlayoutcommon::TdxLayoutSide ASide);
	virtual int __fastcall GetControlAreaHeight(int AControlHeight);
	virtual int __fastcall GetControlAreaWidth(int AControlWidth);
	virtual System::Types::TSize __fastcall GetOriginalControlSize(void);
	virtual bool __fastcall HasBorder(void);
	__property int BorderWidths[Dxlayoutcommon::TdxLayoutSide ASide] = {read=GetBorderWidth};
	__property TdxLayoutControlItem* Item = {read=GetItem};
	__property TdxLayoutControlItemViewInfo* ItemViewInfo = {read=GetItemViewInfo};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateInternalTabOrder(int &AAvailTabOrder);
	virtual void __fastcall CalculateTabOrder(int &AAvailTabOrder);
	virtual int __fastcall CalculateMinHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, nodefault};
	__property Dxlayoutlookandfeels::TdxLayoutBorderStyle BorderStyle = {read=GetBorderStyle, nodefault};
	__property System::Types::TRect ControlBounds = {read=FControlBounds};
	__property bool OpaqueControl = {read=GetOpaqueControl, nodefault};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutControlItemControlViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxCustomLayoutItemElementViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutControlItemControlViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxLayoutControlItemControlViewInfoClass;

class DELPHICLASS TdxLayoutItemControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemControlViewInfo : public TdxLayoutControlItemControlViewInfo
{
	typedef TdxLayoutControlItemControlViewInfo inherited;
	
private:
	Vcl::Controls::TControl* __fastcall GetControl(void);
	HIDESBASE TdxLayoutItem* __fastcall GetItem(void);
	
protected:
	__property TdxLayoutItem* Item = {read=GetItem};
	
public:
	virtual void __fastcall CalculateTabOrder(int &AAvailTabOrder);
	__property Vcl::Controls::TControl* Control = {read=GetControl};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutItemControlViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxLayoutControlItemControlViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutItemControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutBasicItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutBasicItemViewInfo : public TdxCustomLayoutItemViewInfo
{
	typedef TdxCustomLayoutItemViewInfo inherited;
	
protected:
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual TdxCustomLayoutItemHitTestClass __fastcall GetHitTestClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual bool __fastcall IsDefaultColor(void);
	virtual bool __fastcall IsTransparent(void);
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutBasicItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutBasicItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutEmptySpaceItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutEmptySpaceItemViewInfo : public TdxLayoutBasicItemViewInfo
{
	typedef TdxLayoutBasicItemViewInfo inherited;
	
protected:
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall DoCalculateHeight(bool AIsMinHeight);
	virtual int __fastcall DoCalculateWidth(bool AIsMinWidth);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutEmptySpaceItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutBasicItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutEmptySpaceItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutDirectionalItemViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutDirectionalItemViewInfo : public TdxLayoutBasicItemViewInfo
{
	typedef TdxLayoutBasicItemViewInfo inherited;
	
private:
	TdxLayoutDirectionalItem* __fastcall GetItem(void);
	
protected:
	virtual int __fastcall DoCalculateHeight(bool AIsMinHeight);
	virtual int __fastcall DoCalculateWidth(bool AIsMinWidth);
	virtual int __fastcall GetItemMinHeight(void);
	virtual int __fastcall GetItemMinWidth(void);
	bool __fastcall IsVertical(void);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	__property TdxLayoutDirectionalItem* Item = {read=GetItem};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutDirectionalItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutBasicItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutDirectionalItemViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSeparatorItemViewInfo : public TdxLayoutDirectionalItemViewInfo
{
	typedef TdxLayoutDirectionalItemViewInfo inherited;
	
private:
	TdxLayoutSeparatorItem* __fastcall GetSeparator(void);
	
protected:
	virtual int __fastcall GetItemMinHeight(void);
	virtual int __fastcall GetItemMinWidth(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	
public:
	__property TdxLayoutSeparatorItem* Separator = {read=GetSeparator};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutSeparatorItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutDirectionalItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutSeparatorItemViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutSplitterItemViewInfo : public TdxLayoutDirectionalItemViewInfo
{
	typedef TdxLayoutDirectionalItemViewInfo inherited;
	
private:
	TdxLayoutSplitterItem* __fastcall GetSplitter(void);
	
protected:
	virtual System::Types::TRect __fastcall GetHitTestBounds(void);
	virtual TdxCustomLayoutItemHitTestClass __fastcall GetHitTestClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall GetItemMinHeight(void);
	virtual int __fastcall GetItemMinWidth(void);
	virtual void __fastcall StateChanged(void);
	virtual bool __fastcall IsHotTrackable(void);
	
public:
	__property TdxLayoutSplitterItem* Splitter = {read=GetSplitter};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutSplitterItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutDirectionalItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutSplitterItemViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutLabeledItemViewInfo : public TdxLayoutBasicItemViewInfo
{
	typedef TdxLayoutBasicItemViewInfo inherited;
	
protected:
	System::Types::TRect FCaptionViewInfoBounds;
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	void __fastcall InitViewInfoBounds(TdxCustomLayoutItemElementViewInfo* AElementViewInfo, /* out */ System::Types::TRect &ABounds, /* out */ System::Types::TPoint &ASize, /* out */ bool &AVisible);
	virtual void __fastcall CalculateViewInfoBounds(void);
	virtual System::Types::TRect __fastcall CalculatePadding(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual int __fastcall GetContentHeight(bool AIsMinHeight);
	virtual int __fastcall GetContentWidth(bool AIsMinWidth);
	virtual int __fastcall DoCalculateHeight(bool AIsMinHeight);
	virtual int __fastcall DoCalculateWidth(bool AIsMinWidth);
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	virtual int __fastcall GetElementOffsetHorz(void);
	virtual int __fastcall GetElementOffsetVert(void);
	__property int ElementOffsetHorz = {read=GetElementOffsetHorz, nodefault};
	__property int ElementOffsetVert = {read=GetElementOffsetVert, nodefault};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutLabeledItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutBasicItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutLabeledItemViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlItemViewInfo : public TdxLayoutLabeledItemViewInfo
{
	typedef TdxLayoutLabeledItemViewInfo inherited;
	
private:
	TdxLayoutControlItemControlViewInfo* FControlViewInfo;
	TdxLayoutControlItemCaptionViewInfo* __fastcall GetCaptionViewInfo(void);
	TdxLayoutControlItem* __fastcall GetItem(void);
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelItemOptions* __fastcall GetOptionsEx(void);
	
protected:
	System::Types::TRect FControlViewInfoBounds;
	virtual void __fastcall DoCreateViewInfos(void);
	virtual void __fastcall PopulateAutoAlignControlList(System::Classes::TList* AList);
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual TdxLayoutControlItemControlViewInfoClass __fastcall GetControlViewInfoClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall CalculateViewInfoBounds(void);
	virtual int __fastcall GetContentHeight(bool AIsMinHeight);
	virtual int __fastcall GetContentWidth(bool AIsMinWidth);
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	virtual bool __fastcall GetAutoControlAreaAlignment(void);
	virtual TdxCaptionLayout __fastcall GetCaptionLayout(void);
	virtual bool __fastcall HasControl(void);
	virtual void __fastcall PaintSelectionLayer(Cxgraphics::TcxAlphaBitmap* ABitmap);
	__property TdxLayoutControlItem* Item = {read=GetItem};
	__property Dxlayoutlookandfeels::TdxLayoutLookAndFeelItemOptions* Options = {read=GetOptionsEx};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateInternalTabOrders(int &AAvailTabOrder);
	virtual void __fastcall CalculateTabOrders(int &AAvailTabOrder);
	__property bool AutoControlAreaAlignment = {read=GetAutoControlAreaAlignment, nodefault};
	__property TdxCaptionLayout CaptionLayout = {read=GetCaptionLayout, nodefault};
	__property TdxLayoutControlItemCaptionViewInfo* CaptionViewInfo = {read=GetCaptionViewInfo};
	__property TdxLayoutControlItemControlViewInfo* ControlViewInfo = {read=FControlViewInfo};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutControlItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutLabeledItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutControlItemViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemViewInfo : public TdxLayoutControlItemViewInfo
{
	typedef TdxLayoutControlItemViewInfo inherited;
	
private:
	HIDESBASE TdxLayoutItemCaptionViewInfo* __fastcall GetCaptionViewInfo(void);
	TdxLayoutItemControlViewInfo* __fastcall GetControlViewInfo(void);
	HIDESBASE TdxLayoutItem* __fastcall GetItem(void);
	
protected:
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual TdxLayoutControlItemControlViewInfoClass __fastcall GetControlViewInfoClass(void);
	virtual TdxCustomLayoutItemHitTestClass __fastcall GetHitTestClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall PopulateControlViewInfoList(System::Classes::TList* AControls, System::Classes::TList* AWinControls);
	virtual void __fastcall CustomizationMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	bool __fastcall PtInDesignSelectorRect(const System::Types::TPoint &P);
	__property TdxLayoutItem* Item = {read=GetItem};
	
public:
	__property TdxLayoutItemCaptionViewInfo* CaptionViewInfo = {read=GetCaptionViewInfo};
	__property TdxLayoutItemControlViewInfo* ControlViewInfo = {read=GetControlViewInfo};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutItemViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxLayoutControlItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutItemViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupCaptionViewInfo : public TdxCustomLayoutItemCaptionViewInfo
{
	typedef TdxCustomLayoutItemCaptionViewInfo inherited;
	
private:
	Dxlayoutcommon::TdxLayoutSide __fastcall GetCaptionSide(void);
	TdxLayoutGroupViewInfo* __fastcall GetGroupViewInfo(void);
	
protected:
	virtual System::Classes::TAlignment __fastcall GetAlignHorz(void);
	virtual TdxAlignmentVert __fastcall GetAlignVert(void);
	virtual int __fastcall GetAvailableTextHeight(void);
	virtual int __fastcall GetAvailableTextWidth(void);
	virtual System::Types::TRect __fastcall GetImageAreaBounds(void);
	virtual int __fastcall GetTextHeight(void);
	virtual int __fastcall GetTextWidth(void);
	virtual Cxgraphics::TcxRotationAngle __fastcall GetRotationAngle(void);
	virtual bool __fastcall IsVerticalCaption(void);
	__property Dxlayoutcommon::TdxLayoutSide CaptionSide = {read=GetCaptionSide, nodefault};
	__property TdxLayoutGroupViewInfo* GroupViewInfo = {read=GetGroupViewInfo};
	
public:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateMinHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateWidth(void);
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupCaptionViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxCustomLayoutItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TItemInfo
{
public:
	TdxCustomLayoutItemViewInfo* ViewInfo;
	TdxLayoutAlignHorz AlignHorz;
	int UsualWidth;
	int MinWidth;
	int RealWidth;
	int Height;
	System::Types::TRect Bounds;
	bool Calculated;
};


typedef System::DynamicArray<TItemInfo> TItemInfos;

class DELPHICLASS TdxLayoutGroupViewInfoSpecific;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupViewInfoSpecific : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxLayoutGroupViewInfo* FGroupViewInfo;
	TItemInfos FItemInfos;
	System::Types::TPoint FOffset;
	void __fastcall PrepareItemInfos(void);
	void __fastcall CalculateItemViewInfos(void);
	TdxLayoutContainer* __fastcall GetContainer(void);
	int __fastcall GetItemOffset(void);
	TdxCustomLayoutItemViewInfo* __fastcall GetItemViewInfo(int Index);
	int __fastcall GetItemViewInfoCount(void);
	TdxLayoutDirection __fastcall GetLayoutDirection(void);
	void __fastcall SetOffset(const System::Types::TPoint &Value);
	
protected:
	virtual bool __fastcall CanDrawSpecificControls(void);
	virtual void __fastcall DrawSpecificControls(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall CalculateItemsAreaBounds(System::Types::TRect &AItemsAreaBounds);
	virtual void __fastcall CalculateItemsHorizontalBounds(const System::Types::TRect &AItemsAreaBounds);
	virtual void __fastcall CalculateItemsVerticalBounds(const System::Types::TRect &AItemsAreaBounds);
	virtual void __fastcall CalculateInternalTabOrders(int &ATabOrder);
	virtual void __fastcall CorrectItemsAreaBounds(System::Types::TRect &AItemsAreaBounds);
	virtual void __fastcall CorrectAreaPart(TdxLayoutAreaPart &AAreaPart);
	virtual TdxLayoutActionType __fastcall GetActionType(TdxLayoutAreaPart AAreaPart) = 0 ;
	virtual TdxLayoutAreaPart __fastcall GetAreaPart(const System::Types::TPoint &P);
	virtual System::Types::TRect __fastcall GetAreaPartBounds(TdxLayoutAreaPart AAreaPart, TdxCustomLayoutItemViewInfo* AItemViewInfo);
	virtual void __fastcall ConvertCoords(System::Types::TRect &R);
	virtual int __fastcall GetCustomHeight(bool AIsMinHeight);
	virtual int __fastcall GetCustomWidth(bool AIsMinWidth);
	virtual TdxLayoutAlignHorz __fastcall GetItemAlignHorz(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual TdxLayoutAlignVert __fastcall GetItemAlignVert(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemUsualHeight(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemUsualWidth(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemMinHeight(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemMinWidth(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall IsViewInfoFixedWidth(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual bool __fastcall IsViewInfoFixedHeight(TdxCustomLayoutItemViewInfo* AViewInfo) = 0 ;
	virtual int __fastcall GetItemsAreaOffset(Dxlayoutcommon::TdxLayoutSide ASide);
	virtual void __fastcall AddSelectionControls(void);
	virtual void __fastcall RemoveSelectionControls(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall CreateSpecificControls(void);
	virtual void __fastcall DestroySpecificControls(void);
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	void __fastcall AssignBounds(TdxLayoutGroupViewInfoSpecific* ASource);
	virtual bool __fastcall CanAssignBounds(TdxLayoutGroupViewInfoSpecific* ASource);
	virtual void __fastcall DoAssignBounds(TdxLayoutGroupViewInfoSpecific* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	__property TdxLayoutContainer* Container = {read=GetContainer};
	__property TdxLayoutGroupViewInfo* GroupViewInfo = {read=FGroupViewInfo};
	__property int ItemOffset = {read=GetItemOffset, nodefault};
	__property int ItemViewInfoCount = {read=GetItemViewInfoCount, nodefault};
	__property TdxCustomLayoutItemViewInfo* ItemViewInfos[int Index] = {read=GetItemViewInfo};
	__property TdxLayoutDirection LayoutDirection = {read=GetLayoutDirection, nodefault};
	__property System::Types::TPoint Offset = {read=FOffset, write=SetOffset};
	
public:
	__fastcall virtual TdxLayoutGroupViewInfoSpecific(TdxLayoutGroupViewInfo* AGroupViewInfo);
	__fastcall virtual ~TdxLayoutGroupViewInfoSpecific(void);
	virtual void __fastcall Calculate(const System::Types::TRect &AItemsAreaBounds);
	void __fastcall CalculateItemsBounds(const System::Types::TRect &AItemsAreaBounds);
	virtual int __fastcall GetItemsAreaHeight(bool AIsMinHeight);
	virtual int __fastcall GetItemsAreaWidth(bool AIsMinWidth);
	virtual bool __fastcall IsAtInsertionPos(const System::Types::TRect &R, const System::Types::TPoint &P) = 0 ;
	virtual bool __fastcall AllowDrawChild(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	virtual bool __fastcall AllowChildHasBorder(void);
	virtual System::Types::TRect __fastcall GetChildInplaceRenameBounds(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	virtual TdxLayoutItemControlAreaAlignment __fastcall GetDefaultItemControlAreaAlignment(void);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall ProcessDialogKey(System::Word ACharCode, int AKeyData, TdxLayoutItem* AFocusedItem);
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

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupViewInfoHorizontalSpecific;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupViewInfoHorizontalSpecific : public TdxLayoutGroupViewInfoSpecific
{
	typedef TdxLayoutGroupViewInfoSpecific inherited;
	
protected:
	virtual TdxLayoutActionType __fastcall GetActionType(TdxLayoutAreaPart AAreaPart);
	virtual System::Types::TRect __fastcall GetAreaPartBounds(TdxLayoutAreaPart AAreaPart, TdxCustomLayoutItemViewInfo* AItemViewInfo);
	virtual TdxLayoutAlignHorz __fastcall GetItemAlignHorz(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual TdxLayoutAlignVert __fastcall GetItemAlignVert(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemUsualHeight(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemUsualWidth(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemMinHeight(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemMinWidth(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual bool __fastcall IsViewInfoFixedWidth(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual bool __fastcall IsViewInfoFixedHeight(TdxCustomLayoutItemViewInfo* AViewInfo);
	
public:
	virtual bool __fastcall IsAtInsertionPos(const System::Types::TRect &R, const System::Types::TPoint &P);
public:
	/* TdxLayoutGroupViewInfoSpecific.Create */ inline __fastcall virtual TdxLayoutGroupViewInfoHorizontalSpecific(TdxLayoutGroupViewInfo* AGroupViewInfo) : TdxLayoutGroupViewInfoSpecific(AGroupViewInfo) { }
	/* TdxLayoutGroupViewInfoSpecific.Destroy */ inline __fastcall virtual ~TdxLayoutGroupViewInfoHorizontalSpecific(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupViewInfoVerticalSpecific;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupViewInfoVerticalSpecific : public TdxLayoutGroupViewInfoSpecific
{
	typedef TdxLayoutGroupViewInfoSpecific inherited;
	
protected:
	virtual void __fastcall ConvertCoords(System::Types::TRect &R);
	virtual TdxLayoutActionType __fastcall GetActionType(TdxLayoutAreaPart AAreaPart);
	virtual System::Types::TRect __fastcall GetAreaPartBounds(TdxLayoutAreaPart AAreaPart, TdxCustomLayoutItemViewInfo* AItemViewInfo);
	virtual TdxLayoutAlignHorz __fastcall GetItemAlignHorz(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual TdxLayoutAlignVert __fastcall GetItemAlignVert(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemUsualHeight(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemUsualWidth(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemMinHeight(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual int __fastcall GetItemMinWidth(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual bool __fastcall IsViewInfoFixedWidth(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual bool __fastcall IsViewInfoFixedHeight(TdxCustomLayoutItemViewInfo* AViewInfo);
	
public:
	virtual int __fastcall GetItemsAreaHeight(bool AIsMinHeight);
	virtual int __fastcall GetItemsAreaWidth(bool AIsMinWidth);
	virtual bool __fastcall IsAtInsertionPos(const System::Types::TRect &R, const System::Types::TPoint &P);
public:
	/* TdxLayoutGroupViewInfoSpecific.Create */ inline __fastcall virtual TdxLayoutGroupViewInfoVerticalSpecific(TdxLayoutGroupViewInfo* AGroupViewInfo) : TdxLayoutGroupViewInfoSpecific(AGroupViewInfo) { }
	/* TdxLayoutGroupViewInfoSpecific.Destroy */ inline __fastcall virtual ~TdxLayoutGroupViewInfoVerticalSpecific(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutTabbedController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutTabbedController : public Cxpc::TcxCustomTabControlController
{
	typedef Cxpc::TcxCustomTabControlController inherited;
	
protected:
	virtual System::Types::TPoint __fastcall GetClientToScreen(const System::Types::TPoint &APoint);
	virtual System::Types::TPoint __fastcall GetScreenToClient(const System::Types::TPoint &APoint);
public:
	/* TcxCustomTabControlController.Create */ inline __fastcall virtual TdxLayoutTabbedController(System::TObject* AOwner) : Cxpc::TcxCustomTabControlController(AOwner) { }
	/* TcxCustomTabControlController.Destroy */ inline __fastcall virtual ~TdxLayoutTabbedController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutTabbedViewInfo;
class PASCALIMPLEMENTATION TdxLayoutTabbedViewInfo : public Cxpc::TcxCustomTabControlViewInfo
{
	typedef Cxpc::TcxCustomTabControlViewInfo inherited;
	
private:
	TdxLayoutGroupViewInfo* __fastcall GetGroupViewInfo(void);
	
protected:
	virtual int __fastcall GetTabIndex(void);
	virtual void __fastcall SetTabIndex(int Value);
	__property TdxLayoutGroupViewInfo* GroupViewInfo = {read=GetGroupViewInfo};
public:
	/* TcxCustomTabControlViewInfo.Create */ inline __fastcall virtual TdxLayoutTabbedViewInfo(System::TObject* AOwner) : Cxpc::TcxCustomTabControlViewInfo(AOwner) { }
	/* TcxCustomTabControlViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutTabbedViewInfo(void) { }
	
};


class DELPHICLASS TdxTabControlElementViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTabControlElementViewInfo : public TdxCustomLayoutItemElementViewInfo
{
	typedef TdxCustomLayoutItemElementViewInfo inherited;
	
private:
	TdxLayoutTabbedController* FTabController;
	TdxLayoutTabbedViewInfo* FTabViewInfo;
	TdxLayoutGroup* __fastcall GetGroup(void);
	
protected:
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property TdxLayoutGroup* Group = {read=GetGroup};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TdxTabControlElementViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo) : TdxCustomLayoutItemElementViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxTabControlElementViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupViewInfoTabbedSpecific : public TdxLayoutGroupViewInfoHorizontalSpecific
{
	typedef TdxLayoutGroupViewInfoHorizontalSpecific inherited;
	
private:
	System::Types::TRect FTabControlBounds;
	TdxTabControlElementViewInfo* FTabControlElementViewInfo;
	TdxTabControlElementViewInfo* FTabControlElementViewInfoOpposite;
	TdxLayoutTabbedController* FTabController;
	Cxpc::TcxPCCustomPainter* FTabPainter;
	TdxLayoutTabbedViewInfo* FTabViewInfo;
	void __fastcall DrawTabControl(Cxgraphics::TcxCanvas* ACanvas);
	TdxLayoutTabbedOptions* __fastcall GetTabbedOptions(void);
	
protected:
	virtual bool __fastcall CanDrawSpecificControls(void);
	virtual void __fastcall DrawSpecificControls(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall CalculateItemsAreaBounds(System::Types::TRect &AItemsAreaBounds);
	virtual void __fastcall CalculateItemsHorizontalBounds(const System::Types::TRect &AItemsAreaBounds);
	virtual void __fastcall CalculateInternalTabOrders(int &ATabOrder);
	virtual void __fastcall CalculateTabControl(void);
	virtual TdxLayoutActionType __fastcall GetActionType(TdxLayoutAreaPart AAreaPart);
	virtual void __fastcall CorrectAreaPart(TdxLayoutAreaPart &AAreaPart);
	virtual TdxLayoutAreaPart __fastcall GetAreaPart(const System::Types::TPoint &P);
	virtual System::Types::TRect __fastcall GetAreaPartBounds(TdxLayoutAreaPart AAreaPart, TdxCustomLayoutItemViewInfo* AItemViewInfo);
	virtual int __fastcall GetCustomHeight(bool AIsMinHeight);
	virtual int __fastcall GetCustomWidth(bool AIsMinWidth);
	virtual void __fastcall DoAssignBounds(TdxLayoutGroupViewInfoSpecific* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	virtual int __fastcall GetItemsAreaOffset(Dxlayoutcommon::TdxLayoutSide ASide);
	int __fastcall GetHitTabIndex(const System::Types::TPoint &P);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall CreateSpecificControls(void);
	virtual void __fastcall DestroySpecificControls(void);
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	void __fastcall CreateTabControl(void);
	void __fastcall DestroyTabControl(void);
	bool __fastcall HasTabControl(void);
	Cxpc::TcxCustomTabControlController* __fastcall GetTabController(void);
	Cxpc::TcxPCCustomPainter* __fastcall GetTabPainter(void);
	Cxpc::TcxCustomTabControlProperties* __fastcall GetTabProperties(void);
	Cxpc::TcxCustomTabControlViewInfo* __fastcall GetTabViewInfo(void);
	bool __fastcall CanDrawTabParentBackground(void);
	System::Types::TRect __fastcall GetTabBoundsRect(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	Vcl::Controls::TWinControl* __fastcall GetControl(void);
	System::Uitypes::TColor __fastcall GetTabColor(void);
	Cxcontrols::TcxDragAndDropObject* __fastcall GetDragAndDropObject(void);
	Cxcontrols::TcxDragAndDropState __fastcall GetDragAndDropState(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	void __fastcall InvalidateTabRect(const System::Types::TRect &R, bool AEraseBackground);
	void __fastcall SetModified(void);
	bool __fastcall IsEnabled(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsLoading(void);
	bool __fastcall IsParentBackground(void);
	void __fastcall RequestLayout(void);
	__property TdxLayoutTabbedOptions* TabbedOptions = {read=GetTabbedOptions};
	
public:
	__fastcall virtual TdxLayoutGroupViewInfoTabbedSpecific(TdxLayoutGroupViewInfo* AGroupViewInfo);
	__fastcall virtual ~TdxLayoutGroupViewInfoTabbedSpecific(void);
	virtual bool __fastcall AllowDrawChild(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	virtual bool __fastcall AllowChildHasBorder(void);
	virtual System::Types::TRect __fastcall GetChildInplaceRenameBounds(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	virtual TdxLayoutItemControlAreaAlignment __fastcall GetDefaultItemControlAreaAlignment(void);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall ProcessDialogKey(System::Word ACharCode, int AKeyData, TdxLayoutItem* AFocusedItem);
private:
	void *__IcxControlComponentState;	/* Cxcontrols::IcxControlComponentState */
	void *__IcxTabControl;	/* Cxpc::IcxTabControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E29BF582-E8C0-4868-A799-DB4C41AC3BC8}
	operator Cxcontrols::_di_IcxControlComponentState()
	{
		Cxcontrols::_di_IcxControlComponentState intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxControlComponentState; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8C8C2262-5419-46E1-BCE0-5A5311C330A0}
	operator Cxpc::_di_IcxTabControl()
	{
		Cxpc::_di_IcxTabControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxpc::IcxTabControl*(void) { return (Cxpc::IcxTabControl*)&__IcxTabControl; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupButtonsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupButtonViewInfo : public TdxCustomLayoutItemElementViewInfo
{
	typedef TdxCustomLayoutItemElementViewInfo inherited;
	
private:
	TdxLayoutGroupButton* FButton;
	TdxLayoutGroupButtonsViewInfo* FButtonsViewInfo;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	bool __fastcall GetIsEnabled(void);
	int __fastcall GetVisibleIndex(void);
	
protected:
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoClick(void);
	virtual void __fastcall StateChanged(void);
	virtual bool __fastcall IsHotTrackable(void);
	virtual bool __fastcall ShowHint(Vcl::Controls::THintInfo &AHintInfo);
	virtual bool __fastcall GetVisible(void);
	virtual TdxLayoutGroupButtonPainterClass __fastcall GetPainterClass(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	bool __fastcall IsGroupExpanded(void);
	bool __fastcall IsExpandButton(void);
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph};
	__property bool IsEnabled = {read=GetIsEnabled, nodefault};
	
public:
	__fastcall virtual TdxLayoutGroupButtonViewInfo(TdxLayoutGroupButtonsViewInfo* AButtonsViewInfo, TdxLayoutGroupButton* AButton);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	__property TdxLayoutGroupButton* Button = {read=FButton};
	__property TdxLayoutGroupButtonsViewInfo* ButtonsViewInfo = {read=FButtonsViewInfo};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
public:
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupButtonViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupButtonsViewInfo : public TdxCustomLayoutItemElementViewInfo
{
	typedef TdxCustomLayoutItemElementViewInfo inherited;
	
private:
	Cxclasses::TcxObjectList* FButtonViewInfos;
	TdxLayoutGroupButtonViewInfo* __fastcall GetButtonViewInfos(int Index);
	int __fastcall GetButtonViewInfoCount(void);
	TdxLayoutGroupButton* __fastcall GetExpandButton(void);
	TdxLayoutGroupViewInfo* __fastcall GetGroupViewInfo(void);
	TdxLayoutGroupButtonOptions* __fastcall GetOptions(void);
	
protected:
	virtual bool __fastcall GetVisible(void);
	void __fastcall CalculateHorizontalLayout(void);
	void __fastcall CalculateVerticalLayout(void);
	void __fastcall CalculateButtonViewInfos(void);
	void __fastcall CreateButtonViewInfos(void);
	void __fastcall RecreateButtonViewInfos(void);
	void __fastcall DestroyButtonViewInfos(void);
	virtual int __fastcall InternalCalculateHeight(void);
	virtual int __fastcall InternalCalculateWidth(void);
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	virtual bool __fastcall IsLeftAlignment(void);
	__property TdxLayoutGroupButton* ExpandButton = {read=GetExpandButton};
	__property TdxLayoutGroupButtonOptions* Options = {read=GetOptions};
	
public:
	__fastcall virtual TdxLayoutGroupButtonsViewInfo(TdxCustomLayoutItemViewInfo* AItemViewInfo);
	__fastcall virtual ~TdxLayoutGroupButtonsViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateMinHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual int __fastcall CalculateWidth(void);
	__property int ButtonViewInfoCount = {read=GetButtonViewInfoCount, nodefault};
	__property TdxLayoutGroupButtonViewInfo* ButtonViewInfos[int Index] = {read=GetButtonViewInfos};
	__property TdxLayoutGroupViewInfo* GroupViewInfo = {read=GetGroupViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutGroupViewInfoCloneData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupViewInfoCloneData : public TdxCustomLayoutItemViewInfoCloneData
{
	typedef TdxCustomLayoutItemViewInfoCloneData inherited;
	
private:
	bool FIsExpanded;
	int FItemIndex;
	void __fastcall SetIsExpanded(bool Value);
	void __fastcall SetItemIndex(int Value);
	
protected:
	virtual int __fastcall GetSize(void);
	
public:
	virtual void __fastcall Assign(TdxCustomLayoutItemViewInfoCloneData* Source);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall Load(System::Classes::TStream* AStream);
	virtual void __fastcall Save(System::Classes::TStream* AStream);
	__property bool IsExpanded = {read=FIsExpanded, write=SetIsExpanded, nodefault};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
public:
	/* TdxCustomLayoutItemViewInfoCloneData.Create */ inline __fastcall virtual TdxLayoutGroupViewInfoCloneData(TdxLayoutCloneDataList* AOwner, TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemViewInfoCloneData(AOwner, AItem) { }
	/* TdxCustomLayoutItemViewInfoCloneData.Destroy */ inline __fastcall virtual ~TdxLayoutGroupViewInfoCloneData(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutGroupViewInfo : public TdxCustomLayoutItemViewInfo
{
	typedef TdxCustomLayoutItemViewInfo inherited;
	
private:
	TdxLayoutGroupButtonsViewInfo* FButtonsViewInfo;
	bool FOffsetsCalculated;
	int FItemOffset;
	int FItemsAreaOffsetHorz;
	int FItemsAreaOffsetVert;
	System::Contnrs::TObjectList* FItemViewInfos;
	TdxLayoutGroupViewInfoSpecific* FSpecific;
	System::Types::TRect __fastcall GetBorderBounds(Dxlayoutcommon::TdxLayoutSide ASide);
	System::Types::TRect __fastcall GetBorderRestSpaceBounds(Dxlayoutcommon::TdxLayoutSide ASide);
	int __fastcall GetBordersHeight(void);
	int __fastcall GetBordersWidth(void);
	Dxlayoutcommon::TdxLayoutSide __fastcall GetCaptionSide(void);
	TdxLayoutGroupCaptionViewInfo* __fastcall GetCaptionViewInfo(void);
	TdxLayoutGroupViewInfoCloneData* __fastcall GetCloneData(void);
	TdxLayoutGroup* __fastcall GetGroup(void);
	TdxCustomLayoutItemViewInfo* __fastcall GetItemViewInfo(int Index);
	int __fastcall GetItemViewInfoCount(void);
	TdxLayoutDirection __fastcall GetLayoutDirection(void);
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelGroupOptions* __fastcall GetOptionsEx(void);
	TdxLayoutItemControlAreaAlignment __fastcall GetRealItemControlAreaAlignment(void);
	int __fastcall GetItemIndex(void);
	HIDESBASE int __fastcall GetOffset(int Index);
	void __fastcall CreateItemViewInfos(void);
	void __fastcall CreateSpecific(void);
	void __fastcall DestroyItemViewInfos(void);
	void __fastcall DestroySpecific(void);
	
protected:
	System::Types::TRect FCaptionAreaBounds;
	System::Types::TRect FButtonsAreaBounds;
	System::Types::TRect FClientAreaBounds;
	System::Types::TRect FItemsAreaBounds;
	virtual void __fastcall DoCreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	virtual void __fastcall ItemChanged(TdxLayoutItemChangeType AType);
	virtual void __fastcall PopulateAutoAlignControlList(System::Classes::TList* AList);
	virtual void __fastcall PopulateControlViewInfoList(System::Classes::TList* AControls, System::Classes::TList* AWinControls);
	virtual TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual TdxCustomLayoutItemViewInfoCloneDataClass __fastcall GetCloneDataClass(void);
	virtual TdxCustomLayoutItemHitTestClass __fastcall GetHitTestClass(void);
	virtual TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall CanDrawSpecificControls(void);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual void __fastcall AutoAlignControls(void);
	virtual int __fastcall CalculateHeight(void);
	virtual System::Types::TRect __fastcall CalculatePadding(void);
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall DoCalculateHeight(bool AIsMinHeight = false);
	virtual int __fastcall DoCalculateWidth(bool AIsMinWidth = false);
	virtual int __fastcall GetCloneDataSize(void);
	void __fastcall CorrectAreaPart(TdxLayoutAreaPart &AAreaPart);
	TdxLayoutActionType __fastcall GetActionType(TdxLayoutAreaPart AAreaPart);
	virtual TdxLayoutAreaPart __fastcall GetAreaPart(const System::Types::TPoint &P);
	System::Types::TRect __fastcall GetAreaPartBounds(TdxLayoutAreaPart AAreaPart, TdxCustomLayoutItemViewInfo* AItemViewInfo);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LoadCloneData(System::Classes::TStream* AStream);
	virtual void __fastcall SaveCloneData(System::Classes::TStream* AStream);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasBorder(void);
	bool __fastcall HasButtons(void);
	bool __fastcall HasExpandButton(void);
	virtual bool __fastcall IsDefaultColor(void);
	bool __fastcall IsSkinPainterUsed(void);
	virtual bool __fastcall IsTransparent(void);
	virtual void __fastcall CalculateButtonsViewInfoBounds(void);
	virtual void __fastcall CalculateCaptionViewInfoBounds(void);
	virtual void __fastcall CalculateClientBounds(void);
	virtual void __fastcall CalculateItemsAreaBounds(void);
	void __fastcall CalculateOffsets(void);
	void __fastcall CalculateViewInfosBounds(void);
	virtual int __fastcall GetButtonsViewInfoOffset(void);
	virtual int __fastcall GetButtonsViewInfoSpace(void);
	virtual int __fastcall GetCaptionViewInfoOffset(void);
	int __fastcall GetSpaceBetweenButtons(void);
	System::Types::TRect __fastcall GetClientAreaBounds(const System::Types::TRect &ABounds);
	System::Types::TRect __fastcall GetItemAreaBounds(const System::Types::TRect &AClientRect);
	virtual int __fastcall GetBorderWidth(Dxlayoutcommon::TdxLayoutSide ASide);
	virtual int __fastcall GetHeight(int AItemsAreaHeight);
	virtual int __fastcall GetWidth(int AItemsAreaWidth);
	virtual int __fastcall GetMinVisibleHeight(void);
	virtual int __fastcall GetMinVisibleWidth(void);
	virtual System::Types::TRect __fastcall GetRestSpaceBounds(void);
	virtual void __fastcall DoAssignBounds(TdxCustomLayoutElementViewInfo* ASource);
	virtual void __fastcall DoSetOffset(const System::Types::TPoint &Value);
	bool __fastcall AllowChildHasBorder(void);
	virtual bool __fastcall AllowCollapsedHeight(void);
	virtual bool __fastcall AllowCollapsedWidth(void);
	virtual bool __fastcall AllowDrawChild(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	virtual System::Types::TRect __fastcall GetChildInplaceRenameBounds(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	Cxgraphics::TcxRotationAngle __fastcall GetRotationAngle(void);
	bool __fastcall IsChildActuallyVisible(TdxCustomLayoutItemViewInfo* AChildViewInfo);
	virtual bool __fastcall IsExpanded(void);
	bool __fastcall IsVerticalCaption(void);
	virtual bool __fastcall UseItemOffset(void);
	virtual bool __fastcall UseItemsAreaOffsets(void);
	virtual TdxCustomLayoutItemViewInfoClass __fastcall GetItemViewInfoClass(TdxCustomLayoutItem* AItem);
	virtual TdxLayoutGroupViewInfoSpecificClass __fastcall GetSpecificClass(void);
	virtual void __fastcall PaintSelectionLayer(Cxgraphics::TcxAlphaBitmap* ABitmap);
	virtual int __fastcall GetMaxTabOrderIndex(void);
	virtual void __fastcall DoButtonClick(TdxLayoutGroupButtonViewInfo* AViewInfo);
	__property int ButtonsViewInfoOffset = {read=GetButtonsViewInfoOffset, nodefault};
	__property int CaptionViewInfoOffset = {read=GetCaptionViewInfoOffset, nodefault};
	__property int ItemIndex = {read=GetItemIndex, nodefault};
	__property int ItemOffset = {read=GetOffset, write=FItemOffset, index=0, nodefault};
	__property int ItemsAreaOffsetHorz = {read=GetOffset, write=FItemsAreaOffsetHorz, index=1, nodefault};
	__property int ItemsAreaOffsetVert = {read=GetOffset, write=FItemsAreaOffsetVert, index=2, nodefault};
	__property int MinVisibleHeight = {read=GetMinVisibleHeight, nodefault};
	__property int MinVisibleWidth = {read=GetMinVisibleWidth, nodefault};
	__property System::Types::TRect RestSpaceBounds = {read=GetRestSpaceBounds};
	__property Dxlayoutcommon::TdxLayoutSide CaptionSide = {read=GetCaptionSide, nodefault};
	__property TdxLayoutGroupViewInfoCloneData* CloneData = {read=GetCloneData};
	__property TdxLayoutGroup* Group = {read=GetGroup};
	__property TdxLayoutDirection LayoutDirection = {read=GetLayoutDirection, nodefault};
	__property Dxlayoutlookandfeels::TdxLayoutLookAndFeelGroupOptions* Options = {read=GetOptionsEx};
	__property TdxLayoutGroupViewInfoSpecific* Specific = {read=FSpecific};
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall CalculateInternalTabOrders(int &AAvailTabOrder);
	virtual void __fastcall CalculateTabOrders(int &AAvailTabOrder);
	TdxCustomLayoutItemViewInfo* __fastcall FindItemViewInfo(TdxCustomLayoutItem* AItem);
	virtual TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual TdxCustomLayoutItem* __fastcall GetItemWithMouse(const System::Types::TPoint &P);
	virtual int __fastcall GetInsertionPos(const System::Types::TPoint &P);
	__property System::Types::TRect BorderBounds[Dxlayoutcommon::TdxLayoutSide ASide] = {read=GetBorderBounds};
	__property System::Types::TRect BorderRestSpaceBounds[Dxlayoutcommon::TdxLayoutSide ASide] = {read=GetBorderRestSpaceBounds};
	__property int BorderWidths[Dxlayoutcommon::TdxLayoutSide ASide] = {read=GetBorderWidth};
	__property int BordersHeight = {read=GetBordersHeight, nodefault};
	__property int BordersWidth = {read=GetBordersWidth, nodefault};
	__property TdxLayoutGroupButtonsViewInfo* ButtonsViewInfo = {read=FButtonsViewInfo};
	__property TdxLayoutGroupCaptionViewInfo* CaptionViewInfo = {read=GetCaptionViewInfo};
	__property System::Types::TRect ClientBounds = {read=FClientAreaBounds};
	__property System::Types::TRect ItemsAreaBounds = {read=FItemsAreaBounds};
	__property int ItemViewInfoCount = {read=GetItemViewInfoCount, nodefault};
	__property TdxCustomLayoutItemViewInfo* ItemViewInfos[int Index] = {read=GetItemViewInfo};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TdxLayoutGroupViewInfo(TdxLayoutContainerViewInfo* AContainerViewInfo, TdxLayoutGroupViewInfo* AParentViewInfo, TdxCustomLayoutItem* AItem) : TdxCustomLayoutItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutGroupViewInfo(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxLayoutContainerViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxLayoutContainer* FContainer;
	System::Types::TRect FContentBounds;
	bool FIsDragImagePainting;
	TdxLayoutCloneDataList* FItemCloneDataList;
	TdxLayoutGroupViewInfo* FItemsViewInfo;
	TdxCustomLayoutItem* FItemWithMouse;
	System::Types::TPoint FOffset;
	Dxlayoutselection::TdxSelectionLayer* FSelectionLayer;
	System::Classes::TNotifyEvent FOnCloneDataChanged;
	void __fastcall BuildSelectionLayer(void);
	void __fastcall CreateSelectionLayer(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	System::Types::TRect __fastcall GetContentBounds(void);
	int __fastcall GetContentHeight(void);
	int __fastcall GetContentWidth(void);
	void __fastcall SelectionLayerHitTest(System::TObject* ASender, bool &AIsTransparent);
	void __fastcall SelectionLayerUpdate(System::TObject* Sender);
	void __fastcall SelectionLayerEndRename(System::TObject* ASender, const System::UnicodeString AText, bool AAccept);
	void __fastcall SetItemWithMouse(TdxCustomLayoutItem* Value);
	void __fastcall SetOffset(const System::Types::TPoint &Value);
	
protected:
	bool FIsValid;
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	virtual TdxLayoutGroupViewInfoClass __fastcall GetItemsViewInfoClass(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetItemLayoutLookAndFeel(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetItemOptions(TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual void __fastcall PrepareData(void);
	void __fastcall RecreateViewInfos(void);
	virtual void __fastcall AlignItemsByConstraint(void);
	virtual void __fastcall AutoAlignControls(void);
	virtual void __fastcall CalculateItemsViewInfo(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoCalculateInternalTabOrders(void);
	virtual void __fastcall DoCalculateTabOrders(void);
	void __fastcall InvalidateSelectionLayer(const System::Types::TRect &R);
	bool __fastcall ShowHint(Vcl::Controls::THintInfo &AHintInfo, int X, int Y);
	virtual bool __fastcall CanUseCachedInfo(void);
	bool __fastcall HasBackground(void);
	bool __fastcall NeedHighlightRoot(void);
	virtual bool __fastcall IsDragImagePainting(void);
	void __fastcall AssignBounds(TdxLayoutContainerViewInfo* AViewInfo);
	TdxCustomLayoutItemViewInfoCloneData* __fastcall GetCloneData(TdxCustomLayoutItemViewInfo* AViewInfo);
	int __fastcall GetCloneDataSize(void);
	bool __fastcall FindCloneData(TdxCustomLayoutItem* AItem, /* out */ TdxCustomLayoutItemViewInfoCloneData* &ACloneData);
	virtual bool __fastcall IsClone(void);
	void __fastcall ItemCloneDataListChangedHandler(System::TObject* Sender);
	virtual void __fastcall LoadCloneData(System::Classes::TStream* AStream);
	void __fastcall RecalculateCloneDataList(void);
	virtual void __fastcall SaveCloneData(System::Classes::TStream* AStream);
	void __fastcall ResetContentBounds(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property TdxCustomLayoutItem* ItemWithMouse = {read=FItemWithMouse, write=SetItemWithMouse};
	__property Dxlayoutselection::TdxSelectionLayer* SelectionLayer = {read=FSelectionLayer};
	__property System::Classes::TNotifyEvent OnCloneDataChanged = {read=FOnCloneDataChanged, write=FOnCloneDataChanged};
	
public:
	__fastcall virtual TdxLayoutContainerViewInfo(TdxLayoutContainer* AContainer);
	__fastcall virtual ~TdxLayoutContainerViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateTabOrders(void);
	bool __fastcall FindItemViewInfo(TdxCustomLayoutItem* AItem, /* out */ TdxCustomLayoutItemViewInfo* &AViewInfo);
	virtual TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual TdxCustomLayoutItemViewInfo* __fastcall GetItemViewInfo(TdxCustomLayoutItem* AItem);
	TdxCustomLayoutItem* __fastcall GetItemWithMouse(const System::Types::TPoint &P);
	void __fastcall AssignItemWithMouse(int X, int Y);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall FinishDragImagePainting(void);
	void __fastcall StartDragImagePainting(void);
	System::Types::TPoint __fastcall GetScrollOffset(void);
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property TdxLayoutContainer* Container = {read=FContainer};
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property int ContentHeight = {read=GetContentHeight, nodefault};
	__property int ContentWidth = {read=GetContentWidth, nodefault};
	__property TdxLayoutGroupViewInfo* ItemsViewInfo = {read=FItemsViewInfo};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
	__property System::Types::TPoint Offset = {read=FOffset, write=SetOffset};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 htError = System::Int8(-1);
static const System::Int8 htNone = System::Int8(0x0);
static const System::Int8 htCustomizeForm = System::Int8(0x1);
static const System::Int8 htItem = System::Int8(0xa);
static const System::Int8 htGroup = System::Int8(0x14);
static const System::Int8 htClientArea = System::Int8(0x1e);
static const System::Int8 htAvailableItems = System::Int8(0x28);
static const System::Int8 htTreeViewItems = System::Int8(0x32);
static const System::Int8 htBasicItem = System::Int8(0x3c);
static const System::Int8 htSizeHandle = System::Int8(0x46);
static const System::Int8 dxLayoutItemControlDefaultMinHeight = System::Int8(0x14);
static const System::Int8 dxLayoutItemControlDefaultMinWidth = System::Int8(0x14);
static const System::Int8 dxLayoutItemMinSize = System::Int8(0x5);
static const System::Int8 dxLayoutVersion = System::Int8(0x3);
#define dxDefaultLayoutCustomizeFormMenuItems (System::Set<TdxLayoutCustomizeFormMenuItem, TdxLayoutCustomizeFormMenuItem::cfmiAlignHorz, TdxLayoutCustomizeFormMenuItem::cfmiGrouping> () << TdxLayoutCustomizeFormMenuItem::cfmiAlignHorz << TdxLayoutCustomizeFormMenuItem::cfmiAlignVert << TdxLayoutCustomizeFormMenuItem::cfmiDirection << TdxLayoutCustomizeFormMenuItem::cfmiCaptionLayout << TdxLayoutCustomizeFormMenuItem::cfmiCaptionAlignHorz << TdxLayoutCustomizeFormMenuItem::cfmiCaptionAlignVert << TdxLayoutCustomizeFormMenuItem::cfmiCaption << TdxLayoutCustomizeFormMenuItem::cfmiBorder << TdxLayoutCustomizeFormMenuItem::cfmiExpandButton << TdxLayoutCustomizeFormMenuItem::cfmiGrouping )
extern PACKAGE Dxlayoutselection::TdxLayoutRunTimeSelectionHelperClass dxLayoutRunTimeSelectionHelperClass;
extern PACKAGE void __fastcall dxDrawItemGlyph(Cxgraphics::TcxCanvas* ACanvas, TdxCustomLayoutItem* AItem, const System::Types::TRect &R, Cxgraphics::TcxRotationAngle ARotationAngle);
extern PACKAGE void __fastcall dxLayoutSetItemStates(TdxLayoutContainer* AContainer, bool AUnwrapTabs, bool AActiveTabToTop, bool ASkipEmptyGroups, bool AExpandGroups);
extern PACKAGE void __fastcall dxLayoutStoreItemStates(System::Classes::TList* AList, TdxLayoutContainer* AContainer);
extern PACKAGE void __fastcall dxLayoutRestoreItemStates(System::Classes::TList* AList, TdxLayoutContainer* AContainer);
}	/* namespace Dxlayoutcontainer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTCONTAINER)
using namespace Dxlayoutcontainer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutcontainerHPP
