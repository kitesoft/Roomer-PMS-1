// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImage.pas' rev: 24.00 (Win32)

#ifndef CximageHPP
#define CximageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cximage
{
//-- type declarations -------------------------------------------------------
enum TcxPopupMenuItem : unsigned char { pmiCut, pmiCopy, pmiPaste, pmiDelete, pmiLoad, pmiSave, pmiCustom };

typedef void __fastcall (__closure *TcxPopupMenuItemClick)(System::TObject* Sender, TcxPopupMenuItem MenuItem);

typedef System::Set<TcxPopupMenuItem, TcxPopupMenuItem::pmiCut, TcxPopupMenuItem::pmiCustom>  TcxPopupMenuItems;

class DELPHICLASS TcxPopupMenuLayout;
class DELPHICLASS TcxCustomImage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPopupMenuLayout : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FCustomMenuItemCaption;
	Vcl::Graphics::TBitmap* FCustomMenuItemGlyph;
	TcxCustomImage* FImage;
	TcxPopupMenuItems FMenuItems;
	virtual Vcl::Graphics::TBitmap* __fastcall GetCustomMenuItemGlyph(void);
	void __fastcall SetCustomMenuItemGlyph(Vcl::Graphics::TBitmap* Value);
	
public:
	__fastcall TcxPopupMenuLayout(TcxCustomImage* AImage);
	__fastcall virtual ~TcxPopupMenuLayout(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxPopupMenuItems MenuItems = {read=FMenuItems, write=FMenuItems, default=63};
	__property System::UnicodeString CustomMenuItemCaption = {read=FCustomMenuItemCaption, write=FCustomMenuItemCaption};
	__property Vcl::Graphics::TBitmap* CustomMenuItemGlyph = {read=GetCustomMenuItemGlyph, write=SetCustomMenuItemGlyph};
};

#pragma pack(pop)

class DELPHICLASS TcxImageViewInfo;
class PASCALIMPLEMENTATION TcxImageViewInfo : public Cxedit::TcxCustomEditViewInfo
{
	typedef Cxedit::TcxCustomEditViewInfo inherited;
	
private:
	bool FFreePicture;
	Dxskinscore::TdxSkinImage* FZoomButtons;
	System::Types::TRect FZoomInButtonRect;
	System::Types::TRect FZoomOutButtonRect;
	void __fastcall DrawTransparentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	
protected:
	virtual void __fastcall DrawZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall IsRepaintOnStateChangingNeeded(void);
	bool __fastcall GetRealStretch(void);
	
public:
	bool ShowFocusRect;
	System::Types::TPoint TopLeft;
	System::UnicodeString Caption;
	bool Center;
	Vcl::Graphics::TPicture* Picture;
	Cxgraphics::TcxImageFitMode FitMode;
	int Scale;
	bool Scalable;
	__fastcall virtual ~TcxImageViewInfo(void);
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxImageViewInfo(void) : Cxedit::TcxCustomEditViewInfo() { }
	
};


class DELPHICLASS TcxImageViewData;
class PASCALIMPLEMENTATION TcxImageViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxImageViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxImageViewData(void) { }
	
};


typedef void __fastcall (__closure *TcxImageAssignPictureEvent)(System::TObject* Sender, Vcl::Graphics::TPicture* const Picture);

typedef void __fastcall (__closure *TcxImageGraphicClassEvent)(System::TObject* AItem, int ARecordIndex, bool APastingFromClipboard, Vcl::Graphics::TGraphicClass &AGraphicClass);

typedef void __fastcall (__closure *TcxImageEditGraphicClassEvent)(System::TObject* Sender, bool APastingFromClipboard, Vcl::Graphics::TGraphicClass &AGraphicClass);

enum TcxImageTransparency : unsigned char { gtDefault, gtOpaque, gtTransparent };

class DELPHICLASS TcxCustomImageProperties;
class PASCALIMPLEMENTATION TcxCustomImageProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	System::UnicodeString FCaption;
	System::UnicodeString FCustomFilter;
	int FDefaultHeight;
	Vcl::Graphics::TGraphicClass FGraphicClass;
	TcxImageTransparency FGraphicTransparency;
	bool FNeedUpdateImage;
	TcxPopupMenuLayout* FPopupMenuLayout;
	bool FShowFocusRect;
	bool FCenter;
	Cxgraphics::TcxImageFitMode FFitMode;
	TcxImageAssignPictureEvent FOnAssignPicture;
	System::Classes::TNotifyEvent FOnCustomClick;
	TcxImageGraphicClassEvent FOnGetGraphicClass;
	System::UnicodeString __fastcall GetGraphicClassName(void);
	bool __fastcall IsGraphicClassNameStored(void);
	void __fastcall ReadIsGraphicClassNameEmpty(System::Classes::TReader* Reader);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetGraphicClass(const Vcl::Graphics::TGraphicClass Value);
	void __fastcall SetGraphicClassName(const System::UnicodeString Value);
	void __fastcall SetGraphicTransparency(TcxImageTransparency Value);
	void __fastcall SetPopupMenuLayout(TcxPopupMenuLayout* Value);
	void __fastcall SetShowFocusRect(bool Value);
	void __fastcall WriteIsGraphicClassNameEmpty(System::Classes::TWriter* Writer);
	Cxgraphics::TcxImageFitMode __fastcall CalculateFitMode(bool AProportional, bool AStretch);
	bool __fastcall GetProportional(void);
	bool __fastcall GetStretch(void);
	void __fastcall SetCenter(bool AValue);
	void __fastcall SetProportional(bool AValue);
	void __fastcall SetStretch(bool AValue);
	void __fastcall SetFitMode(Cxgraphics::TcxImageFitMode AValue);
	
protected:
	virtual bool __fastcall CanValidate(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	HIDESBASE bool __fastcall IsDesigning(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetDefaultGraphicClass(void);
	bool __fastcall GetRealStretch(const System::Types::TSize &APictureSize, const System::Types::TSize &ABoundsSize);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	bool __fastcall IsScrollbarsNeeded(Vcl::Graphics::TPicture* APicture);
	__property int DefaultHeight = {read=FDefaultHeight, write=FDefaultHeight, default=15};
	__property Cxgraphics::TcxImageFitMode FitMode = {read=FFitMode, write=SetFitMode, nodefault};
	
public:
	__fastcall virtual TcxCustomImageProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomImageProperties(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(System::TObject* AItem, int ARecordIndex, bool APastingFromClipboard = false);
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsResetEditClass(void);
	virtual void __fastcall ValidateDisplayValue(System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error, Cxedit::TcxCustomEdit* AEdit);
	__property Vcl::Graphics::TGraphicClass GraphicClass = {read=FGraphicClass, write=SetGraphicClass};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property bool Center = {read=FCenter, write=SetCenter, default=1};
	__property System::UnicodeString CustomFilter = {read=FCustomFilter, write=FCustomFilter};
	__property System::UnicodeString GraphicClassName = {read=GetGraphicClassName, write=SetGraphicClassName, stored=IsGraphicClassNameStored};
	__property TcxImageTransparency GraphicTransparency = {read=FGraphicTransparency, write=SetGraphicTransparency, default=0};
	__property TcxPopupMenuLayout* PopupMenuLayout = {read=FPopupMenuLayout, write=SetPopupMenuLayout};
	__property bool Proportional = {read=GetProportional, write=SetProportional, default=1};
	__property bool ShowFocusRect = {read=FShowFocusRect, write=SetShowFocusRect, default=1};
	__property bool Stretch = {read=GetStretch, write=SetStretch, default=0};
	__property TcxImageAssignPictureEvent OnAssignPicture = {read=FOnAssignPicture, write=FOnAssignPicture};
	__property System::Classes::TNotifyEvent OnCustomClick = {read=FOnCustomClick, write=FOnCustomClick};
	__property TcxImageGraphicClassEvent OnGetGraphicClass = {read=FOnGetGraphicClass, write=FOnGetGraphicClass};
};


class DELPHICLASS TcxImageProperties;
class PASCALIMPLEMENTATION TcxImageProperties : public TcxCustomImageProperties
{
	typedef TcxCustomImageProperties inherited;
	
__published:
	__property AssignedValues;
	__property Caption = {default=0};
	__property Center = {default=1};
	__property ClearKey = {default=0};
	__property CustomFilter = {default=0};
	__property GraphicClassName = {default=0};
	__property GraphicTransparency = {default=0};
	__property ImmediatePost = {default=0};
	__property PopupMenuLayout;
	__property Proportional = {default=1};
	__property ReadOnly;
	__property ShowFocusRect = {default=1};
	__property Stretch = {default=0};
	__property OnAssignPicture;
	__property OnChange;
	__property OnCustomClick;
	__property OnEditValueChanged;
	__property OnGetGraphicClass;
public:
	/* TcxCustomImageProperties.Create */ inline __fastcall virtual TcxImageProperties(System::Classes::TPersistent* AOwner) : TcxCustomImageProperties(AOwner) { }
	/* TcxCustomImageProperties.Destroy */ inline __fastcall virtual ~TcxImageProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomImage : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	System::Word FClipboardFormat;
	Vcl::Menus::TPopupMenu* FEditPopupMenu;
	bool FIsDialogShowed;
	Vcl::Graphics::TPicture* FPicture;
	TcxImageEditGraphicClassEvent FOnGetGraphicClass;
	System::Types::TPoint FLastDragPos;
	int FMaxScale;
	int FMinScale;
	bool FScalable;
	int FScale;
	bool FAllowUserChangeScale;
	bool __fastcall CanScaleByMouseWheel(System::Classes::TShiftState AShift, const System::Types::TPoint &AMousePos);
	void __fastcall EditAndClear(void);
	void __fastcall EditPopupMenuClick(System::TObject* Sender);
	TcxCustomImageProperties* __fastcall GetProperties(void);
	HIDESBASE TcxImageViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE TcxCustomImageProperties* __fastcall GetActiveProperties(void);
	void __fastcall MenuItemClick(System::TObject* Sender, TcxPopupMenuItem MenuItem);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall PreparePopup(void);
	void __fastcall SetPicture(Vcl::Graphics::TPicture* Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomImageProperties* const Value);
	int __fastcall GetCurrentScale(void);
	void __fastcall SetScalable(bool AValue);
	void __fastcall SetScale(int AValue);
	
protected:
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual bool __fastcall CanAutoSize(void);
	virtual bool __fastcall CanAutoWidth(void);
	DYNAMIC void __fastcall DoContextPopup(const System::Types::TPoint &MousePos, bool &Handled);
	virtual int __fastcall GetDefaultPanOptions(void);
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsInvokeAfterKeyDown(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall Initialize(void);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AIsValueValid);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	DYNAMIC void __fastcall BoundsChanged(void);
	int __fastcall GetLeftPos(void);
	void __fastcall SetLeftPos(int Value);
	int __fastcall GetTopPos(void);
	void __fastcall SetTopPos(int Value);
	System::Types::TSize __fastcall GetContentSize(void);
	System::Types::TSize __fastcall GetClientSize(void);
	Cxcontrols::TcxControl* __fastcall GetInstance(void);
	void __fastcall Zoom(int ADelta, bool &AHandled);
	void __fastcall Centre(void);
	void __fastcall CheckScrollbars(bool AResetPosition = false);
	virtual void __fastcall InitScrollBarsParameters(void);
	bool __fastcall IsScrollbarsNeeded(void);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall CanPasteFromClipboard(void);
	virtual void __fastcall CustomClick(void);
	void __fastcall DoOnAssignPicture(void);
	virtual void __fastcall DoPictureLoadedFromFile(System::UnicodeString AFileName);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(bool APastingFromClipboard = false);
	__property AutoSize = {default=0};
	__property ParentColor = {default=0};
	__property TcxImageEditGraphicClassEvent OnGetGraphicClass = {read=FOnGetGraphicClass, write=FOnGetGraphicClass};
	__property bool IsDialogShowed = {read=FIsDialogShowed, nodefault};
	__property int MaxScale = {read=FMaxScale, write=FMaxScale, nodefault};
	__property int MinScale = {read=FMinScale, write=FMinScale, nodefault};
	__property bool Scalable = {read=FScalable, write=SetScalable, nodefault};
	__property int Scale = {read=FScale, write=SetScale, nodefault};
	__property bool AllowUserChangeScale = {read=FAllowUserChangeScale, write=FAllowUserChangeScale, nodefault};
	
public:
	__fastcall virtual TcxCustomImage(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomImage(void);
	virtual void __fastcall CopyToClipboard(void);
	virtual void __fastcall CutToClipboard(void);
	DYNAMIC bool __fastcall Focused(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	void __fastcall LoadFromFile(void);
	virtual void __fastcall PasteFromClipboard(void);
	void __fastcall SaveToFile(void);
	__property TcxCustomImageProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::Word ClipboardFormat = {read=FClipboardFormat, write=FClipboardFormat, nodefault};
	__property Vcl::Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property TcxCustomImageProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TcxImageViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomImage(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomImage(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
private:
	void *__IdxZoomClient;	/* Dxtouch::IdxZoomClient */
	void *__IdxScrollingControl;	/* Cxcontrols::IdxScrollingControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B3A0623E-D155-462F-B234-22E9CFC6BFBF}
	operator Dxtouch::_di_IdxZoomClient()
	{
		Dxtouch::_di_IdxZoomClient intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxZoomClient*(void) { return (Dxtouch::IdxZoomClient*)&__IdxZoomClient; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7F141990-5975-4E6B-BFAF-03D378860F20}
	operator Cxcontrols::_di_IdxScrollingControl()
	{
		Cxcontrols::_di_IdxScrollingControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IdxScrollingControl*(void) { return (Cxcontrols::IdxScrollingControl*)&__IdxScrollingControl; }
	#endif
	
};


class DELPHICLASS TcxImage;
class PASCALIMPLEMENTATION TcxImage : public TcxCustomImage
{
	typedef TcxCustomImage inherited;
	
private:
	HIDESBASE TcxImageProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxImageProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxImageProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxImageProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=0};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property ParentShowHint = {default=1};
	__property Picture;
	__property PopupMenu;
	__property TcxImageProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetGraphicClass;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomImage.Create */ inline __fastcall virtual TcxImage(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomImage(AOwner) { }
	/* TcxCustomImage.Destroy */ inline __fastcall virtual ~TcxImage(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxImage(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomImage(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxImage(HWND ParentWindow) : TcxCustomImage(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxImageDefaultInplaceHeight = System::Int8(0xf);
extern PACKAGE Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassByName(const System::UnicodeString AClassName);
extern PACKAGE System::Classes::TList* __fastcall GetRegisteredGraphicClasses(void);
extern PACKAGE void __fastcall RegisterGraphicClass(Vcl::Graphics::TGraphicClass AGraphicClass);
extern PACKAGE void __fastcall UnRegisterGraphicClass(Vcl::Graphics::TGraphicClass AGraphicClass);
extern PACKAGE void __fastcall LoadPicture(Vcl::Graphics::TPicture* APicture, Vcl::Graphics::TGraphicClass AGraphicClass, const System::Variant &AValue);
extern PACKAGE void __fastcall SavePicture(Vcl::Graphics::TPicture* APicture, System::AnsiString &AValue);
}	/* namespace Cximage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMAGE)
using namespace Cximage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximageHPP
