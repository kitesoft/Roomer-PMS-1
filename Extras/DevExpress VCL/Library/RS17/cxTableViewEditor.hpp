// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTableViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxtablevieweditorHPP
#define CxtablevieweditorHPP

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
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <cxCustomTableViewEditor.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtablevieweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxTableViewEditor;
class PASCALIMPLEMENTATION TcxTableViewEditor : public Cxcustomtablevieweditor::TcxCustomTableViewEditor
{
	typedef Cxcustomtablevieweditor::TcxCustomTableViewEditor inherited;
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxTableViewEditor(System::Classes::TComponent* AOwner) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTableViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxTableViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTableViewEditor(HWND ParentWindow) : Cxcustomtablevieweditor::TcxCustomTableViewEditor(ParentWindow) { }
	
};


class DELPHICLASS TcxGridTableViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTableViewStorage : public Cxcustomtablevieweditor::TcxCustomGridTableViewStorage
{
	typedef Cxcustomtablevieweditor::TcxCustomGridTableViewStorage inherited;
	
private:
	Cxgridtableview::TcxGridTableFiltering* __fastcall GetFiltering(void);
	Cxgridtableview::TcxGridTableOptionsBehavior* __fastcall GetOptionsBehavior(void);
	Cxgridtableview::TcxGridTableOptionsCustomize* __fastcall GetOptionsCustomize(void);
	Cxgridtableview::TcxGridTableOptionsData* __fastcall GetOptionsData(void);
	Cxgridtableview::TcxGridTableOptionsSelection* __fastcall GetOptionsSelection(void);
	Cxgridtableview::TcxGridTableOptionsView* __fastcall GetOptionsView(void);
	Cxgridtableview::TcxGridPreview* __fastcall GetPreview(void);
	
protected:
	Cxgridtableview::TcxGridTableView* __fastcall TableView(void);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	
__published:
	__property Cxgridtableview::TcxGridTableFiltering* Filtering = {read=GetFiltering};
	__property Cxgridtableview::TcxGridTableOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property Cxgridtableview::TcxGridTableOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize};
	__property Cxgridtableview::TcxGridTableOptionsData* OptionsData = {read=GetOptionsData};
	__property Cxgridtableview::TcxGridTableOptionsSelection* OptionsSelection = {read=GetOptionsSelection};
	__property Cxgridtableview::TcxGridTableOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxgridtableview::TcxGridPreview* Preview = {read=GetPreview};
public:
	/* TcxCustomGridViewStorage.Create */ inline __fastcall virtual TcxGridTableViewStorage(Cxgridcustomview::TcxCustomGridView* AView) : Cxcustomtablevieweditor::TcxCustomGridTableViewStorage(AView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridTableViewStorage(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxtablevieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTABLEVIEWEDITOR)
using namespace Cxtablevieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtablevieweditorHPP
