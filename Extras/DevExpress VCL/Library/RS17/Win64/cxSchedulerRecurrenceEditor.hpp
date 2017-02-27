// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerRecurrenceEditor.pas' rev: 24.00 (Win64)

#ifndef CxschedulerrecurrenceeditorHPP
#define CxschedulerrecurrenceeditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerEventEditor.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <dxBevel.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerrecurrenceeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerCustomRecurrenceEventEditor;
class PASCALIMPLEMENTATION TcxSchedulerCustomRecurrenceEventEditor : public Cxschedulereventeditor::TcxSchedulerCustomEditorForm
{
	typedef Cxschedulereventeditor::TcxSchedulerCustomEditorForm inherited;
	
private:
	bool FNeedCheckLossOfExceptions;
	void __fastcall SetNeedCheckLossOfExceptions(bool AValue);
	
protected:
	virtual void __fastcall SaveChanges(void);
	
public:
	__fastcall virtual TcxSchedulerCustomRecurrenceEventEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	__property bool NeedCheckLossOfExceptions = {read=FNeedCheckLossOfExceptions, write=SetNeedCheckLossOfExceptions, nodefault};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSchedulerCustomRecurrenceEventEditor(System::Classes::TComponent* AOwner) : Cxschedulereventeditor::TcxSchedulerCustomEditorForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerCustomRecurrenceEventEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxschedulereventeditor::TcxSchedulerCustomEditorForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomRecurrenceEventEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerCustomRecurrenceEventEditor(HWND ParentWindow) : Cxschedulereventeditor::TcxSchedulerCustomEditorForm(ParentWindow) { }
	
};


class DELPHICLASS TcxSchedulerRecurrenceEventEditorForm;
class PASCALIMPLEMENTATION TcxSchedulerRecurrenceEventEditorForm : public TcxSchedulerCustomRecurrenceEventEditor
{
	typedef TcxSchedulerCustomRecurrenceEventEditor inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* gbTime;
	Cxlabel::TcxLabel* lbStart;
	Cxlabel::TcxLabel* lbEnd;
	Cxtimeedit::TcxTimeEdit* teStart;
	Cxtimeedit::TcxTimeEdit* teEnd;
	Cxgroupbox::TcxGroupBox* gbPattern;
	Cxradiogroup::TcxRadioButton* rbDaily;
	Cxradiogroup::TcxRadioButton* rbWeekly;
	Cxradiogroup::TcxRadioButton* rbMonthly;
	Cxradiogroup::TcxRadioButton* rbYearly;
	Cxlabel::TcxLabel* lbOfEvery;
	Cxlabel::TcxLabel* lbMonths;
	Cxlabel::TcxLabel* lbOfEvery1;
	Cxlabel::TcxLabel* lbMonths1;
	Cxradiogroup::TcxRadioButton* rbDay;
	Cxradiogroup::TcxRadioButton* rbThe;
	Cxdropdownedit::TcxComboBox* cbWeek;
	Cxdropdownedit::TcxComboBox* cbDay;
	Cxlabel::TcxLabel* lbWeeksOn;
	Cxlabel::TcxLabel* lbRecurEvery;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek1;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek2;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek3;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek4;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek5;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek6;
	Cxcheckbox::TcxCheckBox* cbDayOfWeek7;
	Cxlabel::TcxLabel* lbOf;
	Cxradiogroup::TcxRadioButton* rbEvery1;
	Cxradiogroup::TcxRadioButton* rbThe1;
	Cxdropdownedit::TcxComboBox* cbMonths;
	Cxdropdownedit::TcxComboBox* cbWeek1;
	Cxdropdownedit::TcxComboBox* cbDay1;
	Cxdropdownedit::TcxComboBox* cbMonths1;
	Cxradiogroup::TcxRadioButton* rbEvery;
	Cxradiogroup::TcxRadioButton* rbEveryWeekday;
	Cxgroupbox::TcxGroupBox* gbRange;
	Cxlabel::TcxLabel* lbStart1;
	Cxlabel::TcxLabel* lbOccurrences;
	Cxcalendar::TcxDateEdit* deStart;
	Cxradiogroup::TcxRadioButton* rbNoEndDate;
	Cxradiogroup::TcxRadioButton* rbEndAfter;
	Cxradiogroup::TcxRadioButton* rbEndBy;
	Cxcalendar::TcxDateEdit* deEndBy;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnRemove;
	Cxlabel::TcxLabel* lbDay;
	Cxmaskedit::TcxMaskEdit* meDay;
	Cxmaskedit::TcxMaskEdit* meNumOfWeek;
	Cxmaskedit::TcxMaskEdit* meNumMonth1;
	Cxmaskedit::TcxMaskEdit* meNumMonth;
	Cxmaskedit::TcxMaskEdit* meDayOfMonth;
	Cxmaskedit::TcxMaskEdit* meEndAfter;
	Cxmaskedit::TcxMaskEdit* meNumOfDay;
	Cxlabel::TcxLabel* lbDuration;
	Cxdropdownedit::TcxComboBox* cbDuration;
	Cxgroupbox::TcxGroupBox* pnlDaily;
	Cxgroupbox::TcxGroupBox* pnlWeekly;
	Cxgroupbox::TcxGroupBox* pnlMonthly;
	Cxgroupbox::TcxGroupBox* pnlYearly;
	Cxgroupbox::TcxGroupBox* pnlPeriodicity;
	Dxbevel::TdxBevel* Bevel1;
	void __fastcall SelectPeriodicityClick(System::TObject* Sender);
	void __fastcall meEndAfterPropertiesChange(System::TObject* Sender);
	void __fastcall deEndByPropertiesChange(System::TObject* Sender);
	void __fastcall rbNoEndDateClick(System::TObject* Sender);
	void __fastcall meEndAfterExit(System::TObject* Sender);
	void __fastcall ValidateNumber(System::TObject* Sender);
	void __fastcall meDayPropertiesChange(System::TObject* Sender);
	void __fastcall rbEveryWeekdayClick(System::TObject* Sender);
	void __fastcall SetDayRadioButtonChecked(System::TObject* Sender);
	void __fastcall SetTheRadioButtonChecked(System::TObject* Sender);
	void __fastcall deStartPropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall DoChange(System::TObject* Sender);
	void __fastcall cbMonthsPropertiesChange(System::TObject* Sender);
	void __fastcall cbWeek1PropertiesChange(System::TObject* Sender);
	void __fastcall btnOkClick(System::TObject* Sender);
	void __fastcall deEndByPropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall meEndAfterPropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall cbDurationPropertiesPopup(System::TObject* Sender);
	void __fastcall cbDurationPropertiesValidate(System::TObject* Sender, System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error);
	void __fastcall EndTimeChanged(System::TObject* Sender);
	void __fastcall StartTimeChanged(System::TObject* Sender);
	
private:
	bool FLocked;
	void __fastcall CheckViewRecurrence(bool AResetPattern);
	void __fastcall FillDays(void);
	void __fastcall FillMonths(void);
	void __fastcall FillWeeks(void);
	Cxschedulerstorage::TcxRecurrence __fastcall GetActivePattern(void);
	Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* __fastcall GetRecurrenceInfo(void);
	int __fastcall GetDayOfWeekIndex(void);
	int __fastcall GetMonthIndex(void);
	int __fastcall GetNumber(const System::UnicodeString S);
	int __fastcall GetWeekIndex(void);
	System::TDateTime __fastcall GetCurrentDuration(void);
	bool __fastcall IsValidDailyPattern(void);
	bool __fastcall IsValidMonthlyPattern(void);
	bool __fastcall IsValidWeeklyPattern(void);
	bool __fastcall IsValidYearlyPattern(void);
	void __fastcall ResetDailyTab(void);
	void __fastcall ResetMonthlyTab(void);
	void __fastcall ResetWeeklyTab(void);
	void __fastcall ResetYearlyTab(void);
	void __fastcall SelectDaysOfWeek(Cxdateutils::TDays ADays);
	void __fastcall SetActivePattern(Cxschedulerstorage::TcxRecurrence Value);
	void __fastcall SetDailyPatternFromEvent(void);
	void __fastcall SetDateWithoutChangeEvent(Cxcalendar::TcxDateEdit* AEdit, System::TDateTime ADate);
	void __fastcall SetItemIndexWithoutChangeEvent(Cxdropdownedit::TcxComboBox* AEdit, int AIndex);
	void __fastcall SetMonthlyPatternFromEvent(void);
	void __fastcall SetPatternFromEvent(void);
	void __fastcall SetTextWithoutChangeEvent(Cxmaskedit::TcxCustomMaskEdit* AEdit, const System::UnicodeString AText);
	void __fastcall SetTimeWithoutChangeEvent(Cxtimeedit::TcxTimeEdit* AEdit, System::TDateTime ATime);
	void __fastcall SetupDaysOfWeek(void);
	void __fastcall SetWeeklyPatternFromEvent(void);
	void __fastcall SetYearlyPatternFromEvent(void);
	
protected:
	virtual void __fastcall ApplyChanges(void);
	bool __fastcall CheckLostExceptions(void);
	virtual void __fastcall FillCombos(void);
	virtual System::Uitypes::TColor __fastcall GetFormColor(void);
	Cxschedulerstorage::TcxRecurrenceValidStatus __fastcall GetRecurrenceInfoValidStatus(void);
	virtual void __fastcall InitializeControls(void);
	bool __fastcall IsValid(void);
	virtual void __fastcall LoadEventValuesIntoControls(void);
	void __fastcall SaveEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall SaveRecurrenceInfo(Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* AInfo);
	void __fastcall SaveDailyParams(Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* AInfo);
	void __fastcall SaveWeeklyParams(Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* AInfo);
	void __fastcall SaveMonthlyParams(Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* AInfo);
	void __fastcall SaveYearlyParams(Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* AInfo);
	virtual void __fastcall SetCaptions(void);
	void __fastcall SetEndAfter(void);
	void __fastcall SetEndDate(void);
	void __fastcall SetEventRecurrenceFinish(void);
	virtual void __fastcall SetReadOnly(bool AValue);
	void __fastcall UpdateDuration(void);
	virtual void __fastcall UpdateEventValuesFromControls(void);
	void __fastcall UpdateRange(void);
	__property Cxschedulerstorage::TcxRecurrence ActivePattern = {read=GetActivePattern, write=SetActivePattern, nodefault};
	__property Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* Info = {read=GetRecurrenceInfo};
	__property bool Locked = {read=FLocked, write=FLocked, nodefault};
	
public:
	__property Event;
	__property Modified;
	__property NeedCheckLossOfExceptions;
	__property ReadOnly;
public:
	/* TcxSchedulerCustomRecurrenceEventEditor.CreateEx */ inline __fastcall virtual TcxSchedulerRecurrenceEventEditorForm(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent) : TcxSchedulerCustomRecurrenceEventEditor(AEvent) { }
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSchedulerRecurrenceEventEditorForm(System::Classes::TComponent* AOwner) : TcxSchedulerCustomRecurrenceEventEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerRecurrenceEventEditorForm(System::Classes::TComponent* AOwner, int Dummy) : TcxSchedulerCustomRecurrenceEventEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSchedulerRecurrenceEventEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerRecurrenceEventEditorForm(HWND ParentWindow) : TcxSchedulerCustomRecurrenceEventEditor(ParentWindow) { }
	
};


typedef TcxSchedulerRecurrenceEventEditorForm TcxSchedulerRecurrenceEventEditor;

typedef System::TMetaClass* TcxSchedulerRecurrenceEventEditorClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerrecurrenceeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERRECURRENCEEDITOR)
using namespace Cxschedulerrecurrenceeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerrecurrenceeditorHPP
