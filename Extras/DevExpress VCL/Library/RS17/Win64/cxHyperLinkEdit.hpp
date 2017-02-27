// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxHyperLinkEdit.pas' rev: 24.00 (Win64)

#ifndef CxhyperlinkeditHPP
#define CxhyperlinkeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxhyperlinkedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxHyperLinkEditViewInfo;
class PASCALIMPLEMENTATION TcxHyperLinkEditViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
protected:
	virtual void __fastcall GetColorSettingsByPainter(/* out */ System::Uitypes::TColor &ABackground, /* out */ System::Uitypes::TColor &ATextColor);
	virtual System::Uitypes::TColor __fastcall GetHyperLinkTextColor(void);
	
public:
	virtual bool __fastcall IsHotTrack(void)/* overload */;
	virtual bool __fastcall IsHotTrack(System::Types::TPoint P)/* overload */;
	virtual void __fastcall PrepareCanvasFont(Vcl::Graphics::TCanvas* ACanvas);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxHyperLinkEditViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxHyperLinkEditViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


enum TcxHyperLinkEditUsePrefix : unsigned char { upAlways, upOnlyOnExecute, upNever };

class DELPHICLASS TcxCustomHyperLinkEditProperties;
class PASCALIMPLEMENTATION TcxCustomHyperLinkEditProperties : public Cxtextedit::TcxCustomTextEditProperties
{
	typedef Cxtextedit::TcxCustomTextEditProperties inherited;
	
private:
	bool FSingleClick;
	System::Uitypes::TColor FLinkColor;
	System::Classes::TNotifyEvent FOnStartClick;
	System::UnicodeString FPrefix;
	System::Classes::TShortCut FStartKey;
	TcxHyperLinkEditUsePrefix FUsePrefix;
	bool __fastcall GetAutoComplete(void);
	bool __fastcall GetPrefixStored(void);
	void __fastcall ReadPrefix(System::Classes::TReader* Reader);
	void __fastcall SetAutoComplete(bool Value);
	void __fastcall SetLinkColor(const System::Uitypes::TColor Value);
	void __fastcall SetSingleClick(bool Value);
	void __fastcall WritePrefix(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* AFiler);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual System::UnicodeString __fastcall AddPrefixTo(System::UnicodeString AStr);
	
public:
	__fastcall virtual TcxCustomHyperLinkEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual Cxedit::TcxCustomEditStyleClass __fastcall GetStyleClass();
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &Error, Cxedit::TcxCustomEdit* AEdit);
	__property bool AutoComplete = {read=GetAutoComplete, write=SetAutoComplete, stored=false, nodefault};
	__property AutoSelect = {default=0};
	__property System::Uitypes::TColor LinkColor = {read=FLinkColor, write=SetLinkColor, default=16711680};
	__property System::UnicodeString Prefix = {read=FPrefix, write=FPrefix, stored=false};
	__property bool SingleClick = {read=FSingleClick, write=SetSingleClick, default=0};
	__property System::Classes::TShortCut StartKey = {read=FStartKey, write=FStartKey, default=16397};
	__property TcxHyperLinkEditUsePrefix UsePrefix = {read=FUsePrefix, write=FUsePrefix, default=0};
	__property System::Classes::TNotifyEvent OnStartClick = {read=FOnStartClick, write=FOnStartClick};
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomHyperLinkEditProperties(void) { }
	
};


class DELPHICLASS TcxHyperLinkEditProperties;
class PASCALIMPLEMENTATION TcxHyperLinkEditProperties : public TcxCustomHyperLinkEditProperties
{
	typedef TcxCustomHyperLinkEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoComplete;
	__property AutoSelect = {default=0};
	__property ClearKey = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property IncrementalSearch = {default=1};
	__property LinkColor = {default=16711680};
	__property LookupItems;
	__property LookupItemsSorted = {default=0};
	__property Nullstring = {default=0};
	__property Prefix = {default=0};
	__property ReadOnly;
	__property StartKey = {default=16397};
	__property SingleClick = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property UsePrefix = {default=0};
	__property ValidateOnEnter = {default=0};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnStartClick;
	__property OnValidate;
public:
	/* TcxCustomHyperLinkEditProperties.Create */ inline __fastcall virtual TcxHyperLinkEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomHyperLinkEditProperties(AOwner) { }
	
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxHyperLinkEditProperties(void) { }
	
};


class DELPHICLASS TcxHyperLinkStyle;
class PASCALIMPLEMENTATION TcxHyperLinkStyle : public Cxedit::TcxEditStyle
{
	typedef Cxedit::TcxEditStyle inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual System::Uitypes::TFontStyles __fastcall GetTextStyle(void);
public:
	/* TcxCustomEditStyle.Create */ inline __fastcall virtual TcxHyperLinkStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState) : Cxedit::TcxEditStyle(AOwner, ADirectAccessMode, AParentStyle, AState) { }
	
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxHyperLinkStyle(void) { }
	
};


class DELPHICLASS TcxCustomHyperLinkEdit;
class PASCALIMPLEMENTATION TcxCustomHyperLinkEdit : public Cxtextedit::TcxCustomTextEdit
{
	typedef Cxtextedit::TcxCustomTextEdit inherited;
	
private:
	System::Uitypes::TCursor FSaveCursor;
	HIDESBASE TcxCustomHyperLinkEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCustomHyperLinkEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxHyperLinkStyle* __fastcall GetStyle(void);
	void __fastcall InternalSetCursor(System::Uitypes::TCursor ACursor);
	HIDESBASE void __fastcall SetProperties(TcxCustomHyperLinkEditProperties* const Value);
	HIDESBASE void __fastcall SetStyle(TcxHyperLinkStyle* Value);
	
protected:
	bool __fastcall DoOnStartClick(void);
	virtual void __fastcall DoStart(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	
public:
	virtual void __fastcall ActivateByMouse(System::Classes::TShiftState Shift, int X, int Y, Cxedit::TcxCustomEditData* &AEditData);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall SelectAll(void);
	__property TcxCustomHyperLinkEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomHyperLinkEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TcxHyperLinkStyle* Style = {read=GetStyle, write=SetStyle};
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxCustomHyperLinkEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxCustomHyperLinkEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomHyperLinkEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomHyperLinkEdit(HWND ParentWindow) : Cxtextedit::TcxCustomTextEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxHyperLinkEdit;
class PASCALIMPLEMENTATION TcxHyperLinkEdit : public TcxCustomHyperLinkEdit
{
	typedef TcxCustomHyperLinkEdit inherited;
	
private:
	HIDESBASE TcxHyperLinkEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxHyperLinkEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxHyperLinkEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxHyperLinkEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
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
	__property TcxHyperLinkEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property TextHint = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property BiDiMode;
	__property ParentBiDiMode = {default=1};
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxHyperLinkEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomHyperLinkEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxHyperLinkEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxHyperLinkEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomHyperLinkEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxHyperLinkEdit(HWND ParentWindow) : TcxCustomHyperLinkEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterHyperLinkEditHelper;
class PASCALIMPLEMENTATION TcxFilterHyperLinkEditHelper : public Cxtextedit::TcxFilterTextEditHelper
{
	typedef Cxtextedit::TcxFilterTextEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
public:
	/* TObject.Create */ inline __fastcall TcxFilterHyperLinkEditHelper(void) : Cxtextedit::TcxFilterTextEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterHyperLinkEditHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const int cxHyperLinkEditDefaultLinkColor = int(16711680);
}	/* namespace Cxhyperlinkedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXHYPERLINKEDIT)
using namespace Cxhyperlinkedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxhyperlinkeditHPP
