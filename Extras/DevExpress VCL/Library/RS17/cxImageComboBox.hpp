// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImageComboBox.pas' rev: 24.00 (Win32)

#ifndef CximagecomboboxHPP
#define CximagecomboboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cximagecombobox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxImageComboBoxItem;
class PASCALIMPLEMENTATION TcxImageComboBoxItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Vcl::Controls::TCaption FDescription;
	System::Uitypes::TImageIndex FImageIndex;
	int FTag;
	System::Variant FValue;
	bool __fastcall IsStoredValue(void);
	bool __fastcall IsTagStored(void);
	void __fastcall SetDescription(const Vcl::Controls::TCaption Value);
	void __fastcall SetImageIndex(const System::Uitypes::TImageIndex Value);
	void __fastcall SetValue(const System::Variant &AValue);
	
public:
	__fastcall virtual TcxImageComboBoxItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Controls::TCaption Description = {read=FDescription, write=SetDescription};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property int Tag = {read=FTag, write=FTag, stored=IsTagStored, nodefault};
	__property System::Variant Value = {read=FValue, write=SetValue, stored=IsStoredValue};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxImageComboBoxItem(void) { }
	
};


class DELPHICLASS TcxImageComboBoxItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageComboBoxItems : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxImageComboBoxItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxImageComboBoxItem* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TcxImageComboBoxItem* const Value);
	
protected:
	void __fastcall InternalChanged(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TcxImageComboBoxItems(System::Classes::TPersistent* AOwner);
	HIDESBASE TcxImageComboBoxItem* __fastcall Add(void);
	__property TcxImageComboBoxItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxImageComboBoxItems(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxImageComboBoxListBox;
class DELPHICLASS TcxCustomImageComboBox;
class DELPHICLASS TcxCustomImageComboBoxProperties;
class PASCALIMPLEMENTATION TcxImageComboBoxListBox : public Cxdropdownedit::TcxComboBoxListBox
{
	typedef Cxdropdownedit::TcxComboBoxListBox inherited;
	
private:
	int FClientWidth;
	bool FHasScrollbar;
	HIDESBASE TcxCustomImageComboBox* __fastcall GetEdit(void);
	TcxCustomImageComboBoxProperties* __fastcall GetProperties(void);
	bool __fastcall IsDescriptionsAssigned(void);
	
protected:
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall MeasureItem(int Index, int &Height);
	virtual void __fastcall RecreateWindow(void);
	System::Types::TRect __fastcall GetImageRect(Vcl::Imglist::TCustomImageList* AImages, System::Types::TRect &R);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual int __fastcall GetMaxItemWidth(void);
	__property TcxCustomImageComboBox* Edit = {read=GetEdit};
	__property TcxCustomImageComboBoxProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual TcxImageComboBoxListBox(System::Classes::TComponent* AOwner);
	virtual int __fastcall GetHeight(int ARowCount, int AMaxHeight);
	virtual int __fastcall GetItemWidth(int AIndex);
public:
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TcxImageComboBoxListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxImageComboBoxListBox(HWND ParentWindow) : Cxdropdownedit::TcxComboBoxListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxImageComboBoxLookupData;
class PASCALIMPLEMENTATION TcxImageComboBoxLookupData : public Cxdropdownedit::TcxComboBoxLookupData
{
	typedef Cxdropdownedit::TcxComboBoxLookupData inherited;
	
private:
	TcxImageComboBoxListBox* __fastcall GetList(void);
	
protected:
	virtual Cxtextedit::TcxCustomEditListBoxClass __fastcall GetListBoxClass(void);
	virtual System::UnicodeString __fastcall GetItem(int Index);
	virtual int __fastcall GetItemCount(void);
	__property TcxImageComboBoxListBox* List = {read=GetList};
	
public:
	virtual void __fastcall TextChanged(void);
public:
	/* TcxCustomTextEditLookupData.Create */ inline __fastcall virtual TcxImageComboBoxLookupData(System::Classes::TPersistent* AOwner) : Cxdropdownedit::TcxComboBoxLookupData(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxImageComboBoxLookupData(void) { }
	
};


class DELPHICLASS TcxImageComboBoxViewData;
class PASCALIMPLEMENTATION TcxImageComboBoxViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
private:
	HIDESBASE TcxCustomImageComboBoxProperties* __fastcall GetProperties(void);
	
protected:
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual bool __fastcall IsComboBoxStyle(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall DisplayValueToDrawValue(const System::Variant &ADisplayValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomImageComboBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxImageComboBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxImageComboBoxViewData(void) { }
	
};


enum TcxImageAlign : unsigned char { iaLeft, iaRight };

class DELPHICLASS TcxImageComboBoxViewInfo;
class PASCALIMPLEMENTATION TcxImageComboBoxViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
protected:
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	System::Types::TRect ImageRect;
	bool ShowDescriptions;
	TcxImageAlign ImageAlign;
	System::Uitypes::TImageIndex ImageIndex;
	Vcl::Imglist::TCustomImageList* Images;
	virtual void __fastcall Offset(int DX, int DY);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxImageComboBoxViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxImageComboBoxViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class PASCALIMPLEMENTATION TcxCustomImageComboBoxProperties : public Cxdropdownedit::TcxCustomComboBoxProperties
{
	typedef Cxdropdownedit::TcxCustomComboBoxProperties inherited;
	
private:
	System::UnicodeString FDefaultDescription;
	System::Uitypes::TImageIndex FDefaultImageIndex;
	TcxImageAlign FImageAlign;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	TcxImageComboBoxItems* FItems;
	Vcl::Imglist::TCustomImageList* FLargeImages;
	Vcl::Imglist::TChangeLink* FLargeImagesChangeLink;
	bool FMultiLineText;
	bool FShowDescriptions;
	void __fastcall ImagesChange(System::TObject* Sender);
	void __fastcall LargeImagesChange(System::TObject* Sender);
	void __fastcall SetDefaultDescription(const System::UnicodeString Value);
	void __fastcall SetDefaultImageIndex(const System::Uitypes::TImageIndex Value);
	void __fastcall SetImageAlign(const TcxImageAlign Value);
	HIDESBASE void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	HIDESBASE void __fastcall SetItems(TcxImageComboBoxItems* const Value);
	void __fastcall SetLargeImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetMultiLineText(const bool Value);
	void __fastcall SetShowDescriptions(const bool Value);
	
protected:
	TcxImageComboBoxItem* __fastcall FindItemByText(const System::UnicodeString AText);
	virtual bool __fastcall FindLookupText(const System::UnicodeString AText);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual void __fastcall InternalGetImageComboBoxDisplayValue(TcxImageComboBoxItem* AItem, /* out */ System::UnicodeString &AText, /* out */ System::Uitypes::TImageIndex &AImageIndex, bool AAlwaysShowDescription = false);
	
public:
	__fastcall virtual TcxCustomImageComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomImageComboBoxProperties(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	TcxImageComboBoxItem* __fastcall FindItemByValue(const System::Variant &AValue);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	void __fastcall GetImageComboBoxDisplayValue(const System::Variant &AEditValue, /* out */ System::UnicodeString &AText, /* out */ System::Uitypes::TImageIndex &AImageIndex);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &AEditValue, bool AEditFocused);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	__property System::UnicodeString DefaultDescription = {read=FDefaultDescription, write=SetDefaultDescription};
	__property System::Uitypes::TImageIndex DefaultImageIndex = {read=FDefaultImageIndex, write=SetDefaultImageIndex, default=-1};
	__property TcxImageAlign ImageAlign = {read=FImageAlign, write=SetImageAlign, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TcxImageComboBoxItems* Items = {read=FItems, write=SetItems};
	__property Vcl::Imglist::TCustomImageList* LargeImages = {read=FLargeImages, write=SetLargeImages};
	__property bool MultiLineText = {read=FMultiLineText, write=SetMultiLineText, default=0};
	__property bool ShowDescriptions = {read=FShowDescriptions, write=SetShowDescriptions, default=1};
};


class DELPHICLASS TcxImageComboBoxProperties;
class PASCALIMPLEMENTATION TcxImageComboBoxProperties : public TcxCustomImageComboBoxProperties
{
	typedef TcxCustomImageComboBoxProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property ButtonGlyph;
	__property ClearKey = {default=0};
	__property DefaultDescription = {default=0};
	__property DefaultImageIndex = {default=-1};
	__property DropDownRows = {default=8};
	__property ImageAlign = {default=0};
	__property Images;
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property ImmediateUpdateText = {default=0};
	__property Items;
	__property LargeImages;
	__property MultiLineText = {default=0};
	__property PopupAlignment = {default=0};
	__property PostPopupValueOnTab = {default=0};
	__property ReadOnly;
	__property Revertable = {default=0};
	__property ShowDescriptions = {default=1};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnButtonClick;
	__property OnChange;
	__property OnCloseQuery;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnInitPopup;
	__property OnPopup;
	__property OnValidate;
public:
	/* TcxCustomImageComboBoxProperties.Create */ inline __fastcall virtual TcxImageComboBoxProperties(System::Classes::TPersistent* AOwner) : TcxCustomImageComboBoxProperties(AOwner) { }
	/* TcxCustomImageComboBoxProperties.Destroy */ inline __fastcall virtual ~TcxImageComboBoxProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomImageComboBox : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	HIDESBASE TcxCustomImageComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomImageComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxImageComboBoxLookupData* __fastcall GetLookupData(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomImageComboBoxProperties* const Value);
	
protected:
	virtual System::TObject* __fastcall GetItemObject(void);
	virtual System::Types::TSize __fastcall GetPopupWindowClientPreferredSize(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual System::Variant __fastcall LookupKeyToEditValue(const System::Variant &AKey);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall UpdateDrawValue(void);
	__property TcxImageComboBoxLookupData* LookupData = {read=GetLookupData};
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomImageComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomImageComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomImageComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomImageComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomImageComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomImageComboBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxImageComboBox;
class PASCALIMPLEMENTATION TcxImageComboBox : public TcxCustomImageComboBox
{
	typedef TcxCustomImageComboBox inherited;
	
private:
	HIDESBASE TcxImageComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxImageComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxImageComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxImageComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ItemIndex;
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxImageComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxImageComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxImageComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomImageComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxImageComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomImageComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxImageComboBox(HWND ParentWindow) : TcxCustomImageComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterImageComboBoxHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterImageComboBoxHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterImageComboBoxHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterImageComboBoxHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cximagecombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMAGECOMBOBOX)
using namespace Cximagecombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximagecomboboxHPP
