// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridPopupMenu.pas' rev: 24.00 (Win64)

#ifndef CxgridpopupmenuHPP
#define CxgridpopupmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridUIHelper.hpp>	// Pascal unit
#include <cxGridUICustomTableHelper.hpp>	// Pascal unit
#include <cxGridUITableHelper.hpp>	// Pascal unit
#include <cxGridUIBandedTableHelper.hpp>	// Pascal unit
#include <cxGridUICardHelper.hpp>	// Pascal unit
#include <cxGridCustomPopupMenu.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridpopupmenu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridPopupMenu;
class PASCALIMPLEMENTATION TcxGridPopupMenu : public Cxgridcustompopupmenu::TcxCustomGridPopupMenu
{
	typedef Cxgridcustompopupmenu::TcxCustomGridPopupMenu inherited;
	
private:
	bool FAlwaysFireOnPopup;
	Cxgrid::TcxGrid* FGrid;
	Cxgridcustompopupmenu::TcxGridDefaultPopupMenu* FGridDefaultPopupMenu;
	Cxgriduihelper::TcxGridOperationHelper* FGridOperationHelper;
	Cxgridcustomview::TcxCustomGridView* FHitGridView;
	System::Types::TPoint FHitPoint;
	Cxgridcustomview::TcxCustomGridHitTest* FHitTest;
	Cxgridcustompopupmenu::TcxGridViewHitType FHitType;
	Cxgrid::TcxCustomGridNotification* FMouseupNotification;
	Cxgridcustompopupmenu::TcxGridPopupMenuItemClickProc FOnClick;
	Cxgridcustompopupmenu::TcxGridBeforePopupProc FOnPopup;
	bool FUseBuiltInPopupMenus;
	void __fastcall CreateBuiltInPopupMenus(void);
	void __fastcall FreeBuiltInPopupMenus(void);
	Cxgridcustompopupmenu::TcxPopupMenuInfos* __fastcall GetPopupMenus(void);
	void __fastcall SetUseBuiltInPopupMenus(const bool Value);
	void __fastcall SetGrid(Cxgrid::TcxGrid* const AValue);
	void __fastcall SetPopupMenus(Cxgridcustompopupmenu::TcxPopupMenuInfos* const AValue);
	bool __fastcall TryPopupAsIcxPopupMenuIntf(System::Classes::TComponent* APopupMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Types::TPoint APoint);
	bool __fastcall TryPopupAsIDoPopupIntf(System::Classes::TComponent* APopupMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Types::TPoint APoint);
	bool __fastcall TryPopupAsVCLPopupMenu(System::Classes::TComponent* APopupMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Types::TPoint APoint);
	void __fastcall SetHitTest(Cxgridcustomview::TcxCustomGridHitTest* const Value);
	
protected:
	virtual bool __fastcall DoOnPopup(System::Classes::TComponent* ASenderMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall DoPopup(bool AAPPSKeyPressed);
	virtual Cxgridcustompopupmenu::TcxPopupMenuInfo* __fastcall GetPopupMenuInfo(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridView* const AView, bool SearchDefault = true)/* overload */;
	__property Cxgriduihelper::TcxGridOperationHelper* GridOperationHelper = {read=FGridOperationHelper};
	
public:
	__fastcall virtual TcxGridPopupMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridPopupMenu(void);
	virtual bool __fastcall CheckShortCuts(Winapi::Messages::TWMKey &Message);
	virtual Cxgridcustompopupmenu::TcxPopupMenuInfo* __fastcall FindPopupMenuInfo(Cxgridcustomview::TcxCustomGridView* const AView, Cxgridcustompopupmenu::TcxGridViewHitType AHitType, Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	System::Classes::TComponent* __fastcall GetBuiltInPopupMenuByClass(const Cxgridcustompopupmenu::TcxPopupMenuClass AMenuClass);
	virtual void __fastcall RegisterPopupMenu(System::Classes::TComponent* const AMenu, Cxgridcustompopupmenu::TcxGridViewHitTypes AHitTypes, Cxgridcustompopupmenu::TcxGridOnPopupProc ADoPopupProc, Cxgridcustomview::TcxCustomGridView* const AView)/* overload */;
	virtual void __fastcall RegisterPopupMenu(System::Classes::TComponent* const AMenu, Cxgridcustompopupmenu::TcxGridViewHitTypes AHitTypes, Cxgridcustompopupmenu::TcxGridOnPopupProc ADoPopupProc, Cxgridcustomview::TcxCustomGridViewClass AViewClass)/* overload */;
	virtual void __fastcall UnregisterPopupMenu(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridView* const AGridView, Cxgridcustompopupmenu::TcxGridViewHitTypes AHitTypes = Cxgridcustompopupmenu::TcxGridViewHitTypes() )/* overload */;
	virtual void __fastcall UnregisterPopupMenu(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridViewClass AGridViewClass, Cxgridcustompopupmenu::TcxGridViewHitTypes AHitTypes = Cxgridcustompopupmenu::TcxGridViewHitTypes() )/* overload */;
	__property Cxgridcustompopupmenu::TcxGridDefaultPopupMenu* BuiltInPopupMenus = {read=FGridDefaultPopupMenu};
	__property Cxgridcustomview::TcxCustomGridView* HitGridView = {read=FHitGridView};
	__property System::Types::TPoint HitPoint = {read=FHitPoint};
	__property Cxgridcustomview::TcxCustomGridHitTest* HitTest = {read=FHitTest, write=SetHitTest};
	__property Cxgridcustompopupmenu::TcxGridViewHitType HitType = {read=FHitType, nodefault};
	
__published:
	__property Cxgrid::TcxGrid* Grid = {read=FGrid, write=SetGrid};
	__property Cxgridcustompopupmenu::TcxPopupMenuInfos* PopupMenus = {read=GetPopupMenus, write=SetPopupMenus};
	__property bool UseBuiltInPopupMenus = {read=FUseBuiltInPopupMenus, write=SetUseBuiltInPopupMenus, default=1};
	__property Cxgridcustompopupmenu::TcxGridPopupMenuItemClickProc OnMenuItemClick = {read=FOnClick, write=FOnClick};
	__property Cxgridcustompopupmenu::TcxGridBeforePopupProc OnPopup = {read=FOnPopup, write=FOnPopup};
	__property bool AlwaysFireOnPopup = {read=FAlwaysFireOnPopup, write=FAlwaysFireOnPopup, default=0};
/* Hoisted overloads: */
	
public:
	inline Cxgridcustompopupmenu::TcxPopupMenuInfo* __fastcall  GetPopupMenuInfo(System::Classes::TComponent* const AMenu, Cxgridcustomview::TcxCustomGridViewClass AViewClass, bool ASearchDefault = true){ return Cxgridcustompopupmenu::TcxCustomGridPopupMenu::GetPopupMenuInfo(AMenu, AViewClass, ASearchDefault); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxGridPopupMenu* ActiveGridPopupMenu;
}	/* namespace Cxgridpopupmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDPOPUPMENU)
using namespace Cxgridpopupmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridpopupmenuHPP
