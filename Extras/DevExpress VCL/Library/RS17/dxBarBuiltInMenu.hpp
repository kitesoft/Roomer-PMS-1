// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarBuiltInMenu.pas' rev: 24.00 (Win32)

#ifndef DxbarbuiltinmenuHPP
#define DxbarbuiltinmenuHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarbuiltinmenu
{
//-- type declarations -------------------------------------------------------
enum TdxBarBuiltInMenuItemType : unsigned char { bmitDefault, bmitChecked, bmitSubItem };

class DELPHICLASS TdxBarBuiltInMenuHelper;
class PASCALIMPLEMENTATION TdxBarBuiltInMenuHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxbar::TdxBarManager* FBarManager;
	System::Contnrs::TObjectList* FItems;
	Dxbar::TdxBarPopupMenu* FPopupMenu;
	System::Classes::TNotifyEvent FOnClick;
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* const Value);
	
protected:
	void __fastcall MenuItemClickHandler(System::TObject* Sender);
	
public:
	__fastcall TdxBarBuiltInMenuHelper(void);
	__fastcall virtual ~TdxBarBuiltInMenuHelper(void);
	System::Classes::TComponent* __fastcall CreateMenuItem(const System::UnicodeString ACaption, int ACommand, bool AChecked, int AImageIndex)/* overload */;
	System::Classes::TComponent* __fastcall CreateMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, int ACommand, bool AEnabled = true, TdxBarBuiltInMenuItemType AItemType = (TdxBarBuiltInMenuItemType)(0x0), bool AChecked = false, int AImageIndex = 0xffffffff, bool AWithSeparator = false, Vcl::Graphics::TBitmap* AGlyph = (Vcl::Graphics::TBitmap*)(0x0))/* overload */;
	void __fastcall CreatePopupMenu(void);
	void __fastcall DestroyPopupMenu(void);
	__property Dxbar::TdxBarManager* BarManager = {read=FBarManager};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property Dxbar::TdxBarPopupMenu* PopupMenu = {read=FPopupMenu};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxBarBuiltInMenuHelper* __fastcall dxBarPopupHelper(void);
}	/* namespace Dxbarbuiltinmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARBUILTINMENU)
using namespace Dxbarbuiltinmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarbuiltinmenuHPP
