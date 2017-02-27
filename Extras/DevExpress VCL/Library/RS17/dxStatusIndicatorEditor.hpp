// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxStatusIndicatorEditor.pas' rev: 24.00 (Win32)

#ifndef DxstatusindicatoreditorHPP
#define DxstatusindicatoreditorHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.CheckLst.hpp>	// Pascal unit
#include <dxStatusBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxstatusindicatoreditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxStatusBarIndicatorEditor;
class PASCALIMPLEMENTATION TdxStatusBarIndicatorEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* BtnOK;
	Vcl::Stdctrls::TButton* BtnCancel;
	Vcl::Checklst::TCheckListBox* chlbIndicators;
	Vcl::Extctrls::TBevel* Bevel1;
	Vcl::Stdctrls::TButton* BtnAdd;
	Vcl::Stdctrls::TButton* BtnDelete;
	Vcl::Stdctrls::TButton* BtnClear;
	Vcl::Stdctrls::TComboBox* cbItemTypes;
	Vcl::Stdctrls::TGroupBox* GroupBox1;
	Vcl::Extctrls::TImage* imgExample;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BtnAddClick(System::TObject* Sender);
	void __fastcall BtnDeleteClick(System::TObject* Sender);
	void __fastcall BtnClearClick(System::TObject* Sender);
	void __fastcall chlbIndicatorsClick(System::TObject* Sender);
	void __fastcall chlbIndicatorsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall cbItemTypesChange(System::TObject* Sender);
	
private:
	void __fastcall IndicatorChangeHandler(System::TObject* Sender);
	System::UnicodeString __fastcall IndicatorTypeToStr(const Dxstatusbar::TdxStatusBarStateIndicatorType AIndicatorType);
	Dxstatusbar::TdxStatusBarStateIndicatorType __fastcall StrToIndicatorType(const System::UnicodeString AStr);
	void __fastcall SetControlsState(void);
	void __fastcall SetItemType(void);
	
public:
	Dxstatusbar::TdxStatusBarStateIndicators* Indicators;
	__fastcall virtual TdxStatusBarIndicatorEditor(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxStatusBarIndicatorEditor(void);
	void __fastcall PrepareIndicators(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxStatusBarIndicatorEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxStatusBarIndicatorEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxstatusindicatoreditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSTATUSINDICATOREDITOR)
using namespace Dxstatusindicatoreditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxstatusindicatoreditorHPP
