// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxEditObj.pas' rev: 24.00 (Win64)

#ifndef DxeditobjHPP
#define DxeditobjHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxflchrt.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxeditobj
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFEditObject;
class PASCALIMPLEMENTATION TFEditObject : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Stdctrls::TButton* btnClear;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TCheckBox* cbAdjust;
	Vcl::Stdctrls::TCheckBox* cbBottom;
	Vcl::Stdctrls::TCheckBox* cbDiag;
	Vcl::Stdctrls::TCheckBox* cbFlat;
	Vcl::Stdctrls::TComboBox* cbImagePosition;
	Vcl::Stdctrls::TCheckBox* cbLeft;
	Vcl::Stdctrls::TCheckBox* cbMiddle;
	Vcl::Stdctrls::TCheckBox* cbMono;
	Vcl::Stdctrls::TCheckBox* cbRaisedIn;
	Vcl::Stdctrls::TCheckBox* cbRaisedOut;
	Vcl::Stdctrls::TCheckBox* cbRight;
	Vcl::Stdctrls::TComboBox* cbShapeStyle;
	Vcl::Stdctrls::TCheckBox* cbSoft;
	Vcl::Stdctrls::TCheckBox* cbSunkenIn;
	Vcl::Stdctrls::TCheckBox* cbSunkenOut;
	Vcl::Stdctrls::TComboBox* cbTextPosition;
	Vcl::Stdctrls::TCheckBox* cbTop;
	Vcl::Stdctrls::TCheckBox* cbTransparent;
	Vcl::Dialogs::TColorDialog* ColorDialog;
	Vcl::Dialogs::TFontDialog* FontDialog;
	Vcl::Stdctrls::TGroupBox* GroupBox1;
	Vcl::Stdctrls::TGroupBox* GroupBox2;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Stdctrls::TLabel* Label6;
	Vcl::Stdctrls::TLabel* Label7;
	Vcl::Stdctrls::TLabel* Label8;
	Vcl::Stdctrls::TLabel* Label9;
	Vcl::Comctrls::TListView* lwImage;
	Vcl::Stdctrls::TMemo* memoText;
	Vcl::Comctrls::TPageControl* PageControl;
	Vcl::Extctrls::TPanel* pBkColor;
	Vcl::Extctrls::TPanel* pColor;
	Vcl::Buttons::TSpeedButton* sbFont;
	Vcl::Stdctrls::TEdit* seHeight;
	Vcl::Stdctrls::TEdit* seShapeWidth;
	Vcl::Stdctrls::TEdit* seWidth;
	Vcl::Comctrls::TTabSheet* tsFrame;
	Vcl::Comctrls::TTabSheet* tsGeneral;
	Vcl::Comctrls::TTabSheet* tsImage;
	void __fastcall btnClearClick(System::TObject* Sender);
	void __fastcall pColorClick(System::TObject* Sender);
	void __fastcall sbFontClick(System::TObject* Sender);
	void __fastcall seHeightChange(System::TObject* Sender);
	void __fastcall seHeightKeyPress(System::TObject* Sender, System::WideChar &Key);
	
private:
	int __fastcall GetBorderStyle(void);
	int __fastcall GetEdgeStyle(void);
	bool __fastcall IsBorderStyleChanged(void);
	bool __fastcall IsEdgeStyleChanged(void);
	HIDESBASE void __fastcall SetBorderStyle(int AValue);
	void __fastcall SetEdgeStyle(System::Word AValue);
	bool __fastcall IsModified(System::Classes::TComponent* AComponent);
	void __fastcall ClearModifiedFlag(void);
	void __fastcall LoadLocalizations(void);
	void __fastcall LoadParams(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* AObject);
	void __fastcall Modified(System::TObject* AObject);
	void __fastcall SaveParams(Dxflchrt::TdxFlowChart* AChart, Dxflchrt::TdxFcObject* AObject);
	
public:
	__fastcall virtual TFEditObject(System::Classes::TComponent* AOwner);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFEditObject(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFEditObject(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TFEditObject(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ObjectEditor(Dxflchrt::TdxFlowChart* Chart, Dxflchrt::TdxFcObject* Obj);
}	/* namespace Dxeditobj */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXEDITOBJ)
using namespace Dxeditobj;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxeditobjHPP
