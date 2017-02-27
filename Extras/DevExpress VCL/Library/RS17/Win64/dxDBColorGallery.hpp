// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDBColorGallery.pas' rev: 24.00 (Win64)

#ifndef DxdbcolorgalleryHPP
#define DxdbcolorgalleryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <dxGallery.hpp>	// Pascal unit
#include <dxColorGallery.hpp>	// Pascal unit
#include <dxGalleryControl.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbcolorgallery
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBColorGallery;
class PASCALIMPLEMENTATION TdxDBColorGallery : public Dxcolorgallery::TdxCustomColorGallery
{
	typedef Dxcolorgallery::TdxCustomColorGallery inherited;
	
private:
	Cxdb::TcxDBDataBinding* __fastcall GetDataBinding(void);
	void __fastcall SetDataBinding(Cxdb::TcxDBDataBinding* Value);
	void __fastcall DataChange(void);
	void __fastcall DataSetChange(void);
	void __fastcall UpdateData(void);
	
protected:
	Cxdb::TcxDBDataBinding* FDataBinding;
	virtual void __fastcall DoClickItem(Dxgallery::TdxGalleryItem* AItem);
	
public:
	__fastcall virtual TdxDBColorGallery(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDBColorGallery(void);
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Enabled = {default=1};
	__property Font;
	__property PopupMenu;
	__property Visible = {default=1};
	__property AutoSizeMode = {default=3};
	__property BorderStyle = {default=1};
	__property LookAndFeel;
	__property ColorPalette = {default=0};
	__property ColorSet = {default=0};
	__property Cxdb::TcxDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property ItemSize = {default=0};
	__property OnChange;
	__property OnGetCustomColorSet;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBColorGallery(HWND ParentWindow) : Dxcolorgallery::TdxCustomColorGallery(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbcolorgallery */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBCOLORGALLERY)
using namespace Dxdbcolorgallery;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbcolorgalleryHPP
