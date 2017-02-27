// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxStyleSheetEditor.pas' rev: 24.00 (Win32)

#ifndef CxstylesheeteditorHPP
#define CxstylesheeteditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxstylesheeteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxStyleSheetEditorPreview;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStyleSheetEditorPreview : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TcxStyleSheetEditorPreview(System::Classes::TComponent* AOwner);
	virtual Vcl::Controls::TWinControl* __fastcall Control(void) = 0 ;
	virtual System::Types::TPoint __fastcall GetSize(void);
	__classmethod virtual Cxstyles::TcxCustomStyleSheetClass __fastcall GetStyleSheetClass();
	virtual void __fastcall SetStyleSheet(Cxstyles::TcxCustomStyleSheet* AStyleSheet) = 0 ;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxStyleSheetEditorPreview(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxStyleSheetEditorPreviewClass;

class DELPHICLASS TfrmcxStyleSheetEditor;
class PASCALIMPLEMENTATION TfrmcxStyleSheetEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlBottom;
	Vcl::Extctrls::TPanel* pnlButtons;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TButton* bntCancel;
	Vcl::Dialogs::TFontDialog* FontDialog;
	Vcl::Dialogs::TColorDialog* ColorDialog;
	Vcl::Extctrls::TPanel* pnlClient;
	Vcl::Extctrls::TBevel* Bevel;
	Vcl::Extctrls::TPanel* pnlStyles;
	Vcl::Extctrls::TPanel* pnlStylesCaption;
	Vcl::Extctrls::TPanel* pnlStylesButtons;
	Vcl::Extctrls::TPanel* pnlStylesClient;
	Vcl::Stdctrls::TListBox* lbStyles;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Extctrls::TPanel* pnlPreviewCaption;
	Vcl::Extctrls::TPanel* pnlPreviewClient;
	Vcl::Stdctrls::TCheckBox* cbColor;
	Vcl::Stdctrls::TButton* btnBitmap;
	Vcl::Stdctrls::TButton* btnColor1;
	Vcl::Stdctrls::TButton* btnFont1;
	Vcl::Stdctrls::TCheckBox* cbFont;
	Vcl::Stdctrls::TCheckBox* cbBitmap;
	void __fastcall lbStylesClick(System::TObject* Sender);
	void __fastcall lbStylesMeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	void __fastcall lbStylesDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall cbClick(System::TObject* Sender);
	void __fastcall btnColor1Click(System::TObject* Sender);
	void __fastcall btnFont1Click(System::TObject* Sender);
	void __fastcall btnBitmapClick(System::TObject* Sender);
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxStyleSheetEditorPreview* FPreview;
	bool FStateUpdating;
	System::Classes::TList* FStyleList;
	Cxstyles::TcxCustomStyleSheet* FStyleSheet;
	Cxstyles::TcxStyleValue __fastcall GetCheckBoxStyleValue(Vcl::Stdctrls::TCheckBox* ACheckBox);
	Cxstyles::TcxStyle* __fastcall GetFirstSelectedStyle(void);
	void __fastcall RecreateListBox(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall SetSelectedStylesAssignValue(Vcl::Stdctrls::TCheckBox* ACheckBox);
	void __fastcall SetStyles(Cxstyles::TcxCustomStyleSheet* AStyleSheet);
	void __fastcall UpdateStyles(Cxstyles::TcxCustomStyleSheet* AStyleSheet, Cxstyles::TcxStyleGetName AGetStyleName);
	void __fastcall UpdateState(void);
	
public:
	__fastcall virtual TfrmcxStyleSheetEditor(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TfrmcxStyleSheetEditor(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmcxStyleSheetEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmcxStyleSheetEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ShowcxStyleSheetEditor(Cxstyles::TcxCustomStyleSheet* AStyleSheet, Cxstyles::TcxStyleGetName AGetStyleName);
extern PACKAGE void __fastcall RegisterStyleSheetEditorPreview(TcxStyleSheetEditorPreviewClass APreviewClass);
extern PACKAGE void __fastcall UnregisterStyleSheetEditorPreview(TcxStyleSheetEditorPreviewClass APreviewClass);
extern PACKAGE TcxStyleSheetEditorPreviewClass __fastcall GetPreviewByStyleSheetClass(Cxstyles::TcxCustomStyleSheetClass AStyleSheetClass);
}	/* namespace Cxstylesheeteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSTYLESHEETEDITOR)
using namespace Cxstylesheeteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxstylesheeteditorHPP
