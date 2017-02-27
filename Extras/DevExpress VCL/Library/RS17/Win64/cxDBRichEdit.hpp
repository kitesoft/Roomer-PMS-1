// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBRichEdit.pas' rev: 24.00 (Win64)

#ifndef CxdbricheditHPP
#define CxdbricheditHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbrichedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBRichEditDataBinding;
class PASCALIMPLEMENTATION TcxDBRichEditDataBinding : public Cxdbedit::TcxDBTextEditDataBinding
{
	typedef Cxdbedit::TcxDBTextEditDataBinding inherited;
	
protected:
	virtual void __fastcall UpdateData(void);
public:
	/* TcxDBEditDataBinding.Create */ inline __fastcall virtual TcxDBRichEditDataBinding(Cxedit::TcxCustomEdit* AEdit) : Cxdbedit::TcxDBTextEditDataBinding(AEdit) { }
	/* TcxDBEditDataBinding.Destroy */ inline __fastcall virtual ~TcxDBRichEditDataBinding(void) { }
	
};


class DELPHICLASS TcxDBRichEdit;
class PASCALIMPLEMENTATION TcxDBRichEdit : public Cxrichedit::TcxCustomRichEdit
{
	typedef Cxrichedit::TcxCustomRichEdit inherited;
	
private:
	HIDESBASE Cxrichedit::TcxRichEditProperties* __fastcall GetActiveProperties(void);
	TcxDBRichEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxrichedit::TcxRichEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBRichEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxrichedit::TcxRichEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall EditingChanged(void);
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	virtual bool __fastcall RealReadOnly(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxrichedit::TcxRichEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property Constraints;
	__property TcxDBRichEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxrichedit::TcxRichEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
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
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomRichEdit.Create */ inline __fastcall virtual TcxDBRichEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxrichedit::TcxCustomRichEdit(AOwner) { }
	/* TcxCustomRichEdit.Destroy */ inline __fastcall virtual ~TcxDBRichEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBRichEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxrichedit::TcxCustomRichEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBRichEdit(HWND ParentWindow) : Cxrichedit::TcxCustomRichEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbrichedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBRICHEDIT)
using namespace Cxdbrichedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbricheditHPP
