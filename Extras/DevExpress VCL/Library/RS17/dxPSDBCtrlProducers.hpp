// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSDBCtrlProducers.pas' rev: 24.00 (Win32)

#ifndef DxpsdbctrlproducersHPP
#define DxpsdbctrlproducersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.DBCtrls.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdbctrlproducers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSDBEditProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSDBEditProducer : public Dxpscontainerlnk::TdxPSCustomEditProducer
{
	typedef Dxpscontainerlnk::TdxPSCustomEditProducer inherited;
	
private:
	Data::Db::TField* __fastcall Field(void);
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Vcl::Dbctrls::TDBEdit* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSDBEditProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSCustomEditProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSDBEditProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSDBLookupComboBoxProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSDBLookupComboBoxProducer : public Dxpscontainerlnk::TdxPSContainerWinControlProducer
{
	typedef Dxpscontainerlnk::TdxPSContainerWinControlProducer inherited;
	
protected:
	virtual void __fastcall InitializeItem(Dxpscore::TdxReportVisualItem* AnItem);
	
public:
	HIDESBASE Vcl::Dbctrls::TDBLookupComboBox* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPSDBLookupComboBoxProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSContainerWinControlProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSDBLookupComboBoxProducer(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsdbctrlproducers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDBCTRLPRODUCERS)
using namespace Dxpsdbctrlproducers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdbctrlproducersHPP
