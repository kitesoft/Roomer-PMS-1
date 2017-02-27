// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTLdxBarBuiltInMenu.pas' rev: 24.00 (Win32)

#ifndef CxtldxbarbuiltinmenuHPP
#define CxtldxbarbuiltinmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarBuiltInMenu.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtldxbarbuiltinmenu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxTreeListdxBarBuiltInMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTreeListdxBarBuiltInMenu : public Cxtl::TcxTreeListCustomBuiltInMenu
{
	typedef Cxtl::TcxTreeListCustomBuiltInMenu inherited;
	
private:
	Dxbar::TdxBarPopupMenu* __fastcall GetBarPopup(void);
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	
protected:
	virtual System::Classes::TComponent* __fastcall CreateMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true, Cxtl::TcxTreeListBuiltInMenuItemType AItemType = (Cxtl::TcxTreeListBuiltInMenuItemType)(0x0), bool AChecked = false, int AImageIndex = 0xffffffff, bool AWithSeparator = false, bool AInternal = true);
	virtual void __fastcall CreatePopupMenu(void);
	virtual void __fastcall DestroyPopupMenu(void);
	virtual System::Classes::TComponentClass __fastcall GetPopupClass(void);
	virtual System::Classes::TComponent* __fastcall GetPopupMenu(void);
	
public:
	__property Dxbar::TdxBarPopupMenu* BarPopup = {read=GetBarPopup};
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxTreeListdxBarBuiltInMenu(System::Classes::TPersistent* AOwner) : Cxtl::TcxTreeListCustomBuiltInMenu(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTreeListdxBarBuiltInMenu(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxtldxbarbuiltinmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTLDXBARBUILTINMENU)
using namespace Cxtldxbarbuiltinmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtldxbarbuiltinmenuHPP
