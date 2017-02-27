// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDBColorEdit.pas' rev: 24.00 (Win64)

#ifndef DxdbcoloreditHPP
#define DxdbcoloreditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <dxColorEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbcoloredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBColorEdit;
class PASCALIMPLEMENTATION TdxDBColorEdit : public Dxcoloredit::TdxCustomColorEdit
{
	typedef Dxcoloredit::TdxCustomColorEdit inherited;
	
private:
	HIDESBASE Dxcoloredit::TdxColorEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(Dxcoloredit::TdxColorEditProperties* Value);
	Cxdbedit::TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdbedit::TcxDBEditDataBinding* const Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	
__published:
	__property Anchors = {default=3};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property Cxdbedit::TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Dxcoloredit::TdxColorEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
public:
	/* TdxCustomColorEdit.Create */ inline __fastcall virtual TdxDBColorEdit(System::Classes::TComponent* AOwner)/* overload */ : Dxcoloredit::TdxCustomColorEdit(AOwner) { }
	/* TdxCustomColorEdit.Destroy */ inline __fastcall virtual ~TdxDBColorEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxDBColorEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Dxcoloredit::TdxCustomColorEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBColorEdit(HWND ParentWindow) : Dxcoloredit::TdxCustomColorEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbcoloredit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBCOLOREDIT)
using namespace Dxdbcoloredit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbcoloreditHPP
