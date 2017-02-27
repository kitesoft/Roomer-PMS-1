// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPCdxBarPopupMenu.pas' rev: 24.00 (Win32)

#ifndef CxpcdxbarpopupmenuHPP
#define CxpcdxbarpopupmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxPCGoDialog.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarBuiltInMenu.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpcdxbarpopupmenu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPCdxBarInternalPopupMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCdxBarInternalPopupMenu : public Cxpcgodialog::TcxPCCustomInternalPopupMenu
{
	typedef Cxpcgodialog::TcxPCCustomInternalPopupMenu inherited;
	
private:
	Dxbar::TdxBarPopupMenu* __fastcall GetBarPopup(void);
	
protected:
	virtual System::Classes::TComponent* __fastcall CreateMenuItem(const System::UnicodeString ACaption, int ACommand, bool AChecked, int AImageIndex);
	virtual void __fastcall CreatePopupMenu(void);
	virtual void __fastcall DestroyPopupMenu(void);
	virtual System::Classes::TComponentClass __fastcall GetPopupClass(void);
	virtual System::Classes::TComponent* __fastcall GetPopupMenu(void);
	virtual void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AImages);
	
public:
	__property Dxbar::TdxBarPopupMenu* BarPopup = {read=GetBarPopup};
public:
	/* TcxPCCustomInternalPopupMenu.Create */ inline __fastcall virtual TcxPCdxBarInternalPopupMenu(System::TObject* AOwner) : Cxpcgodialog::TcxPCCustomInternalPopupMenu(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPCdxBarInternalPopupMenu(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpcdxbarpopupmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPCDXBARPOPUPMENU)
using namespace Cxpcdxbarpopupmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpcdxbarpopupmenuHPP
