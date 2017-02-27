// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridStdPopupMenu.pas' rev: 24.00 (Win32)

#ifndef CxgridstdpopupmenuHPP
#define CxgridstdpopupmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGridMenuOperations.hpp>	// Pascal unit
#include <cxGridCustomPopupMenu.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridstdpopupmenu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridPopupMenuItem;
class PASCALIMPLEMENTATION TcxGridPopupMenuItem : public Vcl::Menus::TMenuItem
{
	typedef Vcl::Menus::TMenuItem inherited;
	
private:
	Cxgridmenuoperations::TcxGridPopupMenuOperation* FOperation;
	
public:
	__fastcall virtual TcxGridPopupMenuItem(System::Classes::TComponent* AOwner, Cxgridmenuoperations::TcxGridPopupMenuOperation* AOperation);
	__property Cxgridmenuoperations::TcxGridPopupMenuOperation* Operation = {read=FOperation};
public:
	/* TMenuItem.Destroy */ inline __fastcall virtual ~TcxGridPopupMenuItem(void) { }
	
};


class DELPHICLASS TcxGridStdPopupMenu;
class PASCALIMPLEMENTATION TcxGridStdPopupMenu : public Vcl::Menus::TPopupMenu
{
	typedef Vcl::Menus::TPopupMenu inherited;
	
private:
	Cxgridmenuoperations::TcxGridPopupMenuOperations* FOperations;
	
protected:
	Cxgridcustompopupmenu::TcxGridOnPopupProc __fastcall GetPopupHandler(void);
	bool __fastcall CanPopup(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall AdvancedDrawItem(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall CreateMenuItems(void);
	virtual void __fastcall DoPopup(System::TObject* Sender);
	virtual void __fastcall GridMenuPopup(System::Classes::TComponent* ASenderMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, int X, int Y);
	virtual bool __fastcall HasDynamicContent(void);
	void __fastcall InitItems(Vcl::Menus::TMenuItem* AItems);
	virtual void __fastcall MeasureItem(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, int &Width, int &Height);
	virtual Cxgridmenuoperations::TcxGridPopupMenuOperationsClass __fastcall GetOperationsClass(void) = 0 ;
	__property Cxgridmenuoperations::TcxGridPopupMenuOperations* Operations = {read=FOperations};
	
public:
	__fastcall virtual TcxGridStdPopupMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridStdPopupMenu(void);
private:
	void *__IcxGridPopupMenu;	/* Cxgridcustompopupmenu::IcxGridPopupMenu */
	void *__IDoPopup;	/* Cxgridcustompopupmenu::IDoPopup */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {302C3B32-D753-43A6-BAE2-F513EB4F9399}
	operator Cxgridcustompopupmenu::_di_IcxGridPopupMenu()
	{
		Cxgridcustompopupmenu::_di_IcxGridPopupMenu intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustompopupmenu::IcxGridPopupMenu*(void) { return (Cxgridcustompopupmenu::IcxGridPopupMenu*)&__IcxGridPopupMenu; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {41999EDE-B9D9-4808-9D01-61B09DF700FA}
	operator Cxgridcustompopupmenu::_di_IDoPopup()
	{
		Cxgridcustompopupmenu::_di_IDoPopup intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustompopupmenu::IDoPopup*(void) { return (Cxgridcustompopupmenu::IDoPopup*)&__IDoPopup; }
	#endif
	
};


class DELPHICLASS TcxGridStdHeaderMenu;
class PASCALIMPLEMENTATION TcxGridStdHeaderMenu : public TcxGridStdPopupMenu
{
	typedef TcxGridStdPopupMenu inherited;
	
protected:
	virtual Cxgridmenuoperations::TcxGridPopupMenuOperationsClass __fastcall GetOperationsClass(void);
public:
	/* TcxGridStdPopupMenu.Create */ inline __fastcall virtual TcxGridStdHeaderMenu(System::Classes::TComponent* AOwner) : TcxGridStdPopupMenu(AOwner) { }
	/* TcxGridStdPopupMenu.Destroy */ inline __fastcall virtual ~TcxGridStdHeaderMenu(void) { }
	
};


class DELPHICLASS TcxGridStdFooterMenu;
class PASCALIMPLEMENTATION TcxGridStdFooterMenu : public TcxGridStdPopupMenu
{
	typedef TcxGridStdPopupMenu inherited;
	
protected:
	virtual Cxgridmenuoperations::TcxGridPopupMenuOperationsClass __fastcall GetOperationsClass(void);
public:
	/* TcxGridStdPopupMenu.Create */ inline __fastcall virtual TcxGridStdFooterMenu(System::Classes::TComponent* AOwner) : TcxGridStdPopupMenu(AOwner) { }
	/* TcxGridStdPopupMenu.Destroy */ inline __fastcall virtual ~TcxGridStdFooterMenu(void) { }
	
};


class DELPHICLASS TcxGridStdGroupRowMenu;
class PASCALIMPLEMENTATION TcxGridStdGroupRowMenu : public TcxGridStdPopupMenu
{
	typedef TcxGridStdPopupMenu inherited;
	
protected:
	virtual Cxgridmenuoperations::TcxGridPopupMenuOperationsClass __fastcall GetOperationsClass(void);
	virtual void __fastcall GridMenuPopup(System::Classes::TComponent* ASenderMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, int X, int Y);
	virtual bool __fastcall HasDynamicContent(void);
public:
	/* TcxGridStdPopupMenu.Create */ inline __fastcall virtual TcxGridStdGroupRowMenu(System::Classes::TComponent* AOwner) : TcxGridStdPopupMenu(AOwner) { }
	/* TcxGridStdPopupMenu.Destroy */ inline __fastcall virtual ~TcxGridStdGroupRowMenu(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxgridmenuoperations::TcxGridPopupMenuOperation* __fastcall cxGetGridPopupMenuOperation(System::Classes::TComponent* AMenuItem);
}	/* namespace Cxgridstdpopupmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDSTDPOPUPMENU)
using namespace Cxgridstdpopupmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridstdpopupmenuHPP
