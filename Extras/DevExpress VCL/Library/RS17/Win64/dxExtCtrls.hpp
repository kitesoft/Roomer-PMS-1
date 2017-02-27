// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxExtCtrls.pas' rev: 24.00 (Win64)

#ifndef DxextctrlsHPP
#define DxextctrlsHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxextctrls
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TdxGetBrushStyleNameEvent)(System::TObject* Sender, int Index, Vcl::Graphics::TBrushStyle AStyle, System::UnicodeString &AName);

class DELPHICLASS TdxPSBrushStyleCombo;
class PASCALIMPLEMENTATION TdxPSBrushStyleCombo : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	System::Uitypes::TColor FBrushColor;
	bool FEndEllipsis;
	bool FShowStyleName;
	TdxGetBrushStyleNameEvent FOnGetBrushStyleName;
	HIDESBASE Vcl::Graphics::TBrushStyle __fastcall GetStyle(int Index);
	int __fastcall GetStyleIndex(Vcl::Graphics::TBrushStyle Style);
	Vcl::Graphics::TBrushStyle __fastcall GetStyleValue(void);
	void __fastcall SetBrushColor(System::Uitypes::TColor Value);
	void __fastcall SetEndEllipsis(bool Value);
	void __fastcall SetShowStyleName(bool Value);
	void __fastcall SetStyleValue(Vcl::Graphics::TBrushStyle Value);
	void __fastcall RefreshItems(void);
	void __fastcall ResetItemHeight(void);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMRecreateWnd(Winapi::Messages::TMessage &Message);
	
protected:
	void __fastcall CalculateRects(const System::Types::TRect &R, /* out */ System::Types::TRect &ABrushRect, /* out */ System::Types::TRect &ATextRect);
	virtual void __fastcall CreateWnd(void);
	void __fastcall DoDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual void __fastcall DoGetStyleName(int Index, System::UnicodeString &AName);
	virtual System::UnicodeString __fastcall GetStyleName(int Index);
	
public:
	__fastcall virtual TdxPSBrushStyleCombo(System::Classes::TComponent* AOwner)/* overload */;
	__property int StyleIndexes[Vcl::Graphics::TBrushStyle Style] = {read=GetStyleIndex};
	__property System::UnicodeString StyleNames[int Index] = {read=GetStyleName};
	__property Vcl::Graphics::TBrushStyle Styles[int Index] = {read=GetStyle};
	
__published:
	__property Anchors = {default=3};
	__property BiDiMode;
	__property System::Uitypes::TColor BrushColor = {read=FBrushColor, write=SetBrushColor, default=-16777208};
	__property Vcl::Graphics::TBrushStyle BrushStyle = {read=GetStyleValue, write=SetStyleValue, default=0};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property DragCursor = {default=-12};
	__property Enabled = {default=1};
	__property bool EndEllipsis = {read=FEndEllipsis, write=SetEndEllipsis, default=0};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property bool ShowStyleName = {read=FShowStyleName, write=SetShowStyleName, default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property TdxGetBrushStyleNameEvent OnGetBrushStyleName = {read=FOnGetBrushStyleName, write=FOnGetBrushStyleName};
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TdxPSBrushStyleCombo(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxPSBrushStyleCombo(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSBrushStyleCombo(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


enum TdxEdgeBorder : unsigned char { ebLeft, ebTop, ebRight, ebBottom };

typedef System::Set<TdxEdgeBorder, TdxEdgeBorder::ebLeft, TdxEdgeBorder::ebBottom>  TdxEdgeBorders;

enum TdxEdgeStyle : unsigned char { esNone, esRaised, esSunken };

class DELPHICLASS TdxPSPaintPanel;
class PASCALIMPLEMENTATION TdxPSPaintPanel : public Vcl::Extctrls::TCustomPanel
{
	typedef Vcl::Extctrls::TCustomPanel inherited;
	
private:
	TdxEdgeBorders FEdgeBorders;
	TdxEdgeStyle FEdgeInner;
	TdxEdgeStyle FEdgeOuter;
	System::Classes::TNotifyEvent FOnMouseEnter;
	System::Classes::TNotifyEvent FOnMouseLeave;
	System::Classes::TNotifyEvent FOnPaint;
	TdxEdgeBorders __fastcall GetEdgeBorders(void);
	void __fastcall SetEdgeBorders(TdxEdgeBorders Value);
	void __fastcall SetEdgeInner(TdxEdgeStyle Value);
	void __fastcall SetEdgeOuter(TdxEdgeStyle Value);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall DoPaint(void);
	DYNAMIC void __fastcall DoMouseEnter(void);
	DYNAMIC void __fastcall DoMouseLeave(void);
	
public:
	__fastcall virtual TdxPSPaintPanel(System::Classes::TComponent* AOwner);
	__property Canvas;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragKind = {default=0};
	__property DoubleBuffered = {default=1};
	__property TdxEdgeBorders EdgeBorders = {read=GetEdgeBorders, write=SetEdgeBorders, default=15};
	__property TdxEdgeStyle EdgeInner = {read=FEdgeInner, write=SetEdgeInner, default=1};
	__property TdxEdgeStyle EdgeOuter = {read=FEdgeOuter, write=SetEdgeOuter, default=2};
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Ctl3D;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Visible = {default=1};
	__property System::Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property OnCanResize;
	__property OnConstrainedResize;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnMouseDown;
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TdxPSPaintPanel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSPaintPanel(HWND ParentWindow) : Vcl::Extctrls::TCustomPanel(ParentWindow) { }
	
};


class DELPHICLASS TdxPSBitmapAnimator;
class PASCALIMPLEMENTATION TdxPSBitmapAnimator : public Vcl::Controls::TGraphicControl
{
	typedef Vcl::Controls::TGraphicControl inherited;
	
private:
	int FAnimationSpeed;
	int FAnimationStepCount;
	Vcl::Graphics::TBitmap* FBitmap;
	bool FState;
	void __fastcall SetBitmap(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetState(bool Value);
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	DYNAMIC void __fastcall Animate(void);
	DYNAMIC void __fastcall StateChanged(void);
	
public:
	__fastcall virtual TdxPSBitmapAnimator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSBitmapAnimator(void);
	
__published:
	__property int AnimationSpeed = {read=FAnimationSpeed, write=FAnimationSpeed, default=10};
	__property int AnimationStepCount = {read=FAnimationStepCount, write=FAnimationStepCount, default=10};
	__property Vcl::Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap};
	__property bool State = {read=FState, write=SetState, default=0};
};


class DELPHICLASS TdxPSWarningPane;
class PASCALIMPLEMENTATION TdxPSWarningPane : public TdxPSBitmapAnimator
{
	typedef TdxPSBitmapAnimator inherited;
	
private:
	System::UnicodeString FHint;
	void __fastcall SetHint(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall InitializeBitmap(void);
	virtual void __fastcall InitializeBitmapHint(System::Types::TRect &R);
	DYNAMIC void __fastcall StateChanged(void);
	
public:
	__fastcall virtual TdxPSWarningPane(System::Classes::TComponent* AOwner);
	void __fastcall SetStateAndHint(bool NewState, const System::UnicodeString AHint);
	
__published:
	__property Font;
	__property System::UnicodeString Hint = {read=FHint, write=SetHint};
public:
	/* TdxPSBitmapAnimator.Destroy */ inline __fastcall virtual ~TdxPSWarningPane(void) { }
	
};


enum TdxPSImageScrollBoxBuiltInMenuItem : unsigned char { biiPreview, biiCopy, biiSave };

typedef System::Set<TdxPSImageScrollBoxBuiltInMenuItem, TdxPSImageScrollBoxBuiltInMenuItem::biiPreview, TdxPSImageScrollBoxBuiltInMenuItem::biiSave>  TdxPSImageScrollBoxBuiltInMenuItems;

class DELPHICLASS TdxPSImageScrollBox;
class PASCALIMPLEMENTATION TdxPSImageScrollBox : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Cxgraphics::TcxImageList* FBuiltInImages;
	Vcl::Menus::TPopupMenu* FBuiltInMenu;
	TdxPSImageScrollBoxBuiltInMenuItems FBuiltInMenuItemsVisibility;
	bool FCenter;
	System::UnicodeString FHintText;
	bool FIsGraphicInvalid;
	Vcl::Graphics::TPicture* FPicture;
	int FPictureOriginX;
	int FPictureOriginY;
	System::Uitypes::TColor __fastcall GetContentColor(void);
	System::Uitypes::TColor __fastcall GetContentTextColor(void);
	bool __fastcall GetHasGraphic(void);
	bool __fastcall GetIsPictureHeightExceedControlBounds(void);
	bool __fastcall GetIsPictureWidthExceedControlBounds(void);
	int __fastcall GetPictureHeight(void);
	System::Types::TRect __fastcall GetPictureRect(void);
	int __fastcall GetPictureWidth(void);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetHintText(const System::UnicodeString Value);
	void __fastcall SetPicture(Vcl::Graphics::TPicture* Value);
	void __fastcall SetPictureOriginX(int AValue);
	void __fastcall SetPictureOriginY(int AValue);
	void __fastcall BuiltInMenuPopup(System::TObject* Sender);
	void __fastcall CopyClick(System::TObject* Sender);
	void __fastcall SaveClick(System::TObject* Sender);
	void __fastcall PreviewClick(System::TObject* Sender);
	void __fastcall PictureChanged(System::TObject* Sender);
	
protected:
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miPreview;
	Vcl::Menus::TMenuItem* miSave;
	int __fastcall CheckPictureOriginX(int AValue);
	int __fastcall CheckPictureOriginY(int AValue);
	virtual void __fastcall CreateBuiltInImages(void);
	virtual void __fastcall CreateBuiltInMenu(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawHintText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ATextRect);
	virtual void __fastcall DrawPicture(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollHorizontal(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollVertical(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall UpdatePicturePosition(void);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	__property System::Uitypes::TColor ContentColor = {read=GetContentColor, nodefault};
	__property System::Uitypes::TColor ContentTextColor = {read=GetContentTextColor, nodefault};
	__property bool IsPictureHeightExceedControlBounds = {read=GetIsPictureHeightExceedControlBounds, nodefault};
	__property bool IsPictureWidthExceedControlBounds = {read=GetIsPictureWidthExceedControlBounds, nodefault};
	__property int PictureHeight = {read=GetPictureHeight, nodefault};
	__property int PictureOriginX = {read=FPictureOriginX, write=SetPictureOriginX, nodefault};
	__property int PictureOriginY = {read=FPictureOriginY, write=SetPictureOriginY, nodefault};
	__property System::Types::TRect PictureRect = {read=GetPictureRect};
	__property int PictureWidth = {read=GetPictureWidth, nodefault};
	
public:
	__fastcall virtual TdxPSImageScrollBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSImageScrollBox(void);
	__property Cxgraphics::TcxImageList* BuiltInImages = {read=FBuiltInImages};
	__property Vcl::Menus::TPopupMenu* BuiltInMenu = {read=FBuiltInMenu};
	__property TdxPSImageScrollBoxBuiltInMenuItems BuiltInMenuItemsVisibility = {read=FBuiltInMenuItemsVisibility, write=FBuiltInMenuItemsVisibility, default=7};
	__property bool HasGraphic = {read=GetHasGraphic, nodefault};
	
__published:
	__property bool Center = {read=FCenter, write=SetCenter, default=1};
	__property Color = {default=-16777211};
	__property System::UnicodeString HintText = {read=FHintText, write=SetHintText};
	__property OnClick;
	__property OnDblClick;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property Vcl::Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property PopupMenu;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSImageScrollBox(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


enum TdxPSValueType : unsigned char { ivtDecimal, ivtLiteral, ivtCapitalLiteral, ivtRoman, ivtCapitalRoman };

class DELPHICLASS TdxPSValueEdit;
class PASCALIMPLEMENTATION TdxPSValueEdit : public Cxspinedit::TcxSpinEdit
{
	typedef Cxspinedit::TcxSpinEdit inherited;
	
private:
	TdxPSValueType FValueType;
	System::Variant __fastcall DisplayValueToEditValue(const System::Variant &AValue);
	System::Variant __fastcall EditValueToDisplayValue(const System::Variant &AValue);
	void __fastcall SetValueType(TdxPSValueType AValueType);
	
protected:
	virtual void __fastcall DoValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual System::UnicodeString __fastcall IncrementValueToStr(const System::Variant &AValue);
	virtual bool __fastcall IsValidChar(System::WideChar Key);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	
public:
	__fastcall virtual TdxPSValueEdit(System::Classes::TComponent* AOwner)/* overload */;
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TdxPSValueType ValueType = {read=FValueType, write=SetValueType, default=0};
public:
	/* TcxCustomSpinEdit.Destroy */ inline __fastcall virtual ~TdxPSValueEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TdxPSValueEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxspinedit::TcxSpinEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSValueEdit(HWND ParentWindow) : Cxspinedit::TcxSpinEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool UseAllColorValuesInDropDownList;
extern PACKAGE Cxgraphics::TcxBitmap32* __fastcall WarningSignBitmap(void);
}	/* namespace Dxextctrls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXEXTCTRLS)
using namespace Dxextctrls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxextctrlsHPP
