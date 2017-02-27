// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsDesignHelperReg.pas' rev: 24.00 (Win32)

#ifndef DxskinsdesignhelperregHPP
#define DxskinsdesignhelperregHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <dxSkinsStrs.hpp>	// Pascal unit
#include <dxSkinsForm.hpp>	// Pascal unit
#include <ToolsAPI.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdesignhelperreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinsBaseSelectionEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsBaseSelectionEditor : public Designeditors::TSelectionEditor
{
	typedef Designeditors::TSelectionEditor inherited;
	
public:
	virtual void __fastcall RequiresProductsUnits(System::Classes::TGetStrProc Proc);
	virtual void __fastcall RequiresUnits(System::Classes::TGetStrProc Proc);
public:
	/* TSelectionEditor.Create */ inline __fastcall virtual TdxSkinsBaseSelectionEditor(const Designintf::_di_IDesigner ADesigner) : Designeditors::TSelectionEditor(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinsBaseSelectionEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSkinsAdditionalUnits;
class PASCALIMPLEMENTATION TdxSkinsAdditionalUnits : public System::Classes::TStringList
{
	typedef System::Classes::TStringList inherited;
	
private:
	System::TClass FControlClass;
	
public:
	__fastcall virtual TdxSkinsAdditionalUnits(System::TClass AControlClass);
	void __fastcall RemoveUnit(const System::UnicodeString AName);
	__property System::TClass ControlClass = {read=FControlClass};
public:
	/* TStringList.Destroy */ inline __fastcall virtual ~TdxSkinsAdditionalUnits(void) { }
	
};


class DELPHICLASS TdxSkinsAdditionalUnitsList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinsAdditionalUnitsList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxSkinsAdditionalUnits* operator[](int Index) { return Items[Index]; }
	
private:
	Cxclasses::TcxObjectList* FItems;
	int __fastcall GetCount(void);
	TdxSkinsAdditionalUnits* __fastcall GetItem(int Index);
	
protected:
	bool __fastcall Find(System::TClass AControlClass, /* out */ TdxSkinsAdditionalUnits* &AItem);
	
public:
	__fastcall virtual TdxSkinsAdditionalUnitsList(void);
	__fastcall virtual ~TdxSkinsAdditionalUnitsList(void);
	void __fastcall Add(System::TClass AControlClass, const System::UnicodeString ASkinUnitName);
	void __fastcall Remove(System::TClass AControlClass, const System::UnicodeString ASkinUnitName);
	void __fastcall RequiresUnits(System::TClass AControlClass, System::Classes::TGetStrProc AProc);
	__property int Count = {read=GetCount, nodefault};
	__property TdxSkinsAdditionalUnits* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxSkinsAdditionalUnitsList* __fastcall dxSkinsAdditionalUnits(void);
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxskinsdesignhelperreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDESIGNHELPERREG)
using namespace Dxskinsdesignhelperreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdesignhelperregHPP
