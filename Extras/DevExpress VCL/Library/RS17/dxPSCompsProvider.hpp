// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSCompsProvider.pas' rev: 24.00 (Win32)

#ifndef DxpscompsproviderHPP
#define DxpscompsproviderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscompsprovider
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxComponentItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxComponentItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FCaption;
	System::Classes::TComponent* FComponent;
	System::UnicodeString FDescription;
	
public:
	__fastcall TdxComponentItem(System::Classes::TComponent* AComponent, const System::UnicodeString ACaption, const System::UnicodeString ADescription);
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property System::Classes::TComponent* Component = {read=FComponent, write=FComponent};
	__property System::UnicodeString Description = {read=FDescription, write=FDescription};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxComponentItem(void) { }
	
};

#pragma pack(pop)

enum TdxPSGetComponentOption : unsigned char { gcoExcludeExisting, gcoExcludeOutOfActiveForm, gcoHideCustomContainers };

typedef System::Set<TdxPSGetComponentOption, TdxPSGetComponentOption::gcoExcludeExisting, TdxPSGetComponentOption::gcoHideCustomContainers>  TdxPSGetComponentOptions;

typedef System::TMetaClass* TdxPSComponentsProviderClass;

class DELPHICLASS TAbstractdxPSComponentsProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TAbstractdxPSComponentsProvider : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TAbstractdxPSComponentsProvider(void);
	virtual void __fastcall GetComponents(Dxpscore::TdxComponentPrinter* AComponentPrinter, Dxpscore::TBasedxReportLink* AReportLink, System::Classes::TStrings* AComponents, TdxPSGetComponentOptions AnOptions) = 0 ;
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractdxPSComponentsProvider(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSComponentProvidersFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSComponentProvidersFactory : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
public:
	TAbstractdxPSComponentsProvider* operator[](int Index) { return Providers[Index]; }
	
private:
	System::Classes::TList* FItems;
	TAbstractdxPSComponentsProvider* __fastcall GetActiveProvider(void);
	int __fastcall GetCount(void);
	TAbstractdxPSComponentsProvider* __fastcall GetProvider(int Index);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	
public:
	__classmethod TdxPSComponentProvidersFactory* __fastcall Instance()/* overload */;
	void __fastcall GetComponents(Dxpscore::TdxComponentPrinter* AComponentPrinter, Dxpscore::TBasedxReportLink* AReportLink, System::Classes::TStrings* AComponents, TdxPSGetComponentOptions AnOptions);
	HIDESBASE int __fastcall IndexOf(TdxPSComponentsProviderClass AProviderClass);
	void __fastcall RegisterProvider(TdxPSComponentsProviderClass AProviderClass);
	void __fastcall UnregisterProvider(TdxPSComponentsProviderClass AProviderClass);
	__property TAbstractdxPSComponentsProvider* ActiveProvider = {read=GetActiveProvider};
	__property int Count = {read=GetCount, nodefault};
	__property TAbstractdxPSComponentsProvider* Providers[int Index] = {read=GetProvider/*, default*/};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSComponentProvidersFactory(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSComponentProvidersFactory(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSComponentProvidersFactory(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxComponentItem* __fastcall dxPSCreateComponentItem(System::Classes::TComponent* AComponent, const System::UnicodeString ACaption, const System::UnicodeString ADescription);
extern PACKAGE TdxPSComponentProvidersFactory* __fastcall dxPSComponentProvidersFactory(void);
}	/* namespace Dxpscompsprovider */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCOMPSPROVIDER)
using namespace Dxpscompsprovider;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscompsproviderHPP
