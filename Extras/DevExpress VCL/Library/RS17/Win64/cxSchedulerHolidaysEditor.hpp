// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerHolidaysEditor.pas' rev: 24.00 (Win64)

#ifndef CxschedulerholidayseditorHPP
#define CxschedulerholidayseditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxShellBrowserDialog.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerholidayseditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmHolidaysEditor;
class PASCALIMPLEMENTATION TfmHolidaysEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnImport;
	Cxgroupbox::TcxGroupBox* gbAddedHolidays;
	Cxgroupbox::TcxGroupBox* gbHolidays;
	Cxbuttons::TcxButton* btnHolidaysAdd;
	Cxbuttons::TcxButton* btnHolidaysEdit;
	Cxbuttons::TcxButton* btnHolidaysDelete;
	Cxchecklistbox::TcxCheckListBox* clbHolidays;
	Cxlistbox::TcxListBox* lbxAllAddedHolidays;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnApply;
	Cxbuttons::TcxButton* btnExport;
	Cxgroupbox::TcxGroupBox* gbLocations;
	Cxchecklistbox::TcxCheckListBox* clbLocations;
	Cxbuttons::TcxButton* btnLocationAdd;
	Cxbuttons::TcxButton* btnLocationEdit;
	Cxbuttons::TcxButton* btnLocationDelete;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall clbLocationsClick(System::TObject* Sender);
	void __fastcall clbLocationsClickCheck(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);
	void __fastcall clbHolidaysClickCheck(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);
	void __fastcall btnImportClick(System::TObject* Sender);
	void __fastcall btnApplyClick(System::TObject* Sender);
	void __fastcall btnLocationClick(System::TObject* Sender);
	void __fastcall btnHolidaysClick(System::TObject* Sender);
	void __fastcall clbLocationsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall clbHolidaysKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall btnOkClick(System::TObject* Sender);
	void __fastcall clbLocationsDblClick(System::TObject* Sender);
	void __fastcall clbHolidaysDblClick(System::TObject* Sender);
	void __fastcall btnExportClick(System::TObject* Sender);
	
private:
	Cxschedulerholidays::TcxSchedulerHolidays* FHolidays;
	bool FModify;
	Cxschedulerholidays::TcxSchedulerHolidays* FOwnerHolidays;
	bool FSaved;
	void __fastcall CheckHolideyItemIndex(void);
	int __fastcall GetHolidayIndex(void);
	void __fastcall SetHolidays(Cxschedulerholidays::TcxSchedulerHolidays* const AValue);
	int __fastcall GetLocationIndex(void);
	
protected:
	virtual void __fastcall ChangeHoliday(bool ANew);
	virtual void __fastcall ChangeLocation(bool ANew);
	virtual void __fastcall CheckButtonsState(bool ACanEnabled = true);
	virtual void __fastcall DeleteHoliday(void);
	virtual void __fastcall DeleteLocation(void);
	virtual void __fastcall DoExport(void);
	virtual void __fastcall DoImport(void);
	virtual void __fastcall InitControls(void);
	virtual bool __fastcall Save(void);
	void __fastcall SetCaptions(void);
	void __fastcall PopulateLists(void);
	void __fastcall UpdateAddedHolidays(void)/* overload */;
	void __fastcall UpdateAddedHolidays(int ALocationIndex)/* overload */;
	void __fastcall UpdateHolidays(int ALocationIndex);
	__property int HolidayIndex = {read=GetHolidayIndex, nodefault};
	__property int LocationIndex = {read=GetLocationIndex, nodefault};
	
public:
	virtual int __fastcall ShowModal(void);
	__property Cxschedulerholidays::TcxSchedulerHolidays* Holidays = {read=FHolidays, write=SetHolidays};
	__property bool Modify = {read=FModify, nodefault};
	__property bool Saved = {read=FSaved, nodefault};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmHolidaysEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmHolidaysEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmHolidaysEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmHolidaysEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef TfmHolidaysEditor TcxSchedulerHolidaysEditor;

typedef System::TMetaClass* TcxSchedulerHolidaysEditorClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerholidayseditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERHOLIDAYSEDITOR)
using namespace Cxschedulerholidayseditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerholidayseditorHPP
