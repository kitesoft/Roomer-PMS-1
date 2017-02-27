// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSelectEditRepositoryItem.pas' rev: 24.00 (Win32)

#ifndef CxselecteditrepositoryitemHPP
#define CxselecteditrepositoryitemHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxselecteditrepositoryitem
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TcxSelectRepositoryItemSetup
{
public:
	int TopIndex;
	int Selected;
	Cxclasses::TcxRegisteredClasses* List;
	System::Types::TPoint Pos;
};


class DELPHICLASS TcxSelectRepositoryItem;
class PASCALIMPLEMENTATION TcxSelectRepositoryItem : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TListBox* lbItems;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Stdctrls::TLabel* lbHint;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TButton* btOk;
	Vcl::Stdctrls::TButton* btCancel;
	void __fastcall lbItemsClick(System::TObject* Sender);
	void __fastcall lbItemsMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	
private:
	Cxclasses::TcxRegisteredClasses* FList;
	void __fastcall Setup(const TcxSelectRepositoryItemSetup &AData);
	void __fastcall SaveSetup(TcxSelectRepositoryItemSetup &AData);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSelectRepositoryItem(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSelectRepositoryItem(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSelectRepositoryItem(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSelectRepositoryItem(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxedit::TcxEditRepositoryItemClass __fastcall GetEditRepositoryItemClass(TcxSelectRepositoryItemSetup &ASetupData);
}	/* namespace Cxselecteditrepositoryitem */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSELECTEDITREPOSITORYITEM)
using namespace Cxselecteditrepositoryitem;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxselecteditrepositoryitemHPP
