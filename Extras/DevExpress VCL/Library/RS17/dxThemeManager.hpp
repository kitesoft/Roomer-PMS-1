// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxThemeManager.pas' rev: 24.00 (Win32)

#ifndef DxthememanagerHPP
#define DxthememanagerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxthememanager
{
//-- type declarations -------------------------------------------------------
enum TdxThemedObjectType : unsigned char { totButton, totClock, totComboBox, totEdit, totExplorerBar, totHeader, totListBox, totListView, totMenu, totPage, totProgress, totRebar, totScrollBar, totSpin, totStartPanel, totStatus, totTab, totTaskBand, totTaskBar, totToolBar, totToolTip, totTrackBar, totTrayNotify, totTreeview, totWindow, totNavigation };

typedef System::Set<TdxThemedObjectType, TdxThemedObjectType::totButton, TdxThemedObjectType::totNavigation>  TdxThemedObjectTypes;

typedef void __fastcall (__closure *TdxThemeChangedEvent)(void);

class DELPHICLASS TdxThemeChangedNotificator;
class PASCALIMPLEMENTATION TdxThemeChangedNotificator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxThemeChangedEvent FOnThemeChanged;
	
protected:
	virtual void __fastcall DoThemeChanged(void);
	
public:
	__fastcall TdxThemeChangedNotificator(void);
	__fastcall virtual ~TdxThemeChangedNotificator(void);
	__property TdxThemeChangedEvent OnThemeChanged = {read=FOnThemeChanged, write=FOnThemeChanged};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall AreVisualStylesAvailable(TdxThemedObjectType ANeededThemedObjectType)/* overload */;
extern PACKAGE bool __fastcall AreVisualStylesAvailable(TdxThemedObjectTypes ANeededThemedObjectTypes = TdxThemedObjectTypes() )/* overload */;
extern PACKAGE HRESULT __fastcall CloseTheme(TdxThemedObjectType AThemedObjectType);
extern PACKAGE void __fastcall CloseAllThemes(void);
extern PACKAGE bool __fastcall IsStandardTheme(void);
extern PACKAGE NativeUInt __fastcall OpenTheme(TdxThemedObjectType AThemedObjectType, System::WideChar * APClassNameList = (System::WideChar *)(0x0));
}	/* namespace Dxthememanager */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTHEMEMANAGER)
using namespace Dxthememanager;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxthememanagerHPP
