// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDBZoomTrackBar.pas' rev: 24.00 (Win32)

#ifndef DxdbzoomtrackbarHPP
#define DxdbzoomtrackbarHPP

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
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxZoomTrackBar.hpp>	// Pascal unit
#include <cxTrackBar.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbzoomtrackbar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBZoomTrackBar;
class PASCALIMPLEMENTATION TdxDBZoomTrackBar : public Dxzoomtrackbar::TdxCustomZoomTrackBar
{
	typedef Dxzoomtrackbar::TdxCustomZoomTrackBar inherited;
	
private:
	HIDESBASE Dxzoomtrackbar::TdxZoomTrackBarProperties* __fastcall GetActiveProperties(void);
	Cxdbedit::TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Dxzoomtrackbar::TdxZoomTrackBarProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdbedit::TcxDBEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Dxzoomtrackbar::TdxZoomTrackBarProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Dxzoomtrackbar::TdxZoomTrackBarProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Constraints;
	__property Cxdbedit::TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Dxzoomtrackbar::TdxZoomTrackBarProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent = {default=0};
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
	/* TdxCustomZoomTrackBar.Create */ inline __fastcall virtual TdxDBZoomTrackBar(System::Classes::TComponent* AOwner)/* overload */ : Dxzoomtrackbar::TdxCustomZoomTrackBar(AOwner) { }
	
public:
	/* TcxCustomTrackBar.Destroy */ inline __fastcall virtual ~TdxDBZoomTrackBar(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxDBZoomTrackBar(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Dxzoomtrackbar::TdxCustomZoomTrackBar(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBZoomTrackBar(HWND ParentWindow) : Dxzoomtrackbar::TdxCustomZoomTrackBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbzoomtrackbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBZOOMTRACKBAR)
using namespace Dxdbzoomtrackbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbzoomtrackbarHPP
