// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGroupBox.pas' rev: 24.00 (Win64)

#ifndef CxgroupboxHPP
#define CxgroupboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEditPaintUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgroupbox
{
//-- type declarations -------------------------------------------------------
enum TcxCaptionAlignment : unsigned char { alTopLeft, alTopCenter, alTopRight, alBottomLeft, alBottomCenter, alBottomRight, alLeftTop, alLeftCenter, alLeftBottom, alRightTop, alRightCenter, alRightBottom, alCenterCenter };

enum TcxPanelOffice11BackgroundKind : unsigned char { pobkGradient, pobkOffice11Color, pobkStyleColor };

class DELPHICLASS TcxGroupBoxButtonViewInfo;
class PASCALIMPLEMENTATION TcxGroupBoxButtonViewInfo : public Cxedit::TcxEditButtonViewInfo
{
	typedef Cxedit::TcxEditButtonViewInfo inherited;
	
public:
	System::UnicodeString Caption;
	int Column;
	int Row;
	virtual System::Types::TRect __fastcall GetGlyphRect(const System::Types::TSize AGlyphSize, System::Classes::TLeftRight AAlignment, bool AIsPaintCopy);
public:
	/* TcxEditButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxGroupBoxButtonViewInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGroupBoxButtonViewInfo(void) : Cxedit::TcxEditButtonViewInfo() { }
	
};


class DELPHICLASS TcxGroupBoxViewInfo;
class DELPHICLASS TcxCustomGroupBox;
class PASCALIMPLEMENTATION TcxGroupBoxViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
private:
	bool FCheckBoxVisible;
	Cxlookandfeelpainters::TcxCheckBoxState FCheckBoxCheckState;
	Cxlookandfeelpainters::TcxEditCheckState FCheckBoxViewState;
	bool FCheckPressed;
	System::Types::TRect FCheckBoxRect;
	System::Types::TRect FFocusRect;
	System::Types::TRect FMouseFocusingRect;
	void __fastcall CalculateCheckBoxAndTextRects(System::Types::TRect &ACombinedRect);
	void __fastcall InvalidateCheckBoxRect(void);
	bool __fastcall PointInCheckBox(int X, int Y);
	System::Types::TRect __fastcall GetCaptionRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	System::Types::TRect __fastcall GetCaptionRectIndent(void);
	Cxlookandfeelpainters::TcxGroupBoxCaptionPosition __fastcall GetCaptionPosition(void);
	System::Types::TRect __fastcall GetCheckBoxRect(Cxgraphics::TcxCanvas* ACanvas);
	System::Types::TRect __fastcall GetControlRect(void);
	TcxCustomGroupBox* __fastcall GetEdit(void);
	System::Types::TRect __fastcall GetFrameBounds(void);
	System::Types::TRect __fastcall GetCombinedCaptionRect(void);
	System::Types::TRect __fastcall GetBoundsForPanel(void);
	System::Types::TRect __fastcall GetThemeBackgroundRect(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawCheckBox(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawHorizontalTextCaption(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawVerticalTextCaption(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	void __fastcall DrawNativeBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect);
	void __fastcall DrawNativeGroupBoxBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawNativePanelBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect);
	void __fastcall DrawOffice11PanelBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawParentBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	void __fastcall DrawUsualBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall InternalDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall InternalDrawBackgroundByPainter(Cxgraphics::TcxCanvas* ACanvas);
	
protected:
	void __fastcall CalculateFocusRect(void);
	void __fastcall CalculateRectsForPanel(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall CalculateRectsForStandardPainter(Cxgraphics::TcxCanvas* ACanvas, int AShadowWidth);
	void __fastcall CalculateRectsForSkinPainter(Cxgraphics::TcxCanvas* ACanvas, bool AHasNonClientArea);
	virtual void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas);
	virtual Cxedit::TcxEditButtonViewInfoClass __fastcall GetButtonViewInfoClass(void);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall IsPanelStyle(void);
	__property Cxlookandfeelpainters::TcxGroupBoxCaptionPosition CaptionPosition = {read=GetCaptionPosition, nodefault};
	__property System::Types::TRect CaptionRectIndent = {read=GetCaptionRectIndent};
	__property bool CheckBoxVisible = {read=FCheckBoxVisible, write=FCheckBoxVisible, nodefault};
	__property System::Types::TRect ControlRect = {read=GetControlRect};
	__property System::Types::TRect FocusRect = {read=FFocusRect, write=FFocusRect};
	
public:
	System::Classes::TAlignment Alignment;
	System::Types::TRect CaptionRect;
	bool IsDesigning;
	System::Types::TRect TextRect;
	__fastcall virtual TcxGroupBoxViewInfo(void);
	__fastcall virtual ~TcxGroupBoxViewInfo(void);
	void __fastcall InvalidateCaption(void);
	__property Cxlookandfeelpainters::TcxCheckBoxState CheckBoxCheckState = {read=FCheckBoxCheckState, write=FCheckBoxCheckState, nodefault};
	__property TcxCustomGroupBox* Edit = {read=GetEdit};
	__property System::Types::TRect MouseFocusingRect = {read=FMouseFocusingRect, write=FMouseFocusingRect};
};


class DELPHICLASS TcxGroupBoxViewData;
class PASCALIMPLEMENTATION TcxGroupBoxViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	Cxlookandfeelpainters::TcxGroupBoxCaptionPosition __fastcall GetCaptionPosition(void);
	TcxCustomGroupBox* __fastcall GetEdit(void);
	int __fastcall GetShadowWidth(void);
	bool __fastcall HasNonClientArea(void);
	void __fastcall CalculateRects(Cxgraphics::TcxCanvas* ACanvas, TcxGroupBoxViewInfo* AEditViewInfo);
	
protected:
	virtual Cxcontainer::TcxContainerState __fastcall GetContainerState(const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	System::Types::TRect __fastcall GetContentOffsetsByPainter(TcxGroupBoxViewInfo* AViewInfo);
	bool __fastcall IsPanelStyle(void);
	__property Cxlookandfeelpainters::TcxGroupBoxCaptionPosition CaptionPosition = {read=GetCaptionPosition, nodefault};
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonsViewInfo(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void);
	virtual System::Types::TRect __fastcall GetBorderExtent(void);
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual bool __fastcall HasShadow(void);
	__classmethod virtual bool __fastcall IsNativeStyle(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__property TcxCustomGroupBox* Edit = {read=GetEdit};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxGroupBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGroupBoxViewData(void) { }
	
};


struct DECLSPEC_DRECORD TcxEditMetrics
{
public:
	int AutoHeightColumnWidthCorrection;
	int AutoHeightWidthCorrection;
	int ColumnWidthCorrection;
	int WidthCorrection;
	int ClientLeftBoundCorrection;
	int ClientWidthCorrection;
	int ColumnOffset;
	System::Types::TSize ButtonSize;
};


class DELPHICLASS TcxButtonGroupViewInfo;
class PASCALIMPLEMENTATION TcxButtonGroupViewInfo : public TcxGroupBoxViewInfo
{
	typedef TcxGroupBoxViewInfo inherited;
	
protected:
	virtual void __fastcall DrawEditButton(Cxgraphics::TcxCanvas* ACanvas, int AButtonVisibleIndex);
	virtual void __fastcall DrawButtonCaption(Cxgraphics::TcxCanvas* ACanvas, TcxGroupBoxButtonViewInfo* AButtonViewInfo, const System::Types::TRect &AGlyphRect) = 0 ;
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, TcxGroupBoxButtonViewInfo* AButtonViewInfo, const System::Types::TRect &AGlyphRect) = 0 ;
	virtual Cxedit::TcxEditButtonViewInfoClass __fastcall GetButtonViewInfoClass(void);
	virtual System::Types::TSize __fastcall GetGlyphSize(void);
	virtual bool __fastcall IsButtonGlypthTransparent(TcxGroupBoxButtonViewInfo* AButtonViewInfo) = 0 ;
	
public:
	System::Types::TRect CaptionExtent;
	System::Types::TSize GlyphSize;
public:
	/* TcxGroupBoxViewInfo.Create */ inline __fastcall virtual TcxButtonGroupViewInfo(void) : TcxGroupBoxViewInfo() { }
	/* TcxGroupBoxViewInfo.Destroy */ inline __fastcall virtual ~TcxButtonGroupViewInfo(void) { }
	
};


class DELPHICLASS TcxButtonGroupButtonViewInfo;
class PASCALIMPLEMENTATION TcxButtonGroupButtonViewInfo : public TcxGroupBoxButtonViewInfo
{
	typedef TcxGroupBoxButtonViewInfo inherited;
	
protected:
	virtual Cxedit::TcxEditButtonFadingHelper* __fastcall CreateFadingHelper(void);
public:
	/* TcxEditButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxButtonGroupButtonViewInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxButtonGroupButtonViewInfo(void) : TcxGroupBoxButtonViewInfo() { }
	
};


class DELPHICLASS TcxButtonGroupButtonFadingHelper;
class PASCALIMPLEMENTATION TcxButtonGroupButtonFadingHelper : public Cxedit::TcxEditButtonFadingHelper
{
	typedef Cxedit::TcxEditButtonFadingHelper inherited;
	
private:
	TcxButtonGroupViewInfo* __fastcall InternalGetEditViewInfo(void);
	TcxButtonGroupButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetButtonRect(void);
	virtual Cxgraphics::TcxBitmap32* __fastcall PrepareFadingImage(Cxedit::TcxEditButtonState AState);
	
public:
	__property TcxButtonGroupViewInfo* EditViewInfo = {read=InternalGetEditViewInfo};
	__property TcxButtonGroupButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxEditButtonFadingHelper.Create */ inline __fastcall virtual TcxButtonGroupButtonFadingHelper(Cxedit::TcxEditButtonViewInfo* AViewInfo) : Cxedit::TcxEditButtonFadingHelper(AViewInfo) { }
	
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxButtonGroupButtonFadingHelper(void) { }
	
};


class DELPHICLASS TcxButtonGroupViewData;
class DELPHICLASS TcxCustomButtonGroupProperties;
class PASCALIMPLEMENTATION TcxButtonGroupViewData : public TcxGroupBoxViewData
{
	typedef TcxGroupBoxViewData inherited;
	
private:
	TcxCustomButtonGroupProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall CalculateButtonPositions(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall CalculateButtonViewInfos(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual int __fastcall GetDrawTextFlags(void);
	virtual void __fastcall GetEditMetrics(bool AAutoHeight, Cxgraphics::TcxCanvas* ACanvas, /* out */ TcxEditMetrics &AMetrics) = 0 ;
	virtual System::Types::TRect __fastcall GetCaptionRectExtent(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall CalculateButtonsViewInfo(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual System::Types::TSize __fastcall GetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo = (Cxedit::TcxCustomEditViewInfo*)(0x0));
	__classmethod virtual bool __fastcall IsButtonNativeStyle(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__property TcxCustomButtonGroupProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxButtonGroupViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : TcxGroupBoxViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonGroupViewData(void) { }
	
};


typedef System::TMetaClass* TcxButtonGroupViewDataClass;

class DELPHICLASS TcxCustomGroupBoxProperties;
class PASCALIMPLEMENTATION TcxCustomGroupBoxProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
protected:
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	
public:
	virtual bool __fastcall CanCompareEditValue(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
public:
	/* TcxCustomEditProperties.Create */ inline __fastcall virtual TcxCustomGroupBoxProperties(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditProperties(AOwner) { }
	/* TcxCustomEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomGroupBoxProperties(void) { }
	
};


class DELPHICLASS TcxButtonGroupItem;
class PASCALIMPLEMENTATION TcxButtonGroupItem : public Cxcheckbox::TcxCaptionItem
{
	typedef Cxcheckbox::TcxCaptionItem inherited;
	
private:
	bool FEnabled;
	bool __fastcall GetIsCollectionDestroying(void);
	void __fastcall SetEnabled(bool Value);
	
protected:
	void __fastcall DoChanged(System::Classes::TCollection* ACollection, Cxclasses::TcxCollectionOperation ACollectionOperation, int AIndex = 0xffffffff);
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property bool IsCollectionDestroying = {read=GetIsCollectionDestroying, nodefault};
	
public:
	__fastcall virtual TcxButtonGroupItem(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxButtonGroupItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
};


class DELPHICLASS TcxButtonGroupItems;
class PASCALIMPLEMENTATION TcxButtonGroupItems : public Cxcheckbox::TcxCaptionItems
{
	typedef Cxcheckbox::TcxCaptionItems inherited;
	
public:
	TcxButtonGroupItem* operator[](int Index) { return Items[Index]; }
	
private:
	int FChangedItemIndex;
	Cxclasses::TcxCollectionOperation FChangedItemOperation;
	bool FItemChanged;
	HIDESBASE TcxButtonGroupItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxButtonGroupItem* Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property int ChangedItemIndex = {read=FChangedItemIndex, nodefault};
	__property Cxclasses::TcxCollectionOperation ChangedItemOperation = {read=FChangedItemOperation, nodefault};
	__property bool ItemChanged = {read=FItemChanged, nodefault};
	
public:
	void __fastcall InternalNotify(TcxButtonGroupItem* AItem, int AItemIndex, Cxclasses::TcxCollectionOperation AItemOperation);
	__property TcxButtonGroupItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxOwnedInterfacedCollection.Destroy */ inline __fastcall virtual ~TcxButtonGroupItems(void) { }
	
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxButtonGroupItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : Cxcheckbox::TcxCaptionItems(AOwner, ItemClass) { }
	
};


typedef System::TMetaClass* TcxButtonGroupItemsClass;

class PASCALIMPLEMENTATION TcxCustomButtonGroupProperties : public TcxCustomGroupBoxProperties
{
	typedef TcxCustomGroupBoxProperties inherited;
	
private:
	int FColumns;
	TcxButtonGroupItems* FItems;
	bool FShowEndEllipsis;
	bool FWordWrap;
	void __fastcall SetColumns(int Value);
	void __fastcall SetItems(TcxButtonGroupItems* Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetWordWrap(bool Value);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual TcxButtonGroupItems* __fastcall CreateItems(void);
	int __fastcall GetButtonsPerColumn(void);
	virtual int __fastcall GetColumnCount(void);
	
public:
	__fastcall virtual TcxCustomButtonGroupProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomButtonGroupProperties(void);
	virtual Cxedit::TcxCustomEditProperties* __fastcall CreatePreviewProperties(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property int Columns = {read=FColumns, write=SetColumns, default=1};
	__property TcxButtonGroupItems* Items = {read=FItems, write=SetItems};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
};


class DELPHICLASS TcxPanelStyle;
class PASCALIMPLEMENTATION TcxPanelStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FActive;
	Vcl::Controls::TBorderWidth FBorderWidth;
	int FCaptionIndent;
	TcxCustomGroupBox* FEdit;
	TcxPanelOffice11BackgroundKind FOfficeBackgroundKind;
	bool FWordWrap;
	void __fastcall SetActive(bool AValue);
	void __fastcall SetBorderWidth(Vcl::Controls::TBorderWidth AValue);
	void __fastcall SetCaptionIndent(int AValue);
	void __fastcall SetOfficeBackgroundKind(TcxPanelOffice11BackgroundKind AValue);
	void __fastcall SetWordWrap(bool AValue);
	
protected:
	void __fastcall Update(void);
	__property TcxCustomGroupBox* Edit = {read=FEdit};
	
public:
	__fastcall virtual TcxPanelStyle(TcxCustomGroupBox* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property Vcl::Controls::TBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property int CaptionIndent = {read=FCaptionIndent, write=SetCaptionIndent, default=2};
	__property TcxPanelOffice11BackgroundKind OfficeBackgroundKind = {read=FOfficeBackgroundKind, write=SetOfficeBackgroundKind, default=1};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxPanelStyle(void) { }
	
};


typedef void __fastcall (__closure *TcxGroupBoxCustomDrawEvent)(TcxCustomGroupBox* Sender, bool &ADone);

typedef void __fastcall (__closure *TcxGroupBoxMeasureCaptionHeightEvent)(TcxCustomGroupBox* Sender, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* const APainter, int &ACaptionHeight);

typedef void __fastcall (__closure *TcxGroupBoxCustomDrawElementEvent)(TcxCustomGroupBox* Sender, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* const APainter, bool &ADone);

class PASCALIMPLEMENTATION TcxCustomGroupBox : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	TcxCaptionAlignment FAlignment;
	System::Uitypes::TColor FCaptionBkColor;
	bool FIsAccelCharHandling;
	TcxPanelStyle* FPanelStyle;
	bool FRedrawOnResize;
	TcxGroupBoxCustomDrawEvent FOnCustomDraw;
	TcxGroupBoxCustomDrawElementEvent FOnCustomDrawCaption;
	TcxGroupBoxCustomDrawElementEvent FOnCustomDrawContentBackground;
	TcxGroupBoxMeasureCaptionHeightEvent FOnMeasureCaptionHeight;
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetCheckBoxCheckState(void);
	Cxlookandfeelpainters::TcxEditCheckState __fastcall GetCheckBoxViewState(void);
	void __fastcall SetCheckBoxCheckState(Cxlookandfeelpainters::TcxCheckBoxState AValue);
	void __fastcall SetCheckBoxViewState(Cxlookandfeelpainters::TcxEditCheckState AValue);
	System::Uitypes::TColor __fastcall GetCaptionBkColor(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	HIDESBASE TcxGroupBoxViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsSkinAvailable(void);
	void __fastcall UpdateCaption(void);
	void __fastcall UpdateContentExtents(void);
	int __fastcall GetHorizontalCaptionIndent(void);
	unsigned __fastcall GetPanelStyleCaptionDrawingFlags(void);
	int __fastcall GetVerticalCaptionIndent(void);
	void __fastcall SetAlignment(TcxCaptionAlignment Value);
	void __fastcall SetCaptionBkColor(System::Uitypes::TColor Value);
	HIDESBASE void __fastcall SetColor(System::Uitypes::TColor Value);
	HIDESBASE void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetPanelStyle(TcxPanelStyle* AValue);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMUpdateNonClientArea(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMPRINT(Winapi::Messages::TMessage &Message);
	
protected:
	Vcl::Graphics::TFont* FCaptionFont;
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall CalculateViewInfo(System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent)/* overload */;
	virtual void __fastcall CreateHandle(void);
	virtual TcxPanelStyle* __fastcall CreatePanelStyle(void);
	virtual bool __fastcall DefaultParentColor(void);
	virtual bool __fastcall GetCheckBoxVisible(void);
	virtual System::Types::TRect __fastcall GetClientOffsets(void);
	virtual void __fastcall Initialize(void);
	virtual Cxcontainer::TcxContainerStyle* __fastcall InternalGetActiveStyle(void);
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues(void);
	bool __fastcall PointInCheckBox(System::Types::TPoint APoint);
	virtual void __fastcall Toggle(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall UpdateCheckBoxState(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintNonClientArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall CanAutoSize(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual bool __fastcall CanHaveTransparentBorder(void);
	virtual bool __fastcall InternalCanFocusOnClick(void);
	virtual bool __fastcall IsContainerClass(void);
	virtual bool __fastcall IsNativeBackground(void);
	bool __fastcall IsPanelStyle(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual bool __fastcall FadingCanFadeBackground(void);
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall TextChanged(void);
	virtual bool __fastcall HasShadow(void);
	virtual System::Types::TRect __fastcall GetShadowBounds(void);
	virtual System::Types::TRect __fastcall GetShadowBoundsExtent(void);
	virtual bool __fastcall DoCustomDrawCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter);
	virtual bool __fastcall DoCustomDrawContentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter);
	void __fastcall DoMeasureCaptionHeight(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, int &ACaptionHeight);
	void __fastcall AdjustCanvasFontSettings(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall DoCustomDraw(void);
	unsigned __fastcall GetCaptionDrawingFlags(void);
	virtual bool __fastcall HasNonClientArea(void);
	virtual bool __fastcall IsNonClientAreaSupported(void);
	bool __fastcall IsVerticalText(void);
	void __fastcall CalculateCaptionFont(void);
	void __fastcall RedrawNonClientArea(void);
	DYNAMIC void __fastcall Resize(void);
	__property System::Uitypes::TColor CaptionBkColor = {read=GetCaptionBkColor, write=SetCaptionBkColor, stored=false, nodefault};
	__property Cxlookandfeelpainters::TcxCheckBoxState CheckBoxCheckState = {read=GetCheckBoxCheckState, write=SetCheckBoxCheckState, nodefault};
	__property Cxlookandfeelpainters::TcxEditCheckState CheckBoxViewState = {read=GetCheckBoxViewState, write=SetCheckBoxViewState, nodefault};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, stored=false, nodefault};
	__property Ctl3D;
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont, stored=false};
	__property TcxPanelStyle* PanelStyle = {read=FPanelStyle, write=SetPanelStyle};
	__property ParentBackground = {default=1};
	__property bool RedrawOnResize = {read=FRedrawOnResize, write=FRedrawOnResize, default=1};
	__property TabStop = {default=0};
	__property TcxGroupBoxViewInfo* ViewInfo = {read=GetViewInfo};
	__property TcxGroupBoxCustomDrawEvent OnCustomDraw = {read=FOnCustomDraw, write=FOnCustomDraw};
	__property TcxGroupBoxCustomDrawElementEvent OnCustomDrawCaption = {read=FOnCustomDrawCaption, write=FOnCustomDrawCaption};
	__property TcxGroupBoxCustomDrawElementEvent OnCustomDrawContentBackground = {read=FOnCustomDrawContentBackground, write=FOnCustomDrawContentBackground};
	__property TcxGroupBoxMeasureCaptionHeightEvent OnMeasureCaptionHeight = {read=FOnMeasureCaptionHeight, write=FOnMeasureCaptionHeight};
	
public:
	__fastcall virtual TcxCustomGroupBox(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomGroupBox(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCaptionAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property Transparent = {default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomGroupBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGroupBox(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  CalculateViewInfo(bool AIsMouseEvent){ Cxedit::TcxCustomEdit::CalculateViewInfo(AIsMouseEvent); }
	inline void __fastcall  CalculateViewInfo(Cxedit::TcxCustomEditViewInfo* AViewInfo, System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent){ Cxedit::TcxCustomEdit::CalculateViewInfo(AViewInfo, P, Button, Shift, AIsMouseEvent); }
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
};


class DELPHICLASS TcxGroupBox;
class PASCALIMPLEMENTATION TcxGroupBox : public TcxCustomGroupBox
{
	typedef TcxCustomGroupBox inherited;
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Caption = {default=0};
	__property CaptionBkColor;
	__property Color;
	__property Constraints;
	__property Ctl3D;
	__property UseDockManager = {default=0};
	__property DockSite = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property LookAndFeel;
	__property PanelStyle;
	__property ParentBackground = {default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property RedrawOnResize = {default=1};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Transparent = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnCustomDraw;
	__property OnCustomDrawCaption;
	__property OnCustomDrawContentBackground;
	__property OnDblClick;
	__property OnDockDrop;
	__property OnDockOver;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetSiteInfo;
	__property OnMeasureCaptionHeight;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnUnDock;
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxGroupBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomGroupBox(AOwner) { }
	/* TcxCustomGroupBox.Destroy */ inline __fastcall virtual ~TcxGroupBox(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxGroupBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomGroupBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGroupBox(HWND ParentWindow) : TcxCustomGroupBox(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomButtonGroup;
class PASCALIMPLEMENTATION TcxCustomButtonGroup : public TcxCustomGroupBox
{
	typedef TcxCustomGroupBox inherited;
	
private:
	System::Classes::TList* FButtons;
	void __fastcall DoButtonDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall DoButtonDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall DoButtonKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall DoButtonKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall DoButtonKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall DoButtonMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoButtonMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoButtonMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DoButtonMouseWheel(System::TObject* Sender, System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos, bool &Handled);
	TcxCustomButtonGroupProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomButtonGroupProperties* __fastcall GetActiveProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomButtonGroupProperties* Value);
	
protected:
	virtual bool __fastcall CanAutoSize(void);
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall EnabledChanged(void);
	virtual void __fastcall Initialize(void);
	virtual bool __fastcall IsButtonDC(NativeUInt ADC);
	virtual bool __fastcall IsContainerClass(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall ArrangeButtons(void);
	virtual NativeUInt __fastcall GetButtonDC(int AButtonIndex) = 0 ;
	int __fastcall GetButtonIndexAt(const System::Types::TPoint P);
	virtual Vcl::Controls::TWinControl* __fastcall GetButtonInstance(void) = 0 ;
	int __fastcall GetFocusedButtonIndex(void);
	virtual void __fastcall InitButtonInstance(Vcl::Controls::TWinControl* AButton);
	virtual bool __fastcall IsNonClientAreaSupported(void);
	virtual void __fastcall SetButtonCount(int Value);
	virtual void __fastcall SynchronizeButtonsStyle(void);
	virtual void __fastcall UpdateButtons(void);
	__property System::Classes::TList* InternalButtons = {read=FButtons};
	__property TabStop = {default=1};
	
public:
	__fastcall virtual ~TcxCustomButtonGroup(void);
	virtual void __fastcall ActivateByMouse(System::Classes::TShiftState Shift, int X, int Y, Cxedit::TcxCustomEditData* &AEditData);
	DYNAMIC bool __fastcall Focused(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	bool __fastcall IsButtonNativeStyle(void);
	__property AutoSize = {default=0};
	__property TcxCustomButtonGroupProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomButtonGroupProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxCustomButtonGroup(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomGroupBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomButtonGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomGroupBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomButtonGroup(HWND ParentWindow) : TcxCustomGroupBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool cxGroupBox_SupportNonClientArea;
}	/* namespace Cxgroupbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGROUPBOX)
using namespace Cxgroupbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgroupboxHPP
