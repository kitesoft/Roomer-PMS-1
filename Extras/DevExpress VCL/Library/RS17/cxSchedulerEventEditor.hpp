// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerEventEditor.pas' rev: 24.00 (Win32)

#ifndef CxschedulereventeditorHPP
#define CxschedulereventeditorHPP

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
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxCheckComboBox.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <dxBevel.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulereventeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerCustomEditorForm;
class PASCALIMPLEMENTATION TcxSchedulerCustomEditorForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerControlEvent* FEvent;
	bool FIsInternalActivation;
	bool FReadOnly;
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	
protected:
	bool FModified;
	bool FIsCreation;
	virtual void __fastcall ApplyChanges(void);
	virtual System::Uitypes::TColor __fastcall GetFormColor(void);
	virtual void __fastcall InitializeControls(void);
	virtual void __fastcall LoadEventValuesIntoControls(void);
	virtual void __fastcall LoadValuesIntoTimeControls(const System::TDateTime AStart, const System::TDateTime AFinish, bool AllDayEvent);
	virtual void __fastcall SetReadOnly(bool AValue);
	virtual void __fastcall UpdateEventValuesFromControls(void);
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	__fastcall virtual TcxSchedulerCustomEditorForm(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual int __fastcall ShowModal(void);
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=FEvent};
	__property bool IsInternalActivation = {read=FIsInternalActivation, write=FIsInternalActivation, nodefault};
	__property bool Modified = {read=FModified, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, nodefault};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSchedulerCustomEditorForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerCustomEditorForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerCustomEditorForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TcxSchedulerCustomEventEditor;
class PASCALIMPLEMENTATION TcxSchedulerCustomEventEditor : public TcxSchedulerCustomEditorForm
{
	typedef TcxSchedulerCustomEditorForm inherited;
	
private:
	bool FAllowDelete;
	bool FAllowHiddenEvents;
	bool FAllowRecurrence;
	bool FAllowShare;
	System::TDateTime FBiasTime;
	bool FDeleteSeries;
	bool FDeleteExceptions;
	bool FForceSeries;
	bool FHasStorageEvent;
	bool FIntersection;
	bool FRecurrenceActivate;
	System::TDateTime FPatternStart;
	System::TDateTime FPatternFinish;
	Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* FRecurrenceInfo;
	bool FShowResources;
	bool FShowTaskComplete;
	Cxschedulercustomcontrols::TcxOnDeleteEventFunc FOnDeleteFunc;
	
protected:
	void __fastcall ApplyEventTime(void);
	virtual bool __fastcall CheckIntersection(void);
	virtual void __fastcall DeleteEvent(void);
	virtual bool __fastcall FindAvailableTime(void);
	virtual void __fastcall GetEditingEventTime(System::TDateTime &AStart, System::TDateTime &AFinish, int &AState) = 0 ;
	virtual bool __fastcall GetResourcesPanelVisible(void);
	virtual void __fastcall PostEvent(void);
	virtual void __fastcall SaveChanges(void);
	virtual void __fastcall SaveResourceID(void);
	virtual void __fastcall SetAllowDelete(bool AValue);
	virtual void __fastcall SetAllowRecurrence(bool AValue);
	virtual void __fastcall SetIntersection(bool AValue);
	__property bool DeleteExceptions = {read=FDeleteExceptions, write=FDeleteExceptions, nodefault};
	__property bool DeleteSeries = {read=FDeleteSeries, write=FDeleteSeries, nodefault};
	__property bool HasStorageEvent = {read=FHasStorageEvent, nodefault};
	__property Storage;
	__property System::TDateTime PatternStart = {read=FPatternStart};
	__property System::TDateTime PatternFinish = {read=FPatternFinish};
	__property Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* RecurrenceInfo = {read=FRecurrenceInfo};
	
public:
	__fastcall virtual TcxSchedulerCustomEventEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	__fastcall virtual ~TcxSchedulerCustomEventEditor(void);
	__property bool AllowDelete = {read=FAllowDelete, write=SetAllowDelete, nodefault};
	__property bool AllowHiddenEvents = {read=FAllowHiddenEvents, write=FAllowHiddenEvents, nodefault};
	__property bool AllowRecurrence = {read=FAllowRecurrence, write=SetAllowRecurrence, nodefault};
	__property bool AllowShare = {read=FAllowShare, write=FAllowShare, nodefault};
	__property System::TDateTime BiasTime = {read=FBiasTime, write=FBiasTime};
	__property Event;
	__property bool ForceSeries = {read=FForceSeries, write=FForceSeries, nodefault};
	__property bool Intersection = {read=FIntersection, write=SetIntersection, nodefault};
	__property bool Modified = {read=FModified, nodefault};
	__property bool RecurrenceActivate = {read=FRecurrenceActivate, write=FRecurrenceActivate, nodefault};
	__property ReadOnly;
	__property bool ShowResources = {read=FShowResources, write=FShowResources, nodefault};
	__property bool ShowTaskComplete = {read=FShowTaskComplete, write=FShowTaskComplete, nodefault};
	__property Cxschedulercustomcontrols::TcxOnDeleteEventFunc OnDeleteFunc = {read=FOnDeleteFunc, write=FOnDeleteFunc};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSchedulerCustomEventEditor(System::Classes::TComponent* AOwner) : TcxSchedulerCustomEditorForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerCustomEventEditor(System::Classes::TComponent* AOwner, int Dummy) : TcxSchedulerCustomEditorForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerCustomEventEditor(HWND ParentWindow) : TcxSchedulerCustomEditorForm(ParentWindow) { }
	
};


class DELPHICLASS TcxSchedulerEventEditorForm;
class PASCALIMPLEMENTATION TcxSchedulerEventEditorForm : public TcxSchedulerCustomEventEditor
{
	typedef TcxSchedulerCustomEventEditor inherited;
	
__published:
	Dxbevel::TdxBevel* Bevel1;
	Dxbevel::TdxBevel* Bevel5;
	Dxbevel::TdxBevel* Bevel6;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnRecurrence;
	Cxcheckbox::TcxCheckBox* cbAllDayEvent;
	Cxcheckbox::TcxCheckBox* cbReminder;
	Cxdropdownedit::TcxComboBox* cbReminderMinutesBeforeStart;
	Cxcheckcombobox::TcxCheckComboBox* cbResources;
	Cxbuttons::TcxButton* btnFindTime;
	Cxgroupbox::TcxGroupBox* cxGroupBox1;
	Cxcalendar::TcxDateEdit* deEnd;
	Cxcalendar::TcxDateEdit* deStart;
	Cximagecombobox::TcxImageComboBox* icbLabel;
	Cximagecombobox::TcxImageComboBox* icbShowTimeAs;
	Cxlabel::TcxLabel* lbEndTime;
	Cxlabel::TcxLabel* lbInformation;
	Cxlabel::TcxLabel* lbLabel;
	Cxlabel::TcxLabel* lbLocation;
	Cxlabel::TcxLabel* lbResource;
	Cxlabel::TcxLabel* lbShowTimeAs;
	Cxlabel::TcxLabel* lbStartTime;
	Cxlabel::TcxLabel* lbSubject;
	Cxmemo::TcxMemo* meMessage;
	Vcl::Extctrls::TPanel* pnlButtons;
	Vcl::Extctrls::TPanel* pnlCaption;
	Vcl::Extctrls::TPanel* pnlInformation;
	Vcl::Extctrls::TPanel* pnlMessage;
	Vcl::Extctrls::TPanel* pnlRecurrence;
	Vcl::Extctrls::TPanel* pnlPlaceHolder;
	Vcl::Extctrls::TPanel* pnlResource;
	Vcl::Extctrls::TPanel* pnlThreeButtons;
	Vcl::Extctrls::TPanel* pnlTime;
	Cxtimeedit::TcxTimeEdit* teEnd;
	Cxtextedit::TcxTextEdit* teLocation;
	Cxtimeedit::TcxTimeEdit* teStart;
	Cxtextedit::TcxTextEdit* teSubject;
	Vcl::Extctrls::TPanel* pnlReminder;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* pnlShowTimeAs;
	Vcl::Extctrls::TPanel* pnlRecurrenceInfo;
	Dxbevel::TdxBevel* Bevel7;
	Cxlabel::TcxLabel* lbRecurrence;
	Cxlabel::TcxLabel* lbRecurrencePattern;
	Vcl::Extctrls::TPanel* pnlTaskComplete;
	Dxbevel::TdxBevel* Bevel8;
	Cxlabel::TcxLabel* lbTaskComplete;
	Cxspinedit::TcxSpinEdit* seTaskComplete;
	Cxdropdownedit::TcxComboBox* cbxTaskStatus;
	Cxlabel::TcxLabel* lbTaskStatus;
	void __fastcall OnChanged(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall cbAllDayEventPropertiesChange(System::TObject* Sender);
	void __fastcall StartDateChanged(System::TObject* Sender);
	void __fastcall cbReminderClick(System::TObject* Sender);
	void __fastcall cbReminderMinutesBeforeStartPropertiesValidate(System::TObject* Sender, System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error);
	void __fastcall cbReminderMinutesBeforeStartPropertiesPopup(System::TObject* Sender);
	void __fastcall OnEventTimeChanged(System::TObject* Sender);
	void __fastcall btnRecurrenceClick(System::TObject* Sender);
	void __fastcall OnResourceIDChanged(System::TObject* Sender);
	void __fastcall btnFindTimeClick(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	void __fastcall seTaskCompleteChange(System::TObject* Sender);
	void __fastcall cbxTaskStatusChange(System::TObject* Sender);
	void __fastcall cbResourcesPropertiesClickCheck(System::TObject* Sender, int ItemIndex, bool &AllowToggle);
	
private:
	bool FNeedCheckLossOfExceptions;
	int FRecurrenceInfoHeight;
	System::UnicodeString __fastcall GetEventName(void);
	
protected:
	System::TDateTime FDuration;
	bool FIsUpdating;
	virtual void __fastcall ApplyChanges(void);
	virtual bool __fastcall CheckIntersection(void);
	virtual bool __fastcall CheckTimeRange(System::TDateTime &AStart, System::TDateTime &AFinish);
	virtual void __fastcall CheckVisible(void);
	virtual void __fastcall ClearModifiedFlag(void);
	virtual void __fastcall GetEditingEventTime(System::TDateTime &AStart, System::TDateTime &AFinish, int &AState);
	virtual System::Uitypes::TColor __fastcall GetFormColor(void);
	virtual System::UnicodeString __fastcall GetRecurrenceDescription(void);
	virtual void __fastcall InitializeControls(void);
	void __fastcall InitLabelColor(void);
	void __fastcall InitReminderPanel(void);
	void __fastcall InitResources(void);
	void __fastcall InitShowTimeAsPanel(void);
	void __fastcall InitTaskCompletePanel(void);
	virtual void __fastcall LoadEventValuesIntoControls(void);
	virtual void __fastcall LoadValuesIntoTimeControls(const System::TDateTime AStart, const System::TDateTime AFinish, bool AllDayEvent);
	virtual bool __fastcall IsValid(void);
	virtual void __fastcall RefreshRecurrenceInfo(void);
	virtual void __fastcall SaveResourceID(void);
	HIDESBASE virtual void __fastcall SetActiveControl(void);
	virtual void __fastcall SetAllowDelete(bool AValue);
	virtual void __fastcall SetAllowRecurrence(bool AValue);
	virtual void __fastcall SetCaptions(void);
	virtual void __fastcall SetReadOnly(bool AValue);
	virtual void __fastcall SetReminderMinutesBeforeStart(void);
	virtual void __fastcall UpdateEventValuesFromControls(void);
	
public:
	__fastcall virtual TcxSchedulerEventEditorForm(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual int __fastcall ShowModal(void);
	__property AllowDelete;
	__property AllowRecurrence;
	__property BiasTime = {default=0};
	__property Event;
	__property System::UnicodeString EventName = {read=GetEventName};
	__property ForceSeries;
	__property Modified;
	__property RecurrenceActivate;
	__property ReadOnly;
	__property OnDeleteFunc;
public:
	/* TcxSchedulerCustomEventEditor.Destroy */ inline __fastcall virtual ~TcxSchedulerEventEditorForm(void) { }
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSchedulerEventEditorForm(System::Classes::TComponent* AOwner) : TcxSchedulerCustomEventEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerEventEditorForm(System::Classes::TComponent* AOwner, int Dummy) : TcxSchedulerCustomEventEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerEventEditorForm(HWND ParentWindow) : TcxSchedulerCustomEventEditor(ParentWindow) { }
	
};


typedef TcxSchedulerEventEditorForm TcxSchedulerEventEditor;

typedef System::TMetaClass* TcxSchedulerEventEditorClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulereventeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULEREVENTEDITOR)
using namespace Cxschedulereventeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulereventeditorHPP
