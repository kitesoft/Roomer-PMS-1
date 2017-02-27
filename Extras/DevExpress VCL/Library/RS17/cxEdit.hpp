// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEdit.pas' rev: 24.00 (Win32)

#ifndef CxeditHPP
#define CxeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <cxEditPaintUtils.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Actions.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxedit
{
//-- type declarations -------------------------------------------------------
enum TcxBlobKind : unsigned char { bkNone, bkBlob, bkGraphic, bkMemo, bkOle };

enum TcxEditBorderStyle : unsigned char { ebsNone, ebsSingle, ebsThick, ebsFlat, ebs3D, ebsUltraFlat, ebsOffice11 };

enum TcxEditButtonKind : unsigned char { bkEllipsis, bkDown, bkGlyph, bkText };

enum TcxEditButtonState : unsigned char { ebsDisabled, ebsNormal, ebsPressed, ebsSelected };

enum TcxEditButtonStyle : unsigned char { btsDefault, bts3D, btsFlat, btsSimple, btsHotFlat, btsUltraFlat, btsOffice11 };

enum TcxEditButtonsViewStyle : unsigned char { bvsNormal, bvsButtonsOnly, bvsButtonsAutoWidth };

enum TcxEditButtonTransparency : unsigned char { ebtNone, ebtInactive, ebtAlways, ebtHideInactive, ebtHideUnselected };

typedef Cxclasses::TcxDirection TcxEditGradientDirection;

typedef Cxcontainer::TcxContainerStyleValue TcxEditStyleValue;

typedef Cxcontainer::TcxContainerStyleValues TcxEditStyleValues;

typedef System::Classes::TAlignment TcxEditHorzAlignment;

enum TcxEditVertAlignment : unsigned char { taTopJustify, taBottomJustify, taVCenter };

enum TcxInplaceEditAutoHeight : unsigned char { eahNone, eahEditor, eahRow };

enum TcxItemInplaceEditAutoHeight : unsigned char { ieahDefault, ieahNone };

typedef System::StaticArray<System::UnicodeString, 6> Cxedit__1;

enum TcxEditDisplayFormatOption : unsigned char { dfoSupports, dfoNoCurrencyValue };

typedef System::Set<TcxEditDisplayFormatOption, TcxEditDisplayFormatOption::dfoSupports, TcxEditDisplayFormatOption::dfoNoCurrencyValue>  TcxEditDisplayFormatOptions;

enum TcxEditBackgroundPaintingStyle : unsigned char { bpsSolid, bpsComboEdit, bpsComboListEdit };

enum TcxEditEditingStyle : unsigned char { esEdit, esEditList, esFixedList, esNoEdit };

enum TcxEditPaintOption : unsigned char { epoAllowZeroHeight, epoAutoHeight, epoHasExternalBorder, epoShowEndEllipsis, epoShowFocusRectWhenInplace };

typedef System::Set<TcxEditPaintOption, TcxEditPaintOption::epoAllowZeroHeight, TcxEditPaintOption::epoShowFocusRectWhenInplace>  TcxEditPaintOptions;

enum Cxedit__2 : unsigned char { esfBlobEditValue, esfMinSize, esfNoContentPart, esfClickable, esfMultiRow };

typedef System::Set<Cxedit__2, Cxedit__2::esfBlobEditValue, Cxedit__2::esfMultiRow>  TcxEditSpecialFeatures;

enum TcxEditSupportedOperation : unsigned char { esoAlwaysHotTrack, esoAutoHeight, esoEditing, esoFiltering, esoHorzAlignment, esoHotTrack, esoIncSearch, esoShowingCaption, esoSorting, esoSortingByDisplayText, esoTransparency, esoEditingAutoHeight };

typedef System::Set<TcxEditSupportedOperation, TcxEditSupportedOperation::esoAlwaysHotTrack, TcxEditSupportedOperation::esoEditingAutoHeight>  TcxEditSupportedOperations;

typedef System::Variant TcxEditValue;

typedef System::Variant *PcxEditValue;

typedef void __fastcall (__closure *TcxEditValidateEvent)(System::TObject* Sender, System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error);

typedef int TcxEditErrorKind;

enum Cxedit__3 : unsigned char { evoRaiseException, evoShowErrorIcon, evoAllowLoseFocus };

typedef System::Set<Cxedit__3, Cxedit__3::evoRaiseException, Cxedit__3::evoAllowLoseFocus>  TcxEditValidationOptions;

class DELPHICLASS EcxEditError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxEditError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxEditError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxEditError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxEditError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxEditError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxEditError(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EcxEditValidationError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxEditValidationError : public EcxEditError
{
	typedef EcxEditError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg) : EcxEditError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EcxEditError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditValidationError(NativeUInt Ident)/* overload */ : EcxEditError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec)/* overload */ : EcxEditError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditValidationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EcxEditError(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : EcxEditError(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg, int AHelpContext) : EcxEditError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxEditValidationError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EcxEditError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditValidationError(NativeUInt Ident, int AHelpContext)/* overload */ : EcxEditError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EcxEditError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditValidationError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EcxEditError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxEditValidationError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EcxEditError(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxEditValidationError(void) { }
	
};

#pragma pack(pop)

__interface IcxEditorFieldLink;
typedef System::DelphiInterface<IcxEditorFieldLink> _di_IcxEditorFieldLink;
__interface  INTERFACE_UUID("{E21A0DDE-85DF-42CC-9063-D9E5DF45F02F}") IcxEditorFieldLink  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CreateFieldControls(int X, int Y, System::TObject* ADataSource, System::Classes::TList* AFieldList) = 0 ;
};

__interface IcxCustomInnerEdit;
typedef System::DelphiInterface<IcxCustomInnerEdit> _di_IcxCustomInnerEdit;
__interface  INTERFACE_UUID("{468D21B5-48AA-4077-8ED5-4C6112D460B1}") IcxCustomInnerEdit  : public Cxcontainer::IcxContainerInnerControl 
{
	
public:
	virtual NativeInt __fastcall CallDefWndProc(unsigned AMsg, NativeUInt WParam, NativeInt LParam) = 0 ;
	virtual bool __fastcall CanProcessClipboardMessages(void) = 0 ;
	virtual System::Variant __fastcall GetEditValue(void) = 0 ;
	virtual System::Classes::TNotifyEvent __fastcall GetOnChange(void) = 0 ;
	virtual bool __fastcall GetReadOnly(void) = 0 ;
	virtual void __fastcall LockBounds(bool ALock) = 0 ;
	virtual void __fastcall SafelySetFocus(void) = 0 ;
	virtual void __fastcall SetEditValue(const System::Variant &Value) = 0 ;
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* Value) = 0 ;
	virtual void __fastcall SetOnChange(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetReadOnly(bool Value) = 0 ;
	__property System::Variant EditValue = {read=GetEditValue, write=SetEditValue};
	__property Vcl::Controls::TWinControl* Parent = {write=SetParent};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly};
	__property System::Classes::TNotifyEvent OnChange = {read=GetOnChange, write=SetOnChange};
};

__interface IcxInnerEditHelper;
typedef System::DelphiInterface<IcxInnerEditHelper> _di_IcxInnerEditHelper;
__interface  INTERFACE_UUID("{35667555-6DC8-40D5-B705-B08D5697C621}") IcxInnerEditHelper  : public System::IInterface 
{
	
public:
	virtual _di_IcxCustomInnerEdit __fastcall GetHelper(void) = 0 ;
};

__interface IcxEditOwner;
typedef System::DelphiInterface<IcxEditOwner> _di_IcxEditOwner;
class DELPHICLASS TcxCustomEditViewData;
__interface  INTERFACE_UUID("{4129100C-7FC6-436E-8711-47A5C978CA73}") IcxEditOwner  : public System::IInterface 
{
	
public:
	virtual TcxCustomEditViewData* __fastcall GetViewData(/* out */ bool &AIsViewDataCreated) = 0 ;
	virtual void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground = true) = 0 ;
};

typedef System::TMetaClass* TcxCustomEditPropertiesClass;

__interface IcxEditRepositoryItemListener;
typedef System::DelphiInterface<IcxEditRepositoryItemListener> _di_IcxEditRepositoryItemListener;
class DELPHICLASS TcxEditRepositoryItem;
__interface  INTERFACE_UUID("{4E27D642-022B-4CD2-AB96-64C7CF9B3299}") IcxEditRepositoryItemListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall ItemRemoved(TcxEditRepositoryItem* Sender) = 0 ;
	virtual void __fastcall PropertiesChanged(TcxEditRepositoryItem* Sender) = 0 ;
};

class DELPHICLASS TcxCustomEditProperties;
class DELPHICLASS TcxEditRepository;
class PASCALIMPLEMENTATION TcxEditRepositoryItem : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::_di_IInterfaceList FListenerList;
	TcxCustomEditProperties* FProperties;
	System::Classes::TNotifyEvent FPropertiesEvents;
	TcxEditRepository* FRepository;
	void __fastcall SetProperties(TcxCustomEditProperties* Value);
	void __fastcall SetRepository(TcxEditRepository* Value);
	
protected:
	bool __fastcall ArePropertiesCompatible(System::TClass APropertiesClass);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	
public:
	__fastcall virtual TcxEditRepositoryItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxEditRepositoryItem(void);
	virtual void __fastcall AddListener(_di_IcxEditRepositoryItemListener AListener);
	__classmethod virtual TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass();
	virtual System::UnicodeString __fastcall GetBaseName(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual void __fastcall RemoveListener(_di_IcxEditRepositoryItemListener AListener);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	__property TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property TcxEditRepository* Repository = {read=FRepository, write=SetRepository};
	
__published:
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
};


typedef System::TMetaClass* TcxEditRepositoryItemClass;

__interface IcxEditDefaultValuesProvider;
typedef System::DelphiInterface<IcxEditDefaultValuesProvider> _di_IcxEditDefaultValuesProvider;
__interface  INTERFACE_UUID("{AE727882-6FDF-4E3A-AB35-E58AB28EFE7B}") IcxEditDefaultValuesProvider  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanSetEditMode(void) = 0 ;
	virtual void __fastcall ClearUsers(void) = 0 ;
	virtual System::Classes::TAlignment __fastcall DefaultAlignment(void) = 0 ;
	virtual TcxBlobKind __fastcall DefaultBlobKind(void) = 0 ;
	virtual bool __fastcall DefaultCanModify(void) = 0 ;
	virtual System::UnicodeString __fastcall DefaultDisplayFormat(void) = 0 ;
	virtual System::UnicodeString __fastcall DefaultEditFormat(void) = 0 ;
	virtual System::UnicodeString __fastcall DefaultEditMask(void) = 0 ;
	virtual bool __fastcall DefaultIsFloatValue(void) = 0 ;
	virtual int __fastcall DefaultMaxLength(void) = 0 ;
	virtual double __fastcall DefaultMaxValue(void) = 0 ;
	virtual double __fastcall DefaultMinValue(void) = 0 ;
	virtual int __fastcall DefaultPrecision(void) = 0 ;
	virtual bool __fastcall DefaultReadOnly(void) = 0 ;
	virtual bool __fastcall DefaultRequired(void) = 0 ;
	virtual System::TObject* __fastcall GetInstance(void) = 0 ;
	virtual bool __fastcall IsDataStorage(void) = 0 ;
	virtual bool __fastcall IsBlob(void) = 0 ;
	virtual bool __fastcall IsCurrency(void) = 0 ;
	virtual bool __fastcall IsDataAvailable(void) = 0 ;
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted) = 0 ;
	virtual bool __fastcall IsOnGetTextAssigned(void) = 0 ;
	virtual bool __fastcall IsOnSetTextAssigned(void) = 0 ;
	virtual bool __fastcall IsValidChar(System::WideChar AChar) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditRepository : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TcxEditRepositoryItem* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxEditRepositoryItem* __fastcall GetItem(int Index);
	
protected:
	void __fastcall AddItem(TcxEditRepositoryItem* AItem);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall RemoveItem(TcxEditRepositoryItem* AItem);
	
public:
	__fastcall virtual TcxEditRepository(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxEditRepository(void);
	void __fastcall Clear(void);
	virtual TcxEditRepositoryItem* __fastcall CreateItem(TcxEditRepositoryItemClass ARepositoryItemClass);
	virtual TcxEditRepositoryItem* __fastcall CreateItemEx(TcxEditRepositoryItemClass ARepositoryItemClass, System::Classes::TComponent* AOwner);
	TcxEditRepositoryItem* __fastcall ItemByName(const System::UnicodeString ARepositoryItemName);
	__property int Count = {read=GetCount, nodefault};
	__property TcxEditRepositoryItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

struct TcxEditButtonViewInfoData;
typedef TcxEditButtonViewInfoData *PcxEditButtonViewInfoData;

struct DECLSPEC_DRECORD TcxEditButtonViewInfoData
{
public:
	Vcl::Actnlist::TActionLink* ActionLink;
	System::Uitypes::TColor BackgroundColor;
	System::UnicodeString Caption;
	System::Classes::TAlignment ContentAlignment;
	bool Default;
	bool Gradient;
	System::UnicodeString Hint;
	bool IsInplace;
	TcxEditButtonKind Kind;
	bool LeftAlignment;
	bool Leftmost;
	bool NativeStyle;
	bool Rightmost;
	TcxEditButtonState State;
	TcxEditButtonStyle Style;
	System::Uitypes::TColor TextColor;
	bool Transparent;
	System::UnicodeString VisibleCaption;
	bool BackgroundPartiallyTransparent;
	bool ComboBoxStyle;
	int NativePart;
	int NativeState;
	bool UseSkins;
};


class DELPHICLASS TcxCustomEditFadingHelper;
class DELPHICLASS TcxCustomEditViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditFadingHelper : public Dxfading::TdxFadingObjectHelper
{
	typedef Dxfading::TdxFadingObjectHelper inherited;
	
private:
	_di_IcxEditOwner __fastcall GetEditOwner(void);
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual TcxCustomEditViewInfo* __fastcall GetEditViewInfo(void) = 0 ;
	virtual void __fastcall DrawFadeImage(void);
	
public:
	virtual void __fastcall Invalidate(void) = 0 /* overload */;
	void __fastcall Invalidate(const System::Types::TRect &R, bool AEraseBackground)/* overload */;
	__property _di_IcxEditOwner EditOwner = {read=GetEditOwner};
	__property TcxCustomEditViewInfo* EditViewInfo = {read=GetEditViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxCustomEditFadingHelper(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCustomEditFadingHelper(void) : Dxfading::TdxFadingObjectHelper() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditButtonFadingHelper;
class DELPHICLASS TcxEditButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButtonFadingHelper : public TcxCustomEditFadingHelper
{
	typedef TcxCustomEditFadingHelper inherited;
	
private:
	TcxEditButtonState FState;
	TcxEditButtonViewInfo* FViewInfo;
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetButtonRect(void);
	virtual TcxCustomEditViewInfo* __fastcall GetEditViewInfo(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	virtual Cxgraphics::TcxBitmap32* __fastcall PrepareFadingImage(TcxEditButtonState AState);
	
public:
	__fastcall virtual TcxEditButtonFadingHelper(TcxEditButtonViewInfo* AViewInfo);
	virtual void __fastcall Invalidate(void)/* overload */;
	virtual void __fastcall UpdateState(void);
	__property System::Types::TRect ButtonRect = {read=GetButtonRect};
	__property TcxEditButtonState State = {read=FState, nodefault};
	__property TcxEditButtonViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxEditButtonFadingHelper(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Invalidate(const System::Types::TRect &R, bool AEraseBackground){ TcxCustomEditFadingHelper::Invalidate(R, AEraseBackground); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxEditButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButtonViewInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	virtual TcxEditButtonFadingHelper* __fastcall CreateFadingHelper(void);
	
public:
	System::Types::TRect Bounds;
	int ButtonIndex;
	int ButtonVisibleIndex;
	TcxEditButtonViewInfoData Data;
	TcxCustomEditViewInfo* EditViewInfo;
	TcxEditButtonFadingHelper* FadingHelper;
	Vcl::Graphics::TBitmap* Glyph;
	bool HasBackground;
	System::Uitypes::TImageIndex ImageIndex;
	Vcl::Imglist::TCustomImageList* Images;
	bool Stretchable;
	System::Types::TRect VisibleBounds;
	int Width;
	__fastcall virtual ~TcxEditButtonViewInfo(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(TcxEditButtonViewInfo* AViewInfo);
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, TcxEditButtonViewInfo* AViewInfo, const System::Types::TPoint &AEditPosition);
public:
	/* TObject.Create */ inline __fastcall TcxEditButtonViewInfo(void) : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditButtonActionLink;
class DELPHICLASS TcxCustomEditButton;
class PASCALIMPLEMENTATION TcxEditButtonActionLink : public Vcl::Actnlist::TActionLink
{
	typedef Vcl::Actnlist::TActionLink inherited;
	
protected:
	TcxCustomEditButton* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetHint(const System::UnicodeString Value);
	virtual void __fastcall SetVisible(bool Value);
	
public:
	virtual bool __fastcall PrepareHint(System::UnicodeString &HintStr);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TcxEditButtonActionLink(System::TObject* AClient) : Vcl::Actnlist::TActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TcxEditButtonActionLink(void) { }
	
};


typedef System::TMetaClass* TcxEditButtonActionLinkClass;

class DELPHICLASS TcxCustomEditButtons;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxEditButtonActionLink* FActionLink;
	Vcl::Controls::TCaption FCaption;
	System::Classes::TAlignment FContentAlignment;
	bool FDefault;
	bool FEnabled;
	Vcl::Graphics::TBitmap* FGlyph;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	TcxEditButtonKind FKind;
	bool FLeftAlignment;
	bool FStretchable;
	int FTag;
	System::Uitypes::TColor FTextColor;
	bool FVisible;
	Vcl::Controls::TCaption FVisibleCaption;
	int FWidth;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	void __fastcall DoActionChange(System::TObject* Sender);
	TcxCustomEditButtons* __fastcall GetCollection(void);
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsTagStored(void);
	bool __fastcall IsVisibleStored(void);
	void __fastcall SetAction(System::Classes::TBasicAction* Value);
	void __fastcall SetCaption(const Vcl::Controls::TCaption Value);
	void __fastcall SetContentAlignment(System::Classes::TAlignment Value);
	void __fastcall SetDefault(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetKind(TcxEditButtonKind Value);
	void __fastcall SetLeftAlignment(bool Value);
	void __fastcall SetStretchable(bool Value);
	void __fastcall SetTextColor(System::Uitypes::TColor Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	virtual System::Classes::TBasicAction* __fastcall GetAction(void);
	virtual TcxEditButtonActionLinkClass __fastcall GetActionLinkClass(void);
	virtual void __fastcall InitiateAction(void);
	__property System::Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property TcxEditButtonActionLink* ActionLink = {read=FActionLink};
	__property Vcl::Controls::TCaption Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property TcxCustomEditButtons* Collection = {read=GetCollection};
	__property System::Classes::TAlignment ContentAlignment = {read=FContentAlignment, write=SetContentAlignment, default=2};
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property System::UnicodeString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property TcxEditButtonKind Kind = {read=FKind, write=SetKind, default=1};
	__property bool LeftAlignment = {read=FLeftAlignment, write=SetLeftAlignment, default=0};
	__property bool Stretchable = {read=FStretchable, write=SetStretchable, default=1};
	__property int Tag = {read=FTag, write=FTag, stored=IsTagStored, nodefault};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=SetTextColor, default=-16777198};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property Vcl::Controls::TCaption VisibleCaption = {read=FVisibleCaption};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
	
public:
	__fastcall virtual TcxCustomEditButton(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxCustomEditButton(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxEditButtonClass;

class DELPHICLASS TcxEditButton;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditButton : public TcxCustomEditButton
{
	typedef TcxCustomEditButton inherited;
	
__published:
	__property Action;
	__property Caption = {default=0};
	__property ContentAlignment = {default=2};
	__property Default = {default=0};
	__property Enabled = {default=1};
	__property ImageIndex = {default=-1};
	__property Glyph;
	__property Hint = {default=0};
	__property Kind = {default=1};
	__property LeftAlignment = {default=0};
	__property Stretchable = {default=1};
	__property Tag;
	__property Visible = {default=1};
	__property Width = {default=0};
public:
	/* TcxCustomEditButton.Create */ inline __fastcall virtual TcxEditButton(System::Classes::TCollection* Collection) : TcxCustomEditButton(Collection) { }
	/* TcxCustomEditButton.Destroy */ inline __fastcall virtual ~TcxEditButton(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomEditButtons : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxCustomEditButton* operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	System::Classes::TPersistent* FOwner;
	System::Classes::TNotifyEvent FOnChange;
	HIDESBASE TcxCustomEditButton* __fastcall GetItem(int Index);
	int __fastcall GetVisibleCount(void);
	HIDESBASE void __fastcall SetItem(int Index, TcxCustomEditButton* Value);
	
protected:
	void __fastcall AddFreeNotificatorSender(System::Classes::TComponent* Sender);
	virtual void __fastcall DoFreeNotification(System::Classes::TComponent* Sender);
	__classmethod virtual TcxEditButtonClass __fastcall GetButtonClass();
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall InitiateActions(void);
	void __fastcall RemoveFreeNotificatorSender(System::Classes::TComponent* Sender);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=FFreeNotificator};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TcxCustomEditButtons(System::Classes::TPersistent* AOwner, TcxEditButtonClass AButtonClass);
	__fastcall virtual ~TcxCustomEditButtons(void);
	__property TcxCustomEditButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
};


class DELPHICLASS TcxEditButtons;
class PASCALIMPLEMENTATION TcxEditButtons : public TcxCustomEditButtons
{
	typedef TcxCustomEditButtons inherited;
	
public:
	TcxEditButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxEditButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxEditButton* Value);
	
protected:
	__classmethod virtual TcxEditButtonClass __fastcall GetButtonClass();
	
public:
	HIDESBASE TcxEditButton* __fastcall Add(void);
	__property TcxEditButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxCustomEditButtons.Create */ inline __fastcall virtual TcxEditButtons(System::Classes::TPersistent* AOwner, TcxEditButtonClass AButtonClass) : TcxCustomEditButtons(AOwner, AButtonClass) { }
	/* TcxCustomEditButtons.Destroy */ inline __fastcall virtual ~TcxEditButtons(void) { }
	
};


typedef System::TMetaClass* TcxEditButtonsClass;

typedef void __fastcall (__closure *TcxEditCanStartButtonFadingEvent)(TcxCustomEditViewInfo* Sender, bool &ACanStart);

typedef void __fastcall (__closure *TcxEditDrawBackgroundEvent)(TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, bool &AHandled);

typedef void __fastcall (__closure *TcxEditDrawButtonEvent)(TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, bool &AHandled);

typedef void __fastcall (__closure *TcxEditDrawButtonBackgroundEvent)(TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool &AHandled);

typedef void __fastcall (__closure *TcxEditDrawButtonBorderEvent)(TcxEditButtonViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas, /* out */ System::Types::TRect &ABackgroundRect, /* out */ System::Types::TRect &AContentRect, bool &AHandled);

typedef void __fastcall (__closure *TcxEditGetButtonStateEvent)(TcxEditButtonViewInfo* Sender, TcxEditButtonState &AState);

typedef void __fastcall (__closure *TcxEditPaintEvent)(TcxCustomEditViewInfo* Sender, Cxgraphics::TcxCanvas* ACanvas);

typedef void __fastcall (__closure *TcxEditPrepareButtonFadingImageEvent)(TcxEditButtonViewInfo* ASender, TcxEditButtonState AState, /* out */ Cxgraphics::TcxBitmap32* &AImage, bool &AHandled);

enum TcxDrawBackgroundStyle : unsigned char { dbsCustom, dbsCustomEdit, dbsNone, dbsSimpleFill, dbsSimpleParent, dbsThemeParent };

enum TcxEditViewInfoState : unsigned char { evsPaintButtons };

typedef System::Set<TcxEditViewInfoState, TcxEditViewInfoState::evsPaintButtons, TcxEditViewInfoState::evsPaintButtons>  TcxEditViewInfoStates;

enum TcxEditErrorType : unsigned char { eetNone, eetError, eetWarning, eetInfo, eetCustom };

class DELPHICLASS TcxEditValidateInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditValidateInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxgdiplusclasses::TdxSmartImage* FErrorIcon;
	System::UnicodeString FErrorText;
	TcxEditErrorType FErrorType;
	Vcl::Graphics::TGraphic* __fastcall GetErrorIcon(void);
	void __fastcall SetErrorType(TcxEditErrorType AValue);
	void __fastcall SetErrorIcon(Vcl::Graphics::TGraphic* AValue);
	
protected:
	bool __fastcall IsError(void);
	void __fastcall Reset(void);
	
public:
	__fastcall TcxEditValidateInfo(void);
	__fastcall virtual ~TcxEditValidateInfo(void);
	__property Vcl::Graphics::TGraphic* ErrorIcon = {read=GetErrorIcon, write=SetErrorIcon};
	__property System::UnicodeString ErrorText = {read=FErrorText, write=FErrorText};
	__property TcxEditErrorType ErrorType = {read=FErrorType, write=SetErrorType, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomEdit;
class PASCALIMPLEMENTATION TcxCustomEditViewInfo : public Cxcontainer::TcxContainerViewInfo
{
	typedef Cxcontainer::TcxContainerViewInfo inherited;
	
private:
	typedef System::DynamicArray<TcxEditButtonViewInfo*> _TcxCustomEditViewInfo__1;
	
	
private:
	TcxEditCanStartButtonFadingEvent FOnCanStartButtonFading;
	TcxEditDrawBackgroundEvent FOnDrawBackground;
	TcxEditDrawButtonEvent FOnDrawButton;
	TcxEditDrawButtonBackgroundEvent FOnDrawButtonBackground;
	TcxEditDrawButtonBorderEvent FOnDrawButtonBorder;
	TcxEditGetButtonStateEvent FOnGetButtonState;
	TcxEditPaintEvent FOnPaint;
	TcxEditPrepareButtonFadingImageEvent FOnPrepareButtonFadingImage;
	bool __fastcall DoCanStartButtonFading(void);
	bool __fastcall DoDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall DoDrawButton(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo);
	bool __fastcall DoDrawButtonBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditButtonViewInfo* AViewInfo);
	bool __fastcall DoDrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, /* out */ System::Types::TRect &ABackgroundRect, /* out */ System::Types::TRect &AContentRect);
	bool __fastcall DoPrepareButtonFadingImage(TcxEditButtonViewInfo* ASender, TcxEditButtonState AState, /* out */ Cxgraphics::TcxBitmap32* &AImage);
	TcxDrawBackgroundStyle __fastcall GetDrawBackgroundStyle(void);
	bool __fastcall IsNativeBackground(void);
	bool __fastcall IsTransparent(void);
	System::Types::TRect __fastcall GetHintTextRect(const System::Types::TPoint &P, int APart);
	
protected:
	TcxCustomEdit* FEdit;
	TcxEditViewInfoStates FState;
	System::Types::TRect FErrorBounds;
	System::Types::TRect FEditorBounds;
	TcxEditValidateInfo* FErrorData;
	bool FNeedShowErrorIcon;
	virtual TcxEditBackgroundPaintingStyle __fastcall GetBackgroundPaintingStyle(void);
	virtual TcxEditButtonViewInfoClass __fastcall GetButtonViewInfoClass(void);
	virtual void __fastcall GetColorSettingsByPainter(/* out */ System::Uitypes::TColor &ABackground, /* out */ System::Uitypes::TColor &ATextColor);
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall GetContainerBorderStyle(void);
	bool __fastcall GetHasButtonsStateChanges(void);
	System::UnicodeString __fastcall GetHintText(int APart);
	virtual int __fastcall GetPart(const System::Types::TPoint &P);
	virtual System::Types::TRect __fastcall GetPartRect(int APart);
	bool __fastcall HasNonClientArea(void);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall InternalPrepareEditButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, /* out */ System::Types::TRect &AContentRect, /* out */ System::Types::TRect &ABackgroundRect, /* out */ System::Uitypes::TColor &APenColor, /* out */ System::Uitypes::TColor &ABrushColor, bool ACalculateOnly);
	virtual bool __fastcall IsRepaintOnStateChangingNeeded(void);
	virtual void __fastcall DrawEditButton(Cxgraphics::TcxCanvas* ACanvas, int AButtonVisibleIndex);
	virtual void __fastcall SetOnDrawBackground(TcxEditDrawBackgroundEvent AValue);
	virtual void __fastcall StoreLastState(void);
	virtual void __fastcall Draw3DButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawHotFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawNativeButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawSimpleButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawUltraFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, bool AIsOffice11Style, System::Types::TRect &ARect, System::Types::TRect &AContentRect, /* out */ System::Uitypes::TColor &APenColor, /* out */ System::Uitypes::TColor &ABrushColor);
	void __fastcall CalculateNativeInfo(/* out */ Dxthememanager::TdxThemedObjectType &AThemedObjectType, /* out */ int &ANativePart, /* out */ System::Types::TRect &ABoundsRect);
	void __fastcall DrawButtonBorderByPainter(TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawNativeButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	virtual void __fastcall DrawUsualButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect, System::Uitypes::TColor ABrushColor);
	
public:
	System::Types::TRect BorderExtent;
	TcxEditBorderStyle BorderStyle;
	_TcxCustomEditViewInfo__1 ButtonsInfo;
	bool Calculated;
	int Data;
	TcxCustomEditProperties* EditProperties;
	bool Enabled;
	bool Focused;
	Vcl::Graphics::TFont* Font;
	bool HasBackground;
	bool HasContentOffsets;
	bool HasInnerEdit;
	bool HasTextButtons;
	int HitTestInfo;
	Cxcontainer::TcxContainerHotState HotState;
	System::Types::TRect InnerEditRect;
	bool IsButtonReallyPressed;
	bool IsContainerInnerControl;
	bool IsDBEditPaintCopyDrawing;
	bool IsDesigning;
	bool IsInplace;
	bool IsSelected;
	int LastPressedButton;
	int LastSelectedButton;
	int Left;
	TcxEditPaintOptions PaintOptions;
	Cxlookandfeelpainters::TcxEditPopupBorderStyle PopupBorderStyle;
	int PressedButton;
	int SelectedButton;
	System::Types::TRect ShadowRect;
	System::Uitypes::TColor TextColor;
	int Top;
	bool Transparent;
	HWND WindowHandle;
	__fastcall virtual TcxCustomEditViewInfo(void);
	__fastcall virtual ~TcxCustomEditViewInfo(void);
	virtual void __fastcall Assign(System::TObject* Source);
	virtual bool __fastcall FadingAvailable(void);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(Cxcontainer::TcxContainerViewInfo* AViewInfo);
	virtual void __fastcall Offset(int DX, int DY);
	bool __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	bool __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &APos)/* overload */;
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, int AButtonVisibleIndex);
	void __fastcall DrawButtons(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawEditBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGlyphRect, bool AGlyphTransparent);
	virtual void __fastcall DrawNativeStyleEditBackground(Cxgraphics::TcxCanvas* ACanvas, bool ADrawBackground, HBRUSH ABackgroundBrush);
	virtual bool __fastcall IsBackgroundPartiallyTransparent(void);
	bool __fastcall IsBackgroundTransparent(void);
	void __fastcall DrawButtonBackground(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, const System::Types::TRect &ARect, const System::Types::TRect &AContentRect, System::Uitypes::TColor ABrushColor);
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawButtonContent(Cxgraphics::TcxCanvas* ACanvas, TcxEditButtonViewInfo* AViewInfo, const System::Types::TRect &AContentRect, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, bool ANeedOffsetContent);
	bool __fastcall IsCustomBackground(void);
	bool __fastcall IsCustomButton(int AButtonVisibleIndex = 0x0);
	bool __fastcall IsCustomButtonBackground(int AButtonVisibleIndex = 0x0);
	bool __fastcall IsCustomButtonBorder(int AButtonVisibleIndex = 0x0);
	bool __fastcall IsCustomDrawButton(int AButtonVisibleIndex = 0x0);
	virtual bool __fastcall IsHotTrack(void)/* overload */;
	virtual bool __fastcall IsHotTrack(const System::Types::TPoint &P)/* overload */;
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PaintEx(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PrepareCanvasFont(Vcl::Graphics::TCanvas* ACanvas);
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, Cxcontainer::TcxContainerViewInfo* AViewInfo = (Cxcontainer::TcxContainerViewInfo*)(0x0))/* overload */;
	virtual bool __fastcall Repaint(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &AInnerEditRect, Cxcontainer::TcxContainerViewInfo* AViewInfo = (Cxcontainer::TcxContainerViewInfo*)(0x0))/* overload */;
	void __fastcall ResetValidationInfo(void);
	void __fastcall SetButtonCount(int ACount);
	System::Types::TPoint __fastcall SetOrigin(const System::Types::TPoint &APoint);
	__property TcxEditBackgroundPaintingStyle BackgroundPaintingStyle = {read=GetBackgroundPaintingStyle, nodefault};
	__property TcxCustomEdit* Edit = {read=FEdit};
	__property TcxEditValidateInfo* ErrorData = {read=FErrorData};
	__property TcxEditCanStartButtonFadingEvent OnCanStartButtonFading = {read=FOnCanStartButtonFading, write=FOnCanStartButtonFading};
	__property TcxEditDrawBackgroundEvent OnDrawBackground = {read=FOnDrawBackground, write=SetOnDrawBackground};
	__property TcxEditDrawButtonEvent OnDrawButton = {read=FOnDrawButton, write=FOnDrawButton};
	__property TcxEditDrawButtonBackgroundEvent OnDrawButtonBackground = {read=FOnDrawButtonBackground, write=FOnDrawButtonBackground};
	__property TcxEditDrawButtonBorderEvent OnDrawButtonBorder = {read=FOnDrawButtonBorder, write=FOnDrawButtonBorder};
	__property TcxEditGetButtonStateEvent OnGetButtonState = {read=FOnGetButtonState, write=FOnGetButtonState};
	__property TcxEditPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property TcxEditPrepareButtonFadingImageEvent OnPrepareButtonFadingImage = {read=FOnPrepareButtonFadingImage, write=FOnPrepareButtonFadingImage};
};


struct DECLSPEC_DRECORD TcxInplaceEditPosition
{
public:
	System::TObject* Item;
	NativeInt RecordIndex;
};


struct DECLSPEC_DRECORD TcxInplaceEditParams
{
public:
	bool MultiRowParent;
	TcxInplaceEditPosition Position;
};


struct DECLSPEC_DRECORD TcxEditSizeProperties
{
public:
	int Height;
	int MaxLineCount;
	int Width;
};


typedef TcxEditSizeProperties *PcxEditSizeProperties;

enum TcxEditContentOption : unsigned char { ecoShowFocusRectWhenInplace, ecoOffsetButtonContent };

typedef System::Set<TcxEditContentOption, TcxEditContentOption::ecoShowFocusRectWhenInplace, TcxEditContentOption::ecoOffsetButtonContent>  TcxEditContentOptions;

struct DECLSPEC_DRECORD TcxEditContentParams
{
public:
	System::Types::TRect ExternalBorderBounds;
	System::Types::TRect Offsets;
	TcxEditContentOptions Options;
	System::Types::TSize SizeCorrection;
};


typedef void __fastcall (__closure *TcxEditGetDefaultButtonWidthEvent)(TcxCustomEditViewData* Sender, int AIndex, int &ADefaultWidth);

typedef void __fastcall (__closure *TcxEditViewDataGetDisplayTextEvent)(TcxCustomEditViewData* Sender, System::UnicodeString &AText);

class DELPHICLASS TcxCustomEditStyle;
class PASCALIMPLEMENTATION TcxCustomEditViewData : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::TObject* FData;
	bool FIsInplace;
	int FLeftSideLeftmostButtonIndex;
	int FLeftSideRightmostButtonIndex;
	int FRightSideLeftmostButtonIndex;
	int FRightSideRightmostButtonIndex;
	TcxEditGetDefaultButtonWidthEvent FOnGetDefaultButtonWidth;
	TcxEditViewDataGetDisplayTextEvent FOnGetDisplayText;
	void __fastcall DoGetButtonState(TcxEditButtonViewInfo* AViewInfo, TcxEditButtonState &AState);
	int __fastcall DoGetDefaultButtonWidth(int AIndex);
	TcxCustomEditStyle* __fastcall GetStyle(void);
	void __fastcall SetStyle(TcxCustomEditStyle* Value);
	
protected:
	TcxCustomEdit* FEdit;
	TcxCustomEditProperties* FProperties;
	TcxCustomEditStyle* FStyle;
	virtual void __fastcall CalculateButtonNativeInfo(TcxEditButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall CalculateButtonNativePartInfo(NativeUInt ATheme, TcxEditButtonViewInfo* AButtonViewInfo);
	virtual NativeUInt __fastcall GetButtonNativeTheme(TcxEditButtonViewInfo* AButtonViewInfo);
	virtual TcxEditPaintOptions __fastcall CalculatePaintOptions(void);
	void __fastcall CalculateViewInfo(TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual bool __fastcall CanPressButton(TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	void __fastcall CheckSizeConstraints(System::Types::TSize &AEditSize);
	void __fastcall CorrectBorderStyle(TcxEditBorderStyle &ABorderStyle);
	void __fastcall DoOnGetDisplayText(System::UnicodeString &AText);
	System::UnicodeString __fastcall EditValueToDisplayText(const System::Variant &AEditValue);
	TcxEditButtonStyle __fastcall GetButtonsStyle(void);
	int __fastcall GetCaptureButtonVisibleIndex(void);
	void __fastcall GetColorSettings(TcxCustomEditViewInfo* AViewInfo, System::Uitypes::TColor &FillColor, System::Uitypes::TColor &TextColor);
	virtual Cxcontainer::TcxContainerState __fastcall GetContainerState(const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual System::Types::TRect __fastcall GetEditContentDefaultOffsets(void);
	virtual int __fastcall GetEditNativeState(TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall InitCacheData(void);
	virtual void __fastcall InitEditContentParams(TcxEditContentParams &AParams);
	virtual void __fastcall Initialize(void);
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	bool __fastcall InternalFocused(void);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall InternalGetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	System::Types::TSize __fastcall InternalGetEditSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0), bool AIsEditing = false);
	virtual bool __fastcall IsButtonPressed(TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	
public:
	bool ButtonsOnlyStyle;
	int ButtonVisibleCount;
	Cxcontainer::TcxContainerState ContainerState;
	System::Types::TRect ContentOffset;
	TcxEditContentParams EditContentParams;
	bool Enabled;
	bool Focused;
	System::Classes::TAlignment HorzAlignment;
	Cxcontrols::_di_IcxControlScrollBar HScrollBar;
	_di_IcxCustomInnerEdit InnerEdit;
	TcxInplaceEditParams InplaceEditParams;
	bool IsDesigning;
	bool IsSelected;
	bool IsValueSource;
	int MaxLineCount;
	bool NativeStyle;
	TcxEditPaintOptions PaintOptions;
	bool PreviewMode;
	bool Selected;
	int SelStart;
	int SelLength;
	System::Uitypes::TColor SelTextColor;
	System::Uitypes::TColor SelBackgroundColor;
	bool SupportsTouchMode;
	TcxEditVertAlignment VertAlignment;
	Cxcontrols::_di_IcxControlScrollBar VScrollBar;
	HWND WindowHandle;
	__fastcall virtual TcxCustomEditViewData(TcxCustomEditProperties* AProperties, TcxCustomEditStyle* AStyle, bool AIsInplace);
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonBounds(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex, System::Types::TRect &ButtonsRect);
	virtual void __fastcall CalculateButtonsViewInfo(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonViewInfo(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex, System::Types::TRect &ButtonsRect);
	void __fastcall CalculateEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CheckButtonsOnly(TcxCustomEditViewInfo* AViewInfo, int APrevButtonsWidth, int AButtonsWidth);
	virtual void __fastcall CheckStartButtonsFading(TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, TcxCustomEditViewInfo* AViewInfo);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColorByPainter(bool AIsHighlight);
	virtual System::Types::TRect __fastcall GetBorderExtent(void);
	virtual System::Types::TRect __fastcall GetBorderExtentByEdges(int ABorderWidth);
	virtual System::Types::TRect __fastcall GetBorderExtentByPainter(void);
	virtual TcxEditBorderStyle __fastcall GetBorderStyle(void);
	virtual System::Types::TRect __fastcall GetButtonsExtent(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall GetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, const TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0));
	virtual System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	virtual System::Types::TSize __fastcall GetEditingContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	virtual System::Types::TSize __fastcall GetEditContentSizeCorrection(void);
	System::Types::TSize __fastcall GetEditSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0));
	System::Types::TSize __fastcall GetEditingSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties, TcxCustomEditViewInfo* AViewInfo = (TcxCustomEditViewInfo*)(0x0));
	virtual bool __fastcall HasShadow(void);
	virtual bool __fastcall IgnoreButtonWhileStretching(int AButtonVisibleIndex);
	__classmethod virtual bool __fastcall IsNativeStyle(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__property System::TObject* Data = {read=FData, write=FData};
	__property TcxCustomEdit* Edit = {read=FEdit, write=FEdit};
	__property bool IsInplace = {read=FIsInplace, nodefault};
	__property TcxCustomEditProperties* Properties = {read=FProperties};
	__property TcxCustomEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditGetDefaultButtonWidthEvent OnGetDefaultButtonWidth = {read=FOnGetDefaultButtonWidth, write=FOnGetDefaultButtonWidth};
	__property TcxEditViewDataGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=FOnGetDisplayText};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomEditViewData(void) { }
	
};


typedef System::TMetaClass* TcxCustomEditViewDataClass;

class DELPHICLASS TcxEditStyleController;
class DELPHICLASS TcxEditStyle;
class PASCALIMPLEMENTATION TcxEditStyleController : public Cxcontainer::TcxStyleController
{
	typedef Cxcontainer::TcxStyleController inherited;
	
private:
	HIDESBASE TcxCustomEditStyle* __fastcall GetInternalStyle(Cxcontainer::TcxContainerStateItem AState);
	HIDESBASE TcxEditStyle* __fastcall GetStyle(void);
	TcxEditStyle* __fastcall GetStyleDisabled(void);
	TcxEditStyle* __fastcall GetStyleFocused(void);
	TcxEditStyle* __fastcall GetStyleHot(void);
	HIDESBASE void __fastcall SetInternalStyle(Cxcontainer::TcxContainerStateItem AState, TcxCustomEditStyle* Value);
	void __fastcall SetStyle(TcxEditStyle* Value);
	void __fastcall SetStyleDisabled(TcxEditStyle* Value);
	void __fastcall SetStyleFocused(TcxEditStyle* Value);
	void __fastcall SetStyleHot(TcxEditStyle* Value);
	
protected:
	virtual Cxcontainer::TcxContainerStyleClass __fastcall GetStyleClass(void);
	
public:
	__property TcxCustomEditStyle* Styles[Cxcontainer::TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	
__published:
	__property TcxEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxEditStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxEditStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property OnStyleChanged;
public:
	/* TcxStyleController.Create */ inline __fastcall virtual TcxEditStyleController(System::Classes::TComponent* AOwner) : Cxcontainer::TcxStyleController(AOwner) { }
	/* TcxStyleController.Destroy */ inline __fastcall virtual ~TcxEditStyleController(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomEditStyle : public Cxcontainer::TcxContainerStyle
{
	typedef Cxcontainer::TcxContainerStyle inherited;
	
private:
	TcxEditButtonStyle FButtonStyle;
	TcxEditButtonTransparency FButtonTransparency;
	bool FGradient;
	bool FGradientButtons;
	Cxclasses::TcxDirection FGradientDirection;
	Cxlookandfeelpainters::TcxEditPopupBorderStyle FPopupBorderStyle;
	bool FPopupCloseButton;
	HIDESBASE TcxEditStyleController* __fastcall GetActiveStyleController(void);
	HIDESBASE Cxcontainer::TcxContainerStyleValues __fastcall GetAssignedValues(void);
	HIDESBASE TcxCustomEditStyle* __fastcall GetBaseStyle(void);
	HIDESBASE TcxEditBorderStyle __fastcall GetBorderStyle(void);
	TcxEditButtonStyle __fastcall GetButtonStyle(void);
	TcxEditButtonTransparency __fastcall GetButtonTransparency(void);
	TcxCustomEdit* __fastcall GetEdit(void);
	bool __fastcall GetGradient(void);
	bool __fastcall GetGradientButtons(void);
	TcxEditGradientDirection __fastcall GetGradientDirection(void);
	Cxlookandfeelpainters::TcxEditPopupBorderStyle __fastcall GetPopupBorderStyle(void);
	bool __fastcall GetPopupCloseButton(void);
	TcxEditStyleController* __fastcall GetStyleController(void);
	bool __fastcall InternalGetButtonStyle(TcxEditButtonStyle &ButtonStyle);
	bool __fastcall InternalGetButtonTransparency(TcxEditButtonTransparency &ButtonTransparency);
	bool __fastcall InternalGetGradient(bool &Gradient);
	bool __fastcall InternalGetGradientButtons(bool &GradientButtons);
	bool __fastcall InternalGetGradientDirection(TcxEditGradientDirection &GradientDirection);
	bool __fastcall InternalGetPopupBorderStyle(Cxlookandfeelpainters::TcxEditPopupBorderStyle &PopupBorderStyle);
	HIDESBASE bool __fastcall IsBorderStyleStored(void);
	bool __fastcall IsButtonStyleStored(void);
	bool __fastcall IsButtonTransparencyStored(void);
	bool __fastcall IsGradientStored(void);
	bool __fastcall IsGradientButtonsStored(void);
	bool __fastcall IsGradientDirectionStored(void);
	bool __fastcall IsPopupBorderStyleStored(void);
	HIDESBASE bool __fastcall IsStyleControllerStored(void);
	HIDESBASE void __fastcall SetAssignedValues(Cxcontainer::TcxContainerStyleValues Value);
	HIDESBASE void __fastcall SetBorderStyle(TcxEditBorderStyle Value);
	void __fastcall SetButtonStyle(TcxEditButtonStyle Value);
	void __fastcall SetButtonTransparency(TcxEditButtonTransparency Value);
	void __fastcall SetGradient(bool Value);
	void __fastcall SetGradientButtons(bool Value);
	void __fastcall SetGradientDirection(TcxEditGradientDirection Value);
	void __fastcall SetPopupBorderStyle(Cxlookandfeelpainters::TcxEditPopupBorderStyle Value);
	void __fastcall SetPopupCloseButton(bool Value);
	void __fastcall SetStyleController(TcxEditStyleController* Value);
	
protected:
	virtual Cxcontainer::TcxStyleController* __fastcall GetDefaultStyleController(void);
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedExtendedStyleValues(void);
	virtual TcxEditButtonStyle __fastcall DefaultButtonStyle(void);
	virtual TcxEditButtonTransparency __fastcall DefaultButtonTransparency(void);
	virtual bool __fastcall DefaultGradient(void);
	virtual bool __fastcall DefaultGradientButtons(void);
	virtual TcxEditGradientDirection __fastcall DefaultGradientDirection(void);
	virtual Cxlookandfeelpainters::TcxEditPopupBorderStyle __fastcall DefaultPopupBorderStyle(void);
	__property bool PopupCloseButton = {read=GetPopupCloseButton, write=SetPopupCloseButton, default=1};
	
public:
	__fastcall virtual TcxCustomEditStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall GetStyleValueCount(void);
	virtual bool __fastcall GetStyleValueName(Cxcontainer::TcxContainerStyleValue AStyleValue, /* out */ System::UnicodeString &StyleValueName);
	virtual bool __fastcall IsValueAssigned(Cxcontainer::TcxContainerStyleValue AValue);
	void __fastcall Init(const Cxgraphics::TcxViewParams &AParams);
	__property TcxEditStyleController* ActiveStyleController = {read=GetActiveStyleController};
	__property Cxcontainer::TcxContainerStyleValues AssignedValues = {read=GetAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property TcxCustomEditStyle* BaseStyle = {read=GetBaseStyle};
	__property TcxEditBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, stored=IsBorderStyleStored, nodefault};
	__property TcxEditButtonStyle ButtonStyle = {read=GetButtonStyle, write=SetButtonStyle, stored=IsButtonStyleStored, nodefault};
	__property TcxEditButtonTransparency ButtonTransparency = {read=GetButtonTransparency, write=SetButtonTransparency, stored=IsButtonTransparencyStored, nodefault};
	__property TcxCustomEdit* Edit = {read=GetEdit};
	__property bool Gradient = {read=GetGradient, write=SetGradient, stored=IsGradientStored, nodefault};
	__property bool GradientButtons = {read=GetGradientButtons, write=SetGradientButtons, stored=IsGradientButtonsStored, nodefault};
	__property TcxEditGradientDirection GradientDirection = {read=GetGradientDirection, write=SetGradientDirection, stored=IsGradientDirectionStored, nodefault};
	__property Cxlookandfeelpainters::TcxEditPopupBorderStyle PopupBorderStyle = {read=GetPopupBorderStyle, write=SetPopupBorderStyle, stored=IsPopupBorderStyleStored, nodefault};
	__property TcxEditStyleController* StyleController = {read=GetStyleController, write=SetStyleController, stored=IsStyleControllerStored};
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxCustomEditStyle(void) { }
	
};


typedef System::TMetaClass* TcxCustomEditStyleClass;

class PASCALIMPLEMENTATION TcxEditStyle : public TcxCustomEditStyle
{
	typedef TcxCustomEditStyle inherited;
	
__published:
	__property AssignedValues;
	__property BorderColor;
	__property BorderStyle;
	__property ButtonStyle;
	__property ButtonTransparency;
	__property Color;
	__property Edges;
	__property Font;
	__property Gradient;
	__property GradientDirection;
	__property HotTrack;
	__property LookAndFeel;
	__property PopupBorderStyle;
	__property Shadow;
	__property StyleController;
	__property TextColor;
	__property TextStyle;
	__property TransparentBorder;
public:
	/* TcxCustomEditStyle.Create */ inline __fastcall virtual TcxEditStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState) : TcxCustomEditStyle(AOwner, ADirectAccessMode, AParentStyle, AState) { }
	
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxEditStyle(void) { }
	
};


class DELPHICLASS TcxCustomEditPropertiesValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditPropertiesValues : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	bool FMaxValue;
	bool FMinValue;
	bool FReadOnly;
	TcxCustomEditProperties* __fastcall GetProperties(void);
	void __fastcall SetMaxValue(bool Value);
	void __fastcall SetMinValue(bool Value);
	void __fastcall SetReadOnly(bool Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall Changed(void);
	bool __fastcall IsMaxValueStored(void);
	bool __fastcall IsMinValueStored(void);
	bool __fastcall IsPropertiesPropertyVisible(const System::UnicodeString APropertyName);
	__property bool MaxValue = {read=FMaxValue, write=SetMaxValue, stored=IsMaxValueStored, nodefault};
	__property bool MinValue = {read=FMinValue, write=SetMinValue, stored=IsMinValueStored, nodefault};
	__property TcxCustomEditProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual TcxCustomEditPropertiesValues(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, stored=false, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomEditPropertiesValues(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomEditPropertiesValuesClass;

class DELPHICLASS TcxCustomEditDefaultValuesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditDefaultValuesProvider : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
public:
	__fastcall virtual ~TcxCustomEditDefaultValuesProvider(void);
	virtual bool __fastcall CanSetEditMode(void);
	void __fastcall ClearUsers(void);
	virtual System::Classes::TAlignment __fastcall DefaultAlignment(void);
	virtual TcxBlobKind __fastcall DefaultBlobKind(void);
	virtual bool __fastcall DefaultCanModify(void);
	virtual System::UnicodeString __fastcall DefaultDisplayFormat(void);
	virtual System::UnicodeString __fastcall DefaultEditFormat(void);
	virtual System::UnicodeString __fastcall DefaultEditMask(void);
	virtual bool __fastcall DefaultIsFloatValue(void);
	virtual int __fastcall DefaultMaxLength(void);
	virtual double __fastcall DefaultMaxValue(void);
	virtual double __fastcall DefaultMinValue(void);
	virtual int __fastcall DefaultPrecision(void);
	virtual bool __fastcall DefaultReadOnly(void);
	virtual bool __fastcall DefaultRequired(void);
	System::TObject* __fastcall GetInstance(void);
	virtual bool __fastcall IsBlob(void);
	virtual bool __fastcall IsCurrency(void);
	virtual bool __fastcall IsDataAvailable(void);
	virtual bool __fastcall IsDataStorage(void);
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
	virtual bool __fastcall IsOnGetTextAssigned(void);
	virtual bool __fastcall IsOnSetTextAssigned(void);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxCustomEditDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxInterfacedPersistent(AOwner) { }
	
private:
	void *__IcxEditDefaultValuesProvider;	/* IcxEditDefaultValuesProvider */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {AE727882-6FDF-4E3A-AB35-E58AB28EFE7B}
	operator _di_IcxEditDefaultValuesProvider()
	{
		_di_IcxEditDefaultValuesProvider intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditDefaultValuesProvider*(void) { return (IcxEditDefaultValuesProvider*)&__IcxEditDefaultValuesProvider; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxEditDefaultValuesProvider; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomEditDefaultValuesProviderClass;

typedef void __fastcall (__closure *TcxEditButtonClickEvent)(System::TObject* Sender, int AButtonIndex);

typedef void __fastcall (__closure *TcxEditEditingEvent)(System::TObject* Sender, bool &CanEdit);

enum TcxEditCloseUpReason : unsigned char { crUnknown, crTab, crClose, crCancel, crEnter };

typedef void __fastcall (__closure *TcxEditClosePopupEvent)(Cxcontrols::TcxControl* Sender, TcxEditCloseUpReason AReason);

class DELPHICLASS TcxEditAlignment;
class PASCALIMPLEMENTATION TcxCustomEditProperties : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	bool FAutoSelect;
	bool FBeepOnError;
	TcxEditButtons* FButtons;
	TcxEditButtonsViewStyle FButtonsViewStyle;
	bool FChangedOccurred;
	System::Classes::TShortCut FClearKey;
	System::Classes::TShortCut FClickKey;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FImmediatePost;
	TcxEditAlignment* FInnerAlignment;
	int FIsChangingCount;
	double FMaxValue;
	double FMinValue;
	bool FReadOnly;
	bool FTransparent;
	int FUpdateCount;
	bool FUseLeftAlignmentOnEditing;
	bool FUseMouseWheel;
	Dxgdiplusclasses::TdxSmartImage* FErrorIcon;
	bool FValidateOnEnter;
	TcxEditValidationOptions FValidationOptions;
	TcxEditButtonClickEvent FOnButtonClick;
	System::Classes::TNotifyEvent FOnChange;
	TcxEditClosePopupEvent FOnClosePopup;
	System::Classes::TNotifyEvent FOnEditValueChanged;
	TcxEditValidateEvent FOnValidate;
	System::Classes::TNotifyEvent FOnPropertiesChanged;
	TcxEditAlignment* __fastcall BaseGetAlignment(void);
	void __fastcall DefaultValuesChanged(System::TObject* Sender);
	bool __fastcall GetIsChanging(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	bool __fastcall IsAlignmentStored(void);
	bool __fastcall IsUseLeftAlignmentOnEditingStored(void);
	bool __fastcall IsReadOnlyStored(void);
	void __fastcall SetAssignedValues(TcxCustomEditPropertiesValues* Value);
	void __fastcall SetAutoSelect(bool Value);
	void __fastcall SetButtons(TcxEditButtons* Value);
	void __fastcall SetButtonsViewStyle(TcxEditButtonsViewStyle Value);
	void __fastcall SetErrorIcon(Dxgdiplusclasses::TdxSmartImage* Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	void __fastcall SetIDefaultValuesProvider(_di_IcxEditDefaultValuesProvider Value);
	void __fastcall SetMaxValue(double Value);
	void __fastcall SetMinValue(double Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetValidationOptions(TcxEditValidationOptions Value);
	
protected:
	TcxEditAlignment* FAlignment;
	TcxCustomEditPropertiesValues* FAssignedValues;
	bool FChangedLocked;
	_di_IcxEditDefaultValuesProvider FIDefaultValuesProvider;
	System::Classes::TPersistent* FOwner;
	virtual void __fastcall AlignmentChangedHandler(System::TObject* Sender);
	virtual void __fastcall BaseSetAlignment(TcxEditAlignment* Value);
	virtual void __fastcall ButtonsChanged(System::TObject* Sender);
	bool __fastcall CanModify(void);
	virtual bool __fastcall CanValidate(void);
	virtual bool __fastcall DefaultUseLeftAlignmentOnEditing(void);
	virtual void __fastcall DefaultValuesProviderDestroyed(void);
	virtual void __fastcall DoAssign(TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoChanged(void);
	void __fastcall DoValidate(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, TcxCustomEdit* AEdit, /* out */ bool &AIsUserErrorDisplayValue);
	void __fastcall FillMinMaxValues(double AMinValue, double AMaxValue);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	__classmethod virtual TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual System::Classes::TAlignment __fastcall GetDefaultHorzAlignment(void);
	virtual TcxEditVertAlignment __fastcall GetDefaultVertAlignment(void);
	virtual TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual double __fastcall GetMaxValue(void);
	virtual double __fastcall GetMinValue(void);
	virtual System::UnicodeString __fastcall GetValidateErrorText(int AErrorKind);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetValueEditorEditValueSource(bool AEditFocused);
	__classmethod virtual TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual bool __fastcall InnerEditNeedsTabs(void);
	bool __fastcall IsDesigning(void);
	virtual bool __fastcall IsEditValueConversionDependOnFocused(void);
	bool __fastcall IsMaxValueStored(void);
	bool __fastcall IsMinValueStored(void);
	virtual void __fastcall InitiateActions(void);
	__property TcxCustomEditPropertiesValues* AssignedValues = {read=FAssignedValues, write=SetAssignedValues};
	__property TcxEditButtonsViewStyle ButtonsViewStyle = {read=FButtonsViewStyle, write=SetButtonsViewStyle, default=0};
	__property TcxEditDisplayFormatOptions DisplayFormatOptions = {read=GetDisplayFormatOptions, nodefault};
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=FFreeNotificator};
	__property double MaxValue = {read=GetMaxValue, write=SetMaxValue, stored=IsMaxValueStored};
	__property double MinValue = {read=GetMinValue, write=SetMinValue, stored=IsMinValueStored};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, stored=false, nodefault};
	
public:
	__fastcall virtual TcxCustomEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomEditProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CanCompareEditValue(void);
	virtual TcxCustomEditProperties* __fastcall Clone(System::Classes::TPersistent* AOwner);
	__classmethod virtual TcxEditButtonsClass __fastcall GetButtonsClass();
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual TcxCustomEditStyleClass __fastcall GetStyleClass();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	void __fastcall BeginUpdate(void);
	void __fastcall Changed(void);
	bool __fastcall ChangedLocked(void);
	void __fastcall EndUpdate(bool AInvokeChanged = true);
	virtual void __fastcall Update(TcxCustomEditProperties* AProperties);
	void __fastcall LockUpdate(bool ALock);
	virtual bool __fastcall AllowRepositorySharing(void);
	virtual void __fastcall RefreshNonShareable(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	virtual TcxCustomEditProperties* __fastcall CreatePreviewProperties(void);
	virtual TcxCustomEditViewData* __fastcall CreateViewData(TcxCustomEditStyle* AStyle, bool AIsInplace, bool APreviewMode = false);
	virtual void __fastcall DataChanged(void);
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	System::Types::TSize __fastcall GetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditStyle* AEditStyle, bool AIsInplace, const TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize);
	System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditStyle* AEditStyle, bool AIsInplace, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	System::Types::TSize __fastcall GetEditSize(Cxgraphics::TcxCanvas* ACanvas, TcxCustomEditStyle* AEditStyle, bool AIsInplace, const System::Variant &AEditValue, const TcxEditSizeProperties &AEditSizeProperties);
	virtual TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	virtual bool __fastcall IsActivationKey(System::WideChar AKey);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual bool __fastcall IsResetEditClass(void);
	virtual bool __fastcall IsValueFormattedByProperties(void);
	virtual bool __fastcall IsValueFormattedByProvider(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall RestoreDefaults(void);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, TcxCustomEdit* AEdit);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	__property TcxEditButtons* Buttons = {read=FButtons, write=SetButtons};
	__property _di_IcxEditDefaultValuesProvider IDefaultValuesProvider = {read=FIDefaultValuesProvider, write=SetIDefaultValuesProvider};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool IsChanging = {read=GetIsChanging, nodefault};
	__property System::Classes::TNotifyEvent OnPropertiesChanged = {read=FOnPropertiesChanged, write=FOnPropertiesChanged};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, stored=IsReadOnlyStored, nodefault};
	__property bool UseLeftAlignmentOnEditing = {read=FUseLeftAlignmentOnEditing, write=SetUseLeftAlignmentOnEditing, stored=IsUseLeftAlignmentOnEditingStored, nodefault};
	__property bool UseMouseWheel = {read=FUseMouseWheel, write=FUseMouseWheel, default=1};
	__property TcxEditAlignment* Alignment = {read=BaseGetAlignment, write=BaseSetAlignment, stored=IsAlignmentStored};
	__property bool AutoSelect = {read=FAutoSelect, write=SetAutoSelect, default=1};
	__property bool BeepOnError = {read=FBeepOnError, write=FBeepOnError, default=0};
	__property System::Classes::TShortCut ClearKey = {read=FClearKey, write=FClearKey, default=0};
	__property System::Classes::TShortCut ClickKey = {read=FClickKey, write=FClickKey, default=16397};
	__property bool ImmediatePost = {read=FImmediatePost, write=FImmediatePost, default=0};
	__property bool ValidateOnEnter = {read=FValidateOnEnter, write=FValidateOnEnter, default=0};
	__property TcxEditValidationOptions ValidationOptions = {read=FValidationOptions, write=SetValidationOptions, default=1};
	__property Dxgdiplusclasses::TdxSmartImage* ErrorIcon = {read=FErrorIcon, write=SetErrorIcon};
	__property TcxEditButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TcxEditClosePopupEvent OnClosePopup = {read=FOnClosePopup, write=FOnClosePopup};
	__property System::Classes::TNotifyEvent OnEditValueChanged = {read=FOnEditValueChanged, write=FOnEditValueChanged};
	__property TcxEditValidateEvent OnValidate = {read=FOnValidate, write=FOnValidate};
};


class DELPHICLASS TcxDataBinding;
class PASCALIMPLEMENTATION TcxDataBinding : public Cxdatautils::TcxCustomDataBinding
{
	typedef Cxdatautils::TcxCustomDataBinding inherited;
	
public:
	/* TcxCustomDataBinding.Create */ inline __fastcall virtual TcxDataBinding(System::Classes::TComponent* AOwner, System::Classes::TComponent* ADataComponent) : Cxdatautils::TcxCustomDataBinding(AOwner, ADataComponent) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDataBinding(void) { }
	
};


typedef System::TMetaClass* TInterfacedObjectClass;

class DELPHICLASS TcxEditDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditDataBinding : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomEditDefaultValuesProvider* FIDefaultValuesProvider;
	_di_IcxEditDefaultValuesProvider __fastcall GetIDefaultValuesProvider(void);
	
protected:
	TcxCustomEdit* FEdit;
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall DefaultValuesChanged(void);
	virtual System::Variant __fastcall GetDisplayValue(void);
	virtual bool __fastcall GetIsDataAvailable(void);
	TcxEditDataBinding* __fastcall GetEditDataBindingInstance(void);
	virtual bool __fastcall GetEditing(void);
	virtual bool __fastcall GetModified(void);
	virtual System::Variant __fastcall GetStoredValue(void);
	virtual bool __fastcall IsInnerControlHaveToBeReadOnly(void);
	virtual bool __fastcall IsNull(void);
	virtual void __fastcall Reset(void);
	void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual void __fastcall SetDisplayValue(const System::Variant &Value);
	virtual bool __fastcall SetEditMode(void);
	virtual void __fastcall SetStoredValue(const System::Variant &Value);
	__property TcxCustomEdit* Edit = {read=FEdit};
	
public:
	__fastcall virtual TcxEditDataBinding(TcxCustomEdit* AEdit);
	__fastcall virtual ~TcxEditDataBinding(void);
	virtual bool __fastcall CanCheckEditorValue(void);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall CanPostEditorValue(void);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	__classmethod virtual TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass();
	virtual void __fastcall SetModified(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateDisplayValue(void);
	virtual void __fastcall UpdateNotConnectedDBEditDisplayValue(void);
	__property System::Variant DisplayValue = {read=GetDisplayValue, write=SetDisplayValue};
	__property bool Editing = {read=GetEditing, nodefault};
	__property _di_IcxEditDefaultValuesProvider IDefaultValuesProvider = {read=GetIDefaultValuesProvider};
	__property bool IsDataAvailable = {read=GetIsDataAvailable, nodefault};
	__property bool Modified = {read=GetModified, nodefault};
	__property System::Variant StoredValue = {read=GetStoredValue, write=SetStoredValue};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxEditDataBindingClass;

struct DECLSPEC_DRECORD TcxEditModifiedState
{
public:
	bool Modified;
	bool ModifiedAfterEnter;
};


class DELPHICLASS TcxCustomEditData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomEditData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCleared;
	TcxCustomEdit* FEdit;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	
protected:
	__property bool Cleared = {read=FCleared, write=FCleared, nodefault};
	
public:
	__fastcall virtual TcxCustomEditData(TcxCustomEdit* AEdit);
	__fastcall virtual ~TcxCustomEditData(void);
	void __fastcall Clear(void);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomEditDataClass;

class DELPHICLASS TcxEditChangeEventsCatcher;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditChangeEventsCatcher : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomEdit* FEdit;
	int FLockCount;
	bool FOnChangeEvent;
	bool FOnEditValueChangedEvent;
	
public:
	__fastcall TcxEditChangeEventsCatcher(TcxCustomEdit* AEdit);
	bool __fastcall IsLocked(void);
	void __fastcall Lock(bool ALock, bool AInvokeChangedOnUnlock = true);
	void __fastcall InvokeEditChangedEvents(void);
	__property bool OnChangeEvent = {read=FOnChangeEvent, write=FOnChangeEvent, nodefault};
	__property bool OnEditValueChangedEvent = {read=FOnEditValueChangedEvent, write=FOnEditValueChangedEvent, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEditChangeEventsCatcher(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomEditContainer;
class PASCALIMPLEMENTATION TcxCustomEditContainer : public Cxcontainer::TcxContainer
{
	typedef Cxcontainer::TcxContainer inherited;
	
private:
	MESSAGE void __fastcall CMGestureManagerChanged(Winapi::Messages::TMessage &Message);
	
protected:
	bool __fastcall IsTransparentRegionsPresent(void);
	
__published:
	__property Align = {default=0};
public:
	/* TcxContainer.Create */ inline __fastcall virtual TcxCustomEditContainer(System::Classes::TComponent* AOwner) : Cxcontainer::TcxContainer(AOwner) { }
	/* TcxContainer.Destroy */ inline __fastcall virtual ~TcxCustomEditContainer(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomEditContainer(HWND ParentWindow) : Cxcontainer::TcxContainer(ParentWindow) { }
	
private:
	void *__IcxTransparentControl;	/* Cxcontrols::IcxTransparentControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F4980C69-029E-4B14-B3AD-953DA5C18BE7}
	operator Cxcontrols::_di_IcxTransparentControl()
	{
		Cxcontrols::_di_IcxTransparentControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxTransparentControl*(void) { return (Cxcontrols::IcxTransparentControl*)&__IcxTransparentControl; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomEdit : public TcxCustomEditContainer
{
	typedef TcxCustomEditContainer inherited;
	
private:
	typedef System::DynamicArray<TcxEditModifiedState> _TcxCustomEdit__1;
	
	
private:
	int FAnchorX;
	int FAnchorY;
	Vcl::Controls::TScalingFlags FAnchorScalingFlags;
	bool FAutoSize;
	int FCaptureButtonVisibleIndex;
	TcxEditChangeEventsCatcher* FChangeEventsCatcher;
	int FClickLockCount;
	Cxclasses::TcxTimer* FDblClickTimer;
	TcxCustomEditData* FEditData;
	bool FEditModeSetting;
	int FEditValueChangingLockCount;
	bool FFocused;
	bool FHandleAllocating;
	_di_IcxCustomInnerEdit FInnerEdit;
	bool FIsBarControl;
	bool FIsContentParamsInitialized;
	bool FIsKeyPressHandled;
	bool FIsFirstSetSize;
	bool FIsHiding;
	bool FIsInplace;
	bool FIsJustCreated;
	bool FIsPosting;
	bool FIsUserAction;
	bool FModified;
	bool FModifiedAfterEnter;
	bool FNeedFocusOnClick;
	Vcl::Controls::TKeyEvent FOnAfterKeyDown;
	TcxEditEditingEvent FOnEditing;
	System::Classes::TNotifyEvent FOnPostEditValue;
	System::Variant FPrevEditValue;
	_TcxCustomEdit__1 FPrevModifiedList;
	bool FPrevValidationError;
	System::Classes::TNotifyEvent FPropertiesEvents;
	TcxEditRepositoryItem* FRepositoryItem;
	bool FSupportsTouchMode;
	bool FTransparent;
	bool FUpdate;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	bool FIsEditValidated;
	bool FIsEditValidating;
	int FLockValidate;
	bool FValidateErrorProcessing;
	bool FValidationError;
	Vcl::Controls::TCaption FValidationErrorText;
	bool __fastcall CheckButtonShortCuts(int AKey);
	void __fastcall DblClickTimerHandler(System::TObject* Sender);
	void __fastcall DoClearEditData(TcxCustomEditData* AEditData);
	TcxCustomEditProperties* __fastcall GetActiveProperties(void);
	TcxCustomEditStyle* __fastcall GetEditActiveStyle(void);
	int __fastcall GetHeight(void);
	HIDESBASE TcxCustomEditStyle* __fastcall GetInternalStyle(Cxcontainer::TcxContainerStateItem AState);
	HIDESBASE TcxEditStyle* __fastcall GetStyle(void);
	HIDESBASE TcxEditStyle* __fastcall GetStyleDisabled(void);
	HIDESBASE TcxEditStyle* __fastcall GetStyleFocused(void);
	HIDESBASE TcxEditStyle* __fastcall GetStyleHot(void);
	TcxCustomEditViewInfo* __fastcall GetViewInfo(void);
	void __fastcall HandlePasteMessage(void);
	void __fastcall InitContentParams(void);
	void __fastcall InternalCanResize(int &ANewWidth, int &ANewHeight);
	bool __fastcall IsAutoHeight(void);
	bool __fastcall IsAutoWidth(void);
	void __fastcall ReadAnchorX(System::Classes::TReader* Reader);
	void __fastcall ReadAnchorY(System::Classes::TReader* Reader);
	void __fastcall ReadHeight(System::Classes::TReader* Reader);
	void __fastcall ReadWidth(System::Classes::TReader* Reader);
	void __fastcall SetDataBinding(TcxEditDataBinding* Value);
	HIDESBASE void __fastcall SetHeight(int Value);
	HIDESBASE void __fastcall SetInternalStyle(Cxcontainer::TcxContainerStateItem AState, TcxCustomEditStyle* Value);
	void __fastcall SetInternalReadOnly(bool Value);
	void __fastcall SetModified(bool Value);
	void __fastcall SetModifiedAfterEnter(bool Value);
	void __fastcall SetModifiedAfterEnterValue(bool Value);
	void __fastcall SetPrevEditValue(const System::Variant &Value);
	void __fastcall SetProperties(TcxCustomEditProperties* Value);
	void __fastcall SetRepositoryItem(TcxEditRepositoryItem* Value);
	void __fastcall SetReplicatableFlag(void);
	HIDESBASE void __fastcall SetStyle(TcxEditStyle* Value);
	HIDESBASE void __fastcall SetStyleDisabled(TcxEditStyle* Value);
	HIDESBASE void __fastcall SetStyleFocused(TcxEditStyle* Value);
	HIDESBASE void __fastcall SetStyleHot(TcxEditStyle* Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall WriteAnchorX(System::Classes::TWriter* Writer);
	void __fastcall WriteAnchorY(System::Classes::TWriter* Writer);
	void __fastcall WriteHeight(System::Classes::TWriter* Writer);
	void __fastcall WriteWidth(System::Classes::TWriter* Writer);
	System::UnicodeString __fastcall GetHintText(int APart);
	MESSAGE void __fastcall WMCopy(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCut(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	MESSAGE void __fastcall WMPaste(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMUpdateEditvalue(Winapi::Messages::TMessage &Message);
	
protected:
	TcxEditDataBinding* FDataBinding;
	System::Variant FEditValue;
	TcxCustomEditProperties* FProperties;
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateHandle(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall RequestAlign(void);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	virtual bool __fastcall CanContainerHandleTabs(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual bool __fastcall DoInnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual System::Types::TRect __fastcall GetBorderExtent(void);
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind(void);
	virtual Cxcontainer::TcxContainerStyleClass __fastcall GetStyleClass(void);
	virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetWindowRegionAddon(void);
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues(void);
	virtual bool __fastcall IsTransparentBackground(void);
	virtual void __fastcall DoSetSize(void);
	virtual bool __fastcall IsNativeStyle(void);
	virtual void __fastcall SafeSelectionFocusInnerControl(void);
	virtual void __fastcall AcceleratorClick(void);
	virtual void __fastcall AdjustInnerEditPosition(void);
	virtual void __fastcall AfterPosting(void);
	virtual void __fastcall BeforePosting(void);
	int __fastcall ButtonVisibleIndexAt(const System::Types::TPoint &P);
	HIDESBASE void __fastcall CalculateViewInfo(bool AIsMouseEvent)/* overload */;
	HIDESBASE virtual void __fastcall CalculateViewInfo(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent)/* overload */;
	HIDESBASE void __fastcall CalculateViewInfo(TcxCustomEditViewInfo* AViewInfo, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent)/* overload */;
	virtual void __fastcall CalculateAnchors(void);
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	void __fastcall CheckHandle(void);
	virtual _di_IcxCustomInnerEdit __fastcall CreateInnerEdit(void);
	virtual TcxCustomEditViewData* __fastcall CreateViewData(void);
	virtual void __fastcall DefaultButtonClick(void);
	void __fastcall DoAfterKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoAutoSizeChanged(void);
	virtual void __fastcall DoButtonClick(int AButtonVisibleIndex);
	virtual void __fastcall DoButtonDown(int AButtonVisibleIndex);
	virtual void __fastcall DoButtonUp(int AButtonVisibleIndex);
	virtual void __fastcall DoChange(void);
	void __fastcall DoClick(void);
	void __fastcall DoClosePopup(TcxEditCloseUpReason AReason);
	virtual void __fastcall DoEditValueChanged(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DoEditKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditProcessTab(System::Classes::TShiftState Shift);
	virtual void __fastcall DoFocusChanged(void);
	void __fastcall DoHideEdit(bool AExit);
	virtual void __fastcall DoOnChange(void);
	virtual void __fastcall DoOnEditValueChanged(void);
	void __fastcall DoPostEditValue(void);
	virtual void __fastcall DoProcessEventsOnViewInfoChanging(void);
	virtual void __fastcall DoSetFocusWhenActivate(void);
	virtual void __fastcall DoShowEdit(void);
	virtual void __fastcall EditingChanged(void);
	virtual System::Variant __fastcall GetClearValue(void);
	__classmethod virtual TcxEditDataBindingClass __fastcall GetDataBindingClass();
	int __fastcall GetDefaultButtonVisibleIndex(void);
	virtual System::UnicodeString __fastcall GetDisplayValue(void);
	virtual TcxCustomEditDataClass __fastcall GetEditDataClass(void);
	virtual System::Variant __fastcall GetEditingValue(void);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	bool __fastcall HandleMouseWheel(System::Classes::TShiftState Shift);
	virtual void __fastcall PopulateSizeProperties(TcxEditSizeProperties &AEditSizeProperties);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeEditData(void);
	virtual void __fastcall InitializeInnerEdit(void);
	virtual void __fastcall InitializeViewData(TcxCustomEditViewData* AViewData);
	virtual void __fastcall PrepareEditForInplaceActivation(void);
	virtual bool __fastcall InternalDoEditing(void);
	TcxCustomEditProperties* __fastcall InternalGetActiveProperties(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	void __fastcall InternalPostEditValue(bool AValidateEdit = false);
	void __fastcall InternalPostValue(void);
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall InternalStoreEditValue(const System::Variant &Value);
	HIDESBASE virtual bool __fastcall CanAutoSize(void);
	virtual bool __fastcall CanAutoHeight(void);
	virtual bool __fastcall CanAutoWidth(void);
	virtual bool __fastcall CanKeyDownModifyEdit(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall CanKeyPressModifyEdit(System::WideChar Key);
	virtual bool __fastcall CanModify(void);
	bool __fastcall HasInnerEdit(void);
	virtual bool __fastcall IsActiveControl(void);
	virtual bool __fastcall IsButtonDC(NativeUInt ADC);
	virtual bool __fastcall IsClickEnabledDuringLoading(void);
	bool __fastcall IsDBEdit(void);
	bool __fastcall IsDBEditPaintCopyDrawing(void);
	bool __fastcall IsDefaultButtonKey(System::Classes::TShortCut AShortCut);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual bool __fastcall IsEditorKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsEditValueStored(void);
	virtual bool __fastcall IsNativeBackground(void);
	bool __fastcall IsOnChangeEventAssigned(void);
	bool __fastcall IsOnEditValueChangedEventAssigned(void);
	bool __fastcall IsResetEditClass(void);
	bool __fastcall IsSpecialKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsTransparent(void);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual bool __fastcall NeedsInvokeAfterKeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall UseAnchors(void);
	virtual bool __fastcall UseAnchorX(void);
	virtual bool __fastcall UseAnchorY(void);
	bool __fastcall IsOnValidateEventAssigned(void);
	virtual bool __fastcall CanShowValidationErrorOnPostEditValue(void);
	void __fastcall DisableValidate(void);
	void __fastcall DoOnValidate(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual void __fastcall DoValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	bool __fastcall InternalValidateEdit(TcxEditValidationOptions AValidationOptions, bool AForceValidation = false)/* overload */;
	bool __fastcall InternalValidateEdit(bool AForceValidation = false)/* overload */;
	virtual void __fastcall HandleValidationError(const System::UnicodeString AErrorText, TcxEditValidationOptions AValidationOptions, bool ACanAbortExecution);
	void __fastcall EnableValidate(void);
	virtual void __fastcall PaintCopyDraw(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	bool __fastcall PropertiesChangeLocked(void);
	virtual bool __fastcall RealReadOnly(void);
	virtual void __fastcall RepositoryItemAssigned(void);
	virtual void __fastcall RepositoryItemAssigning(void);
	virtual void __fastcall ResetEditValue(void);
	void __fastcall RestoreModified(void);
	void __fastcall SaveModified(void);
	virtual bool __fastcall SendActivationKey(System::WideChar Key);
	virtual bool __fastcall SetDisplayText(const System::UnicodeString Value);
	virtual void __fastcall SetEditAutoSize(bool Value);
	virtual void __fastcall SetEditValue(const System::Variant &Value);
	virtual void __fastcall SetInternalEditValue(const System::Variant &Value);
	virtual void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeEditValue(void);
	virtual bool __fastcall TabsNeeded(void);
	virtual bool __fastcall UpdateContentOnFocusChanging(void);
	virtual void __fastcall UpdateDrawValue(void);
	void __fastcall UpdateInnerEditReadOnly(void);
	virtual bool __fastcall ValidateKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall ValidateKeyPress(System::WideChar &Key);
	virtual bool __fastcall WantNavigationKeys(void);
	virtual void __fastcall LockedInnerEditWindowProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall LockInnerEditRepainting(void);
	virtual void __fastcall UnlockInnerEditRepainting(void);
	TcxCustomEditViewData* __fastcall GetViewData(/* out */ bool &AIsViewDataCreated);
	HIDESBASE void __fastcall InvalidateRect(const System::Types::TRect &R, bool AEraseBackground = true);
	void __fastcall RepositoryItemListenerItemRemoved(TcxEditRepositoryItem* Sender);
	void __fastcall RepositoryItemListenerPropertiesChanged(TcxEditRepositoryItem* Sender);
	virtual bool __fastcall SupportsSpelling(void);
	virtual void __fastcall SpellCheckerSetIsBarControl(bool AValue);
	virtual void __fastcall SpellCheckerSetSelText(const System::UnicodeString AValue, bool APost = false);
	virtual void __fastcall SpellCheckerSetValue(const System::Variant &AValue);
	virtual bool __fastcall FadingCanFadeBackground(void);
	virtual void __fastcall FadingGetBackgroundImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	void __fastcall FadingInvalidateBackground(void);
	__property TcxCustomEditStyle* ActiveStyle = {read=GetEditActiveStyle};
	__property int AnchorX = {read=FAnchorX, nodefault};
	__property int AnchorY = {read=FAnchorY, nodefault};
	__property bool AutoSize = {read=FAutoSize, write=SetEditAutoSize, default=1};
	__property int CaptureButtonVisibleIndex = {read=FCaptureButtonVisibleIndex, write=FCaptureButtonVisibleIndex, nodefault};
	__property TcxEditChangeEventsCatcher* ChangeEventsCatcher = {read=FChangeEventsCatcher};
	__property TcxEditDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property System::UnicodeString DisplayValue = {read=GetDisplayValue};
	__property TcxCustomEditData* EditData = {read=FEditData};
	__property bool EditModeSetting = {read=FEditModeSetting, nodefault};
	__property _di_IcxCustomInnerEdit InnerEdit = {read=FInnerEdit};
	__property bool IsEditValidated = {read=FIsEditValidated, write=FIsEditValidated, nodefault};
	__property bool IsKeyPressHandled = {read=FIsKeyPressHandled, write=FIsKeyPressHandled, nodefault};
	__property bool IsUserAction = {read=FIsUserAction, write=FIsUserAction, nodefault};
	__property bool NeedFocusOnClick = {read=FNeedFocusOnClick, write=FNeedFocusOnClick, nodefault};
	__property System::Variant PrevEditValue = {read=FPrevEditValue, write=SetPrevEditValue};
	__property TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property bool SupportsTouchMode = {read=FSupportsTouchMode, write=FSupportsTouchMode, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	
public:
	TcxEditContentParams ContentParams;
	TcxInplaceEditParams InplaceParams;
	__fastcall virtual TcxCustomEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual TcxCustomEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */;
	__fastcall virtual ~TcxCustomEdit(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual bool __fastcall InnerControlMenuHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsInplace(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall CopyToClipboard(void);
	virtual void __fastcall CutToClipboard(void);
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall Activate(TcxCustomEditData* &AEditData, bool ANeedSetFocus = true);
	virtual void __fastcall ActivateByKey(System::WideChar Key, TcxCustomEditData* &AEditData);
	virtual void __fastcall ActivateByMouse(System::Classes::TShiftState Shift, int X, int Y, TcxCustomEditData* &AEditData);
	bool __fastcall AreChangeEventsLocked(void);
	bool __fastcall CanPostEditValue(void);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall Deactivate(void);
	bool __fastcall DoEditing(void);
	__classmethod virtual TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall InitiateAction(void);
	bool __fastcall InternalFocused(void);
	virtual bool __fastcall IsChildWindow(NativeUInt AWnd);
	virtual bool __fastcall IsEditClass(void);
	virtual bool __fastcall IsRepositoryItemAcceptable(TcxEditRepositoryItem* ARepositoryItem);
	void __fastcall LockChangeEvents(bool ALock, bool AInvokeChangedOnUnlock = true);
	void __fastcall LockClick(bool ALock);
	void __fastcall LockEditValueChanging(bool ALock);
	void __fastcall PostEditValue(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	void __fastcall Reset(void);
	virtual void __fastcall SelectAll(void);
	void __fastcall SetValidatableEditValue(const System::Variant &AEditValue);
	bool __fastcall ValidateEdit(bool ARaiseExceptionOnError)/* overload */;
	bool __fastcall ValidateEdit(void)/* overload */;
	virtual int __fastcall GetTextBaseLine(void);
	virtual bool __fastcall HasTextBaseLine(void);
	__property TcxCustomEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::Variant EditingValue = {read=GetEditingValue};
	__property bool EditModified = {read=FModified, write=SetModified, nodefault};
	__property System::Variant EditValue = {read=GetEditValue, write=SetEditValue, stored=IsEditValueStored};
	__property System::Variant InternalEditValue = {read=GetEditValue, write=SetInternalEditValue, stored=false};
	__property TcxCustomEditProperties* InternalProperties = {read=FProperties};
	__property bool IsEditValidating = {read=FIsEditValidating, nodefault};
	__property bool IsHiding = {read=FIsHiding, nodefault};
	__property bool IsPosting = {read=FIsPosting, nodefault};
	__property bool ModifiedAfterEnter = {read=FModifiedAfterEnter, write=SetModifiedAfterEnter, nodefault};
	__property TcxEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxEditStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxEditStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property TcxCustomEditStyle* Styles[Cxcontainer::TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	__property TabStop = {default=1};
	__property TcxCustomEditViewInfo* ViewInfo = {read=GetViewInfo};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
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
	__property Vcl::Controls::TKeyEvent OnAfterKeyDown = {read=FOnAfterKeyDown, write=FOnAfterKeyDown};
	__property TcxEditEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property System::Classes::TNotifyEvent OnPostEditValue = {read=FOnPostEditValue, write=FOnPostEditValue};
	
__published:
	__property int Height = {read=GetHeight, write=SetHeight, stored=false, nodefault};
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FPropertiesEvents, write=FPropertiesEvents};
	__property TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
	__property Width = {stored=false};
	__property OnFocusChanged;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomEdit(HWND ParentWindow) : TcxCustomEditContainer(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IcxEditOwner;	/* IcxEditOwner */
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	void *__IdxSpellCheckerControl;	/* Cxcontrols::IdxSpellCheckerControl */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxEditRepositoryItemListener;	/* IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4129100C-7FC6-436E-8711-47A5C978CA73}
	operator _di_IcxEditOwner()
	{
		_di_IcxEditOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditOwner*(void) { return (IcxEditOwner*)&__IcxEditOwner; }
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2DEA4CCA-3C6D-4283-9441-AABBD61F74F3}
	operator Cxcontrols::_di_IdxSpellCheckerControl()
	{
		Cxcontrols::_di_IdxSpellCheckerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IdxSpellCheckerControl*(void) { return (Cxcontrols::IdxSpellCheckerControl*)&__IdxSpellCheckerControl; }
	#endif
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
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator _di_IcxEditRepositoryItemListener()
	{
		_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxEditRepositoryItemListener*(void) { return (IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomEditClass;

class PASCALIMPLEMENTATION TcxEditAlignment : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxEditVertAlignment FDefaultVertAlignment;
	System::Classes::TAlignment FHorz;
	bool FIsHorzAssigned;
	System::Classes::TPersistent* FOwner;
	TcxEditVertAlignment FVert;
	System::Classes::TNotifyEvent FOnChanged;
	void __fastcall SetHorz(const System::Classes::TAlignment Value);
	void __fastcall SetVert(const TcxEditVertAlignment Value);
	
protected:
	void __fastcall DoChanged(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxEditAlignment(System::Classes::TPersistent* AOwner)/* overload */;
	__fastcall virtual TcxEditAlignment(System::Classes::TPersistent* AOwner, TcxEditVertAlignment ADefaultVertAlignment)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsHorzStored(void);
	bool __fastcall IsVertStored(void);
	void __fastcall Reset(void);
	
__published:
	__property System::Classes::TAlignment Horz = {read=FHorz, write=SetHorz, stored=IsHorzStored, nodefault};
	__property TcxEditVertAlignment Vert = {read=FVert, write=SetVert, stored=IsVertStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxEditAlignment(void) { }
	
};


struct DECLSPEC_DRECORD TcxEditListItem
{
public:
	TcxCustomEdit* Edit;
	TcxCustomEditProperties* Properties;
};


class DELPHICLASS TcxInplaceEditList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInplaceEditList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TcxEditListItem> _TcxInplaceEditList__1;
	
	
private:
	_TcxInplaceEditList__1 FItems;
	System::Classes::TComponent* FEditorOwner;
	TcxCustomEdit* __fastcall CreateEdit(TcxCustomEditPropertiesClass APropertiesClass);
	void __fastcall DestroyItems(void);
	int __fastcall FindItem(TcxCustomEditProperties* AProperties, bool ACanUseFreeEditors)/* overload */;
	int __fastcall FindItem(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
	int __fastcall GetCount(void);
	TcxCustomEdit* __fastcall GetEdit(int AItemIndex)/* overload */;
	void __fastcall InitEdit(TcxCustomEdit* AEdit, TcxCustomEditProperties* AProperties);
	void __fastcall RemoveItem(int AIndex)/* overload */;
	
protected:
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::TComponent* EditorOwner = {read=FEditorOwner};
	
public:
	__fastcall virtual TcxInplaceEditList(System::Classes::TComponent* AEditorOwner);
	__fastcall virtual ~TcxInplaceEditList(void);
	void __fastcall DisconnectProperties(TcxCustomEditProperties* AProperties);
	TcxCustomEdit* __fastcall FindEdit(TcxCustomEditProperties* AProperties)/* overload */;
	TcxCustomEdit* __fastcall FindEdit(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
	TcxCustomEdit* __fastcall GetEdit(TcxCustomEditProperties* AProperties)/* overload */;
	TcxCustomEdit* __fastcall GetEdit(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
	void __fastcall RemoveItem(TcxCustomEditProperties* AProperties)/* overload */;
	void __fastcall RemoveItem(TcxCustomEditPropertiesClass APropertiesClass)/* overload */;
};

#pragma pack(pop)

class DELPHICLASS TcxDefaultEditStyleController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDefaultEditStyleController : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
private:
	bool __fastcall GetEmulateStandardControlDrawing(void);
	TcxCustomEditStyle* __fastcall GetInternalStyle(Cxcontainer::TcxContainerStateItem AState);
	System::Classes::TNotifyEvent __fastcall GetOnStyleChanged(void);
	TcxEditStyle* __fastcall GetStyle(void);
	TcxEditStyle* __fastcall GetStyleDisabled(void);
	TcxEditStyle* __fastcall GetStyleFocused(void);
	TcxEditStyle* __fastcall GetStyleHot(void);
	void __fastcall SetEmulateStandardControlDrawing(bool Value);
	void __fastcall SetInternalStyle(Cxcontainer::TcxContainerStateItem AState, TcxCustomEditStyle* Value);
	void __fastcall SetOnStyleChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetStyle(TcxEditStyle* Value);
	void __fastcall SetStyleDisabled(TcxEditStyle* Value);
	void __fastcall SetStyleFocused(TcxEditStyle* Value);
	void __fastcall SetStyleHot(TcxEditStyle* Value);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	
public:
	__fastcall virtual TcxDefaultEditStyleController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDefaultEditStyleController(void);
	void __fastcall RestoreStyles(void);
	__property TcxCustomEditStyle* Styles[Cxcontainer::TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	
__published:
	__property Scalable = {default=1};
	__property bool EmulateStandardControlDrawing = {read=GetEmulateStandardControlDrawing, write=SetEmulateStandardControlDrawing, default=0};
	__property TcxEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxEditStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxEditStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxEditStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property System::Classes::TNotifyEvent OnStyleChanged = {read=GetOnStyleChanged, write=SetOnStyleChanged};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomEditingController;
class PASCALIMPLEMENTATION TcxCustomEditingController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxInplaceEditList* FEditList;
	Cxclasses::TcxTimer* FEditShowingTimer;
	bool FEditUpdateNeeded;
	bool FInitiatingEditing;
	System::Classes::TNotifyEvent FPrevEditOnChange;
	System::Classes::TNotifyEvent FPrevEditOnEditValueChanged;
	void __fastcall EditShowingTimerHandler(System::TObject* Sender);
	TcxEditChangeEventsCatcher* __fastcall GetChangeEventsCatcher(void);
	void __fastcall ImmediateEventHandler(Cxcustomdata::TcxCustomDataController* ADataController);
	
protected:
	TcxCustomEdit* FEdit;
	bool FEditHiding;
	System::Types::TRect FEditPlaceBounds;
	bool FEditPreparing;
	bool FIsEditPlaced;
	bool FIsErrorOnEditExit;
	void __fastcall CancelEditUpdatePost(void);
	virtual bool __fastcall CanHideEdit(void);
	virtual bool __fastcall CanInitEditing(void) = 0 ;
	virtual bool __fastcall CanRemoveEditFocus(void);
	virtual bool __fastcall CanUpdateEditValue(void);
	void __fastcall CheckEditUpdatePost(void);
	virtual void __fastcall ClearEditingItem(void) = 0 ;
	void __fastcall CloseEdit(void);
	virtual void __fastcall DoEditChanged(void);
	virtual void __fastcall DoHideEdit(bool Accept) = 0 ;
	virtual void __fastcall DoUpdateEdit(void) = 0 ;
	virtual bool __fastcall GetCancelEditingOnExit(void) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetEditParent(void) = 0 ;
	virtual System::Types::TRect __fastcall GetFocusRectBounds(void);
	virtual System::Types::TRect __fastcall GetFocusedCellBounds(void) = 0 ;
	virtual bool __fastcall GetHideEditOnExit(void);
	virtual bool __fastcall GetIsEditing(void) = 0 ;
	virtual void __fastcall HideInplaceEditor(void);
	virtual void __fastcall InitEdit(void);
	virtual bool __fastcall IsNeedInvokeEditChangedEventsBeforePost(void);
	void __fastcall InvokeEditChangedEvents(void);
	virtual void __fastcall MultilineEditTextChanged(void);
	void __fastcall PostEditUpdate(void);
	virtual void __fastcall StartEditAutoHeight(bool AHeightChanged);
	virtual void __fastcall StartEditingByTimer(void) = 0 ;
	void __fastcall StartEditShowingTimer(void);
	virtual void __fastcall UninitEdit(void);
	virtual void __fastcall UpdateInplaceParamsPosition(void) = 0 ;
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	virtual System::Variant __fastcall GetValue(void) = 0 ;
	void __fastcall SetImmediatePostEventHandler(bool ASet);
	virtual void __fastcall SetValue(const System::Variant &AValue) = 0 ;
	void __fastcall UpdateEditValue(void);
	void __fastcall UpdateValue(void);
	virtual void __fastcall AssignOverridableEditEvents(void);
	virtual void __fastcall AssignStaticEditEvents(void);
	virtual void __fastcall UnassignEditEvents(void);
	virtual void __fastcall EditAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditChanged(System::TObject* Sender);
	virtual void __fastcall EditDblClick(System::TObject* Sender);
	virtual void __fastcall EditEditing(System::TObject* Sender, bool &CanEdit);
	virtual void __fastcall EditExit(System::TObject* Sender);
	virtual void __fastcall EditFocusChanged(System::TObject* Sender);
	virtual void __fastcall EditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditKeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall EditKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditPostEditValue(System::TObject* Sender);
	virtual void __fastcall EditValueChanged(System::TObject* Sender);
	__property TcxEditChangeEventsCatcher* ChangeEventsCatcher = {read=GetChangeEventsCatcher};
	__property bool EditHiding = {read=FEditHiding, nodefault};
	__property TcxInplaceEditList* EditList = {read=FEditList};
	__property Cxclasses::TcxTimer* EditShowingTimer = {read=FEditShowingTimer};
	__property bool EditPreparing = {read=FEditPreparing, nodefault};
	__property bool EditUpdateNeeded = {read=FEditUpdateNeeded, nodefault};
	__property bool HideEditOnExit = {read=GetHideEditOnExit, nodefault};
	__property bool InitiatingEditing = {read=FInitiatingEditing, nodefault};
	__property bool IsEditPlaced = {read=FIsEditPlaced, nodefault};
	__property bool IsErrorOnEditExit = {read=FIsErrorOnEditExit, nodefault};
	
public:
	__fastcall TcxCustomEditingController(System::Classes::TComponent* AEditorOwner);
	__fastcall virtual ~TcxCustomEditingController(void);
	virtual void __fastcall HideEdit(bool Accept);
	virtual void __fastcall RemoveEdit(TcxCustomEditProperties* AProperties);
	void __fastcall UpdateEdit(void);
	void __fastcall StopEditShowingTimer(void);
	__property TcxCustomEdit* Edit = {read=FEdit};
	__property System::Types::TRect FocusRectBounds = {read=GetFocusRectBounds};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxEditDefaultPrecision = System::Int8(0xf);
static const bool cxEditDefaultUseLeftAlignmentOnEditing = true;
extern PACKAGE System::Classes::TAlignment cxEditDefaultHorzAlignment;
extern PACKAGE TcxEditVertAlignment cxEditDefaultVertAlignment;
static const System::Int8 cxInplaceEditOffset = System::Int8(0x1);
static const System::Int8 ekDefault = System::Int8(0x0);
static const System::Int8 svBorderColor = System::Int8(0x0);
static const System::Int8 svBorderStyle = System::Int8(0x1);
static const System::Int8 svColor = System::Int8(0x2);
static const System::Int8 svEdges = System::Int8(0x3);
static const System::Int8 svFont = System::Int8(0x4);
static const System::Int8 svHotTrack = System::Int8(0x5);
static const System::Int8 svShadow = System::Int8(0x6);
static const System::Int8 svTextColor = System::Int8(0x7);
static const System::Int8 svTextStyle = System::Int8(0x8);
static const System::Int8 svTransparentBorder = System::Int8(0x9);
static const System::Int8 svButtonStyle = System::Int8(0xa);
static const System::Int8 svButtonTransparency = System::Int8(0xb);
static const System::Int8 svPopupBorderStyle = System::Int8(0xc);
static const System::Int8 svGradientButtons = System::Int8(0xd);
static const System::Int8 svGradient = System::Int8(0xe);
static const System::Int8 svGradientDirection = System::Int8(0xf);
static const System::Int8 cxEditStyleValueCount = System::Int8(0x10);
extern PACKAGE Cxedit__1 cxEditStyleValueNameA;
extern PACKAGE System::StaticArray<System::Types::TRect, 2> EditContentDefaultOffsets;
extern PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxEditBtnKind, 4> EditBtnKindToEditBtnPainterKind;
extern PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxButtonState, 4> EditBtnStateToButtonState;
extern PACKAGE System::StaticArray<Cxlookandfeelpainters::TcxEditBtnPosition, 2> EditBtnPositionMap;
static const System::Int8 ecpNone = System::Int8(-3);
static const System::Int8 ecpErrorIcon = System::Int8(-2);
static const System::Int8 ecpControl = System::Int8(-1);
static const System::Int8 ecpButton = System::Int8(0x0);
extern PACKAGE Vcl::Graphics::TBitmap* cxEditErrorIcon;
extern PACKAGE Vcl::Graphics::TBitmap* cxEditWarningIcon;
extern PACKAGE Vcl::Graphics::TBitmap* cxEditInfoIcon;
extern PACKAGE TcxEditSizeProperties DefaultcxEditSizeProperties;
extern PACKAGE System::Classes::TShiftState __fastcall ButtonToShift(System::Uitypes::TMouseButton Button);
extern PACKAGE void __fastcall CheckSize(System::Types::TSize &Size, const System::Types::TSize &ANewSize);
extern PACKAGE System::Classes::TShiftState __fastcall cxButtonToShift(Cxcontainer::TcxMouseButton Button);
extern PACKAGE bool __fastcall cxEditVarEquals(const System::Variant &V1, const System::Variant &V2);
extern PACKAGE TcxEditStyleController* __fastcall DefaultEditStyleController(void);
extern PACKAGE bool __fastcall EmulateStandardControlDrawing(void);
extern PACKAGE TcxEditRepository* __fastcall GetDefaultEditRepository(void);
extern PACKAGE Cxlookandfeels::TcxLookAndFeelKind __fastcall GetEditPopupWindowControlsLookAndFeelKind(TcxCustomEdit* AEdit);
extern PACKAGE System::Classes::TComponent* __fastcall GetOwnerComponent(System::Classes::TPersistent* APersistent);
extern PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall GetRegisteredEditProperties(void);
extern PACKAGE System::TObject* __fastcall GetStandaloneEventSender(TcxCustomEdit* AEdit);
extern PACKAGE bool __fastcall InternalVarEqualsExact(const System::Variant &V1, const System::Variant &V2);
extern PACKAGE bool __fastcall IsSpaceChar(char C)/* overload */;
extern PACKAGE bool __fastcall IsSpaceChar(System::WideChar C)/* overload */;
extern PACKAGE bool __fastcall NeedAssignRepositoryItem(TcxCustomEditProperties* AItemProperties, TcxEditRepositoryItem* ARepositoryItem, TcxCustomEditProperties* &AEditingProperties);
extern PACKAGE void __fastcall SendMouseEvent(Vcl::Controls::TWinControl* AReceiver, unsigned AMessage, System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
extern PACKAGE void __fastcall SendKeyDown(Vcl::Controls::TWinControl* AReceiver, System::Word Key, System::Classes::TShiftState Shift);
extern PACKAGE void __fastcall SendKeyPress(Vcl::Controls::TWinControl* AReceiver, System::WideChar Key);
extern PACKAGE void __fastcall SendKeyUp(Vcl::Controls::TWinControl* AReceiver, System::Word Key, System::Classes::TShiftState Shift);
extern PACKAGE void __fastcall SetStandardControlDrawingEmulationMode(bool AEmulate);
extern PACKAGE void __fastcall UniteRegions(Cxgraphics::TcxRegion* ADestRgn, Cxgraphics::TcxRegion* ASrcRgn);
}	/* namespace Cxedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDIT)
using namespace Cxedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditHPP
