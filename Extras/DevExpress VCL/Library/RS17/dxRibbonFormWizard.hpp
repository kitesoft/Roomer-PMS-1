// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonFormWizard.pas' rev: 24.00 (Win32)

#ifndef DxribbonformwizardHPP
#define DxribbonformwizardHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <ToolsAPI.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <dxRibbonReg.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <dxRibbonForm.hpp>	// Pascal unit
#include <dxDesignHelpers.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonformwizard
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxOTACustomRibbonWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTACustomRibbonWizard : public Dxdesignhelpers::TdxOTACustomRepositoryWizard
{
	typedef Dxdesignhelpers::TdxOTACustomRepositoryWizard inherited;
	
private:
	Dxdesignhelpers::TdxOTAPersonality FPersonality;
	Dxribbonskins::TdxRibbonStyle FRibbonStyle;
	
protected:
	System::UnicodeString __fastcall ExpandRibbonStyleName(const System::UnicodeString AFormat);
	virtual unsigned __fastcall GetGlyph(void);
	virtual System::UnicodeString __fastcall GetIDString(void);
	virtual Dxdesignhelpers::TdxOTAPersonality __fastcall GetPersonality(void);
	
public:
	__fastcall virtual TdxOTACustomRibbonWizard(Dxribbonskins::TdxRibbonStyle ARibbonStyle, Dxdesignhelpers::TdxOTAPersonality APersonality);
	__property Dxdesignhelpers::TdxOTAPersonality Personality = {read=GetPersonality, nodefault};
	__property Dxribbonskins::TdxRibbonStyle RibbonStyle = {read=FRibbonStyle, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTACustomRibbonWizard(void) { }
	
private:
	void *__IOTAFormWizard;	/* Toolsapi::IOTAFormWizard */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {36C8BF35-EFFE-11D1-AB1D-00C04FB16FB3}
	operator Toolsapi::_di_IOTAFormWizard()
	{
		Toolsapi::_di_IOTAFormWizard intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAFormWizard*(void) { return (Toolsapi::IOTAFormWizard*)&__IOTAFormWizard; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTARibbonApplicationCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTARibbonApplicationCreator : public Dxdesignhelpers::TdxOTACustomProjectCreator
{
	typedef Dxdesignhelpers::TdxOTACustomProjectCreator inherited;
	
private:
	Dxdesignhelpers::TdxOTAPersonality FPersonality;
	
protected:
	virtual System::UnicodeString __fastcall GetCreatorType(void);
	virtual Dxdesignhelpers::TdxOTAPersonality __fastcall GetPersonality(void);
	
public:
	__fastcall virtual TdxOTARibbonApplicationCreator(Dxdesignhelpers::TdxOTAPersonality APersonality);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTARibbonApplicationCreator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTARibbonApplicationWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTARibbonApplicationWizard : public TdxOTACustomRibbonWizard
{
	typedef TdxOTACustomRibbonWizard inherited;
	
protected:
	virtual void __fastcall Execute(void);
	virtual Dxdesignhelpers::TdxOTARepositoryCategory __fastcall GetCategory(void);
	virtual System::UnicodeString __fastcall GetComment(void);
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TdxOTACustomRibbonWizard.Create */ inline __fastcall virtual TdxOTARibbonApplicationWizard(Dxribbonskins::TdxRibbonStyle ARibbonStyle, Dxdesignhelpers::TdxOTAPersonality APersonality) : TdxOTACustomRibbonWizard(ARibbonStyle, APersonality) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTARibbonApplicationWizard(void) { }
	
private:
	void *__IOTAProjectWizard;	/* Toolsapi::IOTAProjectWizard */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {36C8BF36-EFFE-11D1-AB1D-00C04FB16FB3}
	operator Toolsapi::_di_IOTAProjectWizard()
	{
		Toolsapi::_di_IOTAProjectWizard intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAProjectWizard*(void) { return (Toolsapi::IOTAProjectWizard*)&__IOTAProjectWizard; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTARibbonFormCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTARibbonFormCreator : public Dxdesignhelpers::TdxOTAFormCreator
{
	typedef Dxdesignhelpers::TdxOTAFormCreator inherited;
	
private:
	Dxribbonskins::TdxRibbonStyle FRibbonStyle;
	System::UnicodeString __fastcall LoadTemplate(const System::UnicodeString AName);
	void __fastcall LoadTemplates(Dxdesignhelpers::TdxOTAPersonality APersonality, /* out */ System::UnicodeString &AFormTemplate, /* out */ System::UnicodeString &AImplTemplate, /* out */ System::UnicodeString &AIntfTemplate);
	
protected:
	virtual System::UnicodeString __fastcall ExpandTemplate(const System::UnicodeString ATemplate, const System::UnicodeString AModuleIdent, const System::UnicodeString AFormIdent, const System::UnicodeString AAncestorIdent);
	
public:
	__fastcall TdxOTARibbonFormCreator(Dxribbonskins::TdxRibbonStyle ARibbonStyle, Dxdesignhelpers::TdxOTAPersonality APersonality);
	__property Dxribbonskins::TdxRibbonStyle RibbonStyle = {read=FRibbonStyle, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTARibbonFormCreator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTARibbonFormWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTARibbonFormWizard : public TdxOTACustomRibbonWizard
{
	typedef TdxOTACustomRibbonWizard inherited;
	
protected:
	virtual void __fastcall Execute(void);
	virtual System::UnicodeString __fastcall GetComment(void);
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TdxOTACustomRibbonWizard.Create */ inline __fastcall virtual TdxOTARibbonFormWizard(Dxribbonskins::TdxRibbonStyle ARibbonStyle, Dxdesignhelpers::TdxOTAPersonality APersonality) : TdxOTACustomRibbonWizard(ARibbonStyle, APersonality) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTARibbonFormWizard(void) { }
	
private:
	void *__IOTAProjectWizard;	/* Toolsapi::IOTAProjectWizard */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {36C8BF36-EFFE-11D1-AB1D-00C04FB16FB3}
	operator Toolsapi::_di_IOTAProjectWizard()
	{
		Toolsapi::_di_IOTAProjectWizard intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAProjectWizard*(void) { return (Toolsapi::IOTAProjectWizard*)&__IOTAProjectWizard; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define sdxRibbonApplicationWizardComment L"Create a Ribbon Office %style% style VCL application"
#define sdxRibbonApplicationWizardName L"DevExpress VCL %version% Ribbon %style% Application"
#define sdxRibbonFormWizardComment L"Create a Ribbon Office %style% style VCL form"
#define sdxRibbonFormWizardName L"DevExpress VCL %version% Ribbon %style% Form"
}	/* namespace Dxribbonformwizard */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONFORMWIZARD)
using namespace Dxribbonformwizard;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonformwizardHPP
