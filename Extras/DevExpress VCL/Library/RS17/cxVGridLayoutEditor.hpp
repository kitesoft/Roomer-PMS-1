// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridLayoutEditor.pas' rev: 24.00 (Win32)

#ifndef CxvgridlayouteditorHPP
#define CxvgridlayouteditorHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgridlayouteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmvgLayoutEditor;
class PASCALIMPLEMENTATION TfmvgLayoutEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlButtons;
	Vcl::Extctrls::TPanel* pnlVGPlace;
	Cxbuttons::TcxButton* btCustomize;
	Cxbuttons::TcxButton* btOk;
	Cxbuttons::TcxButton* btCancel;
	Vcl::Comctrls::TStatusBar* StatusBar1;
	void __fastcall btCustomizeClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	
private:
	Cxvgrid::TcxCustomVerticalGrid* FVerticalGrid;
	
protected:
	virtual void __fastcall ApplyUpdates(Cxvgrid::TcxCustomVerticalGrid* Dest);
	virtual void __fastcall CreateClone(Cxvgrid::TcxCustomVerticalGrid* Source);
	virtual void __fastcall PrepareLayoutStyle(Cxvgrid::TcxCustomVerticalGrid* Source);
	__property Cxvgrid::TcxCustomVerticalGrid* VerticalGrid = {read=FVerticalGrid};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmvgLayoutEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmvgLayoutEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmvgLayoutEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmvgLayoutEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TfmvgLayoutEditor* fmvgLayoutEditor;
extern PACKAGE void __fastcall ShowVerticalGridLayoutEditor(Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, System::UnicodeString ACaption = System::UnicodeString());
}	/* namespace Cxvgridlayouteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDLAYOUTEDITOR)
using namespace Cxvgridlayouteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgridlayouteditorHPP
