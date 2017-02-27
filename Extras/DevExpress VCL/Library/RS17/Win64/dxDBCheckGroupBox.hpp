// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDBCheckGroupBox.pas' rev: 24.00 (Win64)

#ifndef DxdbcheckgroupboxHPP
#define DxdbcheckgroupboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <dxCheckGroupBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbcheckgroupbox
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxDBCheckGroupBoxCheckBoxClass;

class DELPHICLASS TdxDBCheckGroupBoxCheckBox;
class PASCALIMPLEMENTATION TdxDBCheckGroupBoxCheckBox : public Dxcheckgroupbox::TdxCustomCheckGroupBoxCheckBox
{
	typedef Dxcheckgroupbox::TdxCustomCheckGroupBoxCheckBox inherited;
	
__published:
	__property CheckAction = {default=1};
	__property Visible = {default=1};
public:
	/* TdxCustomCheckGroupBoxCheckBox.Create */ inline __fastcall virtual TdxDBCheckGroupBoxCheckBox(Dxcheckgroupbox::TdxCustomCheckGroupBox* AOwner)/* overload */ : Dxcheckgroupbox::TdxCustomCheckGroupBoxCheckBox(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxDBCheckGroupBoxCheckBox(void) { }
	
};


class DELPHICLASS TdxDBCheckGroupBox;
class PASCALIMPLEMENTATION TdxDBCheckGroupBox : public Dxcheckgroupbox::TdxCustomCheckGroupBox
{
	typedef Dxcheckgroupbox::TdxCustomCheckGroupBox inherited;
	
private:
	Cxdbedit::TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxdbedit::TcxDBEditDataBinding* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Dxcheckgroupbox::TdxCustomCheckGroupBoxCheckBoxClass __fastcall GetCheckBoxClass();
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Caption = {default=0};
	__property CheckBox;
	__property Constraints;
	__property Ctl3D;
	__property Cxdbedit::TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DockSite = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Focusable = {default=1};
	__property PanelStyle;
	__property ParentBackground = {default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Properties;
	__property RedrawOnResize = {default=1};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent = {default=0};
	__property UseDockManager = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnCustomDraw;
	__property OnCustomDrawCaption;
	__property OnCustomDrawContentBackground;
	__property OnDblClick;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetSiteInfo;
	__property OnMeasureCaptionHeight;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnUnDock;
public:
	/* TdxCustomCheckGroupBox.Create */ inline __fastcall virtual TdxDBCheckGroupBox(System::Classes::TComponent* AOwner)/* overload */ : Dxcheckgroupbox::TdxCustomCheckGroupBox(AOwner) { }
	/* TdxCustomCheckGroupBox.Destroy */ inline __fastcall virtual ~TdxDBCheckGroupBox(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxDBCheckGroupBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Dxcheckgroupbox::TdxCustomCheckGroupBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBCheckGroupBox(HWND ParentWindow) : Dxcheckgroupbox::TdxCustomCheckGroupBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbcheckgroupbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBCHECKGROUPBOX)
using namespace Dxdbcheckgroupbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbcheckgroupboxHPP
