// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxTileControl.pas' rev: 24.00 (Win64)

#ifndef DxtilecontrolHPP
#define DxtilecontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCustomTileControl.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxtilecontrol
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxTileControl;
class PASCALIMPLEMENTATION TdxTileControl : public Dxcustomtilecontrol::TdxCustomTileControl
{
	typedef Dxcustomtilecontrol::TdxCustomTileControl inherited;
	
__published:
	__property ActionBars;
	__property Align = {default=5};
	__property Anchors = {default=3};
	__property AutoSize = {default=0};
	__property BorderStyle = {default=0};
	__property Constraints;
	__property Cursor = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Groups;
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property HelpType = {default=1};
	__property Items;
	__property LookAndFeel;
	__property OnCanResize;
	__property OnClick;
	__property OnConstrainedResize;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetStoredProperties;
	__property OnGetStoredPropertyValue;
	__property OnInitStoredObject;
	__property OnItemBeforeCheck;
	__property OnItemCheck;
	__property OnItemDragBegin;
	__property OnItemDragEnd;
	__property OnItemDragOver;
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
	__property OnResize;
	__property OnSetStoredPropertyValue;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnUnDock;
	__property OptionsBehavior;
	__property OptionsItemAnimate;
	__property OptionsView;
	__property Style;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Title;
	__property Visible = {default=1};
public:
	/* TdxCustomTileControl.Create */ inline __fastcall virtual TdxTileControl(System::Classes::TComponent* AOwner) : Dxcustomtilecontrol::TdxCustomTileControl(AOwner) { }
	/* TdxCustomTileControl.Destroy */ inline __fastcall virtual ~TdxTileControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTileControl(HWND ParentWindow) : Dxcustomtilecontrol::TdxCustomTileControl(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxtilecontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTILECONTROL)
using namespace Dxtilecontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtilecontrolHPP
