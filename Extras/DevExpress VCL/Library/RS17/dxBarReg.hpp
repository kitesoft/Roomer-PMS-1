// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarReg.pas' rev: 24.00 (Win32)

#ifndef DxbarregHPP
#define DxbarregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxScreenTipRepositoryEditor.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarComponentEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxBarComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxBarComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarItemImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarItemImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
private:
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	
protected:
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBarItemImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBarItemImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarItemLargeImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarItemLargeImageIndexProperty : public TdxBarItemImageIndexProperty
{
	typedef TdxBarItemImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBarItemLargeImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TdxBarItemImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBarItemLargeImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarItemHotImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarItemHotImageIndexProperty : public TdxBarItemImageIndexProperty
{
	typedef TdxBarItemImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBarItemHotImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TdxBarItemImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBarItemHotImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarItemLinkImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarItemLinkImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
private:
	Dxbar::TdxBarItemLink* __fastcall GetItemLink(void);
	
protected:
	__property Dxbar::TdxBarItemLink* ItemLink = {read=GetItemLink};
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBarItemLinkImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBarItemLinkImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarItemLinksPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarItemLinksPropertyEditor : public Designeditors::TPropertyEditor
{
	typedef Designeditors::TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBarItemLinksPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TPropertyEditor(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBarItemLinksPropertyEditor(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxBarProductName L"ExpressBars"
#define dxBarProductPage L"ExpressBars"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxbarreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARREG)
using namespace Dxbarreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarregHPP
