// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxEditCon.pas' rev: 24.00 (Win64)

#ifndef DxeditconHPP
#define DxeditconHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <dxflchrt.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxeditcon
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFEditConnection;
class PASCALIMPLEMENTATION TFEditConnection : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TGroupBox* GroupBox3;
	Vcl::Buttons::TSpeedButton* sbFont;
	Vcl::Dialogs::TColorDialog* ColorDialog;
	Vcl::Dialogs::TFontDialog* FontDialog;
	Vcl::Extctrls::TPanel* pColor;
	Vcl::Extctrls::TPanel* pBkColor;
	Vcl::Stdctrls::TGroupBox* GroupBox2;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Stdctrls::TLabel* Label6;
	Vcl::Stdctrls::TLabel* Label7;
	Vcl::Stdctrls::TEdit* seDPoint;
	Vcl::Stdctrls::TEdit* seDArrowSize;
	Vcl::Stdctrls::TComboBox* cbDArrowStyle;
	Vcl::Stdctrls::TGroupBox* GroupBox1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Stdctrls::TComboBox* cbSArrowStyle;
	Vcl::Stdctrls::TEdit* seSArrowSize;
	Vcl::Stdctrls::TEdit* seSPoint;
	Vcl::Stdctrls::TMemo* MemoText;
	Vcl::Stdctrls::TLabel* Label8;
	Vcl::Stdctrls::TLabel* Label9;
	Vcl::Stdctrls::TLabel* Label1;
	void __fastcall MemoTextChange(System::TObject* Sender);
	void __fastcall pColorClick(System::TObject* Sender);
	void __fastcall sbFontClick(System::TObject* Sender);
	void __fastcall seSArrowSizeKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall seSPointKeyPress(System::TObject* Sender, System::WideChar &Key);
	
protected:
	bool __fastcall IsModified(System::Classes::TComponent* AComponent);
	void __fastcall ClearModifiedFlag(void);
	void __fastcall LoadLocalizations(void);
	void __fastcall LoadParams(Dxflchrt::TdxFcConnection* AConnection);
	void __fastcall Modified(System::TObject* AObject);
	void __fastcall SaveParams(Dxflchrt::TdxFcConnection* AConnection);
	
public:
	__fastcall virtual TFEditConnection(System::Classes::TComponent* AOwner);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFEditConnection(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFEditConnection(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TFEditConnection(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ConnectEditor(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcConnection* AConnection);
}	/* namespace Dxeditcon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXEDITCON)
using namespace Dxeditcon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxeditconHPP
