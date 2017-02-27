// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCheckGroupBox.pas' rev: 24.00 (Win32)

#ifndef DxcheckgroupboxHPP
#define DxcheckgroupboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcheckgroupbox
{
//-- type declarations -------------------------------------------------------
enum TdxCheckGroupBoxCheckBoxAction : unsigned char { cbaNone, cbaToggleChildrenEnabledState };

class DELPHICLASS TdxCheckGroupBoxProperties;
class PASCALIMPLEMENTATION TdxCheckGroupBoxProperties : public Cxgroupbox::TcxCustomGroupBoxProperties
{
	typedef Cxgroupbox::TcxCustomGroupBoxProperties inherited;
	
protected:
	virtual bool __fastcall CanValidate(void);
	
public:
	virtual bool __fastcall IsResetEditClass(void);
	
__published:
	__property ImmediatePost = {default=0};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnValidate;
public:
	/* TcxCustomEditProperties.Create */ inline __fastcall virtual TdxCheckGroupBoxProperties(System::Classes::TPersistent* AOwner) : Cxgroupbox::TcxCustomGroupBoxProperties(AOwner) { }
	/* TcxCustomEditProperties.Destroy */ inline __fastcall virtual ~TdxCheckGroupBoxProperties(void) { }
	
};


typedef System::TMetaClass* TdxCustomCheckGroupBoxCheckBoxClass;

class DELPHICLASS TdxCustomCheckGroupBoxCheckBox;
class DELPHICLASS TdxCustomCheckGroupBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomCheckGroupBoxCheckBox : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxCheckGroupBoxCheckBoxAction FCheckAction;
	TdxCustomCheckGroupBox* FCheckGroupBox;
	bool FVisible;
	bool __fastcall GetChecked(void);
	void __fastcall SetChecked(const bool AValue);
	void __fastcall SetVisible(const bool AValue);
	
public:
	__fastcall virtual TdxCustomCheckGroupBoxCheckBox(TdxCustomCheckGroupBox* AOwner)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxCheckGroupBoxCheckBoxAction CheckAction = {read=FCheckAction, write=FCheckAction, default=1};
	__property bool Checked = {read=GetChecked, write=SetChecked, default=1};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomCheckGroupBoxCheckBox(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxCustomCheckGroupBox : public Cxgroupbox::TcxCustomGroupBox
{
	typedef Cxgroupbox::TcxCustomGroupBox inherited;
	
private:
	TdxCustomCheckGroupBoxCheckBox* FCheckBox;
	bool FFocusable;
	HIDESBASE TdxCheckGroupBoxProperties* __fastcall GetActiveProperties(void);
	TdxCheckGroupBoxProperties* __fastcall GetProperties(void);
	void __fastcall SetCheckBox(TdxCustomCheckGroupBoxCheckBox* AValue);
	HIDESBASE void __fastcall SetProperties(TdxCheckGroupBoxProperties* Value);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	
protected:
	virtual bool __fastcall CanFocusOnClick(int X, int Y)/* overload */;
	void __fastcall DoCheckBoxCheckedChanged(void);
	void __fastcall EnableChildControls(Vcl::Controls::TControl* AControl, bool AEnabled);
	__classmethod virtual TdxCustomCheckGroupBoxCheckBoxClass __fastcall GetCheckBoxClass();
	virtual bool __fastcall GetCheckBoxVisible(void);
	virtual void __fastcall Initialize(void);
	virtual bool __fastcall InternalCanFocusOnClick(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall Loaded(void);
	__property TdxCustomCheckGroupBoxCheckBox* CheckBox = {read=FCheckBox, write=SetCheckBox};
	__property bool Focusable = {read=FFocusable, write=FFocusable, default=1};
	__property TabStop = {default=1};
	
public:
	__fastcall virtual TdxCustomCheckGroupBox(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TdxCustomCheckGroupBox(void);
	DYNAMIC bool __fastcall CanFocus(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TdxCheckGroupBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property TdxCheckGroupBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxCustomCheckGroupBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxgroupbox::TcxCustomGroupBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomCheckGroupBox(HWND ParentWindow) : Cxgroupbox::TcxCustomGroupBox(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(void){ return Cxgroupbox::TcxCustomGroupBox::CanFocusOnClick(); }
	
};


typedef System::TMetaClass* TdxCheckGroupBoxCheckBoxClass;

class DELPHICLASS TdxCheckGroupBoxCheckBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCheckGroupBoxCheckBox : public TdxCustomCheckGroupBoxCheckBox
{
	typedef TdxCustomCheckGroupBoxCheckBox inherited;
	
__published:
	__property CheckAction = {default=1};
	__property Checked = {default=1};
	__property Visible = {default=1};
public:
	/* TdxCustomCheckGroupBoxCheckBox.Create */ inline __fastcall virtual TdxCheckGroupBoxCheckBox(TdxCustomCheckGroupBox* AOwner)/* overload */ : TdxCustomCheckGroupBoxCheckBox(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCheckGroupBoxCheckBox(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCheckGroupBox;
class PASCALIMPLEMENTATION TdxCheckGroupBox : public TdxCustomCheckGroupBox
{
	typedef TdxCustomCheckGroupBox inherited;
	
protected:
	__classmethod virtual TdxCustomCheckGroupBoxCheckBoxClass __fastcall GetCheckBoxClass();
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Caption = {default=0};
	__property CaptionBkColor;
	__property CheckBox;
	__property Color;
	__property Constraints;
	__property Ctl3D;
	__property DockSite = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Focusable = {default=1};
	__property Font;
	__property LookAndFeel;
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
	/* TdxCustomCheckGroupBox.Create */ inline __fastcall virtual TdxCheckGroupBox(System::Classes::TComponent* AOwner)/* overload */ : TdxCustomCheckGroupBox(AOwner) { }
	/* TdxCustomCheckGroupBox.Destroy */ inline __fastcall virtual ~TdxCheckGroupBox(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxCheckGroupBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TdxCustomCheckGroupBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCheckGroupBox(HWND ParentWindow) : TdxCustomCheckGroupBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxcheckgroupbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCHECKGROUPBOX)
using namespace Dxcheckgroupbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcheckgroupboxHPP
