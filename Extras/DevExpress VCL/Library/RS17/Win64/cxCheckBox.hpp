// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCheckBox.pas' rev: 24.00 (Win64)

#ifndef CxcheckboxHPP
#define CxcheckboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Actions.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcheckbox
{
//-- type declarations -------------------------------------------------------
enum TcxCheckBoxNullValueShowingStyle : unsigned char { nssUnchecked, nssInactive, nssGrayedChecked };

enum TcxCheckStatesValueFormatEx : unsigned char { cvfCaptions, cvfIndices, cvfInteger, cvfStatesString, cvfCustom };

typedef TcxCheckStatesValueFormatEx TcxCheckStatesValueFormat;

typedef System::DynamicArray<Cxlookandfeelpainters::TcxCheckBoxState> TcxCheckStates;

typedef Cxedit::TcxEditBorderStyle TcxEditCheckBoxBorderStyle;

typedef void __fastcall (__closure *TcxCheckStatesToValueEvent)(System::TObject* Sender, const TcxCheckStates ACheckStates, /* out */ System::Variant &AValue);

typedef void __fastcall (__closure *TcxValueToCheckStatesEvent)(System::TObject* Sender, const System::Variant &AValue, TcxCheckStates &ACheckStates);

__interface IcxCheckItems;
typedef System::DelphiInterface<IcxCheckItems> _di_IcxCheckItems;
__interface  INTERFACE_UUID("{5BF13228-CF05-4741-9833-F2B8FBFD57ED}") IcxCheckItems  : public System::IInterface 
{
	
public:
	virtual System::UnicodeString __fastcall GetCaption(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	__property System::UnicodeString Captions[int Index] = {read=GetCaption};
	__property int Count = {read=GetCount};
};

class DELPHICLASS TcxCaptionItem;
class PASCALIMPLEMENTATION TcxCaptionItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Vcl::Controls::TCaption FCaption;
	int FTag;
	bool __fastcall IsTagStored(void);
	void __fastcall SetCaption(Vcl::Controls::TCaption AValue);
	
protected:
	__property Vcl::Controls::TCaption Caption = {read=FCaption, write=SetCaption};
	__property int Tag = {read=FTag, write=FTag, stored=IsTagStored, nodefault};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxCaptionItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxCaptionItem(void) { }
	
};


class DELPHICLASS TcxCaptionItems;
class PASCALIMPLEMENTATION TcxCaptionItems : public Cxclasses::TcxOwnedInterfacedCollection
{
	typedef Cxclasses::TcxOwnedInterfacedCollection inherited;
	
public:
	TcxCaptionItem* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	HIDESBASE TcxCaptionItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxCaptionItem* AValue);
	
protected:
	virtual int __fastcall DoCompareItems(Cxclasses::TcxInterfacedCollectionItem* AItem1, Cxclasses::TcxInterfacedCollectionItem* AItem2);
	System::UnicodeString __fastcall GetCaption(int AIndex);
	HIDESBASE int __fastcall GetCount(void);
	
public:
	__property TcxCaptionItem* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxOwnedInterfacedCollection.Destroy */ inline __fastcall virtual ~TcxCaptionItems(void) { }
	
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxCaptionItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : Cxclasses::TcxOwnedInterfacedCollection(AOwner, ItemClass) { }
	
private:
	void *__IcxCheckItems;	/* IcxCheckItems */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5BF13228-CF05-4741-9833-F2B8FBFD57ED}
	operator _di_IcxCheckItems()
	{
		_di_IcxCheckItems intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxCheckItems*(void) { return (IcxCheckItems*)&__IcxCheckItems; }
	#endif
	
};


class DELPHICLASS TcxCheckBoxFadingHelper;
class DELPHICLASS TcxCustomCheckBoxViewInfo;
class PASCALIMPLEMENTATION TcxCheckBoxFadingHelper : public Cxedit::TcxCustomEditFadingHelper
{
	typedef Cxedit::TcxCustomEditFadingHelper inherited;
	
private:
	Cxlookandfeelpainters::TcxEditCheckState FState;
	TcxCustomCheckBoxViewInfo* FViewInfo;
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual Cxedit::TcxCustomEditViewInfo* __fastcall GetEditViewInfo(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	__fastcall virtual TcxCheckBoxFadingHelper(TcxCustomCheckBoxViewInfo* AViewInfo);
	virtual void __fastcall Invalidate(void)/* overload */;
	void __fastcall UpdateState(void);
	__property Cxlookandfeelpainters::TcxEditCheckState State = {read=FState, nodefault};
	__property TcxCustomCheckBoxViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxCheckBoxFadingHelper(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Invalidate(const System::Types::TRect &R, bool AEraseBackground){ Cxedit::TcxCustomEditFadingHelper::Invalidate(R, AEraseBackground); }
	
};


class DELPHICLASS TcxCustomCheckBox;
class PASCALIMPLEMENTATION TcxCustomCheckBoxViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	TcxCustomCheckBox* __fastcall GetEdit(void);
	
protected:
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall IsTextEnabled(void);
	virtual void __fastcall StoreLastState(void);
	
public:
	System::Classes::TAlignment Alignment;
	int CheckBorderOffset;
	Cxedit::TcxEditBorderStyle CheckBoxBorderStyle;
	Vcl::Graphics::TBitmap* CheckBoxGlyph;
	int CheckBoxGlyphCount;
	Cxlookandfeelpainters::TcxEditCheckState CheckBoxLastState;
	System::Types::TRect CheckBoxRect;
	System::Types::TSize CheckBoxSize;
	Cxlookandfeelpainters::TcxEditCheckState CheckBoxState;
	int DrawCaptionFlags;
	TcxCheckBoxFadingHelper* FadingHelper;
	System::Types::TRect FocusRect;
	bool HasGlyph;
	bool IsTextColorAssigned;
	TcxCheckBoxNullValueShowingStyle NullValueShowingStyle;
	Cxlookandfeelpainters::TcxCheckBoxState State;
	__fastcall virtual TcxCustomCheckBoxViewInfo(void);
	__fastcall virtual ~TcxCustomCheckBoxViewInfo(void);
	virtual void __fastcall Assign(System::TObject* Source);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(Cxcontainer::TcxContainerViewInfo* AViewInfo);
	virtual bool __fastcall IsHotTrack(void)/* overload */;
	virtual bool __fastcall IsHotTrack(System::Types::TPoint P)/* overload */;
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Offset(int DX, int DY);
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &AInnerEditRect, Cxcontainer::TcxContainerViewInfo* AViewInfo = (Cxcontainer::TcxContainerViewInfo*)(0x0))/* overload */;
	__property TcxCustomCheckBox* Edit = {read=GetEdit};
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  Repaint(Vcl::Controls::TWinControl* AControl, Cxcontainer::TcxContainerViewInfo* AViewInfo = (Cxcontainer::TcxContainerViewInfo*)(0x0)){ return Cxedit::TcxCustomEditViewInfo::Repaint(AControl, AViewInfo); }
	
};


class DELPHICLASS TcxCustomCheckBoxViewData;
class DELPHICLASS TcxCustomCheckBoxProperties;
class PASCALIMPLEMENTATION TcxCustomCheckBoxViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	TcxCustomCheckBoxProperties* __fastcall GetProperties(void);
	int __fastcall GetTextFlags(bool ADraw);
	
protected:
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	int __fastcall GetCalculateTextFlags(void);
	virtual int __fastcall GetDrawTextFlags(void);
	bool __fastcall GetIsEditClass(void);
	bool __fastcall IsCheckPressed(void);
	virtual System::Types::TRect __fastcall CalculateCheckBoxRect(TcxCustomCheckBoxViewInfo* AViewInfo);
	virtual Cxlookandfeelpainters::TcxEditCheckState __fastcall CalculateCheckBoxState(TcxCustomCheckBoxViewInfo* AViewInfo, const System::Types::TPoint P, Cxcontainer::TcxMouseButton AButton, System::Classes::TShiftState AShift);
	virtual System::Types::TRect __fastcall CalculateTextRect(TcxCustomCheckBoxViewInfo* AViewInfo);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual Cxedit::TcxEditBorderStyle __fastcall GetBorderStyle(void);
	__property TcxCustomCheckBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomCheckBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomCheckBoxViewData(void) { }
	
};


class DELPHICLASS TcxCheckBoxStyle;
class PASCALIMPLEMENTATION TcxCheckBoxStyle : public Cxedit::TcxEditStyle
{
	typedef Cxedit::TcxEditStyle inherited;
	
public:
	virtual bool __fastcall HasBorder(void);
public:
	/* TcxCustomEditStyle.Create */ inline __fastcall virtual TcxCheckBoxStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState) : Cxedit::TcxEditStyle(AOwner, ADirectAccessMode, AParentStyle, AState) { }
	
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxCheckBoxStyle(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomCheckBoxProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	typedef System::StaticArray<System::WideString, 3> _TcxCustomCheckBoxProperties__1;
	
	
private:
	bool FAllowGrayed;
	Vcl::Controls::TCaption FCaption;
	_TcxCustomCheckBoxProperties__1 FDisplayCheckState;
	bool FFullFocusRect;
	Vcl::Graphics::TBitmap* FGlyph;
	int FGlyphCount;
	bool FIsCaptionAssigned;
	System::StaticArray<bool, 3> FIsDisplayCheckStateAssigned;
	bool FMultiLine;
	TcxCheckBoxNullValueShowingStyle FNullStyle;
	bool FShowEndEllipsis;
	bool FUseAlignmentWhenInplace;
	System::Variant FValueChecked;
	System::Variant FValueGrayed;
	System::Variant FValueUnchecked;
	System::Classes::TAlignment __fastcall GetAlignment(void);
	System::UnicodeString __fastcall GetDefaultDisplayCheckState(Cxlookandfeelpainters::TcxCheckBoxState AState);
	System::WideString __fastcall GetDisplayCheckState(const int Index);
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	Cxedit::TcxEditAlignment* __fastcall GetInternalAlignment(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	HIDESBASE bool __fastcall IsAlignmentStored(void);
	bool __fastcall IsDisplayCheckStateStored(int Index);
	bool __fastcall IsLoading(void);
	bool __fastcall IsValueCheckedStored(void);
	bool __fastcall IsValueGrayedStored(void);
	bool __fastcall IsValueUncheckedStored(void);
	void __fastcall ReadCaption(System::Classes::TReader* Reader);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetCaption(const Vcl::Controls::TCaption Value);
	void __fastcall SetDisplayCheckState(const int Index, const System::WideString Value);
	void __fastcall SetFullFocusRect(bool Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphCount(int Value);
	void __fastcall SetMultiLine(bool Value);
	void __fastcall SetNullStyle(TcxCheckBoxNullValueShowingStyle Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetStateValues(const System::Variant &AValueChecked, const System::Variant &AValueGrayed, const System::Variant &AValueUnchecked);
	void __fastcall SetUseAlignmentWhenInplace(bool Value);
	void __fastcall SetValueChecked(const System::Variant &Value);
	void __fastcall SetValueGrayed(const System::Variant &Value);
	void __fastcall SetValueUnchecked(const System::Variant &Value);
	
protected:
	virtual bool __fastcall CanValidate(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	bool __fastcall CheckValue(const System::Variant &AValue);
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetState(const System::Variant &AEditValue);
	virtual Vcl::Graphics::TBitmap* __fastcall InternalGetGlyph(void);
	virtual bool __fastcall IsEmbeddedEdit(void);
	__property Cxedit::TcxEditAlignment* InternalAlignment = {read=GetInternalAlignment};
	
public:
	__fastcall virtual TcxCustomCheckBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomCheckBoxProperties(void);
	virtual bool __fastcall CanCompareEditValue(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	__classmethod virtual Cxedit::TcxCustomEditStyleClass __fastcall GetStyleClass();
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsActivationKey(System::WideChar AKey);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual bool __fastcall IsResetEditClass(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	__property System::Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, stored=IsAlignmentStored, nodefault};
	__property bool AllowGrayed = {read=FAllowGrayed, write=FAllowGrayed, default=0};
	__property Vcl::Controls::TCaption Caption = {read=FCaption, write=SetCaption, stored=false};
	__property System::WideString DisplayChecked = {read=GetDisplayCheckState, write=SetDisplayCheckState, stored=IsDisplayCheckStateStored, index=1};
	__property System::WideString DisplayGrayed = {read=GetDisplayCheckState, write=SetDisplayCheckState, stored=IsDisplayCheckStateStored, index=2};
	__property System::WideString DisplayUnchecked = {read=GetDisplayCheckState, write=SetDisplayCheckState, stored=IsDisplayCheckStateStored, index=0};
	__property bool FullFocusRect = {read=FFullFocusRect, write=SetFullFocusRect, default=0};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=FGlyphCount, write=SetGlyphCount, default=6};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiLine, default=0};
	__property TcxCheckBoxNullValueShowingStyle NullStyle = {read=FNullStyle, write=SetNullStyle, default=2};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=0};
	__property bool UseAlignmentWhenInplace = {read=FUseAlignmentWhenInplace, write=SetUseAlignmentWhenInplace, default=0};
	__property System::Variant ValueChecked = {read=FValueChecked, write=SetValueChecked, stored=IsValueCheckedStored};
	__property System::Variant ValueGrayed = {read=FValueGrayed, write=SetValueGrayed, stored=IsValueGrayedStored};
	__property System::Variant ValueUnchecked = {read=FValueUnchecked, write=SetValueUnchecked, stored=IsValueUncheckedStored};
};


class DELPHICLASS TcxCheckBoxProperties;
class PASCALIMPLEMENTATION TcxCheckBoxProperties : public TcxCustomCheckBoxProperties
{
	typedef TcxCustomCheckBoxProperties inherited;
	
__published:
	__property Alignment;
	__property AllowGrayed = {default=0};
	__property AssignedValues;
	__property Caption = {default=0};
	__property ClearKey = {default=0};
	__property DisplayChecked = {index=1, default=0};
	__property DisplayUnchecked = {index=0, default=0};
	__property DisplayGrayed = {index=2, default=0};
	__property FullFocusRect = {default=0};
	__property Glyph;
	__property GlyphCount = {default=6};
	__property ImmediatePost = {default=0};
	__property MultiLine = {default=0};
	__property NullStyle = {default=2};
	__property ReadOnly;
	__property ShowEndEllipsis = {default=0};
	__property UseAlignmentWhenInplace = {default=0};
	__property ValidationOptions = {default=1};
	__property ValueChecked = {default=0};
	__property ValueGrayed = {default=0};
	__property ValueUnchecked = {default=0};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnValidate;
public:
	/* TcxCustomCheckBoxProperties.Create */ inline __fastcall virtual TcxCheckBoxProperties(System::Classes::TPersistent* AOwner) : TcxCustomCheckBoxProperties(AOwner) { }
	/* TcxCustomCheckBoxProperties.Destroy */ inline __fastcall virtual ~TcxCheckBoxProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomCheckBox : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	bool FIsCheckPressed;
	bool FIsLoaded;
	bool FIsLoadingStateAssigned;
	Cxlookandfeelpainters::TcxCheckBoxState FLoadingState;
	bool __fastcall GetChecked(void);
	TcxCustomCheckBoxProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomCheckBoxProperties* __fastcall GetActiveProperties(void);
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetState(void);
	HIDESBASE TcxCheckBoxStyle* __fastcall GetStyle(void);
	HIDESBASE TcxCustomCheckBoxViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsStateStored(void);
	void __fastcall SetChecked(bool Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomCheckBoxProperties* Value);
	void __fastcall SetState(Cxlookandfeelpainters::TcxCheckBoxState Value);
	HIDESBASE void __fastcall SetStyle(TcxCheckBoxStyle* Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	DYNAMIC Vcl::Controls::TControlActionLinkClass __fastcall GetActionLinkClass(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall AcceleratorClick(void);
	virtual bool __fastcall CanHaveTransparentBorder(void);
	virtual bool __fastcall DefaultParentColor(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DoEditKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DoProcessEventsOnViewInfoChanging(void);
	virtual void __fastcall PopulateSizeProperties(Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind(void);
	virtual System::Types::TRect __fastcall GetShadowBounds(void);
	virtual void __fastcall Initialize(void);
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual bool __fastcall IsClickEnabledDuringLoading(void);
	virtual bool __fastcall IsNativeBackground(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	DYNAMIC void __fastcall TextChanged(void);
	void __fastcall InvalidateCheckRect(void);
	virtual void __fastcall Toggle(void);
	__property Caption = {default=0};
	__property bool Checked = {read=GetChecked, write=SetChecked, stored=false, nodefault};
	__property TcxCustomCheckBoxViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall Clear(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomCheckBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomCheckBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Cxlookandfeelpainters::TcxCheckBoxState State = {read=GetState, write=SetState, stored=IsStateStored, default=0};
	__property TcxCheckBoxStyle* Style = {read=GetStyle, write=SetStyle};
	__property Transparent = {default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomCheckBox(System::Classes::TComponent* AOwner)/* overload */ : Cxedit::TcxCustomEdit(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomCheckBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	/* TcxCustomEdit.Destroy */ inline __fastcall virtual ~TcxCustomCheckBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCheckBox(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxCheckBox;
class PASCALIMPLEMENTATION TcxCheckBox : public TcxCustomCheckBox
{
	typedef TcxCustomCheckBox inherited;
	
private:
	HIDESBASE TcxCheckBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCheckBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCheckBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCheckBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Action;
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Caption = {default=0};
	__property Checked;
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentBackground = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxCheckBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property State = {default=0};
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
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCheckBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomCheckBox(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCheckBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomCheckBox(AOwner, AIsInplace) { }
	/* TcxCustomEdit.Destroy */ inline __fastcall virtual ~TcxCheckBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCheckBox(HWND ParentWindow) : TcxCustomCheckBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterCheckBoxHelper;
class PASCALIMPLEMENTATION TcxFilterCheckBoxHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
public:
	__classmethod virtual void __fastcall GetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &V, Vcl::Controls::TCaption &S);
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual void __fastcall SetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, System::Variant &AValue);
	__classmethod virtual bool __fastcall UseDisplayValue();
public:
	/* TObject.Create */ inline __fastcall TcxFilterCheckBoxHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterCheckBoxHelper(void) { }
	
};


class DELPHICLASS TcxCheckBoxActionLink;
class PASCALIMPLEMENTATION TcxCheckBoxActionLink : public Vcl::Controls::TWinControlActionLink
{
	typedef Vcl::Controls::TWinControlActionLink inherited;
	
protected:
	TcxCustomCheckBox* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual void __fastcall SetChecked(bool Value);
	void __fastcall InternalSetChecked(bool Value);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TcxCheckBoxActionLink(System::TObject* AClient) : Vcl::Controls::TWinControlActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TcxCheckBoxActionLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const int cxEditCheckBoxSingleBorderDefaultColor = int(-16777200);
extern PACKAGE System::Variant __fastcall CalculateCheckStatesValue(const TcxCheckStates ACheckStates, _di_IcxCheckItems AItems, TcxCheckStatesValueFormat AValueFormat);
extern PACKAGE bool __fastcall CalculateCheckStates(const System::Variant &AValue, _di_IcxCheckItems AItems, TcxCheckStatesValueFormat AValueFormat, TcxCheckStates &ACheckStates);
extern PACKAGE void __fastcall DrawCheckBoxText(Cxgraphics::TcxCanvas* ACanvas, System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Types::TRect &ATextRect, int ADrawTextFlags, bool AEnabled);
extern PACKAGE void __fastcall DrawEditCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACheckRect, Cxlookandfeelpainters::TcxEditCheckState ACheckState, TcxCustomCheckBoxViewInfo* AViewInfo)/* overload */;
extern PACKAGE void __fastcall DrawEditCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACheckRect, Cxlookandfeelpainters::TcxCheckBoxState AState, Cxlookandfeelpainters::TcxEditCheckState ACheckState, Vcl::Graphics::TBitmap* AGlyph, int AGlyphCount, Cxedit::TcxEditBorderStyle ABorderStyle, bool ANativeStyle, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor ABackgroundColor, bool ADrawBackground, bool AIsDesigning, bool AFocused, bool ASupportGrayed, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, TcxCheckBoxNullValueShowingStyle AGrayedShowingStyle = (TcxCheckBoxNullValueShowingStyle)(0x2))/* overload */;
extern PACKAGE int __fastcall GetEditCheckBorderOffset(Cxlookandfeelpainters::TcxContainerBorderStyle ACheckBorderStyle, bool ANativeStyle, bool AHasGlyph, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter)/* overload */;
extern PACKAGE int __fastcall GetEditCheckBorderOffset(Cxedit::TcxEditBorderStyle ACheckBorderStyle, bool ANativeStyle, bool AHasGlyph, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter)/* overload */;
extern PACKAGE int __fastcall GetEditCheckBorderOffset(Cxlookandfeels::TcxLookAndFeelKind ALookAndFeelKind, bool ANativeStyle, bool AHasGlyph, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter)/* overload */;
extern PACKAGE int __fastcall GetEditCheckGlyphIndex(Cxlookandfeelpainters::TcxCheckBoxState AState, Cxlookandfeelpainters::TcxEditCheckState ACheckState, bool ASupportGrayed, int AGlyphCount);
extern PACKAGE System::Types::TSize __fastcall GetEditCheckSize(Cxgraphics::TcxCanvas* ACanvas, bool ANativeStyle, Vcl::Graphics::TBitmap* AGlyph, int AGlyphCount, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter);
}	/* namespace Cxcheckbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCHECKBOX)
using namespace Cxcheckbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcheckboxHPP
