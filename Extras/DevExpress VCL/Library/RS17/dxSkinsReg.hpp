// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsReg.pas' rev: 24.00 (Win32)

#ifndef DxskinsregHPP
#define DxskinsregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <cxLibraryReg.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <dxSkinsDefaultPainters.hpp>	// Pascal unit
#include <dxSkinsForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsreg
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (*TdxSkinListFilterProc)(const System::UnicodeString ASkinName);

typedef void __fastcall (*TdxSkinModifyProjectOptionsProc)(void);

class DELPHICLASS TdxSkinNameProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinNameProperty : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxSkinNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxSkinNameProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxSkinsProductName L"ExpressSkins"
extern PACKAGE TdxSkinListFilterProc dxSkinListFilterProc;
extern PACKAGE TdxSkinModifyProjectOptionsProc dxSkinModifyProjectOptionsProc;
extern PACKAGE bool __fastcall dxSkinListCanUseSkin(const System::UnicodeString ASkinName);
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxskinsreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSREG)
using namespace Dxskinsreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsregHPP
