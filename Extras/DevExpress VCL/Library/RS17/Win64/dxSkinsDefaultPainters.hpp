// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsDefaultPainters.pas' rev: 24.00 (Win64)

#ifndef DxskinsdefaultpaintersHPP
#define DxskinsdefaultpaintersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <dxSkinsStrs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdefaultpainters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinsUserSkinPainter;
class PASCALIMPLEMENTATION TdxSkinsUserSkinPainter : public Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter
{
	typedef Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter inherited;
	
protected:
	virtual Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfoClass __fastcall GetSkinInfoClass(void);
	
public:
	virtual bool __fastcall IsInternalPainter(void);
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
public:
	/* TdxSkinLookAndFeelPainter.Create */ inline __fastcall virtual TdxSkinsUserSkinPainter(const System::UnicodeString ASkinResName, NativeUInt ASkinResInstance) : Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter(ASkinResName, ASkinResInstance) { }
	/* TdxSkinLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TdxSkinsUserSkinPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define sdxDefaultUserSkinData L"DefaultUserSkinData"
#define sdxSkinsUserSkinName L"UserSkin"
extern PACKAGE void __fastcall dxSkinsPopulateSkinResources(NativeUInt AModule, System::Classes::TStringList* AResNames, System::Classes::TStringList* ASkinNames);
extern PACKAGE bool __fastcall dxSkinsLoadedUserSkinHasMissingElements(void);
extern PACKAGE System::UnicodeString __fastcall dxSkinsUserSkinGetLoadedSkinName(bool ADisplayName = false);
extern PACKAGE bool __fastcall dxSkinsUserSkinLoadFromFile(const System::UnicodeString AFileName, const System::UnicodeString ASkinName = System::UnicodeString());
extern PACKAGE bool __fastcall dxSkinsUserSkinLoadFromFileByIndex(const System::UnicodeString AFileName, int ASkinIndex = 0x0);
extern PACKAGE bool __fastcall dxSkinsUserSkinLoadFromResource(NativeUInt AInstance, const System::UnicodeString AResourceName, const System::UnicodeString ASkinName = System::UnicodeString());
extern PACKAGE bool __fastcall dxSkinsUserSkinLoadFromStream(System::Classes::TStream* AStream, const System::UnicodeString ASkinName = System::UnicodeString());
extern PACKAGE bool __fastcall dxSkinsUserSkinLoadFromStreamByIndex(System::Classes::TStream* AStream, int ASkinIndex = 0x0);
extern PACKAGE bool __fastcall dxSkinsUserSkinPopulateSkinNames(System::Classes::TStream* AStream, System::Classes::TStrings* AList, bool ADisplayNames = false)/* overload */;
extern PACKAGE bool __fastcall dxSkinsUserSkinPopulateSkinNames(const System::UnicodeString AFileName, System::Classes::TStrings* AList, bool ADisplayNames = false)/* overload */;
}	/* namespace Dxskinsdefaultpainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDEFAULTPAINTERS)
using namespace Dxskinsdefaultpainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdefaultpaintersHPP
