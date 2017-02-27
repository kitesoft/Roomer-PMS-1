// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerDialogs.pas' rev: 24.00 (Win64)

#ifndef CxschedulerdialogsHPP
#define CxschedulerdialogsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxSchedulerEventEditor.hpp>	// Pascal unit
#include <cxSchedulerRecurrenceEditor.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerRecurrenceSelectionDialog.hpp>	// Pascal unit
#include <cxSchedulerReminderWindow.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit
#include <cxSchedulerHolidaysEditor.hpp>	// Pascal unit
#include <cxSchedulerHolidaysLocationHolidayEditor.hpp>	// Pascal unit
#include <cxSchedulerHolidaysLocationEditor.hpp>	// Pascal unit
#include <cxSchedulerTaskDependencyEditor.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerdialogs
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxschedulereventeditor::TcxSchedulerEventEditorClass cxEventEditorClass;
extern PACKAGE Cxschedulerrecurrenceeditor::TcxSchedulerRecurrenceEventEditorClass cxRecurrenceEventEditorClass;
extern PACKAGE Cxschedulerstorage::TcxSchedulerReminderFormClass cxReminderFormClass;
extern PACKAGE Cxschedulerholidayseditor::TcxSchedulerHolidaysEditorClass cxHolidayEditorClass;
extern PACKAGE Cxschedulertaskdependencyeditor::TcxSchedulerTaskDependencyEditorClass cxTaskDependencyEditorClass;
extern PACKAGE bool UseSchedulerColorInDialogs;
extern PACKAGE int __fastcall cxGetLabelGrowDelta(Cxlabel::TcxLabel* ALabel);
extern PACKAGE void __fastcall cxPopulateItemsWithTimeIntervals(System::Classes::TStrings* AItems);
extern PACKAGE void __fastcall cxComboBoxPopulateWithTimeIntervals(Cxdropdownedit::TcxComboBox* ACombo);
extern PACKAGE void __fastcall cxComboBoxSetNearestTimeInterval(Cxdropdownedit::TcxComboBox* ACombo, int AMinutes);
extern PACKAGE void __fastcall cxComboBoxCaretToEnd(Cxdropdownedit::TcxComboBox* AComboBox);
extern PACKAGE bool __fastcall cxShowEventEditorEx(Cxschedulercustomcontrols::TcxSchedulerEventEditInfo* AEventInfo, bool &AModified);
extern PACKAGE bool __fastcall cxShowEventEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, bool ARecurrence, bool &AModified, bool AReadOnly = false, bool AllowDelete = true, bool ARecurrenceButton = true, Cxschedulercustomcontrols::TcxOnDeleteEventFunc AOnDeleteFunc = 0x0, bool AForcePatternEditing = false, System::TDateTime ABiasTime = 0.000000E+00, bool AShowResources = false);
extern PACKAGE bool __fastcall cxShowRecurrenceEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, /* out */ bool &AModified, bool AReadOnly = false, bool AConfirmLossOfExceptions = true, bool AIsInternalActivation = false);
extern PACKAGE void __fastcall cxShowResourcesLayoutEditor(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
extern PACKAGE bool __fastcall cxShowRecurrenceSelectionDialog(Cxschedulerstorage::TcxSchedulerEvent* AEvent, Cxschedulerrecurrenceselectiondialog::TcxRecurrenceSelectionMode AMode, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, /* out */ bool &AOccurrence);
extern PACKAGE bool __fastcall cxShowGoToDateDialog(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::TDateTime &ADate, /* out */ Cxschedulercustomcontrols::TcxSchedulerViewMode &AViewMode);
extern PACKAGE bool __fastcall cxShowHolidaysEditor(Cxschedulerholidays::TcxSchedulerHolidays* &AHolidays, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
extern PACKAGE bool __fastcall cxShowHolidaysLocationHolidayEditor(Cxschedulerholidays::TcxSchedulerHolidaysLocationHoliday* &ALocationHoliday, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
extern PACKAGE bool __fastcall cxShowHolidaysLocationEditor(Cxschedulerholidays::TcxSchedulerHolidaysLocation* &ALocation, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
extern PACKAGE void __fastcall cxShowTaskDependencyEditor(Cxschedulerstorage::TcxSchedulerEventItemLink* AItemLink, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
}	/* namespace Cxschedulerdialogs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERDIALOGS)
using namespace Cxschedulerdialogs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerdialogsHPP
