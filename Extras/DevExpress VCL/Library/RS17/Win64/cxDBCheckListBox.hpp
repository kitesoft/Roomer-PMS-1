// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBCheckListBox.pas' rev: 24.00 (Win64)

#ifndef CxdbchecklistboxHPP
#define CxdbchecklistboxHPP

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
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbchecklistbox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDBCheckListBox;
class PASCALIMPLEMENTATION TcxDBCheckListBox : public Cxchecklistbox::TcxCustomCheckListBox
{
	typedef Cxchecklistbox::TcxCustomCheckListBox inherited;
	
private:
	Cxdb::TcxDBDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdb::TcxDBDataBinding* Value);
	
protected:
	__classmethod virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass();
	
__published:
	__property AllowDblClickToggle = {default=1};
	__property AllowGrayed = {default=0};
	__property Anchors = {default=3};
	__property AutoComplete = {default=1};
	__property AutoCompleteDelay = {default=500};
	__property BiDiMode;
	__property Columns = {default=0};
	__property Constraints;
	__property Cxdb::TcxDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property EditValueFormat = {default=2};
	__property Enabled = {default=1};
	__property Glyph;
	__property GlyphCount = {default=6};
	__property Images;
	__property ImageLayout = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property IntegralHeight = {default=0};
	__property Items;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property ScrollWidth = {default=0};
	__property ShowChecks = {default=1};
	__property ShowHint;
	__property Sorted = {default=0};
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property TabWidth = {default=0};
	__property Visible = {default=1};
	__property OnCheckStatesToEditValue;
	__property OnClick;
	__property OnClickCheck;
	__property OnCompare;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawItem;
	__property OnEditValueToCheckStates;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMeasureItem;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomCheckListBox.Create */ inline __fastcall virtual TcxDBCheckListBox(System::Classes::TComponent* AOwner) : Cxchecklistbox::TcxCustomCheckListBox(AOwner) { }
	/* TcxCustomCheckListBox.Destroy */ inline __fastcall virtual ~TcxDBCheckListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCheckListBox(HWND ParentWindow) : Cxchecklistbox::TcxCustomCheckListBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdbchecklistbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBCHECKLISTBOX)
using namespace Cxdbchecklistbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbchecklistboxHPP
