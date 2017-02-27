// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockPanel.pas' rev: 24.00 (Win32)

#ifndef DxdockpanelHPP
#define DxdockpanelHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxDockConsts.hpp>	// Pascal unit
#include <dxDockControl.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockpanel
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDockPanelTabControlController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockPanelTabControlController : public Dxdockcontrol::TdxDockingTabControlController
{
	typedef Dxdockcontrol::TdxDockingTabControlController inherited;
	
protected:
	virtual bool __fastcall IsDockable(Dxdockcontrol::TdxCustomDockControl* AControl);
	virtual void __fastcall DoUndock(const System::Types::TPoint &APoint, Dxdockcontrol::TdxCustomDockControl* ADockControl);
public:
	/* TdxDockingTabControlController.Create */ inline __fastcall virtual TdxDockPanelTabControlController(System::TObject* AOwner) : Dxdockcontrol::TdxDockingTabControlController(AOwner) { }
	
public:
	/* TcxCustomTabControlController.Destroy */ inline __fastcall virtual ~TdxDockPanelTabControlController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxDockPanelTabControlProperties;
class PASCALIMPLEMENTATION TdxDockPanelTabControlProperties : public Dxdockcontrol::TdxDockingTabControlProperties
{
	typedef Dxdockcontrol::TdxDockingTabControlProperties inherited;
	
public:
	/* TdxDockingTabControlProperties.Create */ inline __fastcall virtual TdxDockPanelTabControlProperties(System::Classes::TPersistent* AOwner) : Dxdockcontrol::TdxDockingTabControlProperties(AOwner) { }
	
public:
	/* TcxCustomTabControlProperties.Destroy */ inline __fastcall virtual ~TdxDockPanelTabControlProperties(void) { }
	
};


class DELPHICLASS TdxDockPanel;
class PASCALIMPLEMENTATION TdxDockPanel : public Dxdockcontrol::TdxCustomDockControl
{
	typedef Dxdockcontrol::TdxCustomDockControl inherited;
	
private:
	bool FShowSingleTab;
	System::Types::TRect FTabControlSuggestedBounds;
	Dxdockcontrol::TdxDockingTabControlViewInfo* FTabControlViewInfo;
	TdxDockPanelTabControlController* FTabsController;
	TdxDockPanelTabControlProperties* FTabsProperties;
	System::Types::TRect __fastcall GetTabRect(void);
	System::Types::TRect __fastcall GetTabsRect(void);
	void __fastcall SetShowSingleTab(const bool Value);
	void __fastcall SetTabsProperties(TdxDockPanelTabControlProperties* AValue);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
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
	bool __fastcall IsEnabled(void);
	bool __fastcall IsFocused(void);
	bool __fastcall IsParentBackground(void);
	void __fastcall InvalidateRect(const System::Types::TRect &R, bool AEraseBackground);
	void __fastcall RequestLayout(void);
	void __fastcall SetModified(void);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual bool __fastcall IsDockPanel(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual void __fastcall UpdateCaption(void);
	DYNAMIC void __fastcall ValidateInsert(System::Classes::TComponent* AComponent);
	virtual void __fastcall CheckActiveDockControl(void);
	virtual void __fastcall DoActivate(void);
	virtual void __fastcall UpdateControlDockZones(Dxdockcontrol::TdxCustomDockControl* AControl, int AZoneWidth);
	virtual void __fastcall CreateLayout(Dxdockcontrol::TdxCustomDockControl* AControl, Dxdockcontrol::TdxDockingType AType, int Index);
	virtual bool __fastcall CanAcceptSideContainerItems(Dxdockcontrol::TdxSideContainerDockSite* AContainer);
	virtual void __fastcall AssignTabContainerSiteProperies(Dxdockcontrol::TdxTabContainerDockSite* ASite);
	virtual bool __fastcall CanAcceptTabContainerItems(Dxdockcontrol::TdxTabContainerDockSite* AContainer);
	virtual void __fastcall CalculateNC(System::Types::TRect &ARect);
	virtual void __fastcall InvalidateCaptionArea(void);
	virtual void __fastcall NCPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall NeedInvalidateCaptionArea(void);
	virtual bool __fastcall HasBorder(void);
	virtual bool __fastcall HasCaption(void);
	virtual bool __fastcall HasTabs(void);
	__property Dxdockcontrol::TdxDockingTabControlViewInfo* TabControlViewInfo = {read=FTabControlViewInfo};
	__property System::Types::TRect TabRect = {read=GetTabRect};
	__property TdxDockPanelTabControlController* TabsController = {read=FTabsController};
	__property System::Types::TRect TabsRect = {read=GetTabsRect};
	
public:
	__fastcall virtual TdxDockPanel(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDockPanel(void);
	virtual bool __fastcall CanActive(void);
	virtual bool __fastcall CanAutoHide(void);
	virtual bool __fastcall CanDock(void);
	virtual bool __fastcall CanDockHost(Dxdockcontrol::TdxCustomDockControl* AControl, Dxdockcontrol::TdxDockingType AType);
	virtual bool __fastcall CanMaximize(void);
	
__published:
	__property AllowDock = {default=31};
	__property AllowDockClients = {default=31};
	__property AllowFloating;
	__property AutoHide;
	__property Caption = {default=0};
	__property CaptionButtons = {default=7};
	__property Dockable = {default=1};
	__property ImageIndex = {default=-1};
	__property ShowCaption = {default=1};
	__property bool ShowSingleTab = {read=FShowSingleTab, write=SetShowSingleTab, default=0};
	__property TdxDockPanelTabControlProperties* TabsProperties = {read=FTabsProperties, write=SetTabsProperties};
	__property OnActivate;
	__property OnAutoHideChanged;
	__property OnAutoHideChanging;
	__property OnCanResize;
	__property OnClose;
	__property OnCloseQuery;
	__property OnCreateFloatSite;
	__property OnCreateSideContainer;
	__property OnCreateTabContainer;
	__property OnCustomDrawDockingSelection;
	__property OnCustomDrawResizingSelection;
	__property OnDock;
	__property OnDocking;
	__property OnEndDocking;
	__property OnEndResizing;
	__property OnGetAutoHidePosition;
	__property OnLayoutChanged;
	__property OnMakeFloating;
	__property OnResize;
	__property OnResizing;
	__property OnRestoreDockPosition;
	__property OnStartDocking;
	__property OnStartResizing;
	__property OnStoreDockPosition;
	__property OnUnDock;
	__property OnUpdateDockZones;
	__property OnUpdateResizeZones;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDockPanel(HWND ParentWindow) : Dxdockcontrol::TdxCustomDockControl(ParentWindow) { }
	
private:
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
	operator Cxcontrols::IcxControlComponentState*(void) { return (Cxcontrols::IcxControlComponentState*)&__IcxTabControl; }
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


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdockpanel */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKPANEL)
using namespace Dxdockpanel;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockpanelHPP
