// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonReg.pas' rev: 24.00 (Win32)

#ifndef DxribbonregHPP
#define DxribbonregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <ColnEdit.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <dxBarReg.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <dxBarSkin.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxStatusBar.hpp>	// Pascal unit
#include <dxRibbonStatusBar.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxComponentCollectionEditor.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <dxRibbonMiniToolbar.hpp>	// Pascal unit
#include <dxBarPopupMenuEd.hpp>	// Pascal unit
#include <dxRibbonRadialMenu.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxRibbonDesignEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonDesignEditor : public Dxbarreg::TdxBarComponentEditor
{
	typedef Dxbarreg::TdxBarComponentEditor inherited;
	
private:
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	
public:
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxRibbonDesignEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxbarreg::TdxBarComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxRibbonDesignEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonColorSchemeNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonColorSchemeNameProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
protected:
	virtual bool __fastcall CanAddSkin(Dxribbonskins::TdxCustomRibbonSkin* ASkin);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value)/* overload */;
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxRibbonColorSchemeNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxRibbonColorSchemeNameProperty(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonApplicationMenuProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonApplicationMenuProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
public:
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxRibbonApplicationMenuProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxRibbonApplicationMenuProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessGroupButtonToolbarProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessGroupButtonToolbarProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
private:
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxRibbonQuickAccessGroupButtonToolbarProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessGroupButtonToolbarProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonStatusBarEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonStatusBarEditor : public Dxbarreg::TdxBarComponentEditor
{
	typedef Dxbarreg::TdxBarComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxRibbonStatusBarEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxbarreg::TdxBarComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonSelectionEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonSelectionEditor : public Designeditors::TSelectionEditor
{
	typedef Designeditors::TSelectionEditor inherited;
	
public:
	virtual void __fastcall RequiresUnits(System::Classes::TGetStrProc Proc);
public:
	/* TSelectionEditor.Create */ inline __fastcall virtual TdxRibbonSelectionEditor(const Designintf::_di_IDesigner ADesigner) : Designeditors::TSelectionEditor(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonSelectionEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarProperty;
class PASCALIMPLEMENTATION TdxBarProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
private:
	Designintf::TGetPropProc FProc;
	void __fastcall GetPropProc(const Designintf::_di_IProperty Prop);
	
public:
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxBarProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxBarProperty(void) { }
	
};


class DELPHICLASS TdxExtraPaneEventEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxExtraPaneEventEditor : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
	
public:
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxExtraPaneEventEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxExtraPaneEventEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonContextProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonContextProperty : public Designeditors::TClassProperty
{
	typedef Designeditors::TClassProperty inherited;
	
private:
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	Dxribbon::TdxRibbonTab* __fastcall GetTab(void);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value)/* overload */;
	virtual System::UnicodeString __fastcall GetValue(void);
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property Dxribbon::TdxRibbonTab* Tab = {read=GetTab};
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxRibbonContextProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxRibbonContextProperty(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonMiniToolbarEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonMiniToolbarEditor : public Dxbarreg::TdxBarComponentEditor
{
	typedef Dxbarreg::TdxBarComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxRibbonMiniToolbarEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxbarreg::TdxBarComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxRibbonMiniToolbarEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonRadialMenuEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonRadialMenuEditor : public Dxbarreg::TdxBarComponentEditor
{
	typedef Dxbarreg::TdxBarComponentEditor inherited;
	
protected:
	virtual bool __fastcall IsAssignable(void);
	virtual void __fastcall DoAssign(System::TObject* AObject);
	virtual System::UnicodeString __fastcall GetAssignItemCaption(void);
	virtual System::TClass __fastcall GetAssignTypeClass(void);
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxRibbonRadialMenuEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxbarreg::TdxBarComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxRibbonRadialMenuEditor(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define EmptyContext L"<none>"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxribbonreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONREG)
using namespace Dxribbonreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonregHPP
