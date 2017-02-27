// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImportDialog.pas' rev: 24.00 (Win32)

#ifndef CximportdialogHPP
#define CximportdialogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cximportdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxImportDialogForm;
class PASCALIMPLEMENTATION TcxImportDialogForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Stdctrls::TButton* Button1;
	Vcl::Stdctrls::TButton* Button2;
	Vcl::Stdctrls::TButton* Button3;
	Vcl::Stdctrls::TListBox* ListBox1;
	Vcl::Extctrls::TPanel* StylesPane;
	Vcl::Comctrls::TPageControl* PageControl1;
	Vcl::Comctrls::TTabSheet* TabSheet2;
	Vcl::Stdctrls::TGroupBox* GroupBox2;
	Vcl::Stdctrls::TRadioButton* RadioButton1;
	Vcl::Stdctrls::TRadioButton* RadioButton2;
	Vcl::Stdctrls::TEdit* Edit1;
	Vcl::Stdctrls::TComboBox* ComboBox1;
	Vcl::Stdctrls::TCheckBox* cbImportStyles;
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ListBox1Click(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall ListBox1DblClick(System::TObject* Sender);
	void __fastcall cbImportStylesClick(System::TObject* Sender);
	void __fastcall RadioButton1Click(System::TObject* Sender);
	void __fastcall RadioButton2Click(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall TabSheet2Show(System::TObject* Sender);
	
private:
	Designintf::_di_IDesigner FDesigner;
	System::TObject* FDestination;
	System::UnicodeString FGroupConverterName;
	bool FStyleOptionsFirstShow;
	int FStylePaneWidth;
	void __fastcall DisableStylesOptions(void);
	void __fastcall DoImport(void);
	void __fastcall EnableStylesOptions(void);
	int __fastcall GetStylePaneWidth(void);
	int __fastcall GetConverterIndex(System::TObject* ASource);
	bool __fastcall IsParent(System::TObject* ASource, const System::UnicodeString AParentClassName);
	void __fastcall LoadComponent(const System::UnicodeString S);
	void __fastcall LoadStyleRepositories(const System::UnicodeString S);
	void __fastcall ShowStyleOptions(void);
	void __fastcall UpdateComboBox(void);
	
protected:
	Cxconverterfactory::TcxCustomConverterWithStylesClass __fastcall GetConverterClass(System::TObject* ASource);
	System::UnicodeString __fastcall GetConverterName(System::TObject* ASource);
	virtual void __fastcall InitializeConverter(Cxconverterfactory::TcxCustomConverterWithStyles* AConverter);
	virtual void __fastcall InitializeOptions(void);
	
public:
	__fastcall virtual TcxImportDialogForm(System::Classes::TComponent* AOwner);
	__property Designintf::_di_IDesigner Designer_ = {read=FDesigner, write=FDesigner};
	__property System::TObject* Destination = {read=FDestination, write=FDestination};
	__property System::UnicodeString GroupConverterName = {read=FGroupConverterName, write=FGroupConverterName};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxImportDialogForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxImportDialogForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxImportDialogForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowImportDialog(Designintf::_di_IDesigner ADesigner, System::TObject* ADestination, const System::UnicodeString AGroupConverterName, bool AShowOptionsButton = true);
}	/* namespace Cximportdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMPORTDIALOG)
using namespace Cximportdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximportdialogHPP
