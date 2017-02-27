// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarViewsFact.pas' rev: 24.00 (Win64)

#ifndef DxnavbarviewsfactHPP
#define DxnavbarviewsfactHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarviewsfact
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarViewsFactory;
class PASCALIMPLEMENTATION TdxNavBarViewsFactory : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Contnrs::TObjectList* FViews;
	int __fastcall GetCount(void);
	int __fastcall GetIDs(int AIndex);
	System::UnicodeString __fastcall GetNames(int AIndex);
	Dxnavbar::TdxNavBarPainterClass __fastcall GetPainterClasses(int AIndex);
	bool __fastcall IsIndexValid(int AIndex);
	
protected:
	void __fastcall Clear(void);
	
public:
	__fastcall TdxNavBarViewsFactory(void);
	__fastcall virtual ~TdxNavBarViewsFactory(void);
	void __fastcall RegisterView(int AID, System::UnicodeString AName, Dxnavbar::TdxNavBarPainterClass APainterClass);
	void __fastcall UnRegisterView(int AID);
	int __fastcall GetIDFromName(const System::UnicodeString Name);
	int __fastcall IndexOfName(const System::UnicodeString Name);
	int __fastcall IndexOfID(const int AID);
	bool __fastcall IsViewRegistered(int AID);
	__property int Count = {read=GetCount, nodefault};
	__property int IDs[int AIndex] = {read=GetIDs};
	__property System::UnicodeString Names[int AIndex] = {read=GetNames};
	__property Dxnavbar::TdxNavBarPainterClass PainterClasses[int AIndex] = {read=GetPainterClasses};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxNavBarViewsFactory* __fastcall dxNavBarViewsFactory(void);
extern PACKAGE void __fastcall RegisterView(int AID, System::UnicodeString AName, Dxnavbar::TdxNavBarPainterClass APainterClass);
extern PACKAGE void __fastcall UnRegisterView(int AID);
}	/* namespace Dxnavbarviewsfact */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARVIEWSFACT)
using namespace Dxnavbarviewsfact;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarviewsfactHPP
