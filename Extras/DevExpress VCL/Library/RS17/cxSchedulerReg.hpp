// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerReg.pas' rev: 24.00 (Win32)

#ifndef CxschedulerregHPP
#define CxschedulerregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxEditPropEditors.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerDBStorage.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxSchedulerDialogs.hpp>	// Pascal unit
#include <cxScheduler.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxSchedulerDateNavigator.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerWeekView.hpp>	// Pascal unit
#include <cxSchedulerYearView.hpp>	// Pascal unit
#include <cxSchedulerTimeGridView.hpp>	// Pascal unit
#include <cxDateNavigator.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit
#include <cxSchedulerAggregateStorage.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxExportSchedulerLink.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerSelectionEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSelectionEditor : public Designeditors::TSelectionEditor
{
	typedef Designeditors::TSelectionEditor inherited;
	
protected:
	System::Classes::TStringList* ComponentsList;
	
public:
	virtual void __fastcall RequiresUnits(System::Classes::TGetStrProc Proc);
public:
	/* TSelectionEditor.Create */ inline __fastcall virtual TcxSchedulerSelectionEditor(const Designintf::_di_IDesigner ADesigner) : Designeditors::TSelectionEditor(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerSelectionEditor(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Designintf::TComponentEditorClass __fastcall cxSchedulerComponentEditor(void);
extern PACKAGE void __fastcall Register(void);
}	/* namespace Cxschedulerreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERREG)
using namespace Cxschedulerreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerregHPP
