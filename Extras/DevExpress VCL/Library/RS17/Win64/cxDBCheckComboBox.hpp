// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBCheckComboBox.pas' rev: 24.00 (Win64)

#ifndef CxdbcheckcomboboxHPP
#define CxdbcheckcomboboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxCheckComboBox.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbcheckcombobox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBCheckComboBox;
class PASCALIMPLEMENTATION TcxDBCheckComboBox : public Cxcheckcombobox::TcxCustomCheckComboBox
{
	typedef Cxcheckcombobox::TcxCustomCheckComboBox inherited;
	
private:
	HIDESBASE Cxcheckcombobox::TcxCheckComboBoxProperties* __fastcall GetActiveProperties(void);
	Cxdbedit::TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxcheckcombobox::TcxCheckComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdbedit::TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxcheckcombobox::TcxCheckComboBoxProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxcheckcombobox::TcxCheckComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property Cxdbedit::TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Cxcheckcombobox::TcxCheckComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxDBCheckComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBCheckComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxcheckcombobox::TcxCustomCheckComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCheckComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcheckcombobox::TcxCustomCheckComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCheckComboBox(HWND ParentWindow) : Cxcheckcombobox::TcxCustomCheckComboBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbcheckcombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBCHECKCOMBOBOX)
using namespace Cxdbcheckcombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbcheckcomboboxHPP
