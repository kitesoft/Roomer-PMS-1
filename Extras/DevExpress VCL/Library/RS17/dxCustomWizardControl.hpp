// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomWizardControl.pas' rev: 24.00 (Win32)

#ifndef DxcustomwizardcontrolHPP
#define DxcustomwizardcontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxWizardControlStrs.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcustomwizardcontrol
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxWizardControlCustomPageClass;

enum TdxWizardControlChange : unsigned char { wccContent, wccLayout, wccStruct };

typedef System::Set<TdxWizardControlChange, TdxWizardControlChange::wccContent, TdxWizardControlChange::wccStruct>  TdxWizardControlChanges;

enum TdxWizardControlButtonKind : unsigned char { wcbkBack, wcbkNext, wcbkCancel, wcbkHelp, wcbkFinish };

enum TdxWizardControlElementVisibility : unsigned char { wcevDefault, wcevAlwaysVisible, wcevAlwaysHidden };

enum TdxWizardControlResizeAnimation : unsigned char { wcraDefault, wcraEnabled, wcraDisabled };

enum TdxWizardControlTransitionEffect : unsigned char { wcteDefault, wcteNone, wcteFade, wcteSlide };

enum TdxWizardControlViewStyle : unsigned char { wcvsWizard97, wcvsAero };

typedef void __fastcall (__closure *TdxWizardControlButtonClickEvent)(System::TObject* Sender, TdxWizardControlButtonKind AKind, bool &AHandled);

typedef void __fastcall (__closure *TdxWizardControlInfoPanelClickEvent)(System::TObject* Sender, bool &AHandled);

class DELPHICLASS TdxWizardControlCustomPage;
typedef void __fastcall (__closure *TdxWizardControlPageChangingEvent)(System::TObject* Sender, TdxWizardControlCustomPage* ANewPage, bool &AAllow);

__interface IdxWizardControlSelectableItem;
typedef System::DelphiInterface<IdxWizardControlSelectableItem> _di_IdxWizardControlSelectableItem;
__interface  INTERFACE_UUID("{D5E058AB-1C90-4D21-BE0A-EB48530EF53B}") IdxWizardControlSelectableItem  : public System::IInterface 
{
	
public:
	virtual void __fastcall SelectionChanged(void) = 0 ;
};

__interface IdxWizardControlFormHelper;
typedef System::DelphiInterface<IdxWizardControlFormHelper> _di_IdxWizardControlFormHelper;
__interface  INTERFACE_UUID("{7DA6D67B-F19A-4D53-A6CB-C55EF65245D7}") IdxWizardControlFormHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall LayoutChanged(void) = 0 ;
	virtual bool __fastcall ProcessHitTest(Winapi::Messages::TWMNCHitTest &Message) = 0 ;
};

class DELPHICLASS EdxWizardControlException;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxWizardControlException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxWizardControlException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxWizardControlException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxWizardControlException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxWizardControlException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxWizardControlException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxWizardControlException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxWizardControlException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxWizardControlException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxWizardControlException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxWizardControlException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxWizardControlException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxWizardControlException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxWizardControlException(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlCustomObject;
class DELPHICLASS TdxCustomWizardControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCustomObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomWizardControl* FWizardControl;
	
public:
	__fastcall virtual TdxWizardControlCustomObject(TdxCustomWizardControl* AWizardControl);
	__property TdxCustomWizardControl* WizardControl = {read=FWizardControl};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlCustomObject(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxWizardControlChangeEvent)(System::TObject* Sender, TdxWizardControlChanges AChanges);

class DELPHICLASS TdxWizardControlCustomPersistent;
class PASCALIMPLEMENTATION TdxWizardControlCustomPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxWizardControlChanges FChanges;
	int FLockCount;
	TdxWizardControlChangeEvent FOnChange;
	
protected:
	void __fastcall Changed(TdxWizardControlChanges AChanges);
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall DoChanged(TdxWizardControlChanges AChanges);
	__property TdxWizardControlChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxWizardControlCustomPersistent(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxWizardControlCustomPersistent(void) : System::Classes::TPersistent() { }
	
};


class DELPHICLASS TdxWizardControlHitTest;
class DELPHICLASS TdxWizardControlCellViewInfo;
class DELPHICLASS TdxWizardControlCustomButton;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlHitTest : public TdxWizardControlCustomObject
{
	typedef TdxWizardControlCustomObject inherited;
	
private:
	System::Uitypes::TCursor FCursor;
	TdxWizardControlCellViewInfo* FHitObject;
	System::Types::TPoint FHitPoint;
	bool __fastcall GetHitAtButton(void);
	bool __fastcall GetHitAtCommandArea(void);
	bool __fastcall GetHitAtHeader(void);
	bool __fastcall GetHitAtInfoPanel(void);
	bool __fastcall GetHitAtTitle(void);
	bool __fastcall GetHitAtWatermark(void);
	TdxWizardControlCustomButton* __fastcall GetHitObjectAsButton(void);
	void __fastcall SetHitPoint(const System::Types::TPoint &AValue);
	
public:
	void __fastcall Calculate(const System::Types::TPoint &APoint);
	__property System::Uitypes::TCursor Cursor = {read=FCursor, write=FCursor, nodefault};
	__property bool HitAtButton = {read=GetHitAtButton, nodefault};
	__property bool HitAtCommandArea = {read=GetHitAtCommandArea, nodefault};
	__property bool HitAtHeader = {read=GetHitAtHeader, nodefault};
	__property bool HitAtInfoPanel = {read=GetHitAtInfoPanel, nodefault};
	__property bool HitAtTitle = {read=GetHitAtTitle, nodefault};
	__property bool HitAtWatermark = {read=GetHitAtWatermark, nodefault};
	__property TdxWizardControlCellViewInfo* HitObject = {read=FHitObject, write=FHitObject};
	__property TdxWizardControlCustomButton* HitObjectAsButton = {read=GetHitObjectAsButton};
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=SetHitPoint};
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlHitTest(TdxCustomWizardControl* AWizardControl) : TdxWizardControlCustomObject(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlHitTest(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlCustomPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCustomPainter : public TdxWizardControlCustomObject
{
	typedef TdxWizardControlCustomObject inherited;
	
private:
	Vcl::Graphics::TFont* FHeaderDescriptionFont;
	Vcl::Graphics::TFont* FHeaderTitleFont;
	bool __fastcall GetIsFadingAvailable(void);
	bool __fastcall GetIsSkinUsed(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual System::Uitypes::TColor __fastcall GetCommandAreaDisabledTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetCommandAreaTextColor(void);
	virtual int __fastcall GetHeaderDescriptionOffset(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderDescriptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderTitleTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetHyperlinkColor(void);
	virtual int __fastcall GetSeparatorSize(void);
	virtual System::Uitypes::TColor __fastcall GetTitleTextColor(void);
	virtual void __fastcall InitializeFonts(void);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__fastcall virtual TdxWizardControlCustomPainter(TdxCustomWizardControl* AWizardControl);
	__fastcall virtual ~TdxWizardControlCustomPainter(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCommandAreaBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawHeaderBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawTitleBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual System::Types::TPoint __fastcall GetButtonOffset(Cxlookandfeelpainters::TcxButtonState AButtonState);
	virtual System::Uitypes::TColor __fastcall GetButtonTextColor(Cxlookandfeelpainters::TcxButtonState AButtonState);
	__property System::Uitypes::TColor CommandAreaDisabledTextColor = {read=GetCommandAreaDisabledTextColor, nodefault};
	__property System::Uitypes::TColor CommandAreaTextColor = {read=GetCommandAreaTextColor, nodefault};
	__property Vcl::Graphics::TFont* HeaderDescriptionFont = {read=FHeaderDescriptionFont};
	__property int HeaderDescriptionOffset = {read=GetHeaderDescriptionOffset, nodefault};
	__property System::Uitypes::TColor HeaderDescriptionTextColor = {read=GetHeaderDescriptionTextColor, nodefault};
	__property Vcl::Graphics::TFont* HeaderTitleFont = {read=FHeaderTitleFont};
	__property System::Uitypes::TColor HeaderTitleTextColor = {read=GetHeaderTitleTextColor, nodefault};
	__property System::Uitypes::TColor HyperlinkColor = {read=GetHyperlinkColor, nodefault};
	__property bool IsFadingAvailable = {read=GetIsFadingAvailable, nodefault};
	__property bool IsSkinUsed = {read=GetIsSkinUsed, nodefault};
	__property int SeparatorSize = {read=GetSeparatorSize, nodefault};
	__property System::Uitypes::TColor TitleTextColor = {read=GetTitleTextColor, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlImage;
class PASCALIMPLEMENTATION TdxWizardControlImage : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	Dxskinscore::TdxSkinImage* FImage;
	bool __fastcall GetEmpty(void);
	int __fastcall GetHeight(void);
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetImage(void);
	Cxgeometry::TcxMargin* __fastcall GetMargins(void);
	Dxskinscore::TdxSkinStretchMode __fastcall GetStretch(void);
	int __fastcall GetWidth(void);
	void __fastcall ImageChanged(System::TObject* Sender);
	void __fastcall SetImage(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetMargins(Cxgeometry::TcxMargin* AValue);
	void __fastcall SetStretch(const Dxskinscore::TdxSkinStretchMode Value);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall Reset(void);
	
public:
	__fastcall virtual TdxWizardControlImage(void);
	__fastcall virtual ~TdxWizardControlImage(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	__property bool Empty = {read=GetEmpty, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	
__published:
	__property Dxgdiplusclasses::TdxSmartImage* Image = {read=GetImage, write=SetImage};
	__property Cxgeometry::TcxMargin* Margins = {read=GetMargins, write=SetMargins};
	__property Dxskinscore::TdxSkinStretchMode Stretch = {read=GetStretch, write=SetStretch, default=0};
};


enum TdxWizardControlHeaderAssignedValue : unsigned char { wchvBackgroundImage, wchvDescriptionFont, wchvDescriptionVisibility, wchvDescriptionOffset, wchvGlyph, wchvGlyphVisibility, wchvTitleFont };

typedef System::Set<TdxWizardControlHeaderAssignedValue, TdxWizardControlHeaderAssignedValue::wchvBackgroundImage, TdxWizardControlHeaderAssignedValue::wchvTitleFont>  TdxWizardControlHeaderAssignedValues;

class DELPHICLASS TdxWizardControlHeader;
class PASCALIMPLEMENTATION TdxWizardControlHeader : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	TdxWizardControlHeaderAssignedValues FAssignedValues;
	TdxWizardControlImage* FBackgroundImage;
	Vcl::Graphics::TFont* FDescriptionFont;
	int FDescriptionOffset;
	Dxgdiplusclasses::TdxSmartImage* FGlyph;
	Vcl::Graphics::TFont* FTitleFont;
	TdxWizardControlElementVisibility FDescriptionVisibility;
	TdxWizardControlElementVisibility FGlyphVisibility;
	bool __fastcall CheckResetValue(TdxWizardControlHeaderAssignedValue AValue, const TdxWizardControlHeaderAssignedValues ANewAssignedValues);
	bool __fastcall IsBackgroundImageStored(void);
	bool __fastcall IsDescriptionFontStored(void);
	bool __fastcall IsDescriptionOffsetStored(void);
	bool __fastcall IsDescriptionVisibilityStored(void);
	bool __fastcall IsGlyphStored(void);
	bool __fastcall IsGlyphVisibilityStored(void);
	bool __fastcall IsTitleFontStored(void);
	void __fastcall BackgroundImageChanged(System::TObject* Sender, TdxWizardControlChanges AChanges);
	void __fastcall DescriptionFontChanged(System::TObject* Sender);
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall TitleFontChanged(System::TObject* Sender);
	void __fastcall SetAssignedValues(TdxWizardControlHeaderAssignedValues AValue);
	void __fastcall SetBackgroundImage(TdxWizardControlImage* AValue);
	void __fastcall SetDescriptionFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetDescriptionOffset(const int AValue);
	void __fastcall SetDescriptionVisibility(TdxWizardControlElementVisibility AValue);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetGlyphVisibility(TdxWizardControlElementVisibility AValue);
	void __fastcall SetTitleFont(Vcl::Graphics::TFont* AValue);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxWizardControlHeader(void);
	__fastcall virtual ~TdxWizardControlHeader(void);
	
__published:
	__property TdxWizardControlHeaderAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, default=0};
	__property TdxWizardControlImage* BackgroundImage = {read=FBackgroundImage, write=SetBackgroundImage, stored=IsBackgroundImageStored};
	__property Vcl::Graphics::TFont* DescriptionFont = {read=FDescriptionFont, write=SetDescriptionFont, stored=IsDescriptionFontStored};
	__property int DescriptionOffset = {read=FDescriptionOffset, write=SetDescriptionOffset, stored=IsDescriptionOffsetStored, nodefault};
	__property TdxWizardControlElementVisibility DescriptionVisibility = {read=FDescriptionVisibility, write=SetDescriptionVisibility, stored=IsDescriptionVisibilityStored, nodefault};
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=FGlyph, write=SetGlyph, stored=IsGlyphStored};
	__property TdxWizardControlElementVisibility GlyphVisibility = {read=FGlyphVisibility, write=SetGlyphVisibility, stored=IsGlyphVisibilityStored, nodefault};
	__property Vcl::Graphics::TFont* TitleFont = {read=FTitleFont, write=SetTitleFont, stored=IsTitleFontStored};
};


class DELPHICLASS TdxWizardControlTitle;
class PASCALIMPLEMENTATION TdxWizardControlTitle : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	bool FFontChanged;
	Dxgdiplusclasses::TdxSmartImage* FGlyph;
	System::UnicodeString FText;
	void __fastcall ChangeHandler(System::TObject* Sender);
	bool __fastcall IsFontStored(void);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetText(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxWizardControlTitle(void);
	__fastcall virtual ~TdxWizardControlTitle(void);
	
__published:
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=FGlyph, write=SetGlyph};
	__property System::UnicodeString Text = {read=FText, write=SetText};
};


enum TdxWizardControlWatermarkAssignedValue : unsigned char { wcwavBackgroundImage, wcwavVisibility };

typedef System::Set<TdxWizardControlWatermarkAssignedValue, TdxWizardControlWatermarkAssignedValue::wcwavBackgroundImage, TdxWizardControlWatermarkAssignedValue::wcwavVisibility>  TdxWizardControlWatermarkAssignedValues;

class DELPHICLASS TdxWizardControlWatermark;
class PASCALIMPLEMENTATION TdxWizardControlWatermark : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	TdxWizardControlWatermarkAssignedValues FAssignedValues;
	TdxWizardControlImage* FBackgroundImage;
	TdxWizardControlElementVisibility FVisibility;
	bool __fastcall CheckResetValue(TdxWizardControlWatermarkAssignedValue AValue, const TdxWizardControlWatermarkAssignedValues ANewAssignedValues);
	void __fastcall BackgroundImageChanged(System::TObject* Sender, TdxWizardControlChanges AChanges);
	void __fastcall SetAssignedValues(TdxWizardControlWatermarkAssignedValues AValue);
	void __fastcall SetBackgroundImage(TdxWizardControlImage* AValue);
	void __fastcall SetVisibility(TdxWizardControlElementVisibility AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual bool __fastcall IsVisibilityStored(void);
	__property TdxWizardControlWatermarkAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, nodefault};
	
public:
	__fastcall virtual TdxWizardControlWatermark(void);
	__fastcall virtual ~TdxWizardControlWatermark(void);
	
__published:
	__property TdxWizardControlImage* BackgroundImage = {read=FBackgroundImage, write=SetBackgroundImage};
	__property TdxWizardControlElementVisibility Visibility = {read=FVisibility, write=SetVisibility, stored=IsVisibilityStored, nodefault};
};


class DELPHICLASS TdxWizardControlPageWatermark;
class PASCALIMPLEMENTATION TdxWizardControlPageWatermark : public TdxWizardControlWatermark
{
	typedef TdxWizardControlWatermark inherited;
	
protected:
	bool __fastcall IsBackgroundImageStored(void);
	virtual bool __fastcall IsVisibilityStored(void);
	
__published:
	__property AssignedValues = {default=0};
	__property BackgroundImage = {stored=IsBackgroundImageStored};
public:
	/* TdxWizardControlWatermark.Create */ inline __fastcall virtual TdxWizardControlPageWatermark(void) : TdxWizardControlWatermark() { }
	/* TdxWizardControlWatermark.Destroy */ inline __fastcall virtual ~TdxWizardControlPageWatermark(void) { }
	
};


class DELPHICLASS TdxWizardControlInfoPanel;
class PASCALIMPLEMENTATION TdxWizardControlInfoPanel : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	System::UnicodeString FCaption;
	bool FEnabled;
	Vcl::Graphics::TFont* FFont;
	bool FFontChanged;
	System::UnicodeString FHyperlink;
	System::Uitypes::TColor FHyperlinkColor;
	bool FVisible;
	bool __fastcall IsFontStored(void);
	void __fastcall FontChangeHandler(System::TObject* Sender);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetEnabled(const bool AValue);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetHyperlink(const System::UnicodeString AValue);
	void __fastcall SetHyperlinkColor(const System::Uitypes::TColor Value);
	void __fastcall SetVisible(const bool AValue);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxWizardControlInfoPanel(void);
	__fastcall virtual ~TdxWizardControlInfoPanel(void);
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property System::UnicodeString Hyperlink = {read=FHyperlink, write=SetHyperlink};
	__property System::Uitypes::TColor HyperlinkColor = {read=FHyperlinkColor, write=SetHyperlinkColor, default=536870912};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


class DELPHICLASS TdxWizardControlPageHeader;
class PASCALIMPLEMENTATION TdxWizardControlPageHeader : public TdxWizardControlHeader
{
	typedef TdxWizardControlHeader inherited;
	
private:
	System::UnicodeString FDescription;
	System::UnicodeString FTitle;
	bool __fastcall IsDescriptionStored(void);
	bool __fastcall IsTitleStored(void);
	void __fastcall ReadDescription(System::Classes::TReader* Reader);
	void __fastcall ReadTitle(System::Classes::TReader* Reader);
	void __fastcall SetDescription(const System::UnicodeString AValue);
	void __fastcall SetTitle(const System::UnicodeString AValue);
	void __fastcall WriteDescrption(System::Classes::TWriter* Writer);
	void __fastcall WriteTitle(System::Classes::TWriter* Writer);
	
protected:
	System::UnicodeString __fastcall GetDefaultDescription(void);
	System::UnicodeString __fastcall GetDefaultTitle(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxWizardControlPageHeader(void);
	
__published:
	__property System::UnicodeString Description = {read=FDescription, write=SetDescription, stored=IsDescriptionStored};
	__property System::UnicodeString Title = {read=FTitle, write=SetTitle, stored=IsTitleStored};
public:
	/* TdxWizardControlHeader.Destroy */ inline __fastcall virtual ~TdxWizardControlPageHeader(void) { }
	
};


class DELPHICLASS TdxWizardControlButtons;
class PASCALIMPLEMENTATION TdxWizardControlCustomButton : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	TdxWizardControlButtons* FButtons;
	System::UnicodeString FCaption;
	bool FCaptionIsDefault;
	bool FEnabled;
	Dxgdiplusclasses::TdxSmartImage* FGlyph;
	Vcl::Buttons::TButtonLayout FGlyphAlignment;
	System::Uitypes::TImageIndex FImageIndex;
	bool FVisible;
	int FWidth;
	bool __fastcall IsCaptionStored(void);
	void __fastcall GlyphChangeHandler(System::TObject* Sender);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetEnabled(const bool AValue);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartImage* AValue);
	void __fastcall SetGlyphAlignment(const Vcl::Buttons::TButtonLayout AValue);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetVisible(const bool AValue);
	void __fastcall SetWidth(const int AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaption(void) = 0 ;
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	__property bool CaptionIsDefault = {read=FCaptionIsDefault, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	
public:
	__fastcall virtual TdxWizardControlCustomButton(TdxWizardControlButtons* AButtons);
	__fastcall virtual ~TdxWizardControlCustomButton(void);
	__property TdxWizardControlButtons* Buttons = {read=FButtons};
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=FGlyph, write=SetGlyph};
	__property Vcl::Buttons::TButtonLayout GlyphAlignment = {read=FGlyphAlignment, write=SetGlyphAlignment, default=0};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
};


class DELPHICLASS TdxWizardControlBackButton;
class PASCALIMPLEMENTATION TdxWizardControlBackButton : public TdxWizardControlCustomButton
{
	typedef TdxWizardControlCustomButton inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
public:
	/* TdxWizardControlCustomButton.Create */ inline __fastcall virtual TdxWizardControlBackButton(TdxWizardControlButtons* AButtons) : TdxWizardControlCustomButton(AButtons) { }
	/* TdxWizardControlCustomButton.Destroy */ inline __fastcall virtual ~TdxWizardControlBackButton(void) { }
	
};


class DELPHICLASS TdxWizardControlCancelButton;
class PASCALIMPLEMENTATION TdxWizardControlCancelButton : public TdxWizardControlCustomButton
{
	typedef TdxWizardControlCustomButton inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
	
__published:
	__property Visible = {default=1};
public:
	/* TdxWizardControlCustomButton.Create */ inline __fastcall virtual TdxWizardControlCancelButton(TdxWizardControlButtons* AButtons) : TdxWizardControlCustomButton(AButtons) { }
	/* TdxWizardControlCustomButton.Destroy */ inline __fastcall virtual ~TdxWizardControlCancelButton(void) { }
	
};


class DELPHICLASS TdxWizardControlFinishButton;
class PASCALIMPLEMENTATION TdxWizardControlFinishButton : public TdxWizardControlCustomButton
{
	typedef TdxWizardControlCustomButton inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
public:
	/* TdxWizardControlCustomButton.Create */ inline __fastcall virtual TdxWizardControlFinishButton(TdxWizardControlButtons* AButtons) : TdxWizardControlCustomButton(AButtons) { }
	/* TdxWizardControlCustomButton.Destroy */ inline __fastcall virtual ~TdxWizardControlFinishButton(void) { }
	
};


class DELPHICLASS TdxWizardControlHelpButton;
class PASCALIMPLEMENTATION TdxWizardControlHelpButton : public TdxWizardControlCustomButton
{
	typedef TdxWizardControlCustomButton inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
	
__published:
	__property Visible = {default=1};
public:
	/* TdxWizardControlCustomButton.Create */ inline __fastcall virtual TdxWizardControlHelpButton(TdxWizardControlButtons* AButtons) : TdxWizardControlCustomButton(AButtons) { }
	/* TdxWizardControlCustomButton.Destroy */ inline __fastcall virtual ~TdxWizardControlHelpButton(void) { }
	
};


class DELPHICLASS TdxWizardControlNextButton;
class PASCALIMPLEMENTATION TdxWizardControlNextButton : public TdxWizardControlCustomButton
{
	typedef TdxWizardControlCustomButton inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultCaption(void);
public:
	/* TdxWizardControlCustomButton.Create */ inline __fastcall virtual TdxWizardControlNextButton(TdxWizardControlButtons* AButtons) : TdxWizardControlCustomButton(AButtons) { }
	/* TdxWizardControlCustomButton.Destroy */ inline __fastcall virtual ~TdxWizardControlNextButton(void) { }
	
};


class DELPHICLASS TdxWizardControlOptionsButtons;
class PASCALIMPLEMENTATION TdxWizardControlOptionsButtons : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	int FHeight;
	int FWidth;
	void __fastcall SetHeight(const int AValue);
	void __fastcall SetWidth(const int AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
__published:
	__property int Height = {read=FHeight, write=SetHeight, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxWizardControlOptionsButtons(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxWizardControlOptionsButtons(void) : TdxWizardControlCustomPersistent() { }
	
};


class PASCALIMPLEMENTATION TdxWizardControlButtons : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	TdxWizardControlBackButton* FBack;
	TdxWizardControlCancelButton* FCancel;
	TdxWizardControlOptionsButtons* FCommon;
	TdxWizardControlFinishButton* FFinish;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	TdxWizardControlHelpButton* FHelp;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	TdxWizardControlNextButton* FNext;
	void __fastcall ChangeHandler(System::TObject* Sender, TdxWizardControlChanges AChanges);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetBack(TdxWizardControlBackButton* AValue);
	void __fastcall SetCancel(TdxWizardControlCancelButton* AValue);
	void __fastcall SetCommon(TdxWizardControlOptionsButtons* AValue);
	void __fastcall SetFinish(TdxWizardControlFinishButton* AValue);
	void __fastcall SetHelp(TdxWizardControlHelpButton* AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetNext(TdxWizardControlNextButton* AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	virtual void __fastcall UpdateTranslation(void);
	__property Dxcoreclasses::TcxFreeNotificator* FreeNotificator = {read=FFreeNotificator};
	
public:
	__fastcall virtual TdxWizardControlButtons(void);
	__fastcall virtual ~TdxWizardControlButtons(void);
	
__published:
	__property TdxWizardControlBackButton* Back = {read=FBack, write=SetBack};
	__property TdxWizardControlCancelButton* Cancel = {read=FCancel, write=SetCancel};
	__property TdxWizardControlOptionsButtons* Common = {read=FCommon, write=SetCommon};
	__property TdxWizardControlFinishButton* Finish = {read=FFinish, write=SetFinish};
	__property TdxWizardControlHelpButton* Help = {read=FHelp, write=SetHelp};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TdxWizardControlNextButton* Next = {read=FNext, write=SetNext};
};


class DELPHICLASS TdxWizardControlOptionsAnimate;
class PASCALIMPLEMENTATION TdxWizardControlOptionsAnimate : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	TdxWizardControlResizeAnimation FResizeAnimation;
	TdxWizardControlTransitionEffect FTransitionEffect;
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxWizardControlResizeAnimation ResizeAnimation = {read=FResizeAnimation, write=FResizeAnimation, default=0};
	__property TdxWizardControlTransitionEffect TransitionEffect = {read=FTransitionEffect, write=FTransitionEffect, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxWizardControlOptionsAnimate(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxWizardControlOptionsAnimate(void) : TdxWizardControlCustomPersistent() { }
	
};


class DELPHICLASS TdxWizardControlOptionsViewStyleAero;
class PASCALIMPLEMENTATION TdxWizardControlOptionsViewStyleAero : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	bool FEnableTitleAero;
	TdxWizardControlTitle* FTitle;
	void __fastcall ChangeHandler(System::TObject* Sender, TdxWizardControlChanges AChanges);
	void __fastcall SetEnableTitleAero(bool AValue);
	void __fastcall SetTitle(TdxWizardControlTitle* AValue);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
public:
	__fastcall virtual TdxWizardControlOptionsViewStyleAero(void);
	__fastcall virtual ~TdxWizardControlOptionsViewStyleAero(void);
	
__published:
	__property bool EnableTitleAero = {read=FEnableTitleAero, write=SetEnableTitleAero, default=1};
	__property TdxWizardControlTitle* Title = {read=FTitle, write=SetTitle};
};


typedef System::TMetaClass* TdxWizardControlCellViewInfoClass;

class DELPHICLASS TdxWizardControlController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCellViewInfo : public TdxWizardControlCustomObject
{
	typedef TdxWizardControlCustomObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxWizardControlController* __fastcall GetController(void);
	TdxWizardControlCustomPainter* __fastcall GetPainter(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetBounds(const System::Types::TRect &ABounds);
	
protected:
	virtual bool __fastcall CanDrawContent(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawChildren(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall IsEnabled(void);
	virtual bool __fastcall IsFocused(void);
	virtual bool __fastcall IsHot(void);
	virtual bool __fastcall IsPressed(void);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	
public:
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall Calculate(void);
	virtual bool __fastcall CalculateHitTest(TdxWizardControlHitTest* AHitTest);
	virtual bool __fastcall CanFocus(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Invalidate(void);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	virtual void __fastcall RefreshState(void);
	__property System::Types::TRect Bounds = {read=FBounds, write=SetBounds};
	__property TdxWizardControlController* Controller = {read=GetController};
	__property TdxWizardControlCustomPainter* Painter = {read=GetPainter};
	__property bool Visible = {read=GetVisible, nodefault};
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlCellViewInfo(TdxCustomWizardControl* AWizardControl) : TdxWizardControlCustomObject(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlCellViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlCellViewInfoList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCellViewInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxWizardControlCellViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxWizardControlCellViewInfo* __fastcall GetItem(int Index);
	
public:
	HIDESBASE int __fastcall Add(TdxWizardControlCellViewInfo* ACustomCellViewInfo);
	bool __fastcall CalculateHitTest(TdxWizardControlHitTest* AHitTest);
	int __fastcall MaxMeasureHeight(void);
	int __fastcall MaxMeasureWidth(void);
	bool __fastcall ProcessDialogChar(System::Word ACharCode);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall RefreshState(void);
	__property TdxWizardControlCellViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxWizardControlCellViewInfoList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxWizardControlCellViewInfoList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlContainerCellViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlContainerCellViewInfo : public TdxWizardControlCellViewInfo
{
	typedef TdxWizardControlCellViewInfo inherited;
	
private:
	TdxWizardControlCellViewInfoList* FCellList;
	
protected:
	TdxWizardControlCellViewInfo* __fastcall AddCell(TdxWizardControlCellViewInfoClass ACellClass);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual void __fastcall DrawChildren(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxWizardControlContainerCellViewInfo(TdxCustomWizardControl* AWizardControl);
	__fastcall virtual ~TdxWizardControlContainerCellViewInfo(void);
	virtual bool __fastcall CalculateHitTest(TdxWizardControlHitTest* AHitTest);
	virtual void __fastcall RefreshState(void);
	__property TdxWizardControlCellViewInfoList* CellList = {read=FCellList};
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlButtonFadingHelper;
class DELPHICLASS TdxWizardControlButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlButtonFadingHelper : public Dxfading::TdxFadingObjectHelper
{
	typedef Dxfading::TdxFadingObjectHelper inherited;
	
private:
	TdxWizardControlButtonViewInfo* FButtonViewInfo;
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall DrawFadeImage(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	__property TdxWizardControlButtonViewInfo* ButtonViewInfo = {read=FButtonViewInfo};
	
public:
	__fastcall virtual TdxWizardControlButtonFadingHelper(TdxWizardControlButtonViewInfo* AViewInfo);
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TdxWizardControlButtonFadingHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxWizardControlButtonViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlButtonViewInfo : public TdxWizardControlCellViewInfo
{
	typedef TdxWizardControlCellViewInfo inherited;
	
private:
	TdxWizardControlCustomButton* FButton;
	TdxWizardControlButtonFadingHelper* FFadingHelper;
	Cxlookandfeelpainters::TcxButtonState FState;
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::Types::TSize __fastcall GetGlyphSize(void);
	void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState AState);
	
protected:
	System::Types::TRect FCaptionRect;
	System::Types::TRect FGlyphRect;
	virtual void __fastcall CalculateCaptionRect(void);
	virtual void __fastcall CalculateGlyphRect(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall CalculateState(void);
	virtual void __fastcall DrawButtonBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetMargins(void);
	virtual bool __fastcall IsDefault(void);
	virtual bool __fastcall IsEnabled(void);
	bool __fastcall IsImageAvailable(void);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	__property TdxWizardControlCustomButton* Button = {read=FButton};
	__property TdxWizardControlButtonFadingHelper* FadingHelper = {read=FFadingHelper};
	
public:
	__fastcall virtual TdxWizardControlButtonViewInfo(TdxCustomWizardControl* AControl, TdxWizardControlCustomButton* AButton);
	__fastcall virtual ~TdxWizardControlButtonViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall IsFadingAvailable(void);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	virtual void __fastcall RefreshState(void);
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property System::Types::TRect GlyphRect = {read=FGlyphRect};
	__property System::Types::TSize GlyphSize = {read=GetGlyphSize};
	__property System::Types::TRect Margins = {read=GetMargins};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlBackButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlBackButtonViewInfo : public TdxWizardControlButtonViewInfo
{
	typedef TdxWizardControlButtonViewInfo inherited;
	
protected:
	virtual bool __fastcall IsEnabled(void);
public:
	/* TdxWizardControlButtonViewInfo.Create */ inline __fastcall virtual TdxWizardControlBackButtonViewInfo(TdxCustomWizardControl* AControl, TdxWizardControlCustomButton* AButton) : TdxWizardControlButtonViewInfo(AControl, AButton) { }
	/* TdxWizardControlButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlBackButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlNextButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlNextButtonViewInfo : public TdxWizardControlButtonViewInfo
{
	typedef TdxWizardControlButtonViewInfo inherited;
	
protected:
	virtual bool __fastcall IsEnabled(void);
public:
	/* TdxWizardControlButtonViewInfo.Create */ inline __fastcall virtual TdxWizardControlNextButtonViewInfo(TdxCustomWizardControl* AControl, TdxWizardControlCustomButton* AButton) : TdxWizardControlButtonViewInfo(AControl, AButton) { }
	/* TdxWizardControlButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlNextButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlInfoPanelViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlInfoPanelViewInfo : public TdxWizardControlCellViewInfo
{
	typedef TdxWizardControlCellViewInfo inherited;
	
private:
	TdxWizardControlInfoPanel* FInfoPanel;
	Cxlookandfeelpainters::TcxButtonState FState;
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::Uitypes::TFontStyles __fastcall GetFontStyle(void);
	bool __fastcall GetIsHyperlinkMode(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState AState);
	
protected:
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxWizardControlInfoPanelViewInfo(TdxCustomWizardControl* AControl);
	virtual bool __fastcall CalculateHitTest(TdxWizardControlHitTest* AHitTest);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	virtual void __fastcall RefreshState(void);
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property System::Uitypes::TFontStyles FontStyle = {read=GetFontStyle, nodefault};
	__property TdxWizardControlInfoPanel* InfoPanel = {read=FInfoPanel};
	__property bool IsHyperlinkMode = {read=GetIsHyperlinkMode, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlInfoPanelViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlCustomCommandAreaViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCustomCommandAreaViewInfo : public TdxWizardControlContainerCellViewInfo
{
	typedef TdxWizardControlContainerCellViewInfo inherited;
	
private:
	TdxWizardControlButtonViewInfo* FCancelButtonViewInfo;
	TdxWizardControlButtonViewInfo* FFinishButtonViewInfo;
	TdxWizardControlButtonViewInfo* FHelpButtonViewInfo;
	TdxWizardControlCellViewInfo* FInfoPanelViewInfo;
	TdxWizardControlButtonViewInfo* FNextButtonViewInfo;
	TdxWizardControlButtonViewInfo* __fastcall GetActualNextButtonViewInfo(void);
	TdxWizardControlButtons* __fastcall GetButtons(void);
	
protected:
	int FButtonsMaxMeasureHeight;
	TdxWizardControlButtonViewInfo* __fastcall AddButtonCell(TdxWizardControlCustomButton* AButton, TdxWizardControlButtonViewInfoClass AViewInfoClass);
	bool __fastcall AlignButtonToRightSide(TdxWizardControlButtonViewInfo* AButtonViewInfo, System::Types::TRect &R);
	int __fastcall MeasureButtonWidth(TdxWizardControlButtonViewInfo* AButtonViewInfo, int AIndent);
	virtual void __fastcall CalculateButtons(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateInfoPanel(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateButtonsMaxMeasureHeight(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetContentMargins(void) = 0 ;
	virtual int __fastcall GetIndentBetweenElementsInGroup(void) = 0 ;
	virtual int __fastcall GetIndentBetweenGroups(void) = 0 ;
	__property TdxWizardControlButtonViewInfo* ActualNextButtonViewInfo = {read=GetActualNextButtonViewInfo};
	__property int ButtonsMaxMeasureHeight = {read=FButtonsMaxMeasureHeight, nodefault};
	__property TdxWizardControlButtonViewInfo* CancelButtonViewInfo = {read=FCancelButtonViewInfo};
	__property TdxWizardControlButtonViewInfo* FinishButtonViewInfo = {read=FFinishButtonViewInfo};
	__property TdxWizardControlButtonViewInfo* HelpButtonViewInfo = {read=FHelpButtonViewInfo};
	__property TdxWizardControlCellViewInfo* InfoPanelViewInfo = {read=FInfoPanelViewInfo};
	__property TdxWizardControlButtonViewInfo* NextButtonViewInfo = {read=FNextButtonViewInfo};
	
public:
	__fastcall virtual TdxWizardControlCustomCommandAreaViewInfo(TdxCustomWizardControl* AWizardControl);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	__property TdxWizardControlButtons* Buttons = {read=GetButtons};
	__property System::Types::TRect ContentMargins = {read=GetContentMargins};
	__property int IndentBetweenElementsInGroup = {read=GetIndentBetweenElementsInGroup, nodefault};
	__property int IndentBetweenGroups = {read=GetIndentBetweenGroups, nodefault};
public:
	/* TdxWizardControlContainerCellViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlCustomCommandAreaViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlCustomHeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCustomHeaderViewInfo : public TdxWizardControlCellViewInfo
{
	typedef TdxWizardControlCellViewInfo inherited;
	
private:
	TdxWizardControlImage* __fastcall GetBackgroundImage(void);
	Vcl::Graphics::TFont* __fastcall GetDescriptionFont(void);
	int __fastcall GetDescriptionOffset(void);
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetGlyph(void);
	System::Types::TSize __fastcall GetGlyphSize(void);
	TdxWizardControlPageHeader* __fastcall GetHeader(void);
	Vcl::Graphics::TFont* __fastcall GetTitleFont(void);
	
protected:
	System::Types::TRect FDescriptionRect;
	System::Types::TRect FGlyphRect;
	System::Types::TRect FTitleRect;
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetActualSettings(TdxWizardControlHeaderAssignedValue AValue, /* out */ TdxWizardControlHeader* &AActualSettings);
	virtual bool __fastcall GetBackgroundImageIsAvailable(void);
	virtual System::Types::TRect __fastcall GetContentMargins(void) = 0 ;
	virtual bool __fastcall GetDescriptionIsVisible(void) = 0 ;
	virtual bool __fastcall GetGlyphIsVisible(void) = 0 ;
	virtual int __fastcall GetIndentBetweenElemenets(void) = 0 ;
	__property TdxWizardControlPageHeader* Header = {read=GetHeader};
	
public:
	virtual void __fastcall Calculate(void);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	__property TdxWizardControlImage* BackgroundImage = {read=GetBackgroundImage};
	__property bool BackgroundImageIsAvailable = {read=GetBackgroundImageIsAvailable, nodefault};
	__property System::Types::TRect ContentMargins = {read=GetContentMargins};
	__property Vcl::Graphics::TFont* DescriptionFont = {read=GetDescriptionFont};
	__property bool DescriptionIsVisible = {read=GetDescriptionIsVisible, nodefault};
	__property int DescriptionOffset = {read=GetDescriptionOffset, nodefault};
	__property System::Types::TRect DescriptionRect = {read=FDescriptionRect};
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=GetGlyph};
	__property bool GlyphIsVisible = {read=GetGlyphIsVisible, nodefault};
	__property System::Types::TRect GlyphRect = {read=FGlyphRect};
	__property System::Types::TSize GlyphSize = {read=GetGlyphSize};
	__property int IndentBetweenElemenets = {read=GetIndentBetweenElemenets, nodefault};
	__property Vcl::Graphics::TFont* TitleFont = {read=GetTitleFont};
	__property System::Types::TRect TitleRect = {read=FTitleRect};
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlCustomHeaderViewInfo(TdxCustomWizardControl* AWizardControl) : TdxWizardControlCellViewInfo(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlCustomHeaderViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlCustomTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCustomTitleViewInfo : public TdxWizardControlContainerCellViewInfo
{
	typedef TdxWizardControlContainerCellViewInfo inherited;
	
private:
	bool FIsPaintOnGlass;
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	TdxWizardControlTitle* __fastcall GetTitle(void);
	
protected:
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__property bool IsPaintOnGlass = {read=FIsPaintOnGlass, write=FIsPaintOnGlass, nodefault};
	__property TdxWizardControlTitle* Title = {read=GetTitle};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
public:
	/* TdxWizardControlContainerCellViewInfo.Create */ inline __fastcall virtual TdxWizardControlCustomTitleViewInfo(TdxCustomWizardControl* AWizardControl) : TdxWizardControlContainerCellViewInfo(AWizardControl) { }
	/* TdxWizardControlContainerCellViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlCustomTitleViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlWatermarkViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlWatermarkViewInfo : public TdxWizardControlCellViewInfo
{
	typedef TdxWizardControlCellViewInfo inherited;
	
private:
	TdxWizardControlImage* __fastcall GetWatermakImage(void);
	TdxWizardControlElementVisibility __fastcall GetWatermakVisibility(void);
	
protected:
	virtual bool __fastcall GetIsImageAvailable(void);
	virtual bool __fastcall GetIsImageVisible(void) = 0 ;
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	__property bool IsImageAvailable = {read=GetIsImageAvailable, nodefault};
	__property bool IsImageVisible = {read=GetIsImageVisible, nodefault};
	__property TdxWizardControlImage* WatermakImage = {read=GetWatermakImage};
	__property TdxWizardControlElementVisibility WatermakVisibility = {read=GetWatermakVisibility, nodefault};
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlWatermarkViewInfo(TdxCustomWizardControl* AWizardControl) : TdxWizardControlCellViewInfo(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlWatermarkViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewInfo : public TdxWizardControlContainerCellViewInfo
{
	typedef TdxWizardControlContainerCellViewInfo inherited;
	
private:
	System::Types::TRect FContentBounds;
	TdxWizardControlCustomCommandAreaViewInfo* FCommandAreaViewInfo;
	TdxWizardControlCellViewInfo* FHeaderViewInfo;
	TdxWizardControlCustomPainter* FPainter;
	TdxWizardControlCustomTitleViewInfo* FTitleViewInfo;
	TdxWizardControlWatermarkViewInfo* FWatermarkViewInfo;
	
protected:
	System::Types::TRect FPageArea;
	virtual void __fastcall CalculateCells(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateCommandArea(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateHeader(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateTitleViewInfo(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateWatermark(System::Types::TRect &ABounds);
	virtual TdxWizardControlCustomCommandAreaViewInfo* __fastcall CreateCommandAreaViewInfo(void) = 0 ;
	virtual TdxWizardControlCustomHeaderViewInfo* __fastcall CreateHeaderViewInfo(void) = 0 ;
	virtual TdxWizardControlCustomPainter* __fastcall CreatePainter(void) = 0 ;
	virtual TdxWizardControlCustomTitleViewInfo* __fastcall CreateTitleViewInfo(void);
	virtual TdxWizardControlWatermarkViewInfo* __fastcall CreateWatermarkViewInfo(void) = 0 ;
	virtual void __fastcall CellsCreate(void);
	virtual void __fastcall CellsFree(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual TdxWizardControlResizeAnimation __fastcall GetDefaultResizeAnimation(void) = 0 ;
	virtual TdxWizardControlTransitionEffect __fastcall GetDefaultTransitionEffect(void) = 0 ;
	virtual System::Types::TRect __fastcall GetTransitionEffectAreaBounds(void);
	
public:
	__fastcall virtual TdxWizardControlViewInfo(TdxCustomWizardControl* AWizardControl);
	__fastcall virtual ~TdxWizardControlViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall GetTabOrderList(TdxWizardControlCellViewInfoList* AList);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	void __fastcall RecreateCells(void);
	__property System::Types::TRect ContentBounds = {read=FContentBounds};
	__property System::Types::TRect PageArea = {read=FPageArea};
	__property TdxWizardControlCustomPainter* Painter = {read=FPainter};
	__property TdxWizardControlCustomCommandAreaViewInfo* CommandAreaViewInfo = {read=FCommandAreaViewInfo};
	__property TdxWizardControlCellViewInfo* HeaderViewInfo = {read=FHeaderViewInfo};
	__property TdxWizardControlCustomTitleViewInfo* TitleViewInfo = {read=FTitleViewInfo};
	__property TdxWizardControlWatermarkViewInfo* WatermarkViewInfo = {read=FWatermarkViewInfo};
	__property TdxWizardControlResizeAnimation DefaultResizeAnimation = {read=GetDefaultResizeAnimation, nodefault};
	__property TdxWizardControlTransitionEffect DefaultTransitionEffect = {read=GetDefaultTransitionEffect, nodefault};
	__property System::Types::TRect TransitionEffectAreaBounds = {read=GetTransitionEffectAreaBounds};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlController : public TdxWizardControlCustomObject
{
	typedef TdxWizardControlCustomObject inherited;
	
private:
	TdxWizardControlCellViewInfo* FFocusedCell;
	TdxWizardControlHitTest* FHitTest;
	TdxWizardControlCellViewInfo* FHotCell;
	TdxWizardControlCellViewInfo* FPressedCell;
	TdxWizardControlCellViewInfo* FPrevFocusedCell;
	TdxWizardControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetHotCell(TdxWizardControlCellViewInfo* AValue);
	void __fastcall SetPressedCell(TdxWizardControlCellViewInfo* AValue);
	void __fastcall SetFocusedCell(TdxWizardControlCellViewInfo* AValue);
	
protected:
	virtual void __fastcall CalculateHitTest(int X, int Y);
	virtual void __fastcall CellRemoving(TdxWizardControlCellViewInfo* ACell);
	bool __fastcall GetButtonKind(TdxWizardControlCustomButton* AButton, /* out */ TdxWizardControlButtonKind &AKind);
	virtual void __fastcall ProcessAccel(TdxWizardControlCellViewInfo* ACell);
	virtual void __fastcall ProcessButtonClick(TdxWizardControlCustomButton* AButton);
	virtual void __fastcall ProcessClick(TdxWizardControlCellViewInfo* ACell);
	virtual void __fastcall ProcessInfoPanelClick(TdxWizardControlInfoPanel* AInfoPanel);
	
public:
	__fastcall virtual TdxWizardControlController(TdxCustomWizardControl* AWizardControl);
	__fastcall virtual ~TdxWizardControlController(void);
	virtual void __fastcall RefreshState(void);
	TdxWizardControlCellViewInfo* __fastcall FindNextFocusableCell(TdxWizardControlCellViewInfo* ACell, bool AGoForward);
	virtual void __fastcall FocusKill(void);
	void __fastcall FocusNextCell(bool AGoForward);
	virtual void __fastcall FocusSet(void);
	void __fastcall ValidateFocusedCell(void);
	virtual bool __fastcall ProcessChildKey(System::Word AKey, System::Classes::TShiftState AShiftState);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual void __fastcall KeyDown(System::Word AKey, System::Classes::TShiftState AShiftState);
	virtual void __fastcall KeyUp(System::Word AKey, System::Classes::TShiftState AShiftState);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property TdxWizardControlCellViewInfo* FocusedCell = {read=FFocusedCell, write=SetFocusedCell};
	__property TdxWizardControlHitTest* HitTest = {read=FHitTest};
	__property TdxWizardControlCellViewInfo* HotCell = {read=FHotCell, write=SetHotCell};
	__property TdxWizardControlCellViewInfo* PressedCell = {read=FPressedCell, write=SetPressedCell};
	__property TdxWizardControlViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlDesignSelector;
class PASCALIMPLEMENTATION TdxWizardControlDesignSelector : public Cxcontrols::TcxDesignSelector
{
	typedef Cxcontrols::TcxDesignSelector inherited;
	
private:
	TdxWizardControlCustomPage* __fastcall GetPage(void);
	
protected:
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall GetSelected(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
public:
	__property TdxWizardControlCustomPage* Page = {read=GetPage};
public:
	/* TcxDesignSelector.Create */ inline __fastcall virtual TdxWizardControlDesignSelector(System::Classes::TComponent* AOwner) : Cxcontrols::TcxDesignSelector(AOwner) { }
	
public:
	/* TcxControl.Destroy */ inline __fastcall virtual ~TdxWizardControlDesignSelector(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlDesignSelector(HWND ParentWindow) : Cxcontrols::TcxDesignSelector(ParentWindow) { }
	
};


enum TdxWizardControlAnimationControllerStage : unsigned char { wctacsPrepare, wctacsTransition, wctacsResizing };

class DELPHICLASS TdxWizardControlAnimationController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlAnimationController : public TdxWizardControlCustomObject
{
	typedef TdxWizardControlCustomObject inherited;
	
private:
	bool FActive;
	System::Types::TRect FAnimatedRect;
	Dxanimation::TdxImageAnimationTransition* FAnimation;
	bool FSuppressContentDrawing;
	bool __fastcall GetActualResizeAnimation(void);
	TdxWizardControlTransitionEffect __fastcall GetActualTransitionEffect(void);
	bool __fastcall GetAutoSize(void);
	TdxWizardControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall AnimationHandler(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	
protected:
	TdxWizardControlAnimationControllerStage FStage;
	Dxanimation::TdxDrawAnimationMode __fastcall CalculateAnimationMode(TdxWizardControlCustomPage* ANewPage, TdxWizardControlCustomPage* APrevPage);
	Cxgraphics::TcxBitmap* __fastcall PrepareBlankBitmap(void);
	void __fastcall PrepareForAnimation(void);
	Cxgraphics::TcxBitmap* __fastcall PreparePageBitmap(TdxWizardControlCustomPage* APage);
	void __fastcall ProcessMultiStageAnimation(TdxWizardControlCustomPage* ANewPage, TdxWizardControlCustomPage* APrevPage, Dxanimation::TdxDrawAnimationMode AAnimationMode);
	void __fastcall ProcessSingleStageAnimation(TdxWizardControlCustomPage* ANewPage, TdxWizardControlCustomPage* APrevPage, Dxanimation::TdxDrawAnimationMode AAnimationMode);
	void __fastcall RedrawArea(const System::Types::TRect &ARect);
	void __fastcall RunAnimation(Vcl::Graphics::TBitmap* AStartImage, Vcl::Graphics::TBitmap* AFinishImage, unsigned ATime, Dxanimation::TdxDrawAnimationMode AMode);
	__property bool AutoSize = {read=GetAutoSize, nodefault};
	
public:
	void __fastcall AnimateTransition(TdxWizardControlCustomPage* ANewPage, TdxWizardControlCustomPage* APrevPage);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property bool Active = {read=FActive, nodefault};
	__property bool ActualResizeAnimation = {read=GetActualResizeAnimation, nodefault};
	__property TdxWizardControlTransitionEffect ActualTransitionEffect = {read=GetActualTransitionEffect, nodefault};
	__property System::Types::TRect AnimatedRect = {read=FAnimatedRect};
	__property Dxanimation::TdxImageAnimationTransition* Animation = {read=FAnimation};
	__property TdxWizardControlAnimationControllerStage Stage = {read=FStage, nodefault};
	__property bool SuppressContentDrawing = {read=FSuppressContentDrawing, nodefault};
	__property TdxWizardControlViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlAnimationController(TdxCustomWizardControl* AWizardControl) : TdxWizardControlCustomObject(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlAnimationController(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxCustomWizardControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxWizardControlCustomPage* FActivePage;
	TdxWizardControlAnimationController* FAnimationController;
	TdxWizardControlButtons* FButtons;
	TdxWizardControlController* FController;
	TdxWizardControlDesignSelector* FDesignSelector;
	TdxWizardControlHeader* FHeader;
	TdxWizardControlInfoPanel* FInfoPanel;
	TdxWizardControlOptionsAnimate* FOptionsAnimate;
	TdxWizardControlOptionsViewStyleAero* FOptionsViewStyleAero;
	System::Classes::TList* FPages;
	TdxWizardControlViewInfo* FViewInfo;
	TdxWizardControlViewStyle FViewStyle;
	TdxWizardControlWatermark* FWatermark;
	TdxWizardControlButtonClickEvent FOnButtonClick;
	TdxWizardControlInfoPanelClickEvent FOnInfoPanelClick;
	System::Classes::TNotifyEvent FOnPageChanged;
	TdxWizardControlPageChangingEvent FOnPageChanging;
	int __fastcall GetActivePageIndex(void);
	TdxWizardControlHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetIsResizingAnimationActive(void);
	TdxWizardControlCustomPage* __fastcall GetPage(int APageIndex);
	int __fastcall GetPageCount(void);
	void __fastcall ChangeHandler(System::TObject* Sender, TdxWizardControlChanges AChanges);
	void __fastcall InternalSetActivePage(TdxWizardControlCustomPage* APage);
	void __fastcall SetActivePage(TdxWizardControlCustomPage* APage);
	void __fastcall SetActivePageIndex(int AValue);
	void __fastcall SetButtons(TdxWizardControlButtons* AValue);
	void __fastcall SetHeader(TdxWizardControlHeader* AValue);
	void __fastcall SetInfoPanel(TdxWizardControlInfoPanel* AValue);
	void __fastcall SetOptionsAnimate(TdxWizardControlOptionsAnimate* AValue);
	void __fastcall SetOptionsViewStyleAero(TdxWizardControlOptionsViewStyleAero* AValue);
	void __fastcall SetViewStyle(TdxWizardControlViewStyle AValue);
	void __fastcall SetWatermark(TdxWizardControlWatermark* AValue);
	HIDESBASE MESSAGE void __fastcall CMChildKey(Vcl::Controls::TCMChildKey &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMTabStopChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	
protected:
	_di_IdxWizardControlFormHelper FFormHelper;
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall CalculateAutoSize(int &AWidth, int &AHeight);
	virtual bool __fastcall CanActivatePage(TdxWizardControlCustomPage* APage);
	virtual bool __fastcall CanAutoSize(int &ANewWidth, int &ANewHeight);
	virtual bool __fastcall CanUseTransitionEffect(TdxWizardControlCustomPage* ANewPage, TdxWizardControlCustomPage* APrevPage);
	HIDESBASE virtual void __fastcall Changed(TdxWizardControlChanges AChanges);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual TdxWizardControlController* __fastcall CreateController(void);
	virtual TdxWizardControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall EraseBackground(HDC DC)/* overload */;
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall RecreateViewInfo(void);
	void __fastcall SelectActivePage(void);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall UpdatePagesVisibility(void);
	virtual void __fastcall ValidateActivePage(void);
	DYNAMIC void __fastcall ValidateInsert(System::Classes::TComponent* AComponent);
	void __fastcall InvalidateDesignSelector(void);
	void __fastcall UpdateDesignSelectorBounds(void);
	virtual bool __fastcall DoButtonClick(TdxWizardControlButtonKind AKind);
	virtual bool __fastcall DoInfoPanelClick(void);
	virtual void __fastcall DoPageChanged(void);
	virtual bool __fastcall DoPageChanging(TdxWizardControlCustomPage* NewPage);
	virtual void __fastcall PageAdded(TdxWizardControlCustomPage* APage);
	virtual void __fastcall PageRemoving(TdxWizardControlCustomPage* APage);
	__property TdxWizardControlAnimationController* AnimationController = {read=FAnimationController};
	__property TdxWizardControlController* Controller = {read=FController};
	__property TdxWizardControlDesignSelector* DesignSelector = {read=FDesignSelector};
	__property _di_IdxWizardControlFormHelper FormHelper = {read=FFormHelper};
	__property bool IsResizingAnimationActive = {read=GetIsResizingAnimationActive, nodefault};
	__property TdxWizardControlViewInfo* ViewInfo = {read=FViewInfo};
	__property TdxWizardControlButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property TdxWizardControlInfoPanelClickEvent OnInfoPanelClick = {read=FOnInfoPanelClick, write=FOnInfoPanelClick};
	__property System::Classes::TNotifyEvent OnPageChanged = {read=FOnPageChanged, write=FOnPageChanged};
	__property TdxWizardControlPageChangingEvent OnPageChanging = {read=FOnPageChanging, write=FOnPageChanging};
	
public:
	__fastcall virtual TdxCustomWizardControl(System::Classes::TComponent* AComponent);
	__fastcall virtual ~TdxCustomWizardControl(void);
	virtual TdxWizardControlCustomPage* __fastcall AddPage(TdxWizardControlCustomPageClass APageClass)/* overload */;
	virtual void __fastcall DeletePage(TdxWizardControlCustomPage* APage)/* overload */;
	void __fastcall FullRefresh(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual bool __fastcall CanGoToNextPage(void);
	virtual bool __fastcall CanGoToPrevPage(void);
	TdxWizardControlCustomPage* __fastcall GetNextPage(TdxWizardControlCustomPage* ACurrentPage, bool ASearchForward);
	virtual void __fastcall GoToNextPage(void);
	virtual void __fastcall GoToPrevPage(void);
	virtual void __fastcall TranslationChanged(void);
	__property TdxWizardControlCustomPage* ActivePage = {read=FActivePage, write=SetActivePage};
	__property int ActivePageIndex = {read=GetActivePageIndex, write=SetActivePageIndex, nodefault};
	__property Align = {default=5};
	__property TdxWizardControlButtons* Buttons = {read=FButtons, write=SetButtons};
	__property TdxWizardControlHeader* Header = {read=FHeader, write=SetHeader};
	__property TdxWizardControlHitTest* HitTest = {read=GetHitTest};
	__property TdxWizardControlInfoPanel* InfoPanel = {read=FInfoPanel, write=SetInfoPanel};
	__property TdxWizardControlOptionsAnimate* OptionsAnimate = {read=FOptionsAnimate, write=SetOptionsAnimate};
	__property TdxWizardControlOptionsViewStyleAero* OptionsViewStyleAero = {read=FOptionsViewStyleAero, write=SetOptionsViewStyleAero};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TdxWizardControlCustomPage* Pages[int Index] = {read=GetPage};
	__property TdxWizardControlViewStyle ViewStyle = {read=FViewStyle, write=SetViewStyle, default=0};
	__property TdxWizardControlWatermark* Watermark = {read=FWatermark, write=SetWatermark};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomWizardControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect){ Cxcontrols::TcxControl::EraseBackground(ACanvas, ARect); }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
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
	
};


class DELPHICLASS TdxWizardControlOptionsSize;
class PASCALIMPLEMENTATION TdxWizardControlOptionsSize : public TdxWizardControlCustomPersistent
{
	typedef TdxWizardControlCustomPersistent inherited;
	
private:
	int FMinHeight;
	int FMinWidth;
	void __fastcall SetMinHeight(int AValue);
	void __fastcall SetMinWidth(int AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	
__published:
	__property int MinHeight = {read=FMinHeight, write=SetMinHeight, default=0};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxWizardControlOptionsSize(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxWizardControlOptionsSize(void) : TdxWizardControlCustomPersistent() { }
	
};


class PASCALIMPLEMENTATION TdxWizardControlCustomPage : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxWizardControlPageHeader* FHeader;
	TdxWizardControlOptionsSize* FOptionsSize;
	bool FPageVisible;
	TdxWizardControlPageWatermark* FWatermark;
	bool __fastcall GetActive(void);
	Vcl::Controls::TAlign __fastcall GetAlign(void);
	int __fastcall GetPageIndex(void);
	TdxCustomWizardControl* __fastcall GetWizardControl(void);
	void __fastcall ChangeHandler(System::TObject* Sender, TdxWizardControlChanges AChanges);
	HIDESBASE void __fastcall SetAlign(Vcl::Controls::TAlign AValue);
	void __fastcall SetHeader(TdxWizardControlPageHeader* AValue);
	void __fastcall SetOptionsSize(TdxWizardControlOptionsSize* AValue);
	void __fastcall SetPageIndex(int AValue);
	void __fastcall SetPageVisible(bool AValue);
	void __fastcall SetWatermark(TdxWizardControlPageWatermark* AValue);
	void __fastcall SetWizardControl(TdxCustomWizardControl* AValue);
	
protected:
	Cxclasses::_di_IcxDesignHelper FDesignHelper;
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall CalculateAutoSize(int &AWidth, int &AHeight);
	HIDESBASE virtual void __fastcall Changed(TdxWizardControlChanges AChanges);
	virtual void __fastcall DoPaint(void);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	bool __fastcall IsObjectSelected(void);
	void __fastcall SelectObject(void);
	void __fastcall SelectionChanged(void);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	
public:
	__fastcall virtual TdxWizardControlCustomPage(System::Classes::TComponent* AComponent);
	__fastcall virtual ~TdxWizardControlCustomPage(void);
	void __fastcall Activate(void);
	__property bool Active = {read=GetActive, nodefault};
	__property Vcl::Controls::TAlign Align = {read=GetAlign, write=SetAlign, default=0};
	__property TdxWizardControlPageHeader* Header = {read=FHeader, write=SetHeader};
	__property TdxWizardControlOptionsSize* OptionsSize = {read=FOptionsSize, write=SetOptionsSize};
	__property int PageIndex = {read=GetPageIndex, write=SetPageIndex, stored=false, nodefault};
	__property bool PageVisible = {read=FPageVisible, write=SetPageVisible, default=1};
	__property TdxWizardControlPageWatermark* Watermark = {read=FWatermark, write=SetWatermark};
	__property TdxCustomWizardControl* WizardControl = {read=GetWizardControl, write=SetWizardControl};
	
__published:
	__property Height = {stored=false};
	__property Left = {stored=false};
	__property Top = {stored=false};
	__property Width = {stored=false};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlCustomPage(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxWizardControlSelectableItem;	/* IdxWizardControlSelectableItem */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D5E058AB-1C90-4D21-BE0A-EB48530EF53B}
	operator _di_IdxWizardControlSelectableItem()
	{
		_di_IdxWizardControlSelectableItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxWizardControlSelectableItem*(void) { return (IdxWizardControlSelectableItem*)&__IdxWizardControlSelectableItem; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxWizardControlDefaultButtonHeight = System::Int8(0x19);
static const System::Int8 dxWizardControlDefaultButtonWidth = System::Int8(0x4b);
extern PACKAGE int dxWizardControlMinHeight;
extern PACKAGE int dxWizardControlMinWidth;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnRegisterWizardControlPage;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnUnregisterWizardControlPage;
}	/* namespace Dxcustomwizardcontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMWIZARDCONTROL)
using namespace Dxcustomwizardcontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomwizardcontrolHPP
