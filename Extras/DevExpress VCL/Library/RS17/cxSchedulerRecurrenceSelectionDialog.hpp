// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerRecurrenceSelectionDialog.pas' rev: 24.00 (Win32)

#ifndef CxschedulerrecurrenceselectiondialogHPP
#define CxschedulerrecurrenceselectiondialogHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerrecurrenceselectiondialog
{
//-- type declarations -------------------------------------------------------
enum TcxRecurrenceSelectionMode : unsigned char { rsmOpen, rsmDeleting };

class DELPHICLASS TfmRecurrenceSelectionForm;
class PASCALIMPLEMENTATION TfmRecurrenceSelectionForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxlabel::TcxLabel* lbMessage;
	Cxradiogroup::TcxRadioButton* rbOccurrence;
	Cxradiogroup::TcxRadioButton* rbSeries;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Vcl::Extctrls::TImage* Image;
	Vcl::Extctrls::TPanel* pnlControls;
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* FEvent;
	TcxRecurrenceSelectionMode FMode;
	
protected:
	DYNAMIC void __fastcall DoShow(void);
	virtual System::Uitypes::TColor __fastcall GetFormColor(void);
	virtual void __fastcall SetCaptions(void);
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=FEvent};
	__property TcxRecurrenceSelectionMode Mode = {read=FMode, nodefault};
	
public:
	__fastcall virtual TfmRecurrenceSelectionForm(Cxschedulerstorage::TcxSchedulerEvent* AEvent, TcxRecurrenceSelectionMode AMode);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmRecurrenceSelectionForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmRecurrenceSelectionForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmRecurrenceSelectionForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmRecurrenceSelectionForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerrecurrenceselectiondialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERRECURRENCESELECTIONDIALOG)
using namespace Cxschedulerrecurrenceselectiondialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerrecurrenceselectiondialogHPP
