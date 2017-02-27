// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSplitterEditor.pas' rev: 24.00 (Win32)

#ifndef CxsplittereditorHPP
#define CxsplittereditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxSplitter.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxTrackBar.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsplittereditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSplitEditor;
class PASCALIMPLEMENTATION TcxSplitEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* cxGroupBox1;
	Cxgroupbox::TcxGroupBox* cxGroupBox2;
	Cxcheckbox::TcxCheckBox* cxCbAhd;
	Cxcheckbox::TcxCheckBox* cxCbAp;
	Cxcheckbox::TcxCheckBox* cxCbSnap;
	Cxcheckbox::TcxCheckBox* cxCbRu;
	Vcl::Stdctrls::TLabel* Label1;
	Cxspinedit::TcxSpinEdit* cxSeMs;
	Vcl::Stdctrls::TLabel* Label2;
	Cxspinedit::TcxSpinEdit* cxSePao;
	Cxgroupbox::TcxGroupBox* cxGroupBox3;
	Cxradiogroup::TcxRadioButton* cxRbHzNone;
	Cxradiogroup::TcxRadioButton* cxRbHzMp8;
	Cxradiogroup::TcxRadioButton* cxRbHzMp9;
	Cxradiogroup::TcxRadioButton* cxRbHzSimple;
	Cxradiogroup::TcxRadioButton* cxRbHzXp;
	Cxcheckbox::TcxCheckBox* cxCbHzVisible;
	Cxtrackbar::TcxTrackBar* cxTbHzWidth;
	Vcl::Stdctrls::TLabel* Label3;
	Cxbuttons::TcxButton* cxBtnOK;
	Cxbuttons::TcxButton* cxBtnCancel;
	Cxgroupbox::TcxGroupBox* cxGroupBox4;
	Cxlistbox::TcxListBox* cxListBox1;
	Cxsplitter::TcxSplitter* cxSplit;
	Cxlistbox::TcxListBox* cxListBox2;
	void __fastcall cxCbAhdClick(System::TObject* Sender);
	void __fastcall cxCbApClick(System::TObject* Sender);
	void __fastcall cxCbSnapClick(System::TObject* Sender);
	void __fastcall cxCbRuClick(System::TObject* Sender);
	void __fastcall cxSeMsPropertiesChange(System::TObject* Sender);
	void __fastcall cxSePaoPropertiesChange(System::TObject* Sender);
	void __fastcall cxCbHzVisiblePropertiesChange(System::TObject* Sender);
	void __fastcall cxRbHzNoneClick(System::TObject* Sender);
	void __fastcall cxRbHzMp8Click(System::TObject* Sender);
	void __fastcall cxTbHzWidthPropertiesChange(System::TObject* Sender);
	
public:
	void __fastcall SetSplitControls(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxSplitEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSplitEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxSplitEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSplitEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowSplitterEditor(Cxsplitter::TcxSplitter* ASplitter);
}	/* namespace Cxsplittereditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSPLITTEREDITOR)
using namespace Cxsplittereditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsplittereditorHPP
