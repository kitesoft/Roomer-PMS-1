// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLayoutViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxlayoutvieweditorHPP
#define CxlayoutvieweditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
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
#include <cxGridLayoutView.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlayoutvieweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxLayoutViewEditor;
class PASCALIMPLEMENTATION TcxLayoutViewEditor : public Cxcustomtablevieweditor::TcxCustomTableViewEditor
{
	typedef Cxcustomtablevieweditor::TcxCustomTableViewEditor inherited;
	
protected:
	virtual void __fastcall DrawListBoxItem(Vcl::Controls::TWinControl* AListBox, int AIndex, const System::Types::TRect &R);
	virtual void __fastcall UpdateSelection(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxLayoutViewEditor(System::Classes::TComponent* AOwner) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxLayoutViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxLayoutViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxLayoutViewEditor(HWND ParentWindow) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(ParentWindow) { }
	
};


class DELPHICLASS TcxGridLayoutViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLayoutViewStorage : public Cxvieweditor::TcxCustomGridViewStorage
{
	typedef Cxvieweditor::TcxCustomGridViewStorage inherited;
	
private:
	Cxgridlayoutview::TcxGridLayoutViewOptionsBehavior* __fastcall GetOptionsBehavior(void);
	Cxgridlayoutview::TcxGridLayoutViewOptionsData* __fastcall GetOptionsData(void);
	Cxgridlayoutview::TcxGridLayoutViewOptionsSelection* __fastcall GetOptionsSelection(void);
	Cxgridlayoutview::TcxGridLayoutViewOptionsView* __fastcall GetOptionsView(void);
	
protected:
	Cxgridlayoutview::TcxGridLayoutView* __fastcall LayoutView(void);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	
__published:
	__property Cxgridlayoutview::TcxGridLayoutViewOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property Cxgridlayoutview::TcxGridLayoutViewOptionsData* OptionsData = {read=GetOptionsData};
	__property Cxgridlayoutview::TcxGridLayoutViewOptionsSelection* OptionsSelection = {read=GetOptionsSelection};
	__property Cxgridlayoutview::TcxGridLayoutViewOptionsView* OptionsView = {read=GetOptionsView};
public:
	/* TcxCustomGridViewStorage.Create */ inline __fastcall virtual TcxGridLayoutViewStorage(Cxgridcustomview::TcxCustomGridView* AView) : Cxvieweditor::TcxCustomGridViewStorage(AView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewStorage(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxlayoutvieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLAYOUTVIEWEDITOR)
using namespace Cxlayoutvieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlayoutvieweditorHPP
