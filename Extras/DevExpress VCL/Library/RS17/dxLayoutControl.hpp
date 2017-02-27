// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutControl.pas' rev: 24.00 (Win32)

#ifndef DxlayoutcontrolHPP
#define DxlayoutcontrolHPP

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
#include <Data.DB.hpp>	// Pascal unit
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
#include <cxDBEdit.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit
#include <dxLayoutSelection.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutcontrol
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxLayoutControlPainterClass;

typedef System::TMetaClass* TdxLayoutControlViewInfoClass;

class DELPHICLASS TdxLayoutControlPersistent;
class DELPHICLASS TdxCustomLayoutControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCustomLayoutControl* FControl;
	
protected:
	virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TdxLayoutControlPersistent(TdxCustomLayoutControl* AControl);
	__property TdxCustomLayoutControl* Control = {read=FControl};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutControlPersistent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlContainerPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlContainerPainter : public Dxlayoutcontainer::TdxLayoutContainerPainter
{
	typedef Dxlayoutcontainer::TdxLayoutContainerPainter inherited;
	
public:
	/* TdxLayoutContainerPainter.Create */ inline __fastcall virtual TdxLayoutControlContainerPainter(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutContainerPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutControlContainerPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutControlContainerViewInfo;
class PASCALIMPLEMENTATION TdxLayoutControlContainerViewInfo : public Dxlayoutcontainer::TdxLayoutContainerViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutContainerViewInfo inherited;
	
public:
	/* TdxLayoutContainerViewInfo.Create */ inline __fastcall virtual TdxLayoutControlContainerViewInfo(Dxlayoutcontainer::TdxLayoutContainer* AContainer) : Dxlayoutcontainer::TdxLayoutContainerViewInfo(AContainer) { }
	/* TdxLayoutContainerViewInfo.Destroy */ inline __fastcall virtual ~TdxLayoutControlContainerViewInfo(void) { }
	
};


class DELPHICLASS TdxLayoutControlContainer;
class PASCALIMPLEMENTATION TdxLayoutControlContainer : public Dxlayoutcontainer::TdxLayoutContainer
{
	typedef Dxlayoutcontainer::TdxLayoutContainer inherited;
	
private:
	TdxCustomLayoutControl* FControl;
	TdxLayoutControlContainerPainter* __fastcall GetPainter(void);
	TdxLayoutControlContainerViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems __fastcall DoGetCustomizationMenuItems(System::Classes::TList* const ASelectedItems);
	virtual Dxlayoutcontainer::TdxLayoutContainerPainterClass __fastcall GetPainterClass(void);
	virtual Dxlayoutcontainer::TdxLayoutContainerViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall GetItemStoredCustomProperties(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, System::Classes::TStrings* AProperties);
	virtual void __fastcall GetItemStoredCustomPropertyValue(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetItemStoredCustomPropertyValue(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall CanGetHitTest(const System::Types::TPoint &P);
	virtual bool __fastcall CanRestore(void);
	virtual void __fastcall Restore(void);
	virtual void __fastcall SizeAdjustment(void);
	virtual void __fastcall Store(void);
	virtual bool __fastcall StoringSupports(void);
	virtual Dxlayoutselection::TdxControlsDesignSelectorHelper* __fastcall CreateCustomizationControlHelper(Dxlayoutcontainer::TdxLayoutItem* AItem);
	virtual void __fastcall CustomizationChanged(void);
	virtual void __fastcall CustomizeFormPostUpdate(Dxlayoutcontainer::TdxLayoutCustomizeFormUpdateTypes AUpdateTypes);
	virtual void __fastcall PostBuildSelectionLayer(void);
	virtual void __fastcall PostInvalidateSelectionLayer(const System::Types::TRect &R);
	virtual void __fastcall PostPlaceControls(void);
	virtual bool __fastcall CanProcessKeyboard(void);
	virtual bool __fastcall CanUpdate(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual System::Classes::TComponent* __fastcall GetItemsOwner(void);
	virtual Cxcontrols::TcxControl* __fastcall GetItemsParent(void);
	virtual System::Classes::TComponent* __fastcall GetItemsParentComponent(void);
	virtual System::Types::TPoint __fastcall GetScrollOffset(void);
	virtual Dxlayoutselection::TdxLayoutRunTimeSelectionHelperClass __fastcall GetSelectionHelperClass(void);
	virtual bool __fastcall HasBackground(void);
	virtual bool __fastcall IsAutoControlAlignment(void);
	virtual bool __fastcall IsAutoControlTabOrders(void);
	virtual bool __fastcall IsFocusControlOnItemCaptionClick(void);
	virtual bool __fastcall IsShowLockedGroupChildren(void);
	virtual bool __fastcall IsSizableHorz(void);
	virtual bool __fastcall IsSizableVert(void);
	virtual void __fastcall MakeVisible(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	virtual Vcl::Graphics::TFont* __fastcall GetBoldFont(void);
	virtual Vcl::Graphics::TFont* __fastcall GetDefaultFont(void);
	virtual void __fastcall InitializeSubControlsCxLookAndFeel(void);
	virtual void __stdcall LayoutLookAndFeelUserChanged(void);
	__property TdxLayoutControlContainerPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TdxLayoutControlContainer(TdxCustomLayoutControl* AControl);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual bool __fastcall CanDragAndDrop(void);
	virtual void __fastcall FinishDragAndDrop(bool Accepted);
	virtual void __fastcall Modified(void);
	__property TdxCustomLayoutControl* Control = {read=FControl};
	__property TdxLayoutControlContainerViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxLayoutContainer.Destroy */ inline __fastcall virtual ~TdxLayoutControlContainer(void) { }
	
};


typedef System::TMetaClass* TdxLayoutControlContainerClass;

class DELPHICLASS TdxStoringOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStoringOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FIniFileName;
	System::UnicodeString FRegistryPath;
	bool FStoreToIniFile;
	bool FStoreToRegistry;
	
protected:
	bool __fastcall CanStoreToIniFile(void);
	bool __fastcall CanStoreToRegistry(void);
	bool __fastcall CanRestoreFromIniFile(void);
	bool __fastcall CanRestoreFromRegistry(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString IniFileName = {read=FIniFileName, write=FIniFileName};
	__property System::UnicodeString RegistryPath = {read=FRegistryPath, write=FRegistryPath};
	__property bool StoreToIniFile = {read=FStoreToIniFile, write=FStoreToIniFile, default=0};
	__property bool StoreToRegistry = {read=FStoreToRegistry, write=FStoreToRegistry, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxStoringOptions(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxStoringOptions(void) : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLayoutItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutItemOptions : public TdxLayoutControlPersistent
{
	typedef TdxLayoutControlPersistent inherited;
	
private:
	bool FAutoControlAreaAlignment;
	bool FAutoControlTabOrders;
	bool FFocusControlOnItemCaptionClick;
	bool FShowLockedGroupChildren;
	bool FSizableHorz;
	bool FSizableVert;
	void __fastcall SetAutoControlAreaAlignment(bool Value);
	void __fastcall SetAutoControlTabOrders(bool Value);
	void __fastcall SetShowLockedGroupChildren(bool Value);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxLayoutItemOptions(TdxCustomLayoutControl* AControl);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AutoControlAreaAlignment = {read=FAutoControlAreaAlignment, write=SetAutoControlAreaAlignment, default=1};
	__property bool AutoControlTabOrders = {read=FAutoControlTabOrders, write=SetAutoControlTabOrders, default=1};
	__property bool FocusControlOnItemCaptionClick = {read=FFocusControlOnItemCaptionClick, write=FFocusControlOnItemCaptionClick, default=0};
	__property bool ShowLockedGroupChildren = {read=FShowLockedGroupChildren, write=SetShowLockedGroupChildren, default=1};
	__property bool SizableHorz = {read=FSizableHorz, write=FSizableHorz, default=0};
	__property bool SizableVert = {read=FSizableVert, write=FSizableVert, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxLayoutItemOptions(void) { }
	
};

#pragma pack(pop)

enum TdxLayoutAutoContentSize : unsigned char { acsWidth, acsHeight };

typedef System::Set<TdxLayoutAutoContentSize, TdxLayoutAutoContentSize::acsWidth, TdxLayoutAutoContentSize::acsHeight>  TdxLayoutAutoContentSizes;

class DELPHICLASS TdxCustomLayoutControlHandler;
class DELPHICLASS TdxLayoutControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomLayoutControlHandler : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TdxCustomLayoutControl* FControl;
	TdxLayoutControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property TdxCustomLayoutControl* Control = {read=FControl};
	__property TdxLayoutControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxCustomLayoutControlHandler(TdxCustomLayoutControl* AControl);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomLayoutControlHandler(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxLayoutControlGetItemStoredPropertiesEvent)(TdxCustomLayoutControl* Sender, Dxlayoutcontainer::TdxCustomLayoutItem* AItem, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TdxLayoutControlGetItemStoredPropertyValueEvent)(TdxCustomLayoutControl* Sender, Dxlayoutcontainer::TdxCustomLayoutItem* AItem, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TdxLayoutControlSetItemStoredPropertyValueEvent)(TdxCustomLayoutControl* Sender, Dxlayoutcontainer::TdxCustomLayoutItem* AItem, const System::UnicodeString AName, const System::Variant &AValue);

typedef void __fastcall (__closure *TdxLayoutControlGetStoredPropertiesEvent)(TdxCustomLayoutControl* Sender, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TdxLayoutControlGetStoredPropertyValueEvent)(TdxCustomLayoutControl* Sender, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TdxLayoutControlSetStoredPropertyValueEvent)(TdxCustomLayoutControl* Sender, const System::UnicodeString AName, const System::Variant &AValue);

typedef void __fastcall (__closure *TdxLayoutGetCustomizationMenuItemsEvent)(System::TObject* Sender, System::Classes::TList* const ASelectedItems, Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems &AMenuItems);

class DELPHICLASS TdxLayoutControlPainter;
class PASCALIMPLEMENTATION TdxCustomLayoutControl : public Cxcontrols::TcxScrollingControl
{
	typedef Cxcontrols::TcxScrollingControl inherited;
	
private:
	Vcl::Graphics::TFont* FBoldFont;
	Dxlayoutcontainer::TdxCustomLayoutHitTest* FDragDropHitTest;
	bool FRightButtonPressed;
	bool FRedrawOnResize;
	TdxLayoutItemOptions* FOptionsItem;
	TdxStoringOptions* FOptionsStoring;
	TdxLayoutControlPainter* FPainter;
	TdxLayoutControlViewInfo* FViewInfo;
	TdxLayoutControlContainer* FContainer;
	bool FIsPopupShown;
	System::Classes::TMemoryStream* FStoredStream;
	System::Classes::TNotifyEvent FOnCustomization;
	TdxLayoutGetCustomizationMenuItemsEvent FOnGetCustomizationMenuItems;
	TdxLayoutControlGetItemStoredPropertiesEvent FOnGetItemStoredProperties;
	TdxLayoutControlGetItemStoredPropertyValueEvent FOnGetItemStoredPropertyValue;
	TdxLayoutControlSetItemStoredPropertyValueEvent FOnSetItemStoredPropertyValue;
	TdxLayoutControlGetStoredPropertiesEvent FOnGetStoredProperties;
	TdxLayoutControlGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	TdxLayoutControlSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	TdxLayoutAutoContentSizes __fastcall GetAutoContentSizes(void);
	System::Types::TRect __fastcall GetContentBounds(void);
	bool __fastcall GetCustomization(void);
	Dxlayoutcontainer::TdxLayoutAvailableItemsViewKind __fastcall GetCustomizeAvailableItemsViewKind(void);
	Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm* __fastcall GetCustomizeForm(void);
	System::Types::TRect __fastcall GetCustomizeFormBounds(void);
	Dxlayoutcontainer::TdxLayoutControlCustomCustomizeFormClass __fastcall GetCustomizeFormClass(void);
	bool __fastcall GetCustomizeFormTabbedView(void);
	bool __fastcall GetHighlightRoot(void);
	bool __fastcall GetIsLayoutLoading(void);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall GetItems(void);
	Dxlayoutcontainer::TdxLayoutDirection __fastcall GetLayoutDirection(void);
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems __fastcall GetMenuItems(void);
	int __fastcall GetOccupiedClientHeight(void);
	int __fastcall GetOccupiedClientWidth(void);
	Dxlayoutcontainer::TdxLayoutImageOptions* __fastcall GetOptionsImage(void);
	bool __fastcall GetShowDesignSelectors(void);
	Dxlayoutcontainer::TdxUndoRedoManager* __fastcall GetUndoRedoManager(void);
	void __fastcall SetAutoContentSizes(TdxLayoutAutoContentSizes Value);
	void __fastcall SetCustomization(bool Value);
	void __fastcall SetCustomizeAvailableItemsViewKind(Dxlayoutcontainer::TdxLayoutAvailableItemsViewKind Value);
	void __fastcall SetCustomizeFormBounds(const System::Types::TRect &AValue);
	void __fastcall SetCustomizeFormClass(Dxlayoutcontainer::TdxLayoutControlCustomCustomizeFormClass AValue);
	void __fastcall SetCustomizeFormTabbedView(bool Value);
	void __fastcall SetHighlightRoot(bool Value);
	void __fastcall SetLayoutDirection(Dxlayoutcontainer::TdxLayoutDirection Value);
	void __fastcall SetLayoutLookAndFeel(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* Value);
	void __fastcall SetMenuItems(Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems Value);
	void __fastcall SetOptionsImage(Dxlayoutcontainer::TdxLayoutImageOptions* Value);
	void __fastcall SetOptionsItem(TdxLayoutItemOptions* Value);
	void __fastcall SetShowDesignSelectors(bool Value);
	bool __fastcall GetAutoControlAlignment(void);
	bool __fastcall GetAutoControlTabOrders(void);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetAbsoluteItem(int Index);
	int __fastcall GetAbsoluteItemCount(void);
	Dxlayoutcontainer::TdxLayoutAlignmentConstraint* __fastcall GetAlignmentConstraint(int Index);
	int __fastcall GetAlignmentConstraintCount(void);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetAvailableItem(int Index);
	int __fastcall GetAvailableItemCount(void);
	void __fastcall SetAutoControlAlignment(bool Value);
	void __fastcall SetAutoControlTabOrders(bool Value);
	void __fastcall SetOptionsStoring(TdxStoringOptions* Value);
	System::UnicodeString __fastcall GetIniFileName(void);
	System::UnicodeString __fastcall GetRegistryPath(void);
	bool __fastcall GetStoreInIniFile(void);
	bool __fastcall GetStoreInRegistry(void);
	void __fastcall SetIniFileName(const System::UnicodeString Value);
	void __fastcall SetRegistryPath(const System::UnicodeString Value);
	void __fastcall SetStoreInIniFile(const bool Value);
	void __fastcall SetStoreInRegistry(const bool Value);
	void __fastcall CreateHandlers(void);
	void __fastcall DestroyHandlers(void);
	void __fastcall ContainerChangedHandler(System::TObject* Sender);
	void __fastcall ContainerSelectionChangedHandler(System::TObject* Sender);
	void __fastcall InitializeSubControlsCxLookAndFeel(void);
	void __fastcall MasterLookAndFeelBeginChangeHandler(System::TObject* Sender);
	void __fastcall MasterLookAndFeelEndChangeHandler(System::TObject* Sender);
	void __fastcall RefreshBoldFont(void);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall CMChildKey(Vcl::Controls::TCMChildKey &Message);
	MESSAGE void __fastcall CMControlChange(Vcl::Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Vcl::Controls::TCMControlListChange &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	MESSAGE void __fastcall CMTabStopChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMPlaceControls(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMBuildSelectionLayer(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMInvalidateSelectionLayer(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMCustomizeFormUpdate(Winapi::Messages::TMessage &Message);
	
protected:
	void __stdcall SelectionChanged(void);
	virtual bool __fastcall CanProcessChildren(void);
	Dxlayoutcontainer::TdxLayoutContainer* __fastcall GetContainer(void);
	bool __fastcall CanGetHitTest(const System::Types::TPoint &P);
	bool __fastcall CanProcessKeyboard(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::Types::TPoint __fastcall GetScrollOffset(void);
	bool __fastcall IsFocusControlOnItemCaptionClick(void);
	bool __fastcall IsShowLockedGroupChildren(void);
	bool __fastcall IsSizableHorz(void);
	bool __fastcall IsSizableVert(void);
	void __fastcall MakeItemVisible(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	void __fastcall PostPlaceControls(void);
	void __fastcall SizeAdjustment(void);
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DoGetCustomizationMenuItems(System::Classes::TList* const ASelectedItems, Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems &AMenuItems);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	virtual void __fastcall SetParentBackground(bool Value);
	virtual void __fastcall WriteState(System::Classes::TWriter* Writer);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall NeedRedrawOnResize(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual void __fastcall LayoutChanged(Cxcontrols::TdxChangeType AType = (Cxcontrols::TdxChangeType)(0x2));
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall IsScrollDataValid(void);
	virtual System::Types::TSize __fastcall GetContentSize(void);
	virtual bool __fastcall NeedsToBringInternalControlsToFront(void);
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall AllowDragAndDropWithoutFocus(void);
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	bool __fastcall CanDragAndDrop(void);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetCxLookAndFeel(void);
	virtual TdxLayoutControlPainterClass __fastcall GetPainterClass(void);
	virtual TdxLayoutControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall CanMultiSelect(void);
	virtual bool __fastcall CanShowSelection(void);
	void __fastcall CustomizeFormPostUpdate(Dxlayoutcontainer::TdxLayoutCustomizeFormUpdateTypes AUpdateTypes);
	virtual void __fastcall DoCustomization(void);
	virtual void __fastcall DoGetItemStoredProperties(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, System::Classes::TStrings* AProperties);
	virtual void __fastcall DoGetItemStoredPropertyValue(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall DoSetItemStoredPropertyValue(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall DoGetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall DoGetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall DoSetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual Dxlayoutcontainer::TdxLayoutAlignmentConstraintClass __fastcall GetAlignmentConstraintClass(void);
	virtual TdxLayoutControlContainerClass __fastcall GetContainerClass(void);
	System::Types::TRect __fastcall GetDesignSelectorRect(void);
	bool __fastcall IsToolSelected(void);
	bool __fastcall IsUpdateLocked(void);
	virtual void __fastcall PostBuildSelectionLayer(void);
	virtual void __fastcall PostInvalidateSelectionLayer(const System::Types::TRect &R);
	bool __fastcall OldLoadFromIniFile(const System::UnicodeString AFileName);
	bool __fastcall OldLoadFromRegistry(const System::UnicodeString ARegistryPath);
	bool __fastcall OldLoadFromStream(System::Classes::TStream* AStream);
	bool __fastcall CreateFieldControls(int X, int Y, System::TObject* ADataSource, System::Classes::TList* AFieldList);
	void __fastcall DoCreateFieldControl(Vcl::Controls::TControl* AControl, Data::Db::TField* AField);
	bool __fastcall NeedCreateCaption(void);
	void __fastcall CancelLastUndo(void);
	void __fastcall SaveToUndo(void);
	void __fastcall CreateBoldFont(void);
	void __fastcall CreateContainer(void);
	void __fastcall CreateOptions(void);
	void __fastcall DestroyBoldFont(void);
	void __fastcall DestroyContainer(void);
	void __fastcall DestroyOptions(void);
	__property Vcl::Graphics::TFont* BoldFont = {read=FBoldFont};
	__property Cxlookandfeels::TcxLookAndFeel* cxLookAndFeel = {read=GetCxLookAndFeel};
	__property bool IsLayoutLoading = {read=GetIsLayoutLoading, nodefault};
	__property Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems MenuItems = {read=GetMenuItems, write=SetMenuItems, nodefault};
	
public:
	__fastcall virtual TdxCustomLayoutControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomLayoutControl(void);
	DYNAMIC void __fastcall BeginDragAndDrop(void);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall Clear(void);
	Dxlayoutcontainer::TdxLayoutAlignmentConstraint* __fastcall CreateAlignmentConstraint(void);
	Dxlayoutcontainer::TdxLayoutItem* __fastcall FindItem(Vcl::Controls::TControl* AControl)/* overload */;
	Dxlayoutcontainer::TdxLayoutItem* __fastcall FindItem(NativeUInt AControlHandle)/* overload */;
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall FindItem(const System::UnicodeString AName)/* overload */;
	Dxlayoutcontainer::TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P)/* overload */;
	Dxlayoutcontainer::TdxCustomLayoutHitTest* __fastcall GetHitTest(int X, int Y)/* overload */;
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(bool ANeedPack = true);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall CreateGroup(Dxlayoutcontainer::TdxLayoutGroupClass AGroupClass = 0x0, Dxlayoutcontainer::TdxLayoutGroup* AParent = (Dxlayoutcontainer::TdxLayoutGroup*)(0x0));
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall CreateItem(Dxlayoutcontainer::TdxCustomLayoutItemClass AItemClass = 0x0, Dxlayoutcontainer::TdxLayoutGroup* AParent = (Dxlayoutcontainer::TdxLayoutGroup*)(0x0));
	Dxlayoutcontainer::TdxLayoutItem* __fastcall CreateItemForControl(Vcl::Controls::TControl* AControl, Dxlayoutcontainer::TdxLayoutGroup* AParent = (Dxlayoutcontainer::TdxLayoutGroup*)(0x0));
	bool __fastcall CanRestore(void);
	void __fastcall Restore(void);
	void __fastcall Store(void);
	void __fastcall LoadFromIniFile(const System::UnicodeString AFileName);
	void __fastcall LoadFromRegistry(const System::UnicodeString ARegistryPath);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToIniFile(const System::UnicodeString AFileName, bool ARecreate = true);
	void __fastcall SaveToRegistry(const System::UnicodeString ARegistryPath, bool ARecreate = true);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property AutoSize = {default=0};
	__property TdxLayoutAutoContentSizes AutoContentSizes = {read=GetAutoContentSizes, write=SetAutoContentSizes, nodefault};
	__property TdxLayoutControlContainer* Container = {read=FContainer};
	__property Dxlayoutcontainer::TdxLayoutDirection LayoutDirection = {read=GetLayoutDirection, write=SetLayoutDirection, nodefault};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LookAndFeel = {read=GetLayoutLookAndFeel, write=SetLayoutLookAndFeel};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel, write=SetLayoutLookAndFeel};
	__property bool RedrawOnResize = {read=FRedrawOnResize, write=FRedrawOnResize, nodefault};
	__property bool Customization = {read=GetCustomization, write=SetCustomization, nodefault};
	__property Dxlayoutcontainer::TdxLayoutAvailableItemsViewKind CustomizeAvailableItemsViewKind = {read=GetCustomizeAvailableItemsViewKind, write=SetCustomizeAvailableItemsViewKind, nodefault};
	__property Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm* CustomizeForm = {read=GetCustomizeForm};
	__property System::Types::TRect CustomizeFormBounds = {read=GetCustomizeFormBounds, write=SetCustomizeFormBounds};
	__property Dxlayoutcontainer::TdxLayoutControlCustomCustomizeFormClass CustomizeFormClass = {read=GetCustomizeFormClass, write=SetCustomizeFormClass};
	__property bool CustomizeFormTabbedView = {read=GetCustomizeFormTabbedView, write=SetCustomizeFormTabbedView, nodefault};
	__property bool ShowDesignSelectors = {read=GetShowDesignSelectors, write=SetShowDesignSelectors, nodefault};
	__property bool HighlightRoot = {read=GetHighlightRoot, write=SetHighlightRoot, nodefault};
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property int OccupiedClientWidth = {read=GetOccupiedClientWidth, nodefault};
	__property int OccupiedClientHeight = {read=GetOccupiedClientHeight, nodefault};
	__property Dxlayoutcontainer::TdxLayoutImageOptions* OptionsImage = {read=GetOptionsImage, write=SetOptionsImage};
	__property TdxLayoutItemOptions* OptionsItem = {read=FOptionsItem, write=SetOptionsItem};
	__property bool AutoControlAlignment = {read=GetAutoControlAlignment, write=SetAutoControlAlignment, default=1};
	__property bool AutoControlTabOrders = {read=GetAutoControlTabOrders, write=SetAutoControlTabOrders, default=1};
	__property int AbsoluteItemCount = {read=GetAbsoluteItemCount, nodefault};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* AbsoluteItems[int Index] = {read=GetAbsoluteItem};
	__property int AvailableItemCount = {read=GetAvailableItemCount, nodefault};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* AvailableItems[int Index] = {read=GetAvailableItem};
	__property int AlignmentConstraintCount = {read=GetAlignmentConstraintCount, nodefault};
	__property Dxlayoutcontainer::TdxLayoutAlignmentConstraint* AlignmentConstraints[int Index] = {read=GetAlignmentConstraint};
	__property Dxlayoutcontainer::TdxLayoutGroup* Items = {read=GetItems};
	__property TdxStoringOptions* OptionsStoring = {read=FOptionsStoring, write=SetOptionsStoring};
	__property System::UnicodeString IniFileName = {read=GetIniFileName, write=SetIniFileName};
	__property System::UnicodeString RegistryPath = {read=GetRegistryPath, write=SetRegistryPath};
	__property bool StoreInIniFile = {read=GetStoreInIniFile, write=SetStoreInIniFile, nodefault};
	__property bool StoreInRegistry = {read=GetStoreInRegistry, write=SetStoreInRegistry, nodefault};
	__property Dxlayoutcontainer::TdxUndoRedoManager* UndoRedoManager = {read=GetUndoRedoManager};
	__property TdxLayoutControlPainter* Painter = {read=FPainter};
	__property TdxLayoutControlViewInfo* ViewInfo = {read=FViewInfo};
	__property System::Classes::TNotifyEvent OnCustomization = {read=FOnCustomization, write=FOnCustomization};
	__property TdxLayoutGetCustomizationMenuItemsEvent OnGetCustomizationMenuItems = {read=FOnGetCustomizationMenuItems, write=FOnGetCustomizationMenuItems};
	__property TdxLayoutControlGetItemStoredPropertiesEvent OnGetItemStoredProperties = {read=FOnGetItemStoredProperties, write=FOnGetItemStoredProperties};
	__property TdxLayoutControlGetItemStoredPropertyValueEvent OnGetItemStoredPropertyValue = {read=FOnGetItemStoredPropertyValue, write=FOnGetItemStoredPropertyValue};
	__property TdxLayoutControlSetItemStoredPropertyValueEvent OnSetItemStoredPropertyValue = {read=FOnSetItemStoredPropertyValue, write=FOnSetItemStoredPropertyValue};
	__property TdxLayoutControlGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=FOnGetStoredProperties};
	__property TdxLayoutControlGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=FOnGetStoredPropertyValue};
	__property TdxLayoutControlSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=FOnSetStoredPropertyValue};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomLayoutControl(HWND ParentWindow) : Cxcontrols::TcxScrollingControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(void){ return Cxcontrols::TcxControl::CanFocusOnClick(); }
	
private:
	void *__IdxLayoutContainer;	/* Dxlayoutcontainer::IdxLayoutContainer */
	void *__IcxEditorFieldLink2;	/* Cxdbedit::IcxEditorFieldLink2 */
	void *__IdxCustomizeControlsHelper;	/* Dxlayoutselection::IdxCustomizeControlsHelper */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IdxLayoutComponent;	/* Dxlayoutcommon::IdxLayoutComponent */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {85310BD8-3D7A-454F-A54B-9898C0AA55A2}
	operator Dxlayoutcontainer::_di_IdxLayoutContainer()
	{
		Dxlayoutcontainer::_di_IdxLayoutContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutcontainer::IdxLayoutContainer*(void) { return (Dxlayoutcontainer::IdxLayoutContainer*)&__IdxLayoutContainer; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4A1B4837-FF36-4408-AF91-D195D16F2BA0}
	operator Cxdbedit::_di_IcxEditorFieldLink2()
	{
		Cxdbedit::_di_IcxEditorFieldLink2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxdbedit::IcxEditorFieldLink2*(void) { return (Cxdbedit::IcxEditorFieldLink2*)&__IcxEditorFieldLink2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {AD2130FB-EDA5-4034-A551-9C26A8DAAE41}
	operator Dxlayoutselection::_di_IdxCustomizeControlsHelper()
	{
		Dxlayoutselection::_di_IdxCustomizeControlsHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutselection::IdxCustomizeControlsHelper*(void) { return (Dxlayoutselection::IdxCustomizeControlsHelper*)&__IdxCustomizeControlsHelper; }
	#endif
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
	// {F31C9078-5732-44D8-9347-3EA7B93837E3}
	operator Dxlayoutcommon::_di_IdxLayoutComponent()
	{
		Dxlayoutcommon::_di_IdxLayoutComponent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutcommon::IdxLayoutComponent*(void) { return (Dxlayoutcommon::IdxLayoutComponent*)&__IdxLayoutComponent; }
	#endif
	
};


class DELPHICLASS TdxLayoutControl;
class PASCALIMPLEMENTATION TdxLayoutControl : public TdxCustomLayoutControl
{
	typedef TdxCustomLayoutControl inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BorderWidth = {default=0};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property FocusOnClick = {default=1};
	__property Font;
	__property MenuItems = {default=1023};
	__property ParentBackground = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property AutoContentSizes = {stored=false};
	__property AutoControlAlignment = {stored=false, default=1};
	__property AutoControlTabOrders = {stored=false, default=1};
	__property AutoSize = {default=0};
	__property LookAndFeel = {stored=false};
	__property LayoutLookAndFeel;
	__property RedrawOnResize = {default=1};
	__property CustomizeFormTabbedView = {default=0};
	__property ShowDesignSelectors = {default=1};
	__property HighlightRoot = {default=1};
	__property OptionsImage;
	__property OptionsItem;
	__property OptionsStoring;
	__property IniFileName = {stored=false, default=0};
	__property RegistryPath = {stored=false, default=0};
	__property StoreInIniFile = {stored=false};
	__property StoreInRegistry = {stored=false};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnCustomization;
	__property OnGetCustomizationMenuItems;
	__property OnGetItemStoredProperties;
	__property OnGetItemStoredPropertyValue;
	__property OnSetItemStoredPropertyValue;
	__property OnGetStoredProperties;
	__property OnGetStoredPropertyValue;
	__property OnSetStoredPropertyValue;
public:
	/* TdxCustomLayoutControl.Create */ inline __fastcall virtual TdxLayoutControl(System::Classes::TComponent* AOwner) : TdxCustomLayoutControl(AOwner) { }
	/* TdxCustomLayoutControl.Destroy */ inline __fastcall virtual ~TdxLayoutControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLayoutControl(HWND ParentWindow) : TdxCustomLayoutControl(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlPainter : public TdxCustomLayoutControlHandler
{
	typedef TdxCustomLayoutControlHandler inherited;
	
protected:
	virtual Cxgraphics::TcxCanvas* __fastcall GetInternalCanvas(void);
	void __fastcall MakeCanvasClipped(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawDesignSelector(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawItems(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawDesignFeatures(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxgraphics::TcxCanvas* InternalCanvas = {read=GetInternalCanvas};
	
public:
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual void __fastcall Paint(void);
public:
	/* TdxCustomLayoutControlHandler.Create */ inline __fastcall virtual TdxLayoutControlPainter(TdxCustomLayoutControl* AControl) : TdxCustomLayoutControlHandler(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLayoutControlPainter(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLayoutControlViewInfo : public TdxCustomLayoutControlHandler
{
	typedef TdxCustomLayoutControlHandler inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	TdxLayoutControlContainerViewInfo* __fastcall GetContainerViewInfo(void);
	int __fastcall GetContentHeight(void);
	int __fastcall GetContentWidth(void);
	Dxlayoutcontainer::TdxLayoutGroupViewInfo* __fastcall GetItemsViewInfo(void);
	Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	bool __fastcall GetIsValid(void);
	
protected:
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(void);
	void __fastcall RecreateViewInfos(void);
	virtual void __fastcall AlignItems(void);
	virtual void __fastcall AutoAlignControls(void);
	virtual void __fastcall CalculateItemsViewInfo(void);
	virtual bool __fastcall GetIsTransparent(void);
	bool __fastcall HasBackground(void);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool EraseBackground);
	bool __fastcall IsCustomization(void);
	virtual void __fastcall PrepareData(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property TdxLayoutControlContainerViewInfo* ContainerViewInfo = {read=GetContainerViewInfo};
	__property bool IsTransparent = {read=GetIsTransparent, nodefault};
	__property bool IsValid = {read=GetIsValid, nodefault};
	
public:
	__fastcall virtual TdxLayoutControlViewInfo(TdxCustomLayoutControl* AControl);
	__fastcall virtual ~TdxLayoutControlViewInfo(void);
	virtual void __fastcall Calculate(void);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall GetItemWithMouse(const System::Types::TPoint &P);
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property int ContentHeight = {read=GetContentHeight, nodefault};
	__property int ContentWidth = {read=GetContentWidth, nodefault};
	__property Dxlayoutcontainer::TdxLayoutGroupViewInfo* ItemsViewInfo = {read=GetItemsViewInfo};
	__property Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Dxlayoutselection::TdxLayoutRunTimeSelectionHelperClass dxLayoutDesignTimeSelectionHelperClass;
}	/* namespace Dxlayoutcontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTCONTROL)
using namespace Dxlayoutcontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutcontrolHPP
