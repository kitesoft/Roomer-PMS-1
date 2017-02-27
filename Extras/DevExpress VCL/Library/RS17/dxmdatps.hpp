// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxmdatps.pas' rev: 24.00 (Win32)

#ifndef DxmdatpsHPP
#define DxmdatpsHPP

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
#include <dxmdaset.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.DBGrids.hpp>	// Pascal unit
#include <Vcl.Grids.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxmdatps
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmdxMemDataPersistent;
class PASCALIMPLEMENTATION TfrmdxMemDataPersistent : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlBottom;
	Vcl::Stdctrls::TButton* btnClear;
	Vcl::Stdctrls::TButton* btnLoad;
	Vcl::Stdctrls::TButton* btnSave;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Dbgrids::TDBGrid* DBGrid;
	Data::Db::TDataSource* DataSource;
	Dxmdaset::TdxMemData* InternalMemData;
	Vcl::Dialogs::TOpenDialog* OpenDialog;
	Vcl::Dialogs::TSaveDialog* SaveDialog;
	Vcl::Stdctrls::TButton* btnGetFieldsFromFile;
	void __fastcall btnClearClick(System::TObject* Sender);
	void __fastcall btnLoadClick(System::TObject* Sender);
	void __fastcall btnSaveClick(System::TObject* Sender);
	void __fastcall btnGetFieldsFromFileClick(System::TObject* Sender);
	
public:
	void __fastcall SetMemData(Dxmdaset::TdxCustomMemData* AMemData);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmdxMemDataPersistent(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmdxMemDataPersistent(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmdxMemDataPersistent(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmdxMemDataPersistent(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowMemDataPersistentEditor(Dxmdaset::TdxCustomMemData* AMemData, Designintf::_di_IDesigner ADesigner);
}	/* namespace Dxmdatps */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXMDATPS)
using namespace Dxmdatps;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxmdatpsHPP
