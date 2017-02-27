// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxRadioGroup.pas' rev: 24.00 (Win64)

#ifndef CxradiogroupHPP
#define CxradiogroupHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <System.Actions.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxradiogroup
{
//-- type declarations -------------------------------------------------------
enum TcxRadioButtonState : unsigned char { rbsDisabled, rbsHot, rbsNormal, rbsPressed };

enum TcxRadioGroupState : unsigned char { rgsActive, rgsDisabled, rgsHot, rgsNormal };

class DELPHICLASS TcxRadioButtonActionLink;
class DELPHICLASS TcxRadioButton;
class PASCALIMPLEMENTATION TcxRadioButtonActionLink : public Vcl::Stdctrls::TButtonActionLink
{
	typedef Vcl::Stdctrls::TButtonActionLink inherited;
	
protected:
	TcxRadioButton* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsGroupIndexLinked(void);
	virtual void __fastcall SetGroupIndex(int Value);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TcxRadioButtonActionLink(System::TObject* AClient) : Vcl::Stdctrls::TButtonActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TcxRadioButtonActionLink(void) { }
	
};


class PASCALIMPLEMENTATION TcxRadioButton : public Vcl::Stdctrls::TRadioButton
{
	typedef Vcl::Stdctrls::TRadioButton inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	bool FChecked;
	int FColumn;
	Vcl::Controls::TControlCanvas* FControlCanvas;
	int FGroupIndex;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::Classes::TComponent* FPopupMenu;
	int FRow;
	bool FShowEndEllipsis;
	TcxRadioButtonState FState;
	bool FTransparent;
	void __fastcall AdjustCanvasFontSettings(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawItem(const tagDRAWITEMSTRUCT &DrawItemStruct);
	System::Types::TRect __fastcall GetButtonRect(void);
	System::Types::TRect __fastcall GetRadioButtonRect(const System::Types::TSize ARadioButtonSize, bool ANativeStyle);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	System::Types::TRect __fastcall GetTextRect(void);
	bool __fastcall IsDisabledTextColorAssigned(void);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	HIDESBASE void __fastcall SetPopupMenu(System::Classes::TComponent* Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetState(TcxRadioButtonState Value);
	void __fastcall SetTransparent(bool Value);
	MESSAGE void __fastcall BMSetCheck(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall CNMeasureItem(Winapi::Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void __fastcall CNSysKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall CheckStartFading(TcxRadioButtonState APrevState, TcxRadioButtonState AState);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC Vcl::Controls::TControlActionLinkClass __fastcall GetActionLinkClass(void);
	virtual bool __fastcall GetChecked(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall CorrectTextRect(System::Types::TRect &R, bool ANativeStyle);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* APopupMenu, int X, int Y);
	DYNAMIC void __fastcall EnabledChanged(void);
	void __fastcall InternalPolyLine(System::Types::TPoint const *APoints, const int APoints_Size);
	void __fastcall InvalidateRadioButton(void);
	virtual bool __fastcall IsInplace(void);
	virtual bool __fastcall IsNativeBackground(void);
	virtual bool __fastcall IsNativeStyle(void);
	virtual bool __fastcall IsTransparent(void);
	virtual bool __fastcall IsTransparentBackground(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	void __fastcall ShortUpdateState(void);
	virtual void __fastcall UpdateState(Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, const System::Types::TPoint P);
	virtual bool __fastcall NeedDoubleBuffered(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, bool ADrawOnlyFocusedState);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas, bool ANativeStyle);
	virtual void __fastcall DrawRadioButton(Cxgraphics::TcxCanvas* ACanvas, TcxRadioButtonState AState);
	virtual void __fastcall Paint(bool ADrawOnlyFocusedState);
	virtual void __fastcall PrepareBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall MouseTrackingCallerMouseLeave(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	bool __fastcall CanFade(void);
	void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	__property System::Types::TRect ButtonRect = {read=GetButtonRect};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property int Column = {read=FColumn, nodefault};
	__property int Row = {read=FRow, nodefault};
	__property TcxRadioButtonState State = {read=FState, write=SetState, nodefault};
	__property System::Types::TRect TextRect = {read=GetTextRect};
	
public:
	__fastcall virtual TcxRadioButton(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxRadioButton(void);
	DYNAMIC bool __fastcall Focused(void);
	virtual void __fastcall Invalidate(void);
	
__published:
	__property int GroupIndex = {read=FGroupIndex, write=FGroupIndex, default=0};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property ParentBackground = {default=1};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=0};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxRadioButton(HWND ParentWindow) : Vcl::Stdctrls::TRadioButton(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};


class DELPHICLASS TcxRadioGroupButtonViewInfo;
class PASCALIMPLEMENTATION TcxRadioGroupButtonViewInfo : public Cxgroupbox::TcxButtonGroupButtonViewInfo
{
	typedef Cxgroupbox::TcxButtonGroupButtonViewInfo inherited;
	
public:
	virtual System::Types::TRect __fastcall GetGlyphRect(const System::Types::TSize AGlyphSize, System::Classes::TLeftRight AAlignment, bool AIsPaintCopy);
public:
	/* TcxEditButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxRadioGroupButtonViewInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxRadioGroupButtonViewInfo(void) : Cxgroupbox::TcxButtonGroupButtonViewInfo() { }
	
};


class DELPHICLASS TcxCustomRadioGroupViewInfo;
class DELPHICLASS TcxCustomRadioGroup;
class PASCALIMPLEMENTATION TcxCustomRadioGroupViewInfo : public Cxgroupbox::TcxButtonGroupViewInfo
{
	typedef Cxgroupbox::TcxButtonGroupViewInfo inherited;
	
private:
	HIDESBASE TcxCustomRadioGroup* __fastcall GetEdit(void);
	NativeUInt __fastcall ThemeHandle(void);
	
protected:
	virtual void __fastcall DrawButtonCaption(Cxgraphics::TcxCanvas* ACanvas, Cxgroupbox::TcxGroupBoxButtonViewInfo* AButtonViewInfo, const System::Types::TRect &AGlyphRect);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Cxgroupbox::TcxGroupBoxButtonViewInfo* AButtonViewInfo, const System::Types::TRect &AGlyphRect);
	virtual Cxedit::TcxEditButtonViewInfoClass __fastcall GetButtonViewInfoClass(void);
	virtual bool __fastcall IsButtonGlypthTransparent(Cxgroupbox::TcxGroupBoxButtonViewInfo* AButtonViewInfo);
	
public:
	int ItemIndex;
	__fastcall virtual TcxCustomRadioGroupViewInfo(void);
	__property TcxCustomRadioGroup* Edit = {read=GetEdit};
public:
	/* TcxGroupBoxViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomRadioGroupViewInfo(void) { }
	
};


class DELPHICLASS TcxCustomRadioGroupViewData;
class DELPHICLASS TcxCustomRadioGroupProperties;
class PASCALIMPLEMENTATION TcxCustomRadioGroupViewData : public Cxgroupbox::TcxButtonGroupViewData
{
	typedef Cxgroupbox::TcxButtonGroupViewData inherited;
	
private:
	HIDESBASE TcxCustomRadioGroupProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateButtonNativePartInfo(NativeUInt ATheme, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual NativeUInt __fastcall GetButtonNativeTheme(Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall GetEditMetrics(bool AAutoHeight, Cxgraphics::TcxCanvas* ACanvas, /* out */ Cxgroupbox::TcxEditMetrics &AMetrics);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomRadioGroupProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomRadioGroupViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxgroupbox::TcxButtonGroupViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomRadioGroupViewData(void) { }
	
};


class DELPHICLASS TcxRadioGroupItem;
class PASCALIMPLEMENTATION TcxRadioGroupItem : public Cxgroupbox::TcxButtonGroupItem
{
	typedef Cxgroupbox::TcxButtonGroupItem inherited;
	
private:
	System::Variant FValue;
	bool __fastcall IsValueStored(void);
	void __fastcall SetValue(const System::Variant &Value);
	
public:
	__fastcall virtual TcxRadioGroupItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Caption = {default=0};
	__property System::Variant Value = {read=FValue, write=SetValue, stored=IsValueStored};
	__property Tag;
public:
	/* TcxButtonGroupItem.Destroy */ inline __fastcall virtual ~TcxRadioGroupItem(void) { }
	
};


class DELPHICLASS TcxRadioGroupItems;
class PASCALIMPLEMENTATION TcxRadioGroupItems : public Cxgroupbox::TcxButtonGroupItems
{
	typedef Cxgroupbox::TcxButtonGroupItems inherited;
	
public:
	TcxRadioGroupItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxRadioGroupItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxRadioGroupItem* Value);
	
public:
	HIDESBASE TcxRadioGroupItem* __fastcall Add(void);
	__property TcxRadioGroupItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxOwnedInterfacedCollection.Destroy */ inline __fastcall virtual ~TcxRadioGroupItems(void) { }
	
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxRadioGroupItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : Cxgroupbox::TcxButtonGroupItems(AOwner, ItemClass) { }
	
};


class PASCALIMPLEMENTATION TcxCustomRadioGroupProperties : public Cxgroupbox::TcxCustomButtonGroupProperties
{
	typedef Cxgroupbox::TcxCustomButtonGroupProperties inherited;
	
private:
	System::WideString FDefaultCaption;
	System::Variant FDefaultValue;
	System::Variant __fastcall GetButtonValue(int AIndex);
	TcxRadioGroupItems* __fastcall GetItems(void);
	bool __fastcall IsDefaultCaptionStored(void);
	bool __fastcall IsDefaultValueStored(void);
	void __fastcall SetDefaultValue(const System::Variant &Value);
	HIDESBASE void __fastcall SetItems(TcxRadioGroupItems* Value);
	
protected:
	virtual Cxgroupbox::TcxButtonGroupItems* __fastcall CreateItems(void);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual int __fastcall GetColumnCount(void);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	
public:
	__fastcall virtual TcxCustomRadioGroupProperties(System::Classes::TPersistent* AOwner);
	virtual bool __fastcall CanCompareEditValue(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	int __fastcall GetRadioGroupItemIndex(const System::Variant &AEditValue);
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsResetEditClass(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	__property System::WideString DefaultCaption = {read=FDefaultCaption, write=FDefaultCaption, stored=IsDefaultCaptionStored};
	__property System::Variant DefaultValue = {read=FDefaultValue, write=SetDefaultValue, stored=IsDefaultValueStored};
	__property TcxRadioGroupItems* Items = {read=GetItems, write=SetItems};
public:
	/* TcxCustomButtonGroupProperties.Destroy */ inline __fastcall virtual ~TcxCustomRadioGroupProperties(void) { }
	
};


class DELPHICLASS TcxRadioGroupProperties;
class PASCALIMPLEMENTATION TcxRadioGroupProperties : public TcxCustomRadioGroupProperties
{
	typedef TcxCustomRadioGroupProperties inherited;
	
__published:
	__property AssignedValues;
	__property ClearKey = {default=0};
	__property Columns = {default=1};
	__property DefaultCaption = {default=0};
	__property DefaultValue = {default=0};
	__property ImmediatePost = {default=0};
	__property Items;
	__property ReadOnly;
	__property ShowEndEllipsis = {default=0};
	__property WordWrap = {default=0};
	__property OnChange;
	__property OnEditValueChanged;
public:
	/* TcxCustomRadioGroupProperties.Create */ inline __fastcall virtual TcxRadioGroupProperties(System::Classes::TPersistent* AOwner) : TcxCustomRadioGroupProperties(AOwner) { }
	
public:
	/* TcxCustomButtonGroupProperties.Destroy */ inline __fastcall virtual ~TcxRadioGroupProperties(void) { }
	
};


class DELPHICLASS TcxCustomRadioGroupButton;
class PASCALIMPLEMENTATION TcxCustomRadioGroupButton : public TcxRadioButton
{
	typedef TcxRadioButton inherited;
	
private:
	bool FFocusingByMouse;
	bool FInternalSettingChecked;
	bool FIsClickLocked;
	TcxCustomRadioGroup* __fastcall GetRadioGroup(void);
	HIDESBASE MESSAGE void __fastcall CNCommand(Winapi::Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	
protected:
	virtual void __fastcall CorrectTextRect(System::Types::TRect &R, bool ANativeStyle);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PrepareBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall IsInplace(void);
	virtual bool __fastcall IsNativeBackground(void);
	virtual bool __fastcall IsNativeStyle(void);
	virtual bool __fastcall IsTransparent(void);
	virtual bool __fastcall IsTransparentBackground(void);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	void __fastcall InternalSetChecked(bool AValue);
	__property TcxCustomRadioGroup* RadioGroup = {read=GetRadioGroup};
	
public:
	__fastcall virtual TcxCustomRadioGroupButton(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomRadioGroupButton(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual void __fastcall DefaultHandler(void *Message);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomRadioGroupButton(HWND ParentWindow) : TcxRadioButton(ParentWindow) { }
	
private:
	void *__IcxContainerInnerControl;	/* Cxcontainer::IcxContainerInnerControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxContainerInnerControl; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomRadioGroupButtonClass;

class PASCALIMPLEMENTATION TcxCustomRadioGroup : public Cxgroupbox::TcxCustomButtonGroup
{
	typedef Cxgroupbox::TcxCustomButtonGroup inherited;
	
private:
	int FLoadedItemIndex;
	int __fastcall GetCheckedIndex(void);
	TcxCustomRadioGroupButton* __fastcall GetButton(int Index);
	HIDESBASE TcxCustomRadioGroupProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomRadioGroupProperties* __fastcall GetActiveProperties(void);
	int __fastcall GetItemIndex(void);
	HIDESBASE TcxCustomRadioGroupViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetItemIndex(int Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomRadioGroupProperties* Value);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	void __fastcall ButtonClickHandler(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall CursorChanged(void);
	virtual void __fastcall DoSetFocusWhenActivate(void);
	virtual NativeUInt __fastcall GetButtonDC(int AButtonIndex);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual bool __fastcall IsContainerFocused(void);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual void __fastcall SetDragMode(System::Uitypes::TDragMode Value);
	void __fastcall SetInternalValues(const System::Variant &AEditValue, bool AValidateEditValue, bool AFromButtonChecked);
	virtual void __fastcall SynchronizeButtonsStyle(void);
	virtual void __fastcall ParentBackgroundChanged(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall SetDragKind(System::Uitypes::TDragKind Value);
	virtual void __fastcall ArrangeButtons(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetButtonInstance(void);
	virtual void __fastcall UpdateButtons(void);
	void __fastcall UpdateValues(void);
	HIDESBASE bool __fastcall IsLoading(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall Updated(void);
	void __fastcall ButtonChecked(TcxCustomRadioGroupButton* AButton);
	__property TcxCustomRadioGroupViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Clear(void);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall SetFocus(void);
	__property TcxCustomRadioGroupProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomRadioGroupButton* Buttons[int Index] = {read=GetButton};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, default=-1};
	__property TcxCustomRadioGroupProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Transparent = {default=0};
public:
	/* TcxCustomButtonGroup.Destroy */ inline __fastcall virtual ~TcxCustomRadioGroup(void) { }
	
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxCustomRadioGroup(System::Classes::TComponent* AOwner)/* overload */ : Cxgroupbox::TcxCustomButtonGroup(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomRadioGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxgroupbox::TcxCustomButtonGroup(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomRadioGroup(HWND ParentWindow) : Cxgroupbox::TcxCustomButtonGroup(ParentWindow) { }
	
};


class DELPHICLASS TcxRadioGroup;
class PASCALIMPLEMENTATION TcxRadioGroup : public TcxCustomRadioGroup
{
	typedef TcxCustomRadioGroup inherited;
	
private:
	HIDESBASE TcxRadioGroupProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxRadioGroupProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxRadioGroupProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxRadioGroupProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Caption = {default=0};
	__property Constraints;
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentBackground = {default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxRadioGroupProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ItemIndex = {default=-1};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomButtonGroup.Destroy */ inline __fastcall virtual ~TcxRadioGroup(void) { }
	
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxRadioGroup(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomRadioGroup(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxRadioGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomRadioGroup(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxRadioGroup(HWND ParentWindow) : TcxCustomRadioGroup(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterRadioGroupHelper;
class PASCALIMPLEMENTATION TcxFilterRadioGroupHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
public:
	__classmethod virtual void __fastcall GetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &V, Vcl::Controls::TCaption &S);
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual void __fastcall SetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &AValue);
	__classmethod virtual bool __fastcall UseDisplayValue();
public:
	/* TObject.Create */ inline __fastcall TcxFilterRadioGroupHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterRadioGroupHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxradiogroup */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXRADIOGROUP)
using namespace Cxradiogroup;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxradiogroupHPP
