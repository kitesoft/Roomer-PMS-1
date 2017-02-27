// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSGraphicLnk.pas' rev: 24.00 (Win32)

#ifndef DxpsgraphiclnkHPP
#define DxpsgraphiclnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsgraphiclnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomdxGraphicReportLink;
class PASCALIMPLEMENTATION TCustomdxGraphicReportLink : public Dxpscore::TBasedxReportLink
{
	typedef Dxpscore::TBasedxReportLink inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	bool FCenter;
	bool FDrawBorder;
	bool FProportional;
	bool FStretch;
	System::Uitypes::TColor FTransparentColor;
	void __fastcall SetBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetDrawBorder(bool Value);
	void __fastcall SetProportional(bool Value);
	void __fastcall SetStretch(bool Value);
	void __fastcall SetTransparentColor(System::Uitypes::TColor Value);
	
protected:
	virtual bool __fastcall GetAlwaysBufferedGraphics(void);
	virtual int __fastcall GetCriticalSize(Dxpscore::TdxReportCells* AReportCells);
	virtual int __fastcall CalculateActualScaleFactor(void);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	virtual int __fastcall GetGraphicHeight(void);
	virtual int __fastcall GetGraphicWidth(void);
	virtual Dxpscore::TdxGraphicDrawMode __fastcall GetDrawMode(void);
	virtual void __fastcall InitializeGraphicItem(Dxpscore::TdxReportCellGraphic* AnItem);
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=SetBorderColor, default=0};
	__property bool Center = {read=FCenter, write=SetCenter, default=0};
	__property bool DrawBorder = {read=FDrawBorder, write=SetDrawBorder, default=0};
	__property Dxpscore::TdxGraphicDrawMode DrawMode = {read=GetDrawMode, nodefault};
	__property int GraphicHeight = {read=GetGraphicHeight, nodefault};
	__property int GraphicWidth = {read=GetGraphicWidth, nodefault};
	__property bool Proportional = {read=FProportional, write=SetProportional, default=0};
	__property bool Stretch = {read=FStretch, write=SetStretch, default=0};
	__property System::Uitypes::TColor TransparentColor = {read=FTransparentColor, write=SetTransparentColor, default=-16777211};
	
public:
	__fastcall virtual TCustomdxGraphicReportLink(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TCustomdxGraphicReportLink(void) { }
	
};


class DELPHICLASS TCustomdxPictureReportLink;
class PASCALIMPLEMENTATION TCustomdxPictureReportLink : public TCustomdxGraphicReportLink
{
	typedef TCustomdxGraphicReportLink inherited;
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual int __fastcall GetGraphicHeight(void);
	virtual int __fastcall GetGraphicWidth(void);
	virtual Vcl::Graphics::TPicture* __fastcall GetPicture(void);
	virtual void __fastcall InitializeGraphicItem(Dxpscore::TdxReportCellGraphic* AnItem);
	bool __fastcall IsPictureEmpty(Vcl::Graphics::TPicture* APicture);
	__property Vcl::Graphics::TPicture* Picture = {read=GetPicture};
	
public:
	virtual bool __fastcall DataProviderPresent(void);
public:
	/* TCustomdxGraphicReportLink.Create */ inline __fastcall virtual TCustomdxPictureReportLink(System::Classes::TComponent* AOwner) : TCustomdxGraphicReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TCustomdxPictureReportLink(void) { }
	
};


class DELPHICLASS TdxPictureReportLink;
class PASCALIMPLEMENTATION TdxPictureReportLink : public TCustomdxPictureReportLink
{
	typedef TCustomdxPictureReportLink inherited;
	
private:
	Vcl::Graphics::TPicture* FPicture;
	void __fastcall SetPicture(Vcl::Graphics::TPicture* Value);
	void __fastcall PictureChanged(System::TObject* Sender);
	
protected:
	virtual Vcl::Graphics::TPicture* __fastcall GetPicture(void);
	virtual void __fastcall SetComponent(System::Classes::TComponent* Value);
	
public:
	__fastcall virtual TdxPictureReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPictureReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property BorderColor = {default=0};
	__property DrawBorder = {default=0};
	__property Picture = {write=SetPicture};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsgraphiclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSGRAPHICLNK)
using namespace Dxpsgraphiclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsgraphiclnkHPP
