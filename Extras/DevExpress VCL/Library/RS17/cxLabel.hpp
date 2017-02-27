// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLabel.pas' rev: 24.00 (Win32)

#ifndef CxlabelHPP
#define CxlabelHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlabel
{
//-- type declarations -------------------------------------------------------
enum TcxLabelEffect : unsigned char { cxleNormal, cxleFun, cxleExtrude, cxleCool };

enum TcxLabelLineAlignment : unsigned char { cxllaTop, cxllaCenter, cxllaBottom };

enum TcxLabelStyle : unsigned char { cxlsNormal, cxlsRaised, cxlsLowered, cxlsOutLine };

enum TcxLabelOrientation : unsigned char { cxoLeft, cxoRight, cxoTop, cxoBottom, cxoLeftTop, cxoLeftBottom, cxoRightTop, cxoRightBottom };

class DELPHICLASS TcxLabelEditStyle;
class PASCALIMPLEMENTATION TcxLabelEditStyle : public Cxedit::TcxEditStyle
{
	typedef Cxedit::TcxEditStyle inherited;
	
protected:
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall DefaultBorderStyle(void);
	virtual bool __fastcall DefaultHotTrack(void);
public:
	/* TcxCustomEditStyle.Create */ inline __fastcall virtual TcxLabelEditStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, Cxcontainer::TcxContainerStyle* AParentStyle, Cxcontainer::TcxContainerStateItem AState) : Cxedit::TcxEditStyle(AOwner, ADirectAccessMode, AParentStyle, AState) { }
	
public:
	/* TcxContainerStyle.Destroy */ inline __fastcall virtual ~TcxLabelEditStyle(void) { }
	
};


class DELPHICLASS TcxLabelLineOptions;
class PASCALIMPLEMENTATION TcxLabelLineOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxLabelLineAlignment FAlignment;
	System::Uitypes::TColor FInnerColor;
	System::Classes::TNotifyEvent FOnChanged;
	System::Uitypes::TColor FOuterColor;
	bool FVisible;
	bool __fastcall GetIsCustomColorsAssigned(void);
	void __fastcall SetAlignment(TcxLabelLineAlignment AValue);
	void __fastcall SetInnerColor(System::Uitypes::TColor AValue);
	void __fastcall SetOuterColor(System::Uitypes::TColor AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	__property bool IsCustomColorsAssigned = {read=GetIsCustomColorsAssigned, nodefault};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxLabelLineOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxLabelLineAlignment Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property System::Uitypes::TColor InnerColor = {read=FInnerColor, write=SetInnerColor, default=536870912};
	__property System::Uitypes::TColor OuterColor = {read=FOuterColor, write=SetOuterColor, default=536870912};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxLabelLineOptions(void) { }
	
};


class DELPHICLASS TcxCustomLabelViewInfo;
class PASCALIMPLEMENTATION TcxCustomLabelViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	Cxedit::TcxEditAlignment* FAlignment;
	int FAngle;
	System::Word FDepth;
	System::Types::TSize FDepthDeltaSize;
	Cxgraphics::TcxBitmap* FDrawBitmap;
	Vcl::Graphics::TBitmap* FGlyph;
	TcxLabelEffect FLabelEffect;
	TcxLabelStyle FLabelStyle;
	int FLabelStyleOffset;
	System::Types::TRect FLabelTextRect;
	System::Uitypes::TColor FLineInnerColor;
	Dxcore::TdxOrientation FLineOrientation;
	System::Uitypes::TColor FLineOuterColor;
	System::Types::TRect FLineRect;
	TcxLabelOrientation FOrientation;
	int FPenWidth;
	System::Uitypes::TColor FShadowedColor;
	bool FWordWrap;
	System::Types::TPoint FInplaceOffset;
	bool FIsDrawBitmapDirty;
	System::Types::TPoint FWindowOrg;
	bool __fastcall HasEffects(void);
	
protected:
	virtual void __fastcall InternalDrawBackground(Cxgraphics::TcxCanvas* ACanvas, Cxgraphics::TcxCanvas* ASource, const System::Types::TRect &R, const System::Types::TPoint &AParentBackgroundOffset);
	virtual void __fastcall SetBackgroundColor(System::Uitypes::TColor Value);
	__property Cxedit::TcxEditAlignment* Alignment = {read=FAlignment, write=FAlignment};
	__property int Angle = {read=FAngle, write=FAngle, nodefault};
	__property System::Word Depth = {read=FDepth, write=FDepth, nodefault};
	__property System::Types::TSize DepthDeltaSize = {read=FDepthDeltaSize, write=FDepthDeltaSize};
	__property Cxgraphics::TcxBitmap* DrawBitmap = {read=FDrawBitmap};
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=FGlyph};
	__property TcxLabelEffect LabelEffect = {read=FLabelEffect, write=FLabelEffect, nodefault};
	__property TcxLabelStyle LabelStyle = {read=FLabelStyle, write=FLabelStyle, nodefault};
	__property int LabelStyleOffset = {read=FLabelStyleOffset, write=FLabelStyleOffset, nodefault};
	__property System::Types::TRect LabelTextRect = {read=FLabelTextRect, write=FLabelTextRect};
	__property System::Uitypes::TColor LineInnerColor = {read=FLineInnerColor, write=FLineInnerColor, nodefault};
	__property Dxcore::TdxOrientation LineOrientation = {read=FLineOrientation, write=FLineOrientation, nodefault};
	__property System::Uitypes::TColor LineOuterColor = {read=FLineOuterColor, write=FLineOuterColor, nodefault};
	__property System::Types::TRect LineRect = {read=FLineRect, write=FLineRect};
	__property TcxLabelOrientation Orientation = {read=FOrientation, write=FOrientation, nodefault};
	__property int PenWidth = {read=FPenWidth, write=FPenWidth, nodefault};
	__property System::Uitypes::TColor ShadowedColor = {read=FShadowedColor, write=FShadowedColor, nodefault};
	__property bool WordWrap = {read=FWordWrap, write=FWordWrap, nodefault};
	
public:
	System::Types::TRect DrawTextOffsets;
	System::Types::TRect FocusRect;
	bool HasGlyph;
	System::Types::TPoint LeftTop;
	bool ShowAccelChar;
	__fastcall virtual TcxCustomLabelViewInfo(void);
	__fastcall virtual ~TcxCustomLabelViewInfo(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawLabel(Cxgraphics::TcxCanvas* ACanvas);
};


class DELPHICLASS TcxCustomLabelViewData;
class DELPHICLASS TcxCustomLabelProperties;
class PASCALIMPLEMENTATION TcxCustomLabelViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	TcxLabelLineOptions* __fastcall GetLineOptions(void);
	TcxCustomLabelProperties* __fastcall GetProperties(void);
	void __fastcall CalculateLabelViewInfoProps(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	
protected:
	virtual int __fastcall CalculateLabelStyleOffset(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall CalculateLineRect(System::Types::TRect &ATextRect, const System::Types::TRect &ABounds, TcxLabelLineAlignment AAlignment, bool AVisible, int ALineHeight, Dxcore::TdxOrientation AOrientation);
	virtual System::Types::TRect __fastcall CalculateTextRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString AText, int ARealAngle);
	virtual System::Types::TSize __fastcall CalculateTextSize(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::UnicodeString AText, bool AFixedWidth);
	void __fastcall CalculateViewParams(Cxgraphics::TcxCanvas* ACanvas, TcxCustomLabelViewInfo* AViewInfo);
	virtual int __fastcall GetDrawTextFlags(void);
	bool __fastcall GetIsEditClass(void);
	virtual int __fastcall GetLineHeight(void);
	virtual Cxedit::TcxEditPaintOptions __fastcall CalculatePaintOptions(void);
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual bool __fastcall IsLineVisible(int ARealAngle);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall GetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	__property TcxLabelLineOptions* LineOptions = {read=GetLineOptions};
	__property TcxCustomLabelProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomLabelViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomLabelViewData(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomLabelProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	int FAngle;
	System::Word FDepth;
	Vcl::Graphics::TBitmap* FGlyph;
	TcxLabelEffect FLabelEffect;
	TcxLabelStyle FLabelStyle;
	TcxLabelLineOptions* FLineOptions;
	TcxLabelOrientation FOrientation;
	int FPenWidth;
	System::Uitypes::TColor FShadowedColor;
	bool FShowAccelChar;
	bool FShowEndEllipsis;
	bool FWordWrap;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	void __fastcall ChangeHandler(System::TObject* Sender);
	void __fastcall SetAngle(int Value);
	void __fastcall SetDepth(System::Word Value);
	void __fastcall SetLabelEffect(TcxLabelEffect Value);
	void __fastcall SetLabelStyle(TcxLabelStyle Value);
	void __fastcall SetLineOptions(TcxLabelLineOptions* AValue);
	void __fastcall SetOrientation(TcxLabelOrientation Value);
	void __fastcall SetPenWidth(int Value);
	void __fastcall SetShadowedColor(System::Uitypes::TColor Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetShowAccelChar(bool Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetWordWrap(bool Value);
	bool __fastcall HasEffects(void);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual System::Types::TSize __fastcall CalculateDepthDelta(void);
	
public:
	__fastcall virtual TcxCustomLabelProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomLabelProperties(void);
	virtual bool __fastcall CanCompareEditValue(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual Cxedit::TcxCustomEditStyleClass __fastcall GetStyleClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	__property int Angle = {read=FAngle, write=SetAngle, default=0};
	__property System::Word Depth = {read=FDepth, write=SetDepth, default=0};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property TcxLabelEffect LabelEffect = {read=FLabelEffect, write=SetLabelEffect, default=0};
	__property TcxLabelStyle LabelStyle = {read=FLabelStyle, write=SetLabelStyle, default=0};
	__property TcxLabelLineOptions* LineOptions = {read=FLineOptions, write=SetLineOptions};
	__property TcxLabelOrientation Orientation = {read=FOrientation, write=SetOrientation, default=7};
	__property int PenWidth = {read=FPenWidth, write=SetPenWidth, default=1};
	__property System::Uitypes::TColor ShadowedColor = {read=FShadowedColor, write=SetShadowedColor, default=-16777199};
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=0};
	__property Transparent;
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
};


class DELPHICLASS TcxLabelProperties;
class PASCALIMPLEMENTATION TcxLabelProperties : public TcxCustomLabelProperties
{
	typedef TcxCustomLabelProperties inherited;
	
__published:
	__property Alignment;
	__property Angle = {default=0};
	__property Depth = {default=0};
	__property Glyph;
	__property LabelEffect = {default=0};
	__property LabelStyle = {default=0};
	__property LineOptions;
	__property Orientation = {default=7};
	__property PenWidth = {default=1};
	__property ShadowedColor = {default=-16777199};
	__property ShowAccelChar = {default=1};
	__property ShowEndEllipsis = {default=0};
	__property Transparent;
	__property WordWrap = {default=0};
public:
	/* TcxCustomLabelProperties.Create */ inline __fastcall virtual TcxLabelProperties(System::Classes::TPersistent* AOwner) : TcxCustomLabelProperties(AOwner) { }
	/* TcxCustomLabelProperties.Destroy */ inline __fastcall virtual ~TcxLabelProperties(void) { }
	
};


class DELPHICLASS TcxCustomLabel;
class PASCALIMPLEMENTATION TcxCustomLabel : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	Vcl::Controls::TWinControl* FFocusControl;
	bool FLockCaption;
	TcxCustomLabelProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomLabelProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxLabelEditStyle* __fastcall GetStyle(void);
	HIDESBASE TcxCustomLabelViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetFocusControl(Vcl::Controls::TWinControl* Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomLabelProperties* Value);
	HIDESBASE void __fastcall SetStyle(TcxLabelEditStyle* Value);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* ACOmponent, System::Classes::TOperation Operation);
	virtual bool __fastcall FadingCanFadeBackground(void);
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual void __fastcall DoAutoSizeChanged(void);
	DYNAMIC void __fastcall TextChanged(void);
	virtual bool __fastcall CanAutoHeight(void);
	virtual bool __fastcall CanAutoWidth(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual bool __fastcall DefaultParentColor(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual bool __fastcall UseAnchorX(void);
	virtual bool __fastcall UseAnchorY(void);
	__property Vcl::Controls::TWinControl* FocusControl = {read=FFocusControl, write=SetFocusControl};
	__property TcxCustomLabelViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual ~TcxCustomLabel(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	DYNAMIC bool __fastcall CanFocus(void);
	virtual int __fastcall GetTextBaseLine(void);
	virtual bool __fastcall HasTextBaseLine(void);
	__property TcxCustomLabelProperties* ActiveProperties = {read=GetActiveProperties};
	__property Caption = {default=0};
	__property TcxCustomLabelProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TcxLabelEditStyle* Style = {read=GetStyle, write=SetStyle};
	__property TabOrder = {stored=false, default=-1};
	__property Transparent = {default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomLabel(System::Classes::TComponent* AOwner)/* overload */ : Cxedit::TcxCustomEdit(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomLabel(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomLabel(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
};


class DELPHICLASS TcxLabel;
class PASCALIMPLEMENTATION TcxLabel : public TcxCustomLabel
{
	typedef TcxCustomLabel inherited;
	
private:
	HIDESBASE TcxLabelProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxLabelProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxLabelProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxLabelProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Caption = {default=0};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property FocusControl;
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TcxLabelProperties* Properties = {read=GetProperties, write=SetProperties};
	__property TabOrder = {default=-1};
	__property Transparent = {default=0};
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
	/* TcxCustomLabel.Destroy */ inline __fastcall virtual ~TcxLabel(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxLabel(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomLabel(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxLabel(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomLabel(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxLabel(HWND ParentWindow) : TcxCustomLabel(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxlabel */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLABEL)
using namespace Cxlabel;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlabelHPP
