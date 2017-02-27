// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilterControlDialog.pas' rev: 24.00 (Win32)

#ifndef CxfiltercontroldialogHPP
#define CxfiltercontroldialogHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxFilterControl.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxfiltercontroldialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmFilterControlDialog;
class PASCALIMPLEMENTATION TfmFilterControlDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlBottom;
	Cxbuttons::TcxButton* btOpen;
	Cxbuttons::TcxButton* btSave;
	Vcl::Dialogs::TOpenDialog* OpenDialog;
	Vcl::Dialogs::TSaveDialog* SaveDialog;
	Vcl::Extctrls::TPanel* pnlBottomRight;
	Cxbuttons::TcxButton* btApply;
	Cxbuttons::TcxButton* btCancel;
	Cxbuttons::TcxButton* btOk;
	void __fastcall acApplyExecute(System::TObject* Sender);
	void __fastcall acOkExecute(System::TObject* Sender);
	void __fastcall acOpenExecute(System::TObject* Sender);
	void __fastcall acSaveExecute(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall FormKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	System::Classes::TNotifyEvent FOnAfterApply;
	System::Classes::TNotifyEvent FOnBeforeApply;
	bool FHasOpenedPopupWindow;
	Cxfiltercontrol::TcxCustomFilterControl* FFilterControl;
	void __fastcall Initialize(const System::UnicodeString AInitialDir);
	void __fastcall SetControlsEnabled(bool AEnabled);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	void __fastcall SetPanelsColor(System::Uitypes::TColor AColor);
	void __fastcall SetTitle(const System::UnicodeString ATitle);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall ApplyFilter(void);
	virtual void __fastcall DoAfterApply(void);
	virtual void __fastcall DoBeforeApply(void);
	
public:
	__fastcall virtual TfmFilterControlDialog(System::Classes::TComponent* AOwner);
	__property Cxfiltercontrol::TcxCustomFilterControl* FilterControl = {read=FFilterControl};
	__property System::Classes::TNotifyEvent OnAfterApply = {read=FOnAfterApply, write=FOnAfterApply};
	__property System::Classes::TNotifyEvent OnBeforeApply = {read=FOnBeforeApply, write=FOnBeforeApply};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmFilterControlDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmFilterControlDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmFilterControlDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Types::TRect cxFilterDialogPosition;
extern PACKAGE bool __fastcall cxInternalExecuteFilterControlDialog(Cxfiltercontrol::TcxCustomFilterControlClass AFilterControlClass, System::Classes::TComponent* ALink, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::Classes::TNotifyEvent AOnApplyProc = 0x0, System::Classes::TNotifyEvent AOnShowDialog = 0x0, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), const System::UnicodeString AInitialDir = System::UnicodeString(), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), System::Classes::TNotifyEvent AOnBeforeApply = 0x0, System::Classes::TNotifyEvent AOnAfterApply = 0x0);
extern PACKAGE bool __fastcall ExecuteFilterControlDialog(System::Classes::TComponent* ALinkComponent, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, System::Classes::TNotifyEvent AOnApplyProc = 0x0, System::Classes::TNotifyEvent AOnShowDialog = 0x0, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), const System::UnicodeString AInitialDir = System::UnicodeString(), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), System::Classes::TNotifyEvent AOnBeforeApply = 0x0, System::Classes::TNotifyEvent AOnAfterApply = 0x0);
}	/* namespace Cxfiltercontroldialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTERCONTROLDIALOG)
using namespace Cxfiltercontroldialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfiltercontroldialogHPP
