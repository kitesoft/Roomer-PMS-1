// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxScreenTip.pas' rev: 24.00 (Win64)

#ifndef DxscreentipHPP
#define DxscreentipHPP

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
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxscreentip
{
//-- type declarations -------------------------------------------------------
__interface IdxScreenTipProvider;
typedef System::DelphiInterface<IdxScreenTipProvider> _di_IdxScreenTipProvider;
class DELPHICLASS TdxScreenTip;
__interface  INTERFACE_UUID("{1479340F-AA1B-4A8E-B136-87E3B5CA3D36}") IdxScreenTipProvider  : public System::IInterface 
{
	
public:
	virtual System::Classes::TBasicAction* __fastcall GetAction(void) = 0 ;
	virtual TdxScreenTip* __fastcall GetScreenTip(void) = 0 ;
	virtual System::UnicodeString __fastcall GetShortCut(void) = 0 ;
};

typedef void __fastcall (__closure *TdxOnGetScreenTip)(System::TObject* Sender, TdxScreenTip* &AScreenTip);

enum TdxScreenTipBandTextAlign : unsigned char { stbtaLeft, stbtaRight };

enum TdxScreenTipBandType : unsigned char { stbHeader, stbDescription, stbFooter };

class DELPHICLASS TdxCustomScreenTipBand;
class PASCALIMPLEMENTATION TdxCustomScreenTipBand : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxScreenTipBandType FBandType;
	Vcl::Graphics::TBitmap* FGlyph;
	bool FGlyphFixedWidth;
	bool FPlainText;
	System::UnicodeString FText;
	TdxScreenTipBandTextAlign FTextAlign;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetPlainText(bool Value);
	void __fastcall SetText(const System::UnicodeString Value);
	void __fastcall SetTextAlign(TdxScreenTipBandTextAlign Value);
	void __fastcall SetGlyphFixedWidth(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void) = 0 ;
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall TdxCustomScreenTipBand(TdxScreenTipBandType ABandType);
	__fastcall virtual ~TdxCustomScreenTipBand(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall HasGlyph(void);
	virtual bool __fastcall IsDefaultTextColor(void) = 0 ;
	bool __fastcall IsVisible(const System::UnicodeString AHintText);
	__property TdxScreenTipBandType BandType = {read=FBandType, write=FBandType, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	
__published:
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property bool GlyphFixedWidth = {read=FGlyphFixedWidth, write=SetGlyphFixedWidth, default=1};
	__property bool PlainText = {read=FPlainText, write=SetPlainText, default=1};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property TdxScreenTipBandTextAlign TextAlign = {read=FTextAlign, write=SetTextAlign, default=1};
};


class DELPHICLASS TdxScreenTipBand;
class PASCALIMPLEMENTATION TdxScreenTipBand : public TdxCustomScreenTipBand
{
	typedef TdxCustomScreenTipBand inherited;
	
private:
	TdxScreenTip* FScreenTip;
	
protected:
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	
public:
	__fastcall virtual TdxScreenTipBand(TdxScreenTip* AScreenTip, TdxScreenTipBandType ABandType);
	virtual bool __fastcall IsDefaultTextColor(void);
	__property TdxScreenTip* ScreenTip = {read=FScreenTip};
public:
	/* TdxCustomScreenTipBand.Destroy */ inline __fastcall virtual ~TdxScreenTipBand(void) { }
	
};


class DELPHICLASS TdxScreenTipFooterBand;
class DELPHICLASS TdxScreenTipRepository;
class PASCALIMPLEMENTATION TdxScreenTipFooterBand : public TdxCustomScreenTipBand
{
	typedef TdxCustomScreenTipBand inherited;
	
private:
	TdxScreenTipRepository* FRepository;
	
protected:
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	
public:
	__fastcall TdxScreenTipFooterBand(TdxScreenTipRepository* ARepository);
	virtual bool __fastcall IsDefaultTextColor(void);
	__property TdxScreenTipRepository* Repository = {read=FRepository};
public:
	/* TdxCustomScreenTipBand.Destroy */ inline __fastcall virtual ~TdxScreenTipFooterBand(void) { }
	
};


class DELPHICLASS TdxScreenTipCollection;
class PASCALIMPLEMENTATION TdxScreenTip : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	System::StaticArray<TdxScreenTipBand*, 3> FBands;
	bool FUseHintAsHeader;
	bool FUseStandardFooter;
	int FWidth;
	TdxScreenTipBand* __fastcall GetBand(int Index);
	void __fastcall SetBand(int Index, TdxScreenTipBand* Value);
	
protected:
	virtual TdxScreenTipCollection* __fastcall GetCollection(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	
public:
	__fastcall virtual TdxScreenTip(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxScreenTip(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TdxCustomScreenTipBand* __fastcall GetBandForCalculation(TdxScreenTipBandType Index);
	virtual int __fastcall GetWidth(void);
	__property TdxScreenTipCollection* Collection = {read=GetCollection};
	
__published:
	__property TdxScreenTipBand* Header = {read=GetBand, write=SetBand, index=0};
	__property TdxScreenTipBand* Description = {read=GetBand, write=SetBand, index=1};
	__property TdxScreenTipBand* Footer = {read=GetBand, write=SetBand, index=2};
	__property bool UseHintAsHeader = {read=FUseHintAsHeader, write=FUseHintAsHeader, default=0};
	__property bool UseStandardFooter = {read=FUseStandardFooter, write=FUseStandardFooter, default=0};
	__property int Width = {read=FWidth, write=FWidth, default=0};
};


class PASCALIMPLEMENTATION TdxScreenTipCollection : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxScreenTip* operator[](int Index) { return Items[Index]; }
	
private:
	TdxScreenTipRepository* FRepository;
	HIDESBASE TdxScreenTip* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxScreenTip* Value);
	
protected:
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem);
	void __fastcall UpdateFonts(void);
	
public:
	__fastcall virtual TdxScreenTipCollection(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass);
	HIDESBASE TdxScreenTip* __fastcall Add(void);
	__property TdxScreenTipRepository* Repository = {read=FRepository};
	__property TdxScreenTip* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxScreenTipCollection(void) { }
	
};


typedef System::Set<TdxScreenTipBandType, TdxScreenTipBandType::stbHeader, TdxScreenTipBandType::stbFooter>  TdxScreenTipRepositoryFonts;

class PASCALIMPLEMENTATION TdxScreenTipRepository : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TdxScreenTipRepositoryFonts FAssignedFonts;
	System::StaticArray<Vcl::Graphics::TFont*, 3> FFonts;
	TdxScreenTipCollection* FItems;
	bool FShowDescription;
	TdxScreenTipFooterBand* FStandardFooter;
	Vcl::Graphics::TFont* FSystemFont;
	void __fastcall CreateFonts(void);
	void __fastcall FontChanged(System::TObject* Sender);
	Vcl::Graphics::TFont* __fastcall GetFont(int Index);
	bool __fastcall IsFontStored(int Index);
	void __fastcall SetFont(int Index, Vcl::Graphics::TFont* Value);
	void __fastcall SetItems(TdxScreenTipCollection* AValue);
	void __fastcall SetStandardFooter(TdxScreenTipFooterBand* Value);
	
protected:
	virtual TdxScreenTipCollection* __fastcall CreateScreenTips(void);
	virtual Vcl::Graphics::TFont* __fastcall GetBandFont(TdxScreenTipBandType ABandType);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	Vcl::Graphics::TFont* __fastcall GetSystemFont(TdxScreenTipBandType ABandType);
	bool __fastcall IsDefaultBandTextColor(TdxScreenTipBandType ABandType);
	
public:
	__fastcall virtual TdxScreenTipRepository(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxScreenTipRepository(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxScreenTipRepositoryFonts AssignedFonts = {read=FAssignedFonts, write=FAssignedFonts, default=0};
	__property TdxScreenTipCollection* Items = {read=FItems, write=SetItems};
	__property Vcl::Graphics::TFont* DescriptionFont = {read=GetFont, write=SetFont, stored=IsFontStored, index=1};
	__property Vcl::Graphics::TFont* FooterFont = {read=GetFont, write=SetFont, stored=IsFontStored, index=2};
	__property Vcl::Graphics::TFont* HeaderFont = {read=GetFont, write=SetFont, stored=IsFontStored, index=0};
	__property TdxScreenTipFooterBand* StandardFooter = {read=FStandardFooter, write=SetStandardFooter};
	__property bool ShowDescription = {read=FShowDescription, write=FShowDescription, default=1};
};


class DELPHICLASS TdxScreenTipPainter;
class PASCALIMPLEMENTATION TdxScreenTipPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	
public:
	__fastcall TdxScreenTipPainter(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter);
	virtual System::Uitypes::TColor __fastcall GetDescriptionTextColor(void);
	virtual int __fastcall GetFooterLineSize(void);
	virtual System::Uitypes::TColor __fastcall GetTitleTextColor(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawFooterLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxScreenTipPainter(void) { }
	
};


class DELPHICLASS TdxScreenTipLikeHintViewInfoHelper;
class PASCALIMPLEMENTATION TdxScreenTipLikeHintViewInfoHelper : public Dxcustomhint::TdxHintViewInfoHelper
{
	typedef Dxcustomhint::TdxHintViewInfoHelper inherited;
	
private:
	TdxScreenTipPainter* FPainter;
	
protected:
	virtual void __fastcall CorrectMinSize(System::Types::TSize &ASize);
	virtual System::Types::TRect __fastcall GetTextRect(void);
	virtual void __fastcall SetTextColor(Vcl::Graphics::TCanvas* ACanvas);
	
public:
	__fastcall TdxScreenTipLikeHintViewInfoHelper(TdxScreenTipPainter* APainter, const System::UnicodeString AHint, const System::UnicodeString AShortCut, const System::Types::TPoint ACursorPos);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxScreenTipLikeHintViewInfoHelper(void) { }
	
};


class DELPHICLASS TdxScreenTipLikeHintViewInfo;
class PASCALIMPLEMENTATION TdxScreenTipLikeHintViewInfo : public Dxcustomhint::TdxCustomHintViewInfo
{
	typedef Dxcustomhint::TdxCustomHintViewInfo inherited;
	
private:
	System::Types::TPoint FCursorPos;
	System::UnicodeString FHint;
	TdxScreenTipPainter* FPainter;
	System::UnicodeString FShortCut;
	
protected:
	virtual void __fastcall CreateHelper(void);
	virtual void __fastcall DestroyHelper(void);
	
public:
	__fastcall TdxScreenTipLikeHintViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::UnicodeString AHint, const System::UnicodeString AShortCut, const System::Types::TPoint ACursorPos);
public:
	/* TdxCustomHintViewInfo.Destroy */ inline __fastcall virtual ~TdxScreenTipLikeHintViewInfo(void) { }
	
};


class DELPHICLASS TdxScreenTipBandViewInfo;
class PASCALIMPLEMENTATION TdxScreenTipBandViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomScreenTipBand* FBand;
	System::Types::TRect FBounds;
	System::Types::TRect FGlyphBounds;
	System::Types::TSize FGlyphSize;
	System::UnicodeString FHintText;
	System::UnicodeString FShortCut;
	System::Types::TRect FTextBounds;
	System::Types::TSize FTextSize;
	int __fastcall GetTextFlags(bool AIsCalculate = false);
	System::Types::TSize __fastcall GetTextSize(Vcl::Graphics::TCanvas* ACanvas, int AWidth);
	bool __fastcall IsPlainText(void);
	bool __fastcall IsTextCenter(void);
	
protected:
	void __fastcall CorrectMinWidth(Vcl::Graphics::TCanvas* ACanvas, int &AWidth);
	int __fastcall GetAvailGlyphWidth(void);
	int __fastcall GetHorzIndent(void);
	int __fastcall GetVertIndent(TdxScreenTipPainter* APainter);
	System::UnicodeString __fastcall GetText(void);
	bool __fastcall HasGlyph(void);
	bool __fastcall HasText(void);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas, TdxScreenTipPainter* APainter);
	void __fastcall CalculateTextHeight(Vcl::Graphics::TCanvas* ACanvas, System::UnicodeString AText, System::Types::TRect &ARect);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect GlyphBounds = {read=FGlyphBounds};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
	__property System::Types::TSize TextSize = {read=FTextSize};
	
public:
	__fastcall TdxScreenTipBandViewInfo(TdxCustomScreenTipBand* ABand, const System::UnicodeString AHintText, const System::UnicodeString AShortCut);
	void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas, TdxScreenTipPainter* APainter, int ATop, int AWidth);
	int __fastcall GetHeight(Vcl::Graphics::TCanvas* ACanvas, const int AWidth, TdxScreenTipPainter* APainter);
	bool __fastcall IsVisible(void);
	__property TdxCustomScreenTipBand* Band = {read=FBand};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxScreenTipBandViewInfo(void) { }
	
};


class DELPHICLASS TdxScreenTipViewInfoHelper;
class PASCALIMPLEMENTATION TdxScreenTipViewInfoHelper : public Dxcustomhint::TdxCustomHintViewInfoHelper
{
	typedef Dxcustomhint::TdxCustomHintViewInfoHelper inherited;
	
private:
	typedef System::DynamicArray<TdxScreenTipBandViewInfo*> _TdxScreenTipViewInfoHelper__1;
	
	
private:
	TdxScreenTipPainter* FPainter;
	TdxScreenTip* FScreenTip;
	System::UnicodeString FHintText;
	System::UnicodeString FShortCut;
	_TdxScreenTipViewInfoHelper__1 FBandViewInfos;
	void __fastcall CreateBandViewInfos(void);
	void __fastcall DestroyBandViewInfos(void);
	TdxScreenTipBandViewInfo* __fastcall GetBandViewInfos(int Index);
	int __fastcall GetBandViewInfosCount(void);
	
protected:
	virtual TdxScreenTipBandViewInfo* __fastcall CreateBandViewInfo(TdxCustomScreenTipBand* ABand);
	
public:
	__fastcall TdxScreenTipViewInfoHelper(TdxScreenTip* AScreenTip, TdxScreenTipPainter* APainter, const System::UnicodeString AHintText, System::UnicodeString AShortCut);
	__fastcall virtual ~TdxScreenTipViewInfoHelper(void);
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas);
	__property TdxScreenTip* ScreenTip = {read=FScreenTip};
	__property int BandViewInfosCount = {read=GetBandViewInfosCount, nodefault};
	__property TdxScreenTipBandViewInfo* BandViewInfos[int Index] = {read=GetBandViewInfos};
};


class DELPHICLASS TdxScreenTipViewInfo;
class PASCALIMPLEMENTATION TdxScreenTipViewInfo : public Dxcustomhint::TdxCustomHintViewInfo
{
	typedef Dxcustomhint::TdxCustomHintViewInfo inherited;
	
private:
	System::UnicodeString FHint;
	TdxScreenTipPainter* FPainter;
	TdxScreenTip* FScreenTip;
	System::UnicodeString FShortCut;
	
protected:
	virtual void __fastcall CreateHelper(void);
	virtual void __fastcall DestroyHelper(void);
	
public:
	__fastcall TdxScreenTipViewInfo(TdxScreenTip* AScreenTip, Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::UnicodeString AHintText, System::UnicodeString AShortCut);
public:
	/* TdxCustomHintViewInfo.Destroy */ inline __fastcall virtual ~TdxScreenTipViewInfo(void) { }
	
};


class DELPHICLASS TdxCustomScreenTipLink;
class PASCALIMPLEMENTATION TdxCustomScreenTipLink : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Classes::TComponent* FComponent;
	TdxScreenTip* FScreenTip;
	void __fastcall SetComponent(System::Classes::TComponent* const Value);
	void __fastcall SetScreenTip(TdxScreenTip* const Value);
	
protected:
	System::Classes::TComponent* __fastcall GetOwnerComponent(void);
	__property System::Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxScreenTip* ScreenTip = {read=FScreenTip, write=SetScreenTip};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TdxCustomScreenTipLink(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxCustomScreenTipLink(void) { }
	
};


typedef System::TMetaClass* TdxScreenTipLinkClass;

class DELPHICLASS TdxCustomScreenTipLinks;
class DELPHICLASS TdxScreenTipStyle;
class PASCALIMPLEMENTATION TdxCustomScreenTipLinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
private:
	TdxScreenTipStyle* FScreenTipStyle;
	
protected:
	TdxCustomScreenTipLink* __fastcall FindLinkByComponent(System::Classes::TComponent* AComponent);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	System::Classes::TComponent* __fastcall GetOwnerComponent(void);
	virtual TdxScreenTipLinkClass __fastcall GetScreenTipLinkClass(void) = 0 ;
	
public:
	__fastcall virtual TdxCustomScreenTipLinks(TdxScreenTipStyle* AScreenTipStyle);
	__property TdxScreenTipStyle* ScreenTipStyle = {read=FScreenTipStyle};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxCustomScreenTipLinks(void) { }
	
};


class DELPHICLASS TdxScreenTipLink;
class PASCALIMPLEMENTATION TdxScreenTipLink : public TdxCustomScreenTipLink
{
	typedef TdxCustomScreenTipLink inherited;
	
private:
	Vcl::Controls::TControl* __fastcall GetControl(void);
	void __fastcall SetControl(Vcl::Controls::TControl* AValue);
	
__published:
	__property Vcl::Controls::TControl* Control = {read=GetControl, write=SetControl};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TdxScreenTipLink(System::Classes::TCollection* Collection) : TdxCustomScreenTipLink(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxScreenTipLink(void) { }
	
};


class DELPHICLASS TdxScreenTipLinks;
class PASCALIMPLEMENTATION TdxScreenTipLinks : public TdxCustomScreenTipLinks
{
	typedef TdxCustomScreenTipLinks inherited;
	
public:
	TdxScreenTipLink* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxScreenTipLink* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxScreenTipLink* Value);
	
protected:
	virtual TdxScreenTipLinkClass __fastcall GetScreenTipLinkClass(void);
	
public:
	HIDESBASE TdxScreenTipLink* __fastcall Add(void);
	TdxScreenTip* __fastcall FindScreenTipByControl(Vcl::Controls::TControl* AControl);
	__property TdxScreenTipLink* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxCustomScreenTipLinks.Create */ inline __fastcall virtual TdxScreenTipLinks(TdxScreenTipStyle* AScreenTipStyle) : TdxCustomScreenTipLinks(AScreenTipStyle) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxScreenTipLinks(void) { }
	
};


class DELPHICLASS TdxScreenTipActionLink;
class PASCALIMPLEMENTATION TdxScreenTipActionLink : public TdxCustomScreenTipLink
{
	typedef TdxCustomScreenTipLink inherited;
	
private:
	System::Classes::TBasicAction* __fastcall GetAction(void);
	void __fastcall SetAction(System::Classes::TBasicAction* AValue);
	
__published:
	__property System::Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TdxScreenTipActionLink(System::Classes::TCollection* Collection) : TdxCustomScreenTipLink(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxScreenTipActionLink(void) { }
	
};


class DELPHICLASS TdxScreenTipActionLinks;
class PASCALIMPLEMENTATION TdxScreenTipActionLinks : public TdxCustomScreenTipLinks
{
	typedef TdxCustomScreenTipLinks inherited;
	
public:
	TdxScreenTipActionLink* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxScreenTipActionLink* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxScreenTipActionLink* Value);
	
protected:
	virtual TdxScreenTipLinkClass __fastcall GetScreenTipLinkClass(void);
	
public:
	HIDESBASE TdxScreenTipActionLink* __fastcall Add(void);
	TdxScreenTip* __fastcall FindScreenTipByAction(System::Classes::TBasicAction* AAction);
	__property TdxScreenTipActionLink* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxCustomScreenTipLinks.Create */ inline __fastcall virtual TdxScreenTipActionLinks(TdxScreenTipStyle* AScreenTipStyle) : TdxCustomScreenTipLinks(AScreenTipStyle) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxScreenTipActionLinks(void) { }
	
};


class PASCALIMPLEMENTATION TdxScreenTipStyle : public Dxcustomhint::TcxCustomHintStyle
{
	typedef Dxcustomhint::TcxCustomHintStyle inherited;
	
private:
	TdxScreenTipLinks* FScreenTipLinks;
	TdxScreenTipActionLinks* FScreenTipActionLinks;
	void __fastcall SetScreenTipLinks(TdxScreenTipLinks* const Value);
	void __fastcall SetScreenTipActionLinks(TdxScreenTipActionLinks* const Value);
	
protected:
	virtual void __fastcall DoShowHint(System::UnicodeString &AHintStr, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	void __fastcall GetScreenTipInfo(Vcl::Controls::TControl* AControl, /* out */ TdxScreenTip* &AScreenTip, /* out */ System::UnicodeString &AShortCut);
	
public:
	__fastcall virtual TdxScreenTipStyle(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxScreenTipStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall ComponentRemoved(System::Classes::TComponent* AComponent);
	virtual Dxcustomhint::TcxCustomHintWindowClass __fastcall GetHintWindowClass(void);
	System::Types::TRect __fastcall GetScreenTipBounds(TdxScreenTip* AScreenTip, const System::UnicodeString AHint = System::UnicodeString());
	void __fastcall ShowScreenTip(int X, int Y, TdxScreenTip* AScreenTip, const System::UnicodeString AHint = System::UnicodeString());
	
__published:
	__property TdxScreenTipLinks* ScreenTipLinks = {read=FScreenTipLinks, write=SetScreenTipLinks};
	__property TdxScreenTipActionLinks* ScreenTipActionLinks = {read=FScreenTipActionLinks, write=SetScreenTipActionLinks};
};


class DELPHICLASS TdxScreenTipWindow;
class PASCALIMPLEMENTATION TdxScreenTipWindow : public Dxcustomhint::TcxCustomHintWindow
{
	typedef Dxcustomhint::TcxCustomHintWindow inherited;
	
private:
	int FBorderWidth;
	TdxScreenTip* FScreenTip;
	Dxcustomhint::TdxCustomHintViewInfo* FViewInfo;
	MESSAGE void __fastcall WMShowWindow(Winapi::Messages::TWMShowWindow &Message);
	
protected:
	virtual void __fastcall AdjustActivateRect(System::Types::TRect &ARect);
	virtual void __fastcall EnableRegion(void);
	virtual bool __fastcall HasWindowRegion(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ShowHint(int X, int Y, System::UnicodeString ACaption, System::UnicodeString AHint, int AMaxWidth = 0x0);
	
public:
	__fastcall virtual TdxScreenTipWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxScreenTipWindow(void);
	virtual System::Types::TRect __fastcall CalcHintRect(int MaxWidth, const System::UnicodeString AHint, void * AData);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxScreenTipWindow(HWND ParentWindow) : Dxcustomhint::TcxCustomHintWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const int dxScreenTipFontColor = int(0x4c4c4c);
}	/* namespace Dxscreentip */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSCREENTIP)
using namespace Dxscreentip;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxscreentipHPP
