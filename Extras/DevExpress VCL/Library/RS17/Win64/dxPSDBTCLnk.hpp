// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSDBTCLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsdbtclnkHPP
#define DxpsdbtclnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <VCLTee.DBChart.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSTCLnk.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdbtclnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBTeeChartReportLink;
class PASCALIMPLEMENTATION TdxDBTeeChartReportLink : public Dxpstclnk::TCustomdxTeeChartReportLink
{
	typedef Dxpstclnk::TCustomdxTeeChartReportLink inherited;
	
private:
	Vcltee::Dbchart::TDBChart* __fastcall GetDBChart(void);
	
public:
	__property Vcltee::Dbchart::TDBChart* DBChart = {read=GetDBChart};
	__property GraphicClass;
	
__published:
	__property GraphicClassName = {default=0};
	__property OnCreateGraphic;
	__property OnGetGraphicClass;
public:
	/* TCustomdxGraphicReportLink.Create */ inline __fastcall virtual TdxDBTeeChartReportLink(System::Classes::TComponent* AOwner) : Dxpstclnk::TCustomdxTeeChartReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxDBTeeChartReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsdbtclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDBTCLNK)
using namespace Dxpsdbtclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdbtclnkHPP
