// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControlReg.pas' rev: 24.00 (Win32)

#ifndef DxwizardcontrolregHPP
#define DxwizardcontrolregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <dxCustomWizardControl.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <dxWizardControl.hpp>	// Pascal unit
#include <dxWizardControlPageCollectionEditor.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrolreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxWizardControlCustomComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlCustomComponentEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
protected:
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual System::UnicodeString __fastcall GetProductName(void);
	virtual Dxcustomwizardcontrol::TdxCustomWizardControl* __fastcall GetWizardControl(void) = 0 ;
	
public:
	void __fastcall AddPage(void);
	void __fastcall DeletePage(void);
	virtual void __fastcall Edit(void);
	void __fastcall NextPage(void);
	void __fastcall PrevPage(void);
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem);
	__property Dxcustomwizardcontrol::TdxCustomWizardControl* WizardControl = {read=GetWizardControl};
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxWizardControlCustomComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxWizardControlCustomComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlComponentEditor : public TdxWizardControlCustomComponentEditor
{
	typedef TdxWizardControlCustomComponentEditor inherited;
	
protected:
	virtual Dxcustomwizardcontrol::TdxCustomWizardControl* __fastcall GetWizardControl(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxWizardControlComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TdxWizardControlCustomComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxWizardControlComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlPageComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlPageComponentEditor : public TdxWizardControlCustomComponentEditor
{
	typedef TdxWizardControlCustomComponentEditor inherited;
	
protected:
	virtual Dxcustomwizardcontrol::TdxCustomWizardControl* __fastcall GetWizardControl(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxWizardControlPageComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TdxWizardControlCustomComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxWizardControlPageComponentEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlPageDesignWindow;
class PASCALIMPLEMENTATION TdxWizardControlPageDesignWindow : public Cxdesignwindows::TcxGlobalDesignWindow
{
	typedef Cxdesignwindows::TcxGlobalDesignWindow inherited;
	
private:
	System::Classes::TList* FCurrentSelection;
	
protected:
	void __fastcall DoAddFreeNotification(System::Classes::TList* AList);
	void __fastcall DoRemoveFreeNotification(System::Classes::TList* AList);
	void __fastcall DoSelectionChanged(System::Classes::TList* AList);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TdxWizardControlPageDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxWizardControlPageDesignWindow(void);
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, System::Classes::TPersistent* Item);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxWizardControlPageDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxGlobalDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlPageDesignWindow(HWND ParentWindow) : Cxdesignwindows::TcxGlobalDesignWindow(ParentWindow) { }
	
};


class DELPHICLASS TdxWizardControlButtonImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlButtonImageIndexProperty : public Cxpropeditors::TImageIndexProperty
{
	typedef Cxpropeditors::TImageIndexProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxWizardControlButtonImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TImageIndexProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxWizardControlButtonImageIndexProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlPageAccess;
class PASCALIMPLEMENTATION TdxWizardControlPageAccess : public Dxcustomwizardcontrol::TdxWizardControlCustomPage
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomPage inherited;
	
public:
	/* TdxWizardControlCustomPage.Create */ inline __fastcall virtual TdxWizardControlPageAccess(System::Classes::TComponent* AComponent) : Dxcustomwizardcontrol::TdxWizardControlCustomPage(AComponent) { }
	/* TdxWizardControlCustomPage.Destroy */ inline __fastcall virtual ~TdxWizardControlPageAccess(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlPageAccess(HWND ParentWindow) : Dxcustomwizardcontrol::TdxWizardControlCustomPage(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define sdxWizardControlProductName L"ExpressWizardControl Suite"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxwizardcontrolreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROLREG)
using namespace Dxwizardcontrolreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwizardcontrolregHPP
