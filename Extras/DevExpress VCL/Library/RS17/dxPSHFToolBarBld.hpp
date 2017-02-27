// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSHFToolBarBld.pas' rev: 24.00 (Win32)

#ifndef DxpshftoolbarbldHPP
#define DxpshftoolbarbldHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpshftoolbarbld
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TdxPSInsertMacrosEvent)(System::TObject* Sender, const System::UnicodeString AMacrosValue);

class DELPHICLASS TdxPSHFToolBarHelper;
class PASCALIMPLEMENTATION TdxPSHFToolBarHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FButtons;
	Vcl::Imglist::TCustomImageList* FButtonsImageList;
	Vcl::Controls::TWinControl* FContainer;
	Vcl::Graphics::TBitmap* FDropDownGlyph;
	System::Classes::TStringList* FFunctionsList;
	Vcl::Menus::TPopupMenu* FMoreFunctionsPopupMenu;
	Cxgraphics::TcxImageList* FMoreFunctionsPopupMenuImages;
	System::Classes::TNotifyEvent FOnAutoTextClick;
	TdxPSInsertMacrosEvent FOnInsertMacros;
	System::UnicodeString __fastcall GetAutoTextButtonCaption(void);
	void __fastcall DoAutoTextItemClick(System::TObject* Sender);
	void __fastcall DoButtonClick(System::TObject* Sender);
	void __fastcall DoImageItemClick(System::TObject* Sender, int AItemIndex);
	void __fastcall DoImagePopup(System::TObject* Sender);
	void __fastcall DoInsertMacros(const System::UnicodeString AValue);
	void __fastcall DoShowPopup(System::TObject* Sender);
	
protected:
	int __fastcall CalculateMenuButtonWidth(void);
	int __fastcall CalculateNextButtonOffset(void);
	int __fastcall CalculateRestSpace(void);
	Cxbuttons::TcxButton* __fastcall CreateButton(int AWidth, int ATag, System::Classes::TNotifyEvent AClickEvent);
	void __fastcall CreateAutoTextMenuButton(int AMenuButtonWidth, System::Classes::TStrings* AAutoHFTextEntries);
	__property System::UnicodeString AutoTextButtonCaption = {read=GetAutoTextButtonCaption};
	__property Vcl::Controls::TWinControl* Container = {read=FContainer};
	__property Vcl::Graphics::TBitmap* DropDownGlyph = {read=FDropDownGlyph};
	__property System::Classes::TStringList* FunctionsList = {read=FFunctionsList};
	__property Vcl::Menus::TPopupMenu* MoreFunctionsPopupMenu = {read=FMoreFunctionsPopupMenu};
	__property Cxgraphics::TcxImageList* MoreFunctionsPopupMenuImages = {read=FMoreFunctionsPopupMenuImages};
	
public:
	__fastcall virtual TdxPSHFToolBarHelper(Vcl::Controls::TWinControl* AContainer);
	__fastcall virtual ~TdxPSHFToolBarHelper(void);
	void __fastcall Build(System::Classes::TStrings* AFunctionList, System::Classes::TStrings* AAutoTextEntries, Cxgraphics::TcxImageCollection* AImageCollection, bool AIncludeAutoTextEntries);
	__property Vcl::Imglist::TCustomImageList* ButtonsImageList = {read=FButtonsImageList, write=FButtonsImageList};
	__property System::Classes::TNotifyEvent OnAutoTextClick = {read=FOnAutoTextClick, write=FOnAutoTextClick};
	__property TdxPSInsertMacrosEvent OnInsertMacros = {read=FOnInsertMacros, write=FOnInsertMacros};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpshftoolbarbld */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSHFTOOLBARBLD)
using namespace Dxpshftoolbarbld;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpshftoolbarbldHPP
