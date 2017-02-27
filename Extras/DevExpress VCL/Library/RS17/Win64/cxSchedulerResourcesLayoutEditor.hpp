// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerResourcesLayoutEditor.pas' rev: 24.00 (Win64)

#ifndef CxschedulerresourceslayouteditorHPP
#define CxschedulerresourceslayouteditorHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerresourceslayouteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmResourcesLayoutEditor;
class PASCALIMPLEMENTATION TfmResourcesLayoutEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxchecklistbox::TcxCheckListBox* clbResources;
	Cxbuttons::TcxButton* btnClose;
	Cxbuttons::TcxButton* btnUp;
	Cxbuttons::TcxButton* btnDown;
	Cxbuttons::TcxButton* btnSelectAll;
	Cxbuttons::TcxButton* btnSelectNone;
	void __fastcall clbResourcesDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall clbResourcesMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall clbResourcesClick(System::TObject* Sender);
	void __fastcall BtnClick(System::TObject* Sender);
	void __fastcall clbResourcesKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall clbResourcesEditValueChanged(System::TObject* Sender);
	
private:
	int FDragItem;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	
protected:
	void __fastcall CheckButtons(void);
	void __fastcall CheckSelectButtons(void);
	void __fastcall FillList(void);
	virtual void __fastcall InitControls(void);
	void __fastcall SelectResources(bool ASelectAll);
	void __fastcall SetCaptions(void);
	void __fastcall SwapItems(int AOldItem, int ANewItem);
	
public:
	virtual int __fastcall ShowModal(void);
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage, write=FStorage};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmResourcesLayoutEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmResourcesLayoutEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmResourcesLayoutEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmResourcesLayoutEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerresourceslayouteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERRESOURCESLAYOUTEDITOR)
using namespace Cxschedulerresourceslayouteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerresourceslayouteditorHPP
