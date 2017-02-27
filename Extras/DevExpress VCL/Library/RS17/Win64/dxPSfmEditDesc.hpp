// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmEditDesc.pas' rev: 24.00 (Win64)

#ifndef DxpsfmeditdescHPP
#define DxpsfmeditdescHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmeditdesc
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmEditDescription;
class PASCALIMPLEMENTATION TdxfmEditDescription : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOK;
	Cxgroupbox::TcxGroupBox* gbxMemoHost;
	Cxmemo::TcxMemo* memDescription;
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	System::UnicodeString __fastcall GetDescription(void);
	void __fastcall SetDescription(const System::UnicodeString Value);
	HIDESBASE MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	void __fastcall Initialize(void);
	void __fastcall LoadStrings(void);
	
public:
	__fastcall virtual TdxfmEditDescription(System::Classes::TComponent* AOwner);
	bool __fastcall Execute(void);
	__property System::UnicodeString Description = {read=GetDescription, write=SetDescription};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmEditDescription(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmEditDescription(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmEditDescription(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxEditDescriptionDlg(System::UnicodeString &ADescription);
}	/* namespace Dxpsfmeditdesc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMEDITDESC)
using namespace Dxpsfmeditdesc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmeditdescHPP
