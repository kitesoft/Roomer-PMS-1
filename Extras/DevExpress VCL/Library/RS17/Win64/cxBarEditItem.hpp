// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxBarEditItem.pas' rev: 24.00 (Win64)

#ifndef CxbaredititemHPP
#define CxbaredititemHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxbaredititem
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxItemsEditorEx;
class PASCALIMPLEMENTATION TcxItemsEditorEx : public Dxbar::TdxItemsEditorEx
{
	typedef Dxbar::TdxItemsEditorEx inherited;
	
protected:
	__classmethod virtual void __fastcall InitSubItem(Dxbar::TdxBarItemLinks* AItemLinks);
	__classmethod virtual Dxbar::TdxBarItemClass __fastcall GetAddedItemClass(const System::UnicodeString AAddedItemName);
	__classmethod virtual System::UnicodeString __fastcall GetPopupItemCaption();
	__classmethod virtual void __fastcall InitializeAddedItem(Dxbar::TdxBarItemLink* AItemLink, System::UnicodeString AAddedItemName);
public:
	/* TObject.Create */ inline __fastcall TcxItemsEditorEx(void) : Dxbar::TdxItemsEditorEx() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxItemsEditorEx(void) { }
	
};


class DELPHICLASS TcxCustomBarEditItem;
class PASCALIMPLEMENTATION TcxCustomBarEditItem : public Dxbar::TdxCustomBarEdit
{
	typedef Dxbar::TdxCustomBarEdit inherited;
	
private:
	Cxedit::TcxCustomEditData* FEditData;
	System::Variant FEditValue;
	int FHeight;
	bool FPrevIsBlobEditValue;
	System::Classes::TNotifyEvent FPrevOnEditValueChanged;
	Cxedit::TcxCustomEditProperties* FProperties;
	System::Classes::TNotifyEvent FPropertiesEvents;
	Cxedit::TcxCustomEditProperties* FPropertiesValue;
	Cxedit::TcxEditRepositoryItem* FRepositoryItem;
	Cxedit::TcxEditRepositoryItem* FRepositoryItemValue;
	bool FBarStyleDropDownButton;
	void __fastcall RepositoryItemItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall RepositoryItemPropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall CustomizingDoDrawEditButtonBackground(Cxedit::TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool &AHandled);
	void __fastcall CustomizingDoGetEditDefaultButtonWidth(Cxedit::TcxCustomEditViewData* Sender, int AIndex, int &ADefaultWidth);
	void __fastcall CheckIsBlobEditValue(void);
	void __fastcall CreateProperties(Cxedit::TcxCustomEditPropertiesClass APropertiesClass);
	void __fastcall DestroyProperties(void);
	System::Variant __fastcall GetCurEditValue(void);
	Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	System::UnicodeString __fastcall GetPropertiesClassName(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetPropertiesValue(void);
	Cxedit::TcxEditRepositoryItem* __fastcall GetRepositoryItemValue(void);
	bool __fastcall IsBarCompatibleEdit(Cxedit::TcxCustomEditProperties* AEditProperties = (Cxedit::TcxCustomEditProperties*)(0x0));
	bool __fastcall IsBlobEditValue(void);
	bool __fastcall IsEditClickable(void);
	bool __fastcall IsEditHasContent(void);
	bool __fastcall IsEditValueStored(System::Classes::TFiler* AFiler);
	void __fastcall PropertiesChangedHandler(System::TObject* Sender);
	void __fastcall PropertiesValueChanged(void);
	void __fastcall ReadEditValue(System::Classes::TReader* AReader)/* overload */;
	void __fastcall ReadEditValue(System::Classes::TStream* AStream)/* overload */;
	void __fastcall SetEditValue(const System::Variant &Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetProperties(Cxedit::TcxCustomEditProperties* Value);
	void __fastcall SetPropertiesClass(Cxedit::TcxCustomEditPropertiesClass Value);
	void __fastcall SetPropertiesClassName(const System::UnicodeString Value);
	void __fastcall SetRepositoryItem(Cxedit::TcxEditRepositoryItem* Value);
	void __fastcall SetRepositoryItemValue(Cxedit::TcxEditRepositoryItem* Value);
	void __fastcall SetBarStyleDropDownButton(bool Value);
	void __fastcall UpdateRepositoryItemValue(void);
	void __fastcall UpdateEditProperties(Cxedit::TcxCustomEdit* AEdit);
	bool __fastcall UseBarPaintingStyle(void);
	void __fastcall WriteEditValue(System::Classes::TWriter* AWriter)/* overload */;
	void __fastcall WriteEditValue(System::Classes::TStream* AStream)/* overload */;
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DrawCustomizingImage(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DrawCustomizingImageContent(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected);
	virtual Dxbar::TdxBarItemControlClass __fastcall GetControlClass(bool AIsVertical);
	virtual bool __fastcall HasAccel(Dxbar::TdxBarItemLink* AItemLink);
	bool __fastcall CanEdit(void);
	bool __fastcall CaptionIsEditValue(void);
	void __fastcall DoEditValueChanged(System::TObject* Sender);
	void __fastcall InitProperties(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall PropertiesChanged(void);
	void __fastcall UpdatePropertiesValue(void);
	
public:
	__fastcall virtual TcxCustomBarEditItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomBarEditItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall DoClick(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	__property System::Variant CurEditValue = {read=GetCurEditValue};
	__property System::Variant EditValue = {read=FEditValue, write=SetEditValue, stored=false};
	__property int Height = {read=FHeight, write=SetHeight, default=0};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property Cxedit::TcxCustomEditPropertiesClass PropertiesClass = {read=GetPropertiesClass, write=SetPropertiesClass};
	__property Cxedit::TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
	
__published:
	__property System::UnicodeString PropertiesClassName = {read=GetPropertiesClassName, write=SetPropertiesClassName};
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
	__property bool BarStyleDropDownButton = {read=FBarStyleDropDownButton, write=SetBarStyleDropDownButton, default=1};
private:
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	
};


class DELPHICLASS TcxBarEditItem;
class PASCALIMPLEMENTATION TcxBarEditItem : public TcxCustomBarEditItem
{
	typedef TcxCustomBarEditItem inherited;
	
__published:
	__property CanSelect = {default=1};
	__property EditValue = {default=0};
	__property Height = {default=0};
	__property LargeGlyph;
	__property Properties;
	__property RepositoryItem;
	__property StyleEdit;
public:
	/* TcxCustomBarEditItem.Create */ inline __fastcall virtual TcxBarEditItem(System::Classes::TComponent* AOwner) : TcxCustomBarEditItem(AOwner) { }
	/* TcxCustomBarEditItem.Destroy */ inline __fastcall virtual ~TcxBarEditItem(void) { }
	
};


struct DECLSPEC_DRECORD TcxBarEditItemControlEditEvents
{
public:
	Vcl::Controls::TKeyEvent OnAfterKeyDown;
	System::Classes::TNotifyEvent OnChange;
	Cxedit::TcxEditClosePopupEvent OnClosePopup;
	System::Classes::TNotifyEvent OnFocusChanged;
	System::Classes::TNotifyEvent OnInitPopup;
	Vcl::Controls::TKeyEvent OnKeyDown;
	Vcl::Controls::TKeyPressEvent OnKeyPress;
	Vcl::Controls::TKeyEvent OnKeyUp;
	Vcl::Controls::TMouseMoveEvent OnMouseMove;
	System::Classes::TNotifyEvent OnPostEditValue;
	Cxedit::TcxEditValidateEvent OnValidate;
};


class DELPHICLASS TcxBarEditItemControl;
class PASCALIMPLEMENTATION TcxBarEditItemControl : public Dxbar::TdxBarCustomEditControl
{
	typedef Dxbar::TdxBarCustomEditControl inherited;
	
private:
	Cxedit::TcxCustomEdit* FEdit;
	Cxedit::TcxCustomEditViewInfo* FEditViewInfo;
	TcxBarEditItemControlEditEvents FSavedEditEvents;
	System::Variant FEditValueBeforeHiding;
	bool FIsEditValueAssigned;
	int FLastEditPart;
	void __fastcall ClearEditEvents(void);
	void __fastcall InternalShowEdit(void);
	void __fastcall SaveEditEvents(void);
	void __fastcall DoAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall DoCanStartButtonFading(Cxedit::TcxCustomEditViewInfo* Sender, bool &ACanStart);
	void __fastcall DoCustomDrawPopupBorder(Cxcontainer::TcxContainerViewInfo* AViewInfo, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool &AHandled, /* out */ int &ABorderWidth);
	void __fastcall DoDrawEditBackground(Cxedit::TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, bool &AHandled);
	void __fastcall DoDrawEditButton(Cxedit::TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, bool &AHandled);
	void __fastcall DoDrawEditButtonBackground(Cxedit::TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool &AHandled);
	void __fastcall DoDrawEditButtonBorder(Cxedit::TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, /* out */ System::Types::TRect &ABackgroundRect, /* out */ System::Types::TRect &AContentRect, bool &AHandled);
	void __fastcall DoEditPaint(Cxedit::TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DoEditClosePopup(Cxcontrols::TcxControl* Sender, Cxedit::TcxEditCloseUpReason AReason);
	void __fastcall DoEditPropertiesChange(System::TObject* Sender);
	void __fastcall DoGetEditButtonState(Cxedit::TcxEditButtonViewInfo* Sender, Cxedit::TcxEditButtonState &AState);
	void __fastcall DoGetEditDefaultButtonWidth(Cxedit::TcxCustomEditViewData* Sender, int AIndex, int &ADefaultWidth);
	void __fastcall DoFocusChanged(System::TObject* Sender);
	void __fastcall DoInitPopup(System::TObject* Sender);
	HIDESBASE void __fastcall DoKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	HIDESBASE void __fastcall DoKeyPress(System::TObject* Sender, System::WideChar &Key);
	HIDESBASE void __fastcall DoKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall DoPostEditValue(System::TObject* Sender);
	void __fastcall DoPrepareButtonFadingImageEvent(Cxedit::TcxEditButtonViewInfo* ASender, Cxedit::TcxEditButtonState AState, /* out */ Cxgraphics::TcxBitmap32* &AImage, bool &AHandled);
	void __fastcall DoValidate(System::TObject* Sender, System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error);
	void __fastcall EditClickHandler(System::TObject* Sender);
	void __fastcall AssignViewInfoEvents(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	void __fastcall CheckHint(const System::Types::TPoint APoint);
	void __fastcall ClearViewInfoEvents(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	void __fastcall DrawEditBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AColor);
	System::Types::TRect __fastcall GetBoundsRect(void);
	System::Variant __fastcall GetCurEditValue(void);
	int __fastcall GetDefaultEditButtonWidth(int AIndex);
	Cxdropdownedit::TcxCustomDropDownEdit* __fastcall GetDropDownEdit(void);
	int __fastcall GetEditButtonState(Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	System::Types::TSize __fastcall GetEditSize(bool AIsMinSize = false);
	Cxedit::TcxEditStyle* __fastcall GetEditStyle(void);
	Cxedit::TcxCustomEditViewInfo* __fastcall GetEditViewInfo(void);
	HIDESBASE TcxCustomBarEditItem* __fastcall GetItem(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	void __fastcall InitEditContentParams(Cxedit::TcxEditContentParams &AParams);
	void __fastcall InternalDrawComboBoxDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	bool __fastcall IsDropDownEdit(void);
	bool __fastcall IsPopupSideward(void);
	bool __fastcall NeedEditShowCaption(void);
	void __fastcall PrepareEditForClose(void);
	void __fastcall UpdateNormalStateImageForActiveFadingHelpers(void);
	void __fastcall LockChangeEvents(bool ALock, bool AInvokeChanged = true);
	__property Cxdropdownedit::TcxCustomDropDownEdit* DropDownEdit = {read=GetDropDownEdit};
	
protected:
	virtual bool __fastcall AllowSelectWithoutFocusing(void);
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual void __fastcall CalcParts(void);
	virtual bool __fastcall CanHide(void);
	virtual bool __fastcall CanSelect(void);
	virtual void __fastcall CheckHotTrack(System::Types::TPoint APoint);
	virtual void __fastcall ControlInactivate(bool Immediately);
	virtual void __fastcall DoPaint(System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	void __fastcall DoMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DrawTextField(void);
	virtual Vcl::Controls::TControl* __fastcall GetControl(void);
	virtual HWND __fastcall GetHandle(void);
	virtual void __fastcall GetHintParams(/* out */ System::UnicodeString &AHintText, /* out */ System::UnicodeString &AShortCut);
	virtual int __fastcall GetDefaultHeight(void);
	virtual int __fastcall GetMinEditorWidth(void);
	virtual int __fastcall GetPartCount(void);
	virtual bool __fastcall GetShowCaption(void);
	virtual int __fastcall GetCaptionAreaWidth(void);
	virtual int __fastcall GetControlAreaWidth(void);
	virtual Dxbar::TdxBarItemViewLevels __fastcall GetPossibleViewLevels(void);
	virtual void __fastcall HotPartChanged(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall ParentVisibleChange(bool AIsShowing);
	virtual void __fastcall RestoreDisplayValue(void);
	virtual void __fastcall StoreDisplayValue(void);
	virtual void __fastcall ActivateEdit(bool AByMouse, System::WideChar AKey = (System::WideChar)(0x0));
	virtual void __fastcall InitEdit(void);
	virtual void __fastcall Show(void);
	virtual void __fastcall Hide(bool AStoreDisplayValue);
	virtual bool __fastcall DrawSelected(void);
	virtual bool __fastcall IsChildWindow(HWND AWnd);
	bool __fastcall IsEditMultiRow(void);
	virtual bool __fastcall IsEditTransparent(void);
	virtual bool __fastcall IsTransparentOnGlass(void);
	bool __fastcall NeedFocusOnClick(void);
	virtual bool __fastcall WantsKey(System::Word Key);
	void __fastcall CalculateEditViewInfo(const System::Types::TRect &ABounds, System::Types::TPoint P, bool AIsMouseEvent, Cxedit::TcxCustomEditViewInfo* AEditViewInfo = (Cxedit::TcxCustomEditViewInfo*)(0x0), bool AFull = true);
	Cxedit::TcxCustomEditViewData* __fastcall CreateEditViewData(bool AFull = true);
	Cxedit::TcxCustomEditViewInfo* __fastcall CreateEditViewInfo(void);
	Cxedit::TcxCustomEditViewData* __fastcall GetViewData(/* out */ bool &AIsViewDataCreated);
	void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground = true);
	__property Cxedit::TcxEditStyle* EditStyle = {read=GetEditStyle};
	__property Cxedit::TcxCustomEditViewInfo* EditViewInfo = {read=GetEditViewInfo};
	__property TcxCustomBarEditItem* Item = {read=GetItem};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual ~TcxBarEditItemControl(void);
	virtual bool __fastcall IsDroppedDown(void);
	__property System::Variant CurEditValue = {read=GetCurEditValue};
	__property Cxedit::TcxCustomEdit* Edit = {read=FEdit};
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TcxBarEditItemControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarCustomEditControl(AItemLink) { }
	
private:
	void *__IcxEditOwner;	/* Cxedit::IcxEditOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4129100C-7FC6-436E-8711-47A5C978CA73}
	operator Cxedit::_di_IcxEditOwner()
	{
		Cxedit::_di_IcxEditOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditOwner*(void) { return (Cxedit::IcxEditOwner*)&__IcxEditOwner; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxbaredititem */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXBAREDITITEM)
using namespace Cxbaredititem;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxbaredititemHPP
