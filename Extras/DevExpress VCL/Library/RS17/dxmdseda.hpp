// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxmdseda.pas' rev: 24.00 (Win32)

#ifndef DxmdsedaHPP
#define DxmdsedaHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxmdaset.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxmdseda
{
//-- type declarations -------------------------------------------------------
typedef Designintf::_di_IDesigner IFormDesigner;

class DELPHICLASS TfrmdxMemDataAddField;
class PASCALIMPLEMENTATION TfrmdxMemDataAddField : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	Vcl::Extctrls::TPanel* pnlBottom;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Extctrls::TPanel* pnlMain;
	Vcl::Stdctrls::TGroupBox* gbFieldProp;
	Vcl::Stdctrls::TEdit* edName;
	Vcl::Stdctrls::TComboBox* cbFieldType;
	Vcl::Stdctrls::TEdit* edComponent;
	Vcl::Stdctrls::TEdit* edSize;
	Vcl::Extctrls::TRadioGroup* gbFieldtype;
	Vcl::Stdctrls::TGroupBox* gbLookup;
	Vcl::Stdctrls::TComboBox* cbLookupField;
	Vcl::Stdctrls::TComboBox* cbKeyField;
	Vcl::Stdctrls::TComboBox* cbDataSet;
	Vcl::Stdctrls::TComboBox* cbResultField;
	void __fastcall cbFieldTypeChange(System::TObject* Sender);
	void __fastcall gbFieldtypeClick(System::TObject* Sender);
	void __fastcall edNameChange(System::TObject* Sender);
	void __fastcall edSizeKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall edComponentChange(System::TObject* Sender);
	void __fastcall cbDataSetExit(System::TObject* Sender);
	Dxmdaset::TdxMemData* Data;
	Data::Db::TDataSet* LookupDS;
	Designintf::_di_IDesigner FormDesigner;
	void __fastcall GetDataSets(const System::UnicodeString AComponentName);
	void __fastcall CreateControls(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmdxMemDataAddField(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmdxMemDataAddField(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmdxMemDataAddField(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmdxMemDataAddField(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Data::Db::TField* __fastcall GetMemDataNewFieldType(Dxmdaset::TdxMemData* Data, int X, int Y, Designintf::_di_IDesigner FormDesigner);
}	/* namespace Dxmdseda */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXMDSEDA)
using namespace Dxmdseda;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxmdsedaHPP
