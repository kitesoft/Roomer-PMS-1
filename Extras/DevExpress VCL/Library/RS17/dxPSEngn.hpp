// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSEngn.pas' rev: 24.00 (Win32)

#ifndef DxpsengnHPP
#define DxpsengnHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxPSESys.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsengn
{
//-- type declarations -------------------------------------------------------
enum TdxPSStorageType : unsigned char { dxstNone, dxstRegistry, dxstIniFile };

class DELPHICLASS TdxPSOptionsStoring;
class PASCALIMPLEMENTATION TdxPSOptionsStoring : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FIniFileName;
	System::Classes::TNotifyEvent FOnChanged;
	System::UnicodeString FRegistryPath;
	bool FSaveFormsPosition;
	TdxPSStorageType FStorageType;
	void __fastcall SetIniFileName(const System::UnicodeString AValue);
	void __fastcall SetRegistryPath(const System::UnicodeString AValue);
	void __fastcall SetSaveFormsPosition(bool AValue);
	void __fastcall SetStorageType(TdxPSStorageType AValue);
	
protected:
	bool __fastcall CanStoreToIniFile(void);
	bool __fastcall CanStoreToRegistry(void);
	virtual void __fastcall Changed(void);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TdxPSOptionsStoring(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString IniFileName = {read=FIniFileName, write=SetIniFileName};
	__property System::UnicodeString RegistryPath = {read=FRegistryPath, write=SetRegistryPath};
	__property bool SaveFormsPosition = {read=FSaveFormsPosition, write=SetSaveFormsPosition, default=1};
	__property TdxPSStorageType StorageType = {read=FStorageType, write=SetStorageType, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSOptionsStoring(void) { }
	
};


class DELPHICLASS TdxPSEngine;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSEngine : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	System::UnicodeString FDesignTimeRegistryPath;
	Cxlookandfeels::TcxLookAndFeel* FDialogsLookAndFeel;
	System::UnicodeString FHelpFile;
	System::UnicodeString __fastcall GetAppName(void);
	bool __fastcall GetIsNativeStyle(void);
	bool __fastcall GetIsSkinsStyle(void);
	bool __fastcall GetIsStandardStyle(void);
	Dxpsglbl::TdxPSPreviewDialogStyle __fastcall GetPreviewDialogStyle(void);
	System::UnicodeString __fastcall GetRealRegistryPath(void);
	System::UnicodeString __fastcall GetRegistryPath(void);
	bool __fastcall GetSaveFormsPosition(void);
	bool __fastcall GetThemesEnabled(void);
	void __fastcall SetDialogsLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetPreviewDialogStyle(const Dxpsglbl::TdxPSPreviewDialogStyle AValue);
	void __fastcall SetRegistryPath(const System::UnicodeString AValue);
	void __fastcall SetSaveFormsPosition(bool AValue);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	
public:
	__classmethod TdxPSEngine* __fastcall Instance()/* overload */;
	__property System::UnicodeString AppName = {read=GetAppName};
	__property System::UnicodeString DesignTimeRegistryPath = {read=FDesignTimeRegistryPath};
	__property Cxlookandfeels::TcxLookAndFeel* DialogsLookAndFeel = {read=FDialogsLookAndFeel, write=SetDialogsLookAndFeel};
	__property System::UnicodeString HelpFile = {read=FHelpFile, write=FHelpFile};
	__property bool IsNativeStyle = {read=GetIsNativeStyle, nodefault};
	__property bool IsSkinsStyle = {read=GetIsSkinsStyle, nodefault};
	__property bool IsStandardStyle = {read=GetIsStandardStyle, nodefault};
	__property Dxpsglbl::TdxPSPreviewDialogStyle PreviewDialogStyle = {read=GetPreviewDialogStyle, write=SetPreviewDialogStyle};
	__property System::UnicodeString RealRegistryPath = {read=GetRealRegistryPath};
	__property System::UnicodeString RegistryPath = {read=GetRegistryPath, write=SetRegistryPath};
	__property bool SaveFormsPosition = {read=GetSaveFormsPosition, write=SetSaveFormsPosition, nodefault};
	__property bool ThemesEnabled = {read=GetThemesEnabled, nodefault};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSEngine(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSEngine(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSEngine(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSEngineController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSEngineController : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	Cxlookandfeels::TcxLookAndFeel* FDialogsLookAndFeel;
	System::UnicodeString FHelpFile;
	TdxPSOptionsStoring* FOptionsStoring;
	Dxpsglbl::TdxPSPreviewDialogStyle FPreviewDialogStyle;
	bool __fastcall GetActive(void);
	Dxpsglbl::TdxPSPreviewDialogStyle __fastcall GetPreviewDialogStyle(void);
	bool __fastcall IsDesigning(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetDialogsLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetHelpFile(const System::UnicodeString Value);
	void __fastcall SetOptionsStoring(TdxPSOptionsStoring* AValue);
	void __fastcall SetPreviewDialogStyle(const Dxpsglbl::TdxPSPreviewDialogStyle AValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall StoringOptionsChanged(System::TObject* Sender);
	void __fastcall UpdateEngineParams(void);
	void __fastcall ReadLookAndFeelProperty(System::Classes::TReader* Reader);
	void __fastcall ReadRegistryPath(System::Classes::TReader* Reader);
	void __fastcall ReadSaveFormsPosition(System::Classes::TReader* Reader);
	void __fastcall ReadUseNativeLookAndFeelProperty(System::Classes::TReader* Reader);
	
public:
	__fastcall virtual TdxPSEngineController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSEngineController(void);
	void __fastcall Activate(void);
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property Cxlookandfeels::TcxLookAndFeel* DialogsLookAndFeel = {read=FDialogsLookAndFeel, write=SetDialogsLookAndFeel};
	__property System::UnicodeString HelpFile = {read=FHelpFile, write=SetHelpFile};
	__property TdxPSOptionsStoring* OptionsStoring = {read=FOptionsStoring, write=SetOptionsStoring};
	__property Dxpsglbl::TdxPSPreviewDialogStyle PreviewDialogStyle = {read=GetPreviewDialogStyle, write=SetPreviewDialogStyle};
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
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
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSStoringManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSStoringManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Inifiles::TCustomIniFile* FIniFile;
	int FLockCount;
	TdxPSOptionsStoring* FOptionsStoring;
	void __fastcall SetOptionsStoring(TdxPSOptionsStoring* AValue);
	
protected:
	System::Inifiles::TCustomIniFile* __fastcall CreateIniFile(void);
	System::UnicodeString __fastcall GetRealIniFileName(void);
	
public:
	__fastcall virtual TdxPSStoringManager(void);
	__fastcall virtual ~TdxPSStoringManager(void);
	bool __fastcall BeginStoring(System::Inifiles::TCustomIniFile* &AIniFile);
	void __fastcall EndStoring(System::Inifiles::TCustomIniFile* &AIniFile);
	__property TdxPSOptionsStoring* OptionsStoring = {read=FOptionsStoring, write=SetOptionsStoring};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSStoringManager* __fastcall dxPSStoringManager(void);
extern PACKAGE TdxPSEngine* __fastcall dxPSEngine(void);
}	/* namespace Dxpsengn */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSENGN)
using namespace Dxpsengn;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsengnHPP
