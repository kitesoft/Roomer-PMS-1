// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControlFormWizard.pas' rev: 24.00 (Win32)

#ifndef DxwizardcontrolformwizardHPP
#define DxwizardcontrolformwizardHPP

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
#include <dxWizardControlReg.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <dxWizardControlForm.hpp>	// Pascal unit
#include <dxDesignHelpers.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrolformwizard
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxOTACustomWizardControlWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTACustomWizardControlWizard : public Dxdesignhelpers::TdxOTACustomRepositoryWizard
{
	typedef Dxdesignhelpers::TdxOTACustomRepositoryWizard inherited;
	
private:
	Dxdesignhelpers::TdxOTAPersonality FPersonality;
	
protected:
	System::UnicodeString __fastcall ExpandWizardControlName(const System::UnicodeString AFormat);
	virtual unsigned __fastcall GetGlyph(void);
	virtual System::UnicodeString __fastcall GetIDString(void);
	virtual Dxdesignhelpers::TdxOTAPersonality __fastcall GetPersonality(void);
	
public:
	__fastcall virtual TdxOTACustomWizardControlWizard(Dxdesignhelpers::TdxOTAPersonality APersonality);
	__property Dxdesignhelpers::TdxOTAPersonality Personality = {read=GetPersonality, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTACustomWizardControlWizard(void) { }
	
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

class DELPHICLASS TdxOTAWizardControlApplicationCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTAWizardControlApplicationCreator : public Dxdesignhelpers::TdxOTACustomProjectCreator
{
	typedef Dxdesignhelpers::TdxOTACustomProjectCreator inherited;
	
private:
	Dxdesignhelpers::TdxOTAPersonality FPersonality;
	
protected:
	virtual System::UnicodeString __fastcall GetCreatorType(void);
	virtual Dxdesignhelpers::TdxOTAPersonality __fastcall GetPersonality(void);
	
public:
	__fastcall virtual TdxOTAWizardControlApplicationCreator(Dxdesignhelpers::TdxOTAPersonality APersonality);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTAWizardControlApplicationCreator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTAWizardControlApplicationWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTAWizardControlApplicationWizard : public TdxOTACustomWizardControlWizard
{
	typedef TdxOTACustomWizardControlWizard inherited;
	
protected:
	virtual void __fastcall Execute(void);
	virtual Dxdesignhelpers::TdxOTARepositoryCategory __fastcall GetCategory(void);
	virtual System::UnicodeString __fastcall GetComment(void);
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TdxOTACustomWizardControlWizard.Create */ inline __fastcall virtual TdxOTAWizardControlApplicationWizard(Dxdesignhelpers::TdxOTAPersonality APersonality) : TdxOTACustomWizardControlWizard(APersonality) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTAWizardControlApplicationWizard(void) { }
	
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

class DELPHICLASS TdxOTAWizardControlFormCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTAWizardControlFormCreator : public Dxdesignhelpers::TdxOTAFormCreator
{
	typedef Dxdesignhelpers::TdxOTAFormCreator inherited;
	
private:
	System::UnicodeString __fastcall LoadTemplate(const System::UnicodeString AName);
	void __fastcall LoadTemplates(Dxdesignhelpers::TdxOTAPersonality APersonality, /* out */ System::UnicodeString &AFormTemplate, /* out */ System::UnicodeString &AImplTemplate, /* out */ System::UnicodeString &AIntfTemplate);
	
public:
	__fastcall TdxOTAWizardControlFormCreator(Dxdesignhelpers::TdxOTAPersonality APersonality);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTAWizardControlFormCreator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTAWizardControlFormWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTAWizardControlFormWizard : public TdxOTACustomWizardControlWizard
{
	typedef TdxOTACustomWizardControlWizard inherited;
	
protected:
	virtual void __fastcall Execute(void);
	virtual System::UnicodeString __fastcall GetComment(void);
	virtual System::UnicodeString __fastcall GetName(void);
public:
	/* TdxOTACustomWizardControlWizard.Create */ inline __fastcall virtual TdxOTAWizardControlFormWizard(Dxdesignhelpers::TdxOTAPersonality APersonality) : TdxOTACustomWizardControlWizard(APersonality) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTAWizardControlFormWizard(void) { }
	
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
#define sdxWizardControlApplicationWizardComment L"Create a Wizard VCL application"
#define sdxWizardControlApplicationWizardName L"DevExpress VCL %version% Wizard Application"
#define sdxWizardControlFormWizardComment L"Create a Wizard VCL form"
#define sdxWizardControlFormWizardName L"DevExpress VCL %version% Wizard Form"
}	/* namespace Dxwizardcontrolformwizard */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROLFORMWIZARD)
using namespace Dxwizardcontrolformwizard;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwizardcontrolformwizardHPP
