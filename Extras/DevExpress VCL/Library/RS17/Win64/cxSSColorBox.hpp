// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSColorBox.pas' rev: 24.00 (Win64)

#ifndef CxsscolorboxHPP
#define CxsscolorboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <cxSSPainterWrapper.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsscolorbox
{
//-- type declarations -------------------------------------------------------
enum TcxColorBoxHitType : unsigned char { cbhNone, cbhBrush, cbhColor, cbhAutomatic };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSColorBoxInfo
{
private:
	typedef System::DynamicArray<System::Types::TRect> _TcxSSColorBoxInfo__1;
	
	typedef System::DynamicArray<System::Types::TRect> _TcxSSColorBoxInfo__2;
	
	typedef System::DynamicArray<System::Types::TRect> _TcxSSColorBoxInfo__3;
	
	
public:
	void *ColorPalette;
	int HalfSpace;
	System::Types::TRect DisplayRect;
	TcxColorBoxHitType HitType;
	short HitIndex;
	short SelectedBrush;
	short SelectedColor;
	_TcxSSColorBoxInfo__1 Bevels;
	System::Int8 AutomaticColor;
	System::Types::TRect AutomaticRect;
	_TcxSSColorBoxInfo__2 BrushBricks;
	_TcxSSColorBoxInfo__3 ColorBricks;
};
#pragma pack(pop)


class DELPHICLASS TcxSSColorBoxViewInfo;
class DELPHICLASS TcxSSColorPanel;
class PASCALIMPLEMENTATION TcxSSColorBoxViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSSColorBoxInfo FViewInfo;
	TcxSSColorPanel* FOwner;
	
protected:
	virtual void __fastcall InvalidateBrick(TcxColorBoxHitType AType, int AIndex);
	virtual void __fastcall InvalidateRect(System::Types::TRect &ARect);
	
public:
	__fastcall virtual TcxSSColorBoxViewInfo(TcxSSColorPanel* const AOwner);
	virtual TcxColorBoxHitType __fastcall HitTest(int X, int Y, short &AHitIndex);
	virtual void __fastcall ReCalcViewInfo(void);
	virtual void __fastcall SetHitBrick(const TcxColorBoxHitType AType, const System::Int8 AIndex);
	virtual bool __fastcall SetSelected(const TcxColorBoxHitType AType, const System::Int8 AIndex);
	__property TcxSSColorBoxInfo ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSColorBoxViewInfo(void) { }
	
};


class DELPHICLASS TcxSSExcelColorBoxPainter;
class PASCALIMPLEMENTATION TcxSSExcelColorBoxPainter : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual void __fastcall Paint(Cxsspainterwrapper::TcxCanvasWrapper* ACanvas, const TcxSSColorBoxInfo &AViewInfo);
public:
	/* TObject.Create */ inline __fastcall TcxSSExcelColorBoxPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSExcelColorBoxPainter(void) { }
	
};


class PASCALIMPLEMENTATION TcxSSColorPanel : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Cxexcelconst::TcxExcelPalette FColorsPalette;
	bool FIsAssignedPalette;
	bool FIncludeBrushes;
	System::Classes::TNotifyEvent FOnChange;
	TcxSSColorBoxViewInfo* FViewInfo;
	Cxsspainterwrapper::TcxCanvasWrapper* FCanvasWrapper;
	System::Byte __fastcall GetAutomaticColor(void);
	Cxexcelconst::PcxExcelPalette __fastcall GetColorsPalette(void);
	bool __fastcall GetIncludeBrushes(void);
	Cxsstypes::TcxSSFillStyle __fastcall GetSelectedBrush(void);
	System::Byte __fastcall GetSelectedColor(void);
	void __fastcall SetAutomaticColor(const System::Byte Value);
	void __fastcall SetIncludeBrushes(const bool Value);
	void __fastcall SetSelectedBrush(const Cxsstypes::TcxSSFillStyle Value);
	void __fastcall SetSelectedColor(const System::Byte Value);
	void __fastcall SetPalette(const Cxexcelconst::PcxExcelPalette Value);
	
protected:
	void __fastcall Change(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	__property Cxsspainterwrapper::TcxCanvasWrapper* CanvasWrapper = {read=FCanvasWrapper};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	
public:
	__fastcall virtual TcxSSColorPanel(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSSColorPanel(void);
	__property Cxexcelconst::PcxExcelPalette ColorPalette = {read=GetColorsPalette, write=SetPalette};
	
__published:
	__property System::Byte AutomaticColor = {read=GetAutomaticColor, write=SetAutomaticColor, nodefault};
	__property bool IncludeBrushes = {read=GetIncludeBrushes, write=SetIncludeBrushes, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Cxsstypes::TcxSSFillStyle SelectedBrush = {read=GetSelectedBrush, write=SetSelectedBrush, nodefault};
	__property System::Byte SelectedColor = {read=GetSelectedColor, write=SetSelectedColor, nodefault};
	__property Align = {default=0};
	__property Font;
	__property Height;
	__property Left;
	__property Top;
	__property Width;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSColorPanel(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxSSColorComboBox;
class PASCALIMPLEMENTATION TcxSSColorComboBox : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	bool FButtonDown;
	System::Types::TRect FButtonRect;
	TcxSSColorPanel* FColorPanel;
	Cxcontrols::TcxPopupWindow* FPopupWindow;
	System::Classes::TNotifyEvent FOnChange;
	Cxsspainterwrapper::TcxCanvasWrapper* FCanvasWrapper;
	System::Byte __fastcall GetAutomaticColor(void);
	Cxexcelconst::PcxExcelPalette __fastcall GetColorPalette(void);
	bool __fastcall GetIncludeBrushes(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	Cxsstypes::TcxSSFillStyle __fastcall GetSelectedBrush(void);
	System::Byte __fastcall GetSelectedColor(void);
	void __fastcall SetAutomaticColor(const System::Byte Value);
	void __fastcall SetColorPalette(const Cxexcelconst::PcxExcelPalette Value);
	void __fastcall SetIncludeBrushes(const bool Value);
	HIDESBASE void __fastcall SetFont(Vcl::Graphics::TFont* AFont);
	void __fastcall SetSelectedBrush(const Cxsstypes::TcxSSFillStyle Value);
	void __fastcall SetSelectedColor(const System::Byte Value);
	
protected:
	virtual void __fastcall DoOnChange(System::TObject* Sender);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall OnHidePopup(System::TObject* Sender);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ShowPopup(void);
	
public:
	__fastcall virtual TcxSSColorComboBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSSColorComboBox(void);
	__property Cxsspainterwrapper::TcxCanvasWrapper* CanvasWrapper = {read=FCanvasWrapper};
	__property Cxexcelconst::PcxExcelPalette ColorPalette = {read=GetColorPalette, write=SetColorPalette};
	
__published:
	__property System::Byte AutomaticColor = {read=GetAutomaticColor, write=SetAutomaticColor, nodefault};
	__property bool IncludeBrushes = {read=GetIncludeBrushes, write=SetIncludeBrushes, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Cxsstypes::TcxSSFillStyle SelectedBrush = {read=GetSelectedBrush, write=SetSelectedBrush, nodefault};
	__property System::Byte SelectedColor = {read=GetSelectedColor, write=SetSelectedColor, nodefault};
	__property Align = {default=0};
	__property Font = {read=GetFont, write=SetFont};
	__property Height;
	__property Left;
	__property Top;
	__property Width;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSColorComboBox(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxSSColorPropertyEditor;
class PASCALIMPLEMENTATION TcxSSColorPropertyEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
protected:
	__classmethod Vcl::Forms::TForm* __fastcall CreateColorEditor();
	
public:
	__classmethod bool __fastcall Execute(Cxsstypes::TcxSSColor &AColor);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSSColorPropertyEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSSColorPropertyEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSSColorPropertyEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSSColorPropertyEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxsscolorbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSCOLORBOX)
using namespace Cxsscolorbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsscolorboxHPP
