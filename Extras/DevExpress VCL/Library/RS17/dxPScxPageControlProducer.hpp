// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxPageControlProducer.pas' rev: 24.00 (Win32)

#ifndef DxpscxpagecontrolproducerHPP
#define DxpscxpagecontrolproducerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxPSContainerLnk.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxpagecontrolproducer
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPScxTabControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxTabControlProducer : public Dxpscontainerlnk::TdxPSRootContainerProducer
{
	typedef Dxpscontainerlnk::TdxPSRootContainerProducer inherited;
	
public:
	HIDESBASE Cxpc::TcxTabControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxTabControlProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxTabControlProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxPageControlIterator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxPageControlIterator : public Dxpscontainerlnk::TdxPSWinControlIterator
{
	typedef Dxpscontainerlnk::TdxPSWinControlIterator inherited;
	
private:
	Cxpc::TcxPageControl* __fastcall GetPageControl(void);
	
protected:
	virtual Vcl::Controls::TControl* __fastcall GetControl(int Index);
	virtual int __fastcall GetControlCount(void);
	
public:
	__property Cxpc::TcxPageControl* PageControl = {read=GetPageControl};
public:
	/* TdxPSWinControlIterator.Create */ inline __fastcall virtual TdxPScxPageControlIterator(Vcl::Controls::TWinControl* AControl) : Dxpscontainerlnk::TdxPSWinControlIterator(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxPageControlIterator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxTabSheetProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxTabSheetProducer : public Dxpscontainerlnk::TdxPSRootContainerProducer
{
	typedef Dxpscontainerlnk::TdxPSRootContainerProducer inherited;
	
public:
	HIDESBASE Cxpc::TcxTabSheet* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxTabSheetProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxTabSheetProducer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPScxPageControlProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPScxPageControlProducer : public Dxpscontainerlnk::TdxPSRootContainerProducer
{
	typedef Dxpscontainerlnk::TdxPSRootContainerProducer inherited;
	
protected:
	virtual bool __fastcall CanProcessChild(Vcl::Controls::TControl* AChildControl);
	__classmethod virtual Dxpscontainerlnk::TdxPSWinControlIteratorClass __fastcall IteratorClass();
	
public:
	HIDESBASE Cxpc::TcxPageControl* __fastcall Control(void)/* overload */;
	__classmethod virtual Vcl::Controls::TControlClass __fastcall ControlClass();
public:
	/* TdxPSCustomProducer.Create */ inline __fastcall virtual TdxPScxPageControlProducer(Dxpscontainerlnk::TdxCustomContainerReportLink* AReportLink, System::Classes::TComponent* AnObject) : Dxpscontainerlnk::TdxPSRootContainerProducer(AReportLink, AnObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPScxPageControlProducer(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpscxpagecontrolproducer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXPAGECONTROLPRODUCER)
using namespace Dxpscxpagecontrolproducer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxpagecontrolproducerHPP
