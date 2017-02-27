// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerHolidaysLocationEditor.pas' rev: 24.00 (Win32)

#ifndef CxschedulerholidayslocationeditorHPP
#define CxschedulerholidayslocationeditorHPP

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
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerholidayslocationeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmHolidaysLocationEditor;
class PASCALIMPLEMENTATION TfmHolidaysLocationEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxtextedit::TcxTextEdit* teName;
	Cxlabel::TcxLabel* lbName;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall teLocationPropertiesChange(System::TObject* Sender);
	void __fastcall btnOKClick(System::TObject* Sender);
	
private:
	Cxschedulerholidays::TcxSchedulerHolidaysLocation* FLocation;
	bool FModify;
	void __fastcall SetLocation(Cxschedulerholidays::TcxSchedulerHolidaysLocation* const AValue);
	
protected:
	void __fastcall CheckButtonsState(void);
	virtual void __fastcall InitControls(void);
	virtual bool __fastcall Save(void);
	void __fastcall SetCaptions(void);
	
public:
	virtual int __fastcall ShowModal(void);
	__property Cxschedulerholidays::TcxSchedulerHolidaysLocation* Location = {read=FLocation, write=SetLocation};
	__property bool Modify = {read=FModify, nodefault};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmHolidaysLocationEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmHolidaysLocationEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmHolidaysLocationEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmHolidaysLocationEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerholidayslocationeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERHOLIDAYSLOCATIONEDITOR)
using namespace Cxschedulerholidayslocationeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerholidayslocationeditorHPP
