// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSpinButton.pas' rev: 24.00 (Win32)

#ifndef CxspinbuttonHPP
#define CxspinbuttonHPP

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
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxspinbutton
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSpinButtonViewData;
class DELPHICLASS TcxCustomSpinButtonProperties;
class PASCALIMPLEMENTATION TcxSpinButtonViewData : public Cxspinedit::TcxSpinEditViewData
{
	typedef Cxspinedit::TcxSpinEditViewData inherited;
	
private:
	HIDESBASE TcxCustomSpinButtonProperties* __fastcall GetProperties(void);
	
protected:
	virtual bool __fastcall CanPressButton(Cxedit::TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	virtual bool __fastcall IsButtonPressed(Cxedit::TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	
public:
	Cxspinedit::TcxSpinEditPressedState PressedState;
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	__property TcxCustomSpinButtonProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxSpinButtonViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxspinedit::TcxSpinEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSpinButtonViewData(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomSpinButtonProperties : public Cxspinedit::TcxCustomSpinEditProperties
{
	typedef Cxspinedit::TcxCustomSpinEditProperties inherited;
	
protected:
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall IsDisplayValueNumeric(void);
	virtual bool __fastcall IsEditValueNumeric(void);
	virtual bool __fastcall PreserveSelection(void);
	
public:
	__fastcall virtual TcxCustomSpinButtonProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
public:
	/* TcxCustomSpinEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomSpinButtonProperties(void) { }
	
};


class DELPHICLASS TcxSpinButtonProperties;
class PASCALIMPLEMENTATION TcxSpinButtonProperties : public TcxCustomSpinButtonProperties
{
	typedef TcxCustomSpinButtonProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=0};
	__property HideSelection = {default=1};
	__property ImmediatePost = {default=0};
	__property Increment = {default=0};
	__property LargeIncrement = {default=0};
	__property MaxValue = {default=0};
	__property MinValue = {default=0};
	__property ReadOnly;
	__property SpinButtons;
	__property UseCtrlIncrement = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property ValueType = {default=0};
	__property OnChange;
	__property OnEditValueChanged;
public:
	/* TcxCustomSpinButtonProperties.Create */ inline __fastcall virtual TcxSpinButtonProperties(System::Classes::TPersistent* AOwner) : TcxCustomSpinButtonProperties(AOwner) { }
	
public:
	/* TcxCustomSpinEditProperties.Destroy */ inline __fastcall virtual ~TcxSpinButtonProperties(void) { }
	
};


class DELPHICLASS TcxCustomSpinButton;
class PASCALIMPLEMENTATION TcxCustomSpinButton : public Cxspinedit::TcxCustomSpinEdit
{
	typedef Cxspinedit::TcxCustomSpinEdit inherited;
	
private:
	Vcl::Controls::TWinControl* FAssociate;
	Vcl::Controls::TWinControl* FSubclassControl;
	bool FAutoWidth;
	Cxcontrols::TcxWindowProcLinkedObject* FPrevAssociateControlWndProcObject;
	HIDESBASE TcxCustomSpinButtonProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCustomSpinButtonProperties* __fastcall GetProperties(void);
	void __fastcall SubclassAssociateControl(void);
	void __fastcall SetAssociate(Vcl::Controls::TWinControl* AValue);
	void __fastcall SetAutoWidth(bool Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomSpinButtonProperties* Value);
	void __fastcall SetSubclassControl(Vcl::Controls::TWinControl* const Value);
	void __fastcall UnsubclassAssociateControl(void);
	bool __fastcall IsAssociatedWithEdit(void);
	
protected:
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual void __fastcall DoSetSize(void);
	virtual void __fastcall Initialize(void);
	virtual bool __fastcall InternalDoEditing(void);
	virtual void __fastcall AssociateControlWndProc(Winapi::Messages::TMessage &AMessage);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall JoinToAssociate(void);
	virtual void __fastcall SetAssociateValue(const System::Variant &AValue);
	virtual void __fastcall SynchronizeEditValueFromAssociate(void);
	__property Vcl::Controls::TWinControl* Associate = {read=FAssociate, write=SetAssociate};
	__property bool AutoWidth = {read=FAutoWidth, write=SetAutoWidth, default=1};
	__property Vcl::Controls::TWinControl* SubclassControl = {read=FSubclassControl, write=SetSubclassControl};
	__property TabStop = {default=0};
	
public:
	__fastcall virtual ~TcxCustomSpinButton(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall Increment(Cxspinedit::TcxSpinEditButton AButton);
	__property TcxCustomSpinButtonProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomSpinButtonProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomSpinButton(System::Classes::TComponent* AOwner)/* overload */ : Cxspinedit::TcxCustomSpinEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomSpinButton(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxspinedit::TcxCustomSpinEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomSpinButton(HWND ParentWindow) : Cxspinedit::TcxCustomSpinEdit(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
};


class DELPHICLASS TcxSpinButton;
class PASCALIMPLEMENTATION TcxSpinButton : public TcxCustomSpinButton
{
	typedef TcxCustomSpinButton inherited;
	
private:
	HIDESBASE TcxSpinButtonProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxSpinButtonProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxSpinButtonProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxSpinButtonProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property Associate;
	__property AutoSize = {default=1};
	__property AutoWidth = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxSpinButtonProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Value = {default=0};
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
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomSpinButton.Destroy */ inline __fastcall virtual ~TcxSpinButton(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxSpinButton(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomSpinButton(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxSpinButton(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomSpinButton(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSpinButton(HWND ParentWindow) : TcxCustomSpinButton(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxspinbutton */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSPINBUTTON)
using namespace Cxspinbutton;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxspinbuttonHPP
