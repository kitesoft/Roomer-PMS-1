// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBevel.pas' rev: 24.00 (Win64)

#ifndef DxbevelHPP
#define DxbevelHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbevel
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxCustomBevel;
class PASCALIMPLEMENTATION TdxCustomBevel : public Vcl::Controls::TGraphicControl
{
	typedef Vcl::Controls::TGraphicControl inherited;
	
private:
	Cxgraphics::TcxCanvas* FcxCanvas;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	Cxlookandfeelpainters::TdxBevelShape FShape;
	Cxlookandfeelpainters::TdxBevelStyle FStyle;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetShape(Cxlookandfeelpainters::TdxBevelShape AValue);
	void __fastcall SetStyle(Cxlookandfeelpainters::TdxBevelStyle AValue);
	
protected:
	virtual bool __fastcall CanAutoHeight(Cxlookandfeelpainters::TdxBevelShape AShape);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual bool __fastcall CanAutoWidth(Cxlookandfeelpainters::TdxBevelShape AShape);
	bool __fastcall IsHorzLineShape(Cxlookandfeelpainters::TdxBevelShape AShape);
	bool __fastcall IsVertLineShape(Cxlookandfeelpainters::TdxBevelShape AShape);
	virtual void __fastcall LookAndFeelChangeHandler(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Paint(void);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	__property Cxgraphics::TcxCanvas* cxCanvas = {read=FcxCanvas};
	
public:
	__fastcall virtual TdxCustomBevel(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomBevel(void);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property Cxlookandfeelpainters::TdxBevelShape Shape = {read=FShape, write=SetShape, default=1};
	__property Cxlookandfeelpainters::TdxBevelStyle Style = {read=FStyle, write=SetStyle, default=0};
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
	
};


class DELPHICLASS TdxBevel;
class PASCALIMPLEMENTATION TdxBevel : public TdxCustomBevel
{
	typedef TdxCustomBevel inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoSize = {default=0};
	__property Constraints;
	__property LookAndFeel;
	__property Shape = {default=1};
	__property Style = {default=0};
	__property Visible = {default=1};
public:
	/* TdxCustomBevel.Create */ inline __fastcall virtual TdxBevel(System::Classes::TComponent* AOwner) : TdxCustomBevel(AOwner) { }
	/* TdxCustomBevel.Destroy */ inline __fastcall virtual ~TdxBevel(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbevel */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBEVEL)
using namespace Dxbevel;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbevelHPP
