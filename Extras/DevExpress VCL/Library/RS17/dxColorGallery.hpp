// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxColorGallery.pas' rev: 24.00 (Win32)

#ifndef DxcolorgalleryHPP
#define DxcolorgalleryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxGalleryControl.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxGallery.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcolorgallery
{
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<System::Uitypes::TColor, 10> TdxOfficeColorSet;

enum TdxColorPalette : unsigned char { cpOffice, cpExtended, cpStandard };

enum TdxColorSet : unsigned char { csDefault, csTheme1, csTheme2, csTheme3, csTheme4, csTheme5, csCustom };

enum TdxColorAccent : unsigned char { caLight80, caLight60, caLight50, caLight40, caLight35, caLight25, caLight15, caLight5, caDark5, caDark10, caDark15, caDark25, caDark35, caDark50, caDark75, caDark90 };

typedef System::StaticArray<TdxColorAccent, 5> TdxColorAccentArray;

typedef void __fastcall (__closure *TdxColorGetCustomColorSetEvent)(System::TObject* Sender, Dxcore::TColors &ASet);

class DELPHICLASS TdxColorGalleryPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxColorGalleryPainter : public Dxgallerycontrol::TdxGalleryControlPainter
{
	typedef Dxgallerycontrol::TdxGalleryControlPainter inherited;
	
protected:
	virtual bool __fastcall DrawItemSelectionFirst(void);
	
public:
	virtual void __fastcall DrawItemSelection(Cxgraphics::TcxCanvas* ACanvas, Dxgallerycontrol::TdxGalleryItemViewInfo* AViewInfo);
public:
	/* TdxGalleryPersistent.Create */ inline __fastcall virtual TdxColorGalleryPainter(Dxgallerycontrol::TdxCustomGalleryControl* AOwner) : Dxgallerycontrol::TdxGalleryControlPainter(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxColorGalleryPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomColorGallery;
class PASCALIMPLEMENTATION TdxCustomColorGallery : public Dxgallerycontrol::TdxCustomGalleryControl
{
	typedef Dxgallerycontrol::TdxCustomGalleryControl inherited;
	
private:
	System::Variant FEditValue;
	TdxColorPalette FColorPalette;
	TdxColorSet FColorSet;
	int FItemSize;
	System::Classes::TNotifyEvent FOnChange;
	TdxColorGetCustomColorSetEvent FOnGetCustomColorSet;
	void __fastcall InternalSetEditValue(const System::Variant &AValue, bool ANeedSynchronizeSelectedItems);
	System::Uitypes::TColor __fastcall GetColorValue(void);
	void __fastcall SetColorValue(System::Uitypes::TColor AValue);
	void __fastcall SetItemSize(int AValue);
	void __fastcall SetEditValue(const System::Variant &AValue);
	void __fastcall SynchronizeSelectedItems(void);
	void __fastcall SetColorPalette(TdxColorPalette AValue);
	void __fastcall SetColorSet(TdxColorSet AValue);
	Dxgallery::TdxGalleryGroup* __fastcall AddColorGroup(const System::UnicodeString ACaption);
	void __fastcall AddColorItem(Dxgallery::TdxGalleryGroup* AGroup, System::Uitypes::TColor AColor, int ASize, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	void __fastcall PopulateWithExtendedColors(void);
	void __fastcall PopulateWithStandardColors(void);
	void __fastcall PopulateWithOfficeColors(void);
	void __fastcall BuildColorPalette(void);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall DoClickItem(Dxgallery::TdxGalleryItem* AItem);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual Dxgallerycontrol::TdxGalleryControlPainter* __fastcall CreatePainter(void);
	__property TdxColorPalette ColorPalette = {read=FColorPalette, write=SetColorPalette, nodefault};
	__property TdxColorSet ColorSet = {read=FColorSet, write=SetColorSet, nodefault};
	__property System::Uitypes::TColor ColorValue = {read=GetColorValue, write=SetColorValue, nodefault};
	__property System::Variant EditValue = {read=FEditValue, write=SetEditValue};
	__property int ItemSize = {read=FItemSize, write=SetItemSize, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TdxColorGetCustomColorSetEvent OnGetCustomColorSet = {read=FOnGetCustomColorSet, write=FOnGetCustomColorSet};
	
public:
	__fastcall virtual TdxCustomColorGallery(System::Classes::TComponent* AOwner);
public:
	/* TdxCustomGalleryControl.Destroy */ inline __fastcall virtual ~TdxCustomColorGallery(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomColorGallery(HWND ParentWindow) : Dxgallerycontrol::TdxCustomGalleryControl(ParentWindow) { }
	
};


class DELPHICLASS TdxColorGallery;
class PASCALIMPLEMENTATION TdxColorGallery : public TdxCustomColorGallery
{
	typedef TdxCustomColorGallery inherited;
	
public:
	__property ColumnCount;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Enabled = {default=1};
	__property Font;
	__property PopupMenu;
	__property Visible = {default=1};
	__property LookAndFeel;
	__property AutoSizeMode = {default=3};
	__property BorderStyle = {default=1};
	__property ColorPalette = {default=0};
	__property ColorSet = {default=0};
	__property ColorValue = {default=536870911};
	__property ItemSize = {default=0};
	__property OnItemClick;
	__property OnChange;
	__property OnGetCustomColorSet;
public:
	/* TdxCustomColorGallery.Create */ inline __fastcall virtual TdxColorGallery(System::Classes::TComponent* AOwner) : TdxCustomColorGallery(AOwner) { }
	
public:
	/* TdxCustomGalleryControl.Destroy */ inline __fastcall virtual ~TdxColorGallery(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxColorGallery(HWND ParentWindow) : TdxCustomColorGallery(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxcOfficeSchemeColorCount = System::Int8(0xa);
static const System::Int8 dxcColorAccentCount = System::Int8(0x5);
static const System::Int8 dxcOfficeSchemeItemSize = System::Int8(0xe);
static const System::Int8 dxcExtendedSchemeItemSize = System::Int8(0xc);
static const System::Int8 dxcStandardSchemeItemSize = System::Int8(0x18);
}	/* namespace Dxcolorgallery */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCOLORGALLERY)
using namespace Dxcolorgallery;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcolorgalleryHPP
