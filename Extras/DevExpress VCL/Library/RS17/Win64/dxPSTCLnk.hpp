// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSTCLnk.pas' rev: 24.00 (Win64)

#ifndef DxpstclnkHPP
#define DxpstclnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <VCLTee.Chart.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpstclnk
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TdxPSTeeChartReportLinkGetGraphicClassEvent)(Dxpscore::TBasedxReportLink* Sender, Vcl::Graphics::TGraphicClass &AGraphicClass);

typedef void __fastcall (__closure *TdxPSTeeChartReportLinkCreateGraphicEvent)(Dxpscore::TBasedxReportLink* Sender, Vcl::Graphics::TGraphic* &AGraphic);

class DELPHICLASS TCustomdxTeeChartReportLink;
class PASCALIMPLEMENTATION TCustomdxTeeChartReportLink : public Dxpsgraphiclnk::TCustomdxGraphicReportLink
{
	typedef Dxpsgraphiclnk::TCustomdxGraphicReportLink inherited;
	
private:
	Vcl::Graphics::TGraphicClass FGraphicClass;
	bool FIsGraphicClassAssigned;
	TdxPSTeeChartReportLinkCreateGraphicEvent FOnCreateGraphic;
	TdxPSTeeChartReportLinkGetGraphicClassEvent FOnGetGraphicClass;
	Vcltee::Chart::TCustomChart* __fastcall GetChart(void);
	System::UnicodeString __fastcall GetGraphicClassName(void);
	Vcl::Graphics::TGraphicClass __fastcall GetGraphicClassValue(void);
	bool __fastcall IsGraphicClassNameStored(void);
	void __fastcall SetGraphicClassName(const System::UnicodeString Value);
	void __fastcall SetGraphicClassValue(Vcl::Graphics::TGraphicClass Value);
	
protected:
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	virtual int __fastcall GetGraphicHeight(void);
	virtual int __fastcall GetGraphicWidth(void);
	virtual void __fastcall CreateGraphicStandard(Vcl::Graphics::TGraphic* &AGraphic);
	DYNAMIC bool __fastcall DoCreateGraphic(Vcl::Graphics::TGraphic* &AGraphic);
	DYNAMIC void __fastcall DoGetGraphicClass(Vcl::Graphics::TGraphicClass &AGraphicClass);
	__property Vcltee::Chart::TCustomChart* Chart = {read=GetChart};
	__property Vcl::Graphics::TGraphicClass GraphicClass = {read=GetGraphicClassValue, write=SetGraphicClassValue};
	__property System::UnicodeString GraphicClassName = {read=GetGraphicClassName, write=SetGraphicClassName, stored=IsGraphicClassNameStored};
	__property TdxPSTeeChartReportLinkCreateGraphicEvent OnCreateGraphic = {read=FOnCreateGraphic, write=FOnCreateGraphic};
	__property TdxPSTeeChartReportLinkGetGraphicClassEvent OnGetGraphicClass = {read=FOnGetGraphicClass, write=FOnGetGraphicClass};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	virtual Vcl::Graphics::TGraphicClass __fastcall DefaultGraphicClass(void);
public:
	/* TCustomdxGraphicReportLink.Create */ inline __fastcall virtual TCustomdxTeeChartReportLink(System::Classes::TComponent* AOwner) : Dxpsgraphiclnk::TCustomdxGraphicReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TCustomdxTeeChartReportLink(void) { }
	
};


class DELPHICLASS TdxTeeChartReportLink;
class PASCALIMPLEMENTATION TdxTeeChartReportLink : public TCustomdxTeeChartReportLink
{
	typedef TCustomdxTeeChartReportLink inherited;
	
private:
	HIDESBASE Vcltee::Chart::TChart* __fastcall GetChart(void);
	
public:
	__property Vcltee::Chart::TChart* Chart = {read=GetChart};
	__property GraphicClass;
	
__published:
	__property GraphicClassName = {default=0};
	__property OnCreateGraphic;
	__property OnGetGraphicClass;
public:
	/* TCustomdxGraphicReportLink.Create */ inline __fastcall virtual TdxTeeChartReportLink(System::Classes::TComponent* AOwner) : TCustomdxTeeChartReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxTeeChartReportLink(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpstclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSTCLNK)
using namespace Dxpstclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpstclnkHPP
