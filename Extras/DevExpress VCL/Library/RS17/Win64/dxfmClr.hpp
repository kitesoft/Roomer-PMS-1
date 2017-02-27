// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmClr.pas' rev: 24.00 (Win64)

#ifndef DxfmclrHPP
#define DxfmclrHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmclr
{
//-- type declarations -------------------------------------------------------
struct TdxBackgroundDlgData;
typedef TdxBackgroundDlgData *PdxBackgroundDlgData;

struct DECLSPEC_DRECORD TdxBackgroundDlgData
{
public:
	Vcl::Forms::TFormBorderStyle BorderStyle;
	System::UnicodeString FormCaption;
	System::UnicodeString NoBtnCaption;
	System::Uitypes::TColor AutoColor;
	bool ShowFillEffects;
	bool ShowMoreColors;
};


class DELPHICLASS TdxfmColorPalette;
class PASCALIMPLEMENTATION TdxfmColorPalette : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* pnlBottom;
	Vcl::Buttons::TSpeedButton* sBtnMoreColors;
	Vcl::Buttons::TSpeedButton* sBtnFillEffects;
	Cxgroupbox::TcxGroupBox* pnlMiddle;
	Cxlabel::TcxLabel* bvlMiddleSeparator;
	Cxgroupbox::TcxGroupBox* pnlTop;
	Vcl::Buttons::TSpeedButton* SpeedButton1;
	Vcl::Buttons::TSpeedButton* SpeedButton2;
	Vcl::Buttons::TSpeedButton* SpeedButton3;
	Vcl::Buttons::TSpeedButton* SpeedButton4;
	Vcl::Buttons::TSpeedButton* SpeedButton5;
	Vcl::Buttons::TSpeedButton* SpeedButton6;
	Vcl::Buttons::TSpeedButton* SpeedButton7;
	Vcl::Buttons::TSpeedButton* SpeedButton8;
	Vcl::Buttons::TSpeedButton* SpeedButton9;
	Vcl::Buttons::TSpeedButton* SpeedButton10;
	Vcl::Buttons::TSpeedButton* SpeedButton11;
	Vcl::Buttons::TSpeedButton* SpeedButton12;
	Vcl::Buttons::TSpeedButton* SpeedButton13;
	Vcl::Buttons::TSpeedButton* SpeedButton14;
	Vcl::Buttons::TSpeedButton* SpeedButton15;
	Vcl::Buttons::TSpeedButton* SpeedButton16;
	Vcl::Buttons::TSpeedButton* SpeedButton17;
	Vcl::Buttons::TSpeedButton* SpeedButton18;
	Vcl::Buttons::TSpeedButton* SpeedButton19;
	Vcl::Buttons::TSpeedButton* SpeedButton20;
	Vcl::Buttons::TSpeedButton* SpeedButton21;
	Vcl::Buttons::TSpeedButton* SpeedButton22;
	Vcl::Buttons::TSpeedButton* SpeedButton23;
	Vcl::Buttons::TSpeedButton* SpeedButton24;
	Vcl::Buttons::TSpeedButton* SpeedButton25;
	Vcl::Buttons::TSpeedButton* SpeedButton26;
	Vcl::Buttons::TSpeedButton* SpeedButton27;
	Vcl::Buttons::TSpeedButton* SpeedButton28;
	Vcl::Buttons::TSpeedButton* SpeedButton29;
	Vcl::Buttons::TSpeedButton* SpeedButton30;
	Vcl::Buttons::TSpeedButton* SpeedButton31;
	Vcl::Buttons::TSpeedButton* SpeedButton32;
	Vcl::Buttons::TSpeedButton* SpeedButton33;
	Vcl::Buttons::TSpeedButton* SpeedButton34;
	Vcl::Buttons::TSpeedButton* SpeedButton35;
	Vcl::Buttons::TSpeedButton* SpeedButton36;
	Vcl::Buttons::TSpeedButton* SpeedButton37;
	Vcl::Buttons::TSpeedButton* SpeedButton38;
	Vcl::Buttons::TSpeedButton* SpeedButton39;
	Vcl::Buttons::TSpeedButton* SpeedButton40;
	Vcl::Extctrls::TBevel* bvlNoFillHolder;
	void __fastcall sBtnMoreColorsClick(System::TObject* Sender);
	void __fastcall sBtnFillEffectsClick(System::TObject* Sender);
	void __fastcall ButtonClick(System::TObject* Sender);
	
private:
	System::Uitypes::TColor FAutoColor;
	Dxbkgnd::TdxBackground* FBackground;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	System::StaticArray<System::StaticArray<Vcl::Buttons::TSpeedButton*, 5>, 8> FButtons;
	System::Uitypes::TColor FColor;
	System::UnicodeString FNoBtnCaption;
	System::Uitypes::TModalResult FResult;
	bool FShowFillEffects;
	bool FShowMoreColors;
	Vcl::Buttons::TSpeedButton* sbtnNoFill;
	void __fastcall AdjustHeight(void);
	void __fastcall FindButtonColor(void);
	void __fastcall InitControls(void);
	void __fastcall LoadStrings(void);
	void __fastcall SetAutoColor(System::Uitypes::TColor Value);
	void __fastcall SetBackground(Dxbkgnd::TdxBackground* Value);
	void __fastcall SetBackgroundColor(System::Uitypes::TColor AColor);
	HIDESBASE void __fastcall SetBorderStyle(Vcl::Forms::TFormBorderStyle Value);
	HIDESBASE void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetNoBtnCaption(const System::UnicodeString Value);
	void __fastcall SetShowFillEffects(bool Value);
	void __fastcall SetShowMoreColors(bool Value);
	void __fastcall SetupButtons(void);
	System::Uitypes::TColor __fastcall TagToColor(int ATag);
	void __fastcall UpButtons(void);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &message);
	HIDESBASE MESSAGE void __fastcall WMNCCreate(Winapi::Messages::TWMNCCreate &message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNoParams &message);
	
protected:
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Initialize(Dxbkgnd::TdxBackground* ABackground, const System::Types::TPoint APosition, TdxBackgroundDlgData &AData);
	DYNAMIC void __fastcall Paint(void);
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, nodefault};
	
public:
	__fastcall virtual TdxfmColorPalette(System::Classes::TComponent* AOwner);
	bool __fastcall Execute(void);
	__property System::Uitypes::TColor AutoColor = {read=FAutoColor, write=SetAutoColor, nodefault};
	__property Dxbkgnd::TdxBackground* Background = {read=FBackground, write=SetBackground};
	__property Vcl::Forms::TFormBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, nodefault};
	__property System::UnicodeString NoBtnCaption = {read=FNoBtnCaption, write=SetNoBtnCaption};
	__property bool ShowFillEffects = {read=FShowFillEffects, write=SetShowFillEffects, nodefault};
	__property bool ShowMoreColors = {read=FShowMoreColors, write=SetShowMoreColors, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmColorPalette(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmColorPalette(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmColorPalette(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxPaletteColCount = System::Int8(0x8);
static const System::Int8 dxPaletteRowCount = System::Int8(0x5);
extern PACKAGE System::StaticArray<System::StaticArray<System::Uitypes::TColor, 5>, 8> dxPaletteColors;
extern PACKAGE System::StaticArray<System::StaticArray<void *, 5>, 8> dxPaletteColorHints;
extern PACKAGE bool __fastcall dxChooseBackgroundDlg(Dxbkgnd::TdxBackground* ABackground, System::Types::TPoint APosition, const TdxBackgroundDlgData &AParams)/* overload */;
extern PACKAGE TdxBackgroundDlgData __fastcall dxDefaultBackgroundDlgData(void);
}	/* namespace Dxfmclr */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMCLR)
using namespace Dxfmclr;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmclrHPP
