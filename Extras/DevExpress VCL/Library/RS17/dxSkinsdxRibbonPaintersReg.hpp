// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsdxRibbonPaintersReg.pas' rev: 24.00 (Win32)

#ifndef DxskinsdxribbonpaintersregHPP
#define DxskinsdxribbonpaintersregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <dxSkinsReg.hpp>	// Pascal unit
#include <dxSkinsDesignHelperReg.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxRibbonReg.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxSkinsdxRibbonPainter.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdxribbonpaintersreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinsdxRibbonColorSchemeNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsdxRibbonColorSchemeNameProperty : public Dxribbonreg::TdxRibbonColorSchemeNameProperty
{
	typedef Dxribbonreg::TdxRibbonColorSchemeNameProperty inherited;
	
protected:
	virtual bool __fastcall CanAddSkin(Dxribbonskins::TdxCustomRibbonSkin* ASkin);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxSkinsdxRibbonColorSchemeNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dxribbonreg::TdxRibbonColorSchemeNameProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxSkinsdxRibbonColorSchemeNameProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxskinsdxribbonpaintersreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDXRIBBONPAINTERSREG)
using namespace Dxskinsdxribbonpaintersreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdxribbonpaintersregHPP
