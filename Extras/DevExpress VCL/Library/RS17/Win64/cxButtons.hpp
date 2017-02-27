// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxButtons.pas' rev: 24.00 (Win64)

#ifndef CxbuttonsHPP
#define CxbuttonsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Actions.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxbuttons
{
//-- type declarations -------------------------------------------------------
enum TcxButtonKind : unsigned char { cxbkStandard, cxbkDropDown, cxbkDropDownButton, cxbkCommandLink, cxbkOfficeDropDown };

enum TcxButtonPaintStyle : unsigned char { bpsDefault, bpsCaption, bpsGlyph };

enum TcxButtonAssignedColor : unsigned char { cxbcDefault, cxbcDefaultText, cxbcDisabled, cxbcDisabledText, cxbcHot, cxbcHotText, cxbcNormal, cxbcNormalText, cxbcPressed, cxbcPressedText };

typedef System::Set<TcxButtonAssignedColor, TcxButtonAssignedColor::cxbcDefault, TcxButtonAssignedColor::cxbcPressedText>  TcxButtonAssignedColors;

class DELPHICLASS TcxCustomButton;
typedef void __fastcall (__closure *TcxButtonGetDrawParamsEvent)(TcxCustomButton* Sender, Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont);

enum TcxButtonInternalStates : unsigned char { bisDown, bisHot, bisPressed, bisMenuButtonPressed, bisMenuVisible, bisAccelExecute };

typedef System::Set<TcxButtonInternalStates, TcxButtonInternalStates::bisDown, TcxButtonInternalStates::bisAccelExecute>  TcxButtonInternalState;

class DELPHICLASS TcxButtonCustomPersistent;
class PASCALIMPLEMENTATION TcxButtonCustomPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomButton* FButton;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property TcxCustomButton* Button = {read=FButton};
	
public:
	__fastcall virtual TcxButtonCustomPersistent(TcxCustomButton* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonCustomPersistent(void) { }
	
};


class DELPHICLASS TcxButtonColors;
class PASCALIMPLEMENTATION TcxButtonColors : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	TcxButtonAssignedColors FAssignedColors;
	System::StaticArray<System::Uitypes::TColor, 10> FColors;
	System::Uitypes::TColor __fastcall GetColor(const int Index);
	bool __fastcall IsColorStored(const int Index);
	void __fastcall SetAssignedColors(TcxButtonAssignedColors Value);
	void __fastcall SetColor(const int Index, const System::Uitypes::TColor Value);
	TcxButtonAssignedColor __fastcall ButtonStateToButtonAssignedColor(Cxlookandfeelpainters::TcxButtonState AState, bool AIsTextColor);
	
protected:
	System::Uitypes::TColor __fastcall GetColorByState(const Cxlookandfeelpainters::TcxButtonState AState);
	System::Uitypes::TColor __fastcall GetTextColorByState(const Cxlookandfeelpainters::TcxButtonState AState);
	
public:
	__fastcall virtual TcxButtonColors(TcxCustomButton* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxButtonAssignedColors AssignedColors = {read=FAssignedColors, write=SetAssignedColors, stored=false, nodefault};
	__property System::Uitypes::TColor Default = {read=GetColor, write=SetColor, stored=IsColorStored, index=0, nodefault};
	__property System::Uitypes::TColor DefaultText = {read=GetColor, write=SetColor, stored=IsColorStored, index=1, nodefault};
	__property System::Uitypes::TColor Normal = {read=GetColor, write=SetColor, stored=IsColorStored, index=6, nodefault};
	__property System::Uitypes::TColor NormalText = {read=GetColor, write=SetColor, stored=IsColorStored, index=7, nodefault};
	__property System::Uitypes::TColor Hot = {read=GetColor, write=SetColor, stored=IsColorStored, index=4, nodefault};
	__property System::Uitypes::TColor HotText = {read=GetColor, write=SetColor, stored=IsColorStored, index=5, nodefault};
	__property System::Uitypes::TColor Pressed = {read=GetColor, write=SetColor, stored=IsColorStored, index=8, nodefault};
	__property System::Uitypes::TColor PressedText = {read=GetColor, write=SetColor, stored=IsColorStored, index=9, nodefault};
	__property System::Uitypes::TColor Disabled = {read=GetColor, write=SetColor, stored=IsColorStored, index=2, nodefault};
	__property System::Uitypes::TColor DisabledText = {read=GetColor, write=SetColor, stored=IsColorStored, index=3, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonColors(void) { }
	
};


class DELPHICLASS TcxGlyphList;
class PASCALIMPLEMENTATION TcxGlyphList : public Cxgraphics::TcxImageList
{
	typedef Cxgraphics::TcxImageList inherited;
	
private:
	System::Classes::TBits* FUsed;
	int FCount;
	int __fastcall AllocateIndex(Vcl::Graphics::TBitmap* ABitmap);
	
public:
	__fastcall TcxGlyphList(int AWidth, int AHeight);
	__fastcall virtual ~TcxGlyphList(void);
	HIDESBASE int __fastcall Add(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask);
	HIDESBASE int __fastcall AddMasked(Vcl::Graphics::TBitmap* AImage, System::Uitypes::TColor AMaskColor);
	HIDESBASE void __fastcall Delete(int AIndex);
	__property int Count = {read=FCount, nodefault};
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxGlyphList(System::Classes::TComponent* AOwner) : Cxgraphics::TcxImageList(AOwner) { }
	
};


typedef System::TMetaClass* TcxButtonGlyphClass;

class DELPHICLASS TcxButtonGlyph;
class PASCALIMPLEMENTATION TcxButtonGlyph : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	Vcl::Graphics::TBitmap* FGlyph;
	TcxGlyphList* FGlyphList;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	int FImageIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	System::StaticArray<int, 4> FIndexs;
	Vcl::Buttons::TNumGlyphs FNumGlyphs;
	System::Classes::TNotifyEvent FOnChange;
	int __fastcall CreateButtonGlyph(Cxlookandfeelpainters::TcxButtonState AState);
	System::Types::TSize __fastcall GetImageSize(void);
	System::Uitypes::TColor __fastcall GetTransparentColor(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall Invalidate(void);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetImageIndex(int Value);
	void __fastcall SetNumGlyphs(Vcl::Buttons::TNumGlyphs Value);
	
protected:
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__fastcall virtual TcxButtonGlyph(TcxCustomButton* AOwner);
	__fastcall virtual ~TcxButtonGlyph(void);
	virtual void __fastcall DrawButtonGlyph(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TPoint AGlyphPos, Cxlookandfeelpainters::TcxButtonState AState);
	bool __fastcall IsImageAssigned(void);
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property System::Types::TSize ImageSize = {read=GetImageSize};
	__property Vcl::Buttons::TNumGlyphs NumGlyphs = {read=FNumGlyphs, write=SetNumGlyphs, nodefault};
	__property System::Uitypes::TColor TransparentColor = {read=GetTransparentColor, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TcxButtonActionLink;
class PASCALIMPLEMENTATION TcxButtonActionLink : public Vcl::Stdctrls::TButtonActionLink
{
	typedef Vcl::Stdctrls::TButtonActionLink inherited;
	
private:
	TcxCustomButton* __fastcall GetClient(void);
	__property TcxCustomButton* Client = {read=GetClient};
	
protected:
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual void __fastcall SetImageIndex(int Value);
	
public:
	__fastcall virtual ~TcxButtonActionLink(void);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TcxButtonActionLink(System::TObject* AClient) : Vcl::Stdctrls::TButtonActionLink(AClient) { }
	
};


class DELPHICLASS TcxSpeedButtonOptions;
class PASCALIMPLEMENTATION TcxSpeedButtonOptions : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	bool FAllowAllUp;
	bool FCanBeFocused;
	int FGroupIndex;
	bool FFlat;
	int FLockCount;
	bool FTransparent;
	bool __fastcall GetActive(void);
	bool __fastcall GetDown(void);
	void __fastcall SetAllowAllUp(bool AValue);
	void __fastcall SetCanBeFocused(bool AValue);
	void __fastcall SetDown(bool AValue);
	void __fastcall SetFlat(bool AValue);
	void __fastcall SetGroupIndex(int AValue);
	void __fastcall SetTransparent(bool AValue);
	void __fastcall UpdateGroup(void);
	
protected:
	void __fastcall UpdateGroupValues(const int AGroupIndex, TcxSpeedButtonOptions* const ASpeedButtonOptions);
	bool __fastcall NeedDrawParts(void);
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TcxSpeedButtonOptions(TcxCustomButton* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	__property bool Active = {read=GetActive, nodefault};
	
__published:
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property bool CanBeFocused = {read=FCanBeFocused, write=SetCanBeFocused, default=1};
	__property bool AllowAllUp = {read=FAllowAllUp, write=SetAllowAllUp, default=0};
	__property bool Down = {read=GetDown, write=SetDown, default=0};
	__property bool Flat = {read=FFlat, write=SetFlat, default=0};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSpeedButtonOptions(void) { }
	
};


class DELPHICLASS TcxButtonImageOptions;
class PASCALIMPLEMENTATION TcxButtonImageOptions : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	System::Uitypes::TImageIndex FImageIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Buttons::TButtonLayout FLayout;
	int FMargin;
	int FSpacing;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	Vcl::Buttons::TNumGlyphs __fastcall GetNumGlyphs(void);
	bool __fastcall IsImageIndexStored(void);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLayout(Vcl::Buttons::TButtonLayout Value);
	void __fastcall SetMargin(int Value);
	void __fastcall SetNumGlyphs(Vcl::Buttons::TNumGlyphs Value);
	void __fastcall SetSpacing(int Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__fastcall virtual TcxButtonImageOptions(TcxCustomButton* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Vcl::Buttons::TButtonLayout Layout = {read=FLayout, write=SetLayout, default=0};
	__property int Margin = {read=FMargin, write=SetMargin, default=-1};
	__property Vcl::Buttons::TNumGlyphs NumGlyphs = {read=GetNumGlyphs, write=SetNumGlyphs, default=1};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=4};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonImageOptions(void) { }
	
};


class DELPHICLASS TcxButtonPainter;
class DELPHICLASS TcxButtonViewInfo;
class PASCALIMPLEMENTATION TcxButtonPainter : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	Cxlookandfeelpainters::TcxLookAndFeelStyle __fastcall GetLookAndFeelStyle(void);
	TcxButtonViewInfo* __fastcall GetViewInfo(void);
	
public:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawDropDownArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawParentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual int __fastcall GetDropDownArrowSize(void);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas, const Vcl::Controls::TCaption AText, System::Types::TRect &R, int ADrawTextFlags)/* overload */;
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas, const Vcl::Controls::TCaption AText, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, int ADrawTextFlags)/* overload */;
	int __fastcall GetBiDiFlags(void);
	virtual System::Uitypes::TColor __fastcall GetDescriptionTextColor(Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0xff000008));
	virtual System::Types::TPoint __fastcall GetPressedTextShift(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0xff000008));
	virtual void __fastcall DrawCommandLinkButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor AColor);
	virtual System::Types::TSize __fastcall GetCommandLinkGlyphSize(void);
	virtual System::Types::TRect __fastcall GetCommandLinkMargins(void);
	virtual void __fastcall DrawSpeedButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor AColor);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property Cxlookandfeelpainters::TcxLookAndFeelStyle LookAndFeelStyle = {read=GetLookAndFeelStyle, nodefault};
	__property TcxButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxButtonCustomPersistent.Create */ inline __fastcall virtual TcxButtonPainter(TcxCustomButton* AOwner) : TcxButtonCustomPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonPainter(void) { }
	
};


class DELPHICLASS TcxButtonCustomLayoutCalculator;
class PASCALIMPLEMENTATION TcxButtonCustomLayoutCalculator : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	TcxButtonImageOptions* __fastcall GetOptionsImage(void);
	TcxButtonPainter* __fastcall GetPainter(void);
	TcxButtonViewInfo* __fastcall GetViewInfo(void);
	
public:
	virtual void __fastcall Calculate(void) = 0 ;
	__property TcxButtonImageOptions* OptionsImage = {read=GetOptionsImage};
	__property TcxButtonPainter* Painter = {read=GetPainter};
	__property TcxButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxButtonCustomPersistent.Create */ inline __fastcall virtual TcxButtonCustomLayoutCalculator(TcxCustomButton* AOwner) : TcxButtonCustomPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonCustomLayoutCalculator(void) { }
	
};


class DELPHICLASS TcxButtonCommandLinkLayoutCalculator;
class PASCALIMPLEMENTATION TcxButtonCommandLinkLayoutCalculator : public TcxButtonCustomLayoutCalculator
{
	typedef TcxButtonCustomLayoutCalculator inherited;
	
protected:
	virtual void __fastcall CalculateLayout(const System::Types::TRect &AContentRect, int AMargin, int ASpacing);
	
public:
	virtual void __fastcall Calculate(void);
public:
	/* TcxButtonCustomPersistent.Create */ inline __fastcall virtual TcxButtonCommandLinkLayoutCalculator(TcxCustomButton* AOwner) : TcxButtonCustomLayoutCalculator(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonCommandLinkLayoutCalculator(void) { }
	
};


class DELPHICLASS TcxButtonStandardLayoutCalculator;
class PASCALIMPLEMENTATION TcxButtonStandardLayoutCalculator : public TcxButtonCustomLayoutCalculator
{
	typedef TcxButtonCustomLayoutCalculator inherited;
	
private:
	System::Types::TPoint __fastcall GetGlyphPos(void);
	System::Types::TSize __fastcall GetGlyphSize(void);
	Vcl::Buttons::TButtonLayout __fastcall GetLayout(void);
	void __fastcall SetGlyphPos(const System::Types::TPoint Value);
	
protected:
	int FMargin;
	int FSpacing;
	System::Types::TSize FTextAreaSize;
	virtual void __fastcall CalculateDropDownArrowRect(void);
	virtual void __fastcall CalculateGlyphPosition(const System::Types::TRect &R);
	virtual void __fastcall CalculateLayout(System::Types::TRect &R);
	virtual void __fastcall CalculateMargins(const System::Types::TRect &R, int &AMargin, int &ASpacing);
	virtual System::Types::TRect __fastcall CalculateTextAreaBounds(const System::Types::TRect &R);
	virtual void __fastcall CalculateTextAreaLayout(const System::Types::TRect &R);
	virtual void __fastcall CalculateTextAreaSize(const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetTextOffsets(void);
	
public:
	virtual void __fastcall Calculate(void);
	__property System::Types::TPoint GlyphPos = {read=GetGlyphPos, write=SetGlyphPos};
	__property System::Types::TSize GlyphSize = {read=GetGlyphSize};
	__property Vcl::Buttons::TButtonLayout Layout = {read=GetLayout, nodefault};
	__property int Margin = {read=FMargin, nodefault};
	__property int Spacing = {read=FSpacing, nodefault};
	__property System::Types::TSize TextAreaSize = {read=FTextAreaSize};
public:
	/* TcxButtonCustomPersistent.Create */ inline __fastcall virtual TcxButtonStandardLayoutCalculator(TcxCustomButton* AOwner) : TcxButtonCustomLayoutCalculator(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonStandardLayoutCalculator(void) { }
	
};


class DELPHICLASS TcxButtonOfficeDropDownLayoutCalculator;
class PASCALIMPLEMENTATION TcxButtonOfficeDropDownLayoutCalculator : public TcxButtonStandardLayoutCalculator
{
	typedef TcxButtonStandardLayoutCalculator inherited;
	
protected:
	System::Types::TSize FCaptionSize;
	System::Types::TSize FDescriptionSize;
	virtual void __fastcall CalculateDropDownArrowRect(void);
	virtual void __fastcall CalculateLayout(System::Types::TRect &R);
	virtual void __fastcall CalculateTextAreaLayout(const System::Types::TRect &R);
	virtual void __fastcall CalculateTextAreaSize(const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetTextOffsets(void);
	
public:
	__property System::Types::TSize CaptionSize = {read=FCaptionSize};
	__property System::Types::TSize DescriptionSize = {read=FDescriptionSize};
public:
	/* TcxButtonCustomPersistent.Create */ inline __fastcall virtual TcxButtonOfficeDropDownLayoutCalculator(TcxCustomButton* AOwner) : TcxButtonStandardLayoutCalculator(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxButtonOfficeDropDownLayoutCalculator(void) { }
	
};


class PASCALIMPLEMENTATION TcxButtonViewInfo : public TcxButtonCustomPersistent
{
	typedef TcxButtonCustomPersistent inherited;
	
private:
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FDescriptionFont;
	Vcl::Graphics::TFont* FFont;
	Vcl::Buttons::TButtonLayout FLayout;
	TcxButtonPainter* FPainter;
	TcxButtonGlyph* __fastcall GetButtonGlyph(void);
	System::UnicodeString __fastcall GetCaption(void);
	System::UnicodeString __fastcall GetDescription(void);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetDropDownButtonState(void);
	bool __fastcall GetHasDropDownButton(void);
	TcxButtonInternalState __fastcall GetInternalState(void);
	bool __fastcall GetIsDrawOnGlass(void);
	TcxButtonKind __fastcall GetKind(void);
	TcxButtonImageOptions* __fastcall GetOptionsImage(void);
	TcxSpeedButtonOptions* __fastcall GetSpeedButtonOptions(void);
	
protected:
	System::Types::TRect FBounds;
	System::Types::TRect FButtonRect;
	System::Types::TRect FCaptionRect;
	System::Types::TRect FDescriptionRect;
	System::Types::TRect FDropDownArrowRect;
	System::Types::TRect FDropDownButtonRect;
	System::Types::TPoint FGlyphPos;
	Cxlookandfeelpainters::TcxButtonState FState;
	virtual void __fastcall CalculateButtonParts(void);
	virtual void __fastcall CalculateContentLayout(void);
	virtual bool __fastcall CanDrawCaption(void);
	virtual bool __fastcall CanDrawGlyph(void);
	virtual TcxButtonCustomLayoutCalculator* __fastcall CreateLayoutCalculator(TcxButtonKind AKind);
	virtual TcxButtonPainter* __fastcall CreatePainter(void);
	virtual void __fastcall CheckLayout(Vcl::Buttons::TButtonLayout &ALayout);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall InitializeFont(void);
	virtual int __fastcall GetCaptionDrawTextFlags(void);
	virtual System::Types::TRect __fastcall GetContentRect(Cxlookandfeelpainters::TcxButtonState AState = (Cxlookandfeelpainters::TcxButtonState)(0x0));
	virtual int __fastcall GetDescriptionDrawTextFlags(void);
	virtual bool __fastcall GetIsDrawFocusRect(void);
	__property TcxButtonInternalState InternalState = {read=GetInternalState, nodefault};
	__property TcxButtonImageOptions* OptionsImage = {read=GetOptionsImage};
	__property TcxSpeedButtonOptions* SpeedButtonOptions = {read=GetSpeedButtonOptions};
	
public:
	__fastcall virtual TcxButtonViewInfo(TcxCustomButton* AOwner);
	__fastcall virtual ~TcxButtonViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TcxButtonGlyph* ButtonGlyph = {read=GetButtonGlyph};
	__property System::Types::TRect ButtonRect = {read=FButtonRect};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
	__property System::UnicodeString Description = {read=GetDescription};
	__property Vcl::Graphics::TFont* DescriptionFont = {read=FDescriptionFont};
	__property System::Types::TRect DescriptionRect = {read=FDescriptionRect};
	__property System::Types::TRect DropDownArrowRect = {read=FDropDownArrowRect};
	__property System::Types::TRect DropDownButtonRect = {read=FDropDownButtonRect};
	__property Cxlookandfeelpainters::TcxButtonState DropDownButtonState = {read=GetDropDownButtonState, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=FFont};
	__property System::Types::TPoint GlyphPos = {read=FGlyphPos};
	__property bool HasDropDownButton = {read=GetHasDropDownButton, nodefault};
	__property bool IsDrawFocusRect = {read=GetIsDrawFocusRect, nodefault};
	__property bool IsDrawOnGlass = {read=GetIsDrawOnGlass, nodefault};
	__property TcxButtonKind Kind = {read=GetKind, nodefault};
	__property Vcl::Buttons::TButtonLayout Layout = {read=FLayout, nodefault};
	__property TcxButtonPainter* Painter = {read=FPainter};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, nodefault};
};


typedef void __fastcall (__closure *TcxButtonCustomDrawEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxButtonViewInfo* AViewInfo, bool &AHandled);

typedef void __fastcall (__closure *TcxButtonDropDownMenuPopupEvent)(System::TObject* Sender, Vcl::Menus::TPopupMenu* &APopupMenu, bool &AHandled);

typedef void __fastcall (__closure *TcxButtonDropDownMenuPopupExEvent)(System::TObject* Sender, System::Classes::TComponent* &APopupMenu, bool &AHandled);

typedef Vcl::Stdctrls::TCustomButton TcxBaseButton;

class PASCALIMPLEMENTATION TcxCustomButton : public Vcl::Stdctrls::TCustomButton
{
	typedef Vcl::Stdctrls::TCustomButton inherited;
	
private:
	bool FAutoSize;
	Cxgraphics::TcxCanvas* FCanvas;
	TcxButtonColors* FColors;
	Vcl::Controls::TControlCanvas* FControlCanvas;
	System::UnicodeString FDescription;
	System::Classes::TComponent* FDropDownMenu;
	TcxButtonGlyph* FGlyph;
	TcxButtonInternalState FInternalState;
	bool FIsDropDownMenuClosing;
	bool FIsFocused;
	bool FIsPaintDefault;
	bool FIsPaintPressed;
	TcxButtonKind FKind;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TcxButtonImageOptions* FOptionsImage;
	TcxButtonPaintStyle FPaintStyle;
	Vcl::Menus::TPopupAlignment FPopupAlignment;
	System::Classes::TComponent* FPopupMenu;
	bool FShowFocusRect;
	TcxSpeedButtonOptions* FSpeedButtonOptions;
	bool FUseSystemPaint;
	TcxButtonViewInfo* FViewInfo;
	TcxButtonDropDownMenuPopupEvent FOnDropDownMenuPopup;
	TcxButtonDropDownMenuPopupExEvent FOnDropDownMenuPopupEx;
	TcxButtonGetDrawParamsEvent FOnGetDrawParams;
	TcxButtonCustomDrawEvent FOnCustomDraw;
	void __fastcall Draw(HDC DC);
	void __fastcall DrawItem(const tagDRAWITEMSTRUCT &DrawItemStruct);
	TcxButtonColors* __fastcall GetColors(void);
	System::UnicodeString __fastcall GetCommandLinkHint(void);
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	Vcl::Buttons::TButtonLayout __fastcall GetLayout(void);
	int __fastcall GetMargin(void);
	Vcl::Buttons::TNumGlyphs __fastcall GetNumGlyphs(void);
	int __fastcall GetSpacing(void);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetLayout(Vcl::Buttons::TButtonLayout Value);
	void __fastcall SetMargin(int Value);
	void __fastcall SetNumGlyphs(Vcl::Buttons::TNumGlyphs Value);
	void __fastcall SetOptionsImage(TcxButtonImageOptions* Value);
	void __fastcall SetSpacing(int Value);
	void __fastcall UpdateImageInfo(void);
	MESSAGE void __fastcall BCMSetNote(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMButtonPressed(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMCloseUpPopupMenu(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall CMDropDownPopupMenu(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNCommand(Winapi::Messages::TWMCommand &Message);
	HIDESBASE MESSAGE void __fastcall CNCtlColorBtn(Winapi::Messages::TWMCtlColor &Message);
	MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall CNMeasureItem(Winapi::Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void __fastcall CNSysKeyDown(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	bool __fastcall CanHotTrack(void);
	void __fastcall CheckStartFading(Cxlookandfeelpainters::TcxButtonState APrevButtonState, Cxlookandfeelpainters::TcxButtonState AButtonState);
	void __fastcall DoDropDownMenu(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	bool __fastcall IsColorsStored(void);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall SetButtonAutoSize(bool Value);
	void __fastcall SetColors(TcxButtonColors* const Value);
	HIDESBASE void __fastcall SetCommandLinkHint(const System::UnicodeString Value);
	void __fastcall SetDescription(const System::UnicodeString Value);
	void __fastcall SetKind(const TcxButtonKind Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetPaintStyle(TcxButtonPaintStyle Value);
	HIDESBASE void __fastcall SetPopupMenu(System::Classes::TComponent* Value);
	void __fastcall CheckPressedState(const System::Types::TPoint P);
	void __fastcall CheckShowMenu(const System::Types::TPoint P);
	bool __fastcall GetAllowAllUp(void);
	bool __fastcall GetCanBeFocused(void);
	bool __fastcall GetDown(void);
	int __fastcall GetGroupIndex(void);
	System::Types::TRect __fastcall GetMenuButtonBounds(void);
	bool __fastcall GetSpeedButtonMode(void);
	void __fastcall SetAllowAllUp(bool AValue);
	void __fastcall SetCanBeFocused(bool AValue);
	void __fastcall SetDown(bool AValue);
	HIDESBASE void __fastcall SetDropDownMenu(System::Classes::TComponent* AValue);
	void __fastcall SetGroupIndex(int AValue);
	void __fastcall SetInternalState(TcxButtonInternalState AValue);
	void __fastcall SetSpeedButtonOptions(TcxSpeedButtonOptions* AValue);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual TcxButtonImageOptions* __fastcall CreateOptionsImage(void);
	virtual TcxButtonViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DestroyWindowHandle(void);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	virtual void __fastcall DoGetDrawParams(Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor &AColor, Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall DoDropDownMenuPopup(System::Classes::TComponent* &APopupMenu);
	virtual bool __fastcall DoOnDropDownMenuPopup(Vcl::Menus::TPopupMenu* &APopupMenu);
	virtual bool __fastcall DoOnDropDownMenuPopupEx(System::Classes::TComponent* &APopupMenu);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* APopupMenu, int X, int Y);
	DYNAMIC Vcl::Controls::TControlActionLinkClass __fastcall GetActionLinkClass(void);
	virtual bool __fastcall GetAllowSpeedButtonOptions(void);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetButtonState(void);
	virtual bool __fastcall GetChecked(void);
	Vcl::Controls::TControlCanvas* __fastcall GetControlCanvas(void);
	virtual TcxButtonGlyphClass __fastcall GetGlyphClass(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	bool __fastcall IsDesigning(void);
	virtual bool __fastcall StandardButton(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetButtonStyle(bool ADefault);
	void __fastcall UpdateSize(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	bool __fastcall DoCustomDraw(Cxgraphics::TcxCanvas* ACanvas, TcxButtonViewInfo* AViewInfo);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall MouseEnter(void);
	DYNAMIC void __fastcall MouseLeave(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	__property bool AllowSpeedButtonOptions = {read=GetAllowSpeedButtonOptions, nodefault};
	__property bool AutoSize = {read=FAutoSize, write=SetButtonAutoSize, default=0};
	__property TcxButtonColors* Colors = {read=GetColors, write=SetColors, stored=IsColorsStored};
	__property System::UnicodeString CommandLinkHint = {read=GetCommandLinkHint, write=SetCommandLinkHint};
	__property System::UnicodeString Description = {read=FDescription, write=SetDescription};
	__property System::Classes::TComponent* DropDownMenu = {read=FDropDownMenu, write=SetDropDownMenu};
	__property TcxButtonInternalState InternalState = {read=FInternalState, write=SetInternalState, nodefault};
	__property bool IsFocused = {read=FIsFocused, nodefault};
	__property TcxButtonKind Kind = {read=FKind, write=SetKind, default=0};
	__property TcxButtonImageOptions* OptionsImage = {read=FOptionsImage, write=SetOptionsImage};
	__property TcxButtonPaintStyle PaintStyle = {read=FPaintStyle, write=SetPaintStyle, default=0};
	__property Vcl::Menus::TPopupAlignment PopupAlignment = {read=FPopupAlignment, write=FPopupAlignment, default=0};
	__property bool ShowFocusRect = {read=FShowFocusRect, write=FShowFocusRect, nodefault};
	__property bool UseSystemPaint = {read=FUseSystemPaint, write=FUseSystemPaint, default=0};
	__property bool AllowAllUp = {read=GetAllowAllUp, write=SetAllowAllUp, default=0};
	__property bool CanBeFocused = {read=GetCanBeFocused, write=SetCanBeFocused, default=1};
	__property bool Down = {read=GetDown, write=SetDown, default=0};
	__property int GroupIndex = {read=GetGroupIndex, write=SetGroupIndex, default=0};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property bool SpeedButtonMode = {read=GetSpeedButtonMode, nodefault};
	__property TcxSpeedButtonOptions* SpeedButtonOptions = {read=FSpeedButtonOptions, write=SetSpeedButtonOptions};
	__property TcxButtonCustomDrawEvent OnCustomDraw = {read=FOnCustomDraw, write=FOnCustomDraw};
	__property TcxButtonDropDownMenuPopupEvent OnDropDownMenuPopup = {read=FOnDropDownMenuPopup, write=FOnDropDownMenuPopup};
	__property TcxButtonDropDownMenuPopupExEvent OnDropDownMenuPopupEx = {read=FOnDropDownMenuPopupEx, write=FOnDropDownMenuPopupEx};
	__property TcxButtonGetDrawParamsEvent OnGetDrawParams = {read=FOnGetDrawParams, write=FOnGetDrawParams};
	__property TcxButtonViewInfo* ViewInfo = {read=FViewInfo};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph, stored=false};
	__property Vcl::Buttons::TButtonLayout Layout = {read=GetLayout, write=SetLayout, default=0};
	__property int Margin = {read=GetMargin, write=SetMargin, default=-1};
	__property Vcl::Buttons::TNumGlyphs NumGlyphs = {read=GetNumGlyphs, write=SetNumGlyphs, default=1};
	__property int Spacing = {read=GetSpacing, write=SetSpacing, default=4};
	
public:
	__fastcall virtual TcxCustomButton(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomButton(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual System::Types::TSize __fastcall GetOptimalSize(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Font;
	__property ParentFont = {default=1};
	__property WordWrap = {default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomButton(HWND ParentWindow) : Vcl::Stdctrls::TCustomButton(ParentWindow) { }
	
private:
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
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
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
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
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	
};


class DELPHICLASS TcxButton;
class PASCALIMPLEMENTATION TcxButton : public TcxCustomButton
{
	typedef TcxCustomButton inherited;
	
__published:
	__property CommandLinkHint = {stored=false};
	__property Glyph = {stored=false};
	__property Layout = {stored=false, default=0};
	__property Margin = {stored=false, default=-1};
	__property NumGlyphs = {stored=false, default=1};
	__property Spacing = {stored=false, default=4};
	__property UseSystemPaint = {default=0};
	__property Align = {default=0};
	__property CanBeFocused = {stored=false, default=1};
	__property GroupIndex = {stored=false, default=0};
	__property Down = {stored=false, default=0};
	__property AllowAllUp = {stored=false, default=0};
	__property Action;
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Cancel = {default=0};
	__property Caption = {default=0};
	__property Colors;
	__property Constraints;
	__property Default = {default=0};
	__property Description = {default=0};
	__property DropDownMenu;
	__property Enabled = {default=1};
	__property Kind = {default=0};
	__property LookAndFeel;
	__property ModalResult = {default=0};
	__property OptionsImage;
	__property PaintStyle = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupAlignment = {default=0};
	__property PopupMenu;
	__property ShowHint;
	__property SpeedButtonOptions;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnDropDownMenuPopup;
	__property OnDropDownMenuPopupEx;
	__property OnEnter;
	__property OnExit;
	__property OnGetDrawParams;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnCustomDraw;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Font;
	__property ParentFont = {default=1};
	__property WordWrap = {default=0};
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnMouseActivate;
public:
	/* TcxCustomButton.Create */ inline __fastcall virtual TcxButton(System::Classes::TComponent* AOwner) : TcxCustomButton(AOwner) { }
	/* TcxCustomButton.Destroy */ inline __fastcall virtual ~TcxButton(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxButton(HWND ParentWindow) : TcxCustomButton(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxDropDownButtonWidth = System::Int8(0xf);
extern PACKAGE Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetButtonPainter(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
}	/* namespace Cxbuttons */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXBUTTONS)
using namespace Cxbuttons;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxbuttonsHPP
