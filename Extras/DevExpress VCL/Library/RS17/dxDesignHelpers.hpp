// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDesignHelpers.pas' rev: 24.00 (Win32)

#ifndef DxdesignhelpersHPP
#define DxdesignhelpersHPP

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
#include <dxCoreReg.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdesignhelpers
{
//-- type declarations -------------------------------------------------------
enum TdxOTARepositoryCategory : unsigned char { dxcNewProject, dxcNewFiles };

enum TdxOTAPersonality : unsigned char { dxopDelphi, dxopCBuilder };

class DELPHICLASS TdxOTACustomRepositoryWizard;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTACustomRepositoryWizard : public Toolsapi::TNotifierObject
{
	typedef Toolsapi::TNotifierObject inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetIDString(void);
	virtual System::UnicodeString __fastcall GetName(void) = 0 ;
	Toolsapi::TWizardState __fastcall GetState(void);
	virtual void __fastcall Execute(void) = 0 ;
	System::UnicodeString __fastcall GetAuthor(void);
	virtual System::UnicodeString __fastcall GetComment(void);
	virtual unsigned __fastcall GetGlyph(void);
	System::UnicodeString __fastcall GetPage(void);
	System::UnicodeString __fastcall GetDesigner(void);
	Toolsapi::_di_IOTAGalleryCategory __fastcall Wizard80GetGalleryCategory(void);
	System::UnicodeString __fastcall Wizard80GetPersonality(void);
	virtual TdxOTARepositoryCategory __fastcall GetCategory(void);
	virtual TdxOTAPersonality __fastcall GetPersonality(void) = 0 ;
	__property TdxOTARepositoryCategory Category = {read=GetCategory, nodefault};
	__property TdxOTAPersonality Personality = {read=GetPersonality, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxOTACustomRepositoryWizard(void) : Toolsapi::TNotifierObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTACustomRepositoryWizard(void) { }
	
private:
	void *__IOTARepositoryWizard80;	/* Toolsapi::IOTARepositoryWizard80 */
	void *__IOTARepositoryWizard60;	/* Toolsapi::IOTARepositoryWizard60 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B75C0CE0-EEA6-11D1-9504-00608CCBF153}
	operator Toolsapi::_di_IOTAWizard()
	{
		Toolsapi::_di_IOTAWizard intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAWizard*(void) { return (Toolsapi::IOTAWizard*)&__IOTARepositoryWizard60; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D7714D41-BC4A-445E-B695-25A65C2F561E}
	operator Toolsapi::_di_IOTARepositoryWizard80()
	{
		Toolsapi::_di_IOTARepositoryWizard80 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTARepositoryWizard80*(void) { return (Toolsapi::IOTARepositoryWizard80*)&__IOTARepositoryWizard80; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {08FCCD88-3A21-4281-ADC9-62FC034CDD12}
	operator Toolsapi::_di_IOTARepositoryWizard60()
	{
		Toolsapi::_di_IOTARepositoryWizard60 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTARepositoryWizard60*(void) { return (Toolsapi::IOTARepositoryWizard60*)&__IOTARepositoryWizard60; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B75C0CE1-EEA6-11D1-9504-00608CCBF153}
	operator Toolsapi::_di_IOTARepositoryWizard()
	{
		Toolsapi::_di_IOTARepositoryWizard intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTARepositoryWizard*(void) { return (Toolsapi::IOTARepositoryWizard*)&__IOTARepositoryWizard60; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTACustomCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTACustomCreator : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCreatorType(void) = 0 ;
	virtual bool __fastcall GetExisting(void);
	virtual System::UnicodeString __fastcall GetFileSystem(void);
	virtual Toolsapi::_di_IOTAModule __fastcall GetOwner(void);
	virtual bool __fastcall GetUnnamed(void);
public:
	/* TObject.Create */ inline __fastcall TdxOTACustomCreator(void) : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTACustomCreator(void) { }
	
private:
	void *__IOTACreator;	/* Toolsapi::IOTACreator */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6EDB9B9E-F57A-11D1-AB23-00C04FB16FB3}
	operator Toolsapi::_di_IOTACreator()
	{
		Toolsapi::_di_IOTACreator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTACreator*(void) { return (Toolsapi::IOTACreator*)&__IOTACreator; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTAFormCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTAFormCreator : public TdxOTACustomCreator
{
	typedef TdxOTACustomCreator inherited;
	
private:
	System::UnicodeString FFormTemplate;
	System::UnicodeString FImplTemplate;
	System::UnicodeString FIntfTemplate;
	Toolsapi::_di_IOTAFile __fastcall CreateOTAFile(const System::UnicodeString ATemplate, const System::UnicodeString AModuleIdent, const System::UnicodeString AFormIdent, const System::UnicodeString AAncestorIdent);
	
protected:
	virtual System::UnicodeString __fastcall ExpandTemplate(const System::UnicodeString ATemplate, const System::UnicodeString AModuleIdent, const System::UnicodeString AFormIdent, const System::UnicodeString AAncestorIdent);
	virtual System::UnicodeString __fastcall GetCreatorType(void);
	virtual System::UnicodeString __fastcall GetAncestorName(void);
	virtual System::UnicodeString __fastcall GetFormName(void);
	virtual System::UnicodeString __fastcall GetImplFileName(void);
	virtual System::UnicodeString __fastcall GetIntfFileName(void);
	virtual bool __fastcall GetMainForm(void);
	virtual bool __fastcall GetShowForm(void);
	virtual bool __fastcall GetShowSource(void);
	virtual Toolsapi::_di_IOTAFile __fastcall NewFormFile(const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent);
	virtual Toolsapi::_di_IOTAFile __fastcall NewImplSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent);
	virtual Toolsapi::_di_IOTAFile __fastcall NewIntfSource(const System::UnicodeString ModuleIdent, const System::UnicodeString FormIdent, const System::UnicodeString AncestorIdent);
	virtual void __fastcall FormCreated(const Toolsapi::_di_IOTAFormEditor FormEditor);
	
public:
	__fastcall TdxOTAFormCreator(const System::UnicodeString AFormTemplate, const System::UnicodeString AImplTemplate, const System::UnicodeString AIntfTemplate);
	__property System::UnicodeString FormTemplate = {read=FFormTemplate};
	__property System::UnicodeString ImplTemplate = {read=FImplTemplate};
	__property System::UnicodeString IntfTemplate = {read=FIntfTemplate};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTAFormCreator(void) { }
	
private:
	void *__IOTAModuleCreator;	/* Toolsapi::IOTAModuleCreator */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6EDB9B9A-F57A-11D1-AB23-00C04FB16FB3}
	operator Toolsapi::_di_IOTAModuleCreator()
	{
		Toolsapi::_di_IOTAModuleCreator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAModuleCreator*(void) { return (Toolsapi::IOTAModuleCreator*)&__IOTAModuleCreator; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxOTACustomProjectCreator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOTACustomProjectCreator : public TdxOTACustomCreator
{
	typedef TdxOTACustomCreator inherited;
	
protected:
	virtual Toolsapi::_di_IOTAModule __fastcall GetOwner(void);
	virtual System::UnicodeString __fastcall GetFileName(void);
	System::UnicodeString __fastcall GetOptionFileName(void);
	virtual bool __fastcall GetShowSource(void);
	Toolsapi::_di_IOTAFile __fastcall NewOptionSource(const System::UnicodeString ProjectName);
	virtual Toolsapi::_di_IOTAFile __fastcall NewProjectSource(const System::UnicodeString ProjectName);
	void __fastcall NewDefaultModule(void);
	virtual void __fastcall NewProjectResource(const Toolsapi::_di_IOTAProject Project);
	virtual void __fastcall NewDefaultProjectModule(const Toolsapi::_di_IOTAProject Project);
	System::UnicodeString __fastcall GetProjectPersonality(void);
	System::UnicodeString __fastcall GetFrameworkType(void);
	System::DynamicArray<System::UnicodeString> __fastcall GetPlatforms(void);
	System::UnicodeString __fastcall GetPreferredPlatform(void);
	void __fastcall SetInitialOptions(const Toolsapi::_di_IOTAProject NewProject);
	virtual TdxOTAPersonality __fastcall GetPersonality(void) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxOTACustomProjectCreator(void) : TdxOTACustomCreator() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOTACustomProjectCreator(void) { }
	
private:
	void *__IOTAProjectCreator160;	/* Toolsapi::IOTAProjectCreator160 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6EDB9B9D-F57A-11D1-AB23-00C04FB16FB3}
	operator Toolsapi::_di_IOTAProjectCreator()
	{
		Toolsapi::_di_IOTAProjectCreator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAProjectCreator*(void) { return (Toolsapi::IOTAProjectCreator*)&__IOTAProjectCreator160; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4334DF37-C1B6-4135-A665-762DC2DA4086}
	operator Toolsapi::_di_IOTAProjectCreator160()
	{
		Toolsapi::_di_IOTAProjectCreator160 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAProjectCreator160*(void) { return (Toolsapi::IOTAProjectCreator160*)&__IOTAProjectCreator160; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9A1D6AF5-84FA-481C-A446-746D9A50F53E}
	operator Toolsapi::_di_IOTAProjectCreator80()
	{
		Toolsapi::_di_IOTAProjectCreator80 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAProjectCreator80*(void) { return (Toolsapi::IOTAProjectCreator80*)&__IOTAProjectCreator160; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {64312F82-62F3-48E9-BAF6-B03DF450312A}
	operator Toolsapi::_di_IOTAProjectCreator50()
	{
		Toolsapi::_di_IOTAProjectCreator50 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Toolsapi::IOTAProjectCreator50*(void) { return (Toolsapi::IOTAProjectCreator50*)&__IOTAProjectCreator160; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Toolsapi::_di_IOTAProject __fastcall dxGetActiveProject(void);
extern PACKAGE System::UnicodeString __fastcall dxGetActiveProjectFileName(void);
extern PACKAGE void __fastcall dxRegisterPackageWizard(TdxOTACustomRepositoryWizard* AWizard);
}	/* namespace Dxdesignhelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDESIGNHELPERS)
using namespace Dxdesignhelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdesignhelpersHPP
