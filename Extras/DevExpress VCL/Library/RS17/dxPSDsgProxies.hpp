// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSDsgProxies.pas' rev: 24.00 (Win32)

#ifndef DxpsdsgproxiesHPP
#define DxpsdsgproxiesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdsgproxies
{
//-- type declarations -------------------------------------------------------
typedef Designintf::_di_IDesigner TFormDesigner;

typedef System::Classes::TPersistent IPersistent;

typedef System::Classes::TComponent IComponent;

typedef Designintf::_di_IDesignerSelections TdxDesignSelectionList;

typedef Componentdesigner::_di_IDesignEnvironment TdxDesignEnvironment;

class DELPHICLASS TdxIdeComponentImageItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxIdeComponentImageItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TComponentClass FComponentClass;
	int FImageIndex;
	
public:
	__fastcall TdxIdeComponentImageItem(int AImageIndex, System::Classes::TComponentClass AComponentClass);
	__property System::Classes::TComponentClass ComponentClass = {read=FComponentClass};
	__property int ImageIndex = {read=FImageIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxIdeComponentImageItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxIdeImagesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxIdeImagesProvider : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
public:
	int operator[](System::Classes::TComponentClass ComponentClass) { return ImageIndexes[ComponentClass]; }
	
private:
	Vcl::Imglist::TCustomImageList* FImages;
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	int __fastcall GetImageIndex(System::Classes::TComponentClass ComponentClass);
	int __fastcall GetImageIndexByComponentClassName(const System::UnicodeString ClassName);
	int __fastcall GetImageIndexByObject(System::Classes::TPersistent* AnObject);
	TdxIdeComponentImageItem* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	void __fastcall Add(int AImageIndex, System::Classes::TComponentClass AComponentClass);
	void __fastcall ClearItems(void);
	int __fastcall ImageIndexByComponentClass(System::Classes::TComponentClass AComponentClass);
	__property TdxIdeComponentImageItem* Items[int Index] = {read=GetItem};
	
public:
	__classmethod TdxIdeImagesProvider* __fastcall Instance()/* overload */;
	void __fastcall Refresh(void);
	__property int Count = {read=GetCount, nodefault};
	__property int ImageIndexes[System::Classes::TComponentClass ComponentClass] = {read=GetImageIndex/*, default*/};
	__property int ImageIndexesByComponentClassName[const System::UnicodeString ClassName] = {read=GetImageIndexByComponentClassName};
	__property int ImageIndexesByObject[System::Classes::TPersistent* AnObject] = {read=GetImageIndexByObject};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxIdeImagesProvider(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxIdeImagesProvider(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxIdeImagesProvider(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 NodeUncheckedStateIndex = System::Int8(0x0);
static const System::Int8 NodeCheckedStateIndex = System::Int8(0x1);
static const System::Int8 NodeParticallyCheckedStateIndex = System::Int8(0x2);
extern PACKAGE Componentdesigner::_di_IDesignEnvironment __fastcall IdeEnvironment(void);
extern PACKAGE Designintf::_di_IDesignerSelections __fastcall CreateDesignSelectionList(void);
extern PACKAGE void __fastcall FreeDesignSelectionList(const Designintf::_di_IDesignerSelections ASelections);
extern PACKAGE void __fastcall RestoreDesignSelection(const Designintf::_di_IDesigner ADesigner, Designintf::_di_IDesignerSelections &AList);
extern PACKAGE void __fastcall SaveDesignSelection(const Designintf::_di_IDesigner ADesigner, /* out */ Designintf::_di_IDesignerSelections &AList);
extern PACKAGE System::UnicodeString __fastcall GetBaseRegistryKey(void);
extern PACKAGE TdxIdeImagesProvider* __fastcall dxIdeImagesProvider(void);
}	/* namespace Dxpsdsgproxies */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDSGPROXIES)
using namespace Dxpsdsgproxies;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdsgproxiesHPP
