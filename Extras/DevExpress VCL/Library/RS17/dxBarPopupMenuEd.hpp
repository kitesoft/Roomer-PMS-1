// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarPopupMenuEd.pas' rev: 24.00 (Win32)

#ifndef DxbarpopupmenuedHPP
#define DxbarpopupmenuedHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarpopupmenued
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarSubMenuEditor;
class PASCALIMPLEMENTATION TdxBarSubMenuEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	
private:
	Dxbar::TdxBarItemLinks* FItemLinks;
	System::Classes::TComponent* FItemLinksOwner;
	int FSubMenuWidth;
	void __fastcall CorrectBounds(void);
	Dxbar::TdxBarSubMenuControl* __fastcall GetSubMenuControl(void);
	void __fastcall SetItemLinks(Dxbar::TdxBarItemLinks* Value);
	HIDESBASE MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	HIDESBASE MESSAGE void __fastcall WMMove(Winapi::Messages::TWMMove &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Winapi::Messages::TWMNCHitMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property Dxbar::TdxBarSubMenuControl* SubMenuControl = {read=GetSubMenuControl};
	
public:
	__fastcall virtual TdxBarSubMenuEditor(System::Classes::TComponent* AOwner);
	HIDESBASE void __fastcall Release(void);
	__property Dxbar::TdxBarItemLinks* ItemLinks = {read=FItemLinks, write=SetItemLinks};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarSubMenuEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxBarSubMenuEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarSubMenuEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowdxBarSubMenuEditor(Dxbar::TdxBarItemLinks* AItemLinks);
extern PACKAGE TdxBarSubMenuEditor* __fastcall dxBarSubMenuEditor(void);
}	/* namespace Dxbarpopupmenued */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARPOPUPMENUED)
using namespace Dxbarpopupmenued;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarpopupmenuedHPP
