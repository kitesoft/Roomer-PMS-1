// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCardViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxcardvieweditorHPP
#define CxcardvieweditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <cxCustomTableViewEditor.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCardView.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcardvieweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCardViewEditor;
class PASCALIMPLEMENTATION TcxCardViewEditor : public Cxcustomtablevieweditor::TcxCustomTableViewEditor
{
	typedef Cxcustomtablevieweditor::TcxCustomTableViewEditor inherited;
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxCardViewEditor(System::Classes::TComponent* AOwner) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCardViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxCardViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCardViewEditor(HWND ParentWindow) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(ParentWindow) { }
	
};


class DELPHICLASS TcxGridCardViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCardViewStorage : public Cxvieweditor::TcxCustomGridViewStorage
{
	typedef Cxvieweditor::TcxCustomGridViewStorage inherited;
	
private:
	Cxgridcardview::TcxGridCardViewLayoutDirection __fastcall GetLayoutDirection(void);
	Cxgridcardview::TcxGridCardViewOptionsBehavior* __fastcall GetOptionsBehavior(void);
	Cxgridcardview::TcxGridCardViewOptionsData* __fastcall GetOptionsData(void);
	Cxgridcardview::TcxGridCardViewOptionsSelection* __fastcall GetOptionsSelection(void);
	Cxgridcardview::TcxGridCardViewOptionsView* __fastcall GetOptionsView(void);
	void __fastcall SetLayoutDirection(Cxgridcardview::TcxGridCardViewLayoutDirection Value);
	
protected:
	Cxgridcardview::TcxGridCardView* __fastcall CardView(void);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	
__published:
	__property Cxgridcardview::TcxGridCardViewLayoutDirection LayoutDirection = {read=GetLayoutDirection, write=SetLayoutDirection, nodefault};
	__property Cxgridcardview::TcxGridCardViewOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property Cxgridcardview::TcxGridCardViewOptionsData* OptionsData = {read=GetOptionsData};
	__property Cxgridcardview::TcxGridCardViewOptionsSelection* OptionsSelection = {read=GetOptionsSelection};
	__property Cxgridcardview::TcxGridCardViewOptionsView* OptionsView = {read=GetOptionsView};
public:
	/* TcxCustomGridViewStorage.Create */ inline __fastcall virtual TcxGridCardViewStorage(Cxgridcustomview::TcxCustomGridView* AView) : Cxvieweditor::TcxCustomGridViewStorage(AView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridCardViewStorage(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcardvieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCARDVIEWEDITOR)
using namespace Cxcardvieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcardvieweditorHPP
