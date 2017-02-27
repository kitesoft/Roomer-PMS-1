// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSImgLnk.pas' rev: 24.00 (Win32)

#ifndef DxpsimglnkHPP
#define DxpsimglnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsimglnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxImageReportLink;
class PASCALIMPLEMENTATION TdxImageReportLink : public Dxpsgraphiclnk::TCustomdxPictureReportLink
{
	typedef Dxpsgraphiclnk::TCustomdxPictureReportLink inherited;
	
private:
	Vcl::Extctrls::TImage* __fastcall GetImage(void);
	
protected:
	virtual void __fastcall InternalRestoreFromOriginal(void);
	virtual int __fastcall GetGraphicHeight(void);
	virtual int __fastcall GetGraphicWidth(void);
	virtual Vcl::Graphics::TPicture* __fastcall GetPicture(void);
	
public:
	virtual bool __fastcall DataProviderPresent(void);
	__property Vcl::Extctrls::TImage* Image = {read=GetImage};
	
__published:
	__property BorderColor = {default=0};
	__property Center = {default=0};
	__property DrawBorder = {default=0};
	__property Proportional = {default=0};
	__property Stretch = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
public:
	/* TCustomdxGraphicReportLink.Create */ inline __fastcall virtual TdxImageReportLink(System::Classes::TComponent* AOwner) : Dxpsgraphiclnk::TCustomdxPictureReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxImageReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsimglnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSIMGLNK)
using namespace Dxpsimglnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsimglnkHPP
