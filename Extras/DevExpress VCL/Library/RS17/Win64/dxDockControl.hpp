// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockControl.pas' rev: 24.00 (Win64)

#ifndef DxdockcontrolHPP
#define DxdockcontrolHPP

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
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.AppEvnts.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxDockConsts.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockcontrol
{
//-- type declarations -------------------------------------------------------
enum TdxDockingState : unsigned char { dsDestroyed, dsUndocked, dsHidden, dsDocked, dsFloating };

enum TdxDockingTypeEx : unsigned char { dtClient, dtLeft, dtTop, dtRight, dtBottom, dtNone };

typedef TdxDockingTypeEx TdxDockingType;

typedef System::Set<TdxDockingType, TdxDockingType::dtClient, TdxDockingType::dtBottom>  TdxDockingTypes;

enum TdxDockStyle : unsigned char { dsStandard, dsVS2005 };

enum TdxZoneDirection : unsigned char { zdUndefined, zdVertical, zdHorizontal };

enum TdxZoneKind : unsigned char { zkDocking, zkResizing };

enum TdxAutoHidePosition : unsigned char { ahpLeft, ahpTop, ahpRight, ahpBottom, ahpUndefined };

enum TdxCaptionButton : unsigned char { cbMaximize, cbHide, cbClose };

typedef System::Set<TdxCaptionButton, TdxCaptionButton::cbMaximize, TdxCaptionButton::cbClose>  TdxCaptionButtons;

enum TdxDockingOption : unsigned char { doActivateAfterDocking, doDblClickDocking, doFloatingOnTop, doFreeOnClose, doUndockOnClose, doTabContainerHasCaption, doTabContainerCanClose, doTabContainerCanAutoHide, doSideContainerHasCaption, doSideContainerCanClose, doSideContainerCanAutoHide, doTabContainerCanInSideContainer, doSideContainerCanInTabContainer, doSideContainerCanInSideContainer, doImmediatelyHideOnAutoHide, doHideAutoHideIfActive, doRedrawOnResize, doFillDockingSelection, doUseCaptionAreaToClientDocking };

typedef System::Set<TdxDockingOption, TdxDockingOption::doActivateAfterDocking, TdxDockingOption::doUseCaptionAreaToClientDocking>  TdxDockingOptions;

typedef System::TMetaClass* TdxCustomDockControlClass;

typedef System::TMetaClass* TdxDockControlPainterClass;

typedef System::TMetaClass* TdxContainerDockSiteClass;

typedef System::TMetaClass* TdxSideContainerDockSiteClass;

class DELPHICLASS TdxDockingDragImage;
class PASCALIMPLEMENTATION TdxDockingDragImage : public Cxcontrols::TcxSizeFrame
{
	typedef Cxcontrols::TcxSizeFrame inherited;
	
public:
	/* TcxSizeFrame.Create */ inline __fastcall virtual TdxDockingDragImage(int AFrameWidth) : Cxcontrols::TcxSizeFrame(AFrameWidth) { }
	/* TcxSizeFrame.Destroy */ inline __fastcall virtual ~TdxDockingDragImage(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxDockingDragImage(System::Classes::TComponent* AOwner, int Dummy) : Cxcontrols::TcxSizeFrame(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockingDragImage(HWND ParentWindow) : Cxcontrols::TcxSizeFrame(ParentWindow) { }
	
};


class DELPHICLASS TdxZone;
class DELPHICLASS TdxCustomDockControl;
class PASCALIMPLEMENTATION TdxZone : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxZoneKind FKind;
	TdxCustomDockControl* FOwner;
	int FWidth;
	
protected:
	virtual TdxZoneDirection __fastcall GetDirection(void) = 0 ;
	virtual int __fastcall GetDockIndex(void);
	virtual TdxDockingType __fastcall GetDockType(void) = 0 ;
	virtual System::Types::TRect __fastcall GetRectangle(void) = 0 ;
	virtual int __fastcall GetSelectionFrameWidth(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall CanConstrainedResize(int NewWidth, int NewHeight);
	
public:
	__fastcall TdxZone(TdxCustomDockControl* AOwner, int AWidth, TdxZoneKind AKind);
	virtual bool __fastcall CanDock(TdxCustomDockControl* AControl);
	virtual bool __fastcall CanResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual bool __fastcall DoCanResize(int ANewWidth, int ANewHeight);
	virtual System::Types::TRect __fastcall GetDockingSelection(TdxCustomDockControl* AControl);
	virtual System::Types::TRect __fastcall GetResizingSelection(System::Types::TPoint pt);
	virtual bool __fastcall IsZonePoint(const System::Types::TPoint pt);
	virtual void __fastcall DoDock(TdxCustomDockControl* AControl);
	virtual void __fastcall DoResize(System::Types::TPoint StartPoint, System::Types::TPoint EndPoint);
	virtual void __fastcall DrawResizingSelection(HDC DC, System::Types::TPoint pt);
	virtual void __fastcall PrepareSelectionRegion(Cxgraphics::TcxRegion* ARegion, TdxCustomDockControl* AControl, const System::Types::TRect &ARect);
	__classmethod virtual bool __fastcall ValidateDockZone(TdxCustomDockControl* AOwner, TdxCustomDockControl* AControl);
	__classmethod virtual bool __fastcall ValidateResizeZone(TdxCustomDockControl* AOwner, TdxCustomDockControl* AControl);
	__property TdxZoneDirection Direction = {read=GetDirection, nodefault};
	__property TdxDockingType DockType = {read=GetDockType, nodefault};
	__property int DockIndex = {read=GetDockIndex, nodefault};
	__property TdxZoneKind Kind = {read=FKind, nodefault};
	__property TdxCustomDockControl* Owner = {read=FOwner};
	__property System::Types::TRect Rectangle = {read=GetRectangle};
	__property int SelectionFrameWidth = {read=GetSelectionFrameWidth, nodefault};
	__property int Width = {read=GetWidth, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxZone(void) { }
	
};


typedef System::TMetaClass* TdxZoneClass;

class DELPHICLASS TdxZoneList;
class PASCALIMPLEMENTATION TdxZoneList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxZone* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxZone* __fastcall GetItem(int Index);
	
public:
	TdxZone* __fastcall FindZone(TdxCustomDockControl* AOwnerControl, TdxDockingType AType);
	bool __fastcall RegisterDockZone(TdxCustomDockControl* AOwnerControl, TdxCustomDockControl* AControl, TdxZoneClass AZoneClass, int AZoneWidth);
	bool __fastcall RegisterResizeZone(TdxCustomDockControl* AOwnerControl, TdxCustomDockControl* AControl, TdxZoneClass AZoneClass, int AZoneWidth);
	void __fastcall RegisterZone(TdxZone* AZone);
	__property TdxZone* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxZoneList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxZoneList(void) { }
	
};


struct DECLSPEC_DRECORD TdxDockPosition
{
public:
	int DockIndex;
	TdxDockingTypeEx DockType;
	int OriginalHeight;
	int OriginalWidth;
	TdxCustomDockControl* Parent;
	TdxCustomDockControl* SiblingAfter;
	TdxCustomDockControl* SiblingBefore;
};


class DELPHICLASS TdxFloatForm;
class DELPHICLASS TdxFloatDockSite;
class PASCALIMPLEMENTATION TdxFloatForm : public Vcl::Forms::TCustomForm
{
	typedef Vcl::Forms::TCustomForm inherited;
	
private:
	bool FCanDesigning;
	bool FCaptionIsDown;
	System::Types::TPoint FCaptionPoint;
	int FClientHeight;
	int FClientWidth;
	TdxFloatDockSite* FDockSite;
	bool FOnTopMost;
	Vcl::Forms::_di_IDesignerHook __fastcall GetActualDesigner(void);
	Vcl::Forms::TCustomForm* __fastcall GetParentForm(void);
	HIDESBASE MESSAGE void __fastcall WMClose(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMMove(Winapi::Messages::TWMMove &Message);
	MESSAGE void __fastcall WMNCLButtonDblClk(Winapi::Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Winapi::Messages::TWMNCHitMessage &Message);
	MESSAGE void __fastcall WMNCLButtonUp(Winapi::Messages::TWMNCHitMessage &Message);
	MESSAGE void __fastcall WMNCMouseMove(Winapi::Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	bool __fastcall CanDesigning(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	void __fastcall InsertDockSite(TdxFloatDockSite* ADockSite);
	void __fastcall RemoveDockSite(void);
	HIDESBASE void __fastcall BringToFront(bool ATopMost);
	
public:
	__fastcall virtual TdxFloatForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxFloatForm(void);
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	void __fastcall ShowWindow(void);
	void __fastcall HideWindow(void);
	__property AutoScroll = {default=0};
	__property BorderStyle = {default=5};
	__property TdxFloatDockSite* DockSite = {read=FDockSite};
	__property FormStyle = {default=0};
	__property Icon;
	__property Vcl::Forms::TCustomForm* ParentForm = {read=GetParentForm};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxFloatForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TCustomForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxFloatForm(HWND ParentWindow) : Vcl::Forms::TCustomForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxFloatFormClass;

typedef void __fastcall (__closure *TdxActivateEvent)(TdxCustomDockControl* Sender, bool Active);

typedef void __fastcall (__closure *TdxCanDockingEvent)(TdxCustomDockControl* Sender, TdxCustomDockControl* Source, TdxZone* Zone, int X, int Y, bool &Accept);

typedef void __fastcall (__closure *TdxCanResizeEvent)(TdxCustomDockControl* Sender, int NewWidth, int NewHeight, bool &Resize);

typedef void __fastcall (__closure *TdxCreateFloatSiteEvent)(TdxCustomDockControl* Sender, TdxFloatDockSite* AFloatSite);

class DELPHICLASS TdxLayoutDockSite;
typedef void __fastcall (__closure *TdxCreateLayoutSiteEvent)(TdxCustomDockControl* Sender, TdxLayoutDockSite* ALayoutSite);

class DELPHICLASS TdxSideContainerDockSite;
typedef void __fastcall (__closure *TdxCreateSideContainerEvent)(TdxCustomDockControl* Sender, TdxSideContainerDockSite* ASideContainer);

class DELPHICLASS TdxTabContainerDockSite;
typedef void __fastcall (__closure *TdxCreateTabContainerEvent)(TdxCustomDockControl* Sender, TdxTabContainerDockSite* ATabContainer);

typedef void __fastcall (__closure *TdxCustomDrawSelectionEvent)(TdxCustomDockControl* Sender, HDC DC, TdxZone* Zone, System::Types::TRect &ARect, bool Erasing, bool &Handled);

typedef void __fastcall (__closure *TdxDockControlCloseQueryEvent)(TdxCustomDockControl* Sender, bool &CanClose);

typedef void __fastcall (__closure *TdxDockControlNotifyEvent)(TdxCustomDockControl* Sender);

typedef void __fastcall (__closure *TdxDockEvent)(TdxCustomDockControl* Sender, TdxCustomDockControl* Site, TdxDockingType ADockType, int AIndex);

typedef void __fastcall (__closure *TdxDockingEvent)(TdxCustomDockControl* Sender, TdxZone* Zone, int X, int Y, bool &Accept);

typedef void __fastcall (__closure *TdxEndDockingEvent)(TdxCustomDockControl* Sender, TdxZone* Zone, int X, int Y);

typedef void __fastcall (__closure *TdxGetAutoHidePositionEvent)(TdxCustomDockControl* Sender, TdxAutoHidePosition &APosition);

typedef void __fastcall (__closure *TdxDockPositionEvent)(TdxCustomDockControl* Sender, TdxDockPosition &APosition);

typedef void __fastcall (__closure *TdxUpdateZonesEvent)(TdxCustomDockControl* Sender, System::Classes::TList* AZones);

typedef void __fastcall (__closure *TdxMakeFloatingEvent)(TdxCustomDockControl* Sender, int X, int Y);

typedef void __fastcall (__closure *TdxResizingEvent)(TdxCustomDockControl* Sender, TdxZone* Zone, int X, int Y);

typedef void __fastcall (__closure *TdxStartDockingEvent)(TdxCustomDockControl* Sender, int X, int Y);

typedef void __fastcall (__closure *TdxUnDockEvent)(TdxCustomDockControl* Sender, TdxCustomDockControl* Site);

enum TdxDockControlInternalState : unsigned char { dcisCreating, dcisDestroying, dcisDestroyed, dcisInternalResizing, dcisFrameChanged, dcisLayoutLoading };

typedef System::Set<TdxDockControlInternalState, TdxDockControlInternalState::dcisCreating, TdxDockControlInternalState::dcisLayoutLoading>  TdxDockControlInternalStates;

class DELPHICLASS TdxDockControlButton;
class DELPHICLASS TdxDockControlButtonsController;
class PASCALIMPLEMENTATION TdxDockControlButton : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxDockControlButtonsController* FController;
	bool FEnabled;
	System::Classes::TNotifyEvent FOnClick;
	bool FVisible;
	TdxCustomDockControl* __fastcall GetDockControl(void);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	
public:
	__fastcall TdxDockControlButton(TdxDockControlButtonsController* AController);
	__fastcall virtual ~TdxDockControlButton(void);
	void __fastcall Click(void);
	bool __fastcall HitTest(const System::Types::TPoint P);
	virtual void __fastcall MouseDown(const System::Types::TPoint P);
	virtual void __fastcall MouseUp(const System::Types::TPoint P);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property TdxDockControlButtonsController* Controller = {read=FController};
	__property TdxCustomDockControl* DockControl = {read=GetDockControl};
	__property bool Enabled = {read=FEnabled, write=FEnabled, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
};


class PASCALIMPLEMENTATION TdxDockControlButtonsController : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxDockControlButton* operator[](int Index) { return Buttons[Index]; }
	
private:
	System::Classes::TList* FButtonsList;
	TdxCustomDockControl* FDockControl;
	TdxDockControlButton* FHotButton;
	TdxDockControlButton* FPressedButton;
	TdxDockControlButton* __fastcall GetButton(int Index);
	int __fastcall GetButtonsCount(void);
	void __fastcall SetHotButton(TdxDockControlButton* AValue);
	void __fastcall SetPressedButton(TdxDockControlButton* AValue);
	
protected:
	void __fastcall Changed(void);
	void __fastcall MouseDown(const System::Types::TPoint P);
	void __fastcall MouseLeave(void);
	void __fastcall MouseMove(const System::Types::TPoint P);
	void __fastcall MouseUp(const System::Types::TPoint P);
	void __fastcall RegisterButton(TdxDockControlButton* AButton);
	void __fastcall UnregisterButton(TdxDockControlButton* AButton);
	__property TdxCustomDockControl* DockControl = {read=FDockControl};
	__property TdxDockControlButton* HotButton = {read=FHotButton, write=SetHotButton};
	__property TdxDockControlButton* PressedButton = {read=FPressedButton, write=SetPressedButton};
	
public:
	__fastcall virtual TdxDockControlButtonsController(TdxCustomDockControl* ADockControl);
	__fastcall virtual ~TdxDockControlButtonsController(void);
	TdxDockControlButton* __fastcall HitTest(const System::Types::TPoint P);
	__property TdxDockControlButton* Buttons[int Index] = {read=GetButton/*, default*/};
	__property int ButtonsCount = {read=GetButtonsCount, nodefault};
};


class DELPHICLASS TdxDockControlPainter;
class DELPHICLASS TdxDockingController;
class DELPHICLASS TdxContainerDockSite;
class DELPHICLASS TdxDockSite;
class DELPHICLASS TdxDockSiteAutoHideContainer;
class PASCALIMPLEMENTATION TdxCustomDockControl : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TdxDockingTypes FAllowDock;
	TdxDockingTypes FAllowDockClients;
	bool FAllowFloating;
	bool FAutoHide;
	TdxAutoHidePosition FAutoHidePosition;
	TdxDockControlButtonsController* FButtonsController;
	Cxgraphics::TcxCanvas* FCanvas;
	TdxCaptionButtons FCaptionButtons;
	System::Types::TPoint FCursorPoint;
	bool FDockable;
	System::Classes::TList* FDockControls;
	System::Types::TPoint FDockingOrigin;
	System::Types::TPoint FDockingPoint;
	TdxZone* FDockingTargetZone;
	TdxDockingTypeEx FDockType;
	TdxZoneList* FDockZones;
	int FImageIndex;
	TdxDockControlInternalStates FInternalState;
	bool FManagerColor;
	bool FManagerFont;
	int FOriginalHeight;
	int FOriginalWidth;
	TdxDockControlPainter* FPainter;
	TdxCustomDockControl* FParentDockControl;
	bool FRecalculateNCNeeded;
	TdxZoneList* FResizeZones;
	System::Types::TPoint FResizingOrigin;
	System::Types::TPoint FResizingPoint;
	TdxZone* FResizingSourceZone;
	Vcl::Controls::TControl* FSavedCaptureControl;
	bool FShowCaption;
	System::Types::TPoint FSourcePoint;
	int FUpdateLayoutLock;
	int FUpdateVisibilityLock;
	TdxDockControlButton* FCaptionCloseButton;
	TdxDockControlButton* FCaptionHideButton;
	TdxDockControlButton* FCaptionMaximizeButton;
	bool FCaptionIsDown;
	System::Types::TRect FCaptionRect;
	System::Types::TRect FCaptionSeparatorRect;
	System::Types::TRect FCaptionTextRect;
	System::Types::TRect FSavedClientRect;
	bool FStoredAutoHide;
	TdxDockPosition FStoredPosition;
	bool FUseDoubleBuffer;
	System::Types::TRect FWindowRect;
	TdxActivateEvent FOnActivate;
	TdxDockControlNotifyEvent FOnAutoHideChanging;
	TdxDockControlNotifyEvent FOnAutoHideChanged;
	TdxCanResizeEvent FOnCanResize;
	TdxDockControlNotifyEvent FOnClose;
	TdxDockControlCloseQueryEvent FOnCloseQuery;
	TdxCanDockingEvent FOnCanDocking;
	TdxCreateFloatSiteEvent FOnCreateFloatSite;
	TdxCreateLayoutSiteEvent FOnCreateLayoutSite;
	TdxCreateSideContainerEvent FOnCreateSideContainer;
	TdxCreateTabContainerEvent FOnCreateTabContainer;
	TdxCustomDrawSelectionEvent FOnCustomDrawDockingSelection;
	TdxCustomDrawSelectionEvent FOnCustomDrawResizingSelection;
	TdxDockEvent FOnDock;
	TdxDockingEvent FOnDocking;
	TdxEndDockingEvent FOnEndDocking;
	TdxResizingEvent FOnEndResizing;
	TdxGetAutoHidePositionEvent FOnGetAutoHidePosition;
	TdxDockControlNotifyEvent FOnLayoutChanged;
	TdxMakeFloatingEvent FOnMakeFloating;
	TdxDockControlNotifyEvent FOnParentChanged;
	TdxDockControlNotifyEvent FOnParentChanging;
	TdxResizingEvent FOnResizing;
	TdxDockPositionEvent FOnRestoreDockPosition;
	TdxStartDockingEvent FOnStartDocking;
	TdxResizingEvent FOnStartResizing;
	TdxDockPositionEvent FOnStoreDockPosition;
	TdxUnDockEvent FOnUnDock;
	TdxUpdateZonesEvent FOnUpdateDockZones;
	TdxUpdateZonesEvent FOnUpdateResizeZones;
	TdxDockControlNotifyEvent FOnVisibleChanged;
	TdxDockControlNotifyEvent FOnVisibleChanging;
	void __fastcall ClearDockType(void);
	void __fastcall ClearChildrenParentDockControl(void);
	bool __fastcall GetActive(void);
	TdxCustomDockControl* __fastcall GetChild(int Index);
	int __fastcall GetChildCount(void);
	TdxDockingController* __fastcall GetController(void);
	int __fastcall GetDockIndex(void);
	System::Types::TRect __fastcall GetDockingRect(void);
	int __fastcall GetDockLevel(void);
	TdxDockingState __fastcall GetDockState(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	TdxDockControlPainter* __fastcall GetPainter(void);
	Vcl::Forms::TCustomForm* __fastcall GetPopupParent(void);
	Cxgraphics::TcxCanvas* __fastcall GetTempCanvas(void);
	TdxCustomDockControl* __fastcall GetValidChild(int Index);
	int __fastcall GetValidChildCount(void);
	HIDESBASE bool __fastcall IsColorStored(void);
	HIDESBASE bool __fastcall IsFontStored(void);
	bool __fastcall IsInternalDestroying(void);
	void __fastcall SetAllowDock(const TdxDockingTypes Value);
	void __fastcall SetAllowDockClients(const TdxDockingTypes Value);
	void __fastcall SetAllowFloating(const bool Value);
	void __fastcall SetAutoHide(const bool Value);
	void __fastcall SetCaptionButtons(TdxCaptionButtons Value);
	void __fastcall SetDockable(const bool Value);
	void __fastcall SetDockType(TdxDockingType Value);
	void __fastcall SetImageIndex(const int Value);
	void __fastcall SetManagerColor(const bool Value);
	void __fastcall SetManagerFont(const bool Value);
	void __fastcall SetParentDockControl(TdxCustomDockControl* Value);
	void __fastcall SetShowCaption(const bool Value);
	void __fastcall SetUseDoubleBuffer(const bool Value);
	void __fastcall ReadAutoHidePosition(System::Classes::TReader* Reader);
	void __fastcall ReadDockType(System::Classes::TReader* Reader);
	void __fastcall ReadDockingType(System::Classes::TReader* Reader);
	void __fastcall ReadOriginalWidth(System::Classes::TReader* Reader);
	void __fastcall ReadOriginalHeight(System::Classes::TReader* Reader);
	void __fastcall WriteAutoHidePosition(System::Classes::TWriter* Writer);
	void __fastcall WriteDockingType(System::Classes::TWriter* Writer);
	void __fastcall WriteOriginalWidth(System::Classes::TWriter* Writer);
	void __fastcall WriteOriginalHeight(System::Classes::TWriter* Writer);
	void __fastcall AddDockControl(TdxCustomDockControl* AControl, int AIndex);
	void __fastcall RemoveDockControl(TdxCustomDockControl* AControl);
	int __fastcall IndexOfControl(TdxCustomDockControl* AControl);
	void __fastcall DoCloseButtonClick(System::TObject* Sender);
	void __fastcall DoHideButtonClick(System::TObject* Sender);
	void __fastcall DoMaximizeButtonClick(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMInvalidate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyUp(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	MESSAGE void __fastcall WMCheckActiveDockControl(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMMove(Winapi::Messages::TWMMove &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	MESSAGE void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	
protected:
	Cxclasses::_di_IcxDesignHelper FDesignHelper;
	virtual void __fastcall MouseLeave(void);
	bool __fastcall PtInCaller(const System::Types::TPoint P);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoEnter(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	DYNAMIC void __fastcall VisibleChanging(void);
	virtual bool __fastcall CanFocusEx(void);
	virtual bool __fastcall IsDockPanel(void);
	bool __fastcall IsAncestor(void);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	void __fastcall CaptureMouse(void);
	void __fastcall ReleaseMouse(void);
	virtual System::Types::TRect __fastcall GetDesignRect(void);
	DYNAMIC bool __fastcall GetDesignHitTest(const System::Types::TPoint APoint, System::Classes::TShiftState AShift);
	bool __fastcall IsSelected(void);
	void __fastcall Modified(void);
	void __fastcall NoSelection(void);
	void __fastcall SelectComponent(System::Classes::TComponent* AComponent);
	System::UnicodeString __fastcall UniqueName(void);
	virtual bool __fastcall CanResizing(int NewWidth, int NewHeight);
	virtual bool __fastcall CanResizeAtPos(System::Types::TPoint pt);
	void __fastcall DoStartResize(System::Types::TPoint pt);
	void __fastcall DoEndResize(System::Types::TPoint pt);
	void __fastcall DoResizing(System::Types::TPoint pt);
	void __fastcall DrawResizingSelection(TdxZone* AZone, System::Types::TPoint pt, bool Erasing);
	virtual void __fastcall StartResize(System::Types::TPoint pt);
	virtual void __fastcall Resizing(System::Types::TPoint pt);
	virtual void __fastcall EndResize(System::Types::TPoint pt, bool Cancel);
	void __fastcall DoUpdateResizeZones(void);
	virtual void __fastcall UpdateControlResizeZones(TdxCustomDockControl* AControl);
	void __fastcall UpdateResizeZones(void);
	virtual bool __fastcall CanUndock(TdxCustomDockControl* AControl);
	TdxCustomDockControl* __fastcall GetDockingTargetControlAtPos(const System::Types::TPoint pt);
	int __fastcall GetDraggingMouseShift(void);
	System::Types::TRect __fastcall GetFloatDockRect(const System::Types::TPoint pt);
	void __fastcall DoStartDocking(const System::Types::TPoint pt);
	void __fastcall DoEndDocking(const System::Types::TPoint pt);
	void __fastcall DoCanDocking(TdxCustomDockControl* Source, System::Types::TPoint pt, TdxZone* TargetZone, bool &Accept);
	void __fastcall DoDocking(System::Types::TPoint pt, TdxZone* TargetZone, bool &Accept);
	void __fastcall SetDockingParams(TdxZone* ADockingTargetZone, const System::Types::TPoint ADockingPoint);
	void __fastcall DrawDockingSelection(TdxZone* AZone, const System::Types::TPoint pt, bool AErasing);
	void __fastcall PrepareSelectionRegion(Cxgraphics::TcxRegion* ARegion, const System::Types::TRect &ARect);
	virtual void __fastcall StartDocking(const System::Types::TPoint APoint);
	virtual void __fastcall Docking(const System::Types::TPoint APoint);
	virtual void __fastcall EndDocking(const System::Types::TPoint APoint, bool Cancel);
	virtual void __fastcall CheckDockRules(void);
	virtual void __fastcall CheckDockClientsRules(void);
	void __fastcall DoUpdateDockZones(void);
	virtual void __fastcall UpdateControlDockZones(TdxCustomDockControl* AControl, int AZoneWidth);
	void __fastcall UpdateDockZones(void);
	void __fastcall DoParentChanged(void);
	void __fastcall DoParentChanging(void);
	virtual void __fastcall UpdateState(void);
	virtual void __fastcall ChildChanged(TdxCustomDockControl* AChild);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DestroyChildLayout(void);
	virtual void __fastcall DestroyLayout(TdxCustomDockControl* AControl);
	void __fastcall DoLayoutChanged(void);
	virtual void __fastcall ExcludeFromDock(void);
	virtual void __fastcall IncludeToDock(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall RemoveFromLayout(void);
	virtual void __fastcall UpdateLayout(void);
	void __fastcall BeginUpdateLayout(void);
	void __fastcall EndUpdateLayout(bool AForceUpdate = true);
	bool __fastcall IsUpdateLayoutLocked(void);
	virtual void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	virtual void __fastcall SaveLayoutToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASection);
	__property int UpdateLayoutLock = {read=FUpdateLayoutLock, nodefault};
	bool __fastcall HasAsParent(TdxCustomDockControl* AControl);
	virtual TdxCustomDockControl* __fastcall GetParentDockControl(void);
	virtual Vcl::Forms::TCustomForm* __fastcall GetParentForm(void);
	virtual bool __fastcall GetParentFormActive(void);
	virtual bool __fastcall GetParentFormVisible(void);
	virtual TdxCustomDockControl* __fastcall GetTopMostDockControl(void);
	virtual void __fastcall AssignLayoutSiteProperties(TdxLayoutDockSite* ASite);
	void __fastcall DoCreateLayoutSite(TdxLayoutDockSite* ASite);
	virtual TdxLayoutDockSite* __fastcall GetLayoutDockSite(void);
	void __fastcall CreateContainerLayout(TdxContainerDockSite* AContainer, TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual TdxContainerDockSite* __fastcall GetContainer(void);
	virtual void __fastcall AssignSideContainerSiteProperties(TdxSideContainerDockSite* ASite);
	virtual bool __fastcall CanAcceptSideContainerItems(TdxSideContainerDockSite* AContainer);
	void __fastcall DoCreateSideContainerSite(TdxSideContainerDockSite* ASite);
	virtual void __fastcall CreateSideContainerLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DoMaximize(void);
	virtual TdxSideContainerDockSite* __fastcall GetSideContainer(void);
	virtual TdxCustomDockControl* __fastcall GetSideContainerItem(void);
	virtual int __fastcall GetSideContainerIndex(void);
	virtual int __fastcall GetMinimizedHeight(void);
	virtual int __fastcall GetMinimizedWidth(void);
	virtual void __fastcall AssignTabContainerSiteProperies(TdxTabContainerDockSite* ASite);
	virtual bool __fastcall CanAcceptTabContainerItems(TdxTabContainerDockSite* AContainer);
	void __fastcall DoCreateTabContainerSite(TdxTabContainerDockSite* ASite);
	virtual void __fastcall CreateTabContainerLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual TdxTabContainerDockSite* __fastcall GetTabContainer(void);
	virtual void __fastcall AutoHideChanged(void);
	void __fastcall DoAutoHideChanged(void);
	void __fastcall DoAutoHideChanging(void);
	virtual TdxAutoHidePosition __fastcall GetControlAutoHidePosition(TdxCustomDockControl* AControl);
	virtual TdxDockSite* __fastcall GetAutoHideHostSite(void);
	virtual TdxDockSiteAutoHideContainer* __fastcall GetAutoHideContainer(void);
	virtual TdxCustomDockControl* __fastcall GetAutoHideControl(void);
	TdxAutoHidePosition __fastcall GetAutoHidePosition(void);
	virtual void __fastcall ChangeAutoHide(void);
	virtual TdxDockSite* __fastcall GetAutoSizeHostSite(void);
	virtual void __fastcall AssignFloatSiteProperties(TdxFloatDockSite* ASite);
	virtual void __fastcall DoCreateFloatSite(TdxFloatDockSite* ASite);
	virtual TdxFloatDockSite* __fastcall GetFloatDockSite(void);
	virtual TdxFloatForm* __fastcall GetFloatForm(void);
	virtual bool __fastcall GetFloatFormActive(void);
	virtual bool __fastcall GetFloatFormVisible(void);
	virtual void __fastcall StoreDockPosition(System::Types::TPoint pt);
	virtual void __fastcall RestoreDockPosition(System::Types::TPoint pt);
	virtual void __fastcall CreateButtons(void);
	virtual void __fastcall DestroyButtons(void);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall AdjustControlBounds(TdxCustomDockControl* AControl);
	void __fastcall SetSize(int AWidth, int AHeight);
	virtual void __fastcall UpdateControlOriginalSize(TdxCustomDockControl* AControl);
	void __fastcall UpdateOriginalSize(void);
	virtual void __fastcall CheckActiveDockControl(void);
	virtual void __fastcall DoActivate(void);
	virtual void __fastcall DoActiveChanged(bool AActive, bool ACallEvent);
	virtual void __fastcall DoClose(void);
	virtual bool __fastcall CanDestroy(void);
	virtual void __fastcall DoDestroy(void);
	virtual void __fastcall ChildVisibilityChanged(TdxCustomDockControl* Sender);
	virtual void __fastcall DoVisibleChanged(void);
	void __fastcall DoVisibleChanging(void);
	void __fastcall BeginUpdateVisibility(void);
	void __fastcall EndUpdateVisibility(void);
	void __fastcall SetVisibility(bool Value);
	virtual void __fastcall UpdateAutoHideControlsVisibility(void);
	virtual void __fastcall UpdateAutoHideHostSiteVisibility(void);
	virtual void __fastcall UpdateLayoutControlsVisibility(void);
	virtual void __fastcall UpdateParentControlsVisibility(void);
	virtual void __fastcall UpdateRelatedControlsVisibility(void);
	__property int UpdateVisibilityLock = {read=FUpdateVisibilityLock, nodefault};
	int __fastcall ControllerAutoHideInterval(void);
	int __fastcall ControllerAutoHideMovingInterval(void);
	int __fastcall ControllerAutoHideMovingSize(void);
	int __fastcall ControllerAutoShowInterval(void);
	System::Uitypes::TColor __fastcall ControllerColor(void);
	int __fastcall ControllerDockZonesWidth(void);
	Vcl::Graphics::TFont* __fastcall ControllerFont(void);
	Vcl::Imglist::TCustomImageList* __fastcall ControllerImages(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall ControllerLookAndFeel(void);
	TdxDockingOptions __fastcall ControllerOptions(void);
	int __fastcall ControllerResizeZonesWidth(void);
	int __fastcall ControllerSelectionFrameWidth(void);
	int __fastcall ControllerTabsScrollInterval(void);
	void __fastcall CheckTempCanvas(System::Types::TRect &ARect);
	virtual void __fastcall NCPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall NCPaintCaption(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall NCPaintCaptionButtons(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Paint(void);
	System::Types::TPoint __fastcall ClientToWindow(const System::Types::TPoint pt);
	System::Types::TPoint __fastcall ScreenToWindow(const System::Types::TPoint pt);
	System::Types::TRect __fastcall WindowRectToClient(const System::Types::TRect &R);
	System::Types::TPoint __fastcall WindowToClient(const System::Types::TPoint pt);
	System::Types::TPoint __fastcall WindowToScreen(const System::Types::TPoint pt);
	virtual void __fastcall CalculateCaptionHorz(System::Types::TRect &ARect);
	virtual void __fastcall CalculateCaptionVert(System::Types::TRect &ARect);
	virtual void __fastcall CalculateNC(System::Types::TRect &ARect);
	HIDESBASE virtual void __fastcall Changed(void);
	virtual void __fastcall DoDrawClient(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawDesignRect(void);
	virtual void __fastcall InvalidateCaptionArea(void);
	void __fastcall InvalidateNC(bool ANeedRecalculate);
	void __fastcall NCChanged(bool AImmediately = false);
	virtual void __fastcall Recalculate(void);
	void __fastcall Redraw(bool AWithChildren);
	void __fastcall BeginUpdateNC(bool ALockRedraw = true);
	void __fastcall EndUpdateNC(void);
	bool __fastcall CanUpdateNC(void);
	bool __fastcall CanCalculateNC(void);
	virtual bool __fastcall HasBorder(void);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasCaptionCloseButton(void);
	virtual bool __fastcall HasCaptionHideButton(void);
	virtual bool __fastcall HasCaptionMaximizeButton(void);
	virtual bool __fastcall HasTabs(void);
	virtual bool __fastcall IsCaptionActive(void);
	virtual bool __fastcall IsCaptionVertical(void);
	bool __fastcall IsCaptionPoint(const System::Types::TPoint pt);
	virtual bool __fastcall NeedInvalidateCaptionArea(void);
	bool __fastcall NeedRedrawOnResize(void);
	__property TdxDockControlPainter* Painter = {read=GetPainter};
	__property bool CaptionIsDown = {read=FCaptionIsDown, nodefault};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Types::TRect CaptionSeparatorRect = {read=FCaptionSeparatorRect};
	__property System::Types::TRect CaptionTextRect = {read=FCaptionTextRect};
	__property System::Types::TRect WindowRect = {read=FWindowRect};
	__property System::Types::TPoint CursorPoint = {read=FCursorPoint, write=FCursorPoint};
	__property System::Types::TPoint DockingOrigin = {read=FDockingOrigin};
	__property System::Types::TPoint DockingPoint = {read=FDockingPoint};
	__property System::Types::TRect DockingRect = {read=GetDockingRect};
	__property TdxZone* DockingTargetZone = {read=FDockingTargetZone};
	__property System::Types::TPoint ResizingOrigin = {read=FResizingOrigin};
	__property System::Types::TPoint ResizingPoint = {read=FResizingPoint};
	__property TdxZone* ResizingSourceZone = {read=FResizingSourceZone};
	__property System::Types::TPoint SourcePoint = {read=FSourcePoint, write=FSourcePoint};
	__property bool StoredAutoHide = {read=FStoredAutoHide, nodefault};
	__property TdxDockPosition StoredPosition = {read=FStoredPosition};
	__property TdxDockControlButtonsController* ButtonsController = {read=FButtonsController};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TdxDockControlButton* CaptionCloseButton = {read=FCaptionCloseButton};
	__property TdxDockControlButton* CaptionHideButton = {read=FCaptionHideButton};
	__property TdxDockControlButton* CaptionMaximizeButton = {read=FCaptionMaximizeButton};
	__property Vcl::Forms::TCustomForm* PopupParent = {read=GetPopupParent};
	__property Cxgraphics::TcxCanvas* TempCanvas = {read=GetTempCanvas};
	
public:
	__fastcall virtual TdxCustomDockControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomDockControl(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall Activate(void);
	virtual bool __fastcall CanActive(void);
	virtual bool __fastcall CanAutoHide(void);
	virtual bool __fastcall CanDock(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	virtual bool __fastcall CanMaximize(void);
	virtual TdxZone* __fastcall GetDockZoneAtPos(TdxCustomDockControl* AControl, System::Types::TPoint APoint);
	virtual TdxZone* __fastcall GetResizeZoneAtPos(System::Types::TPoint APoint);
	virtual bool __fastcall IsNeeded(void);
	virtual bool __fastcall IsValidChild(TdxCustomDockControl* AControl);
	void __fastcall Close(void);
	virtual void __fastcall MakeFloating(void)/* overload */;
	virtual void __fastcall MakeFloating(int XPos, int YPos)/* overload */;
	void __fastcall DockTo(TdxCustomDockControl* AControl, TdxDockingType AType, int AIndex);
	void __fastcall UnDock(void);
	__property bool Active = {read=GetActive, nodefault};
	__property TdxDockingTypes AllowDock = {read=FAllowDock, write=SetAllowDock, default=31};
	__property TdxDockingTypes AllowDockClients = {read=FAllowDockClients, write=SetAllowDockClients, default=31};
	__property bool AllowFloating = {read=FAllowFloating, write=SetAllowFloating, nodefault};
	__property bool AutoHide = {read=FAutoHide, write=SetAutoHide, nodefault};
	__property TdxDockSite* AutoHideHostSite = {read=GetAutoHideHostSite};
	__property TdxDockSiteAutoHideContainer* AutoHideContainer = {read=GetAutoHideContainer};
	__property TdxCustomDockControl* AutoHideControl = {read=GetAutoHideControl};
	__property TdxAutoHidePosition AutoHidePosition = {read=FAutoHidePosition, nodefault};
	__property TdxDockSite* AutoSizeHostSite = {read=GetAutoSizeHostSite};
	__property Caption = {default=0};
	__property TdxCaptionButtons CaptionButtons = {read=FCaptionButtons, write=SetCaptionButtons, default=7};
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property TdxCustomDockControl* Children[int Index] = {read=GetChild};
	__property TdxContainerDockSite* Container = {read=GetContainer};
	__property TdxDockingController* Controller = {read=GetController};
	__property bool Dockable = {read=FDockable, write=SetDockable, default=1};
	__property int DockIndex = {read=GetDockIndex, nodefault};
	__property int DockLevel = {read=GetDockLevel, nodefault};
	__property TdxDockingState DockState = {read=GetDockState, nodefault};
	__property TdxDockingTypeEx DockType = {read=FDockType, nodefault};
	__property TdxZoneList* DockZones = {read=FDockZones};
	__property TdxFloatForm* FloatForm = {read=GetFloatForm};
	__property bool FloatFormActive = {read=GetFloatFormActive, nodefault};
	__property bool FloatFormVisible = {read=GetFloatFormVisible, nodefault};
	__property TdxFloatDockSite* FloatDockSite = {read=GetFloatDockSite};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages};
	__property TdxLayoutDockSite* LayoutDockSite = {read=GetLayoutDockSite};
	__property int OriginalHeight = {read=FOriginalHeight, nodefault};
	__property int OriginalWidth = {read=FOriginalWidth, nodefault};
	__property TdxCustomDockControl* ParentDockControl = {read=GetParentDockControl};
	__property Vcl::Forms::TCustomForm* ParentForm = {read=GetParentForm};
	__property bool ParentFormActive = {read=GetParentFormActive, nodefault};
	__property bool ParentFormVisible = {read=GetParentFormVisible, nodefault};
	__property TdxZoneList* ResizeZones = {read=FResizeZones, write=FResizeZones};
	__property bool ShowCaption = {read=FShowCaption, write=SetShowCaption, default=1};
	__property TdxSideContainerDockSite* SideContainer = {read=GetSideContainer};
	__property TdxCustomDockControl* SideContainerItem = {read=GetSideContainerItem};
	__property int SideContainerIndex = {read=GetSideContainerIndex, nodefault};
	__property TdxTabContainerDockSite* TabContainer = {read=GetTabContainer};
	__property TdxCustomDockControl* TopMostDockControl = {read=GetTopMostDockControl};
	__property bool UseDoubleBuffer = {read=FUseDoubleBuffer, write=SetUseDoubleBuffer, nodefault};
	__property int ValidChildCount = {read=GetValidChildCount, nodefault};
	__property TdxCustomDockControl* ValidChildren[int Index] = {read=GetValidChild};
	__property TdxActivateEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property TdxDockControlNotifyEvent OnAutoHideChanged = {read=FOnAutoHideChanged, write=FOnAutoHideChanged};
	__property TdxDockControlNotifyEvent OnAutoHideChanging = {read=FOnAutoHideChanging, write=FOnAutoHideChanging};
	__property TdxCanDockingEvent OnCanDocking = {read=FOnCanDocking, write=FOnCanDocking};
	__property TdxCanResizeEvent OnCanResize = {read=FOnCanResize, write=FOnCanResize};
	__property TdxDockControlNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property TdxDockControlCloseQueryEvent OnCloseQuery = {read=FOnCloseQuery, write=FOnCloseQuery};
	__property TdxCreateFloatSiteEvent OnCreateFloatSite = {read=FOnCreateFloatSite, write=FOnCreateFloatSite};
	__property TdxCreateLayoutSiteEvent OnCreateLayoutSite = {read=FOnCreateLayoutSite, write=FOnCreateLayoutSite};
	__property TdxCreateSideContainerEvent OnCreateSideContainer = {read=FOnCreateSideContainer, write=FOnCreateSideContainer};
	__property TdxCreateTabContainerEvent OnCreateTabContainer = {read=FOnCreateTabContainer, write=FOnCreateTabContainer};
	__property TdxCustomDrawSelectionEvent OnCustomDrawDockingSelection = {read=FOnCustomDrawDockingSelection, write=FOnCustomDrawDockingSelection};
	__property TdxCustomDrawSelectionEvent OnCustomDrawResizingSelection = {read=FOnCustomDrawResizingSelection, write=FOnCustomDrawResizingSelection};
	__property TdxDockEvent OnDock = {read=FOnDock, write=FOnDock};
	__property TdxDockingEvent OnDocking = {read=FOnDocking, write=FOnDocking};
	__property TdxEndDockingEvent OnEndDocking = {read=FOnEndDocking, write=FOnEndDocking};
	__property TdxResizingEvent OnEndResizing = {read=FOnEndResizing, write=FOnEndResizing};
	__property TdxGetAutoHidePositionEvent OnGetAutoHidePosition = {read=FOnGetAutoHidePosition, write=FOnGetAutoHidePosition};
	__property TdxDockControlNotifyEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	__property TdxMakeFloatingEvent OnMakeFloating = {read=FOnMakeFloating, write=FOnMakeFloating};
	__property OnResize;
	__property TdxResizingEvent OnResizing = {read=FOnResizing, write=FOnResizing};
	__property TdxDockPositionEvent OnRestoreDockPosition = {read=FOnRestoreDockPosition, write=FOnRestoreDockPosition};
	__property TdxStartDockingEvent OnStartDocking = {read=FOnStartDocking, write=FOnStartDocking};
	__property TdxResizingEvent OnStartResizing = {read=FOnStartResizing, write=FOnStartResizing};
	__property TdxDockPositionEvent OnStoreDockPosition = {read=FOnStoreDockPosition, write=FOnStoreDockPosition};
	__property TdxUnDockEvent OnUnDock = {read=FOnUnDock, write=FOnUnDock};
	__property TdxUpdateZonesEvent OnUpdateDockZones = {read=FOnUpdateDockZones, write=FOnUpdateDockZones};
	__property TdxUpdateZonesEvent OnUpdateResizeZones = {read=FOnUpdateResizeZones, write=FOnUpdateResizeZones};
	
__published:
	__property Color = {stored=IsColorStored, default=-16777211};
	__property Font = {stored=IsFontStored};
	__property bool ManagerColor = {read=FManagerColor, write=SetManagerColor, default=1};
	__property bool ManagerFont = {read=FManagerFont, write=SetManagerFont, default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=0};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property TdxDockControlNotifyEvent OnParentChanged = {read=FOnParentChanged, write=FOnParentChanged};
	__property TdxDockControlNotifyEvent OnParentChanging = {read=FOnParentChanging, write=FOnParentChanging};
	__property TdxDockControlNotifyEvent OnVisibleChanged = {read=FOnVisibleChanged, write=FOnVisibleChanged};
	__property TdxDockControlNotifyEvent OnVisibleChanging = {read=FOnVisibleChanging, write=FOnVisibleChanging};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomDockControl(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
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


class DELPHICLASS TdxCustomDockSite;
class PASCALIMPLEMENTATION TdxCustomDockSite : public TdxCustomDockControl
{
	typedef TdxCustomDockControl inherited;
	
protected:
	DYNAMIC void __fastcall ValidateInsert(System::Classes::TComponent* AComponent);
	
public:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	
__published:
	__property AllowDockClients = {default=31};
	__property OnCanDocking;
	__property OnLayoutChanged;
	__property OnUpdateDockZones;
	__property OnUpdateResizeZones;
public:
	/* TdxCustomDockControl.Create */ inline __fastcall virtual TdxCustomDockSite(System::Classes::TComponent* AOwner) : TdxCustomDockControl(AOwner) { }
	/* TdxCustomDockControl.Destroy */ inline __fastcall virtual ~TdxCustomDockSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomDockSite(HWND ParentWindow) : TdxCustomDockControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxLayoutDockSite : public TdxCustomDockSite
{
	typedef TdxCustomDockSite inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall UpdateControlDockZones(TdxCustomDockControl* AControl, int AZoneWidth);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DestroyLayout(TdxCustomDockControl* AControl);
	virtual TdxCustomDockControl* __fastcall GetSiblingDockControl(void);
	virtual bool __fastcall CanDestroy(void);
	
public:
	__fastcall virtual TdxLayoutDockSite(System::Classes::TComponent* AOwner);
	virtual void __fastcall BeforeDestruction(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	__property TdxCustomDockControl* SiblingDockControl = {read=GetSiblingDockControl};
	
__published:
	__property OnCreateLayoutSite;
public:
	/* TdxCustomDockControl.Destroy */ inline __fastcall virtual ~TdxLayoutDockSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLayoutDockSite(HWND ParentWindow) : TdxCustomDockSite(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TdxActiveChildChangeEvent)(TdxContainerDockSite* Sender, TdxCustomDockControl* Child);

class PASCALIMPLEMENTATION TdxContainerDockSite : public TdxCustomDockSite
{
	typedef TdxCustomDockSite inherited;
	
private:
	TdxCustomDockControl* FActiveChild;
	int FActiveChildIndex;
	TdxActiveChildChangeEvent FOnActiveChildChanged;
	int __fastcall GetActiveChildIndex(void);
	void __fastcall SetActiveChildByIndex(int AIndex);
	void __fastcall SetActiveChild(TdxCustomDockControl* Value);
	void __fastcall SetActiveChildIndex(int Value);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DestroyChildLayout(void);
	virtual void __fastcall DestroyLayout(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdateLayout(void);
	virtual void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	virtual void __fastcall SaveLayoutToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASection);
	virtual TdxAutoHidePosition __fastcall GetControlAutoHidePosition(TdxCustomDockControl* AControl);
	virtual void __fastcall ChildVisibilityChanged(TdxCustomDockControl* Sender);
	virtual void __fastcall BeginAdjustBounds(void);
	virtual void __fastcall EndAdjustBounds(void);
	virtual void __fastcall DoActiveChildChanged(TdxCustomDockControl* APrevActiveChild);
	__classmethod virtual TdxDockingType __fastcall GetHeadDockType();
	__classmethod virtual TdxDockingType __fastcall GetTailDockType();
	TdxCustomDockControl* __fastcall GetFirstValidChild(void);
	int __fastcall GetFirstValidChildIndex(void);
	TdxCustomDockControl* __fastcall GetLastValidChild(void);
	int __fastcall GetLastValidChildIndex(void);
	TdxCustomDockControl* __fastcall GetNextValidChild(int AIndex);
	int __fastcall GetNextValidChildIndex(int AIndex);
	TdxCustomDockControl* __fastcall GetPrevValidChild(int AIndex);
	int __fastcall GetPrevValidChildIndex(int AIndex);
	virtual bool __fastcall IsValidActiveChild(TdxCustomDockControl* AControl);
	virtual void __fastcall ValidateActiveChild(int AIndex);
	
public:
	__fastcall virtual TdxContainerDockSite(System::Classes::TComponent* AOwner);
	virtual bool __fastcall CanContainerDockHost(TdxDockingType AType);
	virtual bool __fastcall CanDock(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	__property TdxCustomDockControl* ActiveChild = {read=FActiveChild, write=SetActiveChild};
	
__published:
	__property int ActiveChildIndex = {read=GetActiveChildIndex, write=SetActiveChildIndex, nodefault};
	__property AllowDock = {default=31};
	__property AllowFloating;
	__property TdxActiveChildChangeEvent OnActiveChildChanged = {read=FOnActiveChildChanged, write=FOnActiveChildChanged};
	__property OnCanResize;
	__property OnCreateFloatSite;
	__property OnCustomDrawDockingSelection;
	__property OnCustomDrawResizingSelection;
	__property OnEndResizing;
	__property OnResize;
	__property OnResizing;
	__property OnRestoreDockPosition;
	__property OnStartResizing;
	__property OnStoreDockPosition;
public:
	/* TdxCustomDockControl.Destroy */ inline __fastcall virtual ~TdxContainerDockSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxContainerDockSite(HWND ParentWindow) : TdxCustomDockSite(ParentWindow) { }
	
};


class DELPHICLASS TdxDockingTabControlProperties;
class PASCALIMPLEMENTATION TdxDockingTabControlProperties : public Cxpc::TcxCustomTabControlProperties
{
	typedef Cxpc::TcxCustomTabControlProperties inherited;
	
protected:
	virtual void __fastcall DoCloseTab(int AIndex);
	void __fastcall ReadOldTabsPosition(System::Classes::TReader* AReader);
	void __fastcall ReadOldTabsScroll(System::Classes::TReader* AReader);
	
public:
	__fastcall virtual TdxDockingTabControlProperties(System::Classes::TPersistent* AOwner);
	
__published:
	__property CloseButtonMode = {default=0};
	__property CloseTabWithMiddleClick = {default=0};
	__property HotTrack = {default=0};
	__property ImageBorder = {default=0};
	__property MultiLine = {default=0};
	__property NavigatorPosition = {default=2};
	__property Options = {default=177};
	__property RaggedRight = {default=0};
	__property Rotate = {default=0};
	__property RotatedTabsMaxWidth = {default=0};
	__property Style = {default=0};
	__property TabCaptionAlignment = {default=2};
	__property TabHeight = {default=0};
	__property TabPosition = {default=1};
	__property TabSlants;
	__property TabsScroll = {default=1};
	__property TabWidth = {default=0};
public:
	/* TcxCustomTabControlProperties.Destroy */ inline __fastcall virtual ~TdxDockingTabControlProperties(void) { }
	
};


class DELPHICLASS TdxDockingTabControlViewInfo;
class PASCALIMPLEMENTATION TdxDockingTabControlViewInfo : public Cxpc::TcxCustomTabControlViewInfo
{
	typedef Cxpc::TcxCustomTabControlViewInfo inherited;
	
private:
	Cxpc::TcxPCCustomPainter* FPainter;
	TdxCustomDockControl* __fastcall GetOwner(void);
	System::Types::TRect __fastcall GetPageClientBounds(void);
	HIDESBASE Cxpc::TcxPCCustomPainter* __fastcall GetPainter(void);
	HIDESBASE TdxDockingTabControlProperties* __fastcall GetProperties(void);
	System::Types::TRect __fastcall GetTabBounds(int AIndex);
	Cxpc::TcxTabs* __fastcall GetTabs(void);
	System::Types::TRect __fastcall GetTabsAreaBounds(void);
	
protected:
	System::Types::TPoint __fastcall ClientToWindow(const System::Types::TPoint P);
	System::Types::TRect __fastcall ClientToWindowRect(const System::Types::TRect &R);
	virtual Cxpc::TcxPCPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall HasBorders(void);
	System::Types::TPoint __fastcall WindowToClient(const System::Types::TPoint P);
	
public:
	__fastcall virtual ~TdxDockingTabControlViewInfo(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TComponent* __fastcall GetPopupOwner(void);
	__property TdxCustomDockControl* Owner = {read=GetOwner};
	__property System::Types::TRect PageClientBounds = {read=GetPageClientBounds};
	__property Cxpc::TcxPCCustomPainter* Painter = {read=GetPainter};
	__property TdxDockingTabControlProperties* Properties = {read=GetProperties};
	__property System::Types::TRect TabBounds[int Index] = {read=GetTabBounds};
	__property Cxpc::TcxTabs* Tabs = {read=GetTabs};
	__property System::Types::TRect TabsAreaBounds = {read=GetTabsAreaBounds};
public:
	/* TcxCustomTabControlViewInfo.Create */ inline __fastcall virtual TdxDockingTabControlViewInfo(System::TObject* AOwner) : Cxpc::TcxCustomTabControlViewInfo(AOwner) { }
	
};


class DELPHICLASS TdxDockingTabControlController;
class PASCALIMPLEMENTATION TdxDockingTabControlController : public Cxpc::TcxCustomTabControlController
{
	typedef Cxpc::TcxCustomTabControlController inherited;
	
private:
	int FProcessMouseEventCount;
	int FUpdateCount;
	TdxCustomDockControl* __fastcall GetDockControl(int Index);
	bool __fastcall GetIsProcessingMouseEvent(void);
	bool __fastcall GetIsUpdating(void);
	System::Types::TPoint __fastcall GetMappedToTabsPoint(const System::Types::TPoint P);
	System::Types::TPoint __fastcall GetMappedToTabsSmallPoint(const System::Types::TSmallPoint P);
	TdxCustomDockControl* __fastcall GetOwner(void);
	HIDESBASE TdxDockingTabControlProperties* __fastcall GetProperties(void);
	Cxpc::TcxTabs* __fastcall GetTabs(void);
	HIDESBASE TdxDockingTabControlViewInfo* __fastcall GetViewInfo(void);
	TdxCustomDockControl* __fastcall GetVisibleDockControl(int Index);
	
protected:
	void __fastcall BeginProcessMouseEvent(void);
	void __fastcall EndProcessMouseEvent(void);
	virtual System::Types::TPoint __fastcall GetClientToScreen(const System::Types::TPoint APoint);
	virtual System::Types::TPoint __fastcall GetScreenToClient(const System::Types::TPoint APoint);
	virtual bool __fastcall IsDockable(TdxCustomDockControl* AControl);
	void __fastcall DoChanged(System::TObject* Sender, Cxpc::TcxCustomTabControlPropertiesChangedType AType);
	void __fastcall DoMouseDblClick(Winapi::Messages::TWMMouse &Message);
	void __fastcall DoMouseDown(Winapi::Messages::TWMMouse &Message);
	void __fastcall DoMouseMove(Winapi::Messages::TWMMouse &Message);
	void __fastcall DoMouseUp(Winapi::Messages::TWMMouse &Message);
	void __fastcall DoStyleChanged(System::TObject* Sender);
	virtual void __fastcall DoTabClose(System::TObject* Sender, int ATabIndex);
	virtual void __fastcall DoTabIndexChanged(System::TObject* Sender);
	virtual void __fastcall DoUndock(const System::Types::TPoint APoint, TdxCustomDockControl* ADockControl);
	virtual void __fastcall TabDown(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	void __fastcall TabInfoChanged(TdxCustomDockControl* ADockControl);
	virtual void __fastcall TabUp(int ATabVisibleIndex, System::Classes::TShiftState AShift);
	__property bool IsProcessingMouseEvent = {read=GetIsProcessingMouseEvent, nodefault};
	
public:
	__fastcall virtual TdxDockingTabControlController(System::TObject* AOwner);
	void __fastcall AddTab(TdxCustomDockControl* ADockControl, bool AVisible);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	int __fastcall GetTabIndexAtPoint(const System::Types::TPoint P);
	int __fastcall GetVisibleTabIndexAtPoint(const System::Types::TPoint P);
	void __fastcall RefreshImageList(void);
	void __fastcall RefreshTabInfo(Cxpc::TcxTab* ATab, TdxCustomDockControl* ADockControl);
	__property TdxCustomDockControl* DockControls[int Index] = {read=GetDockControl};
	__property bool IsUpdating = {read=GetIsUpdating, nodefault};
	__property TdxCustomDockControl* Owner = {read=GetOwner};
	__property TdxDockingTabControlProperties* Properties = {read=GetProperties};
	__property Cxpc::TcxTabs* Tabs = {read=GetTabs};
	__property TdxDockingTabControlViewInfo* ViewInfo = {read=GetViewInfo};
	__property TdxCustomDockControl* VisibleDockControls[int Index] = {read=GetVisibleDockControl};
public:
	/* TcxCustomTabControlController.Destroy */ inline __fastcall virtual ~TdxDockingTabControlController(void) { }
	
};


class DELPHICLASS TdxTabContainerDockSiteTabControlProperties;
class PASCALIMPLEMENTATION TdxTabContainerDockSiteTabControlProperties : public TdxDockingTabControlProperties
{
	typedef TdxDockingTabControlProperties inherited;
	
protected:
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	void __fastcall LoadOptions(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	void __fastcall LoadTabSlants(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	void __fastcall SaveOptions(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	void __fastcall SaveTabSlants(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection);
public:
	/* TdxDockingTabControlProperties.Create */ inline __fastcall virtual TdxTabContainerDockSiteTabControlProperties(System::Classes::TPersistent* AOwner) : TdxDockingTabControlProperties(AOwner) { }
	
public:
	/* TcxCustomTabControlProperties.Destroy */ inline __fastcall virtual ~TdxTabContainerDockSiteTabControlProperties(void) { }
	
};


class DELPHICLASS TdxTabContainerDockSiteTabControlController;
class PASCALIMPLEMENTATION TdxTabContainerDockSiteTabControlController : public TdxDockingTabControlController
{
	typedef TdxDockingTabControlController inherited;
	
private:
	TdxCustomDockControl* __fastcall GetActiveChild(void);
	HIDESBASE TdxTabContainerDockSite* __fastcall GetOwner(void);
	void __fastcall SetActiveChild(TdxCustomDockControl* AValue);
	
protected:
	virtual void __fastcall DoTabIndexChanged(System::TObject* Sender);
	
public:
	void __fastcall UpdateActiveTabIndex(void);
	__property TdxCustomDockControl* ActiveChild = {read=GetActiveChild, write=SetActiveChild};
	__property TdxTabContainerDockSite* Owner = {read=GetOwner};
public:
	/* TdxDockingTabControlController.Create */ inline __fastcall virtual TdxTabContainerDockSiteTabControlController(System::TObject* AOwner) : TdxDockingTabControlController(AOwner) { }
	
public:
	/* TcxCustomTabControlController.Destroy */ inline __fastcall virtual ~TdxTabContainerDockSiteTabControlController(void) { }
	
};


class PASCALIMPLEMENTATION TdxTabContainerDockSite : public TdxContainerDockSite
{
	typedef TdxContainerDockSite inherited;
	
private:
	System::Types::TRect FTabControlSuggestedBounds;
	TdxDockingTabControlViewInfo* FTabControlViewInfo;
	TdxTabContainerDockSiteTabControlController* FTabsController;
	TdxTabContainerDockSiteTabControlProperties* FTabsProperties;
	System::Types::TRect __fastcall GetTabRect(int AIndex);
	int __fastcall GetTabRectCount(void);
	System::Types::TRect __fastcall GetTabsRect(void);
	void __fastcall SetTabsProperties(TdxTabContainerDockSiteTabControlProperties* AValue);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Message);
	
protected:
	bool __fastcall CanDrawParentBackground(void);
	HIDESBASE System::Types::TRect __fastcall GetBoundsRect(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	HIDESBASE Cxpc::TcxCustomTabControlController* __fastcall GetController(void);
	Cxcontrols::TcxDragAndDropObject* __fastcall GetDragAndDropObject(void);
	Cxcontrols::TcxDragAndDropState __fastcall GetDragAndDropState(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	HIDESBASE Cxpc::TcxPCCustomPainter* __fastcall GetPainter(void);
	Cxpc::TcxCustomTabControlProperties* __fastcall GetProperties(void);
	Cxpc::TcxCustomTabControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool AEraseBackground);
	bool __fastcall IsEnabled(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsParentBackground(void);
	void __fastcall RequestLayout(void);
	void __fastcall SetModified(void);
	DYNAMIC bool __fastcall GetDesignHitTest(const System::Types::TPoint APoint, System::Classes::TShiftState AShift);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual bool __fastcall CanResizeAtPos(System::Types::TPoint pt);
	virtual void __fastcall UpdateControlDockZones(TdxCustomDockControl* AControl, int AZoneWidth);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DestroyLayout(TdxCustomDockControl* AControl);
	virtual void __fastcall IncludeToDock(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall UpdateLayout(void);
	virtual void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	virtual void __fastcall SaveLayoutToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASection);
	virtual bool __fastcall CanAcceptSideContainerItems(TdxSideContainerDockSite* AContainer);
	virtual bool __fastcall CanAcceptTabContainerItems(TdxTabContainerDockSite* AContainer);
	void __fastcall RefreshTabsList(void);
	virtual void __fastcall ChangeAutoHide(void);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall DoClose(void);
	virtual void __fastcall ChildVisibilityChanged(TdxCustomDockControl* Sender);
	void __fastcall ActivateChild(TdxCustomDockControl* AChild);
	virtual void __fastcall ChildChanged(TdxCustomDockControl* AChild);
	virtual void __fastcall DoActiveChildChanged(TdxCustomDockControl* APrevActiveChild);
	void __fastcall UpdateActiveTab(void);
	void __fastcall UpdateChildrenState(void);
	virtual void __fastcall ValidateActiveChild(int AIndex);
	virtual void __fastcall CalculateNC(System::Types::TRect &ARect);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall NCPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall HasBorder(void);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasTabs(void);
	virtual bool __fastcall IsCaptionActive(void);
	__property int TabRectCount = {read=GetTabRectCount, nodefault};
	__property System::Types::TRect TabsRect = {read=GetTabsRect};
	__property System::Types::TRect TabsRects[int Index] = {read=GetTabRect};
	__property TdxDockingTabControlViewInfo* TabControlViewInfo = {read=FTabControlViewInfo};
	__property TdxTabContainerDockSiteTabControlController* TabsController = {read=FTabsController};
	
public:
	__fastcall virtual TdxTabContainerDockSite(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxTabContainerDockSite(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CanActive(void);
	virtual bool __fastcall CanAutoHide(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	virtual bool __fastcall CanMaximize(void);
	void __fastcall ActivateNextChild(bool AGoForward, bool AGoOnCycle = true);
	
__published:
	__property AutoHide;
	__property CaptionButtons = {default=7};
	__property Dockable = {default=1};
	__property ImageIndex = {default=-1};
	__property ShowCaption = {default=1};
	__property TdxTabContainerDockSiteTabControlProperties* TabsProperties = {read=FTabsProperties, write=SetTabsProperties};
	__property OnActivate;
	__property OnAutoHideChanged;
	__property OnAutoHideChanging;
	__property OnClose;
	__property OnCloseQuery;
	__property OnCreateSideContainer;
	__property OnDock;
	__property OnDocking;
	__property OnEndDocking;
	__property OnGetAutoHidePosition;
	__property OnMakeFloating;
	__property OnStartDocking;
	__property OnUnDock;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTabContainerDockSite(HWND ParentWindow) : TdxContainerDockSite(ParentWindow) { }
	
private:
	void *__IcxTabControl;	/* Cxpc::IcxTabControl */
	
public:
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E29BF582-E8C0-4868-A799-DB4C41AC3BC8}
	operator Cxcontrols::_di_IcxControlComponentState()
	{
		Cxcontrols::_di_IcxControlComponentState intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxTabControl; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxSideContainerDockSite : public TdxContainerDockSite
{
	typedef TdxContainerDockSite inherited;
	
private:
	int FAdjustBoundsLock;
	
protected:
	virtual void __fastcall UpdateControlDockZones(TdxCustomDockControl* AControl, int AZoneWidth);
	virtual void __fastcall IncludeToDock(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall UpdateLayout(void);
	virtual void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	virtual bool __fastcall CanAcceptSideContainerItems(TdxSideContainerDockSite* AContainer);
	virtual bool __fastcall CanAcceptTabContainerItems(TdxTabContainerDockSite* AContainer);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall ChangeAutoHide(void);
	virtual void __fastcall DoClose(void);
	virtual void __fastcall ChildVisibilityChanged(TdxCustomDockControl* Sender);
	virtual void __fastcall ChildChanged(TdxCustomDockControl* AChild);
	virtual void __fastcall DoActiveChildChanged(TdxCustomDockControl* APrevActiveChild);
	bool __fastcall CanChildResize(TdxCustomDockControl* AControl, int ADeltaSize);
	void __fastcall DoChildResize(TdxCustomDockControl* AControl, int ADeltaSize, bool AResizeNextControl = true);
	virtual void __fastcall BeginAdjustBounds(void);
	virtual void __fastcall EndAdjustBounds(void);
	bool __fastcall IsAdjustBoundsLocked(void);
	__property int AdjustBoundsLock = {read=FAdjustBoundsLock, nodefault};
	void __fastcall AdjustChildrenBounds(TdxCustomDockControl* AControl);
	void __fastcall NormalizeChildrenBounds(int ADeltaSize);
	void __fastcall SetChildBounds(TdxCustomDockControl* AControl, int &AWidth, int &AHeight);
	virtual bool __fastcall IsValidActiveChild(TdxCustomDockControl* AControl);
	virtual void __fastcall ValidateActiveChild(int AIndex);
	int __fastcall GetDifferentSize(void);
	virtual int __fastcall GetContainerSize(void) = 0 ;
	virtual int __fastcall GetDimension(int AWidth, int AHeight) = 0 ;
	virtual int __fastcall GetMinSize(int Index) = 0 ;
	virtual int __fastcall GetOriginalSize(int Index) = 0 ;
	virtual int __fastcall GetSize(int Index) = 0 ;
	virtual int __fastcall GetPosition(int Index) = 0 ;
	virtual void __fastcall SetDimension(int &AWidth, int &AHeight, int AValue) = 0 ;
	virtual void __fastcall SetOriginalSize(int Index, const int Value) = 0 ;
	HIDESBASE virtual void __fastcall SetSize(int Index, const int Value) = 0 ;
	virtual void __fastcall SetPosition(int Index, const int Value) = 0 ;
	__property int MinSizes[int Index] = {read=GetMinSize};
	__property int OriginalSizes[int Index] = {read=GetOriginalSize, write=SetOriginalSize};
	__property int Sizes[int Index] = {read=GetSize, write=SetSize};
	__property int Positions[int Index] = {read=GetPosition, write=SetPosition};
	virtual bool __fastcall HasBorder(void);
	virtual bool __fastcall HasCaption(void);
	
public:
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual bool __fastcall CanActive(void);
	virtual bool __fastcall CanAutoHide(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	virtual bool __fastcall CanMaximize(void);
	
__published:
	__property AutoHide;
	__property CaptionButtons = {default=7};
	__property Dockable = {default=1};
	__property ImageIndex = {default=-1};
	__property ShowCaption = {default=1};
	__property OnActivate;
	__property OnAutoHideChanged;
	__property OnAutoHideChanging;
	__property OnClose;
	__property OnCloseQuery;
	__property OnDock;
	__property OnDocking;
	__property OnEndDocking;
	__property OnGetAutoHidePosition;
	__property OnMakeFloating;
	__property OnStartDocking;
	__property OnUnDock;
public:
	/* TdxContainerDockSite.Create */ inline __fastcall virtual TdxSideContainerDockSite(System::Classes::TComponent* AOwner) : TdxContainerDockSite(AOwner) { }
	
public:
	/* TdxCustomDockControl.Destroy */ inline __fastcall virtual ~TdxSideContainerDockSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSideContainerDockSite(HWND ParentWindow) : TdxContainerDockSite(ParentWindow) { }
	
};


class DELPHICLASS TdxHorizContainerDockSite;
class PASCALIMPLEMENTATION TdxHorizContainerDockSite : public TdxSideContainerDockSite
{
	typedef TdxSideContainerDockSite inherited;
	
protected:
	virtual void __fastcall UpdateControlResizeZones(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdateControlOriginalSize(TdxCustomDockControl* AControl);
	__classmethod virtual TdxDockingType __fastcall GetHeadDockType();
	__classmethod virtual TdxDockingType __fastcall GetTailDockType();
	virtual int __fastcall GetContainerSize(void);
	virtual int __fastcall GetDimension(int AWidth, int AHeight);
	virtual int __fastcall GetMinSize(int Index);
	virtual int __fastcall GetOriginalSize(int Index);
	virtual int __fastcall GetSize(int Index);
	virtual int __fastcall GetPosition(int Index);
	virtual void __fastcall SetDimension(int &AWidth, int &AHeight, int AValue);
	virtual void __fastcall SetOriginalSize(int Index, const int Value);
	virtual void __fastcall SetSize(int Index, const int Value);
	virtual void __fastcall SetPosition(int Index, const int Value);
public:
	/* TdxContainerDockSite.Create */ inline __fastcall virtual TdxHorizContainerDockSite(System::Classes::TComponent* AOwner) : TdxSideContainerDockSite(AOwner) { }
	
public:
	/* TdxCustomDockControl.Destroy */ inline __fastcall virtual ~TdxHorizContainerDockSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxHorizContainerDockSite(HWND ParentWindow) : TdxSideContainerDockSite(ParentWindow) { }
	
};


class DELPHICLASS TdxVertContainerDockSite;
class PASCALIMPLEMENTATION TdxVertContainerDockSite : public TdxSideContainerDockSite
{
	typedef TdxSideContainerDockSite inherited;
	
protected:
	virtual void __fastcall UpdateControlResizeZones(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdateControlOriginalSize(TdxCustomDockControl* AControl);
	__classmethod virtual TdxDockingType __fastcall GetHeadDockType();
	__classmethod virtual TdxDockingType __fastcall GetTailDockType();
	virtual int __fastcall GetContainerSize(void);
	virtual int __fastcall GetDimension(int AWidth, int AHeight);
	virtual int __fastcall GetMinSize(int Index);
	virtual int __fastcall GetOriginalSize(int Index);
	virtual int __fastcall GetSize(int Index);
	virtual int __fastcall GetPosition(int Index);
	virtual void __fastcall SetDimension(int &AWidth, int &AHeight, int AValue);
	virtual void __fastcall SetOriginalSize(int Index, const int Value);
	virtual void __fastcall SetSize(int Index, const int Value);
	virtual void __fastcall SetPosition(int Index, const int Value);
public:
	/* TdxContainerDockSite.Create */ inline __fastcall virtual TdxVertContainerDockSite(System::Classes::TComponent* AOwner) : TdxSideContainerDockSite(AOwner) { }
	
public:
	/* TdxCustomDockControl.Destroy */ inline __fastcall virtual ~TdxVertContainerDockSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxVertContainerDockSite(HWND ParentWindow) : TdxSideContainerDockSite(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxDockSiteAutoHideContainer : public Vcl::Controls::TWinControl
{
	typedef Vcl::Controls::TWinControl inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	
public:
	__fastcall virtual TdxDockSiteAutoHideContainer(System::Classes::TComponent* AOwner);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockSiteAutoHideContainer(HWND ParentWindow) : Vcl::Controls::TWinControl(ParentWindow) { }
	/* TWinControl.Destroy */ inline __fastcall virtual ~TdxDockSiteAutoHideContainer(void) { }
	
};


class DELPHICLASS TdxDockSiteHideBarScrollButton;
class PASCALIMPLEMENTATION TdxDockSiteHideBarScrollButton : public TdxDockControlButton
{
	typedef TdxDockControlButton inherited;
	
private:
	int FDirection;
	Cxclasses::TcxTimer* FScrollTimer;
	void __fastcall ScrollingTimerHandler(System::TObject* Sender);
	void __fastcall StartScrollingTimer(void);
	void __fastcall StopScrollingTimer(void);
	
public:
	virtual void __fastcall MouseDown(const System::Types::TPoint P);
	virtual void __fastcall MouseUp(const System::Types::TPoint P);
	__property int Direction = {read=FDirection, write=FDirection, nodefault};
public:
	/* TdxDockControlButton.Create */ inline __fastcall TdxDockSiteHideBarScrollButton(TdxDockControlButtonsController* AController) : TdxDockControlButton(AController) { }
	/* TdxDockControlButton.Destroy */ inline __fastcall virtual ~TdxDockSiteHideBarScrollButton(void) { }
	
};


class DELPHICLASS TdxDockSiteHideBarButtonSection;
class PASCALIMPLEMENTATION TdxDockSiteHideBarButtonSection : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	bool FExpanded;
	TdxCustomDockControl* FDockControl;
	
public:
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxCustomDockControl* DockControl = {read=FDockControl};
	__property bool Expanded = {read=FExpanded, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxDockSiteHideBarButtonSection(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockSiteHideBarButtonSection(void) { }
	
};


class DELPHICLASS TdxDockSiteHideBarButtonSectionList;
class PASCALIMPLEMENTATION TdxDockSiteHideBarButtonSectionList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxDockSiteHideBarButtonSection* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxDockSiteHideBarButtonSection* __fastcall GetItem(int Index);
	
public:
	HIDESBASE TdxDockSiteHideBarButtonSection* __fastcall First(void);
	HIDESBASE TdxDockSiteHideBarButtonSection* __fastcall Last(void);
	__property TdxDockSiteHideBarButtonSection* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxDockSiteHideBarButtonSectionList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxDockSiteHideBarButtonSectionList(void) { }
	
};


class DELPHICLASS TdxDockSiteHideBarButton;
class PASCALIMPLEMENTATION TdxDockSiteHideBarButton : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomDockControl* FDockControl;
	TdxDockSiteHideBarButtonSectionList* FSections;
	System::Types::TRect __fastcall GetBounds(void);
	
public:
	__fastcall virtual TdxDockSiteHideBarButton(TdxCustomDockControl* ADockControl);
	__fastcall virtual ~TdxDockSiteHideBarButton(void);
	void __fastcall AddSection(const System::Types::TRect &ABounds, TdxCustomDockControl* ADockControl, bool AExpanded = true);
	void __fastcall ClearSections(void);
	bool __fastcall HitTest(const System::Types::TPoint P, /* out */ TdxCustomDockControl* &ADockControl);
	void __fastcall Scroll(int dX, int dY);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property TdxCustomDockControl* DockControl = {read=FDockControl};
	__property TdxDockSiteHideBarButtonSectionList* Sections = {read=FSections};
};


class DELPHICLASS TdxDockSiteHideBarButtonsList;
class PASCALIMPLEMENTATION TdxDockSiteHideBarButtonsList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxDockSiteHideBarButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxDockSiteHideBarButton* __fastcall GetItem(int AIndex);
	
public:
	HIDESBASE TdxDockSiteHideBarButton* __fastcall Add(TdxCustomDockControl* ADockControl);
	TdxDockSiteHideBarButtonSectionList* __fastcall GetSections(void);
	int __fastcall IndexOfDockControl(TdxCustomDockControl* ADockControl);
	int __fastcall RemoveDockControl(TdxCustomDockControl* ADockControl);
	void __fastcall Scroll(int dX, int dY);
	__property TdxDockSiteHideBarButton* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxDockSiteHideBarButtonsList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxDockSiteHideBarButtonsList(void) { }
	
};


class DELPHICLASS TdxDockSiteHideBar;
class PASCALIMPLEMENTATION TdxDockSiteHideBar : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxDockSiteHideBarButtonsList* FButtons;
	int FButtonSectionMaxTopIndex;
	int FButtonSectionTopIndex;
	TdxDockSite* FOwner;
	TdxDockSiteHideBarScrollButton* FScrollDownButton;
	TdxDockSiteHideBarScrollButton* FScrollUpButton;
	System::Types::TRect __fastcall GetButtonRect(int Index);
	int __fastcall GetButtonRectCount(void);
	System::Types::TRect __fastcall GetContentRect(void);
	TdxCustomDockControl* __fastcall GetDockControl(int Index);
	int __fastcall GetDockControlCount(void);
	TdxDockControlPainter* __fastcall GetPainter(void);
	bool __fastcall GetVisible(void);
	void __fastcall DoScrollButtonClick(System::TObject* Sender);
	void __fastcall SetButtonSectionTopIndex(int AValue);
	
protected:
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	virtual void __fastcall CalculateBounds(const System::Types::TRect &R) = 0 ;
	virtual void __fastcall CalculateButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton);
	virtual void __fastcall CalculateButtonsPosition(TdxDockSiteHideBarButtonSectionList* ASections) = 0 ;
	virtual int __fastcall CalculateButtonSectionMaxTopIndex(TdxDockSiteHideBarButtonSectionList* ASections) = 0 ;
	virtual void __fastcall CalculateMultiSectionButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton) = 0 ;
	virtual void __fastcall CalculateSingleSectionButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton) = 0 ;
	virtual void __fastcall CalculateScrollButtons(const System::Types::TRect &AButtonsFullRect) = 0 ;
	virtual bool __fastcall CheckHidingFinish(void) = 0 ;
	virtual bool __fastcall CheckShowingFinish(void) = 0 ;
	TdxDockSiteHideBarScrollButton* __fastcall CreateScrollButton(int ADirection);
	virtual int __fastcall GetButtonSectionSize(TdxCustomDockControl* ADockControl, bool AExpanded = true);
	virtual System::Types::TRect __fastcall GetButtonsVisibleRect(void) = 0 ;
	virtual System::Uitypes::TAnchors __fastcall GetContainersAnchors(void) = 0 ;
	virtual System::Types::TRect __fastcall GetContentOffsets(void) = 0 ;
	virtual Vcl::Controls::TAlign __fastcall GetControlsAlign(void) = 0 ;
	int __fastcall GetDefaultImageSize(void);
	int __fastcall GetHideBarHorzInterval(void);
	virtual int __fastcall GetHideBarSize(void) = 0 ;
	int __fastcall GetHideBarVertInterval(void);
	virtual int __fastcall GetImageSize(void) = 0 ;
	virtual TdxAutoHidePosition __fastcall GetPosition(void) = 0 ;
	virtual void __fastcall SetFinalPosition(TdxCustomDockControl* AControl) = 0 ;
	virtual void __fastcall SetInitialPosition(TdxCustomDockControl* AControl) = 0 ;
	virtual void __fastcall UpdatePosition(int ADelta) = 0 ;
	virtual void __fastcall UpdateOwnerAutoSizeBounds(TdxCustomDockControl* AControl) = 0 ;
	virtual TdxCustomDockControl* __fastcall GetControlAtPos(const System::Types::TPoint P, TdxCustomDockControl* &ASubControl);
	int __fastcall IndexOfDockControl(TdxCustomDockControl* AControl);
	virtual void __fastcall CreateAutoHideContainer(TdxCustomDockControl* AControl);
	virtual void __fastcall DestroyAutoHideContainer(TdxCustomDockControl* AControl);
	void __fastcall RegisterDockControl(TdxCustomDockControl* AControl);
	void __fastcall UnregisterDockControl(TdxCustomDockControl* AControl);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property int ButtonRectCount = {read=GetButtonRectCount, nodefault};
	__property TdxDockSiteHideBarButtonsList* Buttons = {read=FButtons};
	__property int ButtonSectionMaxTopIndex = {read=FButtonSectionMaxTopIndex, nodefault};
	__property int ButtonSectionTopIndex = {read=FButtonSectionTopIndex, write=SetButtonSectionTopIndex, nodefault};
	__property System::Types::TRect ButtonsRects[int Index] = {read=GetButtonRect};
	__property System::Types::TRect ButtonsVisibleRect = {read=GetButtonsVisibleRect};
	__property System::Types::TRect ContentRect = {read=GetContentRect};
	__property TdxDockControlPainter* Painter = {read=GetPainter};
	__property TdxDockSiteHideBarScrollButton* ScrollDownButton = {read=FScrollDownButton};
	__property TdxDockSiteHideBarScrollButton* ScrollUpButton = {read=FScrollUpButton};
	
public:
	__fastcall TdxDockSiteHideBar(TdxDockSite* AOwner);
	__fastcall virtual ~TdxDockSiteHideBar(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawButtons(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawScrollButtons(Cxgraphics::TcxCanvas* ACanvas);
	__property int DockControlCount = {read=GetDockControlCount, nodefault};
	__property TdxCustomDockControl* DockControls[int Index] = {read=GetDockControl};
	__property TdxDockSite* Owner = {read=FOwner};
	__property TdxAutoHidePosition Position = {read=GetPosition, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
};


class DELPHICLASS TdxDockSiteLeftHideBar;
class PASCALIMPLEMENTATION TdxDockSiteLeftHideBar : public TdxDockSiteHideBar
{
	typedef TdxDockSiteHideBar inherited;
	
protected:
	virtual void __fastcall CalculateBounds(const System::Types::TRect &R);
	virtual int __fastcall CalculateButtonSectionMaxTopIndex(TdxDockSiteHideBarButtonSectionList* ASections);
	virtual void __fastcall CalculateButtonsPosition(TdxDockSiteHideBarButtonSectionList* ASections);
	virtual void __fastcall CalculateMultiSectionButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton);
	virtual void __fastcall CalculateSingleSectionButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton);
	virtual void __fastcall CalculateScrollButtons(const System::Types::TRect &AButtonsFullRect);
	virtual bool __fastcall CheckHidingFinish(void);
	virtual bool __fastcall CheckShowingFinish(void);
	virtual System::Types::TRect __fastcall GetButtonsVisibleRect(void);
	virtual System::Uitypes::TAnchors __fastcall GetContainersAnchors(void);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual Vcl::Controls::TAlign __fastcall GetControlsAlign(void);
	virtual int __fastcall GetHideBarSize(void);
	virtual int __fastcall GetImageSize(void);
	virtual TdxAutoHidePosition __fastcall GetPosition(void);
	virtual void __fastcall SetFinalPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall SetInitialPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdatePosition(int ADelta);
	virtual void __fastcall UpdateOwnerAutoSizeBounds(TdxCustomDockControl* AControl);
public:
	/* TdxDockSiteHideBar.Create */ inline __fastcall TdxDockSiteLeftHideBar(TdxDockSite* AOwner) : TdxDockSiteHideBar(AOwner) { }
	/* TdxDockSiteHideBar.Destroy */ inline __fastcall virtual ~TdxDockSiteLeftHideBar(void) { }
	
};


class DELPHICLASS TdxDockSiteTopHideBar;
class PASCALIMPLEMENTATION TdxDockSiteTopHideBar : public TdxDockSiteHideBar
{
	typedef TdxDockSiteHideBar inherited;
	
protected:
	virtual void __fastcall CalculateBounds(const System::Types::TRect &R);
	virtual int __fastcall CalculateButtonSectionMaxTopIndex(TdxDockSiteHideBarButtonSectionList* ASections);
	virtual void __fastcall CalculateButtonsPosition(TdxDockSiteHideBarButtonSectionList* ASections);
	virtual void __fastcall CalculateMultiSectionButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton);
	virtual void __fastcall CalculateScrollButtons(const System::Types::TRect &AButtonsFullRect);
	virtual void __fastcall CalculateSingleSectionButton(System::Types::TRect &R, TdxDockSiteHideBarButton* AButton);
	virtual bool __fastcall CheckHidingFinish(void);
	virtual bool __fastcall CheckShowingFinish(void);
	virtual System::Types::TRect __fastcall GetButtonsVisibleRect(void);
	virtual System::Uitypes::TAnchors __fastcall GetContainersAnchors(void);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual Vcl::Controls::TAlign __fastcall GetControlsAlign(void);
	virtual int __fastcall GetHideBarSize(void);
	virtual int __fastcall GetImageSize(void);
	virtual TdxAutoHidePosition __fastcall GetPosition(void);
	virtual void __fastcall SetFinalPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall SetInitialPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdatePosition(int ADelta);
	virtual void __fastcall UpdateOwnerAutoSizeBounds(TdxCustomDockControl* AControl);
public:
	/* TdxDockSiteHideBar.Create */ inline __fastcall TdxDockSiteTopHideBar(TdxDockSite* AOwner) : TdxDockSiteHideBar(AOwner) { }
	/* TdxDockSiteHideBar.Destroy */ inline __fastcall virtual ~TdxDockSiteTopHideBar(void) { }
	
};


class DELPHICLASS TdxDockSiteRightHideBar;
class PASCALIMPLEMENTATION TdxDockSiteRightHideBar : public TdxDockSiteLeftHideBar
{
	typedef TdxDockSiteLeftHideBar inherited;
	
protected:
	virtual void __fastcall CalculateBounds(const System::Types::TRect &R);
	virtual System::Uitypes::TAnchors __fastcall GetContainersAnchors(void);
	virtual Vcl::Controls::TAlign __fastcall GetControlsAlign(void);
	virtual TdxAutoHidePosition __fastcall GetPosition(void);
	virtual void __fastcall SetFinalPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall SetInitialPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdatePosition(int ADelta);
public:
	/* TdxDockSiteHideBar.Create */ inline __fastcall TdxDockSiteRightHideBar(TdxDockSite* AOwner) : TdxDockSiteLeftHideBar(AOwner) { }
	/* TdxDockSiteHideBar.Destroy */ inline __fastcall virtual ~TdxDockSiteRightHideBar(void) { }
	
};


class DELPHICLASS TdxDockSiteBottomHideBar;
class PASCALIMPLEMENTATION TdxDockSiteBottomHideBar : public TdxDockSiteTopHideBar
{
	typedef TdxDockSiteTopHideBar inherited;
	
protected:
	virtual void __fastcall CalculateBounds(const System::Types::TRect &R);
	virtual System::Uitypes::TAnchors __fastcall GetContainersAnchors(void);
	virtual Vcl::Controls::TAlign __fastcall GetControlsAlign(void);
	virtual TdxAutoHidePosition __fastcall GetPosition(void);
	virtual void __fastcall SetFinalPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall SetInitialPosition(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdatePosition(int ADelta);
public:
	/* TdxDockSiteHideBar.Create */ inline __fastcall TdxDockSiteBottomHideBar(TdxDockSite* AOwner) : TdxDockSiteTopHideBar(AOwner) { }
	/* TdxDockSiteHideBar.Destroy */ inline __fastcall virtual ~TdxDockSiteBottomHideBar(void) { }
	
};


typedef void __fastcall (__closure *TdxAutoHideControlEvent)(TdxDockSite* Sender, TdxCustomDockControl* AControl);

class PASCALIMPLEMENTATION TdxDockSite : public TdxCustomDockSite
{
	typedef TdxCustomDockSite inherited;
	
private:
	bool FAutoSize;
	int FAutoSizeHeight;
	int FAutoSizeWidth;
	System::Classes::TList* FHideBars;
	int FHidingTimerID;
	TdxCustomDockControl* FMovingControl;
	TdxDockSiteHideBar* FMovingControlHideBar;
	int FMovingTimerID;
	TdxCustomDockControl* FShowingControl;
	TdxCustomDockControl* FShowingControlCandidate;
	int FShowingTimerID;
	TdxCustomDockControl* FWorkingControl;
	TdxAutoHideControlEvent FOnHideControl;
	TdxAutoHideControlEvent FOnShowControl;
	int __fastcall GetHideBarCount(void);
	TdxDockSiteHideBar* __fastcall GetHideBar(int Index);
	TdxDockSiteAutoHideContainer* __fastcall GetMovingContainer(void);
	void __fastcall SetShowingControl(TdxCustomDockControl* Value);
	void __fastcall SetWorkingControl(TdxCustomDockControl* AValue);
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Message);
	
protected:
	DYNAMIC bool __fastcall GetDesignHitTest(const System::Types::TPoint APoint, System::Classes::TShiftState AShift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetAutoSize(bool Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	DYNAMIC void __fastcall ValidateInsert(System::Classes::TComponent* AComponent);
	virtual void __fastcall UpdateControlResizeZones(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdateControlDockZones(TdxCustomDockControl* AControl, int AZoneWidth);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DestroyLayout(TdxCustomDockControl* AControl);
	virtual void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	virtual void __fastcall SaveLayoutToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASection);
	virtual void __fastcall UpdateControlOriginalSize(TdxCustomDockControl* AControl);
	virtual void __fastcall ChildVisibilityChanged(TdxCustomDockControl* Sender);
	virtual void __fastcall CalculateNC(System::Types::TRect &ARect);
	virtual void __fastcall NCPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Recalculate(void);
	virtual TdxAutoHidePosition __fastcall GetControlAutoHidePosition(TdxCustomDockControl* AControl);
	void __fastcall RegisterAutoHideDockControl(TdxCustomDockControl* AControl, TdxAutoHidePosition APosition);
	void __fastcall UnregisterAutoHideDockControl(TdxCustomDockControl* AControl);
	virtual void __fastcall AdjustAutoSizeBounds(void);
	virtual bool __fastcall CanAutoSizeChange(void);
	virtual bool __fastcall CanResizing(int NewWidth, int NewHeight);
	void __fastcall CheckAutoSizeBounds(void);
	virtual TdxCustomDockControl* __fastcall GetAutoSizeClientControl(void);
	virtual void __fastcall UpdateAutoSizeBounds(int AWidth, int AHeight);
	void __fastcall DoHideControl(TdxCustomDockControl* AControl);
	void __fastcall DoShowControl(TdxCustomDockControl* AControl);
	void __fastcall DoShowMovement(void);
	void __fastcall DoHideMovement(void);
	void __fastcall ImmediatelyHide(bool AFinalizing = false);
	void __fastcall ImmediatelyShow(TdxCustomDockControl* AControl);
	void __fastcall InitializeHiding(void);
	void __fastcall InitializeShowing(void);
	void __fastcall FinalizeHiding(void);
	void __fastcall FinalizeShowing(void);
	void __fastcall SetFinalPosition(TdxCustomDockControl* AControl);
	void __fastcall SetInitialPosition(TdxCustomDockControl* AControl);
	int __fastcall GetClientLeft(void);
	int __fastcall GetClientTop(void);
	HIDESBASE int __fastcall GetClientWidth(void);
	HIDESBASE int __fastcall GetClientHeight(void);
	TdxCustomDockControl* __fastcall GetControlAtPos(System::Types::TPoint pt, TdxCustomDockControl* &SubControl);
	TdxDockSiteHideBar* __fastcall GetHideBarAtPos(System::Types::TPoint pt);
	TdxDockSiteHideBar* __fastcall GetHideBarByControl(TdxCustomDockControl* AControl);
	TdxDockSiteHideBar* __fastcall GetHideBarByPosition(TdxAutoHidePosition APosition);
	virtual void __fastcall CreateHideBars(void);
	virtual void __fastcall DestroyHideBars(void);
	__property int HideBarCount = {read=GetHideBarCount, nodefault};
	__property TdxDockSiteHideBar* HideBars[int Index] = {read=GetHideBar};
	__property TdxDockSiteHideBar* BottomHideBar = {read=GetHideBar, index=1};
	__property TdxDockSiteHideBar* LeftHideBar = {read=GetHideBar, index=2};
	__property TdxDockSiteHideBar* RightHideBar = {read=GetHideBar, index=3};
	__property TdxDockSiteHideBar* TopHideBar = {read=GetHideBar, index=0};
	__property TdxDockSiteAutoHideContainer* MovingContainer = {read=GetMovingContainer};
	__property TdxCustomDockControl* MovingControl = {read=FMovingControl};
	__property TdxDockSiteHideBar* MovingControlHideBar = {read=FMovingControlHideBar};
	
public:
	__fastcall virtual TdxDockSite(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDockSite(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	TdxAutoHidePosition __fastcall GetPositionByControl(TdxCustomDockControl* AControl);
	bool __fastcall HasAutoHideControls(void);
	__property TdxCustomDockControl* AutoSizeClientControl = {read=GetAutoSizeClientControl};
	__property TdxCustomDockControl* ShowingControl = {read=FShowingControl, write=SetShowingControl};
	__property TdxCustomDockControl* WorkingControl = {read=FWorkingControl, write=SetWorkingControl};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property Visible = {default=1};
	__property OnCreateLayoutSite;
	__property TdxAutoHideControlEvent OnHideControl = {read=FOnHideControl, write=FOnHideControl};
	__property TdxAutoHideControlEvent OnShowControl = {read=FOnShowControl, write=FOnShowControl};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockSite(HWND ParentWindow) : TdxCustomDockSite(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TdxSetFloatFormCaptionEvent)(TdxCustomDockControl* Sender, TdxFloatForm* AFloatForm);

class PASCALIMPLEMENTATION TdxFloatDockSite : public TdxCustomDockSite
{
	typedef TdxCustomDockSite inherited;
	
private:
	Vcl::Forms::TCustomForm* FFloatForm;
	int FFloatLeft;
	int FFloatTop;
	int FFloatWidth;
	int FFloatHeight;
	TdxSetFloatFormCaptionEvent FOnSetFloatFormCaption;
	HIDESBASE TdxCustomDockControl* __fastcall GetChild(void);
	int __fastcall GetFloatLeft(void);
	int __fastcall GetFloatTop(void);
	int __fastcall GetFloatWidth(void);
	int __fastcall GetFloatHeight(void);
	void __fastcall SetFloatLeft(const int Value);
	void __fastcall SetFloatTop(const int Value);
	void __fastcall SetFloatWidth(const int Value);
	void __fastcall SetFloatHeight(const int Value);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual System::Types::TRect __fastcall GetDesignRect(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	bool __fastcall IsLoadingFromForm(void);
	virtual bool __fastcall CanUndock(TdxCustomDockControl* AControl);
	virtual void __fastcall StartDocking(const System::Types::TPoint pt);
	virtual void __fastcall CheckDockClientsRules(void);
	virtual void __fastcall UpdateControlDockZones(TdxCustomDockControl* AControl, int AZoneWidth);
	virtual void __fastcall CreateLayout(TdxCustomDockControl* AControl, TdxDockingType AType, int Index);
	virtual void __fastcall DestroyLayout(TdxCustomDockControl* AControl);
	virtual void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	virtual void __fastcall SaveLayoutToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASection);
	void __fastcall DoSetFloatFormCaption(void);
	virtual TdxFloatForm* __fastcall GetFloatForm(void);
	virtual void __fastcall RestoreDockPosition(System::Types::TPoint pt);
	virtual TdxFloatFormClass __fastcall GetFloatFormClass(void);
	virtual void __fastcall CreateFloatForm(void);
	virtual void __fastcall DestroyFloatForm(void);
	void __fastcall HideFloatForm(void);
	void __fastcall ShowFloatForm(void);
	void __fastcall SetFloatFormPosition(int ALeft, int ATop);
	void __fastcall SetFloatFormSize(int AWidth, int AHeight);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall AdjustControlBounds(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdateControlOriginalSize(TdxCustomDockControl* AControl);
	virtual void __fastcall UpdateFloatPosition(void);
	virtual void __fastcall ChildVisibilityChanged(TdxCustomDockControl* Sender);
	virtual void __fastcall DoClose(void);
	virtual bool __fastcall CanDestroy(void);
	
public:
	__fastcall virtual TdxFloatDockSite(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxFloatDockSite(void);
	virtual void __fastcall BeforeDestruction(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual void __fastcall Activate(void);
	virtual bool __fastcall CanDockHost(TdxCustomDockControl* AControl, TdxDockingType AType);
	TdxCustomDockControl* __fastcall GetDockPanel(void);
	__property TdxCustomDockControl* Child = {read=GetChild};
	
__published:
	__property int FloatLeft = {read=GetFloatLeft, write=SetFloatLeft, nodefault};
	__property int FloatTop = {read=GetFloatTop, write=SetFloatTop, nodefault};
	__property int FloatWidth = {read=GetFloatWidth, write=SetFloatWidth, stored=false, nodefault};
	__property int FloatHeight = {read=GetFloatHeight, write=SetFloatHeight, stored=false, nodefault};
	__property TdxSetFloatFormCaptionEvent OnSetFloatFormCaption = {read=FOnSetFloatFormCaption, write=FOnSetFloatFormCaption};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxFloatDockSite(HWND ParentWindow) : TdxCustomDockSite(ParentWindow) { }
	
};


enum TdxEdgePosition : unsigned char { epLeft, epTop, epRight, epBottom, epTopLeft, epBottomRight, epRect };

typedef System::Set<TdxEdgePosition, TdxEdgePosition::epLeft, TdxEdgePosition::epRect>  TdxEdgePositions;

enum TdxEdgesType : unsigned char { etStandard, etFlat, etRaisedInner, etRaisedOuter, etSunkenInner, etSunkenOuter };

class PASCALIMPLEMENTATION TdxDockControlPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomDockControl* FDockControl;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	__classmethod virtual void __fastcall CreateColors();
	__classmethod virtual void __fastcall RefreshColors();
	__classmethod virtual void __fastcall ReleaseColors();
	__classmethod System::Uitypes::TColor __fastcall LightColor(System::Uitypes::TColor AColor);
	__classmethod System::Uitypes::TColor __fastcall LightLightColor(System::Uitypes::TColor AColor);
	__classmethod System::Uitypes::TColor __fastcall DarkColor(System::Uitypes::TColor AColor);
	__classmethod System::Uitypes::TColor __fastcall DarkDarkColor(System::Uitypes::TColor AColor);
	__classmethod void __fastcall DrawColorEdge(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AColor, TdxEdgesType AEdgesType, TdxEdgePositions AEdgePositios);
	__classmethod void __fastcall DrawImage(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, System::Types::TRect &R);
	__classmethod bool __fastcall RectInRect(System::Types::TRect &R1, System::Types::TRect &R2);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void);
	int __fastcall GetCaptionAreaHeight(void);
	virtual System::Uitypes::TColor __fastcall GetCaptionColor(bool IsActive);
	virtual Vcl::Graphics::TFont* __fastcall GetCaptionFont(bool IsActive);
	virtual System::Uitypes::TColor __fastcall GetCaptionFontColor(bool IsActive);
	virtual System::Types::TRect __fastcall GetCaptionRect(const System::Types::TRect &ARect, bool AIsVertical);
	virtual System::Uitypes::TColor __fastcall GetCaptionSignColor(bool IsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall GetHideBarButtonColor(void);
	virtual Vcl::Graphics::TFont* __fastcall GetHideBarButtonFont(void);
	virtual System::Uitypes::TColor __fastcall GetHideBarButtonFontColor(void);
	virtual System::Uitypes::TColor __fastcall GetHideBarColor(void);
	virtual bool __fastcall DrawCaptionFirst(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	
public:
	__fastcall virtual TdxDockControlPainter(TdxCustomDockControl* ADockControl);
	__classmethod virtual Cxpc::TcxPCPainterClass __fastcall GetTabsPainter(Cxpc::TcxPCStyleID ATabsStyle);
	__classmethod virtual bool __fastcall HasLookAndFeelStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle AStyle);
	virtual bool __fastcall CanVerticalCaption(void);
	virtual System::Types::TRect __fastcall GetBorderWidths(void);
	virtual System::Types::TSize __fastcall GetCaptionButtonSize(void);
	virtual System::Types::TRect __fastcall GetCaptionContentOffsets(bool AIsVertical);
	virtual int __fastcall GetCaptionHeight(void);
	virtual int __fastcall GetCaptionSeparatorSize(void);
	int __fastcall GetDefaultImageHeight(void);
	int __fastcall GetDefaultImageSize(TdxAutoHidePosition APosition);
	int __fastcall GetDefaultImageWidth(void);
	int __fastcall GetImageHeight(void);
	int __fastcall GetImageWidth(void);
	virtual int __fastcall GetSpaceBetweenCaptionButtons(void);
	virtual bool __fastcall IsHideBarButtonHotTrackSupports(void);
	bool __fastcall IsValidImageIndex(int AIndex);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);
	virtual void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionSeparator(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);
	virtual void __fastcall DrawCaptionText(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionButtonSelection(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AIsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionCloseButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AIsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionHideButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionMaximizeButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawClient(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);
	virtual int __fastcall GetHideBarHeight(void);
	virtual int __fastcall GetHideBarWidth(void);
	virtual int __fastcall GetHideBarHorizInterval(void);
	virtual int __fastcall GetHideBarVertInterval(void);
	virtual System::Types::TSize __fastcall GetHideBarScrollButtonSize(void);
	virtual void __fastcall DrawHideBar(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButton(Cxgraphics::TcxCanvas* ACanvas, TdxDockSiteHideBarButton* AButton, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TdxDockSiteHideBarButton* AButton, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonSection(Cxgraphics::TcxCanvas* ACanvas, TdxDockSiteHideBarButtonSection* AButtonSection, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonSections(Cxgraphics::TcxCanvas* ACanvas, TdxDockSiteHideBarButton* AButton, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonSectionSeparator(Cxgraphics::TcxCanvas* ACanvas, TdxDockSiteHideBarButtonSection* AButtonSection, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonImage(Cxgraphics::TcxCanvas* ACanvas, TdxCustomDockControl* AControl, System::Types::TRect &ARect);
	virtual void __fastcall DrawHideBarButtonText(Cxgraphics::TcxCanvas* ACanvas, TdxCustomDockControl* AControl, System::Types::TRect &ARect, TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarScrollButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxArrowDirection AArrow);
	__property TdxCustomDockControl* DockControl = {read=FDockControl};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockControlPainter(void) { }
	
};


class DELPHICLASS TdxCustomDockControlProperties;
class DELPHICLASS TdxDockingManager;
class PASCALIMPLEMENTATION TdxCustomDockControlProperties : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxDockingManager* FOwner;
	TdxDockingTypes FAllowDock;
	TdxDockingTypes FAllowDockClients;
	bool FAllowFloating;
	System::UnicodeString FCaption;
	TdxCaptionButtons FCaptionButtons;
	bool FDockable;
	int FImageIndex;
	bool FShowCaption;
	System::Uitypes::TColor FColor;
	System::Uitypes::TCursor FCursor;
	Vcl::Graphics::TFont* FFont;
	System::UnicodeString FHint;
	bool FManagerColor;
	bool FManagerFont;
	Vcl::Menus::TPopupMenu* FPopupMenu;
	bool FShowHint;
	int FTag;
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	void __fastcall SetColor(const System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* const Value);
	void __fastcall SetManagerColor(const bool Value);
	void __fastcall SetManagerFont(const bool Value);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TdxCustomDockControlProperties(TdxDockingManager* AOwner);
	__fastcall virtual ~TdxCustomDockControlProperties(void);
	__property TdxDockingTypes AllowDock = {read=FAllowDock, write=FAllowDock, default=31};
	__property TdxDockingTypes AllowDockClients = {read=FAllowDockClients, write=FAllowDockClients, default=31};
	__property bool AllowFloating = {read=FAllowFloating, write=FAllowFloating, default=1};
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property TdxCaptionButtons CaptionButtons = {read=FCaptionButtons, write=FCaptionButtons, default=7};
	__property bool Dockable = {read=FDockable, write=FDockable, nodefault};
	__property int ImageIndex = {read=FImageIndex, write=FImageIndex, nodefault};
	__property bool ShowCaption = {read=FShowCaption, write=FShowCaption, default=1};
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, default=-16777201};
	__property System::Uitypes::TCursor Cursor = {read=FCursor, write=FCursor, default=0};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property bool ManagerColor = {read=FManagerColor, write=SetManagerColor, default=1};
	__property bool ManagerFont = {read=FManagerFont, write=SetManagerFont, default=1};
	__property Vcl::Menus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=FPopupMenu};
	__property bool ShowHint = {read=FShowHint, write=FShowHint, default=0};
	__property int Tag = {read=FTag, write=FTag, default=0};
};


class DELPHICLASS TdxLayoutDockSiteProperties;
class PASCALIMPLEMENTATION TdxLayoutDockSiteProperties : public TdxCustomDockControlProperties
{
	typedef TdxCustomDockControlProperties inherited;
	
__published:
	__property AllowDockClients = {default=31};
public:
	/* TdxCustomDockControlProperties.Create */ inline __fastcall virtual TdxLayoutDockSiteProperties(TdxDockingManager* AOwner) : TdxCustomDockControlProperties(AOwner) { }
	/* TdxCustomDockControlProperties.Destroy */ inline __fastcall virtual ~TdxLayoutDockSiteProperties(void) { }
	
};


class DELPHICLASS TdxFloatDockSiteProperties;
class PASCALIMPLEMENTATION TdxFloatDockSiteProperties : public TdxCustomDockControlProperties
{
	typedef TdxCustomDockControlProperties inherited;
	
__published:
	__property AllowDockClients = {default=31};
public:
	/* TdxCustomDockControlProperties.Create */ inline __fastcall virtual TdxFloatDockSiteProperties(TdxDockingManager* AOwner) : TdxCustomDockControlProperties(AOwner) { }
	/* TdxCustomDockControlProperties.Destroy */ inline __fastcall virtual ~TdxFloatDockSiteProperties(void) { }
	
};


class DELPHICLASS TdxSideContainerDockSiteProperties;
class PASCALIMPLEMENTATION TdxSideContainerDockSiteProperties : public TdxCustomDockControlProperties
{
	typedef TdxCustomDockControlProperties inherited;
	
__published:
	__property AllowDock = {default=31};
	__property AllowDockClients = {default=31};
	__property AllowFloating = {default=1};
	__property CaptionButtons = {default=7};
	__property Dockable;
	__property ImageIndex;
	__property ShowCaption = {default=1};
public:
	/* TdxCustomDockControlProperties.Create */ inline __fastcall virtual TdxSideContainerDockSiteProperties(TdxDockingManager* AOwner) : TdxCustomDockControlProperties(AOwner) { }
	/* TdxCustomDockControlProperties.Destroy */ inline __fastcall virtual ~TdxSideContainerDockSiteProperties(void) { }
	
};


class DELPHICLASS TdxTabContainerDockSiteProperties;
class PASCALIMPLEMENTATION TdxTabContainerDockSiteProperties : public TdxCustomDockControlProperties
{
	typedef TdxCustomDockControlProperties inherited;
	
private:
	TdxDockingTabControlProperties* FTabsProperties;
	void __fastcall SetTabsProperties(TdxDockingTabControlProperties* AValue);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	__fastcall virtual TdxTabContainerDockSiteProperties(TdxDockingManager* AOwner);
	__fastcall virtual ~TdxTabContainerDockSiteProperties(void);
	
__published:
	__property AllowDock = {default=31};
	__property AllowDockClients = {default=31};
	__property AllowFloating = {default=1};
	__property CaptionButtons = {default=7};
	__property Dockable;
	__property ImageIndex;
	__property ShowCaption = {default=1};
	__property TdxDockingTabControlProperties* TabsProperties = {read=FTabsProperties, write=SetTabsProperties};
};


class DELPHICLASS TdxDockingControllerHelper;
class PASCALIMPLEMENTATION TdxDockingControllerHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxDockingDragImage* FDragImage;
	
protected:
	bool __fastcall CanDocking(TdxCustomDockControl* AControl, TdxCustomDockControl* ATargetControl, TdxZone* ATargetZone, const System::Types::TPoint APoint);
	void __fastcall CreateSelectionDragImage(TdxCustomDockControl* AControl);
	
public:
	virtual void __fastcall DockingStart(TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	virtual void __fastcall DockingMove(TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	virtual void __fastcall DockingFinish(TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	__property TdxDockingDragImage* DragImage = {read=FDragImage};
public:
	/* TObject.Create */ inline __fastcall TdxDockingControllerHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockingControllerHelper(void) { }
	
};


typedef System::TMetaClass* TdxDockingControllerHelperClass;

enum TdxDockingInternalState : unsigned char { disManagerChanged, disContextMenu, disRedrawLocked, disLoading };

typedef System::Set<TdxDockingInternalState, TdxDockingInternalState::disManagerChanged, TdxDockingInternalState::disLoading>  TdxDockingInternalStates;

class PASCALIMPLEMENTATION TdxDockingController : public Cxcontrols::TcxMessageWindow
{
	typedef Cxcontrols::TcxMessageWindow inherited;
	
private:
	TdxCustomDockControl* FActivatingDockControl;
	TdxCustomDockControl* FActiveDockControl;
	int FActiveDockControlLockCount;
	Vcl::Appevnts::TApplicationEvents* FAppEvents;
	bool FApplicationActive;
	bool FApplicationDeactivating;
	TdxCustomDockControl* FCalculatingControl;
	Cxclasses::TcxComponentList* FDestroyedComponents;
	System::Classes::TList* FDockControls;
	TdxDockingControllerHelper* FDockingControllerHelper;
	TdxCustomDockControl* FDockingDockControl;
	System::Classes::TList* FDockManagers;
	Vcl::Graphics::TFont* FFont;
	System::Classes::TList* FInvalidNC;
	System::Classes::TList* FInvalidNCBounds;
	System::Classes::TList* FInvalidRedraw;
	System::Classes::TList* FLoadedForms;
	TdxCustomDockControl* FResizingDockControl;
	Vcl::Graphics::TBrush* FSelectionBrush;
	Cxgraphics::TcxBitmap* FTempBitmap;
	int FUpdateNCLock;
	TdxCustomDockControl* __fastcall GetDockControl(int Index);
	int __fastcall GetDockControlCount(void);
	TdxDockingManager* __fastcall GetDockManager(int Index);
	int __fastcall GetDockManagerCount(void);
	bool __fastcall GetIsDocking(void);
	bool __fastcall GetIsResizing(void);
	void __fastcall SetActiveDockControl(TdxCustomDockControl* Value);
	void __fastcall SetApplicationActive(bool AValue);
	void __fastcall SetSelectionBrush(Vcl::Graphics::TBrush* Value);
	void __fastcall ApplicationDeactivated(System::TObject* Sender);
	bool __fastcall ControlNeedUpdate(TdxCustomDockControl* AControl, Vcl::Forms::TCustomForm* AForm);
	void __fastcall DestroyControls(void);
	void __fastcall FinishDocking(void);
	void __fastcall FinishResizing(void);
	void __fastcall UpdateInvalidControlsNC(void);
	
protected:
	TdxDockingInternalStates FInternalState;
	void __fastcall ActiveAppChanged(bool AActive);
	bool __fastcall IsApplicationDeactivating(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	bool __fastcall IsParentForFloatDockSite(Vcl::Forms::TCustomForm* AParentForm, TdxFloatDockSite* AFloatDockSite);
	void __fastcall BringToFrontFloatForms(Vcl::Forms::TCustomForm* AParentForm, bool ATopMost);
	void __fastcall UpdateEnableStatusFloatForms(Vcl::Forms::TCustomForm* AParentForm, bool AEnable);
	void __fastcall UpdateVisibilityFloatForms(Vcl::Forms::TCustomForm* AParentForm, bool AShow);
	void __fastcall ValidateFloatFormsDesigners(Vcl::Forms::TCustomForm* AParentForm);
	TdxDockingControllerHelper* __fastcall CreateDockingControllerHelper(TdxDockStyle ADockStyle);
	void __fastcall StartDocking(TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	void __fastcall Docking(TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	void __fastcall EndDocking(TdxCustomDockControl* AControl, const System::Types::TPoint APoint);
	void __fastcall DockControlLoaded(TdxCustomDockControl* AControl);
	void __fastcall DockManagerLoaded(Vcl::Forms::TCustomForm* AParentForm);
	int __fastcall IndexOfDockControl(TdxCustomDockControl* AControl);
	void __fastcall PostponedDestroyDockControl(TdxCustomDockControl* AControl);
	void __fastcall PostponedDestroyComponent(System::Classes::TComponent* AComponent);
	void __fastcall RegisterDockControl(TdxCustomDockControl* AControl);
	void __fastcall UnregisterDockControl(TdxCustomDockControl* AControl);
	TdxDockingManager* __fastcall FindManager(Vcl::Forms::TCustomForm* AForm);
	TdxDockingManager* __fastcall FindFormManager(Vcl::Forms::TCustomForm* AForm);
	void __fastcall RegisterManager(TdxDockingManager* AManager);
	void __fastcall UnregisterManager(TdxDockingManager* AManager);
	void __fastcall DoActiveDockControlChanged(TdxCustomDockControl* ASender, bool ACallEvent);
	void __fastcall DoCreateFloatSite(TdxCustomDockControl* ASender, TdxFloatDockSite* ASite);
	void __fastcall DoCreateLayoutSite(TdxCustomDockControl* ASender, TdxLayoutDockSite* ASite);
	void __fastcall DoCreateSideContainerSite(TdxCustomDockControl* ASender, TdxSideContainerDockSite* ASite);
	void __fastcall DoCreateTabContainerSite(TdxCustomDockControl* ASender, TdxTabContainerDockSite* ASite);
	bool __fastcall DoCustomDrawResizingSelection(TdxCustomDockControl* ASender, HDC DC, TdxZone* AZone, System::Types::TPoint pt, bool Erasing);
	bool __fastcall DoCustomDrawDockingSelection(TdxCustomDockControl* ASender, HDC DC, TdxZone* AZone, System::Types::TRect &R, bool Erasing);
	void __fastcall DoSetFloatFormCaption(TdxCustomDockControl* ASender, TdxFloatForm* AFloatForm);
	void __fastcall DoLayoutChanged(TdxCustomDockControl* ASender);
	void __fastcall DoUpdateDockZones(TdxCustomDockControl* ASender);
	void __fastcall DoUpdateResizeZones(TdxCustomDockControl* ASender);
	void __fastcall DoColorChanged(Vcl::Forms::TCustomForm* AForm);
	void __fastcall DoFontChanged(Vcl::Forms::TCustomForm* AForm);
	void __fastcall DoImagesChanged(Vcl::Forms::TCustomForm* AForm);
	void __fastcall DoLayoutLoaded(Vcl::Forms::TCustomForm* AForm);
	void __fastcall DoManagerChanged(Vcl::Forms::TCustomForm* AForm);
	void __fastcall DoOptionsChanged(Vcl::Forms::TCustomForm* AForm);
	void __fastcall DoPainterChanged(Vcl::Forms::TCustomForm* AForm, bool AssignDefaultStyle);
	void __fastcall DoZonesWidthChanged(Vcl::Forms::TCustomForm* AForm);
	void __fastcall ClearLayout(Vcl::Forms::TCustomForm* AForm);
	void __fastcall LoadLayoutFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AForm);
	void __fastcall LoadControlFromCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AParentForm, TdxCustomDockControl* AParentControl, System::UnicodeString ASection);
	void __fastcall SaveLayoutToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, Vcl::Forms::TCustomForm* AForm);
	void __fastcall SaveControlToCustomIni(System::Inifiles::TCustomIniFile* AIniFile, TdxCustomDockControl* AControl);
	void __fastcall UpdateLayout(Vcl::Forms::TCustomForm* AForm);
	System::TObject* __fastcall GetObject(void);
	void __fastcall MasterLookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall MasterLookAndFeelDestroying(Cxlookandfeels::TcxLookAndFeel* Sender);
	void __fastcall BeginUpdateNC(bool ALockRedraw = true);
	void __fastcall EndUpdateNC(void);
	bool __fastcall CanUpdateNC(TdxCustomDockControl* AControl);
	bool __fastcall CanCalculateNC(TdxCustomDockControl* AControl);
	void __fastcall DrawDockingSelection(TdxCustomDockControl* ADockControl, TdxZone* AZone, const System::Types::TPoint APoint, bool AErasing);
	void __fastcall DrawResizingSelection(TdxCustomDockControl* ADockControl, TdxZone* AZone, const System::Types::TPoint APoint, bool AErasing);
	TdxDockControlPainterClass __fastcall PainterClass(Vcl::Forms::TCustomForm* AForm);
	void __fastcall CalculateControls(Vcl::Forms::TCustomForm* AForm);
	void __fastcall InvalidateActiveDockControl(void);
	void __fastcall InvalidateControls(Vcl::Forms::TCustomForm* AForm, bool ANeedRecalculate);
	void __fastcall CreatePainterColors(Vcl::Forms::TCustomForm* AForm);
	void __fastcall RefreshPainterColors(Vcl::Forms::TCustomForm* AForm);
	void __fastcall ReleasePainterColors(Vcl::Forms::TCustomForm* AForm);
	bool __fastcall IsUpdateNCLocked(void);
	void __fastcall CheckTempBitmap(System::Types::TRect &ARect);
	void __fastcall ReleaseTempBitmap(void);
	__property bool ApplicationActive = {read=FApplicationActive, write=SetApplicationActive, nodefault};
	__property TdxDockingControllerHelper* DockingControllerHelper = {read=FDockingControllerHelper};
	__property Cxgraphics::TcxBitmap* TempBitmap = {read=FTempBitmap};
	
public:
	__fastcall virtual TdxDockingController(void);
	__fastcall virtual ~TdxDockingController(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	TdxCustomDockControl* __fastcall GetDockControlAtPos(const System::Types::TPoint P);
	TdxCustomDockControl* __fastcall GetDockControlForWindow(HWND AWnd, HWND ADockWindow = (HWND)(0ULL));
	TdxCustomDockControl* __fastcall GetFloatDockSiteAtPos(const System::Types::TPoint pt);
	TdxCustomDockControl* __fastcall GetNearestDockSiteAtPos(const System::Types::TPoint pt, TdxCustomDockControl* ADockControl = (TdxCustomDockControl*)(0x0));
	bool __fastcall IsDockControlFocusedEx(TdxCustomDockControl* ADockControl);
	TdxLayoutDockSiteProperties* __fastcall DefaultLayoutSiteProperties(Vcl::Forms::TCustomForm* AForm);
	TdxFloatDockSiteProperties* __fastcall DefaultFloatSiteProperties(Vcl::Forms::TCustomForm* AForm);
	TdxSideContainerDockSiteProperties* __fastcall DefaultHorizContainerSiteProperties(Vcl::Forms::TCustomForm* AForm);
	TdxSideContainerDockSiteProperties* __fastcall DefaultVertContainerSiteProperties(Vcl::Forms::TCustomForm* AForm);
	TdxTabContainerDockSiteProperties* __fastcall DefaultTabContainerSiteProperties(Vcl::Forms::TCustomForm* AForm);
	void __fastcall LoadLayoutFromIniFile(System::UnicodeString AFileName, Vcl::Forms::TCustomForm* AForm = (Vcl::Forms::TCustomForm*)(0x0));
	void __fastcall LoadLayoutFromRegistry(System::UnicodeString ARegistryPath, Vcl::Forms::TCustomForm* AForm = (Vcl::Forms::TCustomForm*)(0x0));
	void __fastcall LoadLayoutFromStream(System::Classes::TStream* AStream, Vcl::Forms::TCustomForm* AForm = (Vcl::Forms::TCustomForm*)(0x0));
	void __fastcall SaveLayoutToIniFile(System::UnicodeString AFileName, Vcl::Forms::TCustomForm* AForm = (Vcl::Forms::TCustomForm*)(0x0));
	void __fastcall SaveLayoutToRegistry(System::UnicodeString ARegistryPath, Vcl::Forms::TCustomForm* AForm = (Vcl::Forms::TCustomForm*)(0x0));
	void __fastcall SaveLayoutToStream(System::Classes::TStream* AStream, Vcl::Forms::TCustomForm* AForm = (Vcl::Forms::TCustomForm*)(0x0));
	int __fastcall AutoHideInterval(Vcl::Forms::TCustomForm* AForm);
	int __fastcall AutoHideMovingInterval(Vcl::Forms::TCustomForm* AForm);
	int __fastcall AutoHideMovingSize(Vcl::Forms::TCustomForm* AForm);
	int __fastcall AutoShowInterval(Vcl::Forms::TCustomForm* AForm);
	System::Uitypes::TColor __fastcall Color(Vcl::Forms::TCustomForm* AForm);
	TdxDockStyle __fastcall DockStyle(Vcl::Forms::TCustomForm* AForm);
	int __fastcall DockZonesWidth(Vcl::Forms::TCustomForm* AForm);
	Vcl::Graphics::TFont* __fastcall GetFont(Vcl::Forms::TCustomForm* AForm);
	Vcl::Imglist::TCustomImageList* __fastcall Images(Vcl::Forms::TCustomForm* AForm);
	Cxlookandfeels::TcxLookAndFeel* __fastcall LookAndFeel(Vcl::Forms::TCustomForm* AForm);
	TdxDockingOptions __fastcall Options(Vcl::Forms::TCustomForm* AForm);
	int __fastcall ResizeZonesWidth(Vcl::Forms::TCustomForm* AForm);
	int __fastcall SelectionFrameWidth(Vcl::Forms::TCustomForm* AForm);
	int __fastcall TabsScrollInterval(Vcl::Forms::TCustomForm* AForm);
	__property TdxCustomDockControl* ActiveDockControl = {read=FActiveDockControl, write=SetActiveDockControl};
	__property int DockControlCount = {read=GetDockControlCount, nodefault};
	__property TdxCustomDockControl* DockControls[int Index] = {read=GetDockControl};
	__property int DockManagerCount = {read=GetDockManagerCount, nodefault};
	__property TdxDockingManager* DockManagers[int Index] = {read=GetDockManager};
	__property TdxCustomDockControl* DockingDockControl = {read=FDockingDockControl};
	__property bool IsDocking = {read=GetIsDocking, nodefault};
	__property bool IsResizing = {read=GetIsResizing, nodefault};
	__property TdxCustomDockControl* ResizingDockControl = {read=FResizingDockControl};
	__property Vcl::Graphics::TBrush* SelectionBrush = {read=FSelectionBrush, write=SetSelectionBrush};
private:
	void *__IcxLookAndFeelNotificationListener;	/* Cxlookandfeels::IcxLookAndFeelNotificationListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {205538BF-F19E-4285-B11F-B182D9635881}
	operator Cxlookandfeels::_di_IcxLookAndFeelNotificationListener()
	{
		Cxlookandfeels::_di_IcxLookAndFeelNotificationListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelNotificationListener*(void) { return (Cxlookandfeels::IcxLookAndFeelNotificationListener*)&__IcxLookAndFeelNotificationListener; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxDockingManager : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
private:
	int FAutoHideInterval;
	int FAutoHideMovingInterval;
	int FAutoHideMovingSize;
	int FAutoShowInterval;
	Vcl::Imglist::TChangeLink* FChangeLink;
	System::Uitypes::TColor FColor;
	System::Classes::TList* FDefaultSitesPropertiesList;
	TdxDockStyle FDockStyle;
	int FDockZonesWidth;
	Vcl::Graphics::TFont* FFont;
	Vcl::Imglist::TCustomImageList* FImages;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TdxDockingOptions FOptions;
	TdxDockControlPainterClass FPainterClass;
	int FResizeZonesWidth;
	int FSelectionFrameWidth;
	int FTabsScrollInterval;
	bool FUseDefaultSitesProperties;
	System::Classes::TNotifyEvent FOnActiveDockControlChanged;
	TdxCreateFloatSiteEvent FOnCreateFloatSite;
	TdxCreateLayoutSiteEvent FOnCreateLayoutSite;
	TdxCreateSideContainerEvent FOnCreateSideContainer;
	TdxCreateTabContainerEvent FOnCreateTabContainer;
	TdxCustomDrawSelectionEvent FOnCustomDrawDockingSelection;
	TdxCustomDrawSelectionEvent FOnCustomDrawResizingSelection;
	TdxDockControlNotifyEvent FOnLayoutChanged;
	TdxSetFloatFormCaptionEvent FOnSetFloatFormCaption;
	System::Classes::TNotifyEvent FOnViewChanged;
	TdxUpdateZonesEvent FOnUpdateDockZones;
	TdxUpdateZonesEvent FOnUpdateResizeZones;
	bool __fastcall IsDefaultSitePropertiesStored(void);
	TdxCustomDockControlProperties* __fastcall GetDefaultSiteProperties(int Index);
	int __fastcall GetDefaultSitesPropertiesCount(void);
	TdxLayoutDockSiteProperties* __fastcall GetDefaultLayoutSiteProperties(void);
	TdxFloatDockSiteProperties* __fastcall GetDefaultFloatSiteProperties(void);
	TdxSideContainerDockSiteProperties* __fastcall GetDefaultHorizContainerSiteProperties(void);
	TdxSideContainerDockSiteProperties* __fastcall GetDefaultVertContainerSiteProperties(void);
	TdxTabContainerDockSiteProperties* __fastcall GetDefaultTabContainerSiteProperties(void);
	Vcl::Forms::TCustomForm* __fastcall GetParentForm(void);
	void __fastcall SetColor(const System::Uitypes::TColor Value);
	void __fastcall SetDefaultFloatSiteProperties(TdxFloatDockSiteProperties* Value);
	void __fastcall SetDefaultHorizContainerSiteProperties(TdxSideContainerDockSiteProperties* Value);
	void __fastcall SetDefaultLayoutSiteProperties(TdxLayoutDockSiteProperties* Value);
	void __fastcall SetDefaultTabContainerSiteProperties(TdxTabContainerDockSiteProperties* Value);
	void __fastcall SetDefaultVertContainerSiteProperties(TdxSideContainerDockSiteProperties* Value);
	void __fastcall SetDockStyle(TdxDockStyle AValue);
	void __fastcall SetDockZonesWidth(const int Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* const Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetOptions(const TdxDockingOptions Value);
	void __fastcall SetResizeZonesWidth(const int Value);
	void __fastcall DoOnFontChanged(System::TObject* Sender);
	void __fastcall DoOnImagesChanged(System::TObject* Sender);
	void __fastcall DoOnLFChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall DoViewChanged(void);
	void __fastcall ReadViewStyle(System::Classes::TReader* AReader);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall ChangeScale(int M, int D);
	bool __fastcall IsLoading(void);
	HIDESBASE bool __fastcall IsDestroying(void);
	void __fastcall DoColorChanged(void);
	void __fastcall DoFontChanged(void);
	virtual void __fastcall CreatePainterClass(bool AssignDefaultStyle);
	virtual TdxDockControlPainterClass __fastcall GetActualPainterClass(void);
	virtual TdxDockControlPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall ReleasePainterClass(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	virtual void __fastcall CreateDefaultSitesProperties(void);
	virtual void __fastcall DestroyDefaultSitesProperties(void);
	void __fastcall UpdateDefaultSitesPropertiesColor(void);
	void __fastcall UpdateDefaultSitesPropertiesFont(void);
	
public:
	__fastcall virtual TdxDockingManager(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDockingManager(void);
	void __fastcall LoadLayoutFromIniFile(System::UnicodeString AFileName);
	void __fastcall LoadLayoutFromRegistry(System::UnicodeString ARegistryPath);
	void __fastcall LoadLayoutFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveLayoutToIniFile(System::UnicodeString AFileName);
	void __fastcall SaveLayoutToRegistry(System::UnicodeString ARegistryPath);
	void __fastcall SaveLayoutToStream(System::Classes::TStream* AStream);
	__property TdxCustomDockControlProperties* DefaultSitesProperties[int Index] = {read=GetDefaultSiteProperties};
	__property int DefaultSitesPropertiesCount = {read=GetDefaultSitesPropertiesCount, nodefault};
	__property TdxDockControlPainterClass PainterClass = {read=GetPainterClass};
	__property Vcl::Forms::TCustomForm* ParentForm = {read=GetParentForm};
	
__published:
	__property Scalable = {default=1};
	__property int AutoHideInterval = {read=FAutoHideInterval, write=FAutoHideInterval, default=500};
	__property int AutoHideMovingInterval = {read=FAutoHideMovingInterval, write=FAutoHideMovingInterval, default=1};
	__property int AutoHideMovingSize = {read=FAutoHideMovingSize, write=FAutoHideMovingSize, default=20};
	__property int AutoShowInterval = {read=FAutoShowInterval, write=FAutoShowInterval, default=300};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property TdxLayoutDockSiteProperties* DefaultLayoutSiteProperties = {read=GetDefaultLayoutSiteProperties, write=SetDefaultLayoutSiteProperties, stored=IsDefaultSitePropertiesStored};
	__property TdxFloatDockSiteProperties* DefaultFloatSiteProperties = {read=GetDefaultFloatSiteProperties, write=SetDefaultFloatSiteProperties, stored=IsDefaultSitePropertiesStored};
	__property TdxSideContainerDockSiteProperties* DefaultHorizContainerSiteProperties = {read=GetDefaultHorizContainerSiteProperties, write=SetDefaultHorizContainerSiteProperties, stored=IsDefaultSitePropertiesStored};
	__property TdxSideContainerDockSiteProperties* DefaultVertContainerSiteProperties = {read=GetDefaultVertContainerSiteProperties, write=SetDefaultVertContainerSiteProperties, stored=IsDefaultSitePropertiesStored};
	__property TdxTabContainerDockSiteProperties* DefaultTabContainerSiteProperties = {read=GetDefaultTabContainerSiteProperties, write=SetDefaultTabContainerSiteProperties, stored=IsDefaultSitePropertiesStored};
	__property TdxDockStyle DockStyle = {read=FDockStyle, write=SetDockStyle, default=0};
	__property int DockZonesWidth = {read=FDockZonesWidth, write=SetDockZonesWidth, default=20};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property TdxDockingOptions Options = {read=FOptions, write=SetOptions, default=69287};
	__property int ResizeZonesWidth = {read=FResizeZonesWidth, write=SetResizeZonesWidth, default=3};
	__property int SelectionFrameWidth = {read=FSelectionFrameWidth, write=FSelectionFrameWidth, default=4};
	__property int TabsScrollInterval = {read=FTabsScrollInterval, write=FTabsScrollInterval, default=300};
	__property bool UseDefaultSitesProperties = {read=FUseDefaultSitesProperties, write=FUseDefaultSitesProperties, default=1};
	__property System::Classes::TNotifyEvent OnActiveDockControlChanged = {read=FOnActiveDockControlChanged, write=FOnActiveDockControlChanged};
	__property TdxCreateFloatSiteEvent OnCreateFloatSite = {read=FOnCreateFloatSite, write=FOnCreateFloatSite};
	__property TdxCreateLayoutSiteEvent OnCreateLayoutSite = {read=FOnCreateLayoutSite, write=FOnCreateLayoutSite};
	__property TdxCreateSideContainerEvent OnCreateSideContainer = {read=FOnCreateSideContainer, write=FOnCreateSideContainer};
	__property TdxCreateTabContainerEvent OnCreateTabContainer = {read=FOnCreateTabContainer, write=FOnCreateTabContainer};
	__property TdxCustomDrawSelectionEvent OnCustomDrawDockingSelection = {read=FOnCustomDrawDockingSelection, write=FOnCustomDrawDockingSelection};
	__property TdxCustomDrawSelectionEvent OnCustomDrawResizingSelection = {read=FOnCustomDrawResizingSelection, write=FOnCustomDrawResizingSelection};
	__property TdxDockControlNotifyEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	__property TdxSetFloatFormCaptionEvent OnSetFloatFormCaption = {read=FOnSetFloatFormCaption, write=FOnSetFloatFormCaption};
	__property System::Classes::TNotifyEvent OnViewChanged = {read=FOnViewChanged, write=FOnViewChanged};
	__property TdxUpdateZonesEvent OnUpdateDockZones = {read=FOnUpdateDockZones, write=FOnUpdateDockZones};
	__property TdxUpdateZonesEvent OnUpdateResizeZones = {read=FOnUpdateResizeZones, write=FOnUpdateResizeZones};
private:
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
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
	
};


class DELPHICLASS TdxDockingPaintersManager;
class PASCALIMPLEMENTATION TdxDockingPaintersManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FPainters;
	TdxDockControlPainterClass __fastcall GetPainterClass(int Index);
	int __fastcall GetPainterClassCount(void);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxDockingPaintersManager(void);
	__fastcall virtual ~TdxDockingPaintersManager(void);
	TdxDockControlPainterClass __fastcall Find(Cxlookandfeelpainters::TcxLookAndFeelStyle AStyle);
	TdxDockControlPainterClass __fastcall GetAvailablePainterClass(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	void __fastcall Register(TdxDockControlPainterClass APainterClass);
	void __fastcall Unregister(TdxDockControlPainterClass APainterClass);
	__property TdxDockControlPainterClass PainterClass[int Index] = {read=GetPainterClass};
	__property int PainterClassCount = {read=GetPainterClassCount, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxDockingLayoutVersion = System::Int8(0x1);
#define dxDockingDefaultDockingTypes (System::Set<TdxDockingTypeEx, TdxDockingTypeEx::dtClient, TdxDockingTypeEx::dtNone> () << TdxDockingTypeEx::dtClient << TdxDockingTypeEx::dtLeft << TdxDockingTypeEx::dtTop << TdxDockingTypeEx::dtRight << TdxDockingTypeEx::dtBottom )
#define dxDockinkDefaultCaptionButtons (System::Set<TdxCaptionButton, TdxCaptionButton::cbMaximize, TdxCaptionButton::cbClose> () << TdxCaptionButton::cbMaximize << TdxCaptionButton::cbHide << TdxCaptionButton::cbClose )
#define dxDockingDefaultOptions (System::Set<TdxDockingOption, TdxDockingOption::doActivateAfterDocking, TdxDockingOption::doUseCaptionAreaToClientDocking> () << TdxDockingOption::doActivateAfterDocking << TdxDockingOption::doDblClickDocking << TdxDockingOption::doFloatingOnTop << TdxDockingOption::doTabContainerHasCaption << TdxDockingOption::doTabContainerCanAutoHide << TdxDockingOption::doSideContainerCanClose << TdxDockingOption::doSideContainerCanAutoHide << TdxDockingOption::doTabContainerCanInSideContainer << TdxDockingOption::doRedrawOnResize )
static const TdxDockStyle dxDefaultDockStyle = (TdxDockStyle)(0);
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnRegisterDockControl;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnUnregisterDockControl;
extern PACKAGE TdxDockingPaintersManager* __fastcall dxDockingPaintersManager(void);
extern PACKAGE TdxDockingController* __fastcall dxDockingController(void);
}	/* namespace Dxdockcontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKCONTROL)
using namespace Dxdockcontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockcontrolHPP
