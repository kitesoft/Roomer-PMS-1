// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSAutoHFTextMnuBld.pas' rev: 24.00 (Win32)

#ifndef DxpsautohftextmnubldHPP
#define DxpsautohftextmnubldHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsautohftextmnubld
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAbstractdxPSAutoHFTextMenuBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TAbstractdxPSAutoHFTextMenuBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TAbstractdxPSAutoHFTextMenuBuilder(void);
	virtual void __fastcall BuildAutoHFTextEntriesMenu(System::TObject* ARootItem, void * AData, bool AIncludeSetupAutoHFTextEntriesItem, System::Classes::TStrings* AAutoHFTextEntries, System::Classes::TNotifyEvent AOnHFTextEntriesClick, System::Classes::TNotifyEvent AOnSetupHFTextEntriesClick) = 0 ;
	__classmethod virtual int __fastcall ExtractAutoHFTextEntryIndexFromObj(System::TObject* Obj);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractdxPSAutoHFTextMenuBuilder(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSAutoHFTextMenuBuilderClass;

class DELPHICLASS TdxStandardPSAutoHFTextMenuBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStandardPSAutoHFTextMenuBuilder : public TAbstractdxPSAutoHFTextMenuBuilder
{
	typedef TAbstractdxPSAutoHFTextMenuBuilder inherited;
	
public:
	virtual void __fastcall BuildAutoHFTextEntriesMenu(System::TObject* ARootItem, void * AData, bool AIncludeSetupAutoHFTextEntriesItem, System::Classes::TStrings* AAutoHFTextEntries, System::Classes::TNotifyEvent AOnHFTextEntriesClick, System::Classes::TNotifyEvent AOnSetupHFTextEntriesClick);
	__classmethod virtual int __fastcall ExtractAutoHFTextEntryIndexFromObj(System::TObject* Obj);
public:
	/* TAbstractdxPSAutoHFTextMenuBuilder.Create */ inline __fastcall virtual TdxStandardPSAutoHFTextMenuBuilder(void) : TAbstractdxPSAutoHFTextMenuBuilder() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStandardPSAutoHFTextMenuBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSAutoHFTextMenuBuilderFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSAutoHFTextMenuBuilderFactory : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	Dxbase::TdxClassList* FBuilders;
	TdxPSAutoHFTextMenuBuilderClass __fastcall GetActiveBuilder(void);
	TdxPSAutoHFTextMenuBuilderClass __fastcall GetBuilder(int Index);
	int __fastcall GetCount(void);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	
public:
	__classmethod TdxPSAutoHFTextMenuBuilderFactory* __fastcall Instance()/* overload */;
	void __fastcall RegisterBuilder(TdxPSAutoHFTextMenuBuilderClass ABuilder);
	void __fastcall UnregisterBuilder(TdxPSAutoHFTextMenuBuilderClass ABuilder);
	__property TdxPSAutoHFTextMenuBuilderClass ActiveBuilder = {read=GetActiveBuilder};
	__property TdxPSAutoHFTextMenuBuilderClass Builders[int Index] = {read=GetBuilder};
	__property int Count = {read=GetCount, nodefault};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSAutoHFTextMenuBuilderFactory(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSAutoHFTextMenuBuilderFactory(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSAutoHFTextMenuBuilderFactory(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSAutoHFTextMenuBuilderFactory* __fastcall dxPSAutoHFTextMenuBuilderFactory(void);
}	/* namespace Dxpsautohftextmnubld */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSAUTOHFTEXTMNUBLD)
using namespace Dxpsautohftextmnubld;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsautohftextmnubldHPP
