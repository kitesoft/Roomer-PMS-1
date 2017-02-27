// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxColorEdit.pas' rev: 24.00 (Win64)

#ifndef DxcoloreditHPP
#define DxcoloreditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <dxGallery.hpp>	// Pascal unit
#include <dxColorGallery.hpp>	// Pascal unit
#include <dxGalleryControl.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcoloredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxCustomColorEditViewInfo;
class PASCALIMPLEMENTATION TdxCustomColorEditViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	System::Uitypes::TColor FColor;
	
public:
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TdxCustomColorEditViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TdxCustomColorEditViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class DELPHICLASS TdxCustomColorEditViewData;
class DELPHICLASS TdxCustomColorEditProperties;
class PASCALIMPLEMENTATION TdxCustomColorEditViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
private:
	HIDESBASE TdxCustomColorEditProperties* __fastcall GetProperties(void);
	
protected:
	virtual bool __fastcall IsComboBoxStyle(void);
	
public:
	virtual void __fastcall DisplayValueToDrawValue(const System::Variant &ADisplayValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TdxCustomColorEditProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TdxCustomColorEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxCustomColorEditViewData(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomColorEditProperties : public Cxdropdownedit::TcxCustomPopupEditProperties
{
	typedef Cxdropdownedit::TcxCustomPopupEditProperties inherited;
	
private:
	Dxcolorgallery::TdxColorSet FColorSet;
	Dxcolorgallery::TdxColorPalette FColorPalette;
	System::Uitypes::TColor FDefaultColor;
	int FItemSize;
	Dxcolorgallery::TdxColorGetCustomColorSetEvent FOnGetCustomColorSet;
	void __fastcall SetDefaultColor(System::Uitypes::TColor Value);
	System::Uitypes::TColor __fastcall EditValueToColorValue(System::Variant &AEditValue);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual bool __fastcall GetAlwaysPostEditValue(void);
	virtual bool __fastcall DropDownOnClick(void);
	virtual Cxedit::TcxEditEditingStyle __fastcall GetEditingStyle(void);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	
public:
	__fastcall virtual TdxCustomColorEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property Dxcolorgallery::TdxColorPalette ColorPalette = {read=FColorPalette, write=FColorPalette, nodefault};
	__property Dxcolorgallery::TdxColorSet ColorSet = {read=FColorSet, write=FColorSet, nodefault};
	__property System::Uitypes::TColor DefaultColor = {read=FDefaultColor, write=SetDefaultColor, nodefault};
	__property int ItemSize = {read=FItemSize, write=FItemSize, nodefault};
	__property Dxcolorgallery::TdxColorGetCustomColorSetEvent OnGetCustomColorSet = {read=FOnGetCustomColorSet, write=FOnGetCustomColorSet};
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TdxCustomColorEditProperties(void) { }
	
};


class DELPHICLASS TdxColorEditProperties;
class PASCALIMPLEMENTATION TdxColorEditProperties : public TdxCustomColorEditProperties
{
	typedef TdxCustomColorEditProperties inherited;
	
__published:
	__property AssignedValues;
	__property ButtonGlyph;
	__property ClearKey = {default=0};
	__property ValidationOptions = {default=1};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property ReadOnly;
	__property ColorPalette = {default=0};
	__property ColorSet = {default=0};
	__property DefaultColor = {default=-16777211};
	__property ItemSize = {default=0};
	__property OnChange;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnInitPopup;
	__property OnPopup;
	__property OnValidate;
	__property OnGetCustomColorSet;
public:
	/* TdxCustomColorEditProperties.Create */ inline __fastcall virtual TdxColorEditProperties(System::Classes::TPersistent* AOwner) : TdxCustomColorEditProperties(AOwner) { }
	
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TdxColorEditProperties(void) { }
	
};


class DELPHICLASS TdxPopupColorGallery;
class DELPHICLASS TdxCustomColorEdit;
class PASCALIMPLEMENTATION TdxPopupColorGallery : public Dxcolorgallery::TdxCustomColorGallery
{
	typedef Dxcolorgallery::TdxCustomColorGallery inherited;
	
private:
	TdxCustomColorEdit* FEdit;
	Cxedit::TcxEditClosePopupEvent FOnHidePopup;
	
protected:
	void __fastcall HidePopup(Cxcontrols::TcxControl* Sender, Cxedit::TcxEditCloseUpReason AReason);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	__property TdxCustomColorEdit* Edit = {read=FEdit, write=FEdit};
	
public:
	__fastcall virtual TdxPopupColorGallery(System::Classes::TComponent* AOwner);
	__property Cxedit::TcxEditClosePopupEvent OnHidePopup = {read=FOnHidePopup, write=FOnHidePopup};
public:
	/* TdxCustomGalleryControl.Destroy */ inline __fastcall virtual ~TdxPopupColorGallery(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPopupColorGallery(HWND ParentWindow) : Dxcolorgallery::TdxCustomColorGallery(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxCustomColorEdit : public Cxdropdownedit::TcxCustomPopupEdit
{
	typedef Cxdropdownedit::TcxCustomPopupEdit inherited;
	
private:
	bool __fastcall IsColorValueStored(void);
	System::Uitypes::TColor __fastcall GetColorValue(void);
	void __fastcall SetColorValue(System::Uitypes::TColor AValue);
	HIDESBASE TdxCustomColorEditProperties* __fastcall GetProperties(void);
	HIDESBASE TdxCustomColorEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE void __fastcall SetProperties(TdxCustomColorEditProperties* Value);
	
protected:
	TdxPopupColorGallery* FColorGallery;
	virtual void __fastcall CreatePopupWindow(void);
	virtual void __fastcall InitializeInnerEdit(void);
	virtual void __fastcall InitializePopupWindow(void);
	void __fastcall ItemClickHandler(System::TObject* Sender, Dxgallerycontrol::TdxGalleryControlItem* AItem);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DropDown(void);
	
public:
	__fastcall virtual TdxCustomColorEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TdxCustomColorEdit(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TdxCustomColorEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TdxCustomColorEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property System::Uitypes::TColor ColorValue = {read=GetColorValue, write=SetColorValue, stored=IsColorValueStored, nodefault};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxCustomColorEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomColorEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomPopupEdit(ParentWindow) { }
	
};


class DELPHICLASS TdxColorEdit;
class PASCALIMPLEMENTATION TdxColorEdit : public TdxCustomColorEdit
{
	typedef TdxCustomColorEdit inherited;
	
private:
	HIDESBASE TdxColorEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TdxColorEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	
__published:
	__property Anchors = {default=3};
	__property BeepOnEnter = {default=1};
	__property ColorValue;
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TdxColorEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
public:
	/* TdxCustomColorEdit.Create */ inline __fastcall virtual TdxColorEdit(System::Classes::TComponent* AOwner)/* overload */ : TdxCustomColorEdit(AOwner) { }
	/* TdxCustomColorEdit.Destroy */ inline __fastcall virtual ~TdxColorEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxColorEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TdxCustomColorEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxColorEdit(HWND ParentWindow) : TdxCustomColorEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterColorEditHelper;
class PASCALIMPLEMENTATION TcxFilterColorEditHelper : public Cxdropdownedit::TcxFilterDropDownEditHelper
{
	typedef Cxdropdownedit::TcxFilterDropDownEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
public:
	/* TObject.Create */ inline __fastcall TcxFilterColorEditHelper(void) : Cxdropdownedit::TcxFilterDropDownEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterColorEditHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxcoloredit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCOLOREDIT)
using namespace Dxcoloredit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoloreditHPP
