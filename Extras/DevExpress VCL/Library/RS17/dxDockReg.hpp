// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockReg.pas' rev: 24.00 (Win32)

#ifndef DxdockregHPP
#define DxdockregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDockingComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockingComponentEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxDockingComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxDockingComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxDockingImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockingImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxDockingImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxDockingImageIndexProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxDockProductName L"ExpressDocking Library"
#define dxDockProductPage L"ExpressDocking"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxdockreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKREG)
using namespace Dxdockreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockregHPP
