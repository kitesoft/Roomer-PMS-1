// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGrid.pas' rev: 24.00 (Win64)

#ifndef CxpivotgridHPP
#define CxpivotgridHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGrid;
class PASCALIMPLEMENTATION TcxPivotGrid : public Cxcustompivotgrid::TcxCustomPivotGrid
{
	typedef Cxcustompivotgrid::TcxCustomPivotGrid inherited;
	
public:
	__property DataController;
	
__published:
	__property OLAPDataSource;
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BorderWidth = {default=0};
	__property BorderStyle = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property FieldHeaderImages;
	__property Font;
	__property GroupHeaderImages;
	__property Groups;
	__property LookAndFeel;
	__property OptionsBehavior;
	__property OptionsCustomize;
	__property OptionsData;
	__property OptionsDataField;
	__property OptionsPrefilter;
	__property OptionsSelection;
	__property OptionsView;
	__property ParentFont = {default=1};
	__property PopupMenu;
	__property PopupMenus;
	__property ShowHint;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnCompare;
	__property OnCustomDrawFieldHeader;
	__property OnCustomDrawColumnHeader;
	__property OnCustomDrawRowHeader;
	__property OnCustomDrawCell;
	__property OnCustomDrawPart;
	__property OnCustomization;
	__property OnFieldPosChanged;
	__property OnFieldSizeChanged;
	__property OnFilterChanged;
	__property OnPrefilterDialogShow;
	__property OnLayoutChanged;
	__property OnSelectionChanged;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
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
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomPivotGrid.Create */ inline __fastcall virtual TcxPivotGrid(System::Classes::TComponent* AOwner) : Cxcustompivotgrid::TcxCustomPivotGrid(AOwner) { }
	/* TcxCustomPivotGrid.Destroy */ inline __fastcall virtual ~TcxPivotGrid(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGrid(HWND ParentWindow) : Cxcustompivotgrid::TcxCustomPivotGrid(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgrid */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRID)
using namespace Cxpivotgrid;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridHPP
