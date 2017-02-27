// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerReminderWindow.pas' rev: 24.00 (Win64)

#ifndef CxschedulerreminderwindowHPP
#define CxschedulerreminderwindowHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerreminderwindow
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerReminderFormItem;
class PASCALIMPLEMENTATION TcxSchedulerReminderFormItem : public Cxschedulerstorage::TcxSchedulerReminderEventID
{
	typedef Cxschedulerstorage::TcxSchedulerReminderEventID inherited;
	
protected:
	System::Variant ResourceID;
	System::TDateTime ReminderDate;
	
public:
	__fastcall TcxSchedulerReminderFormItem(Cxschedulerstorage::TcxSchedulerReminder* AReminder);
	HIDESBASE bool __fastcall Equals(Cxschedulerstorage::TcxSchedulerReminder* AReminder);
public:
	/* TcxSchedulerReminderEventID.Destroy */ inline __fastcall virtual ~TcxSchedulerReminderFormItem(void) { }
	
};


typedef System::StaticArray<int, 3> TcxReminderFormLayoutData;

class DELPHICLASS TcxSchedulerReminderForm;
class PASCALIMPLEMENTATION TcxSchedulerReminderForm : public Cxschedulerstorage::TcxSchedulerCustomReminderForm
{
	typedef Cxschedulerstorage::TcxSchedulerCustomReminderForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnDismiss;
	Cxbuttons::TcxButton* btnDismissAll;
	Cxbuttons::TcxButton* btnOpenItem;
	Cxbuttons::TcxButton* btnSnooze;
	Cxdropdownedit::TcxComboBox* cbSnoozeTime;
	Cxlabel::TcxLabel* lbEventCaption;
	Cxlabel::TcxLabel* lbEventStartTime;
	Cxlistview::TcxListView* lvItems;
	Vcl::Extctrls::TPaintBox* pbImage;
	Vcl::Extctrls::TTimer* tmUpdate;
	void __fastcall ButtonClick(System::TObject* Sender);
	void __fastcall DrawIcon(System::TObject* Sender);
	void __fastcall lvItemsSelectItem(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool Selected);
	void __fastcall lvItemsDblClick(System::TObject* Sender);
	void __fastcall tmUpdateTimer(System::TObject* Sender);
	void __fastcall lvItemsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	TcxReminderFormLayoutData FLayoutData;
	int FAdvanceCount;
	Cxclasses::TcxObjectList* FSelections;
	Cxschedulerstorage::TcxSchedulerReminder* __fastcall GetFocusedReminder(void);
	Cxschedulerstorage::TcxSchedulerReminder* __fastcall GetVisibleReminder(int Index);
	int __fastcall GetVisibleReminderCount(void);
	void __fastcall SynchronizeSelection(void);
	MESSAGE void __fastcall WMRedrawHeader(tagMSG &Msg);
	
protected:
	virtual void * __fastcall GetInfoData(void);
	virtual int __fastcall GetInfoDataSize(void);
	virtual void __fastcall SetInfoData(void * AData);
	Vcl::Comctrls::TListItem* __fastcall AddReminder(Cxschedulerstorage::TcxSchedulerReminder* AReminder);
	void __fastcall AddReminderInfo(Cxschedulerstorage::TcxSchedulerReminder* AReminder, Vcl::Comctrls::TListItem* AItem, const System::UnicodeString ADueInText);
	int __fastcall AddSnoozeAdvanceTime(const System::UnicodeString AText, int AMinutes);
	int __fastcall AddSnoozeTime(const System::UnicodeString AText, int AMinutes);
	void __fastcall CheckColumnCaptions(void);
	virtual void __fastcall CheckColumnCount(void);
	virtual void __fastcall CheckFormPosition(void);
	virtual void __fastcall CreateSnoozeAdvanceTimeItems(void);
	void __fastcall DismissEvents(bool All);
	DYNAMIC void __fastcall DoShow(void);
	int __fastcall GetDueInColumnIndex(void);
	virtual int __fastcall GetImageIndexForReminder(Cxschedulerstorage::TcxSchedulerReminder* AReminder);
	int __fastcall GetMaxAdvanceMinutes(void);
	virtual System::UnicodeString __fastcall GetResourceNameForReminder(Cxschedulerstorage::TcxSchedulerReminder* AReminder);
	virtual bool __fastcall GetShowResourceColumn(void);
	virtual System::TDateTime __fastcall GetSnoozeTime(void);
	virtual void __fastcall LayoutChanged(void);
	void __fastcall SnoozeEvents(void);
	void __fastcall OpenFocusedEvent(void);
	virtual void __fastcall RefreshSelectedInfo(void);
	void __fastcall ResetAdvanceCount(void);
	virtual void __fastcall RestoreSelection(void);
	virtual void __fastcall SaveSelection(void);
	virtual void __fastcall SetupCaptions(void);
	void __fastcall UpdateDueTimeTexts(void);
	virtual void __fastcall UpdateReminderList(void);
	virtual void __fastcall UpdateSelectionCaptions(void);
	virtual void __fastcall UpdateSnoozeComboBox(void);
	__property int AdvanceCount = {read=FAdvanceCount, nodefault};
	__property int VisibleReminderCount = {read=GetVisibleReminderCount, nodefault};
	__property Cxschedulerstorage::TcxSchedulerReminder* VisibleReminders[int Index] = {read=GetVisibleReminder};
	
public:
	__fastcall virtual TcxSchedulerReminderForm(Cxschedulerstorage::TcxSchedulerReminders* AReminders);
	__fastcall virtual ~TcxSchedulerReminderForm(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerReminderForm(System::Classes::TComponent* AOwner, int Dummy) : Cxschedulerstorage::TcxSchedulerCustomReminderForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerReminderForm(HWND ParentWindow) : Cxschedulerstorage::TcxSchedulerCustomReminderForm(ParentWindow) { }
	
private:
	void *__IcxDialogMetricsInfoData;	/* Cxclasses::IcxDialogMetricsInfoData */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DBFB3040-4677-4C9D-913C-45A1EE41E35A}
	operator Cxclasses::_di_IcxDialogMetricsInfoData()
	{
		Cxclasses::_di_IcxDialogMetricsInfoData intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IcxDialogMetricsInfoData*(void) { return (Cxclasses::IcxDialogMetricsInfoData*)&__IcxDialogMetricsInfoData; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxDialogMetricsInfoData; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Word cxDefaultResourceNameColumnWidth;
}	/* namespace Cxschedulerreminderwindow */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERREMINDERWINDOW)
using namespace Cxschedulerreminderwindow;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerreminderwindowHPP
