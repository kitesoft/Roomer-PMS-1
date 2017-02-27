// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPCGoDialog.pas' rev: 24.00 (Win64)

#ifndef CxpcgodialogHPP
#define CxpcgodialogHPP

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
#include <cxPC.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpcgodialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPCCustomInternalPopupMenu;
class PASCALIMPLEMENTATION TcxPCCustomInternalPopupMenu : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::TObject* FOwner;
	System::Classes::TComponent* FPopupOwner;
	System::Classes::TComponent* FPopupMenu;
	
protected:
	virtual System::Classes::TComponent* __fastcall CreateMenuItem(const System::UnicodeString ACaption, int ACommand, bool AChecked = false, int AImageIndex = 0xffffffff) = 0 ;
	virtual void __fastcall CreatePopupMenu(void);
	virtual void __fastcall DestroyPopupMenu(void);
	virtual System::Classes::TComponentClass __fastcall GetPopupClass(void) = 0 ;
	virtual System::Classes::TComponent* __fastcall GetPopupMenu(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall MenuItemClickHandler(System::TObject* Sender);
	virtual bool __fastcall Popup(int X, int Y);
	virtual void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AImages) = 0 ;
	__property System::Classes::TComponent* PopupMenu = {read=GetPopupMenu, write=FPopupMenu};
	__property System::TObject* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxPCCustomInternalPopupMenu(System::TObject* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPCCustomInternalPopupMenu(void) { }
	
};


class DELPHICLASS TcxPCInternalPopupMenu;
class PASCALIMPLEMENTATION TcxPCInternalPopupMenu : public TcxPCCustomInternalPopupMenu
{
	typedef TcxPCCustomInternalPopupMenu inherited;
	
protected:
	virtual System::Classes::TComponent* __fastcall CreateMenuItem(const System::UnicodeString ACaption, int ACommand, bool AChecked, int AImageIndex);
	virtual System::Classes::TComponentClass __fastcall GetPopupClass(void);
	virtual void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AImages);
	
public:
	__fastcall virtual ~TcxPCInternalPopupMenu(void);
public:
	/* TcxPCCustomInternalPopupMenu.Create */ inline __fastcall virtual TcxPCInternalPopupMenu(System::TObject* AOwner) : TcxPCCustomInternalPopupMenu(AOwner) { }
	
};


typedef System::TMetaClass* TcxPCCustomInternalPopupMenuClass;

class DELPHICLASS TcxPCGoDialog;
class PASCALIMPLEMENTATION TcxPCGoDialog : public Cxpc::TcxPCCustomGoDialog
{
	typedef Cxpc::TcxPCCustomGoDialog inherited;
	
private:
	TcxPCCustomInternalPopupMenu* FInternalPopup;
	void __fastcall CreateItems(void);
	TcxPCCustomInternalPopupMenu* __fastcall GetPCPopup(void);
	
protected:
	void __fastcall DoClick(int ATabVisibleIndex);
	
public:
	__fastcall virtual ~TcxPCGoDialog(void);
	virtual bool __fastcall Popup(int X, int Y);
public:
	/* TcxPCCustomGoDialog.Create */ inline __fastcall virtual TcxPCGoDialog(Cxpc::_di_IcxTabControl ATabControl) : Cxpc::TcxPCCustomGoDialog(ATabControl) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxPCCustomInternalPopupMenuClass cxPCInternalPopupMenuClass;
}	/* namespace Cxpcgodialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPCGODIALOG)
using namespace Cxpcgodialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpcgodialogHPP
