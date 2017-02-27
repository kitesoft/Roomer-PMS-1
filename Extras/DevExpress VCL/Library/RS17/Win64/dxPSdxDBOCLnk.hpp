// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSdxDBOCLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsdxdboclnkHPP
#define DxpsdxdboclnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <dxdborgc.hpp>	// Pascal unit
#include <dxPSdxOCLnk.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdxdboclnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDBOrgChartReportLink;
class PASCALIMPLEMENTATION TdxDBOrgChartReportLink : public Dxpsdxoclnk::TCustomdxOrgChartReportLink
{
	typedef Dxpsdxoclnk::TCustomdxOrgChartReportLink inherited;
	
private:
	Dxdborgc::TdxDbOrgChart* __fastcall GetDBOrgChart(void);
	
public:
	__property Dxdborgc::TdxDbOrgChart* DBOrgChart = {read=GetDBOrgChart};
	
__published:
	__property BorderColor = {default=0};
	__property Color = {default=16777215};
	__property DrawBorder = {default=0};
	__property FullExpand = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
	__property UseMetafile = {default=1};
public:
	/* TCustomdxOrgChartReportLink.Create */ inline __fastcall virtual TdxDBOrgChartReportLink(System::Classes::TComponent* AOwner) : Dxpsdxoclnk::TCustomdxOrgChartReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxDBOrgChartReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsdxdboclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDXDBOCLNK)
using namespace Dxpsdxdboclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdxdboclnkHPP
