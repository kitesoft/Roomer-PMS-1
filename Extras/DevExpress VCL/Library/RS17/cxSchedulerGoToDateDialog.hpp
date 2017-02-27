// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerGoToDateDialog.pas' rev: 24.00 (Win32)

#ifndef CxschedulergotodatedialogHPP
#define CxschedulergotodatedialogHPP

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
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulergotodatedialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmGoToDateForm;
class PASCALIMPLEMENTATION TfmGoToDateForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* cxGroupBox1;
	Cxcalendar::TcxDateEdit* deDate;
	Cxdropdownedit::TcxComboBox* cbShowIn;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxlabel::TcxLabel* lbDate;
	Cxlabel::TcxLabel* lbShowIn;
	
protected:
	void __fastcall FillCombo(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler);
	System::Uitypes::TColor __fastcall GetFormColor(void);
	void __fastcall SetCaptions(void);
	
public:
	__fastcall virtual TfmGoToDateForm(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler, System::TDateTime ADate);
	Cxschedulercustomcontrols::TcxSchedulerViewMode __fastcall GetViewMode(void);
	virtual int __fastcall ShowModal(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmGoToDateForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmGoToDateForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmGoToDateForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmGoToDateForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulergotodatedialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERGOTODATEDIALOG)
using namespace Cxschedulergotodatedialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulergotodatedialogHPP
