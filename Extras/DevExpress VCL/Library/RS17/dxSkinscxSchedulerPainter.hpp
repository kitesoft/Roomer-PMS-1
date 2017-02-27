// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinscxSchedulerPainter.pas' rev: 24.00 (Win32)

#ifndef DxskinscxschedulerpainterHPP
#define DxskinscxschedulerpainterHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxScheduler.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinscxschedulerpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxScheduler3SkinViewItemsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScheduler3SkinViewItemsPainter : public Cxschedulercustomresourceview::TcxSchedulerExternalPainter
{
	typedef Cxschedulercustomresourceview::TcxSchedulerExternalPainter inherited;
	
private:
	void __fastcall DrawClippedElement(Cxgraphics::TcxCanvas* ACanvas, Dxskinscore::TdxSkinElement* AElement, Cxgraphics::TcxBorders ABorders, const System::Types::TRect &R);
	System::Types::TRect __fastcall GetEventSelectionOffsets(bool AHasTimeLine);
	bool __fastcall IsSkinAvalaible(void);
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* __fastcall SkinInfo(void);
	
protected:
	virtual bool __fastcall DoDrawEvent(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AViewInfo);
	
public:
	virtual void __fastcall DoCustomDrawButton(Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DrawAllDayArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABorderColor, Cxgraphics::TcxBorders ABorders, const Cxgraphics::TcxViewParams &AViewParams, bool ASelected, bool ATransparent);
	virtual void __fastcall DrawCurrentTime(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor, System::TDateTime AStart, const System::Types::TRect &ABounds);
	virtual bool __fastcall DrawCurrentTimeFirst(void);
	virtual void __fastcall DrawEvent(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AViewInfo);
	virtual void __fastcall DrawEventAsProgressText(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AViewInfo, const System::Types::TRect &AContent, const System::Types::TRect &AProgressRect, const System::UnicodeString AText);
	virtual void __fastcall DrawTimeGridCurrentTime(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor, const System::Types::TRect &ATimeLineRect);
	virtual void __fastcall DrawTimeGridHeader(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor ABorderColor, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo, Cxgraphics::TcxBorders ABorders, bool ASelected);
	virtual void __fastcall DrawTimeLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxBorders ABorders, System::Uitypes::TColor ABorderColor);
	virtual void __fastcall DrawTimeRulerBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, const Cxgraphics::TcxViewParams &AViewParams, bool ATransparent);
	virtual void __fastcall DrawShadow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AVisibleRect);
	virtual bool __fastcall DrawShadowFirst(void);
	virtual System::Types::TRect __fastcall GetEventSelectionExtends(void);
	virtual System::Types::TSize __fastcall MoreButtonSize(const System::Types::TSize &ASize);
	virtual bool __fastcall NeedDrawSelection(void);
public:
	/* TObject.Create */ inline __fastcall TcxScheduler3SkinViewItemsPainter(void) : Cxschedulercustomresourceview::TcxSchedulerExternalPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxScheduler3SkinViewItemsPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinscxschedulerpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSCXSCHEDULERPAINTER)
using namespace Dxskinscxschedulerpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinscxschedulerpainterHPP
