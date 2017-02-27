// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxColorComboBox.pas' rev: 24.00 (Win32)

#ifndef CxcolorcomboboxHPP
#define CxcolorcomboboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxEditUtils.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcolorcombobox
{
//-- type declarations -------------------------------------------------------
enum TcxColorBoxAlign : unsigned char { cbaLeft, cbaRight };

enum TcxColorNamingConvention : unsigned char { cxncNone, cxncDelphi, cxncHTML4, cxncX11 };

enum TcxColorPrepareList : unsigned char { cxplNone, cxplDelphi, cxplHTML4, cxplX11, cxplX11Ordered };

enum TcxColorValueFormat : unsigned char { cxcvRGB, cxcvHexadecimal, cxcvInteger };

enum TcxDefaultColorStyle : unsigned char { cxdcClear, cxdcColor, cxdcHatched, cxdcText, cxdcCustom };

enum TcxMRUColorAction : unsigned char { mcaNone, mcaMoved, mcaAdded, mcaDeleted };

class DELPHICLASS TcxColorComboBoxItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxColorComboBoxItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Uitypes::TColor FColor;
	Vcl::Controls::TCaption FDescription;
	bool FIsCustomColor;
	int FTag;
	Vcl::Controls::TCaption __fastcall GetDescription(void);
	bool __fastcall IsTagStored(void);
	void __fastcall SetColor(const System::Uitypes::TColor Value);
	void __fastcall SetDescription(const Vcl::Controls::TCaption Value);
	
public:
	__fastcall virtual TcxColorComboBoxItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool IsCustomColor = {read=FIsCustomColor, nodefault};
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property Vcl::Controls::TCaption Description = {read=GetDescription, write=SetDescription};
	__property int Tag = {read=FTag, write=FTag, stored=IsTagStored, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxColorComboBoxItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxColorComboBoxItems;
class DELPHICLASS TcxCustomColorComboBoxProperties;
class PASCALIMPLEMENTATION TcxColorComboBoxItems : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxColorComboBoxItem* operator[](int Index) { return Items[Index]; }
	
private:
	bool FUpdateLocked;
	System::Classes::TNotifyEvent FOnUpdate;
	TcxColorComboBoxItem* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TcxColorComboBoxItem* const Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property System::Classes::TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
	
public:
	void __fastcall CancelUpdate(void);
	HIDESBASE TcxCustomColorComboBoxProperties* __fastcall Owner(void);
	__property TcxColorComboBoxItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
	virtual TcxColorComboBoxItem* __fastcall FindColorItem(const System::Uitypes::TColor AColor);
	int __fastcall GetIndexByColor(System::Uitypes::TColor AColor);
	System::Uitypes::TColor __fastcall GetColorByIndex(int AIndex, System::Uitypes::TColor ADefaultColor);
	virtual TcxColorComboBoxItem* __fastcall AddColor(const System::Uitypes::TColor AColor, const System::UnicodeString ADescription);
	virtual TcxColorComboBoxItem* __fastcall InsertColor(int Index, const System::Uitypes::TColor AColor, const System::UnicodeString ADescription);
	HIDESBASE TcxColorComboBoxItem* __fastcall Add(void);
	HIDESBASE TcxColorComboBoxItem* __fastcall Insert(int Index);
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	virtual void __fastcall ClearCustom(void);
	virtual void __fastcall ClearNonCustom(void);
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxColorComboBoxItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxColorComboBoxItems(void) { }
	
};


class DELPHICLASS TcxCustomColorComboBoxViewInfo;
class PASCALIMPLEMENTATION TcxCustomColorComboBoxViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	System::Uitypes::TColor FBkColor;
	int FColorBoxWidth;
	TcxColorBoxAlign FColorBoxAlign;
	System::Uitypes::TColor FColorBoxColor;
	System::Types::TRect FColorBoxRect;
	System::Uitypes::TColor FColorBoxFrameColor;
	bool FShowDescriptions;
	TcxDefaultColorStyle FDefaultColorStyle;
	bool FFoundItem;
	
public:
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Offset(int DX, int DY);
	__property System::Uitypes::TColor BkColor = {read=FBkColor, write=FBkColor, nodefault};
	__property int ColorBoxWidth = {read=FColorBoxWidth, write=FColorBoxWidth, nodefault};
	__property TcxColorBoxAlign ColorBoxAlign = {read=FColorBoxAlign, write=FColorBoxAlign, nodefault};
	__property System::Uitypes::TColor ColorBoxFrameColor = {read=FColorBoxFrameColor, write=FColorBoxFrameColor, nodefault};
	__property System::Uitypes::TColor ColorBoxColor = {read=FColorBoxColor, write=FColorBoxColor, nodefault};
	__property System::Types::TRect ColorBoxRect = {read=FColorBoxRect, write=FColorBoxRect};
	__property TcxDefaultColorStyle DefaultColorStyle = {read=FDefaultColorStyle, write=FDefaultColorStyle, nodefault};
	__property bool ShowDescriptions = {read=FShowDescriptions, write=FShowDescriptions, nodefault};
	__property bool FoundItem = {read=FFoundItem, write=FFoundItem, nodefault};
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomColorComboBoxViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxCustomColorComboBoxViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class DELPHICLASS TcxCustomColorComboBoxViewData;
class PASCALIMPLEMENTATION TcxCustomColorComboBoxViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
private:
	HIDESBASE TcxCustomColorComboBoxProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateViewInfoProperties(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual bool __fastcall IsComboBoxStyle(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall DisplayValueToDrawValue(const System::Variant &ADisplayValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomColorComboBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomColorComboBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomColorComboBoxViewData(void) { }
	
};


class DELPHICLASS TcxCustomColorComboBoxListBox;
class DELPHICLASS TcxCustomColorComboBox;
class PASCALIMPLEMENTATION TcxCustomColorComboBoxListBox : public Cxdropdownedit::TcxCustomComboBoxListBox
{
	typedef Cxdropdownedit::TcxCustomComboBoxListBox inherited;
	
private:
	HIDESBASE TcxCustomColorComboBox* __fastcall GetEdit(void);
	
protected:
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
public:
	virtual int __fastcall GetItemHeight(int AIndex = 0xffffffff);
	__property TcxCustomColorComboBox* Edit = {read=GetEdit};
public:
	/* TcxCustomComboBoxListBox.Create */ inline __fastcall virtual TcxCustomColorComboBoxListBox(System::Classes::TComponent* AOwner) : Cxdropdownedit::TcxCustomComboBoxListBox(AOwner) { }
	
public:
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TcxCustomColorComboBoxListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomColorComboBoxListBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBoxListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxColorComboBoxLookupData;
class PASCALIMPLEMENTATION TcxColorComboBoxLookupData : public Cxdropdownedit::TcxComboBoxLookupData
{
	typedef Cxdropdownedit::TcxComboBoxLookupData inherited;
	
private:
	HIDESBASE TcxCustomColorComboBoxProperties* __fastcall GetActiveProperties(void);
	
protected:
	virtual Cxtextedit::TcxCustomEditListBoxClass __fastcall GetListBoxClass(void);
	virtual System::UnicodeString __fastcall GetItem(int Index);
	virtual int __fastcall GetItemCount(void);
	__property TcxCustomColorComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
public:
	virtual System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0);
public:
	/* TcxCustomTextEditLookupData.Create */ inline __fastcall virtual TcxColorComboBoxLookupData(System::Classes::TPersistent* AOwner) : Cxdropdownedit::TcxComboBoxLookupData(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxColorComboBoxLookupData(void) { }
	
};


enum TcxColorComboStyle : unsigned char { cxccsComboList, cxccsComboEdit };

enum TcxColorDialogType : unsigned char { cxcdtDefault, cxcdtCustom };

typedef void __fastcall (__closure *TcxSelectCustomColorEvent)(System::TObject* Sender, System::Uitypes::TColor &AColor, System::UnicodeString &AColorDescription, bool &AddToList);

typedef void __fastcall (__closure *TcxNamingConventionEvent)(System::TObject* Sender, const System::Uitypes::TColor AColor, System::UnicodeString &AColorDescription);

typedef void __fastcall (__closure *TcxChangeItemIndexEvent)(System::TObject* Sender, const int AIndex);

typedef void __fastcall (__closure *TcxGetDefaultColorEvent)(System::TObject* Sender, System::Uitypes::TColor &AColor);

class PASCALIMPLEMENTATION TcxCustomColorComboBoxProperties : public Cxdropdownedit::TcxCustomComboBoxProperties
{
	typedef Cxdropdownedit::TcxCustomComboBoxProperties inherited;
	
private:
	bool FAllowSelectColor;
	TcxColorComboStyle FColorComboStyle;
	TcxColorBoxAlign FColorBoxAlign;
	System::Uitypes::TColor FColorBoxFrameColor;
	int FColorBoxWidth;
	TcxColorDialogType FColorDialogType;
	TcxColorValueFormat FColorValueFormat;
	System::Uitypes::TColor FDefaultColor;
	System::UnicodeString FDefaultDescription;
	TcxDefaultColorStyle FDefaultColorStyle;
	TcxColorComboBoxItems* FItems;
	TcxColorComboBoxItems* FCustomColors;
	TcxColorComboBoxItems* FMRUColors;
	System::Byte FMaxMRUColors;
	TcxColorNamingConvention FNamingConvention;
	bool FShowDescriptions;
	TcxNamingConventionEvent FOnNamingConvention;
	TcxSelectCustomColorEvent FOnSelectCustomColor;
	System::Classes::TNotifyEvent FOnAddedMRUColor;
	System::Classes::TNotifyEvent FOnDeletedMRUColor;
	TcxGetDefaultColorEvent FOnGetDefaultColor;
	System::Classes::TNotifyEvent FOnLoadColorList;
	TcxColorPrepareList FPrepareList;
	TcxColorComboBoxItem* __fastcall ColorItemByIndex(int AIndex);
	void __fastcall DeleteOverMRUColors(void);
	System::UnicodeString __fastcall DoConvertNaming(int AIndex);
	HIDESBASE TcxColorComboBoxItems* __fastcall GetItems(void);
	void __fastcall InternalGetColorComboBoxDisplayValue(int AItemIndex, const System::Variant &AEditValue, /* out */ System::Uitypes::TColor &AColor, /* out */ System::UnicodeString &ADescription, /* out */ bool &AColorFound);
	void __fastcall InternalPrepareColorList(TcxColorPrepareList APrepareList)/* overload */;
	void __fastcall InternalPrepareColorList(System::Uitypes::TColor *AColorValues, const int AColorValues_Size, System::UnicodeString *AColorNames, const int AColorNames_Size)/* overload */;
	bool __fastcall IsDefaultDescriptionStored(void);
	void __fastcall ReadCustomColors(System::Classes::TReader* Reader);
	void __fastcall ReadPrepareInfo(System::Classes::TReader* Reader);
	void __fastcall SetAllowSelectColor(bool Value);
	void __fastcall SetColorBoxAlign(TcxColorBoxAlign Value);
	void __fastcall SetColorBoxFrameColor(System::Uitypes::TColor Value);
	void __fastcall SetColorBoxWidth(int Value);
	void __fastcall SetColorComboStyle(TcxColorComboStyle Value);
	void __fastcall SetColorValueFormat(TcxColorValueFormat Value);
	void __fastcall SetDefaultColor(System::Uitypes::TColor Value);
	void __fastcall SetDefaultDescription(System::UnicodeString Value);
	void __fastcall SetDefaultColorStyle(TcxDefaultColorStyle Value);
	void __fastcall SetCustomColors(TcxColorComboBoxItems* Value);
	HIDESBASE void __fastcall SetItems(TcxColorComboBoxItems* const Value);
	void __fastcall SetMaxMRUColors(System::Byte Value);
	void __fastcall SetMRUColors(TcxColorComboBoxItems* Value);
	void __fastcall SetNamingConvention(TcxColorNamingConvention Value);
	void __fastcall SetPrepareList(TcxColorPrepareList Value);
	void __fastcall SetShowDescriptions(const bool Value);
	void __fastcall SynchronizeCustomColors(void);
	void __fastcall CustomColorChanged(System::TObject* ASender);
	void __fastcall ValidateMRUColors(void);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	bool __fastcall ShowColorBox(bool AColorFound);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	__classmethod virtual Cxdropdownedit::TcxCustomEditPopupWindowClass __fastcall GetPopupWindowClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall IsEditValueNumeric(void);
	System::Uitypes::TColor __fastcall EditValueToColorValue(const System::Variant &AEditValue);
	System::Uitypes::TColor __fastcall GetColorByIndex(int AIndex);
	bool __fastcall GetColorByDescription(const System::UnicodeString ADescription, /* out */ System::Uitypes::TColor &AColor);
	int __fastcall GetIndexByColor(System::Uitypes::TColor AColor);
	System::UnicodeString __fastcall GetDescriptionByIndex(int AIndex);
	int __fastcall IndexByValue(const System::Variant &AValue);
	virtual bool __fastcall IsDisplayValueNumeric(void);
	bool __fastcall StrToColor(const System::UnicodeString S, /* out */ System::Uitypes::TColor &AColor);
	virtual TcxMRUColorAction __fastcall AddMRUColor(const System::Uitypes::TColor AColor);
	virtual TcxMRUColorAction __fastcall DelMRUColor(const System::Uitypes::TColor AColor);
	virtual void __fastcall ClearMRUColors(void);
	virtual void __fastcall DoGetDefaultColor(System::Uitypes::TColor &AColor);
	void __fastcall TranslateValues(const System::Variant &AEditValue, System::Uitypes::TColor &AColor, System::UnicodeString &ADescription, bool ANeedDescription = false);
	
public:
	__fastcall virtual TcxCustomColorComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomColorComboBoxProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual void __fastcall Update(Cxedit::TcxCustomEditProperties* AProperties);
	void __fastcall GetColorComboBoxDisplayValue(const System::Variant &AEditValue, /* out */ System::Uitypes::TColor &AColor, /* out */ System::UnicodeString &ADescription, /* out */ bool &AColorFound);
	void __fastcall PrepareColorList(TcxColorPrepareList APrepareList, bool ASaveCustom, bool ASaveMRU);
	void __fastcall PrepareDelphiColorList(const bool ASaveCustom, const bool ASaveMRU);
	void __fastcall PrepareHTML4ColorList(const bool ASaveCustom, const bool ASaveMRU);
	void __fastcall PrepareX11ColorList(const bool ASaveCustom, const bool ASaveMRU);
	void __fastcall PrepareX11OrderedColorList(const bool ASaveCustom, const bool ASaveMRU);
	__property bool AllowSelectColor = {read=FAllowSelectColor, write=SetAllowSelectColor, default=0};
	__property TcxColorBoxAlign ColorBoxAlign = {read=FColorBoxAlign, write=SetColorBoxAlign, default=0};
	__property System::Uitypes::TColor ColorBoxFrameColor = {read=FColorBoxFrameColor, write=SetColorBoxFrameColor, default=-16777200};
	__property int ColorBoxWidth = {read=FColorBoxWidth, write=SetColorBoxWidth, default=30};
	__property TcxColorComboStyle ColorComboStyle = {read=FColorComboStyle, write=SetColorComboStyle, default=1};
	__property TcxColorDialogType ColorDialogType = {read=FColorDialogType, write=FColorDialogType, default=0};
	__property TcxColorValueFormat ColorValueFormat = {read=FColorValueFormat, write=SetColorValueFormat, default=0};
	__property System::Uitypes::TColor DefaultColor = {read=FDefaultColor, write=SetDefaultColor, default=-16777211};
	__property TcxDefaultColorStyle DefaultColorStyle = {read=FDefaultColorStyle, write=SetDefaultColorStyle, default=1};
	__property System::UnicodeString DefaultDescription = {read=FDefaultDescription, write=SetDefaultDescription, stored=IsDefaultDescriptionStored};
	__property TcxColorComboBoxItems* CustomColors = {read=FCustomColors, write=SetCustomColors};
	__property TcxColorComboBoxItems* Items = {read=GetItems, write=SetItems};
	__property System::Byte MaxMRUColors = {read=FMaxMRUColors, write=SetMaxMRUColors, default=10};
	__property TcxColorComboBoxItems* MRUColors = {read=FMRUColors, write=SetMRUColors};
	__property TcxColorNamingConvention NamingConvention = {read=FNamingConvention, write=SetNamingConvention, default=1};
	__property TcxColorPrepareList PrepareList = {read=FPrepareList, write=SetPrepareList, default=1};
	__property bool ShowDescriptions = {read=FShowDescriptions, write=SetShowDescriptions, default=1};
	__property System::Classes::TNotifyEvent OnAddedMRUColor = {read=FOnAddedMRUColor, write=FOnAddedMRUColor};
	__property System::Classes::TNotifyEvent OnDeletedMRUColor = {read=FOnDeletedMRUColor, write=FOnDeletedMRUColor};
	__property TcxGetDefaultColorEvent OnGetDefaultColor = {read=FOnGetDefaultColor, write=FOnGetDefaultColor};
	__property TcxNamingConventionEvent OnNamingConvention = {read=FOnNamingConvention, write=FOnNamingConvention};
	__property TcxSelectCustomColorEvent OnSelectCustomColor = {read=FOnSelectCustomColor, write=FOnSelectCustomColor};
};


class DELPHICLASS TcxColorComboBoxProperties;
class PASCALIMPLEMENTATION TcxColorComboBoxProperties : public TcxCustomColorComboBoxProperties
{
	typedef TcxCustomColorComboBoxProperties inherited;
	
__published:
	__property Alignment;
	__property AllowSelectColor = {default=0};
	__property AssignedValues;
	__property BeepOnError = {default=0};
	__property ButtonGlyph;
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property ColorBoxAlign = {default=0};
	__property ColorBoxFrameColor = {default=-16777200};
	__property ColorBoxWidth = {default=30};
	__property ColorComboStyle = {default=1};
	__property ColorDialogType = {default=0};
	__property ColorValueFormat = {default=0};
	__property CustomColors;
	__property DefaultColor = {default=-16777211};
	__property DefaultColorStyle = {default=1};
	__property DefaultDescription = {default=0};
	__property DropDownAutoWidth = {default=1};
	__property DropDownRows = {default=8};
	__property DropDownSizeable = {default=0};
	__property DropDownWidth = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property ImmediateUpdateText = {default=0};
	__property MaxMRUColors = {default=10};
	__property NamingConvention = {default=1};
	__property OEMConvert = {default=0};
	__property PopupAlignment = {default=0};
	__property PostPopupValueOnTab = {default=0};
	__property PrepareList = {default=1};
	__property ReadOnly;
	__property Revertable = {default=0};
	__property ShowDescriptions = {default=1};
	__property ValidateOnEnter = {default=1};
	__property OnAddedMRUColor;
	__property OnChange;
	__property OnCloseUp;
	__property OnDeletedMRUColor;
	__property OnEditValueChanged;
	__property OnGetDefaultColor;
	__property OnInitPopup;
	__property OnNamingConvention;
	__property OnNewLookupDisplayText;
	__property OnPopup;
	__property OnSelectCustomColor;
public:
	/* TcxCustomColorComboBoxProperties.Create */ inline __fastcall virtual TcxColorComboBoxProperties(System::Classes::TPersistent* AOwner) : TcxCustomColorComboBoxProperties(AOwner) { }
	/* TcxCustomColorComboBoxProperties.Destroy */ inline __fastcall virtual ~TcxColorComboBoxProperties(void) { }
	
};


class DELPHICLASS TcxCustomColorComboBoxInnerEdit;
class PASCALIMPLEMENTATION TcxCustomColorComboBoxInnerEdit : public Cxdropdownedit::TcxCustomComboBoxInnerEdit
{
	typedef Cxdropdownedit::TcxCustomComboBoxInnerEdit inherited;
	
public:
	/* TcxCustomInnerTextEdit.Create */ inline __fastcall virtual TcxCustomColorComboBoxInnerEdit(System::Classes::TComponent* AOwner) : Cxdropdownedit::TcxCustomComboBoxInnerEdit(AOwner) { }
	/* TcxCustomInnerTextEdit.Destroy */ inline __fastcall virtual ~TcxCustomColorComboBoxInnerEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomColorComboBoxInnerEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBoxInnerEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxColorComboBoxPopupWindow;
class PASCALIMPLEMENTATION TcxColorComboBoxPopupWindow : public Cxdropdownedit::TcxComboBoxPopupWindow
{
	typedef Cxdropdownedit::TcxComboBoxPopupWindow inherited;
	
public:
	__property ViewInfo;
	__property SysPanelStyle;
public:
	/* TcxCustomEditPopupWindow.Create */ inline __fastcall virtual TcxColorComboBoxPopupWindow(Vcl::Controls::TWinControl* AOwnerControl) : Cxdropdownedit::TcxComboBoxPopupWindow(AOwnerControl) { }
	/* TcxCustomEditPopupWindow.Destroy */ inline __fastcall virtual ~TcxColorComboBoxPopupWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxColorComboBoxPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxdropdownedit::TcxComboBoxPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxColorComboBoxPopupWindow(HWND ParentWindow) : Cxdropdownedit::TcxComboBoxPopupWindow(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomColorComboBox : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	Vcl::Dialogs::TColorDialog* FColorDialog;
	bool FIsDialogShowed;
	bool FPropertiesUpdate;
	Vcl::Dialogs::TColorDialog* __fastcall GetColorDialog(void);
	System::Uitypes::TColor __fastcall GetColorValue(void);
	bool __fastcall IsColorValueStored(void);
	void __fastcall SetColorValue(System::Uitypes::TColor Value);
	HIDESBASE TcxColorComboBoxLookupData* __fastcall GetLookupData(void);
	HIDESBASE TcxCustomColorComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomColorComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomColorComboBoxProperties* Value);
	void __fastcall PropertiesLoadColorListHandler(System::TObject* Sender);
	void __fastcall FlushEditValue(void);
	
protected:
	virtual bool __fastcall CanSelectItem(bool AFindSelection);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall DoButtonClick(int AButtonVisibleIndex);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeInnerEdit(void);
	virtual void __fastcall InitializePopupWindow(void);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual System::Variant __fastcall LookupKeyToEditValue(const System::Variant &AKey);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual int __fastcall DoSelectCustomColor(System::Uitypes::TColor AColor, bool ANeedFireEvent);
	virtual void __fastcall ClearEditValue(void);
	bool __fastcall DoOnSelectCustomColor(System::Uitypes::TColor &AColor, /* out */ System::UnicodeString &AColorDescription, bool ANeedFireEvent);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual bool __fastcall NeedResetInvalidTextWhenPropertiesChanged(void);
	virtual void __fastcall SelectCustomColor(System::TObject* Sender);
	__property System::Uitypes::TColor ColorValue = {read=GetColorValue, write=SetColorValue, stored=IsColorValueStored, nodefault};
	__property Vcl::Dialogs::TColorDialog* ColorDialog = {read=GetColorDialog};
	__property TcxColorComboBoxLookupData* LookupData = {read=GetLookupData};
	
public:
	__fastcall virtual ~TcxCustomColorComboBox(void);
	DYNAMIC bool __fastcall Focused(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall IsChildWindow(NativeUInt AWnd);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	TcxMRUColorAction __fastcall AddMRUColor(const System::Uitypes::TColor AColor);
	TcxMRUColorAction __fastcall DelMRUColor(const System::Uitypes::TColor AColor);
	void __fastcall PrepareColorList(TcxColorPrepareList APrepareList, bool ASaveCustom, bool ASaveMRU);
	void __fastcall PrepareDelphiColorList(const bool ASaveCustom, const bool ASaveMRU);
	void __fastcall PrepareHTML4ColorList(const bool ASaveCustom, const bool ASaveMRU);
	void __fastcall PrepareX11ColorList(const bool ASaveCustom, const bool ASaveMRU);
	void __fastcall PrepareX11OrderedColorList(const bool ASaveCustom, const bool ASaveMRU);
	__property TcxCustomColorComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomColorComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomColorComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomColorComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomColorComboBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxColorComboBox;
class PASCALIMPLEMENTATION TcxColorComboBox : public TcxCustomColorComboBox
{
	typedef TcxCustomColorComboBox inherited;
	
private:
	HIDESBASE TcxColorComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxColorComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxColorComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxColorComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property ColorValue;
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
	__property TcxColorComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomColorComboBox.Destroy */ inline __fastcall virtual ~TcxColorComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxColorComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomColorComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxColorComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomColorComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxColorComboBox(HWND ParentWindow) : TcxCustomColorComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterColorComboBoxHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterColorComboBoxHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterColorComboBoxHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterColorComboBoxHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcolorcombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCOLORCOMBOBOX)
using namespace Cxcolorcombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcolorcomboboxHPP
