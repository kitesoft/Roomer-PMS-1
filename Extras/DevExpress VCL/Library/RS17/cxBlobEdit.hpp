// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxBlobEdit.pas' rev: 24.00 (Win32)

#ifndef CxblobeditHPP
#define CxblobeditHPP

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
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxblobedit
{
//-- type declarations -------------------------------------------------------
enum TcxBlobPaintStyle : unsigned char { bpsDefault, bpsIcon, bpsText };

enum TcxBlobEditKind : unsigned char { bekAuto, bekMemo, bekPict, bekOle, bekBlob };

class DELPHICLASS TcxBlobEditViewData;
class PASCALIMPLEMENTATION TcxBlobEditViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
protected:
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual void __fastcall PrepareDrawTextFlags(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxBlobEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxBlobEditViewData(void) { }
	
};


class DELPHICLASS TcxBlobEditViewInfo;
class PASCALIMPLEMENTATION TcxBlobEditViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
protected:
	virtual Cxedit::TcxEditBackgroundPaintingStyle __fastcall GetBackgroundPaintingStyle(void);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	System::Types::TRect IconRect;
	System::Uitypes::TImageIndex ImageIndex;
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Offset(int DX, int DY);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxBlobEditViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxBlobEditViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class DELPHICLASS TcxCustomBlobEditProperties;
class PASCALIMPLEMENTATION TcxCustomBlobEditProperties : public Cxdropdownedit::TcxCustomPopupEditProperties
{
	typedef Cxdropdownedit::TcxCustomPopupEditProperties inherited;
	
private:
	bool FAlwaysSaveData;
	bool FApplyStyleToButtons;
	TcxBlobEditKind FBlobEditKind;
	TcxBlobPaintStyle FBlobPaintStyle;
	bool FMemoAutoReplace;
	bool FMemoWantReturns;
	bool FMemoWantTabs;
	bool FMemoOEMConvert;
	bool FMemoWordWrap;
	int FMemoMaxLength;
	System::Uitypes::TEditCharCase FMemoCharCase;
	System::Uitypes::TScrollStyle FMemoScrollBars;
	bool FPictureAutoSize;
	System::Word FPictureClipboardFormat;
	System::UnicodeString FPictureFilter;
	Vcl::Graphics::TGraphicClass FPictureGraphicClass;
	Cximage::TcxImageTransparency FPictureTransparency;
	bool FShowExPopupItems;
	bool FShowPicturePopup;
	Cximage::TcxImageAssignPictureEvent FOnAssignPicture;
	Cximage::TcxImageGraphicClassEvent FOnGetGraphicClass;
	System::UnicodeString __fastcall GetPictureGraphicClassName(void);
	bool __fastcall IsPictureGraphicClassNameStored(void);
	void __fastcall ReadIsPictureGraphicClassNameEmpty(System::Classes::TReader* Reader);
	void __fastcall SetBlobEditKind(const TcxBlobEditKind Value);
	void __fastcall SetBlobPaintStyle(const TcxBlobPaintStyle Value);
	void __fastcall SetPictureGraphicClass(Vcl::Graphics::TGraphicClass Value);
	void __fastcall SetPictureGraphicClassName(const System::UnicodeString Value);
	void __fastcall WriteIsPictureGraphicClassNameEmpty(System::Classes::TWriter* Writer);
	
protected:
	virtual bool __fastcall CanValidate(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual bool __fastcall DropDownOnClick(void);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	__classmethod virtual Cxdropdownedit::TcxCustomEditPopupWindowClass __fastcall GetPopupWindowClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	void __fastcall CorrectBlobEditKind(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetDefaultPictureGraphicClass(void);
	Vcl::Graphics::TGraphicClass __fastcall GetPictureGraphicClass(System::TObject* AItem, int ARecordIndex, bool APastingFromClipboard = false);
	__property bool ApplyStyleToButtons = {read=FApplyStyleToButtons, write=FApplyStyleToButtons, nodefault};
	__property System::Word PictureClipboardFormat = {read=FPictureClipboardFormat, write=FPictureClipboardFormat, nodefault};
	
public:
	__fastcall virtual TcxCustomBlobEditProperties(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &AEditValue, bool AEditFocused);
	__property Vcl::Graphics::TGraphicClass PictureGraphicClass = {read=FPictureGraphicClass, write=SetPictureGraphicClass};
	__property bool AlwaysSaveData = {read=FAlwaysSaveData, write=FAlwaysSaveData, default=1};
	__property TcxBlobEditKind BlobEditKind = {read=FBlobEditKind, write=SetBlobEditKind, default=0};
	__property TcxBlobPaintStyle BlobPaintStyle = {read=FBlobPaintStyle, write=SetBlobPaintStyle, default=1};
	__property ImmediateDropDownWhenActivated = {default=1};
	__property bool MemoAutoReplace = {read=FMemoAutoReplace, write=FMemoAutoReplace, default=0};
	__property System::Uitypes::TEditCharCase MemoCharCase = {read=FMemoCharCase, write=FMemoCharCase, default=0};
	__property int MemoMaxLength = {read=FMemoMaxLength, write=FMemoMaxLength, default=0};
	__property bool MemoOEMConvert = {read=FMemoOEMConvert, write=FMemoOEMConvert, default=0};
	__property System::Uitypes::TScrollStyle MemoScrollBars = {read=FMemoScrollBars, write=FMemoScrollBars, default=0};
	__property bool MemoWantReturns = {read=FMemoWantReturns, write=FMemoWantReturns, default=1};
	__property bool MemoWantTabs = {read=FMemoWantTabs, write=FMemoWantTabs, default=1};
	__property bool MemoWordWrap = {read=FMemoWordWrap, write=FMemoWordWrap, default=1};
	__property bool PictureAutoSize = {read=FPictureAutoSize, write=FPictureAutoSize, default=1};
	__property System::UnicodeString PictureFilter = {read=FPictureFilter, write=FPictureFilter};
	__property System::UnicodeString PictureGraphicClassName = {read=GetPictureGraphicClassName, write=SetPictureGraphicClassName, stored=IsPictureGraphicClassNameStored};
	__property Cximage::TcxImageTransparency PictureTransparency = {read=FPictureTransparency, write=FPictureTransparency, default=0};
	__property bool ShowExPopupItems = {read=FShowExPopupItems, write=FShowExPopupItems, default=1};
	__property bool ShowPicturePopup = {read=FShowPicturePopup, write=FShowPicturePopup, default=1};
	__property Cximage::TcxImageAssignPictureEvent OnAssignPicture = {read=FOnAssignPicture, write=FOnAssignPicture};
	__property Cximage::TcxImageGraphicClassEvent OnGetGraphicClass = {read=FOnGetGraphicClass, write=FOnGetGraphicClass};
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomBlobEditProperties(void) { }
	
};


class DELPHICLASS TcxBlobEditProperties;
class PASCALIMPLEMENTATION TcxBlobEditProperties : public TcxCustomBlobEditProperties
{
	typedef TcxCustomBlobEditProperties inherited;
	
__published:
	__property AlwaysSaveData = {default=1};
	__property AssignedValues;
	__property BlobEditKind = {default=0};
	__property BlobPaintStyle = {default=1};
	__property ClearKey = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=1};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property MemoAutoReplace = {default=0};
	__property MemoCharCase = {default=0};
	__property MemoMaxLength = {default=0};
	__property MemoOEMConvert = {default=0};
	__property MemoScrollBars = {default=0};
	__property MemoWantReturns = {default=1};
	__property MemoWantTabs = {default=1};
	__property MemoWordWrap = {default=1};
	__property PictureAutoSize = {default=1};
	__property PictureFilter = {default=0};
	__property PictureGraphicClassName = {default=0};
	__property PictureTransparency = {default=0};
	__property PopupHeight = {default=200};
	__property PopupWidth = {default=250};
	__property ReadOnly;
	__property ShowExPopupItems = {default=1};
	__property ShowPicturePopup = {default=1};
	__property ValidationOptions = {default=1};
	__property OnAssignPicture;
	__property OnButtonClick;
	__property OnChange;
	__property OnCloseQuery;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnGetGraphicClass;
	__property OnInitPopup;
	__property OnPopup;
	__property OnValidate;
public:
	/* TcxCustomBlobEditProperties.Create */ inline __fastcall virtual TcxBlobEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomBlobEditProperties(AOwner) { }
	
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxBlobEditProperties(void) { }
	
};


class DELPHICLASS TcxCustomBlobEdit;
class PASCALIMPLEMENTATION TcxCustomBlobEdit : public Cxdropdownedit::TcxCustomPopupEdit
{
	typedef Cxdropdownedit::TcxCustomPopupEdit inherited;
	
private:
	int FButtonWidth;
	Cxbuttons::TcxButton* FCancelButton;
	Vcl::Graphics::TGraphicClass FGraphicClass;
	Cxbuttons::TcxButton* FOkButton;
	Cxedit::TcxCustomEdit* FStorage;
	Cximage::TcxImageEditGraphicClassEvent FOnGetGraphicClass;
	void __fastcall DoPopupImageGetGraphicClass(System::TObject* Sender, bool APastingFromClipboard, Vcl::Graphics::TGraphicClass &AGraphicClass);
	void __fastcall DoPopupImagePropertiesGetGraphicClass(System::TObject* AItem, int ARecordIndex, bool APastingFromClipboard, Vcl::Graphics::TGraphicClass &AGraphicClass);
	HIDESBASE TcxCustomBlobEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCustomBlobEditProperties* __fastcall GetProperties(void);
	void __fastcall InternalChanged(System::TObject* Sender);
	void __fastcall PictureClosePopup(Cxcontrols::TcxControl* Sender, Cxedit::TcxEditCloseUpReason AReason);
	void __fastcall SaveStorage(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomBlobEditProperties* Value);
	
protected:
	DYNAMIC void __fastcall ColorChanged(void);
	virtual void __fastcall CreatePopupControls(void);
	void __fastcall DoAssignPicture(void);
	void __fastcall DoOnAssignPicture(Vcl::Graphics::TPicture* APicture);
	DYNAMIC void __fastcall FontChanged(void);
	virtual System::UnicodeString __fastcall GetDisplayValue(void);
	virtual System::Variant __fastcall GetEditingValue(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetPopupFocusedControl(void);
	virtual System::Types::TSize __fastcall GetPopupWindowClientPreferredSize(void);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual void __fastcall DestroyPopupControls(void);
	virtual void __fastcall DoInitPopup(void);
	virtual void __fastcall DoFinalizePopup(void);
	Vcl::Graphics::TGraphicClass __fastcall GetPictureGraphicClass(bool APastingFromClipboard = false);
	virtual void __fastcall Initialize(void);
	virtual System::UnicodeString __fastcall InternalGetText(void);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	DYNAMIC void __fastcall PopupWindowClosed(System::TObject* Sender);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall SetEditingText(const Vcl::Controls::TCaption Value);
	virtual void __fastcall SetupPopupWindow(void);
	virtual void __fastcall StorageEditingHandler(System::TObject* Sender, bool &CanEdit);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeEditValue(void);
	__property TabStop = {default=1};
	__property Cximage::TcxImageEditGraphicClassEvent OnGetGraphicClass = {read=FOnGetGraphicClass, write=FOnGetGraphicClass};
	
public:
	__fastcall virtual ~TcxCustomBlobEdit(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall IsEditClass(void);
	__property TcxCustomBlobEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomBlobEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomBlobEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomBlobEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomBlobEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomPopupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxBlobEdit;
class PASCALIMPLEMENTATION TcxBlobEdit : public TcxCustomBlobEdit
{
	typedef TcxCustomBlobEdit inherited;
	
private:
	HIDESBASE TcxBlobEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxBlobEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxBlobEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxBlobEditProperties* ActiveProperties = {read=GetActiveProperties};
	
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
	__property TcxBlobEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property BiDiMode;
	__property ParentBiDiMode = {default=1};
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TcxCustomBlobEdit.Destroy */ inline __fastcall virtual ~TcxBlobEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxBlobEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomBlobEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxBlobEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomBlobEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBlobEdit(HWND ParentWindow) : TcxCustomBlobEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterBlobEditHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterBlobEditHelper : public Cxtextedit::TcxFilterTextEditHelper
{
	typedef Cxtextedit::TcxFilterTextEditHelper inherited;
	
public:
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
public:
	/* TObject.Create */ inline __fastcall TcxFilterBlobEditHelper(void) : Cxtextedit::TcxFilterTextEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterBlobEditHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBlobEditPopupWindow;
class PASCALIMPLEMENTATION TcxBlobEditPopupWindow : public Cxdropdownedit::TcxPopupEditPopupWindow
{
	typedef Cxdropdownedit::TcxPopupEditPopupWindow inherited;
	
protected:
	virtual void __fastcall DoPopupControlKey(System::WideChar Key);
public:
	/* TcxCustomEditPopupWindow.Create */ inline __fastcall virtual TcxBlobEditPopupWindow(Vcl::Controls::TWinControl* AOwnerControl) : Cxdropdownedit::TcxPopupEditPopupWindow(AOwnerControl) { }
	/* TcxCustomEditPopupWindow.Destroy */ inline __fastcall virtual ~TcxBlobEditPopupWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxBlobEditPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxdropdownedit::TcxPopupEditPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBlobEditPopupWindow(HWND ParentWindow) : Cxdropdownedit::TcxPopupEditPopupWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxgraphics::TcxImageList* imgBlobImages;
extern PACKAGE System::WideString __fastcall GetBlobText(const System::Variant &Value, TcxCustomBlobEditProperties* AProperties, bool AFullText);
}	/* namespace Cxblobedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXBLOBEDIT)
using namespace Cxblobedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxblobeditHPP
