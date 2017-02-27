// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarCollns.pas' rev: 24.00 (Win64)

#ifndef DxnavbarcollnsHPP
#define DxnavbarcollnsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Themes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Actions.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarcollns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarItemLink;
class DELPHICLASS TdxNavBarItem;
class DELPHICLASS TdxNavBarGroup;
class PASCALIMPLEMENTATION TdxNavBarItemLink : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	NativeInt FData;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FIAccessibilityHelper;
	TdxNavBarItem* FItem;
	TdxNavBarGroup* __fastcall GetGroup(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	void __fastcall SetSelected(bool Value);
	
protected:
	void __fastcall InitiateAction(void);
	bool __fastcall IsAncestorEqual(TdxNavBarItemLink* AItemLink);
	
public:
	__fastcall virtual TdxNavBarItemLink(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxNavBarItemLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall CanSelect(void);
	bool __fastcall IsSelected(void);
	__property NativeInt Data = {read=FData, write=FData};
	__property TdxNavBarGroup* Group = {read=GetGroup};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property bool Selected = {read=IsSelected, write=SetSelected, nodefault};
	
__published:
	__property TdxNavBarItem* Item = {read=FItem, write=FItem};
};


class DELPHICLASS TdxNavBarItemLinks;
class PASCALIMPLEMENTATION TdxNavBarItemLinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxNavBarItemLink* operator[](int Index) { return Items[Index]; }
	
private:
	TdxNavBarGroup* FGroup;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall IsAncestorEqual(TdxNavBarItemLinks* AItemLinks);
	HIDESBASE TdxNavBarItemLink* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxNavBarItemLink* Value);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TdxNavBarItemLinks(TdxNavBarGroup* AGroup);
	HIDESBASE TdxNavBarItemLink* __fastcall Add(void);
	__property TdxNavBarGroup* Group = {read=FGroup};
	__property TdxNavBarItemLink* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxNavBarItemLinks(void) { }
	
};


enum TdxNavBarGroupControlState : unsigned char { gcsOverSizeGrip };

typedef System::Set<TdxNavBarGroupControlState, TdxNavBarGroupControlState::gcsOverSizeGrip, TdxNavBarGroupControlState::gcsOverSizeGrip>  TdxNavBarGroupControlStates;

class DELPHICLASS TdxNavBarGroupControl;
class PASCALIMPLEMENTATION TdxNavBarGroupControl : public Vcl::Extctrls::TCustomPanel
{
	typedef Vcl::Extctrls::TCustomPanel inherited;
	
private:
	TdxNavBarGroupControlStates FInternalState;
	TdxNavBarGroup* FGroup;
	int FGroupIndex;
	System::Uitypes::TCursor FOriginalCursor;
	int FOriginalHeight;
	int FMinHeight;
	int FUpdateLock;
	bool FUseStyle;
	Vcl::Controls::TControl* __fastcall GetInternalNavBar(void);
	void __fastcall SetOriginalHeight(const int Value);
	void __fastcall SetUseStyle(const bool Value);
	System::Types::TRect __fastcall SizeGripRect(void);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	bool __fastcall GetMouseOverSizeGrip(void);
	void __fastcall SetMouseOverSizeGrip(bool AValue);
	__property bool MouseOverSizeGrip = {read=GetMouseOverSizeGrip, write=SetMouseOverSizeGrip, nodefault};
	
protected:
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ReadOriginalHeight(System::Classes::TReader* Reader);
	void __fastcall ReadGroupIndex(System::Classes::TReader* Reader);
	virtual void __fastcall RequestAlign(void);
	void __fastcall WriteOriginalHeight(System::Classes::TWriter* Writer);
	void __fastcall WriteGroupIndex(System::Classes::TWriter* Writer);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall Paint(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall UpdateGroup(void);
	
public:
	__fastcall virtual TdxNavBarGroupControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxNavBarGroupControl(void);
	virtual void __fastcall AdjustControl(System::Types::TRect &ARect, bool AVisible);
	void __fastcall BeginResize(Vcl::Controls::TControl* AControl, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual void __fastcall ConstrainedResize(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
	void __fastcall DrawSizeGrip(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	int __fastcall GetMinHeight(void);
	System::Types::TRect __fastcall GetSizeGripRect(Vcl::Controls::TControl* AControl);
	bool __fastcall IsOnPopupControl(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property int OriginalHeight = {read=FOriginalHeight, write=SetOriginalHeight, nodefault};
	__property TdxNavBarGroup* Group = {read=FGroup, write=FGroup};
	
__published:
	__property Alignment = {default=2};
	__property BiDiMode;
	__property Caption = {default=0};
	__property Color = {default=-16777201};
	__property Font;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property bool UseStyle = {read=FUseStyle, write=SetUseStyle, default=0};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnEnter;
	__property OnExit;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxNavBarGroupControl(HWND ParentWindow) : Vcl::Extctrls::TCustomPanel(ParentWindow) { }
	
};


class DELPHICLASS TdxNavBarCustomItem;
class PASCALIMPLEMENTATION TdxNavBarCustomItem : public Dxnavbarbase::TdxNavBarComponentCollectionItem
{
	typedef Dxnavbarbase::TdxNavBarComponentCollectionItem inherited;
	
private:
	System::UnicodeString FCaption;
	System::UnicodeString FHint;
	int FLargeImageIndex;
	int FSmallImageIndex;
	System::Classes::TNotifyEvent FOnClick;
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetHint(const System::UnicodeString Value);
	void __fastcall SetLargeImageIndex(const int Value);
	void __fastcall SetSmallImageIndex(const int Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	bool FVisible;
	virtual void __fastcall DoSetVisible(bool Value);
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property System::UnicodeString Hint = {read=FHint, write=SetHint};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	
public:
	__fastcall virtual TdxNavBarCustomItem(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	__property int LargeImageIndex = {read=FLargeImageIndex, write=SetLargeImageIndex, default=-1};
	__property int SmallImageIndex = {read=FSmallImageIndex, write=SetSmallImageIndex, default=-1};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TcxComponentCollectionItem.Destroy */ inline __fastcall virtual ~TdxNavBarCustomItem(void) { }
	
};


class DELPHICLASS TdxNavBarGroupExpansionOptions;
class PASCALIMPLEMENTATION TdxNavBarGroupExpansionOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FExpandable;
	bool FExpanded;
	bool FShowExpandButton;
	TdxNavBarGroup* __fastcall GetGroup(void);
	void __fastcall SetExpanded(bool AValue);
	void __fastcall SetShowExpandButton(bool AValue);
	__property TdxNavBarGroup* Group = {read=GetGroup};
	
public:
	__fastcall virtual TdxNavBarGroupExpansionOptions(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Expandable = {read=FExpandable, write=FExpandable, default=1};
	__property bool Expanded = {read=FExpanded, write=SetExpanded, default=1};
	__property bool ShowExpandButton = {read=FShowExpandButton, write=SetShowExpandButton, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarGroupExpansionOptions(void) { }
	
};


class DELPHICLASS TdxNavBarGroupControlOptions;
class PASCALIMPLEMENTATION TdxNavBarGroupControlOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	bool FAllowControlResizing;
	bool FUseControl;
	bool FShowControl;
	TdxNavBarGroup* __fastcall GetGroup(void);
	void __fastcall SetAllowControlResizing(bool AValue);
	void __fastcall SetShowControl(bool AValue);
	void __fastcall SetUseControl(bool AValue);
	__property TdxNavBarGroup* Group = {read=GetGroup};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AllowControlResizing = {read=FAllowControlResizing, write=SetAllowControlResizing, default=0};
	__property bool ShowControl = {read=FShowControl, write=SetShowControl, default=0};
	__property bool UseControl = {read=FUseControl, write=SetUseControl, default=0};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TdxNavBarGroupControlOptions(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxNavBarGroupControlOptions(void) { }
	
};


class PASCALIMPLEMENTATION TdxNavBarGroup : public TdxNavBarCustomItem
{
	typedef TdxNavBarCustomItem inherited;
	
private:
	Cxclasses::TcxAlignmentVert FAlign;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FCaptionPanelIAccessibilityHelper;
	TdxNavBarGroupControl* FControl;
	Dxnavbarstyles::TdxNavBarGroupCustomStyles* FCustomStyles;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FIAccessibilityHelper;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FLinkContainerIAccessibilityHelper;
	TdxNavBarItemLinks* FLinks;
	bool FLinksUseSmallImages;
	int FLoadedSelectedLinkIndex;
	TdxNavBarGroupControlOptions* FOptionsGroupControl;
	TdxNavBarGroupExpansionOptions* FOptionsExpansion;
	TdxNavBarItemLink* FSelectedLink;
	bool FShowAsIconView;
	bool FShowCaption;
	int FTopVisibleLinkIndex;
	bool FUseRestSpace;
	bool FUseSmallImages;
	bool FVisibleForCustomization;
	System::Classes::TNotifyEvent FOnCollapsed;
	System::Classes::TNotifyEvent FOnExpanded;
	System::Classes::TNotifyEvent FOnSelectedLinkChanged;
	System::Classes::TNotifyEvent FOnTopVisibleLinkChanged;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetCaptionPanelIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetLinkContainerIAccessibilityHelper(void);
	int __fastcall GetLinkCount(void);
	TdxNavBarItemLink* __fastcall GetLink(int Index);
	int __fastcall GetSelectedLinkIndex(void);
	void __fastcall SetAlign(const Cxclasses::TcxTopBottom Value);
	void __fastcall SetLinksUseSmallImages(const bool Value);
	void __fastcall SetSelectedLinkIndex(int Value);
	void __fastcall SetShowAsIconView(const bool Value);
	void __fastcall SetShowCaption(const bool Value);
	void __fastcall SetTopVisibleLinkIndex(int Value);
	void __fastcall SetUseRestSpace(bool Value);
	void __fastcall SetUseSmallImages(const bool Value);
	bool __fastcall GetShowControl(void);
	bool __fastcall GetUseControl(void);
	void __fastcall SetOptionsGroupControl(TdxNavBarGroupControlOptions* const Value);
	void __fastcall SetShowControl(const bool Value);
	void __fastcall SetUseControl(const bool Value);
	bool __fastcall GetExpandable(void);
	bool __fastcall GetExpanded(void);
	bool __fastcall GetShowExpandButton(void);
	void __fastcall SetOptionsExpansion(TdxNavBarGroupExpansionOptions* const Value);
	void __fastcall SetExpandable(const bool Value);
	void __fastcall SetExpanded(const bool Value);
	void __fastcall SetShowExpandButton(const bool Value);
	Dxnavbarstyles::TdxNavBarStyleItem* __fastcall GetCustomStyle(int Index);
	void __fastcall SetCustomStyles(Dxnavbarstyles::TdxNavBarGroupCustomStyles* Value);
	void __fastcall SetCustomStyle(int Index, Dxnavbarstyles::TdxNavBarStyleItem* const Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall DestroyAccessibilityHelpers(void);
	virtual void __fastcall DoSetVisible(bool Value);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetCaptionPanelAccessibilityHelperClass(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetLinkContainerAccessibilityHelperClass(void);
	virtual void __fastcall InitiateActions(void);
	virtual void __fastcall Loaded(void);
	void __fastcall ReadLinks(System::Classes::TReader* Reader);
	void __fastcall WriteLinks(System::Classes::TWriter* Writer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	void __fastcall StyleChanged(System::TObject* Sender, Dxnavbarbase::TdxNavBarChangeType AType);
	DYNAMIC void __fastcall DoExpanded(void);
	DYNAMIC void __fastcall DoCollapsed(void);
	DYNAMIC void __fastcall DoSelectedLinkChanged(void);
	DYNAMIC void __fastcall DoTopVisibleLinkChanged(void);
	virtual void __fastcall CreateControl(void);
	virtual void __fastcall DestroyControl(void);
	void __fastcall LinksChanged(TdxNavBarItemLink* ALink);
	
public:
	__fastcall virtual TdxNavBarGroup(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxNavBarGroup(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual void __fastcall AcceptControl(TdxNavBarGroupControl* AControl);
	virtual void __fastcall ReleaseControl(void);
	void __fastcall ClearLinks(void);
	TdxNavBarItemLink* __fastcall CreateLink(TdxNavBarItem* AItem);
	TdxNavBarItemLink* __fastcall FindLink(TdxNavBarItem* AItem);
	void __fastcall RemoveLink(int AIndex);
	void __fastcall RemoveLinks(TdxNavBarItem* AItem);
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper CaptionPanelIAccessibilityHelper = {read=GetCaptionPanelIAccessibilityHelper};
	__property TdxNavBarGroupControl* Control = {read=FControl};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper LinkContainerIAccessibilityHelper = {read=GetLinkContainerIAccessibilityHelper};
	__property int LinkCount = {read=GetLinkCount, nodefault};
	__property TdxNavBarItemLink* Links[int Index] = {read=GetLink};
	__property TdxNavBarItemLink* SelectedLink = {read=FSelectedLink};
	
__published:
	__property Cxclasses::TcxTopBottom Align = {read=FAlign, write=SetAlign, default=0};
	__property Caption = {default=0};
	__property Hint = {default=0};
	__property LargeImageIndex = {default=-1};
	__property bool LinksUseSmallImages = {read=FLinksUseSmallImages, write=SetLinksUseSmallImages, default=1};
	__property int SelectedLinkIndex = {read=GetSelectedLinkIndex, write=SetSelectedLinkIndex, nodefault};
	__property bool ShowAsIconView = {read=FShowAsIconView, write=SetShowAsIconView, default=0};
	__property bool ShowCaption = {read=FShowCaption, write=SetShowCaption, default=1};
	__property SmallImageIndex = {default=-1};
	__property int TopVisibleLinkIndex = {read=FTopVisibleLinkIndex, write=SetTopVisibleLinkIndex, nodefault};
	__property bool UseRestSpace = {read=FUseRestSpace, write=SetUseRestSpace, default=0};
	__property bool UseSmallImages = {read=FUseSmallImages, write=SetUseSmallImages, default=1};
	__property Visible = {default=1};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=FVisibleForCustomization, default=1};
	__property TdxNavBarGroupControlOptions* OptionsGroupControl = {read=FOptionsGroupControl, write=SetOptionsGroupControl};
	__property bool ShowControl = {read=GetShowControl, write=SetShowControl, stored=false, nodefault};
	__property bool UseControl = {read=GetUseControl, write=SetUseControl, stored=false, nodefault};
	__property TdxNavBarGroupExpansionOptions* OptionsExpansion = {read=FOptionsExpansion, write=SetOptionsExpansion};
	__property bool Expandable = {read=GetExpandable, write=SetExpandable, stored=false, nodefault};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, stored=false, nodefault};
	__property bool ShowExpandButton = {read=GetShowExpandButton, write=SetShowExpandButton, stored=false, nodefault};
	__property Dxnavbarstyles::TdxNavBarGroupCustomStyles* CustomStyles = {read=FCustomStyles, write=SetCustomStyles};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleBackground = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=0};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleControl = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=1};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHeader = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=2};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHeaderActive = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=3};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHeaderActiveHotTracked = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=4};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHeaderActivePressed = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=5};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHeaderHotTracked = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=6};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHeaderPressed = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=7};
	__property OnClick;
	__property System::Classes::TNotifyEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property System::Classes::TNotifyEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property System::Classes::TNotifyEvent OnSelectedLinkChanged = {read=FOnSelectedLinkChanged, write=FOnSelectedLinkChanged};
	__property System::Classes::TNotifyEvent OnTopVisibleLinkChanged = {read=FOnTopVisibleLinkChanged, write=FOnTopVisibleLinkChanged};
};


typedef System::TMetaClass* TdxNavBarGroupClass;

typedef void __fastcall (__closure *TdxNavBarLinksChangeEvent)(System::TObject* Sender, TdxNavBarItemLink* ALink);

class DELPHICLASS TdxNavBarCustomItems;
class PASCALIMPLEMENTATION TdxNavBarCustomItems : public Dxnavbarbase::TdxNavBarComponentCollection
{
	typedef Dxnavbarbase::TdxNavBarComponentCollection inherited;
	
protected:
	HIDESBASE TdxNavBarCustomItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxNavBarCustomItem* Value);
	
public:
	HIDESBASE TdxNavBarCustomItem* __fastcall Add(void);
	TdxNavBarCustomItem* __fastcall ItemByCaption(const System::UnicodeString ACaption);
	__property TdxNavBarCustomItem* Items[int Index] = {read=GetItem, write=SetItem};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxNavBarCustomItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Dxnavbarbase::TdxNavBarComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxNavBarCustomItems(void) { }
	
};


class DELPHICLASS TdxNavBarGroups;
class PASCALIMPLEMENTATION TdxNavBarGroups : public TdxNavBarCustomItems
{
	typedef TdxNavBarCustomItems inherited;
	
public:
	TdxNavBarGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TdxNavBarGroup* FJustExpandedGroup;
	TdxNavBarLinksChangeEvent FOnLinksChange;
	
protected:
	HIDESBASE TdxNavBarGroup* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxNavBarGroup* Value);
	DYNAMIC void __fastcall DoLinksChanged(TdxNavBarItemLink* ALink);
	virtual void __fastcall Notify(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	
public:
	HIDESBASE TdxNavBarGroup* __fastcall Add(void);
	virtual void __fastcall InitiateActions(void);
	__property TdxNavBarGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TdxNavBarGroup* JustExpandedGroup = {read=FJustExpandedGroup, write=FJustExpandedGroup};
	__property TdxNavBarLinksChangeEvent OnLinksChange = {read=FOnLinksChange, write=FOnLinksChange};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxNavBarGroups(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : TdxNavBarCustomItems(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxNavBarGroups(void) { }
	
};


class DELPHICLASS TdxNavBarItemActionLink;
class PASCALIMPLEMENTATION TdxNavBarItemActionLink : public Vcl::Actnlist::TActionLink
{
	typedef Vcl::Actnlist::TActionLink inherited;
	
private:
	TdxNavBarItem* FClient;
	
protected:
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHint(const System::UnicodeString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetVisible(bool Value);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TdxNavBarItemActionLink(System::TObject* AClient) : Vcl::Actnlist::TActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TdxNavBarItemActionLink(void) { }
	
};


class DELPHICLASS TdxNavBarCustomGroupItemCalculator;
class PASCALIMPLEMENTATION TdxNavBarCustomGroupItemCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual void __fastcall CalculateBounds(int X, int Y, void *ALinkViewInfo);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarCustomGroupItemCalculator(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarCustomGroupItemCalculator(void) { }
	
};


typedef System::TMetaClass* TdxNavBarCustomGroupItemCalculatorClass;

class PASCALIMPLEMENTATION TdxNavBarItem : public TdxNavBarCustomItem
{
	typedef TdxNavBarCustomItem inherited;
	
private:
	TdxNavBarItemActionLink* FActionLink;
	bool FEnabled;
	Dxnavbarstyles::TdxNavBarItemCustomStyles* FCustomStyles;
	System::Classes::TBasicAction* __fastcall GetAction(void);
	void __fastcall SetAction(System::Classes::TBasicAction* Value);
	void __fastcall SetEnabled(const bool Value);
	Dxnavbarstyles::TdxNavBarStyleItem* __fastcall GetCustomStyle(int Index);
	void __fastcall SetCustomStyles(Dxnavbarstyles::TdxNavBarItemCustomStyles* Value);
	void __fastcall SetCustomStyle(int Index, Dxnavbarstyles::TdxNavBarStyleItem* const Value);
	void __fastcall DoActionChange(System::TObject* Sender);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsVisibleStored(void);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual bool __fastcall CanSelect(void);
	__classmethod virtual TdxNavBarCustomGroupItemCalculatorClass __fastcall GetCalculatorClass();
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	void __fastcall StyleChanged(System::TObject* Sender, Dxnavbarbase::TdxNavBarChangeType AType);
	
public:
	__fastcall virtual TdxNavBarItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxNavBarItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Draw(const void *APainter, const void *ALinkViewInfo);
	void __fastcall RemoveAllLinks(void);
	__property TdxNavBarItemActionLink* ActionLink = {read=FActionLink};
	
__published:
	__property System::Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property Caption = {stored=IsCaptionStored, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, nodefault};
	__property Hint = {stored=IsHintStored, default=0};
	__property LargeImageIndex = {stored=IsImageIndexStored, default=-1};
	__property SmallImageIndex = {stored=IsImageIndexStored, default=-1};
	__property Visible = {stored=IsVisibleStored, default=1};
	__property Dxnavbarstyles::TdxNavBarItemCustomStyles* CustomStyles = {read=FCustomStyles, write=SetCustomStyles};
	__property Dxnavbarstyles::TdxNavBarStyleItem* Style = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=0};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleDisabled = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=1};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StyleHotTracked = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=2};
	__property Dxnavbarstyles::TdxNavBarStyleItem* StylePressed = {read=GetCustomStyle, write=SetCustomStyle, stored=false, index=3};
	__property OnClick;
};


typedef System::TMetaClass* TdxNavBarItemClass;

class DELPHICLASS TdxNavBarItems;
class PASCALIMPLEMENTATION TdxNavBarItems : public TdxNavBarCustomItems
{
	typedef TdxNavBarCustomItems inherited;
	
public:
	TdxNavBarItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TdxNavBarItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxNavBarItem* Value);
	virtual void __fastcall Notify(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	
public:
	HIDESBASE TdxNavBarItem* __fastcall Add(void)/* overload */;
	HIDESBASE TdxNavBarItem* __fastcall Add(TdxNavBarItemClass AItemClass)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxNavBarItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxNavBarItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : TdxNavBarCustomItems(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxNavBarItems(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Types::TPoint __fastcall ClientToParent(Vcl::Controls::TControl* const AControl, const System::Types::TPoint Point, Vcl::Controls::TWinControl* AParent);
}	/* namespace Dxnavbarcollns */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARCOLLNS)
using namespace Dxnavbarcollns;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarcollnsHPP
