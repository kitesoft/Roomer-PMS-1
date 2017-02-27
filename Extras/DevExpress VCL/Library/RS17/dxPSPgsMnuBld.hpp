// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPgsMnuBld.pas' rev: 24.00 (Win32)

#ifndef DxpspgsmnubldHPP
#define DxpspgsmnubldHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspgsmnubld
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxPSPageSetupMenuBuilderClass;

class DELPHICLASS TAbstractdxPSPageSetupMenuBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TAbstractdxPSPageSetupMenuBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TAbstractdxPSPageSetupMenuBuilder(void);
	virtual void __fastcall BuildPageSetupMenu(System::TObject* ARootItem, void * AData, bool AIncludeDefineItem, System::Classes::TStringList* AStyles, Dxpgsdlg::TBasedxPrintStyle* ACurrentStyle, System::Classes::TNotifyEvent AOnStyleClick, System::Classes::TNotifyEvent AOnDefineStylesClick) = 0 ;
	__classmethod virtual Dxpgsdlg::TBasedxPrintStyle* __fastcall ExtractPrintStyleFromObj(System::TObject* Obj);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractdxPSPageSetupMenuBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxStandardPSPageSetupMenuBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStandardPSPageSetupMenuBuilder : public TAbstractdxPSPageSetupMenuBuilder
{
	typedef TAbstractdxPSPageSetupMenuBuilder inherited;
	
public:
	virtual void __fastcall BuildPageSetupMenu(System::TObject* ARootItem, void * AData, bool AIncludeDefineItem, System::Classes::TStringList* AStyles, Dxpgsdlg::TBasedxPrintStyle* ACurrentStyle, System::Classes::TNotifyEvent AOnStyleClick, System::Classes::TNotifyEvent AOnDefineStylesClick);
	__classmethod virtual Dxpgsdlg::TBasedxPrintStyle* __fastcall ExtractPrintStyleFromObj(System::TObject* Obj);
public:
	/* TAbstractdxPSPageSetupMenuBuilder.Create */ inline __fastcall virtual TdxStandardPSPageSetupMenuBuilder(void) : TAbstractdxPSPageSetupMenuBuilder() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStandardPSPageSetupMenuBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPageSetupMenuBuilderFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPageSetupMenuBuilderFactory : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	Dxbase::TdxClassList* FBuilders;
	TdxPSPageSetupMenuBuilderClass __fastcall GetActiveBuilder(void);
	TdxPSPageSetupMenuBuilderClass __fastcall GetBuilder(int Index);
	int __fastcall GetCount(void);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	
public:
	__classmethod TdxPSPageSetupMenuBuilderFactory* __fastcall Instance()/* overload */;
	void __fastcall RegisterBuilder(TdxPSPageSetupMenuBuilderClass ABuilder);
	void __fastcall UnregisterBuilder(TdxPSPageSetupMenuBuilderClass ABuilder);
	__property TdxPSPageSetupMenuBuilderClass ActiveBuilder = {read=GetActiveBuilder};
	__property TdxPSPageSetupMenuBuilderClass Builders[int Index] = {read=GetBuilder};
	__property int Count = {read=GetCount, nodefault};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSPageSetupMenuBuilderFactory(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSPageSetupMenuBuilderFactory(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSPageSetupMenuBuilderFactory(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSPageSetupMenuBuilderFactory* __fastcall dxPSPageSetupMenuBuilderFactory(void);
}	/* namespace Dxpspgsmnubld */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPGSMNUBLD)
using namespace Dxpspgsmnubld;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspgsmnubldHPP
