// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPopupMan.pas' rev: 24.00 (Win32)

#ifndef DxpspopupmanHPP
#define DxpspopupmanHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxHooks.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspopupman
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxPSPopupMenuBuilderClass;

class DELPHICLASS TAbstractdxPSPopupMenuBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TAbstractdxPSPopupMenuBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual System::Classes::TComponent* __fastcall BuildPopup(Vcl::Controls::TControl* const AControl, Vcl::Menus::TPopupMenu* const APopupMenu) = 0 ;
	__classmethod virtual bool __fastcall CanShowPopup(Vcl::Menus::TPopupMenu* const APopupMenu);
	virtual void __fastcall FreePopup(System::Classes::TComponent* &APopupMenu) = 0 ;
	virtual void __fastcall InvokePopup(int X, int Y, Vcl::Controls::TControl* AControl, System::Classes::TComponent* APopupMenu) = 0 ;
	__classmethod virtual bool __fastcall RequireProcessDoPopup();
	
public:
	__fastcall virtual TAbstractdxPSPopupMenuBuilder(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractdxPSPopupMenuBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxStandardPSPopupMenuBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStandardPSPopupMenuBuilder : public TAbstractdxPSPopupMenuBuilder
{
	typedef TAbstractdxPSPopupMenuBuilder inherited;
	
protected:
	virtual System::Classes::TComponent* __fastcall BuildPopup(Vcl::Controls::TControl* const AControl, Vcl::Menus::TPopupMenu* const APopupMenu);
	virtual void __fastcall FreePopup(System::Classes::TComponent* &APopupMenu);
	virtual void __fastcall InvokePopup(int X, int Y, Vcl::Controls::TControl* AControl, System::Classes::TComponent* APopupMenu);
public:
	/* TAbstractdxPSPopupMenuBuilder.Create */ inline __fastcall virtual TdxStandardPSPopupMenuBuilder(void) : TAbstractdxPSPopupMenuBuilder() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStandardPSPopupMenuBuilder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPopupMenuController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPopupMenuController : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	Dxbase::TdxClassList* FBuilders;
	System::Classes::TList* FControls;
	Dxcoreclasses::TcxFreeNotificator* FNexus;
	TdxPSPopupMenuBuilderClass __fastcall GetActiveBuilder(void);
	TdxPSPopupMenuBuilderClass __fastcall GetBuilder(int Index);
	int __fastcall GetBuilderCount(void);
	Vcl::Controls::TControl* __fastcall GetControl(int Index);
	int __fastcall GetControlCount(void);
	void __fastcall FreeAndNilControls(void);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	int __fastcall IndexOfControl(Vcl::Controls::TControl* AControl);
	bool __fastcall TryShowPopup(Vcl::Controls::TControl* AControl, const System::Types::TPoint &Pt);
	void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__classmethod TdxPSPopupMenuController* __fastcall Instance()/* overload */;
	void __fastcall ShowPopup(const int X, const int Y, Vcl::Controls::TControl* const AControl, Vcl::Menus::TPopupMenu* const APopupMenu);
	void __fastcall ShowPopupAtMousePos(Vcl::Controls::TControl* const AControl, Vcl::Menus::TPopupMenu* const APopupMenu);
	void __fastcall RegisterBuilder(TdxPSPopupMenuBuilderClass ABuilder);
	void __fastcall UnregisterBuilder(TdxPSPopupMenuBuilderClass ABuilder);
	void __fastcall RegisterControl(Vcl::Controls::TControl* AControl);
	void __fastcall UnregisterControl(Vcl::Controls::TControl* AControl);
	__property TdxPSPopupMenuBuilderClass ActiveBuilder = {read=GetActiveBuilder};
	__property int BuilderCount = {read=GetBuilderCount, nodefault};
	__property TdxPSPopupMenuBuilderClass Builders[int Index] = {read=GetBuilder};
	__property int ControlCount = {read=GetControlCount, nodefault};
	__property Vcl::Controls::TControl* Controls[int Index] = {read=GetControl};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxPSPopupMenuController(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxPSPopupMenuController(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxPSPopupMenuController(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxPSPopupMenuController* __fastcall dxPSPopupMenuController(void);
}	/* namespace Dxpspopupman */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPOPUPMAN)
using namespace Dxpspopupman;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspopupmanHPP
