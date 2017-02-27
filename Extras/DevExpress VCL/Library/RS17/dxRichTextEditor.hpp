// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRichTextEditor.pas' rev: 24.00 (Win32)

#ifndef DxrichtexteditorHPP
#define DxrichtexteditorHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.StdActns.hpp>	// Pascal unit
#include <Vcl.ExtActns.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxrichtexteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TRichEdit;
class PASCALIMPLEMENTATION TRichEdit : public Vcl::Comctrls::TRichEdit
{
	typedef Vcl::Comctrls::TRichEdit inherited;
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
public:
	/* TCustomRichEdit.Create */ inline __fastcall virtual TRichEdit(System::Classes::TComponent* AOwner) : Vcl::Comctrls::TRichEdit(AOwner) { }
	/* TCustomRichEdit.Destroy */ inline __fastcall virtual ~TRichEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TRichEdit(HWND ParentWindow) : Vcl::Comctrls::TRichEdit(ParentWindow) { }
	
};


class DELPHICLASS TfrmRichTextEditor;
class PASCALIMPLEMENTATION TfrmRichTextEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Stdctrls::TButton* btnOk;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Stdctrls::TButton* btnApply;
	TRichEdit* edtRich;
	Vcl::Dialogs::TFontDialog* FontDialog1;
	Vcl::Comctrls::TToolBar* ToolBar1;
	Vcl::Comctrls::TToolButton* tlbOpen;
	Vcl::Comctrls::TToolButton* tlbSave;
	Vcl::Comctrls::TToolButton* ToolButton1;
	Vcl::Comctrls::TToolButton* tlbCopy;
	Vcl::Comctrls::TToolButton* tlbPaste;
	Vcl::Comctrls::TToolButton* tlbCut;
	Vcl::Comctrls::TToolButton* ToolButton2;
	Vcl::Actnlist::TActionList* ActionList1;
	Vcl::Extactns::TRichEditBold* RichEditBold1;
	Vcl::Extactns::TRichEditItalic* RichEditItalic1;
	Vcl::Extactns::TRichEditUnderline* RichEditUnderline1;
	Vcl::Extactns::TRichEditStrikeOut* RichEditStrikeOut1;
	Vcl::Extactns::TRichEditBullets* RichEditBullets1;
	Vcl::Extactns::TRichEditAlignLeft* RichEditAlignLeft1;
	Vcl::Extactns::TRichEditAlignRight* RichEditAlignRight1;
	Vcl::Extactns::TRichEditAlignCenter* RichEditAlignCenter1;
	Vcl::Stdactns::TEditCut* EditCut1;
	Vcl::Stdactns::TEditCopy* EditCopy1;
	Vcl::Stdactns::TEditPaste* EditPaste1;
	Vcl::Stdactns::TEditSelectAll* EditSelectAll1;
	Vcl::Stdactns::TEditUndo* EditUndo1;
	Vcl::Stdactns::TEditDelete* EditDelete1;
	Vcl::Menus::TPopupMenu* PopupMenu1;
	Vcl::Menus::TMenuItem* Cut1;
	Vcl::Menus::TMenuItem* Copy1;
	Vcl::Menus::TMenuItem* Paste1;
	Cxgraphics::TcxImageList* cxImageList1;
	Vcl::Comctrls::TToolButton* ToolButton8;
	Vcl::Comctrls::TToolButton* ToolButton9;
	Vcl::Comctrls::TToolBar* ToolBar2;
	Vcl::Comctrls::TToolButton* ToolButton7;
	Vcl::Comctrls::TToolButton* ToolButton10;
	Vcl::Comctrls::TToolButton* ToolButton11;
	Vcl::Comctrls::TToolButton* ToolButton12;
	Vcl::Comctrls::TToolButton* ToolButton13;
	Vcl::Comctrls::TToolButton* ToolButton14;
	Vcl::Comctrls::TToolButton* ToolButton15;
	Vcl::Comctrls::TToolButton* ToolButton3;
	Vcl::Comctrls::TToolButton* ToolButton4;
	Vcl::Comctrls::TToolButton* ToolButton6;
	Vcl::Comctrls::TToolButton* ToolButton16;
	Cxgraphics::TcxImageList* ilToolBar;
	Cxgraphics::TcxImageList* ilToolBarDisabled;
	Vcl::Comctrls::TToolButton* ToolButton5;
	Vcl::Comctrls::TToolButton* ToolButton17;
	Vcl::Dialogs::TColorDialog* ColorDialog1;
	Vcl::Stdactns::TFileOpen* FileOpen1;
	Vcl::Stdactns::TFileSaveAs* FileSaveAs1;
	void __fastcall btnApplyClick(System::TObject* Sender);
	void __fastcall edtRichChange(System::TObject* Sender);
	void __fastcall tlbFontClick(System::TObject* Sender);
	void __fastcall edtRichSelectionChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ToolButton17Click(System::TObject* Sender);
	void __fastcall FileOpen1Accept(System::TObject* Sender);
	void __fastcall FileSaveAs1Accept(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
private:
	System::Classes::TNotifyEvent FOnApply;
	HIDESBASE System::UnicodeString __fastcall GetText(void);
	void __fastcall SetChanged(bool AValue);
	HIDESBASE void __fastcall SetText(const System::UnicodeString Value);
	bool __fastcall GetModified(void);
	
public:
	bool __fastcall Execute(void);
	__property System::UnicodeString Text = {read=GetText, write=SetText};
	__property bool Modified = {read=GetModified, nodefault};
	__property System::Classes::TNotifyEvent OnApply = {read=FOnApply, write=FOnApply};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmRichTextEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmRichTextEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmRichTextEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmRichTextEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxrichtexteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRICHTEXTEDITOR)
using namespace Dxrichtexteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxrichtexteditorHPP
