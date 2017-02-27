// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBkGnd.pas' rev: 24.00 (Win32)

#ifndef DxbkgndHPP
#define DxbkgndHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSUtl.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbkgnd
{
//-- type declarations -------------------------------------------------------
enum TdxBackgroundMode : unsigned char { bmNone, bmBrush, bmBrushBitmap, bmPicture };

enum TdxBackgroundParam : unsigned char { bpBkColor, bpBrush, bpMode, bpPictureMode, bpPicture };

typedef System::Set<TdxBackgroundParam, TdxBackgroundParam::bpBkColor, TdxBackgroundParam::bpPicture>  TdxBackgroundParams;

typedef System::TMetaClass* TdxBackgroundClass;

enum TdxPaintSequence : unsigned char { psBefore, psAfter };

typedef void __fastcall (__closure *TdxBackgroundChangeEvent)(System::TObject* Sender, TdxBackgroundParams AChangeWhat);

typedef void __fastcall (__closure *TCustomdxBackgroundPaintEvent)(System::TObject* Sender, Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &ARect, TdxPaintSequence ASequence, bool &ADone);

typedef void __fastcall (__closure *TCustomdxBackgroundPaintExEvent)(System::TObject* Sender, Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &ARect, TdxPaintSequence ASequence, int PixelsNumerator, int PixelsDenominator, bool &ADone);

class DELPHICLASS TdxBackground;
class PASCALIMPLEMENTATION TdxBackground : public Dxbase::TdxBaseObject
{
	typedef Dxbase::TdxBaseObject inherited;
	
private:
	System::Uitypes::TColor FBkColor;
	Vcl::Graphics::TBrush* FBrush;
	bool FIsRepaintNeeded;
	TdxBackgroundMode FMode;
	Vcl::Graphics::TGraphic* FPicture;
	Dxpsreportrendercanvas::TdxPicturePaintMode FPictureMode;
	System::Classes::TNotifyEvent FOnApply;
	TdxBackgroundChangeEvent FOnChange;
	TCustomdxBackgroundPaintEvent FOnPaint;
	TCustomdxBackgroundPaintExEvent FOnPaintEx;
	bool __fastcall GetIsNeedDrawBackground(void);
	Vcl::Graphics::TGraphic* __fastcall GetPicture(void);
	Dxpsreportrendercanvas::TdxPicturePaintMode __fastcall GetStretchDrawMode(void);
	void __fastcall SetBkColor(System::Uitypes::TColor Value);
	void __fastcall SetBrush(Vcl::Graphics::TBrush* Value);
	void __fastcall SetMode(TdxBackgroundMode Value);
	void __fastcall SetPicture(Vcl::Graphics::TGraphic* Value);
	void __fastcall SetPictureMode(Dxpsreportrendercanvas::TdxPicturePaintMode Value);
	
protected:
	DYNAMIC void __fastcall DoApply(void);
	virtual void __fastcall DoAssign(Dxbase::TdxBaseObject* Source);
	DYNAMIC void __fastcall DoChange(TdxBackgroundParams AChangeWhats);
	virtual void __fastcall DoPaint(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &Rect, TdxPaintSequence Sequence, bool &ADone);
	virtual bool __fastcall DoPaintEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &Rect, TdxPaintSequence Sequence, int PixelsNumerator, int PixelsDenominator);
	virtual void __fastcall DoRestoreDefaults(void);
	virtual bool __fastcall RepaintNeeded(TdxBackgroundParams AChangeWhats);
	void __fastcall BrushChanged(System::TObject* Sender);
	DYNAMIC void __fastcall LockUpdate(Dxbase::TdxLockState ALockState);
	void __fastcall PictureChanged(System::TObject* Sender);
	__property System::Classes::TNotifyEvent OnApply = {read=FOnApply, write=FOnApply};
	__property Dxpsreportrendercanvas::TdxPicturePaintMode StretchDrawMode = {read=GetStretchDrawMode, nodefault};
	
public:
	__fastcall virtual TdxBackground(void);
	__fastcall virtual ~TdxBackground(void);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall IsEmpty(void);
	virtual bool __fastcall IsEqual(Dxbase::TdxBaseObject* ABaseObject);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall PaintEx(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &R, int APixelsNumerator, int APixelsDenominator);
	bool __fastcall SetupEffects(void);
	__property bool IsNeedDrawBackground = {read=GetIsNeedDrawBackground, nodefault};
	__property bool IsRepaintNeeded = {read=FIsRepaintNeeded, nodefault};
	__property TdxBackgroundChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TCustomdxBackgroundPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property TCustomdxBackgroundPaintExEvent OnPaintEx = {read=FOnPaintEx, write=FOnPaintEx};
	
__published:
	__property System::Uitypes::TColor BkColor = {read=FBkColor, write=SetBkColor, default=16777215};
	__property Vcl::Graphics::TBrush* Brush = {read=FBrush, write=SetBrush};
	__property TdxBackgroundMode Mode = {read=FMode, write=SetMode, default=0};
	__property Vcl::Graphics::TGraphic* Picture = {read=GetPicture, write=SetPicture};
	__property Dxpsreportrendercanvas::TdxPicturePaintMode PictureMode = {read=FPictureMode, write=SetPictureMode, default=0};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxBackgroundParams cwAll;
}	/* namespace Dxbkgnd */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBKGND)
using namespace Dxbkgnd;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbkgndHPP
