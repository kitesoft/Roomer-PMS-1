// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBCheckGroup.pas' rev: 24.00 (Win32)

#ifndef CxdbcheckgroupHPP
#define CxdbcheckgroupHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxCheckGroup.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbcheckgroup
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBCheckGroupButton;
class PASCALIMPLEMENTATION TcxDBCheckGroupButton : public Cxcheckgroup::TcxCheckGroupButton
{
	typedef Cxcheckgroup::TcxCheckGroupButton inherited;
	
private:
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxDBCheckGroupButton(System::Classes::TComponent* AOwner)/* overload */;
public:
	/* TcxCheckGroupButton.Destroy */ inline __fastcall virtual ~TcxDBCheckGroupButton(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCheckGroupButton(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcheckgroup::TcxCheckGroupButton(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCheckGroupButton(HWND ParentWindow) : Cxcheckgroup::TcxCheckGroupButton(ParentWindow) { }
	
};


class DELPHICLASS TcxDBCheckGroup;
class PASCALIMPLEMENTATION TcxDBCheckGroup : public Cxcheckgroup::TcxCheckGroup
{
	typedef Cxcheckgroup::TcxCheckGroup inherited;
	
private:
	HIDESBASE Cxcheckgroup::TcxCheckGroupProperties* __fastcall GetActiveProperties(void);
	Cxdbedit::TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxcheckgroup::TcxCheckGroupProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdbedit::TcxDBEditDataBinding* const Value);
	HIDESBASE void __fastcall SetProperties(Cxcheckgroup::TcxCheckGroupProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	virtual Vcl::Controls::TWinControl* __fastcall GetButtonInstance(void);
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxcheckgroup::TcxCheckGroupProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property Caption = {default=0};
	__property Constraints;
	__property Cxdbedit::TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property Enabled = {default=1};
	__property ParentBackground = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Cxcheckgroup::TcxCheckGroupProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property StatesItems;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnFocusChanged;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomButtonGroup.Destroy */ inline __fastcall virtual ~TcxDBCheckGroup(void) { }
	
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxDBCheckGroup(System::Classes::TComponent* AOwner)/* overload */ : Cxcheckgroup::TcxCheckGroup(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCheckGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcheckgroup::TcxCheckGroup(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCheckGroup(HWND ParentWindow) : Cxcheckgroup::TcxCheckGroup(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbcheckgroup */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBCHECKGROUP)
using namespace Cxdbcheckgroup;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbcheckgroupHPP
